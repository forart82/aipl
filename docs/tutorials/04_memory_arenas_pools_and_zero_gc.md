[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](INDEX.md) | [Cookbook](cookbook.md) | [Stdlib Reference](../STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Chapter 04: Memory Management, Arenas, Pools & Zero-GC Systems

> **Chapter Summary**: Zero-GC deterministic memory architectures: regional bump arenas with savepoints, generational object pools with ABA handle safety, power-of-two page/slab allocators, ring buffers, and general-purpose allocator leak tracking.

## Table of Contents
- [Chapter 04.1: Regional Bump Arenas (std/alloc/arena: Arena, arenaAlloc, arenaSave, arenaRestore)](#chapter-041-regional-bump-arenas-stdallocarena-arena-arenaalloc-arenasave-arenarestore)
- [Chapter 04.2: Generational Object Pools & ABA Slot Safety (std/alloc/pool_alloc)](#chapter-042-generational-object-pools--aba-slot-safety-stdallocpool_alloc)
- [Chapter 04.3: Power-of-Two Page/Slab Allocators & FIFO Ring Buffers (page_alloc & ring_alloc)](#chapter-043-power-of-two-pageslab-allocators--fifo-ring-buffers-page_alloc--ring_alloc)
- [Chapter 04.4: General-Purpose Allocator Watermarks & Deterministic Leak Detection (std/alloc/gpa)](#chapter-044-general-purpose-allocator-watermarks--deterministic-leak-detection-stdallocgpa)

---

### Chapter 04.1: Regional Bump Arenas (std/alloc/arena: Arena, arenaAlloc, arenaSave, arenaRestore)

#### 1. Concept in 30 Seconds
Teach O(1) regional bump allocation (`arenaCreate`, `arenaAlloc`, `arenaSave`, `arenaRestore`, `arenaReset`) for zero-pause frame and request lifetimes. Pitfall: requesting an alignment that is not a power of two triggers alignment normalization guard.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn arenaMark(): int:` from `std/alloc/arena.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.alloc.arena_z1_test
import * from "std/alloc/arena"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_arena_arenaMark_1(): int:
  let resNom = arenaMark()
  let resEdge = arenaMark()
  assertEqInt(resNom, 0, "arenaMark nominal resNom == 0")
  assertEqInt(resEdge, 0, "arenaMark boundary resEdge == 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_022` | [examples/ex_022_alloc_arena_bump_profiler_cli.aipl](../../examples/ex_022_alloc_arena_bump_profiler_cli.aipl) | `tests/examples/ex_022_alloc_arena_bump_profiler_cli_test.aipl` | `./bin/aipl test tests/examples/ex_022_alloc_arena_bump_profiler_cli_test.aipl` |

---

### Chapter 04.2: Generational Object Pools & ABA Slot Safety (std/alloc/pool_alloc)

#### 1. Concept in 30 Seconds
Teach fixed-slot pooling (`poolCreate`, `poolAlloc`, `poolFree`, `poolIsValid`) with generational counters that reject stale handles after slot reuse. Pitfall: freeing an already-freed handle is caught by generational mismatch.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn poolNew[T](capacity: int): FixedObjectPool[T]:` from `std/alloc/pool_alloc.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.alloc.pool_alloc_z1_test
import * from "std/alloc/pool_alloc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_pool_alloc_poolNew_1(): int:
  let arg_capacity = 4
  let edge_capacity = 1
  let resNom = poolNew(arg_capacity)
  let resEdge = poolNew(edge_capacity)
  assertEqInt(resNom.capacity, 4, "poolNew nominal resNom.capacity == 4")
  assertEqInt(resEdge.capacity, 1, "poolNew boundary resEdge.capacity == 1")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_023` | [examples/ex_023_alloc_pool_fixed_block_cli.aipl](../../examples/ex_023_alloc_pool_fixed_block_cli.aipl) | `tests/examples/ex_023_alloc_pool_fixed_block_cli_test.aipl` | `./bin/aipl test tests/examples/ex_023_alloc_pool_fixed_block_cli_test.aipl` |

---

### Chapter 04.3: Power-of-Two Page/Slab Allocators & FIFO Ring Buffers (page_alloc & ring_alloc)

#### 1. Concept in 30 Seconds
Teach contiguous page allocation (`std/alloc/page_alloc`) and circular FIFO packet/audio scratch buffers (`std/alloc/ring_alloc`). Pitfall: allocating more bytes than `ringAllocAvailable` returns `-1` overflow sentinel.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn systemPageSize(): int:` from `std/alloc/page_alloc.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.alloc.page_alloc_z1_test
import * from "std/alloc/page_alloc"
import { ptrAlloc, ptrFree, ptrMemset } from "std/rt/rt_ptr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_page_alloc_systemPageSize_1(): int:
  let resNom = systemPageSize()
  let resEdge = systemPageSize()
  assertEqInt(resNom, 4096, "systemPageSize nominal resNom == 4096")
  assertEqInt(resEdge, 4096, "systemPageSize boundary resEdge == 4096")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_024` | [examples/ex_024_alloc_page_virtual_slab_cli.aipl](../../examples/ex_024_alloc_page_virtual_slab_cli.aipl) | `tests/examples/ex_024_alloc_page_virtual_slab_cli_test.aipl` | `./bin/aipl test tests/examples/ex_024_alloc_page_virtual_slab_cli_test.aipl` |
| `ex_025` | [examples/ex_025_alloc_ring_packet_buffer_cli.aipl](../../examples/ex_025_alloc_ring_packet_buffer_cli.aipl) | `tests/examples/ex_025_alloc_ring_packet_buffer_cli_test.aipl` | `./bin/aipl test tests/examples/ex_025_alloc_ring_packet_buffer_cli_test.aipl` |

---

### Chapter 04.4: General-Purpose Allocator Watermarks & Deterministic Leak Detection (std/alloc/gpa)

#### 1. Concept in 30 Seconds
Teach tracked heap allocation (`gpaCreate`, `gpaAlloc`, `gpaFree`, `gpaHasLeaks`, `gpaPeakBytes`) to enforce zero memory leaks in unit tests. Pitfall: leaving active allocations at teardown causes `gpaHasLeaks(g) == true`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn gpaInit(): void:` from `std/alloc/gpa.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.alloc.gpa_z1_test
import * from "std/alloc/gpa"
import { ptrAlloc, ptrFree, ptrReadI64, ptrWriteI64, ptrMemcpy, ptrMemset } from "std/rt/rt_ptr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpa_gpaInit_1(): int:
  mut completedCalls = 0
  gpaInit()
  completedCalls = completedCalls + 1
  gpaInit()
  completedCalls = completedCalls + 1
  assertEqInt(completedCalls, 2, "gpaInit nominal and boundary void calls completed")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_026` | [examples/ex_026_alloc_gpa_leak_detector_cli.aipl](../../examples/ex_026_alloc_gpa_leak_detector_cli.aipl) | `tests/examples/ex_026_alloc_gpa_leak_detector_cli_test.aipl` | `./bin/aipl test tests/examples/ex_026_alloc_gpa_leak_detector_cli_test.aipl` |
