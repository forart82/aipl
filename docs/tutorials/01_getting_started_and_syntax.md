[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](INDEX.md) | [Cookbook](cookbook.md) | [Stdlib Reference](../STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Chapter 01: Getting Started, Syntax & Basic Types

> **Chapter Summary**: Module declarations, strict 2-space indentation offside rule, immutable let vs mutable mut bindings, 64-bit int/float primitives, UTF-8 strings, and dynamic arrays/maps.

## Table of Contents
- [Chapter 01.1: Module Declarations, Strict 2-Space Indentation & Hello World CLI](#chapter-011-module-declarations-strict-2-space-indentation--hello-world-cli)
- [Chapter 01.2: Immutable let vs Mutable mut Bindings, Primitives (int, float, bool, str) & Bitwise Operators](#chapter-012-immutable-let-vs-mutable-mut-bindings-primitives-int-float-bool-str--bitwise-operators)
- [Chapter 01.3: UTF-8 Strings, Slicing, Built-in String Methods & Formatting](#chapter-013-utf-8-strings-slicing-built-in-string-methods--formatting)
- [Chapter 01.4: Control Flow (if/elif/else, while, for..in), Dynamic Arrays [T] & Maps Map[K,V]](#chapter-014-control-flow-ifelifelse-while-forin-dynamic-arrays-t--maps-mapkv)

---

### Chapter 01.1: Module Declarations, Strict 2-Space Indentation & Hello World CLI

#### 1. Concept in 30 Seconds
Teach `module` headers, strict 2-space indentation blocks (`INDENT`/`DEDENT` without curly braces), and console output via `print`/`println`. Pitfall: using 4-space or tab indentation triggers `E102_INVALID_INDENT`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `builtin fn int(x: any): int` from `<compiler_builtins>` with `./bin/aipl verify`:

```aipl
module tests.functions.core.compiler_builtins_int_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_int(): int:
  assertEqInt(int(3.99), 3, "float 3.99 truncates to 3")
  assertEqInt(int(-3.99), -3, "float -3.99 truncates to -3")
  assertEqInt(int("42"), 42, "string 42 parses to 42")
  assertEqInt(int("-1024"), -1024, "negative string parses")
  assertEqInt(int(true), 1, "true -> 1")
  assertEqInt(int(false), 0, "false -> 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_001` | [examples/ex_001_hello_world_and_io_cli.aipl](../../examples/ex_001_hello_world_and_io_cli.aipl) | `tests/examples/ex_001_hello_world_and_io_cli_test.aipl` | `./bin/aipl test tests/examples/ex_001_hello_world_and_io_cli_test.aipl` |
| `ex_002` | [examples/ex_002_primitives_and_bitwise_cli.aipl](../../examples/ex_002_primitives_and_bitwise_cli.aipl) | `tests/examples/ex_002_primitives_and_bitwise_cli_test.aipl` | `./bin/aipl test tests/examples/ex_002_primitives_and_bitwise_cli_test.aipl` |

---

### Chapter 01.2: Immutable let vs Mutable mut Bindings, Primitives (int, float, bool, str) & Bitwise Operators

#### 1. Concept in 30 Seconds
Teach immutable `let` by default, explicit `mut` for reassignable state, 64-bit `int`/`float` separation, and explicit `float(x)`/`int(x)` conversions. Pitfall: reassigning a `let` variable triggers `E204_IMMUTABLE_ASSIGN`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `builtin fn int(x: any): int` from `<compiler_builtins>` with `./bin/aipl verify`:

```aipl
module tests.functions.core.compiler_builtins_int_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_int(): int:
  assertEqInt(int(3.99), 3, "float 3.99 truncates to 3")
  assertEqInt(int(-3.99), -3, "float -3.99 truncates to -3")
  assertEqInt(int("42"), 42, "string 42 parses to 42")
  assertEqInt(int("-1024"), -1024, "negative string parses")
  assertEqInt(int(true), 1, "true -> 1")
  assertEqInt(int(false), 0, "false -> 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_002` | [examples/ex_002_primitives_and_bitwise_cli.aipl](../../examples/ex_002_primitives_and_bitwise_cli.aipl) | `tests/examples/ex_002_primitives_and_bitwise_cli_test.aipl` | `./bin/aipl test tests/examples/ex_002_primitives_and_bitwise_cli_test.aipl` |
| `ex_003` | [examples/ex_003_strings_and_interpolation_cli.aipl](../../examples/ex_003_strings_and_interpolation_cli.aipl) | `tests/examples/ex_003_strings_and_interpolation_cli_test.aipl` | `./bin/aipl test tests/examples/ex_003_strings_and_interpolation_cli_test.aipl` |

---

### Chapter 01.3: UTF-8 Strings, Slicing, Built-in String Methods & Formatting

#### 1. Concept in 30 Seconds
Teach built-in string operations (`len`, `slice`, `split`, `trim`, `replace`, `startsWith`, `endsWith`, `toUpper`, `toLower`, `charAt`, `indexOf`). Pitfall: passing `int` directly into string concatenation without `str(n)` triggers `E201_TYPE_MISMATCH`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `builtin fn (self: str) split(delim: str): [str]` from `<compiler_builtins>` with `./bin/aipl verify`:

```aipl
module tests.functions.core.compiler_builtins_split_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_split(): int:
  let parts = "a,b,c".split(",")
  assertEqInt(parts.len(), 3, "3 parts")
  assertEqStr(parts[0], "a", "part 0")
  assertEqStr(parts[1], "b", "part 1")
  assertEqStr(parts[2], "c", "part 2")
  let single = "abc".split(",")
  assertEqInt(single.len(), 1, "missing delim returns 1 element")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_003` | [examples/ex_003_strings_and_interpolation_cli.aipl](../../examples/ex_003_strings_and_interpolation_cli.aipl) | `tests/examples/ex_003_strings_and_interpolation_cli_test.aipl` | `./bin/aipl test tests/examples/ex_003_strings_and_interpolation_cli_test.aipl` |
| `ex_056` | [examples/ex_056_fmt_num_radix_and_scientific_cli.aipl](../../examples/ex_056_fmt_num_radix_and_scientific_cli.aipl) | `tests/examples/ex_056_fmt_num_radix_and_scientific_cli_test.aipl` | `./bin/aipl test tests/examples/ex_056_fmt_num_radix_and_scientific_cli_test.aipl` |

---

### Chapter 01.4: Control Flow (if/elif/else, while, for..in), Dynamic Arrays [T] & Maps Map[K,V]

#### 1. Concept in 30 Seconds
Teach structured control flow with strict boolean conditions (`and`, `or`, `not`), array `[T]` methods (`push`, `pop`, `len`, `contains`), and `Map[K, V]` (`set`, `get`, `has`, `delete`, `keys`). Pitfall: non-boolean `if count:` condition triggers `E202_NON_BOOL_CONDITION`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `builtin fn (mut self: [T]) push(elem: T): void` from `<compiler_builtins>` with `./bin/aipl verify`:

```aipl
module tests.functions.core.compiler_builtins_push_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_push(): int:
  mut arr: [int] = []
  arr.push(10)
  arr.push(0)
  arr.push(-5)
  assertEqInt(arr.len(), 3, "len == 3")
  assertEqInt(arr[0], 10, "first element 10")
  assertEqInt(arr[1], 0, "second element 0")
  assertEqInt(arr[2], -5, "third element -5")
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
| `ex_006` | [examples/ex_006_enums_and_pattern_matching_cli.aipl](../../examples/ex_006_enums_and_pattern_matching_cli.aipl) | `tests/examples/ex_006_enums_and_pattern_matching_cli_test.aipl` | `./bin/aipl test tests/examples/ex_006_enums_and_pattern_matching_cli_test.aipl` |
