[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 17: `sync` API Reference

> Complete API reference manual for AIPL standard library domain `sync` (74 callable functions & methods across ["std/sync/atomic.aipl", "std/sync/barrier.aipl", "std/sync/channel.aipl", "std/sync/mutex.aipl", "std/sync/rwlock.aipl", "std/sync/sync_mod.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `sync`
- **Target Source Modules**: ["std/sync/atomic.aipl", "std/sync/barrier.aipl", "std/sync/channel.aipl", "std/sync/mutex.aipl", "std/sync/rwlock.aipl", "std/sync/sync_mod.aipl"]
- **Total Callable Functions & Methods**: 74
- **Total Data Types (`struct` & `enum`)**: 20
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(20 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `MemoryOrder` | `pub struct` | `std/sync/atomic.aipl` | `order: int` | `MemoryOrder(order)` |
| `AtomicBool` | `pub struct` | `std/sync/atomic.aipl` | `mut val: bool` | `AtomicBool(mut val)` |
| `AtomicInt64` | `pub struct` | `std/sync/atomic.aipl` | `mut val: int` | `AtomicInt64(mut val)` |
| `AtomicUsize` | `pub struct` | `std/sync/atomic.aipl` | `mut val: int` | `AtomicUsize(mut val)` |
| `ThreadBarrier` | `pub struct` | `std/sync/barrier.aipl` | `threshold: int`, `mut count: int`, `mut generation: int` | `ThreadBarrier(threshold, mut count, mut generation)` |
| `WaitGroup` | `pub struct` | `std/sync/barrier.aipl` | `mut counter: int` | `WaitGroup(mut counter)` |
| `CountDownLatch` | `pub struct` | `std/sync/barrier.aipl` | `mut remaining: int` | `CountDownLatch(mut remaining)` |
| `OnceInit` | `pub struct` | `std/sync/barrier.aipl` | `mut state: int` | `OnceInit(mut state)` |
| `ChannelError` | `pub struct` | `std/sync/channel.aipl` | `kind: int`, `message: str` | `ChannelError(kind, message)` |
| `MpscChannel` | `pub struct` | `std/sync/channel.aipl` | `capacity: int`, `mut buffer: [int]`, `mut head: int`, `mut tail: int`, `mut count: int`, `mut closed: bool` | `MpscChannel(capacity, mut buffer, mut head, mut tail, mut count, mut closed)` |
| `SpscRingChannel` | `pub struct` | `std/sync/channel.aipl` | `capacity: int`, `mut buffer: [int]`, `mut readPos: int`, `mut writePos: int`, `mut closed: bool` | `SpscRingChannel(capacity, mut buffer, mut readPos, mut writePos, mut closed)` |
| `BroadcastChannel` | `pub struct` | `std/sync/channel.aipl` | `capacity: int`, `mut messages: [int]`, `mut subscriberPositions: [int]`, `mut closed: bool` | `BroadcastChannel(capacity, mut messages, mut subscriberPositions, mut closed)` |
| `Mutex` | `pub struct` | `std/sync/mutex.aipl` | `mut locked: bool`, `mut ownerThreadId: int` | `Mutex(mut locked, mut ownerThreadId)` |
| `MutexGuard` | `pub struct` | `std/sync/mutex.aipl` | `mutexRef: Mutex` | `MutexGuard(mutexRef)` |
| `SpinLock` | `pub struct` | `std/sync/mutex.aipl` | `mut flag: int` | `SpinLock(mut flag)` |
| `CondVar` | `pub struct` | `std/sync/mutex.aipl` | `mut waitingCount: int`, `mut signaledCount: int = 0` | `CondVar(mut waitingCount, mut signaledCount)` |
| `RwLock` | `pub struct` | `std/sync/rwlock.aipl` | `mut readers: int`, `mut writer: bool` | `RwLock(mut readers, mut writer)` |
| `RwLockReadGuard` | `pub struct` | `std/sync/rwlock.aipl` | `rwlockRef: RwLock` | `RwLockReadGuard(rwlockRef)` |
| `RwLockWriteGuard` | `pub struct` | `std/sync/rwlock.aipl` | `rwlockRef: RwLock` | `RwLockWriteGuard(rwlockRef)` |
| `SeqLock` | `pub struct` | `std/sync/rwlock.aipl` | `mut sequence: int` | `SeqLock(mut sequence)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/sync/atomic.aipl` | `atomicBoolNew` | `pub fn atomicBoolNew(initial: bool): AtomicBool:` | `tests/functions/sync/atomic_test.aipl` |
| `2` | `std/sync/atomic.aipl` | `atomicBoolLoad` | `pub fn atomicBoolLoad(a: AtomicBool, order: int): bool:` | `tests/functions/sync/atomic_test.aipl` |
| `3` | `std/sync/atomic.aipl` | `atomicBoolStore` | `pub fn atomicBoolStore(mut a: AtomicBool, val: bool, order: int): void:` | `tests/functions/sync/atomic_test.aipl` |
| `4` | `std/sync/atomic.aipl` | `atomicBoolSwap` | `pub fn atomicBoolSwap(mut a: AtomicBool, val: bool, order: int): bool:` | `tests/functions/sync/atomic_test.aipl` |
| `5` | `std/sync/atomic.aipl` | `atomicBoolCompareAndSwap` | `pub fn atomicBoolCompareAndSwap(mut a: AtomicBool, expected: bool, desired: bool, order: int): bool:` | `tests/functions/sync/atomic_test.aipl` |
| `6` | `std/sync/atomic.aipl` | `atomicIntNew` | `pub fn atomicIntNew(initial: int): AtomicInt64:` | `tests/functions/sync/atomic_test.aipl` |
| `7` | `std/sync/atomic.aipl` | `atomicIntLoad` | `pub fn atomicIntLoad(a: AtomicInt64, order: int): int:` | `tests/functions/sync/atomic_test.aipl` |
| `8` | `std/sync/atomic.aipl` | `atomicIntStore` | `pub fn atomicIntStore(mut a: AtomicInt64, val: int, order: int): void:` | `tests/functions/sync/atomic_test.aipl` |
| `9` | `std/sync/atomic.aipl` | `atomicIntSwap` | `pub fn atomicIntSwap(mut a: AtomicInt64, val: int, order: int): int:` | `tests/functions/sync/atomic_test.aipl` |
| `10` | `std/sync/atomic.aipl` | `atomicIntCompareAndSwap` | `pub fn atomicIntCompareAndSwap(mut a: AtomicInt64, expected: int, desired: int, order: int): bool:` | `tests/functions/sync/atomic_test.aipl` |
| `11` | `std/sync/atomic.aipl` | `atomicIntFetchAdd` | `pub fn atomicIntFetchAdd(mut a: AtomicInt64, delta: int, order: int): int:` | `tests/functions/sync/atomic_test.aipl` |
| `12` | `std/sync/atomic.aipl` | `atomicIntFetchSub` | `pub fn atomicIntFetchSub(mut a: AtomicInt64, delta: int, order: int): int:` | `tests/functions/sync/atomic_test.aipl` |
| `13` | `std/sync/atomic.aipl` | `atomicIntFetchAnd` | `pub fn atomicIntFetchAnd(mut a: AtomicInt64, mask: int, order: int): int:` | `tests/functions/sync/atomic_test.aipl` |
| `14` | `std/sync/atomic.aipl` | `atomicIntFetchOr` | `pub fn atomicIntFetchOr(mut a: AtomicInt64, mask: int, order: int): int:` | `tests/functions/sync/atomic_test.aipl` |
| `15` | `std/sync/atomic.aipl` | `atomicUsizeNew` | `pub fn atomicUsizeNew(initial: int): AtomicUsize:` | `tests/functions/sync/atomic_test.aipl` |
| `16` | `std/sync/atomic.aipl` | `atomicUsizeLoad` | `pub fn atomicUsizeLoad(a: AtomicUsize, order: int): int:` | `tests/functions/sync/atomic_test.aipl` |
| `17` | `std/sync/atomic.aipl` | `atomicUsizeStore` | `pub fn atomicUsizeStore(mut a: AtomicUsize, val: int, order: int): void:` | `tests/functions/sync/atomic_test.aipl` |
| `18` | `std/sync/atomic.aipl` | `atomicUsizeFetchAdd` | `pub fn atomicUsizeFetchAdd(mut a: AtomicUsize, delta: int, order: int): int:` | `tests/functions/sync/atomic_test.aipl` |
| `19` | `std/sync/atomic.aipl` | `atomicMemoryFence` | `pub fn atomicMemoryFence(order: int): int:` | `tests/functions/sync/atomic_test.aipl` |
| `20` | `std/sync/barrier.aipl` | `threadBarrierNew` | `pub fn threadBarrierNew(threshold: int): ThreadBarrier:` | `tests/functions/sync/barrier_test.aipl` |
| `21` | `std/sync/barrier.aipl` | `threadBarrierWait` | `pub fn threadBarrierWait(mut b: ThreadBarrier): bool:` | `tests/functions/sync/barrier_test.aipl` |
| `22` | `std/sync/barrier.aipl` | `waitGroupNew` | `pub fn waitGroupNew(): WaitGroup:` | `tests/functions/sync/barrier_test.aipl` |
| `23` | `std/sync/barrier.aipl` | `waitGroupAdd` | `pub fn waitGroupAdd(mut wg: WaitGroup, delta: int): void:` | `tests/functions/sync/barrier_test.aipl` |
| `24` | `std/sync/barrier.aipl` | `waitGroupDone` | `pub fn waitGroupDone(mut wg: WaitGroup): void:` | `tests/functions/sync/barrier_test.aipl` |
| `25` | `std/sync/barrier.aipl` | `waitGroupWait` | `pub fn waitGroupWait(wg: WaitGroup): bool:` | `tests/functions/sync/barrier_test.aipl` |
| `26` | `std/sync/barrier.aipl` | `countDownLatchNew` | `pub fn countDownLatchNew(count: int): CountDownLatch:` | `tests/functions/sync/barrier_test.aipl` |
| `27` | `std/sync/barrier.aipl` | `countDownLatchCountDown` | `pub fn countDownLatchCountDown(mut cdl: CountDownLatch): void:` | `tests/functions/sync/barrier_test.aipl` |
| `28` | `std/sync/barrier.aipl` | `countDownLatchWait` | `pub fn countDownLatchWait(cdl: CountDownLatch): bool:` | `tests/functions/sync/barrier_test.aipl` |
| `29` | `std/sync/barrier.aipl` | `countDownLatchGetCount` | `pub fn countDownLatchGetCount(cdl: CountDownLatch): int:` | `tests/functions/sync/barrier_test.aipl` |
| `30` | `std/sync/barrier.aipl` | `onceInitNew` | `pub fn onceInitNew(): OnceInit:` | `tests/functions/sync/barrier_test.aipl` |
| `31` | `std/sync/barrier.aipl` | `onceInitDo` | `pub fn onceInitDo(mut oi: OnceInit): bool:` | `tests/functions/sync/barrier_test.aipl` |
| `32` | `std/sync/barrier.aipl` | `onceInitIsDone` | `pub fn onceInitIsDone(oi: OnceInit): bool:` | `tests/functions/sync/barrier_test.aipl` |
| `33` | `std/sync/channel.aipl` | `mpscChannelNew` | `pub fn mpscChannelNew(capacity: int): MpscChannel:` | `tests/functions/sync/channel_test.aipl` |
| `34` | `std/sync/channel.aipl` | `mpscTrySend` | `pub fn mpscTrySend(mut ch: MpscChannel, val: int): Result[bool, ChannelError]:` | `tests/functions/sync/channel_test.aipl` |
| `35` | `std/sync/channel.aipl` | `mpscSend` | `pub fn mpscSend(mut ch: MpscChannel, val: int): Result[bool, ChannelError]:` | `tests/functions/sync/channel_test.aipl` |
| `36` | `std/sync/channel.aipl` | `mpscTryRecv` | `pub fn mpscTryRecv(mut ch: MpscChannel): Result[int, ChannelError]:` | `tests/functions/sync/channel_test.aipl` |
| `37` | `std/sync/channel.aipl` | `mpscRecv` | `pub fn mpscRecv(mut ch: MpscChannel): Result[int, ChannelError]:` | `tests/functions/sync/channel_test.aipl` |
| `38` | `std/sync/channel.aipl` | `mpscClose` | `pub fn mpscClose(mut ch: MpscChannel): bool:` | `tests/functions/sync/channel_test.aipl` |
| `39` | `std/sync/channel.aipl` | `mpscIsClosed` | `pub fn mpscIsClosed(ch: MpscChannel): bool:` | `tests/functions/sync/channel_test.aipl` |
| `40` | `std/sync/channel.aipl` | `mpscLen` | `pub fn mpscLen(ch: MpscChannel): int:` | `tests/functions/sync/channel_test.aipl` |
| `41` | `std/sync/channel.aipl` | `mpscCapacity` | `pub fn mpscCapacity(ch: MpscChannel): int:` | `tests/functions/sync/channel_test.aipl` |
| `42` | `std/sync/channel.aipl` | `spscChannelNew` | `pub fn spscChannelNew(capacity: int): SpscRingChannel:` | `tests/functions/sync/channel_test.aipl` |
| `43` | `std/sync/channel.aipl` | `spscTrySend` | `pub fn spscTrySend(mut ch: SpscRingChannel, val: int): Result[bool, ChannelError]:` | `tests/functions/sync/channel_test.aipl` |
| `44` | `std/sync/channel.aipl` | `spscSend` | `pub fn spscSend(mut ch: SpscRingChannel, val: int): Result[bool, ChannelError]:` | `tests/functions/sync/channel_test.aipl` |
| `45` | `std/sync/channel.aipl` | `spscTryRecv` | `pub fn spscTryRecv(mut ch: SpscRingChannel): Result[int, ChannelError]:` | `tests/functions/sync/channel_test.aipl` |
| `46` | `std/sync/channel.aipl` | `spscRecv` | `pub fn spscRecv(mut ch: SpscRingChannel): Result[int, ChannelError]:` | `tests/functions/sync/channel_test.aipl` |
| `47` | `std/sync/channel.aipl` | `broadcastChannelNew` | `pub fn broadcastChannelNew(capacity: int): BroadcastChannel:` | `tests/functions/sync/channel_test.aipl` |
| `48` | `std/sync/channel.aipl` | `broadcastSubscribe` | `pub fn broadcastSubscribe(mut ch: BroadcastChannel): int:` | `tests/functions/sync/channel_test.aipl` |
| `49` | `std/sync/channel.aipl` | `broadcastSend` | `pub fn broadcastSend(mut ch: BroadcastChannel, val: int): Result[int, ChannelError]:` | `tests/functions/sync/channel_test.aipl` |
| `50` | `std/sync/channel.aipl` | `broadcastRecv` | `pub fn broadcastRecv(mut ch: BroadcastChannel, subscriberId: int): Result[int, ChannelError]:` | `tests/functions/sync/channel_test.aipl` |
| `51` | `std/sync/mutex.aipl` | `mutexNew` | `pub fn mutexNew(): Mutex:` | `tests/functions/sync/mutex_test.aipl` |
| `52` | `std/sync/mutex.aipl` | `mutexLock` | `pub fn mutexLock(mut m: Mutex): MutexGuard:` | `tests/functions/sync/mutex_test.aipl` |
| `53` | `std/sync/mutex.aipl` | `mutexTryLock` | `pub fn mutexTryLock(mut m: Mutex): Option[MutexGuard]:` | `tests/functions/sync/mutex_test.aipl` |
| `54` | `std/sync/mutex.aipl` | `mutexUnlock` | `pub fn mutexUnlock(mut m: Mutex): bool:` | `tests/functions/sync/mutex_test.aipl` |
| `55` | `std/sync/mutex.aipl` | `spinLockNew` | `pub fn spinLockNew(): SpinLock:` | `tests/functions/sync/mutex_test.aipl` |
| `56` | `std/sync/mutex.aipl` | `spinLockAcquire` | `pub fn spinLockAcquire(mut sl: SpinLock): void:` | `tests/functions/sync/mutex_test.aipl` |
| `57` | `std/sync/mutex.aipl` | `spinLockRelease` | `pub fn spinLockRelease(mut sl: SpinLock): void:` | `tests/functions/sync/mutex_test.aipl` |
| `58` | `std/sync/mutex.aipl` | `condVarNew` | `pub fn condVarNew(): CondVar:` | `tests/functions/sync/mutex_test.aipl` |
| `59` | `std/sync/mutex.aipl` | `condVarWait` | `pub fn condVarWait(mut cv: CondVar, mut guard: MutexGuard): void:` | `tests/functions/sync/mutex_test.aipl` |
| `60` | `std/sync/mutex.aipl` | `condVarWaitTimeout` | `pub fn condVarWaitTimeout(mut cv: CondVar, mut guard: MutexGuard, timeoutMs: int): bool:` | `tests/functions/sync/mutex_test.aipl` |
| `61` | `std/sync/mutex.aipl` | `condVarSignal` | `pub fn condVarSignal(mut cv: CondVar): void:` | `tests/functions/sync/mutex_test.aipl` |
| `62` | `std/sync/mutex.aipl` | `condVarBroadcast` | `pub fn condVarBroadcast(mut cv: CondVar): void:` | `tests/functions/sync/mutex_test.aipl` |
| `63` | `std/sync/rwlock.aipl` | `rwLockNew` | `pub fn rwLockNew(): RwLock:` | `tests/functions/sync/rwlock_test.aipl` |
| `64` | `std/sync/rwlock.aipl` | `rwLockRead` | `pub fn rwLockRead(mut lock: RwLock): RwLockReadGuard:` | `tests/functions/sync/rwlock_test.aipl` |
| `65` | `std/sync/rwlock.aipl` | `rwLockTryRead` | `pub fn rwLockTryRead(mut lock: RwLock): Option[RwLockReadGuard]:` | `tests/functions/sync/rwlock_test.aipl` |
| `66` | `std/sync/rwlock.aipl` | `rwLockReadUnlock` | `pub fn rwLockReadUnlock(mut lock: RwLock): bool:` | `tests/functions/sync/rwlock_test.aipl` |
| `67` | `std/sync/rwlock.aipl` | `rwLockWrite` | `pub fn rwLockWrite(mut lock: RwLock): RwLockWriteGuard:` | `tests/functions/sync/rwlock_test.aipl` |
| `68` | `std/sync/rwlock.aipl` | `rwLockTryWrite` | `pub fn rwLockTryWrite(mut lock: RwLock): Option[RwLockWriteGuard]:` | `tests/functions/sync/rwlock_test.aipl` |
| `69` | `std/sync/rwlock.aipl` | `rwLockWriteUnlock` | `pub fn rwLockWriteUnlock(mut lock: RwLock): bool:` | `tests/functions/sync/rwlock_test.aipl` |
| `70` | `std/sync/rwlock.aipl` | `seqLockNew` | `pub fn seqLockNew(): SeqLock:` | `tests/functions/sync/rwlock_test.aipl` |
| `71` | `std/sync/rwlock.aipl` | `seqLockReadBegin` | `pub fn seqLockReadBegin(sl: SeqLock): int:` | `tests/functions/sync/rwlock_test.aipl` |
| `72` | `std/sync/rwlock.aipl` | `seqLockReadRetry` | `pub fn seqLockReadRetry(sl: SeqLock, initialSeq: int): bool:` | `tests/functions/sync/rwlock_test.aipl` |
| `73` | `std/sync/rwlock.aipl` | `seqLockWriteBegin` | `pub fn seqLockWriteBegin(mut sl: SeqLock): void:` | `tests/functions/sync/rwlock_test.aipl` |
| `74` | `std/sync/rwlock.aipl` | `seqLockWriteEnd` | `pub fn seqLockWriteEnd(mut sl: SeqLock): void:` | `tests/functions/sync/rwlock_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `atomicBoolNew` (`std/sync/atomic.aipl`)

- **Signature**: `pub fn atomicBoolNew(initial: bool): AtomicBool:`
- **Import**: `import * from "std/sync/atomic"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `initial: bool` | **Returns**: `AtomicBool`
- **Unit Test**: `tests/functions/sync/atomic_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `atomicBoolNew` lock-free atomic load/store/swap/CAS (`compareExchange` success vs failure) and fetch-modify return-previous-value semantics. Concrete nominal inputs: `initial: bool = true`; exercises core body path returning/computing `AtomicBool(val: initial)`.

```aipl
module tests.functions.sync.atomic_z1_test
import * from "std/sync/atomic"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atomic_atomicBoolNew_1(): int:
  let arg_initial = true
  let edge_initial = false
  let resNom = atomicBoolNew(arg_initial)
  let resEdge = atomicBoolNew(edge_initial)
  assert(resNom.val == true, "atomicBoolNew nominal resNom.val == true")
  assert(resEdge.val == false, "atomicBoolNew boundary resEdge.val == false")
  ret 0
```

---

### `atomicBoolLoad` (`std/sync/atomic.aipl`)

- **Signature**: `pub fn atomicBoolLoad(a: AtomicBool, order: int): bool:`
- **Import**: `import * from "std/sync/atomic"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: AtomicBool, order: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/sync/atomic_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `atomicBoolLoad` lock-free atomic load/store/swap/CAS (`compareExchange` success vs failure) and fetch-modify return-previous-value semantics. Concrete nominal inputs: `a: AtomicBool = AtomicBool()`, `order: int = 1`; exercises core body path returning/computing `a.val`.

```aipl
module tests.functions.sync.atomic_z2_test
import * from "std/sync/atomic"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atomic_atomicBoolLoad_2(): int:
  let arg_a = AtomicBool(val = true)
  let edge_a = AtomicBool(val = false)
  let arg_order = 2
  let edge_order = 0
  let resNom = atomicBoolLoad(arg_a, arg_order)
  let resEdge = atomicBoolLoad(edge_a, edge_order)
  assert(resNom == true, "atomicBoolLoad nominal resNom == true")
  assert(resEdge == false, "atomicBoolLoad boundary resEdge == false")
  ret 0
```

---

### `atomicBoolStore` (`std/sync/atomic.aipl`)

- **Signature**: `pub fn atomicBoolStore(mut a: AtomicBool, val: bool, order: int): void:`
- **Import**: `import * from "std/sync/atomic"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut a: AtomicBool, val: bool, order: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/sync/atomic_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `atomicBoolStore` lock-free atomic load/store/swap/CAS (`compareExchange` success vs failure) and fetch-modify return-previous-value semantics. Concrete nominal inputs: `a: AtomicBool = AtomicBool()`, `val: bool = true`, `order: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sync.atomic_z3_test
import * from "std/sync/atomic"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atomic_atomicBoolStore_3(): int:
  let arg_a = AtomicBool(val = true)
  let edge_a = AtomicBool(val = false)
  let arg_val = true
  let edge_val = false
  let arg_order = 2
  let edge_order = 0
  atomicBoolStore(arg_a, arg_val, arg_order)
  atomicBoolStore(edge_a, edge_val, edge_order)
  assert(arg_a.val == true, "atomicBoolStore nominal arg_a.val == true")
  assert(edge_a.val == false, "atomicBoolStore boundary edge_a.val == false")
  ret 0
```

---

### `atomicBoolSwap` (`std/sync/atomic.aipl`)

- **Signature**: `pub fn atomicBoolSwap(mut a: AtomicBool, val: bool, order: int): bool:`
- **Import**: `import * from "std/sync/atomic"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut a: AtomicBool, val: bool, order: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/sync/atomic_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `atomicBoolSwap` lock-free atomic load/store/swap/CAS (`compareExchange` success vs failure) and fetch-modify return-previous-value semantics. Concrete nominal inputs: `a: AtomicBool = AtomicBool()`, `val: bool = true`, `order: int = 1`; exercises core body path returning/computing `prev`.

```aipl
module tests.functions.sync.atomic_z4_test
import * from "std/sync/atomic"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atomic_atomicBoolSwap_4(): int:
  let arg_a = AtomicBool(val = true)
  let edge_a = AtomicBool(val = false)
  let arg_val = true
  let edge_val = false
  let arg_order = 2
  let edge_order = 0
  let resNom = atomicBoolSwap(arg_a, arg_val, arg_order)
  let resEdge = atomicBoolSwap(edge_a, edge_val, edge_order)
  assert(resNom == true, "atomicBoolSwap nominal resNom == true")
  assert(resEdge == false, "atomicBoolSwap boundary resEdge == false")
  ret 0
```

---

### `atomicBoolCompareAndSwap` (`std/sync/atomic.aipl`)

- **Signature**: `pub fn atomicBoolCompareAndSwap(mut a: AtomicBool, expected: bool, desired: bool, order: int): bool:`
- **Import**: `import * from "std/sync/atomic"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut a: AtomicBool, expected: bool, desired: bool, order: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/sync/atomic_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `atomicBoolCompareAndSwap` lock-free atomic load/store/swap/CAS (`compareExchange` success vs failure) and fetch-modify return-previous-value semantics. Concrete nominal inputs: `a: AtomicBool = AtomicBool()`, `expected: bool = true`, `desired: bool = true`, `order: int = 1`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.sync.atomic_z5_test
import * from "std/sync/atomic"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atomic_atomicBoolCompareAndSwap_5(): int:
  let arg_a = AtomicBool(val = true)
  let edge_a = AtomicBool(val = false)
  let arg_expected = true
  let edge_expected = false
  let arg_desired = true
  let edge_desired = false
  let arg_order = 2
  let edge_order = 0
  let resNom = atomicBoolCompareAndSwap(arg_a, arg_expected, arg_desired, arg_order)
  let resEdge = atomicBoolCompareAndSwap(edge_a, edge_expected, edge_desired, edge_order)
  assert(resNom == true, "atomicBoolCompareAndSwap nominal resNom == true")
  assert(resEdge == true, "atomicBoolCompareAndSwap boundary resEdge == true")
  ret 0
```

---

### `atomicIntNew` (`std/sync/atomic.aipl`)

- **Signature**: `pub fn atomicIntNew(initial: int): AtomicInt64:`
- **Import**: `import * from "std/sync/atomic"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `initial: int` | **Returns**: `AtomicInt64`
- **Unit Test**: `tests/functions/sync/atomic_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `atomicIntNew` lock-free atomic load/store/swap/CAS (`compareExchange` success vs failure) and fetch-modify return-previous-value semantics. Concrete nominal inputs: `initial: int = 1`; exercises core body path returning/computing `AtomicInt64(val: initial)`.

```aipl
module tests.functions.sync.atomic_z6_test
import * from "std/sync/atomic"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atomic_atomicIntNew_6(): int:
  let arg_initial = 4
  let edge_initial = 1
  let resNom = atomicIntNew(arg_initial)
  let resEdge = atomicIntNew(edge_initial)
  assertEqInt(resNom.val, 4, "atomicIntNew nominal resNom.val == 4")
  assertEqInt(resEdge.val, 1, "atomicIntNew boundary resEdge.val == 1")
  ret 0
```

---

### `atomicIntLoad` (`std/sync/atomic.aipl`)

- **Signature**: `pub fn atomicIntLoad(a: AtomicInt64, order: int): int:`
- **Import**: `import * from "std/sync/atomic"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: AtomicInt64, order: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sync/atomic_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `atomicIntLoad` lock-free atomic load/store/swap/CAS (`compareExchange` success vs failure) and fetch-modify return-previous-value semantics. Concrete nominal inputs: `a: AtomicInt64 = AtomicInt64()`, `order: int = 1`; exercises core body path returning/computing `a.val`.

```aipl
module tests.functions.sync.atomic_z7_test
import * from "std/sync/atomic"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atomic_atomicIntLoad_7(): int:
  let arg_a = AtomicInt64(val = 2)
  let edge_a = AtomicInt64(val = 0)
  let arg_order = 2
  let edge_order = 0
  let resNom = atomicIntLoad(arg_a, arg_order)
  let resEdge = atomicIntLoad(edge_a, edge_order)
  assertEqInt(resNom, 2, "atomicIntLoad nominal resNom == 2")
  assertEqInt(resEdge, 0, "atomicIntLoad boundary resEdge == 0")
  ret 0
```

---

### `atomicIntStore` (`std/sync/atomic.aipl`)

- **Signature**: `pub fn atomicIntStore(mut a: AtomicInt64, val: int, order: int): void:`
- **Import**: `import * from "std/sync/atomic"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut a: AtomicInt64, val: int, order: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/sync/atomic_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `atomicIntStore` lock-free atomic load/store/swap/CAS (`compareExchange` success vs failure) and fetch-modify return-previous-value semantics. Concrete nominal inputs: `a: AtomicInt64 = AtomicInt64()`, `val: int = 1`, `order: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sync.atomic_z8_test
import * from "std/sync/atomic"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atomic_atomicIntStore_8(): int:
  let arg_a = AtomicInt64(val = 2)
  let edge_a = AtomicInt64(val = 0)
  let arg_val = 2
  let edge_val = 0
  let arg_order = 2
  let edge_order = 0
  atomicIntStore(arg_a, arg_val, arg_order)
  atomicIntStore(edge_a, edge_val, edge_order)
  assertEqInt(arg_a.val, 2, "atomicIntStore nominal arg_a.val == 2")
  assertEqInt(edge_a.val, 0, "atomicIntStore boundary edge_a.val == 0")
  ret 0
```

---

### `atomicIntSwap` (`std/sync/atomic.aipl`)

- **Signature**: `pub fn atomicIntSwap(mut a: AtomicInt64, val: int, order: int): int:`
- **Import**: `import * from "std/sync/atomic"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut a: AtomicInt64, val: int, order: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sync/atomic_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `atomicIntSwap` lock-free atomic load/store/swap/CAS (`compareExchange` success vs failure) and fetch-modify return-previous-value semantics. Concrete nominal inputs: `a: AtomicInt64 = AtomicInt64()`, `val: int = 1`, `order: int = 1`; exercises core body path returning/computing `prev`.

```aipl
module tests.functions.sync.atomic_z9_test
import * from "std/sync/atomic"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atomic_atomicIntSwap_9(): int:
  let arg_a = AtomicInt64(val = 2)
  let edge_a = AtomicInt64(val = 0)
  let arg_val = 2
  let edge_val = 0
  let arg_order = 2
  let edge_order = 0
  let resNom = atomicIntSwap(arg_a, arg_val, arg_order)
  let resEdge = atomicIntSwap(edge_a, edge_val, edge_order)
  assertEqInt(resNom, 2, "atomicIntSwap nominal resNom == 2")
  assertEqInt(resEdge, 0, "atomicIntSwap boundary resEdge == 0")
  ret 0
```

---

### `atomicIntCompareAndSwap` (`std/sync/atomic.aipl`)

- **Signature**: `pub fn atomicIntCompareAndSwap(mut a: AtomicInt64, expected: int, desired: int, order: int): bool:`
- **Import**: `import * from "std/sync/atomic"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut a: AtomicInt64, expected: int, desired: int, order: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/sync/atomic_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `atomicIntCompareAndSwap` lock-free atomic load/store/swap/CAS (`compareExchange` success vs failure) and fetch-modify return-previous-value semantics. Concrete nominal inputs: `a: AtomicInt64 = AtomicInt64()`, `expected: int = 1`, `desired: int = 1`, `order: int = 1`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.sync.atomic_z10_test
import * from "std/sync/atomic"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atomic_atomicIntCompareAndSwap_10(): int:
  let arg_a = AtomicInt64(val = 2)
  let edge_a = AtomicInt64(val = 0)
  let arg_expected = 1
  let edge_expected = 0
  let arg_desired = 2
  let edge_desired = 0
  let arg_order = 2
  let edge_order = 0
  let resNom = atomicIntCompareAndSwap(arg_a, arg_expected, arg_desired, arg_order)
  let resEdge = atomicIntCompareAndSwap(edge_a, edge_expected, edge_desired, edge_order)
  assert(resNom == false, "atomicIntCompareAndSwap nominal resNom == false")
  assert(resEdge == true, "atomicIntCompareAndSwap boundary resEdge == true")
  ret 0
```

---

### `atomicIntFetchAdd` (`std/sync/atomic.aipl`)

- **Signature**: `pub fn atomicIntFetchAdd(mut a: AtomicInt64, delta: int, order: int): int:`
- **Import**: `import * from "std/sync/atomic"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut a: AtomicInt64, delta: int, order: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sync/atomic_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `atomicIntFetchAdd` lock-free atomic load/store/swap/CAS (`compareExchange` success vs failure) and fetch-modify return-previous-value semantics. Concrete nominal inputs: `a: AtomicInt64 = AtomicInt64()`, `delta: int = 1`, `order: int = 1`; exercises core body path returning/computing `prev`.

```aipl
module tests.functions.sync.atomic_z11_test
import * from "std/sync/atomic"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atomic_atomicIntFetchAdd_11(): int:
  let arg_a = AtomicInt64(val = 2)
  let edge_a = AtomicInt64(val = 0)
  let arg_delta = 2
  let edge_delta = 0
  let arg_order = 2
  let edge_order = 0
  let resNom = atomicIntFetchAdd(arg_a, arg_delta, arg_order)
  let resEdge = atomicIntFetchAdd(edge_a, edge_delta, edge_order)
  assertEqInt(resNom, 2, "atomicIntFetchAdd nominal resNom == 2")
  assertEqInt(resEdge, 0, "atomicIntFetchAdd boundary resEdge == 0")
  ret 0
```

---

### `atomicIntFetchSub` (`std/sync/atomic.aipl`)

- **Signature**: `pub fn atomicIntFetchSub(mut a: AtomicInt64, delta: int, order: int): int:`
- **Import**: `import * from "std/sync/atomic"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut a: AtomicInt64, delta: int, order: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sync/atomic_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `atomicIntFetchSub` lock-free atomic load/store/swap/CAS (`compareExchange` success vs failure) and fetch-modify return-previous-value semantics. Concrete nominal inputs: `a: AtomicInt64 = AtomicInt64()`, `delta: int = 1`, `order: int = 1`; exercises core body path returning/computing `prev`.

```aipl
module tests.functions.sync.atomic_z12_test
import * from "std/sync/atomic"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atomic_atomicIntFetchSub_12(): int:
  let arg_a = AtomicInt64(val = 2)
  let edge_a = AtomicInt64(val = 0)
  let arg_delta = 2
  let edge_delta = 0
  let arg_order = 2
  let edge_order = 0
  let resNom = atomicIntFetchSub(arg_a, arg_delta, arg_order)
  let resEdge = atomicIntFetchSub(edge_a, edge_delta, edge_order)
  assertEqInt(resNom, 2, "atomicIntFetchSub nominal resNom == 2")
  assertEqInt(resEdge, 0, "atomicIntFetchSub boundary resEdge == 0")
  ret 0
```

---

### `atomicIntFetchAnd` (`std/sync/atomic.aipl`)

- **Signature**: `pub fn atomicIntFetchAnd(mut a: AtomicInt64, mask: int, order: int): int:`
- **Import**: `import * from "std/sync/atomic"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut a: AtomicInt64, mask: int, order: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sync/atomic_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `atomicIntFetchAnd` lock-free atomic load/store/swap/CAS (`compareExchange` success vs failure) and fetch-modify return-previous-value semantics. Concrete nominal inputs: `a: AtomicInt64 = AtomicInt64()`, `mask: int = 1`, `order: int = 1`; exercises core body path returning/computing `prev`.

```aipl
module tests.functions.sync.atomic_z13_test
import * from "std/sync/atomic"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atomic_atomicIntFetchAnd_13(): int:
  let arg_a = AtomicInt64(val = 2)
  let edge_a = AtomicInt64(val = 0)
  let arg_mask = 4
  let edge_mask = 1
  let arg_order = 2
  let edge_order = 0
  let resNom = atomicIntFetchAnd(arg_a, arg_mask, arg_order)
  let resEdge = atomicIntFetchAnd(edge_a, edge_mask, edge_order)
  assertEqInt(resNom, 2, "atomicIntFetchAnd nominal resNom == 2")
  assertEqInt(resEdge, 0, "atomicIntFetchAnd boundary resEdge == 0")
  ret 0
```

---

### `atomicIntFetchOr` (`std/sync/atomic.aipl`)

- **Signature**: `pub fn atomicIntFetchOr(mut a: AtomicInt64, mask: int, order: int): int:`
- **Import**: `import * from "std/sync/atomic"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut a: AtomicInt64, mask: int, order: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sync/atomic_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `atomicIntFetchOr` lock-free atomic load/store/swap/CAS (`compareExchange` success vs failure) and fetch-modify return-previous-value semantics. Concrete nominal inputs: `a: AtomicInt64 = AtomicInt64()`, `mask: int = 1`, `order: int = 1`; exercises core body path returning/computing `prev`.

```aipl
module tests.functions.sync.atomic_z14_test
import * from "std/sync/atomic"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atomic_atomicIntFetchOr_14(): int:
  let arg_a = AtomicInt64(val = 2)
  let edge_a = AtomicInt64(val = 0)
  let arg_mask = 4
  let edge_mask = 1
  let arg_order = 2
  let edge_order = 0
  let resNom = atomicIntFetchOr(arg_a, arg_mask, arg_order)
  let resEdge = atomicIntFetchOr(edge_a, edge_mask, edge_order)
  assertEqInt(resNom, 2, "atomicIntFetchOr nominal resNom == 2")
  assertEqInt(resEdge, 0, "atomicIntFetchOr boundary resEdge == 0")
  ret 0
```

---

### `atomicUsizeNew` (`std/sync/atomic.aipl`)

- **Signature**: `pub fn atomicUsizeNew(initial: int): AtomicUsize:`
- **Import**: `import * from "std/sync/atomic"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `initial: int` | **Returns**: `AtomicUsize`
- **Unit Test**: `tests/functions/sync/atomic_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `atomicUsizeNew` lock-free atomic load/store/swap/CAS (`compareExchange` success vs failure) and fetch-modify return-previous-value semantics. Concrete nominal inputs: `initial: int = 1`; exercises core body path returning/computing `AtomicUsize(val: v)`.

```aipl
module tests.functions.sync.atomic_z15_test
import * from "std/sync/atomic"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atomic_atomicUsizeNew_15(): int:
  let arg_initial = 4
  let edge_initial = 1
  let resNom = atomicUsizeNew(arg_initial)
  let resEdge = atomicUsizeNew(edge_initial)
  assertEqInt(resNom.val, 4, "atomicUsizeNew nominal resNom.val == 4")
  assertEqInt(resEdge.val, 1, "atomicUsizeNew boundary resEdge.val == 1")
  ret 0
```

---

### `atomicUsizeLoad` (`std/sync/atomic.aipl`)

- **Signature**: `pub fn atomicUsizeLoad(a: AtomicUsize, order: int): int:`
- **Import**: `import * from "std/sync/atomic"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: AtomicUsize, order: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sync/atomic_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `atomicUsizeLoad` lock-free atomic load/store/swap/CAS (`compareExchange` success vs failure) and fetch-modify return-previous-value semantics. Concrete nominal inputs: `a: AtomicUsize = AtomicUsize()`, `order: int = 1`; exercises core body path returning/computing `a.val`.

```aipl
module tests.functions.sync.atomic_z16_test
import * from "std/sync/atomic"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atomic_atomicUsizeLoad_16(): int:
  let arg_a = AtomicUsize(val = 2)
  let edge_a = AtomicUsize(val = 0)
  let arg_order = 2
  let edge_order = 0
  let resNom = atomicUsizeLoad(arg_a, arg_order)
  let resEdge = atomicUsizeLoad(edge_a, edge_order)
  assertEqInt(resNom, 2, "atomicUsizeLoad nominal resNom == 2")
  assertEqInt(resEdge, 0, "atomicUsizeLoad boundary resEdge == 0")
  ret 0
```

---

### `atomicUsizeStore` (`std/sync/atomic.aipl`)

- **Signature**: `pub fn atomicUsizeStore(mut a: AtomicUsize, val: int, order: int): void:`
- **Import**: `import * from "std/sync/atomic"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut a: AtomicUsize, val: int, order: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/sync/atomic_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `atomicUsizeStore` lock-free atomic load/store/swap/CAS (`compareExchange` success vs failure) and fetch-modify return-previous-value semantics. Concrete nominal inputs: `a: AtomicUsize = AtomicUsize()`, `val: int = 1`, `order: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sync.atomic_z17_test
import * from "std/sync/atomic"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atomic_atomicUsizeStore_17(): int:
  let arg_a = AtomicUsize(val = 2)
  let edge_a = AtomicUsize(val = 0)
  let arg_val = 2
  let edge_val = 0
  let arg_order = 2
  let edge_order = 0
  atomicUsizeStore(arg_a, arg_val, arg_order)
  atomicUsizeStore(edge_a, edge_val, edge_order)
  assertEqInt(arg_a.val, 2, "atomicUsizeStore nominal arg_a.val == 2")
  assertEqInt(edge_a.val, 0, "atomicUsizeStore boundary edge_a.val == 0")
  ret 0
```

---

### `atomicUsizeFetchAdd` (`std/sync/atomic.aipl`)

- **Signature**: `pub fn atomicUsizeFetchAdd(mut a: AtomicUsize, delta: int, order: int): int:`
- **Import**: `import * from "std/sync/atomic"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut a: AtomicUsize, delta: int, order: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sync/atomic_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `atomicUsizeFetchAdd` lock-free atomic load/store/swap/CAS (`compareExchange` success vs failure) and fetch-modify return-previous-value semantics. Concrete nominal inputs: `a: AtomicUsize = AtomicUsize()`, `delta: int = 1`, `order: int = 1`; exercises core body path returning/computing `prev`.

```aipl
module tests.functions.sync.atomic_z18_test
import * from "std/sync/atomic"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atomic_atomicUsizeFetchAdd_18(): int:
  let arg_a = AtomicUsize(val = 2)
  let edge_a = AtomicUsize(val = 0)
  let arg_delta = 2
  let edge_delta = 0
  let arg_order = 2
  let edge_order = 0
  let resNom = atomicUsizeFetchAdd(arg_a, arg_delta, arg_order)
  let resEdge = atomicUsizeFetchAdd(edge_a, edge_delta, edge_order)
  assertEqInt(resNom, 2, "atomicUsizeFetchAdd nominal resNom == 2")
  assertEqInt(resEdge, 0, "atomicUsizeFetchAdd boundary resEdge == 0")
  ret 0
```

---

### `atomicMemoryFence` (`std/sync/atomic.aipl`)

- **Signature**: `pub fn atomicMemoryFence(order: int): int:`
- **Import**: `import * from "std/sync/atomic"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `order: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sync/atomic_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `atomicMemoryFence` lock-free atomic load/store/swap/CAS (`compareExchange` success vs failure) and fetch-modify return-previous-value semantics. Concrete nominal inputs: `order: int = 1`; exercises core body path returning/computing `order`.

```aipl
module tests.functions.sync.atomic_z19_test
import * from "std/sync/atomic"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atomic_atomicMemoryFence_19(): int:
  let arg_order = 2
  let edge_order = 0
  let resNom = atomicMemoryFence(arg_order)
  let resEdge = atomicMemoryFence(edge_order)
  assertEqInt(resNom, 2, "atomicMemoryFence nominal resNom == 2")
  assertEqInt(resEdge, 0, "atomicMemoryFence boundary resEdge == 0")
  ret 0
```

---

### `threadBarrierNew` (`std/sync/barrier.aipl`)

- **Signature**: `pub fn threadBarrierNew(threshold: int): ThreadBarrier:`
- **Import**: `import * from "std/sync/barrier"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `threshold: int` | **Returns**: `ThreadBarrier`
- **Unit Test**: `tests/functions/sync/barrier_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `threadBarrierNew` N-party `ThreadBarrier` phase release, `WaitGroup` counter zeroing, `CountDownLatch`, and `OnceInit` single-execution guarantee. Concrete nominal inputs: `threshold: int = 1`; exercises core body path returning/computing `ThreadBarrier(threshold: t, count: 0, generation: 0)`.

```aipl
module tests.functions.sync.barrier_z1_test
import * from "std/sync/barrier"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_barrier_threadBarrierNew_1(): int:
  let arg_threshold = 2
  let edge_threshold = 0
  let resNom = threadBarrierNew(arg_threshold)
  let resEdge = threadBarrierNew(edge_threshold)
  assertEqInt(resNom.threshold, 2, "threadBarrierNew nominal resNom.threshold == 2")
  assertEqInt(resEdge.threshold, 1, "threadBarrierNew boundary resEdge.threshold == 1")
  ret 0
```

---

### `threadBarrierWait` (`std/sync/barrier.aipl`)

- **Signature**: `pub fn threadBarrierWait(mut b: ThreadBarrier): bool:`
- **Import**: `import * from "std/sync/barrier"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut b: ThreadBarrier` | **Returns**: `bool`
- **Unit Test**: `tests/functions/sync/barrier_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `threadBarrierWait` N-party `ThreadBarrier` phase release, `WaitGroup` counter zeroing, `CountDownLatch`, and `OnceInit` single-execution guarantee. Concrete nominal inputs: `b: ThreadBarrier = ThreadBarrier(threshold = 1)`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.sync.barrier_z2_test
import * from "std/sync/barrier"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_barrier_threadBarrierWait_2(): int:
  let arg_b = ThreadBarrier(threshold = 2, count = 0, generation = 4)
  let edge_b = ThreadBarrier(threshold = 0, count = 0, generation = 1)
  let resNom = threadBarrierWait(arg_b)
  let resEdge = threadBarrierWait(edge_b)
  assert(resNom == false, "threadBarrierWait nominal resNom == false")
  assert(resEdge == true, "threadBarrierWait boundary resEdge == true")
  ret 0
```

---

### `waitGroupNew` (`std/sync/barrier.aipl`)

- **Signature**: `pub fn waitGroupNew(): WaitGroup:`
- **Import**: `import * from "std/sync/barrier"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `WaitGroup`
- **Unit Test**: `tests/functions/sync/barrier_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `waitGroupNew` N-party `ThreadBarrier` phase release, `WaitGroup` counter zeroing, `CountDownLatch`, and `OnceInit` single-execution guarantee. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `WaitGroup(counter: 0)`.

```aipl
module tests.functions.sync.barrier_z3_test
import * from "std/sync/barrier"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_barrier_waitGroupNew_3(): int:
  let resNom = waitGroupNew()
  let resEdge = waitGroupNew()
  assertEqInt(resNom.counter, 0, "waitGroupNew nominal resNom.counter == 0")
  assertEqInt(resEdge.counter, 0, "waitGroupNew boundary resEdge.counter == 0")
  ret 0
```

---

### `waitGroupAdd` (`std/sync/barrier.aipl`)

- **Signature**: `pub fn waitGroupAdd(mut wg: WaitGroup, delta: int): void:`
- **Import**: `import * from "std/sync/barrier"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut wg: WaitGroup, delta: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/sync/barrier_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `waitGroupAdd` N-party `ThreadBarrier` phase release, `WaitGroup` counter zeroing, `CountDownLatch`, and `OnceInit` single-execution guarantee. Concrete nominal inputs: `wg: WaitGroup = WaitGroup()`, `delta: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sync.barrier_z4_test
import * from "std/sync/barrier"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_barrier_waitGroupAdd_4(): int:
  let arg_wg = WaitGroup(counter = 4)
  let edge_wg = WaitGroup(counter = 1)
  let arg_delta = 2
  let edge_delta = 0
  waitGroupAdd(arg_wg, arg_delta)
  waitGroupAdd(edge_wg, edge_delta)
  assertEqInt(arg_wg.counter, 6, "waitGroupAdd nominal arg_wg.counter == 6")
  assertEqInt(edge_wg.counter, 1, "waitGroupAdd boundary edge_wg.counter == 1")
  ret 0
```

---

### `waitGroupDone` (`std/sync/barrier.aipl`)

- **Signature**: `pub fn waitGroupDone(mut wg: WaitGroup): void:`
- **Import**: `import * from "std/sync/barrier"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut wg: WaitGroup` | **Returns**: `void`
- **Unit Test**: `tests/functions/sync/barrier_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `waitGroupDone` N-party `ThreadBarrier` phase release, `WaitGroup` counter zeroing, `CountDownLatch`, and `OnceInit` single-execution guarantee. Concrete nominal inputs: `wg: WaitGroup = WaitGroup()`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sync.barrier_z5_test
import * from "std/sync/barrier"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_barrier_waitGroupDone_5(): int:
  let arg_wg = WaitGroup(counter = 4)
  let edge_wg = WaitGroup(counter = 1)
  waitGroupDone(arg_wg)
  waitGroupDone(edge_wg)
  assertEqInt(arg_wg.counter, 3, "waitGroupDone nominal arg_wg.counter == 3")
  assertEqInt(edge_wg.counter, 0, "waitGroupDone boundary edge_wg.counter == 0")
  ret 0
```

---

### `waitGroupWait` (`std/sync/barrier.aipl`)

- **Signature**: `pub fn waitGroupWait(wg: WaitGroup): bool:`
- **Import**: `import * from "std/sync/barrier"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `wg: WaitGroup` | **Returns**: `bool`
- **Unit Test**: `tests/functions/sync/barrier_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `waitGroupWait` N-party `ThreadBarrier` phase release, `WaitGroup` counter zeroing, `CountDownLatch`, and `OnceInit` single-execution guarantee. Concrete nominal inputs: `wg: WaitGroup = WaitGroup()`; exercises core body path returning/computing `wg.counter == 0`.

```aipl
module tests.functions.sync.barrier_z6_test
import * from "std/sync/barrier"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_barrier_waitGroupWait_6(): int:
  let arg_wg = WaitGroup(counter = 4)
  let edge_wg = WaitGroup(counter = 1)
  let resNom = waitGroupWait(arg_wg)
  let resEdge = waitGroupWait(edge_wg)
  assert(resNom == false, "waitGroupWait nominal resNom == false")
  assert(resEdge == false, "waitGroupWait boundary resEdge == false")
  ret 0
```

---

### `countDownLatchNew` (`std/sync/barrier.aipl`)

- **Signature**: `pub fn countDownLatchNew(count: int): CountDownLatch:`
- **Import**: `import * from "std/sync/barrier"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `count: int` | **Returns**: `CountDownLatch`
- **Unit Test**: `tests/functions/sync/barrier_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `countDownLatchNew` N-party `ThreadBarrier` phase release, `WaitGroup` counter zeroing, `CountDownLatch`, and `OnceInit` single-execution guarantee. Concrete nominal inputs: `count: int = 64`; exercises core body path returning/computing `CountDownLatch(remaining: c)`.

```aipl
module tests.functions.sync.barrier_z7_test
import * from "std/sync/barrier"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_barrier_countDownLatchNew_7(): int:
  let arg_count = 4
  let edge_count = 1
  let resNom = countDownLatchNew(arg_count)
  let resEdge = countDownLatchNew(edge_count)
  assertEqInt(resNom.remaining, 4, "countDownLatchNew nominal resNom.remaining == 4")
  assertEqInt(resEdge.remaining, 1, "countDownLatchNew boundary resEdge.remaining == 1")
  ret 0
```

---

### `countDownLatchCountDown` (`std/sync/barrier.aipl`)

- **Signature**: `pub fn countDownLatchCountDown(mut cdl: CountDownLatch): void:`
- **Import**: `import * from "std/sync/barrier"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut cdl: CountDownLatch` | **Returns**: `void`
- **Unit Test**: `tests/functions/sync/barrier_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `countDownLatchCountDown` N-party `ThreadBarrier` phase release, `WaitGroup` counter zeroing, `CountDownLatch`, and `OnceInit` single-execution guarantee. Concrete nominal inputs: `cdl: CountDownLatch = CountDownLatch()`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sync.barrier_z8_test
import * from "std/sync/barrier"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_barrier_countDownLatchCountDown_8(): int:
  let arg_cdl = CountDownLatch(remaining = 4)
  let edge_cdl = CountDownLatch(remaining = 1)
  countDownLatchCountDown(arg_cdl)
  countDownLatchCountDown(edge_cdl)
  assertEqInt(arg_cdl.remaining, 3, "countDownLatchCountDown nominal arg_cdl.remaining == 3")
  assertEqInt(edge_cdl.remaining, 0, "countDownLatchCountDown boundary edge_cdl.remaining == 0")
  ret 0
```

---

### `countDownLatchWait` (`std/sync/barrier.aipl`)

- **Signature**: `pub fn countDownLatchWait(cdl: CountDownLatch): bool:`
- **Import**: `import * from "std/sync/barrier"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cdl: CountDownLatch` | **Returns**: `bool`
- **Unit Test**: `tests/functions/sync/barrier_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `countDownLatchWait` N-party `ThreadBarrier` phase release, `WaitGroup` counter zeroing, `CountDownLatch`, and `OnceInit` single-execution guarantee. Concrete nominal inputs: `cdl: CountDownLatch = CountDownLatch()`; exercises core body path returning/computing `cdl.remaining == 0`.

```aipl
module tests.functions.sync.barrier_z9_test
import * from "std/sync/barrier"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_barrier_countDownLatchWait_9(): int:
  let arg_cdl = CountDownLatch(remaining = 4)
  let edge_cdl = CountDownLatch(remaining = 1)
  let resNom = countDownLatchWait(arg_cdl)
  let resEdge = countDownLatchWait(edge_cdl)
  assert(resNom == false, "countDownLatchWait nominal resNom == false")
  assert(resEdge == false, "countDownLatchWait boundary resEdge == false")
  ret 0
```

---

### `countDownLatchGetCount` (`std/sync/barrier.aipl`)

- **Signature**: `pub fn countDownLatchGetCount(cdl: CountDownLatch): int:`
- **Import**: `import * from "std/sync/barrier"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cdl: CountDownLatch` | **Returns**: `int`
- **Unit Test**: `tests/functions/sync/barrier_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `countDownLatchGetCount` N-party `ThreadBarrier` phase release, `WaitGroup` counter zeroing, `CountDownLatch`, and `OnceInit` single-execution guarantee. Concrete nominal inputs: `cdl: CountDownLatch = CountDownLatch()`; exercises core body path returning/computing `cdl.remaining`.

```aipl
module tests.functions.sync.barrier_z10_test
import * from "std/sync/barrier"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_barrier_countDownLatchGetCount_10(): int:
  let arg_cdl = CountDownLatch(remaining = 4)
  let edge_cdl = CountDownLatch(remaining = 1)
  let resNom = countDownLatchGetCount(arg_cdl)
  let resEdge = countDownLatchGetCount(edge_cdl)
  assertEqInt(resNom, 4, "countDownLatchGetCount nominal resNom == 4")
  assertEqInt(resEdge, 1, "countDownLatchGetCount boundary resEdge == 1")
  ret 0
```

---

### `onceInitNew` (`std/sync/barrier.aipl`)

- **Signature**: `pub fn onceInitNew(): OnceInit:`
- **Import**: `import * from "std/sync/barrier"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `OnceInit`
- **Unit Test**: `tests/functions/sync/barrier_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `onceInitNew` N-party `ThreadBarrier` phase release, `WaitGroup` counter zeroing, `CountDownLatch`, and `OnceInit` single-execution guarantee. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `OnceInit(state: 0)`.

```aipl
module tests.functions.sync.barrier_z11_test
import * from "std/sync/barrier"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_barrier_onceInitNew_11(): int:
  let resNom = onceInitNew()
  let resEdge = onceInitNew()
  assertEqInt(resNom.state, 0, "onceInitNew nominal resNom.state == 0")
  assertEqInt(resEdge.state, 0, "onceInitNew boundary resEdge.state == 0")
  ret 0
```

---

### `onceInitDo` (`std/sync/barrier.aipl`)

- **Signature**: `pub fn onceInitDo(mut oi: OnceInit): bool:`
- **Import**: `import * from "std/sync/barrier"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut oi: OnceInit` | **Returns**: `bool`
- **Unit Test**: `tests/functions/sync/barrier_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `onceInitDo` N-party `ThreadBarrier` phase release, `WaitGroup` counter zeroing, `CountDownLatch`, and `OnceInit` single-execution guarantee. Concrete nominal inputs: `oi: OnceInit = OnceInit()`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.sync.barrier_z12_test
import * from "std/sync/barrier"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_barrier_onceInitDo_12(): int:
  let arg_oi = OnceInit(state = 0)
  let edge_oi = OnceInit(state = 0)
  let resNom = onceInitDo(arg_oi)
  let resEdge = onceInitDo(edge_oi)
  assert(resNom == true, "onceInitDo nominal resNom == true")
  assert(resEdge == true, "onceInitDo boundary resEdge == true")
  ret 0
```

---

### `onceInitIsDone` (`std/sync/barrier.aipl`)

- **Signature**: `pub fn onceInitIsDone(oi: OnceInit): bool:`
- **Import**: `import * from "std/sync/barrier"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `oi: OnceInit` | **Returns**: `bool`
- **Unit Test**: `tests/functions/sync/barrier_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `onceInitIsDone` N-party `ThreadBarrier` phase release, `WaitGroup` counter zeroing, `CountDownLatch`, and `OnceInit` single-execution guarantee. Concrete nominal inputs: `oi: OnceInit = OnceInit()`; exercises core body path returning/computing `oi.state == 2`.

```aipl
module tests.functions.sync.barrier_z13_test
import * from "std/sync/barrier"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_barrier_onceInitIsDone_13(): int:
  let arg_oi = OnceInit(state = 0)
  let edge_oi = OnceInit(state = 0)
  let resNom = onceInitIsDone(arg_oi)
  let resEdge = onceInitIsDone(edge_oi)
  assert(resNom == false, "onceInitIsDone nominal resNom == false")
  assert(resEdge == false, "onceInitIsDone boundary resEdge == false")
  ret 0
```

---

### `mpscChannelNew` (`std/sync/channel.aipl`)

- **Signature**: `pub fn mpscChannelNew(capacity: int): MpscChannel:`
- **Import**: `import * from "std/sync/channel"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `capacity: int` | **Returns**: `MpscChannel`
- **Unit Test**: `tests/functions/sync/channel_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `mpscChannelNew` bounded MPSC/SPSC FIFO ordering, full-queue `TrySend` backpressure, closed-channel drain semantics, and multi-subscriber `BroadcastChannel` fanout. Concrete nominal inputs: `capacity: int = 64`; exercises core body path returning/computing `MpscChannel(capacity: cap, buffer: buf, head: 0, tail: 0, count: 0, closed: false)`.

```aipl
module tests.functions.sync.channel_z1_test
import * from "std/sync/channel"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_channel_mpscChannelNew_1(): int:
  let arg_capacity = 4
  let edge_capacity = 1
  let resNom = mpscChannelNew(arg_capacity)
  let resEdge = mpscChannelNew(edge_capacity)
  assertEqInt(resNom.capacity, 4, "mpscChannelNew nominal resNom.capacity == 4")
  assertEqInt(resEdge.capacity, 1, "mpscChannelNew boundary resEdge.capacity == 1")
  ret 0
```

---

### `mpscTrySend` (`std/sync/channel.aipl`)

- **Signature**: `pub fn mpscTrySend(mut ch: MpscChannel, val: int): Result[bool, ChannelError]:`
- **Import**: `import * from "std/sync/channel"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut ch: MpscChannel, val: int` | **Returns**: `Result[bool, ChannelError]`
- **Unit Test**: `tests/functions/sync/channel_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `mpscTrySend` bounded MPSC/SPSC FIFO ordering, full-queue `TrySend` backpressure, closed-channel drain semantics, and multi-subscriber `BroadcastChannel` fanout. Concrete nominal inputs: `ch: MpscChannel = MpscChannel(capacity = 64)`, `val: int = 1`; exercises core body path returning/computing `Ok(true)`.

```aipl
module tests.functions.sync.channel_z2_test
import * from "std/sync/channel"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_channel_mpscTrySend_2(): int:
  let arg_ch = MpscChannel(capacity = 4, buffer = [], head = 0, tail = 0, count = 0, closed = true)
  let edge_ch = MpscChannel(capacity = 4, buffer = [], head = 0, tail = 0, count = 0, closed = false)
  let arg_val = 2
  let edge_val = 0
  let resNom = mpscTrySend(arg_ch, arg_val)
  let resEdge = mpscTrySend(edge_ch, edge_val)
  assert(resNom.isOk() == false, "mpscTrySend nominal resNom.isOk() == false")
  assert(resEdge.isOk() == true, "mpscTrySend boundary resEdge.isOk() == true")
  ret 0
```

---

### `mpscSend` (`std/sync/channel.aipl`)

- **Signature**: `pub fn mpscSend(mut ch: MpscChannel, val: int): Result[bool, ChannelError]:`
- **Import**: `import * from "std/sync/channel"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut ch: MpscChannel, val: int` | **Returns**: `Result[bool, ChannelError]`
- **Unit Test**: `tests/functions/sync/channel_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `mpscSend` bounded MPSC/SPSC FIFO ordering, full-queue `TrySend` backpressure, closed-channel drain semantics, and multi-subscriber `BroadcastChannel` fanout. Concrete nominal inputs: `ch: MpscChannel = MpscChannel(capacity = 64)`, `val: int = 1`; exercises core body path returning/computing `mpscTrySend(ch, val)`.

```aipl
module tests.functions.sync.channel_z3_test
import * from "std/sync/channel"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_channel_mpscSend_3(): int:
  let arg_ch = MpscChannel(capacity = 4, buffer = [], head = 0, tail = 0, count = 0, closed = true)
  let edge_ch = MpscChannel(capacity = 4, buffer = [], head = 0, tail = 0, count = 0, closed = false)
  let arg_val = 2
  let edge_val = 0
  let resNom = mpscSend(arg_ch, arg_val)
  let resEdge = mpscSend(edge_ch, edge_val)
  assert(resNom.isOk() == false, "mpscSend nominal resNom.isOk() == false")
  assert(resEdge.isOk() == true, "mpscSend boundary resEdge.isOk() == true")
  ret 0
```

---

### `mpscTryRecv` (`std/sync/channel.aipl`)

- **Signature**: `pub fn mpscTryRecv(mut ch: MpscChannel): Result[int, ChannelError]:`
- **Import**: `import * from "std/sync/channel"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut ch: MpscChannel` | **Returns**: `Result[int, ChannelError]`
- **Unit Test**: `tests/functions/sync/channel_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `mpscTryRecv` bounded MPSC/SPSC FIFO ordering, full-queue `TrySend` backpressure, closed-channel drain semantics, and multi-subscriber `BroadcastChannel` fanout. Concrete nominal inputs: `ch: MpscChannel = MpscChannel(capacity = 64)`; exercises core body path returning/computing `Ok(v)`.

```aipl
module tests.functions.sync.channel_z4_test
import * from "std/sync/channel"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_channel_mpscTryRecv_4(): int:
  let arg_ch = MpscChannel(capacity = 4, buffer = [], head = 0, tail = 0, count = 0, closed = true)
  let edge_ch = MpscChannel(capacity = 4, buffer = [], head = 0, tail = 0, count = 0, closed = false)
  let resNom = mpscTryRecv(arg_ch)
  let resEdge = mpscTryRecv(edge_ch)
  assert(resNom.isOk() == false, "mpscTryRecv nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "mpscTryRecv boundary resEdge.isOk() == false")
  ret 0
```

---

### `mpscRecv` (`std/sync/channel.aipl`)

- **Signature**: `pub fn mpscRecv(mut ch: MpscChannel): Result[int, ChannelError]:`
- **Import**: `import * from "std/sync/channel"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut ch: MpscChannel` | **Returns**: `Result[int, ChannelError]`
- **Unit Test**: `tests/functions/sync/channel_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `mpscRecv` bounded MPSC/SPSC FIFO ordering, full-queue `TrySend` backpressure, closed-channel drain semantics, and multi-subscriber `BroadcastChannel` fanout. Concrete nominal inputs: `ch: MpscChannel = MpscChannel(capacity = 64)`; exercises core body path returning/computing `mpscTryRecv(ch)`.

```aipl
module tests.functions.sync.channel_z5_test
import * from "std/sync/channel"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_channel_mpscRecv_5(): int:
  let arg_ch = MpscChannel(capacity = 4, buffer = [], head = 0, tail = 0, count = 0, closed = true)
  let edge_ch = MpscChannel(capacity = 4, buffer = [], head = 0, tail = 0, count = 0, closed = false)
  let resNom = mpscRecv(arg_ch)
  let resEdge = mpscRecv(edge_ch)
  assert(resNom.isOk() == false, "mpscRecv nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "mpscRecv boundary resEdge.isOk() == false")
  ret 0
```

---

### `mpscClose` (`std/sync/channel.aipl`)

- **Signature**: `pub fn mpscClose(mut ch: MpscChannel): bool:`
- **Import**: `import * from "std/sync/channel"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut ch: MpscChannel` | **Returns**: `bool`
- **Unit Test**: `tests/functions/sync/channel_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `mpscClose` bounded MPSC/SPSC FIFO ordering, full-queue `TrySend` backpressure, closed-channel drain semantics, and multi-subscriber `BroadcastChannel` fanout. Concrete nominal inputs: `ch: MpscChannel = MpscChannel(capacity = 64)`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.sync.channel_z6_test
import * from "std/sync/channel"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_channel_mpscClose_6(): int:
  let arg_ch = MpscChannel(capacity = 4, buffer = [], head = 0, tail = 0, count = 0, closed = true)
  let edge_ch = MpscChannel(capacity = 4, buffer = [], head = 0, tail = 0, count = 0, closed = false)
  let resNom = mpscClose(arg_ch)
  let resEdge = mpscClose(edge_ch)
  assert(resNom == false, "mpscClose nominal resNom == false")
  assert(resEdge == true, "mpscClose boundary resEdge == true")
  ret 0
```

---

### `mpscIsClosed` (`std/sync/channel.aipl`)

- **Signature**: `pub fn mpscIsClosed(ch: MpscChannel): bool:`
- **Import**: `import * from "std/sync/channel"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ch: MpscChannel` | **Returns**: `bool`
- **Unit Test**: `tests/functions/sync/channel_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `mpscIsClosed` bounded MPSC/SPSC FIFO ordering, full-queue `TrySend` backpressure, closed-channel drain semantics, and multi-subscriber `BroadcastChannel` fanout. Concrete nominal inputs: `ch: MpscChannel = MpscChannel(capacity = 64)`; exercises core body path returning/computing `ch.closed`.

```aipl
module tests.functions.sync.channel_z7_test
import * from "std/sync/channel"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_channel_mpscIsClosed_7(): int:
  let arg_ch = MpscChannel(capacity = 4, buffer = [], head = 0, tail = 0, count = 0, closed = true)
  let edge_ch = MpscChannel(capacity = 4, buffer = [], head = 0, tail = 0, count = 0, closed = false)
  let resNom = mpscIsClosed(arg_ch)
  let resEdge = mpscIsClosed(edge_ch)
  assert(resNom == true, "mpscIsClosed nominal resNom == true")
  assert(resEdge == false, "mpscIsClosed boundary resEdge == false")
  ret 0
```

---

### `mpscLen` (`std/sync/channel.aipl`)

- **Signature**: `pub fn mpscLen(ch: MpscChannel): int:`
- **Import**: `import * from "std/sync/channel"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ch: MpscChannel` | **Returns**: `int`
- **Unit Test**: `tests/functions/sync/channel_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `mpscLen` bounded MPSC/SPSC FIFO ordering, full-queue `TrySend` backpressure, closed-channel drain semantics, and multi-subscriber `BroadcastChannel` fanout. Concrete nominal inputs: `ch: MpscChannel = MpscChannel(capacity = 64)`; exercises core body path returning/computing `ch.count`.

```aipl
module tests.functions.sync.channel_z8_test
import * from "std/sync/channel"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_channel_mpscLen_8(): int:
  let arg_ch = MpscChannel(capacity = 4, buffer = [], head = 0, tail = 0, count = 0, closed = true)
  let edge_ch = MpscChannel(capacity = 4, buffer = [], head = 0, tail = 0, count = 0, closed = false)
  let resNom = mpscLen(arg_ch)
  let resEdge = mpscLen(edge_ch)
  assertEqInt(resNom, 0, "mpscLen nominal resNom == 0")
  assertEqInt(resEdge, 0, "mpscLen boundary resEdge == 0")
  ret 0
```

---

### `mpscCapacity` (`std/sync/channel.aipl`)

- **Signature**: `pub fn mpscCapacity(ch: MpscChannel): int:`
- **Import**: `import * from "std/sync/channel"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ch: MpscChannel` | **Returns**: `int`
- **Unit Test**: `tests/functions/sync/channel_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `mpscCapacity` bounded MPSC/SPSC FIFO ordering, full-queue `TrySend` backpressure, closed-channel drain semantics, and multi-subscriber `BroadcastChannel` fanout. Concrete nominal inputs: `ch: MpscChannel = MpscChannel(capacity = 64)`; exercises core body path returning/computing `ch.capacity`.

```aipl
module tests.functions.sync.channel_z9_test
import * from "std/sync/channel"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_channel_mpscCapacity_9(): int:
  let arg_ch = MpscChannel(capacity = 4, buffer = [], head = 0, tail = 0, count = 0, closed = true)
  let edge_ch = MpscChannel(capacity = 4, buffer = [], head = 0, tail = 0, count = 0, closed = false)
  let resNom = mpscCapacity(arg_ch)
  let resEdge = mpscCapacity(edge_ch)
  assertEqInt(resNom, 4, "mpscCapacity nominal resNom == 4")
  assertEqInt(resEdge, 4, "mpscCapacity boundary resEdge == 4")
  ret 0
```

---

### `spscChannelNew` (`std/sync/channel.aipl`)

- **Signature**: `pub fn spscChannelNew(capacity: int): SpscRingChannel:`
- **Import**: `import * from "std/sync/channel"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `capacity: int` | **Returns**: `SpscRingChannel`
- **Unit Test**: `tests/functions/sync/channel_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `spscChannelNew` bounded MPSC/SPSC FIFO ordering, full-queue `TrySend` backpressure, closed-channel drain semantics, and multi-subscriber `BroadcastChannel` fanout. Concrete nominal inputs: `capacity: int = 64`; exercises core body path returning/computing `SpscRingChannel(capacity: cap, buffer: buf, readPos: 0, writePos: 0, closed: false)`.

```aipl
module tests.functions.sync.channel_z10_test
import * from "std/sync/channel"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_channel_spscChannelNew_10(): int:
  let arg_capacity = 4
  let edge_capacity = 1
  let resNom = spscChannelNew(arg_capacity)
  let resEdge = spscChannelNew(edge_capacity)
  assertEqInt(resNom.capacity, 4, "spscChannelNew nominal resNom.capacity == 4")
  assertEqInt(resEdge.capacity, 1, "spscChannelNew boundary resEdge.capacity == 1")
  ret 0
```

---

### `spscTrySend` (`std/sync/channel.aipl`)

- **Signature**: `pub fn spscTrySend(mut ch: SpscRingChannel, val: int): Result[bool, ChannelError]:`
- **Import**: `import * from "std/sync/channel"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut ch: SpscRingChannel, val: int` | **Returns**: `Result[bool, ChannelError]`
- **Unit Test**: `tests/functions/sync/channel_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `spscTrySend` bounded MPSC/SPSC FIFO ordering, full-queue `TrySend` backpressure, closed-channel drain semantics, and multi-subscriber `BroadcastChannel` fanout. Concrete nominal inputs: `ch: SpscRingChannel = SpscRingChannel(capacity = 64)`, `val: int = 1`; exercises core body path returning/computing `Ok(true)`.

```aipl
module tests.functions.sync.channel_z11_test
import * from "std/sync/channel"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_channel_spscTrySend_11(): int:
  let arg_ch = SpscRingChannel(capacity = 4, buffer = [], readPos = 0, writePos = 0, closed = true)
  let edge_ch = SpscRingChannel(capacity = 4, buffer = [], readPos = 0, writePos = 0, closed = false)
  let arg_val = 2
  let edge_val = 0
  let resNom = spscTrySend(arg_ch, arg_val)
  let resEdge = spscTrySend(edge_ch, edge_val)
  assert(resNom.isOk() == false, "spscTrySend nominal resNom.isOk() == false")
  assert(resEdge.isOk() == true, "spscTrySend boundary resEdge.isOk() == true")
  ret 0
```

---

### `spscSend` (`std/sync/channel.aipl`)

- **Signature**: `pub fn spscSend(mut ch: SpscRingChannel, val: int): Result[bool, ChannelError]:`
- **Import**: `import * from "std/sync/channel"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut ch: SpscRingChannel, val: int` | **Returns**: `Result[bool, ChannelError]`
- **Unit Test**: `tests/functions/sync/channel_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `spscSend` bounded MPSC/SPSC FIFO ordering, full-queue `TrySend` backpressure, closed-channel drain semantics, and multi-subscriber `BroadcastChannel` fanout. Concrete nominal inputs: `ch: SpscRingChannel = SpscRingChannel(capacity = 64)`, `val: int = 1`; exercises core body path returning/computing `spscTrySend(ch, val)`.

```aipl
module tests.functions.sync.channel_z12_test
import * from "std/sync/channel"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_channel_spscSend_12(): int:
  let arg_ch = SpscRingChannel(capacity = 4, buffer = [], readPos = 0, writePos = 0, closed = true)
  let edge_ch = SpscRingChannel(capacity = 4, buffer = [], readPos = 0, writePos = 0, closed = false)
  let arg_val = 2
  let edge_val = 0
  let resNom = spscSend(arg_ch, arg_val)
  let resEdge = spscSend(edge_ch, edge_val)
  assert(resNom.isOk() == false, "spscSend nominal resNom.isOk() == false")
  assert(resEdge.isOk() == true, "spscSend boundary resEdge.isOk() == true")
  ret 0
```

---

### `spscTryRecv` (`std/sync/channel.aipl`)

- **Signature**: `pub fn spscTryRecv(mut ch: SpscRingChannel): Result[int, ChannelError]:`
- **Import**: `import * from "std/sync/channel"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut ch: SpscRingChannel` | **Returns**: `Result[int, ChannelError]`
- **Unit Test**: `tests/functions/sync/channel_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `spscTryRecv` bounded MPSC/SPSC FIFO ordering, full-queue `TrySend` backpressure, closed-channel drain semantics, and multi-subscriber `BroadcastChannel` fanout. Concrete nominal inputs: `ch: SpscRingChannel = SpscRingChannel(capacity = 64)`; exercises core body path returning/computing `Ok(v)`.

```aipl
module tests.functions.sync.channel_z13_test
import * from "std/sync/channel"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_channel_spscTryRecv_13(): int:
  let arg_ch = SpscRingChannel(capacity = 4, buffer = [], readPos = 0, writePos = 0, closed = true)
  let edge_ch = SpscRingChannel(capacity = 4, buffer = [], readPos = 0, writePos = 0, closed = false)
  let resNom = spscTryRecv(arg_ch)
  let resEdge = spscTryRecv(edge_ch)
  assert(resNom.isOk() == false, "spscTryRecv nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "spscTryRecv boundary resEdge.isOk() == false")
  ret 0
```

---

### `spscRecv` (`std/sync/channel.aipl`)

- **Signature**: `pub fn spscRecv(mut ch: SpscRingChannel): Result[int, ChannelError]:`
- **Import**: `import * from "std/sync/channel"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut ch: SpscRingChannel` | **Returns**: `Result[int, ChannelError]`
- **Unit Test**: `tests/functions/sync/channel_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `spscRecv` bounded MPSC/SPSC FIFO ordering, full-queue `TrySend` backpressure, closed-channel drain semantics, and multi-subscriber `BroadcastChannel` fanout. Concrete nominal inputs: `ch: SpscRingChannel = SpscRingChannel(capacity = 64)`; exercises core body path returning/computing `spscTryRecv(ch)`.

```aipl
module tests.functions.sync.channel_z14_test
import * from "std/sync/channel"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_channel_spscRecv_14(): int:
  let arg_ch = SpscRingChannel(capacity = 4, buffer = [], readPos = 0, writePos = 0, closed = true)
  let edge_ch = SpscRingChannel(capacity = 4, buffer = [], readPos = 0, writePos = 0, closed = false)
  let resNom = spscRecv(arg_ch)
  let resEdge = spscRecv(edge_ch)
  assert(resNom.isOk() == false, "spscRecv nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "spscRecv boundary resEdge.isOk() == false")
  ret 0
```

---

### `broadcastChannelNew` (`std/sync/channel.aipl`)

- **Signature**: `pub fn broadcastChannelNew(capacity: int): BroadcastChannel:`
- **Import**: `import * from "std/sync/channel"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `capacity: int` | **Returns**: `BroadcastChannel`
- **Unit Test**: `tests/functions/sync/channel_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `broadcastChannelNew` bounded MPSC/SPSC FIFO ordering, full-queue `TrySend` backpressure, closed-channel drain semantics, and multi-subscriber `BroadcastChannel` fanout. Concrete nominal inputs: `capacity: int = 64`; exercises core body path returning/computing `BroadcastChannel(capacity: cap, messages: [], subscriberPositions: [], closed: false)`.

```aipl
module tests.functions.sync.channel_z15_test
import * from "std/sync/channel"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_channel_broadcastChannelNew_15(): int:
  let arg_capacity = 4
  let edge_capacity = 1
  let resNom = broadcastChannelNew(arg_capacity)
  let resEdge = broadcastChannelNew(edge_capacity)
  assertEqInt(resNom.capacity, 4, "broadcastChannelNew nominal resNom.capacity == 4")
  assertEqInt(resEdge.capacity, 1, "broadcastChannelNew boundary resEdge.capacity == 1")
  ret 0
```

---

### `broadcastSubscribe` (`std/sync/channel.aipl`)

- **Signature**: `pub fn broadcastSubscribe(mut ch: BroadcastChannel): int:`
- **Import**: `import * from "std/sync/channel"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut ch: BroadcastChannel` | **Returns**: `int`
- **Unit Test**: `tests/functions/sync/channel_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `broadcastSubscribe` bounded MPSC/SPSC FIFO ordering, full-queue `TrySend` backpressure, closed-channel drain semantics, and multi-subscriber `BroadcastChannel` fanout. Concrete nominal inputs: `ch: BroadcastChannel = BroadcastChannel(capacity = 64)`; exercises core body path returning/computing `subId`.

```aipl
module tests.functions.sync.channel_z16_test
import * from "std/sync/channel"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_channel_broadcastSubscribe_16(): int:
  let arg_ch = BroadcastChannel(capacity = 4, messages = [], subscriberPositions = [], closed = true)
  let edge_ch = BroadcastChannel(capacity = 4, messages = [], subscriberPositions = [], closed = false)
  let resNom = broadcastSubscribe(arg_ch)
  let resEdge = broadcastSubscribe(edge_ch)
  assertEqInt(resNom, 0, "broadcastSubscribe nominal resNom == 0")
  assertEqInt(resEdge, 0, "broadcastSubscribe boundary resEdge == 0")
  ret 0
```

---

### `broadcastSend` (`std/sync/channel.aipl`)

- **Signature**: `pub fn broadcastSend(mut ch: BroadcastChannel, val: int): Result[int, ChannelError]:`
- **Import**: `import * from "std/sync/channel"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut ch: BroadcastChannel, val: int` | **Returns**: `Result[int, ChannelError]`
- **Unit Test**: `tests/functions/sync/channel_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `broadcastSend` bounded MPSC/SPSC FIFO ordering, full-queue `TrySend` backpressure, closed-channel drain semantics, and multi-subscriber `BroadcastChannel` fanout. Concrete nominal inputs: `ch: BroadcastChannel = BroadcastChannel(capacity = 64)`, `val: int = 1`; exercises core body path returning/computing `Ok(ch.subscriberPositions.len())`.

```aipl
module tests.functions.sync.channel_z17_test
import * from "std/sync/channel"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_channel_broadcastSend_17(): int:
  let arg_ch = BroadcastChannel(capacity = 4, messages = [], subscriberPositions = [], closed = true)
  let edge_ch = BroadcastChannel(capacity = 4, messages = [], subscriberPositions = [], closed = false)
  let arg_val = 2
  let edge_val = 0
  let resNom = broadcastSend(arg_ch, arg_val)
  let resEdge = broadcastSend(edge_ch, edge_val)
  assert(resNom.isOk() == false, "broadcastSend nominal resNom.isOk() == false")
  assert(resEdge.isOk() == true, "broadcastSend boundary resEdge.isOk() == true")
  ret 0
```

---

### `broadcastRecv` (`std/sync/channel.aipl`)

- **Signature**: `pub fn broadcastRecv(mut ch: BroadcastChannel, subscriberId: int): Result[int, ChannelError]:`
- **Import**: `import * from "std/sync/channel"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut ch: BroadcastChannel, subscriberId: int` | **Returns**: `Result[int, ChannelError]`
- **Unit Test**: `tests/functions/sync/channel_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `broadcastRecv` bounded MPSC/SPSC FIFO ordering, full-queue `TrySend` backpressure, closed-channel drain semantics, and multi-subscriber `BroadcastChannel` fanout. Concrete nominal inputs: `ch: BroadcastChannel = BroadcastChannel(capacity = 64)`, `subscriberId: int = 1`; exercises core body path returning/computing `Ok(v)`.

```aipl
module tests.functions.sync.channel_z18_test
import * from "std/sync/channel"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_channel_broadcastRecv_18(): int:
  let arg_ch = BroadcastChannel(capacity = 4, messages = [], subscriberPositions = [], closed = true)
  let edge_ch = BroadcastChannel(capacity = 4, messages = [], subscriberPositions = [], closed = false)
  let arg_subscriberId = 4
  let edge_subscriberId = 1
  let resNom = broadcastRecv(arg_ch, arg_subscriberId)
  let resEdge = broadcastRecv(edge_ch, edge_subscriberId)
  assert(resNom.isOk() == false, "broadcastRecv nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "broadcastRecv boundary resEdge.isOk() == false")
  ret 0
```

---

### `mutexNew` (`std/sync/mutex.aipl`)

- **Signature**: `pub fn mutexNew(): Mutex:`
- **Import**: `import * from "std/sync/mutex"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Mutex`
- **Unit Test**: `tests/functions/sync/mutex_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `mutexNew` mutual exclusion lock/tryLock/unlock state transitions, spinlock acquisition, and condition variable signal/broadcast wakeups. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Mutex(locked: false, ownerThreadId: 0)`.

```aipl
module tests.functions.sync.mutex_z1_test
import * from "std/sync/mutex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mutex_mutexNew_1(): int:
  let resNom = mutexNew()
  let resEdge = mutexNew()
  assert(resNom.locked == false, "mutexNew nominal resNom.locked == false")
  assert(resEdge.locked == false, "mutexNew boundary resEdge.locked == false")
  ret 0
```

---

### `mutexLock` (`std/sync/mutex.aipl`)

- **Signature**: `pub fn mutexLock(mut m: Mutex): MutexGuard:`
- **Import**: `import * from "std/sync/mutex"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut m: Mutex` | **Returns**: `MutexGuard`
- **Unit Test**: `tests/functions/sync/mutex_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `mutexLock` mutual exclusion lock/tryLock/unlock state transitions, spinlock acquisition, and condition variable signal/broadcast wakeups. Concrete nominal inputs: `m: Mutex = Mutex()`; exercises core body path returning/computing `MutexGuard(mutexRef: m)`.

```aipl
module tests.functions.sync.mutex_z2_test
import * from "std/sync/mutex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mutex_mutexLock_2(): int:
  let arg_m = Mutex(locked = true, ownerThreadId = 4)
  let edge_m = Mutex(locked = false, ownerThreadId = 1)
  let resNom = mutexLock(arg_m)
  let resEdge = mutexLock(edge_m)
  assert(resNom.mutexRef.locked == true, "mutexLock nominal resNom.mutexRef.locked == true")
  assert(resEdge.mutexRef.locked == true, "mutexLock boundary resEdge.mutexRef.locked == true")
  ret 0
```

---

### `mutexTryLock` (`std/sync/mutex.aipl`)

- **Signature**: `pub fn mutexTryLock(mut m: Mutex): Option[MutexGuard]:`
- **Import**: `import * from "std/sync/mutex"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut m: Mutex` | **Returns**: `Option[MutexGuard]`
- **Unit Test**: `tests/functions/sync/mutex_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `mutexTryLock` mutual exclusion lock/tryLock/unlock state transitions, spinlock acquisition, and condition variable signal/broadcast wakeups. Concrete nominal inputs: `m: Mutex = Mutex()`; exercises core body path returning/computing `Some(MutexGuard(mutexRef: m))`.

```aipl
module tests.functions.sync.mutex_z3_test
import * from "std/sync/mutex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mutex_mutexTryLock_3(): int:
  let arg_m = Mutex(locked = true, ownerThreadId = 4)
  let edge_m = Mutex(locked = false, ownerThreadId = 1)
  let resNom = mutexTryLock(arg_m)
  let resEdge = mutexTryLock(edge_m)
  assert(resNom.isSome() == false, "mutexTryLock nominal resNom.isSome() == false")
  assert(resEdge.isSome() == true, "mutexTryLock boundary resEdge.isSome() == true")
  ret 0
```

---

### `mutexUnlock` (`std/sync/mutex.aipl`)

- **Signature**: `pub fn mutexUnlock(mut m: Mutex): bool:`
- **Import**: `import * from "std/sync/mutex"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut m: Mutex` | **Returns**: `bool`
- **Unit Test**: `tests/functions/sync/mutex_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `mutexUnlock` mutual exclusion lock/tryLock/unlock state transitions, spinlock acquisition, and condition variable signal/broadcast wakeups. Concrete nominal inputs: `m: Mutex = Mutex()`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.sync.mutex_z4_test
import * from "std/sync/mutex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mutex_mutexUnlock_4(): int:
  let arg_m = Mutex(locked = true, ownerThreadId = 4)
  let edge_m = Mutex(locked = false, ownerThreadId = 1)
  let resNom = mutexUnlock(arg_m)
  let resEdge = mutexUnlock(edge_m)
  assert(resNom == true, "mutexUnlock nominal resNom == true")
  assert(resEdge == false, "mutexUnlock boundary resEdge == false")
  ret 0
```

---

### `spinLockNew` (`std/sync/mutex.aipl`)

- **Signature**: `pub fn spinLockNew(): SpinLock:`
- **Import**: `import * from "std/sync/mutex"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `SpinLock`
- **Unit Test**: `tests/functions/sync/mutex_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `spinLockNew` mutual exclusion lock/tryLock/unlock state transitions, spinlock acquisition, and condition variable signal/broadcast wakeups. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `SpinLock(flag: 0)`.

```aipl
module tests.functions.sync.mutex_z5_test
import * from "std/sync/mutex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mutex_spinLockNew_5(): int:
  let resNom = spinLockNew()
  let resEdge = spinLockNew()
  assertEqInt(resNom.flag, 0, "spinLockNew nominal resNom.flag == 0")
  assertEqInt(resEdge.flag, 0, "spinLockNew boundary resEdge.flag == 0")
  ret 0
```

---

### `spinLockAcquire` (`std/sync/mutex.aipl`)

- **Signature**: `pub fn spinLockAcquire(mut sl: SpinLock): void:`
- **Import**: `import * from "std/sync/mutex"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut sl: SpinLock` | **Returns**: `void`
- **Unit Test**: `tests/functions/sync/mutex_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `spinLockAcquire` mutual exclusion lock/tryLock/unlock state transitions, spinlock acquisition, and condition variable signal/broadcast wakeups. Concrete nominal inputs: `sl: SpinLock = SpinLock()`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sync.mutex_z6_test
import * from "std/sync/mutex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mutex_spinLockAcquire_6(): int:
  let arg_sl = SpinLock(flag = 2)
  let edge_sl = SpinLock(flag = 0)
  spinLockAcquire(arg_sl)
  spinLockAcquire(edge_sl)
  assertEqInt(arg_sl.flag, 1, "spinLockAcquire nominal arg_sl.flag == 1")
  assertEqInt(edge_sl.flag, 1, "spinLockAcquire boundary edge_sl.flag == 1")
  ret 0
```

---

### `spinLockRelease` (`std/sync/mutex.aipl`)

- **Signature**: `pub fn spinLockRelease(mut sl: SpinLock): void:`
- **Import**: `import * from "std/sync/mutex"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut sl: SpinLock` | **Returns**: `void`
- **Unit Test**: `tests/functions/sync/mutex_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `spinLockRelease` mutual exclusion lock/tryLock/unlock state transitions, spinlock acquisition, and condition variable signal/broadcast wakeups. Concrete nominal inputs: `sl: SpinLock = SpinLock()`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sync.mutex_z7_test
import * from "std/sync/mutex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mutex_spinLockRelease_7(): int:
  let arg_sl = SpinLock(flag = 2)
  let edge_sl = SpinLock(flag = 0)
  spinLockRelease(arg_sl)
  spinLockRelease(edge_sl)
  assertEqInt(arg_sl.flag, 0, "spinLockRelease nominal arg_sl.flag == 0")
  assertEqInt(edge_sl.flag, 0, "spinLockRelease boundary edge_sl.flag == 0")
  ret 0
```

---

### `condVarNew` (`std/sync/mutex.aipl`)

- **Signature**: `pub fn condVarNew(): CondVar:`
- **Import**: `import * from "std/sync/mutex"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `CondVar`
- **Unit Test**: `tests/functions/sync/mutex_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `condVarNew` mutual exclusion lock/tryLock/unlock state transitions, spinlock acquisition, and condition variable signal/broadcast wakeups. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `CondVar(waitingCount: 0, signaledCount: 0)`.

```aipl
module tests.functions.sync.mutex_z8_test
import * from "std/sync/mutex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mutex_condVarNew_8(): int:
  let resNom = condVarNew()
  let resEdge = condVarNew()
  assertEqInt(resNom.waitingCount, 0, "condVarNew nominal resNom.waitingCount == 0")
  assertEqInt(resEdge.waitingCount, 0, "condVarNew boundary resEdge.waitingCount == 0")
  ret 0
```

---

### `condVarWait` (`std/sync/mutex.aipl`)

- **Signature**: `pub fn condVarWait(mut cv: CondVar, mut guard: MutexGuard): void:`
- **Import**: `import * from "std/sync/mutex"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut cv: CondVar, mut guard: MutexGuard` | **Returns**: `void`
- **Unit Test**: `tests/functions/sync/mutex_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `condVarWait` mutual exclusion lock/tryLock/unlock state transitions, spinlock acquisition, and condition variable signal/broadcast wakeups. Concrete nominal inputs: `cv: CondVar = CondVar()`, `guard: MutexGuard = MutexGuard(mutexRef = Mutex())`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sync.mutex_z9_test
import * from "std/sync/mutex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mutex_condVarWait_9(): int:
  let arg_cv = CondVar(waitingCount = 4, signaledCount = 4)
  let edge_cv = CondVar(waitingCount = 1, signaledCount = 1)
  let arg_guard = MutexGuard(mutexRef = Mutex(locked = true, ownerThreadId = 4))
  let edge_guard = MutexGuard(mutexRef = Mutex(locked = false, ownerThreadId = 1))
  condVarWait(arg_cv, arg_guard)
  condVarWait(edge_cv, edge_guard)
  assertEqInt(arg_cv.signaledCount, 3, "condVarWait nominal arg_cv.signaledCount == 3")
  assertEqInt(edge_cv.signaledCount, 0, "condVarWait boundary edge_cv.signaledCount == 0")
  ret 0
```

---

### `condVarWaitTimeout` (`std/sync/mutex.aipl`)

- **Signature**: `pub fn condVarWaitTimeout(mut cv: CondVar, mut guard: MutexGuard, timeoutMs: int): bool:`
- **Import**: `import * from "std/sync/mutex"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut cv: CondVar, mut guard: MutexGuard, timeoutMs: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/sync/mutex_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `condVarWaitTimeout` mutual exclusion lock/tryLock/unlock state transitions, spinlock acquisition, and condition variable signal/broadcast wakeups. Concrete nominal inputs: `cv: CondVar = CondVar()`, `guard: MutexGuard = MutexGuard(mutexRef = Mutex())`, `timeoutMs: int = 1`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.sync.mutex_z10_test
import * from "std/sync/mutex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mutex_condVarWaitTimeout_10(): int:
  let arg_cv = CondVar(waitingCount = 4, signaledCount = 4)
  let edge_cv = CondVar(waitingCount = 1, signaledCount = 1)
  let arg_guard = MutexGuard(mutexRef = Mutex(locked = true, ownerThreadId = 4))
  let edge_guard = MutexGuard(mutexRef = Mutex(locked = false, ownerThreadId = 1))
  let arg_timeoutMs = 4
  let edge_timeoutMs = 1
  let resNom = condVarWaitTimeout(arg_cv, arg_guard, arg_timeoutMs)
  let resEdge = condVarWaitTimeout(edge_cv, edge_guard, edge_timeoutMs)
  assert(resNom == true, "condVarWaitTimeout nominal resNom == true")
  assert(resEdge == true, "condVarWaitTimeout boundary resEdge == true")
  ret 0
```

---

### `condVarSignal` (`std/sync/mutex.aipl`)

- **Signature**: `pub fn condVarSignal(mut cv: CondVar): void:`
- **Import**: `import * from "std/sync/mutex"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut cv: CondVar` | **Returns**: `void`
- **Unit Test**: `tests/functions/sync/mutex_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `condVarSignal` mutual exclusion lock/tryLock/unlock state transitions, spinlock acquisition, and condition variable signal/broadcast wakeups. Concrete nominal inputs: `cv: CondVar = CondVar()`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sync.mutex_z11_test
import * from "std/sync/mutex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mutex_condVarSignal_11(): int:
  let arg_cv = CondVar(waitingCount = 4, signaledCount = 4)
  let edge_cv = CondVar(waitingCount = 1, signaledCount = 1)
  condVarSignal(arg_cv)
  condVarSignal(edge_cv)
  assertEqInt(arg_cv.waitingCount, 3, "condVarSignal nominal arg_cv.waitingCount == 3")
  assertEqInt(edge_cv.waitingCount, 0, "condVarSignal boundary edge_cv.waitingCount == 0")
  ret 0
```

---

### `condVarBroadcast` (`std/sync/mutex.aipl`)

- **Signature**: `pub fn condVarBroadcast(mut cv: CondVar): void:`
- **Import**: `import * from "std/sync/mutex"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut cv: CondVar` | **Returns**: `void`
- **Unit Test**: `tests/functions/sync/mutex_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `condVarBroadcast` mutual exclusion lock/tryLock/unlock state transitions, spinlock acquisition, and condition variable signal/broadcast wakeups. Concrete nominal inputs: `cv: CondVar = CondVar()`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sync.mutex_z12_test
import * from "std/sync/mutex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mutex_condVarBroadcast_12(): int:
  let arg_cv = CondVar(waitingCount = 4, signaledCount = 4)
  let edge_cv = CondVar(waitingCount = 1, signaledCount = 1)
  condVarBroadcast(arg_cv)
  condVarBroadcast(edge_cv)
  assertEqInt(arg_cv.waitingCount, 0, "condVarBroadcast nominal arg_cv.waitingCount == 0")
  assertEqInt(edge_cv.waitingCount, 0, "condVarBroadcast boundary edge_cv.waitingCount == 0")
  ret 0
```

---

### `rwLockNew` (`std/sync/rwlock.aipl`)

- **Signature**: `pub fn rwLockNew(): RwLock:`
- **Import**: `import * from "std/sync/rwlock"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `RwLock`
- **Unit Test**: `tests/functions/sync/rwlock_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `rwLockNew` shared multi-reader vs exclusive single-writer locking and `SeqLock` optimistic read retry on concurrent write sequence increments. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `RwLock(readers: 0, writer: false)`.

```aipl
module tests.functions.sync.rwlock_z1_test
import * from "std/sync/rwlock"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rwlock_rwLockNew_1(): int:
  let resNom = rwLockNew()
  let resEdge = rwLockNew()
  assertEqInt(resNom.readers, 0, "rwLockNew nominal resNom.readers == 0")
  assertEqInt(resEdge.readers, 0, "rwLockNew boundary resEdge.readers == 0")
  ret 0
```

---

### `rwLockRead` (`std/sync/rwlock.aipl`)

- **Signature**: `pub fn rwLockRead(mut lock: RwLock): RwLockReadGuard:`
- **Import**: `import * from "std/sync/rwlock"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut lock: RwLock` | **Returns**: `RwLockReadGuard`
- **Unit Test**: `tests/functions/sync/rwlock_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `rwLockRead` shared multi-reader vs exclusive single-writer locking and `SeqLock` optimistic read retry on concurrent write sequence increments. Concrete nominal inputs: `lock: RwLock = RwLock()`; exercises core body path returning/computing `RwLockReadGuard(rwlockRef: lock)`.

```aipl
module tests.functions.sync.rwlock_z2_test
import * from "std/sync/rwlock"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rwlock_rwLockRead_2(): int:
  let arg_lock = RwLock(readers = 2, writer = true)
  let edge_lock = RwLock(readers = 0, writer = false)
  let resNom = rwLockRead(arg_lock)
  let resEdge = rwLockRead(edge_lock)
  assertEqInt(resNom.rwlockRef.readers, 3, "rwLockRead nominal resNom.rwlockRef.readers == 3")
  assertEqInt(resEdge.rwlockRef.readers, 1, "rwLockRead boundary resEdge.rwlockRef.readers == 1")
  ret 0
```

---

### `rwLockTryRead` (`std/sync/rwlock.aipl`)

- **Signature**: `pub fn rwLockTryRead(mut lock: RwLock): Option[RwLockReadGuard]:`
- **Import**: `import * from "std/sync/rwlock"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut lock: RwLock` | **Returns**: `Option[RwLockReadGuard]`
- **Unit Test**: `tests/functions/sync/rwlock_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `rwLockTryRead` shared multi-reader vs exclusive single-writer locking and `SeqLock` optimistic read retry on concurrent write sequence increments. Concrete nominal inputs: `lock: RwLock = RwLock()`; exercises core body path returning/computing `Some(RwLockReadGuard(rwlockRef: lock))`.

```aipl
module tests.functions.sync.rwlock_z3_test
import * from "std/sync/rwlock"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rwlock_rwLockTryRead_3(): int:
  let arg_lock = RwLock(readers = 2, writer = true)
  let edge_lock = RwLock(readers = 0, writer = false)
  let resNom = rwLockTryRead(arg_lock)
  let resEdge = rwLockTryRead(edge_lock)
  assert(resNom.isSome() == false, "rwLockTryRead nominal resNom.isSome() == false")
  assert(resEdge.isSome() == true, "rwLockTryRead boundary resEdge.isSome() == true")
  ret 0
```

---

### `rwLockReadUnlock` (`std/sync/rwlock.aipl`)

- **Signature**: `pub fn rwLockReadUnlock(mut lock: RwLock): bool:`
- **Import**: `import * from "std/sync/rwlock"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut lock: RwLock` | **Returns**: `bool`
- **Unit Test**: `tests/functions/sync/rwlock_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `rwLockReadUnlock` shared multi-reader vs exclusive single-writer locking and `SeqLock` optimistic read retry on concurrent write sequence increments. Concrete nominal inputs: `lock: RwLock = RwLock()`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.sync.rwlock_z4_test
import * from "std/sync/rwlock"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rwlock_rwLockReadUnlock_4(): int:
  let arg_lock = RwLock(readers = 2, writer = true)
  let edge_lock = RwLock(readers = 0, writer = false)
  let resNom = rwLockReadUnlock(arg_lock)
  let resEdge = rwLockReadUnlock(edge_lock)
  assert(resNom == true, "rwLockReadUnlock nominal resNom == true")
  assert(resEdge == false, "rwLockReadUnlock boundary resEdge == false")
  ret 0
```

---

### `rwLockWrite` (`std/sync/rwlock.aipl`)

- **Signature**: `pub fn rwLockWrite(mut lock: RwLock): RwLockWriteGuard:`
- **Import**: `import * from "std/sync/rwlock"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut lock: RwLock` | **Returns**: `RwLockWriteGuard`
- **Unit Test**: `tests/functions/sync/rwlock_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `rwLockWrite` shared multi-reader vs exclusive single-writer locking and `SeqLock` optimistic read retry on concurrent write sequence increments. Concrete nominal inputs: `lock: RwLock = RwLock()`; exercises core body path returning/computing `RwLockWriteGuard(rwlockRef: lock)`.

```aipl
module tests.functions.sync.rwlock_z5_test
import * from "std/sync/rwlock"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rwlock_rwLockWrite_5(): int:
  let arg_lock = RwLock(readers = 2, writer = true)
  let edge_lock = RwLock(readers = 0, writer = false)
  let resNom = rwLockWrite(arg_lock)
  let resEdge = rwLockWrite(edge_lock)
  assertEqInt(resNom.rwlockRef.readers, 2, "rwLockWrite nominal resNom.rwlockRef.readers == 2")
  assertEqInt(resEdge.rwlockRef.readers, 0, "rwLockWrite boundary resEdge.rwlockRef.readers == 0")
  ret 0
```

---

### `rwLockTryWrite` (`std/sync/rwlock.aipl`)

- **Signature**: `pub fn rwLockTryWrite(mut lock: RwLock): Option[RwLockWriteGuard]:`
- **Import**: `import * from "std/sync/rwlock"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut lock: RwLock` | **Returns**: `Option[RwLockWriteGuard]`
- **Unit Test**: `tests/functions/sync/rwlock_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `rwLockTryWrite` shared multi-reader vs exclusive single-writer locking and `SeqLock` optimistic read retry on concurrent write sequence increments. Concrete nominal inputs: `lock: RwLock = RwLock()`; exercises core body path returning/computing `Some(RwLockWriteGuard(rwlockRef: lock))`.

```aipl
module tests.functions.sync.rwlock_z6_test
import * from "std/sync/rwlock"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rwlock_rwLockTryWrite_6(): int:
  let arg_lock = RwLock(readers = 2, writer = true)
  let edge_lock = RwLock(readers = 0, writer = false)
  let resNom = rwLockTryWrite(arg_lock)
  let resEdge = rwLockTryWrite(edge_lock)
  assert(resNom.isSome() == false, "rwLockTryWrite nominal resNom.isSome() == false")
  assert(resEdge.isSome() == true, "rwLockTryWrite boundary resEdge.isSome() == true")
  ret 0
```

---

### `rwLockWriteUnlock` (`std/sync/rwlock.aipl`)

- **Signature**: `pub fn rwLockWriteUnlock(mut lock: RwLock): bool:`
- **Import**: `import * from "std/sync/rwlock"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut lock: RwLock` | **Returns**: `bool`
- **Unit Test**: `tests/functions/sync/rwlock_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `rwLockWriteUnlock` shared multi-reader vs exclusive single-writer locking and `SeqLock` optimistic read retry on concurrent write sequence increments. Concrete nominal inputs: `lock: RwLock = RwLock()`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.sync.rwlock_z7_test
import * from "std/sync/rwlock"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rwlock_rwLockWriteUnlock_7(): int:
  let arg_lock = RwLock(readers = 2, writer = true)
  let edge_lock = RwLock(readers = 0, writer = false)
  let resNom = rwLockWriteUnlock(arg_lock)
  let resEdge = rwLockWriteUnlock(edge_lock)
  assert(resNom == true, "rwLockWriteUnlock nominal resNom == true")
  assert(resEdge == false, "rwLockWriteUnlock boundary resEdge == false")
  ret 0
```

---

### `seqLockNew` (`std/sync/rwlock.aipl`)

- **Signature**: `pub fn seqLockNew(): SeqLock:`
- **Import**: `import * from "std/sync/rwlock"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `SeqLock`
- **Unit Test**: `tests/functions/sync/rwlock_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `seqLockNew` shared multi-reader vs exclusive single-writer locking and `SeqLock` optimistic read retry on concurrent write sequence increments. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `SeqLock(sequence: 0)`.

```aipl
module tests.functions.sync.rwlock_z8_test
import * from "std/sync/rwlock"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rwlock_seqLockNew_8(): int:
  let resNom = seqLockNew()
  let resEdge = seqLockNew()
  assertEqInt(resNom.sequence, 0, "seqLockNew nominal resNom.sequence == 0")
  assertEqInt(resEdge.sequence, 0, "seqLockNew boundary resEdge.sequence == 0")
  ret 0
```

---

### `seqLockReadBegin` (`std/sync/rwlock.aipl`)

- **Signature**: `pub fn seqLockReadBegin(sl: SeqLock): int:`
- **Import**: `import * from "std/sync/rwlock"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sl: SeqLock` | **Returns**: `int`
- **Unit Test**: `tests/functions/sync/rwlock_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `seqLockReadBegin` shared multi-reader vs exclusive single-writer locking and `SeqLock` optimistic read retry on concurrent write sequence increments. Concrete nominal inputs: `sl: SeqLock = SeqLock()`; exercises core body path returning/computing `sl.sequence`.

```aipl
module tests.functions.sync.rwlock_z9_test
import * from "std/sync/rwlock"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rwlock_seqLockReadBegin_9(): int:
  let arg_sl = SeqLock(sequence = 4)
  let edge_sl = SeqLock(sequence = 1)
  let resNom = seqLockReadBegin(arg_sl)
  let resEdge = seqLockReadBegin(edge_sl)
  assertEqInt(resNom, 4, "seqLockReadBegin nominal resNom == 4")
  assertEqInt(resEdge, 1, "seqLockReadBegin boundary resEdge == 1")
  ret 0
```

---

### `seqLockReadRetry` (`std/sync/rwlock.aipl`)

- **Signature**: `pub fn seqLockReadRetry(sl: SeqLock, initialSeq: int): bool:`
- **Import**: `import * from "std/sync/rwlock"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sl: SeqLock, initialSeq: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/sync/rwlock_test.aipl` | **Example**: `examples/ex_111_sync_mutex_shared_ledger_cli.aipl`
- **Behavioral Summary**: Verify `seqLockReadRetry` shared multi-reader vs exclusive single-writer locking and `SeqLock` optimistic read retry on concurrent write sequence increments. Concrete nominal inputs: `sl: SeqLock = SeqLock()`, `initialSeq: int = 1`; exercises core body path returning/computing `sl.sequence != initialSeq`.

```aipl
module tests.functions.sync.rwlock_z10_test
import * from "std/sync/rwlock"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rwlock_seqLockReadRetry_10(): int:
  let arg_sl = SeqLock(sequence = 4)
  let edge_sl = SeqLock(sequence = 1)
  let arg_initialSeq = 4
  let edge_initialSeq = 1
  let resNom = seqLockReadRetry(arg_sl, arg_initialSeq)
  let resEdge = seqLockReadRetry(edge_sl, edge_initialSeq)
  assert(resNom == false, "seqLockReadRetry nominal resNom == false")
  assert(resEdge == true, "seqLockReadRetry boundary resEdge == true")
  ret 0
```

---

### `seqLockWriteBegin` (`std/sync/rwlock.aipl`)

- **Signature**: `pub fn seqLockWriteBegin(mut sl: SeqLock): void:`
- **Import**: `import * from "std/sync/rwlock"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut sl: SeqLock` | **Returns**: `void`
- **Unit Test**: `tests/functions/sync/rwlock_test.aipl` | **Example**: `examples/ex_109_os_system_monitor_top_cli.aipl`
- **Behavioral Summary**: Verify `seqLockWriteBegin` shared multi-reader vs exclusive single-writer locking and `SeqLock` optimistic read retry on concurrent write sequence increments. Concrete nominal inputs: `sl: SeqLock = SeqLock()`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sync.rwlock_z11_test
import * from "std/sync/rwlock"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rwlock_seqLockWriteBegin_11(): int:
  let arg_sl = SeqLock(sequence = 4)
  let edge_sl = SeqLock(sequence = 1)
  seqLockWriteBegin(arg_sl)
  seqLockWriteBegin(edge_sl)
  assertEqInt(arg_sl.sequence, 5, "seqLockWriteBegin nominal arg_sl.sequence == 5")
  assertEqInt(edge_sl.sequence, 2, "seqLockWriteBegin boundary edge_sl.sequence == 2")
  ret 0
```

---

### `seqLockWriteEnd` (`std/sync/rwlock.aipl`)

- **Signature**: `pub fn seqLockWriteEnd(mut sl: SeqLock): void:`
- **Import**: `import * from "std/sync/rwlock"` (or barrel `import * from "std/sync/sync_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut sl: SeqLock` | **Returns**: `void`
- **Unit Test**: `tests/functions/sync/rwlock_test.aipl` | **Example**: `examples/ex_110_sync_atomic_lockfree_counter_cli.aipl`
- **Behavioral Summary**: Verify `seqLockWriteEnd` shared multi-reader vs exclusive single-writer locking and `SeqLock` optimistic read retry on concurrent write sequence increments. Concrete nominal inputs: `sl: SeqLock = SeqLock()`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sync.rwlock_z12_test
import * from "std/sync/rwlock"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rwlock_seqLockWriteEnd_12(): int:
  let arg_sl = SeqLock(sequence = 4)
  let edge_sl = SeqLock(sequence = 1)
  seqLockWriteEnd(arg_sl)
  seqLockWriteEnd(edge_sl)
  assertEqInt(arg_sl.sequence, 5, "seqLockWriteEnd nominal arg_sl.sequence == 5")
  assertEqInt(edge_sl.sequence, 2, "seqLockWriteEnd boundary edge_sl.sequence == 2")
  ret 0
```
