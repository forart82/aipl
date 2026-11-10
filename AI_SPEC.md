# AIPL v0.9.0 AI Agent & LLM Generation Specification
**Authoritative Guidelines, Invariants, and Tooling Protocols for Autonomous AI Coding Agents**

[Home](README.md) | [Docs Index](docs/INDEX.md) | [Specification](SPEC.md) | [Grammar & Syntax](docs/GRAMMAR_AND_SYNTAX.md) | [Build & Targets](docs/BUILD_AND_TARGETS.md) | [Diagnostics Schema](docs/DIAGNOSTICS_SCHEMA.md)

> **When to Read This Document**: Read this specification when designing, generating, or refactoring AIPL code as an autonomous AI coding agent. It documents strict tokenomics rules, 2-space indentation invariants, zero-hallucination cheat sheets, and surgical self-repair protocols.

---

## Canonical Project Architecture & Counts

- **36 Standard Library Domain Groups**: `2` root modules (`std/std_root.aipl`, `std/prelude.aipl`) + `35` canonical domain directories = **`290` `std/` modules**.
- **4,324 Total Callable Functions**: **`32` compiler built-ins + `4,292` `std/` functions, constructors & receiver methods**.
- **250 Curated, Fully-Tested Examples**: `examples/ex_001_*.aipl` through `examples/ex_250_*.aipl` with twin unit tests in `tests/examples/`.
- **36 Architecture Decision Records**: `docs/ADR/ADR-0001-*.md` through `docs/ADR/ADR-0036-*.md` indexed in [`docs/ADR/INDEX.md`](docs/ADR/INDEX.md).

---

## Section 1: Standardized Navigation Header & SentencePiece 256k Tokenomics Invariants

AIPL syntax is co-designed around the empirical mathematics of subword tokenizers (SentencePiece 256k used in Gemini/Gemma) to achieve a **60%+ token reduction** over conventional languages. AI agents must follow these strict invariants:

1. **Strict 2-Space Indentation Offside Rule**:
   - Indentation depth is exactly **2 spaces** (`  `) per nesting level.
   - Tabs (`\t`) are strictly forbidden and trigger compile error `AIPL_E1001_TAB_INDENT_FORBIDDEN`.
   - 4-space indentation is rejected as a syntax error.
2. **Strict camelCase Identifier Invariant (ADR-0002)**:
   - Variables, parameters, and function names must be `camelCase`.
   - Structs, enums, and type aliases must be `PascalCase`.
   - Underscores (`_`) are strictly forbidden in identifier names, except for the single-underscore wildcard `_`.
2. **Strict camelCase Identifier Invariant (ADR-0002)**:
   - Variables, parameters, and function names must be `camelCase` (`test_*` test functions and `UPPER_SNAKE_CASE` constants are preserved).
   - Structs, enums, and type aliases must be `PascalCase`.
   - Underscores (`_`) are strictly forbidden in general identifier names, except for the single-underscore wildcard `_`.
3. **Single-Token Keywords & Automatic Shortest-Syntax Canonicalization**:
   - All keywords (`fn`, `let`, `mut`, `pub`, `ret`, `if`, `elif`, `else`, `match`, `for`, `in`, `while`, `with`, `arena`, `import`, `struct`, `enum`) map to atomic tokens.
   - `aipl verify`, `build`, `run`, `test`, `fmt`, and `fix` automatically rewrite verbose/polyglot syntax in place on disk to the shortest canonical form (`:` over `{}`, `ret` over `return`, `elif` over `else if`, `): Type` over `) -> Type`, `and`/`or`/`not` over `&&`/`||`/`!`, and single-line `fn(...)` and `struct Name(...)`).

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

## Section 2: Zero-Hallucination Idiomatic AIPL Code Generation Cheat Sheet

When generating AIPL code, agents must observe the following anti-hallucination rules:

