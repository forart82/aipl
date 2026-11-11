<p align="center">
  <img src="docs/assets/aipl_banner.png" alt="AIPL: The AI-Programming Language" width="100%" />
</p>

# AIPL: The AI-Programming Language (v0.9.0)

[![Version](https://img.shields.io/badge/version-v0.9.0-brightgreen.svg)](VERSION)
[![License: Apache-2.0](https://img.shields.io/badge/License-Apache_2.0-blue.svg)](LICENSE)
[![Docs Index](https://img.shields.io/badge/docs-INDEX.md-blue.svg)](docs/INDEX.md)
[![Specification](https://img.shields.io/badge/docs-SPEC.md-blue.svg)](docs/SPEC.md)
[![Build & Targets](https://img.shields.io/badge/docs-BUILD__AND__TARGETS.md-teal.svg)](docs/BUILD_AND_TARGETS.md)

**AIPL is a modern programming language designed for AI agents and humans alike — ultra-fast, token-efficient, and compiling seamlessly to native binaries, WebAssembly, and the browser.**

---

## Our Philosophy

Most programming languages were created decades ago for human hands typing on keyboards. But today, code is increasingly written, reviewed, and maintained in partnership with AI. AIPL is built on four core beliefs:

1. **Tokens are the New Compute**: Every extra curly brace, semicolon, or boilerplate keyword consumes AI context window space, increases latency, and costs real money. AIPL strips away syntactic clutter so models generate accurate code faster.
2. **Deterministic Speed (Zero GC)**: Software should never freeze unexpectedly. AIPL uses regional memory arenas and flat memory layouts instead of heavy garbage collectors, guaranteeing predictable, sub-millisecond execution.
3. **One Language from Pixels to Systems**: Developers shouldn't need three different languages to build one application. AIPL handles low-level system logic, 2D/3D graphics, sound synthesis, and UI within a single unified standard library.
4. **Seamless Human-AI Collaboration**: Code should be pleasant for humans to read and painless for AI agents to edit surgically without breaking indentation or cascading hallucinations.

---

## How It Works (At a Glance)

- **Clean, Expressive Syntax**: Combines the readability of Python (2-space indentation) with the type safety of TypeScript and the raw performance of C.
- **Multi-Target Lowering**: Write once in AIPL, then compile to:
  - **Native Binaries** (`x86_64`, `ARM64`, C99) for maximum server and desktop speed.
  - **WebAssembly & TypeScript** for zero-install execution directly in web browsers.
  - **Android APKs** for mobile deployment.
- **Batteries-Included Standard Library**: 38 built-in domains covering immediate-mode UI (`Aura`), 2D/3D graphics, 16-voice audio, game physics, math, and networking.
- **AI Agent Toolchain**: Built-in commands let AI assistants inspect code skeletons (`aipl outline`), replace functions surgically without touching the rest of the file (`aipl splice`), and auto-fix errors (`aipl fix`).

---

## Quickstart

### 1. Run a File Immediately
```bash
aipl run examples/ex_001_hello_world.aipl
```

### 2. Build a Standalone Native Executable
```bash
aipl build src/main.aipl -o my_app --native
```

### 3. Run the Test Suite
```bash
aipl test
```

### Hello World Example

```aipl
import std/fmt

pub fn main():
  let message = "Hello, AIPL!"
  fmt.println("{message}")
```

---

## Documentation Roadmap

Looking for deep technical details, specifications, or recipes? Explore the documentation suite:

| What do you want to learn? | Document |
| :--- | :--- |
| **Complete Documentation Portal** | [`DOCS.md`](DOCS.md) & [`docs/INDEX.md`](docs/INDEX.md) |
| **Step-by-Step Tutorials (12 parts)** | [`docs/TUTORIAL.md`](docs/TUTORIAL.md) & [`docs/tutorials/`](docs/tutorials/INDEX.md) |
| **CLI & Commands Reference** | [`docs/CLI_REFERENCE.md`](docs/CLI_REFERENCE.md) |
| **Standard Library Reference (38 Domains)** | [`docs/STDLIB_REFERENCE.md`](docs/STDLIB_REFERENCE.md) & [`docs/reference/`](docs/reference/INDEX.md) |
| **Cookbook & Code Recipes** | [`docs/COOKBOOK.md`](docs/COOKBOOK.md) |
| **AI Agent Guidelines & Tokenomics** | [`AI_SPEC.md`](AI_SPEC.md) |
| **Formal Language Specification** | [`docs/SPEC.md`](docs/SPEC.md) & [`docs/GRAMMAR_AND_SYNTAX.md`](docs/GRAMMAR_AND_SYNTAX.md) |
| **Compiler Architecture & Pipeline** | [`docs/ARCHITECTURE.md`](docs/ARCHITECTURE.md) & [`ORACLE.md`](ORACLE.md) |
| **Memory Model & Allocators** | [`docs/MEMORY_MODEL.md`](docs/MEMORY_MODEL.md) |
| **Architecture Decision Records** | [`docs/ADR/INDEX.md`](docs/ADR/INDEX.md) (ADR-0001 through ADR-0037) |
| **Web & Browser Integration** | [`docs/BROWSER_ZERO_BUILD.md`](docs/BROWSER_ZERO_BUILD.md) |
| **Debugging & DAP Guide** | [`docs/DEBUGGING.md`](docs/DEBUGGING.md) |

---

## License

AIPL is open source licensed under the [Apache License 2.0](LICENSE).
