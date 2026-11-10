# AIPL Multi-Target Build & Compilation Guide (v0.9.0)
**Single Source of Truth (SSOT) — Target Backends, Toolchain & Packaging**

[Home](../README.md) | [Docs Index](INDEX.md) | [Language Specification](SPEC.md) | [Grammar & Syntax](GRAMMAR_AND_SYNTAX.md) | [Compiler Architecture](ARCHITECTURE.md) | [CLI Reference](CLI_REFERENCE.md)

> **When to Read This Document**: Read this guide when configuring compilation targets, optimizing build performance, transpiling to TypeScript/HTML5, compiling native executables via C99 shards, or preparing standalone WebAssembly binaries.

---

## Canonical Project Architecture & Counts

- **38 Standard Library Domain Groups**: `2` root modules (`std/std_root.aipl`, `std/prelude.aipl`) + `37` canonical domain directories = **`299` `std/` modules** (`262` implementation/root modules + `37` barrel modules).
- **4,379 Total Callable Functions**: **`32` compiler built-ins + `4,347` `std/` functions, constructors & receiver methods**.
- **263 Curated, Fully-Tested Examples**: `examples/ex_001_*.aipl` through `examples/ex_263_*.aipl` with twin unit tests in `tests/examples/`.
- **37 Architecture Decision Records**: `docs/ADR/ADR-0001-*.md` through `docs/ADR/ADR-0037-*.md` indexed in [`docs/ADR/INDEX.md`](ADR/INDEX.md).
---

## 1. Supported Compilation Targets

The AIPL compiler (`bin/aipl`) implements **Early Bifurcation at Canonical HIR** (ADR-0001), lowering a single canonical representation into eight distinct target backends:

| Target Flag | Target Name | Output Artifact | Primary Use Case | Runtime Dependencies |
| :--- | :--- | :--- | :--- | :--- |
| `--target native` | Native Binary (Default) | Executable binary (`ELF64`, `Mach-O`, `PE`) | Standalone CLI & systems software | Zero (Static libc / C runtime) |
| `--target c` | ISO C99 Source | C99 source files (`.c` + `aipl_runtime.h`) | C interop, embedded systems, audit | Host C compiler (`gcc`, `clang`) |
| `--target ts` | TypeScript & React 19 | TypeScript files (`.ts`, `.tsx`) | Web applications, Node.js, edge workers | Node.js, Bun, or Deno |
| `--target html` | Single-File HTML5 Bundle | Standalone HTML5 file (`.html`) | Instant browser deployment, canvas games | Modern browser (zero build step) |
| `--target wasm` | WebAssembly & WASI | Standalone `.wasm` + WIT interface | Serverless edge, sandboxed plugins | WASI runner (Wasmtime, Wasmer) |
| `--target bytecode`| Bytecode VM | Bytecode payload (`.aiplc`) | Fast evaluation, REPL, live debugging | Internal AIPL VM |
| `--target android-arm64` | Android NDK Native | Native shared library (`libaipl_app.so`) | Android NativeActivity applications | Android NDK / Android libc |
| `--target apk` | Android Package Container | Signed APK package (`.apk`) | Standalone Android installable distribution | Android 8.0+ (API 26+) |

---

## 2. Compilation Workflows & CLI Commands

### 2.1 Native Standalone Compilation (`--target native`)
Compiles AIPL source to an optimized native binary by lowering Canonical HIR to parallel C99 shards and linking against the precompiled modular runtime archive (`.aipl/cache/v1/libaipl_rt-<hash16>.a`):

```bash
# Compile to a native binary
./bin/aipl build src/main.aipl -o dist/myapp

# Compile with maximum release optimizations
./bin/aipl build src/main.aipl -O2 -o dist/myapp
```

### 2.2 Pure ISO C99 Emission (`--target c`)
Emits clean, portable ANSI/ISO C99 code suitable for integration with existing C/C++ projects or embedded microcontrollers:

```bash
# Emit modular C99 source with #include <aipl_runtime.h>
./bin/aipl build src/main.aipl --target c -o dist/main.c

# Emit self-contained amalgamated C99 source with embedded runtime
./bin/aipl build src/main.aipl --c -o dist/amalgamated.c
```

### 2.3 Web & Edge TypeScript Transpilation (`--target ts`)
Translates Canonical HIR into idiomatic TypeScript 5.x and React 19 JSX code, preserving nominal struct shapes and generic type annotations:

```bash
# Transpile to TypeScript
./bin/aipl build src/main.aipl --target ts -o dist/main.ts
```

