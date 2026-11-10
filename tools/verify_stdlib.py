#!/usr/bin/env python3
"""
AIPL Standard Library (std/) Architectural Auditor (tools/verify_stdlib.py)

Enforces the 4 Non-Negotiable Architectural Laws across std/:
  1. Law 1 — 100% Global Filename Uniqueness (Zero Duplicate Basenames)
  2. Law 2 — 100% Application-Agnostic Purity (Zero Franchise or Game Lore Leaks)
  3. Law 3 — Explicit Structural Contracts & Zero Duplicate Top-Level Public Symbols
  4. Law 4 — Strict 6-Layer Acyclic Dependency DAG
"""

import argparse
import glob
import os
import re
import sys
from collections import defaultdict

REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
STD_DIR = os.path.join(REPO_ROOT, "std")
TESTS_FUNCTIONS_DIR = os.path.join(REPO_ROOT, "tests", "functions")
DOCS_REF_DIR = os.path.join(REPO_ROOT, "docs", "reference")

DOMAIN_LAYERS = {
    # Layer 0: Host & Memory Kernels
    "sys": 0,
    "rt": 0,
    "alloc": 0,
    # Layer 1: Core Primitives & Math
    "prelude": 1,
    "root_and_prelude": 1,
    "math": 1,
    "collections": 1,
    "fmt": 1,
    "regex": 1,
    "time": 1,
    # Layer 2: Serialization, Compression, Crypto & Database
    "encoding": 2,
    "compress": 2,
    "crypto": 2,
    "db": 2,
    # Layer 3: Streaming I/O, Filesystem, OS, Concurrency, Networking & Testing
    "io": 3,
    "fs": 3,
    "os": 3,
    "sync": 3,
    "thread": 3,
    "net": 3,
    "test": 3,
    # Layer 4: Windowing, Input, Assets, Audio, GPU, 2D/3D Rendering & UI
    "window": 4,
    "input": 4,
    "asset": 4,
    "audio": 4,
    "gfx": 4,
    "gfx2d": 4,
    "gfx25d": 4,
    "gfx3d": 4,
    "particle": 4,
    "ui": 4,
    # Layer 5: ECS, Spatial Topologies, Physics, Procgen, AI & Generic Mechanics
    "ecs": 5,
    "spatial": 5,
    "phys2d": 5,
    "phys3d": 5,
    "procgen": 5,
    "ai": 5,
    "hebar": 5,
    "mechanics": 5,
    # Umbrella root
    "std_root": 5,
}

FORBIDDEN_LORE_PATTERNS = [
    r"warcraft",
    r"\bwc3\b",
    r"diablo",
    r"\bd2\b",
    r"horadric",
    r"larzuk",
    r"gheed",
    r"tristram",
    r"runeword",
    r"cowking",
    r"biohazard",
    r"waygate",
    r"counter-strike",
    r"\bcs16\b",
    r"goldsrc",
    r"\bre1\b",
    r"\bps1\b",
    r"worldstone",
    r"uberkey",
    r"creepcamp",
    r"vgui",
    r"jahithber",
    r"waheed",
    r"resident\s*evil",
    r"v-jolt",
    r"chalsi",
    r"charsi",
]

FORBIDDEN_REGEX = re.compile("|".join(FORBIDDEN_LORE_PATTERNS), re.IGNORECASE)


def get_domain_for_file(rel_path: str) -> str:
    norm = rel_path.replace("\\", "/")
    if norm.startswith("std/"):
        norm = norm[4:]
    parts = norm.split("/")
    if len(parts) == 1:
        stem = os.path.splitext(parts[0])[0]
        return stem
    return parts[0]


def extract_step_targets(step_num: int) -> list[str]:
    pattern = os.path.join(DOCS_REF_DIR, f"{step_num:02d}_*.md")
    matches = sorted(glob.glob(pattern))
    if not matches:
        return []
    content = open(matches[0], "r", encoding="utf-8").read()
    found = sorted(set(re.findall(r"(std/[A-Za-z0-9_/]+\.aipl)", content)))
    return [p for p in found if os.path.isfile(os.path.join(REPO_ROOT, p)) and not os.path.islink(os.path.join(REPO_ROOT, p))]


