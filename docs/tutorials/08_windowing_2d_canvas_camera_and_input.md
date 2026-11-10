[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](INDEX.md) | [Cookbook](cookbook.md) | [Stdlib Reference](../STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Chapter 08: Windowing, 2D Canvas, Camera & Input

> **Chapter Summary**: Cross-platform windowing, 60 FPS fixed-timestep simulation accumulator, 2D vector drawing, camera pan/zoom with Squirrel Eiserloh trauma^2 shake, Wang 47-tile autotiling, 2D lighting with SDF soft shadows, and multi-device ActionMap input.

## Table of Contents
- [Chapter 08.1: Cross-Platform Window Lifecycle, Fixed-Timestep app_loop & HiDPI Monitors (std/window/*)](#chapter-081-cross-platform-window-lifecycle-fixed-timestep-app_loop--hidpi-monitors-stdwindow)
- [Chapter 08.2: Multi-Device Input Polling (Keyboard, Mouse, Gamepad, Touch) & ActionMap (std/input/*)](#chapter-082-multi-device-input-polling-keyboard-mouse-gamepad-touch--actionmap-stdinput)
- [Chapter 08.3: 2D Vector Shapes, Sprite Batching, Camera2D Trauma Shake & Wang 47-Tile Autotiling (std/gfx2d/*)](#chapter-083-2d-vector-shapes-sprite-batching-camera2d-trauma-shake--wang-47-tile-autotiling-stdgfx2d)
- [Chapter 08.4: 2D Normal-Mapped Lighting, SDF Soft Shadows, Parallax Layers & Two-Bone IK (std/gfx2d/*)](#chapter-084-2d-normal-mapped-lighting-sdf-soft-shadows-parallax-layers--two-bone-ik-stdgfx2d)

---

### Chapter 08.1: Cross-Platform Window Lifecycle, Dual Window Modes (`x11` MIT-SHM vs `glx` OpenGL), Fixed-Timestep app_loop & HiDPI Monitors (std/window/*, std/gfx2d/shape2d)

#### 1. Concept in 30 Seconds
Teach `surface`, fixed-timestep accumulator `app_loop`, `monitor`, `cursor_icon`, `clipboard`, and Dual Window Modes (`setWindowMode("x11" | "glx" | "auto")`, `getWindowMode()`):
- **Desktop Application Mode (`setWindowMode("x11")`, `--window-mode=x11`)**: Uses `libXext.so.6` MIT-SHM (`XShmPutImage`) with a native 32-bit BGRA framebuffer and analytical scanline spans (`examples/ex_251_desktop_system_monitor_dashboard_window.aipl`, `examples/ex_252_desktop_vector_diagram_studio_window.aipl`).
- **Game Hardware Mode (`setWindowMode("glx")`, `--window-mode=glx`)**: Uses `libGL.so.1` GLX (`glDrawArrays(GL_TRIANGLES, ...)` + `glXSwapBuffers`) with multi-backend polyphonic audio (`PulseAudio` -> `ALSA` -> `SDL2`, `examples/ex_253_game_glx_snake_arcade_window.aipl`..`examples/ex_258_audio_interactive_fm_piano_and_chords_window.aipl`).

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn resizeWindowSurface(surface: WindowSurface, newWidth: int, newHeight: int, scaleFactor: float): WindowSurface:` from `std/window/surface.aipl` with `./bin/aipl verify`:

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

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_131` | [examples/ex_131_window_app_loop_fixed_timestep_window.aipl](../../examples/ex_131_window_app_loop_fixed_timestep_window.aipl) | `tests/examples/ex_131_window_app_loop_fixed_timestep_window_test.aipl` | `./bin/aipl test tests/examples/ex_131_window_app_loop_fixed_timestep_window_test.aipl` |
| `ex_132` | [examples/ex_132_window_surface_letterbox_viewport_window.aipl](../../examples/ex_132_window_surface_letterbox_viewport_window.aipl) | `tests/examples/ex_132_window_surface_letterbox_viewport_window_test.aipl` | `./bin/aipl test tests/examples/ex_132_window_surface_letterbox_viewport_window_test.aipl` |
| `ex_133` | [examples/ex_133_window_display_multi_monitor_dpi_window.aipl](../../examples/ex_133_window_display_multi_monitor_dpi_window.aipl) | `tests/examples/ex_133_window_display_multi_monitor_dpi_window_test.aipl` | `./bin/aipl test tests/examples/ex_133_window_display_multi_monitor_dpi_window_test.aipl` |
| `ex_134` | [examples/ex_134_window_cursor_custom_crosshair_window.aipl](../../examples/ex_134_window_cursor_custom_crosshair_window.aipl) | `tests/examples/ex_134_window_cursor_custom_crosshair_window_test.aipl` | `./bin/aipl test tests/examples/ex_134_window_cursor_custom_crosshair_window_test.aipl` |
| `ex_135` | [examples/ex_135_window_clipboard_history_manager_window.aipl](../../examples/ex_135_window_clipboard_history_manager_window.aipl) | `tests/examples/ex_135_window_clipboard_history_manager_window_test.aipl` | `./bin/aipl test tests/examples/ex_135_window_clipboard_history_manager_window_test.aipl` |

---

### Chapter 08.2: Multi-Device Input Polling (Keyboard, Mouse, Gamepad, Touch) & ActionMap (std/input/*)

#### 1. Concept in 30 Seconds
Teach `keyboard`, `mouse`, radial-deadzone `gamepad`, multi-finger `touch`, `gesture`, and rebindable `action_map`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn createActionMap(): InputActionMap:` from `std/input/action_map.aipl` with `./bin/aipl verify`:

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

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_136` | [examples/ex_136_input_keyboard_piano_and_shortcuts_window.aipl](../../examples/ex_136_input_keyboard_piano_and_shortcuts_window.aipl) | `tests/examples/ex_136_input_keyboard_piano_and_shortcuts_window_test.aipl` | `./bin/aipl test tests/examples/ex_136_input_keyboard_piano_and_shortcuts_window_test.aipl` |
| `ex_137` | [examples/ex_137_input_mouse_drawing_and_wheel_zoom_window.aipl](../../examples/ex_137_input_mouse_drawing_and_wheel_zoom_window.aipl) | `tests/examples/ex_137_input_mouse_drawing_and_wheel_zoom_window_test.aipl` | `./bin/aipl test tests/examples/ex_137_input_mouse_drawing_and_wheel_zoom_window_test.aipl` |
| `ex_138` | [examples/ex_138_input_gamepad_dual_stick_radar_window.aipl](../../examples/ex_138_input_gamepad_dual_stick_radar_window.aipl) | `tests/examples/ex_138_input_gamepad_dual_stick_radar_window_test.aipl` | `./bin/aipl test tests/examples/ex_138_input_gamepad_dual_stick_radar_window_test.aipl` |
| `ex_139` | [examples/ex_139_input_touch_multitouch_visualizer_window.aipl](../../examples/ex_139_input_touch_multitouch_visualizer_window.aipl) | `tests/examples/ex_139_input_touch_multitouch_visualizer_window_test.aipl` | `./bin/aipl test tests/examples/ex_139_input_touch_multitouch_visualizer_window_test.aipl` |
| `ex_140` | [examples/ex_140_input_gesture_virtual_joystick_window.aipl](../../examples/ex_140_input_gesture_virtual_joystick_window.aipl) | `tests/examples/ex_140_input_gesture_virtual_joystick_window_test.aipl` | `./bin/aipl test tests/examples/ex_140_input_gesture_virtual_joystick_window_test.aipl` |
| `ex_141` | [examples/ex_141_input_action_map_rebind_menu_window.aipl](../../examples/ex_141_input_action_map_rebind_menu_window.aipl) | `tests/examples/ex_141_input_action_map_rebind_menu_window_test.aipl` | `./bin/aipl test tests/examples/ex_141_input_action_map_rebind_menu_window_test.aipl` |

---

### Chapter 08.3: 2D Vector Shapes, Sprite Batching, Camera2D Trauma Shake & Wang 47-Tile Autotiling (std/gfx2d/*)

#### 1. Concept in 30 Seconds
Teach `shape2d`, `sprite2d`, `camera2d` (with Squirrel Eiserloh Trauma^2 screen shake), `tilemap2d`, `nine_slice`, `text2d`, and `canvas2d`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn createCamera2D(viewportW: float = 800.0, viewportH: float = 600.0, zoom: float = 1.0): Camera2D:` from `std/gfx2d/camera2d.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.gfx2d.camera2d_z1_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_createCamera2D_1(): int:
  let arg_viewportW = 2.0
  let edge_viewportW = 1.0
  let arg_viewportH = 2.0
  let edge_viewportH = 1.0
  let arg_zoom = 1.0
  let edge_zoom = 0.5
  let resNom = createCamera2D(arg_viewportW, arg_viewportH, arg_zoom)
  let resEdge = createCamera2D(edge_viewportW, edge_viewportH, edge_zoom)
  assertApproxEq(resNom.zoom, 1.0, 0.001, "createCamera2D nominal resNom.zoom ~= 1.0")
  assertApproxEq(resEdge.zoom, 0.5, 0.001, "createCamera2D boundary resEdge.zoom ~= 0.5")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_162` | [examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl](../../examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl) | `tests/examples/ex_162_gfx2d_shape2d_vector_gallery_window_test.aipl` | `./bin/aipl test tests/examples/ex_162_gfx2d_shape2d_vector_gallery_window_test.aipl` |
| `ex_163` | [examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl](../../examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl) | `tests/examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window_test.aipl` | `./bin/aipl test tests/examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window_test.aipl` |
| `ex_164` | [examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl](../../examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl) | `tests/examples/ex_164_gfx2d_camera2d_trauma_screenshake_window_test.aipl` | `./bin/aipl test tests/examples/ex_164_gfx2d_camera2d_trauma_screenshake_window_test.aipl` |
| `ex_165` | [examples/ex_165_gfx2d_sprite2d_transform_hierarchy_window.aipl](../../examples/ex_165_gfx2d_sprite2d_transform_hierarchy_window.aipl) | `tests/examples/ex_165_gfx2d_sprite2d_transform_hierarchy_window_test.aipl` | `./bin/aipl test tests/examples/ex_165_gfx2d_sprite2d_transform_hierarchy_window_test.aipl` |
| `ex_166` | [examples/ex_166_gfx2d_sprite_anim2d_state_machine_window.aipl](../../examples/ex_166_gfx2d_sprite_anim2d_state_machine_window.aipl) | `tests/examples/ex_166_gfx2d_sprite_anim2d_state_machine_window_test.aipl` | `./bin/aipl test tests/examples/ex_166_gfx2d_sprite_anim2d_state_machine_window_test.aipl` |
| `ex_167` | [examples/ex_167_gfx2d_tilemap_autotile_bitmask_window.aipl](../../examples/ex_167_gfx2d_tilemap_autotile_bitmask_window.aipl) | `tests/examples/ex_167_gfx2d_tilemap_autotile_bitmask_window_test.aipl` | `./bin/aipl test tests/examples/ex_167_gfx2d_tilemap_autotile_bitmask_window_test.aipl` |

---

### Chapter 08.4: 2D Normal-Mapped Lighting, SDF Soft Shadows, Parallax Layers & Two-Bone IK (std/gfx2d/*)

#### 1. Concept in 30 Seconds
Teach 2D point lighting (`light2d`), 1D shadow-ray visibility (`shadow2d`), multi-layer `parallax2d`, and analytic 2-bone `skeleton2d` IK.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn createPointLight2D(pos: Vec2, radius: float, color: ColorRgba8, intensity: float = 1.0): Light2D:` from `std/gfx2d/light2d.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.gfx2d.light2d_z1_test
import * from "std/gfx2d/light2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_light2d_createPointLight2D_1(): int:
  let arg_pos = Vec2(x = 1.0, y = 1.0)
  let edge_pos = Vec2(x = 0.5, y = 0.5)
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_color = ColorRgba8(r = 2, g = 2, b = 4, a = 2)
  let edge_color = ColorRgba8(r = 0, g = 0, b = 1, a = 0)
  let arg_intensity = 1.0
  let edge_intensity = 0.5
  let resNom = createPointLight2D(arg_pos, arg_radius, arg_color, arg_intensity)
  let resEdge = createPointLight2D(edge_pos, edge_radius, edge_color, edge_intensity)
  assertApproxEq(resNom.radius, 2.0, 0.001, "createPointLight2D nominal resNom.radius ~= 2.0")
  assertApproxEq(resEdge.radius, 1.0, 0.001, "createPointLight2D boundary resEdge.radius ~= 1.0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_170` | [examples/ex_170_gfx2d_filter2d_convolution_blur_window.aipl](../../examples/ex_170_gfx2d_filter2d_convolution_blur_window.aipl) | `tests/examples/ex_170_gfx2d_filter2d_convolution_blur_window_test.aipl` | `./bin/aipl test tests/examples/ex_170_gfx2d_filter2d_convolution_blur_window_test.aipl` |
| `ex_171` | [examples/ex_171_gfx2d_ninepatch2d_scalable_panels_window.aipl](../../examples/ex_171_gfx2d_ninepatch2d_scalable_panels_window.aipl) | `tests/examples/ex_171_gfx2d_ninepatch2d_scalable_panels_window_test.aipl` | `./bin/aipl test tests/examples/ex_171_gfx2d_ninepatch2d_scalable_panels_window_test.aipl` |
| `ex_172` | [examples/ex_172_gfx2d_skeletal2d_ik_bone_rig_window.aipl](../../examples/ex_172_gfx2d_skeletal2d_ik_bone_rig_window.aipl) | `tests/examples/ex_172_gfx2d_skeletal2d_ik_bone_rig_window_test.aipl` | `./bin/aipl test tests/examples/ex_172_gfx2d_skeletal2d_ik_bone_rig_window_test.aipl` |
| `ex_173` | [examples/ex_173_gfx3d_primitives3d_platonic_solids_window.aipl](../../examples/ex_173_gfx3d_primitives3d_platonic_solids_window.aipl) | `tests/examples/ex_173_gfx3d_primitives3d_platonic_solids_window_test.aipl` | `./bin/aipl test tests/examples/ex_173_gfx3d_primitives3d_platonic_solids_window_test.aipl` |
