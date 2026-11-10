# AIPL Language Specification (v0.9.0)
**Single Source of Truth (SSOT) Mirror & Root Specification Hub**

[Home](README.md) | [Full Language Specification](docs/SPEC.md) | [Grammar & Syntax](docs/GRAMMAR_AND_SYNTAX.md) | [Build & Targets](docs/BUILD_AND_TARGETS.md) | [Memory Model](docs/MEMORY_MODEL.md) | [ADR Index](docs/ADR/INDEX.md)

> **When to Read This Document**: Read this root specification for an immediate, high-level summary of the AIPL language syntax, 2-space indentation offside rule, core type system, 32 compiler built-ins, and Design-by-Contract (`req:`/`ens:`) primitives. For the exhaustive language manual, refer to [`docs/SPEC.md`](docs/SPEC.md).

---

## Canonical Project Architecture & Counts

- **36 Standard Library Domain Groups**: `2` root modules (`std/std_root.aipl`, `std/prelude.aipl`) + `35` canonical domain directories = **`290` `std/` modules**.
- **4,324 Total Callable Functions**: **`32` compiler built-ins + `4,292` `std/` functions, constructors & receiver methods**.
- **263 Curated, Fully-Tested Examples**: `examples/ex_001_*.aipl` through `examples/ex_263_*.aipl` with twin unit tests in `tests/examples/` (including `ex_259` continuous 2.5D world, `ex_260` textured 2.5D village & river, `ex_261` textured 3D UV mesh gallery, `ex_262` dark-fantasy encampment ARPG, and `ex_263` isometric 8-dir rig & 2.5D lighting lab).
- **37 Architecture Decision Records**: `docs/ADR/ADR-0001-*.md` through `docs/ADR/ADR-0037-*.md` indexed in [`docs/ADR/INDEX.md`](docs/ADR/INDEX.md).

---

## Section 1: Root SPEC.md Canonical SSOT Synchronization Header & Pointer to docs/SPEC.md

Establish root `SPEC.md` as a 100% synchronized canonical mirror and quick-navigation entrypoint pointing to [`docs/SPEC.md`](docs/SPEC.md) with zero contradiction in grammar, semantics, or inventory counts.

AIPL is designed with three core architectural pillars:
1. **Machine-Tractable Tokenomics**: Every keyword, primitive, and indentation rule is co-designed with SentencePiece 256k tokenizers (Gemini/Gemma), achieving a **60%+ token reduction** over Python, TypeScript, and Rust.
2. **Deterministic Dual-Backend Execution**: Unified Canonical High-Level Intermediate Representation (Canonical HIR) bifurcating into pure TypeScript/React 19 for the web and parallel C99 shards / Native ELF64 / WebAssembly for bare-metal systems.
3. **Anti-GC Flat-Stride Memory**: Zero tracing garbage collector pauses. Contiguous Structure of Arrays (SoA) layout combined with task-local regional bump arenas (`with arena:`) and generational object pools.

- **Primary Specification SSOT**: [`docs/SPEC.md`](docs/SPEC.md)
- **Primary Source Module**: `std/std_root.aipl` (`pub fn stdlibBuildTarget(): str:`)
- **Verification Test**: `tests/functions/core/std_root_test.aipl`
- **Runnable Example Reference**: `examples/ex_001_hello_world_and_io_cli.aipl` (tested by `tests/examples/ex_001_hello_world_and_io_cli_test.aipl`)

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

## Section 2: Lexical Structure, 2-Space Indentation & Core Type System Mirror