1. **Zero Implicit Coercion**: AIPL does not automatically convert between numbers. Always use explicit constructor conversions: `float(intVal)` or `int(floatVal)`.
2. **Boolean Strictness**: Condition expressions in `if`, `while`, and contracts must evaluate strictly to `bool`. Non-boolean truthy/falsy values trigger `AIPL_E2003`.
3. **Receiver Method Syntax**: Receiver methods are declared using `pub fn StructName.methodName(self, ...): RetType:`.
4. **Algebraic Error Handling**: Always use `Option[T]` (`Some(v)` or `None()`) and `Result[T, E]` (`Ok(v)` or `Err(e)`). Propagate errors with postfix `?`.
5. **Contract Blocks**: Use `req: <cond>` for pre-conditions and `ens: <cond>` for post-conditions. The return value is referenced as `ret`.
6. **String Interpolation**: Use `"{expr}"` with optional format specifiers `"{val:.2f}"` or `"{val:02x}"`. Never use Python `f"..."` or JS backticks.

- **Primary Source Module**: `std/prelude.aipl` (`pub fn (self: Option[T]) isSome(): bool:`)
- **Verification Test**: `tests/functions/core/prelude_test.aipl`
- **Runnable Example Reference**: `examples/ex_009_option_and_result_error_handling_cli.aipl` (tested by `tests/examples/ex_009_option_and_result_error_handling_cli_test.aipl`)

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

## Section 3: 36-Domain Standard Library Import Rules & Module Resolution

The standard library contains exactly **36 domain groups** (root core + 35 canonical domain directories), encompassing **290 modules**:

### Import Syntax Rules
- **Explicit Selective Import**: `import { functionName, StructName } from "std/<domain>/<module>"`
- **Wildcard Import**: `import * from "std/<domain>/<module>"`
- **Domain Barrel Import**: `import * from "std/<domain>/<domain>_mod"`

### Standard Library Domains (Hierarchical Layers $L_0$ to $L_5$)
- **$L_0$ (Core & Prelude)**: `std/std_root.aipl`, `std/prelude.aipl`
- **$L_1$ (Systems & Runtime)**: `std/sys/`, `std/rt/`, `std/alloc/`, `std/memory/`
- **$L_2$ (Algorithms & Data)**: `std/math/`, `std/collections/`, `std/fmt/`, `std/regex/`, `std/time/`
- **$L_3$ (I/O & Serialization)**: `std/encoding/`, `std/compress/`, `std/crypto/`, `std/db/`, `std/io/`, `std/fs/`, `std/os/`, `std/sync/`, `std/thread/`, `std/net/`, `std/test/`
- **$L_4$ (Media & Graphics)**: `std/window/`, `std/input/`, `std/asset/`, `std/audio/`, `std/gfx/`, `std/gfx2d/`, `std/gfx25d/`, `std/gfx3d/`, `std/particle/`, `std/ui/`
- **$L_5$ (Simulation & Capstone)**: `std/ecs/`, `std/spatial/`, `std/phys2d/`, `std/phys3d/`, `std/procgen/`, `std/ai/`, `std/hebar/`, `std/mechanics/`

### Functional Struct Updates & 2.5D Continuous World Ergonomics
- **Postfix Struct Update**: `let nextCam = cam { worldX = 100.0, worldY = 200.0 }` (lowers to `aipl_struct_spread` with deep nested struct cloning via `cloneStruct(s)`).
- **Continuous 2.5D/3D World Engine, UV Texture Splatting, 2.5D Lighting, 8-Dir Sprite Rigs & Weather (`std/gfx25d/*`, `std/gfx2d/shape2d`)**: Use `createCamera25D`, `project3DToIso`, `unprojectIsoTo3D`, `getVisibleWorldAABB`, `drawHeightfieldPatch25D`, `drawHeightfieldPatchTextured25D`, `drawHeightfieldSplat25D`, `drawGroundDecal25D`, `drawSplineRibbon25D`, `drawSplineRibbonTextured25D`, `drawPrism25D`, `drawPrismTextured25D`, `drawIndexedMesh25D`, `drawIndexedMeshTextured25D`, `drawCone25D`, `drawBillboard25D`, `createPointLight25D`, `drawAmbientDarknessPass25D`, `drawLightCookie25D`, `renderLightingPass25D`, `createIsoSpriteRig25D`, `updateIsoSpriteRig25D`, `drawContactShadow25D`, `drawIsoSpriteRig25D`, `drawBillboardCutout25D`, `createWeather25D`, `stepWeather25D`, `drawMistPlanes25D`, `drawWeatherParticles25D`, `setBlendMode`, `getBlendMode`, `blendModeAlpha`, `blendModeAdditive`, `blendModeMultiplied`, `blendModeScreen`, `drawTriangle3DTextured`, `drawQuad3DTextured`, `createTextureFromRgba`, `createProceduralTexture`, `createIsometricSpriteSheet`, and `saveTextureToPpm` with `setDepthTest(true)`, `clearDepth()`, and `beginWorldPass()` / `endWorldPass()` (which suppresses false-positive UI hitbox telemetry during world geometry passes; showcased in `ex_259`, `ex_260`, `ex_261`, `ex_262`, and `ex_263`).

