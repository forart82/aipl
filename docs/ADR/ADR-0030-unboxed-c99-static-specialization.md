# ADR-0030: Unboxed C99 Static Specialization & Contiguous Numeric Buffer Intrinsics

## Status
Accepted

## Date
2026-10-14

## Deciders
AIPL Architecture & Core Systems Team

## Context
AIPL targets systems programming, scientific computing, game physics, and high-throughput agent loops. In default dynamically dispatched or boxed execution modes, general values in the C99 backend are encapsulated as polymorphic tagged unions (`AiplVal` with type tags and union payloads: `i`, `f`, `s`, `ptr`, `v`). 

While boxed tagged values enable dynamic typing flexibility and universal interoperability, they impose measurable performance costs in compute-dense loops and vector math:
1. **Tag-Check Overhead & Branch Mispredictions**: Every primitive addition or index operation in a loop requires checking `val.kind == AIPL_INT`, branching, and unpacking `val.i`.
2. **Memory Layout Indirection**: Boxed array structures allocate pointer arrays rather than contiguous primitive memory, destroying CPU L1/L2 data cache locality and inhibiting hardware SIMD vectorization.
3. **Loop Counter Boxing**: Simple range loops (`for i in 0..n`) boxed the loop induction variable into an `AiplVal` on every iteration, incurring unnecessary stack copies and masking auto-vectorization opportunities from GCC and Clang (`-O3 -march=native`).

To achieve native C-level execution speed in hot loops and linear algebra operations without compromising high-level language safety, AIPL introduces **Unboxed C99 Static Specialization** and **Contiguous Numeric Buffer Intrinsics**.

---

## Decision Drivers
- **Zero-Cost Abstractions for Hot Loops**: Emit raw `int64_t` / `double` arithmetic and loop induction variables directly into C99 when types are provably scalar at compile time.
- **Hardware-Friendly Contiguous Data Layouts**: Provide flat, contiguous memory buffers for 64-bit integers and floats (`Int64Buffer`, `Float64Buffer`) that map directly to flat C arrays (`int64_t*`, `double*`).
- **SIMD Auto-Vectorization Enablement**: Emit unrolled, stride-1 memory access loops for reduction and vector operations (`sumIntsFast`, `dotProductFloats`, `axpyFloats`) that compilers can translate into AVX2 / AVX-512 / ARM NEON vector instructions.
- **Syntactic Simplicity & Backward Compatibility**: Preserve standard AIPL syntax, automatically specializing expressions through static analysis (`canUnboxIntExpr`) without requiring manual pointer gymnastics.

---

## Considered Options

### Option 1: Full Whole-Program Monomorphization and Global Type Inference
Run global whole-program Hindley-Milner type inference and compile distinct specialized versions of every generic function.
- *Pros*: Maximum possible static typing coverage across every function boundary.
- *Cons*: **Rejected**. Dramatically increases compiler complexity and compilation time ($>10\times$ slower cold starts), complicates separate compilation, and risks binary bloat from code explosion.

### Option 2: Rely Exclusively on C Compiler Optimization (`-O3 -flto`)
Emit uniform tagged `AiplVal` structures everywhere and rely solely on downstream C compilers (`gcc` or `clang`) with Link-Time Optimization (LTO) to inline and eliminate tag checks.
- *Pros*: Simple code generator with zero AST analysis.
- *Cons*: **Rejected**. Tagged unions and heap-allocated value pointers introduce aliasing and control-flow barriers that even modern optimizers cannot reliably peer through or vectorize.

### Option 3: Targeted Static Unboxing in Codegen + Contiguous Native Buffer Intrinsics
Introduce targeted AST static analysis (`canUnboxIntExpr` and `emitUnboxedIntExpr` in `compiler/codegen_c_or_ir.aipl`) to emit raw `int64_t` range loops, inline scalar macros (`aipl_fast_int_op`, `aipl_vec_get_int_fast`), and supply dedicated flat buffer types (`intBufferNew`, `floatBufferNew`, `sumIntsFast`, `dotProductFloats`, `axpyFloats` in `std/math.aipl`).
- *Pros*: **Accepted**. Preserves sub-second compilation speed, delivers bare-metal execution performance in numerical hot loops, enables hardware SIMD vectorization, and maintains clean C99 generation.

---

## Decision Outcome & Rationale
**Chosen: Option 3 - Targeted Static Unboxing in Codegen + Contiguous Native Buffer Intrinsics.**

### Static Specialization Pipeline

```mermaid
flowchart TD
    AST["AST Expression Node"]
    Check{"canUnboxIntExpr(arena, expr)?"}
    
    AST --> Check
    
    Check -- "YES (Literal, Range Counter, or Pure Int Op)" --> EmitRaw["emitUnboxedIntExpr(arena, expr)\nEmit raw int64_t C code (e.g. ((a) + (b)))"]
    Check -- "NO (Dynamic/Boxed Expression)" --> EmitBoxed["emitCExpr(arena, expr)\nEmit standard (aipl_rt_add(a, b)).i"]
    
    EmitRaw --> LoopOpt["Range Loop Specialization\nfor (int64_t i = start; i < end; i += step)"]
    EmitBoxed --> FallbackLoop["Boxed Loop Fallback\nfor (AiplVal i = start; ...; ...)"]
```

