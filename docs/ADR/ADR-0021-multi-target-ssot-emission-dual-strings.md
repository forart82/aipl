# ADR-0021: Multi-Target Single Source of Truth (SSOT) Emission & Dual-String Architecture

## Status
Accepted


## Date
2026-10-11

## Deciders
AIPL Architecture & Core Systems Team

## Context
In modern software engineering and autonomous agent systems, full-stack application development suffers from catastrophic type and schema drift across four decoupled surfaces:
1. **Static Type Interfaces (`.d.ts`)**: Required by IDEs, language servers, and build pipelines (`tsc`) for compile-time checking.
2. **Runtime Validation Schemas (`zod`)**: Required at network and API boundaries (JSON payload deserialization, form validation, WebSocket events) because TypeScript types are completely erased at runtime.
3. **Design Token Stylesheets (`.css`)**: Required by UI rendering engines, CSS-in-JS, and Tailwind configurations for color palettes, spacing units, and typography scales.
4. **Systems & Linear Memory Layouts (`wasm`)**: Required by compute kernels, graphics pipelines, and standalone engines operating in linear WebAssembly memory.

When human developers or AI coding agents manually maintain these four artifacts independently, breaking changes, semantic divergence, and silent contract violations inevitably occur:
- An SMT refinement constraint proved by the solver (e.g., `{ age: int | age >= 0 and age <= 120 }`) is lost during TypeScript transpilation because TypeScript lacks refinement types, leading to runtime data corruption if not duplicated in a validation library.
- Design tokens defined in TypeScript constants diverge from CSS custom properties, causing layout degradation.
- WebAssembly kernels frequently incur severe performance penalties (up to 40% CPU time in string-heavy workloads) when forced to repeatedly transcode between JavaScript UTF-16 strings and Rust/Wasm UTF-8 strings across the host-guest boundary.

## Decision Drivers
- **Single Source of Truth (SSOT)**: A single canonical AIPL definition (`struct`, `type`, `enum`, or `tokens`) must automatically synthesize all downstream artifacts (`.d.ts`, Zod v3 schemas, `.css` design tokens, and Wasm memory layouts).
- **SMT-to-Zod Soundness Parity**: SMT integer bounds and refinement predicates proved in `compiler/smt.aipl` (originally `crates/aipl-smt`) must map deterministically to runtime validation guards (`.min(x).max(y)`).
- **Algebraic Type Preservation**: First-class algebraic `Result[T, E]` and `Option[T]` types must translate cleanly to discriminated unions and nullable/optional schemas.
- **Dual-String Representation Strategy**:
  - **Pipeline A (Web & Edge Tier)**: Native UTF-16 JavaScript strings (`string`) for zero-overhead DOM interop and template literals.
  - **Pipeline B (Wasm & Native Tier)**: Zero-copy UTF-8 byte slices (`AiplStringSlice { ptr: u32, len: u32 }`) in linear memory.
- **Zero-Copy Boundary Bridge**: Automated synthesis of high-performance `TextDecoder` and `TextEncoder.encodeInto` marshaling code.
- **Strict Verification SLA**: Emitted `.d.ts` must pass `tsc --noEmit --strict` with zero warnings; emitted Zod schemas must pass runtime execution verification in Node.js/Bun.

## Considered Options

### Option 1: Erase Refinements to Plain TypeScript & Manual Zod Authorship
Compile AIPL structs to TypeScript interfaces only; require users or agents to author external Zod schemas and CSS stylesheets manually.
- *Pros*: Minimizes initial compiler scope.
- *Cons*: **Rejected**. Re-introduces schema drift; SMT refinement invariants verified at compile-time are discarded at runtime network boundaries; AI agents spend excessive tokens generating redundant schema definitions.

### Option 2: Unified UTF-8 String Representation Across All Targets
Enforce UTF-8 strings uniformly across both Web and Wasm tiers by wrapping Web strings in a custom byte-array class or WASM-backed handle.
- *Pros*: Identical memory layout across Pipeline A and Pipeline B.
- *Cons*: **Rejected**. Cripples JavaScript DOM manipulation performance. Every DOM property assignment (`element.textContent = str`) or JSX prop interpolation requires transcoding UTF-8 bytes to V8 UTF-16 strings on the main UI thread.

