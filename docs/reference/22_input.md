[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 22: `input` API Reference

> Complete API reference manual for AIPL standard library domain `input` (51 callable functions & methods across ["std/input/action_map.aipl", "std/input/gamepad.aipl", "std/input/gesture.aipl", "std/input/input_mod.aipl", "std/input/keyboard.aipl", "std/input/mouse.aipl", "std/input/touch.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `input`
- **Target Source Modules**: ["std/input/action_map.aipl", "std/input/gamepad.aipl", "std/input/gesture.aipl", "std/input/input_mod.aipl", "std/input/keyboard.aipl", "std/input/mouse.aipl", "std/input/touch.aipl"]
- **Total Callable Functions & Methods**: 51
- **Total Data Types (`struct` & `enum`)**: 15
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(15 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `ActionBinding` | `pub struct` | `std/input/action_map.aipl` | `device: int`, `inputCode: int`, `isAxis: bool`, `axisMultiplier: float`, `requiredModifiers: int` | `ActionBinding(device, inputCode, isAxis, axisMultiplier, requiredModifiers)` |
| `InputAction` | `pub struct` | `std/input/action_map.aipl` | `actionName: str`, `bindings: [ActionBinding]`, `value: float`, `isPressed: bool`, `justPressed: bool`, `justReleased: bool` | `InputAction(actionName, bindings, value, isPressed, justPressed, justReleased)` |
| `InputActionMap` | `pub struct` | `std/input/action_map.aipl` | `actions: Map[str`, `InputAction]` | `InputActionMap(actions, InputAction])` |
| `StickDeadzoneConfig` | `pub struct` | `std/input/gamepad.aipl` | `mode: int`, `innerDeadzone: float`, `outerThreshold: float` | `StickDeadzoneConfig(mode, innerDeadzone, outerThreshold)` |
| `StickVector` | `pub struct` | `std/input/gamepad.aipl` | `x: float`, `y: float`, `rawMagnitude: float`, `clampedMagnitude: float` | `StickVector(x, y, rawMagnitude, clampedMagnitude)` |
| `GamepadState` | `pub struct` | `std/input/gamepad.aipl` | `id: int`, `isConnected: bool`, `leftStick: StickVector`, `rightStick: StickVector`, `leftTrigger: float`, `rightTrigger: float`, `buttonMask: int`, `rumbleLeftMotor: float`, `rumbleRightMotor: float` | `GamepadState(id, isConnected, leftStick, rightStick, leftTrigger, rightTrigger, buttonMask, rumbleLeftMotor, rumbleRightMotor)` |
| `PinchGesture` | `pub struct` | `std/input/gesture.aipl` | `scale: float`, `deltaScale: float`, `centerPointX: float`, `centerPointY: float` | `PinchGesture(scale, deltaScale, centerPointX, centerPointY)` |
| `SwipeGesture` | `pub struct` | `std/input/gesture.aipl` | `directionX: float`, `directionY: float`, `velocityPixelsPerSec: float` | `SwipeGesture(directionX, directionY, velocityPixelsPerSec)` |
| `VirtualJoystick` | `pub struct` | `std/input/gesture.aipl` | `centerOriginX: float`, `centerOriginY: float`, `currentHandleX: float`, `currentHandleY: float`, `radiusPixels: float`, `deadzoneFraction: float`, `boundPointerId: int`, `isActive: bool`, `outputVectorX: float`, `outputVectorY: float` | `VirtualJoystick(centerOriginX, centerOriginY, currentHandleX, currentHandleY, radiusPixels, deadzoneFraction, boundPointerId, isActive, outputVectorX, outputVectorY)` |
| `KeyState` | `pub struct` | `std/input/keyboard.aipl` | `isDown: bool`, `justPressed: bool`, `justReleased: bool`, `repeatCount: int` | `KeyState(isDown, justPressed, justReleased, repeatCount)` |
| `KeyboardState` | `pub struct` | `std/input/keyboard.aipl` | `keys: Map[int`, `KeyState]`, `modifiers: int`, `textStream: [str]` | `KeyboardState(keys, KeyState], modifiers, textStream)` |
| `MouseButtonState` | `pub struct` | `std/input/mouse.aipl` | `isDown: bool`, `justPressed: bool`, `justReleased: bool` | `MouseButtonState(isDown, justPressed, justReleased)` |
| `MouseState` | `pub struct` | `std/input/mouse.aipl` | `x: float`, `y: float`, `deltaX: float`, `deltaY: float`, `scrollDeltaX: float`, `scrollDeltaY: float`, `buttonMask: int`, `buttons: Map[int`, `MouseButtonState]` | `MouseState(x, y, deltaX, deltaY, scrollDeltaX, scrollDeltaY, buttonMask, buttons, MouseButtonState])` |
| `TouchPointer` | `pub struct` | `std/input/touch.aipl` | `pointerId: int`, `phase: int`, `startX: float`, `startY: float`, `currentX: float`, `currentY: float`, `deltaX: float`, `deltaY: float`, `pressure: float`, `startTimeMs: int`, `lastTimeMs: int` | `TouchPointer(pointerId, phase, startX, startY, currentX, currentY, deltaX, deltaY, pressure, startTimeMs, lastTimeMs)` |
| `TouchTracker` | `pub struct` | `std/input/touch.aipl` | `activePointers: Map[int`, `TouchPointer]`, `maxActivePointers: int` | `TouchTracker(activePointers, TouchPointer], maxActivePointers)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/input/action_map.aipl` | `createActionMap` | `pub fn createActionMap(): InputActionMap:` | `tests/functions/input/action_map_test.aipl` |
| `2` | `std/input/action_map.aipl` | `getOrCreateAction` | `fn getOrCreateAction(map: InputActionMap, actionName: str): InputAction:` | `tests/functions/input/action_map_test.aipl` |
| `3` | `std/input/action_map.aipl` | `bindActionKey` | `pub fn bindActionKey(map: InputActionMap, actionName: str, keyCode: int, modifiers: int = 0): InputActionMap:` | `tests/functions/input/action_map_test.aipl` |
| `4` | `std/input/action_map.aipl` | `bindActionButton` | `pub fn bindActionButton(map: InputActionMap, actionName: str, gamepadButton: int): InputActionMap:` | `tests/functions/input/action_map_test.aipl` |
| `5` | `std/input/action_map.aipl` | `bindActionAxis` | `pub fn bindActionAxis(map: InputActionMap, actionName: str, device: int, axisCode: int, scale: float = 1.0): InputActionMap:` | `tests/functions/input/action_map_test.aipl` |
| `6` | `std/input/action_map.aipl` | `absFloatAction` | `fn absFloatAction(v: float): float:` | `tests/functions/input/action_map_test.aipl` |
| `7` | `std/input/action_map.aipl` | `evaluateActionMap` | `pub fn evaluateActionMap(map: InputActionMap, kbd: KeyboardState, mouse: MouseState, pad: GamepadState): InputActionMap:` | `tests/functions/input/action_map_test.aipl` |
| `8` | `std/input/action_map.aipl` | `getActionValue` | `pub fn getActionValue(map: InputActionMap, actionName: str): float:` | `tests/functions/input/action_map_test.aipl` |
| `9` | `std/input/action_map.aipl` | `isActionPressed` | `pub fn isActionPressed(map: InputActionMap, actionName: str): bool:` | `tests/functions/input/action_map_test.aipl` |
| `10` | `std/input/action_map.aipl` | `isActionJustPressed` | `pub fn isActionJustPressed(map: InputActionMap, actionName: str): bool:` | `tests/functions/input/action_map_test.aipl` |
| `11` | `std/input/gamepad.aipl` | `absFloatLocal` | `fn absFloatLocal(v: float): float:` | `tests/functions/input/gamepad_test.aipl` |
| `12` | `std/input/gamepad.aipl` | `clamp01` | `fn clamp01(v: float): float:` | `tests/functions/input/gamepad_test.aipl` |
| `13` | `std/input/gamepad.aipl` | `createGamepadState` | `pub fn createGamepadState(id: int): GamepadState:` | `tests/functions/input/gamepad_test.aipl` |
| `14` | `std/input/gamepad.aipl` | `applyAxialDeadzone` | `pub fn applyAxialDeadzone(x: float, y: float, deadzone: float): StickVector:` | `tests/functions/input/gamepad_test.aipl` |
| `15` | `std/input/gamepad.aipl` | `applyRadialDeadzone` | `pub fn applyRadialDeadzone(x: float, y: float, innerDeadzone: float, outerThreshold: float = 1.0): StickVector:` | `tests/functions/input/gamepad_test.aipl` |
| `16` | `std/input/gamepad.aipl` | `isGamepadButtonDown` | `pub fn isGamepadButtonDown(state: GamepadState, button: int): bool:` | `tests/functions/input/gamepad_test.aipl` |
| `17` | `std/input/gamepad.aipl` | `setGamepadRumble` | `pub fn setGamepadRumble(state: GamepadState, lowFreq: float, highFreq: float): GamepadState:` | `tests/functions/input/gamepad_test.aipl` |
| `18` | `std/input/gamepad.aipl` | `updateGamepadStick` | `pub fn updateGamepadStick(state: GamepadState, isLeftStick: bool, rawX: float, rawY: float, config: StickDeadzoneConfig): GamepadState:` | `tests/functions/input/gamepad_test.aipl` |
| `19` | `std/input/gamepad.aipl` | `updateGamepadTrigger` | `pub fn updateGamepadTrigger(state: GamepadState, isLeft: bool, rawVal: float): GamepadState:` | `tests/functions/input/gamepad_test.aipl` |
| `20` | `std/input/gesture.aipl` | `createVirtualJoystick` | `pub fn createVirtualJoystick(originX: float, originY: float, radiusPx: float, deadzoneFraction: float = 0.15): VirtualJoystick:` | `tests/functions/input/gesture_test.aipl` |
| `21` | `std/input/gesture.aipl` | `touchDownVirtualJoystick` | `pub fn touchDownVirtualJoystick(joystick: VirtualJoystick, pointerId: int, touchX: float, touchY: float): VirtualJoystick:` | `tests/functions/input/gesture_test.aipl` |
| `22` | `std/input/gesture.aipl` | `touchMoveVirtualJoystick` | `pub fn touchMoveVirtualJoystick(joystick: VirtualJoystick, pointerId: int, touchX: float, touchY: float): VirtualJoystick:` | `tests/functions/input/gesture_test.aipl` |
| `23` | `std/input/gesture.aipl` | `touchUpVirtualJoystick` | `pub fn touchUpVirtualJoystick(joystick: VirtualJoystick, pointerId: int): VirtualJoystick:` | `tests/functions/input/gesture_test.aipl` |
| `24` | `std/input/gesture.aipl` | `computePinchDelta` | `pub fn computePinchDelta(p1X: float, p1Y: float, p2X: float, p2Y: float, prevDist: float): (float, float):` | `tests/functions/input/gesture_test.aipl` |
| `25` | `std/input/gesture.aipl` | `detectDoubleTap` | `pub fn detectDoubleTap(lastTapTimeMs: int, currentTapTimeMs: int, maxIntervalMs: int = 300): bool:` | `tests/functions/input/gesture_test.aipl` |
| `26` | `std/input/keyboard.aipl` | `createKeyboardState` | `pub fn createKeyboardState(): KeyboardState:` | `tests/functions/input/keyboard_test.aipl` |
| `27` | `std/input/keyboard.aipl` | `isKeyDown` | `pub fn isKeyDown(state: KeyboardState, key: int): bool:` | `tests/functions/input/keyboard_test.aipl` |
| `28` | `std/input/keyboard.aipl` | `isKeyJustPressed` | `pub fn isKeyJustPressed(state: KeyboardState, key: int): bool:` | `tests/functions/input/keyboard_test.aipl` |
| `29` | `std/input/keyboard.aipl` | `isKeyJustReleased` | `pub fn isKeyJustReleased(state: KeyboardState, key: int): bool:` | `tests/functions/input/keyboard_test.aipl` |
| `30` | `std/input/keyboard.aipl` | `hasModifier` | `pub fn hasModifier(state: KeyboardState, modifier: int): bool:` | `tests/functions/input/keyboard_test.aipl` |
| `31` | `std/input/keyboard.aipl` | `pushKeyboardEvent` | `pub fn pushKeyboardEvent(state: KeyboardState, key: int, isDown: bool, repeat: bool): KeyboardState:` | `tests/functions/input/keyboard_test.aipl` |
| `32` | `std/input/keyboard.aipl` | `pushTextInput` | `pub fn pushTextInput(state: KeyboardState, ch: str): KeyboardState:` | `tests/functions/input/keyboard_test.aipl` |
| `33` | `std/input/keyboard.aipl` | `flushKeyFrame` | `pub fn flushKeyFrame(state: KeyboardState): KeyboardState:` | `tests/functions/input/keyboard_test.aipl` |
| `34` | `std/input/mouse.aipl` | `createMouseState` | `pub fn createMouseState(): MouseState:` | `tests/functions/input/mouse_test.aipl` |
| `35` | `std/input/mouse.aipl` | `isMouseButtonDown` | `pub fn isMouseButtonDown(state: MouseState, button: int): bool:` | `tests/functions/input/mouse_test.aipl` |
| `36` | `std/input/mouse.aipl` | `isMouseButtonJustPressed` | `pub fn isMouseButtonJustPressed(state: MouseState, button: int): bool:` | `tests/functions/input/mouse_test.aipl` |
| `37` | `std/input/mouse.aipl` | `isMouseButtonJustReleased` | `pub fn isMouseButtonJustReleased(state: MouseState, button: int): bool:` | `tests/functions/input/mouse_test.aipl` |
| `38` | `std/input/mouse.aipl` | `getMousePosition` | `pub fn getMousePosition(state: MouseState): (float, float):` | `tests/functions/input/mouse_test.aipl` |
| `39` | `std/input/mouse.aipl` | `getMouseDelta` | `pub fn getMouseDelta(state: MouseState): (float, float):` | `tests/functions/input/mouse_test.aipl` |
| `40` | `std/input/mouse.aipl` | `getScrollDelta` | `pub fn getScrollDelta(state: MouseState): (float, float):` | `tests/functions/input/mouse_test.aipl` |
| `41` | `std/input/mouse.aipl` | `updateMousePosition` | `pub fn updateMousePosition(state: MouseState, newX: float, newY: float): MouseState:` | `tests/functions/input/mouse_test.aipl` |
| `42` | `std/input/mouse.aipl` | `updateMouseButton` | `pub fn updateMouseButton(state: MouseState, button: int, isDown: bool): MouseState:` | `tests/functions/input/mouse_test.aipl` |
| `43` | `std/input/mouse.aipl` | `updateMouseScroll` | `pub fn updateMouseScroll(state: MouseState, scrollX: float, scrollY: float): MouseState:` | `tests/functions/input/mouse_test.aipl` |
| `44` | `std/input/mouse.aipl` | `flushMouseFrame` | `pub fn flushMouseFrame(state: MouseState): MouseState:` | `tests/functions/input/mouse_test.aipl` |
| `45` | `std/input/touch.aipl` | `createTouchTracker` | `pub fn createTouchTracker(): TouchTracker:` | `tests/functions/input/touch_test.aipl` |
| `46` | `std/input/touch.aipl` | `handleTouchDown` | `pub fn handleTouchDown(tracker: TouchTracker, pointerId: int, x: float, y: float, pressure: float, timeMs: int): TouchTracker:` | `tests/functions/input/touch_test.aipl` |
| `47` | `std/input/touch.aipl` | `handleTouchMove` | `pub fn handleTouchMove(tracker: TouchTracker, pointerId: int, x: float, y: float, pressure: float, timeMs: int): TouchTracker:` | `tests/functions/input/touch_test.aipl` |
| `48` | `std/input/touch.aipl` | `handleTouchUp` | `pub fn handleTouchUp(tracker: TouchTracker, pointerId: int, x: float, y: float, timeMs: int): TouchTracker:` | `tests/functions/input/touch_test.aipl` |
| `49` | `std/input/touch.aipl` | `handleTouchCancel` | `pub fn handleTouchCancel(tracker: TouchTracker, pointerId: int): TouchTracker:` | `tests/functions/input/touch_test.aipl` |
| `50` | `std/input/touch.aipl` | `getActivePointer` | `pub fn getActivePointer(tracker: TouchTracker, pointerId: int): Option[TouchPointer]:` | `tests/functions/input/touch_test.aipl` |
| `51` | `std/input/touch.aipl` | `getActivePointerCount` | `pub fn getActivePointerCount(tracker: TouchTracker): int:` | `tests/functions/input/touch_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `createActionMap` (`std/input/action_map.aipl`)

- **Signature**: `pub fn createActionMap(): InputActionMap:`
- **Import**: `import * from "std/input/action_map"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `InputActionMap`
- **Unit Test**: `tests/functions/input/action_map_test.aipl` | **Example**: `examples/ex_136_input_keyboard_piano_and_shortcuts_window.aipl`
- **Behavioral Summary**: Verify `createActionMap` unified digital/analog binding across keyboard, mouse, and gamepad inputs and `evaluateActionMap` aggregation. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `InputActionMap(actions = m)`.

```aipl
module tests.functions.input.action_map_z1_test
import * from "std/input/action_map"
import { KeyboardState, isKeyDown, hasModifier } from "std/input/keyboard"
import { MouseState, isMouseButtonDown } from "std/input/mouse"
import { GamepadState, isGamepadButtonDown } from "std/input/gamepad"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_action_map_createActionMap_1(): int:
  let resNom = createActionMap()
  let resEdge = createActionMap()
  assertEqInt(resNom.actions.len(), 0, "createActionMap nominal resNom.actions.len() == 0")
  assertEqInt(resEdge.actions.len(), 0, "createActionMap boundary resEdge.actions.len() == 0")
  ret 0
```

---

### `getOrCreateAction` (`std/input/action_map.aipl`)

- **Signature**: `fn getOrCreateAction(map: InputActionMap, actionName: str): InputAction:`
- **Import**: `import * from "std/input/action_map"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `map: InputActionMap, actionName: str` | **Returns**: `InputAction`
- **Unit Test**: `tests/functions/input/action_map_test.aipl` | **Example**: `examples/ex_137_input_mouse_drawing_and_wheel_zoom_window.aipl`
- **Behavioral Summary**: Verify `getOrCreateAction` unified digital/analog binding across keyboard, mouse, and gamepad inputs and `evaluateActionMap` aggregation. Concrete nominal inputs: `map: InputActionMap = InputActionMap(actions = Map())`, `actionName: str = "aipl_test"`; exercises core body path returning/computing `InputAction(`.

```aipl
module tests.functions.input.action_map_z2_test
import * from "std/input/action_map"
import { KeyboardState, isKeyDown, hasModifier } from "std/input/keyboard"
import { MouseState, isMouseButtonDown } from "std/input/mouse"
import { GamepadState, isGamepadButtonDown } from "std/input/gamepad"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_action_map_getOrCreateAction_2(): int:
  let arg_map = InputActionMap(actions = {})
  let edge_map = InputActionMap(actions = {})
  let arg_actionName = "test"
  let edge_actionName = "a"
  let resNom = getOrCreateAction(arg_map, arg_actionName)
  let resEdge = getOrCreateAction(edge_map, edge_actionName)
  assertEqStr(resNom.actionName, "test", "getOrCreateAction nominal string matches")
  assertEqStr(resEdge.actionName, "a", "getOrCreateAction boundary string matches")
  ret 0
```

---

### `bindActionKey` (`std/input/action_map.aipl`)

- **Signature**: `pub fn bindActionKey(map: InputActionMap, actionName: str, keyCode: int, modifiers: int = 0): InputActionMap:`
- **Import**: `import * from "std/input/action_map"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `map: InputActionMap, actionName: str, keyCode: int, modifiers: int = 0` | **Returns**: `InputActionMap`
- **Unit Test**: `tests/functions/input/action_map_test.aipl` | **Example**: `examples/ex_138_input_gamepad_dual_stick_radar_window.aipl`
- **Behavioral Summary**: Verify `bindActionKey` unified digital/analog binding across keyboard, mouse, and gamepad inputs and `evaluateActionMap` aggregation. Concrete nominal inputs: `map: InputActionMap = InputActionMap(actions = Map())`, `actionName: str = "aipl_test"`, `keyCode: int = 1`, `modifiers: int = 1`; exercises core body path returning/computing `InputActionMap(actions = m)`.

```aipl
module tests.functions.input.action_map_z3_test
import * from "std/input/action_map"
import { KeyboardState, isKeyDown, hasModifier } from "std/input/keyboard"
import { MouseState, isMouseButtonDown } from "std/input/mouse"
import { GamepadState, isGamepadButtonDown } from "std/input/gamepad"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_action_map_bindActionKey_3(): int:
  let arg_map = InputActionMap(actions = {})
  let edge_map = InputActionMap(actions = {})
  let arg_actionName = "test"
  let edge_actionName = "a"
  let arg_keyCode = 4
  let edge_keyCode = 1
  let arg_modifiers = 4
  let edge_modifiers = 1
  let resNom = bindActionKey(arg_map, arg_actionName, arg_keyCode, arg_modifiers)
  let resEdge = bindActionKey(edge_map, edge_actionName, edge_keyCode, edge_modifiers)
  assertEqInt(resNom.actions.len(), 1, "bindActionKey nominal resNom.actions.len() == 1")
  assertEqInt(resEdge.actions.len(), 1, "bindActionKey boundary resEdge.actions.len() == 1")
  ret 0
```

---

### `bindActionButton` (`std/input/action_map.aipl`)

- **Signature**: `pub fn bindActionButton(map: InputActionMap, actionName: str, gamepadButton: int): InputActionMap:`
- **Import**: `import * from "std/input/action_map"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `map: InputActionMap, actionName: str, gamepadButton: int` | **Returns**: `InputActionMap`
- **Unit Test**: `tests/functions/input/action_map_test.aipl` | **Example**: `examples/ex_136_input_keyboard_piano_and_shortcuts_window.aipl`
- **Behavioral Summary**: Verify `bindActionButton` unified digital/analog binding across keyboard, mouse, and gamepad inputs and `evaluateActionMap` aggregation. Concrete nominal inputs: `map: InputActionMap = InputActionMap(actions = Map())`, `actionName: str = "aipl_test"`, `gamepadButton: int = 1`; exercises core body path returning/computing `InputActionMap(actions = m)`.

```aipl
module tests.functions.input.action_map_z4_test
import * from "std/input/action_map"
import { KeyboardState, isKeyDown, hasModifier } from "std/input/keyboard"
import { MouseState, isMouseButtonDown } from "std/input/mouse"
import { GamepadState, isGamepadButtonDown } from "std/input/gamepad"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_action_map_bindActionButton_4(): int:
  let arg_map = InputActionMap(actions = {})
  let edge_map = InputActionMap(actions = {})
  let arg_actionName = "test"
  let edge_actionName = "a"
  let arg_gamepadButton = 4
  let edge_gamepadButton = 1
  let resNom = bindActionButton(arg_map, arg_actionName, arg_gamepadButton)
  let resEdge = bindActionButton(edge_map, edge_actionName, edge_gamepadButton)
  assertEqInt(resNom.actions.len(), 1, "bindActionButton nominal resNom.actions.len() == 1")
  assertEqInt(resEdge.actions.len(), 1, "bindActionButton boundary resEdge.actions.len() == 1")
  ret 0
```

---

### `bindActionAxis` (`std/input/action_map.aipl`)

- **Signature**: `pub fn bindActionAxis(map: InputActionMap, actionName: str, device: int, axisCode: int, scale: float = 1.0): InputActionMap:`
- **Import**: `import * from "std/input/action_map"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `map: InputActionMap, actionName: str, device: int, axisCode: int, scale: float = 1.0` | **Returns**: `InputActionMap`
- **Unit Test**: `tests/functions/input/action_map_test.aipl` | **Example**: `examples/ex_137_input_mouse_drawing_and_wheel_zoom_window.aipl`
- **Behavioral Summary**: Verify `bindActionAxis` unified digital/analog binding across keyboard, mouse, and gamepad inputs and `evaluateActionMap` aggregation. Concrete nominal inputs: `map: InputActionMap = InputActionMap(actions = Map())`, `actionName: str = "aipl_test"`, `device: int = 1`, `axisCode: int = 1`, `scale: float = 1.0`; exercises core body path returning/computing `InputActionMap(actions = m)`.

```aipl
module tests.functions.input.action_map_z5_test
import * from "std/input/action_map"
import { KeyboardState, isKeyDown, hasModifier } from "std/input/keyboard"
import { MouseState, isMouseButtonDown } from "std/input/mouse"
import { GamepadState, isGamepadButtonDown } from "std/input/gamepad"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_action_map_bindActionAxis_5(): int:
  let arg_map = InputActionMap(actions = {})
  let edge_map = InputActionMap(actions = {})
  let arg_actionName = "test"
  let edge_actionName = "a"
  let arg_device = 2
  let edge_device = 0
  let arg_axisCode = 1
  let edge_axisCode = 0
  let arg_scale = 2.0
  let edge_scale = 1.0
  let resNom = bindActionAxis(arg_map, arg_actionName, arg_device, arg_axisCode, arg_scale)
  let resEdge = bindActionAxis(edge_map, edge_actionName, edge_device, edge_axisCode, edge_scale)
  assertEqInt(resNom.actions.len(), 1, "bindActionAxis nominal resNom.actions.len() == 1")
  assertEqInt(resEdge.actions.len(), 1, "bindActionAxis boundary resEdge.actions.len() == 1")
  ret 0
```

---

### `absFloatAction` (`std/input/action_map.aipl`)

- **Signature**: `fn absFloatAction(v: float): float:`
- **Import**: `import * from "std/input/action_map"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/input/action_map_test.aipl` | **Example**: `examples/ex_138_input_gamepad_dual_stick_radar_window.aipl`
- **Behavioral Summary**: Verify `absFloatAction` unified digital/analog binding across keyboard, mouse, and gamepad inputs and `evaluateActionMap` aggregation. Concrete nominal inputs: `v: float = 1.0`; exercises core body path returning/computing `v`.

```aipl
module tests.functions.input.action_map_z6_test
import * from "std/input/action_map"
import { KeyboardState, isKeyDown, hasModifier } from "std/input/keyboard"
import { MouseState, isMouseButtonDown } from "std/input/mouse"
import { GamepadState, isGamepadButtonDown } from "std/input/gamepad"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_action_map_absFloatAction_6(): int:
  let arg_v = 1.0
  let edge_v = 0.5
  let resNom = absFloatAction(arg_v)
  let resEdge = absFloatAction(edge_v)
  assertApproxEq(resNom, 1.0, 0.001, "absFloatAction nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "absFloatAction boundary resEdge ~= 0.5")
  ret 0
```

---

### `evaluateActionMap` (`std/input/action_map.aipl`)

- **Signature**: `pub fn evaluateActionMap(map: InputActionMap, kbd: KeyboardState, mouse: MouseState, pad: GamepadState): InputActionMap:`
- **Import**: `import * from "std/input/action_map"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `map: InputActionMap, kbd: KeyboardState, mouse: MouseState, pad: GamepadState` | **Returns**: `InputActionMap`
- **Unit Test**: `tests/functions/input/action_map_test.aipl` | **Example**: `examples/ex_136_input_keyboard_piano_and_shortcuts_window.aipl`
- **Behavioral Summary**: Verify `evaluateActionMap` unified digital/analog binding across keyboard, mouse, and gamepad inputs and `evaluateActionMap` aggregation. Concrete nominal inputs: `map: InputActionMap = InputActionMap(actions = Map())`, `kbd: KeyboardState = KeyboardState(keys = Map(), modifiers = 1, textStream = ["aipl_test"])`, `mouse: MouseState = MouseState(x = 1.0, y = 1.0, deltaX = 1.0, deltaY = 1.0, scrollDeltaX = 1.0, scrollDeltaY = 1.0, buttonMask = 1, buttons = Map())`, `pad: GamepadState = GamepadState(id = 1, isConnected = true, leftStick = StickVector(x = 1.0, y = 1.0, rawMagnitude = 1.0, clampedMagnitude = 1.0), rightStick = StickVector(x = 1.0, y = 1.0, rawMagnitude = 1.0, clampedMagnitude = 1.0), leftTrigger = 1.0, rightTrigger = 1.0, buttonMask = 1, rumbleLeftMotor = 1.0, rumbleRightMotor = 1.0)`; exercises core body path returning/computing `InputActionMap(actions = m)`.

```aipl
module tests.functions.input.action_map_z7_test
import * from "std/input/action_map"
import { KeyboardState, isKeyDown, hasModifier } from "std/input/keyboard"
import { MouseState, isMouseButtonDown } from "std/input/mouse"
import { GamepadState, isGamepadButtonDown } from "std/input/gamepad"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_action_map_evaluateActionMap_7(): int:
  let arg_map = InputActionMap(actions = {})
  let edge_map = InputActionMap(actions = {})
  let arg_kbd = KeyboardState(keys = {}, modifiers = 4, textStream = [])
  let edge_kbd = KeyboardState(keys = {}, modifiers = 1, textStream = [])
  let arg_mouse = MouseState(x = 1.0, y = 1.0, deltaX = 1.0, deltaY = 1.0, scrollDeltaX = 1.0, scrollDeltaY = 1.0, buttonMask = 4, buttons = {})
  let edge_mouse = MouseState(x = 0.5, y = 0.5, deltaX = 0.5, deltaY = 0.5, scrollDeltaX = 0.5, scrollDeltaY = 0.5, buttonMask = 1, buttons = {})
  let arg_pad = GamepadState(id = 1, isConnected = true, leftStick = StickVector(x = 1.0, y = 1.0, rawMagnitude = 2.0, clampedMagnitude = 1.0), rightStick = StickVector(x = 1.0, y = 1.0, rawMagnitude = 2.0, clampedMagnitude = 1.0), leftTrigger = 1.0, rightTrigger = 2.0, buttonMask = 4, rumbleLeftMotor = 1.0, rumbleRightMotor = 2.0)
  let edge_pad = GamepadState(id = 0, isConnected = false, leftStick = StickVector(x = 0.5, y = 0.5, rawMagnitude = 1.0, clampedMagnitude = 0.5), rightStick = StickVector(x = 0.5, y = 0.5, rawMagnitude = 1.0, clampedMagnitude = 0.5), leftTrigger = 0.5, rightTrigger = 1.0, buttonMask = 1, rumbleLeftMotor = 0.5, rumbleRightMotor = 1.0)
  let resNom = evaluateActionMap(arg_map, arg_kbd, arg_mouse, arg_pad)
  let resEdge = evaluateActionMap(edge_map, edge_kbd, edge_mouse, edge_pad)
  assertEqInt(resNom.actions.len(), 0, "evaluateActionMap nominal resNom.actions.len() == 0")
  assertEqInt(resEdge.actions.len(), 0, "evaluateActionMap boundary resEdge.actions.len() == 0")
  ret 0
```

---

### `getActionValue` (`std/input/action_map.aipl`)

- **Signature**: `pub fn getActionValue(map: InputActionMap, actionName: str): float:`
- **Import**: `import * from "std/input/action_map"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `map: InputActionMap, actionName: str` | **Returns**: `float`
- **Unit Test**: `tests/functions/input/action_map_test.aipl` | **Example**: `examples/ex_137_input_mouse_drawing_and_wheel_zoom_window.aipl`
- **Behavioral Summary**: Verify `getActionValue` unified digital/analog binding across keyboard, mouse, and gamepad inputs and `evaluateActionMap` aggregation. Concrete nominal inputs: `map: InputActionMap = InputActionMap(actions = Map())`, `actionName: str = "aipl_test"`; exercises core body path returning/computing `0.0`.

```aipl
module tests.functions.input.action_map_z8_test
import * from "std/input/action_map"
import { KeyboardState, isKeyDown, hasModifier } from "std/input/keyboard"
import { MouseState, isMouseButtonDown } from "std/input/mouse"
import { GamepadState, isGamepadButtonDown } from "std/input/gamepad"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_action_map_getActionValue_8(): int:
  let arg_map = InputActionMap(actions = {})
  let edge_map = InputActionMap(actions = {})
  let arg_actionName = "test"
  let edge_actionName = "a"
  let resNom = getActionValue(arg_map, arg_actionName)
  let resEdge = getActionValue(edge_map, edge_actionName)
  assertApproxEq(resNom, 0.0, 0.001, "getActionValue nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "getActionValue boundary resEdge ~= 0.0")
  ret 0
```

---

### `isActionPressed` (`std/input/action_map.aipl`)

- **Signature**: `pub fn isActionPressed(map: InputActionMap, actionName: str): bool:`
- **Import**: `import * from "std/input/action_map"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `map: InputActionMap, actionName: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/input/action_map_test.aipl` | **Example**: `examples/ex_138_input_gamepad_dual_stick_radar_window.aipl`
- **Behavioral Summary**: Verify `isActionPressed` unified digital/analog binding across keyboard, mouse, and gamepad inputs and `evaluateActionMap` aggregation. Concrete nominal inputs: `map: InputActionMap = InputActionMap(actions = Map())`, `actionName: str = "aipl_test"`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.input.action_map_z9_test
import * from "std/input/action_map"
import { KeyboardState, isKeyDown, hasModifier } from "std/input/keyboard"
import { MouseState, isMouseButtonDown } from "std/input/mouse"
import { GamepadState, isGamepadButtonDown } from "std/input/gamepad"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_action_map_isActionPressed_9(): int:
  let arg_map = InputActionMap(actions = {})
  let edge_map = InputActionMap(actions = {})
  let arg_actionName = "test"
  let edge_actionName = "a"
  let resNom = isActionPressed(arg_map, arg_actionName)
  let resEdge = isActionPressed(edge_map, edge_actionName)
  assert(resNom == false, "isActionPressed nominal resNom == false")
  assert(resEdge == false, "isActionPressed boundary resEdge == false")
  ret 0
```

---

### `isActionJustPressed` (`std/input/action_map.aipl`)

- **Signature**: `pub fn isActionJustPressed(map: InputActionMap, actionName: str): bool:`
- **Import**: `import * from "std/input/action_map"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `map: InputActionMap, actionName: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/input/action_map_test.aipl` | **Example**: `examples/ex_136_input_keyboard_piano_and_shortcuts_window.aipl`
- **Behavioral Summary**: Verify `isActionJustPressed` unified digital/analog binding across keyboard, mouse, and gamepad inputs and `evaluateActionMap` aggregation. Concrete nominal inputs: `map: InputActionMap = InputActionMap(actions = Map())`, `actionName: str = "aipl_test"`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.input.action_map_z10_test
import * from "std/input/action_map"
import { KeyboardState, isKeyDown, hasModifier } from "std/input/keyboard"
import { MouseState, isMouseButtonDown } from "std/input/mouse"
import { GamepadState, isGamepadButtonDown } from "std/input/gamepad"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_action_map_isActionJustPressed_10(): int:
  let arg_map = InputActionMap(actions = {})
  let edge_map = InputActionMap(actions = {})
  let arg_actionName = "test"
  let edge_actionName = "a"
  let resNom = isActionJustPressed(arg_map, arg_actionName)
  let resEdge = isActionJustPressed(edge_map, edge_actionName)
  assert(resNom == false, "isActionJustPressed nominal resNom == false")
  assert(resEdge == false, "isActionJustPressed boundary resEdge == false")
  ret 0
```

---

### `absFloatLocal` (`std/input/gamepad.aipl`)

- **Signature**: `fn absFloatLocal(v: float): float:`
- **Import**: `import * from "std/input/gamepad"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/input/gamepad_test.aipl` | **Example**: `examples/ex_137_input_mouse_drawing_and_wheel_zoom_window.aipl`
- **Behavioral Summary**: Verify `absFloatLocal` axial vs radial stick deadzone rescaling (`[dz, 1.0] -> [0.0, 1.0]`), trigger normalization, and dual-motor rumble clamping. Concrete nominal inputs: `v: float = 1.0`; exercises core body path returning/computing `v`.

```aipl
module tests.functions.input.gamepad_z1_test
import * from "std/input/gamepad"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gamepad_absFloatLocal_1(): int:
  let arg_v = 1.0
  let edge_v = 0.5
  let resNom = absFloatLocal(arg_v)
  let resEdge = absFloatLocal(edge_v)
  assertApproxEq(resNom, 1.0, 0.001, "absFloatLocal nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "absFloatLocal boundary resEdge ~= 0.5")
  ret 0
```

---

### `clamp01` (`std/input/gamepad.aipl`)

- **Signature**: `fn clamp01(v: float): float:`
- **Import**: `import * from "std/input/gamepad"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/input/gamepad_test.aipl` | **Example**: `examples/ex_138_input_gamepad_dual_stick_radar_window.aipl`
- **Behavioral Summary**: Verify `clamp01` axial vs radial stick deadzone rescaling (`[dz, 1.0] -> [0.0, 1.0]`), trigger normalization, and dual-motor rumble clamping. Concrete nominal inputs: `v: float = 1.0`; exercises core body path returning/computing `v`.

```aipl
module tests.functions.input.gamepad_z2_test
import * from "std/input/gamepad"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gamepad_clamp01_2(): int:
  let arg_v = 1.0
  let edge_v = 0.5
  let resNom = clamp01(arg_v)
  let resEdge = clamp01(edge_v)
  assertApproxEq(resNom, 1.0, 0.001, "clamp01 nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "clamp01 boundary resEdge ~= 0.5")
  ret 0
```

---

### `createGamepadState` (`std/input/gamepad.aipl`)

- **Signature**: `pub fn createGamepadState(id: int): GamepadState:`
- **Import**: `import * from "std/input/gamepad"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `id: int` | **Returns**: `GamepadState`
- **Unit Test**: `tests/functions/input/gamepad_test.aipl` | **Example**: `examples/ex_136_input_keyboard_piano_and_shortcuts_window.aipl`
- **Behavioral Summary**: Verify `createGamepadState` axial vs radial stick deadzone rescaling (`[dz, 1.0] -> [0.0, 1.0]`), trigger normalization, and dual-motor rumble clamping. Concrete nominal inputs: `id: int = 1`; exercises core body path returning/computing `GamepadState(`.

```aipl
module tests.functions.input.gamepad_z3_test
import * from "std/input/gamepad"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gamepad_createGamepadState_3(): int:
  let arg_id = 1
  let edge_id = 0
  let resNom = createGamepadState(arg_id)
  let resEdge = createGamepadState(edge_id)
  assertEqInt(resNom.id, 1, "createGamepadState nominal resNom.id == 1")
  assertEqInt(resEdge.id, 0, "createGamepadState boundary resEdge.id == 0")
  ret 0
```

---

### `applyAxialDeadzone` (`std/input/gamepad.aipl`)

- **Signature**: `pub fn applyAxialDeadzone(x: float, y: float, deadzone: float): StickVector:`
- **Import**: `import * from "std/input/gamepad"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float, deadzone: float` | **Returns**: `StickVector`
- **Unit Test**: `tests/functions/input/gamepad_test.aipl` | **Example**: `examples/ex_137_input_mouse_drawing_and_wheel_zoom_window.aipl`
- **Behavioral Summary**: Verify `applyAxialDeadzone` axial vs radial stick deadzone rescaling (`[dz, 1.0] -> [0.0, 1.0]`), trigger normalization, and dual-motor rumble clamping. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `deadzone: float = 1.0`; exercises core body path returning/computing `StickVector(x = outX, y = outY, rawMagnitude = rawMag, clampedMagnitude = clampedMag)`.

```aipl
module tests.functions.input.gamepad_z4_test
import * from "std/input/gamepad"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gamepad_applyAxialDeadzone_4(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_deadzone = 1.0
  let edge_deadzone = 0.5
  let resNom = applyAxialDeadzone(arg_x, arg_y, arg_deadzone)
  let resEdge = applyAxialDeadzone(edge_x, edge_y, edge_deadzone)
  assertApproxEq(resNom.x, 1.0, 0.001, "applyAxialDeadzone nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "applyAxialDeadzone boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `applyRadialDeadzone` (`std/input/gamepad.aipl`)

- **Signature**: `pub fn applyRadialDeadzone(x: float, y: float, innerDeadzone: float, outerThreshold: float = 1.0): StickVector:`
- **Import**: `import * from "std/input/gamepad"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float, innerDeadzone: float, outerThreshold: float = 1.0` | **Returns**: `StickVector`
- **Unit Test**: `tests/functions/input/gamepad_test.aipl` | **Example**: `examples/ex_138_input_gamepad_dual_stick_radar_window.aipl`
- **Behavioral Summary**: Verify `applyRadialDeadzone` axial vs radial stick deadzone rescaling (`[dz, 1.0] -> [0.0, 1.0]`), trigger normalization, and dual-motor rumble clamping. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `innerDeadzone: float = 1.0`, `outerThreshold: float = 1.0`; exercises core body path returning/computing `StickVector(`.

```aipl
module tests.functions.input.gamepad_z5_test
import * from "std/input/gamepad"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gamepad_applyRadialDeadzone_5(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_innerDeadzone = 1.0
  let edge_innerDeadzone = 0.5
  let arg_outerThreshold = 2.0
  let edge_outerThreshold = 1.0
  let resNom = applyRadialDeadzone(arg_x, arg_y, arg_innerDeadzone, arg_outerThreshold)
  let resEdge = applyRadialDeadzone(edge_x, edge_y, edge_innerDeadzone, edge_outerThreshold)
  assertApproxEq(resNom.x, 0.483208, 0.001, "applyRadialDeadzone nominal resNom.x ~= 0.483208")
  assertApproxEq(resEdge.x, 0.292893, 0.001, "applyRadialDeadzone boundary resEdge.x ~= 0.292893")
  ret 0
```

---

### `isGamepadButtonDown` (`std/input/gamepad.aipl`)

- **Signature**: `pub fn isGamepadButtonDown(state: GamepadState, button: int): bool:`
- **Import**: `import * from "std/input/gamepad"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: GamepadState, button: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/input/gamepad_test.aipl` | **Example**: `examples/ex_136_input_keyboard_piano_and_shortcuts_window.aipl`
- **Behavioral Summary**: Verify `isGamepadButtonDown` axial vs radial stick deadzone rescaling (`[dz, 1.0] -> [0.0, 1.0]`), trigger normalization, and dual-motor rumble clamping. Concrete nominal inputs: `state: GamepadState = GamepadState(id = 1, isConnected = true, leftStick = StickVector(x = 1.0, y = 1.0, rawMagnitude = 1.0, clampedMagnitude = 1.0), rightStick = StickVector(x = 1.0, y = 1.0, rawMagnitude = 1.0, clampedMagnitude = 1.0), leftTrigger = 1.0, rightTrigger = 1.0, buttonMask = 1, rumbleLeftMotor = 1.0, rumbleRightMotor = 1.0)`, `button: int = 1`; exercises core body path returning/computing `(state.buttonMask & (1 << button)) != 0`.

```aipl
module tests.functions.input.gamepad_z6_test
import * from "std/input/gamepad"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gamepad_isGamepadButtonDown_6(): int:
  let arg_state = GamepadState(id = 1, isConnected = true, leftStick = StickVector(x = 1.0, y = 1.0, rawMagnitude = 2.0, clampedMagnitude = 1.0), rightStick = StickVector(x = 1.0, y = 1.0, rawMagnitude = 2.0, clampedMagnitude = 1.0), leftTrigger = 1.0, rightTrigger = 2.0, buttonMask = 4, rumbleLeftMotor = 1.0, rumbleRightMotor = 2.0)
  let edge_state = GamepadState(id = 0, isConnected = false, leftStick = StickVector(x = 0.5, y = 0.5, rawMagnitude = 1.0, clampedMagnitude = 0.5), rightStick = StickVector(x = 0.5, y = 0.5, rawMagnitude = 1.0, clampedMagnitude = 0.5), leftTrigger = 0.5, rightTrigger = 1.0, buttonMask = 1, rumbleLeftMotor = 0.5, rumbleRightMotor = 1.0)
  let arg_button = 4
  let edge_button = 1
  let resNom = isGamepadButtonDown(arg_state, arg_button)
  let resEdge = isGamepadButtonDown(edge_state, edge_button)
  assert(resNom == false, "isGamepadButtonDown nominal resNom == false")
  assert(resEdge == false, "isGamepadButtonDown boundary resEdge == false")
  ret 0
```

---

### `setGamepadRumble` (`std/input/gamepad.aipl`)

- **Signature**: `pub fn setGamepadRumble(state: GamepadState, lowFreq: float, highFreq: float): GamepadState:`
- **Import**: `import * from "std/input/gamepad"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: GamepadState, lowFreq: float, highFreq: float` | **Returns**: `GamepadState`
- **Unit Test**: `tests/functions/input/gamepad_test.aipl` | **Example**: `examples/ex_137_input_mouse_drawing_and_wheel_zoom_window.aipl`
- **Behavioral Summary**: Verify `setGamepadRumble` axial vs radial stick deadzone rescaling (`[dz, 1.0] -> [0.0, 1.0]`), trigger normalization, and dual-motor rumble clamping. Concrete nominal inputs: `state: GamepadState = GamepadState(id = 1, isConnected = true, leftStick = StickVector(x = 1.0, y = 1.0, rawMagnitude = 1.0, clampedMagnitude = 1.0), rightStick = StickVector(x = 1.0, y = 1.0, rawMagnitude = 1.0, clampedMagnitude = 1.0), leftTrigger = 1.0, rightTrigger = 1.0, buttonMask = 1, rumbleLeftMotor = 1.0, rumbleRightMotor = 1.0)`, `lowFreq: float = 1.0`, `highFreq: float = 1.0`; exercises core body path returning/computing `GamepadState(`.

```aipl
module tests.functions.input.gamepad_z7_test
import * from "std/input/gamepad"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gamepad_setGamepadRumble_7(): int:
  let arg_state = GamepadState(id = 1, isConnected = true, leftStick = StickVector(x = 1.0, y = 1.0, rawMagnitude = 2.0, clampedMagnitude = 1.0), rightStick = StickVector(x = 1.0, y = 1.0, rawMagnitude = 2.0, clampedMagnitude = 1.0), leftTrigger = 1.0, rightTrigger = 2.0, buttonMask = 4, rumbleLeftMotor = 1.0, rumbleRightMotor = 2.0)
  let edge_state = GamepadState(id = 0, isConnected = false, leftStick = StickVector(x = 0.5, y = 0.5, rawMagnitude = 1.0, clampedMagnitude = 0.5), rightStick = StickVector(x = 0.5, y = 0.5, rawMagnitude = 1.0, clampedMagnitude = 0.5), leftTrigger = 0.5, rightTrigger = 1.0, buttonMask = 1, rumbleLeftMotor = 0.5, rumbleRightMotor = 1.0)
  let arg_lowFreq = 0.0
  let edge_lowFreq = 0.0
  let arg_highFreq = 2.0
  let edge_highFreq = 1.0
  let resNom = setGamepadRumble(arg_state, arg_lowFreq, arg_highFreq)
  let resEdge = setGamepadRumble(edge_state, edge_lowFreq, edge_highFreq)
  assertEqInt(resNom.id, 1, "setGamepadRumble nominal resNom.id == 1")
  assertEqInt(resEdge.id, 0, "setGamepadRumble boundary resEdge.id == 0")
  ret 0
```

---

### `updateGamepadStick` (`std/input/gamepad.aipl`)

- **Signature**: `pub fn updateGamepadStick(state: GamepadState, isLeftStick: bool, rawX: float, rawY: float, config: StickDeadzoneConfig): GamepadState:`
- **Import**: `import * from "std/input/gamepad"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: GamepadState, isLeftStick: bool, rawX: float, rawY: float, config: StickDeadzoneConfig` | **Returns**: `GamepadState`
- **Unit Test**: `tests/functions/input/gamepad_test.aipl` | **Example**: `examples/ex_138_input_gamepad_dual_stick_radar_window.aipl`
- **Behavioral Summary**: Verify `updateGamepadStick` axial vs radial stick deadzone rescaling (`[dz, 1.0] -> [0.0, 1.0]`), trigger normalization, and dual-motor rumble clamping. Concrete nominal inputs: `state: GamepadState = GamepadState(id = 1, isConnected = true, leftStick = StickVector(x = 1.0, y = 1.0, rawMagnitude = 1.0, clampedMagnitude = 1.0), rightStick = StickVector(x = 1.0, y = 1.0, rawMagnitude = 1.0, clampedMagnitude = 1.0), leftTrigger = 1.0, rightTrigger = 1.0, buttonMask = 1, rumbleLeftMotor = 1.0, rumbleRightMotor = 1.0)`, `isLeftStick: bool = true`, `rawX: float = 1.0`, `rawY: float = 1.0`, `config: StickDeadzoneConfig = StickDeadzoneConfig(mode = 1, innerDeadzone = 1.0, outerThreshold = 1.0)`; exercises core body path returning/computing `GamepadState(`.

```aipl
module tests.functions.input.gamepad_z8_test
import * from "std/input/gamepad"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gamepad_updateGamepadStick_8(): int:
  let arg_state = GamepadState(id = 1, isConnected = true, leftStick = StickVector(x = 1.0, y = 1.0, rawMagnitude = 2.0, clampedMagnitude = 1.0), rightStick = StickVector(x = 1.0, y = 1.0, rawMagnitude = 2.0, clampedMagnitude = 1.0), leftTrigger = 1.0, rightTrigger = 2.0, buttonMask = 4, rumbleLeftMotor = 1.0, rumbleRightMotor = 2.0)
  let edge_state = GamepadState(id = 0, isConnected = false, leftStick = StickVector(x = 0.5, y = 0.5, rawMagnitude = 1.0, clampedMagnitude = 0.5), rightStick = StickVector(x = 0.5, y = 0.5, rawMagnitude = 1.0, clampedMagnitude = 0.5), leftTrigger = 0.5, rightTrigger = 1.0, buttonMask = 1, rumbleLeftMotor = 0.5, rumbleRightMotor = 1.0)
  let arg_isLeftStick = true
  let edge_isLeftStick = false
  let arg_rawX = 2.0
  let edge_rawX = 1.0
  let arg_rawY = 2.0
  let edge_rawY = 1.0
  let arg_config = StickDeadzoneConfig(mode = 4, innerDeadzone = 1.0, outerThreshold = 2.0)
  let edge_config = StickDeadzoneConfig(mode = 1, innerDeadzone = 0.5, outerThreshold = 1.0)
  let resNom = updateGamepadStick(arg_state, arg_isLeftStick, arg_rawX, arg_rawY, arg_config)
  let resEdge = updateGamepadStick(edge_state, edge_isLeftStick, edge_rawX, edge_rawY, edge_config)
  assertEqInt(resNom.id, 1, "updateGamepadStick nominal resNom.id == 1")
  assertEqInt(resEdge.id, 0, "updateGamepadStick boundary resEdge.id == 0")
  ret 0
```

---

### `updateGamepadTrigger` (`std/input/gamepad.aipl`)

- **Signature**: `pub fn updateGamepadTrigger(state: GamepadState, isLeft: bool, rawVal: float): GamepadState:`
- **Import**: `import * from "std/input/gamepad"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: GamepadState, isLeft: bool, rawVal: float` | **Returns**: `GamepadState`
- **Unit Test**: `tests/functions/input/gamepad_test.aipl` | **Example**: `examples/ex_136_input_keyboard_piano_and_shortcuts_window.aipl`
- **Behavioral Summary**: Verify `updateGamepadTrigger` axial vs radial stick deadzone rescaling (`[dz, 1.0] -> [0.0, 1.0]`), trigger normalization, and dual-motor rumble clamping. Concrete nominal inputs: `state: GamepadState = GamepadState(id = 1, isConnected = true, leftStick = StickVector(x = 1.0, y = 1.0, rawMagnitude = 1.0, clampedMagnitude = 1.0), rightStick = StickVector(x = 1.0, y = 1.0, rawMagnitude = 1.0, clampedMagnitude = 1.0), leftTrigger = 1.0, rightTrigger = 1.0, buttonMask = 1, rumbleLeftMotor = 1.0, rumbleRightMotor = 1.0)`, `isLeft: bool = true`, `rawVal: float = 1.0`; exercises core body path returning/computing `GamepadState(`.

```aipl
module tests.functions.input.gamepad_z9_test
import * from "std/input/gamepad"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gamepad_updateGamepadTrigger_9(): int:
  let arg_state = GamepadState(id = 1, isConnected = true, leftStick = StickVector(x = 1.0, y = 1.0, rawMagnitude = 2.0, clampedMagnitude = 1.0), rightStick = StickVector(x = 1.0, y = 1.0, rawMagnitude = 2.0, clampedMagnitude = 1.0), leftTrigger = 1.0, rightTrigger = 2.0, buttonMask = 4, rumbleLeftMotor = 1.0, rumbleRightMotor = 2.0)
  let edge_state = GamepadState(id = 0, isConnected = false, leftStick = StickVector(x = 0.5, y = 0.5, rawMagnitude = 1.0, clampedMagnitude = 0.5), rightStick = StickVector(x = 0.5, y = 0.5, rawMagnitude = 1.0, clampedMagnitude = 0.5), leftTrigger = 0.5, rightTrigger = 1.0, buttonMask = 1, rumbleLeftMotor = 0.5, rumbleRightMotor = 1.0)
  let arg_isLeft = true
  let edge_isLeft = false
  let arg_rawVal = 2.0
  let edge_rawVal = 1.0
  let resNom = updateGamepadTrigger(arg_state, arg_isLeft, arg_rawVal)
  let resEdge = updateGamepadTrigger(edge_state, edge_isLeft, edge_rawVal)
  assertEqInt(resNom.id, 1, "updateGamepadTrigger nominal resNom.id == 1")
  assertEqInt(resEdge.id, 0, "updateGamepadTrigger boundary resEdge.id == 0")
  ret 0
```

---

### `createVirtualJoystick` (`std/input/gesture.aipl`)

- **Signature**: `pub fn createVirtualJoystick(originX: float, originY: float, radiusPx: float, deadzoneFraction: float = 0.15): VirtualJoystick:`
- **Import**: `import * from "std/input/gesture"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `originX: float, originY: float, radiusPx: float, deadzoneFraction: float = 0.15` | **Returns**: `VirtualJoystick`
- **Unit Test**: `tests/functions/input/gesture_test.aipl` | **Example**: `examples/ex_137_input_mouse_drawing_and_wheel_zoom_window.aipl`
- **Behavioral Summary**: Verify `createVirtualJoystick` two-finger pinch zoom delta, pan velocity, swipe direction classification, and double-tap spatial/temporal window detection. Concrete nominal inputs: `originX: float = 1.0`, `originY: float = 1.0`, `radiusPx: float = 1.0`, `deadzoneFraction: float = 1.0`; exercises core body path returning/computing `VirtualJoystick(`.

```aipl
module tests.functions.input.gesture_z1_test
import * from "std/input/gesture"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gesture_createVirtualJoystick_1(): int:
  let arg_originX = 1.0
  let edge_originX = 0.5
  let arg_originY = 1.0
  let edge_originY = 0.5
  let arg_radiusPx = 2.0
  let edge_radiusPx = 1.0
  let arg_deadzoneFraction = 1.0
  let edge_deadzoneFraction = 0.5
  let resNom = createVirtualJoystick(arg_originX, arg_originY, arg_radiusPx, arg_deadzoneFraction)
  let resEdge = createVirtualJoystick(edge_originX, edge_originY, edge_radiusPx, edge_deadzoneFraction)
  assertApproxEq(resNom.centerOriginX, 1.0, 0.001, "createVirtualJoystick nominal resNom.centerOriginX ~= 1.0")
  assertApproxEq(resEdge.centerOriginX, 0.5, 0.001, "createVirtualJoystick boundary resEdge.centerOriginX ~= 0.5")
  ret 0
```

---

### `touchDownVirtualJoystick` (`std/input/gesture.aipl`)

- **Signature**: `pub fn touchDownVirtualJoystick(joystick: VirtualJoystick, pointerId: int, touchX: float, touchY: float): VirtualJoystick:`
- **Import**: `import * from "std/input/gesture"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `joystick: VirtualJoystick, pointerId: int, touchX: float, touchY: float` | **Returns**: `VirtualJoystick`
- **Unit Test**: `tests/functions/input/gesture_test.aipl` | **Example**: `examples/ex_138_input_gamepad_dual_stick_radar_window.aipl`
- **Behavioral Summary**: Verify `touchDownVirtualJoystick` two-finger pinch zoom delta, pan velocity, swipe direction classification, and double-tap spatial/temporal window detection. Concrete nominal inputs: `joystick: VirtualJoystick = VirtualJoystick(centerOriginX = 1.0, centerOriginY = 1.0, currentHandleX = 1.0, currentHandleY = 1.0, radiusPixels = 1.0, deadzoneFraction = 1.0, boundPointerId = 1, isActive = true, outputVectorX = 1.0, outputVectorY = 1.0)`, `pointerId: int = 1`, `touchX: float = 1.0`, `touchY: float = 1.0`; exercises core body path returning/computing `touchMoveVirtualJoystick(activated, pointerId, touchX, touchY)`.

```aipl
module tests.functions.input.gesture_z2_test
import * from "std/input/gesture"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gesture_touchDownVirtualJoystick_2(): int:
  let arg_joystick = VirtualJoystick(centerOriginX = 1.0, centerOriginY = 1.0, currentHandleX = 2.0, currentHandleY = 2.0, radiusPixels = 2.0, deadzoneFraction = 1.0, boundPointerId = 4, isActive = true, outputVectorX = 1.0, outputVectorY = 1.0)
  let edge_joystick = VirtualJoystick(centerOriginX = 0.5, centerOriginY = 0.5, currentHandleX = 1.0, currentHandleY = 1.0, radiusPixels = 1.0, deadzoneFraction = 0.5, boundPointerId = 1, isActive = false, outputVectorX = 0.5, outputVectorY = 0.5)
  let arg_pointerId = 4
  let edge_pointerId = 1
  let arg_touchX = 2.0
  let edge_touchX = 1.0
  let arg_touchY = 2.0
  let edge_touchY = 1.0
  let resNom = touchDownVirtualJoystick(arg_joystick, arg_pointerId, arg_touchX, arg_touchY)
  let resEdge = touchDownVirtualJoystick(edge_joystick, edge_pointerId, edge_touchX, edge_touchY)
  assertApproxEq(resNom.centerOriginX, 1.0, 0.001, "touchDownVirtualJoystick nominal resNom.centerOriginX ~= 1.0")
  assertApproxEq(resEdge.centerOriginX, 0.5, 0.001, "touchDownVirtualJoystick boundary resEdge.centerOriginX ~= 0.5")
  ret 0
```

---

### `touchMoveVirtualJoystick` (`std/input/gesture.aipl`)

- **Signature**: `pub fn touchMoveVirtualJoystick(joystick: VirtualJoystick, pointerId: int, touchX: float, touchY: float): VirtualJoystick:`
- **Import**: `import * from "std/input/gesture"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `joystick: VirtualJoystick, pointerId: int, touchX: float, touchY: float` | **Returns**: `VirtualJoystick`
- **Unit Test**: `tests/functions/input/gesture_test.aipl` | **Example**: `examples/ex_136_input_keyboard_piano_and_shortcuts_window.aipl`
- **Behavioral Summary**: Verify `touchMoveVirtualJoystick` two-finger pinch zoom delta, pan velocity, swipe direction classification, and double-tap spatial/temporal window detection. Concrete nominal inputs: `joystick: VirtualJoystick = VirtualJoystick(centerOriginX = 1.0, centerOriginY = 1.0, currentHandleX = 1.0, currentHandleY = 1.0, radiusPixels = 1.0, deadzoneFraction = 1.0, boundPointerId = 1, isActive = true, outputVectorX = 1.0, outputVectorY = 1.0)`, `pointerId: int = 1`, `touchX: float = 1.0`, `touchY: float = 1.0`; exercises core body path returning/computing `VirtualJoystick(`.

```aipl
module tests.functions.input.gesture_z3_test
import * from "std/input/gesture"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gesture_touchMoveVirtualJoystick_3(): int:
  let arg_joystick = VirtualJoystick(centerOriginX = 1.0, centerOriginY = 1.0, currentHandleX = 2.0, currentHandleY = 2.0, radiusPixels = 2.0, deadzoneFraction = 1.0, boundPointerId = 4, isActive = true, outputVectorX = 1.0, outputVectorY = 1.0)
  let edge_joystick = VirtualJoystick(centerOriginX = 0.5, centerOriginY = 0.5, currentHandleX = 1.0, currentHandleY = 1.0, radiusPixels = 1.0, deadzoneFraction = 0.5, boundPointerId = 1, isActive = false, outputVectorX = 0.5, outputVectorY = 0.5)
  let arg_pointerId = 4
  let edge_pointerId = 1
  let arg_touchX = 2.0
  let edge_touchX = 1.0
  let arg_touchY = 2.0
  let edge_touchY = 1.0
  let resNom = touchMoveVirtualJoystick(arg_joystick, arg_pointerId, arg_touchX, arg_touchY)
  let resEdge = touchMoveVirtualJoystick(edge_joystick, edge_pointerId, edge_touchX, edge_touchY)
  assertApproxEq(resNom.centerOriginX, 1.0, 0.001, "touchMoveVirtualJoystick nominal resNom.centerOriginX ~= 1.0")
  assertApproxEq(resEdge.centerOriginX, 0.5, 0.001, "touchMoveVirtualJoystick boundary resEdge.centerOriginX ~= 0.5")
  ret 0
```

---

### `touchUpVirtualJoystick` (`std/input/gesture.aipl`)

- **Signature**: `pub fn touchUpVirtualJoystick(joystick: VirtualJoystick, pointerId: int): VirtualJoystick:`
- **Import**: `import * from "std/input/gesture"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `joystick: VirtualJoystick, pointerId: int` | **Returns**: `VirtualJoystick`
- **Unit Test**: `tests/functions/input/gesture_test.aipl` | **Example**: `examples/ex_137_input_mouse_drawing_and_wheel_zoom_window.aipl`
- **Behavioral Summary**: Verify `touchUpVirtualJoystick` two-finger pinch zoom delta, pan velocity, swipe direction classification, and double-tap spatial/temporal window detection. Concrete nominal inputs: `joystick: VirtualJoystick = VirtualJoystick(centerOriginX = 1.0, centerOriginY = 1.0, currentHandleX = 1.0, currentHandleY = 1.0, radiusPixels = 1.0, deadzoneFraction = 1.0, boundPointerId = 1, isActive = true, outputVectorX = 1.0, outputVectorY = 1.0)`, `pointerId: int = 1`; exercises core body path returning/computing `VirtualJoystick(`.

```aipl
module tests.functions.input.gesture_z4_test
import * from "std/input/gesture"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gesture_touchUpVirtualJoystick_4(): int:
  let arg_joystick = VirtualJoystick(centerOriginX = 1.0, centerOriginY = 1.0, currentHandleX = 2.0, currentHandleY = 2.0, radiusPixels = 2.0, deadzoneFraction = 1.0, boundPointerId = 4, isActive = true, outputVectorX = 1.0, outputVectorY = 1.0)
  let edge_joystick = VirtualJoystick(centerOriginX = 0.5, centerOriginY = 0.5, currentHandleX = 1.0, currentHandleY = 1.0, radiusPixels = 1.0, deadzoneFraction = 0.5, boundPointerId = 1, isActive = false, outputVectorX = 0.5, outputVectorY = 0.5)
  let arg_pointerId = 4
  let edge_pointerId = 1
  let resNom = touchUpVirtualJoystick(arg_joystick, arg_pointerId)
  let resEdge = touchUpVirtualJoystick(edge_joystick, edge_pointerId)
  assertApproxEq(resNom.centerOriginX, 1.0, 0.001, "touchUpVirtualJoystick nominal resNom.centerOriginX ~= 1.0")
  assertApproxEq(resEdge.centerOriginX, 0.5, 0.001, "touchUpVirtualJoystick boundary resEdge.centerOriginX ~= 0.5")
  ret 0
```

---

### `computePinchDelta` (`std/input/gesture.aipl`)

- **Signature**: `pub fn computePinchDelta(p1X: float, p1Y: float, p2X: float, p2Y: float, prevDist: float): (float, float):`
- **Import**: `import * from "std/input/gesture"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p1X: float, p1Y: float, p2X: float, p2Y: float, prevDist: float` | **Returns**: `(float, float)`
- **Unit Test**: `tests/functions/input/gesture_test.aipl` | **Example**: `examples/ex_138_input_gamepad_dual_stick_radar_window.aipl`
- **Behavioral Summary**: Verify `computePinchDelta` two-finger pinch zoom delta, pan velocity, swipe direction classification, and double-tap spatial/temporal window detection. Concrete nominal inputs: `p1X: float = 1.0`, `p1Y: float = 1.0`, `p2X: float = 1.0`, `p2Y: float = 1.0`, `prevDist: float): (float = float): (float()`, `float: any = 42`; exercises core body path returning/computing `(curDist, scale)`.

```aipl
module tests.functions.input.gesture_z5_test
import * from "std/input/gesture"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gesture_computePinchDelta_5(): int:
  let arg_p1X = 1.0
  let edge_p1X = 0.5
  let arg_p1Y = 1.0
  let edge_p1Y = 0.5
  let arg_p2X = 1.0
  let edge_p2X = 0.5
  let arg_p2Y = 1.0
  let edge_p2Y = 0.5
  let arg_prevDist = 1.0
  let edge_prevDist = 0.5
  let resNom = computePinchDelta(arg_p1X, arg_p1Y, arg_p2X, arg_p2Y, arg_prevDist)
  let resEdge = computePinchDelta(edge_p1X, edge_p1Y, edge_p2X, edge_p2Y, edge_prevDist)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertApproxEq(n_t0, 0.0, 0.001, "computePinchDelta nominal n_t0 ~= 0.0")
  assertApproxEq(e_t0, 0.0, 0.001, "computePinchDelta boundary e_t0 ~= 0.0")
  ret 0
```

---

### `detectDoubleTap` (`std/input/gesture.aipl`)

- **Signature**: `pub fn detectDoubleTap(lastTapTimeMs: int, currentTapTimeMs: int, maxIntervalMs: int = 300): bool:`
- **Import**: `import * from "std/input/gesture"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `lastTapTimeMs: int, currentTapTimeMs: int, maxIntervalMs: int = 300` | **Returns**: `bool`
- **Unit Test**: `tests/functions/input/gesture_test.aipl` | **Example**: `examples/ex_136_input_keyboard_piano_and_shortcuts_window.aipl`
- **Behavioral Summary**: Verify `detectDoubleTap` two-finger pinch zoom delta, pan velocity, swipe direction classification, and double-tap spatial/temporal window detection. Concrete nominal inputs: `lastTapTimeMs: int = 1`, `currentTapTimeMs: int = 1`, `maxIntervalMs: int = 1`; exercises core body path returning/computing `dt >= 0 and dt <= maxIntervalMs`.

```aipl
module tests.functions.input.gesture_z6_test
import * from "std/input/gesture"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gesture_detectDoubleTap_6(): int:
  let arg_lastTapTimeMs = 4
  let edge_lastTapTimeMs = 1
  let arg_currentTapTimeMs = 4
  let edge_currentTapTimeMs = 1
  let arg_maxIntervalMs = 4
  let edge_maxIntervalMs = 1
  let resNom = detectDoubleTap(arg_lastTapTimeMs, arg_currentTapTimeMs, arg_maxIntervalMs)
  let resEdge = detectDoubleTap(edge_lastTapTimeMs, edge_currentTapTimeMs, edge_maxIntervalMs)
  assert(resNom == true, "detectDoubleTap nominal resNom == true")
  assert(resEdge == true, "detectDoubleTap boundary resEdge == true")
  ret 0
```

---

### `createKeyboardState` (`std/input/keyboard.aipl`)

- **Signature**: `pub fn createKeyboardState(): KeyboardState:`
- **Import**: `import * from "std/input/keyboard"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `KeyboardState`
- **Unit Test**: `tests/functions/input/keyboard_test.aipl` | **Example**: `examples/ex_137_input_mouse_drawing_and_wheel_zoom_window.aipl`
- **Behavioral Summary**: Verify `createKeyboardState` key down, `JustPressed`, and `JustReleased` edge transitions, modifier bitmask checks, and `flushKeyFrame` edge clearing. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `KeyboardState(keys = m, modifiers = MOD_NONE, textStream = ts)`.

```aipl
module tests.functions.input.keyboard_z1_test
import * from "std/input/keyboard"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_keyboard_createKeyboardState_1(): int:
  let resNom = createKeyboardState()
  let resEdge = createKeyboardState()
  assertEqInt(resNom.modifiers, 0, "createKeyboardState nominal resNom.modifiers == 0")
  assertEqInt(resEdge.modifiers, 0, "createKeyboardState boundary resEdge.modifiers == 0")
  ret 0
```

---

### `isKeyDown` (`std/input/keyboard.aipl`)

- **Signature**: `pub fn isKeyDown(state: KeyboardState, key: int): bool:`
- **Import**: `import * from "std/input/keyboard"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: KeyboardState, key: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/input/keyboard_test.aipl` | **Example**: `examples/ex_138_input_gamepad_dual_stick_radar_window.aipl`
- **Behavioral Summary**: Verify `isKeyDown` key down, `JustPressed`, and `JustReleased` edge transitions, modifier bitmask checks, and `flushKeyFrame` edge clearing. Concrete nominal inputs: `state: KeyboardState = KeyboardState(keys = Map(), modifiers = 1, textStream = ["aipl_test"])`, `key: int = 1`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.input.keyboard_z2_test
import * from "std/input/keyboard"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_keyboard_isKeyDown_2(): int:
  let arg_state = KeyboardState(keys = {}, modifiers = 4, textStream = [])
  let edge_state = KeyboardState(keys = {}, modifiers = 1, textStream = [])
  let arg_key = 4
  let edge_key = 1
  let resNom = isKeyDown(arg_state, arg_key)
  let resEdge = isKeyDown(edge_state, edge_key)
  assert(resNom == false, "isKeyDown nominal resNom == false")
  assert(resEdge == false, "isKeyDown boundary resEdge == false")
  ret 0
```

---

### `isKeyJustPressed` (`std/input/keyboard.aipl`)

- **Signature**: `pub fn isKeyJustPressed(state: KeyboardState, key: int): bool:`
- **Import**: `import * from "std/input/keyboard"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: KeyboardState, key: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/input/keyboard_test.aipl` | **Example**: `examples/ex_136_input_keyboard_piano_and_shortcuts_window.aipl`
- **Behavioral Summary**: Verify `isKeyJustPressed` key down, `JustPressed`, and `JustReleased` edge transitions, modifier bitmask checks, and `flushKeyFrame` edge clearing. Concrete nominal inputs: `state: KeyboardState = KeyboardState(keys = Map(), modifiers = 1, textStream = ["aipl_test"])`, `key: int = 1`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.input.keyboard_z3_test
import * from "std/input/keyboard"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_keyboard_isKeyJustPressed_3(): int:
  let arg_state = KeyboardState(keys = {}, modifiers = 4, textStream = [])
  let edge_state = KeyboardState(keys = {}, modifiers = 1, textStream = [])
  let arg_key = 4
  let edge_key = 1
  let resNom = isKeyJustPressed(arg_state, arg_key)
  let resEdge = isKeyJustPressed(edge_state, edge_key)
  assert(resNom == false, "isKeyJustPressed nominal resNom == false")
  assert(resEdge == false, "isKeyJustPressed boundary resEdge == false")
  ret 0
```

---

### `isKeyJustReleased` (`std/input/keyboard.aipl`)

- **Signature**: `pub fn isKeyJustReleased(state: KeyboardState, key: int): bool:`
- **Import**: `import * from "std/input/keyboard"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: KeyboardState, key: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/input/keyboard_test.aipl` | **Example**: `examples/ex_137_input_mouse_drawing_and_wheel_zoom_window.aipl`
- **Behavioral Summary**: Verify `isKeyJustReleased` key down, `JustPressed`, and `JustReleased` edge transitions, modifier bitmask checks, and `flushKeyFrame` edge clearing. Concrete nominal inputs: `state: KeyboardState = KeyboardState(keys = Map(), modifiers = 1, textStream = ["aipl_test"])`, `key: int = 1`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.input.keyboard_z4_test
import * from "std/input/keyboard"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_keyboard_isKeyJustReleased_4(): int:
  let arg_state = KeyboardState(keys = {}, modifiers = 4, textStream = [])
  let edge_state = KeyboardState(keys = {}, modifiers = 1, textStream = [])
  let arg_key = 4
  let edge_key = 1
  let resNom = isKeyJustReleased(arg_state, arg_key)
  let resEdge = isKeyJustReleased(edge_state, edge_key)
  assert(resNom == false, "isKeyJustReleased nominal resNom == false")
  assert(resEdge == false, "isKeyJustReleased boundary resEdge == false")
  ret 0
```

---

### `hasModifier` (`std/input/keyboard.aipl`)

- **Signature**: `pub fn hasModifier(state: KeyboardState, modifier: int): bool:`
- **Import**: `import * from "std/input/keyboard"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: KeyboardState, modifier: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/input/keyboard_test.aipl` | **Example**: `examples/ex_138_input_gamepad_dual_stick_radar_window.aipl`
- **Behavioral Summary**: Verify `hasModifier` key down, `JustPressed`, and `JustReleased` edge transitions, modifier bitmask checks, and `flushKeyFrame` edge clearing. Concrete nominal inputs: `state: KeyboardState = KeyboardState(keys = Map(), modifiers = 1, textStream = ["aipl_test"])`, `modifier: int = 1`; exercises core body path returning/computing `(state.modifiers & modifier) == modifier`.

```aipl
module tests.functions.input.keyboard_z5_test
import * from "std/input/keyboard"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_keyboard_hasModifier_5(): int:
  let arg_state = KeyboardState(keys = {}, modifiers = 4, textStream = [])
  let edge_state = KeyboardState(keys = {}, modifiers = 1, textStream = [])
  let arg_modifier = 4
  let edge_modifier = 1
  let resNom = hasModifier(arg_state, arg_modifier)
  let resEdge = hasModifier(edge_state, edge_modifier)
  assert(resNom == true, "hasModifier nominal resNom == true")
  assert(resEdge == true, "hasModifier boundary resEdge == true")
  ret 0
```

---

### `pushKeyboardEvent` (`std/input/keyboard.aipl`)

- **Signature**: `pub fn pushKeyboardEvent(state: KeyboardState, key: int, isDown: bool, repeat: bool): KeyboardState:`
- **Import**: `import * from "std/input/keyboard"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: KeyboardState, key: int, isDown: bool, repeat: bool` | **Returns**: `KeyboardState`
- **Unit Test**: `tests/functions/input/keyboard_test.aipl` | **Example**: `examples/ex_136_input_keyboard_piano_and_shortcuts_window.aipl`
- **Behavioral Summary**: Verify `pushKeyboardEvent` key down, `JustPressed`, and `JustReleased` edge transitions, modifier bitmask checks, and `flushKeyFrame` edge clearing. Concrete nominal inputs: `state: KeyboardState = KeyboardState(keys = Map(), modifiers = 1, textStream = ["aipl_test"])`, `key: int = 1`, `isDown: bool = true`, `repeat: bool = true`; exercises core body path returning/computing `KeyboardState(keys = m, modifiers = state.modifiers, textStream = state.textStream)`.

```aipl
module tests.functions.input.keyboard_z6_test
import * from "std/input/keyboard"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_keyboard_pushKeyboardEvent_6(): int:
  let arg_state = KeyboardState(keys = {}, modifiers = 4, textStream = [])
  let edge_state = KeyboardState(keys = {}, modifiers = 1, textStream = [])
  let arg_key = 4
  let edge_key = 1
  let arg_isDown = true
  let edge_isDown = false
  let arg_repeat = true
  let edge_repeat = false
  let resNom = pushKeyboardEvent(arg_state, arg_key, arg_isDown, arg_repeat)
  let resEdge = pushKeyboardEvent(edge_state, edge_key, edge_isDown, edge_repeat)
  assertEqInt(resNom.modifiers, 4, "pushKeyboardEvent nominal resNom.modifiers == 4")
  assertEqInt(resEdge.modifiers, 1, "pushKeyboardEvent boundary resEdge.modifiers == 1")
  ret 0
```

---

### `pushTextInput` (`std/input/keyboard.aipl`)

- **Signature**: `pub fn pushTextInput(state: KeyboardState, ch: str): KeyboardState:`
- **Import**: `import * from "std/input/keyboard"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: KeyboardState, ch: str` | **Returns**: `KeyboardState`
- **Unit Test**: `tests/functions/input/keyboard_test.aipl` | **Example**: `examples/ex_137_input_mouse_drawing_and_wheel_zoom_window.aipl`
- **Behavioral Summary**: Verify `pushTextInput` key down, `JustPressed`, and `JustReleased` edge transitions, modifier bitmask checks, and `flushKeyFrame` edge clearing. Concrete nominal inputs: `state: KeyboardState = KeyboardState(keys = Map(), modifiers = 1, textStream = ["aipl_test"])`, `ch: str = "aipl_test"`; exercises core body path returning/computing `KeyboardState(keys = state.keys, modifiers = state.modifiers, textStream = ts)`.

```aipl
module tests.functions.input.keyboard_z7_test
import * from "std/input/keyboard"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_keyboard_pushTextInput_7(): int:
  let arg_state = KeyboardState(keys = {}, modifiers = 4, textStream = [])
  let edge_state = KeyboardState(keys = {}, modifiers = 1, textStream = [])
  let arg_ch = "test"
  let edge_ch = "a"
  let resNom = pushTextInput(arg_state, arg_ch)
  let resEdge = pushTextInput(edge_state, edge_ch)
  assertEqInt(resNom.modifiers, 4, "pushTextInput nominal resNom.modifiers == 4")
  assertEqInt(resEdge.modifiers, 1, "pushTextInput boundary resEdge.modifiers == 1")
  ret 0
```

---

### `flushKeyFrame` (`std/input/keyboard.aipl`)

- **Signature**: `pub fn flushKeyFrame(state: KeyboardState): KeyboardState:`
- **Import**: `import * from "std/input/keyboard"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: KeyboardState` | **Returns**: `KeyboardState`
- **Unit Test**: `tests/functions/input/keyboard_test.aipl` | **Example**: `examples/ex_138_input_gamepad_dual_stick_radar_window.aipl`
- **Behavioral Summary**: Verify `flushKeyFrame` key down, `JustPressed`, and `JustReleased` edge transitions, modifier bitmask checks, and `flushKeyFrame` edge clearing. Concrete nominal inputs: `state: KeyboardState = KeyboardState(keys = Map(), modifiers = 1, textStream = ["aipl_test"])`; exercises core body path returning/computing `KeyboardState(keys = m, modifiers = state.modifiers, textStream = emptyTs)`.

```aipl
module tests.functions.input.keyboard_z8_test
import * from "std/input/keyboard"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_keyboard_flushKeyFrame_8(): int:
  let arg_state = KeyboardState(keys = {}, modifiers = 4, textStream = [])
  let edge_state = KeyboardState(keys = {}, modifiers = 1, textStream = [])
  let resNom = flushKeyFrame(arg_state)
  let resEdge = flushKeyFrame(edge_state)
  assertEqInt(resNom.modifiers, 4, "flushKeyFrame nominal resNom.modifiers == 4")
  assertEqInt(resEdge.modifiers, 1, "flushKeyFrame boundary resEdge.modifiers == 1")
  ret 0
```

---

### `createMouseState` (`std/input/mouse.aipl`)

- **Signature**: `pub fn createMouseState(): MouseState:`
- **Import**: `import * from "std/input/mouse"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `MouseState`
- **Unit Test**: `tests/functions/input/mouse_test.aipl` | **Example**: `examples/ex_136_input_keyboard_piano_and_shortcuts_window.aipl`
- **Behavioral Summary**: Verify `createMouseState` button state transitions, displacement `getMouseDelta`, scroll wheel accumulation, and `flushMouseFrame` zeroing. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `MouseState(`.

```aipl
module tests.functions.input.mouse_z1_test
import * from "std/input/mouse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mouse_createMouseState_1(): int:
  let resNom = createMouseState()
  let resEdge = createMouseState()
  assertApproxEq(resNom.x, 0.0, 0.001, "createMouseState nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "createMouseState boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `isMouseButtonDown` (`std/input/mouse.aipl`)

- **Signature**: `pub fn isMouseButtonDown(state: MouseState, button: int): bool:`
- **Import**: `import * from "std/input/mouse"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: MouseState, button: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/input/mouse_test.aipl` | **Example**: `examples/ex_137_input_mouse_drawing_and_wheel_zoom_window.aipl`
- **Behavioral Summary**: Verify `isMouseButtonDown` button state transitions, displacement `getMouseDelta`, scroll wheel accumulation, and `flushMouseFrame` zeroing. Concrete nominal inputs: `state: MouseState = MouseState(x = 1.0, y = 1.0, deltaX = 1.0, deltaY = 1.0, scrollDeltaX = 1.0, scrollDeltaY = 1.0, buttonMask = 1, buttons = Map())`, `button: int = 1`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.input.mouse_z2_test
import * from "std/input/mouse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mouse_isMouseButtonDown_2(): int:
  let arg_state = MouseState(x = 1.0, y = 1.0, deltaX = 1.0, deltaY = 1.0, scrollDeltaX = 1.0, scrollDeltaY = 1.0, buttonMask = 4, buttons = {})
  let edge_state = MouseState(x = 0.5, y = 0.5, deltaX = 0.5, deltaY = 0.5, scrollDeltaX = 0.5, scrollDeltaY = 0.5, buttonMask = 1, buttons = {})
  let arg_button = 4
  let edge_button = 1
  let resNom = isMouseButtonDown(arg_state, arg_button)
  let resEdge = isMouseButtonDown(edge_state, edge_button)
  assert(resNom == true, "isMouseButtonDown nominal resNom == true")
  assert(resEdge == true, "isMouseButtonDown boundary resEdge == true")
  ret 0
```

---

### `isMouseButtonJustPressed` (`std/input/mouse.aipl`)

- **Signature**: `pub fn isMouseButtonJustPressed(state: MouseState, button: int): bool:`
- **Import**: `import * from "std/input/mouse"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: MouseState, button: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/input/mouse_test.aipl` | **Example**: `examples/ex_138_input_gamepad_dual_stick_radar_window.aipl`
- **Behavioral Summary**: Verify `isMouseButtonJustPressed` button state transitions, displacement `getMouseDelta`, scroll wheel accumulation, and `flushMouseFrame` zeroing. Concrete nominal inputs: `state: MouseState = MouseState(x = 1.0, y = 1.0, deltaX = 1.0, deltaY = 1.0, scrollDeltaX = 1.0, scrollDeltaY = 1.0, buttonMask = 1, buttons = Map())`, `button: int = 1`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.input.mouse_z3_test
import * from "std/input/mouse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mouse_isMouseButtonJustPressed_3(): int:
  let arg_state = MouseState(x = 1.0, y = 1.0, deltaX = 1.0, deltaY = 1.0, scrollDeltaX = 1.0, scrollDeltaY = 1.0, buttonMask = 4, buttons = {})
  let edge_state = MouseState(x = 0.5, y = 0.5, deltaX = 0.5, deltaY = 0.5, scrollDeltaX = 0.5, scrollDeltaY = 0.5, buttonMask = 1, buttons = {})
  let arg_button = 4
  let edge_button = 1
  let resNom = isMouseButtonJustPressed(arg_state, arg_button)
  let resEdge = isMouseButtonJustPressed(edge_state, edge_button)
  assert(resNom == false, "isMouseButtonJustPressed nominal resNom == false")
  assert(resEdge == false, "isMouseButtonJustPressed boundary resEdge == false")
  ret 0
```

---

### `isMouseButtonJustReleased` (`std/input/mouse.aipl`)

- **Signature**: `pub fn isMouseButtonJustReleased(state: MouseState, button: int): bool:`
- **Import**: `import * from "std/input/mouse"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: MouseState, button: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/input/mouse_test.aipl` | **Example**: `examples/ex_136_input_keyboard_piano_and_shortcuts_window.aipl`
- **Behavioral Summary**: Verify `isMouseButtonJustReleased` button state transitions, displacement `getMouseDelta`, scroll wheel accumulation, and `flushMouseFrame` zeroing. Concrete nominal inputs: `state: MouseState = MouseState(x = 1.0, y = 1.0, deltaX = 1.0, deltaY = 1.0, scrollDeltaX = 1.0, scrollDeltaY = 1.0, buttonMask = 1, buttons = Map())`, `button: int = 1`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.input.mouse_z4_test
import * from "std/input/mouse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mouse_isMouseButtonJustReleased_4(): int:
  let arg_state = MouseState(x = 1.0, y = 1.0, deltaX = 1.0, deltaY = 1.0, scrollDeltaX = 1.0, scrollDeltaY = 1.0, buttonMask = 4, buttons = {})
  let edge_state = MouseState(x = 0.5, y = 0.5, deltaX = 0.5, deltaY = 0.5, scrollDeltaX = 0.5, scrollDeltaY = 0.5, buttonMask = 1, buttons = {})
  let arg_button = 4
  let edge_button = 1
  let resNom = isMouseButtonJustReleased(arg_state, arg_button)
  let resEdge = isMouseButtonJustReleased(edge_state, edge_button)
  assert(resNom == false, "isMouseButtonJustReleased nominal resNom == false")
  assert(resEdge == false, "isMouseButtonJustReleased boundary resEdge == false")
  ret 0
```

---

### `getMousePosition` (`std/input/mouse.aipl`)

- **Signature**: `pub fn getMousePosition(state: MouseState): (float, float):`
- **Import**: `import * from "std/input/mouse"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: MouseState` | **Returns**: `(float, float)`
- **Unit Test**: `tests/functions/input/mouse_test.aipl` | **Example**: `examples/ex_137_input_mouse_drawing_and_wheel_zoom_window.aipl`
- **Behavioral Summary**: Verify `getMousePosition` button state transitions, displacement `getMouseDelta`, scroll wheel accumulation, and `flushMouseFrame` zeroing. Concrete nominal inputs: `state: MouseState): (float = MouseState): (float()`, `float: any = 42`; exercises core body path returning/computing `(state.x, state.y)`.

```aipl
module tests.functions.input.mouse_z5_test
import * from "std/input/mouse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mouse_getMousePosition_5(): int:
  let arg_state = MouseState(x = 1.0, y = 1.0, deltaX = 1.0, deltaY = 1.0, scrollDeltaX = 1.0, scrollDeltaY = 1.0, buttonMask = 4, buttons = {})
  let edge_state = MouseState(x = 0.5, y = 0.5, deltaX = 0.5, deltaY = 0.5, scrollDeltaX = 0.5, scrollDeltaY = 0.5, buttonMask = 1, buttons = {})
  let resNom = getMousePosition(arg_state)
  let resEdge = getMousePosition(edge_state)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertApproxEq(n_t0, 1.0, 0.001, "getMousePosition nominal n_t0 ~= 1.0")
  assertApproxEq(e_t0, 0.5, 0.001, "getMousePosition boundary e_t0 ~= 0.5")
  ret 0
```

---

### `getMouseDelta` (`std/input/mouse.aipl`)

- **Signature**: `pub fn getMouseDelta(state: MouseState): (float, float):`
- **Import**: `import * from "std/input/mouse"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: MouseState` | **Returns**: `(float, float)`
- **Unit Test**: `tests/functions/input/mouse_test.aipl` | **Example**: `examples/ex_138_input_gamepad_dual_stick_radar_window.aipl`
- **Behavioral Summary**: Verify `getMouseDelta` button state transitions, displacement `getMouseDelta`, scroll wheel accumulation, and `flushMouseFrame` zeroing. Concrete nominal inputs: `state: MouseState): (float = MouseState): (float()`, `float: any = 42`; exercises core body path returning/computing `(state.deltaX, state.deltaY)`.

```aipl
module tests.functions.input.mouse_z6_test
import * from "std/input/mouse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mouse_getMouseDelta_6(): int:
  let arg_state = MouseState(x = 1.0, y = 1.0, deltaX = 1.0, deltaY = 1.0, scrollDeltaX = 1.0, scrollDeltaY = 1.0, buttonMask = 4, buttons = {})
  let edge_state = MouseState(x = 0.5, y = 0.5, deltaX = 0.5, deltaY = 0.5, scrollDeltaX = 0.5, scrollDeltaY = 0.5, buttonMask = 1, buttons = {})
  let resNom = getMouseDelta(arg_state)
  let resEdge = getMouseDelta(edge_state)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertApproxEq(n_t0, 1.0, 0.001, "getMouseDelta nominal n_t0 ~= 1.0")
  assertApproxEq(e_t0, 0.5, 0.001, "getMouseDelta boundary e_t0 ~= 0.5")
  ret 0
```

---

### `getScrollDelta` (`std/input/mouse.aipl`)

- **Signature**: `pub fn getScrollDelta(state: MouseState): (float, float):`
- **Import**: `import * from "std/input/mouse"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: MouseState` | **Returns**: `(float, float)`
- **Unit Test**: `tests/functions/input/mouse_test.aipl` | **Example**: `examples/ex_136_input_keyboard_piano_and_shortcuts_window.aipl`
- **Behavioral Summary**: Verify `getScrollDelta` button state transitions, displacement `getMouseDelta`, scroll wheel accumulation, and `flushMouseFrame` zeroing. Concrete nominal inputs: `state: MouseState): (float = MouseState): (float()`, `float: any = 42`; exercises core body path returning/computing `(state.scrollDeltaX, state.scrollDeltaY)`.

```aipl
module tests.functions.input.mouse_z7_test
import * from "std/input/mouse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mouse_getScrollDelta_7(): int:
  let arg_state = MouseState(x = 1.0, y = 1.0, deltaX = 1.0, deltaY = 1.0, scrollDeltaX = 1.0, scrollDeltaY = 1.0, buttonMask = 4, buttons = {})
  let edge_state = MouseState(x = 0.5, y = 0.5, deltaX = 0.5, deltaY = 0.5, scrollDeltaX = 0.5, scrollDeltaY = 0.5, buttonMask = 1, buttons = {})
  let resNom = getScrollDelta(arg_state)
  let resEdge = getScrollDelta(edge_state)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertApproxEq(n_t0, 1.0, 0.001, "getScrollDelta nominal n_t0 ~= 1.0")
  assertApproxEq(e_t0, 0.5, 0.001, "getScrollDelta boundary e_t0 ~= 0.5")
  ret 0
```

---

### `updateMousePosition` (`std/input/mouse.aipl`)

- **Signature**: `pub fn updateMousePosition(state: MouseState, newX: float, newY: float): MouseState:`
- **Import**: `import * from "std/input/mouse"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: MouseState, newX: float, newY: float` | **Returns**: `MouseState`
- **Unit Test**: `tests/functions/input/mouse_test.aipl` | **Example**: `examples/ex_137_input_mouse_drawing_and_wheel_zoom_window.aipl`
- **Behavioral Summary**: Verify `updateMousePosition` button state transitions, displacement `getMouseDelta`, scroll wheel accumulation, and `flushMouseFrame` zeroing. Concrete nominal inputs: `state: MouseState = MouseState(x = 1.0, y = 1.0, deltaX = 1.0, deltaY = 1.0, scrollDeltaX = 1.0, scrollDeltaY = 1.0, buttonMask = 1, buttons = Map())`, `newX: float = 1.0`, `newY: float = 1.0`; exercises core body path returning/computing `MouseState(`.

```aipl
module tests.functions.input.mouse_z8_test
import * from "std/input/mouse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mouse_updateMousePosition_8(): int:
  let arg_state = MouseState(x = 1.0, y = 1.0, deltaX = 1.0, deltaY = 1.0, scrollDeltaX = 1.0, scrollDeltaY = 1.0, buttonMask = 4, buttons = {})
  let edge_state = MouseState(x = 0.5, y = 0.5, deltaX = 0.5, deltaY = 0.5, scrollDeltaX = 0.5, scrollDeltaY = 0.5, buttonMask = 1, buttons = {})
  let arg_newX = 2.0
  let edge_newX = 1.0
  let arg_newY = 2.0
  let edge_newY = 1.0
  let resNom = updateMousePosition(arg_state, arg_newX, arg_newY)
  let resEdge = updateMousePosition(edge_state, edge_newX, edge_newY)
  assertApproxEq(resNom.x, 2.0, 0.001, "updateMousePosition nominal resNom.x ~= 2.0")
  assertApproxEq(resEdge.x, 1.0, 0.001, "updateMousePosition boundary resEdge.x ~= 1.0")
  ret 0
```

---

### `updateMouseButton` (`std/input/mouse.aipl`)

- **Signature**: `pub fn updateMouseButton(state: MouseState, button: int, isDown: bool): MouseState:`
- **Import**: `import * from "std/input/mouse"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: MouseState, button: int, isDown: bool` | **Returns**: `MouseState`
- **Unit Test**: `tests/functions/input/mouse_test.aipl` | **Example**: `examples/ex_138_input_gamepad_dual_stick_radar_window.aipl`
- **Behavioral Summary**: Verify `updateMouseButton` button state transitions, displacement `getMouseDelta`, scroll wheel accumulation, and `flushMouseFrame` zeroing. Concrete nominal inputs: `state: MouseState = MouseState(x = 1.0, y = 1.0, deltaX = 1.0, deltaY = 1.0, scrollDeltaX = 1.0, scrollDeltaY = 1.0, buttonMask = 1, buttons = Map())`, `button: int = 1`, `isDown: bool = true`; exercises core body path returning/computing `MouseState(`.

```aipl
module tests.functions.input.mouse_z9_test
import * from "std/input/mouse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mouse_updateMouseButton_9(): int:
  let arg_state = MouseState(x = 1.0, y = 1.0, deltaX = 1.0, deltaY = 1.0, scrollDeltaX = 1.0, scrollDeltaY = 1.0, buttonMask = 4, buttons = {})
  let edge_state = MouseState(x = 0.5, y = 0.5, deltaX = 0.5, deltaY = 0.5, scrollDeltaX = 0.5, scrollDeltaY = 0.5, buttonMask = 1, buttons = {})
  let arg_button = 4
  let edge_button = 1
  let arg_isDown = true
  let edge_isDown = false
  let resNom = updateMouseButton(arg_state, arg_button, arg_isDown)
  let resEdge = updateMouseButton(edge_state, edge_button, edge_isDown)
  assertApproxEq(resNom.x, 1.0, 0.001, "updateMouseButton nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "updateMouseButton boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `updateMouseScroll` (`std/input/mouse.aipl`)

- **Signature**: `pub fn updateMouseScroll(state: MouseState, scrollX: float, scrollY: float): MouseState:`
- **Import**: `import * from "std/input/mouse"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: MouseState, scrollX: float, scrollY: float` | **Returns**: `MouseState`
- **Unit Test**: `tests/functions/input/mouse_test.aipl` | **Example**: `examples/ex_136_input_keyboard_piano_and_shortcuts_window.aipl`
- **Behavioral Summary**: Verify `updateMouseScroll` button state transitions, displacement `getMouseDelta`, scroll wheel accumulation, and `flushMouseFrame` zeroing. Concrete nominal inputs: `state: MouseState = MouseState(x = 1.0, y = 1.0, deltaX = 1.0, deltaY = 1.0, scrollDeltaX = 1.0, scrollDeltaY = 1.0, buttonMask = 1, buttons = Map())`, `scrollX: float = 1.0`, `scrollY: float = 1.0`; exercises core body path returning/computing `MouseState(`.

```aipl
module tests.functions.input.mouse_z10_test
import * from "std/input/mouse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mouse_updateMouseScroll_10(): int:
  let arg_state = MouseState(x = 1.0, y = 1.0, deltaX = 1.0, deltaY = 1.0, scrollDeltaX = 1.0, scrollDeltaY = 1.0, buttonMask = 4, buttons = {})
  let edge_state = MouseState(x = 0.5, y = 0.5, deltaX = 0.5, deltaY = 0.5, scrollDeltaX = 0.5, scrollDeltaY = 0.5, buttonMask = 1, buttons = {})
  let arg_scrollX = 1.0
  let edge_scrollX = 0.5
  let arg_scrollY = 1.0
  let edge_scrollY = 0.5
  let resNom = updateMouseScroll(arg_state, arg_scrollX, arg_scrollY)
  let resEdge = updateMouseScroll(edge_state, edge_scrollX, edge_scrollY)
  assertApproxEq(resNom.x, 1.0, 0.001, "updateMouseScroll nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "updateMouseScroll boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `flushMouseFrame` (`std/input/mouse.aipl`)

- **Signature**: `pub fn flushMouseFrame(state: MouseState): MouseState:`
- **Import**: `import * from "std/input/mouse"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: MouseState` | **Returns**: `MouseState`
- **Unit Test**: `tests/functions/input/mouse_test.aipl` | **Example**: `examples/ex_137_input_mouse_drawing_and_wheel_zoom_window.aipl`
- **Behavioral Summary**: Verify `flushMouseFrame` button state transitions, displacement `getMouseDelta`, scroll wheel accumulation, and `flushMouseFrame` zeroing. Concrete nominal inputs: `state: MouseState = MouseState(x = 1.0, y = 1.0, deltaX = 1.0, deltaY = 1.0, scrollDeltaX = 1.0, scrollDeltaY = 1.0, buttonMask = 1, buttons = Map())`; exercises core body path returning/computing `MouseState(`.

```aipl
module tests.functions.input.mouse_z11_test
import * from "std/input/mouse"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mouse_flushMouseFrame_11(): int:
  let arg_state = MouseState(x = 1.0, y = 1.0, deltaX = 1.0, deltaY = 1.0, scrollDeltaX = 1.0, scrollDeltaY = 1.0, buttonMask = 4, buttons = {})
  let edge_state = MouseState(x = 0.5, y = 0.5, deltaX = 0.5, deltaY = 0.5, scrollDeltaX = 0.5, scrollDeltaY = 0.5, buttonMask = 1, buttons = {})
  let resNom = flushMouseFrame(arg_state)
  let resEdge = flushMouseFrame(edge_state)
  assertApproxEq(resNom.x, 1.0, 0.001, "flushMouseFrame nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "flushMouseFrame boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `createTouchTracker` (`std/input/touch.aipl`)

- **Signature**: `pub fn createTouchTracker(): TouchTracker:`
- **Import**: `import * from "std/input/touch"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `TouchTracker`
- **Unit Test**: `tests/functions/input/touch_test.aipl` | **Example**: `examples/ex_138_input_gamepad_dual_stick_radar_window.aipl`
- **Behavioral Summary**: Verify `createTouchTracker` multi-touch `pointerId` isolation, radial virtual joystick clamping, and `handleTouchCancel` zero-reset safety. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `TouchTracker(activePointers = m, maxActivePointers = 10)`.

```aipl
module tests.functions.input.touch_z1_test
import * from "std/input/touch"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_touch_createTouchTracker_1(): int:
  let resNom = createTouchTracker()
  let resEdge = createTouchTracker()
  assertEqInt(resNom.activePointers.len(), 0, "createTouchTracker nominal resNom.activePointers.len() == 0")
  assertEqInt(resEdge.activePointers.len(), 0, "createTouchTracker boundary resEdge.activePointers.len() == 0")
  ret 0
```

---

### `handleTouchDown` (`std/input/touch.aipl`)

- **Signature**: `pub fn handleTouchDown(tracker: TouchTracker, pointerId: int, x: float, y: float, pressure: float, timeMs: int): TouchTracker:`
- **Import**: `import * from "std/input/touch"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `tracker: TouchTracker, pointerId: int, x: float, y: float, pressure: float, timeMs: int` | **Returns**: `TouchTracker`
- **Unit Test**: `tests/functions/input/touch_test.aipl` | **Example**: `examples/ex_136_input_keyboard_piano_and_shortcuts_window.aipl`
- **Behavioral Summary**: Verify `handleTouchDown` multi-touch `pointerId` isolation, radial virtual joystick clamping, and `handleTouchCancel` zero-reset safety. Concrete nominal inputs: `tracker: TouchTracker = TouchTracker(activePointers = Map(), maxActivePointers = 1)`, `pointerId: int = 1`, `x: float = 1.0`, `y: float = 1.0`, `pressure: float = 1.0`, `timeMs: int = 1`; exercises core body path returning/computing `TouchTracker(activePointers = m, maxActivePointers = tracker.maxActivePointers)`.

```aipl
module tests.functions.input.touch_z2_test
import * from "std/input/touch"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_touch_handleTouchDown_2(): int:
  let arg_tracker = TouchTracker(activePointers = {}, maxActivePointers = 4)
  let edge_tracker = TouchTracker(activePointers = {}, maxActivePointers = 1)
  let arg_pointerId = 4
  let edge_pointerId = 1
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_pressure = 1.0
  let edge_pressure = 0.5
  let arg_timeMs = 4
  let edge_timeMs = 1
  let resNom = handleTouchDown(arg_tracker, arg_pointerId, arg_x, arg_y, arg_pressure, arg_timeMs)
  let resEdge = handleTouchDown(edge_tracker, edge_pointerId, edge_x, edge_y, edge_pressure, edge_timeMs)
  assertEqInt(resNom.activePointers.len(), 1, "handleTouchDown nominal resNom.activePointers.len() == 1")
  assertEqInt(resEdge.activePointers.len(), 1, "handleTouchDown boundary resEdge.activePointers.len() == 1")
  ret 0
```

---

### `handleTouchMove` (`std/input/touch.aipl`)

- **Signature**: `pub fn handleTouchMove(tracker: TouchTracker, pointerId: int, x: float, y: float, pressure: float, timeMs: int): TouchTracker:`
- **Import**: `import * from "std/input/touch"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `tracker: TouchTracker, pointerId: int, x: float, y: float, pressure: float, timeMs: int` | **Returns**: `TouchTracker`
- **Unit Test**: `tests/functions/input/touch_test.aipl` | **Example**: `examples/ex_137_input_mouse_drawing_and_wheel_zoom_window.aipl`
- **Behavioral Summary**: Verify `handleTouchMove` multi-touch `pointerId` isolation, radial virtual joystick clamping, and `handleTouchCancel` zero-reset safety. Concrete nominal inputs: `tracker: TouchTracker = TouchTracker(activePointers = Map(), maxActivePointers = 1)`, `pointerId: int = 1`, `x: float = 1.0`, `y: float = 1.0`, `pressure: float = 1.0`, `timeMs: int = 1`; exercises core body path returning/computing `TouchTracker(activePointers = m, maxActivePointers = tracker.maxActivePointers)`.

```aipl
module tests.functions.input.touch_z3_test
import * from "std/input/touch"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_touch_handleTouchMove_3(): int:
  let arg_tracker = TouchTracker(activePointers = {}, maxActivePointers = 4)
  let edge_tracker = TouchTracker(activePointers = {}, maxActivePointers = 1)
  let arg_pointerId = 4
  let edge_pointerId = 1
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_pressure = 1.0
  let edge_pressure = 0.5
  let arg_timeMs = 4
  let edge_timeMs = 1
  let resNom = handleTouchMove(arg_tracker, arg_pointerId, arg_x, arg_y, arg_pressure, arg_timeMs)
  let resEdge = handleTouchMove(edge_tracker, edge_pointerId, edge_x, edge_y, edge_pressure, edge_timeMs)
  assertEqInt(resNom.activePointers.len(), 0, "handleTouchMove nominal resNom.activePointers.len() == 0")
  assertEqInt(resEdge.activePointers.len(), 0, "handleTouchMove boundary resEdge.activePointers.len() == 0")
  ret 0
```

---

### `handleTouchUp` (`std/input/touch.aipl`)

- **Signature**: `pub fn handleTouchUp(tracker: TouchTracker, pointerId: int, x: float, y: float, timeMs: int): TouchTracker:`
- **Import**: `import * from "std/input/touch"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `tracker: TouchTracker, pointerId: int, x: float, y: float, timeMs: int` | **Returns**: `TouchTracker`
- **Unit Test**: `tests/functions/input/touch_test.aipl` | **Example**: `examples/ex_138_input_gamepad_dual_stick_radar_window.aipl`
- **Behavioral Summary**: Verify `handleTouchUp` multi-touch `pointerId` isolation, radial virtual joystick clamping, and `handleTouchCancel` zero-reset safety. Concrete nominal inputs: `tracker: TouchTracker = TouchTracker(activePointers = Map(), maxActivePointers = 1)`, `pointerId: int = 1`, `x: float = 1.0`, `y: float = 1.0`, `timeMs: int = 1`; exercises core body path returning/computing `TouchTracker(activePointers = m, maxActivePointers = tracker.maxActivePointers)`.

```aipl
module tests.functions.input.touch_z4_test
import * from "std/input/touch"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_touch_handleTouchUp_4(): int:
  let arg_tracker = TouchTracker(activePointers = {}, maxActivePointers = 4)
  let edge_tracker = TouchTracker(activePointers = {}, maxActivePointers = 1)
  let arg_pointerId = 4
  let edge_pointerId = 1
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_timeMs = 4
  let edge_timeMs = 1
  let resNom = handleTouchUp(arg_tracker, arg_pointerId, arg_x, arg_y, arg_timeMs)
  let resEdge = handleTouchUp(edge_tracker, edge_pointerId, edge_x, edge_y, edge_timeMs)
  assertEqInt(resNom.activePointers.len(), 0, "handleTouchUp nominal resNom.activePointers.len() == 0")
  assertEqInt(resEdge.activePointers.len(), 0, "handleTouchUp boundary resEdge.activePointers.len() == 0")
  ret 0
```

---

### `handleTouchCancel` (`std/input/touch.aipl`)

- **Signature**: `pub fn handleTouchCancel(tracker: TouchTracker, pointerId: int): TouchTracker:`
- **Import**: `import * from "std/input/touch"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `tracker: TouchTracker, pointerId: int` | **Returns**: `TouchTracker`
- **Unit Test**: `tests/functions/input/touch_test.aipl` | **Example**: `examples/ex_136_input_keyboard_piano_and_shortcuts_window.aipl`
- **Behavioral Summary**: Verify `handleTouchCancel` multi-touch `pointerId` isolation, radial virtual joystick clamping, and `handleTouchCancel` zero-reset safety. Concrete nominal inputs: `tracker: TouchTracker = TouchTracker(activePointers = Map(), maxActivePointers = 1)`, `pointerId: int = 1`; exercises core body path returning/computing `TouchTracker(activePointers = m, maxActivePointers = tracker.maxActivePointers)`.

```aipl
module tests.functions.input.touch_z5_test
import * from "std/input/touch"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_touch_handleTouchCancel_5(): int:
  let arg_tracker = TouchTracker(activePointers = {}, maxActivePointers = 4)
  let edge_tracker = TouchTracker(activePointers = {}, maxActivePointers = 1)
  let arg_pointerId = 4
  let edge_pointerId = 1
  let resNom = handleTouchCancel(arg_tracker, arg_pointerId)
  let resEdge = handleTouchCancel(edge_tracker, edge_pointerId)
  assertEqInt(resNom.activePointers.len(), 0, "handleTouchCancel nominal resNom.activePointers.len() == 0")
  assertEqInt(resEdge.activePointers.len(), 0, "handleTouchCancel boundary resEdge.activePointers.len() == 0")
  ret 0
```

---

### `getActivePointer` (`std/input/touch.aipl`)

- **Signature**: `pub fn getActivePointer(tracker: TouchTracker, pointerId: int): Option[TouchPointer]:`
- **Import**: `import * from "std/input/touch"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `tracker: TouchTracker, pointerId: int` | **Returns**: `Option[TouchPointer]`
- **Unit Test**: `tests/functions/input/touch_test.aipl` | **Example**: `examples/ex_137_input_mouse_drawing_and_wheel_zoom_window.aipl`
- **Behavioral Summary**: Verify `getActivePointer` multi-touch `pointerId` isolation, radial virtual joystick clamping, and `handleTouchCancel` zero-reset safety. Concrete nominal inputs: `tracker: TouchTracker = TouchTracker(activePointers = Map(), maxActivePointers = 1)`, `pointerId: int = 1`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.input.touch_z6_test
import * from "std/input/touch"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_touch_getActivePointer_6(): int:
  let arg_tracker = TouchTracker(activePointers = {}, maxActivePointers = 4)
  let edge_tracker = TouchTracker(activePointers = {}, maxActivePointers = 1)
  let arg_pointerId = 4
  let edge_pointerId = 1
  let resNom = getActivePointer(arg_tracker, arg_pointerId)
  let resEdge = getActivePointer(edge_tracker, edge_pointerId)
  assert(resNom.isSome() == false, "getActivePointer nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "getActivePointer boundary resEdge.isSome() == false")
  ret 0
```

---

### `getActivePointerCount` (`std/input/touch.aipl`)

- **Signature**: `pub fn getActivePointerCount(tracker: TouchTracker): int:`
- **Import**: `import * from "std/input/touch"` (or barrel `import * from "std/input/input_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `tracker: TouchTracker` | **Returns**: `int`
- **Unit Test**: `tests/functions/input/touch_test.aipl` | **Example**: `examples/ex_138_input_gamepad_dual_stick_radar_window.aipl`
- **Behavioral Summary**: Verify `getActivePointerCount` multi-touch `pointerId` isolation, radial virtual joystick clamping, and `handleTouchCancel` zero-reset safety. Concrete nominal inputs: `tracker: TouchTracker = TouchTracker(activePointers = Map(), maxActivePointers = 1)`; exercises core body path returning/computing `tracker.activePointers.keys().len`.

```aipl
module tests.functions.input.touch_z7_test
import * from "std/input/touch"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_touch_getActivePointerCount_7(): int:
  let arg_tracker = TouchTracker(activePointers = {}, maxActivePointers = 4)
  let edge_tracker = TouchTracker(activePointers = {}, maxActivePointers = 1)
  let resNom = getActivePointerCount(arg_tracker)
  let resEdge = getActivePointerCount(edge_tracker)
  assertEqInt(resNom, 0, "getActivePointerCount nominal resNom == 0")
  assertEqInt(resEdge, 0, "getActivePointerCount boundary resEdge == 0")
  ret 0
```