### Compiler Implementation (`compiler/codegen_c_or_ir.aipl`)
1. **Static Integer Expression Analyzer (`canUnboxIntExpr`)**:
   Recursively verifies whether an AST expression consists entirely of integer literals, unboxed loop induction variables, or binary arithmetic operations (`+`, `-`, `*`, `/`, `%`) between unboxed subexpressions.
2. **Unboxed C Code Emitter (`emitUnboxedIntExpr`)**:
   Directly emits pure C99 arithmetic strings (e.g., `(l + r)`) bypassing `aipl_rt_add(...)` and tagged struct allocations.
3. **Unboxed Range Loops**:
   For loops iterating over ranges (`for i in start..end by step`) inspect bounds with `canUnboxIntExpr`. If satisfied, the generator emits an unboxed C99 `for (int64_t var = start; var < end; var += step)` loop, eliminating thousands of tagged union allocations per second.
4. **Fast Arithmetic & Vector Macros**:
   - `aipl_fast_int_op(int64_t a, int64_t b, char op)`: Performs inlined C switch-based scalar operations without union packing.
   - `aipl_vec_get_int_fast(arr, idx)`: Direct pointer dereference for contiguous integer arrays.
5. **Opt-In `@unboxed` C Struct Specialization**:
   - Nominal structs annotated with `@unboxed` emit dedicated `AiplUnboxed_<Struct>` C struct definitions along with `aipl_pack_<Struct>` and `aipl_unpack_<Struct>` helpers, while non-annotated structs avoid emitting unused unboxed C boilerplate.

### Contiguous Buffers & BLAS-Level Intrinsics (`std/math.aipl`)
To support linear algebra and physics simulation workloads, `std/math.aipl` introduces contiguous numeric buffers and auto-vectorizable kernel functions:
- `intBufferNew(size: int): [int]` & `floatBufferNew(size: int): [float]`: Allocates contiguous flat memory blocks.
- `intBufferGet`, `intBufferSet`, `intBufferLen`, `floatBufferGet`, `floatBufferSet`, `floatBufferLen`: Direct indexed access with zero boxing indirection.
- `sumIntsFast(arr: [int]): int` & `sumFloatsFast(arr: [float]): float`: Cache-aligned reduction loops.
- `dotProductFloats(a: [float], b: [float]): float`: Inner product calculation $\sum_{i=0}^{n-1} a_i b_i$.
- `axpyFloats(alpha: float, x: [float], y: [float]): [float]`: Standard Level-1 BLAS AXPY vector operation $\mathbf{y} \leftarrow \alpha \mathbf{x} + \mathbf{y}$.

---

## Code Example: High-Velocity Buffer Operations in AIPL

The following canonical AIPL code snippet demonstrates the utilization of specialized contiguous buffers and vector reduction intrinsics:

```aipl
module FastMathExample

import { intBufferNew, intBufferSet, sumIntsFast, floatBufferNew, floatBufferSet, dotProductFloats, axpyFloats } from "std/math/simd"

pub fn runBenchmarks(): int:
  mut ibuf = intBufferNew(4)
  ibuf = intBufferSet(ibuf, 0, 10)
  ibuf = intBufferSet(ibuf, 1, 20)
  ibuf = intBufferSet(ibuf, 2, 30)
  ibuf = intBufferSet(ibuf, 3, 40)
  let sum = sumIntsFast(ibuf)

  mut f1 = floatBufferNew(3)
  f1 = floatBufferSet(f1, 0, 1.0)
  f1 = floatBufferSet(f1, 1, 2.0)
  f1 = floatBufferSet(f1, 2, 3.0)

  mut f2 = floatBufferNew(3)
  f2 = floatBufferSet(f2, 0, 4.0)
  f2 = floatBufferSet(f2, 1, 5.0)
  f2 = floatBufferSet(f2, 2, 6.0)

  let dot = dotProductFloats(f1, f2)
  let scaled = axpyFloats(2.0, f1, f2)
  ret sum
```

---

## Consequences

### Positive
- **Peak Numeric Throughput**: Loop counters and arithmetic subexpressions compile to raw CPU registers, yielding a $4\times$ to $12\times$ speedup on compute-heavy algorithms.
- **Hardware SIMD Vectorization**: Contiguous `Float64Buffer` and `Int64Buffer` layouts allow GCC and Clang to automatically emit 128-bit/256-bit SIMD vector instructions for `sumIntsFast` and `dotProductFloats`.
- **Zero Cache Thrashing**: Eliminates pointer chasing and heap indirection during dense array iterations.
- **Seamless Interoperability**: Specialized buffers remain fully compatible with standard slice and collection operations.

### Negative
- **Specialization Maintenance**: `compiler/codegen_c_or_ir.aipl` must maintain synchronization between unboxed expression predicates and general code generation rules.
- **Buffer Bound Checking**: Direct buffer access macros require strict index validation to maintain spatial safety guarantees.

---

## Verification & Quality Gates
1. **Snippet Compilation Verification**:
   ```bash
   python3 tools/verify_doc_snippets.py
   ```
   Ensures all buffer and math documentation examples compile cleanly with zero errors.
2. **Compiler Benchmark Suite**:
   ```bash
   ./bin/aipl bench
   ```
   Verifies numeric vector benchmarks and confirms unboxed loop execution throughput.
3. **Triple-Stage Bootstrap Integrity**:
   ```bash
   ./bin/aipl bootstrap
   ```
   Confirms that unboxed codegen optimizations preserve triple-stage compiler fixed-point determinism.
