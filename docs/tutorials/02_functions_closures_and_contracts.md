[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](INDEX.md) | [Cookbook](cookbook.md) | [Stdlib Reference](../STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Chapter 02: Functions, Closures, Contracts & Modules

> **Chapter Summary**: Top-level fn/pub fn functions, default parameters, explicit ret, first-class closures with lexical capture, Design-by-Contract preconditions (req:) and postconditions (ens:) verified by SMT, and multi-file module imports.

## Table of Contents
- [Chapter 02.1: Top-Level Functions (fn / pub fn), Default Parameters, Explicit ret & Tuple Returns](#chapter-021-top-level-functions-fn--pub-fn-default-parameters-explicit-ret--tuple-returns)
- [Chapter 02.2: First-Class Closures ((x: int) -> int => x * 2), Higher-Order Functions & Lexical Capture](#chapter-022-first-class-closures-x-int---int--x--2-higher-order-functions--lexical-capture)
- [Chapter 02.3: Design-by-Contract Preconditions (req:) & Postconditions (ens:) with SMT Verification](#chapter-023-design-by-contract-preconditions-req--postconditions-ens-with-smt-verification)
- [Chapter 02.4: Multi-File Module Imports, Barrel *_mod.aipl Re-Exports & Visibility Rules](#chapter-024-multi-file-module-imports-barrel-_modaipl-re-exports--visibility-rules)

---

### Chapter 02.1: Top-Level Functions (fn / pub fn), Default Parameters, Explicit ret & Tuple Returns

#### 1. Concept in 30 Seconds
Teach `fn` and `pub fn` declarations, default parameter values, tuple return destructuring `let (a, b) = ..`, and mandatory `ret` statements. Pitfall: omitting `ret` in a non-`void` function triggers `E206_MISSING_RETURN`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn None():` from `std/prelude.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.core.prelude_None_test
import * from "std/prelude"

pub fn test_prelude_None(): int:
  let n: Option[int] = None()
  assert(n.isNone() == true, "None isNone == true")
  assert(n.isSome() == false, "None isSome == false")
  assertEqInt(n.unwrapOr(99), 99, "None unwrapOr returns fallback 99")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_004` | [examples/ex_004_control_flow_and_loops_cli.aipl](../../examples/ex_004_control_flow_and_loops_cli.aipl) | `tests/examples/ex_004_control_flow_and_loops_cli_test.aipl` | `./bin/aipl test tests/examples/ex_004_control_flow_and_loops_cli_test.aipl` |
| `ex_010` | [examples/ex_010_modules_and_multi_file_imports_cli.aipl](../../examples/ex_010_modules_and_multi_file_imports_cli.aipl) | `tests/examples/ex_010_modules_and_multi_file_imports_cli_test.aipl` | `./bin/aipl test tests/examples/ex_010_modules_and_multi_file_imports_cli_test.aipl` |
| `ex_014` | [examples/ex_014_sys_net_socket_abi_cli.aipl](../../examples/ex_014_sys_net_socket_abi_cli.aipl) | `tests/examples/ex_014_sys_net_socket_abi_cli_test.aipl` | `./bin/aipl test tests/examples/ex_014_sys_net_socket_abi_cli_test.aipl` |

---

### Chapter 02.2: First-Class Closures ((x: int) -> int => x * 2), Higher-Order Functions & Lexical Capture

#### 1. Concept in 30 Seconds
Teach arrow closure syntax `(x: int) -> int => x * 2`, passing closures to filter/map/fold pipelines, and lexical environment capture. Pitfall: omitting parameter type annotations on closure parameters triggers `E105_CLOSURE_PARAM_TYPE`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn (self: Option[T]) isSome(): bool:` from `std/prelude.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.core.prelude_Option_isSome_test
import * from "std/prelude"

pub fn test_prelude_Option_isSome(): int:
  assert(Some(10).isSome() == true, "Some(10) isSome")
  assert(Some(0).isSome() == true, "Some(0) isSome")
  let n: Option[int] = None()
  assert(n.isSome() == false, "None isSome == false")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_008` | [examples/ex_008_closures_and_functional_pipelines_cli.aipl](../../examples/ex_008_closures_and_functional_pipelines_cli.aipl) | `tests/examples/ex_008_closures_and_functional_pipelines_cli_test.aipl` | `./bin/aipl test tests/examples/ex_008_closures_and_functional_pipelines_cli_test.aipl` |
| `ex_013` | [examples/ex_013_sys_fs_lowlevel_descriptor_cli.aipl](../../examples/ex_013_sys_fs_lowlevel_descriptor_cli.aipl) | `tests/examples/ex_013_sys_fs_lowlevel_descriptor_cli_test.aipl` | `./bin/aipl test tests/examples/ex_013_sys_fs_lowlevel_descriptor_cli_test.aipl` |
| `ex_019` | [examples/ex_019_rt_array_and_map_growth_cli.aipl](../../examples/ex_019_rt_array_and_map_growth_cli.aipl) | `tests/examples/ex_019_rt_array_and_map_growth_cli_test.aipl` | `./bin/aipl test tests/examples/ex_019_rt_array_and_map_growth_cli_test.aipl` |

---

### Chapter 02.3: Design-by-Contract Preconditions (req:) & Postconditions (ens:) with SMT Verification

#### 1. Concept in 30 Seconds
Teach formal `req:` preconditions and `ens:` postconditions referencing `result`, verified statically by `compiler/smt.aipl` and enforced at runtime with `E302`/`E303`. Pitfall: calling a `req: denom != 0` function with `0` triggers `E302_PRECONDITION_FAILED`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn classifyContractResult(valid: bool, hasUnboundedCallOrLoop: bool, reason: str): str:` from `compiler/smt.aipl` with `./bin/aipl verify`:

```aipl
module docs.compiler.smt_verify
import { classifyContractResult, STATUS_PROVEN_STATIC, STATUS_REFUTED_STATIC, STATUS_UNKNOWN_DYNAMIC } from "compiler/smt"
import { assertEqStr } from "std/prelude"

pub fn verify_compiler_smt(): int:
  let sProven = classifyContractResult(true, false, "dbm_valid")
  let sRefuted = classifyContractResult(false, false, "counterexample")
  let sDyn = classifyContractResult(true, true, "unbounded_loop")
  assertEqStr(sProven, STATUS_PROVEN_STATIC, "bounded valid contract is proven static")
  assertEqStr(sRefuted, STATUS_REFUTED_STATIC, "invalid contract is refuted static")
  assertEqStr(sDyn, STATUS_UNKNOWN_DYNAMIC, "unbounded loop delegates to dynamic guard")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_011` | [examples/ex_011_sys_syscall_and_os_probe_cli.aipl](../../examples/ex_011_sys_syscall_and_os_probe_cli.aipl) | `tests/examples/ex_011_sys_syscall_and_os_probe_cli_test.aipl` | `./bin/aipl test tests/examples/ex_011_sys_syscall_and_os_probe_cli_test.aipl` |
| `ex_012` | [examples/ex_012_sys_mem_page_inspector_cli.aipl](../../examples/ex_012_sys_mem_page_inspector_cli.aipl) | `tests/examples/ex_012_sys_mem_page_inspector_cli_test.aipl` | `./bin/aipl test tests/examples/ex_012_sys_mem_page_inspector_cli_test.aipl` |
| `ex_020` | [examples/ex_020_rt_ptr_and_slice_bounds_cli.aipl](../../examples/ex_020_rt_ptr_and_slice_bounds_cli.aipl) | `tests/examples/ex_020_rt_ptr_and_slice_bounds_cli_test.aipl` | `./bin/aipl test tests/examples/ex_020_rt_ptr_and_slice_bounds_cli_test.aipl` |

---

### Chapter 02.4: Multi-File Module Imports, Barrel *_mod.aipl Re-Exports & Visibility Rules

#### 1. Concept in 30 Seconds
Teach `import { sym } from "std/<domain>/<module>"` vs wildcard `import * from "std/prelude"`, diamond import deduplication, and `pub` visibility rules. Pitfall: importing an unexported `fn` across modules triggers `E203_PRIVATE_SYMBOL`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn stdlibBuildTarget(): str:` from `std/std_root.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.core.std_root_stdlibBuildTarget_test
import * from "std/std_root"
import * from "std/prelude"

pub fn test_std_root_stdlibBuildTarget(): int:
  let t = stdlibBuildTarget()
  assertEqStr(t, "native", "default build target is native")
  assert(stdlibHasFeature(t) == true, "build target is a valid feature")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_010` | [examples/ex_010_modules_and_multi_file_imports_cli.aipl](../../examples/ex_010_modules_and_multi_file_imports_cli.aipl) | `tests/examples/ex_010_modules_and_multi_file_imports_cli_test.aipl` | `./bin/aipl test tests/examples/ex_010_modules_and_multi_file_imports_cli_test.aipl` |
| `ex_017` | [examples/ex_017_sys_gpu_adapter_probe_cli.aipl](../../examples/ex_017_sys_gpu_adapter_probe_cli.aipl) | `tests/examples/ex_017_sys_gpu_adapter_probe_cli_test.aipl` | `./bin/aipl test tests/examples/ex_017_sys_gpu_adapter_probe_cli_test.aipl` |
| `ex_021` | [examples/ex_021_rt_canvas_x11_window.aipl](../../examples/ex_021_rt_canvas_x11_window.aipl) | `tests/examples/ex_021_rt_canvas_x11_window_test.aipl` | `./bin/aipl test tests/examples/ex_021_rt_canvas_x11_window_test.aipl` |
