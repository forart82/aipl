[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 20: `test` API Reference

> Complete API reference manual for AIPL standard library domain `test` (32 callable functions & methods across ["std/test/assert.aipl", "std/test/bench.aipl", "std/test/fuzz.aipl", "std/test/test_mod.aipl", "std/test/test_runner.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `test`
- **Target Source Modules**: ["std/test/assert.aipl", "std/test/bench.aipl", "std/test/fuzz.aipl", "std/test/test_mod.aipl", "std/test/test_runner.aipl"]
- **Total Callable Functions & Methods**: 32
- **Total Data Types (`struct` & `enum`)**: 13
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(13 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `AssertionError` | `pub struct` | `std/test/assert.aipl` | `message: str`, `file: str`, `line: int`, `actual: str`, `expected: str` | `AssertionError(message, file, line, actual, expected)` |
| `DiffLine` | `pub struct` | `std/test/assert.aipl` | `kind: int`, `text: str` | `DiffLine(kind, text)` |
| `BenchmarkTimer` | `pub struct` | `std/test/bench.aipl` | `startNs: int`, `elapsedNs: int`, `iterCount: int`, `allocCount: int` | `BenchmarkTimer(startNs, elapsedNs, iterCount, allocCount)` |
| `BenchmarkConfig` | `pub struct` | `std/test/bench.aipl` | `warmupIters: int`, `measureIters: int`, `maxDurationMs: int`, `rejectOutliers: bool` | `BenchmarkConfig(warmupIters, measureIters, maxDurationMs, rejectOutliers)` |
| `BenchmarkStats` | `pub struct` | `std/test/bench.aipl` | `meanNs: float`, `medianNs: float`, `stdDevNs: float`, `minNs: int`, `maxNs: int`, `iqrNs: float`, `allocsPerOp: float` | `BenchmarkStats(meanNs, medianNs, stdDevNs, minNs, maxNs, iqrNs, allocsPerOp)` |
| `BenchmarkResult` | `pub struct` | `std/test/bench.aipl` | `name: str`, `runs: [int]`, `stats: BenchmarkStats` | `BenchmarkResult(name, runs, stats)` |
| `FuzzConfig` | `pub struct` | `std/test/fuzz.aipl` | `seed: int`, `maxIterations: int`, `maxShrinkSteps: int`, `maxCollectionLen: int` | `FuzzConfig(seed, maxIterations, maxShrinkSteps, maxCollectionLen)` |
| `FuzzGenerator` | `pub struct` | `std/test/fuzz.aipl` | `seed: int`, `state: int` | `FuzzGenerator(seed, state)` |
| `FuzzResult` | `pub struct` | `std/test/fuzz.aipl` | `iterationsRun: int`, `counterExampleFound: bool`, `originalCounterExample: str`, `shrunkCounterExample: str` | `FuzzResult(iterationsRun, counterExampleFound, originalCounterExample, shrunkCounterExample)` |
| `TestCase` | `pub struct` | `std/test/test_runner.aipl` | `name: str`, `moduleName: str`, `expectedStatus: int`, `isIgnored: bool`, `timeoutMs: int` | `TestCase(name, moduleName, expectedStatus, isIgnored, timeoutMs)` |
| `TestExecutionResult` | `pub struct` | `std/test/test_runner.aipl` | `testCase: TestCase`, `status: int`, `durationMs: float`, `failureMessage: str` | `TestExecutionResult(testCase, status, durationMs, failureMessage)` |
| `TestSuite` | `pub struct` | `std/test/test_runner.aipl` | `name: str`, `mut cases: [TestCase]`, `mut results: [TestExecutionResult]` | `TestSuite(name, mut cases, mut results)` |
| `TestFilter` | `pub struct` | `std/test/test_runner.aipl` | `pattern: str`, `includeIgnored: bool` | `TestFilter(pattern, includeIgnored)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/test/assert.aipl` | `testAssert` | `pub fn testAssert(cond: bool, msg: str = "Assertion failed"): bool:` | `tests/functions/test/assert_test.aipl` |
| `2` | `std/test/assert.aipl` | `assertEq` | `pub fn assertEq(actual: int, expected: int, label: str = ""): bool:` | `tests/functions/test/assert_test.aipl` |
| `3` | `std/test/assert.aipl` | `assertNe` | `pub fn assertNe(actual: int, expected: int, label: str = ""): bool:` | `tests/functions/test/assert_test.aipl` |
| `4` | `std/test/assert.aipl` | `testAssertApproxEq` | `pub fn testAssertApproxEq(actual: float, expected: float, eps: float = 0.000001, label: str = ""): bool:` | `tests/functions/test/assert_test.aipl` |
| `5` | `std/test/assert.aipl` | `assertContains` | `pub fn assertContains(haystack: str, needle: str, label: str = ""): bool:` | `tests/functions/test/assert_test.aipl` |
| `6` | `std/test/assert.aipl` | `assertStartsWith` | `pub fn assertStartsWith(s: str, prefix: str, label: str = ""): bool:` | `tests/functions/test/assert_test.aipl` |
| `7` | `std/test/assert.aipl` | `assertEndsWith` | `pub fn assertEndsWith(s: str, suffix: str, label: str = ""): bool:` | `tests/functions/test/assert_test.aipl` |
| `8` | `std/test/assert.aipl` | `assertPanics` | `pub fn assertPanics(simulatedErrorMsg: str, expectedErrorSubstring: str = ""): bool:` | `tests/functions/test/assert_test.aipl` |
| `9` | `std/test/assert.aipl` | `formatDiffLines` | `pub fn formatDiffLines(actual: str, expected: str): [DiffLine]:` | `tests/functions/test/assert_test.aipl` |
| `10` | `std/test/assert.aipl` | `renderDiffText` | `pub fn renderDiffText(diffs: [DiffLine]): str:` | `tests/functions/test/assert_test.aipl` |
| `11` | `std/test/bench.aipl` | `createBenchmarkTimer` | `pub fn createBenchmarkTimer(): BenchmarkTimer:` | `tests/functions/test/bench_test.aipl` |
| `12` | `std/test/bench.aipl` | `startBenchmarkTimer` | `pub fn startBenchmarkTimer(mut timer: BenchmarkTimer): BenchmarkTimer:` | `tests/functions/test/bench_test.aipl` |
| `13` | `std/test/bench.aipl` | `stopBenchmarkTimer` | `pub fn stopBenchmarkTimer(mut timer: BenchmarkTimer): BenchmarkTimer:` | `tests/functions/test/bench_test.aipl` |
| `14` | `std/test/bench.aipl` | `sortSamples` | `fn sortSamples(samples: [int]): [int]:` | `tests/functions/test/bench_test.aipl` |
| `15` | `std/test/bench.aipl` | `rejectOutliersIqr` | `pub fn rejectOutliersIqr(samples: [int]): [int]:` | `tests/functions/test/bench_test.aipl` |
| `16` | `std/test/bench.aipl` | `calculateStats` | `pub fn calculateStats(samples: [int], allocs: int): BenchmarkStats:` | `tests/functions/test/bench_test.aipl` |
| `17` | `std/test/bench.aipl` | `formatBenchmarkReport` | `pub fn formatBenchmarkReport(result: BenchmarkResult): str:` | `tests/functions/test/bench_test.aipl` |
| `18` | `std/test/fuzz.aipl` | `createFuzzGenerator` | `pub fn createFuzzGenerator(seed: int): FuzzGenerator:` | `tests/functions/test/fuzz_test.aipl` |
| `19` | `std/test/fuzz.aipl` | `nextRaw64` | `fn nextRaw64(gen: FuzzGenerator): (FuzzGenerator, int):` | `tests/functions/test/fuzz_test.aipl` |
| `20` | `std/test/fuzz.aipl` | `fuzzNextInt` | `pub fn fuzzNextInt(gen: FuzzGenerator, minVal: int, maxVal: int): (FuzzGenerator, int):` | `tests/functions/test/fuzz_test.aipl` |
| `21` | `std/test/fuzz.aipl` | `fuzzNextFloat` | `pub fn fuzzNextFloat(gen: FuzzGenerator, minVal: float, maxVal: float): (FuzzGenerator, float):` | `tests/functions/test/fuzz_test.aipl` |
| `22` | `std/test/fuzz.aipl` | `fuzzNextString` | `pub fn fuzzNextString(gen: FuzzGenerator, maxLen: int): (FuzzGenerator, str):` | `tests/functions/test/fuzz_test.aipl` |
| `23` | `std/test/fuzz.aipl` | `fuzzNextBytes` | `pub fn fuzzNextBytes(gen: FuzzGenerator, maxLen: int): (FuzzGenerator, [int]):` | `tests/functions/test/fuzz_test.aipl` |
| `24` | `std/test/fuzz.aipl` | `shrinkCounterExampleInt` | `pub fn shrinkCounterExampleInt(failingVal: int, targetVal: int, minFailThreshold: int): int:` | `tests/functions/test/fuzz_test.aipl` |
| `25` | `std/test/fuzz.aipl` | `shrinkCounterExampleString` | `pub fn shrinkCounterExampleString(failingStr: str, requiredToken: str): str:` | `tests/functions/test/fuzz_test.aipl` |
| `26` | `std/test/fuzz.aipl` | `verifyProperty` | `pub fn verifyProperty(config: FuzzConfig, failThreshold: int): FuzzResult:` | `tests/functions/test/fuzz_test.aipl` |
| `27` | `std/test/test_runner.aipl` | `createTestSuite` | `pub fn createTestSuite(name: str): TestSuite:` | `tests/functions/test/test_runner_test.aipl` |
| `28` | `std/test/test_runner.aipl` | `registerTestCase` | `pub fn registerTestCase(mut suite: TestSuite, name: str, moduleName: str, expectedStatus: int): TestSuite:` | `tests/functions/test/test_runner_test.aipl` |
| `29` | `std/test/test_runner.aipl` | `filterTestCases` | `pub fn filterTestCases(suite: TestSuite, filter: TestFilter): [TestCase]:` | `tests/functions/test/test_runner_test.aipl` |
| `30` | `std/test/test_runner.aipl` | `runTestSuite` | `pub fn runTestSuite(mut suite: TestSuite, filter: TestFilter): TestSuite:` | `tests/functions/test/test_runner_test.aipl` |
| `31` | `std/test/test_runner.aipl` | `formatTapReport` | `pub fn formatTapReport(suite: TestSuite): str:` | `tests/functions/test/test_runner_test.aipl` |
| `32` | `std/test/test_runner.aipl` | `formatJunitXmlReport` | `pub fn formatJunitXmlReport(suite: TestSuite): str:` | `tests/functions/test/test_runner_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `testAssert` (`std/test/assert.aipl`)

- **Signature**: `pub fn testAssert(cond: bool, msg: str = "Assertion failed"): bool:`
- **Import**: `import * from "std/test/assert"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cond: bool, msg: str = "Assertion failed"` | **Returns**: `bool`
- **Unit Test**: `tests/functions/test/assert_test.aipl` | **Example**: `examples/ex_127_test_assert_matcher_suite_cli.aipl`
- **Behavioral Summary**: Verify `testAssert` test assertion pass/fail evaluation, float epsilon tolerance, panic interception (`assertPanics`), and unified line diff rendering. Concrete nominal inputs: `cond: bool = true`, `msg: str = "aipl_test"`; exercises core body path returning/computing `cond`.

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

---

### `assertEq` (`std/test/assert.aipl`)

- **Signature**: `pub fn assertEq(actual: int, expected: int, label: str = ""): bool:`
- **Import**: `import * from "std/test/assert"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `actual: int, expected: int, label: str = ""` | **Returns**: `bool`
- **Unit Test**: `tests/functions/test/assert_test.aipl` | **Example**: `examples/ex_128_test_runner_tap_junit_report_cli.aipl`
- **Behavioral Summary**: Verify `assertEq` test assertion pass/fail evaluation, float epsilon tolerance, panic interception (`assertPanics`), and unified line diff rendering. Concrete nominal inputs: `actual: int = 1`, `expected: int = 1`, `label: str = "aipl_test"`; exercises core body path returning/computing `actual == expected`.

```aipl
module tests.functions.test.assert_z2_test
import * from "std/test/assert"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_assert_assertEq_2(): int:
  let arg_actual = 1
  let edge_actual = 1
  let arg_expected = 1
  let edge_expected = 1
  let arg_label = "test"
  let edge_label = "test"
  let resNom = assertEq(arg_actual, arg_expected, arg_label)
  let resEdge = assertEq(edge_actual, edge_expected, edge_label)
  assert(resNom == true, "assertEq nominal resNom == true")
  assert(resEdge == true, "assertEq boundary resEdge == true")
  ret 0
```

---

### `assertNe` (`std/test/assert.aipl`)

- **Signature**: `pub fn assertNe(actual: int, expected: int, label: str = ""): bool:`
- **Import**: `import * from "std/test/assert"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `actual: int, expected: int, label: str = ""` | **Returns**: `bool`
- **Unit Test**: `tests/functions/test/assert_test.aipl` | **Example**: `examples/ex_129_test_bench_microbenchmark_cli.aipl`
- **Behavioral Summary**: Verify `assertNe` test assertion pass/fail evaluation, float epsilon tolerance, panic interception (`assertPanics`), and unified line diff rendering. Concrete nominal inputs: `actual: int = 1`, `expected: int = 1`, `label: str = "aipl_test"`; exercises core body path returning/computing `actual != expected`.

```aipl
module tests.functions.test.assert_z3_test
import * from "std/test/assert"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_assert_assertNe_3(): int:
  let arg_actual = 1
  let edge_actual = 1
  let arg_expected = 2
  let edge_expected = 2
  let arg_label = "test"
  let edge_label = "test"
  let resNom = assertNe(arg_actual, arg_expected, arg_label)
  let resEdge = assertNe(edge_actual, edge_expected, edge_label)
  assert(resNom == true, "assertNe nominal resNom == true")
  assert(resEdge == true, "assertNe boundary resEdge == true")
  ret 0
```

---

### `testAssertApproxEq` (`std/test/assert.aipl`)

- **Signature**: `pub fn testAssertApproxEq(actual: float, expected: float, eps: float = 0.000001, label: str = ""): bool:`
- **Import**: `import * from "std/test/assert"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `actual: float, expected: float, eps: float = 0.000001, label: str = ""` | **Returns**: `bool`
- **Unit Test**: `tests/functions/test/assert_test.aipl` | **Example**: `examples/ex_127_test_assert_matcher_suite_cli.aipl`
- **Behavioral Summary**: Verify `testAssertApproxEq` test assertion pass/fail evaluation, float epsilon tolerance, panic interception (`assertPanics`), and unified line diff rendering. Concrete nominal inputs: `actual: float = 1.0`, `expected: float = 1.0`, `eps: float = 0.0001`, `label: str = "aipl_test"`; exercises core body path returning/computing `ok`.

```aipl
module tests.functions.test.assert_z4_test
import * from "std/test/assert"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_assert_testAssertApproxEq_4(): int:
  let arg_actual = 1.0
  let edge_actual = 1.0
  let arg_expected = 1.0
  let edge_expected = 1.0
  let arg_eps = 0.001
  let edge_eps = 0.001
  let arg_label = "test"
  let edge_label = "test"
  let resNom = testAssertApproxEq(arg_actual, arg_expected, arg_eps, arg_label)
  let resEdge = testAssertApproxEq(edge_actual, edge_expected, edge_eps, edge_label)
  assert(resNom == true, "testAssertApproxEq nominal resNom == true")
  assert(resEdge == true, "testAssertApproxEq boundary resEdge == true")
  ret 0
```

---

### `assertContains` (`std/test/assert.aipl`)

- **Signature**: `pub fn assertContains(haystack: str, needle: str, label: str = ""): bool:`
- **Import**: `import * from "std/test/assert"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `haystack: str, needle: str, label: str = ""` | **Returns**: `bool`
- **Unit Test**: `tests/functions/test/assert_test.aipl` | **Example**: `examples/ex_128_test_runner_tap_junit_report_cli.aipl`
- **Behavioral Summary**: Verify `assertContains` test assertion pass/fail evaluation, float epsilon tolerance, panic interception (`assertPanics`), and unified line diff rendering. Concrete nominal inputs: `haystack: str = "aipl_test"`, `needle: str = "aipl_test"`, `label: str = "aipl_test"`; exercises core body path returning/computing `ok`.

```aipl
module tests.functions.test.assert_z5_test
import * from "std/test/assert"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_assert_assertContains_5(): int:
  let arg_haystack = "test"
  let edge_haystack = "test"
  let arg_needle = "test"
  let edge_needle = "test"
  let arg_label = "test"
  let edge_label = "test"
  let resNom = assertContains(arg_haystack, arg_needle, arg_label)
  let resEdge = assertContains(edge_haystack, edge_needle, edge_label)
  assert(resNom == true, "assertContains nominal resNom == true")
  assert(resEdge == true, "assertContains boundary resEdge == true")
  ret 0
```

---

### `assertStartsWith` (`std/test/assert.aipl`)

- **Signature**: `pub fn assertStartsWith(s: str, prefix: str, label: str = ""): bool:`
- **Import**: `import * from "std/test/assert"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, prefix: str, label: str = ""` | **Returns**: `bool`
- **Unit Test**: `tests/functions/test/assert_test.aipl` | **Example**: `examples/ex_129_test_bench_microbenchmark_cli.aipl`
- **Behavioral Summary**: Verify `assertStartsWith` test assertion pass/fail evaluation, float epsilon tolerance, panic interception (`assertPanics`), and unified line diff rendering. Concrete nominal inputs: `s: str = "aipl_test"`, `prefix: str = "aipl_test"`, `label: str = "aipl_test"`; exercises core body path returning/computing `ok`.

```aipl
module tests.functions.test.assert_z6_test
import * from "std/test/assert"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_assert_assertStartsWith_6(): int:
  let arg_s = "test"
  let edge_s = "test"
  let arg_prefix = "test"
  let edge_prefix = "test"
  let arg_label = "test"
  let edge_label = "test"
  let resNom = assertStartsWith(arg_s, arg_prefix, arg_label)
  let resEdge = assertStartsWith(edge_s, edge_prefix, edge_label)
  assert(resNom == true, "assertStartsWith nominal resNom == true")
  assert(resEdge == true, "assertStartsWith boundary resEdge == true")
  ret 0
```

---

### `assertEndsWith` (`std/test/assert.aipl`)

- **Signature**: `pub fn assertEndsWith(s: str, suffix: str, label: str = ""): bool:`
- **Import**: `import * from "std/test/assert"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, suffix: str, label: str = ""` | **Returns**: `bool`
- **Unit Test**: `tests/functions/test/assert_test.aipl` | **Example**: `examples/ex_127_test_assert_matcher_suite_cli.aipl`
- **Behavioral Summary**: Verify `assertEndsWith` test assertion pass/fail evaluation, float epsilon tolerance, panic interception (`assertPanics`), and unified line diff rendering. Concrete nominal inputs: `s: str = "aipl_test"`, `suffix: str = "aipl_test"`, `label: str = "aipl_test"`; exercises core body path returning/computing `ok`.

```aipl
module tests.functions.test.assert_z7_test
import * from "std/test/assert"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_assert_assertEndsWith_7(): int:
  let arg_s = "test"
  let edge_s = "test"
  let arg_suffix = "test"
  let edge_suffix = "test"
  let arg_label = "test"
  let edge_label = "test"
  let resNom = assertEndsWith(arg_s, arg_suffix, arg_label)
  let resEdge = assertEndsWith(edge_s, edge_suffix, edge_label)
  assert(resNom == true, "assertEndsWith nominal resNom == true")
  assert(resEdge == true, "assertEndsWith boundary resEdge == true")
  ret 0
```

---

### `assertPanics` (`std/test/assert.aipl`)

- **Signature**: `pub fn assertPanics(simulatedErrorMsg: str, expectedErrorSubstring: str = ""): bool:`
- **Import**: `import * from "std/test/assert"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `simulatedErrorMsg: str, expectedErrorSubstring: str = ""` | **Returns**: `bool`
- **Unit Test**: `tests/functions/test/assert_test.aipl` | **Example**: `examples/ex_128_test_runner_tap_junit_report_cli.aipl`
- **Behavioral Summary**: Verify `assertPanics` test assertion pass/fail evaluation, float epsilon tolerance, panic interception (`assertPanics`), and unified line diff rendering. Concrete nominal inputs: `simulatedErrorMsg: str = "aipl_test"`, `expectedErrorSubstring: str = "aipl_test"`; exercises core body path returning/computing `simulatedErrorMsg.contains(expectedErrorSubstring)`.

```aipl
module tests.functions.test.assert_z8_test
import * from "std/test/assert"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_assert_assertPanics_8(): int:
  let arg_simulatedErrorMsg = "test"
  let edge_simulatedErrorMsg = "test"
  let arg_expectedErrorSubstring = "test"
  let edge_expectedErrorSubstring = "test"
  let resNom = assertPanics(arg_simulatedErrorMsg, arg_expectedErrorSubstring)
  let resEdge = assertPanics(edge_simulatedErrorMsg, edge_expectedErrorSubstring)
  assert(resNom == true, "assertPanics nominal resNom == true")
  assert(resEdge == true, "assertPanics boundary resEdge == true")
  ret 0
```

---

### `formatDiffLines` (`std/test/assert.aipl`)

- **Signature**: `pub fn formatDiffLines(actual: str, expected: str): [DiffLine]:`
- **Import**: `import * from "std/test/assert"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `actual: str, expected: str` | **Returns**: `[DiffLine]`
- **Unit Test**: `tests/functions/test/assert_test.aipl` | **Example**: `examples/ex_129_test_bench_microbenchmark_cli.aipl`
- **Behavioral Summary**: Verify `formatDiffLines` test assertion pass/fail evaluation, float epsilon tolerance, panic interception (`assertPanics`), and unified line diff rendering. Concrete nominal inputs: `actual: str = "aipl_test"`, `expected: str = "aipl_test"`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.test.assert_z9_test
import * from "std/test/assert"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_assert_formatDiffLines_9(): int:
  let arg_actual = "test"
  let edge_actual = "test"
  let arg_expected = "test"
  let edge_expected = "test"
  let resNom = formatDiffLines(arg_actual, arg_expected)
  let resEdge = formatDiffLines(edge_actual, edge_expected)
  assertEqInt(resNom.len(), 1, "formatDiffLines nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "formatDiffLines boundary resEdge.len() == 1")
  ret 0
```

---

### `renderDiffText` (`std/test/assert.aipl`)

- **Signature**: `pub fn renderDiffText(diffs: [DiffLine]): str:`
- **Import**: `import * from "std/test/assert"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `diffs: [DiffLine]` | **Returns**: `str`
- **Unit Test**: `tests/functions/test/assert_test.aipl` | **Example**: `examples/ex_127_test_assert_matcher_suite_cli.aipl`
- **Behavioral Summary**: Verify `renderDiffText` test assertion pass/fail evaluation, float epsilon tolerance, panic interception (`assertPanics`), and unified line diff rendering. Concrete nominal inputs: `diffs: [DiffLine] = [DiffLine(kind = 1, text = "aipl_test")]`; exercises core body path returning/computing `lines.join("\n")`.

```aipl
module tests.functions.test.assert_z10_test
import * from "std/test/assert"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_assert_renderDiffText_10(): int:
  let arg_diffs = [DiffLine(kind = 4, text = "test")]
  let edge_diffs = []
  let resNom = renderDiffText(arg_diffs)
  let resEdge = renderDiffText(edge_diffs)
  assertEqStr(resNom, "  test", "renderDiffText nominal string matches")
  assertEqStr(resEdge, "", "renderDiffText boundary string matches")
  ret 0
```

---

### `createBenchmarkTimer` (`std/test/bench.aipl`)

- **Signature**: `pub fn createBenchmarkTimer(): BenchmarkTimer:`
- **Import**: `import * from "std/test/bench"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `BenchmarkTimer`
- **Unit Test**: `tests/functions/test/bench_test.aipl` | **Example**: `examples/ex_128_test_runner_tap_junit_report_cli.aipl`
- **Behavioral Summary**: Verify `createBenchmarkTimer` nanosecond benchmark timer, IQR outlier rejection (`rejectOutliersIqr`), and median/mean/p99 statistical summary formatting. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `BenchmarkTimer(startNs: 0, elapsedNs: 0, iterCount: 0, allocCount: 0)`.

```aipl
module tests.functions.test.bench_z1_test
import * from "std/test/bench"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bench_createBenchmarkTimer_1(): int:
  let resNom = createBenchmarkTimer()
  let resEdge = createBenchmarkTimer()
  assertEqInt(resNom.startNs, 0, "createBenchmarkTimer nominal resNom.startNs == 0")
  assertEqInt(resEdge.startNs, 0, "createBenchmarkTimer boundary resEdge.startNs == 0")
  ret 0
```

---

### `startBenchmarkTimer` (`std/test/bench.aipl`)

- **Signature**: `pub fn startBenchmarkTimer(mut timer: BenchmarkTimer): BenchmarkTimer:`
- **Import**: `import * from "std/test/bench"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut timer: BenchmarkTimer` | **Returns**: `BenchmarkTimer`
- **Unit Test**: `tests/functions/test/bench_test.aipl` | **Example**: `examples/ex_129_test_bench_microbenchmark_cli.aipl`
- **Behavioral Summary**: Verify `startBenchmarkTimer` nanosecond benchmark timer, IQR outlier rejection (`rejectOutliersIqr`), and median/mean/p99 statistical summary formatting. Concrete nominal inputs: `timer: BenchmarkTimer = BenchmarkTimer(startNs = 1, elapsedNs = 1, iterCount = 64, allocCount = 64)`; exercises core body path returning/computing `timer`.

```aipl
module tests.functions.test.bench_z2_test
import * from "std/test/bench"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bench_startBenchmarkTimer_2(): int:
  let arg_timer = BenchmarkTimer(startNs = 4, elapsedNs = 4, iterCount = 4, allocCount = 4)
  let edge_timer = BenchmarkTimer(startNs = 1, elapsedNs = 1, iterCount = 1, allocCount = 1)
  let resNom = startBenchmarkTimer(arg_timer)
  let resEdge = startBenchmarkTimer(edge_timer)
  assert(resNom.startNs > 0, "startBenchmarkTimer nominal resNom.startNs > 0")
  assert(resEdge.startNs > 0, "startBenchmarkTimer boundary resEdge.startNs > 0")
  ret 0
```

---

### `stopBenchmarkTimer` (`std/test/bench.aipl`)

- **Signature**: `pub fn stopBenchmarkTimer(mut timer: BenchmarkTimer): BenchmarkTimer:`
- **Import**: `import * from "std/test/bench"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut timer: BenchmarkTimer` | **Returns**: `BenchmarkTimer`
- **Unit Test**: `tests/functions/test/bench_test.aipl` | **Example**: `examples/ex_127_test_assert_matcher_suite_cli.aipl`
- **Behavioral Summary**: Verify `stopBenchmarkTimer` nanosecond benchmark timer, IQR outlier rejection (`rejectOutliersIqr`), and median/mean/p99 statistical summary formatting. Concrete nominal inputs: `timer: BenchmarkTimer = BenchmarkTimer(startNs = 1, elapsedNs = 1, iterCount = 64, allocCount = 64)`; exercises core body path returning/computing `timer`.

```aipl
module tests.functions.test.bench_z3_test
import * from "std/test/bench"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bench_stopBenchmarkTimer_3(): int:
  let arg_timer = BenchmarkTimer(startNs = 4, elapsedNs = 4, iterCount = 4, allocCount = 4)
  let edge_timer = BenchmarkTimer(startNs = 1, elapsedNs = 1, iterCount = 1, allocCount = 1)
  let resNom = stopBenchmarkTimer(arg_timer)
  let resEdge = stopBenchmarkTimer(edge_timer)
  assertEqInt(resNom.startNs, 4, "stopBenchmarkTimer nominal resNom.startNs == 4")
  assertEqInt(resEdge.startNs, 1, "stopBenchmarkTimer boundary resEdge.startNs == 1")
  ret 0
```

---

### `sortSamples` (`std/test/bench.aipl`)

- **Signature**: `fn sortSamples(samples: [int]): [int]:`
- **Import**: `import * from "std/test/bench"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `samples: [int]` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/test/bench_test.aipl` | **Example**: `examples/ex_128_test_runner_tap_junit_report_cli.aipl`
- **Behavioral Summary**: Verify `sortSamples` nanosecond benchmark timer, IQR outlier rejection (`rejectOutliersIqr`), and median/mean/p99 statistical summary formatting. Concrete nominal inputs: `samples: [int] = [1]`; exercises core body path returning/computing `arr`.

```aipl
module tests.functions.test.bench_z4_test
import * from "std/test/bench"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bench_sortSamples_4(): int:
  let arg_samples = [4]
  let edge_samples = []
  let resNom = sortSamples(arg_samples)
  let resEdge = sortSamples(edge_samples)
  assertEqInt(resNom.len(), 1, "sortSamples nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "sortSamples boundary resEdge.len() == 0")
  ret 0
```

---

### `rejectOutliersIqr` (`std/test/bench.aipl`)

- **Signature**: `pub fn rejectOutliersIqr(samples: [int]): [int]:`
- **Import**: `import * from "std/test/bench"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `samples: [int]` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/test/bench_test.aipl` | **Example**: `examples/ex_129_test_bench_microbenchmark_cli.aipl`
- **Behavioral Summary**: Verify `rejectOutliersIqr` nanosecond benchmark timer, IQR outlier rejection (`rejectOutliersIqr`), and median/mean/p99 statistical summary formatting. Concrete nominal inputs: `samples: [int] = [1]`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.test.bench_z5_test
import * from "std/test/bench"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bench_rejectOutliersIqr_5(): int:
  let arg_samples = [4]
  let edge_samples = []
  let resNom = rejectOutliersIqr(arg_samples)
  let resEdge = rejectOutliersIqr(edge_samples)
  assertEqInt(resNom.len(), 1, "rejectOutliersIqr nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "rejectOutliersIqr boundary resEdge.len() == 0")
  ret 0
```

---

### `calculateStats` (`std/test/bench.aipl`)

- **Signature**: `pub fn calculateStats(samples: [int], allocs: int): BenchmarkStats:`
- **Import**: `import * from "std/test/bench"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `samples: [int], allocs: int` | **Returns**: `BenchmarkStats`
- **Unit Test**: `tests/functions/test/bench_test.aipl` | **Example**: `examples/ex_127_test_assert_matcher_suite_cli.aipl`
- **Behavioral Summary**: Verify `calculateStats` nanosecond benchmark timer, IQR outlier rejection (`rejectOutliersIqr`), and median/mean/p99 statistical summary formatting. Concrete nominal inputs: `samples: [int] = [1]`, `allocs: int = 1`; exercises core body path returning/computing `BenchmarkStats(`.

```aipl
module tests.functions.test.bench_z6_test
import * from "std/test/bench"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bench_calculateStats_6(): int:
  let arg_samples = [4]
  let edge_samples = []
  let arg_allocs = 1
  let edge_allocs = 0
  let resNom = calculateStats(arg_samples, arg_allocs)
  let resEdge = calculateStats(edge_samples, edge_allocs)
  assertApproxEq(resNom.meanNs, 4.0, 0.001, "calculateStats nominal resNom.meanNs ~= 4.0")
  assertApproxEq(resEdge.meanNs, 0.0, 0.001, "calculateStats boundary resEdge.meanNs ~= 0.0")
  ret 0
```

---

### `formatBenchmarkReport` (`std/test/bench.aipl`)

- **Signature**: `pub fn formatBenchmarkReport(result: BenchmarkResult): str:`
- **Import**: `import * from "std/test/bench"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `result: BenchmarkResult` | **Returns**: `str`
- **Unit Test**: `tests/functions/test/bench_test.aipl` | **Example**: `examples/ex_128_test_runner_tap_junit_report_cli.aipl`
- **Behavioral Summary**: Verify `formatBenchmarkReport` nanosecond benchmark timer, IQR outlier rejection (`rejectOutliersIqr`), and median/mean/p99 statistical summary formatting. Concrete nominal inputs: `result: BenchmarkResult = BenchmarkResult(name = "aipl_test", runs = [1], stats = BenchmarkStats(meanNs = 1.0, medianNs = 1.0, stdDevNs = 1.0, minNs = 1, maxNs = 1, iqrNs = 1.0, allocsPerOp = 1.0))`; exercises core body path returning/computing `result.name + ": " + str(result.runs.len()) + " ops, " + str(result.stats.meanNs) + " ns/op, " + str(result.stats.allocsPerOp) + " allocs/op"`.

```aipl
module tests.functions.test.bench_z7_test
import * from "std/test/bench"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bench_formatBenchmarkReport_7(): int:
  let arg_result = BenchmarkResult(name = "test", runs = [], stats = BenchmarkStats(meanNs = 1.0, medianNs = 1.0, stdDevNs = 1.0, minNs = 4, maxNs = 4, iqrNs = 1.0, allocsPerOp = 0.0))
  let edge_result = BenchmarkResult(name = "a", runs = [], stats = BenchmarkStats(meanNs = 0.5, medianNs = 0.5, stdDevNs = 0.5, minNs = 1, maxNs = 1, iqrNs = 0.5, allocsPerOp = 0.0))
  let resNom = formatBenchmarkReport(arg_result)
  let resEdge = formatBenchmarkReport(edge_result)
  assertEqStr(resNom, "test: 0 ops, 1 ns/op, 0 allocs/op", "formatBenchmarkReport nominal string matches")
  assertEqStr(resEdge, "a: 0 ops, 0.5 ns/op, 0 allocs/op", "formatBenchmarkReport boundary string matches")
  ret 0
```

---

### `createFuzzGenerator` (`std/test/fuzz.aipl`)

- **Signature**: `pub fn createFuzzGenerator(seed: int): FuzzGenerator:`
- **Import**: `import * from "std/test/fuzz"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `seed: int` | **Returns**: `FuzzGenerator`
- **Unit Test**: `tests/functions/test/fuzz_test.aipl` | **Example**: `examples/ex_129_test_bench_microbenchmark_cli.aipl`
- **Behavioral Summary**: Verify `createFuzzGenerator` deterministic PRNG fuzz input generation and minimal counterexample shrinking (`shrinkCounterExampleInt`/`String`). Concrete nominal inputs: `seed: int = 42`; exercises core body path returning/computing `FuzzGenerator(seed: seed, state: s)`.

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

---

### `nextRaw64` (`std/test/fuzz.aipl`)

- **Signature**: `fn nextRaw64(gen: FuzzGenerator): (FuzzGenerator, int):`
- **Import**: `import * from "std/test/fuzz"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `gen: FuzzGenerator` | **Returns**: `(FuzzGenerator, int)`
- **Unit Test**: `tests/functions/test/fuzz_test.aipl` | **Example**: `examples/ex_127_test_assert_matcher_suite_cli.aipl`
- **Behavioral Summary**: Verify `nextRaw64` deterministic PRNG fuzz input generation and minimal counterexample shrinking (`shrinkCounterExampleInt`/`String`). Concrete nominal inputs: `gen: FuzzGenerator): (FuzzGenerator = FuzzGenerator): (FuzzGenerator()`, `int: any = 42`; exercises core body path returning/computing `(FuzzGenerator(seed: gen.seed, state: x), pos)`.

```aipl
module tests.functions.test.fuzz_z2_test
import * from "std/test/fuzz"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fuzz_nextRaw64_2(): int:
  let arg_gen = FuzzGenerator(seed = 0, state = 0)
  let edge_gen = FuzzGenerator(seed = 0, state = 0)
  let resNom = nextRaw64(arg_gen)
  let resEdge = nextRaw64(edge_gen)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0.seed, 0, "nextRaw64 nominal n_t0.seed == 0")
  assertEqInt(e_t0.seed, 0, "nextRaw64 boundary e_t0.seed == 0")
  ret 0
```

---

### `fuzzNextInt` (`std/test/fuzz.aipl`)

- **Signature**: `pub fn fuzzNextInt(gen: FuzzGenerator, minVal: int, maxVal: int): (FuzzGenerator, int):`
- **Import**: `import * from "std/test/fuzz"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `gen: FuzzGenerator, minVal: int, maxVal: int` | **Returns**: `(FuzzGenerator, int)`
- **Unit Test**: `tests/functions/test/fuzz_test.aipl` | **Example**: `examples/ex_128_test_runner_tap_junit_report_cli.aipl`
- **Behavioral Summary**: Verify `fuzzNextInt` deterministic PRNG fuzz input generation and minimal counterexample shrinking (`shrinkCounterExampleInt`/`String`). Concrete nominal inputs: `gen: FuzzGenerator = FuzzGenerator(seed = 42, state = 1)`, `minVal: int = 1`, `maxVal: int): (FuzzGenerator = int): (FuzzGenerator()`, `int: any = 42`; exercises core body path returning/computing `(nextGen, v)`.

```aipl
module tests.functions.test.fuzz_z3_test
import * from "std/test/fuzz"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fuzz_fuzzNextInt_3(): int:
  let arg_gen = FuzzGenerator(seed = 0, state = 0)
  let edge_gen = FuzzGenerator(seed = 0, state = 0)
  let arg_minVal = 4
  let edge_minVal = 1
  let arg_maxVal = 4
  let edge_maxVal = 1
  let resNom = fuzzNextInt(arg_gen, arg_minVal, arg_maxVal)
  let resEdge = fuzzNextInt(edge_gen, edge_minVal, edge_maxVal)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0.seed, 0, "fuzzNextInt nominal n_t0.seed == 0")
  assertEqInt(e_t0.seed, 0, "fuzzNextInt boundary e_t0.seed == 0")
  ret 0
```

---

### `fuzzNextFloat` (`std/test/fuzz.aipl`)

- **Signature**: `pub fn fuzzNextFloat(gen: FuzzGenerator, minVal: float, maxVal: float): (FuzzGenerator, float):`
- **Import**: `import * from "std/test/fuzz"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `gen: FuzzGenerator, minVal: float, maxVal: float` | **Returns**: `(FuzzGenerator, float)`
- **Unit Test**: `tests/functions/test/fuzz_test.aipl` | **Example**: `examples/ex_129_test_bench_microbenchmark_cli.aipl`
- **Behavioral Summary**: Verify `fuzzNextFloat` deterministic PRNG fuzz input generation and minimal counterexample shrinking (`shrinkCounterExampleInt`/`String`). Concrete nominal inputs: `gen: FuzzGenerator = FuzzGenerator(seed = 42, state = 1)`, `minVal: float = 1.0`, `maxVal: float): (FuzzGenerator = float): (FuzzGenerator()`, `float: any = 42`; exercises core body path returning/computing `(nextGen, minVal + frac * (maxVal - minVal))`.

```aipl
module tests.functions.test.fuzz_z4_test
import * from "std/test/fuzz"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fuzz_fuzzNextFloat_4(): int:
  let arg_gen = FuzzGenerator(seed = 0, state = 0)
  let edge_gen = FuzzGenerator(seed = 0, state = 0)
  let arg_minVal = 0.0
  let edge_minVal = 0.0
  let arg_maxVal = 2.0
  let edge_maxVal = 1.0
  let resNom = fuzzNextFloat(arg_gen, arg_minVal, arg_maxVal)
  let resEdge = fuzzNextFloat(edge_gen, edge_minVal, edge_maxVal)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0.seed, 0, "fuzzNextFloat nominal n_t0.seed == 0")
  assertEqInt(e_t0.seed, 0, "fuzzNextFloat boundary e_t0.seed == 0")
  ret 0
```

---

### `fuzzNextString` (`std/test/fuzz.aipl`)

- **Signature**: `pub fn fuzzNextString(gen: FuzzGenerator, maxLen: int): (FuzzGenerator, str):`
- **Import**: `import * from "std/test/fuzz"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `gen: FuzzGenerator, maxLen: int` | **Returns**: `(FuzzGenerator, str)`
- **Unit Test**: `tests/functions/test/fuzz_test.aipl` | **Example**: `examples/ex_127_test_assert_matcher_suite_cli.aipl`
- **Behavioral Summary**: Verify `fuzzNextString` deterministic PRNG fuzz input generation and minimal counterexample shrinking (`shrinkCounterExampleInt`/`String`). Concrete nominal inputs: `gen: FuzzGenerator = FuzzGenerator(seed = 42, state = 1)`, `maxLen: int): (FuzzGenerator = int): (FuzzGenerator()`, `str: any = 42`; exercises core body path returning/computing `(curGen, out)`.

```aipl
module tests.functions.test.fuzz_z5_test
import * from "std/test/fuzz"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fuzz_fuzzNextString_5(): int:
  let arg_gen = FuzzGenerator(seed = 0, state = 0)
  let edge_gen = FuzzGenerator(seed = 0, state = 0)
  let arg_maxLen = 4
  let edge_maxLen = 1
  let resNom = fuzzNextString(arg_gen, arg_maxLen)
  let resEdge = fuzzNextString(edge_gen, edge_maxLen)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0.seed, 0, "fuzzNextString nominal n_t0.seed == 0")
  assertEqInt(e_t0.seed, 0, "fuzzNextString boundary e_t0.seed == 0")
  ret 0
```

---

### `fuzzNextBytes` (`std/test/fuzz.aipl`)

- **Signature**: `pub fn fuzzNextBytes(gen: FuzzGenerator, maxLen: int): (FuzzGenerator, [int]):`
- **Import**: `import * from "std/test/fuzz"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `gen: FuzzGenerator, maxLen: int` | **Returns**: `(FuzzGenerator, [int])`
- **Unit Test**: `tests/functions/test/fuzz_test.aipl` | **Example**: `examples/ex_128_test_runner_tap_junit_report_cli.aipl`
- **Behavioral Summary**: Verify `fuzzNextBytes` deterministic PRNG fuzz input generation and minimal counterexample shrinking (`shrinkCounterExampleInt`/`String`). Concrete nominal inputs: `gen: FuzzGenerator = FuzzGenerator(seed = 42, state = 1)`, `maxLen: int): (FuzzGenerator = int): (FuzzGenerator()`, `[int]: any = 42`; exercises core body path returning/computing `(curGen, out)`.

```aipl
module tests.functions.test.fuzz_z6_test
import * from "std/test/fuzz"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fuzz_fuzzNextBytes_6(): int:
  let arg_gen = FuzzGenerator(seed = 0, state = 0)
  let edge_gen = FuzzGenerator(seed = 0, state = 0)
  let arg_maxLen = 4
  let edge_maxLen = 1
  let resNom = fuzzNextBytes(arg_gen, arg_maxLen)
  let resEdge = fuzzNextBytes(edge_gen, edge_maxLen)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0.seed, 0, "fuzzNextBytes nominal n_t0.seed == 0")
  assertEqInt(e_t0.seed, 0, "fuzzNextBytes boundary e_t0.seed == 0")
  ret 0
```

---

### `shrinkCounterExampleInt` (`std/test/fuzz.aipl`)

- **Signature**: `pub fn shrinkCounterExampleInt(failingVal: int, targetVal: int, minFailThreshold: int): int:`
- **Import**: `import * from "std/test/fuzz"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `failingVal: int, targetVal: int, minFailThreshold: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/test/fuzz_test.aipl` | **Example**: `examples/ex_129_test_bench_microbenchmark_cli.aipl`
- **Behavioral Summary**: Verify `shrinkCounterExampleInt` deterministic PRNG fuzz input generation and minimal counterexample shrinking (`shrinkCounterExampleInt`/`String`). Concrete nominal inputs: `failingVal: int = 1`, `targetVal: int = 1`, `minFailThreshold: int = 1`; exercises core body path returning/computing `hi`.

```aipl
module tests.functions.test.fuzz_z7_test
import * from "std/test/fuzz"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fuzz_shrinkCounterExampleInt_7(): int:
  let arg_failingVal = 4
  let edge_failingVal = 1
  let arg_targetVal = 2
  let edge_targetVal = 0
  let arg_minFailThreshold = 4
  let edge_minFailThreshold = 1
  let resNom = shrinkCounterExampleInt(arg_failingVal, arg_targetVal, arg_minFailThreshold)
  let resEdge = shrinkCounterExampleInt(edge_failingVal, edge_targetVal, edge_minFailThreshold)
  assertEqInt(resNom, 4, "shrinkCounterExampleInt nominal resNom == 4")
  assertEqInt(resEdge, 1, "shrinkCounterExampleInt boundary resEdge == 1")
  ret 0
```

---

### `shrinkCounterExampleString` (`std/test/fuzz.aipl`)

- **Signature**: `pub fn shrinkCounterExampleString(failingStr: str, requiredToken: str): str:`
- **Import**: `import * from "std/test/fuzz"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `failingStr: str, requiredToken: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/test/fuzz_test.aipl` | **Example**: `examples/ex_127_test_assert_matcher_suite_cli.aipl`
- **Behavioral Summary**: Verify `shrinkCounterExampleString` deterministic PRNG fuzz input generation and minimal counterexample shrinking (`shrinkCounterExampleInt`/`String`). Concrete nominal inputs: `failingStr: str = "aipl_test"`, `requiredToken: str = "aipl_test"`; exercises core body path returning/computing `cur`.

```aipl
module tests.functions.test.fuzz_z8_test
import * from "std/test/fuzz"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fuzz_shrinkCounterExampleString_8(): int:
  let arg_failingStr = "test"
  let edge_failingStr = "a"
  let arg_requiredToken = "test"
  let edge_requiredToken = "a"
  let resNom = shrinkCounterExampleString(arg_failingStr, arg_requiredToken)
  let resEdge = shrinkCounterExampleString(edge_failingStr, edge_requiredToken)
  assertEqStr(resNom, "test", "shrinkCounterExampleString nominal string matches")
  assertEqStr(resEdge, "a", "shrinkCounterExampleString boundary string matches")
  ret 0
```

---

### `verifyProperty` (`std/test/fuzz.aipl`)

- **Signature**: `pub fn verifyProperty(config: FuzzConfig, failThreshold: int): FuzzResult:`
- **Import**: `import * from "std/test/fuzz"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `config: FuzzConfig, failThreshold: int` | **Returns**: `FuzzResult`
- **Unit Test**: `tests/functions/test/fuzz_test.aipl` | **Example**: `examples/ex_128_test_runner_tap_junit_report_cli.aipl`
- **Behavioral Summary**: Verify `verifyProperty` deterministic PRNG fuzz input generation and minimal counterexample shrinking (`shrinkCounterExampleInt`/`String`). Concrete nominal inputs: `config: FuzzConfig = FuzzConfig(seed = 42, maxIterations = 1, maxShrinkSteps = 1, maxCollectionLen = 64)`, `failThreshold: int = 1`; exercises core body path returning/computing `FuzzResult(`.

```aipl
module tests.functions.test.fuzz_z9_test
import * from "std/test/fuzz"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fuzz_verifyProperty_9(): int:
  let arg_config = FuzzConfig(seed = 0, maxIterations = 4, maxShrinkSteps = 4, maxCollectionLen = 4)
  let edge_config = FuzzConfig(seed = 0, maxIterations = 1, maxShrinkSteps = 1, maxCollectionLen = 1)
  let arg_failThreshold = 2
  let edge_failThreshold = 0
  let resNom = verifyProperty(arg_config, arg_failThreshold)
  let resEdge = verifyProperty(edge_config, edge_failThreshold)
  assertEqInt(resNom.iterationsRun, 1, "verifyProperty nominal resNom.iterationsRun == 1")
  assertEqInt(resEdge.iterationsRun, 1, "verifyProperty boundary resEdge.iterationsRun == 1")
  ret 0
```

---

### `createTestSuite` (`std/test/test_runner.aipl`)

- **Signature**: `pub fn createTestSuite(name: str): TestSuite:`
- **Import**: `import * from "std/test/test_runner"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `name: str` | **Returns**: `TestSuite`
- **Unit Test**: `tests/functions/test/test_runner_test.aipl` | **Example**: `examples/ex_129_test_bench_microbenchmark_cli.aipl`
- **Behavioral Summary**: Verify `createTestSuite` test suite registration, substring filtering, pass/fail aggregation, and TAP v13 / JUnit XML report serialization. Concrete nominal inputs: `name: str = "aipl_test"`; exercises core body path returning/computing `TestSuite(name: name, cases: [], results: [])`.

```aipl
module tests.functions.test.test_runner_z1_test
import * from "std/test/test_runner"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_test_runner_createTestSuite_1(): int:
  let arg_name = "test"
  let edge_name = "a"
  let resNom = createTestSuite(arg_name)
  let resEdge = createTestSuite(edge_name)
  assertEqStr(resNom.name, "test", "createTestSuite nominal string matches")
  assertEqStr(resEdge.name, "a", "createTestSuite boundary string matches")
  ret 0
```

---

### `registerTestCase` (`std/test/test_runner.aipl`)

- **Signature**: `pub fn registerTestCase(mut suite: TestSuite, name: str, moduleName: str, expectedStatus: int): TestSuite:`
- **Import**: `import * from "std/test/test_runner"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut suite: TestSuite, name: str, moduleName: str, expectedStatus: int` | **Returns**: `TestSuite`
- **Unit Test**: `tests/functions/test/test_runner_test.aipl` | **Example**: `examples/ex_127_test_assert_matcher_suite_cli.aipl`
- **Behavioral Summary**: Verify `registerTestCase` test suite registration, substring filtering, pass/fail aggregation, and TAP v13 / JUnit XML report serialization. Concrete nominal inputs: `suite: TestSuite = TestSuite(name = "aipl_test")`, `name: str = "aipl_test"`, `moduleName: str = "aipl_test"`, `expectedStatus: int = 1`; exercises core body path returning/computing `suite`.

```aipl
module tests.functions.test.test_runner_z2_test
import * from "std/test/test_runner"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_test_runner_registerTestCase_2(): int:
  let arg_suite = TestSuite(name = "test", cases = [], results = [])
  let edge_suite = TestSuite(name = "a", cases = [], results = [])
  let arg_name = "test"
  let edge_name = "a"
  let arg_moduleName = "test"
  let edge_moduleName = "a"
  let arg_expectedStatus = 1
  let edge_expectedStatus = 0
  let resNom = registerTestCase(arg_suite, arg_name, arg_moduleName, arg_expectedStatus)
  let resEdge = registerTestCase(edge_suite, edge_name, edge_moduleName, edge_expectedStatus)
  assertEqStr(resNom.name, "test", "registerTestCase nominal string matches")
  assertEqStr(resEdge.name, "a", "registerTestCase boundary string matches")
  ret 0
```

---

### `filterTestCases` (`std/test/test_runner.aipl`)

- **Signature**: `pub fn filterTestCases(suite: TestSuite, filter: TestFilter): [TestCase]:`
- **Import**: `import * from "std/test/test_runner"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `suite: TestSuite, filter: TestFilter` | **Returns**: `[TestCase]`
- **Unit Test**: `tests/functions/test/test_runner_test.aipl` | **Example**: `examples/ex_128_test_runner_tap_junit_report_cli.aipl`
- **Behavioral Summary**: Verify `filterTestCases` test suite registration, substring filtering, pass/fail aggregation, and TAP v13 / JUnit XML report serialization. Concrete nominal inputs: `suite: TestSuite = TestSuite(name = "aipl_test")`, `filter: TestFilter = TestFilter(pattern = "aipl_test", includeIgnored = true)`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.test.test_runner_z3_test
import * from "std/test/test_runner"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_test_runner_filterTestCases_3(): int:
  let arg_suite = TestSuite(name = "test", cases = [], results = [])
  let edge_suite = TestSuite(name = "a", cases = [], results = [])
  let arg_filter = TestFilter(pattern = "test", includeIgnored = true)
  let edge_filter = TestFilter(pattern = "a", includeIgnored = false)
  let resNom = filterTestCases(arg_suite, arg_filter)
  let resEdge = filterTestCases(edge_suite, edge_filter)
  assertEqInt(resNom.len(), 0, "filterTestCases nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "filterTestCases boundary resEdge.len() == 0")
  ret 0
```

---

### `runTestSuite` (`std/test/test_runner.aipl`)

- **Signature**: `pub fn runTestSuite(mut suite: TestSuite, filter: TestFilter): TestSuite:`
- **Import**: `import * from "std/test/test_runner"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut suite: TestSuite, filter: TestFilter` | **Returns**: `TestSuite`
- **Unit Test**: `tests/functions/test/test_runner_test.aipl` | **Example**: `examples/ex_129_test_bench_microbenchmark_cli.aipl`
- **Behavioral Summary**: Verify `runTestSuite` test suite registration, substring filtering, pass/fail aggregation, and TAP v13 / JUnit XML report serialization. Concrete nominal inputs: `suite: TestSuite = TestSuite(name = "aipl_test")`, `filter: TestFilter = TestFilter(pattern = "aipl_test", includeIgnored = true)`; exercises core body path returning/computing `suite`.

```aipl
module tests.functions.test.test_runner_z4_test
import * from "std/test/test_runner"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_test_runner_runTestSuite_4(): int:
  let arg_suite = TestSuite(name = "test", cases = [], results = [])
  let edge_suite = TestSuite(name = "a", cases = [], results = [])
  let arg_filter = TestFilter(pattern = "test", includeIgnored = true)
  let edge_filter = TestFilter(pattern = "a", includeIgnored = false)
  let resNom = runTestSuite(arg_suite, arg_filter)
  let resEdge = runTestSuite(edge_suite, edge_filter)
  assertEqStr(resNom.name, "test", "runTestSuite nominal string matches")
  assertEqStr(resEdge.name, "a", "runTestSuite boundary string matches")
  ret 0
```

---

### `formatTapReport` (`std/test/test_runner.aipl`)

- **Signature**: `pub fn formatTapReport(suite: TestSuite): str:`
- **Import**: `import * from "std/test/test_runner"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `suite: TestSuite` | **Returns**: `str`
- **Unit Test**: `tests/functions/test/test_runner_test.aipl` | **Example**: `examples/ex_127_test_assert_matcher_suite_cli.aipl`
- **Behavioral Summary**: Verify `formatTapReport` test suite registration, substring filtering, pass/fail aggregation, and TAP v13 / JUnit XML report serialization. Concrete nominal inputs: `suite: TestSuite = TestSuite(name = "aipl_test")`; exercises core body path returning/computing `lines.join("\n")`.

```aipl
module tests.functions.test.test_runner_z5_test
import * from "std/test/test_runner"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_test_runner_formatTapReport_5(): int:
  let arg_suite = TestSuite(name = "test", cases = [], results = [])
  let edge_suite = TestSuite(name = "a", cases = [], results = [])
  let resNom = formatTapReport(arg_suite)
  let resEdge = formatTapReport(edge_suite)
  assertEqInt(resNom.len(), 19, "formatTapReport nominal string length == 19")
  assertEqInt(resEdge.len(), 19, "formatTapReport boundary string length == 19")
  ret 0
```

---

### `formatJunitXmlReport` (`std/test/test_runner.aipl`)

- **Signature**: `pub fn formatJunitXmlReport(suite: TestSuite): str:`
- **Import**: `import * from "std/test/test_runner"` (or barrel `import * from "std/test/test_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `suite: TestSuite` | **Returns**: `str`
- **Unit Test**: `tests/functions/test/test_runner_test.aipl` | **Example**: `examples/ex_128_test_runner_tap_junit_report_cli.aipl`
- **Behavioral Summary**: Verify `formatJunitXmlReport` test suite registration, substring filtering, pass/fail aggregation, and TAP v13 / JUnit XML report serialization. Concrete nominal inputs: `suite: TestSuite = TestSuite(name = "aipl_test")`; exercises core body path returning/computing `lines.join("\n")`.

```aipl
module tests.functions.test.test_runner_z6_test
import * from "std/test/test_runner"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_test_runner_formatJunitXmlReport_6(): int:
  let arg_suite = TestSuite(name = "<r></r>", cases = [], results = [])
  let edge_suite = TestSuite(name = "<r></r>", cases = [], results = [])
  let resNom = formatJunitXmlReport(arg_suite)
  let resEdge = formatJunitXmlReport(edge_suite)
  assertEqInt(resNom.len(), 132, "formatJunitXmlReport nominal string length == 132")
  assertEqInt(resEdge.len(), 132, "formatJunitXmlReport boundary string length == 132")
  ret 0
```
