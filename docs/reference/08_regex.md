[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 08: `regex` API Reference

> Complete API reference manual for AIPL standard library domain `regex` (53 callable functions & methods across ["std/regex/regex_compile.aipl", "std/regex/regex_mod.aipl", "std/regex/regex_vm.aipl", "std/regex/text_diff.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `regex`
- **Target Source Modules**: ["std/regex/regex_compile.aipl", "std/regex/regex_mod.aipl", "std/regex/regex_vm.aipl", "std/regex/text_diff.aipl"]
- **Total Callable Functions & Methods**: 53
- **Total Data Types (`struct` & `enum`)**: 11
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(11 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `RegexFlags` | `pub struct` | `std/regex/regex_compile.aipl` | `ignoreCase: bool`, `multiline: bool`, `dotAll: bool`, `ungreedy: bool` | `RegexFlags(ignoreCase, multiline, dotAll, ungreedy)` |
| `RegexCharClass` | `pub struct` | `std/regex/regex_compile.aipl` | `ranges: [(int, int)]`, `negated: bool` | `RegexCharClass(ranges, negated)` |
| `RegexAstNode` | `pub struct` | `std/regex/regex_compile.aipl` | `kind: str`, `charCode: int`, `minCount: int`, `maxCount: int`, `children: [RegexAstNode]`, `charClass: RegexCharClass`, `groupIndex: int` | `RegexAstNode(kind, charCode, minCount, maxCount, children, charClass, groupIndex)` |
| `RegexInstruction` | `pub struct` | `std/regex/regex_compile.aipl` | `opcode: int`, `charCode: int`, `targetA: int`, `targetB: int`, `groupIdx: int`, `charClass: RegexCharClass` | `RegexInstruction(opcode, charCode, targetA, targetB, groupIdx, charClass)` |
| `RegexBytecode` | `pub struct` | `std/regex/regex_compile.aipl` | `instructions: [RegexInstruction]`, `groupCount: int`, `anchoredStart: bool`, `anchoredEnd: bool` | `RegexBytecode(instructions, groupCount, anchoredStart, anchoredEnd)` |
| `Regex` | `pub struct` | `std/regex/regex_compile.aipl` | `pattern: str`, `bytecode: RegexBytecode`, `flags: RegexFlags`, `groupCount: int` | `Regex(pattern, bytecode, flags, groupCount)` |
| `RegexMatch` | `pub struct` | `std/regex/regex_vm.aipl` | `start: int`, `end: int`, `text: str`, `groups: [str]` | `RegexMatch(start, end, text, groups)` |
| `RegexSpan` | `pub struct` | `std/regex/regex_vm.aipl` | `start: int`, `end: int` | `RegexSpan(start, end)` |
| `DiffEdit` | `pub struct` | `std/regex/text_diff.aipl` | `op: str`, `text: str`, `oldLineNo: int`, `newLineNo: int` | `DiffEdit(op, text, oldLineNo, newLineNo)` |
| `DiffHunk` | `pub struct` | `std/regex/text_diff.aipl` | `oldStart: int`, `oldCount: int`, `newStart: int`, `newCount: int`, `lines: [str]` | `DiffHunk(oldStart, oldCount, newStart, newCount, lines)` |
| `UnifiedPatch` | `pub struct` | `std/regex/text_diff.aipl` | `headerOld: str`, `headerNew: str`, `hunks: [DiffHunk]`, `addedCount: int`, `deletedCount: int` | `UnifiedPatch(headerOld, headerNew, hunks, addedCount, deletedCount)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/regex/regex_compile.aipl` | `defaultRegexFlags` | `pub fn defaultRegexFlags(): RegexFlags:` | `tests/functions/regex/regex_compile_test.aipl` |
| `2` | `std/regex/regex_compile.aipl` | `emptyCharClass` | `pub fn emptyCharClass(): RegexCharClass:` | `tests/functions/regex/regex_compile_test.aipl` |
| `3` | `std/regex/regex_compile.aipl` | `makeNode` | `fn makeNode(kind: str, charCode: int): RegexAstNode:` | `tests/functions/regex/regex_compile_test.aipl` |
| `4` | `std/regex/regex_compile.aipl` | `makeClassNode` | `fn makeClassNode(ranges: [(int, int)], negated: bool): RegexAstNode:` | `tests/functions/regex/regex_compile_test.aipl` |
| `5` | `std/regex/regex_compile.aipl` | `makeEscapeNode` | `fn makeEscapeNode(esc: str): RegexAstNode:` | `tests/functions/regex/regex_compile_test.aipl` |
| `6` | `std/regex/regex_compile.aipl` | `parseBracketClass` | `fn parseBracketClass(mut st: ParseState): (RegexAstNode, ParseState):` | `tests/functions/regex/regex_compile_test.aipl` |
| `7` | `std/regex/regex_compile.aipl` | `parseQuantifierBounds` | `fn parseQuantifierBounds(mut st: ParseState): (int, int, ParseState):` | `tests/functions/regex/regex_compile_test.aipl` |
| `8` | `std/regex/regex_compile.aipl` | `parseAlternation` | `fn parseAlternation(mut st: ParseState): (RegexAstNode, ParseState):` | `tests/functions/regex/regex_compile_test.aipl` |
| `9` | `std/regex/regex_compile.aipl` | `parseConcat` | `fn parseConcat(mut st: ParseState): (RegexAstNode, ParseState):` | `tests/functions/regex/regex_compile_test.aipl` |
| `10` | `std/regex/regex_compile.aipl` | `parseQuantifiedAtom` | `fn parseQuantifiedAtom(mut st: ParseState): (RegexAstNode, ParseState):` | `tests/functions/regex/regex_compile_test.aipl` |
| `11` | `std/regex/regex_compile.aipl` | `parseAtom` | `fn parseAtom(mut st: ParseState): (RegexAstNode, ParseState):` | `tests/functions/regex/regex_compile_test.aipl` |
| `12` | `std/regex/regex_compile.aipl` | `parseRegexAst` | `pub fn parseRegexAst(pattern: str): Result[RegexAstNode, str]:` | `tests/functions/regex/regex_compile_test.aipl` |
| `13` | `std/regex/regex_compile.aipl` | `makeInst` | `fn makeInst(opcode: int, charCode: int, targetA: int, targetB: int, groupIdx: int, cc: RegexCharClass): RegexInstruction:` | `tests/functions/regex/regex_compile_test.aipl` |
| `14` | `std/regex/regex_compile.aipl` | `emitNodeBytecode` | `fn emitNodeBytecode(node: RegexAstNode, flags: RegexFlags, mut insts: [RegexInstruction]): [RegexInstruction]:` | `tests/functions/regex/regex_compile_test.aipl` |
| `15` | `std/regex/regex_compile.aipl` | `countAstGroups` | `fn countAstGroups(node: RegexAstNode): int:` | `tests/functions/regex/regex_compile_test.aipl` |
| `16` | `std/regex/regex_compile.aipl` | `compileAstToBytecode` | `pub fn compileAstToBytecode(ast: RegexAstNode, flags: RegexFlags): RegexBytecode:` | `tests/functions/regex/regex_compile_test.aipl` |
| `17` | `std/regex/regex_compile.aipl` | `regexCompileEx` | `pub fn regexCompileEx(pattern: str, flags: RegexFlags): Result[Regex, str]:` | `tests/functions/regex/regex_compile_test.aipl` |
| `18` | `std/regex/regex_compile.aipl` | `regexCompile` | `pub fn regexCompile(pattern: str): Result[Regex, str]:` | `tests/functions/regex/regex_compile_test.aipl` |
| `19` | `std/regex/regex_compile.aipl` | `escapeRegexSpecial` | `pub fn escapeRegexSpecial(pattern: str): str:` | `tests/functions/regex/regex_compile_test.aipl` |
| `20` | `std/regex/regex_mod.aipl` | `regexMatch` | `pub fn regexMatch(pattern: str, text: str): bool:` | `tests/functions/regex/regex_mod_test.aipl` |
| `21` | `std/regex/regex_mod.aipl` | `regexIsMatch` | `pub fn regexIsMatch(re: Regex, text: str): bool:` | `tests/functions/regex/regex_mod_test.aipl` |
| `22` | `std/regex/regex_mod.aipl` | `regexSplit` | `pub fn regexSplit(re: Regex, text: str): [str]:` | `tests/functions/regex/regex_mod_test.aipl` |
| `23` | `std/regex/regex_mod.aipl` | `regexFind` | `pub fn regexFind(pattern: str, text: str): Option[RegexMatch]:` | `tests/functions/regex/regex_mod_test.aipl` |
| `24` | `std/regex/regex_mod.aipl` | `regexFindAll` | `pub fn regexFindAll(pattern: str, text: str): [RegexMatch]:` | `tests/functions/regex/regex_mod_test.aipl` |
| `25` | `std/regex/regex_mod.aipl` | `regexReplace` | `pub fn regexReplace(pattern: any, text: str, replacement: str): str:` | `tests/functions/regex/regex_mod_test.aipl` |
| `26` | `std/regex/regex_mod.aipl` | `regexReplaceAll` | `pub fn regexReplaceAll(pattern: any, text: str, replacement: str): str:` | `tests/functions/regex/regex_mod_test.aipl` |
| `27` | `std/regex/regex_mod.aipl` | `diffTexts` | `pub fn diffTexts(oldText: str, newText: str, contextRadius: int = 3): str:` | `tests/functions/regex/regex_mod_test.aipl` |
| `28` | `std/regex/regex_mod.aipl` | `applyPatch` | `pub fn applyPatch(originalText: str, patchText: str): Result[str, str]:` | `tests/functions/regex/regex_mod_test.aipl` |
| `29` | `std/regex/regex_vm.aipl` | `toLowerAsciiCode` | `fn toLowerAsciiCode(c: int): int:` | `tests/functions/regex/regex_vm_test.aipl` |
| `30` | `std/regex/regex_vm.aipl` | `charMatchesClass` | `fn charMatchesClass(c: int, cc: RegexCharClass, ignoreCase: bool): bool:` | `tests/functions/regex/regex_vm_test.aipl` |
| `31` | `std/regex/regex_vm.aipl` | `cloneIntSlots` | `fn cloneIntSlots(slots: [int]): [int]:` | `tests/functions/regex/regex_vm_test.aipl` |
| `32` | `std/regex/regex_vm.aipl` | `addPikeThread` | `fn addPikeThread( mut list: [PikeThread], mut visited: [int], stepId: int, pc: int, slots: [int], bc: RegexBytecode, flags: RegexFlags, text: str, pos: int ): [PikeThread]:` | `tests/functions/regex/regex_vm_test.aipl` |
| `33` | `std/regex/regex_vm.aipl` | `runPikeAtPos` | `fn runPikeAtPos(re: Regex, text: str, startPos: int): Option[[int]]:` | `tests/functions/regex/regex_vm_test.aipl` |
| `34` | `std/regex/regex_vm.aipl` | `buildRegexMatch` | `fn buildRegexMatch(text: str, slots: [int], groupCount: int): RegexMatch:` | `tests/functions/regex/regex_vm_test.aipl` |
| `35` | `std/regex/regex_vm.aipl` | `find` | `pub fn (self: Regex) find(text: str): Option[RegexMatch]:` | `tests/functions/regex/regex_vm_test.aipl` |
| `36` | `std/regex/regex_vm.aipl` | `isMatch` | `pub fn (self: Regex) isMatch(text: str): bool:` | `tests/functions/regex/regex_vm_test.aipl` |
| `37` | `std/regex/regex_vm.aipl` | `findSpan` | `pub fn (self: Regex) findSpan(text: str): Option[RegexSpan]:` | `tests/functions/regex/regex_vm_test.aipl` |
| `38` | `std/regex/regex_vm.aipl` | `findAll` | `pub fn (self: Regex) findAll(text: str): [RegexMatch]:` | `tests/functions/regex/regex_vm_test.aipl` |
| `39` | `std/regex/regex_vm.aipl` | `captures` | `pub fn (self: Regex) captures(text: str): [str]:` | `tests/functions/regex/regex_vm_test.aipl` |
| `40` | `std/regex/regex_vm.aipl` | `expandReplacement` | `fn expandReplacement(replacement: str, m: RegexMatch): str:` | `tests/functions/regex/regex_vm_test.aipl` |
| `41` | `std/regex/regex_vm.aipl` | `replace` | `pub fn (self: Regex) replace(text: str, replacement: str): str:` | `tests/functions/regex/regex_vm_test.aipl` |
| `42` | `std/regex/regex_vm.aipl` | `replaceAll` | `pub fn (self: Regex) replaceAll(text: str, replacement: str): str:` | `tests/functions/regex/regex_vm_test.aipl` |
| `43` | `std/regex/regex_vm.aipl` | `splitN` | `pub fn (self: Regex) splitN(text: str, limit: int): [str]:` | `tests/functions/regex/regex_vm_test.aipl` |
| `44` | `std/regex/regex_vm.aipl` | `split` | `pub fn (self: Regex) split(text: str): [str]:` | `tests/functions/regex/regex_vm_test.aipl` |
| `45` | `std/regex/text_diff.aipl` | `myersDiffLines` | `pub fn myersDiffLines(oldLines: [str], newLines: [str]): [DiffEdit]:` | `tests/functions/regex/text_diff_test.aipl` |
| `46` | `std/regex/text_diff.aipl` | `buildUnifiedHunks` | `pub fn buildUnifiedHunks(edits: [DiffEdit], contextRadius: int = 3): [DiffHunk]:` | `tests/functions/regex/text_diff_test.aipl` |
| `47` | `std/regex/text_diff.aipl` | `formatUnifiedDiff` | `pub fn formatUnifiedDiff(oldFile: str, newFile: str, oldText: str, newText: str, context: int = 3): str:` | `tests/functions/regex/text_diff_test.aipl` |
| `48` | `std/regex/text_diff.aipl` | `parseRangeSpec` | `fn parseRangeSpec(spec: str): (int, int):` | `tests/functions/regex/text_diff_test.aipl` |
| `49` | `std/regex/text_diff.aipl` | `parseUnifiedPatch` | `pub fn parseUnifiedPatch(patchText: str): Result[UnifiedPatch, str]:` | `tests/functions/regex/text_diff_test.aipl` |
| `50` | `std/regex/text_diff.aipl` | `applyUnifiedPatch` | `pub fn applyUnifiedPatch(originalText: str, patch: UnifiedPatch): Result[str, str]:` | `tests/functions/regex/text_diff_test.aipl` |
| `51` | `std/regex/text_diff.aipl` | `threeWayMerge` | `pub fn threeWayMerge(baseText: str, ourText: str, theirText: str): Result[str, str]:` | `tests/functions/regex/text_diff_test.aipl` |
| `52` | `std/regex/text_diff.aipl` | `editDistance` | `pub fn editDistance(a: str, b: str): int:` | `tests/functions/regex/text_diff_test.aipl` |
| `53` | `std/regex/text_diff.aipl` | `similarityRatio` | `pub fn similarityRatio(a: str, b: str): float:` | `tests/functions/regex/text_diff_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `defaultRegexFlags` (`std/regex/regex_compile.aipl`)

- **Signature**: `pub fn defaultRegexFlags(): RegexFlags:`
- **Import**: `import * from "std/regex/regex_compile"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `RegexFlags`
- **Unit Test**: `tests/functions/regex/regex_compile_test.aipl` | **Example**: `examples/ex_061_regex_vm_grep_and_replace_cli.aipl`
- **Behavioral Summary**: `, capture groups, and special-char escaping. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `RegexFlags(ignoreCase = false, multiline = false, dotAll = false, ungreedy = false)`.

```aipl
module tests.functions.regex.regex_compile_z1_test
import * from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_compile_defaultRegexFlags_1(): int:
  let resNom = defaultRegexFlags()
  let resEdge = defaultRegexFlags()
  assert(resNom.ignoreCase == false, "defaultRegexFlags nominal resNom.ignoreCase == false")
  assert(resEdge.ignoreCase == false, "defaultRegexFlags boundary resEdge.ignoreCase == false")
  ret 0
```

---

### `emptyCharClass` (`std/regex/regex_compile.aipl`)

- **Signature**: `pub fn emptyCharClass(): RegexCharClass:`
- **Import**: `import * from "std/regex/regex_compile"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `RegexCharClass`
- **Unit Test**: `tests/functions/regex/regex_compile_test.aipl` | **Example**: `examples/ex_062_regex_text_diff_myers_patch_cli.aipl`
- **Behavioral Summary**: `, capture groups, and special-char escaping. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `RegexCharClass(ranges = r, negated = false)`.

```aipl
module tests.functions.regex.regex_compile_z2_test
import * from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_compile_emptyCharClass_2(): int:
  let resNom = emptyCharClass()
  let resEdge = emptyCharClass()
  assertEqInt(resNom.ranges.len(), 0, "emptyCharClass nominal resNom.ranges.len() == 0")
  assertEqInt(resEdge.ranges.len(), 0, "emptyCharClass boundary resEdge.ranges.len() == 0")
  ret 0
```

---

### `makeNode` (`std/regex/regex_compile.aipl`)

- **Signature**: `fn makeNode(kind: str, charCode: int): RegexAstNode:`
- **Import**: `import * from "std/regex/regex_compile"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `kind: str, charCode: int` | **Returns**: `RegexAstNode`
- **Unit Test**: `tests/functions/regex/regex_compile_test.aipl` | **Example**: `examples/ex_063_regex_fuzzy_search_and_glob_cli.aipl`
- **Behavioral Summary**: `, capture groups, and special-char escaping. Concrete nominal inputs: `kind: str = "aipl_test"`, `charCode: int = 1`; exercises core body path returning/computing `RegexAstNode(`.

```aipl
module tests.functions.regex.regex_compile_z3_test
import * from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_compile_makeNode_3(): int:
  let arg_kind = "test"
  let edge_kind = "a"
  let arg_charCode = 2
  let edge_charCode = 0
  let resNom = makeNode(arg_kind, arg_charCode)
  let resEdge = makeNode(edge_kind, edge_charCode)
  assertEqStr(resNom.kind, "test", "makeNode nominal string matches")
  assertEqStr(resEdge.kind, "a", "makeNode boundary string matches")
  ret 0
```

---

### `makeClassNode` (`std/regex/regex_compile.aipl`)

- **Signature**: `fn makeClassNode(ranges: [(int, int)], negated: bool): RegexAstNode:`
- **Import**: `import * from "std/regex/regex_compile"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ranges: [(int, int)], negated: bool` | **Returns**: `RegexAstNode`
- **Unit Test**: `tests/functions/regex/regex_compile_test.aipl` | **Example**: `examples/ex_061_regex_vm_grep_and_replace_cli.aipl`
- **Behavioral Summary**: `, capture groups, and special-char escaping. Concrete nominal inputs: `ranges: [(int, int)] = [(int, int)()]`, `negated: bool = true`; exercises core body path returning/computing `RegexAstNode(`.

```aipl
module tests.functions.regex.regex_compile_z4_test
import * from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_compile_makeClassNode_4(): int:
  let arg_ranges = [(4, 4)]
  let edge_ranges = []
  let arg_negated = true
  let edge_negated = false
  let resNom = makeClassNode(arg_ranges, arg_negated)
  let resEdge = makeClassNode(edge_ranges, edge_negated)
  assertEqStr(resNom.kind, "class", "makeClassNode nominal string matches")
  assertEqStr(resEdge.kind, "class", "makeClassNode boundary string matches")
  ret 0
```

---

### `makeEscapeNode` (`std/regex/regex_compile.aipl`)

- **Signature**: `fn makeEscapeNode(esc: str): RegexAstNode:`
- **Import**: `import * from "std/regex/regex_compile"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `esc: str` | **Returns**: `RegexAstNode`
- **Unit Test**: `tests/functions/regex/regex_compile_test.aipl` | **Example**: `examples/ex_062_regex_text_diff_myers_patch_cli.aipl`
- **Behavioral Summary**: `, capture groups, and special-char escaping. Concrete nominal inputs: `esc: str = "aipl_test"`; exercises core body path returning/computing `makeNode("char", esc.charCodeAt(0))`.

```aipl
module tests.functions.regex.regex_compile_z5_test
import * from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_compile_makeEscapeNode_5(): int:
  let arg_esc = "test"
  let edge_esc = "a"
  let resNom = makeEscapeNode(arg_esc)
  let resEdge = makeEscapeNode(edge_esc)
  assertEqStr(resNom.kind, "char", "makeEscapeNode nominal string matches")
  assertEqStr(resEdge.kind, "char", "makeEscapeNode boundary string matches")
  ret 0
```

---

### `parseBracketClass` (`std/regex/regex_compile.aipl`)

- **Signature**: `fn parseBracketClass(mut st: ParseState): (RegexAstNode, ParseState):`
- **Import**: `import * from "std/regex/regex_compile"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut st: ParseState` | **Returns**: `(RegexAstNode, ParseState)`
- **Unit Test**: `tests/functions/regex/regex_compile_test.aipl` | **Example**: `examples/ex_063_regex_fuzzy_search_and_glob_cli.aipl`
- **Behavioral Summary**: `, capture groups, and special-char escaping. Concrete nominal inputs: `st: ParseState): (RegexAstNode = ParseState): (RegexAstNode()`, `ParseState: any = 42`; exercises core body path returning/computing `(makeClassNode(ranges, negated), st)`.

```aipl
module tests.functions.regex.regex_compile_z6_test
import * from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_compile_parseBracketClass_6(): int:
  let arg_st = ParseState(pattern = "test", pos = 0, groupCount = 4, err = "test")
  let edge_st = ParseState(pattern = "a", pos = 0, groupCount = 1, err = "a")
  let resNom = parseBracketClass(arg_st)
  let resEdge = parseBracketClass(edge_st)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqStr(n_t0.kind, "empty", "parseBracketClass nominal string matches")
  assertEqStr(e_t0.kind, "empty", "parseBracketClass boundary string matches")
  ret 0
```

---

### `parseQuantifierBounds` (`std/regex/regex_compile.aipl`)

- **Signature**: `fn parseQuantifierBounds(mut st: ParseState): (int, int, ParseState):`
- **Import**: `import * from "std/regex/regex_compile"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut st: ParseState` | **Returns**: `(int, int, ParseState)`
- **Unit Test**: `tests/functions/regex/regex_compile_test.aipl` | **Example**: `examples/ex_061_regex_vm_grep_and_replace_cli.aipl`
- **Behavioral Summary**: `, capture groups, and special-char escaping. Concrete nominal inputs: `st: ParseState): (int = ParseState): (int()`, `int: any = 42`, `ParseState: any = 42`; exercises core body path returning/computing `(minVal, maxVal, st)`.

```aipl
module tests.functions.regex.regex_compile_z7_test
import * from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_compile_parseQuantifierBounds_7(): int:
  let arg_st = ParseState(pattern = "test", pos = 0, groupCount = 4, err = "test")
  let edge_st = ParseState(pattern = "a", pos = 0, groupCount = 1, err = "a")
  let resNom = parseQuantifierBounds(arg_st)
  let resEdge = parseQuantifierBounds(edge_st)
  let (n_t0, n_t1, n_t2) = resNom
  let (e_t0, e_t1, e_t2) = resEdge
  assertEqInt(n_t0, 1, "parseQuantifierBounds nominal n_t0 == 1")
  assertEqInt(e_t0, 1, "parseQuantifierBounds boundary e_t0 == 1")
  ret 0
```

---

### `parseAlternation` (`std/regex/regex_compile.aipl`)

- **Signature**: `fn parseAlternation(mut st: ParseState): (RegexAstNode, ParseState):`
- **Import**: `import * from "std/regex/regex_compile"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut st: ParseState` | **Returns**: `(RegexAstNode, ParseState)`
- **Unit Test**: `tests/functions/regex/regex_compile_test.aipl` | **Example**: `examples/ex_062_regex_text_diff_myers_patch_cli.aipl`
- **Behavioral Summary**: `, capture groups, and special-char escaping. Concrete nominal inputs: `st: ParseState): (RegexAstNode = ParseState): (RegexAstNode()`, `ParseState: any = 42`; exercises core body path returning/computing `(leftNode, st)`.

```aipl
module tests.functions.regex.regex_compile_z8_test
import * from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_compile_parseAlternation_8(): int:
  let arg_st = ParseState(pattern = "test", pos = 0, groupCount = 4, err = "test")
  let edge_st = ParseState(pattern = "a", pos = 0, groupCount = 1, err = "a")
  let resNom = parseAlternation(arg_st)
  let resEdge = parseAlternation(edge_st)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqStr(n_t0.kind, "empty", "parseAlternation nominal string matches")
  assertEqStr(e_t0.kind, "empty", "parseAlternation boundary string matches")
  ret 0
```

---

### `parseConcat` (`std/regex/regex_compile.aipl`)

- **Signature**: `fn parseConcat(mut st: ParseState): (RegexAstNode, ParseState):`
- **Import**: `import * from "std/regex/regex_compile"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut st: ParseState` | **Returns**: `(RegexAstNode, ParseState)`
- **Unit Test**: `tests/functions/regex/regex_compile_test.aipl` | **Example**: `examples/ex_063_regex_fuzzy_search_and_glob_cli.aipl`
- **Behavioral Summary**: `, capture groups, and special-char escaping. Concrete nominal inputs: `st: ParseState): (RegexAstNode = ParseState): (RegexAstNode()`, `ParseState: any = 42`; exercises core body path returning/computing `(seq, st)`.

```aipl
module tests.functions.regex.regex_compile_z9_test
import * from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_compile_parseConcat_9(): int:
  let arg_st = ParseState(pattern = "test", pos = 0, groupCount = 4, err = "test")
  let edge_st = ParseState(pattern = "a", pos = 0, groupCount = 1, err = "a")
  let resNom = parseConcat(arg_st)
  let resEdge = parseConcat(edge_st)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqStr(n_t0.kind, "empty", "parseConcat nominal string matches")
  assertEqStr(e_t0.kind, "empty", "parseConcat boundary string matches")
  ret 0
```

---

### `parseQuantifiedAtom` (`std/regex/regex_compile.aipl`)

- **Signature**: `fn parseQuantifiedAtom(mut st: ParseState): (RegexAstNode, ParseState):`
- **Import**: `import * from "std/regex/regex_compile"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut st: ParseState` | **Returns**: `(RegexAstNode, ParseState)`
- **Unit Test**: `tests/functions/regex/regex_compile_test.aipl` | **Example**: `examples/ex_061_regex_vm_grep_and_replace_cli.aipl`
- **Behavioral Summary**: `, capture groups, and special-char escaping. Concrete nominal inputs: `st: ParseState): (RegexAstNode = ParseState): (RegexAstNode()`, `ParseState: any = 42`; exercises core body path returning/computing `(atom, st)`.

```aipl
module tests.functions.regex.regex_compile_z10_test
import * from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_compile_parseQuantifiedAtom_10(): int:
  let arg_st = ParseState(pattern = "test", pos = 0, groupCount = 4, err = "test")
  let edge_st = ParseState(pattern = "a", pos = 0, groupCount = 1, err = "a")
  let resNom = parseQuantifiedAtom(arg_st)
  let resEdge = parseQuantifiedAtom(edge_st)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqStr(n_t0.kind, "char", "parseQuantifiedAtom nominal string matches")
  assertEqStr(e_t0.kind, "char", "parseQuantifiedAtom boundary string matches")
  ret 0
```

---

### `parseAtom` (`std/regex/regex_compile.aipl`)

- **Signature**: `fn parseAtom(mut st: ParseState): (RegexAstNode, ParseState):`
- **Import**: `import * from "std/regex/regex_compile"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut st: ParseState` | **Returns**: `(RegexAstNode, ParseState)`
- **Unit Test**: `tests/functions/regex/regex_compile_test.aipl` | **Example**: `examples/ex_062_regex_text_diff_myers_patch_cli.aipl`
- **Behavioral Summary**: `, capture groups, and special-char escaping. Concrete nominal inputs: `st: ParseState): (RegexAstNode = ParseState): (RegexAstNode()`, `ParseState: any = 42`; exercises core body path returning/computing `(makeNode("char", pat.charCodeAt(st.pos - 1)), st)`.

```aipl
module tests.functions.regex.regex_compile_z11_test
import * from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_compile_parseAtom_11(): int:
  let arg_st = ParseState(pattern = "test", pos = 0, groupCount = 4, err = "test")
  let edge_st = ParseState(pattern = "a", pos = 0, groupCount = 1, err = "a")
  let resNom = parseAtom(arg_st)
  let resEdge = parseAtom(edge_st)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqStr(n_t0.kind, "char", "parseAtom nominal string matches")
  assertEqStr(e_t0.kind, "char", "parseAtom boundary string matches")
  ret 0
```

---

### `parseRegexAst` (`std/regex/regex_compile.aipl`)

- **Signature**: `pub fn parseRegexAst(pattern: str): Result[RegexAstNode, str]:`
- **Import**: `import * from "std/regex/regex_compile"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pattern: str` | **Returns**: `Result[RegexAstNode, str]`
- **Unit Test**: `tests/functions/regex/regex_compile_test.aipl` | **Example**: `examples/ex_063_regex_fuzzy_search_and_glob_cli.aipl`
- **Behavioral Summary**: `, capture groups, and special-char escaping. Concrete nominal inputs: `pattern: str = "aipl_test"`; exercises core body path returning/computing `Ok(root)`.

```aipl
module tests.functions.regex.regex_compile_z12_test
import * from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_compile_parseRegexAst_12(): int:
  let arg_pattern = "test"
  let edge_pattern = "a"
  let resNom = parseRegexAst(arg_pattern)
  let resEdge = parseRegexAst(edge_pattern)
  assert(resNom.isOk() == true, "parseRegexAst nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "parseRegexAst boundary resEdge.isOk() == true")
  ret 0
```

---

### `makeInst` (`std/regex/regex_compile.aipl`)

- **Signature**: `fn makeInst(opcode: int, charCode: int, targetA: int, targetB: int, groupIdx: int, cc: RegexCharClass): RegexInstruction:`
- **Import**: `import * from "std/regex/regex_compile"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `opcode: int, charCode: int, targetA: int, targetB: int, groupIdx: int, cc: RegexCharClass` | **Returns**: `RegexInstruction`
- **Unit Test**: `tests/functions/regex/regex_compile_test.aipl` | **Example**: `examples/ex_061_regex_vm_grep_and_replace_cli.aipl`
- **Behavioral Summary**: `, capture groups, and special-char escaping. Concrete nominal inputs: `opcode: int = 1`, `charCode: int = 1`, `targetA: int = 1`, `targetB: int = 1`, `groupIdx: int = 0`, `cc: RegexCharClass = RegexCharClass(ranges = [(int, int)()], negated = true)`; exercises core body path returning/computing `RegexInstruction(`.

```aipl
module tests.functions.regex.regex_compile_z13_test
import * from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_compile_makeInst_13(): int:
  let arg_opcode = 2
  let edge_opcode = 0
  let arg_charCode = 2
  let edge_charCode = 0
  let arg_targetA = 2
  let edge_targetA = 0
  let arg_targetB = 4
  let edge_targetB = 1
  let arg_groupIdx = 1
  let edge_groupIdx = 0
  let arg_cc = RegexCharClass(ranges = [], negated = true)
  let edge_cc = RegexCharClass(ranges = [], negated = false)
  let resNom = makeInst(arg_opcode, arg_charCode, arg_targetA, arg_targetB, arg_groupIdx, arg_cc)
  let resEdge = makeInst(edge_opcode, edge_charCode, edge_targetA, edge_targetB, edge_groupIdx, edge_cc)
  assertEqInt(resNom.opcode, 2, "makeInst nominal resNom.opcode == 2")
  assertEqInt(resEdge.opcode, 0, "makeInst boundary resEdge.opcode == 0")
  ret 0
```

---

### `emitNodeBytecode` (`std/regex/regex_compile.aipl`)

- **Signature**: `fn emitNodeBytecode(node: RegexAstNode, flags: RegexFlags, mut insts: [RegexInstruction]): [RegexInstruction]:`
- **Import**: `import * from "std/regex/regex_compile"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `node: RegexAstNode, flags: RegexFlags, mut insts: [RegexInstruction]` | **Returns**: `[RegexInstruction]`
- **Unit Test**: `tests/functions/regex/regex_compile_test.aipl` | **Example**: `examples/ex_062_regex_text_diff_myers_patch_cli.aipl`
- **Behavioral Summary**: `, capture groups, and special-char escaping. Concrete nominal inputs: `node: RegexAstNode = RegexAstNode(kind = "aipl_test", charCode = 1, minCount = 64, maxCount = 64, children = [RegexAstNode(kind = 0, charCode = 0, minCount = 0, maxCount = 0, children = 0, charClass = 0, groupIndex = 0)], charClass = RegexCharClass(ranges = [0], negated = true), groupIndex = 0)`, `flags: RegexFlags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true)`, `insts: [RegexInstruction] = [RegexInstruction(opcode = 1, charCode = 1, targetA = 1, targetB = 1, groupIdx = 0, charClass = RegexCharClass(ranges = 0, negated = 0))]`; exercises core body path returning/computing `insts`.

```aipl
module tests.functions.regex.regex_compile_z14_test
import * from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_compile_emitNodeBytecode_14(): int:
  let arg_node = RegexAstNode(kind = "test", charCode = 2, minCount = 4, maxCount = 4, children = [], charClass = RegexCharClass(ranges = [], negated = true), groupIndex = 4)
  let edge_node = RegexAstNode(kind = "a", charCode = 0, minCount = 1, maxCount = 1, children = [], charClass = RegexCharClass(ranges = [], negated = false), groupIndex = 1)
  let arg_flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true)
  let edge_flags = RegexFlags(ignoreCase = false, multiline = false, dotAll = false, ungreedy = false)
  let arg_insts = [RegexInstruction(opcode = 2, charCode = 2, targetA = 2, targetB = 4, groupIdx = 1, charClass = RegexCharClass(ranges = [], negated = true))]
  let edge_insts = []
  let resNom = emitNodeBytecode(arg_node, arg_flags, arg_insts)
  let resEdge = emitNodeBytecode(edge_node, edge_flags, edge_insts)
  assertEqInt(resNom.len(), 1, "emitNodeBytecode nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "emitNodeBytecode boundary resEdge.len() == 0")
  ret 0
```

---

### `countAstGroups` (`std/regex/regex_compile.aipl`)

- **Signature**: `fn countAstGroups(node: RegexAstNode): int:`
- **Import**: `import * from "std/regex/regex_compile"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `node: RegexAstNode` | **Returns**: `int`
- **Unit Test**: `tests/functions/regex/regex_compile_test.aipl` | **Example**: `examples/ex_063_regex_fuzzy_search_and_glob_cli.aipl`
- **Behavioral Summary**: `, capture groups, and special-char escaping. Concrete nominal inputs: `node: RegexAstNode = RegexAstNode(kind = "aipl_test", charCode = 1, minCount = 64, maxCount = 64, children = [RegexAstNode(kind = 0, charCode = 0, minCount = 0, maxCount = 0, children = 0, charClass = 0, groupIndex = 0)], charClass = RegexCharClass(ranges = [0], negated = true), groupIndex = 0)`; exercises core body path returning/computing `maxG`.

```aipl
module tests.functions.regex.regex_compile_z15_test
import * from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_compile_countAstGroups_15(): int:
  let arg_node = RegexAstNode(kind = "test", charCode = 2, minCount = 4, maxCount = 4, children = [], charClass = RegexCharClass(ranges = [], negated = true), groupIndex = 4)
  let edge_node = RegexAstNode(kind = "a", charCode = 0, minCount = 1, maxCount = 1, children = [], charClass = RegexCharClass(ranges = [], negated = false), groupIndex = 1)
  let resNom = countAstGroups(arg_node)
  let resEdge = countAstGroups(edge_node)
  assertEqInt(resNom, 4, "countAstGroups nominal resNom == 4")
  assertEqInt(resEdge, 1, "countAstGroups boundary resEdge == 1")
  ret 0
```

---

### `compileAstToBytecode` (`std/regex/regex_compile.aipl`)

- **Signature**: `pub fn compileAstToBytecode(ast: RegexAstNode, flags: RegexFlags): RegexBytecode:`
- **Import**: `import * from "std/regex/regex_compile"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ast: RegexAstNode, flags: RegexFlags` | **Returns**: `RegexBytecode`
- **Unit Test**: `tests/functions/regex/regex_compile_test.aipl` | **Example**: `examples/ex_061_regex_vm_grep_and_replace_cli.aipl`
- **Behavioral Summary**: `, capture groups, and special-char escaping. Concrete nominal inputs: `ast: RegexAstNode = RegexAstNode(kind = "aipl_test", charCode = 1, minCount = 64, maxCount = 64, children = [RegexAstNode(kind = 0, charCode = 0, minCount = 0, maxCount = 0, children = 0, charClass = 0, groupIndex = 0)], charClass = RegexCharClass(ranges = [0], negated = true), groupIndex = 0)`, `flags: RegexFlags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true)`; exercises core body path returning/computing `RegexBytecode(`.

```aipl
module tests.functions.regex.regex_compile_z16_test
import * from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_compile_compileAstToBytecode_16(): int:
  let arg_ast = RegexAstNode(kind = "test", charCode = 2, minCount = 4, maxCount = 4, children = [], charClass = RegexCharClass(ranges = [], negated = true), groupIndex = 4)
  let edge_ast = RegexAstNode(kind = "a", charCode = 0, minCount = 1, maxCount = 1, children = [], charClass = RegexCharClass(ranges = [], negated = false), groupIndex = 1)
  let arg_flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true)
  let edge_flags = RegexFlags(ignoreCase = false, multiline = false, dotAll = false, ungreedy = false)
  let resNom = compileAstToBytecode(arg_ast, arg_flags)
  let resEdge = compileAstToBytecode(edge_ast, edge_flags)
  assertEqInt(resNom.instructions.len(), 3, "compileAstToBytecode nominal resNom.instructions.len() == 3")
  assertEqInt(resEdge.instructions.len(), 3, "compileAstToBytecode boundary resEdge.instructions.len() == 3")
  ret 0
```

---

### `regexCompileEx` (`std/regex/regex_compile.aipl`)

- **Signature**: `pub fn regexCompileEx(pattern: str, flags: RegexFlags): Result[Regex, str]:`
- **Import**: `import * from "std/regex/regex_compile"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pattern: str, flags: RegexFlags` | **Returns**: `Result[Regex, str]`
- **Unit Test**: `tests/functions/regex/regex_compile_test.aipl` | **Example**: `examples/ex_062_regex_text_diff_myers_patch_cli.aipl`
- **Behavioral Summary**: `, capture groups, and special-char escaping. Concrete nominal inputs: `pattern: str = "aipl_test"`, `flags: RegexFlags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true)`; exercises core body path returning/computing `Ok(Regex(pattern = pattern, bytecode = bc, flags = flags, groupCount = bc.groupCount))`.

```aipl
module tests.functions.regex.regex_compile_z17_test
import * from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_compile_regexCompileEx_17(): int:
  let arg_pattern = "test"
  let edge_pattern = "a"
  let arg_flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true)
  let edge_flags = RegexFlags(ignoreCase = false, multiline = false, dotAll = false, ungreedy = false)
  let resNom = regexCompileEx(arg_pattern, arg_flags)
  let resEdge = regexCompileEx(edge_pattern, edge_flags)
  assert(resNom.isOk() == true, "regexCompileEx nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "regexCompileEx boundary resEdge.isOk() == true")
  ret 0
```

---

### `regexCompile` (`std/regex/regex_compile.aipl`)

- **Signature**: `pub fn regexCompile(pattern: str): Result[Regex, str]:`
- **Import**: `import * from "std/regex/regex_compile"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pattern: str` | **Returns**: `Result[Regex, str]`
- **Unit Test**: `tests/functions/regex/regex_compile_test.aipl` | **Example**: `examples/ex_063_regex_fuzzy_search_and_glob_cli.aipl`
- **Behavioral Summary**: `, capture groups, and special-char escaping. Concrete nominal inputs: `pattern: str = "aipl_test"`; exercises core body path returning/computing `regexCompileEx(pattern, defaultRegexFlags())`.

```aipl
module tests.functions.regex.regex_compile_z18_test
import * from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_compile_regexCompile_18(): int:
  let arg_pattern = "test"
  let edge_pattern = "a"
  let resNom = regexCompile(arg_pattern)
  let resEdge = regexCompile(edge_pattern)
  assert(resNom.isOk() == true, "regexCompile nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "regexCompile boundary resEdge.isOk() == true")
  ret 0
```

---

### `escapeRegexSpecial` (`std/regex/regex_compile.aipl`)

- **Signature**: `pub fn escapeRegexSpecial(pattern: str): str:`
- **Import**: `import * from "std/regex/regex_compile"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pattern: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/regex/regex_compile_test.aipl` | **Example**: `examples/ex_061_regex_vm_grep_and_replace_cli.aipl`
- **Behavioral Summary**: `, capture groups, and special-char escaping. Concrete nominal inputs: `pattern: str = "aipl_test"`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.regex.regex_compile_z19_test
import * from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_compile_escapeRegexSpecial_19(): int:
  let arg_pattern = "test"
  let edge_pattern = "a"
  let resNom = escapeRegexSpecial(arg_pattern)
  let resEdge = escapeRegexSpecial(edge_pattern)
  assertEqStr(resNom, "test", "escapeRegexSpecial nominal string matches")
  assertEqStr(resEdge, "a", "escapeRegexSpecial boundary string matches")
  ret 0
```

---

### `regexMatch` (`std/regex/regex_mod.aipl`)

- **Signature**: `pub fn regexMatch(pattern: str, text: str): bool:`
- **Import**: `import * from "std/regex/regex_mod"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pattern: str, text: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/regex/regex_mod_test.aipl` | **Example**: `examples/ex_062_regex_text_diff_myers_patch_cli.aipl`
- **Behavioral Summary**: Verify top-level regex/diff facade `regexMatch` on match, search, split, replace, and patch workflows. Concrete nominal inputs: `pattern: str = "aipl_test"`, `text: str = "aipl_test"`; exercises core body path returning/computing `reRes.unwrap().isMatch(text)`.

```aipl
module tests.functions.regex.regex_mod_z1_test
import * from "std/regex/regex_mod"
import { Regex, regexCompile } from "std/regex/regex_compile"
import { RegexMatch } from "std/regex/regex_vm"
import { formatUnifiedDiff, parseUnifiedPatch, applyUnifiedPatch, editDistance, similarityRatio } from "std/regex/text_diff"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_mod_regexMatch_1(): int:
  let arg_pattern = "test"
  let edge_pattern = "a"
  let arg_text = "test"
  let edge_text = "a"
  let resNom = regexMatch(arg_pattern, arg_text)
  let resEdge = regexMatch(edge_pattern, edge_text)
  assert(resNom == true, "regexMatch nominal resNom == true")
  assert(resEdge == true, "regexMatch boundary resEdge == true")
  ret 0
```

---

### `regexIsMatch` (`std/regex/regex_mod.aipl`)

- **Signature**: `pub fn regexIsMatch(re: Regex, text: str): bool:`
- **Import**: `import * from "std/regex/regex_mod"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `re: Regex, text: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/regex/regex_mod_test.aipl` | **Example**: `examples/ex_063_regex_fuzzy_search_and_glob_cli.aipl`
- **Behavioral Summary**: Verify top-level regex/diff facade `regexIsMatch` on match, search, split, replace, and patch workflows. Concrete nominal inputs: `re: Regex = Regex(pattern = "aipl_test", bytecode = RegexBytecode(instructions = [0], groupCount = 64, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 64)`, `text: str = "aipl_test"`; exercises core body path returning/computing `re.isMatch(text)`.

```aipl
module tests.functions.regex.regex_mod_z2_test
import * from "std/regex/regex_mod"
import { Regex, regexCompile } from "std/regex/regex_compile"
import { RegexMatch } from "std/regex/regex_vm"
import { formatUnifiedDiff, parseUnifiedPatch, applyUnifiedPatch, editDistance, similarityRatio } from "std/regex/text_diff"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_mod_regexIsMatch_2(): int:
  let arg_re = Regex(pattern = "test", bytecode = RegexBytecode(instructions = [], groupCount = 4, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 4)
  let edge_re = Regex(pattern = "a", bytecode = RegexBytecode(instructions = [], groupCount = 1, anchoredStart = false, anchoredEnd = false), flags = RegexFlags(ignoreCase = false, multiline = false, dotAll = false, ungreedy = false), groupCount = 1)
  let arg_text = "test"
  let edge_text = "a"
  let resNom = regexIsMatch(arg_re, arg_text)
  let resEdge = regexIsMatch(edge_re, edge_text)
  assert(resNom == false, "regexIsMatch nominal resNom == false")
  assert(resEdge == false, "regexIsMatch boundary resEdge == false")
  ret 0
```

---

### `regexSplit` (`std/regex/regex_mod.aipl`)

- **Signature**: `pub fn regexSplit(re: Regex, text: str): [str]:`
- **Import**: `import * from "std/regex/regex_mod"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `re: Regex, text: str` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/regex/regex_mod_test.aipl` | **Example**: `examples/ex_061_regex_vm_grep_and_replace_cli.aipl`
- **Behavioral Summary**: Verify top-level regex/diff facade `regexSplit` on match, search, split, replace, and patch workflows. Concrete nominal inputs: `re: Regex = Regex(pattern = "aipl_test", bytecode = RegexBytecode(instructions = [0], groupCount = 64, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 64)`, `text: str = "aipl_test"`; exercises core body path returning/computing `re.split(text)`.

```aipl
module tests.functions.regex.regex_mod_z3_test
import * from "std/regex/regex_mod"
import { Regex, regexCompile } from "std/regex/regex_compile"
import { RegexMatch } from "std/regex/regex_vm"
import { formatUnifiedDiff, parseUnifiedPatch, applyUnifiedPatch, editDistance, similarityRatio } from "std/regex/text_diff"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_mod_regexSplit_3(): int:
  let arg_re = Regex(pattern = "test", bytecode = RegexBytecode(instructions = [], groupCount = 4, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 4)
  let edge_re = Regex(pattern = "a", bytecode = RegexBytecode(instructions = [], groupCount = 1, anchoredStart = false, anchoredEnd = false), flags = RegexFlags(ignoreCase = false, multiline = false, dotAll = false, ungreedy = false), groupCount = 1)
  let arg_text = "test"
  let edge_text = "a"
  let resNom = regexSplit(arg_re, arg_text)
  let resEdge = regexSplit(edge_re, edge_text)
  assertEqInt(resNom.len(), 1, "regexSplit nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "regexSplit boundary resEdge.len() == 1")
  ret 0
```

---

### `regexFind` (`std/regex/regex_mod.aipl`)

- **Signature**: `pub fn regexFind(pattern: str, text: str): Option[RegexMatch]:`
- **Import**: `import * from "std/regex/regex_mod"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pattern: str, text: str` | **Returns**: `Option[RegexMatch]`
- **Unit Test**: `tests/functions/regex/regex_mod_test.aipl` | **Example**: `examples/ex_062_regex_text_diff_myers_patch_cli.aipl`
- **Behavioral Summary**: Verify top-level regex/diff facade `regexFind` on match, search, split, replace, and patch workflows. Concrete nominal inputs: `pattern: str = "aipl_test"`, `text: str = "aipl_test"`; exercises core body path returning/computing `reRes.unwrap().find(text)`.

```aipl
module tests.functions.regex.regex_mod_z4_test
import * from "std/regex/regex_mod"
import { Regex, regexCompile } from "std/regex/regex_compile"
import { RegexMatch } from "std/regex/regex_vm"
import { formatUnifiedDiff, parseUnifiedPatch, applyUnifiedPatch, editDistance, similarityRatio } from "std/regex/text_diff"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_mod_regexFind_4(): int:
  let arg_pattern = "test"
  let edge_pattern = "a"
  let arg_text = "test"
  let edge_text = "a"
  let resNom = regexFind(arg_pattern, arg_text)
  let resEdge = regexFind(edge_pattern, edge_text)
  assert(resNom.isSome() == true, "regexFind nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "regexFind boundary resEdge.isSome() == true")
  ret 0
```

---

### `regexFindAll` (`std/regex/regex_mod.aipl`)

- **Signature**: `pub fn regexFindAll(pattern: str, text: str): [RegexMatch]:`
- **Import**: `import * from "std/regex/regex_mod"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pattern: str, text: str` | **Returns**: `[RegexMatch]`
- **Unit Test**: `tests/functions/regex/regex_mod_test.aipl` | **Example**: `examples/ex_063_regex_fuzzy_search_and_glob_cli.aipl`
- **Behavioral Summary**: Verify top-level regex/diff facade `regexFindAll` on match, search, split, replace, and patch workflows. Concrete nominal inputs: `pattern: str = "aipl_test"`, `text: str = "aipl_test"`; exercises core body path returning/computing `reRes.unwrap().findAll(text)`.

```aipl
module tests.functions.regex.regex_mod_z5_test
import * from "std/regex/regex_mod"
import { Regex, regexCompile } from "std/regex/regex_compile"
import { RegexMatch } from "std/regex/regex_vm"
import { formatUnifiedDiff, parseUnifiedPatch, applyUnifiedPatch, editDistance, similarityRatio } from "std/regex/text_diff"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_mod_regexFindAll_5(): int:
  let arg_pattern = "test"
  let edge_pattern = "a"
  let arg_text = "test"
  let edge_text = "a"
  let resNom = regexFindAll(arg_pattern, arg_text)
  let resEdge = regexFindAll(edge_pattern, edge_text)
  assertEqInt(resNom.len(), 1, "regexFindAll nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "regexFindAll boundary resEdge.len() == 1")
  ret 0
```

---

### `regexReplace` (`std/regex/regex_mod.aipl`)

- **Signature**: `pub fn regexReplace(pattern: any, text: str, replacement: str): str:`
- **Import**: `import * from "std/regex/regex_mod"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pattern: any, text: str, replacement: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/regex/regex_mod_test.aipl` | **Example**: `examples/ex_061_regex_vm_grep_and_replace_cli.aipl`
- **Behavioral Summary**: Verify top-level regex/diff facade `regexReplace` on match, search, split, replace, and patch workflows. Concrete nominal inputs: `pattern: any = 42`, `text: str = "aipl_test"`, `replacement: str = "aipl_test"`; exercises core body path returning/computing `reRes.unwrap().replace(text, replacement)`.

```aipl
module tests.functions.regex.regex_mod_z6_test
import * from "std/regex/regex_mod"
import { Regex, regexCompile } from "std/regex/regex_compile"
import { RegexMatch } from "std/regex/regex_vm"
import { formatUnifiedDiff, parseUnifiedPatch, applyUnifiedPatch, editDistance, similarityRatio } from "std/regex/text_diff"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_mod_regexReplace_6(): int:
  let arg_pattern = 1
  let edge_pattern = 0
  let arg_text = "test"
  let edge_text = "a"
  let arg_replacement = "test"
  let edge_replacement = "a"
  let resNom = regexReplace(arg_pattern, arg_text, arg_replacement)
  let resEdge = regexReplace(edge_pattern, edge_text, edge_replacement)
  assertEqStr(resNom, "test", "regexReplace nominal string matches")
  assertEqStr(resEdge, "a", "regexReplace boundary string matches")
  ret 0
```

---

### `regexReplaceAll` (`std/regex/regex_mod.aipl`)

- **Signature**: `pub fn regexReplaceAll(pattern: any, text: str, replacement: str): str:`
- **Import**: `import * from "std/regex/regex_mod"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pattern: any, text: str, replacement: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/regex/regex_mod_test.aipl` | **Example**: `examples/ex_062_regex_text_diff_myers_patch_cli.aipl`
- **Behavioral Summary**: Verify top-level regex/diff facade `regexReplaceAll` on match, search, split, replace, and patch workflows. Concrete nominal inputs: `pattern: any = 42`, `text: str = "aipl_test"`, `replacement: str = "aipl_test"`; exercises core body path returning/computing `reRes.unwrap().replaceAll(text, replacement)`.

```aipl
module tests.functions.regex.regex_mod_z7_test
import * from "std/regex/regex_mod"
import { Regex, regexCompile } from "std/regex/regex_compile"
import { RegexMatch } from "std/regex/regex_vm"
import { formatUnifiedDiff, parseUnifiedPatch, applyUnifiedPatch, editDistance, similarityRatio } from "std/regex/text_diff"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_mod_regexReplaceAll_7(): int:
  let arg_pattern = 1
  let edge_pattern = 0
  let arg_text = "test"
  let edge_text = "a"
  let arg_replacement = "test"
  let edge_replacement = "a"
  let resNom = regexReplaceAll(arg_pattern, arg_text, arg_replacement)
  let resEdge = regexReplaceAll(edge_pattern, edge_text, edge_replacement)
  assertEqStr(resNom, "test", "regexReplaceAll nominal string matches")
  assertEqStr(resEdge, "a", "regexReplaceAll boundary string matches")
  ret 0
```

---

### `diffTexts` (`std/regex/regex_mod.aipl`)

- **Signature**: `pub fn diffTexts(oldText: str, newText: str, contextRadius: int = 3): str:`
- **Import**: `import * from "std/regex/regex_mod"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `oldText: str, newText: str, contextRadius: int = 3` | **Returns**: `str`
- **Unit Test**: `tests/functions/regex/regex_mod_test.aipl` | **Example**: `examples/ex_063_regex_fuzzy_search_and_glob_cli.aipl`
- **Behavioral Summary**: Verify top-level regex/diff facade `diffTexts` on match, search, split, replace, and patch workflows. Concrete nominal inputs: `oldText: str = "aipl_test"`, `newText: str = "aipl_test"`, `contextRadius: int = 1`; exercises core body path returning/computing `formatUnifiedDiff("a", "b", oldText, newText, contextRadius)`.

```aipl
module tests.functions.regex.regex_mod_z8_test
import * from "std/regex/regex_mod"
import { Regex, regexCompile } from "std/regex/regex_compile"
import { RegexMatch } from "std/regex/regex_vm"
import { formatUnifiedDiff, parseUnifiedPatch, applyUnifiedPatch, editDistance, similarityRatio } from "std/regex/text_diff"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_mod_diffTexts_8(): int:
  let arg_oldText = "test"
  let edge_oldText = "a"
  let arg_newText = "test"
  let edge_newText = "a"
  let arg_contextRadius = 4
  let edge_contextRadius = 1
  let resNom = diffTexts(arg_oldText, arg_newText, arg_contextRadius)
  let resEdge = diffTexts(edge_oldText, edge_newText, edge_contextRadius)
  assertEqInt(resNom.len(), 12, "diffTexts nominal string length == 12")
  assertEqInt(resEdge.len(), 12, "diffTexts boundary string length == 12")
  ret 0
```

---

### `applyPatch` (`std/regex/regex_mod.aipl`)

- **Signature**: `pub fn applyPatch(originalText: str, patchText: str): Result[str, str]:`
- **Import**: `import * from "std/regex/regex_mod"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `originalText: str, patchText: str` | **Returns**: `Result[str, str]`
- **Unit Test**: `tests/functions/regex/regex_mod_test.aipl` | **Example**: `examples/ex_061_regex_vm_grep_and_replace_cli.aipl`
- **Behavioral Summary**: Verify top-level regex/diff facade `applyPatch` on match, search, split, replace, and patch workflows. Concrete nominal inputs: `originalText: str = "aipl_test"`, `patchText: str = "aipl_test"`; exercises core body path returning/computing `applyUnifiedPatch(originalText, pRes.unwrap())`.

```aipl
module tests.functions.regex.regex_mod_z9_test
import * from "std/regex/regex_mod"
import { Regex, regexCompile } from "std/regex/regex_compile"
import { RegexMatch } from "std/regex/regex_vm"
import { formatUnifiedDiff, parseUnifiedPatch, applyUnifiedPatch, editDistance, similarityRatio } from "std/regex/text_diff"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_mod_applyPatch_9(): int:
  let arg_originalText = "test"
  let edge_originalText = "a"
  let arg_patchText = "test"
  let edge_patchText = "a"
  let resNom = applyPatch(arg_originalText, arg_patchText)
  let resEdge = applyPatch(edge_originalText, edge_patchText)
  assert(resNom.isOk() == false, "applyPatch nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "applyPatch boundary resEdge.isOk() == false")
  ret 0
```

---

### `toLowerAsciiCode` (`std/regex/regex_vm.aipl`)

- **Signature**: `fn toLowerAsciiCode(c: int): int:`
- **Import**: `import * from "std/regex/regex_vm"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/regex/regex_vm_test.aipl` | **Example**: `examples/ex_062_regex_text_diff_myers_patch_cli.aipl`
- **Behavioral Summary**: Verify linear-time PikeVM execution function `toLowerAsciiCode` (`free fn`) on non-backtracking pathological inputs (`a?a?a?aaa`), numbered group captures, `$1` replacement expansion, and bounded splitting. Concrete nominal inputs: `c: int = 1`; exercises core body path returning/computing `c`.

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

---

### `charMatchesClass` (`std/regex/regex_vm.aipl`)

- **Signature**: `fn charMatchesClass(c: int, cc: RegexCharClass, ignoreCase: bool): bool:`
- **Import**: `import * from "std/regex/regex_vm"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: int, cc: RegexCharClass, ignoreCase: bool` | **Returns**: `bool`
- **Unit Test**: `tests/functions/regex/regex_vm_test.aipl` | **Example**: `examples/ex_063_regex_fuzzy_search_and_glob_cli.aipl`
- **Behavioral Summary**: Verify linear-time PikeVM execution function `charMatchesClass` (`free fn`) on non-backtracking pathological inputs (`a?a?a?aaa`), numbered group captures, `$1` replacement expansion, and bounded splitting. Concrete nominal inputs: `c: int = 1`, `cc: RegexCharClass = RegexCharClass(ranges = [(int, int)()], negated = true)`, `ignoreCase: bool = true`; exercises core body path returning/computing `if cc.negated: not matched else: matched`.

```aipl
module tests.functions.regex.regex_vm_z2_test
import * from "std/regex/regex_vm"
import { OP_MATCH, OP_CHAR, OP_ANY, OP_CHAR_CLASS, OP_SPLIT, OP_JUMP, OP_SAVE, OP_ANCHOR_START, OP_ANCHOR_END, RegexFlags, RegexCharClass, RegexInstruction, RegexBytecode, Regex } from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_vm_charMatchesClass_2(): int:
  let arg_c = 2
  let edge_c = 0
  let arg_cc = RegexCharClass(ranges = [], negated = true)
  let edge_cc = RegexCharClass(ranges = [], negated = false)
  let arg_ignoreCase = true
  let edge_ignoreCase = false
  let resNom = charMatchesClass(arg_c, arg_cc, arg_ignoreCase)
  let resEdge = charMatchesClass(edge_c, edge_cc, edge_ignoreCase)
  assert(resNom == true, "charMatchesClass nominal resNom == true")
  assert(resEdge == false, "charMatchesClass boundary resEdge == false")
  ret 0
```

---

### `cloneIntSlots` (`std/regex/regex_vm.aipl`)

- **Signature**: `fn cloneIntSlots(slots: [int]): [int]:`
- **Import**: `import * from "std/regex/regex_vm"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `slots: [int]` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/regex/regex_vm_test.aipl` | **Example**: `examples/ex_061_regex_vm_grep_and_replace_cli.aipl`
- **Behavioral Summary**: Verify linear-time PikeVM execution function `cloneIntSlots` (`free fn`) on non-backtracking pathological inputs (`a?a?a?aaa`), numbered group captures, `$1` replacement expansion, and bounded splitting. Concrete nominal inputs: `slots: [int] = [1]`; exercises core body path returning/computing `copy`.

```aipl
module tests.functions.regex.regex_vm_z3_test
import * from "std/regex/regex_vm"
import { OP_MATCH, OP_CHAR, OP_ANY, OP_CHAR_CLASS, OP_SPLIT, OP_JUMP, OP_SAVE, OP_ANCHOR_START, OP_ANCHOR_END, RegexFlags, RegexCharClass, RegexInstruction, RegexBytecode, Regex } from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_vm_cloneIntSlots_3(): int:
  let arg_slots = [1]
  let edge_slots = []
  let resNom = cloneIntSlots(arg_slots)
  let resEdge = cloneIntSlots(edge_slots)
  assertEqInt(resNom.len(), 1, "cloneIntSlots nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "cloneIntSlots boundary resEdge.len() == 0")
  ret 0
```

---

### `addPikeThread` (`std/regex/regex_vm.aipl`)

- **Signature**: `fn addPikeThread( mut list: [PikeThread], mut visited: [int], stepId: int, pc: int, slots: [int], bc: RegexBytecode, flags: RegexFlags, text: str, pos: int ): [PikeThread]:`
- **Import**: `import * from "std/regex/regex_vm"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut list: [PikeThread], mut visited: [int], stepId: int, pc: int, slots: [int], bc: RegexBytecode, flags: RegexFlags, text: str, pos: int` | **Returns**: `[PikeThread]`
- **Unit Test**: `tests/functions/regex/regex_vm_test.aipl` | **Example**: `examples/ex_062_regex_text_diff_myers_patch_cli.aipl`
- **Behavioral Summary**: Verify linear-time PikeVM execution function `addPikeThread` (`free fn`) on non-backtracking pathological inputs (`a?a?a?aaa`), numbered group captures, `$1` replacement expansion, and bounded splitting. Concrete nominal inputs: `list: [PikeThread] = [PikeThread(pc = 1, slots = [0])]`, `visited: [int] = [1]`, `stepId: int = 1`, `pc: int = 1`, `slots: [int] = [1]`, `bc: RegexBytecode = RegexBytecode(instructions = [RegexInstruction(opcode = 0, charCode = 0, targetA = 0, targetB = 0, groupIdx = 0, charClass = 0)], groupCount = 64, anchoredStart = true, anchoredEnd = true)`, `flags: RegexFlags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true)`, `text: str = "aipl_test"`, `pos: int = 0`; exercises core body path returning/computing `list`.

```aipl
module tests.functions.regex.regex_vm_z4_test
import * from "std/regex/regex_vm"
import { OP_MATCH, OP_CHAR, OP_ANY, OP_CHAR_CLASS, OP_SPLIT, OP_JUMP, OP_SAVE, OP_ANCHOR_START, OP_ANCHOR_END, RegexFlags, RegexCharClass, RegexInstruction, RegexBytecode, Regex } from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_vm_addPikeThread_4(): int:
  let arg_list = [PikeThread(pc = 2, slots = [])]
  let edge_list = []
  let arg_visited = [2]
  let edge_visited = []
  let arg_stepId = 4
  let edge_stepId = 1
  let arg_pc = 2
  let edge_pc = 0
  let arg_slots = [1]
  let edge_slots = []
  let arg_bc = RegexBytecode(instructions = [], groupCount = 4, anchoredStart = true, anchoredEnd = true)
  let edge_bc = RegexBytecode(instructions = [], groupCount = 1, anchoredStart = false, anchoredEnd = false)
  let arg_flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true)
  let edge_flags = RegexFlags(ignoreCase = false, multiline = false, dotAll = false, ungreedy = false)
  let arg_text = "test"
  let edge_text = "a"
  let arg_pos = 1
  let edge_pos = 0
  let resNom = addPikeThread(arg_list, arg_visited, arg_stepId, arg_pc, arg_slots, arg_bc, arg_flags, arg_text, arg_pos)
  let resEdge = addPikeThread(edge_list, edge_visited, edge_stepId, edge_pc, edge_slots, edge_bc, edge_flags, edge_text, edge_pos)
  assertEqInt(resNom.len(), 1, "addPikeThread nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "addPikeThread boundary resEdge.len() == 0")
  ret 0
```

---

### `runPikeAtPos` (`std/regex/regex_vm.aipl`)

- **Signature**: `fn runPikeAtPos(re: Regex, text: str, startPos: int): Option[[int]]:`
- **Import**: `import * from "std/regex/regex_vm"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `re: Regex, text: str, startPos: int` | **Returns**: `Option[[int]]`
- **Unit Test**: `tests/functions/regex/regex_vm_test.aipl` | **Example**: `examples/ex_063_regex_fuzzy_search_and_glob_cli.aipl`
- **Behavioral Summary**: Verify linear-time PikeVM execution function `runPikeAtPos` (`free fn`) on non-backtracking pathological inputs (`a?a?a?aaa`), numbered group captures, `$1` replacement expansion, and bounded splitting. Concrete nominal inputs: `re: Regex = Regex(pattern = "aipl_test", bytecode = RegexBytecode(instructions = [0], groupCount = 64, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 64)`, `text: str = "aipl_test"`, `startPos: int = 0`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.regex.regex_vm_z5_test
import * from "std/regex/regex_vm"
import { OP_MATCH, OP_CHAR, OP_ANY, OP_CHAR_CLASS, OP_SPLIT, OP_JUMP, OP_SAVE, OP_ANCHOR_START, OP_ANCHOR_END, RegexFlags, RegexCharClass, RegexInstruction, RegexBytecode, Regex } from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_vm_runPikeAtPos_5(): int:
  let arg_re = Regex(pattern = "test", bytecode = RegexBytecode(instructions = [], groupCount = 4, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 4)
  let edge_re = Regex(pattern = "a", bytecode = RegexBytecode(instructions = [], groupCount = 1, anchoredStart = false, anchoredEnd = false), flags = RegexFlags(ignoreCase = false, multiline = false, dotAll = false, ungreedy = false), groupCount = 1)
  let arg_text = "test"
  let edge_text = "a"
  let arg_startPos = 1
  let edge_startPos = 0
  let resNom = runPikeAtPos(arg_re, arg_text, arg_startPos)
  let resEdge = runPikeAtPos(edge_re, edge_text, edge_startPos)
  assert(resNom.isSome() == false, "runPikeAtPos nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "runPikeAtPos boundary resEdge.isSome() == false")
  ret 0
```

---

### `buildRegexMatch` (`std/regex/regex_vm.aipl`)

- **Signature**: `fn buildRegexMatch(text: str, slots: [int], groupCount: int): RegexMatch:`
- **Import**: `import * from "std/regex/regex_vm"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str, slots: [int], groupCount: int` | **Returns**: `RegexMatch`
- **Unit Test**: `tests/functions/regex/regex_vm_test.aipl` | **Example**: `examples/ex_061_regex_vm_grep_and_replace_cli.aipl`
- **Behavioral Summary**: Verify linear-time PikeVM execution function `buildRegexMatch` (`free fn`) on non-backtracking pathological inputs (`a?a?a?aaa`), numbered group captures, `$1` replacement expansion, and bounded splitting. Concrete nominal inputs: `text: str = "aipl_test"`, `slots: [int] = [1]`, `groupCount: int = 64`; exercises core body path returning/computing `RegexMatch(start = mStart, end = mEnd, text = text.slice(mStart, mEnd), groups = groups)`.

```aipl
module tests.functions.regex.regex_vm_z6_test
import * from "std/regex/regex_vm"
import { OP_MATCH, OP_CHAR, OP_ANY, OP_CHAR_CLASS, OP_SPLIT, OP_JUMP, OP_SAVE, OP_ANCHOR_START, OP_ANCHOR_END, RegexFlags, RegexCharClass, RegexInstruction, RegexBytecode, Regex } from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_vm_buildRegexMatch_6(): int:
  let arg_text = "test"
  let edge_text = "a"
  let arg_slots = [1]
  let edge_slots = []
  let arg_groupCount = 4
  let edge_groupCount = 1
  let resNom = buildRegexMatch(arg_text, arg_slots, arg_groupCount)
  let resEdge = buildRegexMatch(edge_text, edge_slots, edge_groupCount)
  assertEqInt(resNom.start, 0, "buildRegexMatch nominal resNom.start == 0")
  assertEqInt(resEdge.start, 0, "buildRegexMatch boundary resEdge.start == 0")
  ret 0
```

---

### `find` (`std/regex/regex_vm.aipl`)

- **Signature**: `pub fn (self: Regex) find(text: str): Option[RegexMatch]:`
- **Import**: `import * from "std/regex/regex_vm"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `self: Regex` | **Parameters**: `text: str` | **Returns**: `Option[RegexMatch]`
- **Unit Test**: `tests/functions/regex/regex_vm_test.aipl` | **Example**: `examples/ex_062_regex_text_diff_myers_patch_cli.aipl`
- **Behavioral Summary**: Verify linear-time PikeVM execution function `find` (`self: Regex`) on non-backtracking pathological inputs (`a?a?a?aaa`), numbered group captures, `$1` replacement expansion, and bounded splitting. Concrete nominal inputs: receiver `recvObj: Regex = Regex(pattern = "aipl_test", bytecode = RegexBytecode(instructions = [0], groupCount = 64, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 64)`, `text: str = "aipl_test"`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.regex.regex_vm_z7_test
import * from "std/regex/regex_vm"
import { OP_MATCH, OP_CHAR, OP_ANY, OP_CHAR_CLASS, OP_SPLIT, OP_JUMP, OP_SAVE, OP_ANCHOR_START, OP_ANCHOR_END, RegexFlags, RegexCharClass, RegexInstruction, RegexBytecode, Regex } from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_vm_Regex_find_7(): int:
  let recv_self = Regex(pattern = "test", bytecode = RegexBytecode(instructions = [], groupCount = 4, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 4)
  let edge_self = Regex(pattern = "a", bytecode = RegexBytecode(instructions = [], groupCount = 1, anchoredStart = false, anchoredEnd = false), flags = RegexFlags(ignoreCase = false, multiline = false, dotAll = false, ungreedy = false), groupCount = 1)
  let arg_text = "test"
  let edge_text = "a"
  let resNom = recv_self.find(arg_text)
  let resEdge = edge_self.find(edge_text)
  assert(resNom.isSome() == false, "find nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "find boundary resEdge.isSome() == false")
  ret 0
```

---

### `isMatch` (`std/regex/regex_vm.aipl`)

- **Signature**: `pub fn (self: Regex) isMatch(text: str): bool:`
- **Import**: `import * from "std/regex/regex_vm"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `self: Regex` | **Parameters**: `text: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/regex/regex_vm_test.aipl` | **Example**: `examples/ex_063_regex_fuzzy_search_and_glob_cli.aipl`
- **Behavioral Summary**: Verify linear-time PikeVM execution function `isMatch` (`self: Regex`) on non-backtracking pathological inputs (`a?a?a?aaa`), numbered group captures, `$1` replacement expansion, and bounded splitting. Concrete nominal inputs: receiver `recvObj: Regex = Regex(pattern = "aipl_test", bytecode = RegexBytecode(instructions = [0], groupCount = 64, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 64)`, `text: str = "aipl_test"`; exercises core body path returning/computing `self.find(text).isSome()`.

```aipl
module tests.functions.regex.regex_vm_z8_test
import * from "std/regex/regex_vm"
import { OP_MATCH, OP_CHAR, OP_ANY, OP_CHAR_CLASS, OP_SPLIT, OP_JUMP, OP_SAVE, OP_ANCHOR_START, OP_ANCHOR_END, RegexFlags, RegexCharClass, RegexInstruction, RegexBytecode, Regex } from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_vm_Regex_isMatch_8(): int:
  let recv_self = Regex(pattern = "test", bytecode = RegexBytecode(instructions = [], groupCount = 4, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 4)
  let edge_self = Regex(pattern = "a", bytecode = RegexBytecode(instructions = [], groupCount = 1, anchoredStart = false, anchoredEnd = false), flags = RegexFlags(ignoreCase = false, multiline = false, dotAll = false, ungreedy = false), groupCount = 1)
  let arg_text = "test"
  let edge_text = "a"
  let resNom = recv_self.isMatch(arg_text)
  let resEdge = edge_self.isMatch(edge_text)
  assert(resNom == false, "isMatch nominal resNom == false")
  assert(resEdge == false, "isMatch boundary resEdge == false")
  ret 0
```

---

### `findSpan` (`std/regex/regex_vm.aipl`)

- **Signature**: `pub fn (self: Regex) findSpan(text: str): Option[RegexSpan]:`
- **Import**: `import * from "std/regex/regex_vm"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `self: Regex` | **Parameters**: `text: str` | **Returns**: `Option[RegexSpan]`
- **Unit Test**: `tests/functions/regex/regex_vm_test.aipl` | **Example**: `examples/ex_061_regex_vm_grep_and_replace_cli.aipl`
- **Behavioral Summary**: Verify linear-time PikeVM execution function `findSpan` (`self: Regex`) on non-backtracking pathological inputs (`a?a?a?aaa`), numbered group captures, `$1` replacement expansion, and bounded splitting. Concrete nominal inputs: receiver `recvObj: Regex = Regex(pattern = "aipl_test", bytecode = RegexBytecode(instructions = [0], groupCount = 64, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 64)`, `text: str = "aipl_test"`; exercises core body path returning/computing `Some(RegexSpan(start = m.start, end = m.end))`.

```aipl
module tests.functions.regex.regex_vm_z9_test
import * from "std/regex/regex_vm"
import { OP_MATCH, OP_CHAR, OP_ANY, OP_CHAR_CLASS, OP_SPLIT, OP_JUMP, OP_SAVE, OP_ANCHOR_START, OP_ANCHOR_END, RegexFlags, RegexCharClass, RegexInstruction, RegexBytecode, Regex } from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_vm_Regex_findSpan_9(): int:
  let recv_self = Regex(pattern = "test", bytecode = RegexBytecode(instructions = [], groupCount = 4, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 4)
  let edge_self = Regex(pattern = "a", bytecode = RegexBytecode(instructions = [], groupCount = 1, anchoredStart = false, anchoredEnd = false), flags = RegexFlags(ignoreCase = false, multiline = false, dotAll = false, ungreedy = false), groupCount = 1)
  let arg_text = "test"
  let edge_text = "a"
  let resNom = recv_self.findSpan(arg_text)
  let resEdge = edge_self.findSpan(edge_text)
  assert(resNom.isSome() == false, "findSpan nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "findSpan boundary resEdge.isSome() == false")
  ret 0
```

---

### `findAll` (`std/regex/regex_vm.aipl`)

- **Signature**: `pub fn (self: Regex) findAll(text: str): [RegexMatch]:`
- **Import**: `import * from "std/regex/regex_vm"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `self: Regex` | **Parameters**: `text: str` | **Returns**: `[RegexMatch]`
- **Unit Test**: `tests/functions/regex/regex_vm_test.aipl` | **Example**: `examples/ex_062_regex_text_diff_myers_patch_cli.aipl`
- **Behavioral Summary**: Verify linear-time PikeVM execution function `findAll` (`self: Regex`) on non-backtracking pathological inputs (`a?a?a?aaa`), numbered group captures, `$1` replacement expansion, and bounded splitting. Concrete nominal inputs: receiver `recvObj: Regex = Regex(pattern = "aipl_test", bytecode = RegexBytecode(instructions = [0], groupCount = 64, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 64)`, `text: str = "aipl_test"`; exercises core body path returning/computing `matches`.

```aipl
module tests.functions.regex.regex_vm_z10_test
import * from "std/regex/regex_vm"
import { OP_MATCH, OP_CHAR, OP_ANY, OP_CHAR_CLASS, OP_SPLIT, OP_JUMP, OP_SAVE, OP_ANCHOR_START, OP_ANCHOR_END, RegexFlags, RegexCharClass, RegexInstruction, RegexBytecode, Regex } from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_vm_Regex_findAll_10(): int:
  let recv_self = Regex(pattern = "test", bytecode = RegexBytecode(instructions = [], groupCount = 4, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 4)
  let edge_self = Regex(pattern = "a", bytecode = RegexBytecode(instructions = [], groupCount = 1, anchoredStart = false, anchoredEnd = false), flags = RegexFlags(ignoreCase = false, multiline = false, dotAll = false, ungreedy = false), groupCount = 1)
  let arg_text = "test"
  let edge_text = "a"
  let resNom = recv_self.findAll(arg_text)
  let resEdge = edge_self.findAll(edge_text)
  assertEqInt(resNom.len(), 0, "findAll nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "findAll boundary resEdge.len() == 0")
  ret 0
```

---

### `captures` (`std/regex/regex_vm.aipl`)

- **Signature**: `pub fn (self: Regex) captures(text: str): [str]:`
- **Import**: `import * from "std/regex/regex_vm"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `self: Regex` | **Parameters**: `text: str` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/regex/regex_vm_test.aipl` | **Example**: `examples/ex_063_regex_fuzzy_search_and_glob_cli.aipl`
- **Behavioral Summary**: Verify linear-time PikeVM execution function `captures` (`self: Regex`) on non-backtracking pathological inputs (`a?a?a?aaa`), numbered group captures, `$1` replacement expansion, and bounded splitting. Concrete nominal inputs: receiver `recvObj: Regex = Regex(pattern = "aipl_test", bytecode = RegexBytecode(instructions = [0], groupCount = 64, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 64)`, `text: str = "aipl_test"`; exercises core body path returning/computing `mOpt.unwrap().groups`.

```aipl
module tests.functions.regex.regex_vm_z11_test
import * from "std/regex/regex_vm"
import { OP_MATCH, OP_CHAR, OP_ANY, OP_CHAR_CLASS, OP_SPLIT, OP_JUMP, OP_SAVE, OP_ANCHOR_START, OP_ANCHOR_END, RegexFlags, RegexCharClass, RegexInstruction, RegexBytecode, Regex } from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_vm_Regex_captures_11(): int:
  let recv_self = Regex(pattern = "test", bytecode = RegexBytecode(instructions = [], groupCount = 4, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 4)
  let edge_self = Regex(pattern = "a", bytecode = RegexBytecode(instructions = [], groupCount = 1, anchoredStart = false, anchoredEnd = false), flags = RegexFlags(ignoreCase = false, multiline = false, dotAll = false, ungreedy = false), groupCount = 1)
  let arg_text = "test"
  let edge_text = "a"
  let resNom = recv_self.captures(arg_text)
  let resEdge = edge_self.captures(edge_text)
  assertEqInt(resNom.len(), 0, "captures nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "captures boundary resEdge.len() == 0")
  ret 0
```

---

### `expandReplacement` (`std/regex/regex_vm.aipl`)

- **Signature**: `fn expandReplacement(replacement: str, m: RegexMatch): str:`
- **Import**: `import * from "std/regex/regex_vm"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `replacement: str, m: RegexMatch` | **Returns**: `str`
- **Unit Test**: `tests/functions/regex/regex_vm_test.aipl` | **Example**: `examples/ex_061_regex_vm_grep_and_replace_cli.aipl`
- **Behavioral Summary**: Verify linear-time PikeVM execution function `expandReplacement` (`free fn`) on non-backtracking pathological inputs (`a?a?a?aaa`), numbered group captures, `$1` replacement expansion, and bounded splitting. Concrete nominal inputs: `replacement: str = "aipl_test"`, `m: RegexMatch = RegexMatch(start = 1, end = 1, text = "aipl_test", groups = ["aipl_test"])`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.regex.regex_vm_z12_test
import * from "std/regex/regex_vm"
import { OP_MATCH, OP_CHAR, OP_ANY, OP_CHAR_CLASS, OP_SPLIT, OP_JUMP, OP_SAVE, OP_ANCHOR_START, OP_ANCHOR_END, RegexFlags, RegexCharClass, RegexInstruction, RegexBytecode, Regex } from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_vm_expandReplacement_12(): int:
  let arg_replacement = "test"
  let edge_replacement = "a"
  let arg_m = RegexMatch(start = 1, end = 4, text = "test", groups = [])
  let edge_m = RegexMatch(start = 0, end = 1, text = "a", groups = [])
  let resNom = expandReplacement(arg_replacement, arg_m)
  let resEdge = expandReplacement(edge_replacement, edge_m)
  assertEqStr(resNom, "test", "expandReplacement nominal string matches")
  assertEqStr(resEdge, "a", "expandReplacement boundary string matches")
  ret 0
```

---

### `replace` (`std/regex/regex_vm.aipl`)

- **Signature**: `pub fn (self: Regex) replace(text: str, replacement: str): str:`
- **Import**: `import * from "std/regex/regex_vm"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `self: Regex` | **Parameters**: `text: str, replacement: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/regex/regex_vm_test.aipl` | **Example**: `examples/ex_062_regex_text_diff_myers_patch_cli.aipl`
- **Behavioral Summary**: Verify linear-time PikeVM execution function `replace` (`self: Regex`) on non-backtracking pathological inputs (`a?a?a?aaa`), numbered group captures, `$1` replacement expansion, and bounded splitting. Concrete nominal inputs: receiver `recvObj: Regex = Regex(pattern = "aipl_test", bytecode = RegexBytecode(instructions = [0], groupCount = 64, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 64)`, `text: str = "aipl_test"`, `replacement: str = "aipl_test"`; exercises core body path returning/computing `text.slice(0, m.start) + expanded + text.slice(m.end, text.len)`.

```aipl
module tests.functions.regex.regex_vm_z13_test
import * from "std/regex/regex_vm"
import { OP_MATCH, OP_CHAR, OP_ANY, OP_CHAR_CLASS, OP_SPLIT, OP_JUMP, OP_SAVE, OP_ANCHOR_START, OP_ANCHOR_END, RegexFlags, RegexCharClass, RegexInstruction, RegexBytecode, Regex } from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_vm_Regex_replace_13(): int:
  let recv_self = Regex(pattern = "test", bytecode = RegexBytecode(instructions = [], groupCount = 4, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 4)
  let edge_self = Regex(pattern = "a", bytecode = RegexBytecode(instructions = [], groupCount = 1, anchoredStart = false, anchoredEnd = false), flags = RegexFlags(ignoreCase = false, multiline = false, dotAll = false, ungreedy = false), groupCount = 1)
  let arg_text = "test"
  let edge_text = "a"
  let arg_replacement = "test"
  let edge_replacement = "a"
  let resNom = recv_self.replace(arg_text, arg_replacement)
  let resEdge = edge_self.replace(edge_text, edge_replacement)
  assertEqStr(resNom, "test", "replace nominal string matches")
  assertEqStr(resEdge, "a", "replace boundary string matches")
  ret 0
```

---

### `replaceAll` (`std/regex/regex_vm.aipl`)

- **Signature**: `pub fn (self: Regex) replaceAll(text: str, replacement: str): str:`
- **Import**: `import * from "std/regex/regex_vm"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `self: Regex` | **Parameters**: `text: str, replacement: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/regex/regex_vm_test.aipl` | **Example**: `examples/ex_063_regex_fuzzy_search_and_glob_cli.aipl`
- **Behavioral Summary**: Verify linear-time PikeVM execution function `replaceAll` (`self: Regex`) on non-backtracking pathological inputs (`a?a?a?aaa`), numbered group captures, `$1` replacement expansion, and bounded splitting. Concrete nominal inputs: receiver `recvObj: Regex = Regex(pattern = "aipl_test", bytecode = RegexBytecode(instructions = [0], groupCount = 64, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 64)`, `text: str = "aipl_test"`, `replacement: str = "aipl_test"`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.regex.regex_vm_z14_test
import * from "std/regex/regex_vm"
import { OP_MATCH, OP_CHAR, OP_ANY, OP_CHAR_CLASS, OP_SPLIT, OP_JUMP, OP_SAVE, OP_ANCHOR_START, OP_ANCHOR_END, RegexFlags, RegexCharClass, RegexInstruction, RegexBytecode, Regex } from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_vm_Regex_replaceAll_14(): int:
  let recv_self = Regex(pattern = "test", bytecode = RegexBytecode(instructions = [], groupCount = 4, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 4)
  let edge_self = Regex(pattern = "a", bytecode = RegexBytecode(instructions = [], groupCount = 1, anchoredStart = false, anchoredEnd = false), flags = RegexFlags(ignoreCase = false, multiline = false, dotAll = false, ungreedy = false), groupCount = 1)
  let arg_text = "test"
  let edge_text = "a"
  let arg_replacement = "test"
  let edge_replacement = "a"
  let resNom = recv_self.replaceAll(arg_text, arg_replacement)
  let resEdge = edge_self.replaceAll(edge_text, edge_replacement)
  assertEqStr(resNom, "test", "replaceAll nominal string matches")
  assertEqStr(resEdge, "a", "replaceAll boundary string matches")
  ret 0
```

---

### `splitN` (`std/regex/regex_vm.aipl`)

- **Signature**: `pub fn (self: Regex) splitN(text: str, limit: int): [str]:`
- **Import**: `import * from "std/regex/regex_vm"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `self: Regex` | **Parameters**: `text: str, limit: int` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/regex/regex_vm_test.aipl` | **Example**: `examples/ex_061_regex_vm_grep_and_replace_cli.aipl`
- **Behavioral Summary**: Verify linear-time PikeVM execution function `splitN` (`self: Regex`) on non-backtracking pathological inputs (`a?a?a?aaa`), numbered group captures, `$1` replacement expansion, and bounded splitting. Concrete nominal inputs: receiver `recvObj: Regex = Regex(pattern = "aipl_test", bytecode = RegexBytecode(instructions = [0], groupCount = 64, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 64)`, `text: str = "aipl_test"`, `limit: int = 1`; exercises core body path returning/computing `parts`.

```aipl
module tests.functions.regex.regex_vm_z15_test
import * from "std/regex/regex_vm"
import { OP_MATCH, OP_CHAR, OP_ANY, OP_CHAR_CLASS, OP_SPLIT, OP_JUMP, OP_SAVE, OP_ANCHOR_START, OP_ANCHOR_END, RegexFlags, RegexCharClass, RegexInstruction, RegexBytecode, Regex } from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_vm_Regex_splitN_15(): int:
  let recv_self = Regex(pattern = "test", bytecode = RegexBytecode(instructions = [], groupCount = 4, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 4)
  let edge_self = Regex(pattern = "a", bytecode = RegexBytecode(instructions = [], groupCount = 1, anchoredStart = false, anchoredEnd = false), flags = RegexFlags(ignoreCase = false, multiline = false, dotAll = false, ungreedy = false), groupCount = 1)
  let arg_text = "test"
  let edge_text = "a"
  let arg_limit = 4
  let edge_limit = 1
  let resNom = recv_self.splitN(arg_text, arg_limit)
  let resEdge = edge_self.splitN(edge_text, edge_limit)
  assertEqInt(resNom.len(), 1, "splitN nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "splitN boundary resEdge.len() == 1")
  ret 0
```

---

### `split` (`std/regex/regex_vm.aipl`)

- **Signature**: `pub fn (self: Regex) split(text: str): [str]:`
- **Import**: `import * from "std/regex/regex_vm"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `self: Regex` | **Parameters**: `text: str` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/regex/regex_vm_test.aipl` | **Example**: `examples/ex_062_regex_text_diff_myers_patch_cli.aipl`
- **Behavioral Summary**: Verify linear-time PikeVM execution function `split` (`self: Regex`) on non-backtracking pathological inputs (`a?a?a?aaa`), numbered group captures, `$1` replacement expansion, and bounded splitting. Concrete nominal inputs: receiver `recvObj: Regex = Regex(pattern = "aipl_test", bytecode = RegexBytecode(instructions = [0], groupCount = 64, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 64)`, `text: str = "aipl_test"`; exercises core body path returning/computing `self.splitN(text, -1)`.

```aipl
module tests.functions.regex.regex_vm_z16_test
import * from "std/regex/regex_vm"
import { OP_MATCH, OP_CHAR, OP_ANY, OP_CHAR_CLASS, OP_SPLIT, OP_JUMP, OP_SAVE, OP_ANCHOR_START, OP_ANCHOR_END, RegexFlags, RegexCharClass, RegexInstruction, RegexBytecode, Regex } from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_vm_Regex_split_16(): int:
  let recv_self = Regex(pattern = "test", bytecode = RegexBytecode(instructions = [], groupCount = 4, anchoredStart = true, anchoredEnd = true), flags = RegexFlags(ignoreCase = true, multiline = true, dotAll = true, ungreedy = true), groupCount = 4)
  let edge_self = Regex(pattern = "a", bytecode = RegexBytecode(instructions = [], groupCount = 1, anchoredStart = false, anchoredEnd = false), flags = RegexFlags(ignoreCase = false, multiline = false, dotAll = false, ungreedy = false), groupCount = 1)
  let arg_text = "test"
  let edge_text = "a"
  let resNom = recv_self.split(arg_text)
  let resEdge = edge_self.split(edge_text)
  assertEqInt(resNom.len(), 1, "split nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "split boundary resEdge.len() == 1")
  ret 0
```

---

### `myersDiffLines` (`std/regex/text_diff.aipl`)

- **Signature**: `pub fn myersDiffLines(oldLines: [str], newLines: [str]): [DiffEdit]:`
- **Import**: `import * from "std/regex/text_diff"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `oldLines: [str], newLines: [str]` | **Returns**: `[DiffEdit]`
- **Unit Test**: `tests/functions/regex/text_diff_test.aipl` | **Example**: `examples/ex_063_regex_fuzzy_search_and_glob_cli.aipl`
- **Behavioral Summary**: Verify Myers O(ND) diff / unified patch / 3-way merge function `myersDiffLines` round-trip patch application (`applyUnifiedPatch(orig, formatUnifiedDiff(orig, target)) == target`) and conflict detection. Concrete nominal inputs: `oldLines: [str] = ["aipl_test"]`, `newLines: [str] = ["aipl_test"]`; exercises core body path returning/computing `edits`.

```aipl
module tests.functions.regex.text_diff_z1_test
import * from "std/regex/text_diff"
import { splitLines, parseInt } from "std/fmt/fmt_mod"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_text_diff_myersDiffLines_1(): int:
  let arg_oldLines = ["test"]
  let edge_oldLines = []
  let arg_newLines = ["test"]
  let edge_newLines = []
  let resNom = myersDiffLines(arg_oldLines, arg_newLines)
  let resEdge = myersDiffLines(edge_oldLines, edge_newLines)
  assertEqInt(resNom.len(), 1, "myersDiffLines nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "myersDiffLines boundary resEdge.len() == 0")
  ret 0
```

---

### `buildUnifiedHunks` (`std/regex/text_diff.aipl`)

- **Signature**: `pub fn buildUnifiedHunks(edits: [DiffEdit], contextRadius: int = 3): [DiffHunk]:`
- **Import**: `import * from "std/regex/text_diff"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `edits: [DiffEdit], contextRadius: int = 3` | **Returns**: `[DiffHunk]`
- **Unit Test**: `tests/functions/regex/text_diff_test.aipl` | **Example**: `examples/ex_061_regex_vm_grep_and_replace_cli.aipl`
- **Behavioral Summary**: Verify Myers O(ND) diff / unified patch / 3-way merge function `buildUnifiedHunks` round-trip patch application (`applyUnifiedPatch(orig, formatUnifiedDiff(orig, target)) == target`) and conflict detection. Concrete nominal inputs: `edits: [DiffEdit] = [DiffEdit(op = "aipl_test", text = "aipl_test", oldLineNo = 1, newLineNo = 1)]`, `contextRadius: int = 1`; exercises core body path returning/computing `hunks`.

```aipl
module tests.functions.regex.text_diff_z2_test
import * from "std/regex/text_diff"
import { splitLines, parseInt } from "std/fmt/fmt_mod"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_text_diff_buildUnifiedHunks_2(): int:
  let arg_edits = [DiffEdit(op = "test", text = "test", oldLineNo = 4, newLineNo = 4)]
  let edge_edits = []
  let arg_contextRadius = 4
  let edge_contextRadius = 1
  let resNom = buildUnifiedHunks(arg_edits, arg_contextRadius)
  let resEdge = buildUnifiedHunks(edge_edits, edge_contextRadius)
  assertEqInt(resNom.len(), 1, "buildUnifiedHunks nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "buildUnifiedHunks boundary resEdge.len() == 0")
  ret 0
```

---

### `formatUnifiedDiff` (`std/regex/text_diff.aipl`)

- **Signature**: `pub fn formatUnifiedDiff(oldFile: str, newFile: str, oldText: str, newText: str, context: int = 3): str:`
- **Import**: `import * from "std/regex/text_diff"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `oldFile: str, newFile: str, oldText: str, newText: str, context: int = 3` | **Returns**: `str`
- **Unit Test**: `tests/functions/regex/text_diff_test.aipl` | **Example**: `examples/ex_062_regex_text_diff_myers_patch_cli.aipl`
- **Behavioral Summary**: Verify Myers O(ND) diff / unified patch / 3-way merge function `formatUnifiedDiff` round-trip patch application (`applyUnifiedPatch(orig, formatUnifiedDiff(orig, target)) == target`) and conflict detection. Concrete nominal inputs: `oldFile: str = "/tmp/aipl_test_artifact.tmp"`, `newFile: str = "/tmp/aipl_test_artifact.tmp"`, `oldText: str = "aipl_test"`, `newText: str = "aipl_test"`, `context: int = 1`; exercises core body path returning/computing `out.join("\n") + "\n"`.

```aipl
module tests.functions.regex.text_diff_z3_test
import * from "std/regex/text_diff"
import { splitLines, parseInt } from "std/fmt/fmt_mod"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_text_diff_formatUnifiedDiff_3(): int:
  let arg_oldFile = "/tmp/aipl_test_path"
  let edge_oldFile = "/tmp/aipl_test_path"
  let arg_newFile = "/tmp/aipl_test_path"
  let edge_newFile = "/tmp/aipl_test_path"
  let arg_oldText = "test"
  let edge_oldText = "a"
  let arg_newText = "test"
  let edge_newText = "a"
  let arg_context = 4
  let edge_context = 1
  let resNom = formatUnifiedDiff(arg_oldFile, arg_newFile, arg_oldText, arg_newText, arg_context)
  let resEdge = formatUnifiedDiff(edge_oldFile, edge_newFile, edge_oldText, edge_newText, edge_context)
  assertEqInt(resNom.len(), 48, "formatUnifiedDiff nominal string length == 48")
  assertEqInt(resEdge.len(), 48, "formatUnifiedDiff boundary string length == 48")
  ret 0
```

---

### `parseRangeSpec` (`std/regex/text_diff.aipl`)

- **Signature**: `fn parseRangeSpec(spec: str): (int, int):`
- **Import**: `import * from "std/regex/text_diff"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `spec: str` | **Returns**: `(int, int)`
- **Unit Test**: `tests/functions/regex/text_diff_test.aipl` | **Example**: `examples/ex_063_regex_fuzzy_search_and_glob_cli.aipl`
- **Behavioral Summary**: Verify Myers O(ND) diff / unified patch / 3-way merge function `parseRangeSpec` round-trip patch application (`applyUnifiedPatch(orig, formatUnifiedDiff(orig, target)) == target`) and conflict detection. Concrete nominal inputs: `spec: str): (int = str): (int()`, `int: any = 42`; exercises core body path returning/computing `(st, ct)`.

```aipl
module tests.functions.regex.text_diff_z4_test
import * from "std/regex/text_diff"
import { splitLines, parseInt } from "std/fmt/fmt_mod"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_text_diff_parseRangeSpec_4(): int:
  let arg_spec = "test"
  let edge_spec = "a"
  let resNom = parseRangeSpec(arg_spec)
  let resEdge = parseRangeSpec(edge_spec)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0, 1, "parseRangeSpec nominal n_t0 == 1")
  assertEqInt(e_t0, 1, "parseRangeSpec boundary e_t0 == 1")
  ret 0
```

---

### `parseUnifiedPatch` (`std/regex/text_diff.aipl`)

- **Signature**: `pub fn parseUnifiedPatch(patchText: str): Result[UnifiedPatch, str]:`
- **Import**: `import * from "std/regex/text_diff"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `patchText: str` | **Returns**: `Result[UnifiedPatch, str]`
- **Unit Test**: `tests/functions/regex/text_diff_test.aipl` | **Example**: `examples/ex_061_regex_vm_grep_and_replace_cli.aipl`
- **Behavioral Summary**: Verify Myers O(ND) diff / unified patch / 3-way merge function `parseUnifiedPatch` round-trip patch application (`applyUnifiedPatch(orig, formatUnifiedDiff(orig, target)) == target`) and conflict detection. Concrete nominal inputs: `patchText: str = "aipl_test"`; exercises core body path returning/computing `Ok(UnifiedPatch(`.

```aipl
module tests.functions.regex.text_diff_z5_test
import * from "std/regex/text_diff"
import { splitLines, parseInt } from "std/fmt/fmt_mod"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_text_diff_parseUnifiedPatch_5(): int:
  let arg_patchText = "test"
  let edge_patchText = "a"
  let resNom = parseUnifiedPatch(arg_patchText)
  let resEdge = parseUnifiedPatch(edge_patchText)
  assert(resNom.isOk() == false, "parseUnifiedPatch nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "parseUnifiedPatch boundary resEdge.isOk() == false")
  ret 0
```

---

### `applyUnifiedPatch` (`std/regex/text_diff.aipl`)

- **Signature**: `pub fn applyUnifiedPatch(originalText: str, patch: UnifiedPatch): Result[str, str]:`
- **Import**: `import * from "std/regex/text_diff"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `originalText: str, patch: UnifiedPatch` | **Returns**: `Result[str, str]`
- **Unit Test**: `tests/functions/regex/text_diff_test.aipl` | **Example**: `examples/ex_062_regex_text_diff_myers_patch_cli.aipl`
- **Behavioral Summary**: Verify Myers O(ND) diff / unified patch / 3-way merge function `applyUnifiedPatch` round-trip patch application (`applyUnifiedPatch(orig, formatUnifiedDiff(orig, target)) == target`) and conflict detection. Concrete nominal inputs: `originalText: str = "aipl_test"`, `patch: UnifiedPatch = UnifiedPatch(headerOld = "aipl_test", headerNew = "aipl_test", hunks = [DiffHunk(oldStart = 0, oldCount = 0, newStart = 0, newCount = 0, lines = 0)], addedCount = 64, deletedCount = 64)`; exercises core body path returning/computing `Ok(joined)`.

```aipl
module tests.functions.regex.text_diff_z6_test
import * from "std/regex/text_diff"
import { splitLines, parseInt } from "std/fmt/fmt_mod"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_text_diff_applyUnifiedPatch_6(): int:
  let arg_originalText = "test"
  let edge_originalText = "a"
  let arg_patch = UnifiedPatch(headerOld = "test", headerNew = "test", hunks = [], addedCount = 4, deletedCount = 4)
  let edge_patch = UnifiedPatch(headerOld = "a", headerNew = "a", hunks = [], addedCount = 1, deletedCount = 1)
  let resNom = applyUnifiedPatch(arg_originalText, arg_patch)
  let resEdge = applyUnifiedPatch(edge_originalText, edge_patch)
  assert(resNom.isOk() == true, "applyUnifiedPatch nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "applyUnifiedPatch boundary resEdge.isOk() == true")
  ret 0
```

---

### `threeWayMerge` (`std/regex/text_diff.aipl`)

- **Signature**: `pub fn threeWayMerge(baseText: str, ourText: str, theirText: str): Result[str, str]:`
- **Import**: `import * from "std/regex/text_diff"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `baseText: str, ourText: str, theirText: str` | **Returns**: `Result[str, str]`
- **Unit Test**: `tests/functions/regex/text_diff_test.aipl` | **Example**: `examples/ex_063_regex_fuzzy_search_and_glob_cli.aipl`
- **Behavioral Summary**: Verify Myers O(ND) diff / unified patch / 3-way merge function `threeWayMerge` round-trip patch application (`applyUnifiedPatch(orig, formatUnifiedDiff(orig, target)) == target`) and conflict detection. Concrete nominal inputs: `baseText: str = "aipl_test"`, `ourText: str = "aipl_test"`, `theirText: str = "aipl_test"`; exercises core body path returning/computing `Ok(out)`.

```aipl
module tests.functions.regex.text_diff_z7_test
import * from "std/regex/text_diff"
import { splitLines, parseInt } from "std/fmt/fmt_mod"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_text_diff_threeWayMerge_7(): int:
  let arg_baseText = "test"
  let edge_baseText = "a"
  let arg_ourText = "test"
  let edge_ourText = "a"
  let arg_theirText = "test"
  let edge_theirText = "a"
  let resNom = threeWayMerge(arg_baseText, arg_ourText, arg_theirText)
  let resEdge = threeWayMerge(edge_baseText, edge_ourText, edge_theirText)
  assert(resNom.isOk() == true, "threeWayMerge nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "threeWayMerge boundary resEdge.isOk() == true")
  ret 0
```

---

### `editDistance` (`std/regex/text_diff.aipl`)

- **Signature**: `pub fn editDistance(a: str, b: str): int:`
- **Import**: `import * from "std/regex/text_diff"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: str, b: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/regex/text_diff_test.aipl` | **Example**: `examples/ex_061_regex_vm_grep_and_replace_cli.aipl`
- **Behavioral Summary**: Verify Myers O(ND) diff / unified patch / 3-way merge function `editDistance` round-trip patch application (`applyUnifiedPatch(orig, formatUnifiedDiff(orig, target)) == target`) and conflict detection. Concrete nominal inputs: `a: str = "aipl_test"`, `b: str = "aipl_test"`; exercises core body path returning/computing `prev[n]`.

```aipl
module tests.functions.regex.text_diff_z8_test
import * from "std/regex/text_diff"
import { splitLines, parseInt } from "std/fmt/fmt_mod"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_text_diff_editDistance_8(): int:
  let arg_a = "test"
  let edge_a = "a"
  let arg_b = "test"
  let edge_b = "a"
  let resNom = editDistance(arg_a, arg_b)
  let resEdge = editDistance(edge_a, edge_b)
  assertEqInt(resNom, 0, "editDistance nominal resNom == 0")
  assertEqInt(resEdge, 0, "editDistance boundary resEdge == 0")
  ret 0
```

---

### `similarityRatio` (`std/regex/text_diff.aipl`)

- **Signature**: `pub fn similarityRatio(a: str, b: str): float:`
- **Import**: `import * from "std/regex/text_diff"` (or barrel `import * from "std/regex/regex_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: str, b: str` | **Returns**: `float`
- **Unit Test**: `tests/functions/regex/text_diff_test.aipl` | **Example**: `examples/ex_062_regex_text_diff_myers_patch_cli.aipl`
- **Behavioral Summary**: Verify Myers O(ND) diff / unified patch / 3-way merge function `similarityRatio` round-trip patch application (`applyUnifiedPatch(orig, formatUnifiedDiff(orig, target)) == target`) and conflict detection. Concrete nominal inputs: `a: str = "aipl_test"`, `b: str = "aipl_test"`; exercises core body path returning/computing `1.0 - (float(dist) / float(maxLen))`.

```aipl
module tests.functions.regex.text_diff_z9_test
import * from "std/regex/text_diff"
import { splitLines, parseInt } from "std/fmt/fmt_mod"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_text_diff_similarityRatio_9(): int:
  let arg_a = "test"
  let edge_a = "a"
  let arg_b = "test"
  let edge_b = "a"
  let resNom = similarityRatio(arg_a, arg_b)
  let resEdge = similarityRatio(edge_a, edge_b)
  assertApproxEq(resNom, 1.0, 0.001, "similarityRatio nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.0, 0.001, "similarityRatio boundary resEdge ~= 1.0")
  ret 0
```