### 2.1 Lexical & Formatting Invariants
- **Indentation**: Strict 2-space block indentation (`  `). Tabs (`\t`) are strictly prohibited and trigger error `AIPL_E1001`.
- **Identifier Casing (ADR-0002)**: All variables, parameters, and function names must be `camelCase`. Structs, enums, and type aliases must be `PascalCase`. Underscores (`_`) are forbidden in identifier names, except for the wildcard pattern `_`, `test_*` functions, and `UPPER_SNAKE_CASE` constants.
- **Automatic Shortest-Syntax Canonicalization**: `aipl verify`, `check`, `build`, `run`, `test`, `transpile`, `lint`, `fmt`, `fix`, and `wire` transparently canonicalize `.aipl` files on disk into the shortest syntax (`:` over `{}`, `ret` over `return`, `elif` over `else if`, `): Type` over `) -> Type`, `and`/`or`/`not` over `&&`/`||`/`!`, single-line `fn(...)` and `struct Name(...)`, and `import { ... } from "std/..."`).
- **Comments**: Single-line comments begin with `//`. Multiline comments are enclosed in `/* ... */`.

### 2.2 Core Type System
AIPL enforces sound bidirectional type checking with zero implicit coercion (`AIPL_E2002`):

| Type | Syntax | Description | Example |
| :--- | :--- | :--- | :--- |
| **Integer** | `int`, `i8`..`i64`, `u8`..`u64` | Signed & unsigned sized integers | `let x: int = 42` |
| **Float** | `float`, `f32`, `f64` | IEEE-754 floating point numbers | `let pi: float = 3.14159` |
| **Boolean** | `bool` | Strict boolean values (`true`, `false`) | `let active: bool = true` |
| **String** | `str` | UTF-8 string with linear slicing | `let name: str = "AIPL"` |
| **Void** | `void` | Absence of value for side-effect functions | `pub fn log(): void:` |
| **Dynamic Array** | `[T]` | Flat contiguous array | `let nums: [int] = [1, 2, 3]` |
| **Hash Map** | `Map[K, V]` | Key-value associative hash map | `let m: Map[str, int] = Map()` |
| **Optional Value** | `Option[T]` | Algebraic sum type (`Some(v)` or `None()`) | `let opt: Option[int] = Some(10)` |
| **Result Value** | `Result[T, E]` | Algebraic error type (`Ok(v)` or `Err(e)`) | `let res: Result[int, str] = Ok(1)` |

- **Primary Source Module**: `std/prelude.aipl` (`pub fn Some(val: any):`)
- **Verification Test**: `tests/functions/core/prelude_test.aipl`
- **Runnable Example Reference**: `examples/ex_002_primitives_and_bitwise_cli.aipl` (tested by `tests/examples/ex_002_primitives_and_bitwise_cli_test.aipl`)

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

## Section 3: Canonical 32 Compiler Built-in Functions & Design-by-Contract (req:/ens:) Quick Table

### 3.1 The 32 Compiler Built-in Functions

AIPL provides exactly 32 core compiler built-ins available in every module without explicit import:

| Built-in Function | Signature / Usage | Purpose |
| :--- | :--- | :--- |
| `print(val)` / `println(val)` | `print(any): void` | Standard output stream writing without/with trailing newline |
| `int(val)` | `int(any): int` | Explicit conversion of float, string, or byte to integer |
| `float(val)` | `float(any): float` | Explicit conversion of int or string to float |
| `str(val)` | `str(any): str` | Explicit string representation of any primitive value |
| `bool(val)` | `bool(any): bool` | Explicit boolean conversion (no truthy coercion) |
| `len(coll)` | `len([T] \| str \| Map): int` | Number of elements in array, string length, or map size |
| `push(arr, item)` | `push([T], T): void` | Appends an item to the end of a dynamic array |
| `pop(arr)` | `pop([T]): T` | Removes and returns the last element of an array |
| `slice(arr, start, end)` | `slice([T], int, int): [T]` | Sub-array extraction without reallocation |
| `contains(arr, val)` | `contains([T] \| str, T): bool` | Membership test for array or substring |
| `split(s, sep)` | `split(str, str): [str]` | Splits string by delimiter into an array of strings |
| `trim(s)` | `trim(str): str` | Strips leading and trailing whitespace |
| `replace(s, old, new)` | `replace(str, str, str): str` | Replaces all occurrences of substring with replacement |
| `startsWith(s, prefix)` | `startsWith(str, str): bool` | Prefix check on string |
| `endsWith(s, suffix)` | `endsWith(str, suffix): bool` | Suffix check on string |
| `toUpper(s)` / `toLower(s)` | `toUpper(str): str` | ASCII case conversion |
| `charAt(s, idx)` | `charAt(str, int): str` | Single-character substring at zero-based index |
| `indexOf(s, sub)` | `indexOf(str, str): int` | First zero-based index of substring or -1 |
| `Map.set(k, v)` | `Map.set(K, V): void` | Sets key-value pair in hash map |
| `Map.get(k)` | `Map.get(K): Option[V]` | Retrieves optional value for key |
| `Map.has(k)` | `Map.has(K): bool` | Checks presence of key in map |
| `Map.delete(k)` | `Map.delete(K): bool` | Removes key from map and returns whether it existed |
| `Map.keys()` | `Map.keys(): [K]` | Returns array of all keys in map |
| `abs(n)` | `abs(int \| float): num` | Absolute value |
| `sqrt(n)` | `sqrt(float): float` | Square root |
| `sin(n)` / `cos(n)` | `sin(float): float` | Trigonometric sine and cosine |
| `floor(n)` / `ceil(n)` | `floor(float): int` | Integer floor and ceiling |
| `pow(base, exp)` | `pow(float, float): float` | Exponentiation |
| `rgb(r, g, b)` | `rgb(int, int, int): int` | Packed 32-bit RGBA color integer |
| `assert(cond, msg)` | `assert(bool, str): void` | Runtime invariant assertion |
| `panic(msg)` | `panic(str): void` | Aborts execution with fatal error message |
| `todo(msg)` | `todo(str): void` | Placeholder triggering fatal unimplemented error |

