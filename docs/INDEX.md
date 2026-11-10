# AIPL Documentation Index & Progressive Learning Map (v0.9.0)
**Single Source of Truth (SSOT) — Master Navigation Hub**

[Home](../README.md) | [Docs Index](INDEX.md) | [Tutorials](TUTORIAL.md) | [Cookbook](COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](CLI_REFERENCE.md)

> **When to Read This Document**: Read this master index to navigate all AIPL specifications, choose a progressive learning path tailored to your role, explore standard library domain references, and locate any of the 37 Architecture Decision Records (ADRs) or 263 curated examples.

---

## Canonical Project Architecture & Verification Counts

The AIPL language, compiler, standard library, and verification suite adhere to strict, verified architecture counts:
- **38 Standard Library Domain Groups**: `2` root modules (`std/std_root.aipl`, `std/prelude.aipl`) + `37` canonical domain subdirectories = **`299` `std/` modules** (`262` implementation/root modules + `37` barrel `*_mod.aipl` modules).
- **4,379 Total Callable Functions**: **`32` compiler built-ins + `4,347` `std/` functions, constructors & receiver methods**.
- **263 Curated, Fully-Tested Examples**: `examples/ex_001_*.aipl` through `examples/ex_263_*.aipl` with 1-to-1 twin unit tests in `tests/examples/ex_001_*_test.aipl` .. `tests/examples/ex_263_*_test.aipl`.
- **37 Architecture Decision Records (ADRs)**: `docs/ADR/ADR-0001-*.md` through `docs/ADR/ADR-0037-*.md` indexed in [`docs/ADR/INDEX.md`](ADR/INDEX.md).
- **Verification Suite**: 653 test suites (`263` example twin tests, `365` exhaustive function tests in `tests/functions/<domain>/`, `12` scenario tests in `tests/scenarios/`, and `13` complex application tests in `tests/complex/`).

---

## Section 1: Master Documentation Table of Contents & Standardized Navigation Header Contract

All documentation manuals within `docs/` follow a uniform, standardized navigation contract:
`[Home](../README.md) | [Docs Index](INDEX.md) | [Tutorials](TUTORIAL.md) | [Cookbook](COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](CLI_REFERENCE.md)`

### Core Manuals Directory

| Document | Path | Description | Target Audience |
| :--- | :--- | :--- | :--- |
| **Project README** | [`README.md`](../README.md) | Project manifesto, 60-second tour, tokenomics, quickstart, and feature highlights | All Developers & Agents |
| **Language Specification** | [`docs/SPEC.md`](SPEC.md) & [`SPEC.md`](../SPEC.md) | Complete formal language reference, lexical grammar, type system, and DB-contracts | Systems Engineers & Tool Authors |
| **Grammar & Syntax Guide** | [`docs/GRAMMAR_AND_SYNTAX.md`](GRAMMAR_AND_SYNTAX.md) | Formal EBNF grammar, token rules, operator precedence, and syntax reference | Language & Tooling Engineers |
| **Compiler Architecture** | [`docs/ARCHITECTURE.md`](ARCHITECTURE.md) | 11 self-hosted compiler subsystems, Canonical HIR, 3-stage bootstrap fixed point | Compiler Contributors |
| **Build & Targets Guide** | [`docs/BUILD_AND_TARGETS.md`](BUILD_AND_TARGETS.md) | Compilation targets (`native`, `c`, `ts`, `html`, `wasm`, `bytecode`, `android-arm64`, `apk`), flags & runtime | Application & Engine Developers |
| **Anti-GC Memory Model** | [`docs/MEMORY_MODEL.md`](MEMORY_MODEL.md) | 3-tier memory model: Task Arenas, Object Pools, ScratchPingPong, GPA telemetry | Systems Engineers |
| **Diagnostics Schema** | [`docs/DIAGNOSTICS_SCHEMA.md`](DIAGNOSTICS_SCHEMA.md) | Single-root `diagnostic-v1.json` catalog (`E1xx`, `E2xx`, `E3xx`) and AST auto-repair | AI Agents & Tool Authors |
| **Transpiler Guide** | [`docs/TRANSPILER_GUIDE.md`](TRANSPILER_GUIDE.md) | Pipeline A (TypeScript 5.x & React 19 JSX lowering) and C99 lowering rules | Web & Fullstack Developers |
| **Zero-Build Browser** | [`docs/BROWSER_ZERO_BUILD.md`](BROWSER_ZERO_BUILD.md) | Zero-build browser ingestion loader, Web Worker loop, and HTML5 canvas blitting | Web & Game Developers |
| **Debugging Guide** | [`docs/DEBUGGING.md`](DEBUGGING.md) | DAP server (`aipl dap`), CLI debugger (`aipl debug`), and DWARF v4/v5 inspection | All Developers |
| **Agent Tooling** | [`docs/AGENT_TOOLING.md`](AGENT_TOOLING.md) | Agent-first tooling, `aipl outline`, `aipl splice`, `aipl fix`, and HEBAR referee | AI Agents & Conductor |
| **Performance Benchmarks**| [`docs/BENCHMARKS.md`](BENCHMARKS.md) | Latency benchmarks, SentencePiece 256k tokenomics, and zero-GC guarantees | Performance Engineers |
| **CLI Reference** | [`docs/CLI_REFERENCE.md`](CLI_REFERENCE.md) | Complete CLI command manual (`run`, `build`, `check`, `test`, `verify`, `docs`) | All Developers & Agents |
| **ADR Catalog** | [`docs/ADR/INDEX.md`](ADR/INDEX.md) | Categorized index of 37 Architecture Decision Records (`ADR-0001`..`ADR-0037`) | Architects & Contributors |
| **AI Agent Invariants** | [`AI_SPEC.md`](../AI_SPEC.md) | Token-optimal idioms, 2-space indentation invariants, and zero-hallucination cheat sheet | AI Coding Agents |
| **Static HTML Portal** | [`docs/html/index.html`](html/index.html) | Standalone, zero-dependency, searchable dark/light mode HTML documentation portal | Offline & Web Readers |

