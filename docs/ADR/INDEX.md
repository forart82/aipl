# Architecture Decision Records (ADRs) Catalog (v0.9.0)
**Single Source of Truth (SSOT) — Master Architectural Registry**

[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](../STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

> **When to Read This Document**: Read this catalog to understand the architectural decisions, trade-offs, and design rationales behind AIPL. It catalogs all 37 Architecture Decision Records (`ADR-0001` through `ADR-0037`), grouped by subsystem and status.

---

## Canonical Architectural Inventory

- **Total Architecture Decision Records**: `37` Active & Accepted ADRs (`ADR-0001` to `ADR-0037`).
- **Standard Library Domains**: `38` domain groups (`std_root`/`prelude` + `37` domain subdirectories = `298` modules).
- **Callable Functions**: `4,379` functions (`32` compiler built-ins + `4,347` standard library functions & methods).
- **Curated Examples & Twin Tests**: `263` examples (`ex_001`..`ex_263`) and `263` 1-to-1 twin tests in `tests/examples/`.
- **Compiler Subsystems**: `11` self-hosted compiler modules in `compiler/*.aipl`.

---

## Master ADR Index Table

| ADR ID | Title | Category | Status | Primary Target File | Summary |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **ADR-0001** | [Dual-Backend Early Bifurcation at Canonical HIR](ADR-0001-dual-backend-early-bifurcation.md) | Compiler Architecture | `Accepted` | `compiler/hir.aipl` | Bifurcates Canonical HIR into TypeScript/React 19 for web/edge and C99/Native/Wasm for bare metal. |
| **ADR-0002** | [Gemini 256k SentencePiece Tokenomics & camelCase Invariant](ADR-0002-sp256k-tokenomics-camelcase-invariant.md) | Tokenomics & Syntax | `Accepted` | `compiler/lexer.aipl` | Eliminates token fragmentation via camelCase identifiers, 2-space indentation, and subword-aligned keywords. |
| **ADR-0003** | [Bump Arena Pratt Parser & Resilient Checkpointing](ADR-0003-oxc-bump-arena-pratt-parser.md) | Frontend Parser | `Accepted` | `compiler/parser.aipl` | Implements zero-GC arena allocation for AST nodes with Pratt operator-precedence parsing and error recovery. |
| **ADR-0004** | [Anti-GC Flat Stride Memory & Task-Local Regional Arenas](ADR-0004-anti-gc-flat-stride-memory.md) | Memory Architecture | `Accepted` | `std/alloc/arena.aipl` | Guarantees 100% 64-byte L1d cache utilization via Structure of Arrays (SoA) layout and scoped regional bump allocators. |
| **ADR-0005** | [Wasmtime AOT & Sub-100µs In-Memory mmap Standalone Engine](ADR-0005-wasmtime-aot-mmap-standalone-engine.md) | Native Engine | `Accepted` | `compiler/codegen_wasm.aipl` | Enables sub-100µs cold-start execution for standalone Wasm binaries via memory-mapped precompiled machine code. |
| **ADR-0006** | [Native Desktop Graphics via wgpu + winit (Zero Electron)](ADR-0006-wgpu-winit-native-graphics.md) | Graphics Runtime | `Accepted` | `std/rt/rt_canvas_x11.aipl` | Provides hardware-accelerated 2D/3D graphics and windowing without web engine overhead. |
| **ADR-0007** | [Deno/Bun-Style Binary Trailer Overlay Packaging](ADR-0007-binary-trailer-overlay-packaging.md) | Packaging | `Accepted` | `compiler/main.aipl` | Appends bytecode and asset payloads to native executable trailers for zero-dependency standalone distribution. |
| **ADR-0008** | [4-Layer Defense-in-Depth Filesystem Shield (chmod 444)](ADR-0008-four-layer-filesystem-shield.md) | Agent Security | `Accepted` | `tools/pre-commit-shield.sh`| Protects codebase integrity during autonomous AI execution via sandbox isolation, path jails, and read-only locks. |
| **ADR-0009** | [Sound Bidirectional Type Checking & Zero Coercion](ADR-0009-bidirectional-type-checking-zero-coercion.md) | Type System | `Accepted` | `compiler/types.aipl` | Prevents runtime type bugs with sound local type inference, explicit conversions, and strict boolean truthiness. |
| **ADR-0010** | [Algebraic Result, Option & Postfix '?' Desugaring](ADR-0010-algebraic-result-option-postfix-try-desugaring.md) | Error Handling | `Accepted` | `compiler/parser.aipl` | Eliminates unchecked exceptions via algebraic sum types and postfix `?` error propagation. |
| **ADR-0011** | [Lightweight Embedded SMT Refinement Solving (QF-LIA & EUF)](ADR-0011-lightweight-embedded-smt-refinement-solving.md) | Verification | `Accepted` | `compiler/smt.aipl` | Proves `req:`/`ens:` contracts, eliminates bounds checks, and refutes arithmetic errors at compile time. |
| **ADR-0012** | [Three-Tier Anti-GC Memory Model: Task Arenas & Acyclic ARC](ADR-0012-three-tier-memory-model-task-arenas-acyclic-arc.md) | Memory Architecture | `Accepted` | `docs/MEMORY_MODEL.md` | Combines stack bump arenas, generational object pools, and cycle-free atomic reference counting. |
| **ADR-0013** | [Single-Root JSON Diagnostic Schema & Exact Byte Locator](ADR-0013-single-root-json-diagnostic-schema-exact-byte-locator.md) | Diagnostics | `Accepted` | `docs/DIAGNOSTICS_SCHEMA.md`| Emits machine-readable `diagnostic-v1.json` with exact byte spans and unified diff repair candidates. |
| **ADR-0014** | [Poisoned-Symbol Tainting & Cascade Suppression Engine](ADR-0014-poisoned-symbol-tainting-cascade-suppression.md) | Diagnostics | `Accepted` | `compiler/types.aipl` | Suppresses misleading downstream diagnostic cascades when a symbol fails earlier type resolution. |
| **ADR-0015** | [Pre-Calculated AST Diff Repairs & Zero-Drift Patch Engine](ADR-0015-pre-calculated-ast-diff-repairs.md) | Autonomous Tooling | `Accepted` | `docs/AGENT_TOOLING.md` | Computes deterministic AST patch diffs allowing AI agents to self-repair syntax and type errors safely. |
| **ADR-0016** | [Salsa-Style Incremental Query DAG & Sub-5ms Re-emit SLA](ADR-0016-salsa-incremental-query-dag.md) | Compiler Pipeline | `Accepted` | `compiler/hir.aipl` | Caches AST, HIR, and type signatures in an incremental dependency graph for sub-5ms rebuild times. |
| **ADR-0017** | [Idiomatic TypeScript & React 19 JSX Lowering Architecture](ADR-0017-idiomatic-typescript-react-19-jsx-lowering.md) | Web Lowering | `Accepted` | `compiler/codegen_ts.aipl`| Generates idiomatic, type-checked TypeScript 5.x and React 19 JSX components for browser integration. |
| **ADR-0018** | [Data-Oriented Struct Lowering to Contiguous Flat ArrayBuffers (SoA)](ADR-0018-data-oriented-struct-lowering-flat-arraybuffers.md) | Memory Architecture | `Accepted` | `std/ecs/archetype.aipl` | Lowers high-level structs into contiguous typed ArrayBuffers for high-throughput zero-copy SIMD and GPU transfer. |
| **ADR-0019** | [Zero-Allocation WebGL2 Streaming & Staging Rings](ADR-0019-zero-allocation-webgl2-webgpu-streaming.md) | Graphics Runtime | `Accepted` | `std/gfx/gpu_buffer.aipl`| Streams vertex, index, and uniform data through mapped ring buffers without GC memory allocations. |
| **ADR-0020** | [Static Shader Verification & std140/WGSL Alignment](ADR-0020-static-shader-verification-std140-wgsl.md) | Graphics Runtime | `Accepted` | `std/gfx/shader.aipl` | Validates WGSL shader struct layouts against CPU memory alignments (std140/std430) during compilation. |
| **ADR-0021** | [Multi-Target SSOT Emission & Dual-String Architecture](ADR-0021-multi-target-ssot-emission-dual-strings.md) | Core Architecture | `Accepted` | `compiler/ast.aipl` | Ensures behavioral parity across all emission backends from a single canonical language representation. |
| **ADR-0022** | [Headless Tokio Reactor, WASI 0.2/0.3 & Capability Sandboxing](ADR-0022-wasi-tokio-capability-sandboxing.md) | Sandboxing | `Accepted` | `std/os/sandboxed_fs.aipl`| Restricts file, network, and clock capabilities to explicit capability handles under WASI and headless runtimes. |
| **ADR-0023** | [Native WebAssembly DWARF (v4/v5) Debugging & DAP Integration](ADR-0023-wasm-dap-dwarf-debugging.md) | Debugging | `Accepted` | `docs/DEBUGGING.md` | Generates DWARF v4/v5 debug info and integrates with Debug Adapter Protocol (DAP) for IDE debugging. |
| **ADR-0024** | [Lossless Concrete Syntax Tree (CST) & Bidirectional Lens Laws](ADR-0024-lossless-cst-lens-laws.md) | Infrastructure | `Accepted` | `compiler/ast.aipl` | Maintains comments and whitespace fidelity across AST transformations via bidirectional lens laws. |
| **ADR-0025** | [Surgical AST Splicing, Skeletonization & Self-Repair](ADR-0025-surgical-ast-splicing-skeletonization.md) | Autonomous Tooling | `Accepted` | `docs/AGENT_TOOLING.md` | Provides `aipl outline` and `aipl splice` for surgical sub-function replacement by AI agents. |
| **ADR-0026** | [Zero-Build Browser Ingestion Loader (aipl-web.js)](ADR-0026-zero-build-browser-ingestion-loader.md) | Web Deployment | `Accepted` | `docs/BROWSER_ZERO_BUILD.md`| Executes AIPL source directly in the browser via in-worker compilation and Blob URL module loading. |
| **ADR-0027** | [Continuous Soak Testing & Zero-GC-Spike Memory Guarantee](ADR-0027-soak-testing-zero-gc-spike-guarantee.md) | Quality Assurance | `Accepted` | `docs/BENCHMARKS.md` | Enforces 10,000-cycle continuous memory soak tests with flat heap profiles and zero latency spikes. |
| **ADR-0028** | [Autonomous LLM Coding Agent Benchmark Matrix (60% Reduction)](ADR-0028-llm-tokenomics-agent-benchmark-matrix.md) | Tokenomics | `Accepted` | `docs/BENCHMARKS.md` | Continuously benchmarks agent token efficiency against Python, Rust, and TypeScript baselines. |
| **ADR-0029** | [100% Pure AIPL Self-Hosting, C99 Backend & 3-Stage Bootstrap](ADR-0029-pure-aipl-self-hosting-and-c99-backend.md) | Bootstrap | `Accepted` | `docs/ARCHITECTURE.md` | Establishes language sovereignty through 100% self-hosted compiler and deterministic 3-stage bootstrap fixed point. |
| **ADR-0030** | [Unboxed C99 Static Specialization & Numeric Intrinsics](ADR-0030-unboxed-c99-static-specialization.md) | Codegen | `Accepted` | `compiler/codegen_c_or_ir.aipl`| Specializes generic primitives and unboxed structs directly into native C scalar types and flat buffers. |
| **ADR-0031** | [Scoped Region Arena Memory Reclamation & Zero-Pause Determinism](ADR-0031-scoped-region-arena-memory-reclamation.md) | Memory Architecture | `Accepted` | `std/alloc/arena.aipl` | Reclaims frame and task allocations deterministically at scope exit with zero stop-the-world pauses. |
| **ADR-0032** | [Compiler JSON Schema Reflection & Standard AI Client Integration](ADR-0032-compiler-json-schema-and-std-ai.md) | AI Integration | `Accepted` | `std/ai/` | Reflects compiler types into standard JSON schemas and provides native AI client interfaces in `std/ai/`. |
| **ADR-0033** | [Zero-FFI Dynamic C Interop & Headless Desktop Canvas Blitter](ADR-0033-zero-ffi-c-interop-and-desktop-canvas.md) | Runtime | `Accepted` | `std/rt/rt_canvas_x11.aipl`| Integrates dynamic C ABI bindings and software/hardware canvas blitting with headless CI verification. |
| **ADR-0034** | [Native Android NDK NativeActivity, ANativeWindow RGBA Blitter, AAudio & Touch Bridge](ADR-0034-android-ndk-native-activity-and-touch-bridge.md) | Mobile Systems | `Accepted` | `std/sys/sys_android.aipl` | Direct native activity execution, hardware surface blitting, low-latency AAudio streaming, and isolated touch input. |
| **ADR-0035** | [Smartphone AIPL Watcher, Embedded Offline VFS & Stateful Hot-Reload](ADR-0035-smartphone-aipl-watcher-and-stateful-hot-reload.md) | Mobile Systems | `Accepted` | `std/fs/android_vfs.aipl` | Offline 281-module embedded VFS, 50ms debounced file watcher, LAN live-reload receiver, and stateful bytecode hot-swapping. |
| **ADR-0036** | [Single-App Android Container & Zero-NDK APK Packager](ADR-0036-single-app-android-container-and-zero-ndk-apk-packager.md) | Packaging | `Accepted` | `std/asset/apk_container_format.aipl` | Standalone single-app APK packaging, locked container execution, deterministic ZIP alignment, and APK Signature Scheme v2. |
| **ADR-0037** | [Continuous 2.5D/3D World Engine, Hardware/Software Z-Buffering & Per-Vertex Gouraud Pipeline](ADR-0037-continuous-25d-world-and-zbuffer-pipeline.md) | Graphics & Referee | `Accepted` | `std/gfx25d/gfx25d_mod.aipl` | Continuous 2.5D/3D isometric camera, heightfield/ribbon/volumetric meshes, hardware/software Z-buffering, per-vertex Gouraud shading, and 5-bound HEBAR referee. |

---

## Detailed Architectural Groupings

### 1. Core Compiler & Language Design
- **[ADR-0001: Dual-Backend Early Bifurcation at Canonical HIR](ADR-0001-dual-backend-early-bifurcation.md)**: Establishes the Canonical HIR early bifurcation into TypeScript/React 19 for web/edge and ANSI C99 / WebAssembly for native bare-metal targets.
- **[ADR-0002: SentencePiece 256k Tokenomics & camelCase Invariant](ADR-0002-sp256k-tokenomics-camelcase-invariant.md)**: Enforces subword-aligned syntax, camelCase identifiers, and 2-space indentation to achieve 60%+ token reduction for AI coding agents.
- **[ADR-0003: Bump Arena Pratt Parser & Resilient Checkpointing](ADR-0003-oxc-bump-arena-pratt-parser.md)**: Employs bump-allocated AST parsing with Pratt operator precedence and resilient parser error recovery.
- **[ADR-0009: Sound Bidirectional Type Checking & Zero Coercion](ADR-0009-bidirectional-type-checking-zero-coercion.md)**: Mandates local bidirectional inference and rejects implicit numeric or boolean type coercions.
- **[ADR-0010: Algebraic Result, Option & Postfix '?' Desugaring](ADR-0010-algebraic-result-option-postfix-try-desugaring.md)**: Formalizes zero-cost algebraic sum types (`Result[T, E]`, `Option[T]`) and postfix error propagation.
- **[ADR-0011: Lightweight Embedded SMT Refinement Solving](ADR-0011-lightweight-embedded-smt-refinement-solving.md)**: Integrates compile-time constraint verification for Design-by-Contract (`req:`/`ens:`) invariants.
- **[ADR-0016: Salsa-Style Incremental Query DAG](ADR-0016-salsa-incremental-query-dag.md)**: Guarantees sub-5ms re-emit cycles through fine-grained dependency tracking.
- **[ADR-0021: Multi-Target SSOT Emission & Dual-String Architecture](ADR-0021-multi-target-ssot-emission-dual-strings.md)**: Single source of truth code generation guaranteeing behavioral parity across native and web runtimes.
- **[ADR-0024: Lossless Concrete Syntax Tree (CST) & Bidirectional Lens Laws](ADR-0024-lossless-cst-lens-laws.md)**: Preserves comments, whitespace, and formatting for lossless AST rewrites.
- **[ADR-0029: 100% Pure AIPL Self-Hosting, C99 Backend & 3-Stage Bootstrap](ADR-0029-pure-aipl-self-hosting-and-c99-backend.md)**: Fixed-point self-hosting sequence guaranteeing `sha256(stage2) == sha256(stage3)`.
- **[ADR-0030: Unboxed C99 Static Specialization](ADR-0030-unboxed-c99-static-specialization.md)**: Lowers unboxed structs and primitives into contiguous native C memory layouts.

### 2. Memory Model & Zero-GC Systems
- **[ADR-0004: Anti-GC Flat Stride Memory & Task-Local Arenas](ADR-0004-anti-gc-flat-stride-memory.md)**: Structure of Arrays (SoA) layouts maximizing 64-byte L1d cache efficiency without tracing GC.
- **[ADR-0012: Three-Tier Anti-GC Memory Model: Task Arenas & Acyclic ARC](ADR-0012-three-tier-memory-model-task-arenas-acyclic-arc.md)**: Combines regional arenas, object pools, and cycle-free reference counting.
- **[ADR-0018: Data-Oriented Struct Lowering to Flat ArrayBuffers](ADR-0018-data-oriented-struct-lowering-flat-arraybuffers.md)**: Direct lowering to typed ArrayBuffers for high-performance JavaScript/Wasm interop.
- **[ADR-0027: Continuous Soak Testing & Zero-GC-Spike Memory Guarantee](ADR-0027-soak-testing-zero-gc-spike-guarantee.md)**: Automated 10,000-cycle soak tests proving zero memory leak and flat latency curves.
- **[ADR-0031: Scoped Region Arena Memory Reclamation](ADR-0031-scoped-region-arena-memory-reclamation.md)**: Deterministic O(1) memory cleanup at scope boundary exits.

### 3. Runtimes, Backends & Targets
- **[ADR-0005: Wasmtime AOT & Sub-100µs mmap Standalone Engine](ADR-0005-wasmtime-aot-mmap-standalone-engine.md)**: Sub-100µs cold-start standalone execution.
- **[ADR-0006: Native Desktop Graphics via wgpu + winit](ADR-0006-wgpu-winit-native-graphics.md)**: Hardware-accelerated native windowing without Chromium/Electron.
- **[ADR-0007: Deno/Bun-Style Binary Trailer Overlay Packaging](ADR-0007-binary-trailer-overlay-packaging.md)**: Appending compiled bytecode trailers to single-file executables.
- **[ADR-0017: Idiomatic TypeScript & React 19 JSX Lowering](ADR-0017-idiomatic-typescript-react-19-jsx-lowering.md)**: Emits pristine, human-readable TypeScript for modern web stacks.
- **[ADR-0019: Zero-Allocation WebGL2 Streaming & Staging Rings](ADR-0019-zero-allocation-webgl2-webgpu-streaming.md)**: Mapped GPU staging rings avoiding per-frame heap allocations.
- **[ADR-0020: Compile-Time Static Shader Verification (std140/WGSL)](ADR-0020-static-shader-verification-std140-wgsl.md)**: Compile-time alignment validation between CPU structures and GPU shaders.
- **[ADR-0022: Headless Tokio Reactor, WASI 0.2/0.3 & Capability Sandboxing](ADR-0022-wasi-tokio-capability-sandboxing.md)**: Fine-grained capability-based security model.
- **[ADR-0023: Native WebAssembly DWARF (v4/v5) Debugging & DAP Integration](ADR-0023-wasm-dap-dwarf-debugging.md)**: Source-level step debugging across VS Code and Cursor.
- **[ADR-0026: Zero-Build Browser Ingestion Loader (aipl-web.js)](ADR-0026-zero-build-browser-ingestion-loader.md)**: Browser runtime running `.aipl` files directly with zero bundling steps.
- **[ADR-0033: Zero-FFI Dynamic C Interop & Headless Desktop Canvas Blitter](ADR-0033-zero-ffi-c-interop-and-desktop-canvas.md)**: Native C ABI interop and headless-verified X11/software canvas blitter.
- **[ADR-0034: Native Android NDK NativeActivity, ANativeWindow RGBA Blitter, AAudio & Touch Bridge](ADR-0034-android-ndk-native-activity-and-touch-bridge.md)**: Native Android execution, hardware surface blitting, AAudio stream, and multi-touch isolation.
- **[ADR-0035: Smartphone AIPL Watcher, Embedded Offline VFS & Stateful Hot-Reload](ADR-0035-smartphone-aipl-watcher-and-stateful-hot-reload.md)**: Embedded offline 281-module VFS, file observer debouncing, LAN live-reload sync, and stateful bytecode hot-swap.
- **[ADR-0036: Single-App Android Container & Zero-NDK APK Packager](ADR-0036-single-app-android-container-and-zero-ndk-apk-packager.md)**: Zero-NDK APK packaging, locked container mode, deterministic ZIP alignment, and APK v2 signature block.
- **[ADR-0037: Continuous 2.5D/3D World Engine, Hardware/Software Z-Buffering & Per-Vertex Gouraud Pipeline](ADR-0037-continuous-25d-world-and-zbuffer-pipeline.md)**: Hardware/software Z-buffering, per-vertex Gouraud interpolation, X11 alpha lock, `std/gfx25d/` continuous world engine, and 5-bound HEBAR referee.

### 4. AI Agent Tooling & Diagnostics
- **[ADR-0008: 4-Layer Defense-in-Depth Filesystem Shield](ADR-0008-four-layer-filesystem-shield.md)**: Sandbox protections preventing unintended file modifications during agent execution.
- **[ADR-0013: Single-Root JSON Diagnostic Schema & Exact Byte Locator](ADR-0013-single-root-json-diagnostic-schema-exact-byte-locator.md)**: Structured `diagnostic-v1.json` output for automated agent tooling.
- **[ADR-0014: Poisoned-Symbol Tainting & Cascade Suppression Engine](ADR-0014-poisoned-symbol-tainting-cascade-suppression.md)**: Shields agents from confusing secondary error cascades.
- **[ADR-0015: Pre-Calculated AST Diff Repairs & Zero-Drift Patch Engine](ADR-0015-pre-calculated-ast-diff-repairs.md)**: Provides automated unified-diff repair candidates for common syntax and type errors.
- **[ADR-0025: Surgical AST Splicing, Skeletonization & Autonomous Self-Repair](ADR-0025-surgical-ast-splicing-skeletonization.md)**: `aipl outline` and `aipl splice` enabling token-efficient localized edits.
- **[ADR-0028: Autonomous LLM Coding Agent Benchmark Matrix](ADR-0028-llm-tokenomics-agent-benchmark-matrix.md)**: Automated token efficiency benchmarks across leading LLMs.
- **[ADR-0032: Compiler JSON Schema Reflection & Standard AI Client Integration](ADR-0032-compiler-json-schema-and-std-ai.md)**: Automated tool-calling schema generation and native `std/ai/` interfaces.

---

## Runnable Verification Suite

The following runnable AIPL test validates that markdown headings and ADR structures can be correctly ingested and parsed by the standard library:

```aipl
module tests.functions.encoding.markdown_adr_suite_test
import { extractMarkdownHeadings, markdownToHtml } from "std/encoding/markdown"
import { assert, assertEqInt, assertEqStr } from "std/prelude"

pub fn test_adr_markdown_heading_extraction(): int:
  let mdSource = "# ADR-0001: Dual-Backend Early Bifurcation at Canonical HIR\n\n## Status\n\nAccepted"
  let headings = extractMarkdownHeadings(mdSource)
  let htmlOut = markdownToHtml(mdSource)
  assertEqInt(headings.len(), 2, "ADR markdown contains H1 title and H2 status headings")
  assertEqStr(headings[0].text, "ADR-0001: Dual-Backend Early Bifurcation at Canonical HIR", "H1 heading matches verbatim ADR title")
  assert(htmlOut.contains("<h1>ADR-0001: Dual-Backend Early Bifurcation at Canonical HIR</h1>"), "HTML output renders verbatim ADR H1 heading")
  ret 0
```
