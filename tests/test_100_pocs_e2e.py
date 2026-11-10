"""
Canonical Examples & Domain E2E Native Compilation & Execution Matrix.
Discovers and tests all 250 canonical example programs in examples/ex_*.aipl,
all 250 Option A example twin test suites in tests/examples/ex_*_test.aipl, and
all function unit test suites in tests/functions/**/*.aipl.

Runs concurrently using ThreadPoolExecutor for high-throughput, low-latency
execution across multi-core systems.
"""

from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path
import os
import re
import subprocess
import sys
import tempfile
import pytest

REPO_ROOT = Path(__file__).resolve().parent.parent
AIPL_BIN = REPO_ROOT / "bin" / "aipl"
EXAMPLES_DIR = REPO_ROOT / "examples"
EXAMPLE_TESTS_DIR = REPO_ROOT / "tests" / "examples"
FUNCTIONS_TESTS_DIR = REPO_ROOT / "tests" / "functions"
SCENARIOS_TESTS_DIR = REPO_ROOT / "tests" / "scenarios"
COMPLEX_TESTS_DIR = REPO_ROOT / "tests" / "complex"

MAX_WORKERS = min(16, max(4, os.cpu_count() or 8))


def _memory_safe_workers() -> int:
    try:
        total_gb = os.sysconf("SC_PAGE_SIZE") * os.sysconf("SC_PHYS_PAGES") / (1024 ** 3)
    except (ValueError, OSError, AttributeError):
        return 4
    return max(2, min(MAX_WORKERS, int(total_gb // 6)))


BUILD_WORKERS = _memory_safe_workers()


def is_elf_binary(path: Path) -> bool:
    """Check if the compiled binary is a valid Linux ELF executable."""
    try:
        with open(path, "rb") as f:
            magic = f.read(4)
            return magic == b"\x7fELF"
    except OSError:
        return False


def clean_temp_artifacts(base_path: str):
    """Safely remove a temporary binary and any associated compiler scratch files."""
    for ext in ["", ".tmp.c"]:
        p = Path(base_path + ext)
        if p.exists():
            try:
                p.unlink()
            except OSError:
                pass


def discover_canonical_examples():
    """Discover all 250 canonical .aipl example entrypoints in examples/."""
    return sorted(EXAMPLES_DIR.glob("ex_*.aipl"))


def discover_example_test_suites():
    """Discover all 250 Option A twin test suites in tests/examples/."""
    return sorted(EXAMPLE_TESTS_DIR.glob("ex_*_test.aipl"))


def discover_function_test_suites():
    """Discover all 356 function unit test suites in tests/functions/."""
    return sorted(FUNCTIONS_TESTS_DIR.glob("**/*_test.aipl"))


def discover_scenario_test_suites():
    """Discover all 10 scenario test suites in tests/scenarios/."""
    return sorted(SCENARIOS_TESTS_DIR.glob("**/*_test.aipl"))


def discover_complex_test_suites():
    """Discover all 13 complex test suites in tests/complex/."""
    return sorted(COMPLEX_TESTS_DIR.glob("*_test.aipl"))


def discover_stdlib_step_suites():
    """Backward-compatible alias for discover_function_test_suites."""
    return discover_function_test_suites()


def test_discovery_counts():
    """Verify that all canonical examples, example twin tests, function tests, scenario tests, and complex tests exist."""
    examples = discover_canonical_examples()
    assert len(examples) == 263, f"Expected 263 canonical examples in {EXAMPLES_DIR}, found {len(examples)}"

    example_tests = discover_example_test_suites()
    assert len(example_tests) == 263, (
        f"Expected 263 example test suites in {EXAMPLE_TESTS_DIR}, found {len(example_tests)}"
    )

    func_tests = discover_function_test_suites()
    assert len(func_tests) == 363, (
        f"Expected 363 function step test suites in {FUNCTIONS_TESTS_DIR}, found {len(func_tests)}"
    )

    scenario_tests = discover_scenario_test_suites()
    assert len(scenario_tests) == 11, (
        f"Expected 11 scenario test suites in {SCENARIOS_TESTS_DIR}, found {len(scenario_tests)}"
    )

    complex_tests = discover_complex_test_suites()
    assert len(complex_tests) == 13, (
        f"Expected 13 complex test suites in {COMPLEX_TESTS_DIR}, found {len(complex_tests)}"
    )
def _check_canonical_module_and_imports(file_path: Path, src: str, is_test: bool) -> str | None:
    """
    Verify that every example and twin test (001-250):
    1. Starts with `module Ex<NNN>...` matching its file number
    2. Uses canonical `import { ... } from "../std/..."` (or `"../../std/..."` / `"../../examples/..."` in tests).
    """
    m_num = re.match(r"ex_(\d{3})_", file_path.name)
    num = m_num.group(1) if m_num else ""
    if not re.search(rf"(?m)^module\s+Ex{num}\w+", src):
        return f"{file_path.name}: missing canonical 'module Ex{num}...' declaration"

    if re.search(r'(?m)^import\s+"', src):
        return f"{file_path.name}: uses legacy 'import \"...\" (...)' syntax instead of 'import {{ ... }} from \"...\"'"

    for m in re.finditer(r'import\s+\{[^}]+\}\s+from\s+"([^"]+)"', src):
        imp_path = m.group(1)
        if is_test:
            if not (imp_path.startswith("../../std/") or imp_path.startswith("../../examples/")):
                return f"{file_path.name}: non-canonical test import path '{imp_path}'"
        else:
            if not imp_path.startswith("../std/"):
                return f"{file_path.name}: non-canonical example import path '{imp_path}' (expected '../std/...')"
    return None


def _check_window_example_invariants(file_path: Path, src: str) -> str | None:
    """
    Verify that a *_window.aipl file:
    1. Declares `module Ex<NNN>...` and canonical `../std/...` imports
    2. Uses `while not windowShouldClose():` ONLY (forbids `frame < 180` or auto-closing frame limits) and increments `frame`
    3. Updates/reads its imported non-gfx2d `std/` domain state inside the `while not windowShouldClose():` loop
       (excluding static `*Audit*` / `audit*` functions so Potemkin HUD-only audit calls cannot pass).
    """
    hdr_err = _check_canonical_module_and_imports(file_path, src, is_test=False)
    if hdr_err:
        return hdr_err

    if re.search(r"while\s+not\s+windowShouldClose\(\)\s+and\b", src) or "frame < 180" in src:
        return (
            f"{file_path.name}: forbidden auto-closing frame limit in window loop; "
            f"must use 'while not windowShouldClose():' only"
        )

    if "while not windowShouldClose():" not in src:
        return f"{file_path.name}: missing 'while not windowShouldClose():' loop"

    loop_body = src.split("while not windowShouldClose():", 1)[1]
    if "frame = frame + 1" not in loop_body:
        return f"{file_path.name}: missing 'frame = frame + 1' inside window loop"

    imports = re.findall(r'import\s+\{([^}]+)\}\s+from\s+"([^"]+)"', src)
    domain_syms = set()
    for syms, mod in imports:
        if "gfx2d/shape2d" in mod or mod.endswith("/prelude"):
            continue
        for s in syms.split(","):
            s = s.strip()
            if s:
                domain_syms.add(s)

    fn_defs = {}
    parts = re.split(r"(?m)^(?:pub\s+)?fn\s+([A-Za-z0-9_]+)\s*\(", src)
    for idx in range(1, len(parts), 2):
        fn_defs[parts[idx]] = parts[idx + 1]

    def _is_audit_fn(name: str) -> bool:
        return name.startswith("audit") or "Audit" in name

    reachable_text = re.sub(r"\b(?:audit\w*|\w*Audit\w*)\s*\([^)]*\)", "", loop_body)
    visited = set()
    queue = [
        fn
        for fn in fn_defs
        if fn != "main" and not _is_audit_fn(fn) and re.search(r"\b" + re.escape(fn) + r"\s*\(", reachable_text)
    ]
    while queue:
        cur = queue.pop(0)
        if cur in visited:
            continue
        visited.add(cur)
        body = fn_defs.get(cur, "")
        reachable_text += "\n" + body
        for fn in fn_defs:
            if (
                fn not in visited
                and fn != "main"
                and not _is_audit_fn(fn)
                and re.search(r"\b" + re.escape(fn) + r"\s*\(", body)
            ):
                queue.append(fn)

    used_domain = [
        s for s in domain_syms if re.search(r"\b" + re.escape(s) + r"\b", reachable_text)
    ]
    if not used_domain:
        return (
            f"{file_path.name}: window loop does not update or read any imported std/ domain state "
            f"(imported={sorted(domain_syms)})"
        )
    return None


def test_window_examples_canonical_loop_and_domain_state():
    """
    Statically verify that all 250 examples and 250 twin tests declare `module Ex<NNN>...`
    and use canonical relative imports, and that every *_window.aipl uses an infinite
    `while not windowShouldClose():` loop (forbidding `frame < 180` or auto-closing frame limits)
    and updates/reads its `std/` domain state inside the window loop.
    """
    errors = []
    for f in discover_canonical_examples():
        src = f.read_text(encoding="utf-8")
        err = _check_canonical_module_and_imports(f, src, is_test=False)
        if err:
            errors.append(err)
        if f.name.endswith("_window.aipl"):
            win_err = _check_window_example_invariants(f, src)
            if win_err:
                errors.append(win_err)

    for tf in discover_example_test_suites():
        t_src = tf.read_text(encoding="utf-8")
        t_err = _check_canonical_module_and_imports(tf, t_src, is_test=True)
        if t_err:
            errors.append(t_err)

    assert not errors, "Example / twin-test invariant failures:\n  " + "\n  ".join(errors)


def test_examples_and_poc_verify_and_build():
    """
    For all 263 canonical .aipl files in examples/:
    1. Run `aipl verify <file>`
    2. Run `aipl build <file> -o <tmp_bin>` and verify valid native ELF executable
    3. Verify runtime execution across all 263 canonical examples.
    """
    example_files = discover_canonical_examples()
    assert len(example_files) == 263, f"Expected 263 examples, found {len(example_files)}"
    headless_env = dict(os.environ)
    headless_env["AIPL_HEADLESS"] = "1"
    tasks = []
    for f in example_files:
        tasks.append((str(f), "verify"))
        tasks.append((str(f), "build_and_run"))

    def run_internal_task(item):
        file_path_str, kind = item
        file_path = Path(file_path_str)

        if kind == "verify":
            src = file_path.read_text(encoding="utf-8")
            if "\npub fn test_" in src or "\nfn test_" in src:
                return {
                    "file": file_path_str,
                    "stage": "option_a_purity",
                    "code": -1,
                    "stdout": "",
                    "stderr": "Production example file must not contain test_* functions",
                }
            if file_path.name.endswith("_window.aipl"):
                win_err = _check_window_example_invariants(file_path, src)
                if win_err:
                    return {
                        "file": file_path_str,
                        "stage": "window_loop_invariant",
                        "code": -1,
                        "stdout": "",
                        "stderr": win_err,
                    }
            cmd = [str(AIPL_BIN), "verify", file_path_str]
            res = subprocess.run(
                cmd, cwd=str(REPO_ROOT), env=headless_env, capture_output=True, text=True, timeout=120
            )
            if res.returncode != 0:
                return {
                    "file": file_path_str,
                    "stage": "verify",
                    "code": res.returncode,
                    "stdout": res.stdout,
                    "stderr": res.stderr,
                }
            return None

        elif kind == "build_and_run":
            with tempfile.NamedTemporaryFile(prefix=f"aipl_eg_{file_path.stem}_", delete=False) as tmp:
                tmp_bin = tmp.name

            try:
                cmd = [str(AIPL_BIN), "build", file_path_str, "-o", tmp_bin]
                res = subprocess.run(
                    cmd, cwd=str(REPO_ROOT), env=headless_env, capture_output=True, text=True, timeout=300
                )
                if res.returncode != 0:
                    return {
                        "file": file_path_str,
                        "stage": "build",
                        "code": res.returncode,
                        "stdout": res.stdout,
                        "stderr": res.stderr,
                    }

                if not is_elf_binary(Path(tmp_bin)):
                    return {
                        "file": file_path_str,
                        "stage": "build_elf_check",
                        "code": -1,
                        "stdout": res.stdout,
                        "stderr": "Output binary is not a valid ELF executable",
                    }

                run_res = subprocess.run(
                    [tmp_bin], cwd=str(REPO_ROOT), env=headless_env, capture_output=True, text=True, timeout=120
                )
                if run_res.returncode != 0:
                    return {
                        "file": file_path_str,
                        "stage": "run_native",
                        "code": run_res.returncode,
                        "stdout": run_res.stdout,
                        "stderr": run_res.stderr,
                    }

                return None
            finally:
                clean_temp_artifacts(tmp_bin)

    failures = []
    with ThreadPoolExecutor(max_workers=MAX_WORKERS) as executor:
        futures = {executor.submit(run_internal_task, t): t for t in tasks}
        for fut in as_completed(futures):
            err = fut.result()
            if err is not None:
                failures.append(err)

    if failures:
        msg_lines = [f"{len(failures)} task(s) failed verify/build/run in examples/:"]
        for f in failures:
            msg_lines.append(f"  [{f['stage'].upper()}] {f['file']} (code {f['code']})")
            if f.get("stderr"):
                msg_lines.append(f"    stderr: {f['stderr'].strip()[:200]}")
            if f.get("stdout"):
                msg_lines.append(f"    stdout: {f['stdout'].strip()[:200]}")
        pytest.fail("\n".join(msg_lines))


def test_100_pocs_native_matrix():
    """
    Verifies all 263 Option A twin example test suites in tests/examples/ex_*_test.aipl
    compile and pass via native `./bin/aipl test`.
    """
    example_tests = discover_example_test_suites()
    assert len(example_tests) == 263, f"Expected 263 example test suites, found {len(example_tests)}"
    headless_env = dict(os.environ)
    headless_env["AIPL_HEADLESS"] = "1"
    def run_test_suite(target_path: Path):
        cmd = [str(AIPL_BIN), "test", str(target_path)]
        res = subprocess.run(
            cmd, cwd=str(REPO_ROOT), env=headless_env, capture_output=True, text=True, timeout=180
        )
        if res.returncode != 0 or f"PASS: {target_path.stem}" not in res.stdout:
            return {
                "suite": target_path.name,
                "stage": "test",
                "code": res.returncode,
                "stdout": res.stdout,
                "stderr": res.stderr,
            }
        return None

    failures = []
    with ThreadPoolExecutor(max_workers=MAX_WORKERS) as executor:
        futures = {executor.submit(run_test_suite, p): p for p in example_tests}
        for fut in as_completed(futures):
            err = fut.result()
            if err is not None:
                failures.append(err)

    if failures:
        msg_lines = [f"{len(failures)}/263 example test suites failed:"]
        for f in failures:
            msg_lines.append(f"  [{f['stage'].upper()}] {f['suite']} (code {f['code']})")
            if f.get("stderr"):
                msg_lines.append(f"    stderr: {f['stderr'].strip()[:200]}")
            if f.get("stdout"):
                msg_lines.append(f"    stdout: {f['stdout'].strip()[:200]}")
        pytest.fail("\n".join(msg_lines))


if __name__ == "__main__":
    sys.exit(pytest.main([__file__, "-v"]))
