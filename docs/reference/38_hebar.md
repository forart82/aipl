[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 38: `hebar` API Reference

> Complete API reference manual for AIPL standard library domain `hebar` (`std/hebar/referee.aipl` and barrel `std/hebar/hebar_mod.aipl`, canonical alias namespace re-exporting all 16 public Human-Equivalent Bot Automated Referee functions and 2 data structures from `std/ai/hebar_referee.aipl`).

## 1. Domain Overview & Source Modules

- **Domain Name**: `hebar`
- **Architecture Layer**: Layer 5 ($L_5$: Human-Equivalent Bot Automated Referee & Biological Fairness Guard)
- **Target Source Modules**: ["std/hebar/referee.aipl", "std/hebar/hebar_mod.aipl"] (re-exporting ["std/ai/hebar_referee.aipl"])
- **Re-Exported Public Callable Functions**: 16 (`tests/functions/hebar/referee_test.aipl`, `tests/functions/hebar/hebar_mod_test.aipl`)
- **Re-Exported Data Types (`struct`)**: 2 (`HebarActionRecord`, `HebarReferee`)
- **Governing ADR**: [ADR-0037: Continuous 2.5D/3D World Engine, Hardware/Software Z-Buffering & Per-Vertex Gouraud Pipeline](../ADR/ADR-0037-continuous-25d-world-and-zbuffer-pipeline.md)
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `HebarActionRecord` | `pub struct` | `std/hebar/referee.aipl` (`std/ai/hebar_referee.aipl`) | `timestampMs: int`, `actionTag: str`, `targetPos: Vec2` | Timestamped bot input event queued for reaction-delay enforcement |
| `HebarReferee` | `pub struct` | `std/hebar/referee.aipl` (`std/ai/hebar_referee.aipl`) | `minReactionDelayMs: int`, `maxReactionDelayMs: int`, `maxActionsPerMinute: int`, `actionHistory: [HebarActionRecord]`, `lastPopTimestampMs: int`, `maxInputHz: float`, `maxCursorSpeedPxPerSec: float`, `maxAngularVelocityRadPerSec: float`, `cursorPos: Vec2`, `headingRad: float`, `tamperViolations: int` | 5-bound biological fairness referee state |

---

## 3. Summary Function Index Table

| # | Module | Function | Verbatim Signature | Unit Test Suite |
| :---: | :--- | :--- | :--- | :--- |
| `1` | `std/hebar/referee.aipl` | `hebarRefereeNew` | `pub fn hebarRefereeNew(minDelayMs: int = 150, maxDelayMs: int = 250, maxApm: int = 900): HebarReferee:` | `tests/functions/hebar/referee_test.aipl` |
| `2` | `std/hebar/referee.aipl` | `hebarEnqueueAction` | `pub fn hebarEnqueueAction(mut referee: HebarReferee, action: HebarActionRecord, currentTimestampMs: int): bool:` | `tests/functions/hebar/referee_test.aipl` |
| `3` | `std/hebar/referee.aipl` | `hebarPopReadyActions` | `pub fn hebarPopReadyActions(mut referee: HebarReferee, currentTimestampMs: int): [HebarActionRecord]:` | `tests/functions/hebar/referee_test.aipl` |
| `4` | `std/hebar/referee.aipl` | `hebarIsWithinApmLimit` | `pub fn hebarIsWithinApmLimit(actionsInWindow: int, windowDurationMs: int, maxApm: int = 900): bool:` | `tests/functions/hebar/referee_test.aipl` |
| `5` | `std/hebar/referee.aipl` | `hebarClampReactionDelayMs` | `pub fn hebarClampReactionDelayMs(delayMs: int, minMs: int = 150, maxMs: int = 250): int:` | `tests/functions/hebar/referee_test.aipl` |
| `6` | `std/hebar/referee.aipl` | `hebarStepCursorTrajectory` | `pub fn hebarStepCursorTrajectory(currentPos: Vec2, targetPos: Vec2, maxSpeedPxPerSec: float = 780.0, dtSec: float = 0.016667): Vec2:` | `tests/functions/hebar/referee_test.aipl` |
| `7` | `std/hebar/referee.aipl` | `hebarClampAngularSlew` | `pub fn hebarClampAngularSlew(currentAngleRad: float, targetAngleRad: float, maxSlewRadPerSec: float = 6.283185307179586, dtSec: float = 0.016667): float:` | `tests/functions/hebar/referee_test.aipl` |
| `8` | `std/hebar/referee.aipl` | `hebarVerifyZeroTampering` | `pub fn hebarVerifyZeroTampering(referee: HebarReferee, directMemoryWrites: int = 0): bool:` | `tests/functions/hebar/referee_test.aipl` |
| `9` | `std/hebar/referee.aipl` | `connectTargetWindow` | `pub fn connectTargetWindow(titleOrPid: str, timeoutMs: int = 3000): int:` | `tests/functions/hebar/referee_test.aipl` |
| `10` | `std/hebar/referee.aipl` | `renderHebarRefereeDashboard` | `pub fn renderHebarRefereeDashboard(referee: HebarReferee, x: float, y: float, w: float, h: float): void:` | `tests/functions/hebar/referee_test.aipl` |
| `11` | `std/hebar/referee.aipl` | `exportHebarTelemetryJson` | `pub fn exportHebarTelemetryJson(referee: HebarReferee, filePath: str): bool:` | `tests/functions/hebar/referee_test.aipl` |
| `12` | `std/hebar/referee.aipl` | `hebarQuantizeFloat` | `pub fn hebarQuantizeFloat(val: float): int:` | `tests/functions/hebar/referee_test.aipl` |
| `13` | `std/hebar/referee.aipl` | `hebarHashInt` | `pub fn hebarHashInt(hashState: int, value: int): int:` | `tests/functions/hebar/referee_test.aipl` |
| `14` | `std/hebar/referee.aipl` | `hebarHashFloat` | `pub fn hebarHashFloat(hashState: int, value: float): int:` | `tests/functions/hebar/referee_test.aipl` |
| `15` | `std/hebar/referee.aipl` | `hebarVerifyDeterminism` | `pub fn hebarVerifyDeterminism(hashesA: [int], hashesB: [int]): bool:` | `tests/functions/hebar/referee_test.aipl` |
| `16` | `std/hebar/referee.aipl` | `hebarStepDamageTrail` | `pub fn hebarStepDamageTrail(trailHp: float, currentHp: float, drainSpeed: float, dt: float): float:` | `tests/functions/hebar/referee_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### 5-Bound Biological Fairness Verification (`std/hebar/referee.aipl`)

```aipl
module tests.functions.hebar.referee_doc_test
import { Vec2 } from "std/math/vec_math"
import { hebarRefereeNew, hebarClampReactionDelayMs, hebarIsWithinApmLimit, hebarStepCursorTrajectory, hebarClampAngularSlew, hebarVerifyZeroTampering, hebarVerifyDeterminism } from "std/hebar/referee"
import { assert, assertEqInt } from "std/prelude"

pub fn test_hebar_referee_bounds(): int:
  let refState = hebarRefereeNew(150, 250, 900)
  assertEqInt(hebarClampReactionDelayMs(50, 150, 250), 150, "clamps below 150ms")
  assert(hebarIsWithinApmLimit(12, 1000, 900), "12 Hz within 900 APM")
  let nextPos = hebarStepCursorTrajectory(Vec2(x = 0.0, y = 0.0), Vec2(x = 500.0, y = 0.0), 780.0, 0.016667)
  assert(nextPos.x > 0.0 and nextPos.x <= 14.0, "cursor velocity clamped")
  let nextAng = hebarClampAngularSlew(0.0, 3.14159, 6.2831853, 0.016667)
  assert(nextAng > 0.0 and nextAng < 0.2, "angular slew clamped")
  assert(hebarVerifyZeroTampering(refState, 0), "zero tampering")
  assert(hebarVerifyDeterminism([101, 202], [101, 202]), "deterministic hash match")
  ret 0
```