def extract_public_symbols(filepath: str) -> list[tuple[str, str, int]]:
    """Returns list of (kind, symbol_name, line_no)."""
    symbols = []
    try:
        lines = open(filepath, "r", encoding="utf-8").read().splitlines()
    except OSError:
        return symbols

    for idx, raw_line in enumerate(lines, start=1):
        line = raw_line.strip()
        if line.startswith("//"):
            continue
        m_struct = re.match(r"^pub\s+struct\s+([A-Za-z_][A-Za-z0-9_]*)", line)
        if m_struct:
            symbols.append(("struct", m_struct.group(1), idx))
            continue
        m_enum = re.match(r"^pub\s+enum\s+([A-Za-z_][A-Za-z0-9_]*)", line)
        if m_enum:
            symbols.append(("enum", m_enum.group(1), idx))
            continue
        m_recv = re.match(
            r"^pub\s+fn\s+\([^:]+:\s*(?:mut\s+|&mut\s+|&)?([A-Za-z_][A-Za-z0-9_]*)(?:\[[^\]]*\])?\)\s+([A-Za-z_][A-Za-z0-9_]*)",
            line,
        )
        if m_recv:
            symbols.append(("fn", f"{m_recv.group(1)}_{m_recv.group(2)}", idx))
            continue
        m_dot = re.match(
            r"^pub\s+fn\s+([A-Za-z_][A-Za-z0-9_]*)\.([A-Za-z_][A-Za-z0-9_]*)", line
        )
        if m_dot:
            symbols.append(("fn", f"{m_dot.group(1)}_{m_dot.group(2)}", idx))
            continue
        m_fn = re.match(r"^pub\s+fn\s+([A-Za-z_][A-Za-z0-9_]*)", line)
        if m_fn:
            symbols.append(("fn", m_fn.group(1), idx))
            continue
    return symbols


def extract_std_imports(filepath: str) -> list[tuple[str, int]]:
    imports = []
    try:
        lines = open(filepath, "r", encoding="utf-8").read().splitlines()
    except OSError:
        return imports
    for idx, raw_line in enumerate(lines, start=1):
        line = raw_line.strip()
        if line.startswith("//"):
            continue
        if line.startswith("import ") or line.startswith("pub import ") or "from \"std/" in line or "from 'std/" in line:
            for m in re.finditer(r"[\"'](std/[A-Za-z0-9_/]+)[\"']", line):
                imports.append((m.group(1), idx))
            for m in re.finditer(r"\b(std\.[A-Za-z0-9_.]+)\b", line):
                imports.append((m.group(1).replace(".", "/"), idx))
    return imports


def extract_public_fns_for_coverage(filepath: str) -> list[tuple[str, str, int]]:
    """Returns list of (call_name, qualified_name, line_no) for all pub fn declarations."""
    fns = []
    try:
        lines = open(filepath, "r", encoding="utf-8").read().splitlines()
    except OSError:
        return fns

    for idx, raw_line in enumerate(lines, start=1):
        line = raw_line.strip()
        if line.startswith("//"):
            continue
        m_recv = re.match(
            r"^pub\s+fn\s+\([^:]+:\s*(?:mut\s+|&mut\s+|&)?([A-Za-z_][A-Za-z0-9_]*)(?:\[[^\]]*\])?\)\s+([A-Za-z_][A-Za-z0-9_]*)",
            line,
        )
        if m_recv:
            fns.append((m_recv.group(2), f"{m_recv.group(1)}_{m_recv.group(2)}", idx))
            continue
        m_dot = re.match(
            r"^pub\s+fn\s+([A-Za-z_][A-Za-z0-9_]*)\.([A-Za-z_][A-Za-z0-9_]*)", line
        )
        if m_dot:
            fns.append((m_dot.group(2), f"{m_dot.group(1)}_{m_dot.group(2)}", idx))
            continue
        m_fn = re.match(r"^pub\s+fn\s+([A-Za-z_][A-Za-z0-9_]*)", line)
        if m_fn:
            fns.append((m_fn.group(1), m_fn.group(1), idx))
            continue
    return fns