### Option 3: Unified UTF-16 String Representation in WebAssembly
Adopt UTF-16 strings inside the Wasm standalone engine (similar to Java or .NET runtimes).
- *Pros*: Matches JavaScript internal string representation.
- *Cons*: **Rejected**. Doubles memory consumption for ASCII-dominated text; incompatible with standard POSIX, Linux, Rust, and GPU shaders which expect UTF-8 or ASCII byte layouts; breaks zero-copy file and network I/O.

### Option 4: Multi-Target SSOT Emission Engine & Dual-String Architecture (`compiler/codegen_ts.aipl`, originally `crates/aipl-codegen-ts`)
Implement an integrated SSOT emission engine that:
1. Lowers AIPL definitions to clean, strictly-typed `.d.ts` files with JSDoc and optional/null unions.
2. Emits executable Zod v3 schemas mapping primitives, SMT refinements, and algebraic types.
3. Emits CSS custom property stylesheets (`:root { ... }`) with kebab-case variable names.
4. Lower strings based on early bifurcation: UTF-16 `string` for Pipeline A, `AiplStringSlice (ptr, len)` for Pipeline B.
5. Emits a hardware-accelerated Web/Wasm marshaling bridge using `TextDecoder` and `TextEncoder`.
- *Pros*: **Accepted**. 100% elimination of schema drift, full runtime enforcement of SMT proofs, zero-overhead DOM interop, and zero-copy Wasm computational throughput.

## Decision Outcome & Rationale
**Chosen: Option 4 - Multi-Target SSOT Emission Engine & Dual-String Architecture.**

### Architectural Workflow

```mermaid
flowchart TD
    subgraph AIPL_Source ["AIPL Single Source of Truth"]
        Model["struct User:\n  id: int\n  name: str\n  age: { a: int | a >= 0 and a <= 120 }\n  email: Option[str]\n  status: Status"]
        Tokens["tokens Theme:\n  primary: \"#3b82f6\"\n  paddingMd: \"16px\""]
    end

    subgraph SSOT_Engine ["SSOT Emission Engine (compiler/codegen_ts.aipl)"]
        Parser["SsotParser / SMT Refinement Extractor"]
        Model --> Parser
        Tokens --> Parser

        DtsGen["dts_emitter::emit_dts()"]
        ZodGen["zod_emitter::emit_zod()"]
        CssGen["css_emitter::emit_css()"]
        DualStr["dual_string::lower_struct_for_tier()"]
        Bridge["dual_string::emit_string_bridge_ts()"]

        Parser --> DtsGen
        Parser --> ZodGen
        Parser --> CssGen
        Parser --> DualStr
        Parser --> Bridge
    end

    subgraph Target_Artifacts ["Multi-Target Single Source of Truth Artifacts"]
        DtsFile[("model.d.ts\nTypeScript Declarations\n(tsc --strict)")]
        ZodFile[("schema.ts\nExecutable Zod v3\n(Runtime Validation)")]
        CssFile[("theme.css\nCSS Custom Properties\n(:root { --padding-md })")]
        WasmFile[("ArticleWasmLayout\n(ptr: u32, len: u32)\n8-byte Linear Stride")]
        BridgeFile[("bridge.ts\nTextDecoder / TextEncoder\nZero-Copy Marshaling")]
    end

    DtsGen --> DtsFile
    ZodGen --> ZodFile
    CssGen --> CssFile
    DualStr --> WasmFile
    Bridge --> BridgeFile
```

---

## Technical Specifications & Invariant Rules

### 1. Type Mapping & Refinement Taxonomy

| AIPL Source Construct | TypeScript (`.d.ts`) | Runtime Validation (Zod v3) | Wasm Linear Memory (Pipeline B) |
| :--- | :--- | :--- | :--- |
| `int` | `number` | `z.number().int()` | `i64` (8 bytes, align 8) |
| `float` | `number` | `z.number()` | `f32` (4 bytes, align 4) |
| `num` | `number` | `z.number()` | `f64` (8 bytes, align 8) |
| `byte` | `number` | `z.number().int().min(0).max(255)` | `u8` (1 byte, align 1) |
| `bool` | `boolean` | `z.boolean()` | `u8` (1 byte, align 1) |
| `str` | `string` (UTF-16) | `z.string()` | `AiplStringSlice` (8 bytes, align 4) |
| `{ x: int \| x >= min and x <= max }` | `number` | `z.number().int().min(min).max(max)` | `i64` with compile-time SMT proof |
| `{ x: int \| x > val }` | `number` | `z.number().int().gt(val)` | `i64` with compile-time SMT proof |
| `{ x: int \| x < val }` | `number` | `z.number().int().lt(val)` | `i64` with compile-time SMT proof |
| `Option[T]` | `T \| null` | `zod(T).nullable()` | `4-byte tag + stride(T)` |
| `Result[T, E]` | `Result<T, E>` | `z.discriminatedUnion("ok", ...)` | `4-byte tag + max(T, E)` |
| `[T]` / `Array[T]` | `T[]` | `z.array(zod(T))` | `u32 ptr + u32 len` (8 bytes) |
| `(A, B)` | `[A, B]` | `z.tuple([zod(A), zod(B)])` | `stride(A) + stride(B)` |
| `enum Status: A, B` | `"A" \| "B"` | `z.enum(["A", "B"])` | `u32` discriminant (4 bytes) |

