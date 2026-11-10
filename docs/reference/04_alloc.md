[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 04: `alloc` API Reference

> Complete API reference manual for AIPL standard library domain `alloc` (54 callable functions & methods across ["std/alloc/alloc_mod.aipl", "std/alloc/arena.aipl", "std/alloc/gpa.aipl", "std/alloc/page_alloc.aipl", "std/alloc/pool_alloc.aipl", "std/alloc/ring_alloc.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `alloc`
- **Target Source Modules**: ["std/alloc/alloc_mod.aipl", "std/alloc/arena.aipl", "std/alloc/gpa.aipl", "std/alloc/page_alloc.aipl", "std/alloc/pool_alloc.aipl", "std/alloc/ring_alloc.aipl"]
- **Total Callable Functions & Methods**: 54
- **Total Data Types (`struct` & `enum`)**: 9
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(9 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `ArenaScope` | `pub struct` | `std/alloc/arena.aipl` | `mark: int`, `depth: int = 0` | `ArenaScope(mark, depth)` |
| `ArenaStats` | `pub struct` | `std/alloc/arena.aipl` | `allocatedBytes: int`, `peakBytes: int`, `resetCount: int`, `markCount: int` | `ArenaStats(allocatedBytes, peakBytes, resetCount, markCount)` |
| `GpaHeader` | `pub struct` | `std/alloc/gpa.aipl` | `magic: int`, `size: int`, `callerId: int`, `canary: int` | `GpaHeader(magic, size, callerId, canary)` |
| `GpaStats` | `pub struct` | `std/alloc/gpa.aipl` | `liveAllocations: int`, `totalAllocated: int`, `totalFreed: int`, `peakMemory: int`, `leakedBytes: int` | `GpaStats(liveAllocations, totalAllocated, totalFreed, peakMemory, leakedBytes)` |
| `VirtualPageAllocator` | `pub struct` | `std/alloc/page_alloc.aipl` | `pageSize: int`, `allocatedPages: int`, `committedBytes: int` | `VirtualPageAllocator(pageSize, allocatedPages, committedBytes)` |
| `GenerationalHandle` | `pub struct` | `std/alloc/pool_alloc.aipl` | `index: int`, `generation: int` | `GenerationalHandle(index, generation)` |
| `PoolHandle` | `pub struct` | `std/alloc/pool_alloc.aipl` | `index: int`, `generation: int` | `PoolHandle(index, generation)` |
| `FixedObjectPool[T]` | `pub struct` | `std/alloc/pool_alloc.aipl` | `capacity: int`, `mut activeCount: int`, `mut freeHead: int`, `mut active: [bool]`, `mut slots: [T]`, `mut generations: [int]`, `mut freeList: [int]`, `numWorkers: int`, `mut queues: [[int]]`, `mut results: [int]`, `mut stolenTasks: int` | `FixedObjectPool(capacity, mut activeCount, mut freeHead, mut active, mut slots, mut generations, mut freeList, numWorkers, mut queues, mut results, mut stolenTasks)` |
| `RingBufferAllocator` | `pub struct` | `std/alloc/ring_alloc.aipl` | `baseAddr: int`, `capacity: int`, `head: int`, `tail: int`, `usedBytes: int`, `allocatedCount: int` | `RingBufferAllocator(baseAddr, capacity, head, tail, usedBytes, allocatedCount)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/alloc/arena.aipl` | `arenaMark` | `pub fn arenaMark(): int:` | `tests/functions/alloc/arena_test.aipl` |
| `2` | `std/alloc/arena.aipl` | `arenaReset` | `pub fn arenaReset(mark: int): int:` | `tests/functions/alloc/arena_test.aipl` |
| `3` | `std/alloc/arena.aipl` | `arenaAllocatedBytes` | `pub fn arenaAllocatedBytes(): int:` | `tests/functions/alloc/arena_test.aipl` |
| `4` | `std/alloc/arena.aipl` | `arenaAlloc` | `pub fn arenaAlloc(bytes: int): int:` | `tests/functions/alloc/arena_test.aipl` |
| `5` | `std/alloc/arena.aipl` | `arenaActiveDepth` | `pub fn arenaActiveDepth(): int:` | `tests/functions/alloc/arena_test.aipl` |
| `6` | `std/alloc/arena.aipl` | `arenaPopEvacuate` | `pub fn arenaPopEvacuate(mark: int, val: any): any:` | `tests/functions/alloc/arena_test.aipl` |
| `7` | `std/alloc/arena.aipl` | `arenaStats` | `pub fn arenaStats(): Map[str, int]:` | `tests/functions/alloc/arena_test.aipl` |
| `8` | `std/alloc/arena.aipl` | `arenaStatsStruct` | `pub fn arenaStatsStruct(): ArenaStats:` | `tests/functions/alloc/arena_test.aipl` |
| `9` | `std/alloc/arena.aipl` | `withScratchArena` | `pub fn withScratchArena(bytesToScratch: int): int:` | `tests/functions/alloc/arena_test.aipl` |
| `10` | `std/alloc/arena.aipl` | `arenaScopeBegin` | `pub fn arenaScopeBegin(): ArenaScope:` | `tests/functions/alloc/arena_test.aipl` |
| `11` | `std/alloc/arena.aipl` | `arenaScopeEnd` | `pub fn arenaScopeEnd(scope: ArenaScope): int:` | `tests/functions/alloc/arena_test.aipl` |
| `12` | `std/alloc/arena.aipl` | `mapNewIn` | `pub fn mapNewIn(scope: ArenaScope): Map[str, any]:` | `tests/functions/alloc/arena_test.aipl` |
| `13` | `std/alloc/arena.aipl` | `arrayNewIn` | `pub fn arrayNewIn(scope: ArenaScope, cap: int): [any]:` | `tests/functions/alloc/arena_test.aipl` |
| `14` | `std/alloc/arena.aipl` | `arenaAllocStrIn` | `pub fn arenaAllocStrIn(scope: ArenaScope, s: str): str:` | `tests/functions/alloc/arena_test.aipl` |
| `15` | `std/alloc/gpa.aipl` | `gpaInit` | `pub fn gpaInit(): void:` | `tests/functions/alloc/gpa_test.aipl` |
| `16` | `std/alloc/gpa.aipl` | `gpaAlloc` | `pub fn gpaAlloc(bytes: int, callerId: int = 0): int:` | `tests/functions/alloc/gpa_test.aipl` |
| `17` | `std/alloc/gpa.aipl` | `gpaValidatePtr` | `pub fn gpaValidatePtr(ptr: int): bool:` | `tests/functions/alloc/gpa_test.aipl` |
| `18` | `std/alloc/gpa.aipl` | `gpaFree` | `pub fn gpaFree(ptr: int): bool:` | `tests/functions/alloc/gpa_test.aipl` |
| `19` | `std/alloc/gpa.aipl` | `gpaRealloc` | `pub fn gpaRealloc(ptr: int, newBytes: int): int:` | `tests/functions/alloc/gpa_test.aipl` |
| `20` | `std/alloc/gpa.aipl` | `gpaGetStats` | `pub fn gpaGetStats(): GpaStats:` | `tests/functions/alloc/gpa_test.aipl` |
| `21` | `std/alloc/gpa.aipl` | `gpaReportLeaks` | `pub fn gpaReportLeaks(): int:` | `tests/functions/alloc/gpa_test.aipl` |
| `22` | `std/alloc/page_alloc.aipl` | `systemPageSize` | `pub fn systemPageSize(): int:` | `tests/functions/alloc/page_alloc_test.aipl` |
| `23` | `std/alloc/page_alloc.aipl` | `pageAllocatorNew` | `pub fn pageAllocatorNew(): VirtualPageAllocator:` | `tests/functions/alloc/page_alloc_test.aipl` |
| `24` | `std/alloc/page_alloc.aipl` | `pageAlloc` | `pub fn pageAlloc(numPages: int): int:` | `tests/functions/alloc/page_alloc_test.aipl` |
| `25` | `std/alloc/page_alloc.aipl` | `pageFree` | `pub fn pageFree(addr: int, numPages: int): bool:` | `tests/functions/alloc/page_alloc_test.aipl` |
| `26` | `std/alloc/page_alloc.aipl` | `pageProtect` | `pub fn pageProtect(addr: int, numPages: int, protMask: int): bool:` | `tests/functions/alloc/page_alloc_test.aipl` |
| `27` | `std/alloc/page_alloc.aipl` | `pageAlignUp` | `pub fn pageAlignUp(bytes: int): int:` | `tests/functions/alloc/page_alloc_test.aipl` |
| `28` | `std/alloc/page_alloc.aipl` | `pageCountForBytes` | `pub fn pageCountForBytes(bytes: int): int:` | `tests/functions/alloc/page_alloc_test.aipl` |
| `29` | `std/alloc/pool_alloc.aipl` | `poolNew` | `pub fn poolNew[T](capacity: int): FixedObjectPool[T]:` | `tests/functions/alloc/pool_alloc_test.aipl` |
| `30` | `std/alloc/pool_alloc.aipl` | `acquire` | `pub fn (mut self: FixedObjectPool[T]) acquire(item: T): Option[GenerationalHandle]:` | `tests/functions/alloc/pool_alloc_test.aipl` |
| `31` | `std/alloc/pool_alloc.aipl` | `isValid` | `pub fn (self: FixedObjectPool[T]) isValid(handle: GenerationalHandle): bool:` | `tests/functions/alloc/pool_alloc_test.aipl` |
| `32` | `std/alloc/pool_alloc.aipl` | `get` | `pub fn (self: FixedObjectPool[T]) get(handle: GenerationalHandle): Option[T]:` | `tests/functions/alloc/pool_alloc_test.aipl` |
| `33` | `std/alloc/pool_alloc.aipl` | `release` | `pub fn (mut self: FixedObjectPool[T]) release(handle: GenerationalHandle): bool:` | `tests/functions/alloc/pool_alloc_test.aipl` |
| `34` | `std/alloc/pool_alloc.aipl` | `count` | `pub fn (self: FixedObjectPool[T]) count(): int:` | `tests/functions/alloc/pool_alloc_test.aipl` |
| `35` | `std/alloc/pool_alloc.aipl` | `isFull` | `pub fn (self: FixedObjectPool[T]) isFull(): bool:` | `tests/functions/alloc/pool_alloc_test.aipl` |
| `36` | `std/alloc/pool_alloc.aipl` | `clear` | `pub fn (mut self: FixedObjectPool[T]) clear(): void:` | `tests/functions/alloc/pool_alloc_test.aipl` |
| `37` | `std/alloc/pool_alloc.aipl` | `poolAcquire` | `pub fn poolAcquire(mut pool: Pool): Option[int]:` | `tests/functions/alloc/pool_alloc_test.aipl` |
| `38` | `std/alloc/pool_alloc.aipl` | `poolRelease` | `pub fn poolRelease(mut pool: Pool, idx: int): bool:` | `tests/functions/alloc/pool_alloc_test.aipl` |
| `39` | `std/alloc/pool_alloc.aipl` | `poolIsActive` | `pub fn poolIsActive(pool: Pool, idx: int): bool:` | `tests/functions/alloc/pool_alloc_test.aipl` |
| `40` | `std/alloc/pool_alloc.aipl` | `poolActiveIndices` | `pub fn poolActiveIndices(pool: Pool): [int]:` | `tests/functions/alloc/pool_alloc_test.aipl` |
| `41` | `std/alloc/pool_alloc.aipl` | `poolActiveCount` | `pub fn poolActiveCount(pool: Pool): int:` | `tests/functions/alloc/pool_alloc_test.aipl` |
| `42` | `std/alloc/pool_alloc.aipl` | `poolClear` | `pub fn poolClear(mut pool: Pool): Pool:` | `tests/functions/alloc/pool_alloc_test.aipl` |
| `43` | `std/alloc/pool_alloc.aipl` | `poolAlloc` | `pub fn poolAlloc(mut pool: Pool): Option[int]:` | `tests/functions/alloc/pool_alloc_test.aipl` |
| `44` | `std/alloc/pool_alloc.aipl` | `poolFree` | `pub fn poolFree(mut pool: Pool, idx: int): bool:` | `tests/functions/alloc/pool_alloc_test.aipl` |
| `45` | `std/alloc/pool_alloc.aipl` | `poolGenerationsNew` | `pub fn poolGenerationsNew(capacity: int): [int]:` | `tests/functions/alloc/pool_alloc_test.aipl` |
| `46` | `std/alloc/pool_alloc.aipl` | `poolAcquireHandle` | `pub fn poolAcquireHandle(mut pool: Pool, generations: [int]): Option[PoolHandle]:` | `tests/functions/alloc/pool_alloc_test.aipl` |
| `47` | `std/alloc/pool_alloc.aipl` | `poolIsHandleValid` | `pub fn poolIsHandleValid(pool: Pool, generations: [int], handle: PoolHandle): bool:` | `tests/functions/alloc/pool_alloc_test.aipl` |
| `48` | `std/alloc/pool_alloc.aipl` | `poolReleaseHandle` | `pub fn poolReleaseHandle(mut pool: Pool, mut generations: [int], handle: PoolHandle): bool:` | `tests/functions/alloc/pool_alloc_test.aipl` |
| `49` | `std/alloc/ring_alloc.aipl` | `ringAllocNew` | `pub fn ringAllocNew(capacity: int): RingBufferAllocator:` | `tests/functions/alloc/ring_alloc_test.aipl` |
| `50` | `std/alloc/ring_alloc.aipl` | `ringAvailable` | `pub fn ringAvailable(ring: RingBufferAllocator): int:` | `tests/functions/alloc/ring_alloc_test.aipl` |
| `51` | `std/alloc/ring_alloc.aipl` | `ringAlloc` | `pub fn ringAlloc(mut ring: RingBufferAllocator, bytes: int): int:` | `tests/functions/alloc/ring_alloc_test.aipl` |
| `52` | `std/alloc/ring_alloc.aipl` | `ringFreeOldest` | `pub fn ringFreeOldest(mut ring: RingBufferAllocator, bytes: int): void:` | `tests/functions/alloc/ring_alloc_test.aipl` |
| `53` | `std/alloc/ring_alloc.aipl` | `ringReset` | `pub fn ringReset(mut ring: RingBufferAllocator): void:` | `tests/functions/alloc/ring_alloc_test.aipl` |
| `54` | `std/alloc/ring_alloc.aipl` | `ringDestroy` | `pub fn ringDestroy(mut ring: RingBufferAllocator): void:` | `tests/functions/alloc/ring_alloc_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `arenaMark` (`std/alloc/arena.aipl`)

- **Signature**: `pub fn arenaMark(): int:`
- **Import**: `import * from "std/alloc/arena"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/alloc/arena_test.aipl` | **Example**: `examples/ex_022_alloc_arena_bump_profiler_cli.aipl`
- **Behavioral Summary**: Capture baseline watermark before allocations and verify non-negative watermark offset. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `0`.

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

---

### `arenaReset` (`std/alloc/arena.aipl`)

- **Signature**: `pub fn arenaReset(mark: int): int:`
- **Import**: `import * from "std/alloc/arena"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mark: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/alloc/arena_test.aipl` | **Example**: `examples/ex_023_alloc_pool_fixed_block_cli.aipl`
- **Behavioral Summary**: Rewind arena to `mark` and assert `arenaAllocatedBytes() == mark`. Concrete nominal inputs: `mark: int = 1`; exercises core body path returning/computing `mark`.

```aipl
module tests.functions.alloc.arena_z2_test
import * from "std/alloc/arena"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_arena_arenaReset_2(): int:
  let arg_mark = 4
  let edge_mark = 1
  let resNom = arenaReset(arg_mark)
  let resEdge = arenaReset(edge_mark)
  assertEqInt(resNom, 0, "arenaReset nominal resNom == 0")
  assertEqInt(resEdge, 0, "arenaReset boundary resEdge == 0")
  ret 0
```

---

### `arenaAllocatedBytes` (`std/alloc/arena.aipl`)

- **Signature**: `pub fn arenaAllocatedBytes(): int:`
- **Import**: `import * from "std/alloc/arena"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/alloc/arena_test.aipl` | **Example**: `examples/ex_024_alloc_page_virtual_slab_cli.aipl`
- **Behavioral Summary**: Verify byte delta after `arenaAlloc(256)` is `>= 256` and returns to baseline after `arenaReset(mark)`. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `0`.

```aipl
module tests.functions.alloc.arena_z3_test
import * from "std/alloc/arena"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_arena_arenaAllocatedBytes_3(): int:
  let resNom = arenaAllocatedBytes()
  let resEdge = arenaAllocatedBytes()
  assertEqInt(resNom, 0, "arenaAllocatedBytes nominal resNom == 0")
  assertEqInt(resEdge, 0, "arenaAllocatedBytes boundary resEdge == 0")
  ret 0
```

---

### `arenaAlloc` (`std/alloc/arena.aipl`)

- **Signature**: `pub fn arenaAlloc(bytes: int): int:`
- **Import**: `import * from "std/alloc/arena"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bytes: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/alloc/arena_test.aipl` | **Example**: `examples/ex_022_alloc_arena_bump_profiler_cli.aipl`
- **Behavioral Summary**: Allocate 64 bytes and 128 bytes; verify returned pointers are distinct and `arenaAllocatedBytes()` increases monotonically. Concrete nominal inputs: `bytes: int = 64`; exercises core body path returning/computing `bytes`.

```aipl
module tests.functions.alloc.arena_z4_test
import * from "std/alloc/arena"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_arena_arenaAlloc_4(): int:
  let arg_bytes = 4
  let edge_bytes = 1
  let resNom = arenaAlloc(arg_bytes)
  let resEdge = arenaAlloc(edge_bytes)
  assertEqInt(resNom, 8, "arenaAlloc nominal resNom == 8")
  assertEqInt(resEdge, 16, "arenaAlloc boundary resEdge == 16")
  ret 0
```

---

### `arenaActiveDepth` (`std/alloc/arena.aipl`)

- **Signature**: `pub fn arenaActiveDepth(): int:`
- **Import**: `import * from "std/alloc/arena"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/alloc/arena_test.aipl` | **Example**: `examples/ex_023_alloc_pool_fixed_block_cli.aipl`
- **Behavioral Summary**: Verify depth increments on `arenaScopeBegin()` and decrements on `arenaScopeEnd(scope)`. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `0`.

```aipl
module tests.functions.alloc.arena_z5_test
import * from "std/alloc/arena"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_arena_arenaActiveDepth_5(): int:
  let resNom = arenaActiveDepth()
  let resEdge = arenaActiveDepth()
  assertEqInt(resNom, 0, "arenaActiveDepth nominal resNom == 0")
  assertEqInt(resEdge, 0, "arenaActiveDepth boundary resEdge == 0")
  ret 0
```

---

### `arenaPopEvacuate` (`std/alloc/arena.aipl`)

- **Signature**: `pub fn arenaPopEvacuate(mark: int, val: any): any:`
- **Import**: `import * from "std/alloc/arena"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mark: int, val: any` | **Returns**: `any`
- **Unit Test**: `tests/functions/alloc/arena_test.aipl` | **Example**: `examples/ex_024_alloc_page_virtual_slab_cli.aipl`
- **Behavioral Summary**: Construct a composite struct/string inside a nested arena scope, call `arenaPopEvacuate(mark, val)`, and verify the evacuated value remains intact after the scope is rewound. Concrete nominal inputs: `mark: int = 1`, `val: any = 42`; exercises core body path returning/computing `val`.

```aipl
module tests.functions.alloc.arena_z6_test
import * from "std/alloc/arena"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_arena_arenaPopEvacuate_6(): int:
  let arg_mark = 4
  let edge_mark = 1
  let arg_val = 1
  let edge_val = 0
  let resNom = arenaPopEvacuate(arg_mark, arg_val)
  let resEdge = arenaPopEvacuate(edge_mark, edge_val)
  assertEqInt(int(resNom), 1, "arenaPopEvacuate nominal int(resNom) == 1")
  assertEqInt(int(resEdge), 0, "arenaPopEvacuate boundary int(resEdge) == 0")
  ret 0
```

---

### `arenaStats` (`std/alloc/arena.aipl`)

- **Signature**: `pub fn arenaStats(): Map[str, int]:`
- **Import**: `import * from "std/alloc/arena"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Map[str, int]`
- **Unit Test**: `tests/functions/alloc/arena_test.aipl` | **Example**: `examples/ex_022_alloc_arena_bump_profiler_cli.aipl`
- **Behavioral Summary**: Verify map telemetry contains `"allocated_bytes"` and `"active_depth"` matching current arena state. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `stats`.

```aipl
module tests.functions.alloc.arena_z7_test
import * from "std/alloc/arena"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_arena_arenaStats_7(): int:
  let resNom = arenaStats()
  let resEdge = arenaStats()
  assertEqInt(resNom.len(), 7, "arenaStats nominal resNom.len() == 7")
  assertEqInt(resEdge.len(), 7, "arenaStats boundary resEdge.len() == 7")
  ret 0
```

---

### `arenaStatsStruct` (`std/alloc/arena.aipl`)

- **Signature**: `pub fn arenaStatsStruct(): ArenaStats:`
- **Import**: `import * from "std/alloc/arena"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `ArenaStats`
- **Unit Test**: `tests/functions/alloc/arena_test.aipl` | **Example**: `examples/ex_023_alloc_pool_fixed_block_cli.aipl`
- **Behavioral Summary**: Verify `stats.allocatedBytes == arenaAllocatedBytes()` and `stats.activeDepth == arenaActiveDepth()`. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `ArenaStats(allocatedBytes = cur, peakBytes = pk, resetCount = rs, markCount = mk)`.

```aipl
module tests.functions.alloc.arena_z8_test
import * from "std/alloc/arena"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_arena_arenaStatsStruct_8(): int:
  let resNom = arenaStatsStruct()
  let resEdge = arenaStatsStruct()
  assertEqInt(resNom.allocatedBytes, 1, "arenaStatsStruct nominal resNom.allocatedBytes == 1")
  assertEqInt(resEdge.allocatedBytes, 1, "arenaStatsStruct boundary resEdge.allocatedBytes == 1")
  ret 0
```

---

### `withScratchArena` (`std/alloc/arena.aipl`)

- **Signature**: `pub fn withScratchArena(bytesToScratch: int): int:`
- **Import**: `import * from "std/alloc/arena"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bytesToScratch: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/alloc/arena_test.aipl` | **Example**: `examples/ex_024_alloc_page_virtual_slab_cli.aipl`
- **Behavioral Summary**: Execute temporary scratch allocation and verify zero net retention after scratch block completes. Concrete nominal inputs: `bytesToScratch: int = 64`; exercises core body path returning/computing `allocRes`.

```aipl
module tests.functions.alloc.arena_z9_test
import * from "std/alloc/arena"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_arena_withScratchArena_9(): int:
  let arg_bytesToScratch = 4
  let edge_bytesToScratch = 1
  let resNom = withScratchArena(arg_bytesToScratch)
  let resEdge = withScratchArena(edge_bytesToScratch)
  assertEqStr(str(resNom), "nil", "withScratchArena nominal str(resNom) == nil")
  assertEqStr(str(resEdge), "nil", "withScratchArena boundary str(resEdge) == nil")
  ret 0
```

---

### `arenaScopeBegin` (`std/alloc/arena.aipl`)

- **Signature**: `pub fn arenaScopeBegin(): ArenaScope:`
- **Import**: `import * from "std/alloc/arena"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `ArenaScope`
- **Unit Test**: `tests/functions/alloc/arena_test.aipl` | **Example**: `examples/ex_022_alloc_arena_bump_profiler_cli.aipl`
- **Behavioral Summary**: Begin nested scope and verify `arenaActiveDepth()` increases by `1`. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `ArenaScope(mark = arenaMark(), depth = arenaActiveDepth())`.

```aipl
module tests.functions.alloc.arena_z10_test
import * from "std/alloc/arena"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_arena_arenaScopeBegin_10(): int:
  let resNom = arenaScopeBegin()
  let resEdge = arenaScopeBegin()
  assertEqInt(resNom.mark, 1, "arenaScopeBegin nominal resNom.mark == 1")
  assertEqInt(resEdge.mark, 1, "arenaScopeBegin boundary resEdge.mark == 1")
  ret 0
```

---

### `arenaScopeEnd` (`std/alloc/arena.aipl`)

- **Signature**: `pub fn arenaScopeEnd(scope: ArenaScope): int:`
- **Import**: `import * from "std/alloc/arena"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `scope: ArenaScope` | **Returns**: `int`
- **Unit Test**: `tests/functions/alloc/arena_test.aipl` | **Example**: `examples/ex_023_alloc_pool_fixed_block_cli.aipl`
- **Behavioral Summary**: End nested scope and verify `arenaActiveDepth()` and `arenaAllocatedBytes()` restore to pre-scope state. Concrete nominal inputs: `scope: ArenaScope = ArenaScope(mark = 1, depth = int = 0())`; exercises core body path returning/computing `arenaReset(scope.mark)`.

```aipl
module tests.functions.alloc.arena_z11_test
import * from "std/alloc/arena"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_arena_arenaScopeEnd_11(): int:
  let arg_scope = ArenaScope(mark = 4, depth = 0)
  let edge_scope = ArenaScope(mark = 1, depth = 0)
  let resNom = arenaScopeEnd(arg_scope)
  let resEdge = arenaScopeEnd(edge_scope)
  assertEqInt(resNom, 4, "arenaScopeEnd nominal resNom == 4")
  assertEqInt(resEdge, 1, "arenaScopeEnd boundary resEdge == 1")
  ret 0
```

---

### `mapNewIn` (`std/alloc/arena.aipl`)

- **Signature**: `pub fn mapNewIn(scope: ArenaScope): Map[str, any]:`
- **Import**: `import * from "std/alloc/arena"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `scope: ArenaScope` | **Returns**: `Map[str, any]`
- **Unit Test**: `tests/functions/alloc/arena_test.aipl` | **Example**: `examples/ex_024_alloc_page_virtual_slab_cli.aipl`
- **Behavioral Summary**: Allocate a map inside scoped arena, populate keys, and verify lookup integrity. Concrete nominal inputs: `scope: ArenaScope = ArenaScope(mark = 1, depth = int = 0())`; exercises core body path returning/computing `m`.

```aipl
module tests.functions.alloc.arena_z12_test
import * from "std/alloc/arena"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_arena_mapNewIn_12(): int:
  let arg_scope = ArenaScope(mark = 4, depth = 0)
  let edge_scope = ArenaScope(mark = 1, depth = 0)
  let resNom = mapNewIn(arg_scope)
  let resEdge = mapNewIn(edge_scope)
  assertEqInt(resNom.len(), 0, "mapNewIn nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "mapNewIn boundary resEdge.len() == 0")
  ret 0
```

---

### `arrayNewIn` (`std/alloc/arena.aipl`)

- **Signature**: `pub fn arrayNewIn(scope: ArenaScope, cap: int): [any]:`
- **Import**: `import * from "std/alloc/arena"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `scope: ArenaScope, cap: int` | **Returns**: `[any]`
- **Unit Test**: `tests/functions/alloc/arena_test.aipl` | **Example**: `examples/ex_022_alloc_arena_bump_profiler_cli.aipl`
- **Behavioral Summary**: Allocate a pre-reserved dynamic array in scoped arena and push elements. Concrete nominal inputs: `scope: ArenaScope = ArenaScope(mark = 1, depth = int = 0())`, `cap: int = 64`; exercises core body path returning/computing `a`.

```aipl
module tests.functions.alloc.arena_z13_test
import * from "std/alloc/arena"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_arena_arrayNewIn_13(): int:
  let arg_scope = ArenaScope(mark = 4, depth = 0)
  let edge_scope = ArenaScope(mark = 1, depth = 0)
  let arg_cap = 4
  let edge_cap = 1
  let resNom = arrayNewIn(arg_scope, arg_cap)
  let resEdge = arrayNewIn(edge_scope, edge_cap)
  assertEqInt(resNom.len(), 0, "arrayNewIn nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "arrayNewIn boundary resEdge.len() == 0")
  ret 0
```

---

### `arenaAllocStrIn` (`std/alloc/arena.aipl`)

- **Signature**: `pub fn arenaAllocStrIn(scope: ArenaScope, s: str): str:`
- **Import**: `import * from "std/alloc/arena"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `scope: ArenaScope, s: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/alloc/arena_test.aipl` | **Example**: `examples/ex_023_alloc_pool_fixed_block_cli.aipl`
- **Behavioral Summary**: Intern/copy string into target `ArenaScope` and assert string equality. Concrete nominal inputs: `scope: ArenaScope = ArenaScope(mark = 1, depth = int = 0())`, `s: str = "aipl_test"`; exercises core body path returning/computing `s`.

```aipl
module tests.functions.alloc.arena_z14_test
import * from "std/alloc/arena"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_arena_arenaAllocStrIn_14(): int:
  let arg_scope = ArenaScope(mark = 4, depth = 0)
  let edge_scope = ArenaScope(mark = 1, depth = 0)
  let arg_s = "test"
  let edge_s = "a"
  let resNom = arenaAllocStrIn(arg_scope, arg_s)
  let resEdge = arenaAllocStrIn(edge_scope, edge_s)
  assertEqStr(resNom, "test", "arenaAllocStrIn nominal string matches")
  assertEqStr(resEdge, "a", "arenaAllocStrIn boundary string matches")
  ret 0
```

---

### `gpaInit` (`std/alloc/gpa.aipl`)

- **Signature**: `pub fn gpaInit(): void:`
- **Import**: `import * from "std/alloc/gpa"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/alloc/gpa_test.aipl` | **Example**: `examples/ex_024_alloc_page_virtual_slab_cli.aipl`
- **Behavioral Summary**: Initialize global GPA tracking state and verify `gpaGetStats().activeCount == 0` and `gpaReportLeaks() == 0`. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `void state update`.

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

---

### `gpaAlloc` (`std/alloc/gpa.aipl`)

- **Signature**: `pub fn gpaAlloc(bytes: int, callerId: int = 0): int:`
- **Import**: `import * from "std/alloc/gpa"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bytes: int, callerId: int = 0` | **Returns**: `int`
- **Unit Test**: `tests/functions/alloc/gpa_test.aipl` | **Example**: `examples/ex_022_alloc_arena_bump_profiler_cli.aipl`
- **Behavioral Summary**: Allocate two tagged blocks (`callerId = 101`, `callerId = 202`), verify non-zero pointer IDs and `gpaGetStats().currentBytes` increase. Concrete nominal inputs: `bytes: int = 64`, `callerId: int = 1`; exercises core body path returning/computing `base + 32`.

```aipl
module tests.functions.alloc.gpa_z2_test
import * from "std/alloc/gpa"
import { ptrAlloc, ptrFree, ptrReadI64, ptrWriteI64, ptrMemcpy, ptrMemset } from "std/rt/rt_ptr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpa_gpaAlloc_2(): int:
  let arg_bytes = 4
  let edge_bytes = 1
  let arg_callerId = 1
  let edge_callerId = 0
  let resNom = gpaAlloc(arg_bytes, arg_callerId)
  let resEdge = gpaAlloc(edge_bytes, edge_callerId)
  assert(resNom > 0, "gpaAlloc nominal resNom > 0")
  assert(resEdge > 0, "gpaAlloc boundary resEdge > 0")
  ret 0
```

---

### `gpaValidatePtr` (`std/alloc/gpa.aipl`)

- **Signature**: `pub fn gpaValidatePtr(ptr: int): bool:`
- **Import**: `import * from "std/alloc/gpa"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ptr: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/alloc/gpa_test.aipl` | **Example**: `examples/ex_023_alloc_pool_fixed_block_cli.aipl`
- **Behavioral Summary**: Assert `gpaValidatePtr` is `true` for live allocated pointer, `false` for `0` (null), and `false` after `gpaFree(ptr)`. Concrete nominal inputs: `ptr: int = 1`; exercises core body path returning/computing `backCanary == GPA_CANARY_MAGIC`.

```aipl
module tests.functions.alloc.gpa_z3_test
import * from "std/alloc/gpa"
import { ptrAlloc, ptrFree, ptrReadI64, ptrWriteI64, ptrMemcpy, ptrMemset } from "std/rt/rt_ptr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpa_gpaValidatePtr_3(): int:
  let arg_ptr = 1
  let edge_ptr = 0
  let resNom = gpaValidatePtr(arg_ptr)
  let resEdge = gpaValidatePtr(edge_ptr)
  assert(resNom == false, "gpaValidatePtr nominal resNom == false")
  assert(resEdge == false, "gpaValidatePtr boundary resEdge == false")
  ret 0
```

---

### `gpaFree` (`std/alloc/gpa.aipl`)

- **Signature**: `pub fn gpaFree(ptr: int): bool:`
- **Import**: `import * from "std/alloc/gpa"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ptr: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/alloc/gpa_test.aipl` | **Example**: `examples/ex_024_alloc_page_virtual_slab_cli.aipl`
- **Behavioral Summary**: Free live block (`true`), verify double-free returns `false`, and verify `activeCount` decrements. Concrete nominal inputs: `ptr: int = 1`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.alloc.gpa_z4_test
import * from "std/alloc/gpa"
import { ptrAlloc, ptrFree, ptrReadI64, ptrWriteI64, ptrMemcpy, ptrMemset } from "std/rt/rt_ptr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpa_gpaFree_4(): int:
  let arg_ptr = 1
  let edge_ptr = 0
  let resNom = gpaFree(arg_ptr)
  let resEdge = gpaFree(edge_ptr)
  assert(resNom == false, "gpaFree nominal resNom == false")
  assert(resEdge == false, "gpaFree boundary resEdge == false")
  ret 0
```

---

### `gpaRealloc` (`std/alloc/gpa.aipl`)

- **Signature**: `pub fn gpaRealloc(ptr: int, newBytes: int): int:`
- **Import**: `import * from "std/alloc/gpa"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ptr: int, newBytes: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/alloc/gpa_test.aipl` | **Example**: `examples/ex_022_alloc_arena_bump_profiler_cli.aipl`
- **Behavioral Summary**: Grow existing block from 128 bytes to 512 bytes and verify `gpaValidatePtr` remains `true` and `currentBytes` reflects `+384` delta. Concrete nominal inputs: `ptr: int = 1`, `newBytes: int = 64`; exercises core body path returning/computing `newPtr`.

```aipl
module tests.functions.alloc.gpa_z5_test
import * from "std/alloc/gpa"
import { ptrAlloc, ptrFree, ptrReadI64, ptrWriteI64, ptrMemcpy, ptrMemset } from "std/rt/rt_ptr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpa_gpaRealloc_5(): int:
  let arg_ptr = 1
  let edge_ptr = 0
  let arg_newBytes = 4
  let edge_newBytes = 1
  let resNom = gpaRealloc(arg_ptr, arg_newBytes)
  let resEdge = gpaRealloc(edge_ptr, edge_newBytes)
  assertEqInt(resNom, 0, "gpaRealloc nominal resNom == 0")
  assert(resEdge > 0, "gpaRealloc boundary resEdge > 0")
  ret 0
```

---

### `gpaGetStats` (`std/alloc/gpa.aipl`)

- **Signature**: `pub fn gpaGetStats(): GpaStats:`
- **Import**: `import * from "std/alloc/gpa"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `GpaStats`
- **Unit Test**: `tests/functions/alloc/gpa_test.aipl` | **Example**: `examples/ex_023_alloc_pool_fixed_block_cli.aipl`
- **Behavioral Summary**: Assert `totalAllocated`, `totalFreed`, `currentBytes`, `peakBytes`, and `activeCount` match exact allocation history. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `GpaStats(`.

```aipl
module tests.functions.alloc.gpa_z6_test
import * from "std/alloc/gpa"
import { ptrAlloc, ptrFree, ptrReadI64, ptrWriteI64, ptrMemcpy, ptrMemset } from "std/rt/rt_ptr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpa_gpaGetStats_6(): int:
  let resNom = gpaGetStats()
  let resEdge = gpaGetStats()
  assertEqInt(resNom.liveAllocations, 3, "gpaGetStats nominal resNom.liveAllocations == 3")
  assertEqInt(resEdge.liveAllocations, 3, "gpaGetStats boundary resEdge.liveAllocations == 3")
  ret 0
```

---

### `gpaReportLeaks` (`std/alloc/gpa.aipl`)

- **Signature**: `pub fn gpaReportLeaks(): int:`
- **Import**: `import * from "std/alloc/gpa"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/alloc/gpa_test.aipl` | **Example**: `examples/ex_024_alloc_page_virtual_slab_cli.aipl`
- **Behavioral Summary**: Leave 1 block intentionally unfreed, verify `gpaReportLeaks() == 1`, then free it and verify `gpaReportLeaks() == 0`. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `stats.liveAllocations`.

```aipl
module tests.functions.alloc.gpa_z7_test
import * from "std/alloc/gpa"
import { ptrAlloc, ptrFree, ptrReadI64, ptrWriteI64, ptrMemcpy, ptrMemset } from "std/rt/rt_ptr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpa_gpaReportLeaks_7(): int:
  let resNom = gpaReportLeaks()
  let resEdge = gpaReportLeaks()
  assertEqInt(resNom, 3, "gpaReportLeaks nominal resNom == 3")
  assertEqInt(resEdge, 3, "gpaReportLeaks boundary resEdge == 3")
  ret 0
```

---

### `systemPageSize` (`std/alloc/page_alloc.aipl`)

- **Signature**: `pub fn systemPageSize(): int:`
- **Import**: `import * from "std/alloc/page_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/alloc/page_alloc_test.aipl` | **Example**: `examples/ex_022_alloc_arena_bump_profiler_cli.aipl`
- **Behavioral Summary**: Assert `systemPageSize() == 4096` (power-of-two OS page size). Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `DEFAULT_SYSTEM_PAGE_SIZE`.

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

---

### `pageAllocatorNew` (`std/alloc/page_alloc.aipl`)

- **Signature**: `pub fn pageAllocatorNew(): VirtualPageAllocator:`
- **Import**: `import * from "std/alloc/page_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `VirtualPageAllocator`
- **Unit Test**: `tests/functions/alloc/page_alloc_test.aipl` | **Example**: `examples/ex_023_alloc_pool_fixed_block_cli.aipl`
- **Behavioral Summary**: Initialize `VirtualPageAllocator` descriptor and verify `pageSize == 4096` and `allocatedPages == 0`. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `VirtualPageAllocator(pageSize = DEFAULT_SYSTEM_PAGE_SIZE, allocatedPages = 0, committedBytes = 0)`.

```aipl
module tests.functions.alloc.page_alloc_z2_test
import * from "std/alloc/page_alloc"
import { ptrAlloc, ptrFree, ptrMemset } from "std/rt/rt_ptr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_page_alloc_pageAllocatorNew_2(): int:
  let resNom = pageAllocatorNew()
  let resEdge = pageAllocatorNew()
  assertEqInt(resNom.pageSize, 4096, "pageAllocatorNew nominal resNom.pageSize == 4096")
  assertEqInt(resEdge.pageSize, 4096, "pageAllocatorNew boundary resEdge.pageSize == 4096")
  ret 0
```

---

### `pageAlloc` (`std/alloc/page_alloc.aipl`)

- **Signature**: `pub fn pageAlloc(numPages: int): int:`
- **Import**: `import * from "std/alloc/page_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `numPages: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/alloc/page_alloc_test.aipl` | **Example**: `examples/ex_024_alloc_page_virtual_slab_cli.aipl`
- **Behavioral Summary**: Allocate 4 pages (`16384` bytes) and verify non-zero page-aligned base address (`addr % 4096 == 0`). Concrete nominal inputs: `numPages: int = 1`; exercises core body path returning/computing `addr`.

```aipl
module tests.functions.alloc.page_alloc_z3_test
import * from "std/alloc/page_alloc"
import { ptrAlloc, ptrFree, ptrMemset } from "std/rt/rt_ptr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_page_alloc_pageAlloc_3(): int:
  let arg_numPages = 1
  let edge_numPages = 0
  let resNom = pageAlloc(arg_numPages)
  let resEdge = pageAlloc(edge_numPages)
  assert(resNom > 0, "pageAlloc nominal resNom > 0")
  assertEqInt(resEdge, 0, "pageAlloc boundary resEdge == 0")
  ret 0
```

---

### `pageFree` (`std/alloc/page_alloc.aipl`)

- **Signature**: `pub fn pageFree(addr: int, numPages: int): bool:`
- **Import**: `import * from "std/alloc/page_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `addr: int, numPages: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/alloc/page_alloc_test.aipl` | **Example**: `examples/ex_022_alloc_arena_bump_profiler_cli.aipl`
- **Behavioral Summary**: Release 4 pages and verify return `true` (`false` on invalid `addr <= 0` or `numPages <= 0`). Concrete nominal inputs: `addr: int = 1`, `numPages: int = 1`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.alloc.page_alloc_z4_test
import * from "std/alloc/page_alloc"
import { ptrAlloc, ptrFree, ptrMemset } from "std/rt/rt_ptr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_page_alloc_pageFree_4(): int:
  let arg_addr = pageAlloc(1)
  let edge_addr = 0
  let arg_numPages = 1
  let edge_numPages = 0
  let resNom = pageFree(arg_addr, arg_numPages)
  let resEdge = pageFree(edge_addr, edge_numPages)
  assert(resNom == true, "pageFree nominal resNom == true")
  assert(resEdge == false, "pageFree boundary resEdge == false")
  ret 0
```

---

### `pageProtect` (`std/alloc/page_alloc.aipl`)

- **Signature**: `pub fn pageProtect(addr: int, numPages: int, protMask: int): bool:`
- **Import**: `import * from "std/alloc/page_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `addr: int, numPages: int, protMask: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/alloc/page_alloc_test.aipl` | **Example**: `examples/ex_023_alloc_pool_fixed_block_cli.aipl`
- **Behavioral Summary**: PROT_WRITE`) and assert `true`. Concrete nominal inputs: `addr: int = 1`, `numPages: int = 1`, `protMask: int = 1`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.alloc.page_alloc_z5_test
import * from "std/alloc/page_alloc"
import { ptrAlloc, ptrFree, ptrMemset } from "std/rt/rt_ptr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_page_alloc_pageProtect_5(): int:
  let arg_addr = pageAlloc(1)
  let edge_addr = 0
  let arg_numPages = 1
  let edge_numPages = 0
  let arg_protMask = 4
  let edge_protMask = 1
  let resNom = pageProtect(arg_addr, arg_numPages, arg_protMask)
  let resEdge = pageProtect(edge_addr, edge_numPages, edge_protMask)
  assert(resNom == true, "pageProtect nominal resNom == true")
  assert(resEdge == false, "pageProtect boundary resEdge == false")
  ret 0
```

---

### `pageAlignUp` (`std/alloc/page_alloc.aipl`)

- **Signature**: `pub fn pageAlignUp(bytes: int): int:`
- **Import**: `import * from "std/alloc/page_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bytes: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/alloc/page_alloc_test.aipl` | **Example**: `examples/ex_024_alloc_page_virtual_slab_cli.aipl`
- **Behavioral Summary**: Test `pageAlignUp(0) == 0`, `pageAlignUp(1) == 4096`, `pageAlignUp(4096) == 4096`, `pageAlignUp(4097) == 8192`. Concrete nominal inputs: `bytes: int = 64`; exercises core body path returning/computing `(bytes + mask) & (~mask)`.

```aipl
module tests.functions.alloc.page_alloc_z6_test
import * from "std/alloc/page_alloc"
import { ptrAlloc, ptrFree, ptrMemset } from "std/rt/rt_ptr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_page_alloc_pageAlignUp_6(): int:
  let arg_bytes = 4
  let edge_bytes = 1
  let resNom = pageAlignUp(arg_bytes)
  let resEdge = pageAlignUp(edge_bytes)
  assertEqInt(resNom, 4096, "pageAlignUp nominal resNom == 4096")
  assertEqInt(resEdge, 4096, "pageAlignUp boundary resEdge == 4096")
  ret 0
```

---

### `pageCountForBytes` (`std/alloc/page_alloc.aipl`)

- **Signature**: `pub fn pageCountForBytes(bytes: int): int:`
- **Import**: `import * from "std/alloc/page_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bytes: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/alloc/page_alloc_test.aipl` | **Example**: `examples/ex_022_alloc_arena_bump_profiler_cli.aipl`
- **Behavioral Summary**: Test `pageCountForBytes(0) == 0`, `pageCountForBytes(1) == 1`, `pageCountForBytes(4096) == 1`, `pageCountForBytes(4097) == 2`. Concrete nominal inputs: `bytes: int = 64`; exercises core body path returning/computing `(bytes + DEFAULT_SYSTEM_PAGE_SIZE - 1) / DEFAULT_SYSTEM_PAGE_SIZE`.

```aipl
module tests.functions.alloc.page_alloc_z7_test
import * from "std/alloc/page_alloc"
import { ptrAlloc, ptrFree, ptrMemset } from "std/rt/rt_ptr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_page_alloc_pageCountForBytes_7(): int:
  let arg_bytes = 4
  let edge_bytes = 1
  let resNom = pageCountForBytes(arg_bytes)
  let resEdge = pageCountForBytes(edge_bytes)
  assertEqInt(resNom, 1, "pageCountForBytes nominal resNom == 1")
  assertEqInt(resEdge, 1, "pageCountForBytes boundary resEdge == 1")
  ret 0
```

---

### `poolNew` (`std/alloc/pool_alloc.aipl`)

- **Signature**: `pub fn poolNew[T](capacity: int): FixedObjectPool[T]:`
- **Import**: `import * from "std/alloc/pool_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `capacity: int` | **Returns**: `FixedObjectPool[T]`
- **Unit Test**: `tests/functions/alloc/pool_alloc_test.aipl` | **Example**: `examples/ex_023_alloc_pool_fixed_block_cli.aipl`
- **Behavioral Summary**: Create `FixedObjectPool[int]` with `capacity = 4` and verify `.count() == 0` and `.isFull() == false`.

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

---

### `acquire` (`std/alloc/pool_alloc.aipl`)

- **Signature**: `pub fn (mut self: FixedObjectPool[T]) acquire(item: T): Option[GenerationalHandle]:`
- **Import**: `import * from "std/alloc/pool_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `mut self: FixedObjectPool[T]` | **Parameters**: `item: T` | **Returns**: `Option[GenerationalHandle]`
- **Unit Test**: `tests/functions/alloc/pool_alloc_test.aipl` | **Example**: `examples/ex_024_alloc_page_virtual_slab_cli.aipl`
- **Behavioral Summary**: Acquire 4 slots, verifying `isSome() == true` for slots `0..3` and `isNone() == true` when full (`5th` acquire). Concrete nominal inputs: receiver `recvObj: FixedObjectPool[T] = poolNew(4)`, `item: T = 42`; exercises core body path returning/computing `Some(GenerationalHandle(index = idx, generation = genVal))`.

```aipl
module tests.functions.alloc.pool_alloc_z2_test
import * from "std/alloc/pool_alloc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_pool_alloc_FixedObjectPool_T__acquire_2(): int:
  let mut recv_self = poolNew(4)
  let mut edge_self = poolNew(4)
  let arg_item = 1
  let edge_item = 0
  let resNom = recv_self.acquire(arg_item)
  let resEdge = edge_self.acquire(edge_item)
  assert(resNom.isSome() == true, "acquire nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "acquire boundary resEdge.isSome() == true")
  ret 0
```

---

### `isValid` (`std/alloc/pool_alloc.aipl`)

- **Signature**: `pub fn (self: FixedObjectPool[T]) isValid(handle: GenerationalHandle): bool:`
- **Import**: `import * from "std/alloc/pool_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `self: FixedObjectPool[T]` | **Parameters**: `handle: GenerationalHandle` | **Returns**: `bool`
- **Unit Test**: `tests/functions/alloc/pool_alloc_test.aipl` | **Example**: `examples/ex_022_alloc_arena_bump_profiler_cli.aipl`
- **Behavioral Summary**: Verify `true` for live `GenerationalHandle`, `false` after `.release(handle)`, and `false` after slot reuse (ABA safety!). Concrete nominal inputs: receiver `recvObj: FixedObjectPool[T] = poolNew(4)`, `handle: GenerationalHandle = GenerationalHandle(index = 0, generation = 1)`; exercises core body path returning/computing `self.generations[handle.index] == handle.generation`.

```aipl
module tests.functions.alloc.pool_alloc_z3_test
import * from "std/alloc/pool_alloc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_pool_alloc_FixedObjectPool_T__isValid_3(): int:
  let recv_self = poolNew(4)
  let edge_self = poolNew(4)
  let arg_handle = GenerationalHandle(index = 0, generation = 4)
  let edge_handle = GenerationalHandle(index = 0, generation = 1)
  let resNom = recv_self.isValid(arg_handle)
  let resEdge = edge_self.isValid(edge_handle)
  assert(resNom == false, "isValid nominal resNom == false")
  assert(resEdge == false, "isValid boundary resEdge == false")
  ret 0
```

---

### `get` (`std/alloc/pool_alloc.aipl`)

- **Signature**: `pub fn (self: FixedObjectPool[T]) get(handle: GenerationalHandle): Option[T]:`
- **Import**: `import * from "std/alloc/pool_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `self: FixedObjectPool[T]` | **Parameters**: `handle: GenerationalHandle` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/alloc/pool_alloc_test.aipl` | **Example**: `examples/ex_023_alloc_pool_fixed_block_cli.aipl`
- **Behavioral Summary**: Retrieve `Some(item)` for valid handle and `None` for stale/released handle. Concrete nominal inputs: receiver `recvObj: FixedObjectPool[T] = poolNew(4)`, `handle: GenerationalHandle = GenerationalHandle(index = 0, generation = 1)`; exercises core body path returning/computing `Some(self.slots[handle.index])`.

```aipl
module tests.functions.alloc.pool_alloc_z4_test
import * from "std/alloc/pool_alloc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_pool_alloc_FixedObjectPool_T__get_4(): int:
  let recv_self = poolNew(4)
  let edge_self = poolNew(4)
  let arg_handle = GenerationalHandle(index = 0, generation = 4)
  let edge_handle = GenerationalHandle(index = 0, generation = 1)
  let resNom = recv_self.get(arg_handle)
  let resEdge = edge_self.get(edge_handle)
  assert(resNom.isSome() == false, "get nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "get boundary resEdge.isSome() == false")
  ret 0
```

---

### `release` (`std/alloc/pool_alloc.aipl`)

- **Signature**: `pub fn (mut self: FixedObjectPool[T]) release(handle: GenerationalHandle): bool:`
- **Import**: `import * from "std/alloc/pool_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `mut self: FixedObjectPool[T]` | **Parameters**: `handle: GenerationalHandle` | **Returns**: `bool`
- **Unit Test**: `tests/functions/alloc/pool_alloc_test.aipl` | **Example**: `examples/ex_024_alloc_page_virtual_slab_cli.aipl`
- **Behavioral Summary**: Release live handle (`true`), verify double-release of same handle returns `false`, and verify subsequent `.acquire` reuses the slot with incremented generation. Concrete nominal inputs: receiver `recvObj: FixedObjectPool[T] = poolNew(4)`, `handle: GenerationalHandle = GenerationalHandle(index = 0, generation = 1)`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.alloc.pool_alloc_z5_test
import * from "std/alloc/pool_alloc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_pool_alloc_FixedObjectPool_T__release_5(): int:
  let mut recv_self = poolNew(4)
  let mut edge_self = poolNew(4)
  let arg_handle = GenerationalHandle(index = 0, generation = 4)
  let edge_handle = GenerationalHandle(index = 0, generation = 1)
  let resNom = recv_self.release(arg_handle)
  let resEdge = edge_self.release(edge_handle)
  assert(resNom == false, "release nominal resNom == false")
  assert(resEdge == false, "release boundary resEdge == false")
  ret 0
```

---

### `count` (`std/alloc/pool_alloc.aipl`)

- **Signature**: `pub fn (self: FixedObjectPool[T]) count(): int:`
- **Import**: `import * from "std/alloc/pool_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `self: FixedObjectPool[T]` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/alloc/pool_alloc_test.aipl` | **Example**: `examples/ex_022_alloc_arena_bump_profiler_cli.aipl`
- **Behavioral Summary**: Verify active count increments on `.acquire` and decrements on `.release`. Concrete nominal inputs: receiver `recvObj: FixedObjectPool[T] = poolNew(4)`; exercises core body path returning/computing `self.activeCount`.

```aipl
module tests.functions.alloc.pool_alloc_z6_test
import * from "std/alloc/pool_alloc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_pool_alloc_FixedObjectPool_T__count_6(): int:
  let recv_self = poolNew(4)
  let edge_self = poolNew(4)
  let resNom = recv_self.count()
  let resEdge = edge_self.count()
  assertEqInt(resNom, 0, "count nominal resNom == 0")
  assertEqInt(resEdge, 0, "count boundary resEdge == 0")
  ret 0
```

---

### `isFull` (`std/alloc/pool_alloc.aipl`)

- **Signature**: `pub fn (self: FixedObjectPool[T]) isFull(): bool:`
- **Import**: `import * from "std/alloc/pool_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `self: FixedObjectPool[T]` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/alloc/pool_alloc_test.aipl` | **Example**: `examples/ex_023_alloc_pool_fixed_block_cli.aipl`
- **Behavioral Summary**: Verify `.isFull()` transitions `false -> true -> false` as pool fills and releases a slot. Concrete nominal inputs: receiver `recvObj: FixedObjectPool[T] = poolNew(4)`; exercises core body path returning/computing `self.activeCount >= self.capacity`.

```aipl
module tests.functions.alloc.pool_alloc_z7_test
import * from "std/alloc/pool_alloc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_pool_alloc_FixedObjectPool_T__isFull_7(): int:
  let recv_self = poolNew(4)
  let edge_self = poolNew(4)
  let resNom = recv_self.isFull()
  let resEdge = edge_self.isFull()
  assert(resNom == false, "isFull nominal resNom == false")
  assert(resEdge == false, "isFull boundary resEdge == false")
  ret 0
```

---

### `clear` (`std/alloc/pool_alloc.aipl`)

- **Signature**: `pub fn (mut self: FixedObjectPool[T]) clear(): void:`
- **Import**: `import * from "std/alloc/pool_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `mut self: FixedObjectPool[T]` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/alloc/pool_alloc_test.aipl` | **Example**: `examples/ex_024_alloc_page_virtual_slab_cli.aipl`
- **Behavioral Summary**: Reset pool, increment all slot generations, and verify `.count() == 0` and old handles become invalid. Concrete nominal inputs: receiver `recvObj: FixedObjectPool[T] = poolNew(4)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.alloc.pool_alloc_z8_test
import * from "std/alloc/pool_alloc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_pool_alloc_FixedObjectPool_T__clear_8(): int:
  let mut recv_self = poolNew(4)
  let mut edge_self = poolNew(4)
  recv_self.clear()
  edge_self.clear()
  assertEqInt(recv_self.activeCount, 0, "clear nominal recv_self.activeCount == 0")
  assertEqInt(recv_self.generations[0], 2, "clear nominal recv_self.generations[0] == 2")
  assertEqInt(edge_self.activeCount, 0, "clear boundary edge_self.activeCount == 0")
  assertEqInt(edge_self.generations[0], 2, "clear boundary edge_self.generations[0] == 2")
  ret 0
```

---

### `poolAcquire` (`std/alloc/pool_alloc.aipl`)

- **Signature**: `pub fn poolAcquire(mut pool: Pool): Option[int]:`
- **Import**: `import * from "std/alloc/pool_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut pool: Pool` | **Returns**: `Option[int]`
- **Unit Test**: `tests/functions/alloc/pool_alloc_test.aipl` | **Example**: `examples/ex_022_alloc_arena_bump_profiler_cli.aipl`
- **Behavioral Summary**: Acquire raw slot index from `Pool` and verify `Some(idx)`. Concrete nominal inputs: `pool: Pool = Pool()`; exercises core body path returning/computing `Some(idx)`.

```aipl
module tests.functions.alloc.pool_alloc_z9_test
import * from "std/alloc/pool_alloc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_pool_alloc_poolAcquire_9(): int:
  let arg_pool = poolNew(4)
  let edge_pool = poolNew(4)
  let resNom = poolAcquire(arg_pool)
  let resEdge = poolAcquire(edge_pool)
  assert(resNom.isSome() == true, "poolAcquire nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "poolAcquire boundary resEdge.isSome() == true")
  ret 0
```

---

### `poolRelease` (`std/alloc/pool_alloc.aipl`)

- **Signature**: `pub fn poolRelease(mut pool: Pool, idx: int): bool:`
- **Import**: `import * from "std/alloc/pool_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut pool: Pool, idx: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/alloc/pool_alloc_test.aipl` | **Example**: `examples/ex_023_alloc_pool_fixed_block_cli.aipl`
- **Behavioral Summary**: Release active slot index (`true`) and reject out-of-range or already-free index (`false`). Concrete nominal inputs: `pool: Pool = Pool()`, `idx: int = 0`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.alloc.pool_alloc_z10_test
import * from "std/alloc/pool_alloc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_pool_alloc_poolRelease_10(): int:
  let arg_pool = poolNew(4)
  let edge_pool = poolNew(4)
  let arg_idx = 1
  let edge_idx = 0
  let resNom = poolRelease(arg_pool, arg_idx)
  let resEdge = poolRelease(edge_pool, edge_idx)
  assert(resNom == false, "poolRelease nominal resNom == false")
  assert(resEdge == false, "poolRelease boundary resEdge == false")
  ret 0
```

---

### `poolIsActive` (`std/alloc/pool_alloc.aipl`)

- **Signature**: `pub fn poolIsActive(pool: Pool, idx: int): bool:`
- **Import**: `import * from "std/alloc/pool_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pool: Pool, idx: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/alloc/pool_alloc_test.aipl` | **Example**: `examples/ex_024_alloc_page_virtual_slab_cli.aipl`
- **Behavioral Summary**: Verify `true` when slot `idx` is acquired and `false` when free. Concrete nominal inputs: `pool: Pool = Pool()`, `idx: int = 0`; exercises core body path returning/computing `pool.active[idx]`.

```aipl
module tests.functions.alloc.pool_alloc_z11_test
import * from "std/alloc/pool_alloc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_pool_alloc_poolIsActive_11(): int:
  let arg_pool = poolNew(4)
  let edge_pool = poolNew(4)
  let arg_idx = 1
  let edge_idx = 0
  let resNom = poolIsActive(arg_pool, arg_idx)
  let resEdge = poolIsActive(edge_pool, edge_idx)
  assert(resNom == false, "poolIsActive nominal resNom == false")
  assert(resEdge == false, "poolIsActive boundary resEdge == false")
  ret 0
```

---

### `poolActiveIndices` (`std/alloc/pool_alloc.aipl`)

- **Signature**: `pub fn poolActiveIndices(pool: Pool): [int]:`
- **Import**: `import * from "std/alloc/pool_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pool: Pool` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/alloc/pool_alloc_test.aipl` | **Example**: `examples/ex_022_alloc_arena_bump_profiler_cli.aipl`
- **Behavioral Summary**: Acquire 3 slots, release middle slot, and verify `poolActiveIndices` returns the exact 2 remaining active indices. Concrete nominal inputs: `pool: Pool = Pool()`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.alloc.pool_alloc_z12_test
import * from "std/alloc/pool_alloc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_pool_alloc_poolActiveIndices_12(): int:
  let arg_pool = poolNew(4)
  let edge_pool = poolNew(4)
  let resNom = poolActiveIndices(arg_pool)
  let resEdge = poolActiveIndices(edge_pool)
  assertEqInt(resNom.len(), 0, "poolActiveIndices nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "poolActiveIndices boundary resEdge.len() == 0")
  ret 0
```

---

### `poolActiveCount` (`std/alloc/pool_alloc.aipl`)

- **Signature**: `pub fn poolActiveCount(pool: Pool): int:`
- **Import**: `import * from "std/alloc/pool_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pool: Pool` | **Returns**: `int`
- **Unit Test**: `tests/functions/alloc/pool_alloc_test.aipl` | **Example**: `examples/ex_023_alloc_pool_fixed_block_cli.aipl`
- **Behavioral Summary**: Verify `poolActiveCount(pool) == poolActiveIndices(pool).len()`. Concrete nominal inputs: `pool: Pool = Pool()`; exercises core body path returning/computing `pool.activeCount`.

```aipl
module tests.functions.alloc.pool_alloc_z13_test
import * from "std/alloc/pool_alloc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_pool_alloc_poolActiveCount_13(): int:
  let arg_pool = poolNew(4)
  let edge_pool = poolNew(4)
  let resNom = poolActiveCount(arg_pool)
  let resEdge = poolActiveCount(edge_pool)
  assertEqInt(resNom, 0, "poolActiveCount nominal resNom == 0")
  assertEqInt(resEdge, 0, "poolActiveCount boundary resEdge == 0")
  ret 0
```

---

### `poolClear` (`std/alloc/pool_alloc.aipl`)

- **Signature**: `pub fn poolClear(mut pool: Pool): Pool:`
- **Import**: `import * from "std/alloc/pool_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut pool: Pool` | **Returns**: `Pool`
- **Unit Test**: `tests/functions/alloc/pool_alloc_test.aipl` | **Example**: `examples/ex_024_alloc_page_virtual_slab_cli.aipl`
- **Behavioral Summary**: Clear all active slots in `Pool` and verify `poolActiveCount == 0`. Concrete nominal inputs: `pool: Pool = Pool()`; exercises core body path returning/computing `pool`.

```aipl
module tests.functions.alloc.pool_alloc_z14_test
import * from "std/alloc/pool_alloc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_pool_alloc_poolClear_14(): int:
  let arg_pool = poolNew(4)
  let edge_pool = poolNew(4)
  let resNom = poolClear(arg_pool)
  let resEdge = poolClear(edge_pool)
  assertEqInt(resNom.capacity, 4, "poolClear nominal resNom.capacity == 4")
  assertEqInt(resEdge.capacity, 4, "poolClear boundary resEdge.capacity == 4")
  ret 0
```

---

### `poolAlloc` (`std/alloc/pool_alloc.aipl`)

- **Signature**: `pub fn poolAlloc(mut pool: Pool): Option[int]:`
- **Import**: `import * from "std/alloc/pool_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut pool: Pool` | **Returns**: `Option[int]`
- **Unit Test**: `tests/functions/alloc/pool_alloc_test.aipl` | **Example**: `examples/ex_022_alloc_arena_bump_profiler_cli.aipl`
- **Behavioral Summary**: Verify alias parity with `poolAcquire`. Concrete nominal inputs: `pool: Pool = Pool()`; exercises core body path returning/computing `poolAcquire(pool)`.

```aipl
module tests.functions.alloc.pool_alloc_z15_test
import * from "std/alloc/pool_alloc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_pool_alloc_poolAlloc_15(): int:
  let arg_pool = poolNew(4)
  let edge_pool = poolNew(4)
  let resNom = poolAlloc(arg_pool)
  let resEdge = poolAlloc(edge_pool)
  assert(resNom.isSome() == true, "poolAlloc nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "poolAlloc boundary resEdge.isSome() == true")
  ret 0
```

---

### `poolFree` (`std/alloc/pool_alloc.aipl`)

- **Signature**: `pub fn poolFree(mut pool: Pool, idx: int): bool:`
- **Import**: `import * from "std/alloc/pool_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut pool: Pool, idx: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/alloc/pool_alloc_test.aipl` | **Example**: `examples/ex_023_alloc_pool_fixed_block_cli.aipl`
- **Behavioral Summary**: Verify alias parity with `poolRelease`. Concrete nominal inputs: `pool: Pool = Pool()`, `idx: int = 0`; exercises core body path returning/computing `poolRelease(pool, idx)`.

```aipl
module tests.functions.alloc.pool_alloc_z16_test
import * from "std/alloc/pool_alloc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_pool_alloc_poolFree_16(): int:
  let arg_pool = poolNew(4)
  let edge_pool = poolNew(4)
  let arg_idx = 1
  let edge_idx = 0
  let resNom = poolFree(arg_pool, arg_idx)
  let resEdge = poolFree(edge_pool, edge_idx)
  assert(resNom == false, "poolFree nominal resNom == false")
  assert(resEdge == false, "poolFree boundary resEdge == false")
  ret 0
```

---

### `poolGenerationsNew` (`std/alloc/pool_alloc.aipl`)

- **Signature**: `pub fn poolGenerationsNew(capacity: int): [int]:`
- **Import**: `import * from "std/alloc/pool_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `capacity: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/alloc/pool_alloc_test.aipl` | **Example**: `examples/ex_024_alloc_page_virtual_slab_cli.aipl`
- **Behavioral Summary**: Initialize generation counter array of length `capacity` filled with initial generation `1`. Concrete nominal inputs: `capacity: int = 64`; exercises core body path returning/computing `gens`.

```aipl
module tests.functions.alloc.pool_alloc_z17_test
import * from "std/alloc/pool_alloc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_pool_alloc_poolGenerationsNew_17(): int:
  let arg_capacity = 4
  let edge_capacity = 1
  let resNom = poolGenerationsNew(arg_capacity)
  let resEdge = poolGenerationsNew(edge_capacity)
  assertEqInt(resNom.len(), 4, "poolGenerationsNew nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 1, "poolGenerationsNew boundary resEdge.len() == 1")
  ret 0
```

---

### `poolAcquireHandle` (`std/alloc/pool_alloc.aipl`)

- **Signature**: `pub fn poolAcquireHandle(mut pool: Pool, generations: [int]): Option[PoolHandle]:`
- **Import**: `import * from "std/alloc/pool_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut pool: Pool, generations: [int]` | **Returns**: `Option[PoolHandle]`
- **Unit Test**: `tests/functions/alloc/pool_alloc_test.aipl` | **Example**: `examples/ex_022_alloc_arena_bump_profiler_cli.aipl`
- **Behavioral Summary**: Acquire `PoolHandle(index, generation)` combining `Pool` slot and generation table. Concrete nominal inputs: `pool: Pool = Pool()`, `generations: [int] = [1]`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.alloc.pool_alloc_z18_test
import * from "std/alloc/pool_alloc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_pool_alloc_poolAcquireHandle_18(): int:
  let arg_pool = poolNew(4)
  let edge_pool = poolNew(4)
  let arg_generations = [4]
  let edge_generations = []
  let resNom = poolAcquireHandle(arg_pool, arg_generations)
  let resEdge = poolAcquireHandle(edge_pool, edge_generations)
  assert(resNom.isSome() == true, "poolAcquireHandle nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "poolAcquireHandle boundary resEdge.isSome() == true")
  ret 0
```

---

### `poolIsHandleValid` (`std/alloc/pool_alloc.aipl`)

- **Signature**: `pub fn poolIsHandleValid(pool: Pool, generations: [int], handle: PoolHandle): bool:`
- **Import**: `import * from "std/alloc/pool_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pool: Pool, generations: [int], handle: PoolHandle` | **Returns**: `bool`
- **Unit Test**: `tests/functions/alloc/pool_alloc_test.aipl` | **Example**: `examples/ex_023_alloc_pool_fixed_block_cli.aipl`
- **Behavioral Summary**: Verify `true` while handle's slot is active with matching generation, and `false` after `poolReleaseHandle`. Concrete nominal inputs: `pool: Pool = Pool()`, `generations: [int] = [1]`, `handle: PoolHandle = PoolHandle(index = 0, generation = 1)`; exercises core body path returning/computing `generations[handle.index] == handle.generation`.

```aipl
module tests.functions.alloc.pool_alloc_z19_test
import * from "std/alloc/pool_alloc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_pool_alloc_poolIsHandleValid_19(): int:
  let arg_pool = poolNew(4)
  let edge_pool = poolNew(4)
  let arg_generations = [4]
  let edge_generations = []
  let arg_handle = PoolHandle(index = 0, generation = 4)
  let edge_handle = PoolHandle(index = 0, generation = 1)
  let resNom = poolIsHandleValid(arg_pool, arg_generations, arg_handle)
  let resEdge = poolIsHandleValid(edge_pool, edge_generations, edge_handle)
  assert(resNom == false, "poolIsHandleValid nominal resNom == false")
  assert(resEdge == false, "poolIsHandleValid boundary resEdge == false")
  ret 0
```

---

### `poolReleaseHandle` (`std/alloc/pool_alloc.aipl`)

- **Signature**: `pub fn poolReleaseHandle(mut pool: Pool, mut generations: [int], handle: PoolHandle): bool:`
- **Import**: `import * from "std/alloc/pool_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut pool: Pool, mut generations: [int], handle: PoolHandle` | **Returns**: `bool`
- **Unit Test**: `tests/functions/alloc/pool_alloc_test.aipl` | **Example**: `examples/ex_024_alloc_page_virtual_slab_cli.aipl`
- **Behavioral Summary**: Release `h1`, bump `generations[h1.index]`, acquire `h2` at same slot, and assert `poolIsHandleValid(pool, generations, h1) == false` and `poolIsHandleValid(pool, generations, h2) == true`. Concrete nominal inputs: `pool: Pool = Pool()`, `generations: [int] = [1]`, `handle: PoolHandle = PoolHandle(index = 0, generation = 1)`; exercises core body path returning/computing `ok`.

```aipl
module tests.functions.alloc.pool_alloc_z20_test
import * from "std/alloc/pool_alloc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_pool_alloc_poolReleaseHandle_20(): int:
  let arg_pool = poolNew(4)
  let edge_pool = poolNew(4)
  let arg_generations = [4]
  let edge_generations = []
  let arg_handle = PoolHandle(index = 0, generation = 4)
  let edge_handle = PoolHandle(index = 0, generation = 1)
  let resNom = poolReleaseHandle(arg_pool, arg_generations, arg_handle)
  let resEdge = poolReleaseHandle(edge_pool, edge_generations, edge_handle)
  assert(resNom == false, "poolReleaseHandle nominal resNom == false")
  assert(resEdge == false, "poolReleaseHandle boundary resEdge == false")
  ret 0
```

---

### `ringAllocNew` (`std/alloc/ring_alloc.aipl`)

- **Signature**: `pub fn ringAllocNew(capacity: int): RingBufferAllocator:`
- **Import**: `import * from "std/alloc/ring_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `capacity: int` | **Returns**: `RingBufferAllocator`
- **Unit Test**: `tests/functions/alloc/ring_alloc_test.aipl` | **Example**: `examples/ex_022_alloc_arena_bump_profiler_cli.aipl`
- **Behavioral Summary**: Create `RingBufferAllocator` with nominal capacity (`capacity = 4`) and verify `ringAvailable(resNom) == 4`.

```aipl
module tests.functions.alloc.ring_alloc_z1_test
import * from "std/alloc/ring_alloc"
import { ptrAlloc, ptrFree, ptrMemset } from "std/rt/rt_ptr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ring_alloc_ringAllocNew_1(): int:
  let arg_capacity = 4
  let edge_capacity = 1
  let resNom = ringAllocNew(arg_capacity)
  let resEdge = ringAllocNew(edge_capacity)
  assertEqInt(resNom.capacity, 4, "ringAllocNew nominal resNom.capacity == 4")
  assertEqInt(resEdge.capacity, 1, "ringAllocNew boundary resEdge.capacity == 1")
  ret 0
```

---

### `ringAvailable` (`std/alloc/ring_alloc.aipl`)

- **Signature**: `pub fn ringAvailable(ring: RingBufferAllocator): int:`
- **Import**: `import * from "std/alloc/ring_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ring: RingBufferAllocator` | **Returns**: `int`
- **Unit Test**: `tests/functions/alloc/ring_alloc_test.aipl` | **Example**: `examples/ex_023_alloc_pool_fixed_block_cli.aipl`
- **Behavioral Summary**: Verify available bytes decrease by exact allocation size and recover upon `ringFreeOldest`. Concrete nominal inputs: `ring: RingBufferAllocator = ringAllocNew(64)`; exercises core body path returning/computing `if rem > 0: rem else: 0`.

```aipl
module tests.functions.alloc.ring_alloc_z2_test
import * from "std/alloc/ring_alloc"
import { ptrAlloc, ptrFree, ptrMemset } from "std/rt/rt_ptr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ring_alloc_ringAvailable_2(): int:
  let arg_ring = ringAllocNew(64)
  let edge_ring = ringAllocNew(64)
  let resNom = ringAvailable(arg_ring)
  let resEdge = ringAvailable(edge_ring)
  assertEqInt(resNom, 64, "ringAvailable nominal resNom == 64")
  assertEqInt(resEdge, 64, "ringAvailable boundary resEdge == 64")
  ret 0
```

---

### `ringAlloc` (`std/alloc/ring_alloc.aipl`)

- **Signature**: `pub fn ringAlloc(mut ring: RingBufferAllocator, bytes: int): int:`
- **Import**: `import * from "std/alloc/ring_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut ring: RingBufferAllocator, bytes: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/alloc/ring_alloc_test.aipl` | **Example**: `examples/ex_024_alloc_page_virtual_slab_cli.aipl`
- **Behavioral Summary**: Allocate `100` and `100` bytes (`available == 56`), and verify a third `100`-byte allocation returns `-1` (full) until oldest block is freed. Concrete nominal inputs: `ring: RingBufferAllocator = ringAllocNew(64)`, `bytes: int = 64`; exercises core body path returning/computing `addr`.

```aipl
module tests.functions.alloc.ring_alloc_z3_test
import * from "std/alloc/ring_alloc"
import { ptrAlloc, ptrFree, ptrMemset } from "std/rt/rt_ptr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ring_alloc_ringAlloc_3(): int:
  let arg_ring = ringAllocNew(64)
  let edge_ring = ringAllocNew(64)
  let arg_bytes = 4
  let edge_bytes = 1
  let resNom = ringAlloc(arg_ring, arg_bytes)
  let resEdge = ringAlloc(edge_ring, edge_bytes)
  assert(resNom > 0, "ringAlloc nominal resNom > 0")
  assert(resEdge > 0, "ringAlloc boundary resEdge > 0")
  ret 0
```

---

### `ringFreeOldest` (`std/alloc/ring_alloc.aipl`)

- **Signature**: `pub fn ringFreeOldest(mut ring: RingBufferAllocator, bytes: int): void:`
- **Import**: `import * from "std/alloc/ring_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut ring: RingBufferAllocator, bytes: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/alloc/ring_alloc_test.aipl` | **Example**: `examples/ex_022_alloc_arena_bump_profiler_cli.aipl`
- **Behavioral Summary**: Free oldest `100`-byte block, then allocate a new `80`-byte block that wraps around the circular buffer boundary! Concrete nominal inputs: `ring: RingBufferAllocator = ringAllocNew(64)`, `bytes: int = 64`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.alloc.ring_alloc_z4_test
import * from "std/alloc/ring_alloc"
import { ptrAlloc, ptrFree, ptrMemset } from "std/rt/rt_ptr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ring_alloc_ringFreeOldest_4(): int:
  let arg_ring = ringAllocNew(64)
  let edge_ring = ringAllocNew(64)
  let arg_bytes = 4
  let edge_bytes = 1
  ringFreeOldest(arg_ring, arg_bytes)
  ringFreeOldest(edge_ring, edge_bytes)
  assertEqInt(arg_ring.usedBytes, 0, "ringFreeOldest nominal arg_ring.usedBytes == 0")
  assertEqInt(edge_ring.usedBytes, 0, "ringFreeOldest boundary edge_ring.usedBytes == 0")
  ret 0
```

---

### `ringReset` (`std/alloc/ring_alloc.aipl`)

- **Signature**: `pub fn ringReset(mut ring: RingBufferAllocator): void:`
- **Import**: `import * from "std/alloc/ring_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut ring: RingBufferAllocator` | **Returns**: `void`
- **Unit Test**: `tests/functions/alloc/ring_alloc_test.aipl` | **Example**: `examples/ex_023_alloc_pool_fixed_block_cli.aipl`
- **Behavioral Summary**: Reset head/tail pointers and assert `ringAvailable(ring) == 256`. Concrete nominal inputs: `ring: RingBufferAllocator = ringAllocNew(64)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.alloc.ring_alloc_z5_test
import * from "std/alloc/ring_alloc"
import { ptrAlloc, ptrFree, ptrMemset } from "std/rt/rt_ptr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ring_alloc_ringReset_5(): int:
  let arg_ring = ringAllocNew(64)
  let edge_ring = ringAllocNew(64)
  ringReset(arg_ring)
  ringReset(edge_ring)
  assertEqInt(arg_ring.usedBytes, 0, "ringReset nominal arg_ring.usedBytes == 0")
  assertEqInt(edge_ring.usedBytes, 0, "ringReset boundary edge_ring.usedBytes == 0")
  ret 0
```

---

### `ringDestroy` (`std/alloc/ring_alloc.aipl`)

- **Signature**: `pub fn ringDestroy(mut ring: RingBufferAllocator): void:`
- **Import**: `import * from "std/alloc/ring_alloc"` (or barrel `import * from "std/alloc/alloc_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut ring: RingBufferAllocator` | **Returns**: `void`
- **Unit Test**: `tests/functions/alloc/ring_alloc_test.aipl` | **Example**: `examples/ex_024_alloc_page_virtual_slab_cli.aipl`
- **Behavioral Summary**: Destroy ring buffer and verify `capacity == 0` and `ringAvailable(ring) == 0`. Concrete nominal inputs: `ring: RingBufferAllocator = ringAllocNew(64)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.alloc.ring_alloc_z6_test
import * from "std/alloc/ring_alloc"
import { ptrAlloc, ptrFree, ptrMemset } from "std/rt/rt_ptr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ring_alloc_ringDestroy_6(): int:
  let arg_ring = ringAllocNew(64)
  let edge_ring = ringAllocNew(64)
  ringDestroy(arg_ring)
  ringDestroy(edge_ring)
  assertEqInt(arg_ring.capacity, 0, "ringDestroy nominal arg_ring.capacity == 0")
  assertEqInt(edge_ring.capacity, 0, "ringDestroy boundary edge_ring.capacity == 0")
  ret 0
```