def get_test_file_for_domain(dom: str) -> str:
    if dom in ("prelude", "std_root", "root_and_prelude"):
        dom_dir = os.path.join(TESTS_FUNCTIONS_DIR, "core")
    else:
        dom_dir = os.path.join(TESTS_FUNCTIONS_DIR, dom)
    if not os.path.isdir(dom_dir):
        return ""
    matches = sorted(glob.glob(os.path.join(dom_dir, "*_test.aipl")))
    return matches[0] if matches else ""


def get_domain_test_corpus(dom: str) -> tuple[str, str | None]:
    if dom in ("prelude", "std_root", "root_and_prelude"):
        dom_dir = os.path.join(TESTS_FUNCTIONS_DIR, "core")
        label = "tests/functions/core/*_test.aipl"
    else:
        dom_dir = os.path.join(TESTS_FUNCTIONS_DIR, dom)
        label = f"tests/functions/{dom}/*_test.aipl"
    if not os.path.isdir(dom_dir):
        return (label, None)
    matches = sorted(glob.glob(os.path.join(dom_dir, "*_test.aipl")))
    if dom in ("sys", "rt"):
        matches += sorted(glob.glob(os.path.join(TESTS_FUNCTIONS_DIR, "sys_rt", "*_test.aipl")))
    if not matches:
        return (label, None)
    chunks = [open(p, "r", encoding="utf-8").read() for p in matches]
    return (label, "\n".join(chunks))


def audit_files(files: list[str], global_mode: bool = False) -> list[str]:
    errors = []

    # 1. Existence check
    for rel in files:
        abs_p = os.path.join(REPO_ROOT, rel)
        if not os.path.isfile(abs_p):
            errors.append(f"[MISSING FILE] {rel} does not exist")

    existing_files = [f for f in files if os.path.isfile(os.path.join(REPO_ROOT, f))]

    # 2. Law 1: Zero Duplicate Basenames
    by_basename = defaultdict(list)
    for rel in existing_files:
        by_basename[os.path.basename(rel)].append(rel)
    for bname, paths in sorted(by_basename.items()):
        if len(paths) > 1:
            errors.append(
                f"[LAW 1: DUPLICATE BASENAME] '{bname}' appears {len(paths)} times: {', '.join(paths)}"
            )

    # 3. Law 2: Zero Franchise Lore
    for rel in existing_files:
        abs_p = os.path.join(REPO_ROOT, rel)
        lines = open(abs_p, "r", encoding="utf-8").read().splitlines()
        for idx, line in enumerate(lines, start=1):
            m = FORBIDDEN_REGEX.search(line)
            if m:
                errors.append(
                    f"[LAW 2: FRANCHISE LORE] {rel}:{idx} contains forbidden token '{m.group(0)}': {line.strip()}"
                )

    # 4. Law 3: Zero Duplicate Public Structs / Enums / Functions
    symbol_defs = defaultdict(list)
    for rel in existing_files:
        abs_p = os.path.join(REPO_ROOT, rel)
        for kind, sym, line_no in extract_public_symbols(abs_p):
            symbol_defs[(kind, sym)].append((rel, line_no))
    for (kind, sym), locs in sorted(symbol_defs.items()):
        if len(locs) > 1:
            loc_str = ", ".join(f"{r}:{ln}" for r, ln in locs)
            errors.append(
                f"[LAW 3: DUPLICATE PUBLIC {kind.upper()}] '{sym}' defined in multiple modules: {loc_str}"
            )

    # 5. Law 4: Strict 6-Layer Acyclic Dependency DAG
    for rel in existing_files:
        src_dom = get_domain_for_file(rel)
        if src_dom == "std_root":
            continue
        src_layer = DOMAIN_LAYERS.get(src_dom)
        if src_layer is None:
            if global_mode:
                errors.append(f"[LAW 4: UNMAPPED DOMAIN] '{src_dom}' in {rel} is not in the 34 canonical domains")
            continue
        abs_p = os.path.join(REPO_ROOT, rel)
        for imp_path, line_no in extract_std_imports(abs_p):
            parts = imp_path.split("/")
            if len(parts) >= 2:
                dst_dom = parts[1]
                dst_layer = DOMAIN_LAYERS.get(dst_dom)
                if dst_layer is not None and dst_layer > src_layer:
                    errors.append(
                        f"[LAW 4: DAG LAYER VIOLATION] {rel}:{line_no} (domain '{src_dom}', Layer {src_layer}) imports '{imp_path}' (domain '{dst_dom}', Layer {dst_layer})"
                    )

    # 6. Law 5: 100% Unit Test Coverage for Every pub fn in std/
    test_cache = {}
    for rel in existing_files:
        if not rel.startswith("std/"):
            continue
        src_dom = get_domain_for_file(rel)
        if src_dom not in test_cache:
            test_cache[src_dom] = get_domain_test_corpus(src_dom)
        tf_rel, tf_content = test_cache[src_dom]
        if tf_content is None:
            errors.append(f"[LAW 5: MISSING TEST FILE] No unit test file found for domain '{src_dom}' ({rel})")
            continue
        abs_p = os.path.join(REPO_ROOT, rel)
        for call_name, qual_name, line_no in extract_public_fns_for_coverage(abs_p):
            if (
                f"{call_name}(" not in tf_content
                and f"{qual_name}(" not in tf_content
                and f"{call_name}[" not in tf_content
                and f"{qual_name}[" not in tf_content
            ):
                errors.append(
                    f"[LAW 5: UNTESTED PUB FN] {rel}:{line_no} 'pub fn {qual_name}' is not called in {tf_rel}"
                )

    return errors


