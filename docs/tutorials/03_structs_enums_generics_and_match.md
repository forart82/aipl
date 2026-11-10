[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](INDEX.md) | [Cookbook](cookbook.md) | [Stdlib Reference](../STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Chapter 03: Structs, Enums, Generics & Pattern Matching

> **Chapter Summary**: Nominal pub struct definitions with value semantics, immutable and mutable receiver methods, algebraic enum sum types (ADTs), Option[T], Result[T, E], postfix ? propagation, and exhaustive match destructuring.

## Table of Contents
- [Chapter 03.1: Nominal pub struct Definitions, Value Semantics & Field Initialization](#chapter-031-nominal-pub-struct-definitions-value-semantics--field-initialization)
- [Chapter 03.2: Immutable & Mutable Receiver Methods (pub fn (self: T) & pub fn (mut self: T))](#chapter-032-immutable--mutable-receiver-methods-pub-fn-self-t--pub-fn-mut-self-t)
- [Chapter 03.3: Algebraic pub enum Sum Types (ADTs) & Exhaustive match Destructuring](#chapter-033-algebraic-pub-enum-sum-types-adts--exhaustive-match-destructuring)
- [Chapter 03.4: Generic Types [T], Option[T] (Some/None), Result[T, E] (Ok/Err) & Postfix ? Propagation](#chapter-034-generic-types-t-optiont-somenone-resultt-e-okerr--postfix--propagation)

---

### Chapter 03.1: Nominal pub struct Definitions, Value Semantics & Field Initialization

#### 1. Concept in 30 Seconds
Teach `pub struct` declarations, named field construction `Vec2(x = 1.0, y = 2.0)`, and deterministic copy/value semantics. Pitfall: missing a required struct field in constructor call triggers `E207_MISSING_STRUCT_FIELD`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn Vec2.new(x: float, y: float): Vec2:` from `std/math/vec_math.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.math.vec_math_z1_test
import * from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec2_new_1(): int:
  let arg_x = 1.0
  let edge_x = 0.0
  let arg_y = 1.0
  let edge_y = 0.0
  let resNom = Vec2.new(arg_x, arg_y)
  let resEdge = Vec2.new(edge_x, edge_y)
  assertApproxEq(resNom.x, 1.0, 0.001, "Vec2.new nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "Vec2.new boundary resEdge.x ~= 0.0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_005` | [examples/ex_005_structs_methods_and_immutability_cli.aipl](../../examples/ex_005_structs_methods_and_immutability_cli.aipl) | `tests/examples/ex_005_structs_methods_and_immutability_cli_test.aipl` | `./bin/aipl test tests/examples/ex_005_structs_methods_and_immutability_cli_test.aipl` |
| `ex_029` | [examples/ex_029_math_vec2_vec3_vec4_cli.aipl](../../examples/ex_029_math_vec2_vec3_vec4_cli.aipl) | `tests/examples/ex_029_math_vec2_vec3_vec4_cli_test.aipl` | `./bin/aipl test tests/examples/ex_029_math_vec2_vec3_vec4_cli_test.aipl` |

---

### Chapter 03.2: Immutable & Mutable Receiver Methods (pub fn (self: T) & pub fn (mut self: T))

#### 1. Concept in 30 Seconds
Teach UFCS receiver method declarations `pub fn (self: T) method(): Ret:` and `pub fn (mut self: T) mutate(): void:` for fluent dot-chaining. Pitfall: mutating `self.field` without `mut self` receiver triggers `E204_IMMUTABLE_ASSIGN`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn (self: Option[T]) isNone(): bool:` from `std/prelude.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.core.prelude_Option_isNone_test
import * from "std/prelude"

pub fn test_prelude_Option_isNone(): int:
  let n: Option[int] = None()
  assert(n.isNone() == true, "None isNone == true")
  assert(Some(0).isNone() == false, "Some(0) isNone == false")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_005` | [examples/ex_005_structs_methods_and_immutability_cli.aipl](../../examples/ex_005_structs_methods_and_immutability_cli.aipl) | `tests/examples/ex_005_structs_methods_and_immutability_cli_test.aipl` | `./bin/aipl test tests/examples/ex_005_structs_methods_and_immutability_cli_test.aipl` |
| `ex_007` | [examples/ex_007_generics_and_containers_cli.aipl](../../examples/ex_007_generics_and_containers_cli.aipl) | `tests/examples/ex_007_generics_and_containers_cli_test.aipl` | `./bin/aipl test tests/examples/ex_007_generics_and_containers_cli_test.aipl` |
| `ex_018` | [examples/ex_018_rt_string_utf8_interner_cli.aipl](../../examples/ex_018_rt_string_utf8_interner_cli.aipl) | `tests/examples/ex_018_rt_string_utf8_interner_cli_test.aipl` | `./bin/aipl test tests/examples/ex_018_rt_string_utf8_interner_cli_test.aipl` |

---

### Chapter 03.3: Algebraic pub enum Sum Types (ADTs) & Exhaustive match Destructuring

#### 1. Concept in 30 Seconds
Teach tagged `pub enum` variants with payloads and exhaustive `match` pattern destructuring. Pitfall: omitting an enum variant arm without `_` wildcard triggers `E208_NON_EXHAUSTIVE_MATCH`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn (self: Option[T]) unwrap(): T:` from `std/prelude.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.core.prelude_Option_unwrap_test
import * from "std/prelude"

pub fn test_prelude_Option_unwrap(): int:
  assertEqInt(Some(99).unwrap(), 99, "unwraps 99")
  assertEqInt(Some(-1).unwrap(), -1, "unwraps -1")
  assertEqStr(Some("ok").unwrap(), "ok", "unwraps ok")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_006` | [examples/ex_006_enums_and_pattern_matching_cli.aipl](../../examples/ex_006_enums_and_pattern_matching_cli.aipl) | `tests/examples/ex_006_enums_and_pattern_matching_cli_test.aipl` | `./bin/aipl test tests/examples/ex_006_enums_and_pattern_matching_cli_test.aipl` |
| `ex_011` | [examples/ex_011_sys_syscall_and_os_probe_cli.aipl](../../examples/ex_011_sys_syscall_and_os_probe_cli.aipl) | `tests/examples/ex_011_sys_syscall_and_os_probe_cli_test.aipl` | `./bin/aipl test tests/examples/ex_011_sys_syscall_and_os_probe_cli_test.aipl` |

---

### Chapter 03.4: Generic Types [T], Option[T] (Some/None), Result[T, E] (Ok/Err) & Postfix ? Propagation

#### 1. Concept in 30 Seconds
Teach zero-null error handling using `Option[T]`, `Result[T, E]`, combinators (`isSome`, `isOk`, `unwrapOr`), and postfix `?` early-return propagation. Pitfall: using `?` inside a function that does not return `Result`/`Option` triggers `E209_INVALID_TRY_OPERATOR`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn (self: Option[T]) unwrapOr(defaultVal: T): T:` from `std/prelude.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.core.prelude_Option_unwrapOr_test
import * from "std/prelude"

pub fn test_prelude_Option_unwrapOr(): int:
  assertEqInt(Some(10).unwrapOr(99), 10, "Some returns payload 10")
  assertEqInt(Some(0).unwrapOr(99), 0, "Some(0) returns 0, not fallback")
  let n: Option[int] = None()
  assertEqInt(n.unwrapOr(99), 99, "None returns fallback 99")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_007` | [examples/ex_007_generics_and_containers_cli.aipl](../../examples/ex_007_generics_and_containers_cli.aipl) | `tests/examples/ex_007_generics_and_containers_cli_test.aipl` | `./bin/aipl test tests/examples/ex_007_generics_and_containers_cli_test.aipl` |
| `ex_009` | [examples/ex_009_option_and_result_error_handling_cli.aipl](../../examples/ex_009_option_and_result_error_handling_cli.aipl) | `tests/examples/ex_009_option_and_result_error_handling_cli_test.aipl` | `./bin/aipl test tests/examples/ex_009_option_and_result_error_handling_cli_test.aipl` |
| `ex_012` | [examples/ex_012_sys_mem_page_inspector_cli.aipl](../../examples/ex_012_sys_mem_page_inspector_cli.aipl) | `tests/examples/ex_012_sys_mem_page_inspector_cli_test.aipl` | `./bin/aipl test tests/examples/ex_012_sys_mem_page_inspector_cli_test.aipl` |