### 2.4 Zero-Dependency Single-File HTML5 Bundling (`--target html`)
Packages the entire application into a single, self-contained HTML file containing HTML, CSS, JavaScript, and WebGL/Canvas visual runtime. The output file has **zero external CDN or network dependencies**:

```bash
# Bundle an interactive graphical window application into a single HTML5 file
./bin/aipl bundle examples/ex_131_window_app_loop_fixed_timestep_window.aipl -o dist/app.html
```

### 2.5 Standalone WebAssembly & WASI (`--target wasm`)
Compiles to a standalone Wasm32 binary targeting the WASI 0.2 Component Model with generated WIT interfaces:

```bash
# Compile to WebAssembly
./bin/aipl build src/main.aipl --target wasm -o dist/app.wasm
```

### 2.6 Android NDK Native Library (`--target android-arm64`)
Compiles AIPL application code to an Android ARM64 native shared library (`libaipl_app.so`) linked against the Android NDK runtime with NativeActivity lifecycle hooks (ADR-0034):

```bash
# Compile to an Android NDK shared library
./bin/aipl build src/main.aipl --target android-arm64 -o dist/libaipl_app.so
```

### 2.7 Pure-AIPL Standalone Signed APK Packaging (`--target apk`)
Constructs, compresses (Deflate store/deflate), generates binary XML manifest (`AndroidManifest.xml`), embeds assets, and digitally signs an installable Android APK package using APK Signature Scheme v2 (ADR-0036):

```bash
# Package and sign a standalone Android APK
./bin/aipl build src/main.aipl --target apk -o dist/app.apk
```

---

## 3. Toolchain & Caching Architecture

The compiler achieves sub-2ms rebuild times for 10k LOC through a multi-tier caching pipeline:

```
Source Code (.aipl)
   │
   ▼
Lexer & Parser ─────────► .aipl/cache/v1/<sha256>.hir   (Merkle Disk Cache)
   │
   ▼
Canonical HIR Optimizer
   │
   ▼ Early Bifurcation
   ├──► TypeScript Emitter ──────► .ts / .tsx / .html
   └──► Parallel C99 Shards ─────► /tmp/aipl-shard-cache/<sha256>.o
           │
           ▼
        Host Linker (gcc/clang) ──► Native Executable
```

1. **Frontend Merkle Cache**: Modules whose source text has not changed bypass lexical and syntax parsing, loading directly from `.aipl/cache/v1/<sha256>.hir`.
2. **Content-Addressed C Shard Cache**: Only modified functions and types are recompiled into `.o` object shards, achieving sub-5ms incremental rebuilds (ADR-0016).
3. **Precompiled Modular Runtime**: The C99 runtime is precompiled once into `.aipl/cache/v1/libaipl_rt-<hash16>.a` and `libaipl_rt_gui-<hash16>.a`.

---

## 4. Cross-Platform Compilation Matrix

| Operating System | Architecture | Primary Compiler | Supported Backends |
| :--- | :--- | :--- | :--- |
| **Linux** | `x86_64`, `aarch64` | `gcc`, `clang` | `native`, `c`, `ts`, `html`, `wasm`, `bytecode` |
| **macOS** | `Apple Silicon (M1..M4)`, `x86_64` | `clang` (Xcode) | `native`, `c`, `ts`, `html`, `wasm`, `bytecode` |
| **Windows** | `x86_64` | `MSVC`, `clang-cl`, `gcc (MinGW)` | `native`, `c`, `ts`, `html`, `wasm`, `bytecode` |
| **Android** | `arm64-v8a`, `x86_64` | Pure-AIPL APK Packager / Android NDK (`clang`) | `apk` (Signed Single-App APK), `android-arm64` (NativeActivity), `html` (WebView) |
| **Browser** | `wasm32`, `js` | Chrome, Firefox, Safari | `html`, `wasm`, `ts` |

---

## 5. Runnable Verification Test

The following runnable AIPL test validates that the runtime environment correctly reports build targets and platform feature flags via `std/std_root`:

```aipl
module tests.functions.core.build_and_targets_test
import * from "std/std_root"
import * from "std/prelude"

pub fn test_build_and_targets_features(): int:
  let target = stdlibBuildTarget()
  assert(target.len() > 0, "Build target name is non-empty")
  assert(stdlibHasFeature("native") == true, "Native feature flag is supported")
  assert(stdlibHasFeature("ts") == true, "TypeScript feature flag is supported")
  ret 0
```
