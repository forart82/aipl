[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](INDEX.md) | [Cookbook](cookbook.md) | [Stdlib Reference](../STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Chapter 12: Testing, Property Fuzzing & Multi-Target Deployment

> **Chapter Summary**: Comprehensive test harness: assert matchers, TAP/JUnit reporting, property-based fuzzing with counterexample shrinking, mock call-spying, capstone game architectures, and native C99, HTML5 Canvas, and WebAssembly deployment pipelines.

## Table of Contents
- [Chapter 12.1: Assertion Matchers, TAP/JUnit Test Suites & Microbenchmarking (std/test/assert, runner, bench)](#chapter-121-assertion-matchers-tapjunit-test-suites--microbenchmarking-stdtestassert-runner-bench)
- [Chapter 12.2: Property-Based Fuzzing, Counterexample Shrinking & Call-Spy Mocking (std/test/fuzz, mock)](#chapter-122-property-based-fuzzing-counterexample-shrinking--call-spy-mocking-stdtestfuzz-mock)
- [Chapter 12.3: Full-Stack Capstone Architectures (Platformer, 3D PBR, Tactical Sim, Synth DAW, Lockstep Netcode)](#chapter-123-full-stack-capstone-architectures-platformer-3d-pbr-tactical-sim-synth-daw-lockstep-netcode)
- [Chapter 12.4: Multi-Target Deployment (Native C99, Single-File HTML5, WASM) & AI Agent Workflows](#chapter-124-multi-target-deployment-native-c99-single-file-html5-wasm--ai-agent-workflows)

---

### Chapter 12.1: Assertion Matchers, TAP/JUnit Test Suites & Microbenchmarking (std/test/assert, runner, bench)

#### 1. Concept in 30 Seconds
Teach `std/test/assert`, `runner`, and `bench` and show how the post-`step_16` `tests/functions/<domain>/<module>_test.aipl` suite is organized.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn testAssert(cond: bool, msg: str = "Assertion failed"): bool:` from `std/test/assert.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.test.assert_z1_test
import * from "std/test/assert"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_assert_testAssert_1(): int:
  let arg_cond = true
  let edge_cond = true
  let arg_msg = "test"
  let edge_msg = "test"
  let resNom = testAssert(arg_cond, arg_msg)
  let resEdge = testAssert(edge_cond, edge_msg)
  assert(resNom == true, "testAssert nominal resNom == true")
  assert(resEdge == true, "testAssert boundary resEdge == true")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_127` | [examples/ex_127_test_assert_matcher_suite_cli.aipl](../../examples/ex_127_test_assert_matcher_suite_cli.aipl) | `tests/examples/ex_127_test_assert_matcher_suite_cli_test.aipl` | `./bin/aipl test tests/examples/ex_127_test_assert_matcher_suite_cli_test.aipl` |
| `ex_128` | [examples/ex_128_test_runner_tap_junit_report_cli.aipl](../../examples/ex_128_test_runner_tap_junit_report_cli.aipl) | `tests/examples/ex_128_test_runner_tap_junit_report_cli_test.aipl` | `./bin/aipl test tests/examples/ex_128_test_runner_tap_junit_report_cli_test.aipl` |
| `ex_129` | [examples/ex_129_test_bench_microbenchmark_cli.aipl](../../examples/ex_129_test_bench_microbenchmark_cli.aipl) | `tests/examples/ex_129_test_bench_microbenchmark_cli_test.aipl` | `./bin/aipl test tests/examples/ex_129_test_bench_microbenchmark_cli_test.aipl` |

---

### Chapter 12.2: Property-Based Fuzzing, Counterexample Shrinking & Call-Spy Mocking (std/test/fuzz, mock)

#### 1. Concept in 30 Seconds
Teach deterministic PRNG fuzzing, minimal counterexample shrinking (`shrinkInt`, `shrinkStr`), and spy verification (`std/test/mock`).

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn createFuzzGenerator(seed: int): FuzzGenerator:` from `std/test/fuzz.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.test.fuzz_z1_test
import * from "std/test/fuzz"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fuzz_createFuzzGenerator_1(): int:
  let arg_seed = 1
  let edge_seed = 0
  let resNom = createFuzzGenerator(arg_seed)
  let resEdge = createFuzzGenerator(edge_seed)
  assertEqInt(resNom.seed, 1, "createFuzzGenerator nominal resNom.seed == 1")
  assertEqInt(resEdge.seed, 0, "createFuzzGenerator boundary resEdge.seed == 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_130` | [examples/ex_130_test_fuzz_and_property_shrinker_cli.aipl](../../examples/ex_130_test_fuzz_and_property_shrinker_cli.aipl) | `tests/examples/ex_130_test_fuzz_and_property_shrinker_cli_test.aipl` | `./bin/aipl test tests/examples/ex_130_test_fuzz_and_property_shrinker_cli_test.aipl` |

---

### Chapter 12.3: Full-Stack Capstone Architectures (Platformer, 3D PBR, Tactical Sim, Synth DAW, Lockstep Netcode)

#### 1. Concept in 30 Seconds
Walk through the 5 capstone applications (`ex_246`..`ex_250`) and their multi-domain stress tests (`tests/complex/sim_01..fuzz_05_*`).

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn spawnEntity(world: EcsWorld): (EcsWorld, EntityId):` from `std/ecs/ecs_world.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.ecs.ecs_world_z2_test
import * from "std/ecs/ecs_world"
import { EntityId, EntityPool, createEntityPool, allocateEntity, recycleEntity, isEntityAlive } from "std/ecs/entity"
import { ArchetypeTable, createArchetypeTable, insertArchetypeRow, swapRemoveArchetypeRow } from "std/ecs/archetype"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ecs_world_spawnEntity_2(): int:
  let arg_world = EcsWorld(entityPool = EntityPool(generations = [], alive = [], freeIndices = []), archetypes = [], locations = [], resources = [])
  let edge_world = EcsWorld(entityPool = EntityPool(generations = [], alive = [], freeIndices = []), archetypes = [], locations = [], resources = [])
  let resNom = spawnEntity(arg_world)
  let resEdge = spawnEntity(edge_world)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0.archetypes.len(), 0, "spawnEntity nominal n_t0.archetypes.len() == 0")
  assertEqInt(e_t0.archetypes.len(), 0, "spawnEntity boundary e_t0.archetypes.len() == 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_246` | [examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl](../../examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl) | `tests/examples/ex_246_mechanics_attribute_modifier_sheet_window_test.aipl` | `./bin/aipl test tests/examples/ex_246_mechanics_attribute_modifier_sheet_window_test.aipl` |
| `ex_247` | [examples/ex_247_mechanics_inventory_spatial_grid_window.aipl](../../examples/ex_247_mechanics_inventory_spatial_grid_window.aipl) | `tests/examples/ex_247_mechanics_inventory_spatial_grid_window_test.aipl` | `./bin/aipl test tests/examples/ex_247_mechanics_inventory_spatial_grid_window_test.aipl` |
| `ex_248` | [examples/ex_248_mechanics_dialogue_dag_quest_journal_window.aipl](../../examples/ex_248_mechanics_dialogue_dag_quest_journal_window.aipl) | `tests/examples/ex_248_mechanics_dialogue_dag_quest_journal_window_test.aipl` | `./bin/aipl test tests/examples/ex_248_mechanics_dialogue_dag_quest_journal_window_test.aipl` |
| `ex_249` | [examples/ex_249_mechanics_economy_crafting_and_market_window.aipl](../../examples/ex_249_mechanics_economy_crafting_and_market_window.aipl) | `tests/examples/ex_249_mechanics_economy_crafting_and_market_window_test.aipl` | `./bin/aipl test tests/examples/ex_249_mechanics_economy_crafting_and_market_window_test.aipl` |
| `ex_250` | [examples/ex_250_mechanics_full_capstone_application_window.aipl](../../examples/ex_250_mechanics_full_capstone_application_window.aipl) | `tests/examples/ex_250_mechanics_full_capstone_application_window_test.aipl` | `./bin/aipl test tests/examples/ex_250_mechanics_full_capstone_application_window_test.aipl` |

---

### Chapter 12.4: Multi-Target Deployment (Native C99, Single-File HTML5, WASM) & AI Agent Workflows

#### 1. Concept in 30 Seconds
Teach shipping production binaries with `./bin/aipl build --native`, `--target html`, and `--target wasm`, plus surgical maintenance with `aipl outline`/`splice`/`fix`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn mapAiplTypeToC(ty: str): str:` from `compiler/codegen_c_or_ir.aipl` with `./bin/aipl verify`:

```aipl
module docs.compiler.codegen_c_verify
import { mapAiplTypeToC } from "compiler/codegen_c_or_ir"
import { assertEqStr } from "std/prelude"

pub fn verify_compiler_codegen_c(): int:
  assertEqStr(mapAiplTypeToC("int"), "AiplVal", "AIPL int maps to C99 AiplVal")
  assertEqStr(mapAiplTypeToC("str"), "AiplVal", "AIPL str maps to C99 AiplVal")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_015` | [examples/ex_015_sys_ffi_c_abi_bridge_cli.aipl](../../examples/ex_015_sys_ffi_c_abi_bridge_cli.aipl) | `tests/examples/ex_015_sys_ffi_c_abi_bridge_cli_test.aipl` | `./bin/aipl test tests/examples/ex_015_sys_ffi_c_abi_bridge_cli_test.aipl` |
| `ex_016` | [examples/ex_016_sys_audio_pcm_ring_cli.aipl](../../examples/ex_016_sys_audio_pcm_ring_cli.aipl) | `tests/examples/ex_016_sys_audio_pcm_ring_cli_test.aipl` | `./bin/aipl test tests/examples/ex_016_sys_audio_pcm_ring_cli_test.aipl` |
| `ex_246` | [examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl](../../examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl) | `tests/examples/ex_246_mechanics_attribute_modifier_sheet_window_test.aipl` | `./bin/aipl test tests/examples/ex_246_mechanics_attribute_modifier_sheet_window_test.aipl` |
| `ex_250` | [examples/ex_250_mechanics_full_capstone_application_window.aipl](../../examples/ex_250_mechanics_full_capstone_application_window.aipl) | `tests/examples/ex_250_mechanics_full_capstone_application_window_test.aipl` | `./bin/aipl test tests/examples/ex_250_mechanics_full_capstone_application_window_test.aipl` |
