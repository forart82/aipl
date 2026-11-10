# AIPL Command-Line Interface (CLI) Reference
**Single Source of Truth (SSOT) — Master Toolchain Guide**

[Home](../README.md) | [Docs Index](INDEX.md) | [Tutorials](tutorials/INDEX.md) | [Cookbook](tutorials/cookbook.md) | [Stdlib Reference](reference/STDLIB_REFERENCE.md) | [CLI Reference](CLI_REFERENCE.md)

> **When to Read This Document**: Read this reference for complete documentation on all AIPL CLI commands, subcommands, flags, exit codes, multi-target build options, debugging tools, and autonomous agent self-repair workflows.

---

## Canonical Project Architecture & Inventory Counts

- **36 Standard Library Domain Groups**: `2` root modules (`std/std_root.aipl`, `std/prelude.aipl`) + `35` canonical domain directories = **`290` `std/` modules** (`260` implementation modules + `30` barrel modules).
- **4,324 Total Callable Functions**: **`32` compiler built-ins + `4,292` `std/` functions, constructors & receiver methods**.
- **263 Curated, Fully-Tested Examples**: `examples/ex_001_*.aipl` through `examples/ex_263_*.aipl` (`118` CLI + `145` interactive Window applications) with 1-to-1 twin unit tests in `tests/examples/`.
- **37 Architecture Decision Records**: `docs/ADR/ADR-0001-*.md` through `docs/ADR/ADR-0037-*.md` indexed in [`docs/ADR/INDEX.md`](ADR/INDEX.md).
- **629 Canonical Test Suites**: `250` example twin tests + `356` function test suites + `10` scenario suites + `13` complex system integration suites.

---

## Command Overview

```bash
aipl <command> [arguments...] [flags...]
```

