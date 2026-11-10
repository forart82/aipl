[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](INDEX.md) | [Cookbook](cookbook.md) | [Stdlib Reference](../STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Chapter 10: Aura Immediate-Mode UI & Accessibility

> **Chapter Summary**: Aura immediate-mode UI: UiContext state machine, Flexbox and 12-column grid layout, Oklch theme scales, WCAG 2.1 AAA / APCA perceptual contrast auditing, gap-buffer text editing, virtualized 100k-row DataGrid, and node-graph editors.

## Table of Contents
- [Chapter 10.1: Immediate-Mode UiContext, Hot/Active State Machine & Flexbox / 12-Column Grid Layout](#chapter-101-immediate-mode-uicontext-hotactive-state-machine--flexbox--12-column-grid-layout)
- [Chapter 10.2: Oklab/Oklch Radix-12 Semantic Theme Scales & WCAG 2.1 / APCA Accessibility (ui_style & ui_a11y)](#chapter-102-oklaboklch-radix-12-semantic-theme-scales--wcag-21--apca-accessibility-ui_style--ui_a11y)
- [Chapter 10.3: Core Widgets, Gap-Buffer Text Editor, Virtualized DataGrid & Dockable Containers](#chapter-103-core-widgets-gap-buffer-text-editor-virtualized-datagrid--dockable-containers)
- [Chapter 10.4: Bezier Node-Graph Editor, Keyframe Timeline, Vector Charts & Game HUD Overlays](#chapter-104-bezier-node-graph-editor-keyframe-timeline-vector-charts--game-hud-overlays)

---

### Chapter 10.1: Immediate-Mode UiContext, Hot/Active State Machine & Flexbox / 12-Column Grid Layout

#### 1. Concept in 30 Seconds
Teach `std/ui/ui_imui` and single-pass Flexbox / CSS-Grid constraint solving in `std/ui/ui_layout`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn beginImUiFrame(ctx: ImUiContext, mouse: Vec2, mouseDown: bool): ImUiContext:` from `std/ui/ui_imui.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.ui.ui_imui_z1_test
import * from "std/ui/ui_imui"
import { Vec2 } from "std/math/vec_math"
import { pi, minInt, maxInt, clampInt, minFloat, maxFloat, clampFloat, absFloat, absInt } from "std/math/consts"
import { Color, rgba, rgb, colorHex, colorFromHexStr, colorHexStr, packColorRgba32, colorToInt, drawRect, drawRectOutline, drawRoundedRect, drawRoundedRectOutline, drawCircle, drawCircleOutline, drawLine, drawTriangle, drawEllipse, drawPolygon, drawArc, drawText, drawTextBox, drawTextCentered, drawTextRight, measureTextWidthPx, measureTextHeight, measureText, truncateText, getScreenWidth, getScreenHeight, getMouseX, getMouseY, isMouseButtonPressed, isMouseButtonReleased, isMouseInRect, isRectClicked, getTextInput, getCompositionText, getCompositionCursor, isKeyPressed, isKeyReleased, mouseWheelX, mouseWheelY, isMouseDoubleClicked, isMouseRightClicked } from "std/gfx2d/shape2d"
import { AuraRect, LayoutBox, AuraSizingAxis, AuraLayoutSpec, AuraTableResult, AuraKanbanAction, layoutInset, layoutSplitHorizontal, auraAxisFixed, auraAxisGrow, auraAxisFit, auraAxisPercent, auraSolveFlexAxis, auraLayoutStack, auraResponsiveTier, auraGrid12Row } from "std/ui/ui_layout"
import { RgbColor, HslColor, OklabColor, OklchColor, SemanticPalette, AuraSeedToken, AuraTypographyToken, defaultDarkPalette, defaultLightPalette, auraApplyStateLayer, auraTypoDisplayLarge, auraTypoHeadlineMedium, auraTypoTitleMedium, auraTypoBodyLarge, auraTypoBodyMedium, auraTypoLabelMedium, packedHexToRgb, rgbToPackedHex, lerpOklabHex, oklchToHex, apcaContrastLc, autoContrastForegroundHex, generateRadix12Scale } from "std/ui/ui_style"
import { ScissorRect, UiCanvas, pushScissor, popScissor, AspectViewport, computeAspectViewport, drawAspectLetterboxBars, unprojectMouseX, unprojectMouseY } from "std/ui/ui_canvas"
import { cycleFocusIndex, wcagContrastRatioLuma } from "std/ui/ui_a11y"
import { RichTextSpan, TextSpan, richSpanPlain, richSpansTotalLength, measureRichLineWidth } from "std/ui/ui_text"
import { Rect } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ui_imui_beginImUiFrame_1(): int:
  let arg_ctx = ImUiContext(hotId = 1, activeId = 1, mousePos = Vec2(x = 1.0, y = 1.0), isMouseDown = true)
  let edge_ctx = ImUiContext(hotId = 0, activeId = 0, mousePos = Vec2(x = 0.5, y = 0.5), isMouseDown = false)
  let arg_mouse = Vec2(x = 1.0, y = 1.0)
  let edge_mouse = Vec2(x = 0.5, y = 0.5)
  let arg_mouseDown = true
  let edge_mouseDown = false
  let resNom = beginImUiFrame(arg_ctx, arg_mouse, arg_mouseDown)
  let resEdge = beginImUiFrame(edge_ctx, edge_mouse, edge_mouseDown)
  assertEqInt(resNom.hotId, 0, "beginImUiFrame nominal resNom.hotId == 0")
  assertEqInt(resEdge.hotId, 0, "beginImUiFrame boundary resEdge.hotId == 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_190` | [examples/ex_190_ui_layout_flexbox_and_grid_solver_window.aipl](../../examples/ex_190_ui_layout_flexbox_and_grid_solver_window.aipl) | `tests/examples/ex_190_ui_layout_flexbox_and_grid_solver_window_test.aipl` | `./bin/aipl test tests/examples/ex_190_ui_layout_flexbox_and_grid_solver_window_test.aipl` |
| `ex_191` | [examples/ex_191_ui_style_dark_light_theme_studio_window.aipl](../../examples/ex_191_ui_style_dark_light_theme_studio_window.aipl) | `tests/examples/ex_191_ui_style_dark_light_theme_studio_window_test.aipl` | `./bin/aipl test tests/examples/ex_191_ui_style_dark_light_theme_studio_window_test.aipl` |

---

### Chapter 10.2: Oklab/Oklch Radix-12 Semantic Theme Scales & WCAG 2.1 / APCA Accessibility (ui_style & ui_a11y)

#### 1. Concept in 30 Seconds
Teach perceptual Oklch color themes (`std/ui/ui_style`) and keyboard focus ring / contrast verification (`std/ui/ui_a11y`).

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn createDarkTheme(): UiTheme:` from `std/ui/ui_style.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.ui.ui_style_z1_test
import * from "std/ui/ui_style"
import { ColorRgba8 } from "std/gfx/color"
import { RadixScale12 } from "std/gfx/color"
import { rgba, drawLine } from "std/gfx2d/shape2d"
import { minInt, maxInt, clampInt, maxFloat, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ui_style_createDarkTheme_1(): int:
  let resNom = createDarkTheme()
  let resEdge = createDarkTheme()
  assert(resNom.isDark == true, "createDarkTheme nominal resNom.isDark == true")
  assert(resEdge.isDark == true, "createDarkTheme boundary resEdge.isDark == true")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_192` | [examples/ex_192_ui_text_wrapping_and_richtext_window.aipl](../../examples/ex_192_ui_text_wrapping_and_richtext_window.aipl) | `tests/examples/ex_192_ui_text_wrapping_and_richtext_window_test.aipl` | `./bin/aipl test tests/examples/ex_192_ui_text_wrapping_and_richtext_window_test.aipl` |
| `ex_201` | [examples/ex_201_ui_a11y_focus_ring_and_contrast_window.aipl](../../examples/ex_201_ui_a11y_focus_ring_and_contrast_window.aipl) | `tests/examples/ex_201_ui_a11y_focus_ring_and_contrast_window_test.aipl` | `./bin/aipl test tests/examples/ex_201_ui_a11y_focus_ring_and_contrast_window_test.aipl` |

---

### Chapter 10.3: Core Widgets, Gap-Buffer Text Editor, Virtualized DataGrid & Dockable Containers

#### 1. Concept in 30 Seconds
Teach `ui_widget`, undo/redo `ui_text_edit`, O(visible_rows) `ui_datagrid`, `ui_tree`, `ui_containers`, and `ui_imui`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `fn isPointInRect(pt: Vec2, r: Rect): bool:` from `std/ui/ui_widget.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.ui.ui_widget_z1_test
import * from "std/ui/ui_widget"
import { EPSILON, clampInt, clampFloat } from "std/math/consts"
import { round } from "std/math/trig"
import { SemanticPalette } from "std/ui/ui_style"
import { Color, rgba, rgb, colorHex, drawRect, drawRectOutline, drawRoundedRect, drawRoundedRectOutline, drawCircle, drawLine, drawText, drawTextCentered, measureTextWidthPx } from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { Rect } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ui_widget_isPointInRect_1(): int:
  let arg_pt = Vec2(x = 1.0, y = 1.0)
  let edge_pt = Vec2(x = 0.5, y = 0.5)
  let arg_r = Rect(x = 1.0, y = 1.0, w = 2.0, h = 2.0)
  let edge_r = Rect(x = 0.5, y = 0.5, w = 1.0, h = 1.0)
  let resNom = isPointInRect(arg_pt, arg_r)
  let resEdge = isPointInRect(edge_pt, edge_r)
  assert(resNom == true, "isPointInRect nominal resNom == true")
  assert(resEdge == true, "isPointInRect boundary resEdge == true")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_193` | [examples/ex_193_ui_widget_retained_forms_and_tabs_window.aipl](../../examples/ex_193_ui_widget_retained_forms_and_tabs_window.aipl) | `tests/examples/ex_193_ui_widget_retained_forms_and_tabs_window_test.aipl` | `./bin/aipl test tests/examples/ex_193_ui_widget_retained_forms_and_tabs_window_test.aipl` |
| `ex_194` | [examples/ex_194_ui_imui_immediate_mode_inspector_window.aipl](../../examples/ex_194_ui_imui_immediate_mode_inspector_window.aipl) | `tests/examples/ex_194_ui_imui_immediate_mode_inspector_window_test.aipl` | `./bin/aipl test tests/examples/ex_194_ui_imui_immediate_mode_inspector_window_test.aipl` |
| `ex_195` | [examples/ex_195_ui_datagrid_one_million_rows_window.aipl](../../examples/ex_195_ui_datagrid_one_million_rows_window.aipl) | `tests/examples/ex_195_ui_datagrid_one_million_rows_window_test.aipl` | `./bin/aipl test tests/examples/ex_195_ui_datagrid_one_million_rows_window_test.aipl` |
| `ex_196` | [examples/ex_196_ui_charts_line_bar_candlestick_window.aipl](../../examples/ex_196_ui_charts_line_bar_candlestick_window.aipl) | `tests/examples/ex_196_ui_charts_line_bar_candlestick_window_test.aipl` | `./bin/aipl test tests/examples/ex_196_ui_charts_line_bar_candlestick_window_test.aipl` |
| `ex_197` | [examples/ex_197_ui_nodegraph_shader_blueprint_editor_window.aipl](../../examples/ex_197_ui_nodegraph_shader_blueprint_editor_window.aipl) | `tests/examples/ex_197_ui_nodegraph_shader_blueprint_editor_window_test.aipl` | `./bin/aipl test tests/examples/ex_197_ui_nodegraph_shader_blueprint_editor_window_test.aipl` |

---

### Chapter 10.4: Bezier Node-Graph Editor, Keyframe Timeline, Vector Charts & Game HUD Overlays

#### 1. Concept in 30 Seconds
Teach topological `ui_nodegraph`, `ui_canvas_charts`, and damage-number / minimap `ui_hud` overlays.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn computeBezierWireControlPoints(startPt: Vec2, endPt: Vec2): [Vec2]:` from `std/ui/ui_nodegraph.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.ui.ui_nodegraph_z1_test
import * from "std/ui/ui_nodegraph"
import { absFloat, maxFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ui_nodegraph_computeBezierWireControlPoints_1(): int:
  let arg_startPt = Vec2(x = 1.0, y = 1.0)
  let edge_startPt = Vec2(x = 0.5, y = 0.5)
  let arg_endPt = Vec2(x = 1.0, y = 1.0)
  let edge_endPt = Vec2(x = 0.5, y = 0.5)
  let resNom = computeBezierWireControlPoints(arg_startPt, arg_endPt)
  let resEdge = computeBezierWireControlPoints(edge_startPt, edge_endPt)
  assertEqInt(resNom.len(), 4, "computeBezierWireControlPoints nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 4, "computeBezierWireControlPoints boundary resEdge.len() == 4")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_198` | [examples/ex_198_ui_canvas_infinite_pan_zoom_board_window.aipl](../../examples/ex_198_ui_canvas_infinite_pan_zoom_board_window.aipl) | `tests/examples/ex_198_ui_canvas_infinite_pan_zoom_board_window_test.aipl` | `./bin/aipl test tests/examples/ex_198_ui_canvas_infinite_pan_zoom_board_window_test.aipl` |
| `ex_199` | [examples/ex_199_ui_hud_radar_minimap_and_toasts_window.aipl](../../examples/ex_199_ui_hud_radar_minimap_and_toasts_window.aipl) | `tests/examples/ex_199_ui_hud_radar_minimap_and_toasts_window_test.aipl` | `./bin/aipl test tests/examples/ex_199_ui_hud_radar_minimap_and_toasts_window_test.aipl` |
| `ex_200` | [examples/ex_200_ui_anim_spring_transitions_window.aipl](../../examples/ex_200_ui_anim_spring_transitions_window.aipl) | `tests/examples/ex_200_ui_anim_spring_transitions_window_test.aipl` | `./bin/aipl test tests/examples/ex_200_ui_anim_spring_transitions_window_test.aipl` |