- **Primary Source Module**: `std/std_root.aipl` (`pub fn stdlibDomainCount(): int:`)
- **Verification Test**: `tests/functions/core/std_root_test.aipl`
- **Runnable Example Reference**: `examples/ex_010_modules_and_multi_file_imports_cli.aipl` (tested by `tests/examples/ex_010_modules_and_multi_file_imports_cli_test.aipl`)

```aipl
module tests.functions.core.std_root_stdlibDomainCount_test
import * from "std/std_root"
import * from "std/prelude"

pub fn test_std_root_stdlibDomainCount(): int:
  assertEqInt(stdlibDomainCount(), 35, "35 canonical domains")
  assertEqInt(stdlibDomainCount(), stdlibCanonicalDomains().len(), "matches array length")
  ret 0
```

---

## Section 4: Surgical Agent Tooling Protocol (outline, splice, fix, verify --json)

Autonomous AI agents should minimize context window consumption using AIPL's surgical sub-commands:

1. **`./bin/aipl outline <file>`**: Emits a token-optimal skeleton of functions, structs, and signatures without function bodies.
2. **`./bin/aipl splice <file> <symbol> <replacement>`**: Replaces an individual function or struct definition in-place without rewriting the entire file.
3. **`./bin/aipl fix <file>`**: Automatically repairs common formatting, indentation, and casing warnings (`AIPL_W1003`).
4. **`./bin/aipl verify <file> --json`**: Validates syntax, types, and contracts, returning structured diagnostic objects.

- **Primary Source Module**: `std/encoding/json.aipl` (`pub fn jsonNull(): JsonValue:`)
- **Verification Test**: `tests/functions/encoding/json_test.aipl`
- **Runnable Example Reference**: `examples/ex_069_time_frame_pacer_hud_window.aipl` (tested by `tests/examples/ex_069_time_frame_pacer_hud_window_test.aipl`)

```aipl
module tests.functions.encoding.json_z1_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonNull_1(): int:
  let resNom = jsonNull()
  let resEdge = jsonNull()
  assertEqStr(resNom.kind, "null", "jsonNull nominal string matches")
  assertEqStr(resEdge.kind, "null", "jsonNull boundary string matches")
  ret 0
```

---

## Section 5: Machine-Readable Diagnostic Code Reference (E1xx, E2xx, E3xx) & Self-Repair Loop

Errors emitted by `./bin/aipl check --json` conform to `diagnostic-v1.json` with three primary error ranges:

| Error Range | Category | Description | Self-Repair Strategy |
| :--- | :--- | :--- | :--- |
| **`E1xx`** | Syntax & Lexer | Indentation depth, unclosed delimiters, invalid tokens | Run `aipl fix` or align blocks to strict 2 spaces |
| **`E2xx`** | Type & Resolution | Type mismatch, missing symbol, unhandled variant | Insert explicit constructor casts (`int()`, `float()`) |
| **`E3xx`** | SMT & Contract | `req:` pre-condition violation, `ens:` post-condition refutation | Strengthen preconditions or adjust logic bounds |

- **Primary Source Module**: `std/test/assert.aipl` (`pub fn testAssert(cond: bool, msg: str = "Assertion failed"): bool:`)
- **Verification Test**: `tests/functions/test/assert_test.aipl`
- **Runnable Example Reference**: `examples/ex_127_test_assert_matcher_suite_cli.aipl` (tested by `tests/examples/ex_127_test_assert_matcher_suite_cli_test.aipl`)

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