### 3.2 Design-by-Contract (`req:` and `ens:`)

Functions in AIPL support formal pre-conditions (`req:` ) and post-conditions (`ens:`) verified by the embedded SMT solver at compile time and verified with assertions at runtime:

```aipl
pub fn safeDivide(numerator: int, denominator: int): int:
  req: denominator != 0
  ens: ret * denominator <= numerator
  ret numerator / denominator
```

### 3.3 Functional Struct Updates & Value Cloning (`orig { field = val }` and `cloneStruct`)

AIPL supports functional struct updates via postfix brace syntax `orig { field = val }` as well as spread syntax `StructName(..orig, field = val)` and `{ ..orig, field: val }`. All struct spreads and `cloneStruct(s)` deep-clone nested struct fields via `aipl_struct_spread` / `aipl_rt_cloneStruct` so immutable updates never suffer from accidental pointer aliasing.

- **Primary Source Module**: `std/prelude.aipl` (`pub fn None():`, `pub fn cloneStruct(s: any): any:`)
- **Verification Test**: `tests/functions/core/prelude_test.aipl`
- **Runnable Example Reference**: `examples/ex_009_option_and_result_error_handling_cli.aipl` (tested by `tests/examples/ex_009_option_and_result_error_handling_cli_test.aipl`)

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

## Section 4: Root-to-Docs Specification Parity & Automated Snippet Verification Gate

All code examples in this specification and across the documentation are checked continuously by the verification engine:
```bash
python3 tools/verify_doc_snippets.py SPEC.md docs/SPEC.md
```

- **Primary Source Module**: `std/encoding/markdown.aipl` (`fn isHorizontalRuleLine(trimmed: str): bool:`)
- **Verification Test**: `tests/functions/encoding/markdown_test.aipl`
- **Runnable Example Reference**: `examples/ex_076_encoding_markdown_to_html_cli.aipl` (tested by `tests/examples/ex_076_encoding_markdown_to_html_cli_test.aipl`)

```aipl
module tests.functions.encoding.markdown_z2_test
import * from "std/encoding/markdown"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_markdown_isHorizontalRuleLine_2(): int:
  let arg_trimmed = "test"
  let edge_trimmed = "a"
  let resNom = isHorizontalRuleLine(arg_trimmed)
  let resEdge = isHorizontalRuleLine(edge_trimmed)
  assert(resNom == false, "isHorizontalRuleLine nominal resNom == false")
  assert(resEdge == false, "isHorizontalRuleLine boundary resEdge == false")
  ret 0
```