### 2. Dual-String Memory Model & Stride Calculation

In AIPL flat memory architecture:
- **Pipeline A (Web / TypeScript)**: Strings are unmanaged V8 UTF-16 rope/flat string instances. Stored on the JavaScript engine heap, garbage collected by V8/JSC.
- **Pipeline B (Wasm / Standalone Native)**: Strings are represented as an exact 8-byte slice:
  ```rust
  #[repr(C)]
  pub struct AiplStringSlice {
      pub ptr: u32,  // 4 bytes: Linear memory byte offset
      pub len: u32,  // 4 bytes: UTF-8 byte length
  }
  ```
  - `AiplStringSlice::STRIDE` = 8 bytes.
  - `AiplStringSlice::ALIGN` = 4 bytes.
  - Struct size calculation aligns each field according to WebAssembly standard struct alignment rules.

### 3. Zero-Copy Web/Wasm Marshaling Bridge

Boundary crossings between Pipeline A (UTF-16) and Pipeline B (UTF-8 linear memory) utilize browser-native streaming decoders:
```typescript
const utf8Decoder = new TextDecoder("utf-8");
const utf8Encoder = new TextEncoder();

export function readAiplString(memory: WebAssembly.Memory, ptr: number, len: number): string {
  return utf8Decoder.decode(new Uint8Array(memory.buffer, ptr, len));
}

export function encodeIntoAiplString(
  memory: WebAssembly.Memory,
  ptr: number,
  maxBytes: number,
  text: string
): { read: number; written: number } {
  return utf8Encoder.encodeInto(text, new Uint8Array(memory.buffer, ptr, maxBytes));
}
```

### 4. Design Token Transformation Rules

1. Any token name declared in `tokens Theme:` or `struct ThemeTokens:` is converted from camelCase or PascalCase to CSS kebab-case:
   $$\text{to\_css\_var}(name) = \text{"--" } + \text{kebab}(name)$$
2. All token sets default to the `:root` selector unless an explicit selector scope is specified (e.g. `[data-theme="dark"]`).
3. Quotes are stripped and units (`px`, `rem`, `%`, `#hex`) are preserved cleanly.

---

## Consequences

### Positive
- Single Source of Truth: TypeScript interfaces, Zod schemas, CSS design tokens, and Wasm layouts originate from a single AIPL specification.
- Runtime safety with zero duplicate maintenance overhead: SMT refinement predicates automatically generate isomorphic Zod runtime validators.
- Deterministic 32-byte layout for Wasm interop with zero-copy decoding bridges for WebAssembly and TypeScript boundaries.

### Negative
- Dual-string model introduces divergence between V8 managed UTF-16 string engine and Wasm linear memory byte slices, necessitating bridge marshaling functions.

---

## Verification & Test Quality Gates

The implementation is verified by an exhaustive 5-part test suite verified via `./bin/aipl test` and `pytest tests/selfhost/` (originally `crates/aipl-codegen-ts/tests/ssot_tests.rs`):
1. `test_dts_emission_cleanliness`: Asserts emitted `.d.ts` compiles cleanly with zero warnings/errors under `tsc --noEmit --strict`.
2. `test_zod_schema_generation_and_validation`: Runs emitted Zod schemas in Bun/Node.js against valid and invalid payloads, verifying runtime parse successes and failures.
3. `test_refinement_to_zod_constraints`: Verifies SMT integer bounds (`min`, `max`, `byte`) map directly to `.min(x).max(y)` in Zod and enforce runtime boundaries.
4. `test_css_design_tokens_emission`: Verifies token structs emit valid `:root { ... }` CSS custom properties with balanced braces.
5. `test_dual_string_lowering`: Asserts TS target emits UTF-16 `string` while Wasm target emits `(ptr, len)` UTF-8 layout with verified 32-byte struct stride and verified bridge compilation.
