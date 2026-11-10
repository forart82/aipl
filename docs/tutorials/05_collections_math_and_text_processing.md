[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](INDEX.md) | [Cookbook](cookbook.md) | [Stdlib Reference](../STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Chapter 05: Collections, Linear Algebra & Text Processing

> **Chapter Summary**: Generic contiguous collections (DynVec, Deque, HashMap, BTreeMap, BinaryMinHeap), 2D/3D linear algebra (Vec2, Vec3, Mat4, Quat), string builders, Unicode runes, linear-time PikeVM regex, and Myers line diff.

## Table of Contents
- [Chapter 05.1: Contiguous Generic Collections (DynVec, Deque, HashMap, BTreeMap, BitSet, BinaryMinHeap, LruCache)](#chapter-051-contiguous-generic-collections-dynvec-deque-hashmap-btreemap-bitset-binaryminheap-lrucache)
- [Chapter 05.2: 2D/3D Linear Algebra, Quaternions, Splines, Fixed-Point Q32.32 & Geometry (std/math/*)](#chapter-052-2d3d-linear-algebra-quaternions-splines-fixed-point-q3232--geometry-stdmath)
- [Chapter 05.3: Fast String Builders, Numeric Formatting, Hexdumps & Unicode Rune Tables (std/fmt/*)](#chapter-053-fast-string-builders-numeric-formatting-hexdumps--unicode-rune-tables-stdfmt)
- [Chapter 05.4: Linear-Time NFA Regex, Glob Wildcards, Myers Diff & Calendar Time (std/regex/*, std/time/*)](#chapter-054-linear-time-nfa-regex-glob-wildcards-myers-diff--calendar-time-stdregex-stdtime)

---

### Chapter 05.1: Contiguous Generic Collections (DynVec, Deque, HashMap, BTreeMap, BitSet, BinaryMinHeap, LruCache)

#### 1. Concept in 30 Seconds
Teach cache-friendly collections in `std/collections/*` including `vec`, `deque`, `hashmap`, `btree`, `bitset`, `priority_queue`, `hash_map`, `bloom_filter`, and `disjoint_set`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn dynVecNew[T](): DynVec[T]:` from `std/collections/dyn_vec.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.collections.dyn_vec_z1_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_dynVecNew_1(): int:
  let resNom = dynVecNew()
  let resEdge = dynVecNew()
  assertEqInt(resNom.items.len(), 0, "dynVecNew nominal resNom.items.len() == 0")
  assertEqInt(resEdge.items.len(), 0, "dynVecNew boundary resEdge.items.len() == 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_043` | [examples/ex_043_collections_dyn_vec_and_sort_cli.aipl](../../examples/ex_043_collections_dyn_vec_and_sort_cli.aipl) | `tests/examples/ex_043_collections_dyn_vec_and_sort_cli_test.aipl` | `./bin/aipl test tests/examples/ex_043_collections_dyn_vec_and_sort_cli_test.aipl` |
| `ex_044` | [examples/ex_044_collections_deque_sliding_window_cli.aipl](../../examples/ex_044_collections_deque_sliding_window_cli.aipl) | `tests/examples/ex_044_collections_deque_sliding_window_cli_test.aipl` | `./bin/aipl test tests/examples/ex_044_collections_deque_sliding_window_cli_test.aipl` |
| `ex_045` | [examples/ex_045_collections_hash_map_word_freq_cli.aipl](../../examples/ex_045_collections_hash_map_word_freq_cli.aipl) | `tests/examples/ex_045_collections_hash_map_word_freq_cli_test.aipl` | `./bin/aipl test tests/examples/ex_045_collections_hash_map_word_freq_cli_test.aipl` |
| `ex_046` | [examples/ex_046_collections_btree_map_range_query_cli.aipl](../../examples/ex_046_collections_btree_map_range_query_cli.aipl) | `tests/examples/ex_046_collections_btree_map_range_query_cli_test.aipl` | `./bin/aipl test tests/examples/ex_046_collections_btree_map_range_query_cli_test.aipl` |
| `ex_047` | [examples/ex_047_collections_priority_queue_scheduler_cli.aipl](../../examples/ex_047_collections_priority_queue_scheduler_cli.aipl) | `tests/examples/ex_047_collections_priority_queue_scheduler_cli_test.aipl` | `./bin/aipl test tests/examples/ex_047_collections_priority_queue_scheduler_cli_test.aipl` |
| `ex_048` | [examples/ex_048_collections_bitset_bloom_filter_cli.aipl](../../examples/ex_048_collections_bitset_bloom_filter_cli.aipl) | `tests/examples/ex_048_collections_bitset_bloom_filter_cli_test.aipl` | `./bin/aipl test tests/examples/ex_048_collections_bitset_bloom_filter_cli_test.aipl` |

---

### Chapter 05.2: 2D/3D Linear Algebra, Quaternions, Splines, Fixed-Point Q32.32 & Geometry (std/math/*)

#### 1. Concept in 30 Seconds
Teach vectors (`vec2`, `vec3`, `vec4`), matrices (`mat3`, `mat4`), quaternions (`quat`), `bezier`/`spline`, `geom2d`/`geom3d`, `fixed` Q16.16/Q32.32 deterministic math, `complex`, `stats`, and `simd`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn Vector2.new(x: float, y: float): Vector2:` from `std/math/vec_math.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.math.vec_math_z2_test
import * from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vector2_new_2(): int:
  let arg_x = 1.0
  let edge_x = 0.0
  let arg_y = 1.0
  let edge_y = 0.0
  let resNom = Vector2.new(arg_x, arg_y)
  let resEdge = Vector2.new(edge_x, edge_y)
  assertApproxEq(resNom.x, 1.0, 0.001, "Vector2.new nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "Vector2.new boundary resEdge.x ~= 0.0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_027` | [examples/ex_027_math_consts_and_num_theory_cli.aipl](../../examples/ex_027_math_consts_and_num_theory_cli.aipl) | `tests/examples/ex_027_math_consts_and_num_theory_cli_test.aipl` | `./bin/aipl test tests/examples/ex_027_math_consts_and_num_theory_cli_test.aipl` |
| `ex_028` | [examples/ex_028_math_trig_and_spherical_cli.aipl](../../examples/ex_028_math_trig_and_spherical_cli.aipl) | `tests/examples/ex_028_math_trig_and_spherical_cli_test.aipl` | `./bin/aipl test tests/examples/ex_028_math_trig_and_spherical_cli_test.aipl` |
| `ex_029` | [examples/ex_029_math_vec2_vec3_vec4_cli.aipl](../../examples/ex_029_math_vec2_vec3_vec4_cli.aipl) | `tests/examples/ex_029_math_vec2_vec3_vec4_cli_test.aipl` | `./bin/aipl test tests/examples/ex_029_math_vec2_vec3_vec4_cli_test.aipl` |
| `ex_030` | [examples/ex_030_math_mat3_mat4_transforms_cli.aipl](../../examples/ex_030_math_mat3_mat4_transforms_cli.aipl) | `tests/examples/ex_030_math_mat3_mat4_transforms_cli_test.aipl` | `./bin/aipl test tests/examples/ex_030_math_mat3_mat4_transforms_cli_test.aipl` |
| `ex_031` | [examples/ex_031_math_quat_slerp_orientation_window.aipl](../../examples/ex_031_math_quat_slerp_orientation_window.aipl) | `tests/examples/ex_031_math_quat_slerp_orientation_window_test.aipl` | `./bin/aipl test tests/examples/ex_031_math_quat_slerp_orientation_window_test.aipl` |
| `ex_032` | [examples/ex_032_math_geom2d_intersections_window.aipl](../../examples/ex_032_math_geom2d_intersections_window.aipl) | `tests/examples/ex_032_math_geom2d_intersections_window_test.aipl` | `./bin/aipl test tests/examples/ex_032_math_geom2d_intersections_window_test.aipl` |

---

### Chapter 05.3: Fast String Builders, Numeric Formatting, Hexdumps & Unicode Rune Tables (std/fmt/*)

#### 1. Concept in 30 Seconds
Teach zero-allocation string building (`std/fmt/text_print`, `num_parse`, `hexdump`, `table_fmt`, `unicode`) and ASCII/UTF-8 table rendering.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn formatInterpolated(templateStr: str, args: [str]): str:` from `std/fmt/text_print.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.fmt.text_print_z1_test
import * from "std/fmt/text_print"
import { formatFloatFixed } from "std/fmt/num_parse"
import { padLeft, padRight, padCenter, repeat, words } from "std/fmt/str_builder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_text_print_formatInterpolated_1(): int:
  let arg_templateStr = "42"
  let edge_templateStr = "0"
  let arg_args = ["42"]
  let edge_args = []
  let resNom = formatInterpolated(arg_templateStr, arg_args)
  let resEdge = formatInterpolated(edge_templateStr, edge_args)
  assertEqStr(resNom, "42", "formatInterpolated nominal string matches")
  assertEqStr(resEdge, "0", "formatInterpolated boundary string matches")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_056` | [examples/ex_056_fmt_num_radix_and_scientific_cli.aipl](../../examples/ex_056_fmt_num_radix_and_scientific_cli.aipl) | `tests/examples/ex_056_fmt_num_radix_and_scientific_cli_test.aipl` | `./bin/aipl test tests/examples/ex_056_fmt_num_radix_and_scientific_cli_test.aipl` |
| `ex_057` | [examples/ex_057_fmt_str_builder_report_engine_cli.aipl](../../examples/ex_057_fmt_str_builder_report_engine_cli.aipl) | `tests/examples/ex_057_fmt_str_builder_report_engine_cli_test.aipl` | `./bin/aipl test tests/examples/ex_057_fmt_str_builder_report_engine_cli_test.aipl` |
| `ex_058` | [examples/ex_058_fmt_text_print_hexdump_cli.aipl](../../examples/ex_058_fmt_text_print_hexdump_cli.aipl) | `tests/examples/ex_058_fmt_text_print_hexdump_cli_test.aipl` | `./bin/aipl test tests/examples/ex_058_fmt_text_print_hexdump_cli_test.aipl` |
| `ex_059` | [examples/ex_059_fmt_unicode_utf8_inspector_cli.aipl](../../examples/ex_059_fmt_unicode_utf8_inspector_cli.aipl) | `tests/examples/ex_059_fmt_unicode_utf8_inspector_cli_test.aipl` | `./bin/aipl test tests/examples/ex_059_fmt_unicode_utf8_inspector_cli_test.aipl` |
| `ex_060` | [examples/ex_060_regex_compile_nfa_inspector_cli.aipl](../../examples/ex_060_regex_compile_nfa_inspector_cli.aipl) | `tests/examples/ex_060_regex_compile_nfa_inspector_cli_test.aipl` | `./bin/aipl test tests/examples/ex_060_regex_compile_nfa_inspector_cli_test.aipl` |

---

### Chapter 05.4: Linear-Time NFA Regex, Glob Wildcards, Myers Diff & Calendar Time (std/regex/*, std/time/*)

#### 1. Concept in 30 Seconds
Teach ReDoS-immune Thompson NFA regex (`std/regex/regex_vm`), `glob`, `text_diff`, and monotonic/ISO-8601 clocks (`std/time/instant`, `datetime`, `duration`, `cron`, `timer_wheel`).

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `fn toLowerAsciiCode(c: int): int:` from `std/regex/regex_vm.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.regex.regex_vm_z1_test
import * from "std/regex/regex_vm"
import { OP_MATCH, OP_CHAR, OP_ANY, OP_CHAR_CLASS, OP_SPLIT, OP_JUMP, OP_SAVE, OP_ANCHOR_START, OP_ANCHOR_END, RegexFlags, RegexCharClass, RegexInstruction, RegexBytecode, Regex } from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_vm_toLowerAsciiCode_1(): int:
  let arg_c = 2
  let edge_c = 0
  let resNom = toLowerAsciiCode(arg_c)
  let resEdge = toLowerAsciiCode(edge_c)
  assertEqInt(resNom, 2, "toLowerAsciiCode nominal resNom == 2")
  assertEqInt(resEdge, 0, "toLowerAsciiCode boundary resEdge == 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_061` | [examples/ex_061_regex_vm_grep_and_replace_cli.aipl](../../examples/ex_061_regex_vm_grep_and_replace_cli.aipl) | `tests/examples/ex_061_regex_vm_grep_and_replace_cli_test.aipl` | `./bin/aipl test tests/examples/ex_061_regex_vm_grep_and_replace_cli_test.aipl` |
| `ex_062` | [examples/ex_062_regex_text_diff_myers_patch_cli.aipl](../../examples/ex_062_regex_text_diff_myers_patch_cli.aipl) | `tests/examples/ex_062_regex_text_diff_myers_patch_cli_test.aipl` | `./bin/aipl test tests/examples/ex_062_regex_text_diff_myers_patch_cli_test.aipl` |
| `ex_063` | [examples/ex_063_regex_fuzzy_search_and_glob_cli.aipl](../../examples/ex_063_regex_fuzzy_search_and_glob_cli.aipl) | `tests/examples/ex_063_regex_fuzzy_search_and_glob_cli_test.aipl` | `./bin/aipl test tests/examples/ex_063_regex_fuzzy_search_and_glob_cli_test.aipl` |
| `ex_064` | [examples/ex_064_time_instant_benchmark_timer_cli.aipl](../../examples/ex_064_time_instant_benchmark_timer_cli.aipl) | `tests/examples/ex_064_time_instant_benchmark_timer_cli_test.aipl` | `./bin/aipl test tests/examples/ex_064_time_instant_benchmark_timer_cli_test.aipl` |
| `ex_065` | [examples/ex_065_time_duration_humanizer_cli.aipl](../../examples/ex_065_time_duration_humanizer_cli.aipl) | `tests/examples/ex_065_time_duration_humanizer_cli_test.aipl` | `./bin/aipl test tests/examples/ex_065_time_duration_humanizer_cli_test.aipl` |
| `ex_066` | [examples/ex_066_time_datetime_iso8601_calendar_cli.aipl](../../examples/ex_066_time_datetime_iso8601_calendar_cli.aipl) | `tests/examples/ex_066_time_datetime_iso8601_calendar_cli_test.aipl` | `./bin/aipl test tests/examples/ex_066_time_datetime_iso8601_calendar_cli_test.aipl` |
