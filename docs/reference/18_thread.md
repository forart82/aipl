[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 18: `thread` API Reference

> Complete API reference manual for AIPL standard library domain `thread` (38 callable functions & methods across ["std/thread/fiber.aipl", "std/thread/job_system.aipl", "std/thread/thread_local.aipl", "std/thread/thread_mod.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `thread`
- **Target Source Modules**: ["std/thread/fiber.aipl", "std/thread/job_system.aipl", "std/thread/thread_local.aipl", "std/thread/thread_mod.aipl"]
- **Total Callable Functions & Methods**: 38
- **Total Data Types (`struct` & `enum`)**: 13
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(13 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `FiberState` | `pub struct` | `std/thread/fiber.aipl` | `state: int` | `FiberState(state)` |
| `YieldContext` | `pub struct` | `std/thread/fiber.aipl` | `fiberId: int`, `mut yieldVal: int`, `mut resumeArg: int` | `YieldContext(fiberId, mut yieldVal, mut resumeArg)` |
| `Fiber` | `pub struct` | `std/thread/fiber.aipl` | `id: int`, `mut state: int`, `mut stepCount: int`, `mut maxSteps: int`, `mut resultVal: int`, `mut sleepTicks: int = 0` | `Fiber(id, mut state, mut stepCount, mut maxSteps, mut resultVal, mut sleepTicks)` |
| `FiberScheduler` | `pub struct` | `std/thread/fiber.aipl` | `mut activeFibers: [Fiber]`, `mut completedCount: int` | `FiberScheduler(mut activeFibers, mut completedCount)` |
| `JobPriority` | `pub struct` | `std/thread/job_system.aipl` | `level: int` | `JobPriority(level)` |
| `JobStatus` | `pub struct` | `std/thread/job_system.aipl` | `status: int` | `JobStatus(status)` |
| `JobHandle` | `pub struct` | `std/thread/job_system.aipl` | `jobId: int`, `priority: int`, `mut status: int`, `mut result: int` | `JobHandle(jobId, priority, mut status, mut result)` |
| `JobTask` | `pub struct` | `std/thread/job_system.aipl` | `id: int`, `priority: int`, `inputVal: int`, `mut outputVal: int` | `JobTask(id, priority, inputVal, mut outputVal)` |
| `JobDagNode` | `pub struct` | `std/thread/job_system.aipl` | `jobId: int`, `mut dependencies: [int]`, `mut dependents: [int]`, `mut satisfiedCount: int` | `JobDagNode(jobId, mut dependencies, mut dependents, mut satisfiedCount)` |
| `JobSystem` | `pub struct` | `std/thread/job_system.aipl` | `workerCount: int`, `mut workerQueues: [[JobTask]]`, `mut dagNodes: [JobDagNode]`, `mut completedJobs: [JobHandle]`, `mut stolenCount: int`, `mut isRunning: bool`, `mut nextJobId: int = 1` | `JobSystem(workerCount, mut workerQueues, mut dagNodes, mut completedJobs, mut stolenCount, mut isRunning, mut nextJobId)` |
| `ThreadConfig` | `pub struct` | `std/thread/thread_local.aipl` | `name: str`, `stackSizeBytes: int` | `ThreadConfig(name, stackSizeBytes)` |
| `ThreadHandle` | `pub struct` | `std/thread/thread_local.aipl` | `id: int`, `name: str`, `mut isFinished: bool`, `payloadResult: int = 0` | `ThreadHandle(id, name, mut isFinished, payloadResult)` |
| `ThreadLocal` | `pub struct` | `std/thread/thread_local.aipl` | `slotIndex: int`, `mut values: [int]` | `ThreadLocal(slotIndex, mut values)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/thread/fiber.aipl` | `fiberSpawn` | `pub fn fiberSpawn(steps: int): Fiber:` | `tests/functions/thread/fiber_test.aipl` |
| `2` | `std/thread/fiber.aipl` | `fiberResume` | `pub fn fiberResume(mut f: Fiber, arg: int): Result[int, str]:` | `tests/functions/thread/fiber_test.aipl` |
| `3` | `std/thread/fiber.aipl` | `fiberYield` | `pub fn fiberYield(mut f: Fiber, yieldVal: int): int:` | `tests/functions/thread/fiber_test.aipl` |
| `4` | `std/thread/fiber.aipl` | `fiberState` | `pub fn fiberState(f: Fiber): int:` | `tests/functions/thread/fiber_test.aipl` |
| `5` | `std/thread/fiber.aipl` | `fiberResult` | `pub fn fiberResult(f: Fiber): Option[int]:` | `tests/functions/thread/fiber_test.aipl` |
| `6` | `std/thread/fiber.aipl` | `fiberCurrentId` | `pub fn fiberCurrentId(): int:` | `tests/functions/thread/fiber_test.aipl` |
| `7` | `std/thread/fiber.aipl` | `fiberSchedulerNew` | `pub fn fiberSchedulerNew(): FiberScheduler:` | `tests/functions/thread/fiber_test.aipl` |
| `8` | `std/thread/fiber.aipl` | `fiberSchedulerAdd` | `pub fn fiberSchedulerAdd(mut sched: FiberScheduler, f: Fiber): void:` | `tests/functions/thread/fiber_test.aipl` |
| `9` | `std/thread/fiber.aipl` | `fiberSchedulerRunUntilIdle` | `pub fn fiberSchedulerRunUntilIdle(mut sched: FiberScheduler): int:` | `tests/functions/thread/fiber_test.aipl` |
| `10` | `std/thread/fiber.aipl` | `fiberSchedulerCount` | `pub fn fiberSchedulerCount(sched: FiberScheduler): int:` | `tests/functions/thread/fiber_test.aipl` |
| `11` | `std/thread/fiber.aipl` | `fiberSleepYield` | `pub fn fiberSleepYield(mut f: Fiber, ticks: int): void:` | `tests/functions/thread/fiber_test.aipl` |
| `12` | `std/thread/job_system.aipl` | `jobSystemNew` | `pub fn jobSystemNew(workers: int): JobSystem:` | `tests/functions/thread/job_system_test.aipl` |
| `13` | `std/thread/job_system.aipl` | `jobSystemShutdown` | `pub fn jobSystemShutdown(mut js: JobSystem): void:` | `tests/functions/thread/job_system_test.aipl` |
| `14` | `std/thread/job_system.aipl` | `jobSystemWorkerCount` | `pub fn jobSystemWorkerCount(js: JobSystem): int:` | `tests/functions/thread/job_system_test.aipl` |
| `15` | `std/thread/job_system.aipl` | `jobSubmitWithPriority` | `pub fn jobSubmitWithPriority(mut js: JobSystem, inputVal: int, priority: int): JobHandle:` | `tests/functions/thread/job_system_test.aipl` |
| `16` | `std/thread/job_system.aipl` | `jobSubmit` | `pub fn jobSubmit(mut js: JobSystem, inputVal: int): JobHandle:` | `tests/functions/thread/job_system_test.aipl` |
| `17` | `std/thread/job_system.aipl` | `findJobIdx` | `fn findJobIdx(jobs: [JobHandle], jobId: int): int:` | `tests/functions/thread/job_system_test.aipl` |
| `18` | `std/thread/job_system.aipl` | `findDagIdx` | `fn findDagIdx(nodes: [JobDagNode], jobId: int): int:` | `tests/functions/thread/job_system_test.aipl` |
| `19` | `std/thread/job_system.aipl` | `jobDependsOn` | `pub fn jobDependsOn(mut js: JobSystem, childJob: JobHandle, parentJob: JobHandle): bool:` | `tests/functions/thread/job_system_test.aipl` |
| `20` | `std/thread/job_system.aipl` | `jobWait` | `pub fn jobWait(mut js: JobSystem, handle: JobHandle): int:` | `tests/functions/thread/job_system_test.aipl` |
| `21` | `std/thread/job_system.aipl` | `jobWaitAll` | `pub fn jobWaitAll(mut js: JobSystem, handles: [JobHandle]): [int]:` | `tests/functions/thread/job_system_test.aipl` |
| `22` | `std/thread/job_system.aipl` | `jobIsComplete` | `pub fn jobIsComplete(js: JobSystem, handle: JobHandle): bool:` | `tests/functions/thread/job_system_test.aipl` |
| `23` | `std/thread/job_system.aipl` | `jobGetResult` | `pub fn jobGetResult(js: JobSystem, handle: JobHandle): Option[int]:` | `tests/functions/thread/job_system_test.aipl` |
| `24` | `std/thread/job_system.aipl` | `parallelFor` | `pub fn parallelFor(mut js: JobSystem, startIdx: int, endIdx: int, chunkSize: int): [int]:` | `tests/functions/thread/job_system_test.aipl` |
| `25` | `std/thread/job_system.aipl` | `parallelReduce` | `pub fn parallelReduce(mut js: JobSystem, numbers: [int], opKind: int): int:` | `tests/functions/thread/job_system_test.aipl` |
| `26` | `std/thread/job_system.aipl` | `jobSystemExecuteStealing` | `pub fn jobSystemExecuteStealing(mut js: JobSystem): int:` | `tests/functions/thread/job_system_test.aipl` |
| `27` | `std/thread/job_system.aipl` | `jobSystemStats` | `pub fn jobSystemStats(js: JobSystem): [int]:` | `tests/functions/thread/job_system_test.aipl` |
| `28` | `std/thread/thread_local.aipl` | `threadSpawnWithConfig` | `pub fn threadSpawnWithConfig(config: ThreadConfig, workerFnId: int, payload: int): Result[ThreadHandle, str]:` | `tests/functions/thread/thread_local_test.aipl` |
| `29` | `std/thread/thread_local.aipl` | `threadSpawn` | `pub fn threadSpawn(workerFnId: int, payload: int): Result[ThreadHandle, str]:` | `tests/functions/thread/thread_local_test.aipl` |
| `30` | `std/thread/thread_local.aipl` | `threadJoin` | `pub fn threadJoin(mut handle: ThreadHandle): Result[int, str]:` | `tests/functions/thread/thread_local_test.aipl` |
| `31` | `std/thread/thread_local.aipl` | `threadYield` | `pub fn threadYield(): void:` | `tests/functions/thread/thread_local_test.aipl` |
| `32` | `std/thread/thread_local.aipl` | `threadSleepMs` | `pub fn threadSleepMs(ms: int): void:` | `tests/functions/thread/thread_local_test.aipl` |
| `33` | `std/thread/thread_local.aipl` | `threadCurrentId` | `pub fn threadCurrentId(): int:` | `tests/functions/thread/thread_local_test.aipl` |
| `34` | `std/thread/thread_local.aipl` | `threadHardwareConcurrency` | `pub fn threadHardwareConcurrency(): int:` | `tests/functions/thread/thread_local_test.aipl` |
| `35` | `std/thread/thread_local.aipl` | `threadLocalNew` | `pub fn threadLocalNew(initialVal: int): ThreadLocal:` | `tests/functions/thread/thread_local_test.aipl` |
| `36` | `std/thread/thread_local.aipl` | `threadLocalGet` | `pub fn threadLocalGet(tl: ThreadLocal): int:` | `tests/functions/thread/thread_local_test.aipl` |
| `37` | `std/thread/thread_local.aipl` | `threadLocalSet` | `pub fn threadLocalSet(mut tl: ThreadLocal, val: int): void:` | `tests/functions/thread/thread_local_test.aipl` |
| `38` | `std/thread/thread_local.aipl` | `threadLocalClear` | `pub fn threadLocalClear(mut tl: ThreadLocal): void:` | `tests/functions/thread/thread_local_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `fiberSpawn` (`std/thread/fiber.aipl`)

- **Signature**: `pub fn fiberSpawn(steps: int): Fiber:`
- **Import**: `import * from "std/thread/fiber"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `steps: int` | **Returns**: `Fiber`
- **Unit Test**: `tests/functions/thread/fiber_test.aipl` | **Example**: `examples/ex_115_thread_job_system_work_stealing_cli.aipl`
- **Behavioral Summary**: Verify `fiberSpawn` cooperative coroutine `Ready -> Running -> Suspended -> Completed` state transitions and `FiberScheduler` round-robin execution. Concrete nominal inputs: `steps: int = 1`; exercises core body path returning/computing `Fiber(id: 100 + maxS, state: 0, stepCount: 0, maxSteps: maxS, resultVal: 0, sleepTicks: 0)`.

```aipl
module tests.functions.thread.fiber_z1_test
import * from "std/thread/fiber"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fiber_fiberSpawn_1(): int:
  let arg_steps = 4
  let edge_steps = 1
  let resNom = fiberSpawn(arg_steps)
  let resEdge = fiberSpawn(edge_steps)
  assertEqInt(resNom.id, 104, "fiberSpawn nominal resNom.id == 104")
  assertEqInt(resEdge.id, 101, "fiberSpawn boundary resEdge.id == 101")
  ret 0
```

---

### `fiberResume` (`std/thread/fiber.aipl`)

- **Signature**: `pub fn fiberResume(mut f: Fiber, arg: int): Result[int, str]:`
- **Import**: `import * from "std/thread/fiber"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut f: Fiber, arg: int` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/thread/fiber_test.aipl` | **Example**: `examples/ex_116_thread_fiber_cooperative_coroutines_cli.aipl`
- **Behavioral Summary**: Verify `fiberResume` cooperative coroutine `Ready -> Running -> Suspended -> Completed` state transitions and `FiberScheduler` round-robin execution. Concrete nominal inputs: `f: Fiber = Fiber(id = 1)`, `arg: int = 1`; exercises core body path returning/computing `Ok(f.resultVal)`.

```aipl
module tests.functions.thread.fiber_z2_test
import * from "std/thread/fiber"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fiber_fiberResume_2(): int:
  let arg_f = Fiber(id = 1, state = 0, stepCount = 4, maxSteps = 4, resultVal = 2, sleepTicks = 4)
  let edge_f = Fiber(id = 0, state = 0, stepCount = 1, maxSteps = 1, resultVal = 0, sleepTicks = 1)
  let arg_arg = 2
  let edge_arg = 0
  let resNom = fiberResume(arg_f, arg_arg)
  let resEdge = fiberResume(edge_f, edge_arg)
  assert(resNom.isOk() == true, "fiberResume nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "fiberResume boundary resEdge.isOk() == true")
  ret 0
```

---

### `fiberYield` (`std/thread/fiber.aipl`)

- **Signature**: `pub fn fiberYield(mut f: Fiber, yieldVal: int): int:`
- **Import**: `import * from "std/thread/fiber"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut f: Fiber, yieldVal: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/thread/fiber_test.aipl` | **Example**: `examples/ex_117_thread_local_context_propagation_cli.aipl`
- **Behavioral Summary**: Verify `fiberYield` cooperative coroutine `Ready -> Running -> Suspended -> Completed` state transitions and `FiberScheduler` round-robin execution. Concrete nominal inputs: `f: Fiber = Fiber(id = 1)`, `yieldVal: int = 1`; exercises core body path returning/computing `yieldVal`.

```aipl
module tests.functions.thread.fiber_z3_test
import * from "std/thread/fiber"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fiber_fiberYield_3(): int:
  let arg_f = Fiber(id = 1, state = 0, stepCount = 4, maxSteps = 4, resultVal = 2, sleepTicks = 4)
  let edge_f = Fiber(id = 0, state = 0, stepCount = 1, maxSteps = 1, resultVal = 0, sleepTicks = 1)
  let arg_yieldVal = 1
  let edge_yieldVal = 0
  let resNom = fiberYield(arg_f, arg_yieldVal)
  let resEdge = fiberYield(edge_f, edge_yieldVal)
  assertEqInt(resNom, 1, "fiberYield nominal resNom == 1")
  assertEqInt(resEdge, 0, "fiberYield boundary resEdge == 0")
  ret 0
```

---

### `fiberState` (`std/thread/fiber.aipl`)

- **Signature**: `pub fn fiberState(f: Fiber): int:`
- **Import**: `import * from "std/thread/fiber"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `f: Fiber` | **Returns**: `int`
- **Unit Test**: `tests/functions/thread/fiber_test.aipl` | **Example**: `examples/ex_115_thread_job_system_work_stealing_cli.aipl`
- **Behavioral Summary**: Verify `fiberState` cooperative coroutine `Ready -> Running -> Suspended -> Completed` state transitions and `FiberScheduler` round-robin execution. Concrete nominal inputs: `f: Fiber = Fiber(id = 1)`; exercises core body path returning/computing `f.state`.

```aipl
module tests.functions.thread.fiber_z4_test
import * from "std/thread/fiber"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fiber_fiberState_4(): int:
  let arg_f = Fiber(id = 1, state = 0, stepCount = 4, maxSteps = 4, resultVal = 2, sleepTicks = 4)
  let edge_f = Fiber(id = 0, state = 0, stepCount = 1, maxSteps = 1, resultVal = 0, sleepTicks = 1)
  let resNom = fiberState(arg_f)
  let resEdge = fiberState(edge_f)
  assertEqInt(resNom, 0, "fiberState nominal resNom == 0")
  assertEqInt(resEdge, 0, "fiberState boundary resEdge == 0")
  ret 0
```

---

### `fiberResult` (`std/thread/fiber.aipl`)

- **Signature**: `pub fn fiberResult(f: Fiber): Option[int]:`
- **Import**: `import * from "std/thread/fiber"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `f: Fiber` | **Returns**: `Option[int]`
- **Unit Test**: `tests/functions/thread/fiber_test.aipl` | **Example**: `examples/ex_116_thread_fiber_cooperative_coroutines_cli.aipl`
- **Behavioral Summary**: Verify `fiberResult` cooperative coroutine `Ready -> Running -> Suspended -> Completed` state transitions and `FiberScheduler` round-robin execution. Concrete nominal inputs: `f: Fiber = Fiber(id = 1)`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.thread.fiber_z5_test
import * from "std/thread/fiber"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fiber_fiberResult_5(): int:
  let arg_f = Fiber(id = 1, state = 0, stepCount = 4, maxSteps = 4, resultVal = 2, sleepTicks = 4)
  let edge_f = Fiber(id = 0, state = 0, stepCount = 1, maxSteps = 1, resultVal = 0, sleepTicks = 1)
  let resNom = fiberResult(arg_f)
  let resEdge = fiberResult(edge_f)
  assert(resNom.isSome() == false, "fiberResult nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "fiberResult boundary resEdge.isSome() == false")
  ret 0
```

---

### `fiberCurrentId` (`std/thread/fiber.aipl`)

- **Signature**: `pub fn fiberCurrentId(): int:`
- **Import**: `import * from "std/thread/fiber"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/thread/fiber_test.aipl` | **Example**: `examples/ex_117_thread_local_context_propagation_cli.aipl`
- **Behavioral Summary**: Verify `fiberCurrentId` cooperative coroutine `Ready -> Running -> Suspended -> Completed` state transitions and `FiberScheduler` round-robin execution. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `1`.

```aipl
module tests.functions.thread.fiber_z6_test
import * from "std/thread/fiber"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fiber_fiberCurrentId_6(): int:
  let resNom = fiberCurrentId()
  let resEdge = fiberCurrentId()
  assertEqInt(resNom, 1, "fiberCurrentId nominal resNom == 1")
  assertEqInt(resEdge, 1, "fiberCurrentId boundary resEdge == 1")
  ret 0
```

---

### `fiberSchedulerNew` (`std/thread/fiber.aipl`)

- **Signature**: `pub fn fiberSchedulerNew(): FiberScheduler:`
- **Import**: `import * from "std/thread/fiber"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `FiberScheduler`
- **Unit Test**: `tests/functions/thread/fiber_test.aipl` | **Example**: `examples/ex_115_thread_job_system_work_stealing_cli.aipl`
- **Behavioral Summary**: Verify `fiberSchedulerNew` cooperative coroutine `Ready -> Running -> Suspended -> Completed` state transitions and `FiberScheduler` round-robin execution. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `FiberScheduler(activeFibers: [], completedCount: 0)`.

```aipl
module tests.functions.thread.fiber_z7_test
import * from "std/thread/fiber"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fiber_fiberSchedulerNew_7(): int:
  let resNom = fiberSchedulerNew()
  let resEdge = fiberSchedulerNew()
  assertEqInt(resNom.activeFibers.len(), 0, "fiberSchedulerNew nominal resNom.activeFibers.len() == 0")
  assertEqInt(resEdge.activeFibers.len(), 0, "fiberSchedulerNew boundary resEdge.activeFibers.len() == 0")
  ret 0
```

---

### `fiberSchedulerAdd` (`std/thread/fiber.aipl`)

- **Signature**: `pub fn fiberSchedulerAdd(mut sched: FiberScheduler, f: Fiber): void:`
- **Import**: `import * from "std/thread/fiber"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut sched: FiberScheduler, f: Fiber` | **Returns**: `void`
- **Unit Test**: `tests/functions/thread/fiber_test.aipl` | **Example**: `examples/ex_116_thread_fiber_cooperative_coroutines_cli.aipl`
- **Behavioral Summary**: Verify `fiberSchedulerAdd` cooperative coroutine `Ready -> Running -> Suspended -> Completed` state transitions and `FiberScheduler` round-robin execution. Concrete nominal inputs: `sched: FiberScheduler = FiberScheduler()`, `f: Fiber = Fiber(id = 1)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.thread.fiber_z8_test
import * from "std/thread/fiber"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fiber_fiberSchedulerAdd_8(): int:
  let arg_sched = FiberScheduler(activeFibers = [], completedCount = 4)
  let edge_sched = FiberScheduler(activeFibers = [], completedCount = 1)
  let arg_f = Fiber(id = 1, state = 0, stepCount = 4, maxSteps = 4, resultVal = 2, sleepTicks = 4)
  let edge_f = Fiber(id = 0, state = 0, stepCount = 1, maxSteps = 1, resultVal = 0, sleepTicks = 1)
  fiberSchedulerAdd(arg_sched, arg_f)
  fiberSchedulerAdd(edge_sched, edge_f)
  assertEqInt(arg_sched.activeFibers.len(), 1, "fiberSchedulerAdd nominal arg_sched.activeFibers.len() == 1")
  assertEqInt(edge_sched.activeFibers.len(), 1, "fiberSchedulerAdd boundary edge_sched.activeFibers.len() == 1")
  ret 0
```

---

### `fiberSchedulerRunUntilIdle` (`std/thread/fiber.aipl`)

- **Signature**: `pub fn fiberSchedulerRunUntilIdle(mut sched: FiberScheduler): int:`
- **Import**: `import * from "std/thread/fiber"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut sched: FiberScheduler` | **Returns**: `int`
- **Unit Test**: `tests/functions/thread/fiber_test.aipl` | **Example**: `examples/ex_117_thread_local_context_propagation_cli.aipl`
- **Behavioral Summary**: Verify `fiberSchedulerRunUntilIdle` cooperative coroutine `Ready -> Running -> Suspended -> Completed` state transitions and `FiberScheduler` round-robin execution. Concrete nominal inputs: `sched: FiberScheduler = FiberScheduler()`; exercises core body path returning/computing `sched.completedCount`.

```aipl
module tests.functions.thread.fiber_z9_test
import * from "std/thread/fiber"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fiber_fiberSchedulerRunUntilIdle_9(): int:
  let arg_sched = FiberScheduler(activeFibers = [], completedCount = 4)
  let edge_sched = FiberScheduler(activeFibers = [], completedCount = 1)
  let resNom = fiberSchedulerRunUntilIdle(arg_sched)
  let resEdge = fiberSchedulerRunUntilIdle(edge_sched)
  assertEqInt(resNom, 4, "fiberSchedulerRunUntilIdle nominal resNom == 4")
  assertEqInt(resEdge, 1, "fiberSchedulerRunUntilIdle boundary resEdge == 1")
  ret 0
```

---

### `fiberSchedulerCount` (`std/thread/fiber.aipl`)

- **Signature**: `pub fn fiberSchedulerCount(sched: FiberScheduler): int:`
- **Import**: `import * from "std/thread/fiber"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sched: FiberScheduler` | **Returns**: `int`
- **Unit Test**: `tests/functions/thread/fiber_test.aipl` | **Example**: `examples/ex_115_thread_job_system_work_stealing_cli.aipl`
- **Behavioral Summary**: Verify `fiberSchedulerCount` cooperative coroutine `Ready -> Running -> Suspended -> Completed` state transitions and `FiberScheduler` round-robin execution. Concrete nominal inputs: `sched: FiberScheduler = FiberScheduler()`; exercises core body path returning/computing `sched.activeFibers.len()`.

```aipl
module tests.functions.thread.fiber_z10_test
import * from "std/thread/fiber"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fiber_fiberSchedulerCount_10(): int:
  let arg_sched = FiberScheduler(activeFibers = [], completedCount = 4)
  let edge_sched = FiberScheduler(activeFibers = [], completedCount = 1)
  let resNom = fiberSchedulerCount(arg_sched)
  let resEdge = fiberSchedulerCount(edge_sched)
  assertEqInt(resNom, 0, "fiberSchedulerCount nominal resNom == 0")
  assertEqInt(resEdge, 0, "fiberSchedulerCount boundary resEdge == 0")
  ret 0
```

---

### `fiberSleepYield` (`std/thread/fiber.aipl`)

- **Signature**: `pub fn fiberSleepYield(mut f: Fiber, ticks: int): void:`
- **Import**: `import * from "std/thread/fiber"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut f: Fiber, ticks: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/thread/fiber_test.aipl` | **Example**: `examples/ex_116_thread_fiber_cooperative_coroutines_cli.aipl`
- **Behavioral Summary**: Verify `fiberSleepYield` cooperative coroutine `Ready -> Running -> Suspended -> Completed` state transitions and `FiberScheduler` round-robin execution. Concrete nominal inputs: `f: Fiber = Fiber(id = 1)`, `ticks: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.thread.fiber_z11_test
import * from "std/thread/fiber"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fiber_fiberSleepYield_11(): int:
  let arg_f = Fiber(id = 1, state = 0, stepCount = 4, maxSteps = 4, resultVal = 2, sleepTicks = 4)
  let edge_f = Fiber(id = 0, state = 0, stepCount = 1, maxSteps = 1, resultVal = 0, sleepTicks = 1)
  let arg_ticks = 4
  let edge_ticks = 1
  fiberSleepYield(arg_f, arg_ticks)
  fiberSleepYield(edge_f, edge_ticks)
  assertEqInt(arg_f.id, 1, "fiberSleepYield nominal arg_f.id == 1")
  assertEqInt(edge_f.id, 0, "fiberSleepYield boundary edge_f.id == 0")
  ret 0
```

---

### `jobSystemNew` (`std/thread/job_system.aipl`)

- **Signature**: `pub fn jobSystemNew(workers: int): JobSystem:`
- **Import**: `import * from "std/thread/job_system"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `workers: int` | **Returns**: `JobSystem`
- **Unit Test**: `tests/functions/thread/job_system_test.aipl` | **Example**: `examples/ex_117_thread_local_context_propagation_cli.aipl`
- **Behavioral Summary**: Verify `jobSystemNew` priority job submission, diamond dependency DAG topological ordering (`jobDependsOn`), work-stealing execution, and `parallelFor`/`parallelReduce`. Concrete nominal inputs: `workers: int = 1`; exercises core body path returning/computing `JobSystem(`.

```aipl
module tests.functions.thread.job_system_z1_test
import * from "std/thread/job_system"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_job_system_jobSystemNew_1(): int:
  let arg_workers = 4
  let edge_workers = 1
  let resNom = jobSystemNew(arg_workers)
  let resEdge = jobSystemNew(edge_workers)
  assertEqInt(resNom.workerCount, 4, "jobSystemNew nominal resNom.workerCount == 4")
  assertEqInt(resEdge.workerCount, 1, "jobSystemNew boundary resEdge.workerCount == 1")
  ret 0
```

---

### `jobSystemShutdown` (`std/thread/job_system.aipl`)

- **Signature**: `pub fn jobSystemShutdown(mut js: JobSystem): void:`
- **Import**: `import * from "std/thread/job_system"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut js: JobSystem` | **Returns**: `void`
- **Unit Test**: `tests/functions/thread/job_system_test.aipl` | **Example**: `examples/ex_115_thread_job_system_work_stealing_cli.aipl`
- **Behavioral Summary**: Verify `jobSystemShutdown` priority job submission, diamond dependency DAG topological ordering (`jobDependsOn`), work-stealing execution, and `parallelFor`/`parallelReduce`. Concrete nominal inputs: `js: JobSystem = JobSystem(workerCount = 64)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.thread.job_system_z2_test
import * from "std/thread/job_system"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_job_system_jobSystemShutdown_2(): int:
  let arg_js = JobSystem(workerCount = 4, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 4, isRunning = true, nextJobId = 4)
  let edge_js = JobSystem(workerCount = 1, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 1, isRunning = false, nextJobId = 1)
  jobSystemShutdown(arg_js)
  jobSystemShutdown(edge_js)
  assert(arg_js.isRunning == false, "jobSystemShutdown nominal arg_js.isRunning == false")
  assert(edge_js.isRunning == false, "jobSystemShutdown boundary edge_js.isRunning == false")
  ret 0
```

---

### `jobSystemWorkerCount` (`std/thread/job_system.aipl`)

- **Signature**: `pub fn jobSystemWorkerCount(js: JobSystem): int:`
- **Import**: `import * from "std/thread/job_system"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `js: JobSystem` | **Returns**: `int`
- **Unit Test**: `tests/functions/thread/job_system_test.aipl` | **Example**: `examples/ex_116_thread_fiber_cooperative_coroutines_cli.aipl`
- **Behavioral Summary**: Verify `jobSystemWorkerCount` priority job submission, diamond dependency DAG topological ordering (`jobDependsOn`), work-stealing execution, and `parallelFor`/`parallelReduce`. Concrete nominal inputs: `js: JobSystem = JobSystem(workerCount = 64)`; exercises core body path returning/computing `js.workerCount`.

```aipl
module tests.functions.thread.job_system_z3_test
import * from "std/thread/job_system"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_job_system_jobSystemWorkerCount_3(): int:
  let arg_js = JobSystem(workerCount = 4, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 4, isRunning = true, nextJobId = 4)
  let edge_js = JobSystem(workerCount = 1, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 1, isRunning = false, nextJobId = 1)
  let resNom = jobSystemWorkerCount(arg_js)
  let resEdge = jobSystemWorkerCount(edge_js)
  assertEqInt(resNom, 4, "jobSystemWorkerCount nominal resNom == 4")
  assertEqInt(resEdge, 1, "jobSystemWorkerCount boundary resEdge == 1")
  ret 0
```

---

### `jobSubmitWithPriority` (`std/thread/job_system.aipl`)

- **Signature**: `pub fn jobSubmitWithPriority(mut js: JobSystem, inputVal: int, priority: int): JobHandle:`
- **Import**: `import * from "std/thread/job_system"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut js: JobSystem, inputVal: int, priority: int` | **Returns**: `JobHandle`
- **Unit Test**: `tests/functions/thread/job_system_test.aipl` | **Example**: `examples/ex_117_thread_local_context_propagation_cli.aipl`
- **Behavioral Summary**: Verify `jobSubmitWithPriority` priority job submission, diamond dependency DAG topological ordering (`jobDependsOn`), work-stealing execution, and `parallelFor`/`parallelReduce`. Concrete nominal inputs: `js: JobSystem = JobSystem(workerCount = 64)`, `inputVal: int = 1`, `priority: int = 1`; exercises core body path returning/computing `h`.

```aipl
module tests.functions.thread.job_system_z4_test
import * from "std/thread/job_system"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_job_system_jobSubmitWithPriority_4(): int:
  let arg_js = JobSystem(workerCount = 4, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 4, isRunning = true, nextJobId = 4)
  let edge_js = JobSystem(workerCount = 1, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 1, isRunning = false, nextJobId = 1)
  let arg_inputVal = 4
  let edge_inputVal = 1
  let arg_priority = 1
  let edge_priority = 0
  let resNom = jobSubmitWithPriority(arg_js, arg_inputVal, arg_priority)
  let resEdge = jobSubmitWithPriority(edge_js, edge_inputVal, edge_priority)
  assertEqInt(resNom.jobId, 4, "jobSubmitWithPriority nominal resNom.jobId == 4")
  assertEqInt(resEdge.jobId, 1, "jobSubmitWithPriority boundary resEdge.jobId == 1")
  ret 0
```

---

### `jobSubmit` (`std/thread/job_system.aipl`)

- **Signature**: `pub fn jobSubmit(mut js: JobSystem, inputVal: int): JobHandle:`
- **Import**: `import * from "std/thread/job_system"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut js: JobSystem, inputVal: int` | **Returns**: `JobHandle`
- **Unit Test**: `tests/functions/thread/job_system_test.aipl` | **Example**: `examples/ex_115_thread_job_system_work_stealing_cli.aipl`
- **Behavioral Summary**: Verify `jobSubmit` priority job submission, diamond dependency DAG topological ordering (`jobDependsOn`), work-stealing execution, and `parallelFor`/`parallelReduce`. Concrete nominal inputs: `js: JobSystem = JobSystem(workerCount = 64)`, `inputVal: int = 1`; exercises core body path returning/computing `jobSubmitWithPriority(js, inputVal, 1)`.

```aipl
module tests.functions.thread.job_system_z5_test
import * from "std/thread/job_system"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_job_system_jobSubmit_5(): int:
  let arg_js = JobSystem(workerCount = 4, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 4, isRunning = true, nextJobId = 4)
  let edge_js = JobSystem(workerCount = 1, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 1, isRunning = false, nextJobId = 1)
  let arg_inputVal = 4
  let edge_inputVal = 1
  let resNom = jobSubmit(arg_js, arg_inputVal)
  let resEdge = jobSubmit(edge_js, edge_inputVal)
  assertEqInt(resNom.jobId, 4, "jobSubmit nominal resNom.jobId == 4")
  assertEqInt(resEdge.jobId, 1, "jobSubmit boundary resEdge.jobId == 1")
  ret 0
```

---

### `findJobIdx` (`std/thread/job_system.aipl`)

- **Signature**: `fn findJobIdx(jobs: [JobHandle], jobId: int): int:`
- **Import**: `import * from "std/thread/job_system"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `jobs: [JobHandle], jobId: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/thread/job_system_test.aipl` | **Example**: `examples/ex_116_thread_fiber_cooperative_coroutines_cli.aipl`
- **Behavioral Summary**: Verify `findJobIdx` priority job submission, diamond dependency DAG topological ordering (`jobDependsOn`), work-stealing execution, and `parallelFor`/`parallelReduce`. Concrete nominal inputs: `jobs: [JobHandle] = [JobHandle(jobId = 1, priority = 1)]`, `jobId: int = 1`; exercises core body path returning/computing `-1`.

```aipl
module tests.functions.thread.job_system_z6_test
import * from "std/thread/job_system"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_job_system_findJobIdx_6(): int:
  let arg_jobs = [JobHandle(jobId = 4, priority = 1, status = 2, result = 2)]
  let edge_jobs = []
  let arg_jobId = 4
  let edge_jobId = 1
  let resNom = findJobIdx(arg_jobs, arg_jobId)
  let resEdge = findJobIdx(edge_jobs, edge_jobId)
  assertEqInt(resNom, 0, "findJobIdx nominal resNom == 0")
  assertEqInt(resEdge, -1, "findJobIdx boundary resEdge == -1")
  ret 0
```

---

### `findDagIdx` (`std/thread/job_system.aipl`)

- **Signature**: `fn findDagIdx(nodes: [JobDagNode], jobId: int): int:`
- **Import**: `import * from "std/thread/job_system"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `nodes: [JobDagNode], jobId: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/thread/job_system_test.aipl` | **Example**: `examples/ex_117_thread_local_context_propagation_cli.aipl`
- **Behavioral Summary**: Verify `findDagIdx` priority job submission, diamond dependency DAG topological ordering (`jobDependsOn`), work-stealing execution, and `parallelFor`/`parallelReduce`. Concrete nominal inputs: `nodes: [JobDagNode] = [JobDagNode(jobId = 1)]`, `jobId: int = 1`; exercises core body path returning/computing `-1`.

```aipl
module tests.functions.thread.job_system_z7_test
import * from "std/thread/job_system"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_job_system_findDagIdx_7(): int:
  let arg_nodes = [JobDagNode(jobId = 4, dependencies = [], dependents = [], satisfiedCount = 4)]
  let edge_nodes = []
  let arg_jobId = 4
  let edge_jobId = 1
  let resNom = findDagIdx(arg_nodes, arg_jobId)
  let resEdge = findDagIdx(edge_nodes, edge_jobId)
  assertEqInt(resNom, 0, "findDagIdx nominal resNom == 0")
  assertEqInt(resEdge, -1, "findDagIdx boundary resEdge == -1")
  ret 0
```

---

### `jobDependsOn` (`std/thread/job_system.aipl`)

- **Signature**: `pub fn jobDependsOn(mut js: JobSystem, childJob: JobHandle, parentJob: JobHandle): bool:`
- **Import**: `import * from "std/thread/job_system"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut js: JobSystem, childJob: JobHandle, parentJob: JobHandle` | **Returns**: `bool`
- **Unit Test**: `tests/functions/thread/job_system_test.aipl` | **Example**: `examples/ex_115_thread_job_system_work_stealing_cli.aipl`
- **Behavioral Summary**: Verify `jobDependsOn` priority job submission, diamond dependency DAG topological ordering (`jobDependsOn`), work-stealing execution, and `parallelFor`/`parallelReduce`. Concrete nominal inputs: `js: JobSystem = JobSystem(workerCount = 64)`, `childJob: JobHandle = JobHandle(jobId = 1, priority = 1)`, `parentJob: JobHandle = JobHandle(jobId = 1, priority = 1)`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.thread.job_system_z8_test
import * from "std/thread/job_system"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_job_system_jobDependsOn_8(): int:
  let arg_js = JobSystem(workerCount = 4, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 4, isRunning = true, nextJobId = 4)
  let edge_js = JobSystem(workerCount = 1, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 1, isRunning = false, nextJobId = 1)
  let arg_childJob = JobHandle(jobId = 4, priority = 1, status = 2, result = 2)
  let edge_childJob = JobHandle(jobId = 1, priority = 0, status = 0, result = 0)
  let arg_parentJob = JobHandle(jobId = 4, priority = 1, status = 2, result = 2)
  let edge_parentJob = JobHandle(jobId = 1, priority = 0, status = 0, result = 0)
  let resNom = jobDependsOn(arg_js, arg_childJob, arg_parentJob)
  let resEdge = jobDependsOn(edge_js, edge_childJob, edge_parentJob)
  assert(resNom == false, "jobDependsOn nominal resNom == false")
  assert(resEdge == false, "jobDependsOn boundary resEdge == false")
  ret 0
```

---

### `jobWait` (`std/thread/job_system.aipl`)

- **Signature**: `pub fn jobWait(mut js: JobSystem, handle: JobHandle): int:`
- **Import**: `import * from "std/thread/job_system"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut js: JobSystem, handle: JobHandle` | **Returns**: `int`
- **Unit Test**: `tests/functions/thread/job_system_test.aipl` | **Example**: `examples/ex_116_thread_fiber_cooperative_coroutines_cli.aipl`
- **Behavioral Summary**: Verify `jobWait` priority job submission, diamond dependency DAG topological ordering (`jobDependsOn`), work-stealing execution, and `parallelFor`/`parallelReduce`. Concrete nominal inputs: `js: JobSystem = JobSystem(workerCount = 64)`, `handle: JobHandle = JobHandle(jobId = 1, priority = 1)`; exercises core body path returning/computing `handle.result`.

```aipl
module tests.functions.thread.job_system_z9_test
import * from "std/thread/job_system"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_job_system_jobWait_9(): int:
  let arg_js = JobSystem(workerCount = 4, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 4, isRunning = true, nextJobId = 4)
  let edge_js = JobSystem(workerCount = 1, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 1, isRunning = false, nextJobId = 1)
  let arg_handle = JobHandle(jobId = 4, priority = 1, status = 2, result = 2)
  let edge_handle = JobHandle(jobId = 1, priority = 0, status = 0, result = 0)
  let resNom = jobWait(arg_js, arg_handle)
  let resEdge = jobWait(edge_js, edge_handle)
  assertEqInt(resNom, 2, "jobWait nominal resNom == 2")
  assertEqInt(resEdge, 0, "jobWait boundary resEdge == 0")
  ret 0
```

---

### `jobWaitAll` (`std/thread/job_system.aipl`)

- **Signature**: `pub fn jobWaitAll(mut js: JobSystem, handles: [JobHandle]): [int]:`
- **Import**: `import * from "std/thread/job_system"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut js: JobSystem, handles: [JobHandle]` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/thread/job_system_test.aipl` | **Example**: `examples/ex_117_thread_local_context_propagation_cli.aipl`
- **Behavioral Summary**: Verify `jobWaitAll` priority job submission, diamond dependency DAG topological ordering (`jobDependsOn`), work-stealing execution, and `parallelFor`/`parallelReduce`. Concrete nominal inputs: `js: JobSystem = JobSystem(workerCount = 64)`, `handles: [JobHandle] = [JobHandle(jobId = 1, priority = 1)]`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.thread.job_system_z10_test
import * from "std/thread/job_system"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_job_system_jobWaitAll_10(): int:
  let arg_js = JobSystem(workerCount = 4, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 4, isRunning = true, nextJobId = 4)
  let edge_js = JobSystem(workerCount = 1, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 1, isRunning = false, nextJobId = 1)
  let arg_handles = [JobHandle(jobId = 4, priority = 1, status = 2, result = 2)]
  let edge_handles = []
  let resNom = jobWaitAll(arg_js, arg_handles)
  let resEdge = jobWaitAll(edge_js, edge_handles)
  assertEqInt(resNom.len(), 1, "jobWaitAll nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "jobWaitAll boundary resEdge.len() == 0")
  ret 0
```

---

### `jobIsComplete` (`std/thread/job_system.aipl`)

- **Signature**: `pub fn jobIsComplete(js: JobSystem, handle: JobHandle): bool:`
- **Import**: `import * from "std/thread/job_system"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `js: JobSystem, handle: JobHandle` | **Returns**: `bool`
- **Unit Test**: `tests/functions/thread/job_system_test.aipl` | **Example**: `examples/ex_115_thread_job_system_work_stealing_cli.aipl`
- **Behavioral Summary**: Verify `jobIsComplete` priority job submission, diamond dependency DAG topological ordering (`jobDependsOn`), work-stealing execution, and `parallelFor`/`parallelReduce`. Concrete nominal inputs: `js: JobSystem = JobSystem(workerCount = 64)`, `handle: JobHandle = JobHandle(jobId = 1, priority = 1)`; exercises core body path returning/computing `handle.status == 2`.

```aipl
module tests.functions.thread.job_system_z11_test
import * from "std/thread/job_system"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_job_system_jobIsComplete_11(): int:
  let arg_js = JobSystem(workerCount = 4, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 4, isRunning = true, nextJobId = 4)
  let edge_js = JobSystem(workerCount = 1, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 1, isRunning = false, nextJobId = 1)
  let arg_handle = JobHandle(jobId = 4, priority = 1, status = 2, result = 2)
  let edge_handle = JobHandle(jobId = 1, priority = 0, status = 0, result = 0)
  let resNom = jobIsComplete(arg_js, arg_handle)
  let resEdge = jobIsComplete(edge_js, edge_handle)
  assert(resNom == true, "jobIsComplete nominal resNom == true")
  assert(resEdge == false, "jobIsComplete boundary resEdge == false")
  ret 0
```

---

### `jobGetResult` (`std/thread/job_system.aipl`)

- **Signature**: `pub fn jobGetResult(js: JobSystem, handle: JobHandle): Option[int]:`
- **Import**: `import * from "std/thread/job_system"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `js: JobSystem, handle: JobHandle` | **Returns**: `Option[int]`
- **Unit Test**: `tests/functions/thread/job_system_test.aipl` | **Example**: `examples/ex_116_thread_fiber_cooperative_coroutines_cli.aipl`
- **Behavioral Summary**: Verify `jobGetResult` priority job submission, diamond dependency DAG topological ordering (`jobDependsOn`), work-stealing execution, and `parallelFor`/`parallelReduce`. Concrete nominal inputs: `js: JobSystem = JobSystem(workerCount = 64)`, `handle: JobHandle = JobHandle(jobId = 1, priority = 1)`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.thread.job_system_z12_test
import * from "std/thread/job_system"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_job_system_jobGetResult_12(): int:
  let arg_js = JobSystem(workerCount = 4, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 4, isRunning = true, nextJobId = 4)
  let edge_js = JobSystem(workerCount = 1, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 1, isRunning = false, nextJobId = 1)
  let arg_handle = JobHandle(jobId = 4, priority = 1, status = 2, result = 2)
  let edge_handle = JobHandle(jobId = 1, priority = 0, status = 0, result = 0)
  let resNom = jobGetResult(arg_js, arg_handle)
  let resEdge = jobGetResult(edge_js, edge_handle)
  assert(resNom.isSome() == false, "jobGetResult nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "jobGetResult boundary resEdge.isSome() == false")
  ret 0
```

---

### `parallelFor` (`std/thread/job_system.aipl`)

- **Signature**: `pub fn parallelFor(mut js: JobSystem, startIdx: int, endIdx: int, chunkSize: int): [int]:`
- **Import**: `import * from "std/thread/job_system"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut js: JobSystem, startIdx: int, endIdx: int, chunkSize: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/thread/job_system_test.aipl` | **Example**: `examples/ex_117_thread_local_context_propagation_cli.aipl`
- **Behavioral Summary**: Verify `parallelFor` priority job submission, diamond dependency DAG topological ordering (`jobDependsOn`), work-stealing execution, and `parallelFor`/`parallelReduce`. Concrete nominal inputs: `js: JobSystem = JobSystem(workerCount = 64)`, `startIdx: int = 0`, `endIdx: int = 0`, `chunkSize: int = 64`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.thread.job_system_z13_test
import * from "std/thread/job_system"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_job_system_parallelFor_13(): int:
  let arg_js = JobSystem(workerCount = 4, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 4, isRunning = true, nextJobId = 4)
  let edge_js = JobSystem(workerCount = 1, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 1, isRunning = false, nextJobId = 1)
  let arg_startIdx = 1
  let edge_startIdx = 0
  let arg_endIdx = 4
  let edge_endIdx = 1
  let arg_chunkSize = 4
  let edge_chunkSize = 1
  let resNom = parallelFor(arg_js, arg_startIdx, arg_endIdx, arg_chunkSize)
  let resEdge = parallelFor(edge_js, edge_startIdx, edge_endIdx, edge_chunkSize)
  assertEqInt(resNom.len(), 3, "parallelFor nominal resNom.len() == 3")
  assertEqInt(resEdge.len(), 1, "parallelFor boundary resEdge.len() == 1")
  ret 0
```

---

### `parallelReduce` (`std/thread/job_system.aipl`)

- **Signature**: `pub fn parallelReduce(mut js: JobSystem, numbers: [int], opKind: int): int:`
- **Import**: `import * from "std/thread/job_system"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut js: JobSystem, numbers: [int], opKind: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/thread/job_system_test.aipl` | **Example**: `examples/ex_115_thread_job_system_work_stealing_cli.aipl`
- **Behavioral Summary**: Verify `parallelReduce` priority job submission, diamond dependency DAG topological ordering (`jobDependsOn`), work-stealing execution, and `parallelFor`/`parallelReduce`. Concrete nominal inputs: `js: JobSystem = JobSystem(workerCount = 64)`, `numbers: [int] = [1]`, `opKind: int = 1`; exercises core body path returning/computing `acc`.

```aipl
module tests.functions.thread.job_system_z14_test
import * from "std/thread/job_system"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_job_system_parallelReduce_14(): int:
  let arg_js = JobSystem(workerCount = 4, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 4, isRunning = true, nextJobId = 4)
  let edge_js = JobSystem(workerCount = 1, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 1, isRunning = false, nextJobId = 1)
  let arg_numbers = [4]
  let edge_numbers = []
  let arg_opKind = 4
  let edge_opKind = 1
  let resNom = parallelReduce(arg_js, arg_numbers, arg_opKind)
  let resEdge = parallelReduce(edge_js, edge_numbers, edge_opKind)
  assertEqInt(resNom, 4, "parallelReduce nominal resNom == 4")
  assertEqInt(resEdge, 0, "parallelReduce boundary resEdge == 0")
  ret 0
```

---

### `jobSystemExecuteStealing` (`std/thread/job_system.aipl`)

- **Signature**: `pub fn jobSystemExecuteStealing(mut js: JobSystem): int:`
- **Import**: `import * from "std/thread/job_system"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut js: JobSystem` | **Returns**: `int`
- **Unit Test**: `tests/functions/thread/job_system_test.aipl` | **Example**: `examples/ex_116_thread_fiber_cooperative_coroutines_cli.aipl`
- **Behavioral Summary**: Verify `jobSystemExecuteStealing` priority job submission, diamond dependency DAG topological ordering (`jobDependsOn`), work-stealing execution, and `parallelFor`/`parallelReduce`. Concrete nominal inputs: `js: JobSystem = JobSystem(workerCount = 64)`; exercises core body path returning/computing `stolen`.

```aipl
module tests.functions.thread.job_system_z15_test
import * from "std/thread/job_system"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_job_system_jobSystemExecuteStealing_15(): int:
  let arg_js = JobSystem(workerCount = 4, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 4, isRunning = true, nextJobId = 4)
  let edge_js = JobSystem(workerCount = 1, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 1, isRunning = false, nextJobId = 1)
  let resNom = jobSystemExecuteStealing(arg_js)
  let resEdge = jobSystemExecuteStealing(edge_js)
  assertEqInt(resNom, 0, "jobSystemExecuteStealing nominal resNom == 0")
  assertEqInt(resEdge, 0, "jobSystemExecuteStealing boundary resEdge == 0")
  ret 0
```

---

### `jobSystemStats` (`std/thread/job_system.aipl`)

- **Signature**: `pub fn jobSystemStats(js: JobSystem): [int]:`
- **Import**: `import * from "std/thread/job_system"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `js: JobSystem` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/thread/job_system_test.aipl` | **Example**: `examples/ex_117_thread_local_context_propagation_cli.aipl`
- **Behavioral Summary**: Verify `jobSystemStats` priority job submission, diamond dependency DAG topological ordering (`jobDependsOn`), work-stealing execution, and `parallelFor`/`parallelReduce`. Concrete nominal inputs: `js: JobSystem = JobSystem(workerCount = 64)`; exercises core body path returning/computing `[submitted, submitted, js.stolenCount]`.

```aipl
module tests.functions.thread.job_system_z16_test
import * from "std/thread/job_system"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_job_system_jobSystemStats_16(): int:
  let arg_js = JobSystem(workerCount = 4, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 4, isRunning = true, nextJobId = 4)
  let edge_js = JobSystem(workerCount = 1, workerQueues = [], dagNodes = [], completedJobs = [], stolenCount = 1, isRunning = false, nextJobId = 1)
  let resNom = jobSystemStats(arg_js)
  let resEdge = jobSystemStats(edge_js)
  assertEqInt(resNom.len(), 3, "jobSystemStats nominal resNom.len() == 3")
  assertEqInt(resEdge.len(), 3, "jobSystemStats boundary resEdge.len() == 3")
  ret 0
```

---

### `threadSpawnWithConfig` (`std/thread/thread_local.aipl`)

- **Signature**: `pub fn threadSpawnWithConfig(config: ThreadConfig, workerFnId: int, payload: int): Result[ThreadHandle, str]:`
- **Import**: `import * from "std/thread/thread_local"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `config: ThreadConfig, workerFnId: int, payload: int` | **Returns**: `Result[ThreadHandle, str]`
- **Unit Test**: `tests/functions/thread/thread_local_test.aipl` | **Example**: `examples/ex_115_thread_job_system_work_stealing_cli.aipl`
- **Behavioral Summary**: Verify `threadSpawnWithConfig` OS/virtual thread spawn/join lifecycle and isolated per-thread `ThreadLocal` slot storage across distinct thread IDs. Concrete nominal inputs: `config: ThreadConfig = ThreadConfig(name = "aipl_test", stackSizeBytes = 64)`, `workerFnId: int = 1`, `payload: int = 1`; exercises core body path returning/computing `Ok(ThreadHandle(`.

```aipl
module tests.functions.thread.thread_local_z1_test
import * from "std/thread/thread_local"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_thread_local_threadSpawnWithConfig_1(): int:
  let arg_config = ThreadConfig(name = "test", stackSizeBytes = 4)
  let edge_config = ThreadConfig(name = "a", stackSizeBytes = 1)
  let arg_workerFnId = 4
  let edge_workerFnId = 1
  let arg_payload = 1
  let edge_payload = 0
  let resNom = threadSpawnWithConfig(arg_config, arg_workerFnId, arg_payload)
  let resEdge = threadSpawnWithConfig(edge_config, edge_workerFnId, edge_payload)
  assert(resNom.isOk() == true, "threadSpawnWithConfig nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "threadSpawnWithConfig boundary resEdge.isOk() == true")
  ret 0
```

---

### `threadSpawn` (`std/thread/thread_local.aipl`)

- **Signature**: `pub fn threadSpawn(workerFnId: int, payload: int): Result[ThreadHandle, str]:`
- **Import**: `import * from "std/thread/thread_local"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `workerFnId: int, payload: int` | **Returns**: `Result[ThreadHandle, str]`
- **Unit Test**: `tests/functions/thread/thread_local_test.aipl` | **Example**: `examples/ex_116_thread_fiber_cooperative_coroutines_cli.aipl`
- **Behavioral Summary**: Verify `threadSpawn` OS/virtual thread spawn/join lifecycle and isolated per-thread `ThreadLocal` slot storage across distinct thread IDs. Concrete nominal inputs: `workerFnId: int = 1`, `payload: int = 1`; exercises core body path returning/computing `threadSpawnWithConfig(cfg, workerFnId, payload)`.

```aipl
module tests.functions.thread.thread_local_z2_test
import * from "std/thread/thread_local"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_thread_local_threadSpawn_2(): int:
  let arg_workerFnId = 4
  let edge_workerFnId = 1
  let arg_payload = 1
  let edge_payload = 0
  let resNom = threadSpawn(arg_workerFnId, arg_payload)
  let resEdge = threadSpawn(edge_workerFnId, edge_payload)
  assert(resNom.isOk() == true, "threadSpawn nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "threadSpawn boundary resEdge.isOk() == true")
  ret 0
```

---

### `threadJoin` (`std/thread/thread_local.aipl`)

- **Signature**: `pub fn threadJoin(mut handle: ThreadHandle): Result[int, str]:`
- **Import**: `import * from "std/thread/thread_local"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut handle: ThreadHandle` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/thread/thread_local_test.aipl` | **Example**: `examples/ex_117_thread_local_context_propagation_cli.aipl`
- **Behavioral Summary**: Verify `threadJoin` OS/virtual thread spawn/join lifecycle and isolated per-thread `ThreadLocal` slot storage across distinct thread IDs. Concrete nominal inputs: `handle: ThreadHandle = ThreadHandle(id = 1, name = "aipl_test", payloadResult = int = 0())`; exercises core body path returning/computing `Ok(handle.payloadResult)`.

```aipl
module tests.functions.thread.thread_local_z3_test
import * from "std/thread/thread_local"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_thread_local_threadJoin_3(): int:
  let arg_handle = ThreadHandle(id = 1, name = "test", isFinished = true, payloadResult = 1)
  let edge_handle = ThreadHandle(id = 0, name = "a", isFinished = false, payloadResult = 0)
  let resNom = threadJoin(arg_handle)
  let resEdge = threadJoin(edge_handle)
  assert(resNom.isOk() == true, "threadJoin nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "threadJoin boundary resEdge.isOk() == true")
  ret 0
```

---

### `threadYield` (`std/thread/thread_local.aipl`)

- **Signature**: `pub fn threadYield(): void:`
- **Import**: `import * from "std/thread/thread_local"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/thread/thread_local_test.aipl` | **Example**: `examples/ex_115_thread_job_system_work_stealing_cli.aipl`
- **Behavioral Summary**: Verify `threadYield` OS/virtual thread spawn/join lifecycle and isolated per-thread `ThreadLocal` slot storage across distinct thread IDs. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.thread.thread_local_z4_test
import * from "std/thread/thread_local"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_thread_local_threadYield_4(): int:
  mut completedCalls = 0
  threadYield()
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "threadYield nominal and boundary void calls completed")
  ret 0
```

---

### `threadSleepMs` (`std/thread/thread_local.aipl`)

- **Signature**: `pub fn threadSleepMs(ms: int): void:`
- **Import**: `import * from "std/thread/thread_local"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ms: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/thread/thread_local_test.aipl` | **Example**: `examples/ex_116_thread_fiber_cooperative_coroutines_cli.aipl`
- **Behavioral Summary**: Verify `threadSleepMs` OS/virtual thread spawn/join lifecycle and isolated per-thread `ThreadLocal` slot storage across distinct thread IDs. Concrete nominal inputs: `ms: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.thread.thread_local_z5_test
import * from "std/thread/thread_local"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_thread_local_threadSleepMs_5(): int:
  mut completedCalls = 0
  let arg_ms = 4
  let edge_ms = 1
  threadSleepMs(arg_ms)
  threadSleepMs(edge_ms)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "threadSleepMs nominal and boundary void calls completed")
  ret 0
```

---

### `threadCurrentId` (`std/thread/thread_local.aipl`)

- **Signature**: `pub fn threadCurrentId(): int:`
- **Import**: `import * from "std/thread/thread_local"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/thread/thread_local_test.aipl` | **Example**: `examples/ex_117_thread_local_context_propagation_cli.aipl`
- **Behavioral Summary**: Verify `threadCurrentId` OS/virtual thread spawn/join lifecycle and isolated per-thread `ThreadLocal` slot storage across distinct thread IDs. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `1`.

```aipl
module tests.functions.thread.thread_local_z6_test
import * from "std/thread/thread_local"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_thread_local_threadCurrentId_6(): int:
  let resNom = threadCurrentId()
  let resEdge = threadCurrentId()
  assertEqInt(resNom, 1, "threadCurrentId nominal resNom == 1")
  assertEqInt(resEdge, 1, "threadCurrentId boundary resEdge == 1")
  ret 0
```

---

### `threadHardwareConcurrency` (`std/thread/thread_local.aipl`)

- **Signature**: `pub fn threadHardwareConcurrency(): int:`
- **Import**: `import * from "std/thread/thread_local"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/thread/thread_local_test.aipl` | **Example**: `examples/ex_115_thread_job_system_work_stealing_cli.aipl`
- **Behavioral Summary**: Verify `threadHardwareConcurrency` OS/virtual thread spawn/join lifecycle and isolated per-thread `ThreadLocal` slot storage across distinct thread IDs. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `1`.

```aipl
module tests.functions.thread.thread_local_z7_test
import * from "std/thread/thread_local"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_thread_local_threadHardwareConcurrency_7(): int:
  let resNom = threadHardwareConcurrency()
  let resEdge = threadHardwareConcurrency()
  assertEqInt(resNom, 14, "threadHardwareConcurrency nominal resNom == 14")
  assertEqInt(resEdge, 14, "threadHardwareConcurrency boundary resEdge == 14")
  ret 0
```

---

### `threadLocalNew` (`std/thread/thread_local.aipl`)

- **Signature**: `pub fn threadLocalNew(initialVal: int): ThreadLocal:`
- **Import**: `import * from "std/thread/thread_local"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `initialVal: int` | **Returns**: `ThreadLocal`
- **Unit Test**: `tests/functions/thread/thread_local_test.aipl` | **Example**: `examples/ex_116_thread_fiber_cooperative_coroutines_cli.aipl`
- **Behavioral Summary**: Verify `threadLocalNew` OS/virtual thread spawn/join lifecycle and isolated per-thread `ThreadLocal` slot storage across distinct thread IDs. Concrete nominal inputs: `initialVal: int = 1`; exercises core body path returning/computing `ThreadLocal(slotIndex: 0, values: [initialVal])`.

```aipl
module tests.functions.thread.thread_local_z8_test
import * from "std/thread/thread_local"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_thread_local_threadLocalNew_8(): int:
  let arg_initialVal = 4
  let edge_initialVal = 1
  let resNom = threadLocalNew(arg_initialVal)
  let resEdge = threadLocalNew(edge_initialVal)
  assertEqInt(resNom.slotIndex, 0, "threadLocalNew nominal resNom.slotIndex == 0")
  assertEqInt(resEdge.slotIndex, 0, "threadLocalNew boundary resEdge.slotIndex == 0")
  ret 0
```

---

### `threadLocalGet` (`std/thread/thread_local.aipl`)

- **Signature**: `pub fn threadLocalGet(tl: ThreadLocal): int:`
- **Import**: `import * from "std/thread/thread_local"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `tl: ThreadLocal` | **Returns**: `int`
- **Unit Test**: `tests/functions/thread/thread_local_test.aipl` | **Example**: `examples/ex_117_thread_local_context_propagation_cli.aipl`
- **Behavioral Summary**: Verify `threadLocalGet` OS/virtual thread spawn/join lifecycle and isolated per-thread `ThreadLocal` slot storage across distinct thread IDs. Concrete nominal inputs: `tl: ThreadLocal = ThreadLocal(slotIndex = 0)`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.thread.thread_local_z9_test
import * from "std/thread/thread_local"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_thread_local_threadLocalGet_9(): int:
  let arg_tl = ThreadLocal(slotIndex = 4, values = [])
  let edge_tl = ThreadLocal(slotIndex = 1, values = [])
  let resNom = threadLocalGet(arg_tl)
  let resEdge = threadLocalGet(edge_tl)
  assertEqInt(resNom, 0, "threadLocalGet nominal resNom == 0")
  assertEqInt(resEdge, 0, "threadLocalGet boundary resEdge == 0")
  ret 0
```

---

### `threadLocalSet` (`std/thread/thread_local.aipl`)

- **Signature**: `pub fn threadLocalSet(mut tl: ThreadLocal, val: int): void:`
- **Import**: `import * from "std/thread/thread_local"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut tl: ThreadLocal, val: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/thread/thread_local_test.aipl` | **Example**: `examples/ex_115_thread_job_system_work_stealing_cli.aipl`
- **Behavioral Summary**: Verify `threadLocalSet` OS/virtual thread spawn/join lifecycle and isolated per-thread `ThreadLocal` slot storage across distinct thread IDs. Concrete nominal inputs: `tl: ThreadLocal = ThreadLocal(slotIndex = 0)`, `val: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.thread.thread_local_z10_test
import * from "std/thread/thread_local"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_thread_local_threadLocalSet_10(): int:
  let arg_tl = ThreadLocal(slotIndex = 4, values = [])
  let edge_tl = ThreadLocal(slotIndex = 1, values = [])
  let arg_val = 2
  let edge_val = 0
  threadLocalSet(arg_tl, arg_val)
  threadLocalSet(edge_tl, edge_val)
  assertEqInt(arg_tl.values.len(), 1, "threadLocalSet nominal arg_tl.values.len() == 1")
  assertEqInt(edge_tl.values.len(), 1, "threadLocalSet boundary edge_tl.values.len() == 1")
  ret 0
```

---

### `threadLocalClear` (`std/thread/thread_local.aipl`)

- **Signature**: `pub fn threadLocalClear(mut tl: ThreadLocal): void:`
- **Import**: `import * from "std/thread/thread_local"` (or barrel `import * from "std/thread/thread_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut tl: ThreadLocal` | **Returns**: `void`
- **Unit Test**: `tests/functions/thread/thread_local_test.aipl` | **Example**: `examples/ex_116_thread_fiber_cooperative_coroutines_cli.aipl`
- **Behavioral Summary**: Verify `threadLocalClear` OS/virtual thread spawn/join lifecycle and isolated per-thread `ThreadLocal` slot storage across distinct thread IDs. Concrete nominal inputs: `tl: ThreadLocal = ThreadLocal(slotIndex = 0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.thread.thread_local_z11_test
import * from "std/thread/thread_local"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_thread_local_threadLocalClear_11(): int:
  let arg_tl = ThreadLocal(slotIndex = 4, values = [])
  let edge_tl = ThreadLocal(slotIndex = 1, values = [])
  threadLocalClear(arg_tl)
  threadLocalClear(edge_tl)
  assertEqInt(arg_tl.slotIndex, 4, "threadLocalClear nominal arg_tl.slotIndex == 4")
  assertEqInt(edge_tl.slotIndex, 1, "threadLocalClear boundary edge_tl.slotIndex == 1")
  ret 0
```
