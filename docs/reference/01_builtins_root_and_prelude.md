[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 01: `builtins_root_and_prelude` API Reference

> Complete API reference manual for AIPL standard library domain `builtins_root_and_prelude` (74 callable functions & methods across ["<compiler_builtins>", "std/std_root.aipl", "std/prelude.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `builtins_root_and_prelude`
- **Target Source Modules**: ["<compiler_builtins>", "std/std_root.aipl", "std/prelude.aipl"]
- **Total Callable Functions & Methods**: 74
- **Total Data Types (`struct` & `enum`)**: 4
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(4 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `StdlibVersion` | `pub struct` | `std/std_root.aipl` | `major: int`, `minor: int`, `patch: int`, `prerelease: str` | `StdlibVersion(major, minor, patch, prerelease)` |
| `StdlibDomainDescriptor` | `pub struct` | `std/std_root.aipl` | `name: str`, `layer: int`, `barrelPath: str`, `moduleCount: int` | `StdlibDomainDescriptor(name, layer, barrelPath, moduleCount)` |
| `Option[T]` | `pub struct` | `std/prelude.aipl` | `hasValue: bool`, `value: T` | `Option(hasValue, value)` |
| `Result[T, E]` | `pub struct` | `std/prelude.aipl` | `isSuccess: bool`, `value: T`, `error: E` | `Result(isSuccess, value, error)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `<compiler_builtins>` | `int` | `builtin fn int(x: any): int` | `tests/functions/core/compiler_builtins_test.aipl` |
| `2` | `<compiler_builtins>` | `float` | `builtin fn float(x: any): float` | `tests/functions/core/compiler_builtins_test.aipl` |
| `3` | `<compiler_builtins>` | `str` | `builtin fn str(x: any): str` | `tests/functions/core/compiler_builtins_test.aipl` |
| `4` | `<compiler_builtins>` | `bool` | `builtin fn bool(x: any): bool` | `tests/functions/core/compiler_builtins_test.aipl` |
| `5` | `<compiler_builtins>` | `len` | `builtin fn (self: str | [T]) len(): int` | `tests/functions/core/compiler_builtins_test.aipl` |
| `6` | `<compiler_builtins>` | `push` | `builtin fn (mut self: [T]) push(elem: T): void` | `tests/functions/core/compiler_builtins_test.aipl` |
| `7` | `<compiler_builtins>` | `pop` | `builtin fn (mut self: [T]) pop(): T` | `tests/functions/core/compiler_builtins_test.aipl` |
| `8` | `<compiler_builtins>` | `slice` | `builtin fn (self: str | [T]) slice(start: int, end: int): str | [T]` | `tests/functions/core/compiler_builtins_test.aipl` |
| `9` | `<compiler_builtins>` | `contains` | `builtin fn (self: str | [T]) contains(sub: any): bool` | `tests/functions/core/compiler_builtins_test.aipl` |
| `10` | `<compiler_builtins>` | `split` | `builtin fn (self: str) split(delim: str): [str]` | `tests/functions/core/compiler_builtins_test.aipl` |
| `11` | `<compiler_builtins>` | `trim` | `builtin fn (self: str) trim(): str` | `tests/functions/core/compiler_builtins_test.aipl` |
| `12` | `<compiler_builtins>` | `replace` | `builtin fn (self: str) replace(old: str, new: str): str` | `tests/functions/core/compiler_builtins_test.aipl` |
| `13` | `<compiler_builtins>` | `startsWith` | `builtin fn (self: str) startsWith(prefix: str): bool` | `tests/functions/core/compiler_builtins_test.aipl` |
| `14` | `<compiler_builtins>` | `endsWith` | `builtin fn (self: str) endsWith(suffix: str): bool` | `tests/functions/core/compiler_builtins_test.aipl` |
| `15` | `<compiler_builtins>` | `toUpper` | `builtin fn (self: str) toUpper(): str` | `tests/functions/core/compiler_builtins_test.aipl` |
| `16` | `<compiler_builtins>` | `toLower` | `builtin fn (self: str) toLower(): str` | `tests/functions/core/compiler_builtins_test.aipl` |
| `17` | `<compiler_builtins>` | `charAt` | `builtin fn (self: str) charAt(idx: int): str` | `tests/functions/core/compiler_builtins_test.aipl` |
| `18` | `<compiler_builtins>` | `indexOf` | `builtin fn (self: str) indexOf(sub: str): int` | `tests/functions/core/compiler_builtins_test.aipl` |
| `19` | `<compiler_builtins>` | `Map.set` | `builtin fn (mut self: Map[K, V]) set(key: K, val: V): void` | `tests/functions/core/compiler_builtins_test.aipl` |
| `20` | `<compiler_builtins>` | `Map.get` | `builtin fn (self: Map[K, V]) get(key: K): Option[V]` | `tests/functions/core/compiler_builtins_test.aipl` |
| `21` | `<compiler_builtins>` | `Map.has` | `builtin fn (self: Map[K, V]) has(key: K): bool` | `tests/functions/core/compiler_builtins_test.aipl` |
| `22` | `<compiler_builtins>` | `Map.delete` | `builtin fn (mut self: Map[K, V]) delete(key: K): void` | `tests/functions/core/compiler_builtins_test.aipl` |
| `23` | `<compiler_builtins>` | `Map.keys` | `builtin fn (self: Map[K, V]) keys(): [K]` | `tests/functions/core/compiler_builtins_test.aipl` |
| `24` | `<compiler_builtins>` | `abs` | `builtin fn abs(x: int | float): int | float` | `tests/functions/core/compiler_builtins_test.aipl` |
| `25` | `<compiler_builtins>` | `sqrt` | `builtin fn sqrt(x: float): float` | `tests/functions/core/compiler_builtins_test.aipl` |
| `26` | `<compiler_builtins>` | `sin_cos` | `builtin fn sin(x: float): float / builtin fn cos(x: float): float` | `tests/functions/core/compiler_builtins_test.aipl` |
| `27` | `<compiler_builtins>` | `floor_ceil` | `builtin fn floor(x: float): float / builtin fn ceil(x: float): float` | `tests/functions/core/compiler_builtins_test.aipl` |
| `28` | `<compiler_builtins>` | `pow` | `builtin fn pow(base: float, exp: float): float` | `tests/functions/core/compiler_builtins_test.aipl` |
| `29` | `<compiler_builtins>` | `rgb` | `builtin fn rgb(r: int, g: int, b: int): int` | `tests/functions/core/compiler_builtins_test.aipl` |
| `30` | `<compiler_builtins>` | `print_println` | `builtin fn print(s: any): void / builtin fn println(s: any): void` | `tests/functions/core/compiler_builtins_test.aipl` |
| `31` | `<compiler_builtins>` | `assert_builtin` | `builtin fn assert(cond: bool, msg: str): void` | `tests/functions/core/compiler_builtins_test.aipl` |
| `32` | `<compiler_builtins>` | `panic_todo_builtin` | `builtin fn panic(msg: str): void / builtin fn todo(msg: str): void` | `tests/functions/core/compiler_builtins_test.aipl` |
| `33` | `std/std_root.aipl` | `stdlibVersion` | `pub fn stdlibVersion(): StdlibVersion:` | `tests/functions/core/std_root_test.aipl` |
| `34` | `std/std_root.aipl` | `stdlibVersionString` | `pub fn stdlibVersionString(): str:` | `tests/functions/core/std_root_test.aipl` |
| `35` | `std/std_root.aipl` | `stdlibBuildTarget` | `pub fn stdlibBuildTarget(): str:` | `tests/functions/core/std_root_test.aipl` |
| `36` | `std/std_root.aipl` | `stdlibHasFeature` | `pub fn stdlibHasFeature(feature: str): bool:` | `tests/functions/core/std_root_test.aipl` |
| `37` | `std/std_root.aipl` | `stdlibDomainCount` | `pub fn stdlibDomainCount(): int:` | `tests/functions/core/std_root_test.aipl` |
| `38` | `std/std_root.aipl` | `stdlibLayerCount` | `pub fn stdlibLayerCount(): int:` | `tests/functions/core/std_root_test.aipl` |
| `39` | `std/std_root.aipl` | `stdlibCanonicalDomains` | `pub fn stdlibCanonicalDomains(): [str]:` | `tests/functions/core/std_root_test.aipl` |
| `40` | `std/std_root.aipl` | `stdlibIsCanonicalDomain` | `pub fn stdlibIsCanonicalDomain(domain: str): bool:` | `tests/functions/core/std_root_test.aipl` |
| `41` | `std/std_root.aipl` | `stdlibDomainLayer` | `pub fn stdlibDomainLayer(domain: str): int:` | `tests/functions/core/std_root_test.aipl` |
| `42` | `std/std_root.aipl` | `stdlibDomainBarrelPath` | `pub fn stdlibDomainBarrelPath(domain: str): str:` | `tests/functions/core/std_root_test.aipl` |
| `43` | `std/std_root.aipl` | `stdlibCanImportLayer` | `pub fn stdlibCanImportLayer(fromLayer: int, toLayer: int): bool:` | `tests/functions/core/std_root_test.aipl` |
| `44` | `std/std_root.aipl` | `stdlibCanDomainImport` | `pub fn stdlibCanDomainImport(fromDomain: str, toDomain: str): bool:` | `tests/functions/core/std_root_test.aipl` |
| `45` | `std/prelude.aipl` | `Some` | `pub fn Some(val: any):` | `tests/functions/core/prelude_test.aipl` |
| `46` | `std/prelude.aipl` | `None` | `pub fn None():` | `tests/functions/core/prelude_test.aipl` |
| `47` | `std/prelude.aipl` | `Option.isSome` | `pub fn (self: Option[T]) isSome(): bool:` | `tests/functions/core/prelude_test.aipl` |
| `48` | `std/prelude.aipl` | `Option.isNone` | `pub fn (self: Option[T]) isNone(): bool:` | `tests/functions/core/prelude_test.aipl` |
| `49` | `std/prelude.aipl` | `Option.unwrap` | `pub fn (self: Option[T]) unwrap(): T:` | `tests/functions/core/prelude_test.aipl` |
| `50` | `std/prelude.aipl` | `Option.unwrapOr` | `pub fn (self: Option[T]) unwrapOr(defaultVal: T): T:` | `tests/functions/core/prelude_test.aipl` |
| `51` | `std/prelude.aipl` | `Ok` | `pub fn Ok(val: any):` | `tests/functions/core/prelude_test.aipl` |
| `52` | `std/prelude.aipl` | `Err` | `pub fn Err(err: any):` | `tests/functions/core/prelude_test.aipl` |
| `53` | `std/prelude.aipl` | `Result.isOk` | `pub fn (self: Result[T, E]) isOk(): bool:` | `tests/functions/core/prelude_test.aipl` |
| `54` | `std/prelude.aipl` | `Result.isErr` | `pub fn (self: Result[T, E]) isErr(): bool:` | `tests/functions/core/prelude_test.aipl` |
| `55` | `std/prelude.aipl` | `Result.unwrap` | `pub fn (self: Result[T, E]) unwrap(): T:` | `tests/functions/core/prelude_test.aipl` |
| `56` | `std/prelude.aipl` | `Result.unwrapErr` | `pub fn (self: Result[T, E]) unwrapErr(): E:` | `tests/functions/core/prelude_test.aipl` |
| `57` | `std/prelude.aipl` | `Result.unwrapOr` | `pub fn (self: Result[T, E]) unwrapOr(defaultVal: T): T:` | `tests/functions/core/prelude_test.aipl` |
| `58` | `std/prelude.aipl` | `panic` | `pub fn panic(message: str): void:` | `tests/functions/core/prelude_test.aipl` |
| `59` | `std/prelude.aipl` | `todo` | `pub fn todo(message: str): void:` | `tests/functions/core/prelude_test.aipl` |
| `60` | `std/prelude.aipl` | `unreachable` | `pub fn unreachable(message: str): void:` | `tests/functions/core/prelude_test.aipl` |
| `61` | `std/prelude.aipl` | `assert` | `pub fn assert(cond: bool, message: str): void:` | `tests/functions/core/prelude_test.aipl` |
| `62` | `std/prelude.aipl` | `assertEqInt` | `pub fn assertEqInt(actual: int, expected: int, message: str): void:` | `tests/functions/core/prelude_test.aipl` |
| `63` | `std/prelude.aipl` | `assertEqStr` | `pub fn assertEqStr(actual: str, expected: str, message: str): void:` | `tests/functions/core/prelude_test.aipl` |
| `64` | `std/prelude.aipl` | `assertApproxEq` | `pub fn assertApproxEq(actual: float, expected: float, eps: float, message: str): void:` | `tests/functions/core/prelude_test.aipl` |
| `65` | `std/prelude.aipl` | `minInt` | `pub fn minInt(a: int, b: int): int:` | `tests/functions/core/prelude_test.aipl` |
| `66` | `std/prelude.aipl` | `maxInt` | `pub fn maxInt(a: int, b: int): int:` | `tests/functions/core/prelude_test.aipl` |
| `67` | `std/prelude.aipl` | `clampInt` | `pub fn clampInt(v: int, lo: int, hi: int): int:` | `tests/functions/core/prelude_test.aipl` |
| `68` | `std/prelude.aipl` | `minFloat` | `pub fn minFloat(a: float, b: float): float:` | `tests/functions/core/prelude_test.aipl` |
| `69` | `std/prelude.aipl` | `maxFloat` | `pub fn maxFloat(a: float, b: float): float:` | `tests/functions/core/prelude_test.aipl` |
| `70` | `std/prelude.aipl` | `clampFloat` | `pub fn clampFloat(v: float, lo: float, hi: float): float:` | `tests/functions/core/prelude_test.aipl` |
| `71` | `std/prelude.aipl` | `inRangeInt` | `pub fn inRangeInt(v: int, lo: int, hi: int): bool:` | `tests/functions/core/prelude_test.aipl` |
| `72` | `std/prelude.aipl` | `inRangeFloat` | `pub fn inRangeFloat(v: float, lo: float, hi: float): bool:` | `tests/functions/core/prelude_test.aipl` |
| `73` | `std/prelude.aipl` | `boolToInt` | `pub fn boolToInt(b: bool): int:` | `tests/functions/core/prelude_test.aipl` |
| `74` | `std/prelude.aipl` | `intToBool` | `pub fn intToBool(v: int): bool:` | `tests/functions/core/prelude_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `int` (`<compiler_builtins>`)

- **Signature**: `builtin fn int(x: any): int`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `None (free function)` | **Parameters**: `x: any` | **Returns**: `int`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Truncate float (`int(3.99) == 3`, `int(-3.99) == -3`), parse decimal string (`int("42") == 42`), and convert boolean (`int(true) == 1`).

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

---

### `float` (`<compiler_builtins>`)

- **Signature**: `builtin fn float(x: any): float`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `None (free function)` | **Parameters**: `x: any` | **Returns**: `float`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Widen integer (`float(42) == 42.0`, `float(-7) == -7.0`) and parse decimal string (`float("3.25") == 3.25`).

```aipl
module tests.functions.core.compiler_builtins_float_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_float(): int:
  assertApproxEq(float(42), 42.0, 0.000001, "42 -> 42.0")
  assertApproxEq(float(-7), -7.0, 0.000001, "-7 -> -7.0")
  assertApproxEq(float(0), 0.0, 0.000001, "0 -> 0.0")
  assertApproxEq(float("3.25"), 3.25, 0.000001, "string 3.25 -> 3.25")
  assertEqInt(int(float(42)), 42, "int(float(42)) round-trip")
  ret 0
```

---

### `str` (`<compiler_builtins>`)

- **Signature**: `builtin fn str(x: any): str`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `None (free function)` | **Parameters**: `x: any` | **Returns**: `str`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Format integer (`str(42) == "42"`), float (`str(2.5) == "2.5"`), and boolean (`str(true) == "true"`).

```aipl
module tests.functions.core.compiler_builtins_str_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_str(): int:
  assertEqStr(str(0), "0", "0 -> 0")
  assertEqStr(str(-999), "-999", "-999 -> -999")
  assertEqStr(str(2.5), "2.5", "2.5 -> 2.5")
  assertEqStr(str(true), "true", "true -> true")
  assertEqStr(str(false), "false", "false -> false")
  ret 0
```

---

### `bool` (`<compiler_builtins>`)

- **Signature**: `builtin fn bool(x: any): bool`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `None (free function)` | **Parameters**: `x: any` | **Returns**: `bool`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Convert integer truthiness (`bool(1) == true`) and falsiness (`bool(0) == false`).

```aipl
module tests.functions.core.compiler_builtins_bool_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_bool(): int:
  assert(bool(1) == true, "1 -> true")
  assert(bool(0) == false, "0 -> false")
  assert(bool(int(true)) == true, "round-trip true")
  assert(bool(int(false)) == false, "round-trip false")
  ret 0
```

---

### `len` (`<compiler_builtins>`)

- **Signature**: `builtin fn (self: str | [T]) len(): int`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `self: str | [T]` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Query length of ASCII string `"aipl".len() == 4` and array `[10, 20, 30].len() == 3`.

```aipl
module tests.functions.core.compiler_builtins_len_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_len(): int:
  assertEqInt("".len(), 0, "empty string len == 0")
  assertEqInt("aipl".len(), 4, "aipl len == 4")
  mut arr: [int] = []
  assertEqInt(arr.len(), 0, "empty array len == 0")
  arr.push(10)
  arr.push(20)
  assertEqInt(arr.len(), 2, "array len after 2 pushes == 2")
  ret 0
```

---

### `push` (`<compiler_builtins>`)

- **Signature**: `builtin fn (mut self: [T]) push(elem: T): void`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `mut self: [T]` | **Parameters**: `elem: T` | **Returns**: `void`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Append elements `10`, `20`, `30` to dynamic array `[int]` and verify index order.

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

---

### `pop` (`<compiler_builtins>`)

- **Signature**: `builtin fn (mut self: [T]) pop(): T`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `mut self: [T]` | **Parameters**: `none` | **Returns**: `T`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Remove and return the last element from `[10, 20, 30]`.

```aipl
module tests.functions.core.compiler_builtins_pop_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_pop(): int:
  mut arr: [int] = [10, 20, 30]
  let last = arr.pop()
  assertEqInt(last, 30, "popped 30")
  assertEqInt(arr.len(), 2, "len decremented to 2")
  assertEqInt(arr.pop(), 20, "popped 20")
  assertEqInt(arr.pop(), 10, "popped 10")
  assertEqInt(arr.len(), 0, "array now empty")
  ret 0
```

---

### `slice` (`<compiler_builtins>`)

- **Signature**: `builtin fn (self: str | [T]) slice(start: int, end: int): str | [T]`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `self: str | [T]` | **Parameters**: `start: int, end: int` | **Returns**: `str | [T]`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Extract interior slice `"aipl_lang".slice(0, 4) == "aipl"` and array slice `[10, 20, 30, 40].slice(1, 3)`.

```aipl
module tests.functions.core.compiler_builtins_slice_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_slice(): int:
  let s = "aipl_lang"
  assertEqStr(s.slice(0, 4), "aipl", "prefix slice")
  assertEqStr(s.slice(5, 9), "lang", "suffix slice")
  assertEqStr(s.slice(0, 0), "", "empty zero-width slice")
  assertEqStr(s.slice(0, s.len()), "aipl_lang", "full slice copy")
  ret 0
```

---

### `contains` (`<compiler_builtins>`)

- **Signature**: `builtin fn (self: str | [T]) contains(sub: any): bool`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `self: str | [T]` | **Parameters**: `sub: any` | **Returns**: `bool`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Check substring presence `"aipl_stdlib".contains("stdlib") == true` and absence `"aipl".contains("xyz") == false`.

```aipl
module tests.functions.core.compiler_builtins_contains_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_contains(): int:
  assert("aipl_stdlib".contains("stdlib") == true, "contains stdlib")
  assert("aipl_stdlib".contains("xyz") == false, "does not contain xyz")
  assert("".contains("a") == false, "empty string does not contain a")
  assert("aipl".contains("aipl") == true, "string contains itself")
  ret 0
```

---

### `split` (`<compiler_builtins>`)

- **Signature**: `builtin fn (self: str) split(delim: str): [str]`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `self: str` | **Parameters**: `delim: str` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Split CSV token string `"a,b,c".split(",")` into 3 segments `["a", "b", "c"]`.

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

---

### `trim` (`<compiler_builtins>`)

- **Signature**: `builtin fn (self: str) trim(): str`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `self: str` | **Parameters**: `none` | **Returns**: `str`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Strip leading and trailing spaces, tabs, and newlines from `"  \t\naipl\n ".trim()` -> `"aipl"`.

```aipl
module tests.functions.core.compiler_builtins_trim_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_trim(): int:
  assertEqStr("  \t\naipl\n ".trim(), "aipl", "strips surrounding whitespace")
  assertEqStr("   ".trim(), "", "all-whitespace -> empty")
  assertEqStr("".trim(), "", "empty -> empty")
  assertEqStr("aipl".trim().trim(), "aipl", "idempotent trim")
  ret 0
```

---

### `replace` (`<compiler_builtins>`)

- **Signature**: `builtin fn (self: str) replace(old: str, new: str): str`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `self: str` | **Parameters**: `old: str, new: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Replace all occurrences in `"foo_bar_foo".replace("foo", "baz")` -> `"baz_bar_baz"`.

```aipl
module tests.functions.core.compiler_builtins_replace_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_replace(): int:
  assertEqStr("foo_bar_foo".replace("foo", "baz"), "baz_bar_baz", "replaces all matches")
  assertEqStr("aipl".replace("xyz", "q"), "aipl", "unmatched unchanged")
  assertEqStr("a_b_c".replace("_", ""), "abc", "deletion replacement")
  ret 0
```

---

### `startsWith` (`<compiler_builtins>`)

- **Signature**: `builtin fn (self: str) startsWith(prefix: str): bool`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `self: str` | **Parameters**: `prefix: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Verify prefix check `"std/math/vec".startsWith("std/") == true` and `"std/math".startsWith("gfx") == false`.

```aipl
module tests.functions.core.compiler_builtins_startsWith_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_startsWith(): int:
  assert("std/math/vec".startsWith("std/") == true, "matches prefix std/")
  assert("std/math".startsWith("gfx") == false, "rejects non-prefix")
  assert("std/math".startsWith("") == true, "empty prefix always true")
  ret 0
```

---

### `endsWith` (`<compiler_builtins>`)

- **Signature**: `builtin fn (self: str) endsWith(suffix: str): bool`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `self: str` | **Parameters**: `suffix: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Verify suffix check `"ex_001.aipl".endsWith(".aipl") == true` and `"ex_001.aipl".endsWith(".c") == false`.

```aipl
module tests.functions.core.compiler_builtins_endsWith_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_endsWith(): int:
  assert("ex_001.aipl".endsWith(".aipl") == true, "matches .aipl suffix")
  assert("ex_001.aipl".endsWith(".c") == false, "rejects .c suffix")
  assert("ex_001.aipl".endsWith("") == true, "empty suffix always true")
  ret 0
```

---

### `toUpper` (`<compiler_builtins>`)

- **Signature**: `builtin fn (self: str) toUpper(): str`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `self: str` | **Parameters**: `none` | **Returns**: `str`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Convert mixed-case ASCII `"AiPl_123".toUpper()` to `"AIPL_123"`.

```aipl
module tests.functions.core.compiler_builtins_toUpper_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_toUpper(): int:
  assertEqStr("AiPl_123".toUpper(), "AIPL_123", "mixed case to upper")
  assertEqStr("".toUpper(), "", "empty to upper")
  assertEqStr("AIPL".toUpper(), "AIPL", "idempotent upper")
  ret 0
```

---

### `toLower` (`<compiler_builtins>`)

- **Signature**: `builtin fn (self: str) toLower(): str`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `self: str` | **Parameters**: `none` | **Returns**: `str`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Convert mixed-case ASCII `"AiPl_123".toLower()` to `"aipl_123"`.

```aipl
module tests.functions.core.compiler_builtins_toLower_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_toLower(): int:
  assertEqStr("AiPl_123".toLower(), "aipl_123", "mixed case to lower")
  assertEqStr("".toLower(), "", "empty to lower")
  assertEqStr("AiPl".toUpper().toLower(), "aipl", "upper then lower")
  ret 0
```

---

### `charAt` (`<compiler_builtins>`)

- **Signature**: `builtin fn (self: str) charAt(idx: int): str`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `self: str` | **Parameters**: `idx: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Extract single character at index `0` (`"aipl".charAt(0) == "a"`), middle index `2` (`"p"`), and last index `3` (`"l"`).

```aipl
module tests.functions.core.compiler_builtins_charAt_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_charAt(): int:
  let s = "aipl"
  assertEqStr(s.charAt(0), "a", "idx 0 -> a")
  assertEqStr(s.charAt(2), "p", "idx 2 -> p")
  assertEqStr(s.charAt(3), "l", "idx 3 -> l")
  assertEqStr(s.charAt(1), s.slice(1, 2), "charAt matches 1-char slice")
  ret 0
```

---

### `indexOf` (`<compiler_builtins>`)

- **Signature**: `builtin fn (self: str) indexOf(sub: str): int`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `self: str` | **Parameters**: `sub: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Locate substring offset in `"hello world".indexOf("world") == 6`.

```aipl
module tests.functions.core.compiler_builtins_indexOf_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_indexOf(): int:
  assertEqInt("hello world".indexOf("world"), 6, "world at offset 6")
  assertEqInt("hello world".indexOf("hello"), 0, "hello at offset 0")
  assertEqInt("hello world".indexOf("xyz"), -1, "missing returns -1")
  ret 0
```

---

### `Map.set` (`<compiler_builtins>`)

- **Signature**: `builtin fn (mut self: Map[K, V]) set(key: K, val: V): void`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `mut self: Map[K, V]` | **Parameters**: `key: K, val: V` | **Returns**: `void`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Insert key-value pairs `m.set("a", 10)` and `m.set("b", 20)` into `Map[str, int]`.

```aipl
module tests.functions.core.compiler_builtins_Map_set_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_Map_set(): int:
  mut m: Map[str, int] = Map()
  m.set("a", 10)
  m.set("b", 20)
  assertEqInt(m.keys().len(), 2, "2 keys inserted")
  m.set("a", 99)
  assertEqInt(m.keys().len(), 2, "overwrite preserves key count")
  assertEqInt(m.get("a").unwrap(), 99, "overwritten value is 99")
  ret 0
```

---

### `Map.get` (`<compiler_builtins>`)

- **Signature**: `builtin fn (self: Map[K, V]) get(key: K): Option[V]`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `self: Map[K, V]` | **Parameters**: `key: K` | **Returns**: `Option[V]`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Retrieve present key `m.get("k")` returning `Some(42)`.

```aipl
module tests.functions.core.compiler_builtins_Map_get_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_Map_get(): int:
  mut m: Map[str, int] = Map()
  m.set("k", 42)
  assert(m.get("k").isSome() == true, "present key isSome")
  assertEqInt(m.get("k").unwrap(), 42, "unwraps to 42")
  assert(m.get("missing").isNone() == true, "absent key isNone")
  ret 0
```

---

### `Map.has` (`<compiler_builtins>`)

- **Signature**: `builtin fn (self: Map[K, V]) has(key: K): bool`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `self: Map[K, V]` | **Parameters**: `key: K` | **Returns**: `bool`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Check key membership `m.has("alpha") == true` after insertion.

```aipl
module tests.functions.core.compiler_builtins_Map_has_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_Map_has(): int:
  mut m: Map[str, int] = Map()
  assert(m.has("alpha") == false, "initially false")
  m.set("alpha", 1)
  assert(m.has("alpha") == true, "true after set")
  m.delete("alpha")
  assert(m.has("alpha") == false, "false after delete")
  ret 0
```

---

### `Map.delete` (`<compiler_builtins>`)

- **Signature**: `builtin fn (mut self: Map[K, V]) delete(key: K): void`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `mut self: Map[K, V]` | **Parameters**: `key: K` | **Returns**: `void`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Delete existing key `m.delete("k")` from `Map[str, int]`.

```aipl
module tests.functions.core.compiler_builtins_Map_delete_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_Map_delete(): int:
  mut m: Map[str, int] = Map()
  m.set("x", 10)
  m.set("y", 20)
  m.delete("x")
  assert(m.has("x") == false, "x removed")
  assert(m.has("y") == true, "y retained")
  m.delete("nonexistent")
  assertEqInt(m.keys().len(), 1, "1 key remains")
  ret 0
```

---

### `Map.keys` (`<compiler_builtins>`)

- **Signature**: `builtin fn (self: Map[K, V]) keys(): [K]`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `self: Map[K, V]` | **Parameters**: `none` | **Returns**: `[K]`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Extract key array `m.keys()` from a populated map.

```aipl
module tests.functions.core.compiler_builtins_Map_keys_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_Map_keys(): int:
  mut m: Map[str, int] = Map()
  assertEqInt(m.keys().len(), 0, "empty map has 0 keys")
  m.set("k1", 1)
  m.set("k2", 2)
  let ks = m.keys()
  assertEqInt(ks.len(), 2, "2 keys returned")
  assert(m.has(ks[0]) and m.has(ks[1]), "all returned keys exist in map")
  ret 0
```

---

### `abs` (`<compiler_builtins>`)

- **Signature**: `builtin fn abs(x: int | float): int | float`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `None (free function)` | **Parameters**: `x: int | float` | **Returns**: `int | float`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Compute magnitude of negative integer `abs(-42) == 42` and positive integer `abs(42) == 42`.

```aipl
module tests.functions.core.compiler_builtins_abs_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_abs(): int:
  assertEqInt(abs(-42), 42, "abs(-42) == 42")
  assertEqInt(abs(42), 42, "abs(42) == 42")
  assertEqInt(abs(0), 0, "abs(0) == 0")
  ret 0
```

---

### `sqrt` (`<compiler_builtins>`)

- **Signature**: `builtin fn sqrt(x: float): float`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `None (free function)` | **Parameters**: `x: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Compute principal square root of perfect square `sqrt(144.0) == 12.0` and irrational `sqrt(2.0)`.

```aipl
module tests.functions.core.compiler_builtins_sqrt_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_sqrt(): int:
  assertApproxEq(sqrt(0.0), 0.0, 0.000001, "sqrt(0) == 0")
  assertApproxEq(sqrt(1.0), 1.0, 0.000001, "sqrt(1) == 1")
  assertApproxEq(sqrt(144.0), 12.0, 0.000001, "sqrt(144) == 12")
  let r2 = sqrt(2.0)
  assertApproxEq(r2 * r2, 2.0, 0.000001, "sqrt(2)^2 == 2")
  ret 0
```

---

### `sin_cos` (`<compiler_builtins>`)

- **Signature**: `builtin fn sin(x: float): float / builtin fn cos(x: float): float`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `None (free function)` | **Parameters**: `x: float): float / builtin fn cos(x: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Evaluate `sin(0.0) == 0.0`, `cos(0.0) == 1.0`, and quadrant angles `PI/2`, `PI`.

```aipl
module tests.functions.core.compiler_builtins_sin_cos_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_sin_cos(): int:
  assertApproxEq(sin(0.0), 0.0, 0.000001, "sin(0) == 0")
  assertApproxEq(cos(0.0), 1.0, 0.000001, "cos(0) == 1")
  let s = sin(0.78539816339)
  let c = cos(0.78539816339)
  assertApproxEq(s * s + c * c, 1.0, 0.000001, "sin^2 + cos^2 == 1")
  ret 0
```

---

### `floor_ceil` (`<compiler_builtins>`)

- **Signature**: `builtin fn floor(x: float): float / builtin fn ceil(x: float): float`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `None (free function)` | **Parameters**: `x: float): float / builtin fn ceil(x: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Round fractional values `floor(2.9) == 2.0` and `ceil(2.1) == 3.0`.

```aipl
module tests.functions.core.compiler_builtins_floor_ceil_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_floor_ceil(): int:
  assertApproxEq(floor(2.9), 2.0, 0.000001, "floor(2.9) == 2.0")
  assertApproxEq(floor(-2.1), -3.0, 0.000001, "floor(-2.1) == -3.0")
  assertApproxEq(ceil(2.1), 3.0, 0.000001, "ceil(2.1) == 3.0")
  assertApproxEq(ceil(-2.9), -2.0, 0.000001, "ceil(-2.9) == -2.0")
  ret 0
```

---

### `pow` (`<compiler_builtins>`)

- **Signature**: `builtin fn pow(base: float, exp: float): float`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `None (free function)` | **Parameters**: `base: float, exp: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Compute exponentiation `pow(2.0, 10.0) == 1024.0` and fractional exponent `pow(9.0, 0.5) == 3.0`.

```aipl
module tests.functions.core.compiler_builtins_pow_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_pow(): int:
  assertApproxEq(pow(2.0, 10.0), 1024.0, 0.000001, "2^10 == 1024")
  assertApproxEq(pow(5.0, 0.0), 1.0, 0.000001, "5^0 == 1")
  assertApproxEq(pow(9.0, 0.5), 3.0, 0.000001, "9^0.5 == 3")
  ret 0
```

---

### `rgb` (`<compiler_builtins>`)

- **Signature**: `builtin fn rgb(r: int, g: int, b: int): int`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `None (free function)` | **Parameters**: `r: int, g: int, b: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Pack 8-bit channels `rgb(255, 0, 128)` into 24-bit color integer `16711808` (`0xFF0080`).

```aipl
module tests.functions.core.compiler_builtins_rgb_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_rgb(): int:
  let c = rgb(255, 0, 128)
  assertEqInt(c, 16711808, "rgb(255, 0, 128) == 0xFF0080")
  assertEqInt(rgb(0, 0, 0), 0, "black == 0")
  assertEqInt(rgb(255, 255, 255), 16777215, "white == 0xFFFFFF")
  ret 0
```

---

### `print_println` (`<compiler_builtins>`)

- **Signature**: `builtin fn print(s: any): void / builtin fn println(s: any): void`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `None (free function)` | **Parameters**: `s: any): void / builtin fn println(s: any` | **Returns**: `void`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Emit formatted string and numeric diagnostics to standard output via `print` and `println`.

```aipl
module tests.functions.core.compiler_builtins_print_println_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_print_println(): int:
  let msg = "AIPL builtin print/println smoke ok"
  print("")
  println(msg)
  assertEqInt(msg.len(), 35, "stdout emission completed without error")
  ret 0
```

---

### `assert_builtin` (`<compiler_builtins>`)

- **Signature**: `builtin fn assert(cond: bool, msg: str): void`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `None (free function)` | **Parameters**: `cond: bool, msg: str` | **Returns**: `void`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Verify truthy condition `assert(2 + 2 == 4, "math ok")` passes silently.

```aipl
module tests.functions.core.compiler_builtins_assert_builtin_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_assert_builtin(): int:
  assert(2 + 2 == 4, "arithmetic assertion")
  assert(true and not false, "boolean assertion")
  ret 0
```

---

### `panic_todo_builtin` (`<compiler_builtins>`)

- **Signature**: `builtin fn panic(msg: str): void / builtin fn todo(msg: str): void`
- **Import**: // Compiler built-in intrinsic (globally available without import)
- **Receiver**: `None (free function)` | **Parameters**: `msg: str): void / builtin fn todo(msg: str` | **Returns**: `void`
- **Unit Test**: `tests/functions/core/compiler_builtins_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Verify unreachable guard branches containing `panic(msg)` and `todo(msg)` typecheck and compile cleanly.

```aipl
module tests.functions.core.compiler_builtins_panic_todo_builtin_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_panic_todo_builtin(): int:
  let guardOk = true
  if not guardOk:
    panic("unreachable panic branch")
    todo("unreachable todo branch")
  assert(guardOk == true, "guarded panic/todo branches compiled cleanly")
  ret 0
```

---

### `stdlibVersion` (`std/std_root.aipl`)

- **Signature**: `pub fn stdlibVersion(): StdlibVersion:`
- **Import**: `import * from "std/std_root"`
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `StdlibVersion`
- **Unit Test**: `tests/functions/core/std_root_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Retrieve `StdlibVersion` struct and verify `major == 4`, `minor == 0`, `patch == 0`, `prerelease == ""`.

```aipl
module tests.functions.core.std_root_stdlibVersion_test
import * from "std/std_root"
import * from "std/prelude"

pub fn test_std_root_stdlibVersion(): int:
  let v = stdlibVersion()
  assertEqInt(v.major, 4, "major == 4")
  assertEqInt(v.minor, 0, "minor == 0")
  assertEqInt(v.patch, 0, "patch == 0")
  assertEqStr(v.prerelease, "", "prerelease empty")
  ret 0
```

---

### `stdlibVersionString` (`std/std_root.aipl`)

- **Signature**: `pub fn stdlibVersionString(): str:`
- **Import**: `import * from "std/std_root"`
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `str`
- **Unit Test**: `tests/functions/core/std_root_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Format standard library semantic version string `stdlibVersionString() == "4.0.0"`.

```aipl
module tests.functions.core.std_root_stdlibVersionString_test
import * from "std/std_root"
import * from "std/prelude"

pub fn test_std_root_stdlibVersionString(): int:
  let v = stdlibVersion()
  let s = stdlibVersionString()
  assertEqStr(s, "4.0.0", "version string is 4.0.0")
  assertEqStr(s, str(v.major) + "." + str(v.minor) + "." + str(v.patch), "matches struct fields")
  ret 0
```

---

### `stdlibBuildTarget` (`std/std_root.aipl`)

- **Signature**: `pub fn stdlibBuildTarget(): str:`
- **Import**: `import * from "std/std_root"`
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `str`
- **Unit Test**: `tests/functions/core/std_root_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Query active build target identifier `stdlibBuildTarget() == "native"`.

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

---

### `stdlibHasFeature` (`std/std_root.aipl`)

- **Signature**: `pub fn stdlibHasFeature(feature: str): bool:`
- **Import**: `import * from "std/std_root"`
- **Receiver**: `None (free function)` | **Parameters**: `feature: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/core/std_root_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Test active features `"native"`, `"c99"`, `"wasm"`, `"html"`, `"simd"`, `"ecs"` returning `true`.

```aipl
module tests.functions.core.std_root_stdlibHasFeature_test
import * from "std/std_root"
import * from "std/prelude"

pub fn test_std_root_stdlibHasFeature(): int:
  assert(stdlibHasFeature("native") == true, "native enabled")
  assert(stdlibHasFeature("  SIMD ") == true, "case-insensitive trimmed SIMD enabled")
  assert(stdlibHasFeature("nonexistent_xyz") == false, "unknown feature false")
  assert(stdlibHasFeature("") == false, "empty feature false")
  ret 0
```

---

### `stdlibDomainCount` (`std/std_root.aipl`)

- **Signature**: `pub fn stdlibDomainCount(): int:`
- **Import**: `import * from "std/std_root"`
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/core/std_root_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Return exact canonical domain subdirectory count `stdlibDomainCount() == 37`.

```aipl
module tests.functions.core.std_root_stdlibDomainCount_test
import * from "std/std_root"
import * from "std/prelude"

pub fn test_std_root_stdlibDomainCount(): int:
  assertEqInt(stdlibDomainCount(), 37, "37 canonical domains")
  assertEqInt(stdlibDomainCount(), stdlibCanonicalDomains().len(), "matches array length")
  ret 0
```

---

### `stdlibLayerCount` (`std/std_root.aipl`)

- **Signature**: `pub fn stdlibLayerCount(): int:`
- **Import**: `import * from "std/std_root"`
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/core/std_root_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Return architectural layer count `stdlibLayerCount() == 6` (Layers 0 through 5).

```aipl
module tests.functions.core.std_root_stdlibLayerCount_test
import * from "std/std_root"
import * from "std/prelude"

pub fn test_std_root_stdlibLayerCount(): int:
  assertEqInt(stdlibLayerCount(), 6, "6 layers (0..5)")
  ret 0
```

---

### `stdlibCanonicalDomains` (`std/std_root.aipl`)

- **Signature**: `pub fn stdlibCanonicalDomains(): [str]:`
- **Import**: `import * from "std/std_root"`
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/core/std_root_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Return ordered list of all 37 canonical domain names from `"sys"` (index 0) to `"mechanics"` (index 36).

```aipl
module tests.functions.core.std_root_stdlibCanonicalDomains_test
import * from "std/std_root"
import * from "std/prelude"

pub fn test_std_root_stdlibCanonicalDomains(): int:
  let doms = stdlibCanonicalDomains()
  assertEqInt(doms.len(), 37, "37 domains")
  assertEqStr(doms[0], "sys", "first domain is sys")
  assertEqStr(doms[36], "mechanics", "last domain is mechanics")
  ret 0
```

---

### `stdlibIsCanonicalDomain` (`std/std_root.aipl`)

- **Signature**: `pub fn stdlibIsCanonicalDomain(domain: str): bool:`
- **Import**: `import * from "std/std_root"`
- **Receiver**: `None (free function)` | **Parameters**: `domain: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/core/std_root_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Verify `stdlibIsCanonicalDomain("math") == true`, `"ui" -> true`, `"phys3d" -> true`.

```aipl
module tests.functions.core.std_root_stdlibIsCanonicalDomain_test
import * from "std/std_root"
import * from "std/prelude"

pub fn test_std_root_stdlibIsCanonicalDomain(): int:
  assert(stdlibIsCanonicalDomain("math") == true, "math is canonical")
  assert(stdlibIsCanonicalDomain("ui") == true, "ui is canonical")
  assert(stdlibIsCanonicalDomain("") == false, "empty string false")
  assert(stdlibIsCanonicalDomain("foobar") == false, "foobar false")
  ret 0
```

---

### `stdlibDomainLayer` (`std/std_root.aipl`)

- **Signature**: `pub fn stdlibDomainLayer(domain: str): int:`
- **Import**: `import * from "std/std_root"`
- **Receiver**: `None (free function)` | **Parameters**: `domain: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/core/std_root_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Verify DAG layer numbers: `"sys" -> 0`, `"math" -> 1`, `"encoding" -> 2`, `"io" -> 3`, `"gfx2d" -> 4`, `"mechanics" -> 5`.

```aipl
module tests.functions.core.std_root_stdlibDomainLayer_test
import * from "std/std_root"
import * from "std/prelude"

pub fn test_std_root_stdlibDomainLayer(): int:
  assertEqInt(stdlibDomainLayer("sys"), 0, "sys -> layer 0")
  assertEqInt(stdlibDomainLayer("math"), 1, "math -> layer 1")
  assertEqInt(stdlibDomainLayer("encoding"), 2, "encoding -> layer 2")
  assertEqInt(stdlibDomainLayer("io"), 3, "io -> layer 3")
  assertEqInt(stdlibDomainLayer("gfx2d"), 4, "gfx2d -> layer 4")
  assertEqInt(stdlibDomainLayer("mechanics"), 5, "mechanics -> layer 5")
  assertEqInt(stdlibDomainLayer("unknown"), -1, "unknown -> -1")
  ret 0
```

---

### `stdlibDomainBarrelPath` (`std/std_root.aipl`)

- **Signature**: `pub fn stdlibDomainBarrelPath(domain: str): str:`
- **Import**: `import * from "std/std_root"`
- **Receiver**: `None (free function)` | **Parameters**: `domain: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/core/std_root_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Resolve barrel paths: `"math" -> "std/math/math_mod.aipl"`, `"prelude" -> "std/prelude.aipl"`, `"std_root" -> "std/std_root.aipl"`.

```aipl
module tests.functions.core.std_root_stdlibDomainBarrelPath_test
import * from "std/std_root"
import * from "std/prelude"

pub fn test_std_root_stdlibDomainBarrelPath(): int:
  assertEqStr(stdlibDomainBarrelPath("math"), "std/math/math_mod.aipl", "math barrel path")
  assertEqStr(stdlibDomainBarrelPath("prelude"), "std/prelude.aipl", "prelude path")
  assertEqStr(stdlibDomainBarrelPath("std_root"), "std/std_root.aipl", "std_root path")
  assertEqStr(stdlibDomainBarrelPath("invalid"), "", "invalid -> empty")
  ret 0
```

---

### `stdlibCanImportLayer` (`std/std_root.aipl`)

- **Signature**: `pub fn stdlibCanImportLayer(fromLayer: int, toLayer: int): bool:`
- **Import**: `import * from "std/std_root"`
- **Receiver**: `None (free function)` | **Parameters**: `fromLayer: int, toLayer: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/core/std_root_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Verify downward/same-layer imports allowed (`stdlibCanImportLayer(5, 1) == true`, `stdlibCanImportLayer(2, 2) == true`) and upward forbidden (`stdlibCanImportLayer(1, 4) == false`).

```aipl
module tests.functions.core.std_root_stdlibCanImportLayer_test
import * from "std/std_root"
import * from "std/prelude"

pub fn test_std_root_stdlibCanImportLayer(): int:
  assert(stdlibCanImportLayer(5, 1) == true, "layer 5 can import layer 1")
  assert(stdlibCanImportLayer(2, 2) == true, "same layer allowed")
  assert(stdlibCanImportLayer(1, 4) == false, "upward import forbidden")
  assert(stdlibCanImportLayer(-1, 0) == false, "negative fromLayer rejected")
  ret 0
```

---

### `stdlibCanDomainImport` (`std/std_root.aipl`)

- **Signature**: `pub fn stdlibCanDomainImport(fromDomain: str, toDomain: str): bool:`
- **Import**: `import * from "std/std_root"`
- **Receiver**: `None (free function)` | **Parameters**: `fromDomain: str, toDomain: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/core/std_root_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Verify `stdlibCanDomainImport("mechanics", "math") == true` and `stdlibCanDomainImport("math", "ui") == false`.

```aipl
module tests.functions.core.std_root_stdlibCanDomainImport_test
import * from "std/std_root"
import * from "std/prelude"

pub fn test_std_root_stdlibCanDomainImport(): int:
  assert(stdlibCanDomainImport("mechanics", "math") == true, "mechanics (L5) -> math (L1) allowed")
  assert(stdlibCanDomainImport("math", "ui") == false, "math (L1) -> ui (L4) forbidden")
  assert(stdlibCanDomainImport("unknown", "math") == false, "unknown domain rejected")
  ret 0
```

---

### `Some` (`std/prelude.aipl`)

- **Signature**: `pub fn Some(val: any):`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Construct `Option` carrying value `Some(42)` and `Some("aipl")`.

```aipl
module tests.functions.core.prelude_Some_test
import * from "std/prelude"

pub fn test_prelude_Some(): int:
  let a = Some(42)
  let b = Some(0)
  assert(a.isSome() == true, "Some(42) isSome")
  assertEqInt(a.unwrap(), 42, "Some(42) unwraps to 42")
  assert(b.isSome() == true, "Some(0) isSome")
  assertEqInt(b.unwrap(), 0, "Some(0) unwraps to 0")
  ret 0
```

---

### `None` (`std/prelude.aipl`)

- **Signature**: `pub fn None():`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Construct empty `Option` via `None()`.

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

---

### `Option.isSome` (`std/prelude.aipl`)

- **Signature**: `pub fn (self: Option[T]) isSome(): bool:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `self: Option[T]` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Verify `Some(10).isSome() == true`.

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

---

### `Option.isNone` (`std/prelude.aipl`)

- **Signature**: `pub fn (self: Option[T]) isNone(): bool:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `self: Option[T]` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Verify `None().isNone() == true` and `Some(10).isNone() == false`.

```aipl
module tests.functions.core.prelude_Option_isNone_test
import * from "std/prelude"

pub fn test_prelude_Option_isNone(): int:
  let n: Option[int] = None()
  assert(n.isNone() == true, "None isNone == true")
  assert(Some(0).isNone() == false, "Some(0) isNone == false")
  ret 0
```

---

### `Option.unwrap` (`std/prelude.aipl`)

- **Signature**: `pub fn (self: Option[T]) unwrap(): T:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `self: Option[T]` | **Parameters**: `none` | **Returns**: `T`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Extract payload from `Some(99).unwrap() == 99` and `Some("ok").unwrap() == "ok"`.

```aipl
module tests.functions.core.prelude_Option_unwrap_test
import * from "std/prelude"

pub fn test_prelude_Option_unwrap(): int:
  assertEqInt(Some(99).unwrap(), 99, "unwraps 99")
  assertEqInt(Some(-1).unwrap(), -1, "unwraps -1")
  assertEqStr(Some("ok").unwrap(), "ok", "unwraps ok")
  ret 0
```

---

### `Option.unwrapOr` (`std/prelude.aipl`)

- **Signature**: `pub fn (self: Option[T]) unwrapOr(defaultVal: T): T:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `self: Option[T]` | **Parameters**: `defaultVal: T` | **Returns**: `T`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Return inner value on `Some(10).unwrapOr(99) == 10` and fallback on `None().unwrapOr(99) == 99`.

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

---

### `Ok` (`std/prelude.aipl`)

- **Signature**: `pub fn Ok(val: any):`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Construct successful `Result` via `Ok(200)`.

```aipl
module tests.functions.core.prelude_Ok_test
import * from "std/prelude"

pub fn test_prelude_Ok(): int:
  let r: Result[int, str] = Ok(200)
  assert(r.isOk() == true, "Ok(200) isOk")
  assertEqInt(r.unwrap(), 200, "Ok(200) unwraps to 200")
  ret 0
```

---

### `Err` (`std/prelude.aipl`)

- **Signature**: `pub fn Err(err: any):`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Construct error `Result` via `Err("E_IO")`.

```aipl
module tests.functions.core.prelude_Err_test
import * from "std/prelude"

pub fn test_prelude_Err(): int:
  let r: Result[int, str] = Err("E_IO")
  assert(r.isErr() == true, "Err isErr == true")
  assertEqStr(r.unwrapErr(), "E_IO", "unwrapErr == E_IO")
  ret 0
```

---

### `Result.isOk` (`std/prelude.aipl`)

- **Signature**: `pub fn (self: Result[T, E]) isOk(): bool:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `self: Result[T, E]` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Verify `Ok(1).isOk() == true` and `Err("bad").isOk() == false`.

```aipl
module tests.functions.core.prelude_Result_isOk_test
import * from "std/prelude"

pub fn test_prelude_Result_isOk(): int:
  let okRes: Result[int, str] = Ok(0)
  let errRes: Result[int, str] = Err("bad")
  assert(okRes.isOk() == true, "Ok(0) isOk")
  assert(errRes.isOk() == false, "Err isOk == false")
  ret 0
```

---

### `Result.isErr` (`std/prelude.aipl`)

- **Signature**: `pub fn (self: Result[T, E]) isErr(): bool:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `self: Result[T, E]` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Verify `Err("bad").isErr() == true` and `Ok(1).isErr() == false`.

```aipl
module tests.functions.core.prelude_Result_isErr_test
import * from "std/prelude"

pub fn test_prelude_Result_isErr(): int:
  let okRes: Result[int, str] = Ok(1)
  let errRes: Result[int, str] = Err("")
  assert(errRes.isErr() == true, "Err isErr == true")
  assert(okRes.isErr() == false, "Ok isErr == false")
  ret 0
```

---

### `Result.unwrap` (`std/prelude.aipl`)

- **Signature**: `pub fn (self: Result[T, E]) unwrap(): T:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `self: Result[T, E]` | **Parameters**: `none` | **Returns**: `T`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Extract value from `Ok(777).unwrap() == 777`.

```aipl
module tests.functions.core.prelude_Result_unwrap_test
import * from "std/prelude"

pub fn test_prelude_Result_unwrap(): int:
  let r1: Result[int, str] = Ok(777)
  let r2: Result[int, str] = Ok(-42)
  assertEqInt(r1.unwrap(), 777, "unwrap 777")
  assertEqInt(r2.unwrap(), -42, "unwrap -42")
  ret 0
```

---

### `Result.unwrapErr` (`std/prelude.aipl`)

- **Signature**: `pub fn (self: Result[T, E]) unwrapErr(): E:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `self: Result[T, E]` | **Parameters**: `none` | **Returns**: `E`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Extract error payload from `Err("E_TIMEOUT").unwrapErr() == "E_TIMEOUT"`.

```aipl
module tests.functions.core.prelude_Result_unwrapErr_test
import * from "std/prelude"

pub fn test_prelude_Result_unwrapErr(): int:
  let r: Result[int, str] = Err("E_TIMEOUT")
  assertEqStr(r.unwrapErr(), "E_TIMEOUT", "unwrapErr == E_TIMEOUT")
  ret 0
```

---

### `Result.unwrapOr` (`std/prelude.aipl`)

- **Signature**: `pub fn (self: Result[T, E]) unwrapOr(defaultVal: T): T:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `self: Result[T, E]` | **Parameters**: `defaultVal: T` | **Returns**: `T`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Verify `Ok(5).unwrapOr(0) == 5` and `Err("fail").unwrapOr(42) == 42`.

```aipl
module tests.functions.core.prelude_Result_unwrapOr_test
import * from "std/prelude"

pub fn test_prelude_Result_unwrapOr(): int:
  let okRes: Result[int, str] = Ok(5)
  let errRes: Result[int, str] = Err("fail")
  assertEqInt(okRes.unwrapOr(0), 5, "Ok returns 5")
  assertEqInt(errRes.unwrapOr(42), 42, "Err returns fallback 42")
  ret 0
```

---

### `panic` (`std/prelude.aipl`)

- **Signature**: `pub fn panic(message: str): void:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `None (free function)` | **Parameters**: `message: str` | **Returns**: `void`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Verify `panic(message)` contract in guarded unreachable branch.

```aipl
module tests.functions.core.prelude_panic_test
import * from "std/prelude"

pub fn test_prelude_panic(): int:
  let valid = true
  if not valid:
    panic("fatal invariant breach")
  assert(valid == true, "panic guard verified")
  ret 0
```

---

### `todo` (`std/prelude.aipl`)

- **Signature**: `pub fn todo(message: str): void:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `None (free function)` | **Parameters**: `message: str` | **Returns**: `void`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Verify `todo(message)` stub helper in guarded branch.

```aipl
module tests.functions.core.prelude_todo_test
import * from "std/prelude"

pub fn test_prelude_todo(): int:
  let implemented = true
  if not implemented:
    todo("future path")
  assert(implemented == true, "todo guard verified")
  ret 0
```

---

### `unreachable` (`std/prelude.aipl`)

- **Signature**: `pub fn unreachable(message: str): void:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `None (free function)` | **Parameters**: `message: str` | **Returns**: `void`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Verify `unreachable(message)` exhaustiveness guard in `match`/conditional branch.

```aipl
module tests.functions.core.prelude_unreachable_test
import * from "std/prelude"

pub fn test_prelude_unreachable(): int:
  let mode = 1
  if mode != 1:
    unreachable("mode is fixed to 1")
  assertEqInt(mode, 1, "unreachable guard verified")
  ret 0
```

---

### `assert` (`std/prelude.aipl`)

- **Signature**: `pub fn assert(cond: bool, message: str): void:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `None (free function)` | **Parameters**: `cond: bool, message: str` | **Returns**: `void`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Verify `assert(cond, message)` passes on `true`.

```aipl
module tests.functions.core.prelude_assert_test
import * from "std/prelude"

pub fn test_prelude_assert(): int:
  assert(true, "simple true")
  assert(10 > 5 and 0 == 0, "compound boolean")
  ret 0
```

---

### `assertEqInt` (`std/prelude.aipl`)

- **Signature**: `pub fn assertEqInt(actual: int, expected: int, message: str): void:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `None (free function)` | **Parameters**: `actual: int, expected: int, message: str` | **Returns**: `void`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Verify integer equality assertion on positive `42`, zero `0`, and negative `-500`.

```aipl
module tests.functions.core.prelude_assertEqInt_test
import * from "std/prelude"

pub fn test_prelude_assertEqInt(): int:
  assertEqInt(42, 42, "positive int")
  assertEqInt(0, 0, "zero int")
  assertEqInt(-500, -500, "negative int")
  ret 0
```

---

### `assertEqStr` (`std/prelude.aipl`)

- **Signature**: `pub fn assertEqStr(actual: str, expected: str, message: str): void:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `None (free function)` | **Parameters**: `actual: str, expected: str, message: str` | **Returns**: `void`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Verify string equality assertion on ASCII `"aipl"` and multi-line strings.

```aipl
module tests.functions.core.prelude_assertEqStr_test
import * from "std/prelude"

pub fn test_prelude_assertEqStr(): int:
  assertEqStr("", "", "empty string")
  assertEqStr("aipl", "aipl", "ascii string")
  assertEqStr("a\nb", "a\nb", "multiline string")
  ret 0
```

---

### `assertApproxEq` (`std/prelude.aipl`)

- **Signature**: `pub fn assertApproxEq(actual: float, expected: float, eps: float, message: str): void:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `None (free function)` | **Parameters**: `actual: float, expected: float, eps: float, message: str` | **Returns**: `void`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Verify IEEE-754 approximate equality `assertApproxEq(0.1 + 0.2, 0.3, 0.000001, "ieee754")`.

```aipl
module tests.functions.core.prelude_assertApproxEq_test
import * from "std/prelude"

pub fn test_prelude_assertApproxEq(): int:
  assertApproxEq(0.1 + 0.2, 0.3, 0.000001, "0.1 + 0.2 ~= 0.3")
  assertApproxEq(0.0, 0.0, 0.0, "exact 0.0")
  assertApproxEq(-1.5, -1.5, 0.0001, "negative float")
  ret 0
```

---

### `minInt` (`std/prelude.aipl`)

- **Signature**: `pub fn minInt(a: int, b: int): int:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `None (free function)` | **Parameters**: `a: int, b: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Compute minimum of two integers `minInt(5, 10) == 5` and `minInt(-10, -5) == -10`.

```aipl
module tests.functions.core.prelude_minInt_test
import * from "std/prelude"

pub fn test_prelude_minInt(): int:
  assertEqInt(minInt(5, 10), 5, "minInt(5, 10) == 5")
  assertEqInt(minInt(-10, -5), -10, "minInt(-10, -5) == -10")
  assertEqInt(minInt(7, 7), 7, "minInt(7, 7) == 7")
  ret 0
```

---

### `maxInt` (`std/prelude.aipl`)

- **Signature**: `pub fn maxInt(a: int, b: int): int:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `None (free function)` | **Parameters**: `a: int, b: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Compute maximum of two integers `maxInt(5, 10) == 10` and `maxInt(-10, -5) == -5`.

```aipl
module tests.functions.core.prelude_maxInt_test
import * from "std/prelude"

pub fn test_prelude_maxInt(): int:
  assertEqInt(maxInt(5, 10), 10, "maxInt(5, 10) == 10")
  assertEqInt(maxInt(-10, -5), -5, "maxInt(-10, -5) == -5")
  assertEqInt(maxInt(7, 7), 7, "maxInt(7, 7) == 7")
  ret 0
```

---

### `clampInt` (`std/prelude.aipl`)

- **Signature**: `pub fn clampInt(v: int, lo: int, hi: int): int:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `None (free function)` | **Parameters**: `v: int, lo: int, hi: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Clamp integer `clampInt(6, 0, 10) == 6` within `[0, 10]`.

```aipl
module tests.functions.core.prelude_clampInt_test
import * from "std/prelude"

pub fn test_prelude_clampInt(): int:
  assertEqInt(clampInt(-5, 0, 10), 0, "below lo -> 0")
  assertEqInt(clampInt(6, 0, 10), 6, "within range -> 6")
  assertEqInt(clampInt(25, 0, 10), 10, "above hi -> 10")
  assertEqInt(clampInt(9, 4, 4), 4, "degenerate lo == hi -> 4")
  ret 0
```

---

### `minFloat` (`std/prelude.aipl`)

- **Signature**: `pub fn minFloat(a: float, b: float): float:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `None (free function)` | **Parameters**: `a: float, b: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Compute minimum of two floats `minFloat(-2.5, 1.5) == -2.5`.

```aipl
module tests.functions.core.prelude_minFloat_test
import * from "std/prelude"

pub fn test_prelude_minFloat(): int:
  assertApproxEq(minFloat(-2.5, 1.5), -2.5, 0.000001, "minFloat(-2.5, 1.5)")
  assertApproxEq(minFloat(0.0, 0.0), 0.0, 0.000001, "minFloat(0, 0)")
  ret 0
```

---

### `maxFloat` (`std/prelude.aipl`)

- **Signature**: `pub fn maxFloat(a: float, b: float): float:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `None (free function)` | **Parameters**: `a: float, b: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Compute maximum of two floats `maxFloat(-2.5, 1.5) == 1.5`.

```aipl
module tests.functions.core.prelude_maxFloat_test
import * from "std/prelude"

pub fn test_prelude_maxFloat(): int:
  assertApproxEq(maxFloat(-2.5, 1.5), 1.5, 0.000001, "maxFloat(-2.5, 1.5)")
  assertApproxEq(maxFloat(-10.0, -20.0), -10.0, 0.000001, "maxFloat(-10, -20)")
  ret 0
```

---

### `clampFloat` (`std/prelude.aipl`)

- **Signature**: `pub fn clampFloat(v: float, lo: float, hi: float): float:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `None (free function)` | **Parameters**: `v: float, lo: float, hi: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Clamp float `clampFloat(0.5, 0.0, 1.0) == 0.5`.

```aipl
module tests.functions.core.prelude_clampFloat_test
import * from "std/prelude"

pub fn test_prelude_clampFloat(): int:
  assertApproxEq(clampFloat(-0.5, 0.0, 1.0), 0.0, 0.000001, "below lo -> 0.0")
  assertApproxEq(clampFloat(0.5, 0.0, 1.0), 0.5, 0.000001, "interior -> 0.5")
  assertApproxEq(clampFloat(1.5, 0.0, 1.0), 1.0, 0.000001, "above hi -> 1.0")
  ret 0
```

---

### `inRangeInt` (`std/prelude.aipl`)

- **Signature**: `pub fn inRangeInt(v: int, lo: int, hi: int): bool:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `None (free function)` | **Parameters**: `v: int, lo: int, hi: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Check inclusive integer interval `inRangeInt(5, 0, 10) == true`.

```aipl
module tests.functions.core.prelude_inRangeInt_test
import * from "std/prelude"

pub fn test_prelude_inRangeInt(): int:
  assert(inRangeInt(0, 0, 10) == true, "lo inclusive")
  assert(inRangeInt(10, 0, 10) == true, "hi inclusive")
  assert(inRangeInt(-1, 0, 10) == false, "below lo false")
  assert(inRangeInt(11, 0, 10) == false, "above hi false")
  ret 0
```

---

### `inRangeFloat` (`std/prelude.aipl`)

- **Signature**: `pub fn inRangeFloat(v: float, lo: float, hi: float): bool:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `None (free function)` | **Parameters**: `v: float, lo: float, hi: float` | **Returns**: `bool`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Check inclusive float interval `inRangeFloat(0.5, 0.0, 1.0) == true`.

```aipl
module tests.functions.core.prelude_inRangeFloat_test
import * from "std/prelude"

pub fn test_prelude_inRangeFloat(): int:
  assert(inRangeFloat(0.0, 0.0, 1.0) == true, "0.0 inclusive")
  assert(inRangeFloat(1.0, 0.0, 1.0) == true, "1.0 inclusive")
  assert(inRangeFloat(-0.001, 0.0, 1.0) == false, "-0.001 false")
  assert(inRangeFloat(1.001, 0.0, 1.0) == false, "1.001 false")
  ret 0
```

---

### `boolToInt` (`std/prelude.aipl`)

- **Signature**: `pub fn boolToInt(b: bool): int:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `None (free function)` | **Parameters**: `b: bool` | **Returns**: `int`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_001_hello_world_and_io_cli.aipl`
- **Behavioral Summary**: Convert `boolToInt(true) == 1` and `boolToInt(false) == 0`.

```aipl
module tests.functions.core.prelude_boolToInt_test
import * from "std/prelude"

pub fn test_prelude_boolToInt(): int:
  assertEqInt(boolToInt(true), 1, "true -> 1")
  assertEqInt(boolToInt(false), 0, "false -> 0")
  ret 0
```

---

### `intToBool` (`std/prelude.aipl`)

- **Signature**: `pub fn intToBool(v: int): bool:`
- **Import**: `import * from "std/prelude"`
- **Receiver**: `None (free function)` | **Parameters**: `v: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/core/prelude_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Convert non-zero integer `intToBool(1) == true` and zero `intToBool(0) == false`.

```aipl
module tests.functions.core.prelude_intToBool_test
import * from "std/prelude"

pub fn test_prelude_intToBool(): int:
  assert(intToBool(0) == false, "0 -> false")
  assert(intToBool(1) == true, "1 -> true")
  assert(intToBool(-99) == true, "-99 -> true")
  assert(intToBool(boolToInt(true)) == true, "round-trip true")
  ret 0
```