def main() -> int:
    parser = argparse.ArgumentParser(description="AIPL std/ Architectural Auditor")
    parser.add_argument("--verify-step", "--step", dest="step", type=str, default=None)
    parser.add_argument("--domain", type=str, default=None)
    parser.add_argument("--global-audit", action="store_true")
    parser.add_argument("--check-unique-basenames", action="store_true")
    parser.add_argument("--check-zero-lore", action="store_true")
    parser.add_argument("--check-dag", action="store_true")
    args = parser.parse_args()

    if args.step is not None:
        step_num = int(args.step)
        targets = extract_step_targets(step_num)
        if not targets:
            print(f"ERROR: No target files found for step {step_num:02d}", file=sys.stderr)
            return 1
        errors = audit_files(targets, global_mode=False)
        if errors:
            for e in errors:
                print(e, file=sys.stderr)
            print(f"FAIL: Step {step_num:02d} stdlib audit failed with {len(errors)} error(s).", file=sys.stderr)
            return 1
        print(f"PASS: Step {step_num:02d} stdlib audit verified ({len(targets)} target files, 0 errors).")
        return 0

    if args.domain is not None:
        dom = args.domain.strip()
        if dom in ("root_and_prelude", "prelude", "std_root"):
            targets = ["std/std_root.aipl", "std/prelude.aipl"]
        else:
            dom_dir = os.path.join(STD_DIR, dom)
            if not os.path.isdir(dom_dir):
                print(f"ERROR: Domain directory std/{dom} does not exist", file=sys.stderr)
                return 1
            targets = sorted(
                os.path.relpath(p, REPO_ROOT)
                for p in glob.glob(os.path.join(dom_dir, "**", "*.aipl"), recursive=True)
                if not os.path.islink(p)
            )
            if not targets:
                print(f"ERROR: No .aipl files found in std/{dom}", file=sys.stderr)
                return 1
        errors = audit_files(targets, global_mode=False)
        if errors:
            for e in errors:
                print(e, file=sys.stderr)
            print(f"FAIL: Domain '{dom}' audit failed with {len(errors)} error(s).", file=sys.stderr)
            return 1
        print(f"PASS: Domain '{dom}' stdlib audit verified ({len(targets)} files, 0 errors).")
        return 0

    # Global audit across all .aipl files in std/
    all_std_files = sorted(
        os.path.relpath(p, REPO_ROOT)
        for p in glob.glob(os.path.join(STD_DIR, "**", "*.aipl"), recursive=True)
        if not os.path.islink(p)
    )
    errors = audit_files(all_std_files, global_mode=True)
    if errors:
        for e in errors:
            print(e, file=sys.stderr)
        print(
            f"FAIL: Global stdlib audit failed across {len(all_std_files)} files with {len(errors)} error(s).",
            file=sys.stderr,
        )
        return 1
    print(f"PASS: Global stdlib audit verified ({len(all_std_files)} files, 0 duplicate basenames, 0 lore strings, 0 symbol collisions, 0 DAG violations).")
    return 0


if __name__ == "__main__":
    sys.exit(main())