| Command | Subcommands / Flags | Description |
| :--- | :--- | :--- |
| [`splice`](#1-aipl-splice) | `<file.aipl> <symbol> <replacement.aipl>` | Surgically splices AST symbols with 0 diff outside targeted lines |
| [`outline`](#2-aipl-outline) | `<file.aipl> [--json]` | Generates semantic skeleton with structural module & symbol inspection |
| [`fix`](#3-aipl-fix) | `<file.aipl>` | Autonomous self-repair engine for formatting and unused imports (`LINT010`) |
| [`shield`](#4-aipl-shield) | `lock \| unlock \| verify \| status \| eject` | Manages 4-layer filesystem protections for SSOT architecture files |
| [`bench`](#5-aipl-bench) | `--soak \| <artifact.cwasm> [--iterations N]` | Continuous soak testing & sub-100µs AOT cold-start latency profiler |
| [`run`](#6-aipl-run) | `<file.aipl> [--quiet] [--window] [--headless] [--screenshot <path>] [--snapshot-frame <N>] [--assets <dir>] [-- <args...>]` | Executes AIPL source with cached native compilation, headless/window rendering |
| [`test`](#19-aipl-test-aipl-fmt-aipl-lint--aipl-lsp) | `[path\|dir] [--json] [--filter <pat>] [--step <N>]` | Runs all `test*()` functions across a file or full test directory |
| [`compile`](#7-aipl-compile) | `<file.wasm\|file.wat> -o <out.cwasm>` | Ahead-Of-Time compilation from Wasm/WAT to Cranelift machine code |
| [`package`](#8-aipl-package) | `<stub> <payload> -o <binary> [--asset <bundle>] [--assets <dir>]` | Fast binary trailer packaging (<5ms) for zero-dependency executables |
| [`inspect`](#9-aipl-inspect) | `<standalone_binary>` | Inspects binary trailer overlay, CRC32 checksum, and payload size |
| [`dap`](#10-aipl-dap) | `[--port <port>] [--stdio]` | Launches Debug Adapter Protocol (DAP) server for IDE integration |
| [`debug`](#11-aipl-debug) | `<artifact>` | Launches interactive source-level CLI debugger with DWARF line tables |
| [`verify`](#12-aipl-verify) | `<file.aipl> [--json] [--check-budget=<size>]` | Static type checking, SMT refinement verification, and binary budget check |
| [`tokens`](#13-aipl-tokens) | `<file.aipl> [--vocab=sp256k]` | Analyzes tokenomics density across SentencePiece 256k and OpenAI BPE |
| [`build`](#14-aipl-build--aipl-bundle) | `<file.aipl> [-o <out>] [-g\|--debug-info] [--native\|--c-native\|--c\|--c-modular\|--ts\|--html\|--wasm\|--elf64\|--arm64\|--pure-aipl] [--target <native\|c\|html\|ts\|wasm\|llvm\|x86_64-linux\|arm64-linux\|android-arm64\|apk>]` | Compiles AIPL into native binary, C99, TypeScript, HTML5, WASM32, Android shared library, signed APK, LLVM IR, or direct ELF64 |
| [`docs`](#15-aipl-docs--aipl-prompt) | `search <q> [--json] \| html [-o <out>] \| index \| tutorial <NN> \| std/<domain> \| topic \| stdlib` | Interactive zero-dependency documentation portal, AST signatures, full-text search, and HTML compiler |
| [`examples`](#16-aipl-examples) | `list [--all\|--window\|--cli\|<domain>] \| search <query> \| show <id> [--test] \| test <id> \| run <id>` | 258 verified curriculum examples explorer (`ex_001`–`ex_258`), domain filtering, source viewer, and twin test runner |
| [`new`](#17-aipl-new) | `<name> [--template=canvas\|cli] [-o <file.aipl>]` | Scaffolds a self-documenting AIPL starter project with C++-style `main()` loop |
| [`fmt`](#19-aipl-test-aipl-fmt-aipl-lint--aipl-lsp) | `<file.aipl> [--check] [--stdin]` | Formats AIPL source code with canonical 2-space indentation |
| [`lint`](#19-aipl-test-aipl-fmt-aipl-lint--aipl-lsp) | `<file.aipl> [--fix] [--json]` | Runs static verification and linter diagnostics |
| [`lsp`](#19-aipl-test-aipl-fmt-aipl-lint--aipl-lsp) | `[--stdio]` | Launches AIPL Language Server Protocol (LSP) server over JSON-RPC stdio |
| [`help`](#18-aipl-help--subcommand-help) | `[subcommand\|quickstart\|syntax\|builtins\|std\|tutorials\|cookbook\|examples\|errors\|<symbol>]` | 31 CLI command manuals, agent knowledge library, 60s quickstart, AST grammar, and diagnostics |
| [`install-global`](#20-aipl-install-global) | | Installs `aipl` compiler binary globally into `/usr/local/bin` system PATH |
| [`repl`](#21-aipl-repl) | `[--no-color]` | Interactive Read-Eval-Print Loop with expression evaluation and persistent bindings |
| [`patch`](#22-aipl-patch) | `<file.aipl> [--diff=<diff>] [--line-start=<N>] [--line-end=<N>]` | Line-range and AST-node atomic code patching utility |
| [`schema`](#23-aipl-schema) | `[target] [--extract\|--synthesize=<schema>\|--ast\|--diagnostics]` | Draft 2020-12 JSON Schema extractor & struct synthesizer |
| [`fuzz`](#24-aipl-fuzz) | `<file.aipl> [--runs=<N>] [--seed=<N>] [--timeout=<ms>] [--corpus=<dir>]` | Property-based & coverage-guided mutational fuzz testing harness |
| [`conductor`](#25-aipl-conductor) | `[manifest.json] [--json]` | Multi-agent concurrency contracts & deterministic worktree arbitration |
| [`bootstrap`](#26-aipl-bootstrap) | | 3-stage self-hosting fixed-point compiler verification |
| [`window`](#27-aipl-window-aipl-screenshot--aipl-record) | `list \| screenshot \| record \| action` | Inspects, captures, and controls live hardware-accelerated canvas windows via IPC |
| [`screenshot`](#27-aipl-window-aipl-screenshot--aipl-record) | `<target> <out_path>` | Synchronously captures window framebuffer to PNG/JPEG image (alias) |
| [`record`](#27-aipl-window-aipl-screenshot--aipl-record) | `<target> <out_path> [--frames <N>] [--fps <fps>]` | Records targeted window video stream (alias) |
| [`eject`](#4-aipl-shield) | | Completely removes shield & uninstalls hooks |
| `--window-mode=x11\|glx\|auto` | `--x11`, `--gl`, `--software`, `AIPL_WINDOW_MODE` | Selects X11 + MIT-SHM (`x11`/`app`) or X11 + `libGL.so.1` GLX (`glx`/`game`) window backend |
| `--BenchmarkWindowFps` | `AIPL_BENCHMARK_WINDOW_FPS=1` | Benchmarks 120 every-frame presented frames (`do_present = 1`) after 5 warmup frames |
| `--version` / `-v` | | Displays current compiler toolchain version |
| `--help` / `-h` | | Displays toolchain usage and command reference |

- **Primary Source Module**: `std/os/cli_args.aipl` (`pub fn cliAppVersion(mut app: CliApp, version: str): CliApp:`)
- **Verification Test**: `tests/functions/os/cli_args_test.aipl`
- **Runnable Example Reference**: `examples/ex_104_os_cli_args_subcommands_cli.aipl` (tested by `tests/examples/ex_104_os_cli_args_subcommands_cli_test.aipl`)

```aipl
module tests.functions.os.cli_args_z2_test
import * from "std/os/cli_args"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cli_args_cliAppVersion_2(): int:
  let arg_app = CliApp(name = "test", version = "test", description = "test", flags = [], options = [], args = [], subcommands = [])
  let edge_app = CliApp(name = "a", version = "a", description = "a", flags = [], options = [], args = [], subcommands = [])
  let arg_version = "test"
  let edge_version = "a"
  let resNom = cliAppVersion(arg_app, arg_version)
  let resEdge = cliAppVersion(edge_app, edge_version)
  assertEqStr(resNom.name, "test", "cliAppVersion nominal string matches")
  assertEqStr(resEdge.name, "a", "cliAppVersion boundary string matches")
  ret 0
```

---

## 1. `aipl splice`

Surgically replaces a specific top-level or member symbol in an AIPL source file using the Concrete Syntax Tree (CST) bidirectional lens engine.

### Invariants & Guarantees
- **Exact Byte Targeting**: Targets precisely the matched symbol node without disturbing surrounding trivia, formatting, indentation, or comments.
- **Zero Drift Invariant**: Generates zero diff lines outside the targeted symbol span. Bytes before and after the targeted node are 100% byte-for-byte identical.
- **Trivia Preservation**: Leading doc comments (`/// ...`), trailing line comments (`// ...`), and blank lines are strictly preserved.
- **Qualified Identifier Support**: Supports top-level functions (`takeDamage`), member methods (`Player.takeDamage`), structs, interfaces, and systems.

### Syntax
```bash
aipl splice <file.aipl> <symbol> <replacement.aipl>
```

### Arguments & Flags
- `<file.aipl>`: Absolute or relative path to the target `.aipl` source file.
- `<symbol>`: Symbol identifier to replace (function, struct, or enum name).
- `<replacement.aipl>`: Path to the replacement `.aipl` file containing the new definition.

### Example Execution
```bash
aipl splice src/player.aipl takeDamage patch/new_damage.aipl
```

### Sample Output
```
AIPL Surgical AST Splicer: SUCCESS
  - Target file:    src/player.aipl
  - Target symbol:  takeDamage
  - Replacement:    patch/new_damage.aipl
  - Replaced lines: 45-56

Unified Diff:
--- src/player.aipl
+++ src/player.aipl
@@ -45,12 +45,9 @@
-  fn takeDamage(amount: int): void:
-    self.health -= amount
+  fn takeDamage(amount: int): void:
+    if amount <= 0:
+      ret
+    let blocked = amount.min(self.shield)
+    self.shield -= blocked
+    let rem = amount - blocked
+    self.health -= rem
```

---

## 2. `aipl outline`

Extracts the semantic skeleton of an AIPL module, preserving all exported type signatures, interfaces, systems, shaders, and function headers while stripping implementation bodies to `= ...`.

### Invariants & Guarantees
- **$\ge 80\%$ Token Reduction**: Strips function/method loop logic and computational blocks on 1,500+ line modules while retaining 100% of module signatures.
- **Context Preservation**: Preserves module declarations, imports, type aliases, enums, structs (with field types and method signatures), interfaces, ECS systems (with query parameters), and shaders.
- **Agent Context Window Optimization**: Enables AI agents to ingest massive dependency trees within tight prompt context limits without token bloat.

### Syntax
```bash
aipl outline <file.aipl>
aipl outline <file.aipl> --json
```

### Arguments & Flags
- `<file.aipl>`: Path to the target `.aipl` module.
- `--json`: (Optional) Emits a structured single-line or pretty JSON payload containing module declaration and symbol descriptor objects.

### Example Human-Readable Output
```bash
aipl outline src/game/engine.aipl
```
```
Module Engine (src/game/engine.aipl):
  pub Module Engine (line 1)
  pub Struct ComponentData1 (line 20)
  pub Function updateValue (line 28)
  pub Function computeMatrixTransform1 (line 45)
```

### Structured `--json` Schema
```bash
aipl outline src/game/engine.aipl --json
```
```json
{
  "file": "src/game/engine.aipl",
  "module": "Engine",
  "symbols": [
    {
      "name": "Engine",
      "kind": "Module",
      "line": 1,
      "isPub": true
    },
    {
      "name": "ComponentData1",
      "kind": "Struct",
      "line": 20,
      "isPub": true
    },
    {
      "name": "updateValue",
      "kind": "Function",
      "line": 28,
      "isPub": true
    },
    {
      "name": "computeMatrixTransform1",
      "kind": "Function",
      "line": 45,
      "isPub": true
    }
  ]
}
```

---

## 3. `aipl fix`

Autonomous multi-pass self-repair engine that formats AIPL source files to canonical 2-space indentation, detects and prunes unused imports (`LINT010`), and automatically rectifies common syntactic, tokenomic, and semantic compilation diagnostics.

### Supported Repairs & Diagnostics
1. **Automatic Shortest-Syntax Source Canonicalization**: Rewrites C-style block braces `{ ... }` on `fn`, `if`, `elif`, `else`, `while`, `for`, and `match` into `:` + 2-space indented blocks, collapses multi-line `fn(...)` signatures and `struct Name(...)` / `struct Name { ... }` declarations onto single canonical lines, rewrites `return` -> `ret`, `else if` -> `elif`, `) -> Type` -> `): Type`, `&&` -> `and`, `||` -> `or`, unary `!expr` -> `not expr`, strips redundant trailing `;`, and normalizes `import { ... } "mod"` and `"std.domain.mod"` into `import { ... } from "std/domain/mod"`.
2. **Unused Import Pruning (`LINT010`)**: Identifies imported symbols that are not referenced in the module body and cleanly removes them from `import { ... } from "..."` statements, dropping empty import declarations automatically.
3. **Missing `mut` (`AIPL_E2001_IMMUTABLE_ASSIGNMENT`)**: Detects reassignments to immutable bindings and synthesizes `mut` declaration edits.
4. **Snake Case Token Penalty (`AIPL_W0041_SNAKE_CASE_TOKEN_PENALTY` / `AIPL_W1003_SNAKE_CASE_AUTOFIX`)**: Converts snake_case identifiers to camelCase/PascalCase to maintain SP256K tokenomic density while preserving `test_*` functions, `module` paths, `extern` symbols, and `UPPER_SNAKE_CASE` constants.
5. **Digit-Suffixed Primitives (`AIPL_E0042_DIGIT_PRIMITIVE_FORBIDDEN`)**: Automatically replaces `i32`/`i64`/`u64` with `int`, `f32`/`f64` with `float`, and `u8` with `byte`.
6. **Unhandled Result Operations (`AIPL_E1004_UNHANDLED_RESULT`)**: Synthesizes postfix `?` propagation operators on unhandled `Result[T, E]` return types.
7. **Non-Boolean Conditionals (`AIPL_E2004_NON_BOOLEAN_CONDITION`)**: Converts implicit truthiness checks (e.g. `if items:`) into strict boolean expressions (`if items.len() > 0:`).

### Benchmark Guarantees
- Achieves $\ge 95\%$ first-pass resolution across synthetic diagnostic suites.
- Applies edits deterministically in reverse byte order to eliminate span offset drift.
- Type & Refinement Verification: Ensures resulting repaired files compile cleanly without manual intervention.

### Syntax
```bash
aipl fix <file.aipl>
```

### Arguments & Flags
- `<file.aipl>`: Source file to format and repair in place.

### Example Execution
```bash
aipl fix src/dirty.aipl
```
```
Formatted 'src/dirty.aipl' and pruned unused imports.
```

---

## 4. `aipl shield`

Manages the four-layer filesystem shield protecting Single-Source-of-Truth (SSOT) architecture, grammar, and security specification files against unauthorized modification.

### Protection Layers
- **Layer 1: OS-Level DAC Permissions**: Enforces read-only permissions (`0444`) on protected files.
- **Layer 2: Virtual Filesystem (VFS) Write Gate**: Intercepts compiler and agent writes, failing fast if targeted file is protected.
- **Layer 3: Agent Scoping Context Synchronization**: Automatically syncs `.agentignore`, `.geminiignore`, and `.cursorignore`.
- **Layer 4: Cryptographic SHA-256 Manifest**: Verifies cryptographic checksums in `.aipl/manifest.sha256` before Git commits.

### Commands
```bash
# Locks protected SSOT files (mode 0444) and generates SHA-256 manifest
aipl shield lock [--hook]

# Temporarily unlocks SSOT files (mode 0644) for intentional authoring
aipl shield unlock

# Verifies cryptographic hash and permission integrity across all SSOT files
aipl shield verify [--json]

# Displays current lock status, file counts, and hook configuration
aipl shield status

# Ejects the shield: restores mode 0644, uninstalls hooks, cleans ignore files
aipl eject
```

- **Primary Source Module**: `std/regex/text_diff.aipl` (`pub fn formatUnifiedDiff(oldFile: str, newFile: str, oldText: str, newText: str, context: int = 3): str:`)
- **Verification Test**: `tests/functions/regex/text_diff_test.aipl`
- **Runnable Example Reference**: `examples/ex_064_time_instant_benchmark_timer_cli.aipl` (tested by `tests/examples/ex_064_time_instant_benchmark_timer_cli_test.aipl`)

```aipl
module tests.functions.regex.text_diff_z3_test
import * from "std/regex/text_diff"
import { splitLines, parseInt } from "std/fmt/fmt_mod"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_text_diff_formatUnifiedDiff_3(): int:
  let arg_oldFile = "/tmp/aipl_test_path"
  let edge_oldFile = "/tmp/aipl_test_path"
  let arg_newFile = "/tmp/aipl_test_path"
  let edge_newFile = "/tmp/aipl_test_path"
  let arg_oldText = "test"
  let edge_oldText = "a"
  let arg_newText = "test"
  let edge_newText = "a"
  let arg_context = 4
  let edge_context = 1
  let resNom = formatUnifiedDiff(arg_oldFile, arg_newFile, arg_oldText, arg_newText, arg_context)
  let resEdge = formatUnifiedDiff(edge_oldFile, edge_newFile, edge_oldText, edge_newText, edge_context)
  assertEqInt(resNom.len(), 48, "formatUnifiedDiff nominal string length == 48")
  assertEqInt(resEdge.len(), 48, "formatUnifiedDiff boundary string length == 48")
  ret 0
```

---

## 5. `aipl bench`

Executes high-throughput continuous soak benchmarks, memory flatline verification, and V8 garbage collection profiling across both execution runtimes.

### Invariants & Quality Gates
- **Zero Major GC Spikes**: Asserts 0 Major GC (Mark-Sweep-Compact) pauses $> 5.0\text{ms}$ in V8/Node.js.
- **Zero Heap Allocations**: Asserts 0 bytes allocated per frame in the hot loop.
- **Process RSS Flatline**: Asserts process RSS memory growth $< 2.0\text{MB}$ post-warmup across 1,000,000 frames.
- **Deterministic State**: Validates identical mathematical checksums across millions of continuous ticks.

### Syntax
```bash
aipl bench --soak [--duration <duration>] [--engine <native|v8|both>] [--particles <N>] [--iterations <N>]
```

### Examples
```bash
# Accelerated burst mode: 1,000,000 frames in seconds
aipl bench --soak

# Production 24-hour daemon verification mode
aipl bench --soak --duration=24h

# 10-minute native Cranelift AOT soak
aipl bench --soak --engine=native --duration=10m

# 1-hour V8 / Node.js GC profiling soak
aipl bench --soak --engine=v8 --duration=1h

# Sub-100µs cold-start latency benchmark on compiled AOT artifact
aipl bench artifact.cwasm --iterations 100
```

---

## 6. `aipl run`

Executes an AIPL source file (`.aipl`) with cached native compilation, Ahead-Of-Time compiled artifact (`.cwasm`), or WebAssembly module (`.wasm`). When running `.aipl` source files, `aipl run` performs static bidirectional type-checking and SMT refinement verification first, compiles to a cached native binary under `/tmp/aipl-run-<sha256>`, and executes directly. Supports CLI entrypoints (`pub fn main(): int`), autonomous game loops (`initWindow`, `while not windowShouldClose():`), or headless CI rendering.

### Syntax
```bash
aipl run <file.aipl> [--quiet] [--window] [--headless] [--screenshot <path>] [--snapshot-frame <N>] [--frames <N>] [--assets <dir>] [-- <args...>]
```

### Flags & Options
- `--quiet`: Suppresses compilation progress logs and runs the program output silently.
- `--window`: Launches native desktop graphics window with hardware-accelerated 144 FPS swapchain (`wgpu` + `winit`, zero Electron, <25MB RSS).
- `--headless`: Initializes headless GPU/software context for CI environments and offscreen rendering without requiring a display server (`DISPLAY`/`WAYLAND_DISPLAY`).
- `--screenshot <path>`: Captures the rendered frame to an image file at `<path>` during execution.
- `--snapshot-frame <N>`: Captures a deterministic snapshot specifically on frame index $N$.
- `--frames <N>` (or `--frames=<N>`): Executes exactly $N$ frames and exits cleanly.
- `--assets <dir>`: Binds the specified directory into the in-memory asset VFS for runtime access (`assetRead`, `loadImage`).
- `-- <args...>`: Forwards trailing command-line arguments to the program.

### Examples
```bash
# Run CLI language programs silently
aipl run examples/ex_001_hello_world_and_io_cli.aipl --quiet

# Run interactive 1280x720 visual galleries in a native 144 FPS GPU window
aipl run examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl --window

# Run 5 frames offscreen in headless GPU mode and capture a screenshot for CI verification
aipl run examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl --headless --frames 5 --screenshot test_frame.png --snapshot-frame 3
```

---

## 7. `aipl compile`

Pre-compiles WebAssembly bytecode (`.wasm`) or WebAssembly text format (`.wat`) into native machine code (`.cwasm`) using Cranelift Ahead-Of-Time compilation.

### Syntax
```bash
aipl compile <file.wasm|file.wat> -o <artifact.cwasm>
```

---

## 8. `aipl package`

Packages an application payload (`.cwasm` or `.wasm`) and optional embedded asset bundle into a single self-contained standalone native executable using the binary trailer overlay format.

### Syntax
```bash
aipl package <stub> <payload> -o <output_binary> [--asset <asset_path>]
```

---

## 9. `aipl inspect`

Inspects a standalone binary's trailer overlay, validating payload length, asset bundle length, CRC32 checksum, and format version flags.

### Syntax
```bash
aipl inspect <standalone_binary>
```

---

## 10. `aipl dap`

Launches the Debug Adapter Protocol (DAP) server engine over standard I/O or TCP, enabling zero-configuration source-level debugging for VS Code, Cursor, Zed, and autonomous AI agents.

### Syntax
```bash
aipl dap [--port <port>] [--stdio]
```

---

## 11. `aipl debug`

Launches an interactive source-level CLI debugger supporting breakpoints, demangled stack traces (`bt`), single-line stepping (`next`, `stepIn`), and variable inspection (`info locals`, `print`) via DWARF line tables.

### Syntax
```bash
aipl debug <artifact>
```

- **Primary Source Module**: `std/encoding/hex.aipl` (`fn hexNibbleToChar(nib: int, uppercase: bool): str:`)
- **Verification Test**: `tests/functions/encoding/hex_test.aipl`
- **Runnable Example Reference**: `examples/ex_059_fmt_unicode_utf8_inspector_cli.aipl` (tested by `tests/examples/ex_059_fmt_unicode_utf8_inspector_cli_test.aipl`)

```aipl
module tests.functions.encoding.hex_z1_test
import * from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hex_hexNibbleToChar_1(): int:
  let arg_nib = 4
  let edge_nib = 1
  let arg_uppercase = true
  let edge_uppercase = false
  let resNom = hexNibbleToChar(arg_nib, arg_uppercase)
  let resEdge = hexNibbleToChar(edge_nib, edge_uppercase)
  assertEqStr(resNom, "4", "hexNibbleToChar nominal string matches")
  assertEqStr(resEdge, "1", "hexNibbleToChar boundary string matches")
  ret 0
```

---

## 12. `aipl verify`

Performs complete static lexical, syntactic, type-checking, and SMT refinement verification on an AIPL source file, emitting machine-actionable single-root JSON (`ADR-0023`). Optionally verifies compiled binary size against strict budget limits via `--check-budget`.

### Syntax
```bash
aipl verify <file.aipl> [--json] [--check-budget=<size>]
```

### Flags & Options
- `--json`: Emits machine-actionable single-root JSON diagnostics adhering to `ADR-0023` schema with `file`, `valid`, `errors`, `warnings`, `diagnostics`, and `functionCount`.
- `--check-budget=<size>` (or `--check-budget <size>`): Enforces a compiled standalone binary byte budget ceiling. Supports byte suffixes `B`, `KB` ($1024$ bytes), and `MB` ($1048576$ bytes). If compiled artifact exceeds budget, verification fails with a budget violation diagnostic.

### Examples
```bash
# Verify static types and SMT refinements
aipl verify src/main.aipl

# Emit single-root JSON diagnostics for agent auto-repair
aipl verify src/main.aipl --json

# Verify module and enforce a strict 2MB binary size budget
aipl verify src/main.aipl --check-budget=2MB
```

---

## 13. `aipl tokens`

Analyzes source code tokenomics density across Google SentencePiece 256k, OpenAI `cl100k_base`, and OpenAI `o200k_base` vocabularies.

### Syntax
```bash
aipl tokens <file.aipl> [--vocab=sp256k]
```

---

## 14. `aipl build` & `aipl bundle`

Compiles an AIPL source program (`.aipl`) into a self-contained standalone native executable (`--native` or `--elf64`), a single-file zero-dependency HTML5 application (`--html` or `aipl bundle`), WebAssembly binary (`--wasm` / `--target wasm`), LLVM IR (`--target llvm`), clean TypeScript (`--ts`), React 19 JSX (`--tsx`), or executable JavaScript with sourcemaps (`--js`).

### Syntax
```bash
aipl build <file.aipl> [-o <out>] [-g|--debug-info] [--native|--c-native|--c|--c-modular|--ts|--html|--wasm|--elf64|--arm64|--pure-aipl] [--target <native|c|html|ts|wasm|llvm|x86_64-linux|arm64-linux|android-arm64|apk>] [--assets <dir>]
aipl bundle <file.aipl> [-o <out.html>] [--assets <dir>]
```

### Flags & Options
- `--native` / `--c-native` (or `--target native`): Recursively bundles local `.aipl` module imports, performs whole-program call-graph dead code elimination, verifies static types and SMT refinements, emits modular ISO C99 (`#include <aipl_runtime.h>`), and compiles in parallel across CPU cores via host `gcc`/`clang` linked against the content-addressed runtime archive (`.aipl/cache/v1/libaipl_rt-<hash16>.a` or `libaipl_rt_gui-<hash16>.a`) into a zero-dependency native binary (`chmod 0755`).
- `--c` (or `--target c`): Emits a standalone, self-contained amalgamated ISO C99 source file (`.c`) embedding `runtime/aipl_runtime.h` and `runtime/rt_*.c` (or compiles a native binary if `-o` does not end in `.c`).
- `--c-modular`: Emits a lightweight modular ISO C99 source file (`.c`) that uses `#include <aipl_runtime.h>` and links against `libaipl_rt-<hash16>.a`.
- `--elf64` / `--arm64` / `--pure-aipl` (or `--target x86_64-linux` / `--target arm64-linux`): Direct native ELF64 Zero-C machine code emission with linear-scan register allocation and direct Linux kernel syscalls (`std/syscall.aipl`).
- `--wasm` / `--target wasm` / `--target wasm32`: Direct single-pass WebAssembly 1.0 binary emitter generating a standalone `.wasm` file with WASI Preview 1 system calls (`fd_write`, `fd_read`, `clock_time_get`, `proc_exit`).
- `--target android-arm64`: Compiles AIPL application code to an Android ARM64 native shared library (`libaipl_app.so`) linked against the Android NDK runtime with NativeActivity lifecycle hooks (ADR-0034).
- `--target apk`: Constructs, generates binary XML manifest (`AndroidManifest.xml`), embeds assets, and digitally signs an installable Android APK package using APK Signature Scheme v2 (ADR-0036).
- `--target llvm`: Emits SSA-based LLVM IR (`.ll`) text representation.
- `-g` / `--debug-info`: Emits `#line` source directives and DWARF line tables for native debugging in GDB, LLDB, and the AIPL DAP debugger.
- `--html` / `--target html` (or `aipl bundle`): Bundles the AIPL program, standard library, and hardware-accelerated WebGL2/WebGPU instanced uber-shader batch renderer into a single self-contained `.html` file that runs offline in any modern browser.
- `--ts` / `--target ts` / `--tsx` / `--js`: Emits TypeScript 5.x, React 19 JSX, or pure JavaScript ESM output.
- `-o <path>`: Destination file path for the compiled artifact.

### Examples
```bash
# Build a standalone native executable binary with debug info
aipl build examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl --native -g -o objects3d_bin
./objects3d_bin --headless --frames 5

# Build a direct WebAssembly binary with WASI
aipl build src/main.aipl --target wasm32 -o dist/app.wasm

# Build a single-file HTML5 visual showcase
aipl build examples/ex_202_ecs_entity_generational_arena_window.aipl --html -o dist/ecs_physics.html

# Transpile to TypeScript
aipl build examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl --ts -o dist/objects3d.ts
```

- **Primary Source Module**: `compiler/codegen_c_or_ir.aipl` (`pub fn mapAiplTypeToC(ty: str): str:`)
- **Verification Test**: `tests/complex/lang_05_cross_target_interpreter_c_html_wasm_parity_test.py`
- **Runnable Example Reference**: `examples/ex_015_sys_ffi_c_abi_bridge_cli.aipl` (tested by `tests/examples/ex_015_sys_ffi_c_abi_bridge_cli_test.aipl`)

```aipl
module docs.compiler.codegen_c_verify
import { mapAiplTypeToC } from "compiler/codegen_c_or_ir"
import { assertEqStr } from "std/prelude"

pub fn verify_compiler_codegen_c(): int:
  assertEqStr(mapAiplTypeToC("int"), "AiplVal", "AIPL int maps to C99 AiplVal")
  assertEqStr(mapAiplTypeToC("str"), "AiplVal", "AIPL str maps to C99 AiplVal")
  ret 0
```

---

## 15. `aipl docs` & `aipl prompt`

Provides sub-millisecond, zero-network access to the authoritative AIPL documentation, language grammar, 290 embedded standard library modules across 36 domain directories (`std/<domain>/*.aipl`), 250 canonical examples (`examples/ex_001`–`ex_250`), token-optimized LLM system prompt, full-text & signature search, and static HTML portal compilation directly from the compiled CLI binary.

### Syntax
```bash
aipl docs [topic|stdlib|std/<module>|cli] [--list] [--llm] [--json]
aipl docs search <query> [--json]
aipl docs html [-o docs/html/index.html]
aipl docs index
aipl docs tutorial <01..12>
aipl docs std/<domain>
aipl prompt
```

### Subcommands & Capabilities
- `aipl docs search <query> [--json]`: Instant sub-millisecond full-text and signature search across all 4,292 standard library function signatures, 32 language built-ins, and 250 example programs. Emits highlighted matches with exact `import "std/..."` paths or machine-readable JSON (`{"query": "...", "total_matches": N, "results": [...]}`).
- `aipl docs html [-o <path>]`: Compiles all embedded Markdown manuals, tutorials, stdlib references, and 250 example links into a standalone, zero-dependency HTML documentation portal (`docs/html/index.html` by default).
- `aipl docs index`: Renders the master documentation index (`docs/INDEX.md`).
- `aipl docs tutorial <01..12>`: Renders progressive step-by-step tutorial chapters (`docs/tutorials/<NN>_*.md`).
- `aipl docs std/<domain>`: Displays the domain reference documentation and extracts live exported function/struct signatures across all modules in `std/<domain>/*.aipl`.
- `aipl docs stdlib`: Full index of all 290 embedded standard library modules across the 36 domains under `std/`.
- `aipl docs std/<module>`: Inspects top-of-file `///` module documentation headers, struct definitions, and exported function signatures for a specific module (e.g. `aipl docs std/fs`, `aipl docs std/db`, `aipl docs std/crypto`, `aipl docs std/math`, `aipl docs std/canvas`).
- `aipl docs llm` / `aipl docs --llm` / `aipl prompt`: Emits the single-pass, token-optimized (<2,500 tokens) AIPL reference guide for AI coding agents.
- `aipl docs syntax`: Full language specification and EBNF grammar (`docs/SPEC.md`).
- `aipl docs canvas`: 2D vector drawing primitives, 4x MSAA, HiDPI, textures, and input polling.
- `aipl docs transforms`: 2D affine matrix stack and 3D transformations.
- `aipl docs 3d`: 3D solid geometry, depth-sorted rasterizer, perspective projection, and Lambertian shading.
- `aipl docs aura`: AuraDS Material Design 3 UI component framework, 24-theme palette engine, and game HUD overlays.
- `aipl docs examples`: Complete source and overview of canonical language & visual examples.
- `aipl docs agent`: Surgical AST splicing, semantic skeletonization, and self-repair reference (`docs/AGENT_TOOLING.md`).
- `aipl docs cli`: Complete CLI reference manual (`docs/CLI_REFERENCE.md`).
- `aipl docs --json`: Emits the entire documentation catalog as a structured JSON array.

---

## 16. `aipl examples`

Lists, filters, inspects, executes, or tests the 250 canonical self-contained AIPL examples stored in [`examples/`](../examples) (`ex_001`–`ex_250`) and their twin test suites in `tests/examples/`.

### Syntax
```bash
aipl examples [list] [--all|--window|--cli|<domain>]
aipl examples search <query>
aipl examples show <id|slug> [--test]
aipl examples test <id|slug>
aipl examples run <id|slug> [--window] [--headless] [--frames <N>]
```

### Filtering & Inspection Subcommands
- `aipl examples list`: Default 36-domain curriculum overview with domain ranges and flagship highlights.
- `aipl examples list --all`: Lists all 250 verified examples (`ex_001` through `ex_250`) with `[CLI]` and `[WINDOW]` category badges.
- `aipl examples list --window`: Filters the 132 interactive Window examples.
- `aipl examples list --cli`: Filters the 118 command-line CLI examples.
- `aipl examples list <domain>`: Filters examples by domain keyword (e.g., `aipl examples list crypto`, `aipl examples list math`).
- `aipl examples search <query>`: Searches all 250 examples by keyword, domain name, or called standard library functions.
- `aipl examples show <id|slug>`: Displays the complete commented source code for an example program.
- `aipl examples show <id|slug> --test`: Displays the Option A twin test suite (`tests/examples/ex_NNN_*_test.aipl`) for the targeted example.
- `aipl examples test <id|slug>`: Directly runs the matching twin test suite via `aipl test`.
- `aipl examples run <id|slug> [--window|--headless]`: Compiles and executes the targeted example program.

### Representative Examples Catalog (`examples/`)

| ID | Slug | File | Layer | Highlights |
| :---: | :--- | :--- | :---: | :--- |
| `001` | `core_types` | [`examples/ex_001_hello_world_and_io_cli.aipl`](../examples/ex_001_hello_world_and_io_cli.aipl) | Layer 0 | Core types, standard streams, banner checksums, and Option A CLI structure |
| `022` | `memory_arenas` | [`examples/ex_022_alloc_arena_bump_profiler_cli.aipl`](../examples/ex_022_alloc_arena_bump_profiler_cli.aipl) | Layer 0 | Linear bump arena allocator, high-water mark, and bulk reset profiler |
| `041` | `math_dsp` | [`examples/ex_041_math_complex_and_fft_spectrum_cli.aipl`](../examples/ex_041_math_complex_and_fft_spectrum_cli.aipl) | Layer 1 | Complex phasors, Euler roots of unity, and Cooley-Tukey radix-2 FFT |
| `051` | `collections` | [`examples/ex_051_collections_graph_dijkstra_mst_cli.aipl`](../examples/ex_051_collections_graph_dijkstra_mst_cli.aipl) | Layer 1 | Directed/weighted adjacency graphs, Dijkstra shortest path, TopoSort, and Kruskal MST |
| `062` | `text_time` | [`examples/ex_062_regex_text_diff_myers_patch_cli.aipl`](../examples/ex_062_regex_text_diff_myers_patch_cli.aipl) | Layer 1 | Myers `O(ND)` shortest edit script (SES) and unified diff patch generator |
| `070` | `serialization` | [`examples/ex_070_encoding_json_jq_query_cli.aipl`](../examples/ex_070_encoding_json_jq_query_cli.aipl) | Layer 2 | RFC 8259 JSON DOM parser, pointer path query, and canonical pretty printer |
| `090` | `crypto_db` | [`examples/ex_090_crypto_aead_chacha20_poly1305_cli.aipl`](../examples/ex_090_crypto_aead_chacha20_poly1305_cli.aipl) | Layer 2 | ChaCha20-Poly1305 & AES-256-GCM AEAD authenticated encryption |
| `115` | `io_os_sync` | [`examples/ex_115_thread_job_system_work_stealing_cli.aipl`](../examples/ex_115_thread_job_system_work_stealing_cli.aipl) | Layer 3 | Chase-Lev work-stealing job deque and fork-join parallel task graph |
| `126` | `net_rpc_test` | [`examples/ex_126_net_rpc_jsonrpc2_dispatcher_cli.aipl`](../examples/ex_126_net_rpc_jsonrpc2_dispatcher_cli.aipl) | Layer 3 | JSON-RPC 2.0 & gRPC service dispatcher, batch correlation, and deadlines |
| `131` | `window_audio` | [`examples/ex_131_window_app_loop_fixed_timestep_window.aipl`](../examples/ex_131_window_app_loop_fixed_timestep_window.aipl) | Layer 4 | Deterministic Glenn Fiedler fixed-timestep accumulator and render alpha window |
| `176` | `gpu_gfx` | [`examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`](../examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl) | Layer 4 | 3D Gribb-Hartmann frustum culling and occlusion window |
| `190` | `ui_a11y` | [`examples/ex_190_ui_layout_flexbox_and_grid_solver_window.aipl`](../examples/ex_190_ui_layout_flexbox_and_grid_solver_window.aipl) | Layer 4 | Two-pass Flexbox & Grid UI layout engine (`row`/`column`, `grow`/`shrink`) solver window |
| `202` | `ecs_spatial` | [`examples/ex_202_ecs_entity_generational_arena_window.aipl`](../examples/ex_202_ecs_entity_generational_arena_window.aipl) | Layer 5 | 64-bit generational entity IDs (`32b Index + 32b Generation`) and ABA safety window |
| `216` | `physics_procgen` | [`examples/ex_216_phys2d_rigid_body_gravity_stacks_window.aipl`](../examples/ex_216_phys2d_rigid_body_gravity_stacks_window.aipl) | Layer 5 | 2D symplectic Euler rigid-body world, gravity substepping, and sleep islands window |
| `245` | `ai_rag_hebar` | [`examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`](../examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl) | Layer 5 | Human-Equivalent Bot Automated Referee (`HEBAR`) & Wilson 85% flow-corridor window |
| `250` | `mechanics_capstone` | [`examples/ex_250_mechanics_full_capstone_application_window.aipl`](../examples/ex_250_mechanics_full_capstone_application_window.aipl) | Layer 5 | Full-stack capstone: ECS tactical arena, alias-method loot, pity timer, and v1->v3 save window |
| `259` | `gfx25d_world` | [`examples/ex_259_continuous_world_25d.aipl`](../examples/ex_259_continuous_world_25d.aipl) | Layer 4 | Continuous 2.5D/3D isometric world, Z-buffered heightfield, spline river, and HEBAR referee |
| `260` | `gfx25d_textured_world` | [`examples/ex_260_textured_25d_village_and_river_window.aipl`](../examples/ex_260_textured_25d_village_and_river_window.aipl) | Layer 4 | Slope-splatted UV-textured 2.5D heightfield village, UV-scrolled river/road, and textured houses |
| `261` | `gfx25d_textured_gallery` | [`examples/ex_261_textured_3d_gallery_and_uv_mesh_window.aipl`](../examples/ex_261_textured_3d_gallery_and_uv_mesh_window.aipl) | Layer 4 | Interactive 2.5D/3D UV mesh monument gallery, procedural micro-normal textures, and PPM round-trip |
| `262` | `gfx25d_dark_fantasy_arpg` | [`examples/ex_262_dark_fantasy_encampment_arpg_window.aipl`](../examples/ex_262_dark_fantasy_encampment_arpg_window.aipl) | Layer 4 | Dark-fantasy ARPG 2.5D encampment, multi-biome splatting, 8-dir sprite rigs, light cookies, and weather |
| `263` | `gfx25d_lighting_lab` | [`examples/ex_263_isometric_8dir_rig_and_lighting_lab_window.aipl`](../examples/ex_263_isometric_8dir_rig_and_lighting_lab_window.aipl) | Layer 4 | Interactive 8-directional isometric sprite rig, 4 blend modes, and 2.5D lighting workbench |

### 263-Example & Option A Twin Test Suite Architecture (`examples/`)
- [`examples/`](../examples): Master 28-category, 263-example curriculum pairing every `examples/ex_XXX_<name>.aipl` CLI and Window showcase with its Option A pre-written twin test suite `tests/examples/ex_XXX_<name>_test.aipl`.

---

## 17. `aipl new`

Scaffolds a new, self-documenting AIPL starter project (`--template=canvas` or `--template=cli`) that uses `//` comments, `r = ...` struct field initialization, and an autonomous C++-style `pub fn main()` loop passing `aipl verify` with 0 errors out of the box.

### Syntax
```bash
aipl new <name> [--template=canvas|cli] [-o <file.aipl>]
```

---

## 18. `aipl help` & Subcommand Help

Displays top-level toolchain usage, the dedicated AI Agent Quick-Start & Knowledge Library, or detailed interactive manual pages for all 31 CLI commands, compiler diagnostic codes, and standard library symbols.

### Syntax
```bash
aipl --help
aipl help
aipl help <command>
aipl help <topic>
aipl help <symbol>
```

### AI Agent Quick-Start & Knowledge Library Topics
- `aipl help quickstart`: 60-second language summary, 2-space indentation rules, `let`/`mut` immutability, `Option`/`Result`, and SMT refinement contracts (`req:` / `ens:`).
- `aipl help syntax`: Complete lexical & AST grammar reference (modules, imports, structs, enums, receiver methods, closures, pattern matching).
- `aipl help builtins`: All 32 core language built-in functions with exact signatures and one-line examples.
- `aipl help std [domain|module|fn]`: Browse all 36 `std/` domain groups, inspect any of the 290 modules, or search 4,292 stdlib functions.
- `aipl help tutorials [1..12]`: Read any of the 12 progressive step-by-step tutorials directly in the terminal.
- `aipl help cookbook [query]`: Browse or search the catalog of 50 copy-pasteable production recipes.
- `aipl help examples [domain|cli|window|001..250]`: Interactive 250-example curriculum explorer and twin test navigator.
- `aipl help errors [E1xx|E2xx|E3xx]`: Compiler diagnostic codes (E1xx syntax, E2xx types, E3xx SMT refinements, E4xx runtime, LINT rules) with before/after autonomous self-repair patterns.
- `aipl help <symbol>`: Fallback symbol lookup across standard library modules, structs, and functions (e.g. `aipl help Vec2`, `aipl help chacha20`, `aipl help std/math`).

### 31 CLI Command Manuals
Complete manual pages with flags, arguments, exit codes, and examples for all 31 CLI commands:
`verify`/`check`, `build`, `bundle`, `run`, `transpile`, `test`, `repl`, `bench`, `fuzz`, `docs`, `doc`, `examples`, `inspect`, `patch`, `splice`, `outline`, `tokens`, `schema`, `fmt`, `lint`, `fix`, `new`, `init`, `scaffold`, `pkg`, `bootstrap`, `install-global`, `shield`, `conductor`, `lsp`, `dap`, `window` (`list`, `screenshot`, `record`, `action`).

- **Primary Source Module**: `std/std_root.aipl` (`pub fn stdlibVersionString(): str:`)
- **Verification Test**: `tests/functions/core/std_root_test.aipl`
- **Runnable Example Reference**: `examples/ex_001_hello_world_and_io_cli.aipl` (tested by `tests/examples/ex_001_hello_world_and_io_cli_test.aipl`)

```aipl
module tests.functions.core.std_root_stdlibVersionString_test
import * from "std/std_root"
import * from "std/prelude"

pub fn test_std_root_stdlibVersionString(): int:
  let v = stdlibVersion()
  let s = stdlibVersionString()
  assertEqStr(s, "4.0.0", "version string is 4.0.0")
  assertEqStr(s, str(v.major) + "." + str(v.minor) + "." + str(v.patch), "matches struct fields")
  ret 0
```

---

## 19. `aipl test`, `aipl fmt`, `aipl lint` & `aipl lsp`

Developer and IDE ergonomics commands for unit testing, canonical 2-space source formatting, tokenomics linting, and Language Server Protocol (LSP) integration.

### `aipl test`
Runs all `test*()` functions in a targeted `.aipl` test file or recursively discovers and executes every `.aipl` test file across an entire directory (e.g. `tests/stdlib`).

```bash
aipl test [path|dir] [--json] [--filter <pattern>] [--step <N>] [--headless] [--screenshot <path>] [--snapshot-frame <N>]
```

- `[path|dir]`: Single test file or directory path. Defaults to `tests/` if omitted.
- `--json`: Emits machine-actionable JSON test summary (`{"status":"ok","success":true,"passed":N,"failed":0}`).
- `--filter <pattern>` (or `--filter=<pattern>`): Only executes test files whose names contain `<pattern>` (e.g. `aipl test tests/stdlib --filter=bytes`).
- `--headless`: Runs tests using offscreen rendering for visual canvas/audio tests in CI environments.
- `--screenshot <path>` & `--snapshot-frame <N>`: Captures visual frame artifacts during test execution.

- **Primary Source Module**: `std/test/test_runner.aipl` (`pub fn registerTestCase(mut suite: TestSuite, name: str, moduleName: str, expectedStatus: int): TestSuite:`)
- **Verification Test**: `tests/functions/test/test_runner_test.aipl`
- **Runnable Example Reference**: `examples/ex_128_test_runner_tap_junit_report_cli.aipl` (tested by `tests/examples/ex_128_test_runner_tap_junit_report_cli_test.aipl`)

```aipl
module tests.functions.test.test_runner_z2_test
import * from "std/test/test_runner"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_test_runner_registerTestCase_2(): int:
  let arg_suite = TestSuite(name = "test", cases = [], results = [])
  let edge_suite = TestSuite(name = "a", cases = [], results = [])
  let arg_name = "test"
  let edge_name = "a"
  let arg_moduleName = "test"
  let edge_moduleName = "a"
  let arg_expectedStatus = 1
  let edge_expectedStatus = 0
  let resNom = registerTestCase(arg_suite, arg_name, arg_moduleName, arg_expectedStatus)
  let resEdge = registerTestCase(edge_suite, edge_name, edge_moduleName, edge_expectedStatus)
  assertEqStr(resNom.name, "test", "registerTestCase nominal string matches")
  assertEqStr(resEdge.name, "a", "registerTestCase boundary string matches")
  ret 0
```

### `aipl fmt`
Formats AIPL source code to enforce strict canonical 2-space indentation, consistent colon blocks, and clean blank line spacing.

```bash
aipl fmt <file.aipl> [--check] [--stdin]
```

- `--check`: Dry-run format verification. Exits with code `0` if the file is properly formatted, or exit code `1` if formatting is required.
- `--stdin`: Reads unformatted source code from standard input (`/dev/stdin`) and prints formatted code directly to standard output. Enables seamless editor formatting pipes (VS Code, Zed, Neovim).

### `aipl lint`
Executes tokenomics and static verification linter rules across source modules.

```bash
aipl lint <file.aipl> [--json]
```

- `--json`: Serializes lint diagnostics to JSON adhering to `ADR-0023` single-root schema.

### `aipl lsp`
Launches the AIPL Language Server Protocol (LSP) server daemon over JSON-RPC 2.0 stdio with standard HTTP-style framing (`Content-Length: <N>\r\n\r\n{...}`).

```bash
aipl lsp [--stdio]
```

Provides live diagnostics on publish, document outline symbol resolution, hover documentation strings from doc comments (`///`), and definition jumps.

---

## 20. `aipl install-global`

Installs the `./bin/aipl` self-hosted native compiler executable globally into the host operating system's system PATH (`/usr/local/bin/aipl`), establishing system-wide availability of `aipl`.

### Syntax
```bash
aipl install-global
```

Ensures execute permissions (`chmod 0755`) and verifies that `aipl --version` resolves from any terminal working directory.

---

## 21. `aipl repl`

Interactive Read-Eval-Print Loop (REPL) with instant expression evaluation, persistent variable bindings, line editing, and history.

### Syntax
```bash
aipl repl [--no-color]
```

### REPL Commands
- `:help`: Display REPL interactive command help and keybindings.
- `:type <expr>`: Inspect the static type of an expression without evaluating it.
- `:symbols`: List currently defined session variables, functions, and imported modules.
- `:clear`: Reset the REPL evaluation environment and free session memory.
- `:quit`, `:q`: Exit the interactive session cleanly.

### Example Session
```text
aipl> let x = 42
aipl> let y = 58
aipl> x + y
100
aipl> :type x + y
int
aipl> :q
```

---

## 22. `aipl patch`

Line-range and AST-node atomic code patching utility. Applies verified, AST-preserving atomic patches and validates syntax and invariants before committing changes to disk.

### Syntax
```bash
aipl patch <file.aipl> [OPTIONS]
```

### Arguments & Flags
- `--diff=<diff_file>`: Unified or structural diff file to apply.
- `--line-start=<N>`: Target start line (1-indexed) for surgical replacement.
- `--line-end=<N>`: Target end line (1-indexed) for surgical replacement.
- `--replacement=<file>`: File containing replacement code snippet.
- `--dry-run`: Validate patch against AST without modifying the target file.

### Example Execution
```bash
aipl patch src/main.aipl --dry-run --diff=update.patch
aipl patch src/engine.aipl --line-start=45 --line-end=52 --replacement=new_fn.aipl
```

---

## 23. `aipl schema`

Draft 2020-12 JSON Schema extractor and bidirectional AIPL struct synthesizer. Extracts standardized schemas from AIPL struct definitions, or synthesizes type-safe AIPL structs and serialization logic from existing JSON Schemas.

### Syntax
```bash
aipl schema [target] [OPTIONS]
```

### Arguments & Flags
- `--extract`: Extract JSON Schema from AIPL source structs (default mode).
- `--synthesize=<schema>`: Synthesize AIPL struct definitions from a JSON Schema file.
- `-o <path>`: Output destination file (defaults to stdout).
- `--ast`: Emit the official JSON schema for AIPL AST nodes.
- `--diagnostics`: Emit the `ADR-0023` single-root compiler diagnostic schema.

### Example Execution
```bash
# Extract JSON schema from struct models
aipl schema src/models.aipl -o schemas/models.json

# Synthesize AIPL nominal struct definitions from JSON schema
aipl schema --synthesize=schemas/config.json -o src/config.aipl

# Inspect ADR-0023 single-root diagnostic schema
aipl schema --diagnostics
```

---

## 24. `aipl fuzz`

Property-based and mutational fuzz testing harness. Generates coverage-guided AST and lexical fuzz mutations to discover edge cases, validate refinement type invariants, and detect crash regressions.

### Syntax
```bash
aipl fuzz <file.aipl> [OPTIONS]
```

### Arguments & Flags
- `--runs=<N>`: Maximum number of mutation iterations (default: 10,000).
- `--seed=<N>`: Deterministic pseudo-random seed for reproducibility.
- `--timeout=<ms>`: Execution timeout per run in milliseconds (default: 1,000ms).
- `--corpus=<dir>`: Directory containing seed input corpus files.
- `--json`: Emit failure diagnostics and crash seeds as structured JSON.

### Example Execution
```bash
aipl fuzz tests/fuzz/parser_fuzz.aipl
aipl fuzz src/main.aipl --runs=50000 --seed=1337 --timeout=500
```

---

## 25. `aipl conductor`

Multi-Agent Concurrency Contracts & Deterministic Worktree Arbitration engine. Validates multi-agent write scope disjointness ($\text{Scope}(A) \cap \text{Scope}(B) = \emptyset$), checks AST symbol reservations, and computes deterministic worktree merge order.

### Syntax
```bash
aipl conductor [manifest.json] [--json]
```

### Invariants & Guarantees
- **Scope Disjointness**: Enforces that concurrently operating AI agents possess non-overlapping file write paths.
- **Frozen Contract Protection**: Halts build if core interface definitions or SSOT specifications are modified out-of-turn.
- **Worktree Reintegration**: Validates clean mergeability before Git fast-forward commits.

### Example Execution
```bash
aipl conductor
aipl conductor manifest.json --json
```

---

## 26. `aipl bootstrap`

Three-stage self-hosting fixed-point compiler verification engine. Validates that the AIPL compiler can compile itself reproducibly without divergence.

### Stages
1. **Stage 1**: Compiles `compiler/main.aipl` with active compiler binary.
2. **Stage 2**: Compiles `compiler/main.aipl` using the Stage 1 binary.
3. **Stage 3**: Compiles `compiler/main.aipl` using the Stage 2 binary.
4. **Fixed-Point Verification**: Asserts $\text{SHA256}(\text{Stage 2 Output}) == \text{SHA256}(\text{Stage 3 Output})$, updates `./bin/aipl` and `~/.local/bin/aipl`.

### Syntax
```bash
aipl bootstrap
```

---

## 27. `aipl window`, `aipl screenshot` & `aipl record`

Inspects, captures, and controls live hardware-accelerated AIPL canvas windows via IPC. Enables autonomous agents and testing referee bots (HEBAR) to inspect framebuffers and inject simulated inputs.

### Syntax
```bash
aipl window list
aipl window screenshot <target> <out_path>
aipl window record <target> <out_path> [--frames <N>] [--fps <fps>]
aipl window action <target> <bot_script>
aipl screenshot <target> <out_path>
aipl record <target> <out_path> [--frames <N>] [--fps <fps>]
```

### Subcommands & Aliases
- `window list`: Lists all active AIPL windows and process IDs.
- `window screenshot <target> <out_path>` (alias: `aipl screenshot`): Synchronously captures window framebuffer to PNG/JPEG image.
- `window record <target> <out_path>` (alias: `aipl record`): Records targeted window video stream with specified frame count and FPS.
- `window action <target> <bot_script>`: Injects simulated keyboard/pointer inputs and resize events into the targeted window.

### Windowed Frame Pacing, Screenshot & Benchmark Flags (`aipl run`)
- `--frames <N>` / `--max-frames=<N>`: Runs for `N` frames. In interactive windowed mode (`X11`/`GLX`), `CLOCK_MONOTONIC` `nanosleep` frame pacing remains active (default `60 FPS`) so `--frames` runs at human-observable speed; in headless mode (`--headless`), `nanosleep` is bypassed for maximum test throughput.
- `--unlocked-fps` / `--benchmark-window-fps` (or `AIPL_UNLOCKED_FPS=1`): Explicitly disables windowed frame pacing so windowed benchmarks run uncapped.
- `--screenshot <path>`: Captures a screenshot on exit (`frame == maxFrames - 1`). If the application already called `saveScreenshot(path)` in-loop to the same file path, the exit hook preserves the in-loop capture unless `--screenshot-on-exit` is passed. In GLX mode, `saveScreenshot` automatically calls `_aipl_sync_gl_to_fb()` (`glReadPixels`) before writing so live OpenGL VRAM pixels are captured.
- `--screenshot-on-exit`: Forces `--screenshot <path>` to overwrite the output file on the final frame even if `saveScreenshot(path)` was called earlier in the loop.

### Example Execution
```bash
aipl window list
aipl screenshot main_window screen.png
aipl record main_window demo.mp4 --frames=300 --fps=60
```

---

## Part II: `aipl-rt` Standalone Runtime CLI Reference

The `aipl-rt` binary provides standalone Ahead-Of-Time (AOT) execution, cold-start benchmarking, packaging, and DAP debugging.

```bash
aipl-rt <command> [arguments...] [flags...]
```

| Command | Arguments | Description |
| :--- | :--- | :--- |
| `package` | `<stub> <payload> -o <output_binary> [--asset <asset_path>]` | Appends trailer overlay to stub |
| `inspect` | `<standalone_binary>` | Verifies CRC32 and extracts trailer metadata |
| `run` | `<artifact.cwasm\|file.wasm> [--bench] [--iterations N] [--window] [--headless]` | Executes AOT module with sub-100µs cold start |
| `compile` | `<file.wasm\|file.wat> -o <artifact.cwasm>` | Compiles Wasm/WAT to Cranelift native machine code |
| `bench` | `<artifact.cwasm> [--iterations N] \| --soak [--duration <duration>]` | Benchmarks cold-start latency or runs continuous soak |
| `dap` | `[--port <port>] [--stdio]` | Runs DAP debug server |
| `debug` | `<artifact>` | Interactive DWARF debugger |
| `--version` / `-v` | | Displays runtime version |
| `--help` / `-h` | | Displays runtime command reference |

---

## Part III: `aipl-shield` Standalone Filesystem Shield CLI Reference

The `aipl-shield` standalone binary enforces the 4-layer defense-in-depth filesystem shield protecting Single-Source-of-Truth architecture specifications.

```bash
aipl-shield <command> [flags...]
```

| Command | Flags | Description |
| :--- | :--- | :--- |
| `lock` | `[--hook]` | Sets `chmod 0444` on SSOT files, writes `.aipl/manifest.sha256`, installs git hook |
| `unlock` | | Restores `chmod 0644` read-write permissions for authorized human maintainers |
| `verify` | `[--json]` | Validates cryptographic SHA-256 digests and file permissions |
| `status` | | Queries current shield protection metrics and tracking state |
| `eject` | | Cleanly strips all shield layers, restores 0644, and uninstalls hooks |
| `--version` / `-v` | | Displays shield version |
| `--help` / `-h` | | Displays shield command reference |



## 12. `aipl verify`

Performs complete static lexical, syntactic, type-checking, and SMT refinement verification on an AIPL source file, emitting machine-actionable single-root JSON (`ADR-0023`). Transparently runs the idempotent shortest-syntax source canonicalizer on the entry `.aipl` file and resolved project modules on disk (unless `AIPL_NO_AUTO_FMT=1` is set). Optionally verifies compiled binary size against strict budget limits via `--check-budget`.

### `aipl fmt`
Formats and canonicalizes AIPL source code into the shortest canonical AIPL form: 2-space indentation (`:` over `{}`), `ret` over `return`, `elif` over `else if`, `): Type` over `) -> Type`, `and`/`or`/`not` over `&&`/`||`/`!`, single-line `fn(...)` and `struct Name(...)` declarations, and canonical `import { ... } from "std/..."` imports. Automatically triggered on disk during `verify`, `check`, `build`, `run`, `test`, `transpile`, `lint`, `fmt`, `fix`, and `wire`.

```bash
aipl fmt <file.aipl> [--check] [--stdin]
```

- `--check`: Dry-run format verification. Exits with code `0` if the file is properly formatted, or exit code `1` if formatting is required.
- `--stdin`: Reads unformatted source code from standard input (`/dev/stdin`) and prints formatted code directly to standard output. Enables seamless editor formatting pipes (VS Code, Zed, Neovim).