```aipl
module tests.functions.core.std_root_stdlibLayerCount_test
import * from "std/std_root"
import * from "std/prelude"

pub fn test_std_root_stdlibLayerCount(): int:
  assertEqInt(stdlibLayerCount(), 6, "6 layers (0..5)")
  ret 0
```

---

## Section 2: Progressive Reading Paths by Developer & Agent Persona

To maximize learning velocity, AIPL documentation provides structured reading tracks tailored to 5 distinct developer and AI agent personas:

### Track 1: Language Beginner
1. Read the [60-Second Language Tour in README.md](../README.md#2-architecture--pipeline-breakdown).
2. Follow the [Step-by-Step Tutorial](TUTORIAL.md) from Chapter 1 (Hello World) to Chapter 5 (Data Structures).
3. Review canonical beginner examples: [`examples/ex_001_hello_world_and_io_cli.aipl`](../examples/ex_001_hello_world_and_io_cli.aipl) through [`examples/ex_015_sys_ffi_c_abi_bridge_cli.aipl`](../examples/ex_015_sys_ffi_c_abi_bridge_cli.aipl).
4. Experiment interactively with `./bin/aipl run examples/ex_001_hello_world_and_io_cli.aipl`.

### Track 2: Systems & Memory Engineer
1. Read the [Anti-GC Flat Memory Model](MEMORY_MODEL.md) for regional bump arenas, generational object pools, and zero-leak GPA telemetry.
2. Study [ADR-0004: Anti-GC Flat Stride Memory](ADR/ADR-0004-anti-gc-flat-stride-memory.md), [ADR-0012: Three-Tier Anti-GC Memory Model](ADR/ADR-0012-three-tier-memory-model-task-arenas-acyclic-arc.md), and [ADR-0031: Scoped Region Arena Memory Reclamation](ADR/ADR-0031-scoped-region-arena-memory-reclamation.md).
3. Review memory-intensive systems examples: [`examples/ex_031_math_quat_slerp_orientation_window.aipl`](../examples/ex_031_math_quat_slerp_orientation_window.aipl) through [`examples/ex_045_collections_hash_map_word_freq_cli.aipl`](../examples/ex_045_collections_hash_map_word_freq_cli.aipl).
4. Inspect native C99 emission in [Build & Targets Guide](BUILD_AND_TARGETS.md).

### Track 3: 2D/3D Game & Aura UI Developer
1. Read the [Zero-Build Browser Guide](BROWSER_ZERO_BUILD.md) and [Transpiler Guide](TRANSPILER_GUIDE.md).
2. Study [ADR-0006: Native Desktop Graphics via wgpu + winit](ADR/ADR-0006-wgpu-winit-native-graphics.md) and [ADR-0019: Zero-Allocation WebGL2 Streaming](ADR/ADR-0019-zero-allocation-webgl2-webgpu-streaming.md).
3. Explore the 145 interactive graphical showcases: [`examples/ex_131_window_app_loop_fixed_timestep_window.aipl`](../examples/ex_131_window_app_loop_fixed_timestep_window.aipl) through [`examples/ex_263_isometric_8dir_rig_and_lighting_lab_window.aipl`](../examples/ex_263_isometric_8dir_rig_and_lighting_lab_window.aipl).
4. Run with headless verification: `AIPL_HEADLESS=1 ./bin/aipl run examples/ex_131_window_app_loop_fixed_timestep_window.aipl`.

### Track 4: Compiler Contributor
1. Read the [Compiler Architecture Specification](ARCHITECTURE.md) covering the 11 subsystems (`compiler/*.aipl`).
2. Study the 3-stage bootstrap fixed-point sequence (`sha256(stage2) == sha256(stage3)`).
3. Review SMT contract solving in `compiler/smt.aipl` and Canonical HIR optimization in `compiler/hir.aipl`.
4. Consult the complete [Architecture Decision Records Catalog](ADR/INDEX.md).

### Track 5: Autonomous AI Coding Agent
1. Ingest [`AI_SPEC.md`](../AI_SPEC.md) for strict 2-space indentation offside rules, camelCase identifier conventions, and token-optimal idioms.
2. Ingest [`docs/DIAGNOSTICS_SCHEMA.md`](DIAGNOSTICS_SCHEMA.md) for machine-readable JSON error parsing and automated candidate repairs.
3. Utilize [`docs/AGENT_TOOLING.md`](AGENT_TOOLING.md) for `aipl outline`, `aipl splice`, `aipl fix`, and HEBAR referee validation.
4. Execute verification gates with `python3 tools/verify_doc_snippets.py`.

```aipl
module tests.functions.core.std_root_stdlibCanonicalDomains_test
import * from "std/std_root"
import * from "std/prelude"

pub fn test_std_root_stdlibCanonicalDomains(): int:
  let doms = stdlibCanonicalDomains()
  assertEqInt(doms.len(), 37, "37 domains")
  assertEqStr(doms[0], "sys", "first domain is sys")
  assertEqStr(doms[36], "mechanics", "last domain is mechanics")
  ret 0
```

---

## Section 3: Core Manuals, 12 Tutorials, 51 Cookbook Recipes & 37 ADRs Cross-Reference Matrix

Every manual in `docs/` is cross-referenced with tutorials, cookbook recipes, and architecture decision records:

| Domain / Area | Core Manual | Tutorial Chapters | Cookbook Recipes | Governing ADRs |
| :--- | :--- | :--- | :--- | :--- |
| **Core & Syntax** | [`docs/SPEC.md`](SPEC.md) | Chapters 01–03 | Recipes 01–10 | `ADR-0002`, `ADR-0009`, `ADR-0010`, `ADR-0024` |
| **Compiler Pipeline** | [`docs/ARCHITECTURE.md`](ARCHITECTURE.md) | Chapter 11 | Recipes 41–45 | `ADR-0001`, `ADR-0003`, `ADR-0011`, `ADR-0016`, `ADR-0029` |
| **Memory & Allocators**| [`docs/MEMORY_MODEL.md`](MEMORY_MODEL.md) | Chapter 04 | Recipes 11–18 | `ADR-0004`, `ADR-0012`, `ADR-0018`, `ADR-0027`, `ADR-0031` |
| **Diagnostics & AST** | [`docs/DIAGNOSTICS_SCHEMA.md`](DIAGNOSTICS_SCHEMA.md) | Chapter 12 | Recipes 46–50 | `ADR-0013`, `ADR-0014`, `ADR-0015`, `ADR-0025` |
| **Multi-Target Codegen**| [`docs/BUILD_AND_TARGETS.md`](BUILD_AND_TARGETS.md) | Chapters 05–06 | Recipes 19–25 | `ADR-0005`, `ADR-0007`, `ADR-0017`, `ADR-0021`, `ADR-0030`, `ADR-0034`, `ADR-0035`, `ADR-0036` |
| **Graphics & Audio** | [`docs/BROWSER_ZERO_BUILD.md`](BROWSER_ZERO_BUILD.md) | Chapters 07–08 | Recipes 26–33, 51 | `ADR-0006`, `ADR-0019`, `ADR-0020`, `ADR-0026`, `ADR-0033`, `ADR-0037` |
| **AI Agent Tooling** | [`docs/AGENT_TOOLING.md`](AGENT_TOOLING.md) | Chapter 10 | Recipes 34–40 | `ADR-0008`, `ADR-0022`, `ADR-0028`, `ADR-0032`, `ADR-0037` |
| **Debugging & Replay** | [`docs/DEBUGGING.md`](DEBUGGING.md) | Chapter 09 | Recipes 36–38 | `ADR-0023` |

```aipl
module tests.functions.encoding.markdown_z3_test
import * from "std/encoding/markdown"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_markdown_splitTableRowCells_3(): int:
  let arg_line = "test"
  let edge_line = "a"
  let resNom = splitTableRowCells(arg_line)
  let resEdge = splitTableRowCells(edge_line)
  assertEqInt(resNom.len(), 1, "splitTableRowCells nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "splitTableRowCells boundary resEdge.len() == 1")
  ret 0
```

---

## Section 4: 38-Domain Standard Library Reference & Verification Suite Lookup Table

The standard library encompasses 38 domain groups (`2` root modules + `37` canonical domain directories = `299` modules), structured across 6 hierarchical layers ($L_0$ to $L_5$):

| Layer | Domain Group | Implementations (`std/<domain>/`) | Unit Tests (`tests/functions/<domain>/`) | Curated Example Coverage |
| :--- | :--- | :--- | :--- | :--- |
| **$L_0$** | **Host & Memory Kernels** | `std/sys/`, `std/rt/`, `std/alloc/` | `tests/functions/sys/`, `rt/`, `alloc/` | `ex_011` .. `ex_030` |
| **$L_1$** | **Core Primitives & Math** | `std/std_root.aipl`, `std/prelude.aipl`, `std/math/`, `std/collections/`, `std/fmt/`, `std/regex/`, `std/time/` | `tests/functions/core/`, `math/`, `collections/`, `fmt/`, `regex/`, `time/` | `ex_001` .. `ex_010`, `ex_031` .. `ex_075` |
| **$L_2$** | **Serialization, Crypto & DB** | `std/encoding/`, `std/compress/`, `std/crypto/`, `std/db/` | `tests/functions/encoding/`, `compress/`, `crypto/`, `db/` | `ex_076` .. `ex_098` |
| **$L_3$** | **I/O, OS, Sync, Net & Test** | `std/io/`, `std/fs/`, `std/os/`, `std/sync/`, `std/thread/`, `std/net/`, `std/test/` | `tests/functions/io/`, `fs/`, `os/`, `sync/`, `thread/`, `net/`, `test/` | `ex_099` .. `ex_130` |
| **$L_4$** | **Media, 2D/2.5D/3D & UI** | `std/window/`, `std/input/`, `std/asset/`, `std/audio/`, `std/gfx/`, `std/gfx2d/`, `std/gfx25d/`, `std/gfx3d/`, `std/particle/`, `std/ui/` | `tests/functions/window/`, `input/`, `asset/`, `audio/`, `gfx/`, `gfx2d/`, `gfx25d/`, `gfx3d/`, `particle/`, `ui/` | `ex_131` .. `ex_200`, `ex_251` .. `ex_263` |
| **$L_5$** | **Simulation, AI & Capstone**| `std/ecs/`, `std/spatial/`, `std/phys2d/`, `std/phys3d/`, `std/procgen/`, `std/ai/`, `std/hebar/`, `std/mechanics/` | `tests/functions/ecs/`, `spatial/`, `phys2d/`, `phys3d/`, `procgen/`, `ai/`, `hebar/`, `mechanics/` | `ex_201` .. `ex_250` |
```aipl
module tests.functions.core.std_root_stdlibIsCanonicalDomain_test
import * from "std/std_root"
import * from "std/prelude"

pub fn test_std_root_stdlibIsCanonicalDomain(): int:
  assert(stdlibIsCanonicalDomain("math") == true, "math is canonical")
  assert(stdlibIsCanonicalDomain("ui") == true, "ui is canonical")
  assert(stdlibIsCanonicalDomain("") == false, "empty string false")
  assert(stdlibIsCanonicalDomain("foobar") == false, "foobar false")
  ret 0
```

---

## Section 5: Dual Markdown SSOT + Static HTML Portal (docs/html/index.html) Build & Audit Gate

AIPL enforces a dual-format documentation model:
1. **Markdown Single Source of Truth (SSOT)**: All canonical documentation is authored in Git-versioned Markdown under `docs/` and root (`README.md`, `SPEC.md`, `AI_SPEC.md`).
2. **Zero-Dependency Static HTML Documentation Portal (`docs/html/index.html`)**: Generated standalone documentation portal bundling all manuals, 38 stdlib domain references, 263 example links, instant fuzzy search (`Ctrl+K`), and Dark/Light mode theme switching with zero external network or CDN dependencies.

To verify documentation integrity across the entire repository:
```bash
# Verify all code blocks in documentation
python3 tools/verify_doc_snippets.py docs/INDEX.md docs/SPEC.md README.md

# Verify standard library basenames and imports
python3 tools/verify_stdlib.py --check-unique-basenames
```

```aipl
module tests.functions.encoding.markdown_z4_test
import * from "std/encoding/markdown"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_markdown_isTableSeparatorLine_4(): int:
  let arg_line = "test"
  let edge_line = "a"
  let resNom = isTableSeparatorLine(arg_line)
  let resEdge = isTableSeparatorLine(edge_line)
  assert(resNom == false, "isTableSeparatorLine nominal resNom == false")
  assert(resEdge == false, "isTableSeparatorLine boundary resEdge == false")
  ret 0
```
