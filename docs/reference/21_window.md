[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 21: `window` API Reference

> Complete API reference manual for AIPL standard library domain `window` (28 callable functions & methods across ["std/window/app_loop.aipl", "std/window/clipboard.aipl", "std/window/cursor.aipl", "std/window/display.aipl", "std/window/surface.aipl", "std/window/window_mod.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `window`
- **Target Source Modules**: ["std/window/app_loop.aipl", "std/window/clipboard.aipl", "std/window/cursor.aipl", "std/window/display.aipl", "std/window/surface.aipl", "std/window/window_mod.aipl"]
- **Total Callable Functions & Methods**: 28 (plus `setWindowMode` and `getWindowMode` intrinsics in `std/gfx2d/shape2d.aipl`)
- **Total Data Types (`struct` & `enum`)**: 11
- **Dual Desktop Window Backends**:
  - **Normal Desktop Application Mode (`setWindowMode("x11")` / `"app"`, `--window-mode=x11`)**: X11 + MIT-SHM (`libXext.so.6` `XShmPutImage`) zero-copy 32-bit BGRA presentation (`examples/ex_251_desktop_system_monitor_dashboard_window.aipl`, `examples/ex_252_desktop_vector_diagram_studio_window.aipl`).
  - **Game Hardware Mode (`setWindowMode("glx")` / `"game"`, `--window-mode=glx`)**: X11 + `libGL.so.1` GLX hardware batch renderer (`glDrawArrays(GL_TRIANGLES, ...)` + `glXSwapBuffers`, `examples/ex_253_game_glx_snake_arcade_window.aipl`..`examples/ex_255_game_glx_brick_breaker_arcade_window.aipl`).
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(11 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `AppConfig` | `pub struct` | `std/window/app_loop.aipl` | `title: str`, `targetFps: int`, `fixedUpdatesPerSec: int`, `maxFrameSkip: int`, `vsync: bool` | `AppConfig(title, targetFps, fixedUpdatesPerSec, maxFrameSkip, vsync)` |
| `AppLoopState` | `pub struct` | `std/window/app_loop.aipl` | `isRunning: bool`, `frameCount: int`, `totalTimeSeconds: float`, `deltaTimeSeconds: float`, `alpha: float`, `accumulatorSeconds: float` | `AppLoopState(isRunning, frameCount, totalTimeSeconds, deltaTimeSeconds, alpha, accumulatorSeconds)` |
| `AppLifecycleHooks` | `pub struct` | `std/window/app_loop.aipl` | `onInit: int`, `onUpdate: int`, `onFixedUpdate: int`, `onDraw: int`, `onShutdown: int` | `AppLifecycleHooks(onInit, onUpdate, onFixedUpdate, onDraw, onShutdown)` |
| `ClipboardItem` | `pub struct` | `std/window/clipboard.aipl` | `mimeType: int`, `data: [int]`, `text: str` | `ClipboardItem(mimeType, data, text)` |
| `ClipboardState` | `pub struct` | `std/window/clipboard.aipl` | `items: Map[int`, `ClipboardItem]`, `changeCount: int` | `ClipboardState(items, ClipboardItem], changeCount)` |
| `CursorState` | `pub struct` | `std/window/cursor.aipl` | `mode: int`, `shape: int`, `positionX: float`, `positionY: float`, `deltaX: float`, `deltaY: float`, `isVisible: bool` | `CursorState(mode, shape, positionX, positionY, deltaX, deltaY, isVisible)` |
| `VideoMode` | `pub struct` | `std/window/display.aipl` | `width: int`, `height: int`, `refreshRateHz: int`, `bitDepth: int` | `VideoMode(width, height, refreshRateHz, bitDepth)` |
| `MonitorInfo` | `pub struct` | `std/window/display.aipl` | `id: int`, `name: str`, `isPrimary: bool`, `positionX: int`, `positionY: int`, `currentMode: VideoMode`, `supportedModes: [VideoMode]`, `dpiScale: float` | `MonitorInfo(id, name, isPrimary, positionX, positionY, currentMode, supportedModes, dpiScale)` |
| `WindowSurface` | `pub struct` | `std/window/surface.aipl` | `handle: int`, `width: int`, `height: int`, `scaleFactor: float`, `isMinimized: bool`, `isFocused: bool`, `presentMode: int`, `format: int` | `WindowSurface(handle, width, height, scaleFactor, isMinimized, isFocused, presentMode, format)` |
| `SurfaceDimensions` | `pub struct` | `std/window/surface.aipl` | `logicalWidth: int`, `logicalHeight: int`, `physicalWidth: int`, `physicalHeight: int`, `scaleFactor: float` | `SurfaceDimensions(logicalWidth, logicalHeight, physicalWidth, physicalHeight, scaleFactor)` |
| `LetterboxRect` | `pub struct` | `std/window/surface.aipl` | `x: int`, `y: int`, `width: int`, `height: int` | `LetterboxRect(x, y, width, height)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/window/app_loop.aipl` | `createAppConfig` | `pub fn createAppConfig(title: str = "AIPL Window", targetFps: int = 60, fixedUpdatesPerSec: int = 60): AppConfig:` | `tests/functions/window/app_loop_test.aipl` |
| `2` | `std/window/app_loop.aipl` | `createAppLoopState` | `pub fn createAppLoopState(config: AppConfig): AppLoopState:` | `tests/functions/window/app_loop_test.aipl` |
| `3` | `std/window/app_loop.aipl` | `clampDeltaTime` | `pub fn clampDeltaTime(dt: float, maxDt: float = 0.25): float:` | `tests/functions/window/app_loop_test.aipl` |
| `4` | `std/window/app_loop.aipl` | `calculateAlpha` | `pub fn calculateAlpha(accumulator: float, fixedDt: float): float:` | `tests/functions/window/app_loop_test.aipl` |
| `5` | `std/window/app_loop.aipl` | `stepAppLoop` | `pub fn stepAppLoop(state: AppLoopState, config: AppConfig, rawDeltaSeconds: float, hooks: AppLifecycleHooks): AppLoopState:` | `tests/functions/window/app_loop_test.aipl` |
| `6` | `std/window/app_loop.aipl` | `requestAppExit` | `pub fn requestAppExit(state: AppLoopState): AppLoopState:` | `tests/functions/window/app_loop_test.aipl` |
| `7` | `std/window/clipboard.aipl` | `createClipboardState` | `pub fn createClipboardState(): ClipboardState:` | `tests/functions/window/clipboard_test.aipl` |
| `8` | `std/window/clipboard.aipl` | `setClipboardText` | `pub fn setClipboardText(state: ClipboardState, text: str): ClipboardState:` | `tests/functions/window/clipboard_test.aipl` |
| `9` | `std/window/clipboard.aipl` | `getClipboardText` | `pub fn getClipboardText(state: ClipboardState): Option[str]:` | `tests/functions/window/clipboard_test.aipl` |
| `10` | `std/window/clipboard.aipl` | `hasClipboardText` | `pub fn hasClipboardText(state: ClipboardState): bool:` | `tests/functions/window/clipboard_test.aipl` |
| `11` | `std/window/clipboard.aipl` | `clearClipboard` | `pub fn clearClipboard(state: ClipboardState): ClipboardState:` | `tests/functions/window/clipboard_test.aipl` |
| `12` | `std/window/cursor.aipl` | `createCursorState` | `pub fn createCursorState(): CursorState:` | `tests/functions/window/cursor_test.aipl` |
| `13` | `std/window/cursor.aipl` | `setCursorShape` | `pub fn setCursorShape(state: CursorState, shape: int): CursorState:` | `tests/functions/window/cursor_test.aipl` |
| `14` | `std/window/cursor.aipl` | `setCursorMode` | `pub fn setCursorMode(state: CursorState, mode: int): CursorState:` | `tests/functions/window/cursor_test.aipl` |
| `15` | `std/window/cursor.aipl` | `updateCursorPosition` | `pub fn updateCursorPosition(state: CursorState, newX: float, newY: float): CursorState:` | `tests/functions/window/cursor_test.aipl` |
| `16` | `std/window/cursor.aipl` | `isCursorLocked` | `pub fn isCursorLocked(state: CursorState): bool:` | `tests/functions/window/cursor_test.aipl` |
| `17` | `std/window/display.aipl` | `getPrimaryMonitor` | `pub fn getPrimaryMonitor(): MonitorInfo:` | `tests/functions/window/display_test.aipl` |
| `18` | `std/window/display.aipl` | `enumerateMonitors` | `pub fn enumerateMonitors(): [MonitorInfo]:` | `tests/functions/window/display_test.aipl` |
| `19` | `std/window/display.aipl` | `absIntLocal` | `fn absIntLocal(x: int): int:` | `tests/functions/window/display_test.aipl` |
| `20` | `std/window/display.aipl` | `findClosestVideoMode` | `pub fn findClosestVideoMode(monitor: MonitorInfo, targetW: int, targetH: int, targetHz: int): VideoMode:` | `tests/functions/window/display_test.aipl` |
| `21` | `std/window/display.aipl` | `scaleLogicalToPhysical` | `pub fn scaleLogicalToPhysical(logicalPx: float, dpiScale: float): int:` | `tests/functions/window/display_test.aipl` |
| `22` | `std/window/display.aipl` | `scalePhysicalToLogical` | `pub fn scalePhysicalToLogical(physicalPx: int, dpiScale: float): float:` | `tests/functions/window/display_test.aipl` |
| `23` | `std/window/surface.aipl` | `createWindowSurface` | `pub fn createWindowSurface(title: str, width: int, height: int, presentMode: int = 2): WindowSurface:` | `tests/functions/window/surface_test.aipl` |
| `24` | `std/window/surface.aipl` | `resizeWindowSurface` | `pub fn resizeWindowSurface(surface: WindowSurface, newWidth: int, newHeight: int, scaleFactor: float): WindowSurface:` | `tests/functions/window/surface_test.aipl` |
| `25` | `std/window/surface.aipl` | `calculateSurfaceDimensions` | `pub fn calculateSurfaceDimensions(surface: WindowSurface): SurfaceDimensions:` | `tests/functions/window/surface_test.aipl` |
| `26` | `std/window/surface.aipl` | `computeLetterbox` | `pub fn computeLetterbox(surfaceWidth: int, surfaceHeight: int, targetAspect: float): LetterboxRect:` | `tests/functions/window/surface_test.aipl` |
| `27` | `std/window/surface.aipl` | `isSurfaceReady` | `pub fn isSurfaceReady(surface: WindowSurface): bool:` | `tests/functions/window/surface_test.aipl` |
| `28` | `std/window/surface.aipl` | `destroyWindowSurface` | `pub fn destroyWindowSurface(surface: WindowSurface): WindowSurface:` | `tests/functions/window/surface_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `createAppConfig` (`std/window/app_loop.aipl`)

- **Signature**: `pub fn createAppConfig(title: str = "AIPL Window", targetFps: int = 60, fixedUpdatesPerSec: int = 60): AppConfig:`
- **Import**: `import * from "std/window/app_loop"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `title: str = "AIPL Window", targetFps: int = 60, fixedUpdatesPerSec: int = 60` | **Returns**: `AppConfig`
- **Unit Test**: `tests/functions/window/app_loop_test.aipl` | **Example**: `examples/ex_131_window_app_loop_fixed_timestep_window.aipl`
- **Behavioral Summary**: Verify `createAppConfig` fixed-timestep accumulator clamping (`clampDeltaTime` spiral-of-death guard), interpolation `alpha` in `[0.0, 1.0)`, and exit flag state. Concrete nominal inputs: `title: str = "aipl_test"`, `targetFps: int = 1`, `fixedUpdatesPerSec: int = 1`; exercises core body path returning/computing `AppConfig(`.

```aipl
module tests.functions.window.app_loop_z1_test
import * from "std/window/app_loop"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_app_loop_createAppConfig_1(): int:
  let arg_title = "test"
  let edge_title = "a"
  let arg_targetFps = 2
  let edge_targetFps = 0
  let arg_fixedUpdatesPerSec = 1
  let edge_fixedUpdatesPerSec = 0
  let resNom = createAppConfig(arg_title, arg_targetFps, arg_fixedUpdatesPerSec)
  let resEdge = createAppConfig(edge_title, edge_targetFps, edge_fixedUpdatesPerSec)
  assertEqStr(resNom.title, "test", "createAppConfig nominal string matches")
  assertEqStr(resEdge.title, "a", "createAppConfig boundary string matches")
  ret 0
```

---

### `createAppLoopState` (`std/window/app_loop.aipl`)

- **Signature**: `pub fn createAppLoopState(config: AppConfig): AppLoopState:`
- **Import**: `import * from "std/window/app_loop"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `config: AppConfig` | **Returns**: `AppLoopState`
- **Unit Test**: `tests/functions/window/app_loop_test.aipl` | **Example**: `examples/ex_132_window_surface_letterbox_viewport_window.aipl`
- **Behavioral Summary**: Verify `createAppLoopState` fixed-timestep accumulator clamping (`clampDeltaTime` spiral-of-death guard), interpolation `alpha` in `[0.0, 1.0)`, and exit flag state. Concrete nominal inputs: `config: AppConfig = AppConfig(title = "aipl_test", targetFps = 1, fixedUpdatesPerSec = 1, maxFrameSkip = 64, vsync = true)`; exercises core body path returning/computing `AppLoopState(`.

```aipl
module tests.functions.window.app_loop_z2_test
import * from "std/window/app_loop"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_app_loop_createAppLoopState_2(): int:
  let arg_config = AppConfig(title = "test", targetFps = 2, fixedUpdatesPerSec = 1, maxFrameSkip = 4, vsync = true)
  let edge_config = AppConfig(title = "a", targetFps = 0, fixedUpdatesPerSec = 0, maxFrameSkip = 1, vsync = false)
  let resNom = createAppLoopState(arg_config)
  let resEdge = createAppLoopState(edge_config)
  assert(resNom.isRunning == true, "createAppLoopState nominal resNom.isRunning == true")
  assert(resEdge.isRunning == false, "createAppLoopState boundary resEdge.isRunning == false")
  ret 0
```

---

### `clampDeltaTime` (`std/window/app_loop.aipl`)

- **Signature**: `pub fn clampDeltaTime(dt: float, maxDt: float = 0.25): float:`
- **Import**: `import * from "std/window/app_loop"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dt: float, maxDt: float = 0.25` | **Returns**: `float`
- **Unit Test**: `tests/functions/window/app_loop_test.aipl` | **Example**: `examples/ex_133_window_display_multi_monitor_dpi_window.aipl`
- **Behavioral Summary**: Verify `clampDeltaTime` fixed-timestep accumulator clamping (`clampDeltaTime` spiral-of-death guard), interpolation `alpha` in `[0.0, 1.0)`, and exit flag state. Concrete nominal inputs: `dt: float = 0.016667`, `maxDt: float = 0.016667`; exercises core body path returning/computing `dt`.

```aipl
module tests.functions.window.app_loop_z3_test
import * from "std/window/app_loop"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_app_loop_clampDeltaTime_3(): int:
  let arg_dt = 2.0
  let edge_dt = 1.0
  let arg_maxDt = 2.0
  let edge_maxDt = 1.0
  let resNom = clampDeltaTime(arg_dt, arg_maxDt)
  let resEdge = clampDeltaTime(edge_dt, edge_maxDt)
  assertApproxEq(resNom, 2.0, 0.001, "clampDeltaTime nominal resNom ~= 2.0")
  assertApproxEq(resEdge, 1.0, 0.001, "clampDeltaTime boundary resEdge ~= 1.0")
  ret 0
```

---

### `calculateAlpha` (`std/window/app_loop.aipl`)

- **Signature**: `pub fn calculateAlpha(accumulator: float, fixedDt: float): float:`
- **Import**: `import * from "std/window/app_loop"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `accumulator: float, fixedDt: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/window/app_loop_test.aipl` | **Example**: `examples/ex_131_window_app_loop_fixed_timestep_window.aipl`
- **Behavioral Summary**: Verify `calculateAlpha` fixed-timestep accumulator clamping (`clampDeltaTime` spiral-of-death guard), interpolation `alpha` in `[0.0, 1.0)`, and exit flag state. Concrete nominal inputs: `accumulator: float = 1.0`, `fixedDt: float = 0.016667`; exercises core body path returning/computing `a`.

```aipl
module tests.functions.window.app_loop_z4_test
import * from "std/window/app_loop"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_app_loop_calculateAlpha_4(): int:
  let arg_accumulator = 1.0
  let edge_accumulator = 0.5
  let arg_fixedDt = 2.0
  let edge_fixedDt = 1.0
  let resNom = calculateAlpha(arg_accumulator, arg_fixedDt)
  let resEdge = calculateAlpha(edge_accumulator, edge_fixedDt)
  assertApproxEq(resNom, 0.5, 0.001, "calculateAlpha nominal resNom ~= 0.5")
  assertApproxEq(resEdge, 0.5, 0.001, "calculateAlpha boundary resEdge ~= 0.5")
  ret 0
```

---

### `stepAppLoop` (`std/window/app_loop.aipl`)

- **Signature**: `pub fn stepAppLoop(state: AppLoopState, config: AppConfig, rawDeltaSeconds: float, hooks: AppLifecycleHooks): AppLoopState:`
- **Import**: `import * from "std/window/app_loop"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: AppLoopState, config: AppConfig, rawDeltaSeconds: float, hooks: AppLifecycleHooks` | **Returns**: `AppLoopState`
- **Unit Test**: `tests/functions/window/app_loop_test.aipl` | **Example**: `examples/ex_132_window_surface_letterbox_viewport_window.aipl`
- **Behavioral Summary**: Verify `stepAppLoop` fixed-timestep accumulator clamping (`clampDeltaTime` spiral-of-death guard), interpolation `alpha` in `[0.0, 1.0)`, and exit flag state. Concrete nominal inputs: `state: AppLoopState = AppLoopState(isRunning = true, frameCount = 64, totalTimeSeconds = 1.0, deltaTimeSeconds = 1.0, alpha = 0.5, accumulatorSeconds = 1.0)`, `config: AppConfig = AppConfig(title = "aipl_test", targetFps = 1, fixedUpdatesPerSec = 1, maxFrameSkip = 64, vsync = true)`, `rawDeltaSeconds: float = 1.0`, `hooks: AppLifecycleHooks = AppLifecycleHooks(onInit = 1, onUpdate = 1, onFixedUpdate = 1, onDraw = 1, onShutdown = 1)`; exercises core body path returning/computing `AppLoopState(`.

```aipl
module tests.functions.window.app_loop_z5_test
import * from "std/window/app_loop"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_app_loop_stepAppLoop_5(): int:
  let arg_state = AppLoopState(isRunning = true, frameCount = 4, totalTimeSeconds = 1.0, deltaTimeSeconds = 1.0, alpha = 2.0, accumulatorSeconds = 1.0)
  let edge_state = AppLoopState(isRunning = false, frameCount = 1, totalTimeSeconds = 0.5, deltaTimeSeconds = 0.5, alpha = 1.0, accumulatorSeconds = 0.5)
  let arg_config = AppConfig(title = "test", targetFps = 2, fixedUpdatesPerSec = 1, maxFrameSkip = 4, vsync = true)
  let edge_config = AppConfig(title = "a", targetFps = 0, fixedUpdatesPerSec = 0, maxFrameSkip = 1, vsync = false)
  let arg_rawDeltaSeconds = 2.0
  let edge_rawDeltaSeconds = 1.0
  let arg_hooks = AppLifecycleHooks(onInit = 4, onUpdate = 4, onFixedUpdate = 4, onDraw = 4, onShutdown = 4)
  let edge_hooks = AppLifecycleHooks(onInit = 1, onUpdate = 1, onFixedUpdate = 1, onDraw = 1, onShutdown = 1)
  let resNom = stepAppLoop(arg_state, arg_config, arg_rawDeltaSeconds, arg_hooks)
  let resEdge = stepAppLoop(edge_state, edge_config, edge_rawDeltaSeconds, edge_hooks)
  assert(resNom.isRunning == true, "stepAppLoop nominal resNom.isRunning == true")
  assert(resEdge.isRunning == false, "stepAppLoop boundary resEdge.isRunning == false")
  ret 0
```

---

### `requestAppExit` (`std/window/app_loop.aipl`)

- **Signature**: `pub fn requestAppExit(state: AppLoopState): AppLoopState:`
- **Import**: `import * from "std/window/app_loop"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: AppLoopState` | **Returns**: `AppLoopState`
- **Unit Test**: `tests/functions/window/app_loop_test.aipl` | **Example**: `examples/ex_133_window_display_multi_monitor_dpi_window.aipl`
- **Behavioral Summary**: Verify `requestAppExit` fixed-timestep accumulator clamping (`clampDeltaTime` spiral-of-death guard), interpolation `alpha` in `[0.0, 1.0)`, and exit flag state. Concrete nominal inputs: `state: AppLoopState = AppLoopState(isRunning = true, frameCount = 64, totalTimeSeconds = 1.0, deltaTimeSeconds = 1.0, alpha = 0.5, accumulatorSeconds = 1.0)`; exercises core body path returning/computing `AppLoopState(`.

```aipl
module tests.functions.window.app_loop_z6_test
import * from "std/window/app_loop"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_app_loop_requestAppExit_6(): int:
  let arg_state = AppLoopState(isRunning = true, frameCount = 4, totalTimeSeconds = 1.0, deltaTimeSeconds = 1.0, alpha = 2.0, accumulatorSeconds = 1.0)
  let edge_state = AppLoopState(isRunning = false, frameCount = 1, totalTimeSeconds = 0.5, deltaTimeSeconds = 0.5, alpha = 1.0, accumulatorSeconds = 0.5)
  let resNom = requestAppExit(arg_state)
  let resEdge = requestAppExit(edge_state)
  assert(resNom.isRunning == false, "requestAppExit nominal resNom.isRunning == false")
  assert(resEdge.isRunning == false, "requestAppExit boundary resEdge.isRunning == false")
  ret 0
```

---

### `createClipboardState` (`std/window/clipboard.aipl`)

- **Signature**: `pub fn createClipboardState(): ClipboardState:`
- **Import**: `import * from "std/window/clipboard"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `ClipboardState`
- **Unit Test**: `tests/functions/window/clipboard_test.aipl` | **Example**: `examples/ex_131_window_app_loop_fixed_timestep_window.aipl`
- **Behavioral Summary**: Verify `createClipboardState` UTF-8 clipboard set, get, has-content, and clear operations. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `ClipboardState(items = m, changeCount = 0)`.

```aipl
module tests.functions.window.clipboard_z1_test
import * from "std/window/clipboard"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_clipboard_createClipboardState_1(): int:
  let resNom = createClipboardState()
  let resEdge = createClipboardState()
  assertEqInt(resNom.items.len(), 0, "createClipboardState nominal resNom.items.len() == 0")
  assertEqInt(resEdge.items.len(), 0, "createClipboardState boundary resEdge.items.len() == 0")
  ret 0
```

---

### `setClipboardText` (`std/window/clipboard.aipl`)

- **Signature**: `pub fn setClipboardText(state: ClipboardState, text: str): ClipboardState:`
- **Import**: `import * from "std/window/clipboard"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: ClipboardState, text: str` | **Returns**: `ClipboardState`
- **Unit Test**: `tests/functions/window/clipboard_test.aipl` | **Example**: `examples/ex_132_window_surface_letterbox_viewport_window.aipl`
- **Behavioral Summary**: Verify `setClipboardText` UTF-8 clipboard set, get, has-content, and clear operations. Concrete nominal inputs: `state: ClipboardState = ClipboardState(items = Map(), changeCount = 2)`, `text: str = "aipl_test"`; exercises core body path returning/computing `ClipboardState(items = m, changeCount = state.changeCount + 1)`.

```aipl
module tests.functions.window.clipboard_z2_test
import * from "std/window/clipboard"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_clipboard_setClipboardText_2(): int:
  let arg_state = ClipboardState(items = {}, changeCount = 4)
  let edge_state = ClipboardState(items = {}, changeCount = 1)
  let arg_text = "127.0.0.1"
  let edge_text = "127.0.0.1"
  let resNom = setClipboardText(arg_state, arg_text)
  let resEdge = setClipboardText(edge_state, edge_text)
  assertEqInt(resNom.items.len(), 1, "setClipboardText nominal resNom.items.len() == 1")
  assertEqInt(resEdge.items.len(), 1, "setClipboardText boundary resEdge.items.len() == 1")
  ret 0
```

---

### `getClipboardText` (`std/window/clipboard.aipl`)

- **Signature**: `pub fn getClipboardText(state: ClipboardState): Option[str]:`
- **Import**: `import * from "std/window/clipboard"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: ClipboardState` | **Returns**: `Option[str]`
- **Unit Test**: `tests/functions/window/clipboard_test.aipl` | **Example**: `examples/ex_133_window_display_multi_monitor_dpi_window.aipl`
- **Behavioral Summary**: Verify `getClipboardText` UTF-8 clipboard set, get, has-content, and clear operations. Concrete nominal inputs: `state: ClipboardState = ClipboardState(items = Map(), changeCount = 2)`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.window.clipboard_z3_test
import * from "std/window/clipboard"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_clipboard_getClipboardText_3(): int:
  let arg_state = ClipboardState(items = {}, changeCount = 4)
  let edge_state = ClipboardState(items = {}, changeCount = 1)
  let resNom = getClipboardText(arg_state)
  let resEdge = getClipboardText(edge_state)
  assert(resNom.isSome() == false, "getClipboardText nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "getClipboardText boundary resEdge.isSome() == false")
  ret 0
```

---

### `hasClipboardText` (`std/window/clipboard.aipl`)

- **Signature**: `pub fn hasClipboardText(state: ClipboardState): bool:`
- **Import**: `import * from "std/window/clipboard"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: ClipboardState` | **Returns**: `bool`
- **Unit Test**: `tests/functions/window/clipboard_test.aipl` | **Example**: `examples/ex_131_window_app_loop_fixed_timestep_window.aipl`
- **Behavioral Summary**: Verify `hasClipboardText` UTF-8 clipboard set, get, has-content, and clear operations. Concrete nominal inputs: `state: ClipboardState = ClipboardState(items = Map(), changeCount = 2)`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.window.clipboard_z4_test
import * from "std/window/clipboard"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_clipboard_hasClipboardText_4(): int:
  let arg_state = ClipboardState(items = {}, changeCount = 4)
  let edge_state = ClipboardState(items = {}, changeCount = 1)
  let resNom = hasClipboardText(arg_state)
  let resEdge = hasClipboardText(edge_state)
  assert(resNom == false, "hasClipboardText nominal resNom == false")
  assert(resEdge == false, "hasClipboardText boundary resEdge == false")
  ret 0
```

---

### `clearClipboard` (`std/window/clipboard.aipl`)

- **Signature**: `pub fn clearClipboard(state: ClipboardState): ClipboardState:`
- **Import**: `import * from "std/window/clipboard"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: ClipboardState` | **Returns**: `ClipboardState`
- **Unit Test**: `tests/functions/window/clipboard_test.aipl` | **Example**: `examples/ex_132_window_surface_letterbox_viewport_window.aipl`
- **Behavioral Summary**: Verify `clearClipboard` UTF-8 clipboard set, get, has-content, and clear operations. Concrete nominal inputs: `state: ClipboardState = ClipboardState(items = Map(), changeCount = 2)`; exercises core body path returning/computing `ClipboardState(items = m, changeCount = state.changeCount + 1)`.

```aipl
module tests.functions.window.clipboard_z5_test
import * from "std/window/clipboard"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_clipboard_clearClipboard_5(): int:
  let arg_state = ClipboardState(items = {}, changeCount = 4)
  let edge_state = ClipboardState(items = {}, changeCount = 1)
  let resNom = clearClipboard(arg_state)
  let resEdge = clearClipboard(edge_state)
  assertEqInt(resNom.items.len(), 0, "clearClipboard nominal resNom.items.len() == 0")
  assertEqInt(resEdge.items.len(), 0, "clearClipboard boundary resEdge.items.len() == 0")
  ret 0
```

---

### `createCursorState` (`std/window/cursor.aipl`)

- **Signature**: `pub fn createCursorState(): CursorState:`
- **Import**: `import * from "std/window/cursor"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `CursorState`
- **Unit Test**: `tests/functions/window/cursor_test.aipl` | **Example**: `examples/ex_133_window_display_multi_monitor_dpi_window.aipl`
- **Behavioral Summary**: Verify `createCursorState` cursor shape/visibility/grab-lock state transitions and pointer coordinate clamping. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `CursorState(`.

```aipl
module tests.functions.window.cursor_z1_test
import * from "std/window/cursor"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cursor_createCursorState_1(): int:
  let resNom = createCursorState()
  let resEdge = createCursorState()
  assertEqInt(resNom.mode, 0, "createCursorState nominal resNom.mode == 0")
  assertEqInt(resEdge.mode, 0, "createCursorState boundary resEdge.mode == 0")
  ret 0
```

---

### `setCursorShape` (`std/window/cursor.aipl`)

- **Signature**: `pub fn setCursorShape(state: CursorState, shape: int): CursorState:`
- **Import**: `import * from "std/window/cursor"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: CursorState, shape: int` | **Returns**: `CursorState`
- **Unit Test**: `tests/functions/window/cursor_test.aipl` | **Example**: `examples/ex_131_window_app_loop_fixed_timestep_window.aipl`
- **Behavioral Summary**: Verify `setCursorShape` cursor shape/visibility/grab-lock state transitions and pointer coordinate clamping. Concrete nominal inputs: `state: CursorState = CursorState(mode = 1, shape = 1, positionX = 1.0, positionY = 1.0, deltaX = 1.0, deltaY = 1.0, isVisible = true)`, `shape: int = 1`; exercises core body path returning/computing `CursorState(`.

```aipl
module tests.functions.window.cursor_z2_test
import * from "std/window/cursor"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cursor_setCursorShape_2(): int:
  let arg_state = CursorState(mode = 4, shape = 2, positionX = 1.0, positionY = 1.0, deltaX = 1.0, deltaY = 1.0, isVisible = true)
  let edge_state = CursorState(mode = 1, shape = 0, positionX = 0.5, positionY = 0.5, deltaX = 0.5, deltaY = 0.5, isVisible = false)
  let arg_shape = 2
  let edge_shape = 0
  let resNom = setCursorShape(arg_state, arg_shape)
  let resEdge = setCursorShape(edge_state, edge_shape)
  assertEqInt(resNom.mode, 4, "setCursorShape nominal resNom.mode == 4")
  assertEqInt(resEdge.mode, 1, "setCursorShape boundary resEdge.mode == 1")
  ret 0
```

---

### `setCursorMode` (`std/window/cursor.aipl`)

- **Signature**: `pub fn setCursorMode(state: CursorState, mode: int): CursorState:`
- **Import**: `import * from "std/window/cursor"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: CursorState, mode: int` | **Returns**: `CursorState`
- **Unit Test**: `tests/functions/window/cursor_test.aipl` | **Example**: `examples/ex_132_window_surface_letterbox_viewport_window.aipl`
- **Behavioral Summary**: Verify `setCursorMode` cursor shape/visibility/grab-lock state transitions and pointer coordinate clamping. Concrete nominal inputs: `state: CursorState = CursorState(mode = 1, shape = 1, positionX = 1.0, positionY = 1.0, deltaX = 1.0, deltaY = 1.0, isVisible = true)`, `mode: int = 1`; exercises core body path returning/computing `CursorState(`.

```aipl
module tests.functions.window.cursor_z3_test
import * from "std/window/cursor"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cursor_setCursorMode_3(): int:
  let arg_state = CursorState(mode = 4, shape = 2, positionX = 1.0, positionY = 1.0, deltaX = 1.0, deltaY = 1.0, isVisible = true)
  let edge_state = CursorState(mode = 1, shape = 0, positionX = 0.5, positionY = 0.5, deltaX = 0.5, deltaY = 0.5, isVisible = false)
  let arg_mode = 4
  let edge_mode = 1
  let resNom = setCursorMode(arg_state, arg_mode)
  let resEdge = setCursorMode(edge_state, edge_mode)
  assertEqInt(resNom.mode, 4, "setCursorMode nominal resNom.mode == 4")
  assertEqInt(resEdge.mode, 1, "setCursorMode boundary resEdge.mode == 1")
  ret 0
```

---

### `updateCursorPosition` (`std/window/cursor.aipl`)

- **Signature**: `pub fn updateCursorPosition(state: CursorState, newX: float, newY: float): CursorState:`
- **Import**: `import * from "std/window/cursor"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: CursorState, newX: float, newY: float` | **Returns**: `CursorState`
- **Unit Test**: `tests/functions/window/cursor_test.aipl` | **Example**: `examples/ex_133_window_display_multi_monitor_dpi_window.aipl`
- **Behavioral Summary**: Verify `updateCursorPosition` cursor shape/visibility/grab-lock state transitions and pointer coordinate clamping. Concrete nominal inputs: `state: CursorState = CursorState(mode = 1, shape = 1, positionX = 1.0, positionY = 1.0, deltaX = 1.0, deltaY = 1.0, isVisible = true)`, `newX: float = 1.0`, `newY: float = 1.0`; exercises core body path returning/computing `CursorState(`.

```aipl
module tests.functions.window.cursor_z4_test
import * from "std/window/cursor"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cursor_updateCursorPosition_4(): int:
  let arg_state = CursorState(mode = 4, shape = 2, positionX = 1.0, positionY = 1.0, deltaX = 1.0, deltaY = 1.0, isVisible = true)
  let edge_state = CursorState(mode = 1, shape = 0, positionX = 0.5, positionY = 0.5, deltaX = 0.5, deltaY = 0.5, isVisible = false)
  let arg_newX = 2.0
  let edge_newX = 1.0
  let arg_newY = 2.0
  let edge_newY = 1.0
  let resNom = updateCursorPosition(arg_state, arg_newX, arg_newY)
  let resEdge = updateCursorPosition(edge_state, edge_newX, edge_newY)
  assertEqInt(resNom.mode, 4, "updateCursorPosition nominal resNom.mode == 4")
  assertEqInt(resEdge.mode, 1, "updateCursorPosition boundary resEdge.mode == 1")
  ret 0
```

---

### `isCursorLocked` (`std/window/cursor.aipl`)

- **Signature**: `pub fn isCursorLocked(state: CursorState): bool:`
- **Import**: `import * from "std/window/cursor"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: CursorState` | **Returns**: `bool`
- **Unit Test**: `tests/functions/window/cursor_test.aipl` | **Example**: `examples/ex_131_window_app_loop_fixed_timestep_window.aipl`
- **Behavioral Summary**: Verify `isCursorLocked` cursor shape/visibility/grab-lock state transitions and pointer coordinate clamping. Concrete nominal inputs: `state: CursorState = CursorState(mode = 1, shape = 1, positionX = 1.0, positionY = 1.0, deltaX = 1.0, deltaY = 1.0, isVisible = true)`; exercises core body path returning/computing `state.mode == CURSOR_MODE_LOCKED`.

```aipl
module tests.functions.window.cursor_z5_test
import * from "std/window/cursor"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cursor_isCursorLocked_5(): int:
  let arg_state = CursorState(mode = 4, shape = 2, positionX = 1.0, positionY = 1.0, deltaX = 1.0, deltaY = 1.0, isVisible = true)
  let edge_state = CursorState(mode = 1, shape = 0, positionX = 0.5, positionY = 0.5, deltaX = 0.5, deltaY = 0.5, isVisible = false)
  let resNom = isCursorLocked(arg_state)
  let resEdge = isCursorLocked(edge_state)
  assert(resNom == false, "isCursorLocked nominal resNom == false")
  assert(resEdge == false, "isCursorLocked boundary resEdge == false")
  ret 0
```

---

### `getPrimaryMonitor` (`std/window/display.aipl`)

- **Signature**: `pub fn getPrimaryMonitor(): MonitorInfo:`
- **Import**: `import * from "std/window/display"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `MonitorInfo`
- **Unit Test**: `tests/functions/window/display_test.aipl` | **Example**: `examples/ex_132_window_surface_letterbox_viewport_window.aipl`
- **Behavioral Summary**: Verify `getPrimaryMonitor` monitor video-mode matching (`findClosestVideoMode`) and reversible HiDPI logical/physical coordinate scaling. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `MonitorInfo(`.

```aipl
module tests.functions.window.display_z1_test
import * from "std/window/display"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_display_getPrimaryMonitor_1(): int:
  let resNom = getPrimaryMonitor()
  let resEdge = getPrimaryMonitor()
  assertEqInt(resNom.id, 1, "getPrimaryMonitor nominal resNom.id == 1")
  assertEqInt(resEdge.id, 1, "getPrimaryMonitor boundary resEdge.id == 1")
  ret 0
```

---

### `enumerateMonitors` (`std/window/display.aipl`)

- **Signature**: `pub fn enumerateMonitors(): [MonitorInfo]:`
- **Import**: `import * from "std/window/display"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `[MonitorInfo]`
- **Unit Test**: `tests/functions/window/display_test.aipl` | **Example**: `examples/ex_133_window_display_multi_monitor_dpi_window.aipl`
- **Behavioral Summary**: Verify `enumerateMonitors` monitor video-mode matching (`findClosestVideoMode`) and reversible HiDPI logical/physical coordinate scaling. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `[primary]`.

```aipl
module tests.functions.window.display_z2_test
import * from "std/window/display"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_display_enumerateMonitors_2(): int:
  let resNom = enumerateMonitors()
  let resEdge = enumerateMonitors()
  assertEqInt(resNom.len(), 1, "enumerateMonitors nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "enumerateMonitors boundary resEdge.len() == 1")
  ret 0
```

---

### `absIntLocal` (`std/window/display.aipl`)

- **Signature**: `fn absIntLocal(x: int): int:`
- **Import**: `import * from "std/window/display"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/window/display_test.aipl` | **Example**: `examples/ex_131_window_app_loop_fixed_timestep_window.aipl`
- **Behavioral Summary**: Verify `absIntLocal` monitor video-mode matching (`findClosestVideoMode`) and reversible HiDPI logical/physical coordinate scaling. Concrete nominal inputs: `x: int = 1`; exercises core body path returning/computing `x`.

```aipl
module tests.functions.window.display_z3_test
import * from "std/window/display"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_display_absIntLocal_3(): int:
  let arg_x = 1
  let edge_x = 0
  let resNom = absIntLocal(arg_x)
  let resEdge = absIntLocal(edge_x)
  assertEqInt(resNom, 1, "absIntLocal nominal resNom == 1")
  assertEqInt(resEdge, 0, "absIntLocal boundary resEdge == 0")
  ret 0
```

---

### `findClosestVideoMode` (`std/window/display.aipl`)

- **Signature**: `pub fn findClosestVideoMode(monitor: MonitorInfo, targetW: int, targetH: int, targetHz: int): VideoMode:`
- **Import**: `import * from "std/window/display"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `monitor: MonitorInfo, targetW: int, targetH: int, targetHz: int` | **Returns**: `VideoMode`
- **Unit Test**: `tests/functions/window/display_test.aipl` | **Example**: `examples/ex_132_window_surface_letterbox_viewport_window.aipl`
- **Behavioral Summary**: Verify `findClosestVideoMode` monitor video-mode matching (`findClosestVideoMode`) and reversible HiDPI logical/physical coordinate scaling. Concrete nominal inputs: `monitor: MonitorInfo = MonitorInfo(id = 1, name = "aipl_test", isPrimary = true, positionX = 0, positionY = 0, currentMode = VideoMode(width = 128, height = 128, refreshRateHz = 48000, bitDepth = 1), supportedModes = [VideoMode(width = 0, height = 0, refreshRateHz = 0, bitDepth = 0)], dpiScale = 1.0)`, `targetW: int = 1`, `targetH: int = 1`, `targetHz: int = 1`; exercises core body path returning/computing `best`.

```aipl
module tests.functions.window.display_z4_test
import * from "std/window/display"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_display_findClosestVideoMode_4(): int:
  let arg_monitor = MonitorInfo(id = 1, name = "test", isPrimary = true, positionX = 4, positionY = 4, currentMode = VideoMode(width = 4, height = 4, refreshRateHz = 4, bitDepth = 4), supportedModes = [], dpiScale = 2.0)
  let edge_monitor = MonitorInfo(id = 0, name = "a", isPrimary = false, positionX = 1, positionY = 1, currentMode = VideoMode(width = 4, height = 4, refreshRateHz = 1, bitDepth = 1), supportedModes = [], dpiScale = 1.0)
  let arg_targetW = 2
  let edge_targetW = 0
  let arg_targetH = 2
  let edge_targetH = 0
  let arg_targetHz = 1
  let edge_targetHz = 0
  let resNom = findClosestVideoMode(arg_monitor, arg_targetW, arg_targetH, arg_targetHz)
  let resEdge = findClosestVideoMode(edge_monitor, edge_targetW, edge_targetH, edge_targetHz)
  assertEqInt(resNom.width, 4, "findClosestVideoMode nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "findClosestVideoMode boundary resEdge.width == 4")
  ret 0
```

---

### `scaleLogicalToPhysical` (`std/window/display.aipl`)

- **Signature**: `pub fn scaleLogicalToPhysical(logicalPx: float, dpiScale: float): int:`
- **Import**: `import * from "std/window/display"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `logicalPx: float, dpiScale: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/window/display_test.aipl` | **Example**: `examples/ex_133_window_display_multi_monitor_dpi_window.aipl`
- **Behavioral Summary**: Verify `scaleLogicalToPhysical` monitor video-mode matching (`findClosestVideoMode`) and reversible HiDPI logical/physical coordinate scaling. Concrete nominal inputs: `logicalPx: float = 1.0`, `dpiScale: float = 1.0`; exercises core body path returning/computing `int(logicalPx * scale + 0.5)`.

```aipl
module tests.functions.window.display_z5_test
import * from "std/window/display"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_display_scaleLogicalToPhysical_5(): int:
  let arg_logicalPx = 0.0
  let edge_logicalPx = 0.0
  let arg_dpiScale = 2.0
  let edge_dpiScale = 1.0
  let resNom = scaleLogicalToPhysical(arg_logicalPx, arg_dpiScale)
  let resEdge = scaleLogicalToPhysical(edge_logicalPx, edge_dpiScale)
  assertEqInt(resNom, 0, "scaleLogicalToPhysical nominal resNom == 0")
  assertEqInt(resEdge, 0, "scaleLogicalToPhysical boundary resEdge == 0")
  ret 0
```

---

### `scalePhysicalToLogical` (`std/window/display.aipl`)

- **Signature**: `pub fn scalePhysicalToLogical(physicalPx: int, dpiScale: float): float:`
- **Import**: `import * from "std/window/display"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `physicalPx: int, dpiScale: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/window/display_test.aipl` | **Example**: `examples/ex_131_window_app_loop_fixed_timestep_window.aipl`
- **Behavioral Summary**: Verify `scalePhysicalToLogical` monitor video-mode matching (`findClosestVideoMode`) and reversible HiDPI logical/physical coordinate scaling. Concrete nominal inputs: `physicalPx: int = 1`, `dpiScale: float = 1.0`; exercises core body path returning/computing `float(physicalPx) / scale`.

```aipl
module tests.functions.window.display_z6_test
import * from "std/window/display"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_display_scalePhysicalToLogical_6(): int:
  let arg_physicalPx = 1
  let edge_physicalPx = 0
  let arg_dpiScale = 2.0
  let edge_dpiScale = 1.0
  let resNom = scalePhysicalToLogical(arg_physicalPx, arg_dpiScale)
  let resEdge = scalePhysicalToLogical(edge_physicalPx, edge_dpiScale)
  assertApproxEq(resNom, 0.5, 0.001, "scalePhysicalToLogical nominal resNom ~= 0.5")
  assertApproxEq(resEdge, 0.0, 0.001, "scalePhysicalToLogical boundary resEdge ~= 0.0")
  ret 0
```

---

### `createWindowSurface` (`std/window/surface.aipl`)

- **Signature**: `pub fn createWindowSurface(title: str, width: int, height: int, presentMode: int = 2): WindowSurface:`
- **Import**: `import * from "std/window/surface"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `title: str, width: int, height: int, presentMode: int = 2` | **Returns**: `WindowSurface`
- **Unit Test**: `tests/functions/window/surface_test.aipl` | **Example**: `examples/ex_132_window_surface_letterbox_viewport_window.aipl`
- **Behavioral Summary**: Verify `createWindowSurface` framebuffer resize dimensions and 16:9 letterbox/pillarbox viewport offset & scale inside 21:9 and 4:3 containers. Concrete nominal inputs: `title: str = "aipl_test"`, `width: int = 128`, `height: int = 128`, `presentMode: int = 1`; exercises core body path returning/computing `WindowSurface(`.

```aipl
module tests.functions.window.surface_z1_test
import * from "std/window/surface"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_surface_createWindowSurface_1(): int:
  let arg_title = "test"
  let edge_title = "a"
  let arg_width = 4
  let edge_width = 1
  let arg_height = 4
  let edge_height = 1
  let arg_presentMode = 4
  let edge_presentMode = 1
  let resNom = createWindowSurface(arg_title, arg_width, arg_height, arg_presentMode)
  let resEdge = createWindowSurface(edge_title, edge_width, edge_height, edge_presentMode)
  assertEqInt(resNom.handle, 1, "createWindowSurface nominal resNom.handle == 1")
  assertEqInt(resEdge.handle, 1, "createWindowSurface boundary resEdge.handle == 1")
  ret 0
```

---

### `resizeWindowSurface` (`std/window/surface.aipl`)

- **Signature**: `pub fn resizeWindowSurface(surface: WindowSurface, newWidth: int, newHeight: int, scaleFactor: float): WindowSurface:`
- **Import**: `import * from "std/window/surface"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `surface: WindowSurface, newWidth: int, newHeight: int, scaleFactor: float` | **Returns**: `WindowSurface`
- **Unit Test**: `tests/functions/window/surface_test.aipl` | **Example**: `examples/ex_133_window_display_multi_monitor_dpi_window.aipl`
- **Behavioral Summary**: Verify `resizeWindowSurface` framebuffer resize dimensions and 16:9 letterbox/pillarbox viewport offset & scale inside 21:9 and 4:3 containers. Concrete nominal inputs: `surface: WindowSurface = WindowSurface(handle = 1, width = 128, height = 128, scaleFactor = 1.0, isMinimized = true, isFocused = true, presentMode = 1, format = 1)`, `newWidth: int = 1`, `newHeight: int = 1`, `scaleFactor: float = 1.0`; exercises core body path returning/computing `WindowSurface(`.

```aipl
module tests.functions.window.surface_z2_test
import * from "std/window/surface"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_surface_resizeWindowSurface_2(): int:
  let arg_surface = WindowSurface(handle = 0, width = 4, height = 4, scaleFactor = 2.0, isMinimized = true, isFocused = true, presentMode = 4, format = 4)
  let edge_surface = WindowSurface(handle = 0, width = 4, height = 4, scaleFactor = 1.0, isMinimized = false, isFocused = false, presentMode = 1, format = 1)
  let arg_newWidth = 4
  let edge_newWidth = 1
  let arg_newHeight = 4
  let edge_newHeight = 1
  let arg_scaleFactor = 2.0
  let edge_scaleFactor = 1.0
  let resNom = resizeWindowSurface(arg_surface, arg_newWidth, arg_newHeight, arg_scaleFactor)
  let resEdge = resizeWindowSurface(edge_surface, edge_newWidth, edge_newHeight, edge_scaleFactor)
  assertEqInt(resNom.handle, 0, "resizeWindowSurface nominal resNom.handle == 0")
  assertEqInt(resEdge.handle, 0, "resizeWindowSurface boundary resEdge.handle == 0")
  ret 0
```

---

### `calculateSurfaceDimensions` (`std/window/surface.aipl`)

- **Signature**: `pub fn calculateSurfaceDimensions(surface: WindowSurface): SurfaceDimensions:`
- **Import**: `import * from "std/window/surface"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `surface: WindowSurface` | **Returns**: `SurfaceDimensions`
- **Unit Test**: `tests/functions/window/surface_test.aipl` | **Example**: `examples/ex_131_window_app_loop_fixed_timestep_window.aipl`
- **Behavioral Summary**: Verify `calculateSurfaceDimensions` framebuffer resize dimensions and 16:9 letterbox/pillarbox viewport offset & scale inside 21:9 and 4:3 containers. Concrete nominal inputs: `surface: WindowSurface = WindowSurface(handle = 1, width = 128, height = 128, scaleFactor = 1.0, isMinimized = true, isFocused = true, presentMode = 1, format = 1)`; exercises core body path returning/computing `SurfaceDimensions(`.

```aipl
module tests.functions.window.surface_z3_test
import * from "std/window/surface"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_surface_calculateSurfaceDimensions_3(): int:
  let arg_surface = WindowSurface(handle = 0, width = 4, height = 4, scaleFactor = 2.0, isMinimized = true, isFocused = true, presentMode = 4, format = 4)
  let edge_surface = WindowSurface(handle = 0, width = 4, height = 4, scaleFactor = 1.0, isMinimized = false, isFocused = false, presentMode = 1, format = 1)
  let resNom = calculateSurfaceDimensions(arg_surface)
  let resEdge = calculateSurfaceDimensions(edge_surface)
  assertEqInt(resNom.logicalWidth, 2, "calculateSurfaceDimensions nominal resNom.logicalWidth == 2")
  assertEqInt(resEdge.logicalWidth, 4, "calculateSurfaceDimensions boundary resEdge.logicalWidth == 4")
  ret 0
```

---

### `computeLetterbox` (`std/window/surface.aipl`)

- **Signature**: `pub fn computeLetterbox(surfaceWidth: int, surfaceHeight: int, targetAspect: float): LetterboxRect:`
- **Import**: `import * from "std/window/surface"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `surfaceWidth: int, surfaceHeight: int, targetAspect: float` | **Returns**: `LetterboxRect`
- **Unit Test**: `tests/functions/window/surface_test.aipl` | **Example**: `examples/ex_132_window_surface_letterbox_viewport_window.aipl`
- **Behavioral Summary**: Verify `computeLetterbox` framebuffer resize dimensions and 16:9 letterbox/pillarbox viewport offset & scale inside 21:9 and 4:3 containers. Concrete nominal inputs: `surfaceWidth: int = 1`, `surfaceHeight: int = 1`, `targetAspect: float = 1.0`; exercises core body path returning/computing `LetterboxRect(x = 0, y = offY, width = viewW, height = viewH)`.

```aipl
module tests.functions.window.surface_z4_test
import * from "std/window/surface"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_surface_computeLetterbox_4(): int:
  let arg_surfaceWidth = 4
  let edge_surfaceWidth = 1
  let arg_surfaceHeight = 4
  let edge_surfaceHeight = 1
  let arg_targetAspect = 1.0
  let edge_targetAspect = 0.5
  let resNom = computeLetterbox(arg_surfaceWidth, arg_surfaceHeight, arg_targetAspect)
  let resEdge = computeLetterbox(edge_surfaceWidth, edge_surfaceHeight, edge_targetAspect)
  assertEqInt(resNom.x, 0, "computeLetterbox nominal resNom.x == 0")
  assertEqInt(resEdge.x, 0, "computeLetterbox boundary resEdge.x == 0")
  ret 0
```

---

### `isSurfaceReady` (`std/window/surface.aipl`)

- **Signature**: `pub fn isSurfaceReady(surface: WindowSurface): bool:`
- **Import**: `import * from "std/window/surface"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `surface: WindowSurface` | **Returns**: `bool`
- **Unit Test**: `tests/functions/window/surface_test.aipl` | **Example**: `examples/ex_133_window_display_multi_monitor_dpi_window.aipl`
- **Behavioral Summary**: Verify `isSurfaceReady` framebuffer resize dimensions and 16:9 letterbox/pillarbox viewport offset & scale inside 21:9 and 4:3 containers. Concrete nominal inputs: `surface: WindowSurface = WindowSurface(handle = 1, width = 128, height = 128, scaleFactor = 1.0, isMinimized = true, isFocused = true, presentMode = 1, format = 1)`; exercises core body path returning/computing `surface.handle > 0 and not surface.isMinimized and surface.width > 0 and surface.height > 0`.

```aipl
module tests.functions.window.surface_z5_test
import * from "std/window/surface"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_surface_isSurfaceReady_5(): int:
  let arg_surface = WindowSurface(handle = 0, width = 4, height = 4, scaleFactor = 2.0, isMinimized = true, isFocused = true, presentMode = 4, format = 4)
  let edge_surface = WindowSurface(handle = 0, width = 4, height = 4, scaleFactor = 1.0, isMinimized = false, isFocused = false, presentMode = 1, format = 1)
  let resNom = isSurfaceReady(arg_surface)
  let resEdge = isSurfaceReady(edge_surface)
  assert(resNom == false, "isSurfaceReady nominal resNom == false")
  assert(resEdge == false, "isSurfaceReady boundary resEdge == false")
  ret 0
```

---

### `destroyWindowSurface` (`std/window/surface.aipl`)

- **Signature**: `pub fn destroyWindowSurface(surface: WindowSurface): WindowSurface:`
- **Import**: `import * from "std/window/surface"` (or barrel `import * from "std/window/window_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `surface: WindowSurface` | **Returns**: `WindowSurface`
- **Unit Test**: `tests/functions/window/surface_test.aipl` | **Example**: `examples/ex_131_window_app_loop_fixed_timestep_window.aipl`
- **Behavioral Summary**: Verify `destroyWindowSurface` framebuffer resize dimensions and 16:9 letterbox/pillarbox viewport offset & scale inside 21:9 and 4:3 containers. Concrete nominal inputs: `surface: WindowSurface = WindowSurface(handle = 1, width = 128, height = 128, scaleFactor = 1.0, isMinimized = true, isFocused = true, presentMode = 1, format = 1)`; exercises core body path returning/computing `WindowSurface(`.

```aipl
module tests.functions.window.surface_z6_test
import * from "std/window/surface"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_surface_destroyWindowSurface_6(): int:
  let arg_surface = WindowSurface(handle = 0, width = 4, height = 4, scaleFactor = 2.0, isMinimized = true, isFocused = true, presentMode = 4, format = 4)
  let edge_surface = WindowSurface(handle = 0, width = 4, height = 4, scaleFactor = 1.0, isMinimized = false, isFocused = false, presentMode = 1, format = 1)
  let resNom = destroyWindowSurface(arg_surface)
  let resEdge = destroyWindowSurface(edge_surface)
  assertEqInt(resNom.handle, 0, "destroyWindowSurface nominal resNom.handle == 0")
  assertEqInt(resEdge.handle, 0, "destroyWindowSurface boundary resEdge.handle == 0")
  ret 0
```
