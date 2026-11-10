[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 26: `gfx2d` API Reference

> Complete API reference manual for AIPL standard library domain `gfx2d` (420 callable functions & methods across ["std/gfx2d/batch2d.aipl", "std/gfx2d/camera2d.aipl", "std/gfx2d/filter2d.aipl", "std/gfx2d/gfx2d_mod.aipl", "std/gfx2d/iso_projector2d.aipl", "std/gfx2d/light2d.aipl", "std/gfx2d/ninepatch2d.aipl", "std/gfx2d/shape2d.aipl", "std/gfx2d/skeletal2d.aipl", "std/gfx2d/sprite2d.aipl", "std/gfx2d/sprite_anim2d.aipl", "std/gfx2d/tilemap_renderer2d.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `gfx2d`
- **Target Source Modules**: ["std/gfx2d/batch2d.aipl", "std/gfx2d/camera2d.aipl", "std/gfx2d/filter2d.aipl", "std/gfx2d/gfx2d_mod.aipl", "std/gfx2d/iso_projector2d.aipl", "std/gfx2d/light2d.aipl", "std/gfx2d/ninepatch2d.aipl", "std/gfx2d/shape2d.aipl", "std/gfx2d/skeletal2d.aipl", "std/gfx2d/sprite2d.aipl", "std/gfx2d/sprite_anim2d.aipl", "std/gfx2d/tilemap_renderer2d.aipl"]
- **Total Callable Functions & Methods**: 422 (including `setWindowMode(mode: str)` and `getWindowMode(): str` in `std/gfx2d/shape2d.aipl`)
- **Total Data Types (`struct` & `enum`)**: 65
- **Dual Window Modes & Analytical Scanline Rasterizer (`std/gfx2d/shape2d.aipl`, `runtime/rt_gui_audio.c`)**:
  - `setWindowMode("x11" | "glx" | "auto")` and `getWindowMode(): str` select between Mode 1 (`"x11"` / `"app"`: X11 + MIT-SHM `XShmPutImage` zero-copy 32-bit BGRA desktop app mode, `examples/ex_251`–`ex_252`) and Mode 2 (`"glx"` / `"game"`: X11 + `libGL.so.1` GLX hardware vertex batching via `glDrawArrays(GL_TRIANGLES, ...)` and `glXSwapBuffers`, `examples/ex_253`–`ex_255`).
  - Analytical scanline span rasterization for `drawEllipse`, `drawTriangle`, `drawCircleOutline`, `drawRectGradientH`, `drawPixelBuffer`, and `drawImageSub` eliminates inner per-pixel division/sqrt loops.
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(65 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `BatchVertex2D` | `pub struct` | `std/gfx2d/batch2d.aipl` | `x: float`, `y: float`, `u: float`, `v: float`, `colorRgba: int` | `BatchVertex2D(x, y, u, v, colorRgba)` |
| `BatchDrawCall` | `pub struct` | `std/gfx2d/batch2d.aipl` | `textureId: int`, `blendMode: int`, `startIndex: int`, `indexCount: int` | `BatchDrawCall(textureId, blendMode, startIndex, indexCount)` |
| `SpriteBatch2D` | `pub struct` | `std/gfx2d/batch2d.aipl` | `maxQuads: int`, `vertices: [BatchVertex2D]`, `indices: [int]`, `drawCalls: [BatchDrawCall]`, `currentTexture: int`, `currentBlend: int` | `SpriteBatch2D(maxQuads, vertices, indices, drawCalls, currentTexture, currentBlend)` |
| `SpriteFrame` | `pub struct` | `std/gfx2d/batch2d.aipl` | `u0: float`, `v0: float`, `u1: float`, `v1: float`, `w: int`, `h: int` | `SpriteFrame(u0, v0, u1, v1, w, h)` |
| `SpriteAnimation` | `pub struct` | `std/gfx2d/batch2d.aipl` | `frames: [SpriteFrame]`, `fps: float`, `looping: bool`, `pingPong: bool`, `elapsed: float` | `SpriteAnimation(frames, fps, looping, pingPong, elapsed)` |
| `SpriteTransform2D` | `pub struct` | `std/gfx2d/batch2d.aipl` | `x: float`, `y: float`, `w: float`, `h: float`, `rotRad: float`, `pivotX: float`, `pivotY: float`, `tintHex: int`, `flipX: bool`, `flipY: bool` | `SpriteTransform2D(x, y, w, h, rotRad, pivotX, pivotY, tintHex, flipX, flipY)` |
| `Camera2D` | `pub struct` | `std/gfx2d/camera2d.aipl` | `center: Vec2 = Vec2(x = 0.0`, `y = 0.0` | `Camera2D(center, y = 0.0)` |
| `ViewportBounds2D` | `pub struct` | `std/gfx2d/camera2d.aipl` | `minX: float`, `minY: float`, `maxX: float`, `maxY: float` | `ViewportBounds2D(minX, minY, maxX, maxY)` |
| `SpriteClip` | `pub struct` | `std/gfx2d/camera2d.aipl` | `name: str`, `startFrame: int`, `frameCount: int`, `fps: float`, `looping: bool` | `SpriteClip(name, startFrame, frameCount, fps, looping)` |
| `SpriteAnimator` | `pub struct` | `std/gfx2d/camera2d.aipl` | `currentClip: str`, `frameIndex: int`, `timer: float`, `playing: bool`, `flipX: bool` | `SpriteAnimator(currentClip, frameIndex, timer, playing, flipX)` |
| `PlatformerFeel` | `pub struct` | `std/gfx2d/camera2d.aipl` | `coyoteTimer: float`, `jumpBufferTimer: float`, `hitStopTimer: float`, `timeScale: float` | `PlatformerFeel(coyoteTimer, jumpBufferTimer, hitStopTimer, timeScale)` |
| `FpsTelemetry` | `pub struct` | `std/gfx2d/camera2d.aipl` | `maxFps: int`, `currentFps: int`, `frameTimeMs: float` | `FpsTelemetry(maxFps, currentFps, frameTimeMs)` |
| `FixedStepAccumulator` | `pub struct` | `std/gfx2d/camera2d.aipl` | `fixedDt: float`, `maxFrameDt: float`, `accumulator: float`, `stepsToRun: int`, `alpha: float`, `totalTicks: int` | `FixedStepAccumulator(fixedDt, maxFrameDt, accumulator, stepsToRun, alpha, totalTicks)` |
| `SimClock` | `pub struct` | `std/gfx2d/camera2d.aipl` | `tick: int`, `fixedDt: float`, `simTimeSec: float`, `wallTimeSec: float`, `timeScale: float`, `paused: bool` | `SimClock(tick, fixedDt, simTimeSec, wallTimeSec, timeScale, paused)` |
| `SceneStack` | `pub struct` | `std/gfx2d/camera2d.aipl` | `scenes: [str]` | `SceneStack(scenes)` |
| `ReplayBuffer` | `pub struct` | `std/gfx2d/camera2d.aipl` | `ticks: [int]`, `inputs: [int]`, `stateHashes: [int]` | `ReplayBuffer(ticks, inputs, stateHashes)` |
| `ConvolutionKernel2D` | `pub struct` | `std/gfx2d/filter2d.aipl` | `size: int`, `weights: [float]` | `ConvolutionKernel2D(size, weights)` |
| `DropShadowConfig2D` | `pub struct` | `std/gfx2d/filter2d.aipl` | `offset: Vec2`, `blurRadius: float`, `color: ColorRgba8` | `DropShadowConfig2D(offset, blurRadius, color)` |
| `FxParticle` | `pub struct` | `std/gfx2d/filter2d.aipl` | `x: float`, `y: float`, `vx: float`, `vy: float`, `colorStart: Color`, `colorEnd: Color`, `color: Color`, `life: float`, `maxLife: float`, `size: float`, `active: bool` | `FxParticle(x, y, vx, vy, colorStart, colorEnd, color, life, maxLife, size, active)` |
| `CameraShake2D` | `pub struct` | `std/gfx2d/filter2d.aipl` | `trauma: float`, `decayRate: float`, `maxOffsetPx: float`, `maxAngleRad: float`, `timeAcc: float`, `offsetX: float`, `offsetY: float`, `angleRad: float` | `CameraShake2D(trauma, decayRate, maxOffsetPx, maxAngleRad, timeAcc, offsetX, offsetY, angleRad)` |
| `HitStopState` | `pub struct` | `std/gfx2d/filter2d.aipl` | `remainingSec: float`, `timeScale: float` | `HitStopState(remainingSec, timeScale)` |
| `HitStopTimer` | `pub struct` | `std/gfx2d/filter2d.aipl` | `remainingSec: float`, `timeScale: float` | `HitStopTimer(remainingSec, timeScale)` |
| `IsoTileCoord` | `pub struct` | `std/gfx2d/iso_projector2d.aipl` | `col: int`, `row: int`, `elevation: float` | `IsoTileCoord(col, row, elevation)` |
| `IsoProjector2D` | `pub struct` | `std/gfx2d/iso_projector2d.aipl` | `tileWidth: float`, `tileHeight: float`, `elevationScale: float`, `projectionType: int` | `IsoProjector2D(tileWidth, tileHeight, elevationScale, projectionType)` |
| `PainterSortItem` | `pub struct` | `std/gfx2d/iso_projector2d.aipl` | `entityId: int`, `sortKey: float`, `drawOrder: int` | `PainterSortItem(entityId, sortKey, drawOrder)` |
| `HexCoord` | `pub struct` | `std/gfx2d/iso_projector2d.aipl` | `q: int`, `r: int` | `HexCoord(q, r)` |
| `IsoCoord` | `pub struct` | `std/gfx2d/iso_projector2d.aipl` | `col: int`, `row: int`, `height: float` | `IsoCoord(col, row, height)` |
| `IsoGridMap` | `pub struct` | `std/gfx2d/iso_projector2d.aipl` | `cols: int`, `rows: int`, `tileW: float`, `tileH: float`, `heights: [float]` | `IsoGridMap(cols, rows, tileW, tileH, heights)` |
| `IsoCamera2D` | `pub struct` | `std/gfx2d/iso_projector2d.aipl` | `originX: float`, `originY: float`, `tileW: float`, `tileH: float`, `zoom: float` | `IsoCamera2D(originX, originY, tileW, tileH, zoom)` |
| `IsoCamera25D` | `pub struct` | `std/gfx2d/iso_projector2d.aipl` | `camX: float`, `camY: float`, `camZ: float`, `zoom: float`, `yawDeg: float`, `pitchDeg: float`, `tileW: float`, `tileH: float`, `heightScale: float`, `perspectiveMode: int` | `IsoCamera25D(camX, camY, camZ, zoom, yawDeg, pitchDeg, tileW, tileH, heightScale, perspectiveMode)` |
| `HexCoordAxial` | `pub struct` | `std/gfx2d/iso_projector2d.aipl` | `q: int`, `r: int`, `elevation: float` | `HexCoordAxial(q, r, elevation)` |
| `Light2D` | `pub struct` | `std/gfx2d/light2d.aipl` | `position: Vec2`, `radius: float`, `color: ColorRgba8`, `intensity: float`, `spotAngleRad: float`, `spotDir: Vec2` | `Light2D(position, radius, color, intensity, spotAngleRad, spotDir)` |
| `OccluderSegment2D` | `pub struct` | `std/gfx2d/light2d.aipl` | `p0: Vec2`, `p1: Vec2` | `OccluderSegment2D(p0, p1)` |
| `ShadowMap1D` | `pub struct` | `std/gfx2d/light2d.aipl` | `resolution: int`, `distances: [float]` | `ShadowMap1D(resolution, distances)` |
| `SliceInsets2D` | `pub struct` | `std/gfx2d/ninepatch2d.aipl` | `left: float`, `top: float`, `right: float`, `bottom: float` | `SliceInsets2D(left, top, right, bottom)` |
| `NinePatch2D` | `pub struct` | `std/gfx2d/ninepatch2d.aipl` | `textureId: int`, `imageSize: Vec2`, `insets: SliceInsets2D`, `drawMode: int` | `NinePatch2D(textureId, imageSize, insets, drawMode)` |
| `StrokeStyle2D` | `pub struct` | `std/gfx2d/shape2d.aipl` | `width: float`, `color: ColorRgba8`, `capStyle: int`, `joinStyle: int` | `StrokeStyle2D(width, color, capStyle, joinStyle)` |
| `Color` | `pub struct` | `std/gfx2d/shape2d.aipl` | `r: float`, `g: float`, `b: float`, `a: float` | `Color(r, g, b, a)` |
| `Transform2D` | `pub struct` | `std/gfx2d/shape2d.aipl` | `tx: float`, `ty: float`, `rotRad: float`, `sx: float`, `sy: float` | `Transform2D(tx, ty, rotRad, sx, sy)` |
| `PointerEvent` | `pub struct` | `std/gfx2d/shape2d.aipl` | `x: float`, `y: float`, `button: int`, `kind: str` | `PointerEvent(x, y, button, kind)` |
| `Paint2D` | `pub struct` | `std/gfx2d/shape2d.aipl` | `fillColor: Color`, `strokeColor: Color`, `strokeWidth: float`, `blendMode: int`, `antiAlias: bool` | `Paint2D(fillColor, strokeColor, strokeWidth, blendMode, antiAlias)` |
| `Path2D` | `pub struct` | `std/gfx2d/shape2d.aipl` | `points: [Vec2]`, `closed: bool`, `subpathStarts: [int]` | `Path2D(points, closed, subpathStarts)` |
| `RenderCommand2D` | `pub struct` | `std/gfx2d/shape2d.aipl` | `kind: str`, `x: float`, `y: float`, `w: float`, `h: float`, `radius: float`, `text: str`, `zOrder: int`, `paint: Paint2D` | `RenderCommand2D(kind, x, y, w, h, radius, text, zOrder, paint)` |
| `RenderGroup2D` | `pub struct` | `std/gfx2d/shape2d.aipl` | `id: str`, `transform: Transform2D`, `visible: bool`, `opacity: float`, `commands: [RenderCommand2D]` | `RenderGroup2D(id, transform, visible, opacity, commands)` |
| `Bone2D` | `pub struct` | `std/gfx2d/skeletal2d.aipl` | `name: str`, `length: float`, `localAngleRad: float = 0.0`, `worldPosition: Vec2 = Vec2(x = 0.0`, `y = 0.0` | `Bone2D(name, length, localAngleRad, worldPosition, y = 0.0)` |
| `Skeleton2D` | `pub struct` | `std/gfx2d/skeletal2d.aipl` | `bones: [Bone2D]` | `Skeleton2D(bones)` |
| `IkSolution2D` | `pub struct` | `std/gfx2d/skeletal2d.aipl` | `joint1Angle: float`, `joint2Angle: float`, `isReachable: bool` | `IkSolution2D(joint1Angle, joint2Angle, isReachable)` |
| `BoneNode2D` | `pub struct` | `std/gfx2d/skeletal2d.aipl` | `name: str`, `parentIndex: int`, `length: float`, `localAngleDeg: float`, `worldStartX: float`, `worldStartY: float`, `worldEndX: float`, `worldEndY: float`, `worldAngleDeg: float` | `BoneNode2D(name, parentIndex, length, localAngleDeg, worldStartX, worldStartY, worldEndX, worldEndY, worldAngleDeg)` |
| `TwoBoneIKResult` | `pub struct` | `std/gfx2d/skeletal2d.aipl` | `shoulderAngleDeg: float`, `elbowAngleDeg: float`, `elbowX: float`, `elbowY: float`, `effectorX: float`, `effectorY: float` | `TwoBoneIKResult(shoulderAngleDeg, elbowAngleDeg, elbowX, elbowY, effectorX, effectorY)` |
| `UvRect` | `pub struct` | `std/gfx2d/sprite2d.aipl` | `u0: float`, `v0: float`, `u1: float`, `v1: float` | `UvRect(u0, v0, u1, v1)` |
| `SpriteOrigin` | `pub struct` | `std/gfx2d/sprite2d.aipl` | `xRatio: float`, `yRatio: float` | `SpriteOrigin(xRatio, yRatio)` |
| `Sprite2D` | `pub struct` | `std/gfx2d/sprite2d.aipl` | `textureId: int`, `uv: UvRect`, `size: Vec2`, `origin: SpriteOrigin`, `position: Vec2`, `rotationRad: float`, `scale: Vec2`, `tint: ColorRgba8`, `flipX: bool`, `flipY: bool`, `zOrder: int` | `Sprite2D(textureId, uv, size, origin, position, rotationRad, scale, tint, flipX, flipY, zOrder)` |
| `Tween` | `pub struct` | `std/gfx2d/sprite2d.aipl` | `startVal: float`, `endVal: float`, `durationMs: float`, `elapsedMs: float`, `easing: str`, `looping: bool`, `pingPong: bool`, `forward: bool`, `finished: bool` | `Tween(startVal, endVal, durationMs, elapsedMs, easing, looping, pingPong, forward, finished)` |
| `TweenSequence` | `pub struct` | `std/gfx2d/sprite2d.aipl` | `steps: [Tween]`, `currentIndex: int`, `looping: bool`, `finished: bool` | `TweenSequence(steps, currentIndex, looping, finished)` |
| `SpriteAnimationFrame2D` | `pub struct` | `std/gfx2d/sprite_anim2d.aipl` | `uv: UvRect`, `durationSec: float`, `eventTrigger: str` | `SpriteAnimationFrame2D(uv, durationSec, eventTrigger)` |
| `SpriteAnimationClip2D` | `pub struct` | `std/gfx2d/sprite_anim2d.aipl` | `name: str`, `frames: [SpriteAnimationFrame2D]`, `loopMode: int` | `SpriteAnimationClip2D(name, frames, loopMode)` |
| `SpriteAnimator2D` | `pub struct` | `std/gfx2d/sprite_anim2d.aipl` | `currentClip: SpriteAnimationClip2D`, `currentFrameIdx: int`, `elapsedTimeSec: float`, `isPlaying: bool`, `isFinished: bool` | `SpriteAnimator2D(currentClip, currentFrameIdx, elapsedTimeSec, isPlaying, isFinished)` |
| `AnimClip` | `pub struct` | `std/gfx2d/sprite_anim2d.aipl` | `name: str`, `startFrame: int`, `frameCount: int`, `fps: float`, `looping: bool`, `fallbackState: str` | `AnimClip(name, startFrame, frameCount, fps, looping, fallbackState)` |
| `AnimStateMachine` | `pub struct` | `std/gfx2d/sprite_anim2d.aipl` | `currentState: str`, `currentFrameOffset: int`, `accumMs: float`, `clips: [AnimClip]`, `transitionCount: int` | `AnimStateMachine(currentState, currentFrameOffset, accumMs, clips, transitionCount)` |
| `AnimClipEx` | `pub struct` | `std/gfx2d/sprite_anim2d.aipl` | `name: str`, `startFrame: int`, `frameCount: int`, `fps: float`, `mode: int` | `AnimClipEx(name, startFrame, frameCount, fps, mode)` |
| `TilemapLayer2D` | `pub struct` | `std/gfx2d/tilemap_renderer2d.aipl` | `layerId: int`, `width: int`, `height: int`, `tiles: [int]`, `zOrder: int`, `opacity: float` | `TilemapLayer2D(layerId, width, height, tiles, zOrder, opacity)` |
| `WangBlob47Autotiler` | `pub struct` | `std/gfx2d/tilemap_renderer2d.aipl` | `transitionTable: [int]` | `WangBlob47Autotiler(transitionTable)` |
| `Tilemap2D` | `pub struct` | `std/gfx2d/tilemap_renderer2d.aipl` | `width: int`, `height: int`, `tileSize: float`, `tiles: [int]`, `solidIds: [int]`, `spawnX: float`, `spawnY: float` | `Tilemap2D(width, height, tileSize, tiles, solidIds, spawnX, spawnY)` |
| `SlideResult2D` | `pub struct` | `std/gfx2d/tilemap_renderer2d.aipl` | `x: float`, `y: float`, `vx: float`, `vy: float`, `hitX: bool`, `hitY: bool`, `onGround: bool` | `SlideResult2D(x, y, vx, vy, hitX, hitY, onGround)` |
| `TileRaycastHit2D` | `pub struct` | `std/gfx2d/tilemap_renderer2d.aipl` | `hit: bool`, `col: int`, `row: int`, `hitX: float`, `hitY: float`, `dist: float`, `normalX: float`, `normalY: float` | `TileRaycastHit2D(hit, col, row, hitX, hitY, dist, normalX, normalY)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/gfx2d/batch2d.aipl` | `createSpriteBatch2D` | `pub fn createSpriteBatch2D(maxQuads: int = 2048): SpriteBatch2D:` | `tests/functions/gfx2d/batch2d_test.aipl` |
| `2` | `std/gfx2d/batch2d.aipl` | `beginSpriteBatch` | `pub fn beginSpriteBatch(batch: SpriteBatch2D): SpriteBatch2D:` | `tests/functions/gfx2d/batch2d_test.aipl` |
| `3` | `std/gfx2d/batch2d.aipl` | `pushBatchQuad` | `pub fn pushBatchQuad(batch: SpriteBatch2D, textureId: int, blendMode: int, v0: BatchVertex2D, v1: BatchVertex2D, v2: BatchVertex2D, v3: BatchVertex2D): SpriteBatch2D:` | `tests/functions/gfx2d/batch2d_test.aipl` |
| `4` | `std/gfx2d/batch2d.aipl` | `flushSpriteBatch` | `pub fn flushSpriteBatch(batch: SpriteBatch2D): SpriteBatch2D:` | `tests/functions/gfx2d/batch2d_test.aipl` |
| `5` | `std/gfx2d/batch2d.aipl` | `spriteAtlasFrame` | `pub fn spriteAtlasFrame(col: int, row: int, cellW: int, cellH: int, sheetW: int, sheetH: int): SpriteFrame:` | `tests/functions/gfx2d/batch2d_test.aipl` |
| `6` | `std/gfx2d/batch2d.aipl` | `spriteAnimStep` | `pub fn spriteAnimStep(mut anim: SpriteAnimation, dt: float): SpriteAnimation:` | `tests/functions/gfx2d/batch2d_test.aipl` |
| `7` | `std/gfx2d/batch2d.aipl` | `spriteAnimSampleFrame` | `pub fn spriteAnimSampleFrame(anim: SpriteAnimation): SpriteFrame:` | `tests/functions/gfx2d/batch2d_test.aipl` |
| `8` | `std/gfx2d/batch2d.aipl` | `drawSpriteTransformed` | `pub fn drawSpriteTransformed(imgId: int, tr: SpriteTransform2D): void:` | `tests/functions/gfx2d/batch2d_test.aipl` |
| `9` | `std/gfx2d/batch2d.aipl` | `drawSpriteNineSlice` | `pub fn drawSpriteNineSlice(imgId: int, sx: float, sy: float, sw: float, sh: float, dx: float, dy: float, dw: float, dh: float, left: float, top: float, right: float, bottom: float): void:` | `tests/functions/gfx2d/batch2d_test.aipl` |
| `10` | `std/gfx2d/camera2d.aipl` | `createCamera2D` | `pub fn createCamera2D(viewportW: float = 800.0, viewportH: float = 600.0, zoom: float = 1.0): Camera2D:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `11` | `std/gfx2d/camera2d.aipl` | `camera2DNew` | `pub fn camera2DNew(a: float = 800.0, b: float = 600.0, zoom: float = 1.0, viewportW: float = -1.0, viewportH: float = -1.0): Camera2D:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `12` | `std/gfx2d/camera2d.aipl` | `setCameraCenter` | `pub fn setCameraCenter(cam: Camera2D, center: Vec2): Camera2D:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `13` | `std/gfx2d/camera2d.aipl` | `setCameraZoom` | `pub fn setCameraZoom(cam: Camera2D, zoom: float): Camera2D:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `14` | `std/gfx2d/camera2d.aipl` | `addCameraTrauma` | `pub fn addCameraTrauma(cam: Camera2D, amount: float): Camera2D:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `15` | `std/gfx2d/camera2d.aipl` | `camera2DAddTrauma` | `pub fn camera2DAddTrauma(cam: Camera2D, amount: float): Camera2D:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `16` | `std/gfx2d/camera2d.aipl` | `updateCameraShake` | `pub fn updateCameraShake(cam: Camera2D, dt: float, decayRate: float = 1.0): Camera2D:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `17` | `std/gfx2d/camera2d.aipl` | `computeCameraShakeOffset` | `pub fn computeCameraShakeOffset(cam: Camera2D, seedTime: float, maxAngleRad: float = 0.1, maxOffsetPx: float = 16.0): Vec2:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `18` | `std/gfx2d/camera2d.aipl` | `worldToScreen2D` | `pub fn worldToScreen2D(cam: Camera2D, worldPt: Vec2): Vec2:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `19` | `std/gfx2d/camera2d.aipl` | `screenToWorld2D` | `pub fn screenToWorld2D(cam: Camera2D, screenPt: Vec2): Vec2:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `20` | `std/gfx2d/camera2d.aipl` | `getCameraVisibleBounds` | `pub fn getCameraVisibleBounds(cam: Camera2D): ViewportBounds2D:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `21` | `std/gfx2d/camera2d.aipl` | `camera2DSmoothFollow` | `pub fn camera2DSmoothFollow(cam: Camera2D, targetX: float, targetY: float, stiffness: float, dt: float): Camera2D:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `22` | `std/gfx2d/camera2d.aipl` | `camera2DFollow` | `pub fn camera2DFollow(cam: Camera2D, targetX: float, targetY: float, smoothSpeed: float, dt: float, frameSeed: int): Camera2D:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `23` | `std/gfx2d/camera2d.aipl` | `camera2DFollowExact` | `pub fn camera2DFollowExact(cam: Camera2D, targetX: float, targetY: float, smoothSpeed: float, dt: float, frameSeed: int): Camera2D:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `24` | `std/gfx2d/camera2d.aipl` | `camera2DWorldToScreenX` | `pub fn camera2DWorldToScreenX(cam: Camera2D, wx: float): float:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `25` | `std/gfx2d/camera2d.aipl` | `camera2DWorldToScreenY` | `pub fn camera2DWorldToScreenY(cam: Camera2D, wy: float): float:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `26` | `std/gfx2d/camera2d.aipl` | `beginCamera2D` | `pub fn beginCamera2D(cam: Camera2D):` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `27` | `std/gfx2d/camera2d.aipl` | `endCamera2D` | `pub fn endCamera2D():` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `28` | `std/gfx2d/camera2d.aipl` | `camEnvStr` | `fn camEnvStr(key: str, fallback: str): str:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `29` | `std/gfx2d/camera2d.aipl` | `beginMode2D` | `pub fn beginMode2D(cam: Camera2D): void:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `30` | `std/gfx2d/camera2d.aipl` | `endMode2D` | `pub fn endMode2D(): void:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `31` | `std/gfx2d/camera2d.aipl` | `isMode2DActive` | `pub fn isMode2DActive(): bool:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `32` | `std/gfx2d/camera2d.aipl` | `activeCamera2D` | `pub fn activeCamera2D(): Camera2D:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `33` | `std/gfx2d/camera2d.aipl` | `aabbOverlap` | `pub fn aabbOverlap(x1: float, y1: float, w1: float, h1: float, x2: float, y2: float, w2: float, h2: float): bool:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `34` | `std/gfx2d/camera2d.aipl` | `circleOverlap` | `pub fn circleOverlap(x1: float, y1: float, r1: float, x2: float, y2: float, r2: float): bool:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `35` | `std/gfx2d/camera2d.aipl` | `circleRectOverlap` | `pub fn circleRectOverlap(cx: float, cy: float, r: float, rx: float, ry: float, rw: float, rh: float): bool:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `36` | `std/gfx2d/camera2d.aipl` | `lineCircleOverlap` | `pub fn lineCircleOverlap(x1: float, y1: float, x2: float, y2: float, cx: float, cy: float, r: float): bool:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `37` | `std/gfx2d/camera2d.aipl` | `aimDirectionX` | `pub fn aimDirectionX(fromX: float, fromY: float, toX: float, toY: float): float:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `38` | `std/gfx2d/camera2d.aipl` | `aimDirectionY` | `pub fn aimDirectionY(fromX: float, fromY: float, toX: float, toY: float): float:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `39` | `std/gfx2d/camera2d.aipl` | `stepTimer` | `pub fn stepTimer(timer: float, dt: float): float:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `40` | `std/gfx2d/camera2d.aipl` | `isBlinkVisible` | `pub fn isBlinkVisible(timer: float, frequency: float): bool:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `41` | `std/gfx2d/camera2d.aipl` | `drawHealthBar` | `pub fn drawHealthBar(x: float, y: float, w: float, h: float, currentHp: float, maxHp: float, fillColor: Color, bgColor: Color):` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `42` | `std/gfx2d/camera2d.aipl` | `drawShieldBar` | `pub fn drawShieldBar(x: float, y: float, w: float, h: float, currentShield: float, maxShield: float, fillColor: Color, bgColor: Color):` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `43` | `std/gfx2d/camera2d.aipl` | `drawBossHealthBar` | `pub fn drawBossHealthBar(title: str, x: float, y: float, w: float, h: float, currentHp: float, maxHp: float, fillColor: Color):` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `44` | `std/gfx2d/camera2d.aipl` | `drawScoreCounter` | `pub fn drawScoreCounter(label: str, score: int, digits: int, x: float, y: float, size: float, color: Color):` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `45` | `std/gfx2d/camera2d.aipl` | `drawStarfield` | `pub fn drawStarfield(time: float, width: float, height: float, count: int, speed: float):` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `46` | `std/gfx2d/camera2d.aipl` | `spriteAnimatorNew` | `pub fn spriteAnimatorNew(initialClip: str): SpriteAnimator:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `47` | `std/gfx2d/camera2d.aipl` | `spriteAnimatorUpdate` | `pub fn spriteAnimatorUpdate(anim: SpriteAnimator, clip: SpriteClip, dt: float): SpriteAnimator:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `48` | `std/gfx2d/camera2d.aipl` | `platformerFeelNew` | `pub fn platformerFeelNew(): PlatformerFeel:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `49` | `std/gfx2d/camera2d.aipl` | `triggerHitStop` | `pub fn triggerHitStop(feel: PlatformerFeel, durationSec: float): PlatformerFeel:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `50` | `std/gfx2d/camera2d.aipl` | `canExecuteJump` | `pub fn canExecuteJump(feel: PlatformerFeel): bool:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `51` | `std/gfx2d/camera2d.aipl` | `platformerFeelStep` | `pub fn platformerFeelStep(feel: PlatformerFeel, dt: float, isGrounded: bool, jumpPressed: bool, coyoteDuration: float = 0.15, bufferDuration: float = 0.15): PlatformerFeel:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `52` | `std/gfx2d/camera2d.aipl` | `platformerFeelConsumeJump` | `pub fn platformerFeelConsumeJump(feel: PlatformerFeel): PlatformerFeel:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `53` | `std/gfx2d/camera2d.aipl` | `configureGameMaxFps` | `pub fn configureGameMaxFps(maxFps: int): int:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `54` | `std/gfx2d/camera2d.aipl` | `setGameMaxFps` | `pub fn setGameMaxFps(maxFps: int):` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `55` | `std/gfx2d/camera2d.aipl` | `getGameFrameTimeMs` | `pub fn getGameFrameTimeMs(): float:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `56` | `std/gfx2d/camera2d.aipl` | `getGameCurrentFps` | `pub fn getGameCurrentFps(): int:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `57` | `std/gfx2d/camera2d.aipl` | `sampleFpsTelemetry` | `pub fn sampleFpsTelemetry(maxFps: int): FpsTelemetry:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `58` | `std/gfx2d/camera2d.aipl` | `evaluateEcgWaveform` | `pub fn evaluateEcgWaveform(bpm: float, phaseSec: float, conditionTier: int): float:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `59` | `std/gfx2d/camera2d.aipl` | `parabolicProjectilePosY` | `pub fn parabolicProjectilePosY(startY: float, vy0: float, gravity: float, t: float): float:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `60` | `std/gfx2d/camera2d.aipl` | `fixedAccumulatorNew` | `pub fn fixedAccumulatorNew(fixedDt: float, maxFrameDt: float): FixedStepAccumulator:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `61` | `std/gfx2d/camera2d.aipl` | `fixedAccumulatorAdvance` | `pub fn fixedAccumulatorAdvance(acc: FixedStepAccumulator, rawDeltaSec: float): FixedStepAccumulator:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `62` | `std/gfx2d/camera2d.aipl` | `simClockNew` | `pub fn simClockNew(fixedDt: float): SimClock:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `63` | `std/gfx2d/camera2d.aipl` | `simClockBeginFrame` | `pub fn simClockBeginFrame(clock: SimClock, rawDeltaSec: float, stepsExecuted: int): SimClock:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `64` | `std/gfx2d/camera2d.aipl` | `sceneStackNew` | `pub fn sceneStackNew(initialScene: str = "boot"): SceneStack:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `65` | `std/gfx2d/camera2d.aipl` | `sceneStackPush` | `pub fn sceneStackPush(mut stack: SceneStack, sceneName: str): SceneStack:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `66` | `std/gfx2d/camera2d.aipl` | `sceneStackPop` | `pub fn sceneStackPop(mut stack: SceneStack): SceneStack:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `67` | `std/gfx2d/camera2d.aipl` | `sceneStackTop` | `pub fn sceneStackTop(stack: SceneStack): str:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `68` | `std/gfx2d/camera2d.aipl` | `replayBufferNew` | `pub fn replayBufferNew(): ReplayBuffer:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `69` | `std/gfx2d/camera2d.aipl` | `replayBufferRecord` | `pub fn replayBufferRecord(mut buf: ReplayBuffer, tick: int, inputMask: int, stateHash: int): ReplayBuffer:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `70` | `std/gfx2d/camera2d.aipl` | `replayBufferSampleInput` | `pub fn replayBufferSampleInput(buf: ReplayBuffer, index: int): int:` | `tests/functions/gfx2d/camera2d_test.aipl` |
| `71` | `std/gfx2d/filter2d.aipl` | `generateGaussianKernel1D` | `pub fn generateGaussianKernel1D(radius: int, sigma: float): [float]:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `72` | `std/gfx2d/filter2d.aipl` | `generateSobelKernels` | `pub fn generateSobelKernels(): [ConvolutionKernel2D]:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `73` | `std/gfx2d/filter2d.aipl` | `applyConvolution2D` | `pub fn applyConvolution2D(pixelGrid: [int], width: int, height: int, kernel: ConvolutionKernel2D): [int]:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `74` | `std/gfx2d/filter2d.aipl` | `applyLumaThreshold` | `pub fn applyLumaThreshold(luma: int, threshold: int): int:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `75` | `std/gfx2d/filter2d.aipl` | `blendPixelChannel` | `pub fn blendPixelChannel(src: int, dst: int, alphaPct: int): int:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `76` | `std/gfx2d/filter2d.aipl` | `f2dClamp` | `fn f2dClamp(v: int, lo: int, hi: int): int:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `77` | `std/gfx2d/filter2d.aipl` | `convolve3x3` | `pub fn convolve3x3(pixels: [int], w: int, h: int, k: [int], divisor: int, bias: int): [int]:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `78` | `std/gfx2d/filter2d.aipl` | `filterBoxBlur3x3` | `pub fn filterBoxBlur3x3(pixels: [int], w: int, h: int): [int]:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `79` | `std/gfx2d/filter2d.aipl` | `filterGaussian3x3` | `pub fn filterGaussian3x3(pixels: [int], w: int, h: int): [int]:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `80` | `std/gfx2d/filter2d.aipl` | `filterSharpen3x3` | `pub fn filterSharpen3x3(pixels: [int], w: int, h: int): [int]:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `81` | `std/gfx2d/filter2d.aipl` | `filterSobelEdges` | `pub fn filterSobelEdges(pixels: [int], w: int, h: int): [int]:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `82` | `std/gfx2d/filter2d.aipl` | `fadeAlpha` | `pub fn fadeAlpha(baseColor: Color, alpha: float): Color:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `83` | `std/gfx2d/filter2d.aipl` | `morphColor` | `pub fn morphColor(c1: Color, c2: Color, t: float): Color:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `84` | `std/gfx2d/filter2d.aipl` | `hslToColor` | `pub fn hslToColor(h: float, s: float, l: float): Color:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `85` | `std/gfx2d/filter2d.aipl` | `rainbowMorph` | `pub fn rainbowMorph(t: float): Color:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `86` | `std/gfx2d/filter2d.aipl` | `morphPoints` | `pub fn morphPoints(ptsA: [float], ptsB: [float], t: float): [float]:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `87` | `std/gfx2d/filter2d.aipl` | `calculatePulseScale` | `pub fn calculatePulseScale(baseScale: float, pulseAmount: float, frequency: float, time: float): float:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `88` | `std/gfx2d/filter2d.aipl` | `drawGlowCircleColor` | `pub fn drawGlowCircleColor(cx: float, cy: float, radius: float, color: Color, layers: int):` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `89` | `std/gfx2d/filter2d.aipl` | `drawGlowRect` | `pub fn drawGlowRect(x: float, y: float, w: float, h: float, color: Color, layers: int):` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `90` | `std/gfx2d/filter2d.aipl` | `dissolveShape` | `pub fn dissolveShape(centerX: float, centerY: float, w: float, h: float, progress: float, color: Color, particleCount: int):` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `91` | `std/gfx2d/filter2d.aipl` | `interpolateColorOverLife` | `pub fn interpolateColorOverLife(startColor: Color, endColor: Color, life: float, maxLife: float): Color:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `92` | `std/gfx2d/filter2d.aipl` | `colorOverLife` | `pub fn colorOverLife(c1: Color, c2: Color, progress: float): Color:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `93` | `std/gfx2d/filter2d.aipl` | `emitExplosionParticles` | `pub fn emitExplosionParticles(ox: float, oy: float, count: int, speed: float, baseColor: Color): [FxParticle]:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `94` | `std/gfx2d/filter2d.aipl` | `emitSparkTrail` | `pub fn emitSparkTrail(ox: float, oy: float, dirX: float, dirY: float, count: int, speed: float, sparkColor: Color): [FxParticle]:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `95` | `std/gfx2d/filter2d.aipl` | `countAliveParticles` | `pub fn countAliveParticles(particles: [FxParticle]): int:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `96` | `std/gfx2d/filter2d.aipl` | `updateFxParticle` | `pub fn updateFxParticle(p: FxParticle, dt: float, gravity: float = 0.0): FxParticle:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `97` | `std/gfx2d/filter2d.aipl` | `updateFxParticles` | `pub fn updateFxParticles(particles: [FxParticle], dt: float, gravity: float = 0.0): [FxParticle]:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `98` | `std/gfx2d/filter2d.aipl` | `cameraShakeNew` | `pub fn cameraShakeNew(decayRate: float, maxOffsetPx: float, maxAngleRad: float): CameraShake2D:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `99` | `std/gfx2d/filter2d.aipl` | `addCameraShakeTrauma` | `pub fn addCameraShakeTrauma(mut sh: CameraShake2D, amount: float): CameraShake2D:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `100` | `std/gfx2d/filter2d.aipl` | `stepCameraShake2D` | `pub fn stepCameraShake2D(mut sh: CameraShake2D, dt: float): CameraShake2D:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `101` | `std/gfx2d/filter2d.aipl` | `hitStopTimerNew` | `pub fn hitStopTimerNew(durationSec: float, freezeScale: float = 0.0): HitStopTimer:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `102` | `std/gfx2d/filter2d.aipl` | `stepHitStopTimer` | `pub fn stepHitStopTimer(mut ht: HitStopTimer, rawDt: float): HitStopTimer:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `103` | `std/gfx2d/filter2d.aipl` | `hitStopTimerScale` | `pub fn hitStopTimerScale(ht: HitStopTimer): float:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `104` | `std/gfx2d/filter2d.aipl` | `hitStopTrigger` | `pub fn hitStopTrigger(durationSec: float, freezeScale: float): HitStopState:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `105` | `std/gfx2d/filter2d.aipl` | `stepHitStop` | `pub fn stepHitStop(mut hs: HitStopState, rawDt: float): HitStopState:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `106` | `std/gfx2d/filter2d.aipl` | `effectiveHitStopDt` | `pub fn effectiveHitStopDt(hs: HitStopState, rawDt: float): float:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `107` | `std/gfx2d/filter2d.aipl` | `drawVignetteOverlay` | `pub fn drawVignetteOverlay(viewW: float, viewH: float, thickness: float, maxAlpha: float): void:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `108` | `std/gfx2d/filter2d.aipl` | `imageChromaticAberration` | `pub fn imageChromaticAberration(pixels: [int], w: int, h: int, shiftPx: int): [int]:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `109` | `std/gfx2d/filter2d.aipl` | `morphColorOklab` | `pub fn morphColorOklab(c1: Color, c2: Color, t: float): Color:` | `tests/functions/gfx2d/filter2d_test.aipl` |
| `110` | `std/gfx2d/iso_projector2d.aipl` | `createIsoProjector2D` | `pub fn createIsoProjector2D(tileW: float = 64.0, tileH: float = 32.0, elevationScale: float = 16.0): IsoProjector2D:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `111` | `std/gfx2d/iso_projector2d.aipl` | `isoGridToScreen` | `pub fn isoGridToScreen(proj: IsoProjector2D, coord: IsoTileCoord): Vec2:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `112` | `std/gfx2d/iso_projector2d.aipl` | `roundFloatIso` | `fn roundFloatIso(v: float): int:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `113` | `std/gfx2d/iso_projector2d.aipl` | `screenToIsoGrid` | `pub fn screenToIsoGrid(proj: IsoProjector2D, screenPt: Vec2): IsoTileCoord:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `114` | `std/gfx2d/iso_projector2d.aipl` | `computeTopologicalDepthSortKey` | `pub fn computeTopologicalDepthSortKey(col: int, row: int, elevation: float): float:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `115` | `std/gfx2d/iso_projector2d.aipl` | `sortEntitiesByTopologicalDepth` | `pub fn sortEntitiesByTopologicalDepth(items: [PainterSortItem]): [PainterSortItem]:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `116` | `std/gfx2d/iso_projector2d.aipl` | `worldToIsoX` | `pub fn worldToIsoX(gx: float, gy: float, tileW: float, originX: float): float:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `117` | `std/gfx2d/iso_projector2d.aipl` | `worldToIsoY` | `pub fn worldToIsoY(gx: float, gy: float, gz: float, tileH: float, originY: float): float:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `118` | `std/gfx2d/iso_projector2d.aipl` | `worldToIso` | `pub fn worldToIso(gx: float, gy: float, gz: float, tileW: float, tileH: float, originX: float, originY: float): [float]:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `119` | `std/gfx2d/iso_projector2d.aipl` | `isoToWorld` | `pub fn isoToWorld(screenX: float, screenY: float, tileW: float, tileH: float, originX: float, originY: float): [float]:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `120` | `std/gfx2d/iso_projector2d.aipl` | `isoDepthKey` | `pub fn isoDepthKey(gx: int, gy: int, gz: int): int:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `121` | `std/gfx2d/iso_projector2d.aipl` | `drawIsoDiamond` | `pub fn drawIsoDiamond(cx: float, cy: float, tileW: float, tileH: float, fillCol: Color, outlineCol: Color):` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `122` | `std/gfx2d/iso_projector2d.aipl` | `drawIsoBlock` | `pub fn drawIsoBlock(cx: float, cy: float, tileW: float, tileH: float, heightPx: float, topCol: Color, leftCol: Color, rightCol: Color, outlineCol: Color):` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `123` | `std/gfx2d/iso_projector2d.aipl` | `absVal` | `fn absVal(n: int): int:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `124` | `std/gfx2d/iso_projector2d.aipl` | `hexNeighbors` | `pub fn hexNeighbors(h: HexCoord): [HexCoord]:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `125` | `std/gfx2d/iso_projector2d.aipl` | `pixelToHex` | `pub fn pixelToHex(px: float, py: float, radius: float, originX: float, originY: float): HexCoord:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `126` | `std/gfx2d/iso_projector2d.aipl` | `drawHexagon` | `pub fn drawHexagon(cx: float, cy: float, radius: float, fillCol: Color, outlineCol: Color):` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `127` | `std/gfx2d/iso_projector2d.aipl` | `isoSortIndicesByDepth3D` | `pub fn isoSortIndicesByDepth3D(gxList: [float], gyList: [float], gzList: [float]): [int]:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `128` | `std/gfx2d/iso_projector2d.aipl` | `isoSortIndicesByDepth` | `pub fn isoSortIndicesByDepth(gxList: [float], gyList: [float]): [int]:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `129` | `std/gfx2d/iso_projector2d.aipl` | `isoSortIndicesByDepthFast` | `pub fn isoSortIndicesByDepthFast(gxList: [float], gyList: [float]): [int]:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `130` | `std/gfx2d/iso_projector2d.aipl` | `isoGridMapNew` | `pub fn isoGridMapNew(cols: int, rows: int, tileW: float, tileH: float, defaultHeight: float = 0.0): IsoGridMap:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `131` | `std/gfx2d/iso_projector2d.aipl` | `isoGridGetHeight` | `pub fn isoGridGetHeight(map: IsoGridMap, col: int, row: int): float:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `132` | `std/gfx2d/iso_projector2d.aipl` | `isoGridSetHeight` | `pub fn isoGridSetHeight(mut map: IsoGridMap, col: int, row: int, height: float): IsoGridMap:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `133` | `std/gfx2d/iso_projector2d.aipl` | `isoPickTileRay` | `pub fn isoPickTileRay(map: IsoGridMap, screenX: float, screenY: float, originX: float, originY: float): IsoCoord:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `134` | `std/gfx2d/iso_projector2d.aipl` | `isoProjectWithCamera` | `pub fn isoProjectWithCamera(cam: IsoCamera2D, gx: float, gy: float, gz: float): [float]:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `135` | `std/gfx2d/iso_projector2d.aipl` | `isoUnprojectWithCamera` | `pub fn isoUnprojectWithCamera(cam: IsoCamera2D, screenX: float, screenY: float): [float]:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `136` | `std/gfx2d/iso_projector2d.aipl` | `drawIsoShadow` | `pub fn drawIsoShadow(cx: float, cy: float, rx: float, ry: float, alpha: float):` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `137` | `std/gfx2d/iso_projector2d.aipl` | `drawIsoLightHalo` | `pub fn drawIsoLightHalo(cx: float, cy: float, radius: float, r: float, g: float, b: float, intensity: float):` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `138` | `std/gfx2d/iso_projector2d.aipl` | `drawIsoTexturedTile` | `pub fn drawIsoTexturedTile(cx: float, cy: float, tileW: float, tileH: float, fillCol: Color, detailCol: Color, outlineCol: Color):` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `139` | `std/gfx2d/iso_projector2d.aipl` | `drawIsoAutomapDiamond` | `pub fn drawIsoAutomapDiamond(cx: float, cy: float, tileW: float, tileH: float, wallMask: int, tintCol: Color):` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `140` | `std/gfx2d/iso_projector2d.aipl` | `tileWorldToIsoScreenX` | `pub fn tileWorldToIsoScreenX(wx: float, wy: float, wz: float, tileW: float, tileH: float, originX: float): float:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `141` | `std/gfx2d/iso_projector2d.aipl` | `tileWorldToIsoScreenY` | `pub fn tileWorldToIsoScreenY(wx: float, wy: float, wz: float, tileW: float, tileH: float, heightScale: float, originY: float): float:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `142` | `std/gfx2d/iso_projector2d.aipl` | `tileIsoScreenToWorldX` | `pub fn tileIsoScreenToWorldX(sx: float, sy: float, tileW: float, tileH: float, originX: float, originY: float): float:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `143` | `std/gfx2d/iso_projector2d.aipl` | `tileIsoScreenToWorldY` | `pub fn tileIsoScreenToWorldY(sx: float, sy: float, tileW: float, tileH: float, originX: float, originY: float): float:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `144` | `std/gfx2d/iso_projector2d.aipl` | `tileHexAxialToPixelX` | `pub fn tileHexAxialToPixelX(q: int, r: int, hexRadius: float, originX: float): float:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `145` | `std/gfx2d/iso_projector2d.aipl` | `tileHexAxialToPixelY` | `pub fn tileHexAxialToPixelY(q: int, r: int, hexRadius: float, originY: float): float:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `146` | `std/gfx2d/iso_projector2d.aipl` | `tileHexAxialDistance` | `pub fn tileHexAxialDistance(q1: int, r1: int, q2: int, r2: int): int:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `147` | `std/gfx2d/iso_projector2d.aipl` | `tileIsChunkInViewportFrustum` | `pub fn tileIsChunkInViewportFrustum(chunkMinX: float, chunkMinY: float, chunkMaxX: float, chunkMaxY: float, viewX: float, viewY: float, viewW: float, viewH: float, marginPx: float): bool:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `148` | `std/gfx2d/iso_projector2d.aipl` | `tileBilinearHeightSample` | `pub fn tileBilinearHeightSample(h00: float, h10: float, h01: float, h11: float, fracX: float, fracY: float): float:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `149` | `std/gfx2d/iso_projector2d.aipl` | `drawTileIsoDiamondWireframe` | `pub fn drawTileIsoDiamondWireframe(cx: float, cy: float, tileW: float, tileH: float, r: int, g: int, b: int, a: int):` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `150` | `std/gfx2d/iso_projector2d.aipl` | `drawTileHeightfieldPrism25D` | `pub fn drawTileHeightfieldPrism25D(cx: float, cy: float, tileW: float, tileH: float, extrudeH: float, r: int, g: int, b: int, a: int):` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `151` | `std/gfx2d/iso_projector2d.aipl` | `tileComputeLightRadiusFogAlpha` | `pub fn tileComputeLightRadiusFogAlpha(tileDistSq: float, lightRadiusTiles: float, minAlpha: int, maxAlpha: int): int:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `152` | `std/gfx2d/iso_projector2d.aipl` | `tileComputePortalTeleportX` | `pub fn tileComputePortalTeleportX(unitX: float, gateInX: float, gateOutX: float): float:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `153` | `std/gfx2d/iso_projector2d.aipl` | `tileComputePortalTeleportY` | `pub fn tileComputePortalTeleportY(unitY: float, gateInY: float, gateOutY: float): float:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `154` | `std/gfx2d/iso_projector2d.aipl` | `tileComputePortalFormationSlotX` | `pub fn tileComputePortalFormationSlotX(centerX: float, unitIdx: int, ringRadius: float): float:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `155` | `std/gfx2d/iso_projector2d.aipl` | `tileComputePortalFormationSlotY` | `pub fn tileComputePortalFormationSlotY(centerY: float, unitIdx: int, ringRadius: float): float:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `156` | `std/gfx2d/iso_projector2d.aipl` | `tileComputePortalVortexX` | `pub fn tileComputePortalVortexX(campCenterX: float, angleDeg: float, orbitRadius: float): float:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `157` | `std/gfx2d/iso_projector2d.aipl` | `tileComputePortalVortexY` | `pub fn tileComputePortalVortexY(campCenterY: float, angleDeg: float, orbitRadius: float): float:` | `tests/functions/gfx2d/iso_projector2d_test.aipl` |
| `158` | `std/gfx2d/light2d.aipl` | `createPointLight2D` | `pub fn createPointLight2D(pos: Vec2, radius: float, color: ColorRgba8, intensity: float = 1.0): Light2D:` | `tests/functions/gfx2d/light2d_test.aipl` |
| `159` | `std/gfx2d/light2d.aipl` | `raySegmentDist` | `fn raySegmentDist(ox: float, oy: float, dx: float, dy: float, seg: OccluderSegment2D, maxR: float): float:` | `tests/functions/gfx2d/light2d_test.aipl` |
| `160` | `std/gfx2d/light2d.aipl` | `bakeShadowMap1D` | `pub fn bakeShadowMap1D(light: Light2D, occluders: [OccluderSegment2D], resolution: int = 512): ShadowMap1D:` | `tests/functions/gfx2d/light2d_test.aipl` |
| `161` | `std/gfx2d/light2d.aipl` | `sampleLight2DIntensity` | `pub fn sampleLight2DIntensity(light: Light2D, shadowMap: ShadowMap1D, targetPt: Vec2): float:` | `tests/functions/gfx2d/light2d_test.aipl` |
| `162` | `std/gfx2d/ninepatch2d.aipl` | `createNinePatch2D` | `pub fn createNinePatch2D(textureId: int, imgW: float, imgH: float, insets: SliceInsets2D): NinePatch2D:` | `tests/functions/gfx2d/ninepatch2d_test.aipl` |
| `163` | `std/gfx2d/ninepatch2d.aipl` | `generateNinePatchQuads` | `pub fn generateNinePatchQuads(patch: NinePatch2D, targetBounds: Rect): [BatchVertex2D]:` | `tests/functions/gfx2d/ninepatch2d_test.aipl` |
| `164` | `std/gfx2d/shape2d.aipl` | `packRgbaInt` | `fn packRgbaInt(c: ColorRgba8): int:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `165` | `std/gfx2d/shape2d.aipl` | `buildLineQuads` | `pub fn buildLineQuads(p0: Vec2, p1: Vec2, stroke: StrokeStyle2D): [BatchVertex2D]:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `166` | `std/gfx2d/shape2d.aipl` | `buildCircleTris` | `pub fn buildCircleTris(center: Vec2, radius: float, color: ColorRgba8, segments: int = 32): [BatchVertex2D]:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `167` | `std/gfx2d/shape2d.aipl` | `buildCapsuleTris` | `pub fn buildCapsuleTris(startPt: Vec2, endPt: Vec2, radius: float, color: ColorRgba8, segments: int = 16): [BatchVertex2D]:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `168` | `std/gfx2d/shape2d.aipl` | `buildCubicBezierPoints` | `pub fn buildCubicBezierPoints(p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, subdivisions: int = 32): [Vec2]:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `169` | `std/gfx2d/shape2d.aipl` | `blendModeMultiplied` | `pub fn blendModeMultiplied(): int:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `170` | `std/gfx2d/shape2d.aipl` | `blendModeScreen` | `pub fn blendModeScreen(): int:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `171` | `std/gfx2d/shape2d.aipl` | `rgba` | `pub fn rgba(r: int, g: int, b: int, a: float): Color:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `172` | `std/gfx2d/shape2d.aipl` | `rgba8Color` | `pub fn rgba8Color(r: int, g: int, b: int, a: int): Color:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `173` | `std/gfx2d/shape2d.aipl` | `rgb` | `pub fn rgb(r: int, g: int, b: int): Color:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `174` | `std/gfx2d/shape2d.aipl` | `colorHexRgb` | `pub fn colorHexRgb(hex: int): Color:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `175` | `std/gfx2d/shape2d.aipl` | `colorHexRgba` | `pub fn colorHexRgba(hex: int): Color:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `176` | `std/gfx2d/shape2d.aipl` | `colorHex` | `pub fn colorHex(hex: int): Color:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `177` | `std/gfx2d/shape2d.aipl` | `canvasHexDigit` | `fn canvasHexDigit(code: int): int:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `178` | `std/gfx2d/shape2d.aipl` | `colorFromHexStr` | `pub fn colorFromHexStr(hexStr: str): Color:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `179` | `std/gfx2d/shape2d.aipl` | `colorHexStr` | `pub fn colorHexStr(hexStr: str): Color:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `180` | `std/gfx2d/shape2d.aipl` | `packColorRgba32` | `pub fn packColorRgba32(c: Color): int:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `181` | `std/gfx2d/shape2d.aipl` | `colorToInt` | `pub fn colorToInt(c: Color): int:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `182` | `std/gfx2d/shape2d.aipl` | `pushTransform` | `pub fn pushTransform(tx: float, ty: float, rotRad: float, sx: float, sy: float): Transform2D:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `183` | `std/gfx2d/shape2d.aipl` | `popTransform` | `pub fn popTransform(): void:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `184` | `std/gfx2d/shape2d.aipl` | `colorRed` | `pub fn colorRed(): Color:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `185` | `std/gfx2d/shape2d.aipl` | `colorGreen` | `pub fn colorGreen(): Color:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `186` | `std/gfx2d/shape2d.aipl` | `colorBlue` | `pub fn colorBlue(): Color:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `187` | `std/gfx2d/shape2d.aipl` | `colorWhite` | `pub fn colorWhite(): Color:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `188` | `std/gfx2d/shape2d.aipl` | `colorBlack` | `pub fn colorBlack(): Color:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `189` | `std/gfx2d/shape2d.aipl` | `colorCyan` | `pub fn colorCyan(): Color:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `190` | `std/gfx2d/shape2d.aipl` | `colorYellow` | `pub fn colorYellow(): Color:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `191` | `std/gfx2d/shape2d.aipl` | `colorMagenta` | `pub fn colorMagenta(): Color:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `192` | `std/gfx2d/shape2d.aipl` | `colorOrange` | `pub fn colorOrange(): Color:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `193` | `std/gfx2d/shape2d.aipl` | `colorGray` | `pub fn colorGray(): Color:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `194` | `std/gfx2d/shape2d.aipl` | `clearScreen` | `pub fn clearScreen(color: Color):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `195` | `std/gfx2d/shape2d.aipl` | `drawRect` | `pub fn drawRect(x: float, y: float, w: float, h: float, color: Color):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `196` | `std/gfx2d/shape2d.aipl` | `drawRectOutline` | `pub fn drawRectOutline(x: float, y: float, w: float, h: float, thickness: float, color: Color):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `197` | `std/gfx2d/shape2d.aipl` | `drawCircle` | `pub fn drawCircle(cx: float, cy: float, radius: float, color: Color):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `198` | `std/gfx2d/shape2d.aipl` | `drawCircleOutline` | `pub fn drawCircleOutline(cx: float, cy: float, radius: float, thickness: float, color: Color):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `199` | `std/gfx2d/shape2d.aipl` | `drawLine` | `pub fn drawLine(x1: float, y1: float, x2: float, y2: float, color: Color, thickness: float):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `200` | `std/gfx2d/shape2d.aipl` | `drawTriangle` | `pub fn drawTriangle(x1: float, y1: float, x2: float, y2: float, x3: float, y3: float, color: Color):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `201` | `std/gfx2d/shape2d.aipl` | `drawTriangleOutline` | `pub fn drawTriangleOutline(x1: float, y1: float, x2: float, y2: float, x3: float, y3: float, color: Color):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `202` | `std/gfx2d/shape2d.aipl` | `drawTriangleLines` | `pub fn drawTriangleLines(x1: float, y1: float, x2: float, y2: float, x3: float, y3: float, color: Color):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `203` | `std/gfx2d/shape2d.aipl` | `drawEllipse` | `pub fn drawEllipse(cx: float, cy: float, rx: float, ry: float, color: Color):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `204` | `std/gfx2d/shape2d.aipl` | `drawRegularPolygon` | `pub fn drawRegularPolygon(cx: float, cy: float, radius: float, sides: int, color: Color):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `205` | `std/gfx2d/shape2d.aipl` | `drawPolygon` | `pub fn drawPolygon(points: [float], color: Color):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `206` | `std/gfx2d/shape2d.aipl` | `drawText` | `pub fn drawText(text: str, x: float, y: float, size: float, color: Color):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `207` | `std/gfx2d/shape2d.aipl` | `measureTextWidthPx` | `pub fn measureTextWidthPx(text: str, size: float): float:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `208` | `std/gfx2d/shape2d.aipl` | `measureTextHeight` | `pub fn measureTextHeight(text: str, size: float): float:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `209` | `std/gfx2d/shape2d.aipl` | `measureText` | `pub fn measureText(text: str, size: float): Vec2:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `210` | `std/gfx2d/shape2d.aipl` | `truncateText` | `pub fn truncateText(text: str, maxWidth: float, size: float): str:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `211` | `std/gfx2d/shape2d.aipl` | `drawTextBox` | `pub fn drawTextBox(text: str, x: float, y: float, maxWidth: float, size: float, color: Color):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `212` | `std/gfx2d/shape2d.aipl` | `drawTextCentered` | `pub fn drawTextCentered(text: str, cx: float, y: float, size: float, color: Color):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `213` | `std/gfx2d/shape2d.aipl` | `drawTextRight` | `pub fn drawTextRight(text: str, rightX: float, y: float, size: float, color: Color):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `214` | `std/gfx2d/shape2d.aipl` | `isKeyPressed` | `pub fn isKeyPressed(key: str): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `215` | `std/gfx2d/shape2d.aipl` | `isKeyReleased` | `pub fn isKeyReleased(key: str): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `216` | `std/gfx2d/shape2d.aipl` | `getMouseX` | `pub fn getMouseX(): float:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `217` | `std/gfx2d/shape2d.aipl` | `getMouseY` | `pub fn getMouseY(): float:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `218` | `std/gfx2d/shape2d.aipl` | `isMouseButtonPressed` | `pub fn isMouseButtonPressed(button: int): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `219` | `std/gfx2d/shape2d.aipl` | `isMouseButtonReleased` | `pub fn isMouseButtonReleased(button: int): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `220` | `std/gfx2d/shape2d.aipl` | `isMouseInRect` | `pub fn isMouseInRect(x: float, y: float, w: float, h: float): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `221` | `std/gfx2d/shape2d.aipl` | `isRectClicked` | `pub fn isRectClicked(x: float, y: float, w: float, h: float): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `222` | `std/gfx2d/shape2d.aipl` | `getTextInput` | `pub fn getTextInput(): str:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `223` | `std/gfx2d/shape2d.aipl` | `injectTextInput` | `pub fn injectTextInput(s: str):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `224` | `std/gfx2d/shape2d.aipl` | `getCompositionText` | `pub fn getCompositionText(): str:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `225` | `std/gfx2d/shape2d.aipl` | `getCompositionCursor` | `pub fn getCompositionCursor(): int:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `226` | `std/gfx2d/shape2d.aipl` | `isKeyHeld` | `pub fn isKeyHeld(keyCode: int): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `227` | `std/gfx2d/shape2d.aipl` | `mouseWheelX` | `pub fn mouseWheelX(): float:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `228` | `std/gfx2d/shape2d.aipl` | `mouseWheelY` | `pub fn mouseWheelY(): float:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `229` | `std/gfx2d/shape2d.aipl` | `isMouseDoubleClicked` | `pub fn isMouseDoubleClicked(): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `230` | `std/gfx2d/shape2d.aipl` | `isMouseRightClicked` | `pub fn isMouseRightClicked(): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `231` | `std/gfx2d/shape2d.aipl` | `pollPointerEvents` | `pub fn pollPointerEvents(): [PointerEvent]:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `232` | `std/gfx2d/shape2d.aipl` | `loadImage` | `pub fn loadImage(path: str): Result[int, str]:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `233` | `std/gfx2d/shape2d.aipl` | `decodeImage` | `pub fn decodeImage(data: bytes): Result[int, str]:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `234` | `std/gfx2d/shape2d.aipl` | `imageWidth` | `pub fn imageWidth(imgId: int): int:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `235` | `std/gfx2d/shape2d.aipl` | `imageHeight` | `pub fn imageHeight(imgId: int): int:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `236` | `std/gfx2d/shape2d.aipl` | `getImageWidth` | `pub fn getImageWidth(imgId: int): int:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `237` | `std/gfx2d/shape2d.aipl` | `getImageHeight` | `pub fn getImageHeight(imgId: int): int:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `238` | `std/gfx2d/shape2d.aipl` | `unloadImage` | `pub fn unloadImage(imgId: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `239` | `std/gfx2d/shape2d.aipl` | `drawImage` | `pub fn drawImage(imgId: int, x: float, y: float):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `240` | `std/gfx2d/shape2d.aipl` | `drawImageScaled` | `pub fn drawImageScaled(imgId: int, x: float, y: float, w: float, h: float):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `241` | `std/gfx2d/shape2d.aipl` | `drawSubImage` | `pub fn drawSubImage(imgId: int, sx: float, sy: float, sw: float, sh: float, dx: float, dy: float, dw: float, dh: float):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `242` | `std/gfx2d/shape2d.aipl` | `drawImageSub` | `pub fn drawImageSub(imgId: int, sx: float, sy: float, sw: float, sh: float, dx: float, dy: float, dw: float, dh: float):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `243` | `std/gfx2d/shape2d.aipl` | `drawImageEx` | `pub fn drawImageEx(imgId: int, x: float, y: float, w: float, h: float, rotRad: float, originX: float, originY: float, tintColor: int, flipX: bool, flipY: bool):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `244` | `std/gfx2d/shape2d.aipl` | `saveImage` | `pub fn saveImage(imgId: int, path: str): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `245` | `std/gfx2d/shape2d.aipl` | `saveScreenshot` | `pub fn saveScreenshot(path: str): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `246` | `std/gfx2d/shape2d.aipl` | `startVideoRecording` | `pub fn startVideoRecording(path: str, fps: int): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `247` | `std/gfx2d/shape2d.aipl` | `recordVideoFrame` | `pub fn recordVideoFrame(): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `248` | `std/gfx2d/shape2d.aipl` | `stopVideoRecording` | `pub fn stopVideoRecording(): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `249` | `std/gfx2d/shape2d.aipl` | `isRecordingVideo` | `pub fn isRecordingVideo(): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `250` | `std/gfx2d/shape2d.aipl` | `createImageFromPixels` | `pub fn createImageFromPixels(width: int, height: int, rgbaPixels: [int]): int:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `251` | `std/gfx2d/shape2d.aipl` | `readCanvasPixel` | `pub fn readCanvasPixel(x: int, y: int): int:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `252` | `std/gfx2d/shape2d.aipl` | `getScreenWidth` | `pub fn getScreenWidth(): int:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `253` | `std/gfx2d/shape2d.aipl` | `getScreenHeight` | `pub fn getScreenHeight(): int:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `254` | `std/gfx2d/shape2d.aipl` | `getWindowWidth` | `pub fn getWindowWidth(): int:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `255` | `std/gfx2d/shape2d.aipl` | `getWindowHeight` | `pub fn getWindowHeight(): int:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `256` | `std/gfx2d/shape2d.aipl` | `isWindowResized` | `pub fn isWindowResized(): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `257` | `std/gfx2d/shape2d.aipl` | `setWindowMinSize` | `pub fn setWindowMinSize(w: int, h: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `258` | `std/gfx2d/shape2d.aipl` | `getScaleFactor` | `pub fn getScaleFactor(): float:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `259` | `std/gfx2d/shape2d.aipl` | `getContentScale` | `pub fn getContentScale(): float:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `260` | `std/gfx2d/shape2d.aipl` | `setWindowTitle` | `pub fn setWindowTitle(title: str):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `261` | `std/gfx2d/shape2d.aipl` | `setWindowSize` | `pub fn setWindowSize(w: int, h: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `262` | `std/gfx2d/shape2d.aipl` | `setTargetFps` | `pub fn setTargetFps(fps: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `263` | `std/gfx2d/shape2d.aipl` | `getFrameTime` | `pub fn getFrameTime(): float:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `264` | `std/gfx2d/shape2d.aipl` | `setMaxFps` | `pub fn setMaxFps(maxFps: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `265` | `std/gfx2d/shape2d.aipl` | `getMaxFps` | `pub fn getMaxFps(configuredMaxFps: int = 120): int:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `266` | `std/gfx2d/shape2d.aipl` | `getCurrentFps` | `pub fn getCurrentFps(): int:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `267` | `std/gfx2d/shape2d.aipl` | `getFrameTimeMs` | `pub fn getFrameTimeMs(): float:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `268` | `std/gfx2d/shape2d.aipl` | `drawRoundedRect` | `pub fn drawRoundedRect(x: float, y: float, w: float, h: float, radius: float, color: Color):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `269` | `std/gfx2d/shape2d.aipl` | `drawRoundedRectOutline` | `pub fn drawRoundedRectOutline(x: float, y: float, w: float, h: float, radius: float, thickness: float, color: Color):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `270` | `std/gfx2d/shape2d.aipl` | `drawArc` | `pub fn drawArc(cx: float, cy: float, radius: float, startAngleRad: float, endAngleRad: float, thickness: float, color: Color):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `271` | `std/gfx2d/shape2d.aipl` | `loadFont` | `pub fn loadFont(path: str): Result[int, str]:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `272` | `std/gfx2d/shape2d.aipl` | `decodeFont` | `pub fn decodeFont(data: bytes): Result[int, str]:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `273` | `std/gfx2d/shape2d.aipl` | `drawTextFont` | `pub fn drawTextFont(fontId: int, text: str, x: float, y: float, size: float, col: Color):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `274` | `std/gfx2d/shape2d.aipl` | `measureTextFont` | `pub fn measureTextFont(fontId: int, text: str, size: float): Vec2:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `275` | `std/gfx2d/shape2d.aipl` | `drawLines` | `pub fn drawLines(points: [Vec2], thickness: float, color: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `276` | `std/gfx2d/shape2d.aipl` | `drawCircles` | `pub fn drawCircles(centers: [Vec2], radius: float, color: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `277` | `std/gfx2d/shape2d.aipl` | `drawPixelBuffer` | `pub fn drawPixelBuffer(pixels: [int], gridW: int, gridH: int, dstX: int, dstY: int, dstW: int, dstH: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `278` | `std/gfx2d/shape2d.aipl` | `drawCirclesSoA` | `pub fn drawCirclesSoA(xs: [float], ys: [float], radii: [float], colors: [int], count: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `279` | `std/gfx2d/shape2d.aipl` | `drawRectsSoA` | `pub fn drawRectsSoA(xs: [float], ys: [float], ws: [float], hs: [float], colors: [int], count: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `280` | `std/gfx2d/shape2d.aipl` | `getFrameProfile` | `pub fn getFrameProfile(): Map[str, float]:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `281` | `std/gfx2d/shape2d.aipl` | `canvasBackendName` | `pub fn canvasBackendName(): str:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `282` | `std/gfx2d/shape2d.aipl` | `isHeadlessMode` | `pub fn isHeadlessMode(): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `283` | `std/gfx2d/shape2d.aipl` | `beginFrame` | `pub fn beginFrame():` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `284` | `std/gfx2d/shape2d.aipl` | `endFrame` | `pub fn endFrame():` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `285` | `std/gfx2d/shape2d.aipl` | `clearCanvas` | `pub fn clearCanvas(color: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `286` | `std/gfx2d/shape2d.aipl` | `getPixel` | `pub fn getPixel(x: int, y: int): int:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `287` | `std/gfx2d/shape2d.aipl` | `initCanvas` | `pub fn initCanvas(w: int, h: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `288` | `std/gfx2d/shape2d.aipl` | `initWindow` | `pub fn initWindow(w: int, h: int, title: str):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `289` | `std/gfx2d/shape2d.aipl` | `closeWindow` | `pub fn closeWindow():` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `290` | `std/gfx2d/shape2d.aipl` | `setSingleInstance` | `pub fn setSingleInstance(enabled: bool): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `291` | `std/gfx2d/shape2d.aipl` | `isSingleInstance` | `pub fn isSingleInstance(): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `292` | `std/gfx2d/shape2d.aipl` | `targetWindowScreenshot` | `pub fn targetWindowScreenshot(target: str, outPath: str): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `293` | `std/gfx2d/shape2d.aipl` | `targetWindowRecord` | `pub fn targetWindowRecord(target: str, outPath: str, frames: int, fps: int): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `294` | `std/gfx2d/shape2d.aipl` | `targetWindowAction` | `pub fn targetWindowAction(target: str, botScript: str): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `295` | `std/gfx2d/shape2d.aipl` | `targetWindowSeatAction` | `pub fn targetWindowSeatAction(target: str, seatId: int, botScript: str): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `296` | `std/gfx2d/shape2d.aipl` | `publishBotState` | `pub fn publishBotState(key: str, jsonVal: str): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `297` | `std/gfx2d/shape2d.aipl` | `publishTurnState` | `pub fn publishTurnState(activeSeat: int, phase: str, winnerSeat: int): bool:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `298` | `std/gfx2d/shape2d.aipl` | `listRunningWindows` | `pub fn listRunningWindows(): [str]:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `299` | `std/gfx2d/shape2d.aipl` | `setWindowPosition` | `pub fn setWindowPosition(x: int, y: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `300` | `std/gfx2d/shape2d.aipl` | `drawTexturedWallStrip` | `pub fn drawTexturedWallStrip(x: float, yTop: float, colW: float, wallH: float, texU: float, wallKind: int, distShade: float, baseColor: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `301` | `std/gfx2d/shape2d.aipl` | `drawFloorCeilingScanlines` | `pub fn drawFloorCeilingScanlines(x: float, y: float, w: float, h: float, horizonY: float, skyColorTop: int, floorColorNear: int, bands: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `302` | `std/gfx2d/shape2d.aipl` | `drawDepthColumnsSoA` | `pub fn drawDepthColumnsSoA(xs: [float], yTops: [float], heights: [float], colors: [int], colW: float, count: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `303` | `std/gfx2d/shape2d.aipl` | `listRunningWindowsFiltered` | `pub fn listRunningWindowsFiltered(titleSubstr: str): [str]:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `304` | `std/gfx2d/shape2d.aipl` | `drawPerspectiveQuad` | `pub fn drawPerspectiveQuad(x1: float, y1: float, x2: float, y2: float, x3: float, y3: float, x4: float, y4: float, col: Color):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `305` | `std/gfx2d/shape2d.aipl` | `drawGlowCircle` | `pub fn drawGlowCircle(cx: float, cy: float, radius: float, colorHexVal: int, rings: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `306` | `std/gfx2d/shape2d.aipl` | `drawDashedRectOutline` | `pub fn drawDashedRectOutline(x: float, y: float, w: float, h: float, dashLen: float, gapLen: float, col: Color, thickness: float):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `307` | `std/gfx2d/shape2d.aipl` | `drawVectorField2D` | `pub fn drawVectorField2D(xs: [float], ys: [float], vxs: [float], vys: [float], scale: float, col: Color, count: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `308` | `std/gfx2d/shape2d.aipl` | `drawCrosshairSniperScope` | `pub fn drawCrosshairSniperScope(cx: float, cy: float, radius: float, screenW: float, screenH: float, zoomFactor: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `309` | `std/gfx2d/shape2d.aipl` | `drawIsometricWallSegment` | `pub fn drawIsometricWallSegment(x1: float, y1: float, x2: float, y2: float, wallHeight: float, topCol: Color, faceCol: Color, mortarCol: Color):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `310` | `std/gfx2d/shape2d.aipl` | `drawRadialRadarSweep` | `pub fn drawRadialRadarSweep(x: float, y: float, r: float, angleDeg: float, sweepColor: str, ringColor: str):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `311` | `std/gfx2d/shape2d.aipl` | `drawPerspectiveCheckerFloor` | `pub fn drawPerspectiveCheckerFloor(x: float, y: float, w: float, h: float, horizonY: float, colA: str, colB: str):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `312` | `std/gfx2d/shape2d.aipl` | `drawVolumetricFogLayer` | `pub fn drawVolumetricFogLayer(x: float, y: float, w: float, h: float, densityPct: int, fogHex: str):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `313` | `std/gfx2d/shape2d.aipl` | `drawBezierRibbonConnection` | `pub fn drawBezierRibbonConnection(x1: float, y1: float, x2: float, y2: float, thickness: float, colStart: str, colEnd: str):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `314` | `std/gfx2d/shape2d.aipl` | `drawNormalLitSurface` | `pub fn drawNormalLitSurface(x: float, y: float, w: float, h: float, lightAzimuth: float, lightElevation: float, baseHex: str, specHex: str):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `315` | `std/gfx2d/shape2d.aipl` | `drawAudioSpectrumBars` | `pub fn drawAudioSpectrumBars(x: float, y: float, w: float, h: float, numBands: int, peakDb: int, accentHex: str):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `316` | `std/gfx2d/shape2d.aipl` | `drawSubpixelAASpan` | `pub fn drawSubpixelAASpan(x: float, y: float, w: float, h: float, coverage: float, fgHex: int, bgHex: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `317` | `std/gfx2d/shape2d.aipl` | `drawParticleRibbonTrail` | `pub fn drawParticleRibbonTrail(x1: float, y1: float, x2: float, y2: float, widthStart: float, widthEnd: float, colHex: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `318` | `std/gfx2d/shape2d.aipl` | `drawRibbonTrail` | `pub fn drawRibbonTrail(x1: float, y1: float, x2: float, y2: float, segments: int, startWidth: float, coreHex: int, fadeHex: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `319` | `std/gfx2d/shape2d.aipl` | `drawSubpixelRect` | `pub fn drawSubpixelRect(x: float, y: float, w: float, h: float, fgHex: int, bgHex: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `320` | `std/gfx2d/shape2d.aipl` | `drawSubpixelTextSpan` | `pub fn drawSubpixelTextSpan(x: float, y: float, text: str, fontPx: float, textHex: int, bgPlateHex: int):` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `321` | `std/gfx2d/shape2d.aipl` | `canvasEnvStr` | `fn canvasEnvStr(key: str, fallback: str): str:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `322` | `std/gfx2d/shape2d.aipl` | `setBlendMode` | `pub fn setBlendMode(mode: int): void:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `323` | `std/gfx2d/shape2d.aipl` | `getBlendMode` | `pub fn getBlendMode(): int:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `324` | `std/gfx2d/shape2d.aipl` | `paint2DFill` | `pub fn paint2DFill(col: Color): Paint2D:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `325` | `std/gfx2d/shape2d.aipl` | `paint2DStroke` | `pub fn paint2DStroke(col: Color, width: float): Paint2D:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `326` | `std/gfx2d/shape2d.aipl` | `path2DNew` | `pub fn path2DNew(): Path2D:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `327` | `std/gfx2d/shape2d.aipl` | `path2DMoveTo` | `pub fn path2DMoveTo(mut p: Path2D, x: float, y: float): Path2D:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `328` | `std/gfx2d/shape2d.aipl` | `path2DLineTo` | `pub fn path2DLineTo(mut p: Path2D, x: float, y: float): Path2D:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `329` | `std/gfx2d/shape2d.aipl` | `path2DQuadTo` | `pub fn path2DQuadTo(mut p: Path2D, cx: float, cy: float, x: float, y: float, segments: int = 8): Path2D:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `330` | `std/gfx2d/shape2d.aipl` | `path2DCubicTo` | `pub fn path2DCubicTo(mut p: Path2D, c1x: float, c1y: float, c2x: float, c2y: float, x: float, y: float, segments: int = 12): Path2D:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `331` | `std/gfx2d/shape2d.aipl` | `path2DClose` | `pub fn path2DClose(mut p: Path2D): Path2D:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `332` | `std/gfx2d/shape2d.aipl` | `drawPath2D` | `pub fn drawPath2D(p: Path2D, paint: Paint2D): void:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `333` | `std/gfx2d/shape2d.aipl` | `renderGroup2DNew` | `pub fn renderGroup2DNew(id: str): RenderGroup2D:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `334` | `std/gfx2d/shape2d.aipl` | `renderGroup2DAddRect` | `pub fn renderGroup2DAddRect(mut g: RenderGroup2D, x: float, y: float, w: float, h: float, paint: Paint2D, zOrder: int = 0): RenderGroup2D:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `335` | `std/gfx2d/shape2d.aipl` | `renderGroup2DAddCircle` | `pub fn renderGroup2DAddCircle(mut g: RenderGroup2D, cx: float, cy: float, r: float, paint: Paint2D, zOrder: int = 0): RenderGroup2D:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `336` | `std/gfx2d/shape2d.aipl` | `renderGroup2DFlush` | `pub fn renderGroup2DFlush(g: RenderGroup2D): int:` | `tests/functions/gfx2d/shape2d_test.aipl` |
| `337` | `std/gfx2d/skeletal2d.aipl` | `updateSkeletonTransforms2D` | `pub fn updateSkeletonTransforms2D(skel: Skeleton2D): Skeleton2D:` | `tests/functions/gfx2d/skeletal2d_test.aipl` |
| `338` | `std/gfx2d/skeletal2d.aipl` | `clampCosIk` | `fn clampCosIk(v: float): float:` | `tests/functions/gfx2d/skeletal2d_test.aipl` |
| `339` | `std/gfx2d/skeletal2d.aipl` | `solveTwoBoneIk2D` | `pub fn solveTwoBoneIk2D(rootPos: Vec2, targetPos: Vec2, length1: float, length2: float, flipElbow: bool = false): IkSolution2D:` | `tests/functions/gfx2d/skeletal2d_test.aipl` |
| `340` | `std/gfx2d/skeletal2d.aipl` | `solveChainFK2D` | `pub fn solveChainFK2D(rootX: float, rootY: float, bones: [Bone2D]): [float]:` | `tests/functions/gfx2d/skeletal2d_test.aipl` |
| `341` | `std/gfx2d/skeletal2d.aipl` | `solveTwoBoneIK2D` | `pub fn solveTwoBoneIK2D(rootX: float, rootY: float, len1: float, len2: float, targetX: float, targetY: float, bendPositive: bool): [float]:` | `tests/functions/gfx2d/skeletal2d_test.aipl` |
| `342` | `std/gfx2d/skeletal2d.aipl` | `solveSkeletonTreeFK2D` | `pub fn solveSkeletonTreeFK2D(rootX: float, rootY: float, mut nodes: [BoneNode2D]): [BoneNode2D]:` | `tests/functions/gfx2d/skeletal2d_test.aipl` |
| `343` | `std/gfx2d/skeletal2d.aipl` | `solveTwoBoneIK2DResult` | `pub fn solveTwoBoneIK2DResult(rootX: float, rootY: float, len1: float, len2: float, targetX: float, targetY: float, bendPositive: bool): TwoBoneIKResult:` | `tests/functions/gfx2d/skeletal2d_test.aipl` |
| `344` | `std/gfx2d/skeletal2d.aipl` | `solveTwoBoneIK2DEx` | `pub fn solveTwoBoneIK2DEx(rootX: float, rootY: float, len1: float, len2: float, targetX: float, targetY: float, bendPositive: bool): TwoBoneIKResult:` | `tests/functions/gfx2d/skeletal2d_test.aipl` |
| `345` | `std/gfx2d/skeletal2d.aipl` | `solveFABRIK2D` | `pub fn solveFABRIK2D(mut joints: [float], targetX: float, targetY: float, iterations: int, tolerance: float): [float]:` | `tests/functions/gfx2d/skeletal2d_test.aipl` |
| `346` | `std/gfx2d/sprite2d.aipl` | `createSprite2D` | `pub fn createSprite2D(textureId: int, w: float, h: float): Sprite2D:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `347` | `std/gfx2d/sprite2d.aipl` | `setSpriteUv` | `pub fn setSpriteUv(sprite: Sprite2D, uv: UvRect): Sprite2D:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `348` | `std/gfx2d/sprite2d.aipl` | `computeSpriteCorners` | `pub fn computeSpriteCorners(sprite: Sprite2D): [Vec2]:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `349` | `std/gfx2d/sprite2d.aipl` | `clamp01` | `pub fn clamp01(t: float): float:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `350` | `std/gfx2d/sprite2d.aipl` | `lerpFloat` | `pub fn lerpFloat(a: float, b: float, t: float): float:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `351` | `std/gfx2d/sprite2d.aipl` | `easeTypeLinear` | `pub fn easeTypeLinear(): int:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `352` | `std/gfx2d/sprite2d.aipl` | `easeTypeInQuad` | `pub fn easeTypeInQuad(): int:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `353` | `std/gfx2d/sprite2d.aipl` | `easeTypeOutQuad` | `pub fn easeTypeOutQuad(): int:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `354` | `std/gfx2d/sprite2d.aipl` | `easeTypeInOutQuad` | `pub fn easeTypeInOutQuad(): int:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `355` | `std/gfx2d/sprite2d.aipl` | `easeTypeInCubic` | `pub fn easeTypeInCubic(): int:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `356` | `std/gfx2d/sprite2d.aipl` | `easeTypeOutCubic` | `pub fn easeTypeOutCubic(): int:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `357` | `std/gfx2d/sprite2d.aipl` | `easeTypeInOutCubic` | `pub fn easeTypeInOutCubic(): int:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `358` | `std/gfx2d/sprite2d.aipl` | `easeTypeInSine` | `pub fn easeTypeInSine(): int:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `359` | `std/gfx2d/sprite2d.aipl` | `easeTypeOutSine` | `pub fn easeTypeOutSine(): int:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `360` | `std/gfx2d/sprite2d.aipl` | `easeTypeInOutSine` | `pub fn easeTypeInOutSine(): int:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `361` | `std/gfx2d/sprite2d.aipl` | `easeTypeOutBounce` | `pub fn easeTypeOutBounce(): int:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `362` | `std/gfx2d/sprite2d.aipl` | `easeTypeInBounce` | `pub fn easeTypeInBounce(): int:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `363` | `std/gfx2d/sprite2d.aipl` | `easeTypeInOutBounce` | `pub fn easeTypeInOutBounce(): int:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `364` | `std/gfx2d/sprite2d.aipl` | `easeTypeOutElastic` | `pub fn easeTypeOutElastic(): int:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `365` | `std/gfx2d/sprite2d.aipl` | `easeTypeInElastic` | `pub fn easeTypeInElastic(): int:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `366` | `std/gfx2d/sprite2d.aipl` | `easeTypeInOutElastic` | `pub fn easeTypeInOutElastic(): int:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `367` | `std/gfx2d/sprite2d.aipl` | `easeInSine` | `pub fn easeInSine(t: float): float:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `368` | `std/gfx2d/sprite2d.aipl` | `easeOutSine` | `pub fn easeOutSine(t: float): float:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `369` | `std/gfx2d/sprite2d.aipl` | `easeInOutSine` | `pub fn easeInOutSine(t: float): float:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `370` | `std/gfx2d/sprite2d.aipl` | `easeByName` | `pub fn easeByName(name: str, t: float): float:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `371` | `std/gfx2d/sprite2d.aipl` | `tweenNew` | `pub fn tweenNew(startVal: float, endVal: float, durationMs: float, easing: str, looping: bool = false, pingPong: bool = false): Tween:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `372` | `std/gfx2d/sprite2d.aipl` | `tweenUpdate` | `pub fn tweenUpdate(tw: Tween, dtMs: float): Tween:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `373` | `std/gfx2d/sprite2d.aipl` | `tweenValue` | `pub fn tweenValue(tw: Tween): float:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `374` | `std/gfx2d/sprite2d.aipl` | `applyEasing` | `pub fn applyEasing(t: float, easingType: int): float:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `375` | `std/gfx2d/sprite2d.aipl` | `tweenFloat` | `pub fn tweenFloat(startVal: float, endVal: float, t: float, easingType: int): float:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `376` | `std/gfx2d/sprite2d.aipl` | `tweenColor` | `pub fn tweenColor(c1: Color, c2: Color, t: float): Color:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `377` | `std/gfx2d/sprite2d.aipl` | `polarSquareRadius` | `pub fn polarSquareRadius(halfSide: float, angle: float): float:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `378` | `std/gfx2d/sprite2d.aipl` | `polarStarRadius` | `pub fn polarStarRadius(baseRadius: float, spikeAmp: float, points: int, angle: float): float:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `379` | `std/gfx2d/sprite2d.aipl` | `tweenSequenceNew` | `pub fn tweenSequenceNew(looping: bool): TweenSequence:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `380` | `std/gfx2d/sprite2d.aipl` | `tweenSequenceAdd` | `pub fn tweenSequenceAdd(mut seq: TweenSequence, tw: Tween): TweenSequence:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `381` | `std/gfx2d/sprite2d.aipl` | `stepTweenSequence` | `pub fn stepTweenSequence(mut seq: TweenSequence, dtMs: float): TweenSequence:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `382` | `std/gfx2d/sprite2d.aipl` | `tweenSequenceValue` | `pub fn tweenSequenceValue(seq: TweenSequence): float:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `383` | `std/gfx2d/sprite2d.aipl` | `stepTweenWithMode` | `pub fn stepTweenWithMode(tw: Tween, dtMs: float, easingType: int): float:` | `tests/functions/gfx2d/sprite2d_test.aipl` |
| `384` | `std/gfx2d/sprite_anim2d.aipl` | `createAnimator2D` | `pub fn createAnimator2D(clip: SpriteAnimationClip2D): SpriteAnimator2D:` | `tests/functions/gfx2d/sprite_anim2d_test.aipl` |
| `385` | `std/gfx2d/sprite_anim2d.aipl` | `stepAnimator2D` | `pub fn stepAnimator2D(anim: SpriteAnimator2D, dt: float): SpriteAnimator2D:` | `tests/functions/gfx2d/sprite_anim2d_test.aipl` |
| `386` | `std/gfx2d/sprite_anim2d.aipl` | `getCurrentFrameUv` | `pub fn getCurrentFrameUv(anim: SpriteAnimator2D): UvRect:` | `tests/functions/gfx2d/sprite_anim2d_test.aipl` |
| `387` | `std/gfx2d/sprite_anim2d.aipl` | `animMachineNew` | `pub fn animMachineNew(initialState: str, clips: [AnimClip]): AnimStateMachine:` | `tests/functions/gfx2d/sprite_anim2d_test.aipl` |
| `388` | `std/gfx2d/sprite_anim2d.aipl` | `animSetState` | `pub fn animSetState(sm: AnimStateMachine, newState: str): AnimStateMachine:` | `tests/functions/gfx2d/sprite_anim2d_test.aipl` |
| `389` | `std/gfx2d/sprite_anim2d.aipl` | `animStep` | `pub fn animStep(sm: AnimStateMachine, dtMs: float): AnimStateMachine:` | `tests/functions/gfx2d/sprite_anim2d_test.aipl` |
| `390` | `std/gfx2d/sprite_anim2d.aipl` | `animCurrentSpriteFrame` | `pub fn animCurrentSpriteFrame(sm: AnimStateMachine): int:` | `tests/functions/gfx2d/sprite_anim2d_test.aipl` |
| `391` | `std/gfx2d/sprite_anim2d.aipl` | `animModeOnce` | `pub fn animModeOnce(): int:` | `tests/functions/gfx2d/sprite_anim2d_test.aipl` |
| `392` | `std/gfx2d/sprite_anim2d.aipl` | `animModeLoop` | `pub fn animModeLoop(): int:` | `tests/functions/gfx2d/sprite_anim2d_test.aipl` |
| `393` | `std/gfx2d/sprite_anim2d.aipl` | `animModePingPong` | `pub fn animModePingPong(): int:` | `tests/functions/gfx2d/sprite_anim2d_test.aipl` |
| `394` | `std/gfx2d/sprite_anim2d.aipl` | `animClipToEx` | `pub fn animClipToEx(clip: AnimClip, pingPong: bool = false): AnimClipEx:` | `tests/functions/gfx2d/sprite_anim2d_test.aipl` |
| `395` | `std/gfx2d/sprite_anim2d.aipl` | `animClipFromEx` | `pub fn animClipFromEx(clipEx: AnimClipEx, fallbackState: str = "idle"): AnimClip:` | `tests/functions/gfx2d/sprite_anim2d_test.aipl` |
| `396` | `std/gfx2d/sprite_anim2d.aipl` | `sampleAnimClipEx` | `pub fn sampleAnimClipEx(clip: AnimClipEx, elapsedSec: float): int:` | `tests/functions/gfx2d/sprite_anim2d_test.aipl` |
| `397` | `std/gfx2d/sprite_anim2d.aipl` | `sampleAnimClip` | `pub fn sampleAnimClip(clip: AnimClip, elapsedSec: float, pingPong: bool = false): int:` | `tests/functions/gfx2d/sprite_anim2d_test.aipl` |
| `398` | `std/gfx2d/tilemap_renderer2d.aipl` | `createWangBlob47Autotiler` | `pub fn createWangBlob47Autotiler(): WangBlob47Autotiler:` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` |
| `399` | `std/gfx2d/tilemap_renderer2d.aipl` | `hasTileAt` | `fn hasTileAt(layer: TilemapLayer2D, c: int, r: int, target: int): bool:` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` |
| `400` | `std/gfx2d/tilemap_renderer2d.aipl` | `evaluateAutotileBitmask` | `pub fn evaluateAutotileBitmask(layer: TilemapLayer2D, col: int, row: int, targetTileType: int): int:` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` |
| `401` | `std/gfx2d/tilemap_renderer2d.aipl` | `resolveWang47TileIndex` | `pub fn resolveWang47TileIndex(autotiler: WangBlob47Autotiler, bitmask8: int): int:` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` |
| `402` | `std/gfx2d/tilemap_renderer2d.aipl` | `cullTilemapLayer` | `pub fn cullTilemapLayer(layer: TilemapLayer2D, bounds: ViewportBounds2D, tileW: float, tileH: float): [int]:` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` |
| `403` | `std/gfx2d/tilemap_renderer2d.aipl` | `tilemapNew` | `pub fn tilemapNew(width: int, height: int, tileSize: float, defaultTile: int = 0): Tilemap2D:` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` |
| `404` | `std/gfx2d/tilemap_renderer2d.aipl` | `tilemapInBounds` | `pub fn tilemapInBounds(m: Tilemap2D, col: int, row: int): bool:` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` |
| `405` | `std/gfx2d/tilemap_renderer2d.aipl` | `tilemapGet` | `pub fn tilemapGet(m: Tilemap2D, col: int, row: int): int:` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` |
| `406` | `std/gfx2d/tilemap_renderer2d.aipl` | `tilemapSet` | `pub fn tilemapSet(m: Tilemap2D, col: int, row: int, tileId: int): Tilemap2D:` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` |
| `407` | `std/gfx2d/tilemap_renderer2d.aipl` | `tilemapSetInPlace` | `pub fn tilemapSetInPlace(mut m: Tilemap2D, col: int, row: int, tileId: int): Tilemap2D:` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` |
| `408` | `std/gfx2d/tilemap_renderer2d.aipl` | `tilemapIsSolidAtGrid` | `pub fn tilemapIsSolidAtGrid(m: Tilemap2D, col: int, row: int): bool:` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` |
| `409` | `std/gfx2d/tilemap_renderer2d.aipl` | `tilemapFromAscii` | `pub fn tilemapFromAscii(rows: [str], tileSize: float): Tilemap2D:` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` |
| `410` | `std/gfx2d/tilemap_renderer2d.aipl` | `tilemapWorldToCol` | `pub fn tilemapWorldToCol(m: Tilemap2D, x: float): int:` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` |
| `411` | `std/gfx2d/tilemap_renderer2d.aipl` | `tilemapWorldToRow` | `pub fn tilemapWorldToRow(m: Tilemap2D, y: float): int:` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` |
| `412` | `std/gfx2d/tilemap_renderer2d.aipl` | `tilemapColToWorld` | `pub fn tilemapColToWorld(m: Tilemap2D, col: int): float:` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` |
| `413` | `std/gfx2d/tilemap_renderer2d.aipl` | `tilemapRowToWorld` | `pub fn tilemapRowToWorld(m: Tilemap2D, row: int): float:` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` |
| `414` | `std/gfx2d/tilemap_renderer2d.aipl` | `tilemapCheckAABB` | `pub fn tilemapCheckAABB(m: Tilemap2D, x: float, y: float, w: float, h: float): bool:` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` |
| `415` | `std/gfx2d/tilemap_renderer2d.aipl` | `tilemapMoveAndSlide` | `pub fn tilemapMoveAndSlide(m: Tilemap2D, x: float, y: float, w: float, h: float, vx: float, vy: float, dt: float): [float]:` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` |
| `416` | `std/gfx2d/tilemap_renderer2d.aipl` | `tilemapAutotile16Mask` | `pub fn tilemapAutotile16Mask(m: Tilemap2D, col: int, row: int, targetId: int): int:` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` |
| `417` | `std/gfx2d/tilemap_renderer2d.aipl` | `tilemapAutotile47CanonicalMask` | `pub fn tilemapAutotile47CanonicalMask(m: Tilemap2D, col: int, row: int, targetId: int): int:` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` |
| `418` | `std/gfx2d/tilemap_renderer2d.aipl` | `tilemapBlobMaskToIndex47` | `pub fn tilemapBlobMaskToIndex47(canonicalMask: int): int:` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` |
| `419` | `std/gfx2d/tilemap_renderer2d.aipl` | `tilemapMoveAndSlideEx` | `pub fn tilemapMoveAndSlideEx(m: Tilemap2D, x: float, y: float, w: float, h: float, vx: float, vy: float, dt: float): SlideResult2D:` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` |
| `420` | `std/gfx2d/tilemap_renderer2d.aipl` | `tilemapRaycastDDA` | `pub fn tilemapRaycastDDA(m: Tilemap2D, startX: float, startY: float, dirX: float, dirY: float, maxDist: float): TileRaycastHit2D:` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `createSpriteBatch2D` (`std/gfx2d/batch2d.aipl`)

- **Signature**: `pub fn createSpriteBatch2D(maxQuads: int = 2048): SpriteBatch2D:`
- **Import**: `import * from "std/gfx2d/batch2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `maxQuads: int = 2048` | **Returns**: `SpriteBatch2D`
- **Unit Test**: `tests/functions/gfx2d/batch2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `createSpriteBatch2D` 2D quad batch coalescing on matching texture ID, automatic flush on texture change, and UV frame slicing. Concrete nominal inputs: `maxQuads: int = 1`; exercises core body path returning/computing `SpriteBatch2D(`.

```aipl
module tests.functions.gfx2d.batch2d_z1_test
import * from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_batch2d_createSpriteBatch2D_1(): int:
  let arg_maxQuads = 4
  let edge_maxQuads = 1
  let resNom = createSpriteBatch2D(arg_maxQuads)
  let resEdge = createSpriteBatch2D(edge_maxQuads)
  assertEqInt(resNom.maxQuads, 4, "createSpriteBatch2D nominal resNom.maxQuads == 4")
  assertEqInt(resEdge.maxQuads, 1, "createSpriteBatch2D boundary resEdge.maxQuads == 1")
  ret 0
```

---

### `beginSpriteBatch` (`std/gfx2d/batch2d.aipl`)

- **Signature**: `pub fn beginSpriteBatch(batch: SpriteBatch2D): SpriteBatch2D:`
- **Import**: `import * from "std/gfx2d/batch2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `batch: SpriteBatch2D` | **Returns**: `SpriteBatch2D`
- **Unit Test**: `tests/functions/gfx2d/batch2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `beginSpriteBatch` 2D quad batch coalescing on matching texture ID, automatic flush on texture change, and UV frame slicing. Concrete nominal inputs: `batch: SpriteBatch2D = SpriteBatch2D(maxQuads = 1, vertices = [BatchVertex2D(x = 0, y = 0, u = 0, v = 0, colorRgba = 0)], indices = [1], drawCalls = [BatchDrawCall(textureId = 0, blendMode = 0, startIndex = 0, indexCount = 0)], currentTexture = 1, currentBlend = 64)`; exercises core body path returning/computing `SpriteBatch2D(`.

```aipl
module tests.functions.gfx2d.batch2d_z2_test
import * from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_batch2d_beginSpriteBatch_2(): int:
  let arg_batch = SpriteBatch2D(maxQuads = 4, vertices = [], indices = [], drawCalls = [], currentTexture = 4, currentBlend = 4)
  let edge_batch = SpriteBatch2D(maxQuads = 1, vertices = [], indices = [], drawCalls = [], currentTexture = 1, currentBlend = 1)
  let resNom = beginSpriteBatch(arg_batch)
  let resEdge = beginSpriteBatch(edge_batch)
  assertEqInt(resNom.maxQuads, 4, "beginSpriteBatch nominal resNom.maxQuads == 4")
  assertEqInt(resEdge.maxQuads, 1, "beginSpriteBatch boundary resEdge.maxQuads == 1")
  ret 0
```

---

### `pushBatchQuad` (`std/gfx2d/batch2d.aipl`)

- **Signature**: `pub fn pushBatchQuad(batch: SpriteBatch2D, textureId: int, blendMode: int, v0: BatchVertex2D, v1: BatchVertex2D, v2: BatchVertex2D, v3: BatchVertex2D): SpriteBatch2D:`
- **Import**: `import * from "std/gfx2d/batch2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `batch: SpriteBatch2D, textureId: int, blendMode: int, v0: BatchVertex2D, v1: BatchVertex2D, v2: BatchVertex2D, v3: BatchVertex2D` | **Returns**: `SpriteBatch2D`
- **Unit Test**: `tests/functions/gfx2d/batch2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `pushBatchQuad` 2D quad batch coalescing on matching texture ID, automatic flush on texture change, and UV frame slicing. Concrete nominal inputs: `batch: SpriteBatch2D = SpriteBatch2D(maxQuads = 1, vertices = [BatchVertex2D(x = 0, y = 0, u = 0, v = 0, colorRgba = 0)], indices = [1], drawCalls = [BatchDrawCall(textureId = 0, blendMode = 0, startIndex = 0, indexCount = 0)], currentTexture = 1, currentBlend = 64)`, `textureId: int = 1`, `blendMode: int = 64`, `v0: BatchVertex2D = BatchVertex2D(x = 1.0, y = 1.0, u = 1.0, v = 1.0, colorRgba = 1)`, `v1: BatchVertex2D = BatchVertex2D(x = 1.0, y = 1.0, u = 1.0, v = 1.0, colorRgba = 1)`, `v2: BatchVertex2D = BatchVertex2D(x = 1.0, y = 1.0, u = 1.0, v = 1.0, colorRgba = 1)`, `v3: BatchVertex2D = BatchVertex2D(x = 1.0, y = 1.0, u = 1.0, v = 1.0, colorRgba = 1)`; exercises core body path returning/computing `SpriteBatch2D(`.

```aipl
module tests.functions.gfx2d.batch2d_z3_test
import * from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_batch2d_pushBatchQuad_3(): int:
  let arg_batch = SpriteBatch2D(maxQuads = 4, vertices = [], indices = [], drawCalls = [], currentTexture = 4, currentBlend = 4)
  let edge_batch = SpriteBatch2D(maxQuads = 1, vertices = [], indices = [], drawCalls = [], currentTexture = 1, currentBlend = 1)
  let arg_textureId = 1
  let edge_textureId = 0
  let arg_blendMode = 4
  let edge_blendMode = 1
  let arg_v0 = BatchVertex2D(x = 1.0, y = 1.0, u = 1.0, v = 1.0, colorRgba = 4)
  let edge_v0 = BatchVertex2D(x = 0.5, y = 0.5, u = 0.5, v = 0.5, colorRgba = 1)
  let arg_v1 = BatchVertex2D(x = 1.0, y = 1.0, u = 1.0, v = 1.0, colorRgba = 4)
  let edge_v1 = BatchVertex2D(x = 0.5, y = 0.5, u = 0.5, v = 0.5, colorRgba = 1)
  let arg_v2 = BatchVertex2D(x = 1.0, y = 1.0, u = 1.0, v = 1.0, colorRgba = 4)
  let edge_v2 = BatchVertex2D(x = 0.5, y = 0.5, u = 0.5, v = 0.5, colorRgba = 1)
  let arg_v3 = BatchVertex2D(x = 1.0, y = 1.0, u = 1.0, v = 1.0, colorRgba = 4)
  let edge_v3 = BatchVertex2D(x = 0.5, y = 0.5, u = 0.5, v = 0.5, colorRgba = 1)
  let resNom = pushBatchQuad(arg_batch, arg_textureId, arg_blendMode, arg_v0, arg_v1, arg_v2, arg_v3)
  let resEdge = pushBatchQuad(edge_batch, edge_textureId, edge_blendMode, edge_v0, edge_v1, edge_v2, edge_v3)
  assertEqInt(resNom.maxQuads, 4, "pushBatchQuad nominal resNom.maxQuads == 4")
  assertEqInt(resEdge.maxQuads, 1, "pushBatchQuad boundary resEdge.maxQuads == 1")
  ret 0
```

---

### `flushSpriteBatch` (`std/gfx2d/batch2d.aipl`)

- **Signature**: `pub fn flushSpriteBatch(batch: SpriteBatch2D): SpriteBatch2D:`
- **Import**: `import * from "std/gfx2d/batch2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `batch: SpriteBatch2D` | **Returns**: `SpriteBatch2D`
- **Unit Test**: `tests/functions/gfx2d/batch2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `flushSpriteBatch` 2D quad batch coalescing on matching texture ID, automatic flush on texture change, and UV frame slicing. Concrete nominal inputs: `batch: SpriteBatch2D = SpriteBatch2D(maxQuads = 1, vertices = [BatchVertex2D(x = 0, y = 0, u = 0, v = 0, colorRgba = 0)], indices = [1], drawCalls = [BatchDrawCall(textureId = 0, blendMode = 0, startIndex = 0, indexCount = 0)], currentTexture = 1, currentBlend = 64)`; exercises core body path returning/computing `beginSpriteBatch(batch)`.

```aipl
module tests.functions.gfx2d.batch2d_z4_test
import * from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_batch2d_flushSpriteBatch_4(): int:
  let arg_batch = SpriteBatch2D(maxQuads = 4, vertices = [], indices = [], drawCalls = [], currentTexture = 4, currentBlend = 4)
  let edge_batch = SpriteBatch2D(maxQuads = 1, vertices = [], indices = [], drawCalls = [], currentTexture = 1, currentBlend = 1)
  let resNom = flushSpriteBatch(arg_batch)
  let resEdge = flushSpriteBatch(edge_batch)
  assertEqInt(resNom.maxQuads, 4, "flushSpriteBatch nominal resNom.maxQuads == 4")
  assertEqInt(resEdge.maxQuads, 1, "flushSpriteBatch boundary resEdge.maxQuads == 1")
  ret 0
```

---

### `spriteAtlasFrame` (`std/gfx2d/batch2d.aipl`)

- **Signature**: `pub fn spriteAtlasFrame(col: int, row: int, cellW: int, cellH: int, sheetW: int, sheetH: int): SpriteFrame:`
- **Import**: `import * from "std/gfx2d/batch2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `col: int, row: int, cellW: int, cellH: int, sheetW: int, sheetH: int` | **Returns**: `SpriteFrame`
- **Unit Test**: `tests/functions/gfx2d/batch2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `spriteAtlasFrame` 2D quad batch coalescing on matching texture ID, automatic flush on texture change, and UV frame slicing. Concrete nominal inputs: `col: int = 1`, `row: int = 1`, `cellW: int = 1`, `cellH: int = 1`, `sheetW: int = 1`, `sheetH: int = 1`; exercises core body path returning/computing `SpriteFrame(u0 = x0 / sw, v0 = y0 / sh, u1 = (x0 + float(cellW)) / sw, v1 = (y0 + float(cellH)) / sh, w = cellW, h = cellH)`.

```aipl
module tests.functions.gfx2d.batch2d_z5_test
import * from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_batch2d_spriteAtlasFrame_5(): int:
  let arg_col = 1
  let edge_col = 0
  let arg_row = 1
  let edge_row = 0
  let arg_cellW = 2
  let edge_cellW = 0
  let arg_cellH = 2
  let edge_cellH = 0
  let arg_sheetW = 2
  let edge_sheetW = 0
  let arg_sheetH = 2
  let edge_sheetH = 0
  let resNom = spriteAtlasFrame(arg_col, arg_row, arg_cellW, arg_cellH, arg_sheetW, arg_sheetH)
  let resEdge = spriteAtlasFrame(edge_col, edge_row, edge_cellW, edge_cellH, edge_sheetW, edge_sheetH)
  assertApproxEq(resNom.u0, 1.0, 0.001, "spriteAtlasFrame nominal resNom.u0 ~= 1.0")
  assertApproxEq(resEdge.u0, 0.0, 0.001, "spriteAtlasFrame boundary resEdge.u0 ~= 0.0")
  ret 0
```

---

### `spriteAnimStep` (`std/gfx2d/batch2d.aipl`)

- **Signature**: `pub fn spriteAnimStep(mut anim: SpriteAnimation, dt: float): SpriteAnimation:`
- **Import**: `import * from "std/gfx2d/batch2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut anim: SpriteAnimation, dt: float` | **Returns**: `SpriteAnimation`
- **Unit Test**: `tests/functions/gfx2d/batch2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `spriteAnimStep` 2D quad batch coalescing on matching texture ID, automatic flush on texture change, and UV frame slicing. Concrete nominal inputs: `anim: SpriteAnimation = SpriteAnimation(frames = [SpriteFrame(u0 = 0, v0 = 0, u1 = 0, v1 = 0, w = 0, h = 0)], fps = 1.0, looping = true, pingPong = true, elapsed = 1.0)`, `dt: float = 0.016667`; exercises core body path returning/computing `anim`.

```aipl
module tests.functions.gfx2d.batch2d_z6_test
import * from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_batch2d_spriteAnimStep_6(): int:
  let arg_anim = SpriteAnimation(frames = [], fps = 1.0, looping = true, pingPong = true, elapsed = 1.0)
  let edge_anim = SpriteAnimation(frames = [], fps = 0.5, looping = false, pingPong = false, elapsed = 0.5)
  let arg_dt = 2.0
  let edge_dt = 1.0
  let resNom = spriteAnimStep(arg_anim, arg_dt)
  let resEdge = spriteAnimStep(edge_anim, edge_dt)
  assertEqInt(resNom.frames.len(), 0, "spriteAnimStep nominal resNom.frames.len() == 0")
  assertEqInt(resEdge.frames.len(), 0, "spriteAnimStep boundary resEdge.frames.len() == 0")
  ret 0
```

---

### `spriteAnimSampleFrame` (`std/gfx2d/batch2d.aipl`)

- **Signature**: `pub fn spriteAnimSampleFrame(anim: SpriteAnimation): SpriteFrame:`
- **Import**: `import * from "std/gfx2d/batch2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `anim: SpriteAnimation` | **Returns**: `SpriteFrame`
- **Unit Test**: `tests/functions/gfx2d/batch2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `spriteAnimSampleFrame` 2D quad batch coalescing on matching texture ID, automatic flush on texture change, and UV frame slicing. Concrete nominal inputs: `anim: SpriteAnimation = SpriteAnimation(frames = [SpriteFrame(u0 = 0, v0 = 0, u1 = 0, v1 = 0, w = 0, h = 0)], fps = 1.0, looping = true, pingPong = true, elapsed = 1.0)`; exercises core body path returning/computing `anim.frames[rawFrame % n]`.

```aipl
module tests.functions.gfx2d.batch2d_z7_test
import * from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_batch2d_spriteAnimSampleFrame_7(): int:
  let arg_anim = SpriteAnimation(frames = [], fps = 1.0, looping = true, pingPong = true, elapsed = 1.0)
  let edge_anim = SpriteAnimation(frames = [], fps = 0.5, looping = false, pingPong = false, elapsed = 0.5)
  let resNom = spriteAnimSampleFrame(arg_anim)
  let resEdge = spriteAnimSampleFrame(edge_anim)
  assertApproxEq(resNom.u0, 0.0, 0.001, "spriteAnimSampleFrame nominal resNom.u0 ~= 0.0")
  assertApproxEq(resEdge.u0, 0.0, 0.001, "spriteAnimSampleFrame boundary resEdge.u0 ~= 0.0")
  ret 0
```

---

### `drawSpriteTransformed` (`std/gfx2d/batch2d.aipl`)

- **Signature**: `pub fn drawSpriteTransformed(imgId: int, tr: SpriteTransform2D): void:`
- **Import**: `import * from "std/gfx2d/batch2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `imgId: int, tr: SpriteTransform2D` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/batch2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawSpriteTransformed` 2D quad batch coalescing on matching texture ID, automatic flush on texture change, and UV frame slicing. Concrete nominal inputs: `imgId: int = 1`, `tr: SpriteTransform2D = SpriteTransform2D(x = 1.0, y = 1.0, w = 1.0, h = 1.0, rotRad = 1.0, pivotX = 1.0, pivotY = 1.0, tintHex = 1, flipX = true, flipY = true)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.batch2d_z8_test
import * from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_batch2d_drawSpriteTransformed_8(): int:
  mut completedCalls = 0
  let arg_imgId = 4
  let edge_imgId = 1
  let arg_tr = SpriteTransform2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, rotRad = 1.0, pivotX = 1.0, pivotY = 1.0, tintHex = 4, flipX = true, flipY = true)
  let edge_tr = SpriteTransform2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, rotRad = 0.5, pivotX = 0.5, pivotY = 0.5, tintHex = 1, flipX = false, flipY = false)
  drawSpriteTransformed(arg_imgId, arg_tr)
  drawSpriteTransformed(edge_imgId, edge_tr)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawSpriteTransformed nominal and boundary void calls completed")
  ret 0
```

---

### `drawSpriteNineSlice` (`std/gfx2d/batch2d.aipl`)

- **Signature**: `pub fn drawSpriteNineSlice(imgId: int, sx: float, sy: float, sw: float, sh: float, dx: float, dy: float, dw: float, dh: float, left: float, top: float, right: float, bottom: float): void:`
- **Import**: `import * from "std/gfx2d/batch2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `imgId: int, sx: float, sy: float, sw: float, sh: float, dx: float, dy: float, dw: float, dh: float, left: float, top: float, right: float, bottom: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/batch2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `drawSpriteNineSlice` 2D quad batch coalescing on matching texture ID, automatic flush on texture change, and UV frame slicing. Concrete nominal inputs: `imgId: int = 1`, `sx: float = 1.0`, `sy: float = 1.0`, `sw: float = 1.0`, `sh: float = 1.0`, `dx: float = 1.0`, `dy: float = 1.0`, `dw: float = 1.0`, `dh: float = 1.0`, `left: float = 1.0`, `top: float = 1.0`, `right: float = 1.0`, `bottom: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.batch2d_z9_test
import * from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_batch2d_drawSpriteNineSlice_9(): int:
  mut completedCalls = 0
  let arg_imgId = 4
  let edge_imgId = 1
  let arg_sx = 1.0
  let edge_sx = 0.5
  let arg_sy = 1.0
  let edge_sy = 0.5
  let arg_sw = 2.0
  let edge_sw = 1.0
  let arg_sh = 2.0
  let edge_sh = 1.0
  let arg_dx = 1.0
  let edge_dx = 0.5
  let arg_dy = 1.0
  let edge_dy = 0.5
  let arg_dw = 2.0
  let edge_dw = 1.0
  let arg_dh = 2.0
  let edge_dh = 1.0
  let arg_left = 1.0
  let edge_left = 0.5
  let arg_top = 1.0
  let edge_top = 0.5
  let arg_right = 2.0
  let edge_right = 1.0
  let arg_bottom = 1.0
  let edge_bottom = 0.5
  drawSpriteNineSlice(arg_imgId, arg_sx, arg_sy, arg_sw, arg_sh, arg_dx, arg_dy, arg_dw, arg_dh, arg_left, arg_top, arg_right, arg_bottom)
  drawSpriteNineSlice(edge_imgId, edge_sx, edge_sy, edge_sw, edge_sh, edge_dx, edge_dy, edge_dw, edge_dh, edge_left, edge_top, edge_right, edge_bottom)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawSpriteNineSlice nominal and boundary void calls completed")
  ret 0
```

---

### `createCamera2D` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn createCamera2D(viewportW: float = 800.0, viewportH: float = 600.0, zoom: float = 1.0): Camera2D:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `viewportW: float = 800.0, viewportH: float = 600.0, zoom: float = 1.0` | **Returns**: `Camera2D`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `createCamera2D` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `viewportW: float = 1.0`, `viewportH: float = 1.0`, `zoom: float = 1.0`; exercises core body path returning/computing `Camera2D(`.

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

---

### `camera2DNew` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn camera2DNew(a: float = 800.0, b: float = 600.0, zoom: float = 1.0, viewportW: float = -1.0, viewportH: float = -1.0): Camera2D:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: float = 800.0, b: float = 600.0, zoom: float = 1.0, viewportW: float = -1.0, viewportH: float = -1.0` | **Returns**: `Camera2D`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `camera2DNew` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `a: float = 1.0`, `b: float = 1.0`, `zoom: float = 1.0`, `viewportW: float = 1.0`, `viewportH: float = 1.0`; exercises core body path returning/computing `Camera2D(`.

```aipl
module tests.functions.gfx2d.camera2d_z2_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_camera2DNew_2(): int:
  let arg_a = 1.0
  let edge_a = 0.5
  let arg_b = 1.0
  let edge_b = 0.5
  let arg_zoom = 1.0
  let edge_zoom = 0.5
  let arg_viewportW = 2.0
  let edge_viewportW = 1.0
  let arg_viewportH = 2.0
  let edge_viewportH = 1.0
  let resNom = camera2DNew(arg_a, arg_b, arg_zoom, arg_viewportW, arg_viewportH)
  let resEdge = camera2DNew(edge_a, edge_b, edge_zoom, edge_viewportW, edge_viewportH)
  assertApproxEq(resNom.zoom, 1.0, 0.001, "camera2DNew nominal resNom.zoom ~= 1.0")
  assertApproxEq(resEdge.zoom, 0.5, 0.001, "camera2DNew boundary resEdge.zoom ~= 0.5")
  ret 0
```

---

### `setCameraCenter` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn setCameraCenter(cam: Camera2D, center: Vec2): Camera2D:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera2D, center: Vec2` | **Returns**: `Camera2D`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `setCameraCenter` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `cam: Camera2D = Camera2D(center = Vec2 = Vec2(x = 0.0, y = 0.0)(), zoom = float = 1.0(), rotationRad = float = 0.0(), viewportWidth = float = 800.0(), viewportHeight = float = 600.0(), trauma = float = 0.0(), x = float = 0.0(), y = float = 0.0(), targetX = float = 0.0(), targetY = float = 0.0(), rotation = float = 0.0(), shakeOffsetX = float = 0.0(), shakeOffsetY = float = 0.0(), viewportW = float = 800.0(), viewportH = float = 600.0())`, `center: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `Camera2D(`.

```aipl
module tests.functions.gfx2d.camera2d_z3_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_setCameraCenter_3(): int:
  let arg_cam = Camera2D(center = Vec2(x = 1.0, y = 1.0), zoom = 1.0, rotationRad = 1.0, viewportWidth = 2.0, viewportHeight = 2.0, trauma = 1.0, x = 1.0, y = 1.0, targetX = 1.0, targetY = 1.0, rotation = 1.0, shakeOffsetX = 2.0, shakeOffsetY = 2.0, viewportW = 2.0, viewportH = 2.0)
  let edge_cam = Camera2D(center = Vec2(x = 0.5, y = 0.5), zoom = 0.5, rotationRad = 0.5, viewportWidth = 1.0, viewportHeight = 1.0, trauma = 0.5, x = 0.5, y = 0.5, targetX = 0.5, targetY = 0.5, rotation = 0.5, shakeOffsetX = 1.0, shakeOffsetY = 1.0, viewportW = 1.0, viewportH = 1.0)
  let arg_center = Vec2(x = 1.0, y = 1.0)
  let edge_center = Vec2(x = 0.5, y = 0.5)
  let resNom = setCameraCenter(arg_cam, arg_center)
  let resEdge = setCameraCenter(edge_cam, edge_center)
  assertApproxEq(resNom.zoom, 1.0, 0.001, "setCameraCenter nominal resNom.zoom ~= 1.0")
  assertApproxEq(resEdge.zoom, 0.5, 0.001, "setCameraCenter boundary resEdge.zoom ~= 0.5")
  ret 0
```

---

### `setCameraZoom` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn setCameraZoom(cam: Camera2D, zoom: float): Camera2D:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera2D, zoom: float` | **Returns**: `Camera2D`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `setCameraZoom` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `cam: Camera2D = Camera2D(center = Vec2 = Vec2(x = 0.0, y = 0.0)(), zoom = float = 1.0(), rotationRad = float = 0.0(), viewportWidth = float = 800.0(), viewportHeight = float = 600.0(), trauma = float = 0.0(), x = float = 0.0(), y = float = 0.0(), targetX = float = 0.0(), targetY = float = 0.0(), rotation = float = 0.0(), shakeOffsetX = float = 0.0(), shakeOffsetY = float = 0.0(), viewportW = float = 800.0(), viewportH = float = 600.0())`, `zoom: float = 1.0`; exercises core body path returning/computing `Camera2D(`.

```aipl
module tests.functions.gfx2d.camera2d_z4_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_setCameraZoom_4(): int:
  let arg_cam = Camera2D(center = Vec2(x = 1.0, y = 1.0), zoom = 1.0, rotationRad = 1.0, viewportWidth = 2.0, viewportHeight = 2.0, trauma = 1.0, x = 1.0, y = 1.0, targetX = 1.0, targetY = 1.0, rotation = 1.0, shakeOffsetX = 2.0, shakeOffsetY = 2.0, viewportW = 2.0, viewportH = 2.0)
  let edge_cam = Camera2D(center = Vec2(x = 0.5, y = 0.5), zoom = 0.5, rotationRad = 0.5, viewportWidth = 1.0, viewportHeight = 1.0, trauma = 0.5, x = 0.5, y = 0.5, targetX = 0.5, targetY = 0.5, rotation = 0.5, shakeOffsetX = 1.0, shakeOffsetY = 1.0, viewportW = 1.0, viewportH = 1.0)
  let arg_zoom = 1.0
  let edge_zoom = 0.5
  let resNom = setCameraZoom(arg_cam, arg_zoom)
  let resEdge = setCameraZoom(edge_cam, edge_zoom)
  assertApproxEq(resNom.zoom, 1.0, 0.001, "setCameraZoom nominal resNom.zoom ~= 1.0")
  assertApproxEq(resEdge.zoom, 0.5, 0.001, "setCameraZoom boundary resEdge.zoom ~= 0.5")
  ret 0
```

---

### `addCameraTrauma` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn addCameraTrauma(cam: Camera2D, amount: float): Camera2D:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera2D, amount: float` | **Returns**: `Camera2D`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `addCameraTrauma` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `cam: Camera2D = Camera2D(center = Vec2 = Vec2(x = 0.0, y = 0.0)(), zoom = float = 1.0(), rotationRad = float = 0.0(), viewportWidth = float = 800.0(), viewportHeight = float = 600.0(), trauma = float = 0.0(), x = float = 0.0(), y = float = 0.0(), targetX = float = 0.0(), targetY = float = 0.0(), rotation = float = 0.0(), shakeOffsetX = float = 0.0(), shakeOffsetY = float = 0.0(), viewportW = float = 800.0(), viewportH = float = 600.0())`, `amount: float = 1.0`; exercises core body path returning/computing `Camera2D(`.

```aipl
module tests.functions.gfx2d.camera2d_z5_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_addCameraTrauma_5(): int:
  let arg_cam = Camera2D(center = Vec2(x = 1.0, y = 1.0), zoom = 1.0, rotationRad = 1.0, viewportWidth = 2.0, viewportHeight = 2.0, trauma = 1.0, x = 1.0, y = 1.0, targetX = 1.0, targetY = 1.0, rotation = 1.0, shakeOffsetX = 2.0, shakeOffsetY = 2.0, viewportW = 2.0, viewportH = 2.0)
  let edge_cam = Camera2D(center = Vec2(x = 0.5, y = 0.5), zoom = 0.5, rotationRad = 0.5, viewportWidth = 1.0, viewportHeight = 1.0, trauma = 0.5, x = 0.5, y = 0.5, targetX = 0.5, targetY = 0.5, rotation = 0.5, shakeOffsetX = 1.0, shakeOffsetY = 1.0, viewportW = 1.0, viewportH = 1.0)
  let arg_amount = 1.0
  let edge_amount = 0.5
  let resNom = addCameraTrauma(arg_cam, arg_amount)
  let resEdge = addCameraTrauma(edge_cam, edge_amount)
  assertApproxEq(resNom.zoom, 1.0, 0.001, "addCameraTrauma nominal resNom.zoom ~= 1.0")
  assertApproxEq(resEdge.zoom, 0.5, 0.001, "addCameraTrauma boundary resEdge.zoom ~= 0.5")
  ret 0
```

---

### `camera2DAddTrauma` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn camera2DAddTrauma(cam: Camera2D, amount: float): Camera2D:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera2D, amount: float` | **Returns**: `Camera2D`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `camera2DAddTrauma` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `cam: Camera2D = Camera2D(center = Vec2 = Vec2(x = 0.0, y = 0.0)(), zoom = float = 1.0(), rotationRad = float = 0.0(), viewportWidth = float = 800.0(), viewportHeight = float = 600.0(), trauma = float = 0.0(), x = float = 0.0(), y = float = 0.0(), targetX = float = 0.0(), targetY = float = 0.0(), rotation = float = 0.0(), shakeOffsetX = float = 0.0(), shakeOffsetY = float = 0.0(), viewportW = float = 800.0(), viewportH = float = 600.0())`, `amount: float = 1.0`; exercises core body path returning/computing `addCameraTrauma(cam, amount)`.

```aipl
module tests.functions.gfx2d.camera2d_z6_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_camera2DAddTrauma_6(): int:
  let arg_cam = Camera2D(center = Vec2(x = 1.0, y = 1.0), zoom = 1.0, rotationRad = 1.0, viewportWidth = 2.0, viewportHeight = 2.0, trauma = 1.0, x = 1.0, y = 1.0, targetX = 1.0, targetY = 1.0, rotation = 1.0, shakeOffsetX = 2.0, shakeOffsetY = 2.0, viewportW = 2.0, viewportH = 2.0)
  let edge_cam = Camera2D(center = Vec2(x = 0.5, y = 0.5), zoom = 0.5, rotationRad = 0.5, viewportWidth = 1.0, viewportHeight = 1.0, trauma = 0.5, x = 0.5, y = 0.5, targetX = 0.5, targetY = 0.5, rotation = 0.5, shakeOffsetX = 1.0, shakeOffsetY = 1.0, viewportW = 1.0, viewportH = 1.0)
  let arg_amount = 1.0
  let edge_amount = 0.5
  let resNom = camera2DAddTrauma(arg_cam, arg_amount)
  let resEdge = camera2DAddTrauma(edge_cam, edge_amount)
  assertApproxEq(resNom.zoom, 1.0, 0.001, "camera2DAddTrauma nominal resNom.zoom ~= 1.0")
  assertApproxEq(resEdge.zoom, 0.5, 0.001, "camera2DAddTrauma boundary resEdge.zoom ~= 0.5")
  ret 0
```

---

### `updateCameraShake` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn updateCameraShake(cam: Camera2D, dt: float, decayRate: float = 1.0): Camera2D:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera2D, dt: float, decayRate: float = 1.0` | **Returns**: `Camera2D`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `updateCameraShake` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `cam: Camera2D = Camera2D(center = Vec2 = Vec2(x = 0.0, y = 0.0)(), zoom = float = 1.0(), rotationRad = float = 0.0(), viewportWidth = float = 800.0(), viewportHeight = float = 600.0(), trauma = float = 0.0(), x = float = 0.0(), y = float = 0.0(), targetX = float = 0.0(), targetY = float = 0.0(), rotation = float = 0.0(), shakeOffsetX = float = 0.0(), shakeOffsetY = float = 0.0(), viewportW = float = 800.0(), viewportH = float = 600.0())`, `dt: float = 0.016667`, `decayRate: float = 1.0`; exercises core body path returning/computing `Camera2D(`.

```aipl
module tests.functions.gfx2d.camera2d_z7_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_updateCameraShake_7(): int:
  let arg_cam = Camera2D(center = Vec2(x = 1.0, y = 1.0), zoom = 1.0, rotationRad = 1.0, viewportWidth = 2.0, viewportHeight = 2.0, trauma = 1.0, x = 1.0, y = 1.0, targetX = 1.0, targetY = 1.0, rotation = 1.0, shakeOffsetX = 2.0, shakeOffsetY = 2.0, viewportW = 2.0, viewportH = 2.0)
  let edge_cam = Camera2D(center = Vec2(x = 0.5, y = 0.5), zoom = 0.5, rotationRad = 0.5, viewportWidth = 1.0, viewportHeight = 1.0, trauma = 0.5, x = 0.5, y = 0.5, targetX = 0.5, targetY = 0.5, rotation = 0.5, shakeOffsetX = 1.0, shakeOffsetY = 1.0, viewportW = 1.0, viewportH = 1.0)
  let arg_dt = 2.0
  let edge_dt = 1.0
  let arg_decayRate = 2.0
  let edge_decayRate = 1.0
  let resNom = updateCameraShake(arg_cam, arg_dt, arg_decayRate)
  let resEdge = updateCameraShake(edge_cam, edge_dt, edge_decayRate)
  assertApproxEq(resNom.zoom, 1.0, 0.001, "updateCameraShake nominal resNom.zoom ~= 1.0")
  assertApproxEq(resEdge.zoom, 0.5, 0.001, "updateCameraShake boundary resEdge.zoom ~= 0.5")
  ret 0
```

---

### `computeCameraShakeOffset` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn computeCameraShakeOffset(cam: Camera2D, seedTime: float, maxAngleRad: float = 0.1, maxOffsetPx: float = 16.0): Vec2:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera2D, seedTime: float, maxAngleRad: float = 0.1, maxOffsetPx: float = 16.0` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `computeCameraShakeOffset` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `cam: Camera2D = Camera2D(center = Vec2 = Vec2(x = 0.0, y = 0.0)(), zoom = float = 1.0(), rotationRad = float = 0.0(), viewportWidth = float = 800.0(), viewportHeight = float = 600.0(), trauma = float = 0.0(), x = float = 0.0(), y = float = 0.0(), targetX = float = 0.0(), targetY = float = 0.0(), rotation = float = 0.0(), shakeOffsetX = float = 0.0(), shakeOffsetY = float = 0.0(), viewportW = float = 800.0(), viewportH = float = 600.0())`, `seedTime: float = 0.016667`, `maxAngleRad: float = 1.0`, `maxOffsetPx: float = 1.0`; exercises core body path returning/computing `Vec2(`.

```aipl
module tests.functions.gfx2d.camera2d_z8_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_computeCameraShakeOffset_8(): int:
  let arg_cam = Camera2D(center = Vec2(x = 1.0, y = 1.0), zoom = 1.0, rotationRad = 1.0, viewportWidth = 2.0, viewportHeight = 2.0, trauma = 1.0, x = 1.0, y = 1.0, targetX = 1.0, targetY = 1.0, rotation = 1.0, shakeOffsetX = 2.0, shakeOffsetY = 2.0, viewportW = 2.0, viewportH = 2.0)
  let edge_cam = Camera2D(center = Vec2(x = 0.5, y = 0.5), zoom = 0.5, rotationRad = 0.5, viewportWidth = 1.0, viewportHeight = 1.0, trauma = 0.5, x = 0.5, y = 0.5, targetX = 0.5, targetY = 0.5, rotation = 0.5, shakeOffsetX = 1.0, shakeOffsetY = 1.0, viewportW = 1.0, viewportH = 1.0)
  let arg_seedTime = 2.0
  let edge_seedTime = 1.0
  let arg_maxAngleRad = 2.0
  let edge_maxAngleRad = 1.0
  let arg_maxOffsetPx = 2.0
  let edge_maxOffsetPx = 1.0
  let resNom = computeCameraShakeOffset(arg_cam, arg_seedTime, arg_maxAngleRad, arg_maxOffsetPx)
  let resEdge = computeCameraShakeOffset(edge_cam, edge_seedTime, edge_maxAngleRad, edge_maxOffsetPx)
  assertApproxEq(resNom.x, 0.421444, 0.001, "computeCameraShakeOffset nominal resNom.x ~= 0.421444")
  assertApproxEq(resEdge.x, -0.188586, 0.001, "computeCameraShakeOffset boundary resEdge.x ~= -0.188586")
  ret 0
```

---

### `worldToScreen2D` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn worldToScreen2D(cam: Camera2D, worldPt: Vec2): Vec2:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera2D, worldPt: Vec2` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `worldToScreen2D` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `cam: Camera2D = Camera2D(center = Vec2 = Vec2(x = 0.0, y = 0.0)(), zoom = float = 1.0(), rotationRad = float = 0.0(), viewportWidth = float = 800.0(), viewportHeight = float = 600.0(), trauma = float = 0.0(), x = float = 0.0(), y = float = 0.0(), targetX = float = 0.0(), targetY = float = 0.0(), rotation = float = 0.0(), shakeOffsetX = float = 0.0(), shakeOffsetY = float = 0.0(), viewportW = float = 800.0(), viewportH = float = 600.0())`, `worldPt: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `Vec2(`.

```aipl
module tests.functions.gfx2d.camera2d_z9_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_worldToScreen2D_9(): int:
  let arg_cam = Camera2D(center = Vec2(x = 1.0, y = 1.0), zoom = 1.0, rotationRad = 1.0, viewportWidth = 2.0, viewportHeight = 2.0, trauma = 1.0, x = 1.0, y = 1.0, targetX = 1.0, targetY = 1.0, rotation = 1.0, shakeOffsetX = 2.0, shakeOffsetY = 2.0, viewportW = 2.0, viewportH = 2.0)
  let edge_cam = Camera2D(center = Vec2(x = 0.5, y = 0.5), zoom = 0.5, rotationRad = 0.5, viewportWidth = 1.0, viewportHeight = 1.0, trauma = 0.5, x = 0.5, y = 0.5, targetX = 0.5, targetY = 0.5, rotation = 0.5, shakeOffsetX = 1.0, shakeOffsetY = 1.0, viewportW = 1.0, viewportH = 1.0)
  let arg_worldPt = Vec2(x = 1.0, y = 1.0)
  let edge_worldPt = Vec2(x = 0.5, y = 0.5)
  let resNom = worldToScreen2D(arg_cam, arg_worldPt)
  let resEdge = worldToScreen2D(edge_cam, edge_worldPt)
  assertApproxEq(resNom.x, 1.0, 0.001, "worldToScreen2D nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "worldToScreen2D boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `screenToWorld2D` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn screenToWorld2D(cam: Camera2D, screenPt: Vec2): Vec2:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera2D, screenPt: Vec2` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `screenToWorld2D` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `cam: Camera2D = Camera2D(center = Vec2 = Vec2(x = 0.0, y = 0.0)(), zoom = float = 1.0(), rotationRad = float = 0.0(), viewportWidth = float = 800.0(), viewportHeight = float = 600.0(), trauma = float = 0.0(), x = float = 0.0(), y = float = 0.0(), targetX = float = 0.0(), targetY = float = 0.0(), rotation = float = 0.0(), shakeOffsetX = float = 0.0(), shakeOffsetY = float = 0.0(), viewportW = float = 800.0(), viewportH = float = 600.0())`, `screenPt: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `Vec2(x = wx, y = wy)`.

```aipl
module tests.functions.gfx2d.camera2d_z10_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_screenToWorld2D_10(): int:
  let arg_cam = Camera2D(center = Vec2(x = 1.0, y = 1.0), zoom = 1.0, rotationRad = 1.0, viewportWidth = 2.0, viewportHeight = 2.0, trauma = 1.0, x = 1.0, y = 1.0, targetX = 1.0, targetY = 1.0, rotation = 1.0, shakeOffsetX = 2.0, shakeOffsetY = 2.0, viewportW = 2.0, viewportH = 2.0)
  let edge_cam = Camera2D(center = Vec2(x = 0.5, y = 0.5), zoom = 0.5, rotationRad = 0.5, viewportWidth = 1.0, viewportHeight = 1.0, trauma = 0.5, x = 0.5, y = 0.5, targetX = 0.5, targetY = 0.5, rotation = 0.5, shakeOffsetX = 1.0, shakeOffsetY = 1.0, viewportW = 1.0, viewportH = 1.0)
  let arg_screenPt = Vec2(x = 1.0, y = 1.0)
  let edge_screenPt = Vec2(x = 0.5, y = 0.5)
  let resNom = screenToWorld2D(arg_cam, arg_screenPt)
  let resEdge = screenToWorld2D(edge_cam, edge_screenPt)
  assertApproxEq(resNom.x, 1.0, 0.001, "screenToWorld2D nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "screenToWorld2D boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `getCameraVisibleBounds` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn getCameraVisibleBounds(cam: Camera2D): ViewportBounds2D:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera2D` | **Returns**: `ViewportBounds2D`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `getCameraVisibleBounds` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `cam: Camera2D = Camera2D(center = Vec2 = Vec2(x = 0.0, y = 0.0)(), zoom = float = 1.0(), rotationRad = float = 0.0(), viewportWidth = float = 800.0(), viewportHeight = float = 600.0(), trauma = float = 0.0(), x = float = 0.0(), y = float = 0.0(), targetX = float = 0.0(), targetY = float = 0.0(), rotation = float = 0.0(), shakeOffsetX = float = 0.0(), shakeOffsetY = float = 0.0(), viewportW = float = 800.0(), viewportH = float = 600.0())`; exercises core body path returning/computing `ViewportBounds2D(`.

```aipl
module tests.functions.gfx2d.camera2d_z11_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_getCameraVisibleBounds_11(): int:
  let arg_cam = Camera2D(center = Vec2(x = 1.0, y = 1.0), zoom = 1.0, rotationRad = 1.0, viewportWidth = 2.0, viewportHeight = 2.0, trauma = 1.0, x = 1.0, y = 1.0, targetX = 1.0, targetY = 1.0, rotation = 1.0, shakeOffsetX = 2.0, shakeOffsetY = 2.0, viewportW = 2.0, viewportH = 2.0)
  let edge_cam = Camera2D(center = Vec2(x = 0.5, y = 0.5), zoom = 0.5, rotationRad = 0.5, viewportWidth = 1.0, viewportHeight = 1.0, trauma = 0.5, x = 0.5, y = 0.5, targetX = 0.5, targetY = 0.5, rotation = 0.5, shakeOffsetX = 1.0, shakeOffsetY = 1.0, viewportW = 1.0, viewportH = 1.0)
  let resNom = getCameraVisibleBounds(arg_cam)
  let resEdge = getCameraVisibleBounds(edge_cam)
  assertApproxEq(resNom.minX, 0.0, 0.001, "getCameraVisibleBounds nominal resNom.minX ~= 0.0")
  assertApproxEq(resEdge.minX, -0.5, 0.001, "getCameraVisibleBounds boundary resEdge.minX ~= -0.5")
  ret 0
```

---

### `camera2DSmoothFollow` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn camera2DSmoothFollow(cam: Camera2D, targetX: float, targetY: float, stiffness: float, dt: float): Camera2D:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera2D, targetX: float, targetY: float, stiffness: float, dt: float` | **Returns**: `Camera2D`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `camera2DSmoothFollow` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `cam: Camera2D = Camera2D(center = Vec2 = Vec2(x = 0.0, y = 0.0)(), zoom = float = 1.0(), rotationRad = float = 0.0(), viewportWidth = float = 800.0(), viewportHeight = float = 600.0(), trauma = float = 0.0(), x = float = 0.0(), y = float = 0.0(), targetX = float = 0.0(), targetY = float = 0.0(), rotation = float = 0.0(), shakeOffsetX = float = 0.0(), shakeOffsetY = float = 0.0(), viewportW = float = 800.0(), viewportH = float = 600.0())`, `targetX: float = 1.0`, `targetY: float = 1.0`, `stiffness: float = 1.0`, `dt: float = 0.016667`; exercises core body path returning/computing `Camera2D(`.

```aipl
module tests.functions.gfx2d.camera2d_z12_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_camera2DSmoothFollow_12(): int:
  let arg_cam = Camera2D(center = Vec2(x = 1.0, y = 1.0), zoom = 1.0, rotationRad = 1.0, viewportWidth = 2.0, viewportHeight = 2.0, trauma = 1.0, x = 1.0, y = 1.0, targetX = 1.0, targetY = 1.0, rotation = 1.0, shakeOffsetX = 2.0, shakeOffsetY = 2.0, viewportW = 2.0, viewportH = 2.0)
  let edge_cam = Camera2D(center = Vec2(x = 0.5, y = 0.5), zoom = 0.5, rotationRad = 0.5, viewportWidth = 1.0, viewportHeight = 1.0, trauma = 0.5, x = 0.5, y = 0.5, targetX = 0.5, targetY = 0.5, rotation = 0.5, shakeOffsetX = 1.0, shakeOffsetY = 1.0, viewportW = 1.0, viewportH = 1.0)
  let arg_targetX = 1.0
  let edge_targetX = 0.5
  let arg_targetY = 1.0
  let edge_targetY = 0.5
  let arg_stiffness = 1.0
  let edge_stiffness = 0.5
  let arg_dt = 2.0
  let edge_dt = 1.0
  let resNom = camera2DSmoothFollow(arg_cam, arg_targetX, arg_targetY, arg_stiffness, arg_dt)
  let resEdge = camera2DSmoothFollow(edge_cam, edge_targetX, edge_targetY, edge_stiffness, edge_dt)
  assertApproxEq(resNom.zoom, 1.0, 0.001, "camera2DSmoothFollow nominal resNom.zoom ~= 1.0")
  assertApproxEq(resEdge.zoom, 0.5, 0.001, "camera2DSmoothFollow boundary resEdge.zoom ~= 0.5")
  ret 0
```

---

### `camera2DFollow` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn camera2DFollow(cam: Camera2D, targetX: float, targetY: float, smoothSpeed: float, dt: float, frameSeed: int): Camera2D:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera2D, targetX: float, targetY: float, smoothSpeed: float, dt: float, frameSeed: int` | **Returns**: `Camera2D`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `camera2DFollow` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `cam: Camera2D = Camera2D(center = Vec2 = Vec2(x = 0.0, y = 0.0)(), zoom = float = 1.0(), rotationRad = float = 0.0(), viewportWidth = float = 800.0(), viewportHeight = float = 600.0(), trauma = float = 0.0(), x = float = 0.0(), y = float = 0.0(), targetX = float = 0.0(), targetY = float = 0.0(), rotation = float = 0.0(), shakeOffsetX = float = 0.0(), shakeOffsetY = float = 0.0(), viewportW = float = 800.0(), viewportH = float = 600.0())`, `targetX: float = 1.0`, `targetY: float = 1.0`, `smoothSpeed: float = 1.0`, `dt: float = 0.016667`, `frameSeed: int = 64`; exercises core body path returning/computing `Camera2D(`.

```aipl
module tests.functions.gfx2d.camera2d_z13_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_camera2DFollow_13(): int:
  let arg_cam = Camera2D(center = Vec2(x = 1.0, y = 1.0), zoom = 1.0, rotationRad = 1.0, viewportWidth = 2.0, viewportHeight = 2.0, trauma = 1.0, x = 1.0, y = 1.0, targetX = 1.0, targetY = 1.0, rotation = 1.0, shakeOffsetX = 2.0, shakeOffsetY = 2.0, viewportW = 2.0, viewportH = 2.0)
  let edge_cam = Camera2D(center = Vec2(x = 0.5, y = 0.5), zoom = 0.5, rotationRad = 0.5, viewportWidth = 1.0, viewportHeight = 1.0, trauma = 0.5, x = 0.5, y = 0.5, targetX = 0.5, targetY = 0.5, rotation = 0.5, shakeOffsetX = 1.0, shakeOffsetY = 1.0, viewportW = 1.0, viewportH = 1.0)
  let arg_targetX = 1.0
  let edge_targetX = 0.5
  let arg_targetY = 1.0
  let edge_targetY = 0.5
  let arg_smoothSpeed = 2.0
  let edge_smoothSpeed = 1.0
  let arg_dt = 2.0
  let edge_dt = 1.0
  let arg_frameSeed = 4
  let edge_frameSeed = 1
  let resNom = camera2DFollow(arg_cam, arg_targetX, arg_targetY, arg_smoothSpeed, arg_dt, arg_frameSeed)
  let resEdge = camera2DFollow(edge_cam, edge_targetX, edge_targetY, edge_smoothSpeed, edge_dt, edge_frameSeed)
  assertApproxEq(resNom.zoom, 1.0, 0.001, "camera2DFollow nominal resNom.zoom ~= 1.0")
  assertApproxEq(resEdge.zoom, 0.5, 0.001, "camera2DFollow boundary resEdge.zoom ~= 0.5")
  ret 0
```

---

### `camera2DFollowExact` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn camera2DFollowExact(cam: Camera2D, targetX: float, targetY: float, smoothSpeed: float, dt: float, frameSeed: int): Camera2D:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera2D, targetX: float, targetY: float, smoothSpeed: float, dt: float, frameSeed: int` | **Returns**: `Camera2D`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `camera2DFollowExact` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `cam: Camera2D = Camera2D(center = Vec2 = Vec2(x = 0.0, y = 0.0)(), zoom = float = 1.0(), rotationRad = float = 0.0(), viewportWidth = float = 800.0(), viewportHeight = float = 600.0(), trauma = float = 0.0(), x = float = 0.0(), y = float = 0.0(), targetX = float = 0.0(), targetY = float = 0.0(), rotation = float = 0.0(), shakeOffsetX = float = 0.0(), shakeOffsetY = float = 0.0(), viewportW = float = 800.0(), viewportH = float = 600.0())`, `targetX: float = 1.0`, `targetY: float = 1.0`, `smoothSpeed: float = 1.0`, `dt: float = 0.016667`, `frameSeed: int = 64`; exercises core body path returning/computing `camera2DFollow(cam, targetX, targetY, smoothSpeed, dt, frameSeed)`.

```aipl
module tests.functions.gfx2d.camera2d_z14_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_camera2DFollowExact_14(): int:
  let arg_cam = Camera2D(center = Vec2(x = 1.0, y = 1.0), zoom = 1.0, rotationRad = 1.0, viewportWidth = 2.0, viewportHeight = 2.0, trauma = 1.0, x = 1.0, y = 1.0, targetX = 1.0, targetY = 1.0, rotation = 1.0, shakeOffsetX = 2.0, shakeOffsetY = 2.0, viewportW = 2.0, viewportH = 2.0)
  let edge_cam = Camera2D(center = Vec2(x = 0.5, y = 0.5), zoom = 0.5, rotationRad = 0.5, viewportWidth = 1.0, viewportHeight = 1.0, trauma = 0.5, x = 0.5, y = 0.5, targetX = 0.5, targetY = 0.5, rotation = 0.5, shakeOffsetX = 1.0, shakeOffsetY = 1.0, viewportW = 1.0, viewportH = 1.0)
  let arg_targetX = 1.0
  let edge_targetX = 0.5
  let arg_targetY = 1.0
  let edge_targetY = 0.5
  let arg_smoothSpeed = 2.0
  let edge_smoothSpeed = 1.0
  let arg_dt = 2.0
  let edge_dt = 1.0
  let arg_frameSeed = 4
  let edge_frameSeed = 1
  let resNom = camera2DFollowExact(arg_cam, arg_targetX, arg_targetY, arg_smoothSpeed, arg_dt, arg_frameSeed)
  let resEdge = camera2DFollowExact(edge_cam, edge_targetX, edge_targetY, edge_smoothSpeed, edge_dt, edge_frameSeed)
  assertApproxEq(resNom.zoom, 1.0, 0.001, "camera2DFollowExact nominal resNom.zoom ~= 1.0")
  assertApproxEq(resEdge.zoom, 0.5, 0.001, "camera2DFollowExact boundary resEdge.zoom ~= 0.5")
  ret 0
```

---

### `camera2DWorldToScreenX` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn camera2DWorldToScreenX(cam: Camera2D, wx: float): float:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera2D, wx: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `camera2DWorldToScreenX` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `cam: Camera2D = Camera2D(center = Vec2 = Vec2(x = 0.0, y = 0.0)(), zoom = float = 1.0(), rotationRad = float = 0.0(), viewportWidth = float = 800.0(), viewportHeight = float = 600.0(), trauma = float = 0.0(), x = float = 0.0(), y = float = 0.0(), targetX = float = 0.0(), targetY = float = 0.0(), rotation = float = 0.0(), shakeOffsetX = float = 0.0(), shakeOffsetY = float = 0.0(), viewportW = float = 800.0(), viewportH = float = 600.0())`, `wx: float = 1.0`; exercises core body path returning/computing `(wx - (cam.x + cam.shakeOffsetX)) * cam.zoom + centerX`.

```aipl
module tests.functions.gfx2d.camera2d_z15_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_camera2DWorldToScreenX_15(): int:
  let arg_cam = Camera2D(center = Vec2(x = 1.0, y = 1.0), zoom = 1.0, rotationRad = 1.0, viewportWidth = 2.0, viewportHeight = 2.0, trauma = 1.0, x = 1.0, y = 1.0, targetX = 1.0, targetY = 1.0, rotation = 1.0, shakeOffsetX = 2.0, shakeOffsetY = 2.0, viewportW = 2.0, viewportH = 2.0)
  let edge_cam = Camera2D(center = Vec2(x = 0.5, y = 0.5), zoom = 0.5, rotationRad = 0.5, viewportWidth = 1.0, viewportHeight = 1.0, trauma = 0.5, x = 0.5, y = 0.5, targetX = 0.5, targetY = 0.5, rotation = 0.5, shakeOffsetX = 1.0, shakeOffsetY = 1.0, viewportW = 1.0, viewportH = 1.0)
  let arg_wx = 2.0
  let edge_wx = 1.0
  let resNom = camera2DWorldToScreenX(arg_cam, arg_wx)
  let resEdge = camera2DWorldToScreenX(edge_cam, edge_wx)
  assertApproxEq(resNom, 0.0, 0.001, "camera2DWorldToScreenX nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.25, 0.001, "camera2DWorldToScreenX boundary resEdge ~= 0.25")
  ret 0
```

---

### `camera2DWorldToScreenY` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn camera2DWorldToScreenY(cam: Camera2D, wy: float): float:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera2D, wy: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `camera2DWorldToScreenY` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `cam: Camera2D = Camera2D(center = Vec2 = Vec2(x = 0.0, y = 0.0)(), zoom = float = 1.0(), rotationRad = float = 0.0(), viewportWidth = float = 800.0(), viewportHeight = float = 600.0(), trauma = float = 0.0(), x = float = 0.0(), y = float = 0.0(), targetX = float = 0.0(), targetY = float = 0.0(), rotation = float = 0.0(), shakeOffsetX = float = 0.0(), shakeOffsetY = float = 0.0(), viewportW = float = 800.0(), viewportH = float = 600.0())`, `wy: float = 1.0`; exercises core body path returning/computing `(wy - (cam.y + cam.shakeOffsetY)) * cam.zoom + centerY`.

```aipl
module tests.functions.gfx2d.camera2d_z16_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_camera2DWorldToScreenY_16(): int:
  let arg_cam = Camera2D(center = Vec2(x = 1.0, y = 1.0), zoom = 1.0, rotationRad = 1.0, viewportWidth = 2.0, viewportHeight = 2.0, trauma = 1.0, x = 1.0, y = 1.0, targetX = 1.0, targetY = 1.0, rotation = 1.0, shakeOffsetX = 2.0, shakeOffsetY = 2.0, viewportW = 2.0, viewportH = 2.0)
  let edge_cam = Camera2D(center = Vec2(x = 0.5, y = 0.5), zoom = 0.5, rotationRad = 0.5, viewportWidth = 1.0, viewportHeight = 1.0, trauma = 0.5, x = 0.5, y = 0.5, targetX = 0.5, targetY = 0.5, rotation = 0.5, shakeOffsetX = 1.0, shakeOffsetY = 1.0, viewportW = 1.0, viewportH = 1.0)
  let arg_wy = 2.0
  let edge_wy = 1.0
  let resNom = camera2DWorldToScreenY(arg_cam, arg_wy)
  let resEdge = camera2DWorldToScreenY(edge_cam, edge_wy)
  assertApproxEq(resNom, 0.0, 0.001, "camera2DWorldToScreenY nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.25, 0.001, "camera2DWorldToScreenY boundary resEdge ~= 0.25")
  ret 0
```

---

### `beginCamera2D` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn beginCamera2D(cam: Camera2D):`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `beginCamera2D` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `cam: Camera2D = Camera2D(center = Vec2 = Vec2(x = 0.0, y = 0.0)(), zoom = float = 1.0(), rotationRad = float = 0.0(), viewportWidth = float = 800.0(), viewportHeight = float = 600.0(), trauma = float = 0.0(), x = float = 0.0(), y = float = 0.0(), targetX = float = 0.0(), targetY = float = 0.0(), rotation = float = 0.0(), shakeOffsetX = float = 0.0(), shakeOffsetY = float = 0.0(), viewportW = float = 800.0(), viewportH = float = 600.0())`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.camera2d_z17_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_beginCamera2D_17(): int:
  mut completedCalls = 0
  let arg_cam = Camera2D(center = Vec2(x = 1.0, y = 1.0), zoom = 1.0, rotationRad = 1.0, viewportWidth = 2.0, viewportHeight = 2.0, trauma = 1.0, x = 1.0, y = 1.0, targetX = 1.0, targetY = 1.0, rotation = 1.0, shakeOffsetX = 2.0, shakeOffsetY = 2.0, viewportW = 2.0, viewportH = 2.0)
  let edge_cam = Camera2D(center = Vec2(x = 0.5, y = 0.5), zoom = 0.5, rotationRad = 0.5, viewportWidth = 1.0, viewportHeight = 1.0, trauma = 0.5, x = 0.5, y = 0.5, targetX = 0.5, targetY = 0.5, rotation = 0.5, shakeOffsetX = 1.0, shakeOffsetY = 1.0, viewportW = 1.0, viewportH = 1.0)
  beginCamera2D(arg_cam)
  beginCamera2D(edge_cam)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "beginCamera2D nominal and boundary void calls completed")
  ret 0
```

---

### `endCamera2D` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn endCamera2D():`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `endCamera2D` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.camera2d_z18_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_endCamera2D_18(): int:
  mut completedCalls = 0
  endCamera2D()
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "endCamera2D nominal and boundary void calls completed")
  ret 0
```

---

### `camEnvStr` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `fn camEnvStr(key: str, fallback: str): str:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `key: str, fallback: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `camEnvStr` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `key: str = "aipl_test"`, `fallback: str = "aipl_test"`; exercises core body path returning/computing `fallback`.

```aipl
module tests.functions.gfx2d.camera2d_z19_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_camEnvStr_19(): int:
  let arg_key = "test"
  let edge_key = "a"
  let arg_fallback = "test"
  let edge_fallback = "a"
  let resNom = camEnvStr(arg_key, arg_fallback)
  let resEdge = camEnvStr(edge_key, edge_fallback)
  assertEqStr(resNom, "test", "camEnvStr nominal string matches")
  assertEqStr(resEdge, "a", "camEnvStr boundary string matches")
  ret 0
```

---

### `beginMode2D` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn beginMode2D(cam: Camera2D): void:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera2D` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `beginMode2D` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `cam: Camera2D = Camera2D(center = Vec2 = Vec2(x = 0.0, y = 0.0)(), zoom = float = 1.0(), rotationRad = float = 0.0(), viewportWidth = float = 800.0(), viewportHeight = float = 600.0(), trauma = float = 0.0(), x = float = 0.0(), y = float = 0.0(), targetX = float = 0.0(), targetY = float = 0.0(), rotation = float = 0.0(), shakeOffsetX = float = 0.0(), shakeOffsetY = float = 0.0(), viewportW = float = 800.0(), viewportH = float = 600.0())`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.camera2d_z20_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_beginMode2D_20(): int:
  mut completedCalls = 0
  let arg_cam = Camera2D(center = Vec2(x = 1.0, y = 1.0), zoom = 1.0, rotationRad = 1.0, viewportWidth = 2.0, viewportHeight = 2.0, trauma = 1.0, x = 1.0, y = 1.0, targetX = 1.0, targetY = 1.0, rotation = 1.0, shakeOffsetX = 2.0, shakeOffsetY = 2.0, viewportW = 2.0, viewportH = 2.0)
  let edge_cam = Camera2D(center = Vec2(x = 0.5, y = 0.5), zoom = 0.5, rotationRad = 0.5, viewportWidth = 1.0, viewportHeight = 1.0, trauma = 0.5, x = 0.5, y = 0.5, targetX = 0.5, targetY = 0.5, rotation = 0.5, shakeOffsetX = 1.0, shakeOffsetY = 1.0, viewportW = 1.0, viewportH = 1.0)
  beginMode2D(arg_cam)
  beginMode2D(edge_cam)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "beginMode2D nominal and boundary void calls completed")
  ret 0
```

---

### `endMode2D` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn endMode2D(): void:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `endMode2D` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.camera2d_z21_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_endMode2D_21(): int:
  mut completedCalls = 0
  endMode2D()
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "endMode2D nominal and boundary void calls completed")
  ret 0
```

---

### `isMode2DActive` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn isMode2DActive(): bool:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `isMode2DActive` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `camEnvStr("__AIPL_MODE2D_ACTIVE", "0") == "1"`.

```aipl
module tests.functions.gfx2d.camera2d_z22_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_isMode2DActive_22(): int:
  let resNom = isMode2DActive()
  let resEdge = isMode2DActive()
  assert(resNom == false, "isMode2DActive nominal resNom == false")
  assert(resEdge == false, "isMode2DActive boundary resEdge == false")
  ret 0
```

---

### `activeCamera2D` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn activeCamera2D(): Camera2D:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Camera2D`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `activeCamera2D` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Camera2D(`.

```aipl
module tests.functions.gfx2d.camera2d_z23_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_activeCamera2D_23(): int:
  let resNom = activeCamera2D()
  let resEdge = activeCamera2D()
  assertApproxEq(resNom.zoom, 0.5, 0.001, "activeCamera2D nominal resNom.zoom ~= 0.5")
  assertApproxEq(resEdge.zoom, 0.5, 0.001, "activeCamera2D boundary resEdge.zoom ~= 0.5")
  ret 0
```

---

### `aabbOverlap` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn aabbOverlap(x1: float, y1: float, w1: float, h1: float, x2: float, y2: float, w2: float, h2: float): bool:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x1: float, y1: float, w1: float, h1: float, x2: float, y2: float, w2: float, h2: float` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `aabbOverlap` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `x1: float = 1.0`, `y1: float = 1.0`, `w1: float = 1.0`, `h1: float = 1.0`, `x2: float = 1.0`, `y2: float = 1.0`, `w2: float = 1.0`, `h2: float = 1.0`; exercises core body path returning/computing `x1 < x2 + w2 and x1 + w1 > x2 and y1 < y2 + h2 and y1 + h1 > y2`.

```aipl
module tests.functions.gfx2d.camera2d_z24_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_aabbOverlap_24(): int:
  let arg_x1 = 1.0
  let edge_x1 = 0.5
  let arg_y1 = 1.0
  let edge_y1 = 0.5
  let arg_w1 = 2.0
  let edge_w1 = 1.0
  let arg_h1 = 2.0
  let edge_h1 = 1.0
  let arg_x2 = 1.0
  let edge_x2 = 0.5
  let arg_y2 = 1.0
  let edge_y2 = 0.5
  let arg_w2 = 2.0
  let edge_w2 = 1.0
  let arg_h2 = 2.0
  let edge_h2 = 1.0
  let resNom = aabbOverlap(arg_x1, arg_y1, arg_w1, arg_h1, arg_x2, arg_y2, arg_w2, arg_h2)
  let resEdge = aabbOverlap(edge_x1, edge_y1, edge_w1, edge_h1, edge_x2, edge_y2, edge_w2, edge_h2)
  assert(resNom == true, "aabbOverlap nominal resNom == true")
  assert(resEdge == true, "aabbOverlap boundary resEdge == true")
  ret 0
```

---

### `circleOverlap` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn circleOverlap(x1: float, y1: float, r1: float, x2: float, y2: float, r2: float): bool:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x1: float, y1: float, r1: float, x2: float, y2: float, r2: float` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `circleOverlap` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `x1: float = 1.0`, `y1: float = 1.0`, `r1: float = 1.0`, `x2: float = 1.0`, `y2: float = 1.0`, `r2: float = 1.0`; exercises core body path returning/computing `(dx * dx + dy * dy) <= (rSum * rSum)`.

```aipl
module tests.functions.gfx2d.camera2d_z25_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_circleOverlap_25(): int:
  let arg_x1 = 1.0
  let edge_x1 = 0.5
  let arg_y1 = 1.0
  let edge_y1 = 0.5
  let arg_r1 = 1.0
  let edge_r1 = 0.5
  let arg_x2 = 1.0
  let edge_x2 = 0.5
  let arg_y2 = 1.0
  let edge_y2 = 0.5
  let arg_r2 = 1.0
  let edge_r2 = 0.5
  let resNom = circleOverlap(arg_x1, arg_y1, arg_r1, arg_x2, arg_y2, arg_r2)
  let resEdge = circleOverlap(edge_x1, edge_y1, edge_r1, edge_x2, edge_y2, edge_r2)
  assert(resNom == true, "circleOverlap nominal resNom == true")
  assert(resEdge == true, "circleOverlap boundary resEdge == true")
  ret 0
```

---

### `circleRectOverlap` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn circleRectOverlap(cx: float, cy: float, r: float, rx: float, ry: float, rw: float, rh: float): bool:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cx: float, cy: float, r: float, rx: float, ry: float, rw: float, rh: float` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `circleRectOverlap` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `cx: float = 1.0`, `cy: float = 1.0`, `r: float = 1.0`, `rx: float = 1.0`, `ry: float = 1.0`, `rw: float = 1.0`, `rh: float = 1.0`; exercises core body path returning/computing `(dx * dx + dy * dy) <= (r * r)`.

```aipl
module tests.functions.gfx2d.camera2d_z26_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_circleRectOverlap_26(): int:
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_cy = 1.0
  let edge_cy = 0.5
  let arg_r = 1.0
  let edge_r = 0.5
  let arg_rx = 1.0
  let edge_rx = 0.5
  let arg_ry = 1.0
  let edge_ry = 0.5
  let arg_rw = 2.0
  let edge_rw = 1.0
  let arg_rh = 2.0
  let edge_rh = 1.0
  let resNom = circleRectOverlap(arg_cx, arg_cy, arg_r, arg_rx, arg_ry, arg_rw, arg_rh)
  let resEdge = circleRectOverlap(edge_cx, edge_cy, edge_r, edge_rx, edge_ry, edge_rw, edge_rh)
  assert(resNom == true, "circleRectOverlap nominal resNom == true")
  assert(resEdge == true, "circleRectOverlap boundary resEdge == true")
  ret 0
```

---

### `lineCircleOverlap` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn lineCircleOverlap(x1: float, y1: float, x2: float, y2: float, cx: float, cy: float, r: float): bool:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x1: float, y1: float, x2: float, y2: float, cx: float, cy: float, r: float` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `lineCircleOverlap` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `x1: float = 1.0`, `y1: float = 1.0`, `x2: float = 1.0`, `y2: float = 1.0`, `cx: float = 1.0`, `cy: float = 1.0`, `r: float = 1.0`; exercises core body path returning/computing `(dx * dx + dy * dy) <= (r * r)`.

```aipl
module tests.functions.gfx2d.camera2d_z27_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_lineCircleOverlap_27(): int:
  let arg_x1 = 1.0
  let edge_x1 = 0.5
  let arg_y1 = 1.0
  let edge_y1 = 0.5
  let arg_x2 = 1.0
  let edge_x2 = 0.5
  let arg_y2 = 1.0
  let edge_y2 = 0.5
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_cy = 1.0
  let edge_cy = 0.5
  let arg_r = 1.0
  let edge_r = 0.5
  let resNom = lineCircleOverlap(arg_x1, arg_y1, arg_x2, arg_y2, arg_cx, arg_cy, arg_r)
  let resEdge = lineCircleOverlap(edge_x1, edge_y1, edge_x2, edge_y2, edge_cx, edge_cy, edge_r)
  assert(resNom == true, "lineCircleOverlap nominal resNom == true")
  assert(resEdge == true, "lineCircleOverlap boundary resEdge == true")
  ret 0
```

---

### `aimDirectionX` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn aimDirectionX(fromX: float, fromY: float, toX: float, toY: float): float:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fromX: float, fromY: float, toX: float, toY: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `aimDirectionX` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `fromX: float = 1.0`, `fromY: float = 1.0`, `toX: float = 1.0`, `toY: float = 1.0`; exercises core body path returning/computing `dx / d`.

```aipl
module tests.functions.gfx2d.camera2d_z28_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_aimDirectionX_28(): int:
  let arg_fromX = 1.0
  let edge_fromX = 0.5
  let arg_fromY = 1.0
  let edge_fromY = 0.5
  let arg_toX = 1.0
  let edge_toX = 0.5
  let arg_toY = 1.0
  let edge_toY = 0.5
  let resNom = aimDirectionX(arg_fromX, arg_fromY, arg_toX, arg_toY)
  let resEdge = aimDirectionX(edge_fromX, edge_fromY, edge_toX, edge_toY)
  assertApproxEq(resNom, 1.0, 0.001, "aimDirectionX nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.0, 0.001, "aimDirectionX boundary resEdge ~= 1.0")
  ret 0
```

---

### `aimDirectionY` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn aimDirectionY(fromX: float, fromY: float, toX: float, toY: float): float:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fromX: float, fromY: float, toX: float, toY: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `aimDirectionY` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `fromX: float = 1.0`, `fromY: float = 1.0`, `toX: float = 1.0`, `toY: float = 1.0`; exercises core body path returning/computing `dy / d`.

```aipl
module tests.functions.gfx2d.camera2d_z29_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_aimDirectionY_29(): int:
  let arg_fromX = 1.0
  let edge_fromX = 0.5
  let arg_fromY = 1.0
  let edge_fromY = 0.5
  let arg_toX = 1.0
  let edge_toX = 0.5
  let arg_toY = 1.0
  let edge_toY = 0.5
  let resNom = aimDirectionY(arg_fromX, arg_fromY, arg_toX, arg_toY)
  let resEdge = aimDirectionY(edge_fromX, edge_fromY, edge_toX, edge_toY)
  assertApproxEq(resNom, 0.0, 0.001, "aimDirectionY nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "aimDirectionY boundary resEdge ~= 0.0")
  ret 0
```

---

### `stepTimer` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn stepTimer(timer: float, dt: float): float:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `timer: float, dt: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `stepTimer` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `timer: float = 1.0`, `dt: float = 0.016667`; exercises core body path returning/computing `timer - dt`.

```aipl
module tests.functions.gfx2d.camera2d_z30_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_stepTimer_30(): int:
  let arg_timer = 1.0
  let edge_timer = 0.5
  let arg_dt = 2.0
  let edge_dt = 1.0
  let resNom = stepTimer(arg_timer, arg_dt)
  let resEdge = stepTimer(edge_timer, edge_dt)
  assertApproxEq(resNom, 0.0, 0.001, "stepTimer nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "stepTimer boundary resEdge ~= 0.0")
  ret 0
```

---

### `isBlinkVisible` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn isBlinkVisible(timer: float, frequency: float): bool:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `timer: float, frequency: float` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `isBlinkVisible` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `timer: float = 1.0`, `frequency: float = 1.0`; exercises core body path returning/computing `(cycle % 2) == 0`.

```aipl
module tests.functions.gfx2d.camera2d_z31_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_isBlinkVisible_31(): int:
  let arg_timer = 1.0
  let edge_timer = 0.5
  let arg_frequency = 2.0
  let edge_frequency = 1.0
  let resNom = isBlinkVisible(arg_timer, arg_frequency)
  let resEdge = isBlinkVisible(edge_timer, edge_frequency)
  assert(resNom == true, "isBlinkVisible nominal resNom == true")
  assert(resEdge == false, "isBlinkVisible boundary resEdge == false")
  ret 0
```

---

### `drawHealthBar` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn drawHealthBar(x: float, y: float, w: float, h: float, currentHp: float, maxHp: float, fillColor: Color, bgColor: Color):`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawHealthBar` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`, `currentHp: float = 1.0`, `maxHp: float = 1.0`, `fillColor: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `bgColor: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.camera2d_z32_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_drawHealthBar_32(): int:
  mut completedCalls = 0
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let arg_currentHp = 2.0
  let edge_currentHp = 1.0
  let arg_maxHp = 2.0
  let edge_maxHp = 1.0
  let arg_fillColor = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_fillColor = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_bgColor = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_bgColor = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawHealthBar(arg_x, arg_y, arg_w, arg_h, arg_currentHp, arg_maxHp, arg_fillColor, arg_bgColor)
  drawHealthBar(edge_x, edge_y, edge_w, edge_h, edge_currentHp, edge_maxHp, edge_fillColor, edge_bgColor)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawHealthBar nominal and boundary void calls completed")
  ret 0
```

---

### `drawShieldBar` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn drawShieldBar(x: float, y: float, w: float, h: float, currentShield: float, maxShield: float, fillColor: Color, bgColor: Color):`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `drawShieldBar` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`, `currentShield: float = 1.0`, `maxShield: float = 1.0`, `fillColor: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `bgColor: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.camera2d_z33_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_drawShieldBar_33(): int:
  mut completedCalls = 0
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let arg_currentShield = 2.0
  let edge_currentShield = 1.0
  let arg_maxShield = 2.0
  let edge_maxShield = 1.0
  let arg_fillColor = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_fillColor = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_bgColor = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_bgColor = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawShieldBar(arg_x, arg_y, arg_w, arg_h, arg_currentShield, arg_maxShield, arg_fillColor, arg_bgColor)
  drawShieldBar(edge_x, edge_y, edge_w, edge_h, edge_currentShield, edge_maxShield, edge_fillColor, edge_bgColor)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawShieldBar nominal and boundary void calls completed")
  ret 0
```

---

### `drawBossHealthBar` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn drawBossHealthBar(title: str, x: float, y: float, w: float, h: float, currentHp: float, maxHp: float, fillColor: Color):`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `drawBossHealthBar` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `title: str = "aipl_test"`, `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`, `currentHp: float = 1.0`, `maxHp: float = 1.0`, `fillColor: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.camera2d_z34_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_drawBossHealthBar_34(): int:
  mut completedCalls = 0
  let arg_title = "test"
  let edge_title = "a"
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let arg_currentHp = 2.0
  let edge_currentHp = 1.0
  let arg_maxHp = 2.0
  let edge_maxHp = 1.0
  let arg_fillColor = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_fillColor = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawBossHealthBar(arg_title, arg_x, arg_y, arg_w, arg_h, arg_currentHp, arg_maxHp, arg_fillColor)
  drawBossHealthBar(edge_title, edge_x, edge_y, edge_w, edge_h, edge_currentHp, edge_maxHp, edge_fillColor)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawBossHealthBar nominal and boundary void calls completed")
  ret 0
```

---

### `drawScoreCounter` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn drawScoreCounter(label: str, score: int, digits: int, x: float, y: float, size: float, color: Color):`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawScoreCounter` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `label: str = "aipl_test"`, `score: int = 1`, `digits: int = 1`, `x: float = 1.0`, `y: float = 1.0`, `size: float = 1.0`, `color: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.camera2d_z35_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_drawScoreCounter_35(): int:
  mut completedCalls = 0
  let arg_label = "test"
  let edge_label = "a"
  let arg_score = 2
  let edge_score = 0
  let arg_digits = 2
  let edge_digits = 0
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_size = 1.0
  let edge_size = 0.5
  let arg_color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawScoreCounter(arg_label, arg_score, arg_digits, arg_x, arg_y, arg_size, arg_color)
  drawScoreCounter(edge_label, edge_score, edge_digits, edge_x, edge_y, edge_size, edge_color)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawScoreCounter nominal and boundary void calls completed")
  ret 0
```

---

### `drawStarfield` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn drawStarfield(time: float, width: float, height: float, count: int, speed: float):`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `drawStarfield` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `time: float = 1.0`, `width: float = 0.016667`, `height: float = 1.0`, `count: int = 64`, `speed: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.camera2d_z36_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_drawStarfield_36(): int:
  mut completedCalls = 0
  let arg_time = 1.0
  let edge_time = 0.5
  let arg_width = 2.0
  let edge_width = 1.0
  let arg_height = 2.0
  let edge_height = 1.0
  let arg_count = 4
  let edge_count = 1
  let arg_speed = 1.0
  let edge_speed = 0.5
  drawStarfield(arg_time, arg_width, arg_height, arg_count, arg_speed)
  drawStarfield(edge_time, edge_width, edge_height, edge_count, edge_speed)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawStarfield nominal and boundary void calls completed")
  ret 0
```

---

### `spriteAnimatorNew` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn spriteAnimatorNew(initialClip: str): SpriteAnimator:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `initialClip: str` | **Returns**: `SpriteAnimator`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `spriteAnimatorNew` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `initialClip: str = "127.0.0.1"`; exercises core body path returning/computing `SpriteAnimator(`.

```aipl
module tests.functions.gfx2d.camera2d_z37_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_spriteAnimatorNew_37(): int:
  let arg_initialClip = "[s]\nk=v"
  let edge_initialClip = "[s]\nk=v"
  let resNom = spriteAnimatorNew(arg_initialClip)
  let resEdge = spriteAnimatorNew(edge_initialClip)
  assertEqInt(resNom.currentClip.len(), 7, "spriteAnimatorNew nominal string length == 7")
  assertEqInt(resEdge.currentClip.len(), 7, "spriteAnimatorNew boundary string length == 7")
  ret 0
```

---

### `spriteAnimatorUpdate` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn spriteAnimatorUpdate(anim: SpriteAnimator, clip: SpriteClip, dt: float): SpriteAnimator:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `anim: SpriteAnimator, clip: SpriteClip, dt: float` | **Returns**: `SpriteAnimator`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `spriteAnimatorUpdate` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `anim: SpriteAnimator = SpriteAnimator(currentClip = "127.0.0.1", frameIndex = 0, timer = 1.0, playing = true, flipX = true)`, `clip: SpriteClip = SpriteClip(name = "aipl_test", startFrame = 1, frameCount = 64, fps = 1.0, looping = true)`, `dt: float = 0.016667`; exercises core body path returning/computing `SpriteAnimator(`.

```aipl
module tests.functions.gfx2d.camera2d_z38_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_spriteAnimatorUpdate_38(): int:
  let arg_anim = SpriteAnimator(currentClip = "test", frameIndex = 4, timer = 1.0, playing = true, flipX = true)
  let edge_anim = SpriteAnimator(currentClip = "a", frameIndex = 1, timer = 0.5, playing = false, flipX = false)
  let arg_clip = SpriteClip(name = "test", startFrame = 4, frameCount = 4, fps = 1.0, looping = true)
  let edge_clip = SpriteClip(name = "a", startFrame = 1, frameCount = 1, fps = 0.5, looping = false)
  let arg_dt = 2.0
  let edge_dt = 1.0
  let resNom = spriteAnimatorUpdate(arg_anim, arg_clip, arg_dt)
  let resEdge = spriteAnimatorUpdate(edge_anim, edge_clip, edge_dt)
  assertEqStr(resNom.currentClip, "test", "spriteAnimatorUpdate nominal string matches")
  assertEqStr(resEdge.currentClip, "a", "spriteAnimatorUpdate boundary string matches")
  ret 0
```

---

### `platformerFeelNew` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn platformerFeelNew(): PlatformerFeel:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `PlatformerFeel`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `platformerFeelNew` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `PlatformerFeel(`.

```aipl
module tests.functions.gfx2d.camera2d_z39_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_platformerFeelNew_39(): int:
  let resNom = platformerFeelNew()
  let resEdge = platformerFeelNew()
  assertApproxEq(resNom.coyoteTimer, 0.0, 0.001, "platformerFeelNew nominal resNom.coyoteTimer ~= 0.0")
  assertApproxEq(resEdge.coyoteTimer, 0.0, 0.001, "platformerFeelNew boundary resEdge.coyoteTimer ~= 0.0")
  ret 0
```

---

### `triggerHitStop` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn triggerHitStop(feel: PlatformerFeel, durationSec: float): PlatformerFeel:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `feel: PlatformerFeel, durationSec: float` | **Returns**: `PlatformerFeel`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `triggerHitStop` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `feel: PlatformerFeel = PlatformerFeel(coyoteTimer = 1.0, jumpBufferTimer = 1.0, hitStopTimer = 1.0, timeScale = 1.0)`, `durationSec: float = 0.5`; exercises core body path returning/computing `PlatformerFeel(`.

```aipl
module tests.functions.gfx2d.camera2d_z40_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_triggerHitStop_40(): int:
  let arg_feel = PlatformerFeel(coyoteTimer = 1.0, jumpBufferTimer = 1.0, hitStopTimer = 2.0, timeScale = 2.0)
  let edge_feel = PlatformerFeel(coyoteTimer = 0.5, jumpBufferTimer = 0.5, hitStopTimer = 1.0, timeScale = 1.0)
  let arg_durationSec = 1.0
  let edge_durationSec = 0.5
  let resNom = triggerHitStop(arg_feel, arg_durationSec)
  let resEdge = triggerHitStop(edge_feel, edge_durationSec)
  assertApproxEq(resNom.coyoteTimer, 1.0, 0.001, "triggerHitStop nominal resNom.coyoteTimer ~= 1.0")
  assertApproxEq(resEdge.coyoteTimer, 0.5, 0.001, "triggerHitStop boundary resEdge.coyoteTimer ~= 0.5")
  ret 0
```

---

### `canExecuteJump` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn canExecuteJump(feel: PlatformerFeel): bool:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `feel: PlatformerFeel` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `canExecuteJump` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `feel: PlatformerFeel = PlatformerFeel(coyoteTimer = 1.0, jumpBufferTimer = 1.0, hitStopTimer = 1.0, timeScale = 1.0)`; exercises core body path returning/computing `feel.coyoteTimer > 0.0 and feel.jumpBufferTimer > 0.0`.

```aipl
module tests.functions.gfx2d.camera2d_z41_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_canExecuteJump_41(): int:
  let arg_feel = PlatformerFeel(coyoteTimer = 1.0, jumpBufferTimer = 1.0, hitStopTimer = 2.0, timeScale = 2.0)
  let edge_feel = PlatformerFeel(coyoteTimer = 0.5, jumpBufferTimer = 0.5, hitStopTimer = 1.0, timeScale = 1.0)
  let resNom = canExecuteJump(arg_feel)
  let resEdge = canExecuteJump(edge_feel)
  assert(resNom == true, "canExecuteJump nominal resNom == true")
  assert(resEdge == true, "canExecuteJump boundary resEdge == true")
  ret 0
```

---

### `platformerFeelStep` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn platformerFeelStep(feel: PlatformerFeel, dt: float, isGrounded: bool, jumpPressed: bool, coyoteDuration: float = 0.15, bufferDuration: float = 0.15): PlatformerFeel:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `feel: PlatformerFeel, dt: float, isGrounded: bool, jumpPressed: bool, coyoteDuration: float = 0.15, bufferDuration: float = 0.15` | **Returns**: `PlatformerFeel`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `platformerFeelStep` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `feel: PlatformerFeel = PlatformerFeel(coyoteTimer = 1.0, jumpBufferTimer = 1.0, hitStopTimer = 1.0, timeScale = 1.0)`, `dt: float = 0.016667`, `isGrounded: bool = true`, `jumpPressed: bool = true`, `coyoteDuration: float = 0.5`, `bufferDuration: float = 0.5`; exercises core body path returning/computing `PlatformerFeel(`.

```aipl
module tests.functions.gfx2d.camera2d_z42_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_platformerFeelStep_42(): int:
  let arg_feel = PlatformerFeel(coyoteTimer = 1.0, jumpBufferTimer = 1.0, hitStopTimer = 2.0, timeScale = 2.0)
  let edge_feel = PlatformerFeel(coyoteTimer = 0.5, jumpBufferTimer = 0.5, hitStopTimer = 1.0, timeScale = 1.0)
  let arg_dt = 2.0
  let edge_dt = 1.0
  let arg_isGrounded = true
  let edge_isGrounded = false
  let arg_jumpPressed = true
  let edge_jumpPressed = false
  let arg_coyoteDuration = 1.0
  let edge_coyoteDuration = 0.5
  let arg_bufferDuration = 1.0
  let edge_bufferDuration = 0.5
  let resNom = platformerFeelStep(arg_feel, arg_dt, arg_isGrounded, arg_jumpPressed, arg_coyoteDuration, arg_bufferDuration)
  let resEdge = platformerFeelStep(edge_feel, edge_dt, edge_isGrounded, edge_jumpPressed, edge_coyoteDuration, edge_bufferDuration)
  assertApproxEq(resNom.coyoteTimer, 1.0, 0.001, "platformerFeelStep nominal resNom.coyoteTimer ~= 1.0")
  assertApproxEq(resEdge.coyoteTimer, 0.0, 0.001, "platformerFeelStep boundary resEdge.coyoteTimer ~= 0.0")
  ret 0
```

---

### `platformerFeelConsumeJump` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn platformerFeelConsumeJump(feel: PlatformerFeel): PlatformerFeel:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `feel: PlatformerFeel` | **Returns**: `PlatformerFeel`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `platformerFeelConsumeJump` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `feel: PlatformerFeel = PlatformerFeel(coyoteTimer = 1.0, jumpBufferTimer = 1.0, hitStopTimer = 1.0, timeScale = 1.0)`; exercises core body path returning/computing `PlatformerFeel(`.

```aipl
module tests.functions.gfx2d.camera2d_z43_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_platformerFeelConsumeJump_43(): int:
  let arg_feel = PlatformerFeel(coyoteTimer = 1.0, jumpBufferTimer = 1.0, hitStopTimer = 2.0, timeScale = 2.0)
  let edge_feel = PlatformerFeel(coyoteTimer = 0.5, jumpBufferTimer = 0.5, hitStopTimer = 1.0, timeScale = 1.0)
  let resNom = platformerFeelConsumeJump(arg_feel)
  let resEdge = platformerFeelConsumeJump(edge_feel)
  assertApproxEq(resNom.coyoteTimer, 0.0, 0.001, "platformerFeelConsumeJump nominal resNom.coyoteTimer ~= 0.0")
  assertApproxEq(resEdge.coyoteTimer, 0.0, 0.001, "platformerFeelConsumeJump boundary resEdge.coyoteTimer ~= 0.0")
  ret 0
```

---

### `configureGameMaxFps` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn configureGameMaxFps(maxFps: int): int:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `maxFps: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `configureGameMaxFps` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `maxFps: int = 1`; exercises core body path returning/computing `safeMax`.

```aipl
module tests.functions.gfx2d.camera2d_z44_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_configureGameMaxFps_44(): int:
  let arg_maxFps = 4
  let edge_maxFps = 1
  let resNom = configureGameMaxFps(arg_maxFps)
  let resEdge = configureGameMaxFps(edge_maxFps)
  assertEqInt(resNom, 15, "configureGameMaxFps nominal resNom == 15")
  assertEqInt(resEdge, 15, "configureGameMaxFps boundary resEdge == 15")
  ret 0
```

---

### `setGameMaxFps` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn setGameMaxFps(maxFps: int):`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `setGameMaxFps` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `maxFps: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.camera2d_z45_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_setGameMaxFps_45(): int:
  mut completedCalls = 0
  let arg_maxFps = 4
  let edge_maxFps = 1
  setGameMaxFps(arg_maxFps)
  setGameMaxFps(edge_maxFps)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "setGameMaxFps nominal and boundary void calls completed")
  ret 0
```

---

### `getGameFrameTimeMs` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn getGameFrameTimeMs(): float:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `getGameFrameTimeMs` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `dt * 1000.0`.

```aipl
module tests.functions.gfx2d.camera2d_z46_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_getGameFrameTimeMs_46(): int:
  let resNom = getGameFrameTimeMs()
  let resEdge = getGameFrameTimeMs()
  assertApproxEq(resNom, 66.6667, 0.001, "getGameFrameTimeMs nominal resNom ~= 66.6667")
  assertApproxEq(resEdge, 66.6667, 0.001, "getGameFrameTimeMs boundary resEdge ~= 66.6667")
  ret 0
```

---

### `getGameCurrentFps` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn getGameCurrentFps(): int:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `getGameCurrentFps` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `int((1.0 / dt) + 0.5)`.

```aipl
module tests.functions.gfx2d.camera2d_z47_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_getGameCurrentFps_47(): int:
  let resNom = getGameCurrentFps()
  let resEdge = getGameCurrentFps()
  assertEqInt(resNom, 15, "getGameCurrentFps nominal resNom == 15")
  assertEqInt(resEdge, 15, "getGameCurrentFps boundary resEdge == 15")
  ret 0
```

---

### `sampleFpsTelemetry` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn sampleFpsTelemetry(maxFps: int): FpsTelemetry:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `maxFps: int` | **Returns**: `FpsTelemetry`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `sampleFpsTelemetry` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `maxFps: int = 1`; exercises core body path returning/computing `FpsTelemetry(`.

```aipl
module tests.functions.gfx2d.camera2d_z48_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_sampleFpsTelemetry_48(): int:
  let arg_maxFps = 4
  let edge_maxFps = 1
  let resNom = sampleFpsTelemetry(arg_maxFps)
  let resEdge = sampleFpsTelemetry(edge_maxFps)
  assertEqInt(resNom.maxFps, 4, "sampleFpsTelemetry nominal resNom.maxFps == 4")
  assertEqInt(resEdge.maxFps, 1, "sampleFpsTelemetry boundary resEdge.maxFps == 1")
  ret 0
```

---

### `evaluateEcgWaveform` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn evaluateEcgWaveform(bpm: float, phaseSec: float, conditionTier: int): float:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bpm: float, phaseSec: float, conditionTier: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `evaluateEcgWaveform` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `bpm: float = 1.0`, `phaseSec: float = 1.0`, `conditionTier: int = 1`; exercises core body path returning/computing `0.0`.

```aipl
module tests.functions.gfx2d.camera2d_z49_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_evaluateEcgWaveform_49(): int:
  let arg_bpm = 1.0
  let edge_bpm = 0.5
  let arg_phaseSec = 2.0
  let edge_phaseSec = 1.0
  let arg_conditionTier = 4
  let edge_conditionTier = 1
  let resNom = evaluateEcgWaveform(arg_bpm, arg_phaseSec, arg_conditionTier)
  let resEdge = evaluateEcgWaveform(edge_bpm, edge_phaseSec, edge_conditionTier)
  assertApproxEq(resNom, -0.288, 0.001, "evaluateEcgWaveform nominal resNom ~= -0.288")
  assertApproxEq(resEdge, 0.0, 0.001, "evaluateEcgWaveform boundary resEdge ~= 0.0")
  ret 0
```

---

### `parabolicProjectilePosY` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn parabolicProjectilePosY(startY: float, vy0: float, gravity: float, t: float): float:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `startY: float, vy0: float, gravity: float, t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `parabolicProjectilePosY` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `startY: float = 1.0`, `vy0: float = 1.0`, `gravity: float = 1.0`, `t: float = 0.5`; exercises core body path returning/computing `startY + vy0 * t + 0.5 * gravity * t * t`.

```aipl
module tests.functions.gfx2d.camera2d_z50_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_parabolicProjectilePosY_50(): int:
  let arg_startY = 0.0
  let edge_startY = 0.0
  let arg_vy0 = 1.0
  let edge_vy0 = 0.5
  let arg_gravity = 1.0
  let edge_gravity = 0.5
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = parabolicProjectilePosY(arg_startY, arg_vy0, arg_gravity, arg_t)
  let resEdge = parabolicProjectilePosY(edge_startY, edge_vy0, edge_gravity, edge_t)
  assertApproxEq(resNom, 1.5, 0.001, "parabolicProjectilePosY nominal resNom ~= 1.5")
  assertApproxEq(resEdge, 0.3125, 0.001, "parabolicProjectilePosY boundary resEdge ~= 0.3125")
  ret 0
```

---

### `fixedAccumulatorNew` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn fixedAccumulatorNew(fixedDt: float, maxFrameDt: float): FixedStepAccumulator:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fixedDt: float, maxFrameDt: float` | **Returns**: `FixedStepAccumulator`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `fixedAccumulatorNew` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `fixedDt: float = 0.016667`, `maxFrameDt: float = 0.016667`; exercises core body path returning/computing `FixedStepAccumulator(`.

```aipl
module tests.functions.gfx2d.camera2d_z51_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_fixedAccumulatorNew_51(): int:
  let arg_fixedDt = 2.0
  let edge_fixedDt = 1.0
  let arg_maxFrameDt = 2.0
  let edge_maxFrameDt = 1.0
  let resNom = fixedAccumulatorNew(arg_fixedDt, arg_maxFrameDt)
  let resEdge = fixedAccumulatorNew(edge_fixedDt, edge_maxFrameDt)
  assertApproxEq(resNom.fixedDt, 2.0, 0.001, "fixedAccumulatorNew nominal resNom.fixedDt ~= 2.0")
  assertApproxEq(resEdge.fixedDt, 1.0, 0.001, "fixedAccumulatorNew boundary resEdge.fixedDt ~= 1.0")
  ret 0
```

---

### `fixedAccumulatorAdvance` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn fixedAccumulatorAdvance(acc: FixedStepAccumulator, rawDeltaSec: float): FixedStepAccumulator:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `acc: FixedStepAccumulator, rawDeltaSec: float` | **Returns**: `FixedStepAccumulator`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `fixedAccumulatorAdvance` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `acc: FixedStepAccumulator = FixedStepAccumulator(fixedDt = 0.016667, maxFrameDt = 0.016667, accumulator = 1.0, stepsToRun = 1, alpha = 0.5, totalTicks = 1)`, `rawDeltaSec: float = 1.0`; exercises core body path returning/computing `FixedStepAccumulator(`.

```aipl
module tests.functions.gfx2d.camera2d_z52_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_fixedAccumulatorAdvance_52(): int:
  let arg_acc = FixedStepAccumulator(fixedDt = 2.0, maxFrameDt = 2.0, accumulator = 1.0, stepsToRun = 4, alpha = 2.0, totalTicks = 4)
  let edge_acc = FixedStepAccumulator(fixedDt = 1.0, maxFrameDt = 1.0, accumulator = 0.5, stepsToRun = 1, alpha = 1.0, totalTicks = 1)
  let arg_rawDeltaSec = 2.0
  let edge_rawDeltaSec = 1.0
  let resNom = fixedAccumulatorAdvance(arg_acc, arg_rawDeltaSec)
  let resEdge = fixedAccumulatorAdvance(edge_acc, edge_rawDeltaSec)
  assertApproxEq(resNom.fixedDt, 2.0, 0.001, "fixedAccumulatorAdvance nominal resNom.fixedDt ~= 2.0")
  assertApproxEq(resEdge.fixedDt, 1.0, 0.001, "fixedAccumulatorAdvance boundary resEdge.fixedDt ~= 1.0")
  ret 0
```

---

### `simClockNew` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn simClockNew(fixedDt: float): SimClock:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fixedDt: float` | **Returns**: `SimClock`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `simClockNew` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `fixedDt: float = 0.016667`; exercises core body path returning/computing `SimClock(`.

```aipl
module tests.functions.gfx2d.camera2d_z53_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_simClockNew_53(): int:
  let arg_fixedDt = 2.0
  let edge_fixedDt = 1.0
  let resNom = simClockNew(arg_fixedDt)
  let resEdge = simClockNew(edge_fixedDt)
  assertEqInt(resNom.tick, 0, "simClockNew nominal resNom.tick == 0")
  assertEqInt(resEdge.tick, 0, "simClockNew boundary resEdge.tick == 0")
  ret 0
```

---

### `simClockBeginFrame` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn simClockBeginFrame(clock: SimClock, rawDeltaSec: float, stepsExecuted: int): SimClock:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `clock: SimClock, rawDeltaSec: float, stepsExecuted: int` | **Returns**: `SimClock`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `simClockBeginFrame` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `clock: SimClock = SimClock(tick = 1, fixedDt = 0.016667, simTimeSec = 1.0, wallTimeSec = 1.0, timeScale = 1.0, paused = true)`, `rawDeltaSec: float = 1.0`, `stepsExecuted: int = 1`; exercises core body path returning/computing `SimClock(`.

```aipl
module tests.functions.gfx2d.camera2d_z54_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_simClockBeginFrame_54(): int:
  let arg_clock = SimClock(tick = 4, fixedDt = 2.0, simTimeSec = 1.0, wallTimeSec = 2.0, timeScale = 2.0, paused = true)
  let edge_clock = SimClock(tick = 1, fixedDt = 1.0, simTimeSec = 0.5, wallTimeSec = 1.0, timeScale = 1.0, paused = false)
  let arg_rawDeltaSec = 2.0
  let edge_rawDeltaSec = 1.0
  let arg_stepsExecuted = 4
  let edge_stepsExecuted = 1
  let resNom = simClockBeginFrame(arg_clock, arg_rawDeltaSec, arg_stepsExecuted)
  let resEdge = simClockBeginFrame(edge_clock, edge_rawDeltaSec, edge_stepsExecuted)
  assertEqInt(resNom.tick, 4, "simClockBeginFrame nominal resNom.tick == 4")
  assertEqInt(resEdge.tick, 2, "simClockBeginFrame boundary resEdge.tick == 2")
  ret 0
```

---

### `sceneStackNew` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn sceneStackNew(initialScene: str = "boot"): SceneStack:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `initialScene: str = "boot"` | **Returns**: `SceneStack`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `sceneStackNew` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `initialScene: str = "aipl_test"`; exercises core body path returning/computing `SceneStack(scenes = s)`.

```aipl
module tests.functions.gfx2d.camera2d_z55_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_sceneStackNew_55(): int:
  let arg_initialScene = "[s]\nk=v"
  let edge_initialScene = "[s]\nk=v"
  let resNom = sceneStackNew(arg_initialScene)
  let resEdge = sceneStackNew(edge_initialScene)
  assertEqInt(resNom.scenes.len(), 1, "sceneStackNew nominal resNom.scenes.len() == 1")
  assertEqInt(resEdge.scenes.len(), 1, "sceneStackNew boundary resEdge.scenes.len() == 1")
  ret 0
```

---

### `sceneStackPush` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn sceneStackPush(mut stack: SceneStack, sceneName: str): SceneStack:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut stack: SceneStack, sceneName: str` | **Returns**: `SceneStack`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `sceneStackPush` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `stack: SceneStack = SceneStack(scenes = ["aipl_test"])`, `sceneName: str = "aipl_test"`; exercises core body path returning/computing `stack`.

```aipl
module tests.functions.gfx2d.camera2d_z56_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_sceneStackPush_56(): int:
  let arg_stack = SceneStack(scenes = [])
  let edge_stack = SceneStack(scenes = [])
  let arg_sceneName = "test"
  let edge_sceneName = "a"
  let resNom = sceneStackPush(arg_stack, arg_sceneName)
  let resEdge = sceneStackPush(edge_stack, edge_sceneName)
  assertEqInt(resNom.scenes.len(), 1, "sceneStackPush nominal resNom.scenes.len() == 1")
  assertEqInt(resEdge.scenes.len(), 1, "sceneStackPush boundary resEdge.scenes.len() == 1")
  ret 0
```

---

### `sceneStackPop` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn sceneStackPop(mut stack: SceneStack): SceneStack:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut stack: SceneStack` | **Returns**: `SceneStack`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `sceneStackPop` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `stack: SceneStack = SceneStack(scenes = ["aipl_test"])`; exercises core body path returning/computing `stack`.

```aipl
module tests.functions.gfx2d.camera2d_z57_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_sceneStackPop_57(): int:
  let arg_stack = SceneStack(scenes = [])
  let edge_stack = SceneStack(scenes = [])
  let resNom = sceneStackPop(arg_stack)
  let resEdge = sceneStackPop(edge_stack)
  assertEqInt(resNom.scenes.len(), 0, "sceneStackPop nominal resNom.scenes.len() == 0")
  assertEqInt(resEdge.scenes.len(), 0, "sceneStackPop boundary resEdge.scenes.len() == 0")
  ret 0
```

---

### `sceneStackTop` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn sceneStackTop(stack: SceneStack): str:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `stack: SceneStack` | **Returns**: `str`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `sceneStackTop` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `stack: SceneStack = SceneStack(scenes = ["aipl_test"])`; exercises core body path returning/computing `stack.scenes[stack.scenes.len() - 1]`.

```aipl
module tests.functions.gfx2d.camera2d_z58_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_sceneStackTop_58(): int:
  let arg_stack = SceneStack(scenes = [])
  let edge_stack = SceneStack(scenes = [])
  let resNom = sceneStackTop(arg_stack)
  let resEdge = sceneStackTop(edge_stack)
  assertEqStr(resNom, "", "sceneStackTop nominal string matches")
  assertEqStr(resEdge, "", "sceneStackTop boundary string matches")
  ret 0
```

---

### `replayBufferNew` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn replayBufferNew(): ReplayBuffer:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `ReplayBuffer`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `replayBufferNew` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `ReplayBuffer(ticks = t, inputs = inp, stateHashes = h)`.

```aipl
module tests.functions.gfx2d.camera2d_z59_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_replayBufferNew_59(): int:
  let resNom = replayBufferNew()
  let resEdge = replayBufferNew()
  assertEqInt(resNom.ticks.len(), 0, "replayBufferNew nominal resNom.ticks.len() == 0")
  assertEqInt(resEdge.ticks.len(), 0, "replayBufferNew boundary resEdge.ticks.len() == 0")
  ret 0
```

---

### `replayBufferRecord` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn replayBufferRecord(mut buf: ReplayBuffer, tick: int, inputMask: int, stateHash: int): ReplayBuffer:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut buf: ReplayBuffer, tick: int, inputMask: int, stateHash: int` | **Returns**: `ReplayBuffer`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `replayBufferRecord` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `buf: ReplayBuffer = ReplayBuffer(ticks = [1], inputs = [1], stateHashes = [1])`, `tick: int = 1`, `inputMask: int = 1`, `stateHash: int = 1`; exercises core body path returning/computing `buf`.

```aipl
module tests.functions.gfx2d.camera2d_z60_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_replayBufferRecord_60(): int:
  let arg_buf = ReplayBuffer(ticks = [], inputs = [], stateHashes = [])
  let edge_buf = ReplayBuffer(ticks = [], inputs = [], stateHashes = [])
  let arg_tick = 4
  let edge_tick = 1
  let arg_inputMask = 4
  let edge_inputMask = 1
  let arg_stateHash = 1
  let edge_stateHash = 0
  let resNom = replayBufferRecord(arg_buf, arg_tick, arg_inputMask, arg_stateHash)
  let resEdge = replayBufferRecord(edge_buf, edge_tick, edge_inputMask, edge_stateHash)
  assertEqInt(resNom.ticks.len(), 1, "replayBufferRecord nominal resNom.ticks.len() == 1")
  assertEqInt(resEdge.ticks.len(), 1, "replayBufferRecord boundary resEdge.ticks.len() == 1")
  ret 0
```

---

### `replayBufferSampleInput` (`std/gfx2d/camera2d.aipl`)

- **Signature**: `pub fn replayBufferSampleInput(buf: ReplayBuffer, index: int): int:`
- **Import**: `import * from "std/gfx2d/camera2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `buf: ReplayBuffer, index: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/camera2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `replayBufferSampleInput` (`free fn`) 2D camera pan/zoom `worldToScreen2D` <-> `screenToWorld2D` bijection, Trauma^2 screen shake, coyote-time/jump-buffer feel, and scene stack transitions. Concrete nominal inputs: `buf: ReplayBuffer = ReplayBuffer(ticks = [1], inputs = [1], stateHashes = [1])`, `index: int = 0`; exercises core body path returning/computing `buf.inputs[index]`.

```aipl
module tests.functions.gfx2d.camera2d_z61_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_replayBufferSampleInput_61(): int:
  let arg_buf = ReplayBuffer(ticks = [], inputs = [], stateHashes = [])
  let edge_buf = ReplayBuffer(ticks = [], inputs = [], stateHashes = [])
  let arg_index = 4
  let edge_index = 1
  let resNom = replayBufferSampleInput(arg_buf, arg_index)
  let resEdge = replayBufferSampleInput(edge_buf, edge_index)
  assertEqInt(resNom, 0, "replayBufferSampleInput nominal resNom == 0")
  assertEqInt(resEdge, 0, "replayBufferSampleInput boundary resEdge == 0")
  ret 0
```

---

### `generateGaussianKernel1D` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn generateGaussianKernel1D(radius: int, sigma: float): [float]:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `radius: int, sigma: float` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `generateGaussianKernel1D` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `radius: int = 1`, `sigma: float = 1.0`; exercises core body path returning/computing `norm`.

```aipl
module tests.functions.gfx2d.filter2d_z1_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_generateGaussianKernel1D_1(): int:
  let arg_radius = 2
  let edge_radius = 0
  let arg_sigma = 1.0
  let edge_sigma = 0.5
  let resNom = generateGaussianKernel1D(arg_radius, arg_sigma)
  let resEdge = generateGaussianKernel1D(edge_radius, edge_sigma)
  assertEqInt(resNom.len(), 5, "generateGaussianKernel1D nominal resNom.len() == 5")
  assertEqInt(resEdge.len(), 1, "generateGaussianKernel1D boundary resEdge.len() == 1")
  ret 0
```

---

### `generateSobelKernels` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn generateSobelKernels(): [ConvolutionKernel2D]:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `[ConvolutionKernel2D]`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `generateSobelKernels` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `[gx, gy]`.

```aipl
module tests.functions.gfx2d.filter2d_z2_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_generateSobelKernels_2(): int:
  let resNom = generateSobelKernels()
  let resEdge = generateSobelKernels()
  assertEqInt(resNom.len(), 2, "generateSobelKernels nominal resNom.len() == 2")
  assertEqInt(resEdge.len(), 2, "generateSobelKernels boundary resEdge.len() == 2")
  ret 0
```

---

### `applyConvolution2D` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn applyConvolution2D(pixelGrid: [int], width: int, height: int, kernel: ConvolutionKernel2D): [int]:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pixelGrid: [int], width: int, height: int, kernel: ConvolutionKernel2D` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `applyConvolution2D` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `pixelGrid: [int] = [1]`, `width: int = 128`, `height: int = 128`, `kernel: ConvolutionKernel2D = ConvolutionKernel2D(size = 64, weights = [0.5])`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.gfx2d.filter2d_z3_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_applyConvolution2D_3(): int:
  let arg_pixelGrid = [1]
  let edge_pixelGrid = []
  let arg_width = 4
  let edge_width = 1
  let arg_height = 4
  let edge_height = 1
  let arg_kernel = ConvolutionKernel2D(size = 0, weights = [])
  let edge_kernel = ConvolutionKernel2D(size = 0, weights = [])
  let resNom = applyConvolution2D(arg_pixelGrid, arg_width, arg_height, arg_kernel)
  let resEdge = applyConvolution2D(edge_pixelGrid, edge_width, edge_height, edge_kernel)
  assertEqInt(resNom.len(), 16, "applyConvolution2D nominal resNom.len() == 16")
  assertEqInt(resEdge.len(), 1, "applyConvolution2D boundary resEdge.len() == 1")
  ret 0
```

---

### `applyLumaThreshold` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn applyLumaThreshold(luma: int, threshold: int): int:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `luma: int, threshold: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `applyLumaThreshold` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `luma: int = 1`, `threshold: int = 1`; exercises core body path returning/computing `if luma >= threshold: 255 else: 0`.

```aipl
module tests.functions.gfx2d.filter2d_z4_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_applyLumaThreshold_4(): int:
  let arg_luma = 4
  let edge_luma = 1
  let arg_threshold = 2
  let edge_threshold = 0
  let resNom = applyLumaThreshold(arg_luma, arg_threshold)
  let resEdge = applyLumaThreshold(edge_luma, edge_threshold)
  assertEqInt(resNom, 255, "applyLumaThreshold nominal resNom == 255")
  assertEqInt(resEdge, 255, "applyLumaThreshold boundary resEdge == 255")
  ret 0
```

---

### `blendPixelChannel` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn blendPixelChannel(src: int, dst: int, alphaPct: int): int:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `src: int, dst: int, alphaPct: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `blendPixelChannel` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `src: int = 1`, `dst: int = 1`, `alphaPct: int = 1`; exercises core body path returning/computing `(src * a + dst * (100 - a)) / 100`.

```aipl
module tests.functions.gfx2d.filter2d_z5_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_blendPixelChannel_5(): int:
  let arg_src = 2
  let edge_src = 0
  let arg_dst = 2
  let edge_dst = 0
  let arg_alphaPct = 2
  let edge_alphaPct = 0
  let resNom = blendPixelChannel(arg_src, arg_dst, arg_alphaPct)
  let resEdge = blendPixelChannel(edge_src, edge_dst, edge_alphaPct)
  assertEqInt(resNom, 2, "blendPixelChannel nominal resNom == 2")
  assertEqInt(resEdge, 0, "blendPixelChannel boundary resEdge == 0")
  ret 0
```

---

### `f2dClamp` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `fn f2dClamp(v: int, lo: int, hi: int): int:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: int, lo: int, hi: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `f2dClamp` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `v: int = 1`, `lo: int = 1`, `hi: int = 1`; exercises core body path returning/computing `v`.

```aipl
module tests.functions.gfx2d.filter2d_z6_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_f2dClamp_6(): int:
  let arg_v = 2
  let edge_v = 0
  let arg_lo = 1
  let edge_lo = 0
  let arg_hi = 2
  let edge_hi = 0
  let resNom = f2dClamp(arg_v, arg_lo, arg_hi)
  let resEdge = f2dClamp(edge_v, edge_lo, edge_hi)
  assertEqInt(resNom, 2, "f2dClamp nominal resNom == 2")
  assertEqInt(resEdge, 0, "f2dClamp boundary resEdge == 0")
  ret 0
```

---

### `convolve3x3` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn convolve3x3(pixels: [int], w: int, h: int, k: [int], divisor: int, bias: int): [int]:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pixels: [int], w: int, h: int, k: [int], divisor: int, bias: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `convolve3x3` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `pixels: [int] = [1]`, `w: int = 128`, `h: int = 128`, `k: [int] = [1]`, `divisor: int = 1`, `bias: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.gfx2d.filter2d_z7_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_convolve3x3_7(): int:
  let arg_pixels = [1]
  let edge_pixels = []
  let arg_w = 2
  let edge_w = 0
  let arg_h = 2
  let edge_h = 0
  let arg_k = [4]
  let edge_k = []
  let arg_divisor = 2
  let edge_divisor = 0
  let arg_bias = 4
  let edge_bias = 1
  let resNom = convolve3x3(arg_pixels, arg_w, arg_h, arg_k, arg_divisor, arg_bias)
  let resEdge = convolve3x3(edge_pixels, edge_w, edge_h, edge_k, edge_divisor, edge_bias)
  assertEqInt(resNom.len(), 1, "convolve3x3 nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "convolve3x3 boundary resEdge.len() == 0")
  ret 0
```

---

### `filterBoxBlur3x3` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn filterBoxBlur3x3(pixels: [int], w: int, h: int): [int]:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pixels: [int], w: int, h: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `filterBoxBlur3x3` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `pixels: [int] = [1]`, `w: int = 128`, `h: int = 128`; exercises core body path returning/computing `convolve3x3(pixels, w, h, [1, 1, 1, 1, 1, 1, 1, 1, 1], 9, 0)`.

```aipl
module tests.functions.gfx2d.filter2d_z8_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_filterBoxBlur3x3_8(): int:
  let arg_pixels = [1]
  let edge_pixels = []
  let arg_w = 2
  let edge_w = 0
  let arg_h = 2
  let edge_h = 0
  let resNom = filterBoxBlur3x3(arg_pixels, arg_w, arg_h)
  let resEdge = filterBoxBlur3x3(edge_pixels, edge_w, edge_h)
  assertEqInt(resNom.len(), 1, "filterBoxBlur3x3 nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "filterBoxBlur3x3 boundary resEdge.len() == 0")
  ret 0
```

---

### `filterGaussian3x3` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn filterGaussian3x3(pixels: [int], w: int, h: int): [int]:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pixels: [int], w: int, h: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `filterGaussian3x3` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `pixels: [int] = [1]`, `w: int = 128`, `h: int = 128`; exercises core body path returning/computing `convolve3x3(pixels, w, h, [1, 2, 1, 2, 4, 2, 1, 2, 1], 16, 0)`.

```aipl
module tests.functions.gfx2d.filter2d_z9_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_filterGaussian3x3_9(): int:
  let arg_pixels = [1]
  let edge_pixels = []
  let arg_w = 2
  let edge_w = 0
  let arg_h = 2
  let edge_h = 0
  let resNom = filterGaussian3x3(arg_pixels, arg_w, arg_h)
  let resEdge = filterGaussian3x3(edge_pixels, edge_w, edge_h)
  assertEqInt(resNom.len(), 1, "filterGaussian3x3 nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "filterGaussian3x3 boundary resEdge.len() == 0")
  ret 0
```

---

### `filterSharpen3x3` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn filterSharpen3x3(pixels: [int], w: int, h: int): [int]:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pixels: [int], w: int, h: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `filterSharpen3x3` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `pixels: [int] = [1]`, `w: int = 128`, `h: int = 128`; exercises core body path returning/computing `convolve3x3(pixels, w, h, [0, -1, 0, -1, 5, -1, 0, -1, 0], 1, 0)`.

```aipl
module tests.functions.gfx2d.filter2d_z10_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_filterSharpen3x3_10(): int:
  let arg_pixels = [1]
  let edge_pixels = []
  let arg_w = 2
  let edge_w = 0
  let arg_h = 2
  let edge_h = 0
  let resNom = filterSharpen3x3(arg_pixels, arg_w, arg_h)
  let resEdge = filterSharpen3x3(edge_pixels, edge_w, edge_h)
  assertEqInt(resNom.len(), 1, "filterSharpen3x3 nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "filterSharpen3x3 boundary resEdge.len() == 0")
  ret 0
```

---

### `filterSobelEdges` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn filterSobelEdges(pixels: [int], w: int, h: int): [int]:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pixels: [int], w: int, h: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `filterSobelEdges` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `pixels: [int] = [1]`, `w: int = 128`, `h: int = 128`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.gfx2d.filter2d_z11_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_filterSobelEdges_11(): int:
  let arg_pixels = [1]
  let edge_pixels = []
  let arg_w = 2
  let edge_w = 0
  let arg_h = 2
  let edge_h = 0
  let resNom = filterSobelEdges(arg_pixels, arg_w, arg_h)
  let resEdge = filterSobelEdges(edge_pixels, edge_w, edge_h)
  assertEqInt(resNom.len(), 1, "filterSobelEdges nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "filterSobelEdges boundary resEdge.len() == 0")
  ret 0
```

---

### `fadeAlpha` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn fadeAlpha(baseColor: Color, alpha: float): Color:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `baseColor: Color, alpha: float` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `fadeAlpha` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `baseColor: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `alpha: float = 0.5`; exercises core body path returning/computing `Color(r = baseColor.r, g = baseColor.g, b = baseColor.b, a = a)`.

```aipl
module tests.functions.gfx2d.filter2d_z12_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_fadeAlpha_12(): int:
  let arg_baseColor = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_baseColor = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_alpha = 2.0
  let edge_alpha = 1.0
  let resNom = fadeAlpha(arg_baseColor, arg_alpha)
  let resEdge = fadeAlpha(edge_baseColor, edge_alpha)
  assertApproxEq(resNom.r, 1.0, 0.001, "fadeAlpha nominal resNom.r ~= 1.0")
  assertApproxEq(resEdge.r, 0.5, 0.001, "fadeAlpha boundary resEdge.r ~= 0.5")
  ret 0
```

---

### `morphColor` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn morphColor(c1: Color, c2: Color, t: float): Color:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c1: Color, c2: Color, t: float` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `morphColor` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `c1: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `c2: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `Color(r = r, g = g, b = b, a = a)`.

```aipl
module tests.functions.gfx2d.filter2d_z13_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_morphColor_13(): int:
  let arg_c1 = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_c1 = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_c2 = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_c2 = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = morphColor(arg_c1, arg_c2, arg_t)
  let resEdge = morphColor(edge_c1, edge_c2, edge_t)
  assertApproxEq(resNom.r, 1.0, 0.001, "morphColor nominal resNom.r ~= 1.0")
  assertApproxEq(resEdge.r, 0.5, 0.001, "morphColor boundary resEdge.r ~= 0.5")
  ret 0
```

---

### `hslToColor` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn hslToColor(h: float, s: float, l: float): Color:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `h: float, s: float, l: float` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `hslToColor` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `h: float = 1.0`, `s: float = 1.0`, `l: float = 1.0`; exercises core body path returning/computing `Color(r = r1 + m, g = g1 + m, b = b1 + m, a = 1.0)`.

```aipl
module tests.functions.gfx2d.filter2d_z14_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_hslToColor_14(): int:
  let arg_h = 2.0
  let edge_h = 1.0
  let arg_s = 1.0
  let edge_s = 0.5
  let arg_l = 1.0
  let edge_l = 0.5
  let resNom = hslToColor(arg_h, arg_s, arg_l)
  let resEdge = hslToColor(edge_h, edge_s, edge_l)
  assertApproxEq(resNom.r, 1.0, 0.001, "hslToColor nominal resNom.r ~= 1.0")
  assertApproxEq(resEdge.r, 0.75, 0.001, "hslToColor boundary resEdge.r ~= 0.75")
  ret 0
```

---

### `rainbowMorph` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn rainbowMorph(t: float): Color:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `rainbowMorph` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `hslToColor(h, 1.0, 0.5)`.

```aipl
module tests.functions.gfx2d.filter2d_z15_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_rainbowMorph_15(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = rainbowMorph(arg_t)
  let resEdge = rainbowMorph(edge_t)
  assertApproxEq(resNom.r, 1.0, 0.001, "rainbowMorph nominal resNom.r ~= 1.0")
  assertApproxEq(resEdge.r, 0.0, 0.001, "rainbowMorph boundary resEdge.r ~= 0.0")
  ret 0
```

---

### `morphPoints` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn morphPoints(ptsA: [float], ptsB: [float], t: float): [float]:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ptsA: [float], ptsB: [float], t: float` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `morphPoints` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `ptsA: [float] = [1.0]`, `ptsB: [float] = [1.0]`, `t: float = 0.5`; exercises core body path returning/computing `result`.

```aipl
module tests.functions.gfx2d.filter2d_z16_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_morphPoints_16(): int:
  let arg_ptsA = [1.0]
  let edge_ptsA = []
  let arg_ptsB = [1.0]
  let edge_ptsB = []
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = morphPoints(arg_ptsA, arg_ptsB, arg_t)
  let resEdge = morphPoints(edge_ptsA, edge_ptsB, edge_t)
  assertEqInt(resNom.len(), 1, "morphPoints nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "morphPoints boundary resEdge.len() == 0")
  ret 0
```

---

### `calculatePulseScale` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn calculatePulseScale(baseScale: float, pulseAmount: float, frequency: float, time: float): float:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `baseScale: float, pulseAmount: float, frequency: float, time: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `calculatePulseScale` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `baseScale: float = 1.0`, `pulseAmount: float = 1.0`, `frequency: float = 1.0`, `time: float = 1.0`; exercises core body path returning/computing `baseScale + pulseAmount * wave`.

```aipl
module tests.functions.gfx2d.filter2d_z17_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_calculatePulseScale_17(): int:
  let arg_baseScale = 2.0
  let edge_baseScale = 1.0
  let arg_pulseAmount = 1.0
  let edge_pulseAmount = 0.5
  let arg_frequency = 2.0
  let edge_frequency = 1.0
  let arg_time = 1.0
  let edge_time = 0.5
  let resNom = calculatePulseScale(arg_baseScale, arg_pulseAmount, arg_frequency, arg_time)
  let resEdge = calculatePulseScale(edge_baseScale, edge_pulseAmount, edge_frequency, edge_time)
  assertApproxEq(resNom, 2.0, 0.001, "calculatePulseScale nominal resNom ~= 2.0")
  assertApproxEq(resEdge, 1.0, 0.001, "calculatePulseScale boundary resEdge ~= 1.0")
  ret 0
```

---

### `drawGlowCircleColor` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn drawGlowCircleColor(cx: float, cy: float, radius: float, color: Color, layers: int):`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `drawGlowCircleColor` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `cx: float = 1.0`, `cy: float = 1.0`, `radius: float = 1.0`, `color: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `layers: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.filter2d_z18_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_drawGlowCircleColor_18(): int:
  mut completedCalls = 0
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_cy = 1.0
  let edge_cy = 0.5
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_layers = 1
  let edge_layers = 0
  drawGlowCircleColor(arg_cx, arg_cy, arg_radius, arg_color, arg_layers)
  drawGlowCircleColor(edge_cx, edge_cy, edge_radius, edge_color, edge_layers)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawGlowCircleColor nominal and boundary void calls completed")
  ret 0
```

---

### `drawGlowRect` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn drawGlowRect(x: float, y: float, w: float, h: float, color: Color, layers: int):`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawGlowRect` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`, `color: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `layers: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.filter2d_z19_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_drawGlowRect_19(): int:
  mut completedCalls = 0
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let arg_color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_layers = 1
  let edge_layers = 0
  drawGlowRect(arg_x, arg_y, arg_w, arg_h, arg_color, arg_layers)
  drawGlowRect(edge_x, edge_y, edge_w, edge_h, edge_color, edge_layers)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawGlowRect nominal and boundary void calls completed")
  ret 0
```

---

### `dissolveShape` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn dissolveShape(centerX: float, centerY: float, w: float, h: float, progress: float, color: Color, particleCount: int):`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `dissolveShape` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `centerX: float = 1.0`, `centerY: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`, `progress: float = 1.0`, `color: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `particleCount: int = 64`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.filter2d_z20_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_dissolveShape_20(): int:
  mut completedCalls = 0
  let arg_centerX = 1.0
  let edge_centerX = 0.5
  let arg_centerY = 1.0
  let edge_centerY = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let arg_progress = 1.0
  let edge_progress = 0.5
  let arg_color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_particleCount = 4
  let edge_particleCount = 1
  dissolveShape(arg_centerX, arg_centerY, arg_w, arg_h, arg_progress, arg_color, arg_particleCount)
  dissolveShape(edge_centerX, edge_centerY, edge_w, edge_h, edge_progress, edge_color, edge_particleCount)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "dissolveShape nominal and boundary void calls completed")
  ret 0
```

---

### `interpolateColorOverLife` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn interpolateColorOverLife(startColor: Color, endColor: Color, life: float, maxLife: float): Color:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `startColor: Color, endColor: Color, life: float, maxLife: float` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `interpolateColorOverLife` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `startColor: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `endColor: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `life: float = 1.0`, `maxLife: float = 1.0`; exercises core body path returning/computing `morphColor(startColor, endColor, t)`.

```aipl
module tests.functions.gfx2d.filter2d_z21_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_interpolateColorOverLife_21(): int:
  let arg_startColor = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_startColor = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_endColor = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_endColor = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_life = 1.0
  let edge_life = 0.5
  let arg_maxLife = 2.0
  let edge_maxLife = 1.0
  let resNom = interpolateColorOverLife(arg_startColor, arg_endColor, arg_life, arg_maxLife)
  let resEdge = interpolateColorOverLife(edge_startColor, edge_endColor, edge_life, edge_maxLife)
  assertApproxEq(resNom.r, 1.0, 0.001, "interpolateColorOverLife nominal resNom.r ~= 1.0")
  assertApproxEq(resEdge.r, 0.5, 0.001, "interpolateColorOverLife boundary resEdge.r ~= 0.5")
  ret 0
```

---

### `colorOverLife` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn colorOverLife(c1: Color, c2: Color, progress: float): Color:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c1: Color, c2: Color, progress: float` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `colorOverLife` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `c1: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `c2: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `progress: float = 1.0`; exercises core body path returning/computing `morphColor(c1, c2, progress)`.

```aipl
module tests.functions.gfx2d.filter2d_z22_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_colorOverLife_22(): int:
  let arg_c1 = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_c1 = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_c2 = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_c2 = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_progress = 1.0
  let edge_progress = 0.5
  let resNom = colorOverLife(arg_c1, arg_c2, arg_progress)
  let resEdge = colorOverLife(edge_c1, edge_c2, edge_progress)
  assertApproxEq(resNom.r, 1.0, 0.001, "colorOverLife nominal resNom.r ~= 1.0")
  assertApproxEq(resEdge.r, 0.5, 0.001, "colorOverLife boundary resEdge.r ~= 0.5")
  ret 0
```

---

### `emitExplosionParticles` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn emitExplosionParticles(ox: float, oy: float, count: int, speed: float, baseColor: Color): [FxParticle]:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ox: float, oy: float, count: int, speed: float, baseColor: Color` | **Returns**: `[FxParticle]`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `emitExplosionParticles` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `ox: float = 1.0`, `oy: float = 1.0`, `count: int = 64`, `speed: float = 1.0`, `baseColor: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.gfx2d.filter2d_z23_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_emitExplosionParticles_23(): int:
  let arg_ox = 1.0
  let edge_ox = 0.5
  let arg_oy = 1.0
  let edge_oy = 0.5
  let arg_count = 4
  let edge_count = 1
  let arg_speed = 1.0
  let edge_speed = 0.5
  let arg_baseColor = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_baseColor = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let resNom = emitExplosionParticles(arg_ox, arg_oy, arg_count, arg_speed, arg_baseColor)
  let resEdge = emitExplosionParticles(edge_ox, edge_oy, edge_count, edge_speed, edge_baseColor)
  assertEqInt(resNom.len(), 4, "emitExplosionParticles nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 1, "emitExplosionParticles boundary resEdge.len() == 1")
  ret 0
```

---

### `emitSparkTrail` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn emitSparkTrail(ox: float, oy: float, dirX: float, dirY: float, count: int, speed: float, sparkColor: Color): [FxParticle]:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ox: float, oy: float, dirX: float, dirY: float, count: int, speed: float, sparkColor: Color` | **Returns**: `[FxParticle]`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `emitSparkTrail` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `ox: float = 1.0`, `oy: float = 1.0`, `dirX: float = 1.0`, `dirY: float = 1.0`, `count: int = 64`, `speed: float = 1.0`, `sparkColor: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.gfx2d.filter2d_z24_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_emitSparkTrail_24(): int:
  let arg_ox = 1.0
  let edge_ox = 0.5
  let arg_oy = 1.0
  let edge_oy = 0.5
  let arg_dirX = 1.0
  let edge_dirX = 0.5
  let arg_dirY = 1.0
  let edge_dirY = 0.5
  let arg_count = 4
  let edge_count = 1
  let arg_speed = 1.0
  let edge_speed = 0.5
  let arg_sparkColor = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_sparkColor = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let resNom = emitSparkTrail(arg_ox, arg_oy, arg_dirX, arg_dirY, arg_count, arg_speed, arg_sparkColor)
  let resEdge = emitSparkTrail(edge_ox, edge_oy, edge_dirX, edge_dirY, edge_count, edge_speed, edge_sparkColor)
  assertEqInt(resNom.len(), 4, "emitSparkTrail nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 1, "emitSparkTrail boundary resEdge.len() == 1")
  ret 0
```

---

### `countAliveParticles` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn countAliveParticles(particles: [FxParticle]): int:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `particles: [FxParticle]` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `countAliveParticles` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `particles: [FxParticle] = [FxParticle(x = 1.0, y = 1.0, vx = 1.0, vy = 1.0, colorStart = Color(r = 0, g = 0, b = 0, a = 0), colorEnd = Color(r = 0, g = 0, b = 0, a = 0), color = Color(r = 0, g = 0, b = 0, a = 0), life = 1.0, maxLife = 1.0, size = 1.0, active = true)]`; exercises core body path returning/computing `alive`.

```aipl
module tests.functions.gfx2d.filter2d_z25_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_countAliveParticles_25(): int:
  let arg_particles = [FxParticle(x = 1.0, y = 1.0, vx = 1.0, vy = 1.0, colorStart = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), colorEnd = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), life = 1.0, maxLife = 2.0, size = 1.0, active = true)]
  let edge_particles = []
  let resNom = countAliveParticles(arg_particles)
  let resEdge = countAliveParticles(edge_particles)
  assertEqInt(resNom, 1, "countAliveParticles nominal resNom == 1")
  assertEqInt(resEdge, 0, "countAliveParticles boundary resEdge == 0")
  ret 0
```

---

### `updateFxParticle` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn updateFxParticle(p: FxParticle, dt: float, gravity: float = 0.0): FxParticle:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p: FxParticle, dt: float, gravity: float = 0.0` | **Returns**: `FxParticle`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `updateFxParticle` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `p: FxParticle = FxParticle(x = 1.0, y = 1.0, vx = 1.0, vy = 1.0, colorStart = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), colorEnd = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), life = 1.0, maxLife = 1.0, size = 1.0, active = true)`, `dt: float = 0.016667`, `gravity: float = 1.0`; exercises core body path returning/computing `FxParticle(`.

```aipl
module tests.functions.gfx2d.filter2d_z26_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_updateFxParticle_26(): int:
  let arg_p = FxParticle(x = 1.0, y = 1.0, vx = 1.0, vy = 1.0, colorStart = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), colorEnd = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), life = 1.0, maxLife = 2.0, size = 1.0, active = true)
  let edge_p = FxParticle(x = 0.5, y = 0.5, vx = 0.5, vy = 0.5, colorStart = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5), colorEnd = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5), color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5), life = 0.5, maxLife = 1.0, size = 0.5, active = false)
  let arg_dt = 2.0
  let edge_dt = 1.0
  let arg_gravity = 1.0
  let edge_gravity = 0.5
  let resNom = updateFxParticle(arg_p, arg_dt, arg_gravity)
  let resEdge = updateFxParticle(edge_p, edge_dt, edge_gravity)
  assertApproxEq(resNom.x, 3.0, 0.001, "updateFxParticle nominal resNom.x ~= 3.0")
  assertApproxEq(resEdge.x, 1.0, 0.001, "updateFxParticle boundary resEdge.x ~= 1.0")
  ret 0
```

---

### `updateFxParticles` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn updateFxParticles(particles: [FxParticle], dt: float, gravity: float = 0.0): [FxParticle]:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `particles: [FxParticle], dt: float, gravity: float = 0.0` | **Returns**: `[FxParticle]`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `updateFxParticles` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `particles: [FxParticle] = [FxParticle(x = 1.0, y = 1.0, vx = 1.0, vy = 1.0, colorStart = Color(r = 0, g = 0, b = 0, a = 0), colorEnd = Color(r = 0, g = 0, b = 0, a = 0), color = Color(r = 0, g = 0, b = 0, a = 0), life = 1.0, maxLife = 1.0, size = 1.0, active = true)]`, `dt: float = 0.016667`, `gravity: float = 1.0`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.gfx2d.filter2d_z27_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_updateFxParticles_27(): int:
  let arg_particles = [FxParticle(x = 1.0, y = 1.0, vx = 1.0, vy = 1.0, colorStart = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), colorEnd = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), life = 1.0, maxLife = 2.0, size = 1.0, active = true)]
  let edge_particles = []
  let arg_dt = 2.0
  let edge_dt = 1.0
  let arg_gravity = 1.0
  let edge_gravity = 0.5
  let resNom = updateFxParticles(arg_particles, arg_dt, arg_gravity)
  let resEdge = updateFxParticles(edge_particles, edge_dt, edge_gravity)
  assertEqInt(resNom.len(), 1, "updateFxParticles nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "updateFxParticles boundary resEdge.len() == 0")
  ret 0
```

---

### `cameraShakeNew` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn cameraShakeNew(decayRate: float, maxOffsetPx: float, maxAngleRad: float): CameraShake2D:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `decayRate: float, maxOffsetPx: float, maxAngleRad: float` | **Returns**: `CameraShake2D`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `cameraShakeNew` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `decayRate: float = 1.0`, `maxOffsetPx: float = 1.0`, `maxAngleRad: float = 1.0`; exercises core body path returning/computing `CameraShake2D(`.

```aipl
module tests.functions.gfx2d.filter2d_z28_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_cameraShakeNew_28(): int:
  let arg_decayRate = 2.0
  let edge_decayRate = 1.0
  let arg_maxOffsetPx = 2.0
  let edge_maxOffsetPx = 1.0
  let arg_maxAngleRad = 2.0
  let edge_maxAngleRad = 1.0
  let resNom = cameraShakeNew(arg_decayRate, arg_maxOffsetPx, arg_maxAngleRad)
  let resEdge = cameraShakeNew(edge_decayRate, edge_maxOffsetPx, edge_maxAngleRad)
  assertApproxEq(resNom.trauma, 0.0, 0.001, "cameraShakeNew nominal resNom.trauma ~= 0.0")
  assertApproxEq(resEdge.trauma, 0.0, 0.001, "cameraShakeNew boundary resEdge.trauma ~= 0.0")
  ret 0
```

---

### `addCameraShakeTrauma` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn addCameraShakeTrauma(mut sh: CameraShake2D, amount: float): CameraShake2D:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut sh: CameraShake2D, amount: float` | **Returns**: `CameraShake2D`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `addCameraShakeTrauma` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `sh: CameraShake2D = CameraShake2D(trauma = 1.0, decayRate = 1.0, maxOffsetPx = 1.0, maxAngleRad = 1.0, timeAcc = 1.0, offsetX = 1.0, offsetY = 1.0, angleRad = 1.0)`, `amount: float = 1.0`; exercises core body path returning/computing `sh`.

```aipl
module tests.functions.gfx2d.filter2d_z29_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_addCameraShakeTrauma_29(): int:
  let arg_sh = CameraShake2D(trauma = 1.0, decayRate = 2.0, maxOffsetPx = 2.0, maxAngleRad = 2.0, timeAcc = 1.0, offsetX = 1.0, offsetY = 1.0, angleRad = 1.0)
  let edge_sh = CameraShake2D(trauma = 0.5, decayRate = 1.0, maxOffsetPx = 1.0, maxAngleRad = 1.0, timeAcc = 0.5, offsetX = 0.5, offsetY = 0.5, angleRad = 0.5)
  let arg_amount = 1.0
  let edge_amount = 0.5
  let resNom = addCameraShakeTrauma(arg_sh, arg_amount)
  let resEdge = addCameraShakeTrauma(edge_sh, edge_amount)
  assertApproxEq(resNom.trauma, 1.0, 0.001, "addCameraShakeTrauma nominal resNom.trauma ~= 1.0")
  assertApproxEq(resEdge.trauma, 1.0, 0.001, "addCameraShakeTrauma boundary resEdge.trauma ~= 1.0")
  ret 0
```

---

### `stepCameraShake2D` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn stepCameraShake2D(mut sh: CameraShake2D, dt: float): CameraShake2D:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut sh: CameraShake2D, dt: float` | **Returns**: `CameraShake2D`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `stepCameraShake2D` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `sh: CameraShake2D = CameraShake2D(trauma = 1.0, decayRate = 1.0, maxOffsetPx = 1.0, maxAngleRad = 1.0, timeAcc = 1.0, offsetX = 1.0, offsetY = 1.0, angleRad = 1.0)`, `dt: float = 0.016667`; exercises core body path returning/computing `sh`.

```aipl
module tests.functions.gfx2d.filter2d_z30_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_stepCameraShake2D_30(): int:
  let arg_sh = CameraShake2D(trauma = 1.0, decayRate = 2.0, maxOffsetPx = 2.0, maxAngleRad = 2.0, timeAcc = 1.0, offsetX = 1.0, offsetY = 1.0, angleRad = 1.0)
  let edge_sh = CameraShake2D(trauma = 0.5, decayRate = 1.0, maxOffsetPx = 1.0, maxAngleRad = 1.0, timeAcc = 0.5, offsetX = 0.5, offsetY = 0.5, angleRad = 0.5)
  let arg_dt = 2.0
  let edge_dt = 1.0
  let resNom = stepCameraShake2D(arg_sh, arg_dt)
  let resEdge = stepCameraShake2D(edge_sh, edge_dt)
  assertApproxEq(resNom.trauma, 0.0, 0.001, "stepCameraShake2D nominal resNom.trauma ~= 0.0")
  assertApproxEq(resEdge.trauma, 0.0, 0.001, "stepCameraShake2D boundary resEdge.trauma ~= 0.0")
  ret 0
```

---

### `hitStopTimerNew` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn hitStopTimerNew(durationSec: float, freezeScale: float = 0.0): HitStopTimer:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `durationSec: float, freezeScale: float = 0.0` | **Returns**: `HitStopTimer`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `hitStopTimerNew` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `durationSec: float = 0.5`, `freezeScale: float = 1.0`; exercises core body path returning/computing `HitStopTimer(remainingSec = maxFloat(0.0, durationSec), timeScale = clampFloat(freezeScale, 0.0, 1.0))`.

```aipl
module tests.functions.gfx2d.filter2d_z31_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_hitStopTimerNew_31(): int:
  let arg_durationSec = 1.0
  let edge_durationSec = 0.5
  let arg_freezeScale = 2.0
  let edge_freezeScale = 1.0
  let resNom = hitStopTimerNew(arg_durationSec, arg_freezeScale)
  let resEdge = hitStopTimerNew(edge_durationSec, edge_freezeScale)
  assertApproxEq(resNom.remainingSec, 1.0, 0.001, "hitStopTimerNew nominal resNom.remainingSec ~= 1.0")
  assertApproxEq(resEdge.remainingSec, 0.5, 0.001, "hitStopTimerNew boundary resEdge.remainingSec ~= 0.5")
  ret 0
```

---

### `stepHitStopTimer` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn stepHitStopTimer(mut ht: HitStopTimer, rawDt: float): HitStopTimer:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut ht: HitStopTimer, rawDt: float` | **Returns**: `HitStopTimer`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `stepHitStopTimer` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `ht: HitStopTimer = HitStopTimer(remainingSec = 1.0, timeScale = 1.0)`, `rawDt: float = 0.016667`; exercises core body path returning/computing `ht`.

```aipl
module tests.functions.gfx2d.filter2d_z32_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_stepHitStopTimer_32(): int:
  let arg_ht = HitStopTimer(remainingSec = 1.0, timeScale = 2.0)
  let edge_ht = HitStopTimer(remainingSec = 0.5, timeScale = 1.0)
  let arg_rawDt = 2.0
  let edge_rawDt = 1.0
  let resNom = stepHitStopTimer(arg_ht, arg_rawDt)
  let resEdge = stepHitStopTimer(edge_ht, edge_rawDt)
  assertApproxEq(resNom.remainingSec, 0.0, 0.001, "stepHitStopTimer nominal resNom.remainingSec ~= 0.0")
  assertApproxEq(resEdge.remainingSec, 0.0, 0.001, "stepHitStopTimer boundary resEdge.remainingSec ~= 0.0")
  ret 0
```

---

### `hitStopTimerScale` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn hitStopTimerScale(ht: HitStopTimer): float:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ht: HitStopTimer` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `hitStopTimerScale` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `ht: HitStopTimer = HitStopTimer(remainingSec = 1.0, timeScale = 1.0)`; exercises core body path returning/computing `1.0`.

```aipl
module tests.functions.gfx2d.filter2d_z33_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_hitStopTimerScale_33(): int:
  let arg_ht = HitStopTimer(remainingSec = 1.0, timeScale = 2.0)
  let edge_ht = HitStopTimer(remainingSec = 0.5, timeScale = 1.0)
  let resNom = hitStopTimerScale(arg_ht)
  let resEdge = hitStopTimerScale(edge_ht)
  assertApproxEq(resNom, 2.0, 0.001, "hitStopTimerScale nominal resNom ~= 2.0")
  assertApproxEq(resEdge, 1.0, 0.001, "hitStopTimerScale boundary resEdge ~= 1.0")
  ret 0
```

---

### `hitStopTrigger` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn hitStopTrigger(durationSec: float, freezeScale: float): HitStopState:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `durationSec: float, freezeScale: float` | **Returns**: `HitStopState`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `hitStopTrigger` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `durationSec: float = 0.5`, `freezeScale: float = 1.0`; exercises core body path returning/computing `HitStopState(remainingSec = maxFloat(0.0, durationSec), timeScale = clampFloat(freezeScale, 0.0, 1.0))`.

```aipl
module tests.functions.gfx2d.filter2d_z34_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_hitStopTrigger_34(): int:
  let arg_durationSec = 1.0
  let edge_durationSec = 0.5
  let arg_freezeScale = 2.0
  let edge_freezeScale = 1.0
  let resNom = hitStopTrigger(arg_durationSec, arg_freezeScale)
  let resEdge = hitStopTrigger(edge_durationSec, edge_freezeScale)
  assertApproxEq(resNom.remainingSec, 1.0, 0.001, "hitStopTrigger nominal resNom.remainingSec ~= 1.0")
  assertApproxEq(resEdge.remainingSec, 0.5, 0.001, "hitStopTrigger boundary resEdge.remainingSec ~= 0.5")
  ret 0
```

---

### `stepHitStop` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn stepHitStop(mut hs: HitStopState, rawDt: float): HitStopState:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut hs: HitStopState, rawDt: float` | **Returns**: `HitStopState`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `stepHitStop` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `hs: HitStopState = HitStopState(remainingSec = 1.0, timeScale = 1.0)`, `rawDt: float = 0.016667`; exercises core body path returning/computing `hs`.

```aipl
module tests.functions.gfx2d.filter2d_z35_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_stepHitStop_35(): int:
  let arg_hs = HitStopState(remainingSec = 1.0, timeScale = 2.0)
  let edge_hs = HitStopState(remainingSec = 0.5, timeScale = 1.0)
  let arg_rawDt = 2.0
  let edge_rawDt = 1.0
  let resNom = stepHitStop(arg_hs, arg_rawDt)
  let resEdge = stepHitStop(edge_hs, edge_rawDt)
  assertApproxEq(resNom.remainingSec, 0.0, 0.001, "stepHitStop nominal resNom.remainingSec ~= 0.0")
  assertApproxEq(resEdge.remainingSec, 0.0, 0.001, "stepHitStop boundary resEdge.remainingSec ~= 0.0")
  ret 0
```

---

### `effectiveHitStopDt` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn effectiveHitStopDt(hs: HitStopState, rawDt: float): float:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `hs: HitStopState, rawDt: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `effectiveHitStopDt` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `hs: HitStopState = HitStopState(remainingSec = 1.0, timeScale = 1.0)`, `rawDt: float = 0.016667`; exercises core body path returning/computing `rawDt`.

```aipl
module tests.functions.gfx2d.filter2d_z36_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_effectiveHitStopDt_36(): int:
  let arg_hs = HitStopState(remainingSec = 1.0, timeScale = 2.0)
  let edge_hs = HitStopState(remainingSec = 0.5, timeScale = 1.0)
  let arg_rawDt = 2.0
  let edge_rawDt = 1.0
  let resNom = effectiveHitStopDt(arg_hs, arg_rawDt)
  let resEdge = effectiveHitStopDt(edge_hs, edge_rawDt)
  assertApproxEq(resNom, 4.0, 0.001, "effectiveHitStopDt nominal resNom ~= 4.0")
  assertApproxEq(resEdge, 1.0, 0.001, "effectiveHitStopDt boundary resEdge ~= 1.0")
  ret 0
```

---

### `drawVignetteOverlay` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn drawVignetteOverlay(viewW: float, viewH: float, thickness: float, maxAlpha: float): void:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `viewW: float, viewH: float, thickness: float, maxAlpha: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawVignetteOverlay` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `viewW: float = 1.0`, `viewH: float = 1.0`, `thickness: float = 1.0`, `maxAlpha: float = 0.5`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.filter2d_z37_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_drawVignetteOverlay_37(): int:
  mut completedCalls = 0
  let arg_viewW = 2.0
  let edge_viewW = 1.0
  let arg_viewH = 2.0
  let edge_viewH = 1.0
  let arg_thickness = 2.0
  let edge_thickness = 1.0
  let arg_maxAlpha = 2.0
  let edge_maxAlpha = 1.0
  drawVignetteOverlay(arg_viewW, arg_viewH, arg_thickness, arg_maxAlpha)
  drawVignetteOverlay(edge_viewW, edge_viewH, edge_thickness, edge_maxAlpha)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawVignetteOverlay nominal and boundary void calls completed")
  ret 0
```

---

### `imageChromaticAberration` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn imageChromaticAberration(pixels: [int], w: int, h: int, shiftPx: int): [int]:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pixels: [int], w: int, h: int, shiftPx: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `imageChromaticAberration` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `pixels: [int] = [1]`, `w: int = 128`, `h: int = 128`, `shiftPx: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.gfx2d.filter2d_z38_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_imageChromaticAberration_38(): int:
  let arg_pixels = [1]
  let edge_pixels = []
  let arg_w = 2
  let edge_w = 0
  let arg_h = 2
  let edge_h = 0
  let arg_shiftPx = 1
  let edge_shiftPx = 0
  let resNom = imageChromaticAberration(arg_pixels, arg_w, arg_h, arg_shiftPx)
  let resEdge = imageChromaticAberration(edge_pixels, edge_w, edge_h, edge_shiftPx)
  assertEqInt(resNom.len(), 1, "imageChromaticAberration nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "imageChromaticAberration boundary resEdge.len() == 0")
  ret 0
```

---

### `morphColorOklab` (`std/gfx2d/filter2d.aipl`)

- **Signature**: `pub fn morphColorOklab(c1: Color, c2: Color, t: float): Color:`
- **Import**: `import * from "std/gfx2d/filter2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c1: Color, c2: Color, t: float` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/filter2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `morphColorOklab` 3x3 Gaussian/Sobel/Sharpen/Box convolution kernels, Oklab/HSL color grading, FX burst/trail updates, and hit-stop time scaling. Concrete nominal inputs: `c1: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `c2: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `Color(r = rOut, g = gOut, b = bOut, a = aOut)`.

```aipl
module tests.functions.gfx2d.filter2d_z39_test
import * from "std/gfx2d/filter2d"
import { Color, rgba, drawRect, drawCircle, drawPolygon } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_filter2d_morphColorOklab_39(): int:
  let arg_c1 = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_c1 = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_c2 = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_c2 = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = morphColorOklab(arg_c1, arg_c2, arg_t)
  let resEdge = morphColorOklab(edge_c1, edge_c2, edge_t)
  assertApproxEq(resNom.r, 1.0, 0.001, "morphColorOklab nominal resNom.r ~= 1.0")
  assertApproxEq(resEdge.r, 0.5, 0.001, "morphColorOklab boundary resEdge.r ~= 0.5")
  ret 0
```

---

### `createIsoProjector2D` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn createIsoProjector2D(tileW: float = 64.0, tileH: float = 32.0, elevationScale: float = 16.0): IsoProjector2D:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `tileW: float = 64.0, tileH: float = 32.0, elevationScale: float = 16.0` | **Returns**: `IsoProjector2D`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `createIsoProjector2D` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `tileW: float = 1.0`, `tileH: float = 1.0`, `elevationScale: float = 1.0`; exercises core body path returning/computing `IsoProjector2D(`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z1_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_createIsoProjector2D_1(): int:
  let arg_tileW = 2.0
  let edge_tileW = 1.0
  let arg_tileH = 2.0
  let edge_tileH = 1.0
  let arg_elevationScale = 2.0
  let edge_elevationScale = 1.0
  let resNom = createIsoProjector2D(arg_tileW, arg_tileH, arg_elevationScale)
  let resEdge = createIsoProjector2D(edge_tileW, edge_tileH, edge_elevationScale)
  assertApproxEq(resNom.tileWidth, 2.0, 0.001, "createIsoProjector2D nominal resNom.tileWidth ~= 2.0")
  assertApproxEq(resEdge.tileWidth, 1.0, 0.001, "createIsoProjector2D boundary resEdge.tileWidth ~= 1.0")
  ret 0
```

---

### `isoGridToScreen` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn isoGridToScreen(proj: IsoProjector2D, coord: IsoTileCoord): Vec2:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `proj: IsoProjector2D, coord: IsoTileCoord` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `isoGridToScreen` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `proj: IsoProjector2D = IsoProjector2D(tileWidth = 0.016667, tileHeight = 1.0, elevationScale = 1.0, projectionType = 1)`, `coord: IsoTileCoord = IsoTileCoord(col = 1, row = 1, elevation = 1.0)`; exercises core body path returning/computing `Vec2(x = sx, y = sy)`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z2_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_isoGridToScreen_2(): int:
  let arg_proj = IsoProjector2D(tileWidth = 2.0, tileHeight = 2.0, elevationScale = 2.0, projectionType = 4)
  let edge_proj = IsoProjector2D(tileWidth = 1.0, tileHeight = 1.0, elevationScale = 1.0, projectionType = 1)
  let arg_coord = IsoTileCoord(col = 1, row = 1, elevation = 1.0)
  let edge_coord = IsoTileCoord(col = 0, row = 0, elevation = 0.5)
  let resNom = isoGridToScreen(arg_proj, arg_coord)
  let resEdge = isoGridToScreen(edge_proj, edge_coord)
  assertApproxEq(resNom.x, 0.0, 0.001, "isoGridToScreen nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "isoGridToScreen boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `roundFloatIso` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `fn roundFloatIso(v: float): int:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `roundFloatIso` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `v: float = 1.0`; exercises core body path returning/computing `int(v - 0.5)`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z3_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_roundFloatIso_3(): int:
  let arg_v = 1.0
  let edge_v = 0.5
  let resNom = roundFloatIso(arg_v)
  let resEdge = roundFloatIso(edge_v)
  assertEqInt(resNom, 1, "roundFloatIso nominal resNom == 1")
  assertEqInt(resEdge, 1, "roundFloatIso boundary resEdge == 1")
  ret 0
```

---

### `screenToIsoGrid` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn screenToIsoGrid(proj: IsoProjector2D, screenPt: Vec2): IsoTileCoord:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `proj: IsoProjector2D, screenPt: Vec2` | **Returns**: `IsoTileCoord`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `screenToIsoGrid` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `proj: IsoProjector2D = IsoProjector2D(tileWidth = 0.016667, tileHeight = 1.0, elevationScale = 1.0, projectionType = 1)`, `screenPt: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `IsoTileCoord(col = col, row = row, elevation = 0.0)`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z4_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_screenToIsoGrid_4(): int:
  let arg_proj = IsoProjector2D(tileWidth = 2.0, tileHeight = 2.0, elevationScale = 2.0, projectionType = 4)
  let edge_proj = IsoProjector2D(tileWidth = 1.0, tileHeight = 1.0, elevationScale = 1.0, projectionType = 1)
  let arg_screenPt = Vec2(x = 1.0, y = 1.0)
  let edge_screenPt = Vec2(x = 0.5, y = 0.5)
  let resNom = screenToIsoGrid(arg_proj, arg_screenPt)
  let resEdge = screenToIsoGrid(edge_proj, edge_screenPt)
  assertEqInt(resNom.col, 1, "screenToIsoGrid nominal resNom.col == 1")
  assertEqInt(resEdge.col, 1, "screenToIsoGrid boundary resEdge.col == 1")
  ret 0
```

---

### `computeTopologicalDepthSortKey` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn computeTopologicalDepthSortKey(col: int, row: int, elevation: float): float:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `col: int, row: int, elevation: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `computeTopologicalDepthSortKey` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `col: int = 1`, `row: int = 1`, `elevation: float = 1.0`; exercises core body path returning/computing `float(col + row) + elevation * 0.001`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z5_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_computeTopologicalDepthSortKey_5(): int:
  let arg_col = 1
  let edge_col = 0
  let arg_row = 1
  let edge_row = 0
  let arg_elevation = 1.0
  let edge_elevation = 0.5
  let resNom = computeTopologicalDepthSortKey(arg_col, arg_row, arg_elevation)
  let resEdge = computeTopologicalDepthSortKey(edge_col, edge_row, edge_elevation)
  assertApproxEq(resNom, 2.001, 0.001, "computeTopologicalDepthSortKey nominal resNom ~= 2.001")
  assertApproxEq(resEdge, 0.0005, 0.001, "computeTopologicalDepthSortKey boundary resEdge ~= 0.0005")
  ret 0
```

---

### `sortEntitiesByTopologicalDepth` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn sortEntitiesByTopologicalDepth(items: [PainterSortItem]): [PainterSortItem]:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `items: [PainterSortItem]` | **Returns**: `[PainterSortItem]`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `sortEntitiesByTopologicalDepth` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `items: [PainterSortItem] = [PainterSortItem(entityId = 1, sortKey = 1.0, drawOrder = 1)]`; exercises core body path returning/computing `sorted`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z6_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_sortEntitiesByTopologicalDepth_6(): int:
  let arg_items = [PainterSortItem(entityId = 4, sortKey = 1.0, drawOrder = 2)]
  let edge_items = []
  let resNom = sortEntitiesByTopologicalDepth(arg_items)
  let resEdge = sortEntitiesByTopologicalDepth(edge_items)
  assertEqInt(resNom.len(), 1, "sortEntitiesByTopologicalDepth nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "sortEntitiesByTopologicalDepth boundary resEdge.len() == 0")
  ret 0
```

---

### `worldToIsoX` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn worldToIsoX(gx: float, gy: float, tileW: float, originX: float): float:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `gx: float, gy: float, tileW: float, originX: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `worldToIsoX` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `gx: float = 1.0`, `gy: float = 1.0`, `tileW: float = 1.0`, `originX: float = 1.0`; exercises core body path returning/computing `originX + (gx - gy) * (tileW * 0.5)`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z7_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_worldToIsoX_7(): int:
  let arg_gx = 1.0
  let edge_gx = 0.5
  let arg_gy = 1.0
  let edge_gy = 0.5
  let arg_tileW = 2.0
  let edge_tileW = 1.0
  let arg_originX = 1.0
  let edge_originX = 0.5
  let resNom = worldToIsoX(arg_gx, arg_gy, arg_tileW, arg_originX)
  let resEdge = worldToIsoX(edge_gx, edge_gy, edge_tileW, edge_originX)
  assertApproxEq(resNom, 1.0, 0.001, "worldToIsoX nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "worldToIsoX boundary resEdge ~= 0.5")
  ret 0
```

---

### `worldToIsoY` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn worldToIsoY(gx: float, gy: float, gz: float, tileH: float, originY: float): float:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `gx: float, gy: float, gz: float, tileH: float, originY: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `worldToIsoY` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `gx: float = 1.0`, `gy: float = 1.0`, `gz: float = 1.0`, `tileH: float = 1.0`, `originY: float = 1.0`; exercises core body path returning/computing `originY + (gx + gy) * (tileH * 0.5) - gz`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z8_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_worldToIsoY_8(): int:
  let arg_gx = 1.0
  let edge_gx = 0.5
  let arg_gy = 1.0
  let edge_gy = 0.5
  let arg_gz = 1.0
  let edge_gz = 0.5
  let arg_tileH = 2.0
  let edge_tileH = 1.0
  let arg_originY = 1.0
  let edge_originY = 0.5
  let resNom = worldToIsoY(arg_gx, arg_gy, arg_gz, arg_tileH, arg_originY)
  let resEdge = worldToIsoY(edge_gx, edge_gy, edge_gz, edge_tileH, edge_originY)
  assertApproxEq(resNom, 2.0, 0.001, "worldToIsoY nominal resNom ~= 2.0")
  assertApproxEq(resEdge, 0.5, 0.001, "worldToIsoY boundary resEdge ~= 0.5")
  ret 0
```

---

### `worldToIso` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn worldToIso(gx: float, gy: float, gz: float, tileW: float, tileH: float, originX: float, originY: float): [float]:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `gx: float, gy: float, gz: float, tileW: float, tileH: float, originX: float, originY: float` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `worldToIso` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `gx: float = 1.0`, `gy: float = 1.0`, `gz: float = 1.0`, `tileW: float = 1.0`, `tileH: float = 1.0`, `originX: float = 1.0`, `originY: float = 1.0`; exercises core body path returning/computing `[sx, sy]`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z9_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_worldToIso_9(): int:
  let arg_gx = 1.0
  let edge_gx = 0.5
  let arg_gy = 1.0
  let edge_gy = 0.5
  let arg_gz = 1.0
  let edge_gz = 0.5
  let arg_tileW = 2.0
  let edge_tileW = 1.0
  let arg_tileH = 2.0
  let edge_tileH = 1.0
  let arg_originX = 1.0
  let edge_originX = 0.5
  let arg_originY = 1.0
  let edge_originY = 0.5
  let resNom = worldToIso(arg_gx, arg_gy, arg_gz, arg_tileW, arg_tileH, arg_originX, arg_originY)
  let resEdge = worldToIso(edge_gx, edge_gy, edge_gz, edge_tileW, edge_tileH, edge_originX, edge_originY)
  assertEqInt(resNom.len(), 2, "worldToIso nominal resNom.len() == 2")
  assertEqInt(resEdge.len(), 2, "worldToIso boundary resEdge.len() == 2")
  ret 0
```

---

### `isoToWorld` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn isoToWorld(screenX: float, screenY: float, tileW: float, tileH: float, originX: float, originY: float): [float]:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `screenX: float, screenY: float, tileW: float, tileH: float, originX: float, originY: float` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `isoToWorld` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `screenX: float = 1.0`, `screenY: float = 1.0`, `tileW: float = 1.0`, `tileH: float = 1.0`, `originX: float = 1.0`, `originY: float = 1.0`; exercises core body path returning/computing `[gx, gy]`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z10_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_isoToWorld_10(): int:
  let arg_screenX = 1.0
  let edge_screenX = 0.5
  let arg_screenY = 1.0
  let edge_screenY = 0.5
  let arg_tileW = 2.0
  let edge_tileW = 1.0
  let arg_tileH = 2.0
  let edge_tileH = 1.0
  let arg_originX = 1.0
  let edge_originX = 0.5
  let arg_originY = 1.0
  let edge_originY = 0.5
  let resNom = isoToWorld(arg_screenX, arg_screenY, arg_tileW, arg_tileH, arg_originX, arg_originY)
  let resEdge = isoToWorld(edge_screenX, edge_screenY, edge_tileW, edge_tileH, edge_originX, edge_originY)
  assertEqInt(resNom.len(), 2, "isoToWorld nominal resNom.len() == 2")
  assertEqInt(resEdge.len(), 2, "isoToWorld boundary resEdge.len() == 2")
  ret 0
```

---

### `isoDepthKey` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn isoDepthKey(gx: int, gy: int, gz: int): int:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `gx: int, gy: int, gz: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `isoDepthKey` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `gx: int = 1`, `gy: int = 1`, `gz: int = 1`; exercises core body path returning/computing `(gx + gy) * 1000 + gz`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z11_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_isoDepthKey_11(): int:
  let arg_gx = 1
  let edge_gx = 0
  let arg_gy = 1
  let edge_gy = 0
  let arg_gz = 1
  let edge_gz = 0
  let resNom = isoDepthKey(arg_gx, arg_gy, arg_gz)
  let resEdge = isoDepthKey(edge_gx, edge_gy, edge_gz)
  assertEqInt(resNom, 2001, "isoDepthKey nominal resNom == 2001")
  assertEqInt(resEdge, 0, "isoDepthKey boundary resEdge == 0")
  ret 0
```

---

### `drawIsoDiamond` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn drawIsoDiamond(cx: float, cy: float, tileW: float, tileH: float, fillCol: Color, outlineCol: Color):`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `drawIsoDiamond` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `cx: float = 1.0`, `cy: float = 1.0`, `tileW: float = 1.0`, `tileH: float = 1.0`, `fillCol: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `outlineCol: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z12_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_drawIsoDiamond_12(): int:
  mut completedCalls = 0
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_cy = 1.0
  let edge_cy = 0.5
  let arg_tileW = 2.0
  let edge_tileW = 1.0
  let arg_tileH = 2.0
  let edge_tileH = 1.0
  let arg_fillCol = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_fillCol = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_outlineCol = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_outlineCol = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawIsoDiamond(arg_cx, arg_cy, arg_tileW, arg_tileH, arg_fillCol, arg_outlineCol)
  drawIsoDiamond(edge_cx, edge_cy, edge_tileW, edge_tileH, edge_fillCol, edge_outlineCol)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawIsoDiamond nominal and boundary void calls completed")
  ret 0
```

---

### `drawIsoBlock` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn drawIsoBlock(cx: float, cy: float, tileW: float, tileH: float, heightPx: float, topCol: Color, leftCol: Color, rightCol: Color, outlineCol: Color):`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawIsoBlock` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `cx: float = 1.0`, `cy: float = 1.0`, `tileW: float = 1.0`, `tileH: float = 1.0`, `heightPx: float = 1.0`, `topCol: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `leftCol: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `rightCol: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `outlineCol: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z13_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_drawIsoBlock_13(): int:
  mut completedCalls = 0
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_cy = 1.0
  let edge_cy = 0.5
  let arg_tileW = 2.0
  let edge_tileW = 1.0
  let arg_tileH = 2.0
  let edge_tileH = 1.0
  let arg_heightPx = 2.0
  let edge_heightPx = 1.0
  let arg_topCol = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_topCol = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_leftCol = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_leftCol = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_rightCol = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_rightCol = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_outlineCol = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_outlineCol = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawIsoBlock(arg_cx, arg_cy, arg_tileW, arg_tileH, arg_heightPx, arg_topCol, arg_leftCol, arg_rightCol, arg_outlineCol)
  drawIsoBlock(edge_cx, edge_cy, edge_tileW, edge_tileH, edge_heightPx, edge_topCol, edge_leftCol, edge_rightCol, edge_outlineCol)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawIsoBlock nominal and boundary void calls completed")
  ret 0
```

---

### `absVal` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `fn absVal(n: int): int:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `n: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `absVal` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `n: int = 1`; exercises core body path returning/computing `n`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z14_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_absVal_14(): int:
  let arg_n = 4
  let edge_n = 1
  let resNom = absVal(arg_n)
  let resEdge = absVal(edge_n)
  assertEqInt(resNom, 4, "absVal nominal resNom == 4")
  assertEqInt(resEdge, 1, "absVal boundary resEdge == 1")
  ret 0
```

---

### `hexNeighbors` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn hexNeighbors(h: HexCoord): [HexCoord]:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `h: HexCoord` | **Returns**: `[HexCoord]`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `hexNeighbors` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `h: HexCoord = HexCoord(q = 1, r = 1)`; exercises core body path returning/computing `[`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z15_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_hexNeighbors_15(): int:
  let arg_h = HexCoord(q = 2, r = 2)
  let edge_h = HexCoord(q = 0, r = 0)
  let resNom = hexNeighbors(arg_h)
  let resEdge = hexNeighbors(edge_h)
  assertEqInt(resNom.len(), 6, "hexNeighbors nominal resNom.len() == 6")
  assertEqInt(resEdge.len(), 6, "hexNeighbors boundary resEdge.len() == 6")
  ret 0
```

---

### `pixelToHex` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn pixelToHex(px: float, py: float, radius: float, originX: float, originY: float): HexCoord:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `px: float, py: float, radius: float, originX: float, originY: float` | **Returns**: `HexCoord`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `pixelToHex` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `px: float = 1.0`, `py: float = 1.0`, `radius: float = 1.0`, `originX: float = 1.0`, `originY: float = 1.0`; exercises core body path returning/computing `HexCoord(q = rq, r = rr)`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z16_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_pixelToHex_16(): int:
  let arg_px = 1.0
  let edge_px = 0.5
  let arg_py = 1.0
  let edge_py = 0.5
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_originX = 1.0
  let edge_originX = 0.5
  let arg_originY = 1.0
  let edge_originY = 0.5
  let resNom = pixelToHex(arg_px, arg_py, arg_radius, arg_originX, arg_originY)
  let resEdge = pixelToHex(edge_px, edge_py, edge_radius, edge_originX, edge_originY)
  assertEqInt(resNom.q, 0, "pixelToHex nominal resNom.q == 0")
  assertEqInt(resEdge.q, 0, "pixelToHex boundary resEdge.q == 0")
  ret 0
```

---

### `drawHexagon` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn drawHexagon(cx: float, cy: float, radius: float, fillCol: Color, outlineCol: Color):`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `drawHexagon` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `cx: float = 1.0`, `cy: float = 1.0`, `radius: float = 1.0`, `fillCol: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `outlineCol: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z17_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_drawHexagon_17(): int:
  mut completedCalls = 0
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_cy = 1.0
  let edge_cy = 0.5
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_fillCol = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_fillCol = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_outlineCol = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_outlineCol = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawHexagon(arg_cx, arg_cy, arg_radius, arg_fillCol, arg_outlineCol)
  drawHexagon(edge_cx, edge_cy, edge_radius, edge_fillCol, edge_outlineCol)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawHexagon nominal and boundary void calls completed")
  ret 0
```

---

### `isoSortIndicesByDepth3D` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn isoSortIndicesByDepth3D(gxList: [float], gyList: [float], gzList: [float]): [int]:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `gxList: [float], gyList: [float], gzList: [float]` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `isoSortIndicesByDepth3D` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `gxList: [float] = [1.0]`, `gyList: [float] = [1.0]`, `gzList: [float] = [1.0]`; exercises core body path returning/computing `indices`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z18_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_isoSortIndicesByDepth3D_18(): int:
  let arg_gxList = [1.0]
  let edge_gxList = []
  let arg_gyList = [1.0]
  let edge_gyList = []
  let arg_gzList = [1.0]
  let edge_gzList = []
  let resNom = isoSortIndicesByDepth3D(arg_gxList, arg_gyList, arg_gzList)
  let resEdge = isoSortIndicesByDepth3D(edge_gxList, edge_gyList, edge_gzList)
  assertEqInt(resNom.len(), 1, "isoSortIndicesByDepth3D nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "isoSortIndicesByDepth3D boundary resEdge.len() == 0")
  ret 0
```

---

### `isoSortIndicesByDepth` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn isoSortIndicesByDepth(gxList: [float], gyList: [float]): [int]:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `gxList: [float], gyList: [float]` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `isoSortIndicesByDepth` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `gxList: [float] = [1.0]`, `gyList: [float] = [1.0]`; exercises core body path returning/computing `isoSortIndicesByDepth3D(gxList, gyList, zeroZ)`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z19_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_isoSortIndicesByDepth_19(): int:
  let arg_gxList = [1.0]
  let edge_gxList = []
  let arg_gyList = [1.0]
  let edge_gyList = []
  let resNom = isoSortIndicesByDepth(arg_gxList, arg_gyList)
  let resEdge = isoSortIndicesByDepth(edge_gxList, edge_gyList)
  assertEqInt(resNom.len(), 1, "isoSortIndicesByDepth nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "isoSortIndicesByDepth boundary resEdge.len() == 0")
  ret 0
```

---

### `isoSortIndicesByDepthFast` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn isoSortIndicesByDepthFast(gxList: [float], gyList: [float]): [int]:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `gxList: [float], gyList: [float]` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `isoSortIndicesByDepthFast` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `gxList: [float] = [1.0]`, `gyList: [float] = [1.0]`; exercises core body path returning/computing `isoSortIndicesByDepth(gxList, gyList)`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z20_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_isoSortIndicesByDepthFast_20(): int:
  let arg_gxList = [1.0]
  let edge_gxList = []
  let arg_gyList = [1.0]
  let edge_gyList = []
  let resNom = isoSortIndicesByDepthFast(arg_gxList, arg_gyList)
  let resEdge = isoSortIndicesByDepthFast(edge_gxList, edge_gyList)
  assertEqInt(resNom.len(), 1, "isoSortIndicesByDepthFast nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "isoSortIndicesByDepthFast boundary resEdge.len() == 0")
  ret 0
```

---

### `isoGridMapNew` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn isoGridMapNew(cols: int, rows: int, tileW: float, tileH: float, defaultHeight: float = 0.0): IsoGridMap:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cols: int, rows: int, tileW: float, tileH: float, defaultHeight: float = 0.0` | **Returns**: `IsoGridMap`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `isoGridMapNew` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `cols: int = 1`, `rows: int = 1`, `tileW: float = 1.0`, `tileH: float = 1.0`, `defaultHeight: float = 1.0`; exercises core body path returning/computing `IsoGridMap(cols = c, rows = r, tileW = tileW, tileH = tileH, heights = h)`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z21_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_isoGridMapNew_21(): int:
  let arg_cols = 4
  let edge_cols = 1
  let arg_rows = 4
  let edge_rows = 1
  let arg_tileW = 2.0
  let edge_tileW = 1.0
  let arg_tileH = 2.0
  let edge_tileH = 1.0
  let arg_defaultHeight = 2.0
  let edge_defaultHeight = 1.0
  let resNom = isoGridMapNew(arg_cols, arg_rows, arg_tileW, arg_tileH, arg_defaultHeight)
  let resEdge = isoGridMapNew(edge_cols, edge_rows, edge_tileW, edge_tileH, edge_defaultHeight)
  assertEqInt(resNom.cols, 4, "isoGridMapNew nominal resNom.cols == 4")
  assertEqInt(resEdge.cols, 1, "isoGridMapNew boundary resEdge.cols == 1")
  ret 0
```

---

### `isoGridGetHeight` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn isoGridGetHeight(map: IsoGridMap, col: int, row: int): float:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `map: IsoGridMap, col: int, row: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `isoGridGetHeight` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `map: IsoGridMap = IsoGridMap(cols = 1, rows = 1, tileW = 1.0, tileH = 1.0, heights = [1.0])`, `col: int = 1`, `row: int = 1`; exercises core body path returning/computing `map.heights[row * map.cols + col]`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z22_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_isoGridGetHeight_22(): int:
  let arg_map = IsoGridMap(cols = 2, rows = 2, tileW = 2.0, tileH = 2.0, heights = [1.5, 2.5, 3.5, 4.5])
  let edge_map = IsoGridMap(cols = 0, rows = 0, tileW = 1.0, tileH = 1.0, heights = [])
  let arg_col = 1
  let edge_col = 0
  let arg_row = 1
  let edge_row = 0
  let resNom = isoGridGetHeight(arg_map, arg_col, arg_row)
  let resEdge = isoGridGetHeight(edge_map, edge_col, edge_row)
  assertApproxEq(resNom, 4.5, 0.0001, "isoGridGetHeight nominal resNom == 4.5")
  assertApproxEq(resEdge, 0.0, 0.0001, "isoGridGetHeight boundary resEdge == 0.0")
  ret 0
```

---

### `isoGridSetHeight` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn isoGridSetHeight(mut map: IsoGridMap, col: int, row: int, height: float): IsoGridMap:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut map: IsoGridMap, col: int, row: int, height: float` | **Returns**: `IsoGridMap`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `isoGridSetHeight` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `map: IsoGridMap = IsoGridMap(cols = 1, rows = 1, tileW = 1.0, tileH = 1.0, heights = [1.0])`, `col: int = 1`, `row: int = 1`, `height: float = 1.0`; exercises core body path returning/computing `map`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z23_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_isoGridSetHeight_23(): int:
  let arg_map = IsoGridMap(cols = 4, rows = 4, tileW = 2.0, tileH = 2.0, heights = [])
  let edge_map = IsoGridMap(cols = 4, rows = 4, tileW = 1.0, tileH = 1.0, heights = [])
  let arg_col = 1
  let edge_col = 0
  let arg_row = 1
  let edge_row = 0
  let arg_height = 2.0
  let edge_height = 1.0
  let resNom = isoGridSetHeight(arg_map, arg_col, arg_row, arg_height)
  let resEdge = isoGridSetHeight(edge_map, edge_col, edge_row, edge_height)
  assertEqInt(resNom.cols, 4, "isoGridSetHeight nominal resNom.cols == 4")
  assertEqInt(resEdge.cols, 4, "isoGridSetHeight boundary resEdge.cols == 4")
  ret 0
```

---

### `isoPickTileRay` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn isoPickTileRay(map: IsoGridMap, screenX: float, screenY: float, originX: float, originY: float): IsoCoord:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `map: IsoGridMap, screenX: float, screenY: float, originX: float, originY: float` | **Returns**: `IsoCoord`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `isoPickTileRay` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `map: IsoGridMap = IsoGridMap(cols = 1, rows = 1, tileW = 1.0, tileH = 1.0, heights = [1.0])`, `screenX: float = 1.0`, `screenY: float = 1.0`, `originX: float = 1.0`, `originY: float = 1.0`; exercises core body path returning/computing `IsoCoord(col = gc, row = gr, height = isoGridGetHeight(map, gc, gr))`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z24_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_isoPickTileRay_24(): int:
  let arg_map = IsoGridMap(cols = 4, rows = 4, tileW = 2.0, tileH = 2.0, heights = [])
  let edge_map = IsoGridMap(cols = 4, rows = 4, tileW = 1.0, tileH = 1.0, heights = [])
  let arg_screenX = 1.0
  let edge_screenX = 0.5
  let arg_screenY = 1.0
  let edge_screenY = 0.5
  let arg_originX = 1.0
  let edge_originX = 0.5
  let arg_originY = 1.0
  let edge_originY = 0.5
  let resNom = isoPickTileRay(arg_map, arg_screenX, arg_screenY, arg_originX, arg_originY)
  let resEdge = isoPickTileRay(edge_map, edge_screenX, edge_screenY, edge_originX, edge_originY)
  assertEqInt(resNom.col, 0, "isoPickTileRay nominal resNom.col == 0")
  assertEqInt(resEdge.col, 1, "isoPickTileRay boundary resEdge.col == 1")
  ret 0
```

---

### `isoProjectWithCamera` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn isoProjectWithCamera(cam: IsoCamera2D, gx: float, gy: float, gz: float): [float]:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: IsoCamera2D, gx: float, gy: float, gz: float` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `isoProjectWithCamera` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `cam: IsoCamera2D = IsoCamera2D(originX = 1.0, originY = 1.0, tileW = 1.0, tileH = 1.0, zoom = 1.0)`, `gx: float = 1.0`, `gy: float = 1.0`, `gz: float = 1.0`; exercises core body path returning/computing `[sx, sy]`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z25_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_isoProjectWithCamera_25(): int:
  let arg_cam = IsoCamera2D(originX = 1.0, originY = 1.0, tileW = 2.0, tileH = 2.0, zoom = 1.0)
  let edge_cam = IsoCamera2D(originX = 0.5, originY = 0.5, tileW = 1.0, tileH = 1.0, zoom = 0.5)
  let arg_gx = 1.0
  let edge_gx = 0.5
  let arg_gy = 1.0
  let edge_gy = 0.5
  let arg_gz = 1.0
  let edge_gz = 0.5
  let resNom = isoProjectWithCamera(arg_cam, arg_gx, arg_gy, arg_gz)
  let resEdge = isoProjectWithCamera(edge_cam, edge_gx, edge_gy, edge_gz)
  assertEqInt(resNom.len(), 2, "isoProjectWithCamera nominal resNom.len() == 2")
  assertEqInt(resEdge.len(), 2, "isoProjectWithCamera boundary resEdge.len() == 2")
  ret 0
```

---

### `isoUnprojectWithCamera` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn isoUnprojectWithCamera(cam: IsoCamera2D, screenX: float, screenY: float): [float]:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: IsoCamera2D, screenX: float, screenY: float` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `isoUnprojectWithCamera` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `cam: IsoCamera2D = IsoCamera2D(originX = 1.0, originY = 1.0, tileW = 1.0, tileH = 1.0, zoom = 1.0)`, `screenX: float = 1.0`, `screenY: float = 1.0`; exercises core body path returning/computing `isoToWorld(screenX, screenY, effW, effH, cam.originX, cam.originY)`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z26_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_isoUnprojectWithCamera_26(): int:
  let arg_cam = IsoCamera2D(originX = 1.0, originY = 1.0, tileW = 2.0, tileH = 2.0, zoom = 1.0)
  let edge_cam = IsoCamera2D(originX = 0.5, originY = 0.5, tileW = 1.0, tileH = 1.0, zoom = 0.5)
  let arg_screenX = 1.0
  let edge_screenX = 0.5
  let arg_screenY = 1.0
  let edge_screenY = 0.5
  let resNom = isoUnprojectWithCamera(arg_cam, arg_screenX, arg_screenY)
  let resEdge = isoUnprojectWithCamera(edge_cam, edge_screenX, edge_screenY)
  assertEqInt(resNom.len(), 2, "isoUnprojectWithCamera nominal resNom.len() == 2")
  assertEqInt(resEdge.len(), 2, "isoUnprojectWithCamera boundary resEdge.len() == 2")
  ret 0
```

---

### `drawIsoShadow` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn drawIsoShadow(cx: float, cy: float, rx: float, ry: float, alpha: float):`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `drawIsoShadow` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `cx: float = 1.0`, `cy: float = 1.0`, `rx: float = 1.0`, `ry: float = 1.0`, `alpha: float = 0.5`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z27_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_drawIsoShadow_27(): int:
  mut completedCalls = 0
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_cy = 1.0
  let edge_cy = 0.5
  let arg_rx = 1.0
  let edge_rx = 0.5
  let arg_ry = 1.0
  let edge_ry = 0.5
  let arg_alpha = 2.0
  let edge_alpha = 1.0
  drawIsoShadow(arg_cx, arg_cy, arg_rx, arg_ry, arg_alpha)
  drawIsoShadow(edge_cx, edge_cy, edge_rx, edge_ry, edge_alpha)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawIsoShadow nominal and boundary void calls completed")
  ret 0
```

---

### `drawIsoLightHalo` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn drawIsoLightHalo(cx: float, cy: float, radius: float, r: float, g: float, b: float, intensity: float):`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawIsoLightHalo` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `cx: float = 1.0`, `cy: float = 1.0`, `radius: float = 1.0`, `r: float = 1.0`, `g: float = 1.0`, `b: float = 1.0`, `intensity: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z28_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_drawIsoLightHalo_28(): int:
  mut completedCalls = 0
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_cy = 1.0
  let edge_cy = 0.5
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_r = 1.0
  let edge_r = 0.5
  let arg_g = 1.0
  let edge_g = 0.5
  let arg_b = 1.0
  let edge_b = 0.5
  let arg_intensity = 1.0
  let edge_intensity = 0.5
  drawIsoLightHalo(arg_cx, arg_cy, arg_radius, arg_r, arg_g, arg_b, arg_intensity)
  drawIsoLightHalo(edge_cx, edge_cy, edge_radius, edge_r, edge_g, edge_b, edge_intensity)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawIsoLightHalo nominal and boundary void calls completed")
  ret 0
```

---

### `drawIsoTexturedTile` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn drawIsoTexturedTile(cx: float, cy: float, tileW: float, tileH: float, fillCol: Color, detailCol: Color, outlineCol: Color):`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `drawIsoTexturedTile` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `cx: float = 1.0`, `cy: float = 1.0`, `tileW: float = 1.0`, `tileH: float = 1.0`, `fillCol: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `detailCol: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `outlineCol: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z29_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_drawIsoTexturedTile_29(): int:
  mut completedCalls = 0
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_cy = 1.0
  let edge_cy = 0.5
  let arg_tileW = 2.0
  let edge_tileW = 1.0
  let arg_tileH = 2.0
  let edge_tileH = 1.0
  let arg_fillCol = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_fillCol = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_detailCol = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_detailCol = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_outlineCol = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_outlineCol = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawIsoTexturedTile(arg_cx, arg_cy, arg_tileW, arg_tileH, arg_fillCol, arg_detailCol, arg_outlineCol)
  drawIsoTexturedTile(edge_cx, edge_cy, edge_tileW, edge_tileH, edge_fillCol, edge_detailCol, edge_outlineCol)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawIsoTexturedTile nominal and boundary void calls completed")
  ret 0
```

---

### `drawIsoAutomapDiamond` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn drawIsoAutomapDiamond(cx: float, cy: float, tileW: float, tileH: float, wallMask: int, tintCol: Color):`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `drawIsoAutomapDiamond` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `cx: float = 1.0`, `cy: float = 1.0`, `tileW: float = 1.0`, `tileH: float = 1.0`, `wallMask: int = 1`, `tintCol: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z30_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_drawIsoAutomapDiamond_30(): int:
  mut completedCalls = 0
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_cy = 1.0
  let edge_cy = 0.5
  let arg_tileW = 2.0
  let edge_tileW = 1.0
  let arg_tileH = 2.0
  let edge_tileH = 1.0
  let arg_wallMask = 4
  let edge_wallMask = 1
  let arg_tintCol = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_tintCol = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawIsoAutomapDiamond(arg_cx, arg_cy, arg_tileW, arg_tileH, arg_wallMask, arg_tintCol)
  drawIsoAutomapDiamond(edge_cx, edge_cy, edge_tileW, edge_tileH, edge_wallMask, edge_tintCol)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawIsoAutomapDiamond nominal and boundary void calls completed")
  ret 0
```

---

### `tileWorldToIsoScreenX` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn tileWorldToIsoScreenX(wx: float, wy: float, wz: float, tileW: float, tileH: float, originX: float): float:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `wx: float, wy: float, wz: float, tileW: float, tileH: float, originX: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `tileWorldToIsoScreenX` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `wx: float = 1.0`, `wy: float = 1.0`, `wz: float = 1.0`, `tileW: float = 1.0`, `tileH: float = 1.0`, `originX: float = 1.0`; exercises core body path returning/computing `originX + (wx - wy) * (tileW * 0.5)`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z31_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_tileWorldToIsoScreenX_31(): int:
  let arg_wx = 2.0
  let edge_wx = 1.0
  let arg_wy = 2.0
  let edge_wy = 1.0
  let arg_wz = 2.0
  let edge_wz = 1.0
  let arg_tileW = 2.0
  let edge_tileW = 1.0
  let arg_tileH = 2.0
  let edge_tileH = 1.0
  let arg_originX = 1.0
  let edge_originX = 0.5
  let resNom = tileWorldToIsoScreenX(arg_wx, arg_wy, arg_wz, arg_tileW, arg_tileH, arg_originX)
  let resEdge = tileWorldToIsoScreenX(edge_wx, edge_wy, edge_wz, edge_tileW, edge_tileH, edge_originX)
  assertApproxEq(resNom, 1.0, 0.001, "tileWorldToIsoScreenX nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "tileWorldToIsoScreenX boundary resEdge ~= 0.5")
  ret 0
```

---

### `tileWorldToIsoScreenY` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn tileWorldToIsoScreenY(wx: float, wy: float, wz: float, tileW: float, tileH: float, heightScale: float, originY: float): float:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `wx: float, wy: float, wz: float, tileW: float, tileH: float, heightScale: float, originY: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `tileWorldToIsoScreenY` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `wx: float = 1.0`, `wy: float = 1.0`, `wz: float = 1.0`, `tileW: float = 1.0`, `tileH: float = 1.0`, `heightScale: float = 1.0`, `originY: float = 1.0`; exercises core body path returning/computing `originY + (wx + wy) * (tileH * 0.5) - wz * heightScale`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z32_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_tileWorldToIsoScreenY_32(): int:
  let arg_wx = 2.0
  let edge_wx = 1.0
  let arg_wy = 2.0
  let edge_wy = 1.0
  let arg_wz = 2.0
  let edge_wz = 1.0
  let arg_tileW = 2.0
  let edge_tileW = 1.0
  let arg_tileH = 2.0
  let edge_tileH = 1.0
  let arg_heightScale = 2.0
  let edge_heightScale = 1.0
  let arg_originY = 1.0
  let edge_originY = 0.5
  let resNom = tileWorldToIsoScreenY(arg_wx, arg_wy, arg_wz, arg_tileW, arg_tileH, arg_heightScale, arg_originY)
  let resEdge = tileWorldToIsoScreenY(edge_wx, edge_wy, edge_wz, edge_tileW, edge_tileH, edge_heightScale, edge_originY)
  assertApproxEq(resNom, 1.0, 0.001, "tileWorldToIsoScreenY nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "tileWorldToIsoScreenY boundary resEdge ~= 0.5")
  ret 0
```

---

### `tileIsoScreenToWorldX` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn tileIsoScreenToWorldX(sx: float, sy: float, tileW: float, tileH: float, originX: float, originY: float): float:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sx: float, sy: float, tileW: float, tileH: float, originX: float, originY: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `tileIsoScreenToWorldX` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `sx: float = 1.0`, `sy: float = 1.0`, `tileW: float = 1.0`, `tileH: float = 1.0`, `originX: float = 1.0`, `originY: float = 1.0`; exercises core body path returning/computing `(float(dx) / float(safeW)) + (float(dy) / float(safeH))`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z33_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_tileIsoScreenToWorldX_33(): int:
  let arg_sx = 1.0
  let edge_sx = 0.5
  let arg_sy = 1.0
  let edge_sy = 0.5
  let arg_tileW = 2.0
  let edge_tileW = 1.0
  let arg_tileH = 2.0
  let edge_tileH = 1.0
  let arg_originX = 1.0
  let edge_originX = 0.5
  let arg_originY = 1.0
  let edge_originY = 0.5
  let resNom = tileIsoScreenToWorldX(arg_sx, arg_sy, arg_tileW, arg_tileH, arg_originX, arg_originY)
  let resEdge = tileIsoScreenToWorldX(edge_sx, edge_sy, edge_tileW, edge_tileH, edge_originX, edge_originY)
  assertApproxEq(resNom, 0.0, 0.001, "tileIsoScreenToWorldX nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "tileIsoScreenToWorldX boundary resEdge ~= 0.0")
  ret 0
```

---

### `tileIsoScreenToWorldY` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn tileIsoScreenToWorldY(sx: float, sy: float, tileW: float, tileH: float, originX: float, originY: float): float:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sx: float, sy: float, tileW: float, tileH: float, originX: float, originY: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `tileIsoScreenToWorldY` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `sx: float = 1.0`, `sy: float = 1.0`, `tileW: float = 1.0`, `tileH: float = 1.0`, `originX: float = 1.0`, `originY: float = 1.0`; exercises core body path returning/computing `(float(dy) / float(safeH)) - (float(dx) / float(safeW))`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z34_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_tileIsoScreenToWorldY_34(): int:
  let arg_sx = 1.0
  let edge_sx = 0.5
  let arg_sy = 1.0
  let edge_sy = 0.5
  let arg_tileW = 2.0
  let edge_tileW = 1.0
  let arg_tileH = 2.0
  let edge_tileH = 1.0
  let arg_originX = 1.0
  let edge_originX = 0.5
  let arg_originY = 1.0
  let edge_originY = 0.5
  let resNom = tileIsoScreenToWorldY(arg_sx, arg_sy, arg_tileW, arg_tileH, arg_originX, arg_originY)
  let resEdge = tileIsoScreenToWorldY(edge_sx, edge_sy, edge_tileW, edge_tileH, edge_originX, edge_originY)
  assertApproxEq(resNom, 0.0, 0.001, "tileIsoScreenToWorldY nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "tileIsoScreenToWorldY boundary resEdge ~= 0.0")
  ret 0
```

---

### `tileHexAxialToPixelX` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn tileHexAxialToPixelX(q: int, r: int, hexRadius: float, originX: float): float:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `q: int, r: int, hexRadius: float, originX: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `tileHexAxialToPixelX` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `q: int = 1`, `r: int = 1`, `hexRadius: float = 1.0`, `originX: float = 1.0`; exercises core body path returning/computing `originX + rad * (1.73205081 * float(q) + 0.86602540 * float(r))`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z35_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_tileHexAxialToPixelX_35(): int:
  let arg_q = 2
  let edge_q = 0
  let arg_r = 2
  let edge_r = 0
  let arg_hexRadius = 2.0
  let edge_hexRadius = 1.0
  let arg_originX = 1.0
  let edge_originX = 0.5
  let resNom = tileHexAxialToPixelX(arg_q, arg_r, arg_hexRadius, arg_originX)
  let resEdge = tileHexAxialToPixelX(edge_q, edge_r, edge_hexRadius, edge_originX)
  assertApproxEq(resNom, 11.3923, 0.001, "tileHexAxialToPixelX nominal resNom ~= 11.3923")
  assertApproxEq(resEdge, 0.5, 0.001, "tileHexAxialToPixelX boundary resEdge ~= 0.5")
  ret 0
```

---

### `tileHexAxialToPixelY` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn tileHexAxialToPixelY(q: int, r: int, hexRadius: float, originY: float): float:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `q: int, r: int, hexRadius: float, originY: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `tileHexAxialToPixelY` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `q: int = 1`, `r: int = 1`, `hexRadius: float = 1.0`, `originY: float = 1.0`; exercises core body path returning/computing `originY + rad * (1.5 * float(r) + 0.0 * float(q))`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z36_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_tileHexAxialToPixelY_36(): int:
  let arg_q = 2
  let edge_q = 0
  let arg_r = 2
  let edge_r = 0
  let arg_hexRadius = 2.0
  let edge_hexRadius = 1.0
  let arg_originY = 1.0
  let edge_originY = 0.5
  let resNom = tileHexAxialToPixelY(arg_q, arg_r, arg_hexRadius, arg_originY)
  let resEdge = tileHexAxialToPixelY(edge_q, edge_r, edge_hexRadius, edge_originY)
  assertApproxEq(resNom, 7.0, 0.001, "tileHexAxialToPixelY nominal resNom ~= 7.0")
  assertApproxEq(resEdge, 0.5, 0.001, "tileHexAxialToPixelY boundary resEdge ~= 0.5")
  ret 0
```

---

### `tileHexAxialDistance` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn tileHexAxialDistance(q1: int, r1: int, q2: int, r2: int): int:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `q1: int, r1: int, q2: int, r2: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `tileHexAxialDistance` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `q1: int = 1`, `r1: int = 1`, `q2: int = 1`, `r2: int = 1`; exercises core body path returning/computing `(dq + dr + ds) / 2`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z37_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_tileHexAxialDistance_37(): int:
  let arg_q1 = 2
  let edge_q1 = 0
  let arg_r1 = 2
  let edge_r1 = 0
  let arg_q2 = 2
  let edge_q2 = 0
  let arg_r2 = 2
  let edge_r2 = 0
  let resNom = tileHexAxialDistance(arg_q1, arg_r1, arg_q2, arg_r2)
  let resEdge = tileHexAxialDistance(edge_q1, edge_r1, edge_q2, edge_r2)
  assertEqInt(resNom, 0, "tileHexAxialDistance nominal resNom == 0")
  assertEqInt(resEdge, 0, "tileHexAxialDistance boundary resEdge == 0")
  ret 0
```

---

### `tileIsChunkInViewportFrustum` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn tileIsChunkInViewportFrustum(chunkMinX: float, chunkMinY: float, chunkMaxX: float, chunkMaxY: float, viewX: float, viewY: float, viewW: float, viewH: float, marginPx: float): bool:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `chunkMinX: float, chunkMinY: float, chunkMaxX: float, chunkMaxY: float, viewX: float, viewY: float, viewW: float, viewH: float, marginPx: float` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `tileIsChunkInViewportFrustum` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `chunkMinX: float = 1.0`, `chunkMinY: float = 1.0`, `chunkMaxX: float = 1.0`, `chunkMaxY: float = 1.0`, `viewX: float = 1.0`, `viewY: float = 1.0`, `viewW: float = 1.0`, `viewH: float = 1.0`, `marginPx: float = 1.0`; exercises core body path returning/computing `chunkMaxX >= vMinX and chunkMinX <= vMaxX and chunkMaxY >= vMinY and chunkMinY <= vMaxY`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z38_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_tileIsChunkInViewportFrustum_38(): int:
  let arg_chunkMinX = 0.0
  let edge_chunkMinX = 0.0
  let arg_chunkMinY = 0.0
  let edge_chunkMinY = 0.0
  let arg_chunkMaxX = 2.0
  let edge_chunkMaxX = 1.0
  let arg_chunkMaxY = 2.0
  let edge_chunkMaxY = 1.0
  let arg_viewX = 2.0
  let edge_viewX = 1.0
  let arg_viewY = 2.0
  let edge_viewY = 1.0
  let arg_viewW = 2.0
  let edge_viewW = 1.0
  let arg_viewH = 2.0
  let edge_viewH = 1.0
  let arg_marginPx = 1.0
  let edge_marginPx = 0.5
  let resNom = tileIsChunkInViewportFrustum(arg_chunkMinX, arg_chunkMinY, arg_chunkMaxX, arg_chunkMaxY, arg_viewX, arg_viewY, arg_viewW, arg_viewH, arg_marginPx)
  let resEdge = tileIsChunkInViewportFrustum(edge_chunkMinX, edge_chunkMinY, edge_chunkMaxX, edge_chunkMaxY, edge_viewX, edge_viewY, edge_viewW, edge_viewH, edge_marginPx)
  assert(resNom == true, "tileIsChunkInViewportFrustum nominal resNom == true")
  assert(resEdge == true, "tileIsChunkInViewportFrustum boundary resEdge == true")
  ret 0
```

---

### `tileBilinearHeightSample` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn tileBilinearHeightSample(h00: float, h10: float, h01: float, h11: float, fracX: float, fracY: float): float:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `h00: float, h10: float, h01: float, h11: float, fracX: float, fracY: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `tileBilinearHeightSample` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `h00: float = 1.0`, `h10: float = 1.0`, `h01: float = 1.0`, `h11: float = 1.0`, `fracX: float = 1.0`, `fracY: float = 1.0`; exercises core body path returning/computing `top + (bot - top) * ty`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z39_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_tileBilinearHeightSample_39(): int:
  let arg_h00 = 2.0
  let edge_h00 = 1.0
  let arg_h10 = 2.0
  let edge_h10 = 1.0
  let arg_h01 = 2.0
  let edge_h01 = 1.0
  let arg_h11 = 2.0
  let edge_h11 = 1.0
  let arg_fracX = 1.0
  let edge_fracX = 0.5
  let arg_fracY = 1.0
  let edge_fracY = 0.5
  let resNom = tileBilinearHeightSample(arg_h00, arg_h10, arg_h01, arg_h11, arg_fracX, arg_fracY)
  let resEdge = tileBilinearHeightSample(edge_h00, edge_h10, edge_h01, edge_h11, edge_fracX, edge_fracY)
  assertApproxEq(resNom, 2.0, 0.001, "tileBilinearHeightSample nominal resNom ~= 2.0")
  assertApproxEq(resEdge, 1.0, 0.001, "tileBilinearHeightSample boundary resEdge ~= 1.0")
  ret 0
```

---

### `drawTileIsoDiamondWireframe` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn drawTileIsoDiamondWireframe(cx: float, cy: float, tileW: float, tileH: float, r: int, g: int, b: int, a: int):`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawTileIsoDiamondWireframe` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `cx: float = 1.0`, `cy: float = 1.0`, `tileW: float = 1.0`, `tileH: float = 1.0`, `r: int = 1`, `g: int = 1`, `b: int = 1`, `a: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z40_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_drawTileIsoDiamondWireframe_40(): int:
  mut completedCalls = 0
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_cy = 1.0
  let edge_cy = 0.5
  let arg_tileW = 2.0
  let edge_tileW = 1.0
  let arg_tileH = 2.0
  let edge_tileH = 1.0
  let arg_r = 2
  let edge_r = 0
  let arg_g = 2
  let edge_g = 0
  let arg_b = 4
  let edge_b = 1
  let arg_a = 2
  let edge_a = 0
  drawTileIsoDiamondWireframe(arg_cx, arg_cy, arg_tileW, arg_tileH, arg_r, arg_g, arg_b, arg_a)
  drawTileIsoDiamondWireframe(edge_cx, edge_cy, edge_tileW, edge_tileH, edge_r, edge_g, edge_b, edge_a)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawTileIsoDiamondWireframe nominal and boundary void calls completed")
  ret 0
```

---

### `drawTileHeightfieldPrism25D` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn drawTileHeightfieldPrism25D(cx: float, cy: float, tileW: float, tileH: float, extrudeH: float, r: int, g: int, b: int, a: int):`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `drawTileHeightfieldPrism25D` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `cx: float = 1.0`, `cy: float = 1.0`, `tileW: float = 1.0`, `tileH: float = 1.0`, `extrudeH: float = 1.0`, `r: int = 1`, `g: int = 1`, `b: int = 1`, `a: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z41_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_drawTileHeightfieldPrism25D_41(): int:
  mut completedCalls = 0
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_cy = 1.0
  let edge_cy = 0.5
  let arg_tileW = 2.0
  let edge_tileW = 1.0
  let arg_tileH = 2.0
  let edge_tileH = 1.0
  let arg_extrudeH = 2.0
  let edge_extrudeH = 1.0
  let arg_r = 2
  let edge_r = 0
  let arg_g = 2
  let edge_g = 0
  let arg_b = 4
  let edge_b = 1
  let arg_a = 2
  let edge_a = 0
  drawTileHeightfieldPrism25D(arg_cx, arg_cy, arg_tileW, arg_tileH, arg_extrudeH, arg_r, arg_g, arg_b, arg_a)
  drawTileHeightfieldPrism25D(edge_cx, edge_cy, edge_tileW, edge_tileH, edge_extrudeH, edge_r, edge_g, edge_b, edge_a)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawTileHeightfieldPrism25D nominal and boundary void calls completed")
  ret 0
```

---

### `tileComputeLightRadiusFogAlpha` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn tileComputeLightRadiusFogAlpha(tileDistSq: float, lightRadiusTiles: float, minAlpha: int, maxAlpha: int): int:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `tileDistSq: float, lightRadiusTiles: float, minAlpha: int, maxAlpha: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `tileComputeLightRadiusFogAlpha` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `tileDistSq: float = 1.0`, `lightRadiusTiles: float = 1.0`, `minAlpha: int = 1`, `maxAlpha: int = 1`; exercises core body path returning/computing `clampInt(alpha, lo, hi)`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z42_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_tileComputeLightRadiusFogAlpha_42(): int:
  let arg_tileDistSq = 1.0
  let edge_tileDistSq = 0.5
  let arg_lightRadiusTiles = 2.0
  let edge_lightRadiusTiles = 1.0
  let arg_minAlpha = 4
  let edge_minAlpha = 1
  let arg_maxAlpha = 4
  let edge_maxAlpha = 1
  let resNom = tileComputeLightRadiusFogAlpha(arg_tileDistSq, arg_lightRadiusTiles, arg_minAlpha, arg_maxAlpha)
  let resEdge = tileComputeLightRadiusFogAlpha(edge_tileDistSq, edge_lightRadiusTiles, edge_minAlpha, edge_maxAlpha)
  assertEqInt(resNom, 4, "tileComputeLightRadiusFogAlpha nominal resNom == 4")
  assertEqInt(resEdge, 1, "tileComputeLightRadiusFogAlpha boundary resEdge == 1")
  ret 0
```

---

### `tileComputePortalTeleportX` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn tileComputePortalTeleportX(unitX: float, gateInX: float, gateOutX: float): float:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `unitX: float, gateInX: float, gateOutX: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `tileComputePortalTeleportX` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `unitX: float = 1.0`, `gateInX: float = 1.0`, `gateOutX: float = 1.0`; exercises core body path returning/computing `gateOutX + (unitX - gateInX)`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z43_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_tileComputePortalTeleportX_43(): int:
  let arg_unitX = 1.0
  let edge_unitX = 0.5
  let arg_gateInX = 1.0
  let edge_gateInX = 0.5
  let arg_gateOutX = 1.0
  let edge_gateOutX = 0.5
  let resNom = tileComputePortalTeleportX(arg_unitX, arg_gateInX, arg_gateOutX)
  let resEdge = tileComputePortalTeleportX(edge_unitX, edge_gateInX, edge_gateOutX)
  assertApproxEq(resNom, 1.0, 0.001, "tileComputePortalTeleportX nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "tileComputePortalTeleportX boundary resEdge ~= 0.5")
  ret 0
```

---

### `tileComputePortalTeleportY` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn tileComputePortalTeleportY(unitY: float, gateInY: float, gateOutY: float): float:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `unitY: float, gateInY: float, gateOutY: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `tileComputePortalTeleportY` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `unitY: float = 1.0`, `gateInY: float = 1.0`, `gateOutY: float = 1.0`; exercises core body path returning/computing `gateOutY + (unitY - gateInY)`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z44_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_tileComputePortalTeleportY_44(): int:
  let arg_unitY = 1.0
  let edge_unitY = 0.5
  let arg_gateInY = 1.0
  let edge_gateInY = 0.5
  let arg_gateOutY = 1.0
  let edge_gateOutY = 0.5
  let resNom = tileComputePortalTeleportY(arg_unitY, arg_gateInY, arg_gateOutY)
  let resEdge = tileComputePortalTeleportY(edge_unitY, edge_gateInY, edge_gateOutY)
  assertApproxEq(resNom, 1.0, 0.001, "tileComputePortalTeleportY nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "tileComputePortalTeleportY boundary resEdge ~= 0.5")
  ret 0
```

---

### `tileComputePortalFormationSlotX` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn tileComputePortalFormationSlotX(centerX: float, unitIdx: int, ringRadius: float): float:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `centerX: float, unitIdx: int, ringRadius: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `tileComputePortalFormationSlotX` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `centerX: float = 1.0`, `unitIdx: int = 0`, `ringRadius: float = 1.0`; exercises core body path returning/computing `centerX + cos(angleRad) * maxFloat(0.0, ringRadius)`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z45_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_tileComputePortalFormationSlotX_45(): int:
  let arg_centerX = 1.0
  let edge_centerX = 0.5
  let arg_unitIdx = 4
  let edge_unitIdx = 1
  let arg_ringRadius = 2.0
  let edge_ringRadius = 1.0
  let resNom = tileComputePortalFormationSlotX(arg_centerX, arg_unitIdx, arg_ringRadius)
  let resEdge = tileComputePortalFormationSlotX(edge_centerX, edge_unitIdx, edge_ringRadius)
  assertApproxEq(resNom, -1.0, 0.001, "tileComputePortalFormationSlotX nominal resNom ~= -1.0")
  assertApproxEq(resEdge, 1.20711, 0.001, "tileComputePortalFormationSlotX boundary resEdge ~= 1.20711")
  ret 0
```

---

### `tileComputePortalFormationSlotY` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn tileComputePortalFormationSlotY(centerY: float, unitIdx: int, ringRadius: float): float:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `centerY: float, unitIdx: int, ringRadius: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `tileComputePortalFormationSlotY` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `centerY: float = 1.0`, `unitIdx: int = 0`, `ringRadius: float = 1.0`; exercises core body path returning/computing `centerY + sin(angleRad) * maxFloat(0.0, ringRadius)`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z46_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_tileComputePortalFormationSlotY_46(): int:
  let arg_centerY = 1.0
  let edge_centerY = 0.5
  let arg_unitIdx = 4
  let edge_unitIdx = 1
  let arg_ringRadius = 2.0
  let edge_ringRadius = 1.0
  let resNom = tileComputePortalFormationSlotY(arg_centerY, arg_unitIdx, arg_ringRadius)
  let resEdge = tileComputePortalFormationSlotY(edge_centerY, edge_unitIdx, edge_ringRadius)
  assertApproxEq(resNom, 1.0, 0.001, "tileComputePortalFormationSlotY nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.20711, 0.001, "tileComputePortalFormationSlotY boundary resEdge ~= 1.20711")
  ret 0
```

---

### `tileComputePortalVortexX` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn tileComputePortalVortexX(campCenterX: float, angleDeg: float, orbitRadius: float): float:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `campCenterX: float, angleDeg: float, orbitRadius: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `tileComputePortalVortexX` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `campCenterX: float = 1.0`, `angleDeg: float = 1.0`, `orbitRadius: float = 1.0`; exercises core body path returning/computing `campCenterX + cos(rad) * maxFloat(0.0, orbitRadius)`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z47_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_tileComputePortalVortexX_47(): int:
  let arg_campCenterX = 1.0
  let edge_campCenterX = 0.5
  let arg_angleDeg = 1.0
  let edge_angleDeg = 0.5
  let arg_orbitRadius = 2.0
  let edge_orbitRadius = 1.0
  let resNom = tileComputePortalVortexX(arg_campCenterX, arg_angleDeg, arg_orbitRadius)
  let resEdge = tileComputePortalVortexX(edge_campCenterX, edge_angleDeg, edge_orbitRadius)
  assertApproxEq(resNom, 2.9997, 0.001, "tileComputePortalVortexX nominal resNom ~= 2.9997")
  assertApproxEq(resEdge, 1.49996, 0.001, "tileComputePortalVortexX boundary resEdge ~= 1.49996")
  ret 0
```

---

### `tileComputePortalVortexY` (`std/gfx2d/iso_projector2d.aipl`)

- **Signature**: `pub fn tileComputePortalVortexY(campCenterY: float, angleDeg: float, orbitRadius: float): float:`
- **Import**: `import * from "std/gfx2d/iso_projector2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `campCenterY: float, angleDeg: float, orbitRadius: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/iso_projector2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `tileComputePortalVortexY` 2:1 isometric diamond projection `isoGridToScreen` <-> `screenToIsoGrid` round-trip, painter topological depth sort, and axial hex distance. Concrete nominal inputs: `campCenterY: float = 1.0`, `angleDeg: float = 1.0`, `orbitRadius: float = 1.0`; exercises core body path returning/computing `campCenterY + sin(rad) * maxFloat(0.0, orbitRadius)`.

```aipl
module tests.functions.gfx2d.iso_projector2d_z48_test
import * from "std/gfx2d/iso_projector2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawLine, drawTriangle, drawPolygon, drawCircle, drawEllipse } from "std/gfx2d/shape2d"
import { pi, absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_projector2d_tileComputePortalVortexY_48(): int:
  let arg_campCenterY = 1.0
  let edge_campCenterY = 0.5
  let arg_angleDeg = 1.0
  let edge_angleDeg = 0.5
  let arg_orbitRadius = 2.0
  let edge_orbitRadius = 1.0
  let resNom = tileComputePortalVortexY(arg_campCenterY, arg_angleDeg, arg_orbitRadius)
  let resEdge = tileComputePortalVortexY(edge_campCenterY, edge_angleDeg, edge_orbitRadius)
  assertApproxEq(resNom, 1.0349, 0.001, "tileComputePortalVortexY nominal resNom ~= 1.0349")
  assertApproxEq(resEdge, 0.508727, 0.001, "tileComputePortalVortexY boundary resEdge ~= 0.508727")
  ret 0
```

---

### `createPointLight2D` (`std/gfx2d/light2d.aipl`)

- **Signature**: `pub fn createPointLight2D(pos: Vec2, radius: float, color: ColorRgba8, intensity: float = 1.0): Light2D:`
- **Import**: `import * from "std/gfx2d/light2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pos: Vec2, radius: float, color: ColorRgba8, intensity: float = 1.0` | **Returns**: `Light2D`
- **Unit Test**: `tests/functions/gfx2d/light2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `createPointLight2D` 1D polar shadow map baking (`bakeShadowMap1D`), occluder ray shadow attenuation, and additive normal-mapped point light falloff. Concrete nominal inputs: `pos: Vec2 = Vec2(x = 1.0, y = 1.0)`, `radius: float = 1.0`, `color: ColorRgba8 = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255())`, `intensity: float = 1.0`; exercises core body path returning/computing `Light2D(`.

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

---

### `raySegmentDist` (`std/gfx2d/light2d.aipl`)

- **Signature**: `fn raySegmentDist(ox: float, oy: float, dx: float, dy: float, seg: OccluderSegment2D, maxR: float): float:`
- **Import**: `import * from "std/gfx2d/light2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ox: float, oy: float, dx: float, dy: float, seg: OccluderSegment2D, maxR: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/light2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `raySegmentDist` 1D polar shadow map baking (`bakeShadowMap1D`), occluder ray shadow attenuation, and additive normal-mapped point light falloff. Concrete nominal inputs: `ox: float = 1.0`, `oy: float = 1.0`, `dx: float = 1.0`, `dy: float = 1.0`, `seg: OccluderSegment2D = OccluderSegment2D(p0 = Vec2(x = 1.0, y = 1.0), p1 = Vec2(x = 1.0, y = 1.0))`, `maxR: float = 1.0`; exercises core body path returning/computing `maxR`.

```aipl
module tests.functions.gfx2d.light2d_z2_test
import * from "std/gfx2d/light2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_light2d_raySegmentDist_2(): int:
  let arg_ox = 1.0
  let edge_ox = 0.5
  let arg_oy = 1.0
  let edge_oy = 0.5
  let arg_dx = 1.0
  let edge_dx = 0.5
  let arg_dy = 1.0
  let edge_dy = 0.5
  let arg_seg = OccluderSegment2D(p0 = Vec2(x = 1.0, y = 1.0), p1 = Vec2(x = 1.0, y = 1.0))
  let edge_seg = OccluderSegment2D(p0 = Vec2(x = 0.5, y = 0.5), p1 = Vec2(x = 0.5, y = 0.5))
  let arg_maxR = 2.0
  let edge_maxR = 1.0
  let resNom = raySegmentDist(arg_ox, arg_oy, arg_dx, arg_dy, arg_seg, arg_maxR)
  let resEdge = raySegmentDist(edge_ox, edge_oy, edge_dx, edge_dy, edge_seg, edge_maxR)
  assertApproxEq(resNom, 2.0, 0.001, "raySegmentDist nominal resNom ~= 2.0")
  assertApproxEq(resEdge, 1.0, 0.001, "raySegmentDist boundary resEdge ~= 1.0")
  ret 0
```

---

### `bakeShadowMap1D` (`std/gfx2d/light2d.aipl`)

- **Signature**: `pub fn bakeShadowMap1D(light: Light2D, occluders: [OccluderSegment2D], resolution: int = 512): ShadowMap1D:`
- **Import**: `import * from "std/gfx2d/light2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `light: Light2D, occluders: [OccluderSegment2D], resolution: int = 512` | **Returns**: `ShadowMap1D`
- **Unit Test**: `tests/functions/gfx2d/light2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `bakeShadowMap1D` 1D polar shadow map baking (`bakeShadowMap1D`), occluder ray shadow attenuation, and additive normal-mapped point light falloff. Concrete nominal inputs: `light: Light2D = Light2D(position = Vec2(x = 1.0, y = 1.0), radius = 1.0, color = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255()), intensity = 1.0, spotAngleRad = 1.0, spotDir = Vec2(x = 1.0, y = 1.0))`, `occluders: [OccluderSegment2D] = [OccluderSegment2D(p0 = Vec2(x = 0, y = 0), p1 = Vec2(x = 0, y = 0))]`, `resolution: int = 1`; exercises core body path returning/computing `ShadowMap1D(resolution = res, distances = dists)`.

```aipl
module tests.functions.gfx2d.light2d_z3_test
import * from "std/gfx2d/light2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_light2d_bakeShadowMap1D_3(): int:
  let arg_light = Light2D(position = Vec2(x = 1.0, y = 1.0), radius = 2.0, color = ColorRgba8(r = 2, g = 2, b = 4, a = 2), intensity = 1.0, spotAngleRad = 1.0, spotDir = Vec2(x = 1.0, y = 1.0))
  let edge_light = Light2D(position = Vec2(x = 0.5, y = 0.5), radius = 1.0, color = ColorRgba8(r = 0, g = 0, b = 1, a = 0), intensity = 0.5, spotAngleRad = 0.5, spotDir = Vec2(x = 0.5, y = 0.5))
  let arg_occluders = [OccluderSegment2D(p0 = Vec2(x = 1.0, y = 1.0), p1 = Vec2(x = 1.0, y = 1.0))]
  let edge_occluders = []
  let arg_resolution = 4
  let edge_resolution = 1
  let resNom = bakeShadowMap1D(arg_light, arg_occluders, arg_resolution)
  let resEdge = bakeShadowMap1D(edge_light, edge_occluders, edge_resolution)
  assertEqInt(resNom.resolution, 64, "bakeShadowMap1D nominal resNom.resolution == 64")
  assertEqInt(resEdge.resolution, 64, "bakeShadowMap1D boundary resEdge.resolution == 64")
  ret 0
```

---

### `sampleLight2DIntensity` (`std/gfx2d/light2d.aipl`)

- **Signature**: `pub fn sampleLight2DIntensity(light: Light2D, shadowMap: ShadowMap1D, targetPt: Vec2): float:`
- **Import**: `import * from "std/gfx2d/light2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `light: Light2D, shadowMap: ShadowMap1D, targetPt: Vec2` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/light2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `sampleLight2DIntensity` 1D polar shadow map baking (`bakeShadowMap1D`), occluder ray shadow attenuation, and additive normal-mapped point light falloff. Concrete nominal inputs: `light: Light2D = Light2D(position = Vec2(x = 1.0, y = 1.0), radius = 1.0, color = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255()), intensity = 1.0, spotAngleRad = 1.0, spotDir = Vec2(x = 1.0, y = 1.0))`, `shadowMap: ShadowMap1D = ShadowMap1D(resolution = 1, distances = [1.0])`, `targetPt: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `light.intensity * norm * norm`.

```aipl
module tests.functions.gfx2d.light2d_z4_test
import * from "std/gfx2d/light2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_light2d_sampleLight2DIntensity_4(): int:
  let arg_light = Light2D(position = Vec2(x = 1.0, y = 1.0), radius = 2.0, color = ColorRgba8(r = 2, g = 2, b = 4, a = 2), intensity = 1.0, spotAngleRad = 1.0, spotDir = Vec2(x = 1.0, y = 1.0))
  let edge_light = Light2D(position = Vec2(x = 0.5, y = 0.5), radius = 1.0, color = ColorRgba8(r = 0, g = 0, b = 1, a = 0), intensity = 0.5, spotAngleRad = 0.5, spotDir = Vec2(x = 0.5, y = 0.5))
  let arg_shadowMap = ShadowMap1D(resolution = 4, distances = [])
  let edge_shadowMap = ShadowMap1D(resolution = 1, distances = [])
  let arg_targetPt = Vec2(x = 1.0, y = 1.0)
  let edge_targetPt = Vec2(x = 0.5, y = 0.5)
  let resNom = sampleLight2DIntensity(arg_light, arg_shadowMap, arg_targetPt)
  let resEdge = sampleLight2DIntensity(edge_light, edge_shadowMap, edge_targetPt)
  assertApproxEq(resNom, 1.0, 0.001, "sampleLight2DIntensity nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "sampleLight2DIntensity boundary resEdge ~= 0.5")
  ret 0
```

---

### `createNinePatch2D` (`std/gfx2d/ninepatch2d.aipl`)

- **Signature**: `pub fn createNinePatch2D(textureId: int, imgW: float, imgH: float, insets: SliceInsets2D): NinePatch2D:`
- **Import**: `import * from "std/gfx2d/ninepatch2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `textureId: int, imgW: float, imgH: float, insets: SliceInsets2D` | **Returns**: `NinePatch2D`
- **Unit Test**: `tests/functions/gfx2d/ninepatch2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `createNinePatch2D` 9-slice UI panel quad generation preserving unscaled corner margins while stretching center/edge regions. Concrete nominal inputs: `textureId: int = 1`, `imgW: float = 1.0`, `imgH: float = 1.0`, `insets: SliceInsets2D = SliceInsets2D(left = 1.0, top = 1.0, right = 1.0, bottom = 1.0)`; exercises core body path returning/computing `NinePatch2D(`.

```aipl
module tests.functions.gfx2d.ninepatch2d_z1_test
import * from "std/gfx2d/ninepatch2d"
import { Vec2 } from "std/math/vec_math"
import { Rect } from "std/math/geom2d"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ninepatch2d_createNinePatch2D_1(): int:
  let arg_textureId = 1
  let edge_textureId = 0
  let arg_imgW = 2.0
  let edge_imgW = 1.0
  let arg_imgH = 2.0
  let edge_imgH = 1.0
  let arg_insets = SliceInsets2D(left = 1.0, top = 1.0, right = 2.0, bottom = 1.0)
  let edge_insets = SliceInsets2D(left = 0.5, top = 0.5, right = 1.0, bottom = 0.5)
  let resNom = createNinePatch2D(arg_textureId, arg_imgW, arg_imgH, arg_insets)
  let resEdge = createNinePatch2D(edge_textureId, edge_imgW, edge_imgH, edge_insets)
  assertEqInt(resNom.textureId, 1, "createNinePatch2D nominal resNom.textureId == 1")
  assertEqInt(resEdge.textureId, 0, "createNinePatch2D boundary resEdge.textureId == 0")
  ret 0
```

---

### `generateNinePatchQuads` (`std/gfx2d/ninepatch2d.aipl`)

- **Signature**: `pub fn generateNinePatchQuads(patch: NinePatch2D, targetBounds: Rect): [BatchVertex2D]:`
- **Import**: `import * from "std/gfx2d/ninepatch2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `patch: NinePatch2D, targetBounds: Rect` | **Returns**: `[BatchVertex2D]`
- **Unit Test**: `tests/functions/gfx2d/ninepatch2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `generateNinePatchQuads` 9-slice UI panel quad generation preserving unscaled corner margins while stretching center/edge regions. Concrete nominal inputs: `patch: NinePatch2D = NinePatch2D(textureId = 1, imageSize = Vec2(x = 1.0, y = 1.0), insets = SliceInsets2D(left = 1.0, top = 1.0, right = 1.0, bottom = 1.0), drawMode = 1)`, `targetBounds: Rect = Rect(x = 1.0, y = 1.0, w = 1.0, h = 1.0)`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.gfx2d.ninepatch2d_z2_test
import * from "std/gfx2d/ninepatch2d"
import { Vec2 } from "std/math/vec_math"
import { Rect } from "std/math/geom2d"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ninepatch2d_generateNinePatchQuads_2(): int:
  let arg_patch = NinePatch2D(textureId = 1, imageSize = Vec2(x = 1.0, y = 1.0), insets = SliceInsets2D(left = 1.0, top = 1.0, right = 2.0, bottom = 1.0), drawMode = 4)
  let edge_patch = NinePatch2D(textureId = 0, imageSize = Vec2(x = 0.5, y = 0.5), insets = SliceInsets2D(left = 0.5, top = 0.5, right = 1.0, bottom = 0.5), drawMode = 1)
  let arg_targetBounds = Rect(x = 1.0, y = 1.0, w = 2.0, h = 2.0)
  let edge_targetBounds = Rect(x = 0.5, y = 0.5, w = 1.0, h = 1.0)
  let resNom = generateNinePatchQuads(arg_patch, arg_targetBounds)
  let resEdge = generateNinePatchQuads(edge_patch, edge_targetBounds)
  assertEqInt(resNom.len(), 36, "generateNinePatchQuads nominal resNom.len() == 36")
  assertEqInt(resEdge.len(), 36, "generateNinePatchQuads boundary resEdge.len() == 36")
  ret 0
```

---

### `packRgbaInt` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `fn packRgbaInt(c: ColorRgba8): int:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: ColorRgba8` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `packRgbaInt` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `c: ColorRgba8 = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255())`; exercises core body path returning/computing `((c.r & 255) << 24) | ((c.g & 255) << 16) | ((c.b & 255) << 8) | (c.a & 255)`.

```aipl
module tests.functions.gfx2d.shape2d_z1_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_packRgbaInt_1(): int:
  let arg_c = ColorRgba8(r = 2, g = 2, b = 4, a = 2)
  let edge_c = ColorRgba8(r = 0, g = 0, b = 1, a = 0)
  let resNom = packRgbaInt(arg_c)
  let resEdge = packRgbaInt(edge_c)
  assertEqInt(resNom, 33686530, "packRgbaInt nominal resNom == 33686530")
  assertEqInt(resEdge, 256, "packRgbaInt boundary resEdge == 256")
  ret 0
```

---

### `buildLineQuads` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn buildLineQuads(p0: Vec2, p1: Vec2, stroke: StrokeStyle2D): [BatchVertex2D]:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p0: Vec2, p1: Vec2, stroke: StrokeStyle2D` | **Returns**: `[BatchVertex2D]`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `buildLineQuads` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `p0: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p1: Vec2 = Vec2(x = 1.0, y = 1.0)`, `stroke: StrokeStyle2D = StrokeStyle2D(width = 0.016667, color = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255()), capStyle = 64, joinStyle = 1)`; exercises core body path returning/computing `[`.

```aipl
module tests.functions.gfx2d.shape2d_z2_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_buildLineQuads_2(): int:
  let arg_p0 = Vec2(x = 1.0, y = 1.0)
  let edge_p0 = Vec2(x = 0.5, y = 0.5)
  let arg_p1 = Vec2(x = 1.0, y = 1.0)
  let edge_p1 = Vec2(x = 0.5, y = 0.5)
  let arg_stroke = StrokeStyle2D(width = 2.0, color = ColorRgba8(r = 2, g = 2, b = 4, a = 2), capStyle = 4, joinStyle = 4)
  let edge_stroke = StrokeStyle2D(width = 1.0, color = ColorRgba8(r = 0, g = 0, b = 1, a = 0), capStyle = 1, joinStyle = 1)
  let resNom = buildLineQuads(arg_p0, arg_p1, arg_stroke)
  let resEdge = buildLineQuads(edge_p0, edge_p1, edge_stroke)
  assertEqInt(resNom.len(), 4, "buildLineQuads nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 4, "buildLineQuads boundary resEdge.len() == 4")
  ret 0
```

---

### `buildCircleTris` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn buildCircleTris(center: Vec2, radius: float, color: ColorRgba8, segments: int = 32): [BatchVertex2D]:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `center: Vec2, radius: float, color: ColorRgba8, segments: int = 32` | **Returns**: `[BatchVertex2D]`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `buildCircleTris` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `center: Vec2 = Vec2(x = 1.0, y = 1.0)`, `radius: float = 1.0`, `color: ColorRgba8 = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255())`, `segments: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.gfx2d.shape2d_z3_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_buildCircleTris_3(): int:
  let arg_center = Vec2(x = 1.0, y = 1.0)
  let edge_center = Vec2(x = 0.5, y = 0.5)
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_color = ColorRgba8(r = 2, g = 2, b = 4, a = 2)
  let edge_color = ColorRgba8(r = 0, g = 0, b = 1, a = 0)
  let arg_segments = 4
  let edge_segments = 1
  let resNom = buildCircleTris(arg_center, arg_radius, arg_color, arg_segments)
  let resEdge = buildCircleTris(edge_center, edge_radius, edge_color, edge_segments)
  assertEqInt(resNom.len(), 12, "buildCircleTris nominal resNom.len() == 12")
  assertEqInt(resEdge.len(), 48, "buildCircleTris boundary resEdge.len() == 48")
  ret 0
```

---

### `buildCapsuleTris` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn buildCapsuleTris(startPt: Vec2, endPt: Vec2, radius: float, color: ColorRgba8, segments: int = 16): [BatchVertex2D]:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `startPt: Vec2, endPt: Vec2, radius: float, color: ColorRgba8, segments: int = 16` | **Returns**: `[BatchVertex2D]`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `buildCapsuleTris` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `startPt: Vec2 = Vec2(x = 1.0, y = 1.0)`, `endPt: Vec2 = Vec2(x = 1.0, y = 1.0)`, `radius: float = 1.0`, `color: ColorRgba8 = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255())`, `segments: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.gfx2d.shape2d_z4_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_buildCapsuleTris_4(): int:
  let arg_startPt = Vec2(x = 1.0, y = 1.0)
  let edge_startPt = Vec2(x = 0.5, y = 0.5)
  let arg_endPt = Vec2(x = 1.0, y = 1.0)
  let edge_endPt = Vec2(x = 0.5, y = 0.5)
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_color = ColorRgba8(r = 2, g = 2, b = 4, a = 2)
  let edge_color = ColorRgba8(r = 0, g = 0, b = 1, a = 0)
  let arg_segments = 4
  let edge_segments = 1
  let resNom = buildCapsuleTris(arg_startPt, arg_endPt, arg_radius, arg_color, arg_segments)
  let resEdge = buildCapsuleTris(edge_startPt, edge_endPt, edge_radius, edge_color, edge_segments)
  assertEqInt(resNom.len(), 16, "buildCapsuleTris nominal resNom.len() == 16")
  assertEqInt(resEdge.len(), 52, "buildCapsuleTris boundary resEdge.len() == 52")
  ret 0
```

---

### `buildCubicBezierPoints` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn buildCubicBezierPoints(p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, subdivisions: int = 32): [Vec2]:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, subdivisions: int = 32` | **Returns**: `[Vec2]`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `buildCubicBezierPoints` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `p0: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p1: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p2: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p3: Vec2 = Vec2(x = 1.0, y = 1.0)`, `subdivisions: int = 1`; exercises core body path returning/computing `pts`.

```aipl
module tests.functions.gfx2d.shape2d_z5_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_buildCubicBezierPoints_5(): int:
  let arg_p0 = Vec2(x = 1.0, y = 1.0)
  let edge_p0 = Vec2(x = 0.5, y = 0.5)
  let arg_p1 = Vec2(x = 1.0, y = 1.0)
  let edge_p1 = Vec2(x = 0.5, y = 0.5)
  let arg_p2 = Vec2(x = 1.0, y = 1.0)
  let edge_p2 = Vec2(x = 0.5, y = 0.5)
  let arg_p3 = Vec2(x = 1.0, y = 1.0)
  let edge_p3 = Vec2(x = 0.5, y = 0.5)
  let arg_subdivisions = 4
  let edge_subdivisions = 1
  let resNom = buildCubicBezierPoints(arg_p0, arg_p1, arg_p2, arg_p3, arg_subdivisions)
  let resEdge = buildCubicBezierPoints(edge_p0, edge_p1, edge_p2, edge_p3, edge_subdivisions)
  assertEqInt(resNom.len(), 5, "buildCubicBezierPoints nominal resNom.len() == 5")
  assertEqInt(resEdge.len(), 17, "buildCubicBezierPoints boundary resEdge.len() == 17")
  ret 0
```

---

### `blendModeMultiplied` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn blendModeMultiplied(): int:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `blendModeMultiplied` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `2`.

```aipl
module tests.functions.gfx2d.shape2d_z6_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_blendModeMultiplied_6(): int:
  let resNom = blendModeMultiplied()
  let resEdge = blendModeMultiplied()
  assertEqInt(resNom, 2, "blendModeMultiplied nominal resNom == 2")
  assertEqInt(resEdge, 2, "blendModeMultiplied boundary resEdge == 2")
  ret 0
```

---

### `blendModeScreen` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn blendModeScreen(): int:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `blendModeScreen` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `3`.

```aipl
module tests.functions.gfx2d.shape2d_z7_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_blendModeScreen_7(): int:
  let resNom = blendModeScreen()
  let resEdge = blendModeScreen()
  assertEqInt(resNom, 3, "blendModeScreen nominal resNom == 3")
  assertEqInt(resEdge, 3, "blendModeScreen boundary resEdge == 3")
  ret 0
```

---

### `rgba` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn rgba(r: int, g: int, b: int, a: float): Color:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `r: int, g: int, b: int, a: float` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `rgba` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `r: int = 1`, `g: int = 1`, `b: int = 1`, `a: float = 1.0`; exercises core body path returning/computing `Color(r = rf, g = gf, b = bf, a = af)`.

```aipl
module tests.functions.gfx2d.shape2d_z8_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_rgba_8(): int:
  let arg_r = 2
  let edge_r = 0
  let arg_g = 2
  let edge_g = 0
  let arg_b = 4
  let edge_b = 1
  let arg_a = 1.0
  let edge_a = 0.5
  let resNom = rgba(arg_r, arg_g, arg_b, arg_a)
  let resEdge = rgba(edge_r, edge_g, edge_b, edge_a)
  assertApproxEq(resNom.r, 0.007843, 0.001, "rgba nominal resNom.r ~= 0.007843")
  assertApproxEq(resEdge.r, 0.0, 0.001, "rgba boundary resEdge.r ~= 0.0")
  ret 0
```

---

### `rgba8Color` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn rgba8Color(r: int, g: int, b: int, a: int): Color:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `r: int, g: int, b: int, a: int` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `rgba8Color` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `r: int = 1`, `g: int = 1`, `b: int = 1`, `a: int = 1`; exercises core body path returning/computing `rgba(r, g, b, float(clampInt(a, 0, 255)) / 255.0)`.

```aipl
module tests.functions.gfx2d.shape2d_z9_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_rgba8Color_9(): int:
  let arg_r = 2
  let edge_r = 0
  let arg_g = 2
  let edge_g = 0
  let arg_b = 4
  let edge_b = 1
  let arg_a = 2
  let edge_a = 0
  let resNom = rgba8Color(arg_r, arg_g, arg_b, arg_a)
  let resEdge = rgba8Color(edge_r, edge_g, edge_b, edge_a)
  assertApproxEq(resNom.r, 0.007843, 0.001, "rgba8Color nominal resNom.r ~= 0.007843")
  assertApproxEq(resEdge.r, 0.0, 0.001, "rgba8Color boundary resEdge.r ~= 0.0")
  ret 0
```

---

### `rgb` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn rgb(r: int, g: int, b: int): Color:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `r: int, g: int, b: int` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `rgb` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `r: int = 1`, `g: int = 1`, `b: int = 1`; exercises core body path returning/computing `rgba(r, g, b, 1.0)`.

```aipl
module tests.functions.gfx2d.shape2d_z10_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_rgb_10(): int:
  let arg_r = 2
  let edge_r = 0
  let arg_g = 2
  let edge_g = 0
  let arg_b = 4
  let edge_b = 1
  let resNom = rgb(arg_r, arg_g, arg_b)
  let resEdge = rgb(edge_r, edge_g, edge_b)
  assertApproxEq(resNom.r, 0.007843, 0.001, "rgb nominal resNom.r ~= 0.007843")
  assertApproxEq(resEdge.r, 0.0, 0.001, "rgb boundary resEdge.r ~= 0.0")
  ret 0
```

---

### `colorHexRgb` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn colorHexRgb(hex: int): Color:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `hex: int` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `colorHexRgb` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `hex: int = 1`; exercises core body path returning/computing `rgb(r, g, b)`.

```aipl
module tests.functions.gfx2d.shape2d_z11_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_colorHexRgb_11(): int:
  let arg_hex = 1
  let edge_hex = 0
  let resNom = colorHexRgb(arg_hex)
  let resEdge = colorHexRgb(edge_hex)
  assertApproxEq(resNom.r, 0.0, 0.001, "colorHexRgb nominal resNom.r ~= 0.0")
  assertApproxEq(resEdge.r, 0.0, 0.001, "colorHexRgb boundary resEdge.r ~= 0.0")
  ret 0
```

---

### `colorHexRgba` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn colorHexRgba(hex: int): Color:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `hex: int` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `colorHexRgba` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `hex: int = 1`; exercises core body path returning/computing `rgba(r, g, b, a)`.

```aipl
module tests.functions.gfx2d.shape2d_z12_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_colorHexRgba_12(): int:
  let arg_hex = 1
  let edge_hex = 0
  let resNom = colorHexRgba(arg_hex)
  let resEdge = colorHexRgba(edge_hex)
  assertApproxEq(resNom.r, 0.0, 0.001, "colorHexRgba nominal resNom.r ~= 0.0")
  assertApproxEq(resEdge.r, 0.0, 0.001, "colorHexRgba boundary resEdge.r ~= 0.0")
  ret 0
```

---

### `colorHex` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn colorHex(hex: int): Color:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `hex: int` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `colorHex` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `hex: int = 1`; exercises core body path returning/computing `colorHexRgb(hex)`.

```aipl
module tests.functions.gfx2d.shape2d_z13_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_colorHex_13(): int:
  let arg_hex = 1
  let edge_hex = 0
  let resNom = colorHex(arg_hex)
  let resEdge = colorHex(edge_hex)
  assertApproxEq(resNom.r, 0.0, 0.001, "colorHex nominal resNom.r ~= 0.0")
  assertApproxEq(resEdge.r, 0.0, 0.001, "colorHex boundary resEdge.r ~= 0.0")
  ret 0
```

---

### `canvasHexDigit` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `fn canvasHexDigit(code: int): int:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `code: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `canvasHexDigit` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `code: int = 1`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.gfx2d.shape2d_z14_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_canvasHexDigit_14(): int:
  let arg_code = 2
  let edge_code = 0
  let resNom = canvasHexDigit(arg_code)
  let resEdge = canvasHexDigit(edge_code)
  assertEqInt(resNom, 0, "canvasHexDigit nominal resNom == 0")
  assertEqInt(resEdge, 0, "canvasHexDigit boundary resEdge == 0")
  ret 0
```

---

### `colorFromHexStr` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn colorFromHexStr(hexStr: str): Color:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `hexStr: str` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `colorFromHexStr` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `hexStr: str = "aipl_test"`; exercises core body path returning/computing `rgb(56, 189, 248)`.

```aipl
module tests.functions.gfx2d.shape2d_z15_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_colorFromHexStr_15(): int:
  let arg_hexStr = "4142"
  let edge_hexStr = "00"
  let resNom = colorFromHexStr(arg_hexStr)
  let resEdge = colorFromHexStr(edge_hexStr)
  assertApproxEq(resNom.r, 0.219608, 0.001, "colorFromHexStr nominal resNom.r ~= 0.219608")
  assertApproxEq(resEdge.r, 0.219608, 0.001, "colorFromHexStr boundary resEdge.r ~= 0.219608")
  ret 0
```

---

### `colorHexStr` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn colorHexStr(hexStr: str): Color:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `hexStr: str` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `colorHexStr` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `hexStr: str = "aipl_test"`; exercises core body path returning/computing `colorFromHexStr(hexStr)`.

```aipl
module tests.functions.gfx2d.shape2d_z16_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_colorHexStr_16(): int:
  let arg_hexStr = "4142"
  let edge_hexStr = "00"
  let resNom = colorHexStr(arg_hexStr)
  let resEdge = colorHexStr(edge_hexStr)
  assertApproxEq(resNom.r, 0.219608, 0.001, "colorHexStr nominal resNom.r ~= 0.219608")
  assertApproxEq(resEdge.r, 0.219608, 0.001, "colorHexStr boundary resEdge.r ~= 0.219608")
  ret 0
```

---

### `packColorRgba32` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn packColorRgba32(c: Color): int:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: Color` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `packColorRgba32` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `c: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `(a << 24) | (r << 16) | (g << 8) | b`.

```aipl
module tests.functions.gfx2d.shape2d_z17_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_packColorRgba32_17(): int:
  let arg_c = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_c = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let resNom = packColorRgba32(arg_c)
  let resEdge = packColorRgba32(edge_c)
  assertEqInt(resNom, 4294967295, "packColorRgba32 nominal resNom == 4294967295")
  assertEqInt(resEdge, 2155905152, "packColorRgba32 boundary resEdge == 2155905152")
  ret 0
```

---

### `colorToInt` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn colorToInt(c: Color): int:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: Color` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `colorToInt` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `c: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `packColorRgba32(c)`.

```aipl
module tests.functions.gfx2d.shape2d_z18_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_colorToInt_18(): int:
  let arg_c = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_c = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let resNom = colorToInt(arg_c)
  let resEdge = colorToInt(edge_c)
  assertEqInt(resNom, 4294967295, "colorToInt nominal resNom == 4294967295")
  assertEqInt(resEdge, 2155905152, "colorToInt boundary resEdge == 2155905152")
  ret 0
```

---

### `pushTransform` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn pushTransform(tx: float, ty: float, rotRad: float, sx: float, sy: float): Transform2D:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `tx: float, ty: float, rotRad: float, sx: float, sy: float` | **Returns**: `Transform2D`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `pushTransform` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `tx: float = 1.0`, `ty: float = 1.0`, `rotRad: float = 1.0`, `sx: float = 1.0`, `sy: float = 1.0`; exercises core body path returning/computing `Transform2D(tx = tx, ty = ty, rotRad = rotRad, sx = sx, sy = sy)`.

```aipl
module tests.functions.gfx2d.shape2d_z19_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_pushTransform_19(): int:
  let arg_tx = 1.0
  let edge_tx = 0.5
  let arg_ty = 1.0
  let edge_ty = 0.5
  let arg_rotRad = 1.0
  let edge_rotRad = 0.5
  let arg_sx = 1.0
  let edge_sx = 0.5
  let arg_sy = 1.0
  let edge_sy = 0.5
  let resNom = pushTransform(arg_tx, arg_ty, arg_rotRad, arg_sx, arg_sy)
  let resEdge = pushTransform(edge_tx, edge_ty, edge_rotRad, edge_sx, edge_sy)
  assertApproxEq(resNom.tx, 1.0, 0.001, "pushTransform nominal resNom.tx ~= 1.0")
  assertApproxEq(resEdge.tx, 0.5, 0.001, "pushTransform boundary resEdge.tx ~= 0.5")
  ret 0
```

---

### `popTransform` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn popTransform(): void:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `popTransform` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z20_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_popTransform_20(): int:
  mut completedCalls = 0
  popTransform()
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "popTransform nominal and boundary void calls completed")
  ret 0
```

---

### `colorRed` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn colorRed(): Color:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `colorRed` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Color(r = 1.0, g = 0.0, b = 0.0, a = 1.0)`.

```aipl
module tests.functions.gfx2d.shape2d_z21_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_colorRed_21(): int:
  let resNom = colorRed()
  let resEdge = colorRed()
  assertApproxEq(resNom.r, 1.0, 0.001, "colorRed nominal resNom.r ~= 1.0")
  assertApproxEq(resEdge.r, 1.0, 0.001, "colorRed boundary resEdge.r ~= 1.0")
  ret 0
```

---

### `colorGreen` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn colorGreen(): Color:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `colorGreen` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Color(r = 0.0, g = 1.0, b = 0.0, a = 1.0)`.

```aipl
module tests.functions.gfx2d.shape2d_z22_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_colorGreen_22(): int:
  let resNom = colorGreen()
  let resEdge = colorGreen()
  assertApproxEq(resNom.r, 0.0, 0.001, "colorGreen nominal resNom.r ~= 0.0")
  assertApproxEq(resEdge.r, 0.0, 0.001, "colorGreen boundary resEdge.r ~= 0.0")
  ret 0
```

---

### `colorBlue` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn colorBlue(): Color:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `colorBlue` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Color(r = 0.0, g = 0.0, b = 1.0, a = 1.0)`.

```aipl
module tests.functions.gfx2d.shape2d_z23_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_colorBlue_23(): int:
  let resNom = colorBlue()
  let resEdge = colorBlue()
  assertApproxEq(resNom.r, 0.0, 0.001, "colorBlue nominal resNom.r ~= 0.0")
  assertApproxEq(resEdge.r, 0.0, 0.001, "colorBlue boundary resEdge.r ~= 0.0")
  ret 0
```

---

### `colorWhite` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn colorWhite(): Color:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `colorWhite` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`.

```aipl
module tests.functions.gfx2d.shape2d_z24_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_colorWhite_24(): int:
  let resNom = colorWhite()
  let resEdge = colorWhite()
  assertApproxEq(resNom.r, 1.0, 0.001, "colorWhite nominal resNom.r ~= 1.0")
  assertApproxEq(resEdge.r, 1.0, 0.001, "colorWhite boundary resEdge.r ~= 1.0")
  ret 0
```

---

### `colorBlack` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn colorBlack(): Color:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `colorBlack` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Color(r = 0.0, g = 0.0, b = 0.0, a = 1.0)`.

```aipl
module tests.functions.gfx2d.shape2d_z25_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_colorBlack_25(): int:
  let resNom = colorBlack()
  let resEdge = colorBlack()
  assertApproxEq(resNom.r, 0.0, 0.001, "colorBlack nominal resNom.r ~= 0.0")
  assertApproxEq(resEdge.r, 0.0, 0.001, "colorBlack boundary resEdge.r ~= 0.0")
  ret 0
```

---

### `colorCyan` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn colorCyan(): Color:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `colorCyan` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Color(r = 0.0, g = 1.0, b = 1.0, a = 1.0)`.

```aipl
module tests.functions.gfx2d.shape2d_z26_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_colorCyan_26(): int:
  let resNom = colorCyan()
  let resEdge = colorCyan()
  assertApproxEq(resNom.r, 0.0, 0.001, "colorCyan nominal resNom.r ~= 0.0")
  assertApproxEq(resEdge.r, 0.0, 0.001, "colorCyan boundary resEdge.r ~= 0.0")
  ret 0
```

---

### `colorYellow` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn colorYellow(): Color:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `colorYellow` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Color(r = 1.0, g = 1.0, b = 0.0, a = 1.0)`.

```aipl
module tests.functions.gfx2d.shape2d_z27_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_colorYellow_27(): int:
  let resNom = colorYellow()
  let resEdge = colorYellow()
  assertApproxEq(resNom.r, 1.0, 0.001, "colorYellow nominal resNom.r ~= 1.0")
  assertApproxEq(resEdge.r, 1.0, 0.001, "colorYellow boundary resEdge.r ~= 1.0")
  ret 0
```

---

### `colorMagenta` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn colorMagenta(): Color:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `colorMagenta` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Color(r = 1.0, g = 0.0, b = 1.0, a = 1.0)`.

```aipl
module tests.functions.gfx2d.shape2d_z28_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_colorMagenta_28(): int:
  let resNom = colorMagenta()
  let resEdge = colorMagenta()
  assertApproxEq(resNom.r, 1.0, 0.001, "colorMagenta nominal resNom.r ~= 1.0")
  assertApproxEq(resEdge.r, 1.0, 0.001, "colorMagenta boundary resEdge.r ~= 1.0")
  ret 0
```

---

### `colorOrange` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn colorOrange(): Color:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `colorOrange` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Color(r = 1.0, g = 0.65, b = 0.0, a = 1.0)`.

```aipl
module tests.functions.gfx2d.shape2d_z29_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_colorOrange_29(): int:
  let resNom = colorOrange()
  let resEdge = colorOrange()
  assertApproxEq(resNom.r, 1.0, 0.001, "colorOrange nominal resNom.r ~= 1.0")
  assertApproxEq(resEdge.r, 1.0, 0.001, "colorOrange boundary resEdge.r ~= 1.0")
  ret 0
```

---

### `colorGray` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn colorGray(): Color:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `colorGray` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Color(r = 0.5, g = 0.5, b = 0.5, a = 1.0)`.

```aipl
module tests.functions.gfx2d.shape2d_z30_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_colorGray_30(): int:
  let resNom = colorGray()
  let resEdge = colorGray()
  assertApproxEq(resNom.r, 0.5, 0.001, "colorGray nominal resNom.r ~= 0.5")
  assertApproxEq(resEdge.r, 0.5, 0.001, "colorGray boundary resEdge.r ~= 0.5")
  ret 0
```

---

### `clearScreen` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn clearScreen(color: Color):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `clearScreen` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `color: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z31_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_clearScreen_31(): int:
  mut completedCalls = 0
  let arg_color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  clearScreen(arg_color)
  clearScreen(edge_color)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "clearScreen nominal and boundary void calls completed")
  ret 0
```

---

### `drawRect` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawRect(x: float, y: float, w: float, h: float, color: Color):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `drawRect` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`, `color: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z32_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawRect_32(): int:
  mut completedCalls = 0
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let arg_color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawRect(arg_x, arg_y, arg_w, arg_h, arg_color)
  drawRect(edge_x, edge_y, edge_w, edge_h, edge_color)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawRect nominal and boundary void calls completed")
  ret 0
```

---

### `drawRectOutline` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawRectOutline(x: float, y: float, w: float, h: float, thickness: float, color: Color):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `drawRectOutline` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`, `thickness: float = 1.0`, `color: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z33_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawRectOutline_33(): int:
  mut completedCalls = 0
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let arg_thickness = 2.0
  let edge_thickness = 1.0
  let arg_color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawRectOutline(arg_x, arg_y, arg_w, arg_h, arg_thickness, arg_color)
  drawRectOutline(edge_x, edge_y, edge_w, edge_h, edge_thickness, edge_color)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawRectOutline nominal and boundary void calls completed")
  ret 0
```

---

### `drawCircle` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawCircle(cx: float, cy: float, radius: float, color: Color):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawCircle` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `cx: float = 1.0`, `cy: float = 1.0`, `radius: float = 1.0`, `color: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z34_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawCircle_34(): int:
  mut completedCalls = 0
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_cy = 1.0
  let edge_cy = 0.5
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawCircle(arg_cx, arg_cy, arg_radius, arg_color)
  drawCircle(edge_cx, edge_cy, edge_radius, edge_color)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawCircle nominal and boundary void calls completed")
  ret 0
```

---

### `drawCircleOutline` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawCircleOutline(cx: float, cy: float, radius: float, thickness: float, color: Color):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `drawCircleOutline` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `cx: float = 1.0`, `cy: float = 1.0`, `radius: float = 1.0`, `thickness: float = 1.0`, `color: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z35_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawCircleOutline_35(): int:
  mut completedCalls = 0
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_cy = 1.0
  let edge_cy = 0.5
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_thickness = 2.0
  let edge_thickness = 1.0
  let arg_color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawCircleOutline(arg_cx, arg_cy, arg_radius, arg_thickness, arg_color)
  drawCircleOutline(edge_cx, edge_cy, edge_radius, edge_thickness, edge_color)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawCircleOutline nominal and boundary void calls completed")
  ret 0
```

---

### `drawLine` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawLine(x1: float, y1: float, x2: float, y2: float, color: Color, thickness: float):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `drawLine` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x1: float = 1.0`, `y1: float = 1.0`, `x2: float = 1.0`, `y2: float = 1.0`, `color: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `thickness: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z36_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawLine_36(): int:
  mut completedCalls = 0
  let arg_x1 = 1.0
  let edge_x1 = 0.5
  let arg_y1 = 1.0
  let edge_y1 = 0.5
  let arg_x2 = 1.0
  let edge_x2 = 0.5
  let arg_y2 = 1.0
  let edge_y2 = 0.5
  let arg_color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_thickness = 2.0
  let edge_thickness = 1.0
  drawLine(arg_x1, arg_y1, arg_x2, arg_y2, arg_color, arg_thickness)
  drawLine(edge_x1, edge_y1, edge_x2, edge_y2, edge_color, edge_thickness)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawLine nominal and boundary void calls completed")
  ret 0
```

---

### `drawTriangle` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawTriangle(x1: float, y1: float, x2: float, y2: float, x3: float, y3: float, color: Color):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawTriangle` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x1: float = 1.0`, `y1: float = 1.0`, `x2: float = 1.0`, `y2: float = 1.0`, `x3: float = 1.0`, `y3: float = 1.0`, `color: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z37_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawTriangle_37(): int:
  mut completedCalls = 0
  let arg_x1 = 1.0
  let edge_x1 = 0.5
  let arg_y1 = 1.0
  let edge_y1 = 0.5
  let arg_x2 = 1.0
  let edge_x2 = 0.5
  let arg_y2 = 1.0
  let edge_y2 = 0.5
  let arg_x3 = 1.0
  let edge_x3 = 0.5
  let arg_y3 = 1.0
  let edge_y3 = 0.5
  let arg_color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawTriangle(arg_x1, arg_y1, arg_x2, arg_y2, arg_x3, arg_y3, arg_color)
  drawTriangle(edge_x1, edge_y1, edge_x2, edge_y2, edge_x3, edge_y3, edge_color)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawTriangle nominal and boundary void calls completed")
  ret 0
```

---

### `drawTriangleOutline` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawTriangleOutline(x1: float, y1: float, x2: float, y2: float, x3: float, y3: float, color: Color):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `drawTriangleOutline` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x1: float = 1.0`, `y1: float = 1.0`, `x2: float = 1.0`, `y2: float = 1.0`, `x3: float = 1.0`, `y3: float = 1.0`, `color: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z38_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawTriangleOutline_38(): int:
  mut completedCalls = 0
  let arg_x1 = 1.0
  let edge_x1 = 0.5
  let arg_y1 = 1.0
  let edge_y1 = 0.5
  let arg_x2 = 1.0
  let edge_x2 = 0.5
  let arg_y2 = 1.0
  let edge_y2 = 0.5
  let arg_x3 = 1.0
  let edge_x3 = 0.5
  let arg_y3 = 1.0
  let edge_y3 = 0.5
  let arg_color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawTriangleOutline(arg_x1, arg_y1, arg_x2, arg_y2, arg_x3, arg_y3, arg_color)
  drawTriangleOutline(edge_x1, edge_y1, edge_x2, edge_y2, edge_x3, edge_y3, edge_color)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawTriangleOutline nominal and boundary void calls completed")
  ret 0
```

---

### `drawTriangleLines` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawTriangleLines(x1: float, y1: float, x2: float, y2: float, x3: float, y3: float, color: Color):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `drawTriangleLines` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x1: float = 1.0`, `y1: float = 1.0`, `x2: float = 1.0`, `y2: float = 1.0`, `x3: float = 1.0`, `y3: float = 1.0`, `color: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z39_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawTriangleLines_39(): int:
  mut completedCalls = 0
  let arg_x1 = 1.0
  let edge_x1 = 0.5
  let arg_y1 = 1.0
  let edge_y1 = 0.5
  let arg_x2 = 1.0
  let edge_x2 = 0.5
  let arg_y2 = 1.0
  let edge_y2 = 0.5
  let arg_x3 = 1.0
  let edge_x3 = 0.5
  let arg_y3 = 1.0
  let edge_y3 = 0.5
  let arg_color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawTriangleLines(arg_x1, arg_y1, arg_x2, arg_y2, arg_x3, arg_y3, arg_color)
  drawTriangleLines(edge_x1, edge_y1, edge_x2, edge_y2, edge_x3, edge_y3, edge_color)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawTriangleLines nominal and boundary void calls completed")
  ret 0
```

---

### `drawEllipse` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawEllipse(cx: float, cy: float, rx: float, ry: float, color: Color):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawEllipse` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `cx: float = 1.0`, `cy: float = 1.0`, `rx: float = 1.0`, `ry: float = 1.0`, `color: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z40_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawEllipse_40(): int:
  mut completedCalls = 0
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_cy = 1.0
  let edge_cy = 0.5
  let arg_rx = 1.0
  let edge_rx = 0.5
  let arg_ry = 1.0
  let edge_ry = 0.5
  let arg_color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawEllipse(arg_cx, arg_cy, arg_rx, arg_ry, arg_color)
  drawEllipse(edge_cx, edge_cy, edge_rx, edge_ry, edge_color)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawEllipse nominal and boundary void calls completed")
  ret 0
```

---

### `drawRegularPolygon` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawRegularPolygon(cx: float, cy: float, radius: float, sides: int, color: Color):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `drawRegularPolygon` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `cx: float = 1.0`, `cy: float = 1.0`, `radius: float = 1.0`, `sides: int = 1`, `color: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z41_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawRegularPolygon_41(): int:
  mut completedCalls = 0
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_cy = 1.0
  let edge_cy = 0.5
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_sides = 1
  let edge_sides = 0
  let arg_color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawRegularPolygon(arg_cx, arg_cy, arg_radius, arg_sides, arg_color)
  drawRegularPolygon(edge_cx, edge_cy, edge_radius, edge_sides, edge_color)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawRegularPolygon nominal and boundary void calls completed")
  ret 0
```

---

### `drawPolygon` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawPolygon(points: [float], color: Color):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `drawPolygon` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `points: [float] = [1.0]`, `color: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z42_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawPolygon_42(): int:
  mut completedCalls = 0
  let arg_points = [1.0]
  let edge_points = []
  let arg_color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawPolygon(arg_points, arg_color)
  drawPolygon(edge_points, edge_color)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawPolygon nominal and boundary void calls completed")
  ret 0
```

---

### `drawText` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawText(text: str, x: float, y: float, size: float, color: Color):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawText` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `text: str = "aipl_test"`, `x: float = 1.0`, `y: float = 1.0`, `size: float = 1.0`, `color: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z43_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawText_43(): int:
  mut completedCalls = 0
  let arg_text = "test"
  let edge_text = "a"
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_size = 1.0
  let edge_size = 0.5
  let arg_color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawText(arg_text, arg_x, arg_y, arg_size, arg_color)
  drawText(edge_text, edge_x, edge_y, edge_size, edge_color)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawText nominal and boundary void calls completed")
  ret 0
```

---

### `measureTextWidthPx` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn measureTextWidthPx(text: str, size: float): float:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str, size: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `measureTextWidthPx` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `text: str = "aipl_test"`, `size: float = 1.0`; exercises core body path returning/computing `float(text.len) * maxFloat(1.0, size) * 0.6`.

```aipl
module tests.functions.gfx2d.shape2d_z44_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_measureTextWidthPx_44(): int:
  let arg_text = "test"
  let edge_text = "a"
  let arg_size = 1.0
  let edge_size = 0.5
  let resNom = measureTextWidthPx(arg_text, arg_size)
  let resEdge = measureTextWidthPx(edge_text, edge_size)
  assertApproxEq(resNom, 2.4, 0.001, "measureTextWidthPx nominal resNom ~= 2.4")
  assertApproxEq(resEdge, 0.6, 0.001, "measureTextWidthPx boundary resEdge ~= 0.6")
  ret 0
```

---

### `measureTextHeight` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn measureTextHeight(text: str, size: float): float:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str, size: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `measureTextHeight` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `text: str = "aipl_test"`, `size: float = 1.0`; exercises core body path returning/computing `if text.len > 0: maxFloat(8.0, size * 1.2) else: 0.0`.

```aipl
module tests.functions.gfx2d.shape2d_z45_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_measureTextHeight_45(): int:
  let arg_text = "test"
  let edge_text = "a"
  let arg_size = 1.0
  let edge_size = 0.5
  let resNom = measureTextHeight(arg_text, arg_size)
  let resEdge = measureTextHeight(edge_text, edge_size)
  assertApproxEq(resNom, 13.0, 0.001, "measureTextHeight nominal resNom ~= 13.0")
  assertApproxEq(resEdge, 9.0, 0.001, "measureTextHeight boundary resEdge ~= 9.0")
  ret 0
```

---

### `measureText` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn measureText(text: str, size: float): Vec2:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str, size: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `measureText` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `text: str = "aipl_test"`, `size: float = 1.0`; exercises core body path returning/computing `Vec2(x = measureTextWidthPx(text, size), y = measureTextHeight(text, size))`.

```aipl
module tests.functions.gfx2d.shape2d_z46_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_measureText_46(): int:
  let arg_text = "test"
  let edge_text = "a"
  let arg_size = 1.0
  let edge_size = 0.5
  let resNom = measureText(arg_text, arg_size)
  let resEdge = measureText(edge_text, edge_size)
  assertApproxEq(resNom.x, 25.0, 0.001, "measureText nominal resNom.x ~= 25.0")
  assertApproxEq(resEdge.x, 6.0, 0.001, "measureText boundary resEdge.x ~= 6.0")
  ret 0
```

---

### `truncateText` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn truncateText(text: str, maxWidth: float, size: float): str:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: str, maxWidth: float, size: float` | **Returns**: `str`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `truncateText` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `text: str = "aipl_test"`, `maxWidth: float = 0.016667`, `size: float = 1.0`; exercises core body path returning/computing `text.slice(0, maxChars)`.

```aipl
module tests.functions.gfx2d.shape2d_z47_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_truncateText_47(): int:
  let arg_text = "test"
  let edge_text = "a"
  let arg_maxWidth = 2.0
  let edge_maxWidth = 1.0
  let arg_size = 1.0
  let edge_size = 0.5
  let resNom = truncateText(arg_text, arg_maxWidth, arg_size)
  let resEdge = truncateText(edge_text, edge_maxWidth, edge_size)
  assertEqStr(resNom, "test", "truncateText nominal string matches")
  assertEqStr(resEdge, "a", "truncateText boundary string matches")
  ret 0
```

---

### `drawTextBox` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawTextBox(text: str, x: float, y: float, maxWidth: float, size: float, color: Color):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `drawTextBox` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `text: str = "aipl_test"`, `x: float = 1.0`, `y: float = 1.0`, `maxWidth: float = 0.016667`, `size: float = 1.0`, `color: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z48_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawTextBox_48(): int:
  mut completedCalls = 0
  let arg_text = "test"
  let edge_text = "a"
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_maxWidth = 2.0
  let edge_maxWidth = 1.0
  let arg_size = 1.0
  let edge_size = 0.5
  let arg_color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawTextBox(arg_text, arg_x, arg_y, arg_maxWidth, arg_size, arg_color)
  drawTextBox(edge_text, edge_x, edge_y, edge_maxWidth, edge_size, edge_color)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawTextBox nominal and boundary void calls completed")
  ret 0
```

---

### `drawTextCentered` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawTextCentered(text: str, cx: float, y: float, size: float, color: Color):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawTextCentered` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `text: str = "aipl_test"`, `cx: float = 1.0`, `y: float = 1.0`, `size: float = 1.0`, `color: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z49_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawTextCentered_49(): int:
  mut completedCalls = 0
  let arg_text = "test"
  let edge_text = "a"
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_size = 1.0
  let edge_size = 0.5
  let arg_color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawTextCentered(arg_text, arg_cx, arg_y, arg_size, arg_color)
  drawTextCentered(edge_text, edge_cx, edge_y, edge_size, edge_color)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawTextCentered nominal and boundary void calls completed")
  ret 0
```

---

### `drawTextRight` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawTextRight(text: str, rightX: float, y: float, size: float, color: Color):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `drawTextRight` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `text: str = "aipl_test"`, `rightX: float = 1.0`, `y: float = 1.0`, `size: float = 1.0`, `color: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z50_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawTextRight_50(): int:
  mut completedCalls = 0
  let arg_text = "test"
  let edge_text = "a"
  let arg_rightX = 2.0
  let edge_rightX = 1.0
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_size = 1.0
  let edge_size = 0.5
  let arg_color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawTextRight(arg_text, arg_rightX, arg_y, arg_size, arg_color)
  drawTextRight(edge_text, edge_rightX, edge_y, edge_size, edge_color)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawTextRight nominal and boundary void calls completed")
  ret 0
```

---

### `isKeyPressed` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn isKeyPressed(key: str): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `key: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `isKeyPressed` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `key: str = "aipl_test"`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.gfx2d.shape2d_z51_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_isKeyPressed_51(): int:
  let arg_key = "test"
  let edge_key = "a"
  let resNom = isKeyPressed(arg_key)
  let resEdge = isKeyPressed(edge_key)
  assert(resNom == false, "isKeyPressed nominal resNom == false")
  assert(resEdge == false, "isKeyPressed boundary resEdge == false")
  ret 0
```

---

### `isKeyReleased` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn isKeyReleased(key: str): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `key: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `isKeyReleased` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `key: str = "aipl_test"`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.gfx2d.shape2d_z52_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_isKeyReleased_52(): int:
  let arg_key = "test"
  let edge_key = "a"
  let resNom = isKeyReleased(arg_key)
  let resEdge = isKeyReleased(edge_key)
  assert(resNom == false, "isKeyReleased nominal resNom == false")
  assert(resEdge == false, "isKeyReleased boundary resEdge == false")
  ret 0
```

---

### `getMouseX` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn getMouseX(): float:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `getMouseX` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `0.0`.

```aipl
module tests.functions.gfx2d.shape2d_z53_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_getMouseX_53(): int:
  let resNom = getMouseX()
  let resEdge = getMouseX()
  assertApproxEq(resNom, 0.0, 0.001, "getMouseX nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "getMouseX boundary resEdge ~= 0.0")
  ret 0
```

---

### `getMouseY` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn getMouseY(): float:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `getMouseY` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `0.0`.

```aipl
module tests.functions.gfx2d.shape2d_z54_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_getMouseY_54(): int:
  let resNom = getMouseY()
  let resEdge = getMouseY()
  assertApproxEq(resNom, 0.0, 0.001, "getMouseY nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "getMouseY boundary resEdge ~= 0.0")
  ret 0
```

---

### `isMouseButtonPressed` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn isMouseButtonPressed(button: int): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `button: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `isMouseButtonPressed` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `button: int = 1`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.gfx2d.shape2d_z55_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_isMouseButtonPressed_55(): int:
  let arg_button = 4
  let edge_button = 1
  let resNom = isMouseButtonPressed(arg_button)
  let resEdge = isMouseButtonPressed(edge_button)
  assert(resNom == false, "isMouseButtonPressed nominal resNom == false")
  assert(resEdge == false, "isMouseButtonPressed boundary resEdge == false")
  ret 0
```

---

### `isMouseButtonReleased` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn isMouseButtonReleased(button: int): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `button: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `isMouseButtonReleased` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `button: int = 1`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.gfx2d.shape2d_z56_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_isMouseButtonReleased_56(): int:
  let arg_button = 4
  let edge_button = 1
  let resNom = isMouseButtonReleased(arg_button)
  let resEdge = isMouseButtonReleased(edge_button)
  assert(resNom == false, "isMouseButtonReleased nominal resNom == false")
  assert(resEdge == false, "isMouseButtonReleased boundary resEdge == false")
  ret 0
```

---

### `isMouseInRect` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn isMouseInRect(x: float, y: float, w: float, h: float): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float, w: float, h: float` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `isMouseInRect` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.gfx2d.shape2d_z57_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_isMouseInRect_57(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let resNom = isMouseInRect(arg_x, arg_y, arg_w, arg_h)
  let resEdge = isMouseInRect(edge_x, edge_y, edge_w, edge_h)
  assert(resNom == false, "isMouseInRect nominal resNom == false")
  assert(resEdge == false, "isMouseInRect boundary resEdge == false")
  ret 0
```

---

### `isRectClicked` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn isRectClicked(x: float, y: float, w: float, h: float): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float, w: float, h: float` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `isRectClicked` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.gfx2d.shape2d_z58_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_isRectClicked_58(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let resNom = isRectClicked(arg_x, arg_y, arg_w, arg_h)
  let resEdge = isRectClicked(edge_x, edge_y, edge_w, edge_h)
  assert(resNom == false, "isRectClicked nominal resNom == false")
  assert(resEdge == false, "isRectClicked boundary resEdge == false")
  ret 0
```

---

### `getTextInput` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn getTextInput(): str:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `str`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `getTextInput` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `""`.

```aipl
module tests.functions.gfx2d.shape2d_z59_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_getTextInput_59(): int:
  let resNom = getTextInput()
  let resEdge = getTextInput()
  assertEqStr(resNom, "", "getTextInput nominal string matches")
  assertEqStr(resEdge, "", "getTextInput boundary string matches")
  ret 0
```

---

### `injectTextInput` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn injectTextInput(s: str):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `injectTextInput` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z60_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_injectTextInput_60(): int:
  mut completedCalls = 0
  let arg_s = "test"
  let edge_s = "a"
  injectTextInput(arg_s)
  injectTextInput(edge_s)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "injectTextInput nominal and boundary void calls completed")
  ret 0
```

---

### `getCompositionText` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn getCompositionText(): str:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `str`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `getCompositionText` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `""`.

```aipl
module tests.functions.gfx2d.shape2d_z61_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_getCompositionText_61(): int:
  let resNom = getCompositionText()
  let resEdge = getCompositionText()
  assertEqStr(resNom, "", "getCompositionText nominal string matches")
  assertEqStr(resEdge, "", "getCompositionText boundary string matches")
  ret 0
```

---

### `getCompositionCursor` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn getCompositionCursor(): int:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `getCompositionCursor` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `0`.

```aipl
module tests.functions.gfx2d.shape2d_z62_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_getCompositionCursor_62(): int:
  let resNom = getCompositionCursor()
  let resEdge = getCompositionCursor()
  assertEqInt(resNom, 0, "getCompositionCursor nominal resNom == 0")
  assertEqInt(resEdge, 0, "getCompositionCursor boundary resEdge == 0")
  ret 0
```

---

### `isKeyHeld` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn isKeyHeld(keyCode: int): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `keyCode: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `isKeyHeld` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `keyCode: int = 1`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.gfx2d.shape2d_z63_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_isKeyHeld_63(): int:
  let arg_keyCode = 4
  let edge_keyCode = 1
  let resNom = isKeyHeld(arg_keyCode)
  let resEdge = isKeyHeld(edge_keyCode)
  assert(resNom == false, "isKeyHeld nominal resNom == false")
  assert(resEdge == false, "isKeyHeld boundary resEdge == false")
  ret 0
```

---

### `mouseWheelX` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn mouseWheelX(): float:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `mouseWheelX` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `0.0`.

```aipl
module tests.functions.gfx2d.shape2d_z64_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_mouseWheelX_64(): int:
  let resNom = mouseWheelX()
  let resEdge = mouseWheelX()
  assertApproxEq(resNom, 0.0, 0.001, "mouseWheelX nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "mouseWheelX boundary resEdge ~= 0.0")
  ret 0
```

---

### `mouseWheelY` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn mouseWheelY(): float:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `mouseWheelY` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `0.0`.

```aipl
module tests.functions.gfx2d.shape2d_z65_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_mouseWheelY_65(): int:
  let resNom = mouseWheelY()
  let resEdge = mouseWheelY()
  assertApproxEq(resNom, 0.0, 0.001, "mouseWheelY nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "mouseWheelY boundary resEdge ~= 0.0")
  ret 0
```

---

### `isMouseDoubleClicked` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn isMouseDoubleClicked(): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `isMouseDoubleClicked` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `false`.

```aipl
module tests.functions.gfx2d.shape2d_z66_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_isMouseDoubleClicked_66(): int:
  let resNom = isMouseDoubleClicked()
  let resEdge = isMouseDoubleClicked()
  assert(resNom == false, "isMouseDoubleClicked nominal resNom == false")
  assert(resEdge == false, "isMouseDoubleClicked boundary resEdge == false")
  ret 0
```

---

### `isMouseRightClicked` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn isMouseRightClicked(): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `isMouseRightClicked` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `false`.

```aipl
module tests.functions.gfx2d.shape2d_z67_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_isMouseRightClicked_67(): int:
  let resNom = isMouseRightClicked()
  let resEdge = isMouseRightClicked()
  assert(resNom == false, "isMouseRightClicked nominal resNom == false")
  assert(resEdge == false, "isMouseRightClicked boundary resEdge == false")
  ret 0
```

---

### `pollPointerEvents` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn pollPointerEvents(): [PointerEvent]:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `[PointerEvent]`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `pollPointerEvents` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `[]`.

```aipl
module tests.functions.gfx2d.shape2d_z68_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_pollPointerEvents_68(): int:
  let resNom = pollPointerEvents()
  let resEdge = pollPointerEvents()
  assertEqInt(resNom.len(), 0, "pollPointerEvents nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "pollPointerEvents boundary resEdge.len() == 0")
  ret 0
```

---

### `loadImage` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn loadImage(path: str): Result[int, str]:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `path: str` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `loadImage` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `Err("native loadImage builtin")`.

```aipl
module tests.functions.gfx2d.shape2d_z69_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_loadImage_69(): int:
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = loadImage(arg_path)
  let resEdge = loadImage(edge_path)
  assert(resNom.isOk() == false, "loadImage nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "loadImage boundary resEdge.isOk() == false")
  ret 0
```

---

### `decodeImage` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn decodeImage(data: bytes): Result[int, str]:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `decodeImage` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `Err("native decodeImage builtin")`.

```aipl
module tests.functions.gfx2d.shape2d_z70_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_decodeImage_70(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = decodeImage(arg_data)
  let resEdge = decodeImage(edge_data)
  assert(resNom.isOk() == true, "decodeImage nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "decodeImage boundary resEdge.isOk() == true")
  ret 0
```

---

### `imageWidth` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn imageWidth(imgId: int): int:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `imgId: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `imageWidth` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `imgId: int = 1`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.gfx2d.shape2d_z71_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_imageWidth_71(): int:
  let arg_imgId = 4
  let edge_imgId = 1
  let resNom = imageWidth(arg_imgId)
  let resEdge = imageWidth(edge_imgId)
  assertEqInt(resNom, 0, "imageWidth nominal resNom == 0")
  assertEqInt(resEdge, 64, "imageWidth boundary resEdge == 64")
  ret 0
```

---

### `imageHeight` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn imageHeight(imgId: int): int:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `imgId: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `imageHeight` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `imgId: int = 1`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.gfx2d.shape2d_z72_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_imageHeight_72(): int:
  let arg_imgId = 4
  let edge_imgId = 1
  let resNom = imageHeight(arg_imgId)
  let resEdge = imageHeight(edge_imgId)
  assertEqInt(resNom, 0, "imageHeight nominal resNom == 0")
  assertEqInt(resEdge, 64, "imageHeight boundary resEdge == 64")
  ret 0
```

---

### `getImageWidth` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn getImageWidth(imgId: int): int:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `imgId: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `getImageWidth` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `imgId: int = 1`; exercises core body path returning/computing `imageWidth(imgId)`.

```aipl
module tests.functions.gfx2d.shape2d_z73_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_getImageWidth_73(): int:
  let arg_imgId = 4
  let edge_imgId = 1
  let resNom = getImageWidth(arg_imgId)
  let resEdge = getImageWidth(edge_imgId)
  assertEqInt(resNom, 0, "getImageWidth nominal resNom == 0")
  assertEqInt(resEdge, 64, "getImageWidth boundary resEdge == 64")
  ret 0
```

---

### `getImageHeight` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn getImageHeight(imgId: int): int:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `imgId: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `getImageHeight` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `imgId: int = 1`; exercises core body path returning/computing `imageHeight(imgId)`.

```aipl
module tests.functions.gfx2d.shape2d_z74_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_getImageHeight_74(): int:
  let arg_imgId = 4
  let edge_imgId = 1
  let resNom = getImageHeight(arg_imgId)
  let resEdge = getImageHeight(edge_imgId)
  assertEqInt(resNom, 0, "getImageHeight nominal resNom == 0")
  assertEqInt(resEdge, 64, "getImageHeight boundary resEdge == 64")
  ret 0
```

---

### `unloadImage` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn unloadImage(imgId: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `unloadImage` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `imgId: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z75_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_unloadImage_75(): int:
  mut completedCalls = 0
  let arg_imgId = 4
  let edge_imgId = 1
  unloadImage(arg_imgId)
  unloadImage(edge_imgId)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "unloadImage nominal and boundary void calls completed")
  ret 0
```

---

### `drawImage` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawImage(imgId: int, x: float, y: float):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawImage` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `imgId: int = 1`, `x: float = 1.0`, `y: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z76_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawImage_76(): int:
  mut completedCalls = 0
  let arg_imgId = 4
  let edge_imgId = 1
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  drawImage(arg_imgId, arg_x, arg_y)
  drawImage(edge_imgId, edge_x, edge_y)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawImage nominal and boundary void calls completed")
  ret 0
```

---

### `drawImageScaled` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawImageScaled(imgId: int, x: float, y: float, w: float, h: float):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `drawImageScaled` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `imgId: int = 1`, `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z77_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawImageScaled_77(): int:
  mut completedCalls = 0
  let arg_imgId = 4
  let edge_imgId = 1
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  drawImageScaled(arg_imgId, arg_x, arg_y, arg_w, arg_h)
  drawImageScaled(edge_imgId, edge_x, edge_y, edge_w, edge_h)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawImageScaled nominal and boundary void calls completed")
  ret 0
```

---

### `drawSubImage` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawSubImage(imgId: int, sx: float, sy: float, sw: float, sh: float, dx: float, dy: float, dw: float, dh: float):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `drawSubImage` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `imgId: int = 1`, `sx: float = 1.0`, `sy: float = 1.0`, `sw: float = 1.0`, `sh: float = 1.0`, `dx: float = 1.0`, `dy: float = 1.0`, `dw: float = 1.0`, `dh: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z78_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawSubImage_78(): int:
  mut completedCalls = 0
  let arg_imgId = 4
  let edge_imgId = 1
  let arg_sx = 1.0
  let edge_sx = 0.5
  let arg_sy = 1.0
  let edge_sy = 0.5
  let arg_sw = 2.0
  let edge_sw = 1.0
  let arg_sh = 2.0
  let edge_sh = 1.0
  let arg_dx = 1.0
  let edge_dx = 0.5
  let arg_dy = 1.0
  let edge_dy = 0.5
  let arg_dw = 2.0
  let edge_dw = 1.0
  let arg_dh = 2.0
  let edge_dh = 1.0
  drawSubImage(arg_imgId, arg_sx, arg_sy, arg_sw, arg_sh, arg_dx, arg_dy, arg_dw, arg_dh)
  drawSubImage(edge_imgId, edge_sx, edge_sy, edge_sw, edge_sh, edge_dx, edge_dy, edge_dw, edge_dh)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawSubImage nominal and boundary void calls completed")
  ret 0
```

---

### `drawImageSub` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawImageSub(imgId: int, sx: float, sy: float, sw: float, sh: float, dx: float, dy: float, dw: float, dh: float):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawImageSub` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `imgId: int = 1`, `sx: float = 1.0`, `sy: float = 1.0`, `sw: float = 1.0`, `sh: float = 1.0`, `dx: float = 1.0`, `dy: float = 1.0`, `dw: float = 1.0`, `dh: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z79_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawImageSub_79(): int:
  mut completedCalls = 0
  let arg_imgId = 4
  let edge_imgId = 1
  let arg_sx = 1.0
  let edge_sx = 0.5
  let arg_sy = 1.0
  let edge_sy = 0.5
  let arg_sw = 2.0
  let edge_sw = 1.0
  let arg_sh = 2.0
  let edge_sh = 1.0
  let arg_dx = 1.0
  let edge_dx = 0.5
  let arg_dy = 1.0
  let edge_dy = 0.5
  let arg_dw = 2.0
  let edge_dw = 1.0
  let arg_dh = 2.0
  let edge_dh = 1.0
  drawImageSub(arg_imgId, arg_sx, arg_sy, arg_sw, arg_sh, arg_dx, arg_dy, arg_dw, arg_dh)
  drawImageSub(edge_imgId, edge_sx, edge_sy, edge_sw, edge_sh, edge_dx, edge_dy, edge_dw, edge_dh)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawImageSub nominal and boundary void calls completed")
  ret 0
```

---

### `drawImageEx` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawImageEx(imgId: int, x: float, y: float, w: float, h: float, rotRad: float, originX: float, originY: float, tintColor: int, flipX: bool, flipY: bool):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `drawImageEx` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `imgId: int = 1`, `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`, `rotRad: float = 1.0`, `originX: float = 1.0`, `originY: float = 1.0`, `tintColor: int = 1`, `flipX: bool = true`, `flipY: bool = true`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z80_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawImageEx_80(): int:
  mut completedCalls = 0
  let arg_imgId = 4
  let edge_imgId = 1
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let arg_rotRad = 1.0
  let edge_rotRad = 0.5
  let arg_originX = 1.0
  let edge_originX = 0.5
  let arg_originY = 1.0
  let edge_originY = 0.5
  let arg_tintColor = 4
  let edge_tintColor = 1
  let arg_flipX = true
  let edge_flipX = false
  let arg_flipY = true
  let edge_flipY = false
  drawImageEx(arg_imgId, arg_x, arg_y, arg_w, arg_h, arg_rotRad, arg_originX, arg_originY, arg_tintColor, arg_flipX, arg_flipY)
  drawImageEx(edge_imgId, edge_x, edge_y, edge_w, edge_h, edge_rotRad, edge_originX, edge_originY, edge_tintColor, edge_flipX, edge_flipY)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawImageEx nominal and boundary void calls completed")
  ret 0
```

---

### `saveImage` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn saveImage(imgId: int, path: str): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `imgId: int, path: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `saveImage` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `imgId: int = 1`, `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.gfx2d.shape2d_z81_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_saveImage_81(): int:
  let arg_imgId = 4
  let edge_imgId = 1
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = saveImage(arg_imgId, arg_path)
  let resEdge = saveImage(edge_imgId, edge_path)
  assert(resNom == false, "saveImage nominal resNom == false")
  assert(resEdge == false, "saveImage boundary resEdge == false")
  ret 0
```

---

### `saveScreenshot` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn saveScreenshot(path: str): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `path: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `saveScreenshot` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.gfx2d.shape2d_z82_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_saveScreenshot_82(): int:
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = saveScreenshot(arg_path)
  let resEdge = saveScreenshot(edge_path)
  assert(resNom == false, "saveScreenshot nominal resNom == false")
  assert(resEdge == false, "saveScreenshot boundary resEdge == false")
  ret 0
```

---

### `startVideoRecording` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn startVideoRecording(path: str, fps: int): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `path: str, fps: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `startVideoRecording` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `path: str = "/tmp/aipl_test_artifact.tmp"`, `fps: int = 1`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.gfx2d.shape2d_z83_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_startVideoRecording_83(): int:
  let arg_path = "/tmp/aipl_test_vid.mp4"
  let edge_path = ""
  let arg_fps = 24
  let edge_fps = 0
  let resNom = startVideoRecording(arg_path, arg_fps)
  let resEdge = startVideoRecording(edge_path, edge_fps)
  stopVideoRecording()
  assert(resNom == true, "startVideoRecording nominal resNom == true")
  assert(resEdge == true, "startVideoRecording boundary resEdge == true")
  ret 0
```

---

### `recordVideoFrame` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn recordVideoFrame(): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `recordVideoFrame` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `true`.

```aipl
module tests.functions.gfx2d.shape2d_z84_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_recordVideoFrame_84(): int:
  let resNom = recordVideoFrame()
  let resEdge = recordVideoFrame()
  assertEqStr(str(resNom), "nil", "recordVideoFrame nominal str(resNom) == nil")
  assertEqStr(str(resEdge), "nil", "recordVideoFrame boundary str(resEdge) == nil")
  ret 0
```

---

### `stopVideoRecording` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn stopVideoRecording(): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `stopVideoRecording` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `true`.

```aipl
module tests.functions.gfx2d.shape2d_z85_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_stopVideoRecording_85(): int:
  let resNom = stopVideoRecording()
  let resEdge = stopVideoRecording()
  assert(resNom == false, "stopVideoRecording nominal resNom == false")
  assert(resEdge == false, "stopVideoRecording boundary resEdge == false")
  ret 0
```

---

### `isRecordingVideo` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn isRecordingVideo(): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `isRecordingVideo` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `false`.

```aipl
module tests.functions.gfx2d.shape2d_z86_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_isRecordingVideo_86(): int:
  let resNom = isRecordingVideo()
  let resEdge = isRecordingVideo()
  assert(resNom == false, "isRecordingVideo nominal resNom == false")
  assert(resEdge == false, "isRecordingVideo boundary resEdge == false")
  ret 0
```

---

### `createImageFromPixels` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn createImageFromPixels(width: int, height: int, rgbaPixels: [int]): int:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `width: int, height: int, rgbaPixels: [int]` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `createImageFromPixels` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `width: int = 128`, `height: int = 128`, `rgbaPixels: [int] = [1]`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.gfx2d.shape2d_z87_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_createImageFromPixels_87(): int:
  let arg_width = 4
  let edge_width = 1
  let arg_height = 4
  let edge_height = 1
  let arg_rgbaPixels = [4]
  let edge_rgbaPixels = []
  let resNom = createImageFromPixels(arg_width, arg_height, arg_rgbaPixels)
  let resEdge = createImageFromPixels(edge_width, edge_height, edge_rgbaPixels)
  assertEqInt(resNom, 100, "createImageFromPixels nominal resNom == 100")
  assertEqInt(resEdge, 101, "createImageFromPixels boundary resEdge == 101")
  ret 0
```

---

### `readCanvasPixel` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn readCanvasPixel(x: int, y: int): int:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: int, y: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `readCanvasPixel` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x: int = 1`, `y: int = 1`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.gfx2d.shape2d_z88_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_readCanvasPixel_88(): int:
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let resNom = readCanvasPixel(arg_x, arg_y)
  let resEdge = readCanvasPixel(edge_x, edge_y)
  assertEqStr(str(resNom), "<struct Color>", "readCanvasPixel nominal returns Color struct")
  assertEqStr(str(resEdge), "<struct Color>", "readCanvasPixel boundary returns Color struct")
  ret 0
```

---

### `getScreenWidth` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn getScreenWidth(): int:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `getScreenWidth` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `800`.

```aipl
module tests.functions.gfx2d.shape2d_z89_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_getScreenWidth_89(): int:
  let resNom = getScreenWidth()
  let resEdge = getScreenWidth()
  assertEqInt(resNom, 800, "getScreenWidth nominal resNom == 800")
  assertEqInt(resEdge, 800, "getScreenWidth boundary resEdge == 800")
  ret 0
```

---

### `getScreenHeight` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn getScreenHeight(): int:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `getScreenHeight` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `600`.

```aipl
module tests.functions.gfx2d.shape2d_z90_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_getScreenHeight_90(): int:
  let resNom = getScreenHeight()
  let resEdge = getScreenHeight()
  assertEqInt(resNom, 600, "getScreenHeight nominal resNom == 600")
  assertEqInt(resEdge, 600, "getScreenHeight boundary resEdge == 600")
  ret 0
```

---

### `getWindowWidth` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn getWindowWidth(): int:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `getWindowWidth` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `getScreenWidth()`.

```aipl
module tests.functions.gfx2d.shape2d_z91_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_getWindowWidth_91(): int:
  let resNom = getWindowWidth()
  let resEdge = getWindowWidth()
  assertEqInt(resNom, 800, "getWindowWidth nominal resNom == 800")
  assertEqInt(resEdge, 800, "getWindowWidth boundary resEdge == 800")
  ret 0
```

---

### `getWindowHeight` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn getWindowHeight(): int:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `getWindowHeight` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `getScreenHeight()`.

```aipl
module tests.functions.gfx2d.shape2d_z92_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_getWindowHeight_92(): int:
  let resNom = getWindowHeight()
  let resEdge = getWindowHeight()
  assertEqInt(resNom, 600, "getWindowHeight nominal resNom == 600")
  assertEqInt(resEdge, 600, "getWindowHeight boundary resEdge == 600")
  ret 0
```

---

### `isWindowResized` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn isWindowResized(): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `isWindowResized` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `false`.

```aipl
module tests.functions.gfx2d.shape2d_z93_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_isWindowResized_93(): int:
  let resNom = isWindowResized()
  let resEdge = isWindowResized()
  assert(resNom == false, "isWindowResized nominal resNom == false")
  assert(resEdge == false, "isWindowResized boundary resEdge == false")
  ret 0
```

---

### `setWindowMinSize` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn setWindowMinSize(w: int, h: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `setWindowMinSize` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `w: int = 128`, `h: int = 128`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z94_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_setWindowMinSize_94(): int:
  mut completedCalls = 0
  let arg_w = 2
  let edge_w = 0
  let arg_h = 2
  let edge_h = 0
  setWindowMinSize(arg_w, arg_h)
  setWindowMinSize(edge_w, edge_h)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "setWindowMinSize nominal and boundary void calls completed")
  ret 0
```

---

### `getScaleFactor` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn getScaleFactor(): float:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `getScaleFactor` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `1.0`.

```aipl
module tests.functions.gfx2d.shape2d_z95_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_getScaleFactor_95(): int:
  let resNom = getScaleFactor()
  let resEdge = getScaleFactor()
  assertApproxEq(resNom, 1.0, 0.001, "getScaleFactor nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.0, 0.001, "getScaleFactor boundary resEdge ~= 1.0")
  ret 0
```

---

### `getContentScale` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn getContentScale(): float:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `getContentScale` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `getScaleFactor()`.

```aipl
module tests.functions.gfx2d.shape2d_z96_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_getContentScale_96(): int:
  let resNom = getContentScale()
  let resEdge = getContentScale()
  assertApproxEq(resNom, 1.0, 0.001, "getContentScale nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.0, 0.001, "getContentScale boundary resEdge ~= 1.0")
  ret 0
```

---

### `setWindowTitle` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn setWindowTitle(title: str):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `setWindowTitle` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `title: str = "aipl_test"`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z97_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_setWindowTitle_97(): int:
  mut completedCalls = 0
  let arg_title = "test"
  let edge_title = "a"
  setWindowTitle(arg_title)
  setWindowTitle(edge_title)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "setWindowTitle nominal and boundary void calls completed")
  ret 0
```

---

### `setWindowSize` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn setWindowSize(w: int, h: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `setWindowSize` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `w: int = 128`, `h: int = 128`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z98_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_setWindowSize_98(): int:
  mut completedCalls = 0
  let arg_w = 2
  let edge_w = 0
  let arg_h = 2
  let edge_h = 0
  setWindowSize(arg_w, arg_h)
  setWindowSize(edge_w, edge_h)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "setWindowSize nominal and boundary void calls completed")
  ret 0
```

---

### `setTargetFps` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn setTargetFps(fps: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `setTargetFps` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `fps: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z99_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_setTargetFps_99(): int:
  mut completedCalls = 0
  let arg_fps = 2
  let edge_fps = 0
  setTargetFps(arg_fps)
  setTargetFps(edge_fps)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "setTargetFps nominal and boundary void calls completed")
  ret 0
```

---

### `getFrameTime` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn getFrameTime(): float:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `getFrameTime` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `0.0166667`.

```aipl
module tests.functions.gfx2d.shape2d_z100_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_getFrameTime_100(): int:
  let resNom = getFrameTime()
  let resEdge = getFrameTime()
  assertApproxEq(resNom, 0.5, 0.001, "getFrameTime nominal resNom ~= 0.5")
  assertApproxEq(resEdge, 0.5, 0.001, "getFrameTime boundary resEdge ~= 0.5")
  ret 0
```

---

### `setMaxFps` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn setMaxFps(maxFps: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `setMaxFps` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `maxFps: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z101_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_setMaxFps_101(): int:
  mut completedCalls = 0
  let arg_maxFps = 4
  let edge_maxFps = 1
  setMaxFps(arg_maxFps)
  setMaxFps(edge_maxFps)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "setMaxFps nominal and boundary void calls completed")
  ret 0
```

---

### `getMaxFps` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn getMaxFps(configuredMaxFps: int = 120): int:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `configuredMaxFps: int = 120` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `getMaxFps` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `configuredMaxFps: int = 1`; exercises core body path returning/computing `getCurrentFps()`.

```aipl
module tests.functions.gfx2d.shape2d_z102_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_getMaxFps_102(): int:
  let arg_configuredMaxFps = 4
  let edge_configuredMaxFps = 1
  let resNom = getMaxFps(arg_configuredMaxFps)
  let resEdge = getMaxFps(edge_configuredMaxFps)
  assertEqInt(resNom, 4, "getMaxFps nominal resNom == 4")
  assertEqInt(resEdge, 1, "getMaxFps boundary resEdge == 1")
  ret 0
```

---

### `getCurrentFps` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn getCurrentFps(): int:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `getCurrentFps` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `int((1.0 / dt) + 0.5)`.

```aipl
module tests.functions.gfx2d.shape2d_z103_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_getCurrentFps_103(): int:
  let resNom = getCurrentFps()
  let resEdge = getCurrentFps()
  assertEqInt(resNom, 240, "getCurrentFps nominal resNom == 240")
  assertEqInt(resEdge, 240, "getCurrentFps boundary resEdge == 240")
  ret 0
```

---

### `getFrameTimeMs` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn getFrameTimeMs(): float:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `getFrameTimeMs` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `getFrameTime() * 1000.0`.

```aipl
module tests.functions.gfx2d.shape2d_z104_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_getFrameTimeMs_104(): int:
  let resNom = getFrameTimeMs()
  let resEdge = getFrameTimeMs()
  assertApproxEq(resNom, 4.1667, 0.001, "getFrameTimeMs nominal resNom ~= 4.1667")
  assertApproxEq(resEdge, 4.1667, 0.001, "getFrameTimeMs boundary resEdge ~= 4.1667")
  ret 0
```

---

### `drawRoundedRect` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawRoundedRect(x: float, y: float, w: float, h: float, radius: float, color: Color):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `drawRoundedRect` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`, `radius: float = 1.0`, `color: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z105_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawRoundedRect_105(): int:
  mut completedCalls = 0
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawRoundedRect(arg_x, arg_y, arg_w, arg_h, arg_radius, arg_color)
  drawRoundedRect(edge_x, edge_y, edge_w, edge_h, edge_radius, edge_color)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawRoundedRect nominal and boundary void calls completed")
  ret 0
```

---

### `drawRoundedRectOutline` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawRoundedRectOutline(x: float, y: float, w: float, h: float, radius: float, thickness: float, color: Color):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawRoundedRectOutline` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`, `radius: float = 1.0`, `thickness: float = 1.0`, `color: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z106_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawRoundedRectOutline_106(): int:
  mut completedCalls = 0
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_thickness = 2.0
  let edge_thickness = 1.0
  let arg_color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawRoundedRectOutline(arg_x, arg_y, arg_w, arg_h, arg_radius, arg_thickness, arg_color)
  drawRoundedRectOutline(edge_x, edge_y, edge_w, edge_h, edge_radius, edge_thickness, edge_color)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawRoundedRectOutline nominal and boundary void calls completed")
  ret 0
```

---

### `drawArc` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawArc(cx: float, cy: float, radius: float, startAngleRad: float, endAngleRad: float, thickness: float, color: Color):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `drawArc` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `cx: float = 1.0`, `cy: float = 1.0`, `radius: float = 1.0`, `startAngleRad: float = 1.0`, `endAngleRad: float = 1.0`, `thickness: float = 1.0`, `color: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z107_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawArc_107(): int:
  mut completedCalls = 0
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_cy = 1.0
  let edge_cy = 0.5
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_startAngleRad = 0.0
  let edge_startAngleRad = 0.0
  let arg_endAngleRad = 2.0
  let edge_endAngleRad = 1.0
  let arg_thickness = 2.0
  let edge_thickness = 1.0
  let arg_color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawArc(arg_cx, arg_cy, arg_radius, arg_startAngleRad, arg_endAngleRad, arg_thickness, arg_color)
  drawArc(edge_cx, edge_cy, edge_radius, edge_startAngleRad, edge_endAngleRad, edge_thickness, edge_color)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawArc nominal and boundary void calls completed")
  ret 0
```

---

### `loadFont` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn loadFont(path: str): Result[int, str]:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `path: str` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `loadFont` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `Err("native loadFont builtin")`.

```aipl
module tests.functions.gfx2d.shape2d_z108_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_loadFont_108(): int:
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = loadFont(arg_path)
  let resEdge = loadFont(edge_path)
  assert(resNom.isOk() == false, "loadFont nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "loadFont boundary resEdge.isOk() == false")
  ret 0
```

---

### `decodeFont` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn decodeFont(data: bytes): Result[int, str]:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `decodeFont` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `Err("native decodeFont builtin")`.

```aipl
module tests.functions.gfx2d.shape2d_z109_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_decodeFont_109(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = decodeFont(arg_data)
  let resEdge = decodeFont(edge_data)
  assert(resNom.isOk() == true, "decodeFont nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "decodeFont boundary resEdge.isOk() == true")
  ret 0
```

---

### `drawTextFont` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawTextFont(fontId: int, text: str, x: float, y: float, size: float, col: Color):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `drawTextFont` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `fontId: int = 1`, `text: str = "aipl_test"`, `x: float = 1.0`, `y: float = 1.0`, `size: float = 1.0`, `col: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z110_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawTextFont_110(): int:
  mut completedCalls = 0
  let arg_fontId = 4
  let edge_fontId = 1
  let arg_text = "test"
  let edge_text = "a"
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_size = 1.0
  let edge_size = 0.5
  let arg_col = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_col = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawTextFont(arg_fontId, arg_text, arg_x, arg_y, arg_size, arg_col)
  drawTextFont(edge_fontId, edge_text, edge_x, edge_y, edge_size, edge_col)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawTextFont nominal and boundary void calls completed")
  ret 0
```

---

### `measureTextFont` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn measureTextFont(fontId: int, text: str, size: float): Vec2:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fontId: int, text: str, size: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `measureTextFont` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `fontId: int = 1`, `text: str = "aipl_test"`, `size: float = 1.0`; exercises core body path returning/computing `Vec2(x = measureTextWidthPx(text, size), y = measureTextHeight(text, size))`.

```aipl
module tests.functions.gfx2d.shape2d_z111_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_measureTextFont_111(): int:
  let arg_fontId = 4
  let edge_fontId = 1
  let arg_text = "test"
  let edge_text = "a"
  let arg_size = 1.0
  let edge_size = 0.5
  let resNom = measureTextFont(arg_fontId, arg_text, arg_size)
  let resEdge = measureTextFont(edge_fontId, edge_text, edge_size)
  assertApproxEq(resNom.x, 25.0, 0.001, "measureTextFont nominal resNom.x ~= 25.0")
  assertApproxEq(resEdge.x, 6.0, 0.001, "measureTextFont boundary resEdge.x ~= 6.0")
  ret 0
```

---

### `drawLines` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawLines(points: [Vec2], thickness: float, color: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawLines` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `points: [Vec2] = [Vec2(x = 1.0, y = 1.0)]`, `thickness: float = 1.0`, `color: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z112_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawLines_112(): int:
  mut completedCalls = 0
  let arg_points = [Vec2(x = 1.0, y = 1.0)]
  let edge_points = []
  let arg_thickness = 2.0
  let edge_thickness = 1.0
  let arg_color = 1
  let edge_color = 0
  drawLines(arg_points, arg_thickness, arg_color)
  drawLines(edge_points, edge_thickness, edge_color)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawLines nominal and boundary void calls completed")
  ret 0
```

---

### `drawCircles` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawCircles(centers: [Vec2], radius: float, color: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `drawCircles` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `centers: [Vec2] = [Vec2(x = 1.0, y = 1.0)]`, `radius: float = 1.0`, `color: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z113_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawCircles_113(): int:
  mut completedCalls = 0
  let arg_centers = [Vec2(x = 1.0, y = 1.0)]
  let edge_centers = []
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_color = 1
  let edge_color = 0
  drawCircles(arg_centers, arg_radius, arg_color)
  drawCircles(edge_centers, edge_radius, edge_color)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawCircles nominal and boundary void calls completed")
  ret 0
```

---

### `drawPixelBuffer` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawPixelBuffer(pixels: [int], gridW: int, gridH: int, dstX: int, dstY: int, dstW: int, dstH: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `drawPixelBuffer` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `pixels: [int] = [1]`, `gridW: int = 1`, `gridH: int = 1`, `dstX: int = 1`, `dstY: int = 1`, `dstW: int = 1`, `dstH: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z114_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawPixelBuffer_114(): int:
  mut completedCalls = 0
  let arg_pixels = [1]
  let edge_pixels = []
  let arg_gridW = 1
  let edge_gridW = 0
  let arg_gridH = 1
  let edge_gridH = 0
  let arg_dstX = 1
  let edge_dstX = 0
  let arg_dstY = 1
  let edge_dstY = 0
  let arg_dstW = 2
  let edge_dstW = 0
  let arg_dstH = 2
  let edge_dstH = 0
  drawPixelBuffer(arg_pixels, arg_gridW, arg_gridH, arg_dstX, arg_dstY, arg_dstW, arg_dstH)
  drawPixelBuffer(edge_pixels, edge_gridW, edge_gridH, edge_dstX, edge_dstY, edge_dstW, edge_dstH)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawPixelBuffer nominal and boundary void calls completed")
  ret 0
```

---

### `drawCirclesSoA` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawCirclesSoA(xs: [float], ys: [float], radii: [float], colors: [int], count: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawCirclesSoA` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `xs: [float] = [1.0]`, `ys: [float] = [1.0]`, `radii: [float] = [1.0]`, `colors: [int] = [1]`, `count: int = 64`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z115_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawCirclesSoA_115(): int:
  mut completedCalls = 0
  let arg_xs = [1.0]
  let edge_xs = []
  let arg_ys = [1.0]
  let edge_ys = []
  let arg_radii = [1.0]
  let edge_radii = []
  let arg_colors = [1]
  let edge_colors = []
  let arg_count = 4
  let edge_count = 1
  drawCirclesSoA(arg_xs, arg_ys, arg_radii, arg_colors, arg_count)
  drawCirclesSoA(edge_xs, edge_ys, edge_radii, edge_colors, edge_count)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawCirclesSoA nominal and boundary void calls completed")
  ret 0
```

---

### `drawRectsSoA` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawRectsSoA(xs: [float], ys: [float], ws: [float], hs: [float], colors: [int], count: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `drawRectsSoA` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `xs: [float] = [1.0]`, `ys: [float] = [1.0]`, `ws: [float] = [1.0]`, `hs: [float] = [1.0]`, `colors: [int] = [1]`, `count: int = 64`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z116_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawRectsSoA_116(): int:
  mut completedCalls = 0
  let arg_xs = [1.0]
  let edge_xs = []
  let arg_ys = [1.0]
  let edge_ys = []
  let arg_ws = [2.0]
  let edge_ws = []
  let arg_hs = [2.0]
  let edge_hs = []
  let arg_colors = [1]
  let edge_colors = []
  let arg_count = 4
  let edge_count = 1
  drawRectsSoA(arg_xs, arg_ys, arg_ws, arg_hs, arg_colors, arg_count)
  drawRectsSoA(edge_xs, edge_ys, edge_ws, edge_hs, edge_colors, edge_count)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawRectsSoA nominal and boundary void calls completed")
  ret 0
```

---

### `getFrameProfile` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn getFrameProfile(): Map[str, float]:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Map[str, float]`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `getFrameProfile` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `mapNew()`.

```aipl
module tests.functions.gfx2d.shape2d_z117_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_getFrameProfile_117(): int:
  let resNom = getFrameProfile()
  let resEdge = getFrameProfile()
  assertEqInt(resNom.len(), 0, "getFrameProfile nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "getFrameProfile boundary resEdge.len() == 0")
  ret 0
```

---

### `canvasBackendName` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn canvasBackendName(): str:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `str`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `canvasBackendName` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `"headless"`.

```aipl
module tests.functions.gfx2d.shape2d_z118_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_canvasBackendName_118(): int:
  let resNom = canvasBackendName()
  let resEdge = canvasBackendName()
  assertEqStr(resNom, "headless", "canvasBackendName nominal string matches")
  assertEqStr(resEdge, "headless", "canvasBackendName boundary string matches")
  ret 0
```

---

### `isHeadlessMode` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn isHeadlessMode(): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `isHeadlessMode` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `true`.

```aipl
module tests.functions.gfx2d.shape2d_z119_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_isHeadlessMode_119(): int:
  let resNom = isHeadlessMode()
  let resEdge = isHeadlessMode()
  assert(resNom == true, "isHeadlessMode nominal resNom == true")
  assert(resEdge == true, "isHeadlessMode boundary resEdge == true")
  ret 0
```

---

### `beginFrame` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn beginFrame():`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `beginFrame` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z120_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_beginFrame_120(): int:
  mut completedCalls = 0
  beginFrame()
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "beginFrame nominal and boundary void calls completed")
  ret 0
```

---

### `endFrame` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn endFrame():`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `endFrame` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z121_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_endFrame_121(): int:
  mut completedCalls = 0
  endFrame()
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "endFrame nominal and boundary void calls completed")
  ret 0
```

---

### `clearCanvas` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn clearCanvas(color: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `clearCanvas` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `color: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z122_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_clearCanvas_122(): int:
  mut completedCalls = 0
  let arg_color = 1
  let edge_color = 0
  clearCanvas(arg_color)
  clearCanvas(edge_color)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "clearCanvas nominal and boundary void calls completed")
  ret 0
```

---

### `getPixel` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn getPixel(x: int, y: int): int:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: int, y: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `getPixel` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x: int = 1`, `y: int = 1`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.gfx2d.shape2d_z123_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_getPixel_123(): int:
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let resNom = getPixel(arg_x, arg_y)
  let resEdge = getPixel(edge_x, edge_y)
  assertEqInt(resNom, 255, "getPixel nominal resNom == 255")
  assertEqInt(resEdge, 255, "getPixel boundary resEdge == 255")
  ret 0
```

---

### `initCanvas` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn initCanvas(w: int, h: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `initCanvas` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `w: int = 128`, `h: int = 128`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z124_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_initCanvas_124(): int:
  mut completedCalls = 0
  let arg_w = 2
  let edge_w = 0
  let arg_h = 2
  let edge_h = 0
  initCanvas(arg_w, arg_h)
  initCanvas(edge_w, edge_h)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "initCanvas nominal and boundary void calls completed")
  ret 0
```

---

### `initWindow` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn initWindow(w: int, h: int, title: str):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `initWindow` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `w: int = 128`, `h: int = 128`, `title: str = "aipl_test"`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z125_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_initWindow_125(): int:
  mut completedCalls = 0
  let arg_w = 2
  let edge_w = 0
  let arg_h = 2
  let edge_h = 0
  let arg_title = "[s]\nk=v"
  let edge_title = "[s]\nk=v"
  initWindow(arg_w, arg_h, arg_title)
  initWindow(edge_w, edge_h, edge_title)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "initWindow nominal and boundary void calls completed")
  ret 0
```

---

### `closeWindow` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn closeWindow():`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `closeWindow` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z126_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_closeWindow_126(): int:
  mut completedCalls = 0
  closeWindow()
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "closeWindow nominal and boundary void calls completed")
  ret 0
```

---

### `setSingleInstance` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn setSingleInstance(enabled: bool): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `enabled: bool` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `setSingleInstance` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `enabled: bool = true`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.gfx2d.shape2d_z127_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_setSingleInstance_127(): int:
  let arg_enabled = true
  let edge_enabled = false
  let resNom = setSingleInstance(arg_enabled)
  let resEdge = setSingleInstance(edge_enabled)
  assert(resNom == true, "setSingleInstance nominal resNom == true")
  assert(resEdge == true, "setSingleInstance boundary resEdge == true")
  ret 0
```

---

### `isSingleInstance` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn isSingleInstance(): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `isSingleInstance` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `false`.

```aipl
module tests.functions.gfx2d.shape2d_z128_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_isSingleInstance_128(): int:
  let resNom = isSingleInstance()
  let resEdge = isSingleInstance()
  assert(resNom == false, "isSingleInstance nominal resNom == false")
  assert(resEdge == false, "isSingleInstance boundary resEdge == false")
  ret 0
```

---

### `targetWindowScreenshot` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn targetWindowScreenshot(target: str, outPath: str): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `target: str, outPath: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `targetWindowScreenshot` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `target: str = "aipl_test"`, `outPath: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.gfx2d.shape2d_z129_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_targetWindowScreenshot_129(): int:
  let arg_target = "test"
  let edge_target = "a"
  let arg_outPath = "/tmp/aipl_test_path"
  let edge_outPath = "/tmp/aipl_test_path"
  let resNom = targetWindowScreenshot(arg_target, arg_outPath)
  let resEdge = targetWindowScreenshot(edge_target, edge_outPath)
  assert(resNom == false, "targetWindowScreenshot nominal resNom == false")
  assert(resEdge == false, "targetWindowScreenshot boundary resEdge == false")
  ret 0
```

---

### `targetWindowRecord` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn targetWindowRecord(target: str, outPath: str, frames: int, fps: int): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `target: str, outPath: str, frames: int, fps: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `targetWindowRecord` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `target: str = "aipl_test"`, `outPath: str = "/tmp/aipl_test_artifact.tmp"`, `frames: int = 64`, `fps: int = 1`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.gfx2d.shape2d_z130_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_targetWindowRecord_130(): int:
  let arg_target = "test"
  let edge_target = "a"
  let arg_outPath = "/tmp/aipl_test_path"
  let edge_outPath = "/tmp/aipl_test_path"
  let arg_frames = 4
  let edge_frames = 1
  let arg_fps = 2
  let edge_fps = 0
  let resNom = targetWindowRecord(arg_target, arg_outPath, arg_frames, arg_fps)
  let resEdge = targetWindowRecord(edge_target, edge_outPath, edge_frames, edge_fps)
  assert(resNom == false, "targetWindowRecord nominal resNom == false")
  assert(resEdge == false, "targetWindowRecord boundary resEdge == false")
  ret 0
```

---

### `targetWindowAction` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn targetWindowAction(target: str, botScript: str): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `target: str, botScript: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `targetWindowAction` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `target: str = "aipl_test"`, `botScript: str = "127.0.0.1"`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.gfx2d.shape2d_z131_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_targetWindowAction_131(): int:
  let arg_target = "test"
  let edge_target = "a"
  let arg_botScript = "test"
  let edge_botScript = "a"
  let resNom = targetWindowAction(arg_target, arg_botScript)
  let resEdge = targetWindowAction(edge_target, edge_botScript)
  assert(resNom == false, "targetWindowAction nominal resNom == false")
  assert(resEdge == false, "targetWindowAction boundary resEdge == false")
  ret 0
```

---

### `targetWindowSeatAction` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn targetWindowSeatAction(target: str, seatId: int, botScript: str): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `target: str, seatId: int, botScript: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `targetWindowSeatAction` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `target: str = "aipl_test"`, `seatId: int = 1`, `botScript: str = "127.0.0.1"`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.gfx2d.shape2d_z132_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_targetWindowSeatAction_132(): int:
  let arg_target = "test"
  let edge_target = "a"
  let arg_seatId = 1
  let edge_seatId = 0
  let arg_botScript = "test"
  let edge_botScript = "a"
  let resNom = targetWindowSeatAction(arg_target, arg_seatId, arg_botScript)
  let resEdge = targetWindowSeatAction(edge_target, edge_seatId, edge_botScript)
  assert(resNom == false, "targetWindowSeatAction nominal resNom == false")
  assert(resEdge == false, "targetWindowSeatAction boundary resEdge == false")
  ret 0
```

---

### `publishBotState` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn publishBotState(key: str, jsonVal: str): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `key: str, jsonVal: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `publishBotState` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `key: str = "aipl_test"`, `jsonVal: str = "{\"ok\":true}"`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.gfx2d.shape2d_z133_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_publishBotState_133(): int:
  let arg_key = "test"
  let edge_key = "a"
  let arg_jsonVal = "{\"a\":1}"
  let edge_jsonVal = "{}"
  let resNom = publishBotState(arg_key, arg_jsonVal)
  let resEdge = publishBotState(edge_key, edge_jsonVal)
  assert(resNom == true, "publishBotState nominal resNom == true")
  assert(resEdge == true, "publishBotState boundary resEdge == true")
  ret 0
```

---

### `publishTurnState` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn publishTurnState(activeSeat: int, phase: str, winnerSeat: int): bool:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `activeSeat: int, phase: str, winnerSeat: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `publishTurnState` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `activeSeat: int = 1`, `phase: str = "aipl_test"`, `winnerSeat: int = 1`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.gfx2d.shape2d_z134_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_publishTurnState_134(): int:
  let arg_activeSeat = 2
  let edge_activeSeat = 0
  let arg_phase = "test"
  let edge_phase = "a"
  let arg_winnerSeat = 4
  let edge_winnerSeat = 1
  let resNom = publishTurnState(arg_activeSeat, arg_phase, arg_winnerSeat)
  let resEdge = publishTurnState(edge_activeSeat, edge_phase, edge_winnerSeat)
  assert(resNom == true, "publishTurnState nominal resNom == true")
  assert(resEdge == true, "publishTurnState boundary resEdge == true")
  ret 0
```

---

### `listRunningWindows` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn listRunningWindows(): [str]:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `listRunningWindows` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `[]`.

```aipl
module tests.functions.gfx2d.shape2d_z135_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_listRunningWindows_135(): int:
  let resNom = listRunningWindows()
  let resEdge = listRunningWindows()
  assertEqInt(resNom.len(), 1, "listRunningWindows nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "listRunningWindows boundary resEdge.len() == 1")
  ret 0
```

---

### `setWindowPosition` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn setWindowPosition(x: int, y: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `setWindowPosition` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x: int = 1`, `y: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z136_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_setWindowPosition_136(): int:
  mut completedCalls = 0
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  setWindowPosition(arg_x, arg_y)
  setWindowPosition(edge_x, edge_y)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "setWindowPosition nominal and boundary void calls completed")
  ret 0
```

---

### `drawTexturedWallStrip` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawTexturedWallStrip(x: float, yTop: float, colW: float, wallH: float, texU: float, wallKind: int, distShade: float, baseColor: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `drawTexturedWallStrip` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x: float = 1.0`, `yTop: float = 1.0`, `colW: float = 1.0`, `wallH: float = 1.0`, `texU: float = 1.0`, `wallKind: int = 1`, `distShade: float = 1.0`, `baseColor: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z137_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawTexturedWallStrip_137(): int:
  mut completedCalls = 0
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_yTop = 1.0
  let edge_yTop = 0.5
  let arg_colW = 2.0
  let edge_colW = 1.0
  let arg_wallH = 2.0
  let edge_wallH = 1.0
  let arg_texU = 1.0
  let edge_texU = 0.5
  let arg_wallKind = 4
  let edge_wallKind = 1
  let arg_distShade = 2.0
  let edge_distShade = 1.0
  let arg_baseColor = 4
  let edge_baseColor = 1
  drawTexturedWallStrip(arg_x, arg_yTop, arg_colW, arg_wallH, arg_texU, arg_wallKind, arg_distShade, arg_baseColor)
  drawTexturedWallStrip(edge_x, edge_yTop, edge_colW, edge_wallH, edge_texU, edge_wallKind, edge_distShade, edge_baseColor)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawTexturedWallStrip nominal and boundary void calls completed")
  ret 0
```

---

### `drawFloorCeilingScanlines` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawFloorCeilingScanlines(x: float, y: float, w: float, h: float, horizonY: float, skyColorTop: int, floorColorNear: int, bands: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `drawFloorCeilingScanlines` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`, `horizonY: float = 1.0`, `skyColorTop: int = 1`, `floorColorNear: int = 1`, `bands: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z138_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawFloorCeilingScanlines_138(): int:
  mut completedCalls = 0
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let arg_horizonY = 2.0
  let edge_horizonY = 1.0
  let arg_skyColorTop = 4
  let edge_skyColorTop = 1
  let arg_floorColorNear = 4
  let edge_floorColorNear = 1
  let arg_bands = 4
  let edge_bands = 1
  drawFloorCeilingScanlines(arg_x, arg_y, arg_w, arg_h, arg_horizonY, arg_skyColorTop, arg_floorColorNear, arg_bands)
  drawFloorCeilingScanlines(edge_x, edge_y, edge_w, edge_h, edge_horizonY, edge_skyColorTop, edge_floorColorNear, edge_bands)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawFloorCeilingScanlines nominal and boundary void calls completed")
  ret 0
```

---

### `drawDepthColumnsSoA` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawDepthColumnsSoA(xs: [float], yTops: [float], heights: [float], colors: [int], colW: float, count: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawDepthColumnsSoA` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `xs: [float] = [1.0]`, `yTops: [float] = [1.0]`, `heights: [float] = [1.0]`, `colors: [int] = [1]`, `colW: float = 1.0`, `count: int = 64`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z139_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawDepthColumnsSoA_139(): int:
  mut completedCalls = 0
  let arg_xs = [1.0]
  let edge_xs = []
  let arg_yTops = [1.0]
  let edge_yTops = []
  let arg_heights = [2.0]
  let edge_heights = []
  let arg_colors = [1]
  let edge_colors = []
  let arg_colW = 2.0
  let edge_colW = 1.0
  let arg_count = 4
  let edge_count = 1
  drawDepthColumnsSoA(arg_xs, arg_yTops, arg_heights, arg_colors, arg_colW, arg_count)
  drawDepthColumnsSoA(edge_xs, edge_yTops, edge_heights, edge_colors, edge_colW, edge_count)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawDepthColumnsSoA nominal and boundary void calls completed")
  ret 0
```

---

### `listRunningWindowsFiltered` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn listRunningWindowsFiltered(titleSubstr: str): [str]:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `titleSubstr: str` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `listRunningWindowsFiltered` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `titleSubstr: str = "aipl_test"`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.gfx2d.shape2d_z140_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_listRunningWindowsFiltered_140(): int:
  let arg_titleSubstr = "test"
  let edge_titleSubstr = "a"
  let resNom = listRunningWindowsFiltered(arg_titleSubstr)
  let resEdge = listRunningWindowsFiltered(edge_titleSubstr)
  assertEqInt(resNom.len(), 0, "listRunningWindowsFiltered nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 1, "listRunningWindowsFiltered boundary resEdge.len() == 1")
  ret 0
```

---

### `drawPerspectiveQuad` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawPerspectiveQuad(x1: float, y1: float, x2: float, y2: float, x3: float, y3: float, x4: float, y4: float, col: Color):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `drawPerspectiveQuad` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x1: float = 1.0`, `y1: float = 1.0`, `x2: float = 1.0`, `y2: float = 1.0`, `x3: float = 1.0`, `y3: float = 1.0`, `x4: float = 1.0`, `y4: float = 1.0`, `col: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z141_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawPerspectiveQuad_141(): int:
  mut completedCalls = 0
  let arg_x1 = 1.0
  let edge_x1 = 0.5
  let arg_y1 = 1.0
  let edge_y1 = 0.5
  let arg_x2 = 1.0
  let edge_x2 = 0.5
  let arg_y2 = 1.0
  let edge_y2 = 0.5
  let arg_x3 = 1.0
  let edge_x3 = 0.5
  let arg_y3 = 1.0
  let edge_y3 = 0.5
  let arg_x4 = 1.0
  let edge_x4 = 0.5
  let arg_y4 = 1.0
  let edge_y4 = 0.5
  let arg_col = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_col = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawPerspectiveQuad(arg_x1, arg_y1, arg_x2, arg_y2, arg_x3, arg_y3, arg_x4, arg_y4, arg_col)
  drawPerspectiveQuad(edge_x1, edge_y1, edge_x2, edge_y2, edge_x3, edge_y3, edge_x4, edge_y4, edge_col)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawPerspectiveQuad nominal and boundary void calls completed")
  ret 0
```

---

### `drawGlowCircle` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawGlowCircle(cx: float, cy: float, radius: float, colorHexVal: int, rings: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawGlowCircle` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `cx: float = 1.0`, `cy: float = 1.0`, `radius: float = 1.0`, `colorHexVal: int = 1`, `rings: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z142_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawGlowCircle_142(): int:
  mut completedCalls = 0
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_cy = 1.0
  let edge_cy = 0.5
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_colorHexVal = 1
  let edge_colorHexVal = 0
  let arg_rings = 4
  let edge_rings = 1
  drawGlowCircle(arg_cx, arg_cy, arg_radius, arg_colorHexVal, arg_rings)
  drawGlowCircle(edge_cx, edge_cy, edge_radius, edge_colorHexVal, edge_rings)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawGlowCircle nominal and boundary void calls completed")
  ret 0
```

---

### `drawDashedRectOutline` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawDashedRectOutline(x: float, y: float, w: float, h: float, dashLen: float, gapLen: float, col: Color, thickness: float):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `drawDashedRectOutline` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`, `dashLen: float = 1.0`, `gapLen: float = 1.0`, `col: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `thickness: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z143_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawDashedRectOutline_143(): int:
  mut completedCalls = 0
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let arg_dashLen = 2.0
  let edge_dashLen = 1.0
  let arg_gapLen = 1.0
  let edge_gapLen = 0.5
  let arg_col = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_col = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_thickness = 2.0
  let edge_thickness = 1.0
  drawDashedRectOutline(arg_x, arg_y, arg_w, arg_h, arg_dashLen, arg_gapLen, arg_col, arg_thickness)
  drawDashedRectOutline(edge_x, edge_y, edge_w, edge_h, edge_dashLen, edge_gapLen, edge_col, edge_thickness)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawDashedRectOutline nominal and boundary void calls completed")
  ret 0
```

---

### `drawVectorField2D` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawVectorField2D(xs: [float], ys: [float], vxs: [float], vys: [float], scale: float, col: Color, count: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `drawVectorField2D` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `xs: [float] = [1.0]`, `ys: [float] = [1.0]`, `vxs: [float] = [1.0]`, `vys: [float] = [1.0]`, `scale: float = 1.0`, `col: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `count: int = 64`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z144_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawVectorField2D_144(): int:
  mut completedCalls = 0
  let arg_xs = [1.0]
  let edge_xs = []
  let arg_ys = [1.0]
  let edge_ys = []
  let arg_vxs = [1.0]
  let edge_vxs = []
  let arg_vys = [1.0]
  let edge_vys = []
  let arg_scale = 2.0
  let edge_scale = 1.0
  let arg_col = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_col = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_count = 4
  let edge_count = 1
  drawVectorField2D(arg_xs, arg_ys, arg_vxs, arg_vys, arg_scale, arg_col, arg_count)
  drawVectorField2D(edge_xs, edge_ys, edge_vxs, edge_vys, edge_scale, edge_col, edge_count)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawVectorField2D nominal and boundary void calls completed")
  ret 0
```

---

### `drawCrosshairSniperScope` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawCrosshairSniperScope(cx: float, cy: float, radius: float, screenW: float, screenH: float, zoomFactor: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawCrosshairSniperScope` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `cx: float = 1.0`, `cy: float = 1.0`, `radius: float = 1.0`, `screenW: float = 1.0`, `screenH: float = 1.0`, `zoomFactor: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z145_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawCrosshairSniperScope_145(): int:
  mut completedCalls = 0
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_cy = 1.0
  let edge_cy = 0.5
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_screenW = 2.0
  let edge_screenW = 1.0
  let arg_screenH = 2.0
  let edge_screenH = 1.0
  let arg_zoomFactor = 4
  let edge_zoomFactor = 1
  drawCrosshairSniperScope(arg_cx, arg_cy, arg_radius, arg_screenW, arg_screenH, arg_zoomFactor)
  drawCrosshairSniperScope(edge_cx, edge_cy, edge_radius, edge_screenW, edge_screenH, edge_zoomFactor)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawCrosshairSniperScope nominal and boundary void calls completed")
  ret 0
```

---

### `drawIsometricWallSegment` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawIsometricWallSegment(x1: float, y1: float, x2: float, y2: float, wallHeight: float, topCol: Color, faceCol: Color, mortarCol: Color):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `drawIsometricWallSegment` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x1: float = 1.0`, `y1: float = 1.0`, `x2: float = 1.0`, `y2: float = 1.0`, `wallHeight: float = 1.0`, `topCol: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `faceCol: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `mortarCol: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z146_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawIsometricWallSegment_146(): int:
  mut completedCalls = 0
  let arg_x1 = 1.0
  let edge_x1 = 0.5
  let arg_y1 = 1.0
  let edge_y1 = 0.5
  let arg_x2 = 1.0
  let edge_x2 = 0.5
  let arg_y2 = 1.0
  let edge_y2 = 0.5
  let arg_wallHeight = 2.0
  let edge_wallHeight = 1.0
  let arg_topCol = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_topCol = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_faceCol = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_faceCol = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_mortarCol = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_mortarCol = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  drawIsometricWallSegment(arg_x1, arg_y1, arg_x2, arg_y2, arg_wallHeight, arg_topCol, arg_faceCol, arg_mortarCol)
  drawIsometricWallSegment(edge_x1, edge_y1, edge_x2, edge_y2, edge_wallHeight, edge_topCol, edge_faceCol, edge_mortarCol)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawIsometricWallSegment nominal and boundary void calls completed")
  ret 0
```

---

### `drawRadialRadarSweep` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawRadialRadarSweep(x: float, y: float, r: float, angleDeg: float, sweepColor: str, ringColor: str):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `drawRadialRadarSweep` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `r: float = 1.0`, `angleDeg: float = 1.0`, `sweepColor: str = "aipl_test"`, `ringColor: str = "aipl_test"`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z147_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawRadialRadarSweep_147(): int:
  mut completedCalls = 0
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_r = 1.0
  let edge_r = 0.5
  let arg_angleDeg = 1.0
  let edge_angleDeg = 0.5
  let arg_sweepColor = "test"
  let edge_sweepColor = "a"
  let arg_ringColor = "test"
  let edge_ringColor = "a"
  drawRadialRadarSweep(arg_x, arg_y, arg_r, arg_angleDeg, arg_sweepColor, arg_ringColor)
  drawRadialRadarSweep(edge_x, edge_y, edge_r, edge_angleDeg, edge_sweepColor, edge_ringColor)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawRadialRadarSweep nominal and boundary void calls completed")
  ret 0
```

---

### `drawPerspectiveCheckerFloor` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawPerspectiveCheckerFloor(x: float, y: float, w: float, h: float, horizonY: float, colA: str, colB: str):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawPerspectiveCheckerFloor` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`, `horizonY: float = 1.0`, `colA: str = "aipl_test"`, `colB: str = "aipl_test"`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z148_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawPerspectiveCheckerFloor_148(): int:
  mut completedCalls = 0
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let arg_horizonY = 2.0
  let edge_horizonY = 1.0
  let arg_colA = "test"
  let edge_colA = "a"
  let arg_colB = "test"
  let edge_colB = "a"
  drawPerspectiveCheckerFloor(arg_x, arg_y, arg_w, arg_h, arg_horizonY, arg_colA, arg_colB)
  drawPerspectiveCheckerFloor(edge_x, edge_y, edge_w, edge_h, edge_horizonY, edge_colA, edge_colB)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawPerspectiveCheckerFloor nominal and boundary void calls completed")
  ret 0
```

---

### `drawVolumetricFogLayer` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawVolumetricFogLayer(x: float, y: float, w: float, h: float, densityPct: int, fogHex: str):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `drawVolumetricFogLayer` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`, `densityPct: int = 1`, `fogHex: str = "aipl_test"`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z149_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawVolumetricFogLayer_149(): int:
  mut completedCalls = 0
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let arg_densityPct = 4
  let edge_densityPct = 1
  let arg_fogHex = "4142"
  let edge_fogHex = "00"
  drawVolumetricFogLayer(arg_x, arg_y, arg_w, arg_h, arg_densityPct, arg_fogHex)
  drawVolumetricFogLayer(edge_x, edge_y, edge_w, edge_h, edge_densityPct, edge_fogHex)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawVolumetricFogLayer nominal and boundary void calls completed")
  ret 0
```

---

### `drawBezierRibbonConnection` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawBezierRibbonConnection(x1: float, y1: float, x2: float, y2: float, thickness: float, colStart: str, colEnd: str):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `drawBezierRibbonConnection` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x1: float = 1.0`, `y1: float = 1.0`, `x2: float = 1.0`, `y2: float = 1.0`, `thickness: float = 1.0`, `colStart: str = "aipl_test"`, `colEnd: str = "aipl_test"`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z150_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawBezierRibbonConnection_150(): int:
  mut completedCalls = 0
  let arg_x1 = 1.0
  let edge_x1 = 0.5
  let arg_y1 = 1.0
  let edge_y1 = 0.5
  let arg_x2 = 1.0
  let edge_x2 = 0.5
  let arg_y2 = 1.0
  let edge_y2 = 0.5
  let arg_thickness = 2.0
  let edge_thickness = 1.0
  let arg_colStart = "test"
  let edge_colStart = "a"
  let arg_colEnd = "test"
  let edge_colEnd = "a"
  drawBezierRibbonConnection(arg_x1, arg_y1, arg_x2, arg_y2, arg_thickness, arg_colStart, arg_colEnd)
  drawBezierRibbonConnection(edge_x1, edge_y1, edge_x2, edge_y2, edge_thickness, edge_colStart, edge_colEnd)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawBezierRibbonConnection nominal and boundary void calls completed")
  ret 0
```

---

### `drawNormalLitSurface` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawNormalLitSurface(x: float, y: float, w: float, h: float, lightAzimuth: float, lightElevation: float, baseHex: str, specHex: str):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawNormalLitSurface` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`, `lightAzimuth: float = 1.0`, `lightElevation: float = 1.0`, `baseHex: str = "aipl_test"`, `specHex: str = "aipl_test"`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z151_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawNormalLitSurface_151(): int:
  mut completedCalls = 0
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let arg_lightAzimuth = 2.0
  let edge_lightAzimuth = 1.0
  let arg_lightElevation = 2.0
  let edge_lightElevation = 1.0
  let arg_baseHex = "4142"
  let edge_baseHex = "00"
  let arg_specHex = "4142"
  let edge_specHex = "00"
  drawNormalLitSurface(arg_x, arg_y, arg_w, arg_h, arg_lightAzimuth, arg_lightElevation, arg_baseHex, arg_specHex)
  drawNormalLitSurface(edge_x, edge_y, edge_w, edge_h, edge_lightAzimuth, edge_lightElevation, edge_baseHex, edge_specHex)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawNormalLitSurface nominal and boundary void calls completed")
  ret 0
```

---

### `drawAudioSpectrumBars` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawAudioSpectrumBars(x: float, y: float, w: float, h: float, numBands: int, peakDb: int, accentHex: str):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `drawAudioSpectrumBars` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`, `numBands: int = 1`, `peakDb: int = 1`, `accentHex: str = "aipl_test"`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z152_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawAudioSpectrumBars_152(): int:
  mut completedCalls = 0
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let arg_numBands = 4
  let edge_numBands = 1
  let arg_peakDb = 4
  let edge_peakDb = 1
  let arg_accentHex = "4142"
  let edge_accentHex = "00"
  drawAudioSpectrumBars(arg_x, arg_y, arg_w, arg_h, arg_numBands, arg_peakDb, arg_accentHex)
  drawAudioSpectrumBars(edge_x, edge_y, edge_w, edge_h, edge_numBands, edge_peakDb, edge_accentHex)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawAudioSpectrumBars nominal and boundary void calls completed")
  ret 0
```

---

### `drawSubpixelAASpan` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawSubpixelAASpan(x: float, y: float, w: float, h: float, coverage: float, fgHex: int, bgHex: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `drawSubpixelAASpan` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`, `coverage: float = 1.0`, `fgHex: int = 1`, `bgHex: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z153_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawSubpixelAASpan_153(): int:
  mut completedCalls = 0
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let arg_coverage = 1.0
  let edge_coverage = 0.5
  let arg_fgHex = 1
  let edge_fgHex = 0
  let arg_bgHex = 4
  let edge_bgHex = 1
  drawSubpixelAASpan(arg_x, arg_y, arg_w, arg_h, arg_coverage, arg_fgHex, arg_bgHex)
  drawSubpixelAASpan(edge_x, edge_y, edge_w, edge_h, edge_coverage, edge_fgHex, edge_bgHex)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawSubpixelAASpan nominal and boundary void calls completed")
  ret 0
```

---

### `drawParticleRibbonTrail` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawParticleRibbonTrail(x1: float, y1: float, x2: float, y2: float, widthStart: float, widthEnd: float, colHex: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawParticleRibbonTrail` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x1: float = 1.0`, `y1: float = 1.0`, `x2: float = 1.0`, `y2: float = 1.0`, `widthStart: float = 0.016667`, `widthEnd: float = 0.016667`, `colHex: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z154_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawParticleRibbonTrail_154(): int:
  mut completedCalls = 0
  let arg_x1 = 1.0
  let edge_x1 = 0.5
  let arg_y1 = 1.0
  let edge_y1 = 0.5
  let arg_x2 = 1.0
  let edge_x2 = 0.5
  let arg_y2 = 1.0
  let edge_y2 = 0.5
  let arg_widthStart = 0.0
  let edge_widthStart = 0.0
  let arg_widthEnd = 2.0
  let edge_widthEnd = 1.0
  let arg_colHex = 1
  let edge_colHex = 0
  drawParticleRibbonTrail(arg_x1, arg_y1, arg_x2, arg_y2, arg_widthStart, arg_widthEnd, arg_colHex)
  drawParticleRibbonTrail(edge_x1, edge_y1, edge_x2, edge_y2, edge_widthStart, edge_widthEnd, edge_colHex)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawParticleRibbonTrail nominal and boundary void calls completed")
  ret 0
```

---

### `drawRibbonTrail` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawRibbonTrail(x1: float, y1: float, x2: float, y2: float, segments: int, startWidth: float, coreHex: int, fadeHex: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `drawRibbonTrail` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x1: float = 1.0`, `y1: float = 1.0`, `x2: float = 1.0`, `y2: float = 1.0`, `segments: int = 1`, `startWidth: float = 0.016667`, `coreHex: int = 1`, `fadeHex: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z155_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawRibbonTrail_155(): int:
  mut completedCalls = 0
  let arg_x1 = 1.0
  let edge_x1 = 0.5
  let arg_y1 = 1.0
  let edge_y1 = 0.5
  let arg_x2 = 1.0
  let edge_x2 = 0.5
  let arg_y2 = 1.0
  let edge_y2 = 0.5
  let arg_segments = 4
  let edge_segments = 1
  let arg_startWidth = 0.0
  let edge_startWidth = 0.0
  let arg_coreHex = 1
  let edge_coreHex = 0
  let arg_fadeHex = 1
  let edge_fadeHex = 0
  drawRibbonTrail(arg_x1, arg_y1, arg_x2, arg_y2, arg_segments, arg_startWidth, arg_coreHex, arg_fadeHex)
  drawRibbonTrail(edge_x1, edge_y1, edge_x2, edge_y2, edge_segments, edge_startWidth, edge_coreHex, edge_fadeHex)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawRibbonTrail nominal and boundary void calls completed")
  ret 0
```

---

### `drawSubpixelRect` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawSubpixelRect(x: float, y: float, w: float, h: float, fgHex: int, bgHex: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `drawSubpixelRect` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`, `fgHex: int = 1`, `bgHex: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z156_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawSubpixelRect_156(): int:
  mut completedCalls = 0
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let arg_fgHex = 1
  let edge_fgHex = 0
  let arg_bgHex = 4
  let edge_bgHex = 1
  drawSubpixelRect(arg_x, arg_y, arg_w, arg_h, arg_fgHex, arg_bgHex)
  drawSubpixelRect(edge_x, edge_y, edge_w, edge_h, edge_fgHex, edge_bgHex)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawSubpixelRect nominal and boundary void calls completed")
  ret 0
```

---

### `drawSubpixelTextSpan` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawSubpixelTextSpan(x: float, y: float, text: str, fontPx: float, textHex: int, bgPlateHex: int):`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawSubpixelTextSpan` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `text: str = "aipl_test"`, `fontPx: float = 1.0`, `textHex: int = 1`, `bgPlateHex: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z157_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawSubpixelTextSpan_157(): int:
  mut completedCalls = 0
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_text = "test"
  let edge_text = "a"
  let arg_fontPx = 1.0
  let edge_fontPx = 0.5
  let arg_textHex = 1
  let edge_textHex = 0
  let arg_bgPlateHex = 4
  let edge_bgPlateHex = 1
  drawSubpixelTextSpan(arg_x, arg_y, arg_text, arg_fontPx, arg_textHex, arg_bgPlateHex)
  drawSubpixelTextSpan(edge_x, edge_y, edge_text, edge_fontPx, edge_textHex, edge_bgPlateHex)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawSubpixelTextSpan nominal and boundary void calls completed")
  ret 0
```

---

### `canvasEnvStr` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `fn canvasEnvStr(key: str, fallback: str): str:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `key: str, fallback: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `canvasEnvStr` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `key: str = "aipl_test"`, `fallback: str = "aipl_test"`; exercises core body path returning/computing `fallback`.

```aipl
module tests.functions.gfx2d.shape2d_z158_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_canvasEnvStr_158(): int:
  let arg_key = "test"
  let edge_key = "a"
  let arg_fallback = "test"
  let edge_fallback = "a"
  let resNom = canvasEnvStr(arg_key, arg_fallback)
  let resEdge = canvasEnvStr(edge_key, edge_fallback)
  assertEqStr(resNom, "test", "canvasEnvStr nominal string matches")
  assertEqStr(resEdge, "a", "canvasEnvStr boundary string matches")
  ret 0
```

---

### `setBlendMode` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn setBlendMode(mode: int): void:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mode: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `setBlendMode` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `mode: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z159_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_setBlendMode_159(): int:
  mut completedCalls = 0
  let arg_mode = 4
  let edge_mode = 1
  setBlendMode(arg_mode)
  setBlendMode(edge_mode)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "setBlendMode nominal and boundary void calls completed")
  ret 0
```

---

### `getBlendMode` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn getBlendMode(): int:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `getBlendMode` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `int(canvasEnvStr("__AIPL_BLEND_MODE", "0"))`.

```aipl
module tests.functions.gfx2d.shape2d_z160_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_getBlendMode_160(): int:
  let resNom = getBlendMode()
  let resEdge = getBlendMode()
  assertEqInt(resNom, 1, "getBlendMode nominal resNom == 1")
  assertEqInt(resEdge, 1, "getBlendMode boundary resEdge == 1")
  ret 0
```

---

### `paint2DFill` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn paint2DFill(col: Color): Paint2D:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `col: Color` | **Returns**: `Paint2D`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `paint2DFill` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `col: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`; exercises core body path returning/computing `Paint2D(fillColor = col, strokeColor = Color(r = col.r, g = col.g, b = col.b, a = 0.0), strokeWidth = 0.0, blendMode = 0, antiAlias = true)`.

```aipl
module tests.functions.gfx2d.shape2d_z161_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_paint2DFill_161(): int:
  let arg_col = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_col = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let resNom = paint2DFill(arg_col)
  let resEdge = paint2DFill(edge_col)
  assertApproxEq(resNom.strokeWidth, 0.0, 0.001, "paint2DFill nominal resNom.strokeWidth ~= 0.0")
  assertApproxEq(resEdge.strokeWidth, 0.0, 0.001, "paint2DFill boundary resEdge.strokeWidth ~= 0.0")
  ret 0
```

---

### `paint2DStroke` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn paint2DStroke(col: Color, width: float): Paint2D:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `col: Color, width: float` | **Returns**: `Paint2D`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `paint2DStroke` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `col: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `width: float = 0.016667`; exercises core body path returning/computing `Paint2D(fillColor = Color(r = col.r, g = col.g, b = col.b, a = 0.0), strokeColor = col, strokeWidth = maxFloat(0.5, width), blendMode = 0, antiAlias = true)`.

```aipl
module tests.functions.gfx2d.shape2d_z162_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_paint2DStroke_162(): int:
  let arg_col = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_col = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_width = 2.0
  let edge_width = 1.0
  let resNom = paint2DStroke(arg_col, arg_width)
  let resEdge = paint2DStroke(edge_col, edge_width)
  assertApproxEq(resNom.strokeWidth, 2.0, 0.001, "paint2DStroke nominal resNom.strokeWidth ~= 2.0")
  assertApproxEq(resEdge.strokeWidth, 1.0, 0.001, "paint2DStroke boundary resEdge.strokeWidth ~= 1.0")
  ret 0
```

---

### `path2DNew` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn path2DNew(): Path2D:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Path2D`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `path2DNew` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Path2D(points = pts, closed = false, subpathStarts = starts)`.

```aipl
module tests.functions.gfx2d.shape2d_z163_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_path2DNew_163(): int:
  let resNom = path2DNew()
  let resEdge = path2DNew()
  assertEqInt(resNom.points.len(), 0, "path2DNew nominal resNom.points.len() == 0")
  assertEqInt(resEdge.points.len(), 0, "path2DNew boundary resEdge.points.len() == 0")
  ret 0
```

---

### `path2DMoveTo` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn path2DMoveTo(mut p: Path2D, x: float, y: float): Path2D:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut p: Path2D, x: float, y: float` | **Returns**: `Path2D`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `path2DMoveTo` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `p: Path2D = Path2D(points = [Vec2(x = 0, y = 0)], closed = true, subpathStarts = [1])`, `x: float = 1.0`, `y: float = 1.0`; exercises core body path returning/computing `p`.

```aipl
module tests.functions.gfx2d.shape2d_z164_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_path2DMoveTo_164(): int:
  let arg_p = Path2D(points = [], closed = true, subpathStarts = [])
  let edge_p = Path2D(points = [], closed = false, subpathStarts = [])
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let resNom = path2DMoveTo(arg_p, arg_x, arg_y)
  let resEdge = path2DMoveTo(edge_p, edge_x, edge_y)
  assertEqInt(resNom.points.len(), 1, "path2DMoveTo nominal resNom.points.len() == 1")
  assertEqInt(resEdge.points.len(), 1, "path2DMoveTo boundary resEdge.points.len() == 1")
  ret 0
```

---

### `path2DLineTo` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn path2DLineTo(mut p: Path2D, x: float, y: float): Path2D:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut p: Path2D, x: float, y: float` | **Returns**: `Path2D`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `path2DLineTo` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `p: Path2D = Path2D(points = [Vec2(x = 0, y = 0)], closed = true, subpathStarts = [1])`, `x: float = 1.0`, `y: float = 1.0`; exercises core body path returning/computing `p`.

```aipl
module tests.functions.gfx2d.shape2d_z165_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_path2DLineTo_165(): int:
  let arg_p = Path2D(points = [], closed = true, subpathStarts = [])
  let edge_p = Path2D(points = [], closed = false, subpathStarts = [])
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let resNom = path2DLineTo(arg_p, arg_x, arg_y)
  let resEdge = path2DLineTo(edge_p, edge_x, edge_y)
  assertEqInt(resNom.points.len(), 1, "path2DLineTo nominal resNom.points.len() == 1")
  assertEqInt(resEdge.points.len(), 1, "path2DLineTo boundary resEdge.points.len() == 1")
  ret 0
```

---

### `path2DQuadTo` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn path2DQuadTo(mut p: Path2D, cx: float, cy: float, x: float, y: float, segments: int = 8): Path2D:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut p: Path2D, cx: float, cy: float, x: float, y: float, segments: int = 8` | **Returns**: `Path2D`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `path2DQuadTo` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `p: Path2D = Path2D(points = [Vec2(x = 0, y = 0)], closed = true, subpathStarts = [1])`, `cx: float = 1.0`, `cy: float = 1.0`, `x: float = 1.0`, `y: float = 1.0`, `segments: int = 1`; exercises core body path returning/computing `p`.

```aipl
module tests.functions.gfx2d.shape2d_z166_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_path2DQuadTo_166(): int:
  let arg_p = Path2D(points = [], closed = true, subpathStarts = [])
  let edge_p = Path2D(points = [], closed = false, subpathStarts = [])
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_cy = 1.0
  let edge_cy = 0.5
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_segments = 4
  let edge_segments = 1
  let resNom = path2DQuadTo(arg_p, arg_cx, arg_cy, arg_x, arg_y, arg_segments)
  let resEdge = path2DQuadTo(edge_p, edge_cx, edge_cy, edge_x, edge_y, edge_segments)
  assertEqInt(resNom.points.len(), 4, "path2DQuadTo nominal resNom.points.len() == 4")
  assertEqInt(resEdge.points.len(), 2, "path2DQuadTo boundary resEdge.points.len() == 2")
  ret 0
```

---

### `path2DCubicTo` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn path2DCubicTo(mut p: Path2D, c1x: float, c1y: float, c2x: float, c2y: float, x: float, y: float, segments: int = 12): Path2D:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut p: Path2D, c1x: float, c1y: float, c2x: float, c2y: float, x: float, y: float, segments: int = 12` | **Returns**: `Path2D`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `path2DCubicTo` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `p: Path2D = Path2D(points = [Vec2(x = 0, y = 0)], closed = true, subpathStarts = [1])`, `c1x: float = 1.0`, `c1y: float = 1.0`, `c2x: float = 1.0`, `c2y: float = 1.0`, `x: float = 1.0`, `y: float = 1.0`, `segments: int = 1`; exercises core body path returning/computing `p`.

```aipl
module tests.functions.gfx2d.shape2d_z167_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_path2DCubicTo_167(): int:
  let arg_p = Path2D(points = [], closed = true, subpathStarts = [])
  let edge_p = Path2D(points = [], closed = false, subpathStarts = [])
  let arg_c1x = 1.0
  let edge_c1x = 0.5
  let arg_c1y = 1.0
  let edge_c1y = 0.5
  let arg_c2x = 1.0
  let edge_c2x = 0.5
  let arg_c2y = 1.0
  let edge_c2y = 0.5
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_segments = 4
  let edge_segments = 1
  let resNom = path2DCubicTo(arg_p, arg_c1x, arg_c1y, arg_c2x, arg_c2y, arg_x, arg_y, arg_segments)
  let resEdge = path2DCubicTo(edge_p, edge_c1x, edge_c1y, edge_c2x, edge_c2y, edge_x, edge_y, edge_segments)
  assertEqInt(resNom.points.len(), 4, "path2DCubicTo nominal resNom.points.len() == 4")
  assertEqInt(resEdge.points.len(), 2, "path2DCubicTo boundary resEdge.points.len() == 2")
  ret 0
```

---

### `path2DClose` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn path2DClose(mut p: Path2D): Path2D:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut p: Path2D` | **Returns**: `Path2D`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `path2DClose` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `p: Path2D = Path2D(points = [Vec2(x = 0, y = 0)], closed = true, subpathStarts = [1])`; exercises core body path returning/computing `p`.

```aipl
module tests.functions.gfx2d.shape2d_z168_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_path2DClose_168(): int:
  let arg_p = Path2D(points = [], closed = true, subpathStarts = [])
  let edge_p = Path2D(points = [], closed = false, subpathStarts = [])
  let resNom = path2DClose(arg_p)
  let resEdge = path2DClose(edge_p)
  assertEqInt(resNom.points.len(), 0, "path2DClose nominal resNom.points.len() == 0")
  assertEqInt(resEdge.points.len(), 0, "path2DClose boundary resEdge.points.len() == 0")
  ret 0
```

---

### `drawPath2D` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn drawPath2D(p: Path2D, paint: Paint2D): void:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p: Path2D, paint: Paint2D` | **Returns**: `void`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `drawPath2D` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `p: Path2D = Path2D(points = [Vec2(x = 0, y = 0)], closed = true, subpathStarts = [1])`, `paint: Paint2D = Paint2D(fillColor = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), strokeColor = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), strokeWidth = 0.016667, blendMode = 64, antiAlias = true)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.gfx2d.shape2d_z169_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_drawPath2D_169(): int:
  mut completedCalls = 0
  let arg_p = Path2D(points = [], closed = true, subpathStarts = [])
  let edge_p = Path2D(points = [], closed = false, subpathStarts = [])
  let arg_paint = Paint2D(fillColor = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), strokeColor = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), strokeWidth = 2.0, blendMode = 4, antiAlias = true)
  let edge_paint = Paint2D(fillColor = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5), strokeColor = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5), strokeWidth = 1.0, blendMode = 1, antiAlias = false)
  drawPath2D(arg_p, arg_paint)
  drawPath2D(edge_p, edge_paint)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawPath2D nominal and boundary void calls completed")
  ret 0
```

---

### `renderGroup2DNew` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn renderGroup2DNew(id: str): RenderGroup2D:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `id: str` | **Returns**: `RenderGroup2D`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `renderGroup2DNew` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `id: str = "aipl_test"`; exercises core body path returning/computing `RenderGroup2D(`.

```aipl
module tests.functions.gfx2d.shape2d_z170_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_renderGroup2DNew_170(): int:
  let arg_id = "test"
  let edge_id = "a"
  let resNom = renderGroup2DNew(arg_id)
  let resEdge = renderGroup2DNew(edge_id)
  assertEqStr(resNom.id, "test", "renderGroup2DNew nominal string matches")
  assertEqStr(resEdge.id, "a", "renderGroup2DNew boundary string matches")
  ret 0
```

---

### `renderGroup2DAddRect` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn renderGroup2DAddRect(mut g: RenderGroup2D, x: float, y: float, w: float, h: float, paint: Paint2D, zOrder: int = 0): RenderGroup2D:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut g: RenderGroup2D, x: float, y: float, w: float, h: float, paint: Paint2D, zOrder: int = 0` | **Returns**: `RenderGroup2D`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `renderGroup2DAddRect` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `g: RenderGroup2D = RenderGroup2D(id = "aipl_test", transform = Transform2D(tx = 1.0, ty = 1.0, rotRad = 1.0, sx = 1.0, sy = 1.0), visible = true, opacity = 1.0, commands = [RenderCommand2D(kind = 0, x = 0, y = 0, w = 0, h = 0, radius = 0, text = 0, zOrder = 0, paint = 0)])`, `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`, `paint: Paint2D = Paint2D(fillColor = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), strokeColor = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), strokeWidth = 0.016667, blendMode = 64, antiAlias = true)`, `zOrder: int = 1`; exercises core body path returning/computing `g`.

```aipl
module tests.functions.gfx2d.shape2d_z171_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_renderGroup2DAddRect_171(): int:
  let arg_g = RenderGroup2D(id = "test", transform = Transform2D(tx = 1.0, ty = 1.0, rotRad = 1.0, sx = 1.0, sy = 1.0), visible = true, opacity = 1.0, commands = [])
  let edge_g = RenderGroup2D(id = "a", transform = Transform2D(tx = 0.5, ty = 0.5, rotRad = 0.5, sx = 0.5, sy = 0.5), visible = false, opacity = 0.5, commands = [])
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let arg_paint = Paint2D(fillColor = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), strokeColor = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), strokeWidth = 2.0, blendMode = 4, antiAlias = true)
  let edge_paint = Paint2D(fillColor = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5), strokeColor = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5), strokeWidth = 1.0, blendMode = 1, antiAlias = false)
  let arg_zOrder = 1
  let edge_zOrder = 0
  let resNom = renderGroup2DAddRect(arg_g, arg_x, arg_y, arg_w, arg_h, arg_paint, arg_zOrder)
  let resEdge = renderGroup2DAddRect(edge_g, edge_x, edge_y, edge_w, edge_h, edge_paint, edge_zOrder)
  assertEqStr(resNom.id, "test", "renderGroup2DAddRect nominal string matches")
  assertEqStr(resEdge.id, "a", "renderGroup2DAddRect boundary string matches")
  ret 0
```

---

### `renderGroup2DAddCircle` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn renderGroup2DAddCircle(mut g: RenderGroup2D, cx: float, cy: float, r: float, paint: Paint2D, zOrder: int = 0): RenderGroup2D:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut g: RenderGroup2D, cx: float, cy: float, r: float, paint: Paint2D, zOrder: int = 0` | **Returns**: `RenderGroup2D`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `renderGroup2DAddCircle` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `g: RenderGroup2D = RenderGroup2D(id = "aipl_test", transform = Transform2D(tx = 1.0, ty = 1.0, rotRad = 1.0, sx = 1.0, sy = 1.0), visible = true, opacity = 1.0, commands = [RenderCommand2D(kind = 0, x = 0, y = 0, w = 0, h = 0, radius = 0, text = 0, zOrder = 0, paint = 0)])`, `cx: float = 1.0`, `cy: float = 1.0`, `r: float = 1.0`, `paint: Paint2D = Paint2D(fillColor = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), strokeColor = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), strokeWidth = 0.016667, blendMode = 64, antiAlias = true)`, `zOrder: int = 1`; exercises core body path returning/computing `g`.

```aipl
module tests.functions.gfx2d.shape2d_z172_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_renderGroup2DAddCircle_172(): int:
  let arg_g = RenderGroup2D(id = "test", transform = Transform2D(tx = 1.0, ty = 1.0, rotRad = 1.0, sx = 1.0, sy = 1.0), visible = true, opacity = 1.0, commands = [])
  let edge_g = RenderGroup2D(id = "a", transform = Transform2D(tx = 0.5, ty = 0.5, rotRad = 0.5, sx = 0.5, sy = 0.5), visible = false, opacity = 0.5, commands = [])
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_cy = 1.0
  let edge_cy = 0.5
  let arg_r = 1.0
  let edge_r = 0.5
  let arg_paint = Paint2D(fillColor = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), strokeColor = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0), strokeWidth = 2.0, blendMode = 4, antiAlias = true)
  let edge_paint = Paint2D(fillColor = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5), strokeColor = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5), strokeWidth = 1.0, blendMode = 1, antiAlias = false)
  let arg_zOrder = 1
  let edge_zOrder = 0
  let resNom = renderGroup2DAddCircle(arg_g, arg_cx, arg_cy, arg_r, arg_paint, arg_zOrder)
  let resEdge = renderGroup2DAddCircle(edge_g, edge_cx, edge_cy, edge_r, edge_paint, edge_zOrder)
  assertEqStr(resNom.id, "test", "renderGroup2DAddCircle nominal string matches")
  assertEqStr(resEdge.id, "a", "renderGroup2DAddCircle boundary string matches")
  ret 0
```

---

### `renderGroup2DFlush` (`std/gfx2d/shape2d.aipl`)

- **Signature**: `pub fn renderGroup2DFlush(g: RenderGroup2D): int:`
- **Import**: `import * from "std/gfx2d/shape2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `g: RenderGroup2D` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/shape2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `renderGroup2DFlush` software/X11 canvas primitive rasterization (`getPixel` readback), tessellation vertex/triangle counts, and window IPC telemetry. Concrete nominal inputs: `g: RenderGroup2D = RenderGroup2D(id = "aipl_test", transform = Transform2D(tx = 1.0, ty = 1.0, rotRad = 1.0, sx = 1.0, sy = 1.0), visible = true, opacity = 1.0, commands = [RenderCommand2D(kind = 0, x = 0, y = 0, w = 0, h = 0, radius = 0, text = 0, zOrder = 0, paint = 0)])`; exercises core body path returning/computing `drawn`.

```aipl
module tests.functions.gfx2d.shape2d_z173_test
import * from "std/gfx2d/shape2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { BatchVertex2D } from "std/gfx2d/batch2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_shape2d_renderGroup2DFlush_173(): int:
  let arg_g = RenderGroup2D(id = "test", transform = Transform2D(tx = 1.0, ty = 1.0, rotRad = 1.0, sx = 1.0, sy = 1.0), visible = true, opacity = 1.0, commands = [])
  let edge_g = RenderGroup2D(id = "a", transform = Transform2D(tx = 0.5, ty = 0.5, rotRad = 0.5, sx = 0.5, sy = 0.5), visible = false, opacity = 0.5, commands = [])
  let resNom = renderGroup2DFlush(arg_g)
  let resEdge = renderGroup2DFlush(edge_g)
  assertEqInt(resNom, 0, "renderGroup2DFlush nominal resNom == 0")
  assertEqInt(resEdge, 0, "renderGroup2DFlush boundary resEdge == 0")
  ret 0
```

---

### `updateSkeletonTransforms2D` (`std/gfx2d/skeletal2d.aipl`)

- **Signature**: `pub fn updateSkeletonTransforms2D(skel: Skeleton2D): Skeleton2D:`
- **Import**: `import * from "std/gfx2d/skeletal2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `skel: Skeleton2D` | **Returns**: `Skeleton2D`
- **Unit Test**: `tests/functions/gfx2d/skeletal2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `updateSkeletonTransforms2D` 2D forward kinematics (`FK`) transform chain and Two-Bone / FABRIK inverse kinematics (`IK`) end-effector convergence. Concrete nominal inputs: `skel: Skeleton2D = Skeleton2D(bones = [Bone2D(name = 0, length = 0, localAngleRad = 0, worldPosition = 0, worldAngleRad = 0, parentIdx = 0, localAngleDeg = 0)])`; exercises core body path returning/computing `Skeleton2D(bones = out)`.

```aipl
module tests.functions.gfx2d.skeletal2d_z1_test
import * from "std/gfx2d/skeletal2d"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_skeletal2d_updateSkeletonTransforms2D_1(): int:
  let arg_skel = Skeleton2D(bones = [])
  let edge_skel = Skeleton2D(bones = [])
  let resNom = updateSkeletonTransforms2D(arg_skel)
  let resEdge = updateSkeletonTransforms2D(edge_skel)
  assertEqInt(resNom.bones.len(), 0, "updateSkeletonTransforms2D nominal resNom.bones.len() == 0")
  assertEqInt(resEdge.bones.len(), 0, "updateSkeletonTransforms2D boundary resEdge.bones.len() == 0")
  ret 0
```

---

### `clampCosIk` (`std/gfx2d/skeletal2d.aipl`)

- **Signature**: `fn clampCosIk(v: float): float:`
- **Import**: `import * from "std/gfx2d/skeletal2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/skeletal2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `clampCosIk` 2D forward kinematics (`FK`) transform chain and Two-Bone / FABRIK inverse kinematics (`IK`) end-effector convergence. Concrete nominal inputs: `v: float = 1.0`; exercises core body path returning/computing `v`.

```aipl
module tests.functions.gfx2d.skeletal2d_z2_test
import * from "std/gfx2d/skeletal2d"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_skeletal2d_clampCosIk_2(): int:
  let arg_v = 1.0
  let edge_v = 0.5
  let resNom = clampCosIk(arg_v)
  let resEdge = clampCosIk(edge_v)
  assertApproxEq(resNom, 1.0, 0.001, "clampCosIk nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "clampCosIk boundary resEdge ~= 0.5")
  ret 0
```

---

### `solveTwoBoneIk2D` (`std/gfx2d/skeletal2d.aipl`)

- **Signature**: `pub fn solveTwoBoneIk2D(rootPos: Vec2, targetPos: Vec2, length1: float, length2: float, flipElbow: bool = false): IkSolution2D:`
- **Import**: `import * from "std/gfx2d/skeletal2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rootPos: Vec2, targetPos: Vec2, length1: float, length2: float, flipElbow: bool = false` | **Returns**: `IkSolution2D`
- **Unit Test**: `tests/functions/gfx2d/skeletal2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `solveTwoBoneIk2D` 2D forward kinematics (`FK`) transform chain and Two-Bone / FABRIK inverse kinematics (`IK`) end-effector convergence. Concrete nominal inputs: `rootPos: Vec2 = Vec2(x = 1.0, y = 1.0)`, `targetPos: Vec2 = Vec2(x = 1.0, y = 1.0)`, `length1: float = 1.0`, `length2: float = 1.0`, `flipElbow: bool = true`; exercises core body path returning/computing `IkSolution2D(`.

```aipl
module tests.functions.gfx2d.skeletal2d_z3_test
import * from "std/gfx2d/skeletal2d"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_skeletal2d_solveTwoBoneIk2D_3(): int:
  let arg_rootPos = Vec2(x = 1.0, y = 1.0)
  let edge_rootPos = Vec2(x = 0.5, y = 0.5)
  let arg_targetPos = Vec2(x = 1.0, y = 1.0)
  let edge_targetPos = Vec2(x = 0.5, y = 0.5)
  let arg_length1 = 2.0
  let edge_length1 = 1.0
  let arg_length2 = 2.0
  let edge_length2 = 1.0
  let arg_flipElbow = true
  let edge_flipElbow = false
  let resNom = solveTwoBoneIk2D(arg_rootPos, arg_targetPos, arg_length1, arg_length2, arg_flipElbow)
  let resEdge = solveTwoBoneIk2D(edge_rootPos, edge_targetPos, edge_length1, edge_length2, edge_flipElbow)
  assertApproxEq(resNom.joint1Angle, 0.0, 0.001, "solveTwoBoneIk2D nominal resNom.joint1Angle ~= 0.0")
  assertApproxEq(resEdge.joint1Angle, 0.0, 0.001, "solveTwoBoneIk2D boundary resEdge.joint1Angle ~= 0.0")
  ret 0
```

---

### `solveChainFK2D` (`std/gfx2d/skeletal2d.aipl`)

- **Signature**: `pub fn solveChainFK2D(rootX: float, rootY: float, bones: [Bone2D]): [float]:`
- **Import**: `import * from "std/gfx2d/skeletal2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rootX: float, rootY: float, bones: [Bone2D]` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/gfx2d/skeletal2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `solveChainFK2D` 2D forward kinematics (`FK`) transform chain and Two-Bone / FABRIK inverse kinematics (`IK`) end-effector convergence. Concrete nominal inputs: `rootX: float = 1.0`, `rootY: float = 1.0`, `bones: [Bone2D] = [Bone2D(name = "aipl_test", length = 1.0, localAngleRad = float = 0.0(), worldPosition = Vec2 = Vec2(x = 0.0, y = 0.0)(), worldAngleRad = float = 0.0(), parentIdx = int = -1(), localAngleDeg = float = 0.0())]`; exercises core body path returning/computing `coords`.

```aipl
module tests.functions.gfx2d.skeletal2d_z4_test
import * from "std/gfx2d/skeletal2d"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_skeletal2d_solveChainFK2D_4(): int:
  let arg_rootX = 1.0
  let edge_rootX = 0.5
  let arg_rootY = 1.0
  let edge_rootY = 0.5
  let arg_bones = [Bone2D(name = "test", length = 2.0, localAngleRad = 0.0, worldPosition = Vec2(x = 1.0, y = 1.0), worldAngleRad = 2.0, parentIdx = 4, localAngleDeg = 0.0)]
  let edge_bones = []
  let resNom = solveChainFK2D(arg_rootX, arg_rootY, arg_bones)
  let resEdge = solveChainFK2D(edge_rootX, edge_rootY, edge_bones)
  assertEqInt(resNom.len(), 4, "solveChainFK2D nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 2, "solveChainFK2D boundary resEdge.len() == 2")
  ret 0
```

---

### `solveTwoBoneIK2D` (`std/gfx2d/skeletal2d.aipl`)

- **Signature**: `pub fn solveTwoBoneIK2D(rootX: float, rootY: float, len1: float, len2: float, targetX: float, targetY: float, bendPositive: bool): [float]:`
- **Import**: `import * from "std/gfx2d/skeletal2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rootX: float, rootY: float, len1: float, len2: float, targetX: float, targetY: float, bendPositive: bool` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/gfx2d/skeletal2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `solveTwoBoneIK2D` 2D forward kinematics (`FK`) transform chain and Two-Bone / FABRIK inverse kinematics (`IK`) end-effector convergence. Concrete nominal inputs: `rootX: float = 1.0`, `rootY: float = 1.0`, `len1: float = 1.0`, `len2: float = 1.0`, `targetX: float = 1.0`, `targetY: float = 1.0`, `bendPositive: bool = true`; exercises core body path returning/computing `[shoulderAngleDeg, elbowAngleDeg, elbowX, elbowY, effectorX, effectorY]`.

```aipl
module tests.functions.gfx2d.skeletal2d_z5_test
import * from "std/gfx2d/skeletal2d"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_skeletal2d_solveTwoBoneIK2D_5(): int:
  let arg_rootX = 1.0
  let edge_rootX = 0.5
  let arg_rootY = 1.0
  let edge_rootY = 0.5
  let arg_len1 = 1.0
  let edge_len1 = 0.5
  let arg_len2 = 1.0
  let edge_len2 = 0.5
  let arg_targetX = 1.0
  let edge_targetX = 0.5
  let arg_targetY = 1.0
  let edge_targetY = 0.5
  let arg_bendPositive = true
  let edge_bendPositive = false
  let resNom = solveTwoBoneIK2D(arg_rootX, arg_rootY, arg_len1, arg_len2, arg_targetX, arg_targetY, arg_bendPositive)
  let resEdge = solveTwoBoneIK2D(edge_rootX, edge_rootY, edge_len1, edge_len2, edge_targetX, edge_targetY, edge_bendPositive)
  assertEqInt(resNom.len(), 6, "solveTwoBoneIK2D nominal resNom.len() == 6")
  assertEqInt(resEdge.len(), 6, "solveTwoBoneIK2D boundary resEdge.len() == 6")
  ret 0
```

---

### `solveSkeletonTreeFK2D` (`std/gfx2d/skeletal2d.aipl`)

- **Signature**: `pub fn solveSkeletonTreeFK2D(rootX: float, rootY: float, mut nodes: [BoneNode2D]): [BoneNode2D]:`
- **Import**: `import * from "std/gfx2d/skeletal2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rootX: float, rootY: float, mut nodes: [BoneNode2D]` | **Returns**: `[BoneNode2D]`
- **Unit Test**: `tests/functions/gfx2d/skeletal2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `solveSkeletonTreeFK2D` 2D forward kinematics (`FK`) transform chain and Two-Bone / FABRIK inverse kinematics (`IK`) end-effector convergence. Concrete nominal inputs: `rootX: float = 1.0`, `rootY: float = 1.0`, `nodes: [BoneNode2D] = [BoneNode2D(name = "aipl_test", parentIndex = 0, length = 1.0, localAngleDeg = 1.0, worldStartX = 1.0, worldStartY = 1.0, worldEndX = 1.0, worldEndY = 1.0, worldAngleDeg = 1.0)]`; exercises core body path returning/computing `nodes`.

```aipl
module tests.functions.gfx2d.skeletal2d_z6_test
import * from "std/gfx2d/skeletal2d"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_skeletal2d_solveSkeletonTreeFK2D_6(): int:
  let arg_rootX = 1.0
  let edge_rootX = 0.5
  let arg_rootY = 1.0
  let edge_rootY = 0.5
  let arg_nodes = [BoneNode2D(name = "test", parentIndex = 4, length = 2.0, localAngleDeg = 0.0, worldStartX = 0.0, worldStartY = 0.0, worldEndX = 2.0, worldEndY = 2.0, worldAngleDeg = 2.0)]
  let edge_nodes = []
  let resNom = solveSkeletonTreeFK2D(arg_rootX, arg_rootY, arg_nodes)
  let resEdge = solveSkeletonTreeFK2D(edge_rootX, edge_rootY, edge_nodes)
  assertEqInt(resNom.len(), 1, "solveSkeletonTreeFK2D nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "solveSkeletonTreeFK2D boundary resEdge.len() == 0")
  ret 0
```

---

### `solveTwoBoneIK2DResult` (`std/gfx2d/skeletal2d.aipl`)

- **Signature**: `pub fn solveTwoBoneIK2DResult(rootX: float, rootY: float, len1: float, len2: float, targetX: float, targetY: float, bendPositive: bool): TwoBoneIKResult:`
- **Import**: `import * from "std/gfx2d/skeletal2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rootX: float, rootY: float, len1: float, len2: float, targetX: float, targetY: float, bendPositive: bool` | **Returns**: `TwoBoneIKResult`
- **Unit Test**: `tests/functions/gfx2d/skeletal2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `solveTwoBoneIK2DResult` 2D forward kinematics (`FK`) transform chain and Two-Bone / FABRIK inverse kinematics (`IK`) end-effector convergence. Concrete nominal inputs: `rootX: float = 1.0`, `rootY: float = 1.0`, `len1: float = 1.0`, `len2: float = 1.0`, `targetX: float = 1.0`, `targetY: float = 1.0`, `bendPositive: bool = true`; exercises core body path returning/computing `TwoBoneIKResult(`.

```aipl
module tests.functions.gfx2d.skeletal2d_z7_test
import * from "std/gfx2d/skeletal2d"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_skeletal2d_solveTwoBoneIK2DResult_7(): int:
  let arg_rootX = 1.0
  let edge_rootX = 0.5
  let arg_rootY = 1.0
  let edge_rootY = 0.5
  let arg_len1 = 1.0
  let edge_len1 = 0.5
  let arg_len2 = 1.0
  let edge_len2 = 0.5
  let arg_targetX = 1.0
  let edge_targetX = 0.5
  let arg_targetY = 1.0
  let edge_targetY = 0.5
  let arg_bendPositive = true
  let edge_bendPositive = false
  let resNom = solveTwoBoneIK2DResult(arg_rootX, arg_rootY, arg_len1, arg_len2, arg_targetX, arg_targetY, arg_bendPositive)
  let resEdge = solveTwoBoneIK2DResult(edge_rootX, edge_rootY, edge_len1, edge_len2, edge_targetX, edge_targetY, edge_bendPositive)
  assertApproxEq(resNom.shoulderAngleDeg, -89.9714, 0.001, "solveTwoBoneIK2DResult nominal resNom.shoulderAngleDeg ~= -89.9714")
  assertApproxEq(resEdge.shoulderAngleDeg, 89.9427, 0.001, "solveTwoBoneIK2DResult boundary resEdge.shoulderAngleDeg ~= 89.9427")
  ret 0
```

---

### `solveTwoBoneIK2DEx` (`std/gfx2d/skeletal2d.aipl`)

- **Signature**: `pub fn solveTwoBoneIK2DEx(rootX: float, rootY: float, len1: float, len2: float, targetX: float, targetY: float, bendPositive: bool): TwoBoneIKResult:`
- **Import**: `import * from "std/gfx2d/skeletal2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rootX: float, rootY: float, len1: float, len2: float, targetX: float, targetY: float, bendPositive: bool` | **Returns**: `TwoBoneIKResult`
- **Unit Test**: `tests/functions/gfx2d/skeletal2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `solveTwoBoneIK2DEx` 2D forward kinematics (`FK`) transform chain and Two-Bone / FABRIK inverse kinematics (`IK`) end-effector convergence. Concrete nominal inputs: `rootX: float = 1.0`, `rootY: float = 1.0`, `len1: float = 1.0`, `len2: float = 1.0`, `targetX: float = 1.0`, `targetY: float = 1.0`, `bendPositive: bool = true`; exercises core body path returning/computing `solveTwoBoneIK2DResult(rootX, rootY, len1, len2, targetX, targetY, bendPositive)`.

```aipl
module tests.functions.gfx2d.skeletal2d_z8_test
import * from "std/gfx2d/skeletal2d"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_skeletal2d_solveTwoBoneIK2DEx_8(): int:
  let arg_rootX = 1.0
  let edge_rootX = 0.5
  let arg_rootY = 1.0
  let edge_rootY = 0.5
  let arg_len1 = 1.0
  let edge_len1 = 0.5
  let arg_len2 = 1.0
  let edge_len2 = 0.5
  let arg_targetX = 1.0
  let edge_targetX = 0.5
  let arg_targetY = 1.0
  let edge_targetY = 0.5
  let arg_bendPositive = true
  let edge_bendPositive = false
  let resNom = solveTwoBoneIK2DEx(arg_rootX, arg_rootY, arg_len1, arg_len2, arg_targetX, arg_targetY, arg_bendPositive)
  let resEdge = solveTwoBoneIK2DEx(edge_rootX, edge_rootY, edge_len1, edge_len2, edge_targetX, edge_targetY, edge_bendPositive)
  assertApproxEq(resNom.shoulderAngleDeg, -89.9714, 0.001, "solveTwoBoneIK2DEx nominal resNom.shoulderAngleDeg ~= -89.9714")
  assertApproxEq(resEdge.shoulderAngleDeg, 89.9427, 0.001, "solveTwoBoneIK2DEx boundary resEdge.shoulderAngleDeg ~= 89.9427")
  ret 0
```

---

### `solveFABRIK2D` (`std/gfx2d/skeletal2d.aipl`)

- **Signature**: `pub fn solveFABRIK2D(mut joints: [float], targetX: float, targetY: float, iterations: int, tolerance: float): [float]:`
- **Import**: `import * from "std/gfx2d/skeletal2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut joints: [float], targetX: float, targetY: float, iterations: int, tolerance: float` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/gfx2d/skeletal2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `solveFABRIK2D` 2D forward kinematics (`FK`) transform chain and Two-Bone / FABRIK inverse kinematics (`IK`) end-effector convergence. Concrete nominal inputs: `joints: [float] = [1.0]`, `targetX: float = 1.0`, `targetY: float = 1.0`, `iterations: int = 1`, `tolerance: float = 1.0`; exercises core body path returning/computing `joints`.

```aipl
module tests.functions.gfx2d.skeletal2d_z9_test
import * from "std/gfx2d/skeletal2d"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_skeletal2d_solveFABRIK2D_9(): int:
  let arg_joints = [1.0]
  let edge_joints = []
  let arg_targetX = 1.0
  let edge_targetX = 0.5
  let arg_targetY = 1.0
  let edge_targetY = 0.5
  let arg_iterations = 4
  let edge_iterations = 1
  let arg_tolerance = 1.0
  let edge_tolerance = 0.5
  let resNom = solveFABRIK2D(arg_joints, arg_targetX, arg_targetY, arg_iterations, arg_tolerance)
  let resEdge = solveFABRIK2D(edge_joints, edge_targetX, edge_targetY, edge_iterations, edge_tolerance)
  assertEqInt(resNom.len(), 1, "solveFABRIK2D nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "solveFABRIK2D boundary resEdge.len() == 0")
  ret 0
```

---

### `createSprite2D` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn createSprite2D(textureId: int, w: float, h: float): Sprite2D:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `textureId: int, w: float, h: float` | **Returns**: `Sprite2D`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `createSprite2D` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: `textureId: int = 1`, `w: float = 1.0`, `h: float = 1.0`; exercises core body path returning/computing `Sprite2D(`.

```aipl
module tests.functions.gfx2d.sprite2d_z1_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_createSprite2D_1(): int:
  let arg_textureId = 1
  let edge_textureId = 0
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let resNom = createSprite2D(arg_textureId, arg_w, arg_h)
  let resEdge = createSprite2D(edge_textureId, edge_w, edge_h)
  assertEqInt(resNom.textureId, 1, "createSprite2D nominal resNom.textureId == 1")
  assertEqInt(resEdge.textureId, 0, "createSprite2D boundary resEdge.textureId == 0")
  ret 0
```

---

### `setSpriteUv` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn setSpriteUv(sprite: Sprite2D, uv: UvRect): Sprite2D:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sprite: Sprite2D, uv: UvRect` | **Returns**: `Sprite2D`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `setSpriteUv` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: `sprite: Sprite2D = Sprite2D(textureId = 1, uv = UvRect(u0 = 1.0, v0 = 1.0, u1 = 1.0, v1 = 1.0), size = Vec2(x = 1.0, y = 1.0), origin = SpriteOrigin(xRatio = 0.5, yRatio = 0.5), position = Vec2(x = 1.0, y = 1.0), rotationRad = 1.0, scale = Vec2(x = 1.0, y = 1.0), tint = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255()), flipX = true, flipY = true, zOrder = 1)`, `uv: UvRect = UvRect(u0 = 1.0, v0 = 1.0, u1 = 1.0, v1 = 1.0)`; exercises core body path returning/computing `Sprite2D(`.

```aipl
module tests.functions.gfx2d.sprite2d_z2_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_setSpriteUv_2(): int:
  let arg_sprite = Sprite2D(textureId = 1, uv = UvRect(u0 = 1.0, v0 = 1.0, u1 = 1.0, v1 = 1.0), size = Vec2(x = 1.0, y = 1.0), origin = SpriteOrigin(xRatio = 1.0, yRatio = 1.0), position = Vec2(x = 1.0, y = 1.0), rotationRad = 1.0, scale = Vec2(x = 1.0, y = 1.0), tint = ColorRgba8(r = 2, g = 2, b = 4, a = 2), flipX = true, flipY = true, zOrder = 1)
  let edge_sprite = Sprite2D(textureId = 0, uv = UvRect(u0 = 0.5, v0 = 0.5, u1 = 0.5, v1 = 0.5), size = Vec2(x = 0.5, y = 0.5), origin = SpriteOrigin(xRatio = 0.5, yRatio = 0.5), position = Vec2(x = 0.5, y = 0.5), rotationRad = 0.5, scale = Vec2(x = 0.5, y = 0.5), tint = ColorRgba8(r = 0, g = 0, b = 1, a = 0), flipX = false, flipY = false, zOrder = 0)
  let arg_uv = UvRect(u0 = 1.0, v0 = 1.0, u1 = 1.0, v1 = 1.0)
  let edge_uv = UvRect(u0 = 0.5, v0 = 0.5, u1 = 0.5, v1 = 0.5)
  let resNom = setSpriteUv(arg_sprite, arg_uv)
  let resEdge = setSpriteUv(edge_sprite, edge_uv)
  assertEqInt(resNom.textureId, 1, "setSpriteUv nominal resNom.textureId == 1")
  assertEqInt(resEdge.textureId, 0, "setSpriteUv boundary resEdge.textureId == 0")
  ret 0
```

---

### `computeSpriteCorners` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn computeSpriteCorners(sprite: Sprite2D): [Vec2]:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sprite: Sprite2D` | **Returns**: `[Vec2]`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `computeSpriteCorners` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: `sprite: Sprite2D = Sprite2D(textureId = 1, uv = UvRect(u0 = 1.0, v0 = 1.0, u1 = 1.0, v1 = 1.0), size = Vec2(x = 1.0, y = 1.0), origin = SpriteOrigin(xRatio = 0.5, yRatio = 0.5), position = Vec2(x = 1.0, y = 1.0), rotationRad = 1.0, scale = Vec2(x = 1.0, y = 1.0), tint = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255()), flipX = true, flipY = true, zOrder = 1)`; exercises core body path returning/computing `[p0, p1, p2, p3]`.

```aipl
module tests.functions.gfx2d.sprite2d_z3_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_computeSpriteCorners_3(): int:
  let arg_sprite = Sprite2D(textureId = 1, uv = UvRect(u0 = 1.0, v0 = 1.0, u1 = 1.0, v1 = 1.0), size = Vec2(x = 1.0, y = 1.0), origin = SpriteOrigin(xRatio = 1.0, yRatio = 1.0), position = Vec2(x = 1.0, y = 1.0), rotationRad = 1.0, scale = Vec2(x = 1.0, y = 1.0), tint = ColorRgba8(r = 2, g = 2, b = 4, a = 2), flipX = true, flipY = true, zOrder = 1)
  let edge_sprite = Sprite2D(textureId = 0, uv = UvRect(u0 = 0.5, v0 = 0.5, u1 = 0.5, v1 = 0.5), size = Vec2(x = 0.5, y = 0.5), origin = SpriteOrigin(xRatio = 0.5, yRatio = 0.5), position = Vec2(x = 0.5, y = 0.5), rotationRad = 0.5, scale = Vec2(x = 0.5, y = 0.5), tint = ColorRgba8(r = 0, g = 0, b = 1, a = 0), flipX = false, flipY = false, zOrder = 0)
  let resNom = computeSpriteCorners(arg_sprite)
  let resEdge = computeSpriteCorners(edge_sprite)
  assertEqInt(resNom.len(), 4, "computeSpriteCorners nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 4, "computeSpriteCorners boundary resEdge.len() == 4")
  ret 0
```

---

### `clamp01` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn clamp01(t: float): float:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `clamp01` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `t`.

```aipl
module tests.functions.gfx2d.sprite2d_z4_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_clamp01_4(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = clamp01(arg_t)
  let resEdge = clamp01(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "clamp01 nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "clamp01 boundary resEdge ~= 0.5")
  ret 0
```

---

### `lerpFloat` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn lerpFloat(a: float, b: float, t: float): float:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: float, b: float, t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `lerpFloat` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: `a: float = 1.0`, `b: float = 1.0`, `t: float = 0.5`; exercises core body path returning/computing `a + (b - a) * t`.

```aipl
module tests.functions.gfx2d.sprite2d_z5_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_lerpFloat_5(): int:
  let arg_a = 1.0
  let edge_a = 0.5
  let arg_b = 1.0
  let edge_b = 0.5
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = lerpFloat(arg_a, arg_b, arg_t)
  let resEdge = lerpFloat(edge_a, edge_b, edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "lerpFloat nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "lerpFloat boundary resEdge ~= 0.5")
  ret 0
```

---

### `easeTypeLinear` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn easeTypeLinear(): int:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `easeTypeLinear` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `0`.

```aipl
module tests.functions.gfx2d.sprite2d_z6_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_easeTypeLinear_6(): int:
  let resNom = easeTypeLinear()
  let resEdge = easeTypeLinear()
  assertEqInt(resNom, 0, "easeTypeLinear nominal resNom == 0")
  assertEqInt(resEdge, 0, "easeTypeLinear boundary resEdge == 0")
  ret 0
```

---

### `easeTypeInQuad` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn easeTypeInQuad(): int:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `easeTypeInQuad` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `1`.

```aipl
module tests.functions.gfx2d.sprite2d_z7_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_easeTypeInQuad_7(): int:
  let resNom = easeTypeInQuad()
  let resEdge = easeTypeInQuad()
  assertEqInt(resNom, 1, "easeTypeInQuad nominal resNom == 1")
  assertEqInt(resEdge, 1, "easeTypeInQuad boundary resEdge == 1")
  ret 0
```

---

### `easeTypeOutQuad` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn easeTypeOutQuad(): int:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `easeTypeOutQuad` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `2`.

```aipl
module tests.functions.gfx2d.sprite2d_z8_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_easeTypeOutQuad_8(): int:
  let resNom = easeTypeOutQuad()
  let resEdge = easeTypeOutQuad()
  assertEqInt(resNom, 2, "easeTypeOutQuad nominal resNom == 2")
  assertEqInt(resEdge, 2, "easeTypeOutQuad boundary resEdge == 2")
  ret 0
```

---

### `easeTypeInOutQuad` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn easeTypeInOutQuad(): int:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `easeTypeInOutQuad` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `3`.

```aipl
module tests.functions.gfx2d.sprite2d_z9_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_easeTypeInOutQuad_9(): int:
  let resNom = easeTypeInOutQuad()
  let resEdge = easeTypeInOutQuad()
  assertEqInt(resNom, 3, "easeTypeInOutQuad nominal resNom == 3")
  assertEqInt(resEdge, 3, "easeTypeInOutQuad boundary resEdge == 3")
  ret 0
```

---

### `easeTypeInCubic` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn easeTypeInCubic(): int:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `easeTypeInCubic` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `4`.

```aipl
module tests.functions.gfx2d.sprite2d_z10_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_easeTypeInCubic_10(): int:
  let resNom = easeTypeInCubic()
  let resEdge = easeTypeInCubic()
  assertEqInt(resNom, 4, "easeTypeInCubic nominal resNom == 4")
  assertEqInt(resEdge, 4, "easeTypeInCubic boundary resEdge == 4")
  ret 0
```

---

### `easeTypeOutCubic` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn easeTypeOutCubic(): int:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `easeTypeOutCubic` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `5`.

```aipl
module tests.functions.gfx2d.sprite2d_z11_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_easeTypeOutCubic_11(): int:
  let resNom = easeTypeOutCubic()
  let resEdge = easeTypeOutCubic()
  assertEqInt(resNom, 5, "easeTypeOutCubic nominal resNom == 5")
  assertEqInt(resEdge, 5, "easeTypeOutCubic boundary resEdge == 5")
  ret 0
```

---

### `easeTypeInOutCubic` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn easeTypeInOutCubic(): int:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `easeTypeInOutCubic` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `6`.

```aipl
module tests.functions.gfx2d.sprite2d_z12_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_easeTypeInOutCubic_12(): int:
  let resNom = easeTypeInOutCubic()
  let resEdge = easeTypeInOutCubic()
  assertEqInt(resNom, 6, "easeTypeInOutCubic nominal resNom == 6")
  assertEqInt(resEdge, 6, "easeTypeInOutCubic boundary resEdge == 6")
  ret 0
```

---

### `easeTypeInSine` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn easeTypeInSine(): int:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `easeTypeInSine` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `7`.

```aipl
module tests.functions.gfx2d.sprite2d_z13_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_easeTypeInSine_13(): int:
  let resNom = easeTypeInSine()
  let resEdge = easeTypeInSine()
  assertEqInt(resNom, 7, "easeTypeInSine nominal resNom == 7")
  assertEqInt(resEdge, 7, "easeTypeInSine boundary resEdge == 7")
  ret 0
```

---

### `easeTypeOutSine` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn easeTypeOutSine(): int:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `easeTypeOutSine` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `8`.

```aipl
module tests.functions.gfx2d.sprite2d_z14_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_easeTypeOutSine_14(): int:
  let resNom = easeTypeOutSine()
  let resEdge = easeTypeOutSine()
  assertEqInt(resNom, 8, "easeTypeOutSine nominal resNom == 8")
  assertEqInt(resEdge, 8, "easeTypeOutSine boundary resEdge == 8")
  ret 0
```

---

### `easeTypeInOutSine` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn easeTypeInOutSine(): int:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `easeTypeInOutSine` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `9`.

```aipl
module tests.functions.gfx2d.sprite2d_z15_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_easeTypeInOutSine_15(): int:
  let resNom = easeTypeInOutSine()
  let resEdge = easeTypeInOutSine()
  assertEqInt(resNom, 9, "easeTypeInOutSine nominal resNom == 9")
  assertEqInt(resEdge, 9, "easeTypeInOutSine boundary resEdge == 9")
  ret 0
```

---

### `easeTypeOutBounce` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn easeTypeOutBounce(): int:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `easeTypeOutBounce` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `10`.

```aipl
module tests.functions.gfx2d.sprite2d_z16_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_easeTypeOutBounce_16(): int:
  let resNom = easeTypeOutBounce()
  let resEdge = easeTypeOutBounce()
  assertEqInt(resNom, 10, "easeTypeOutBounce nominal resNom == 10")
  assertEqInt(resEdge, 10, "easeTypeOutBounce boundary resEdge == 10")
  ret 0
```

---

### `easeTypeInBounce` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn easeTypeInBounce(): int:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `easeTypeInBounce` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `11`.

```aipl
module tests.functions.gfx2d.sprite2d_z17_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_easeTypeInBounce_17(): int:
  let resNom = easeTypeInBounce()
  let resEdge = easeTypeInBounce()
  assertEqInt(resNom, 11, "easeTypeInBounce nominal resNom == 11")
  assertEqInt(resEdge, 11, "easeTypeInBounce boundary resEdge == 11")
  ret 0
```

---

### `easeTypeInOutBounce` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn easeTypeInOutBounce(): int:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `easeTypeInOutBounce` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `12`.

```aipl
module tests.functions.gfx2d.sprite2d_z18_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_easeTypeInOutBounce_18(): int:
  let resNom = easeTypeInOutBounce()
  let resEdge = easeTypeInOutBounce()
  assertEqInt(resNom, 12, "easeTypeInOutBounce nominal resNom == 12")
  assertEqInt(resEdge, 12, "easeTypeInOutBounce boundary resEdge == 12")
  ret 0
```

---

### `easeTypeOutElastic` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn easeTypeOutElastic(): int:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `easeTypeOutElastic` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `13`.

```aipl
module tests.functions.gfx2d.sprite2d_z19_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_easeTypeOutElastic_19(): int:
  let resNom = easeTypeOutElastic()
  let resEdge = easeTypeOutElastic()
  assertEqInt(resNom, 13, "easeTypeOutElastic nominal resNom == 13")
  assertEqInt(resEdge, 13, "easeTypeOutElastic boundary resEdge == 13")
  ret 0
```

---

### `easeTypeInElastic` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn easeTypeInElastic(): int:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `easeTypeInElastic` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `14`.

```aipl
module tests.functions.gfx2d.sprite2d_z20_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_easeTypeInElastic_20(): int:
  let resNom = easeTypeInElastic()
  let resEdge = easeTypeInElastic()
  assertEqInt(resNom, 14, "easeTypeInElastic nominal resNom == 14")
  assertEqInt(resEdge, 14, "easeTypeInElastic boundary resEdge == 14")
  ret 0
```

---

### `easeTypeInOutElastic` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn easeTypeInOutElastic(): int:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `easeTypeInOutElastic` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `15`.

```aipl
module tests.functions.gfx2d.sprite2d_z21_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_easeTypeInOutElastic_21(): int:
  let resNom = easeTypeInOutElastic()
  let resEdge = easeTypeInOutElastic()
  assertEqInt(resNom, 15, "easeTypeInOutElastic nominal resNom == 15")
  assertEqInt(resEdge, 15, "easeTypeInOutElastic boundary resEdge == 15")
  ret 0
```

---

### `easeInSine` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn easeInSine(t: float): float:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `easeInSine` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `1.0 - cos((u * pi()) / 2.0)`.

```aipl
module tests.functions.gfx2d.sprite2d_z22_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_easeInSine_22(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeInSine(arg_t)
  let resEdge = easeInSine(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeInSine nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.292893, 0.001, "easeInSine boundary resEdge ~= 0.292893")
  ret 0
```

---

### `easeOutSine` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn easeOutSine(t: float): float:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `easeOutSine` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `sin((u * pi()) / 2.0)`.

```aipl
module tests.functions.gfx2d.sprite2d_z23_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_easeOutSine_23(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeOutSine(arg_t)
  let resEdge = easeOutSine(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeOutSine nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.707107, 0.001, "easeOutSine boundary resEdge ~= 0.707107")
  ret 0
```

---

### `easeInOutSine` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn easeInOutSine(t: float): float:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `easeInOutSine` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `-0.5 * (cos(pi() * u) - 1.0)`.

```aipl
module tests.functions.gfx2d.sprite2d_z24_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_easeInOutSine_24(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeInOutSine(arg_t)
  let resEdge = easeInOutSine(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeInOutSine nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "easeInOutSine boundary resEdge ~= 0.5")
  ret 0
```

---

### `easeByName` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn easeByName(name: str, t: float): float:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `name: str, t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `easeByName` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: `name: str = "aipl_test"`, `t: float = 0.5`; exercises core body path returning/computing `easeLinear(t)`.

```aipl
module tests.functions.gfx2d.sprite2d_z25_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_easeByName_25(): int:
  let arg_name = "test"
  let edge_name = "a"
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeByName(arg_name, arg_t)
  let resEdge = easeByName(edge_name, edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeByName nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "easeByName boundary resEdge ~= 0.5")
  ret 0
```

---

### `tweenNew` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn tweenNew(startVal: float, endVal: float, durationMs: float, easing: str, looping: bool = false, pingPong: bool = false): Tween:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `startVal: float, endVal: float, durationMs: float, easing: str, looping: bool = false, pingPong: bool = false` | **Returns**: `Tween`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `tweenNew` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: `startVal: float = 1.0`, `endVal: float = 1.0`, `durationMs: float = 0.5`, `easing: str = "aipl_test"`, `looping: bool = true`, `pingPong: bool = true`; exercises core body path returning/computing `Tween(`.

```aipl
module tests.functions.gfx2d.sprite2d_z26_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_tweenNew_26(): int:
  let arg_startVal = 0.0
  let edge_startVal = 0.0
  let arg_endVal = 2.0
  let edge_endVal = 1.0
  let arg_durationMs = 1.0
  let edge_durationMs = 0.5
  let arg_easing = "test"
  let edge_easing = "a"
  let arg_looping = true
  let edge_looping = false
  let arg_pingPong = true
  let edge_pingPong = false
  let resNom = tweenNew(arg_startVal, arg_endVal, arg_durationMs, arg_easing, arg_looping, arg_pingPong)
  let resEdge = tweenNew(edge_startVal, edge_endVal, edge_durationMs, edge_easing, edge_looping, edge_pingPong)
  assertApproxEq(resNom.startVal, 0.0, 0.001, "tweenNew nominal resNom.startVal ~= 0.0")
  assertApproxEq(resEdge.startVal, 0.0, 0.001, "tweenNew boundary resEdge.startVal ~= 0.0")
  ret 0
```

---

### `tweenUpdate` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn tweenUpdate(tw: Tween, dtMs: float): Tween:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `tw: Tween, dtMs: float` | **Returns**: `Tween`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `tweenUpdate` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: `tw: Tween = Tween(startVal = 1.0, endVal = 1.0, durationMs = 0.5, elapsedMs = 1.0, easing = "aipl_test", looping = true, pingPong = true, forward = true, finished = true)`, `dtMs: float = 0.016667`; exercises core body path returning/computing `Tween(`.

```aipl
module tests.functions.gfx2d.sprite2d_z27_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_tweenUpdate_27(): int:
  let arg_tw = Tween(startVal = 0.0, endVal = 2.0, durationMs = 1.0, elapsedMs = 1.0, easing = "test", looping = true, pingPong = true, forward = true, finished = true)
  let edge_tw = Tween(startVal = 0.0, endVal = 1.0, durationMs = 0.5, elapsedMs = 0.5, easing = "a", looping = false, pingPong = false, forward = false, finished = false)
  let arg_dtMs = 2.0
  let edge_dtMs = 1.0
  let resNom = tweenUpdate(arg_tw, arg_dtMs)
  let resEdge = tweenUpdate(edge_tw, edge_dtMs)
  assertApproxEq(resNom.startVal, 0.0, 0.001, "tweenUpdate nominal resNom.startVal ~= 0.0")
  assertApproxEq(resEdge.startVal, 0.0, 0.001, "tweenUpdate boundary resEdge.startVal ~= 0.0")
  ret 0
```

---

### `tweenValue` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn tweenValue(tw: Tween): float:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `tw: Tween` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `tweenValue` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: `tw: Tween = Tween(startVal = 1.0, endVal = 1.0, durationMs = 0.5, elapsedMs = 1.0, easing = "aipl_test", looping = true, pingPong = true, forward = true, finished = true)`; exercises core body path returning/computing `lerpFloat(tw.startVal, tw.endVal, factor)`.

```aipl
module tests.functions.gfx2d.sprite2d_z28_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_tweenValue_28(): int:
  let arg_tw = Tween(startVal = 0.0, endVal = 2.0, durationMs = 1.0, elapsedMs = 1.0, easing = "test", looping = true, pingPong = true, forward = true, finished = true)
  let edge_tw = Tween(startVal = 0.0, endVal = 1.0, durationMs = 0.5, elapsedMs = 0.5, easing = "a", looping = false, pingPong = false, forward = false, finished = false)
  let resNom = tweenValue(arg_tw)
  let resEdge = tweenValue(edge_tw)
  assertApproxEq(resNom, 2.0, 0.001, "tweenValue nominal resNom ~= 2.0")
  assertApproxEq(resEdge, 1.0, 0.001, "tweenValue boundary resEdge ~= 1.0")
  ret 0
```

---

### `applyEasing` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn applyEasing(t: float, easingType: int): float:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float, easingType: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `applyEasing` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: `t: float = 0.5`, `easingType: int = 1`; exercises core body path returning/computing `easeLinear(t)`.

```aipl
module tests.functions.gfx2d.sprite2d_z29_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_applyEasing_29(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let arg_easingType = 4
  let edge_easingType = 1
  let resNom = applyEasing(arg_t, arg_easingType)
  let resEdge = applyEasing(edge_t, edge_easingType)
  assertApproxEq(resNom, 1.0, 0.001, "applyEasing nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.25, 0.001, "applyEasing boundary resEdge ~= 0.25")
  ret 0
```

---

### `tweenFloat` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn tweenFloat(startVal: float, endVal: float, t: float, easingType: int): float:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `startVal: float, endVal: float, t: float, easingType: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `tweenFloat` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: `startVal: float = 1.0`, `endVal: float = 1.0`, `t: float = 0.5`, `easingType: int = 1`; exercises core body path returning/computing `lerpFloat(startVal, endVal, easedT)`.

```aipl
module tests.functions.gfx2d.sprite2d_z30_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_tweenFloat_30(): int:
  let arg_startVal = 0.0
  let edge_startVal = 0.0
  let arg_endVal = 2.0
  let edge_endVal = 1.0
  let arg_t = 1.0
  let edge_t = 0.5
  let arg_easingType = 4
  let edge_easingType = 1
  let resNom = tweenFloat(arg_startVal, arg_endVal, arg_t, arg_easingType)
  let resEdge = tweenFloat(edge_startVal, edge_endVal, edge_t, edge_easingType)
  assertApproxEq(resNom, 2.0, 0.001, "tweenFloat nominal resNom ~= 2.0")
  assertApproxEq(resEdge, 0.25, 0.001, "tweenFloat boundary resEdge ~= 0.25")
  ret 0
```

---

### `tweenColor` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn tweenColor(c1: Color, c2: Color, t: float): Color:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c1: Color, c2: Color, t: float` | **Returns**: `Color`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `tweenColor` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: `c1: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `c2: Color = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `Color(r = r, g = g, b = b, a = a)`.

```aipl
module tests.functions.gfx2d.sprite2d_z31_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_tweenColor_31(): int:
  let arg_c1 = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_c1 = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_c2 = Color(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_c2 = Color(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = tweenColor(arg_c1, arg_c2, arg_t)
  let resEdge = tweenColor(edge_c1, edge_c2, edge_t)
  assertApproxEq(resNom.r, 1.0, 0.001, "tweenColor nominal resNom.r ~= 1.0")
  assertApproxEq(resEdge.r, 0.5, 0.001, "tweenColor boundary resEdge.r ~= 0.5")
  ret 0
```

---

### `polarSquareRadius` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn polarSquareRadius(halfSide: float, angle: float): float:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `halfSide: float, angle: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `polarSquareRadius` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: `halfSide: float = 1.0`, `angle: float = 1.0`; exercises core body path returning/computing `halfSide / denom`.

```aipl
module tests.functions.gfx2d.sprite2d_z32_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_polarSquareRadius_32(): int:
  let arg_halfSide = 2.0
  let edge_halfSide = 1.0
  let arg_angle = 1.0
  let edge_angle = 0.5
  let resNom = polarSquareRadius(arg_halfSide, arg_angle)
  let resEdge = polarSquareRadius(edge_halfSide, edge_angle)
  assertApproxEq(resNom, 2.37679, 0.001, "polarSquareRadius nominal resNom ~= 2.37679")
  assertApproxEq(resEdge, 1.13949, 0.001, "polarSquareRadius boundary resEdge ~= 1.13949")
  ret 0
```

---

### `polarStarRadius` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn polarStarRadius(baseRadius: float, spikeAmp: float, points: int, angle: float): float:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `baseRadius: float, spikeAmp: float, points: int, angle: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `polarStarRadius` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: `baseRadius: float = 1.0`, `spikeAmp: float = 1.0`, `points: int = 1`, `angle: float = 1.0`; exercises core body path returning/computing `baseRadius + spikeAmp * cos(angle * float(points))`.

```aipl
module tests.functions.gfx2d.sprite2d_z33_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_polarStarRadius_33(): int:
  let arg_baseRadius = 2.0
  let edge_baseRadius = 1.0
  let arg_spikeAmp = 1.0
  let edge_spikeAmp = 0.5
  let arg_points = 4
  let edge_points = 1
  let arg_angle = 1.0
  let edge_angle = 0.5
  let resNom = polarStarRadius(arg_baseRadius, arg_spikeAmp, arg_points, arg_angle)
  let resEdge = polarStarRadius(edge_baseRadius, edge_spikeAmp, edge_points, edge_angle)
  assertApproxEq(resNom, 1.34636, 0.001, "polarStarRadius nominal resNom ~= 1.34636")
  assertApproxEq(resEdge, 1.43879, 0.001, "polarStarRadius boundary resEdge ~= 1.43879")
  ret 0
```

---

### `tweenSequenceNew` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn tweenSequenceNew(looping: bool): TweenSequence:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `looping: bool` | **Returns**: `TweenSequence`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `tweenSequenceNew` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: `looping: bool = true`; exercises core body path returning/computing `TweenSequence(steps = emptySteps, currentIndex = 0, looping = looping, finished = false)`.

```aipl
module tests.functions.gfx2d.sprite2d_z34_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_tweenSequenceNew_34(): int:
  let arg_looping = true
  let edge_looping = false
  let resNom = tweenSequenceNew(arg_looping)
  let resEdge = tweenSequenceNew(edge_looping)
  assertEqInt(resNom.steps.len(), 0, "tweenSequenceNew nominal resNom.steps.len() == 0")
  assertEqInt(resEdge.steps.len(), 0, "tweenSequenceNew boundary resEdge.steps.len() == 0")
  ret 0
```

---

### `tweenSequenceAdd` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn tweenSequenceAdd(mut seq: TweenSequence, tw: Tween): TweenSequence:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut seq: TweenSequence, tw: Tween` | **Returns**: `TweenSequence`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `tweenSequenceAdd` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: `seq: TweenSequence = TweenSequence(steps = [Tween(startVal = 0, endVal = 0, durationMs = 0, elapsedMs = 0, easing = 0, looping = 0, pingPong = 0, forward = 0, finished = 0)], currentIndex = 0, looping = true, finished = true)`, `tw: Tween = Tween(startVal = 1.0, endVal = 1.0, durationMs = 0.5, elapsedMs = 1.0, easing = "aipl_test", looping = true, pingPong = true, forward = true, finished = true)`; exercises core body path returning/computing `seq`.

```aipl
module tests.functions.gfx2d.sprite2d_z35_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_tweenSequenceAdd_35(): int:
  let arg_seq = TweenSequence(steps = [], currentIndex = 4, looping = true, finished = true)
  let edge_seq = TweenSequence(steps = [], currentIndex = 1, looping = false, finished = false)
  let arg_tw = Tween(startVal = 0.0, endVal = 2.0, durationMs = 1.0, elapsedMs = 1.0, easing = "test", looping = true, pingPong = true, forward = true, finished = true)
  let edge_tw = Tween(startVal = 0.0, endVal = 1.0, durationMs = 0.5, elapsedMs = 0.5, easing = "a", looping = false, pingPong = false, forward = false, finished = false)
  let resNom = tweenSequenceAdd(arg_seq, arg_tw)
  let resEdge = tweenSequenceAdd(edge_seq, edge_tw)
  assertEqInt(resNom.steps.len(), 1, "tweenSequenceAdd nominal resNom.steps.len() == 1")
  assertEqInt(resEdge.steps.len(), 1, "tweenSequenceAdd boundary resEdge.steps.len() == 1")
  ret 0
```

---

### `stepTweenSequence` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn stepTweenSequence(mut seq: TweenSequence, dtMs: float): TweenSequence:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut seq: TweenSequence, dtMs: float` | **Returns**: `TweenSequence`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `stepTweenSequence` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: `seq: TweenSequence = TweenSequence(steps = [Tween(startVal = 0, endVal = 0, durationMs = 0, elapsedMs = 0, easing = 0, looping = 0, pingPong = 0, forward = 0, finished = 0)], currentIndex = 0, looping = true, finished = true)`, `dtMs: float = 0.016667`; exercises core body path returning/computing `seq`.

```aipl
module tests.functions.gfx2d.sprite2d_z36_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_stepTweenSequence_36(): int:
  let arg_seq = TweenSequence(steps = [], currentIndex = 4, looping = true, finished = true)
  let edge_seq = TweenSequence(steps = [], currentIndex = 1, looping = false, finished = false)
  let arg_dtMs = 2.0
  let edge_dtMs = 1.0
  let resNom = stepTweenSequence(arg_seq, arg_dtMs)
  let resEdge = stepTweenSequence(edge_seq, edge_dtMs)
  assertEqInt(resNom.steps.len(), 0, "stepTweenSequence nominal resNom.steps.len() == 0")
  assertEqInt(resEdge.steps.len(), 0, "stepTweenSequence boundary resEdge.steps.len() == 0")
  ret 0
```

---

### `tweenSequenceValue` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn tweenSequenceValue(seq: TweenSequence): float:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `seq: TweenSequence` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `tweenSequenceValue` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: `seq: TweenSequence = TweenSequence(steps = [Tween(startVal = 0, endVal = 0, durationMs = 0, elapsedMs = 0, easing = 0, looping = 0, pingPong = 0, forward = 0, finished = 0)], currentIndex = 0, looping = true, finished = true)`; exercises core body path returning/computing `tweenValue(seq.steps[idx])`.

```aipl
module tests.functions.gfx2d.sprite2d_z37_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_tweenSequenceValue_37(): int:
  let arg_seq = TweenSequence(steps = [], currentIndex = 4, looping = true, finished = true)
  let edge_seq = TweenSequence(steps = [], currentIndex = 1, looping = false, finished = false)
  let resNom = tweenSequenceValue(arg_seq)
  let resEdge = tweenSequenceValue(edge_seq)
  assertApproxEq(resNom, 0.0, 0.001, "tweenSequenceValue nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "tweenSequenceValue boundary resEdge ~= 0.0")
  ret 0
```

---

### `stepTweenWithMode` (`std/gfx2d/sprite2d.aipl`)

- **Signature**: `pub fn stepTweenWithMode(tw: Tween, dtMs: float, easingType: int): float:`
- **Import**: `import * from "std/gfx2d/sprite2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `tw: Tween, dtMs: float, easingType: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/sprite2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `stepTweenWithMode` (`free fn`) rotated/scaled sprite quad corner geometry, z-order sorting, and multi-step `TweenSequence` interpolation. Concrete nominal inputs: `tw: Tween = Tween(startVal = 1.0, endVal = 1.0, durationMs = 0.5, elapsedMs = 1.0, easing = "aipl_test", looping = true, pingPong = true, forward = true, finished = true)`, `dtMs: float = 0.016667`, `easingType: int = 1`; exercises core body path returning/computing `tweenFloat(updated.startVal, updated.endVal, t, easingType)`.

```aipl
module tests.functions.gfx2d.sprite2d_z38_test
import * from "std/gfx2d/sprite2d"
import { Vec2 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Color, rgba } from "std/gfx2d/shape2d"
import { pi, absFloat, maxFloat } from "std/math/consts"
import { smoothstep, smootherstep, pingPong, easeInQuad, easeOutQuad, easeInOutQuad, easeInCubic, easeOutCubic, easeInOutCubic, easeInQuart, easeOutQuart, easeInOutQuart, easeInBack, easeOutBack, easeInOutBack, easeOutElastic, easeInElastic, easeInOutElastic, easeInBounce, easeOutBounce, easeInOutBounce } from "std/math/ease"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite2d_stepTweenWithMode_38(): int:
  let arg_tw = Tween(startVal = 0.0, endVal = 2.0, durationMs = 1.0, elapsedMs = 1.0, easing = "test", looping = true, pingPong = true, forward = true, finished = true)
  let edge_tw = Tween(startVal = 0.0, endVal = 1.0, durationMs = 0.5, elapsedMs = 0.5, easing = "a", looping = false, pingPong = false, forward = false, finished = false)
  let arg_dtMs = 2.0
  let edge_dtMs = 1.0
  let arg_easingType = 4
  let edge_easingType = 1
  let resNom = stepTweenWithMode(arg_tw, arg_dtMs, arg_easingType)
  let resEdge = stepTweenWithMode(edge_tw, edge_dtMs, edge_easingType)
  assertApproxEq(resNom, 2.0, 0.001, "stepTweenWithMode nominal resNom ~= 2.0")
  assertApproxEq(resEdge, 0.0, 0.001, "stepTweenWithMode boundary resEdge ~= 0.0")
  ret 0
```

---

### `createAnimator2D` (`std/gfx2d/sprite_anim2d.aipl`)

- **Signature**: `pub fn createAnimator2D(clip: SpriteAnimationClip2D): SpriteAnimator2D:`
- **Import**: `import * from "std/gfx2d/sprite_anim2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `clip: SpriteAnimationClip2D` | **Returns**: `SpriteAnimator2D`
- **Unit Test**: `tests/functions/gfx2d/sprite_anim2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `createAnimator2D` sprite animation clip frame advancement across `Once`, `Loop`, and `PingPong` modes and state-machine transitions. Concrete nominal inputs: `clip: SpriteAnimationClip2D = SpriteAnimationClip2D(name = "aipl_test", frames = [SpriteAnimationFrame2D(uv = 0, durationSec = 0, eventTrigger = 0)], loopMode = 1)`; exercises core body path returning/computing `SpriteAnimator2D(`.

```aipl
module tests.functions.gfx2d.sprite_anim2d_z1_test
import * from "std/gfx2d/sprite_anim2d"
import { UvRect } from "std/gfx2d/sprite2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite_anim2d_createAnimator2D_1(): int:
  let arg_clip = SpriteAnimationClip2D(name = "test", frames = [], loopMode = 4)
  let edge_clip = SpriteAnimationClip2D(name = "a", frames = [], loopMode = 1)
  let resNom = createAnimator2D(arg_clip)
  let resEdge = createAnimator2D(edge_clip)
  assertEqInt(resNom.currentFrameIdx, 0, "createAnimator2D nominal resNom.currentFrameIdx == 0")
  assertEqInt(resEdge.currentFrameIdx, 0, "createAnimator2D boundary resEdge.currentFrameIdx == 0")
  ret 0
```

---

### `stepAnimator2D` (`std/gfx2d/sprite_anim2d.aipl`)

- **Signature**: `pub fn stepAnimator2D(anim: SpriteAnimator2D, dt: float): SpriteAnimator2D:`
- **Import**: `import * from "std/gfx2d/sprite_anim2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `anim: SpriteAnimator2D, dt: float` | **Returns**: `SpriteAnimator2D`
- **Unit Test**: `tests/functions/gfx2d/sprite_anim2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `stepAnimator2D` sprite animation clip frame advancement across `Once`, `Loop`, and `PingPong` modes and state-machine transitions. Concrete nominal inputs: `anim: SpriteAnimator2D = SpriteAnimator2D(currentClip = SpriteAnimationClip2D(name = "aipl_test", frames = [0], loopMode = 1), currentFrameIdx = 0, elapsedTimeSec = 0.016667, isPlaying = true, isFinished = true)`, `dt: float = 0.016667`; exercises core body path returning/computing `SpriteAnimator2D(`.

```aipl
module tests.functions.gfx2d.sprite_anim2d_z2_test
import * from "std/gfx2d/sprite_anim2d"
import { UvRect } from "std/gfx2d/sprite2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite_anim2d_stepAnimator2D_2(): int:
  let arg_anim = SpriteAnimator2D(currentClip = SpriteAnimationClip2D(name = "test", frames = [], loopMode = 4), currentFrameIdx = 4, elapsedTimeSec = 2.0, isPlaying = true, isFinished = true)
  let edge_anim = SpriteAnimator2D(currentClip = SpriteAnimationClip2D(name = "a", frames = [], loopMode = 1), currentFrameIdx = 1, elapsedTimeSec = 1.0, isPlaying = false, isFinished = false)
  let arg_dt = 2.0
  let edge_dt = 1.0
  let resNom = stepAnimator2D(arg_anim, arg_dt)
  let resEdge = stepAnimator2D(edge_anim, edge_dt)
  assertEqInt(resNom.currentFrameIdx, 4, "stepAnimator2D nominal resNom.currentFrameIdx == 4")
  assertEqInt(resEdge.currentFrameIdx, 1, "stepAnimator2D boundary resEdge.currentFrameIdx == 1")
  ret 0
```

---

### `getCurrentFrameUv` (`std/gfx2d/sprite_anim2d.aipl`)

- **Signature**: `pub fn getCurrentFrameUv(anim: SpriteAnimator2D): UvRect:`
- **Import**: `import * from "std/gfx2d/sprite_anim2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `anim: SpriteAnimator2D` | **Returns**: `UvRect`
- **Unit Test**: `tests/functions/gfx2d/sprite_anim2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `getCurrentFrameUv` sprite animation clip frame advancement across `Once`, `Loop`, and `PingPong` modes and state-machine transitions. Concrete nominal inputs: `anim: SpriteAnimator2D = SpriteAnimator2D(currentClip = SpriteAnimationClip2D(name = "aipl_test", frames = [0], loopMode = 1), currentFrameIdx = 0, elapsedTimeSec = 0.016667, isPlaying = true, isFinished = true)`; exercises core body path returning/computing `anim.currentClip.frames[idx].uv`.

```aipl
module tests.functions.gfx2d.sprite_anim2d_z3_test
import * from "std/gfx2d/sprite_anim2d"
import { UvRect } from "std/gfx2d/sprite2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite_anim2d_getCurrentFrameUv_3(): int:
  let arg_anim = SpriteAnimator2D(currentClip = SpriteAnimationClip2D(name = "test", frames = [], loopMode = 4), currentFrameIdx = 4, elapsedTimeSec = 2.0, isPlaying = true, isFinished = true)
  let edge_anim = SpriteAnimator2D(currentClip = SpriteAnimationClip2D(name = "a", frames = [], loopMode = 1), currentFrameIdx = 1, elapsedTimeSec = 1.0, isPlaying = false, isFinished = false)
  let resNom = getCurrentFrameUv(arg_anim)
  let resEdge = getCurrentFrameUv(edge_anim)
  assertApproxEq(resNom.u0, 0.0, 0.001, "getCurrentFrameUv nominal resNom.u0 ~= 0.0")
  assertApproxEq(resEdge.u0, 0.0, 0.001, "getCurrentFrameUv boundary resEdge.u0 ~= 0.0")
  ret 0
```

---

### `animMachineNew` (`std/gfx2d/sprite_anim2d.aipl`)

- **Signature**: `pub fn animMachineNew(initialState: str, clips: [AnimClip]): AnimStateMachine:`
- **Import**: `import * from "std/gfx2d/sprite_anim2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `initialState: str, clips: [AnimClip]` | **Returns**: `AnimStateMachine`
- **Unit Test**: `tests/functions/gfx2d/sprite_anim2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `animMachineNew` sprite animation clip frame advancement across `Once`, `Loop`, and `PingPong` modes and state-machine transitions. Concrete nominal inputs: `initialState: str = "aipl_test"`, `clips: [AnimClip] = [AnimClip(name = "aipl_test", startFrame = 1, frameCount = 64, fps = 1.0, looping = true, fallbackState = "aipl_test")]`; exercises core body path returning/computing `AnimStateMachine(`.

```aipl
module tests.functions.gfx2d.sprite_anim2d_z4_test
import * from "std/gfx2d/sprite_anim2d"
import { UvRect } from "std/gfx2d/sprite2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite_anim2d_animMachineNew_4(): int:
  let arg_initialState = "[s]\nk=v"
  let edge_initialState = "[s]\nk=v"
  let arg_clips = [AnimClip(name = "test", startFrame = 4, frameCount = 4, fps = 1.0, looping = true, fallbackState = "test")]
  let edge_clips = []
  let resNom = animMachineNew(arg_initialState, arg_clips)
  let resEdge = animMachineNew(edge_initialState, edge_clips)
  assertEqInt(resNom.currentState.len(), 7, "animMachineNew nominal string length == 7")
  assertEqInt(resEdge.currentState.len(), 7, "animMachineNew boundary string length == 7")
  ret 0
```

---

### `animSetState` (`std/gfx2d/sprite_anim2d.aipl`)

- **Signature**: `pub fn animSetState(sm: AnimStateMachine, newState: str): AnimStateMachine:`
- **Import**: `import * from "std/gfx2d/sprite_anim2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sm: AnimStateMachine, newState: str` | **Returns**: `AnimStateMachine`
- **Unit Test**: `tests/functions/gfx2d/sprite_anim2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `animSetState` sprite animation clip frame advancement across `Once`, `Loop`, and `PingPong` modes and state-machine transitions. Concrete nominal inputs: `sm: AnimStateMachine = AnimStateMachine(currentState = "aipl_test", currentFrameOffset = 0, accumMs = 1.0, clips = [AnimClip(name = 0, startFrame = 0, frameCount = 0, fps = 0, looping = 0, fallbackState = 0)], transitionCount = 64)`, `newState: str = "aipl_test"`; exercises core body path returning/computing `AnimStateMachine(`.

```aipl
module tests.functions.gfx2d.sprite_anim2d_z5_test
import * from "std/gfx2d/sprite_anim2d"
import { UvRect } from "std/gfx2d/sprite2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite_anim2d_animSetState_5(): int:
  let arg_sm = AnimStateMachine(currentState = "test", currentFrameOffset = 4, accumMs = 1.0, clips = [], transitionCount = 4)
  let edge_sm = AnimStateMachine(currentState = "a", currentFrameOffset = 1, accumMs = 0.5, clips = [], transitionCount = 1)
  let arg_newState = "test"
  let edge_newState = "a"
  let resNom = animSetState(arg_sm, arg_newState)
  let resEdge = animSetState(edge_sm, edge_newState)
  assertEqStr(resNom.currentState, "test", "animSetState nominal string matches")
  assertEqStr(resEdge.currentState, "a", "animSetState boundary string matches")
  ret 0
```

---

### `animStep` (`std/gfx2d/sprite_anim2d.aipl`)

- **Signature**: `pub fn animStep(sm: AnimStateMachine, dtMs: float): AnimStateMachine:`
- **Import**: `import * from "std/gfx2d/sprite_anim2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sm: AnimStateMachine, dtMs: float` | **Returns**: `AnimStateMachine`
- **Unit Test**: `tests/functions/gfx2d/sprite_anim2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `animStep` sprite animation clip frame advancement across `Once`, `Loop`, and `PingPong` modes and state-machine transitions. Concrete nominal inputs: `sm: AnimStateMachine = AnimStateMachine(currentState = "aipl_test", currentFrameOffset = 0, accumMs = 1.0, clips = [AnimClip(name = 0, startFrame = 0, frameCount = 0, fps = 0, looping = 0, fallbackState = 0)], transitionCount = 64)`, `dtMs: float = 0.016667`; exercises core body path returning/computing `AnimStateMachine(`.

```aipl
module tests.functions.gfx2d.sprite_anim2d_z6_test
import * from "std/gfx2d/sprite_anim2d"
import { UvRect } from "std/gfx2d/sprite2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite_anim2d_animStep_6(): int:
  let arg_sm = AnimStateMachine(currentState = "test", currentFrameOffset = 4, accumMs = 1.0, clips = [], transitionCount = 4)
  let edge_sm = AnimStateMachine(currentState = "a", currentFrameOffset = 1, accumMs = 0.5, clips = [], transitionCount = 1)
  let arg_dtMs = 2.0
  let edge_dtMs = 1.0
  let resNom = animStep(arg_sm, arg_dtMs)
  let resEdge = animStep(edge_sm, edge_dtMs)
  assertEqStr(resNom.currentState, "test", "animStep nominal string matches")
  assertEqStr(resEdge.currentState, "a", "animStep boundary string matches")
  ret 0
```

---

### `animCurrentSpriteFrame` (`std/gfx2d/sprite_anim2d.aipl`)

- **Signature**: `pub fn animCurrentSpriteFrame(sm: AnimStateMachine): int:`
- **Import**: `import * from "std/gfx2d/sprite_anim2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sm: AnimStateMachine` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/sprite_anim2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `animCurrentSpriteFrame` sprite animation clip frame advancement across `Once`, `Loop`, and `PingPong` modes and state-machine transitions. Concrete nominal inputs: `sm: AnimStateMachine = AnimStateMachine(currentState = "aipl_test", currentFrameOffset = 0, accumMs = 1.0, clips = [AnimClip(name = 0, startFrame = 0, frameCount = 0, fps = 0, looping = 0, fallbackState = 0)], transitionCount = 64)`; exercises core body path returning/computing `sm.currentFrameOffset`.

```aipl
module tests.functions.gfx2d.sprite_anim2d_z7_test
import * from "std/gfx2d/sprite_anim2d"
import { UvRect } from "std/gfx2d/sprite2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite_anim2d_animCurrentSpriteFrame_7(): int:
  let arg_sm = AnimStateMachine(currentState = "test", currentFrameOffset = 4, accumMs = 1.0, clips = [], transitionCount = 4)
  let edge_sm = AnimStateMachine(currentState = "a", currentFrameOffset = 1, accumMs = 0.5, clips = [], transitionCount = 1)
  let resNom = animCurrentSpriteFrame(arg_sm)
  let resEdge = animCurrentSpriteFrame(edge_sm)
  assertEqInt(resNom, 4, "animCurrentSpriteFrame nominal resNom == 4")
  assertEqInt(resEdge, 1, "animCurrentSpriteFrame boundary resEdge == 1")
  ret 0
```

---

### `animModeOnce` (`std/gfx2d/sprite_anim2d.aipl`)

- **Signature**: `pub fn animModeOnce(): int:`
- **Import**: `import * from "std/gfx2d/sprite_anim2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/sprite_anim2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `animModeOnce` sprite animation clip frame advancement across `Once`, `Loop`, and `PingPong` modes and state-machine transitions. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `0`.

```aipl
module tests.functions.gfx2d.sprite_anim2d_z8_test
import * from "std/gfx2d/sprite_anim2d"
import { UvRect } from "std/gfx2d/sprite2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite_anim2d_animModeOnce_8(): int:
  let resNom = animModeOnce()
  let resEdge = animModeOnce()
  assertEqInt(resNom, 0, "animModeOnce nominal resNom == 0")
  assertEqInt(resEdge, 0, "animModeOnce boundary resEdge == 0")
  ret 0
```

---

### `animModeLoop` (`std/gfx2d/sprite_anim2d.aipl`)

- **Signature**: `pub fn animModeLoop(): int:`
- **Import**: `import * from "std/gfx2d/sprite_anim2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/sprite_anim2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `animModeLoop` sprite animation clip frame advancement across `Once`, `Loop`, and `PingPong` modes and state-machine transitions. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `1`.

```aipl
module tests.functions.gfx2d.sprite_anim2d_z9_test
import * from "std/gfx2d/sprite_anim2d"
import { UvRect } from "std/gfx2d/sprite2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite_anim2d_animModeLoop_9(): int:
  let resNom = animModeLoop()
  let resEdge = animModeLoop()
  assertEqInt(resNom, 1, "animModeLoop nominal resNom == 1")
  assertEqInt(resEdge, 1, "animModeLoop boundary resEdge == 1")
  ret 0
```

---

### `animModePingPong` (`std/gfx2d/sprite_anim2d.aipl`)

- **Signature**: `pub fn animModePingPong(): int:`
- **Import**: `import * from "std/gfx2d/sprite_anim2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/sprite_anim2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `animModePingPong` sprite animation clip frame advancement across `Once`, `Loop`, and `PingPong` modes and state-machine transitions. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `2`.

```aipl
module tests.functions.gfx2d.sprite_anim2d_z10_test
import * from "std/gfx2d/sprite_anim2d"
import { UvRect } from "std/gfx2d/sprite2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite_anim2d_animModePingPong_10(): int:
  let resNom = animModePingPong()
  let resEdge = animModePingPong()
  assertEqInt(resNom, 2, "animModePingPong nominal resNom == 2")
  assertEqInt(resEdge, 2, "animModePingPong boundary resEdge == 2")
  ret 0
```

---

### `animClipToEx` (`std/gfx2d/sprite_anim2d.aipl`)

- **Signature**: `pub fn animClipToEx(clip: AnimClip, pingPong: bool = false): AnimClipEx:`
- **Import**: `import * from "std/gfx2d/sprite_anim2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `clip: AnimClip, pingPong: bool = false` | **Returns**: `AnimClipEx`
- **Unit Test**: `tests/functions/gfx2d/sprite_anim2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `animClipToEx` sprite animation clip frame advancement across `Once`, `Loop`, and `PingPong` modes and state-machine transitions. Concrete nominal inputs: `clip: AnimClip = AnimClip(name = "aipl_test", startFrame = 1, frameCount = 64, fps = 1.0, looping = true, fallbackState = "aipl_test")`, `pingPong: bool = true`; exercises core body path returning/computing `AnimClipEx(name = clip.name, startFrame = clip.startFrame, frameCount = clip.frameCount, fps = clip.fps, mode = m)`.

```aipl
module tests.functions.gfx2d.sprite_anim2d_z11_test
import * from "std/gfx2d/sprite_anim2d"
import { UvRect } from "std/gfx2d/sprite2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite_anim2d_animClipToEx_11(): int:
  let arg_clip = AnimClip(name = "127.0.0.1", startFrame = 4, frameCount = 4, fps = 1.0, looping = true, fallbackState = "127.0.0.1")
  let edge_clip = AnimClip(name = "127.0.0.1", startFrame = 1, frameCount = 1, fps = 0.5, looping = false, fallbackState = "127.0.0.1")
  let arg_pingPong = true
  let edge_pingPong = false
  let resNom = animClipToEx(arg_clip, arg_pingPong)
  let resEdge = animClipToEx(edge_clip, edge_pingPong)
  assertEqStr(resNom.name, "127.0.0.1", "animClipToEx nominal string matches")
  assertEqStr(resEdge.name, "127.0.0.1", "animClipToEx boundary string matches")
  ret 0
```

---

### `animClipFromEx` (`std/gfx2d/sprite_anim2d.aipl`)

- **Signature**: `pub fn animClipFromEx(clipEx: AnimClipEx, fallbackState: str = "idle"): AnimClip:`
- **Import**: `import * from "std/gfx2d/sprite_anim2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `clipEx: AnimClipEx, fallbackState: str = "idle"` | **Returns**: `AnimClip`
- **Unit Test**: `tests/functions/gfx2d/sprite_anim2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `animClipFromEx` sprite animation clip frame advancement across `Once`, `Loop`, and `PingPong` modes and state-machine transitions. Concrete nominal inputs: `clipEx: AnimClipEx = AnimClipEx(name = "aipl_test", startFrame = 1, frameCount = 64, fps = 1.0, mode = 1)`, `fallbackState: str = "aipl_test"`; exercises core body path returning/computing `AnimClip(name = clipEx.name, startFrame = clipEx.startFrame, frameCount = clipEx.frameCount, fps = clipEx.fps, looping = (clipEx.mode != 0), fallbackState = fallbackState)`.

```aipl
module tests.functions.gfx2d.sprite_anim2d_z12_test
import * from "std/gfx2d/sprite_anim2d"
import { UvRect } from "std/gfx2d/sprite2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite_anim2d_animClipFromEx_12(): int:
  let arg_clipEx = AnimClipEx(name = "127.0.0.1", startFrame = 4, frameCount = 4, fps = 1.0, mode = 4)
  let edge_clipEx = AnimClipEx(name = "127.0.0.1", startFrame = 1, frameCount = 1, fps = 0.5, mode = 1)
  let arg_fallbackState = "127.0.0.1"
  let edge_fallbackState = "127.0.0.1"
  let resNom = animClipFromEx(arg_clipEx, arg_fallbackState)
  let resEdge = animClipFromEx(edge_clipEx, edge_fallbackState)
  assertEqStr(resNom.name, "127.0.0.1", "animClipFromEx nominal string matches")
  assertEqStr(resEdge.name, "127.0.0.1", "animClipFromEx boundary string matches")
  ret 0
```

---

### `sampleAnimClipEx` (`std/gfx2d/sprite_anim2d.aipl`)

- **Signature**: `pub fn sampleAnimClipEx(clip: AnimClipEx, elapsedSec: float): int:`
- **Import**: `import * from "std/gfx2d/sprite_anim2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `clip: AnimClipEx, elapsedSec: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/sprite_anim2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `sampleAnimClipEx` sprite animation clip frame advancement across `Once`, `Loop`, and `PingPong` modes and state-machine transitions. Concrete nominal inputs: `clip: AnimClipEx = AnimClipEx(name = "aipl_test", startFrame = 1, frameCount = 64, fps = 1.0, mode = 1)`, `elapsedSec: float = 1.0`; exercises core body path returning/computing `clip.startFrame + (rawFrame % count)`.

```aipl
module tests.functions.gfx2d.sprite_anim2d_z13_test
import * from "std/gfx2d/sprite_anim2d"
import { UvRect } from "std/gfx2d/sprite2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite_anim2d_sampleAnimClipEx_13(): int:
  let arg_clip = AnimClipEx(name = "127.0.0.1", startFrame = 4, frameCount = 4, fps = 1.0, mode = 4)
  let edge_clip = AnimClipEx(name = "127.0.0.1", startFrame = 1, frameCount = 1, fps = 0.5, mode = 1)
  let arg_elapsedSec = 1.0
  let edge_elapsedSec = 0.5
  let resNom = sampleAnimClipEx(arg_clip, arg_elapsedSec)
  let resEdge = sampleAnimClipEx(edge_clip, edge_elapsedSec)
  assertEqInt(resNom, 5, "sampleAnimClipEx nominal resNom == 5")
  assertEqInt(resEdge, 1, "sampleAnimClipEx boundary resEdge == 1")
  ret 0
```

---

### `sampleAnimClip` (`std/gfx2d/sprite_anim2d.aipl`)

- **Signature**: `pub fn sampleAnimClip(clip: AnimClip, elapsedSec: float, pingPong: bool = false): int:`
- **Import**: `import * from "std/gfx2d/sprite_anim2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `clip: AnimClip, elapsedSec: float, pingPong: bool = false` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/sprite_anim2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `sampleAnimClip` sprite animation clip frame advancement across `Once`, `Loop`, and `PingPong` modes and state-machine transitions. Concrete nominal inputs: `clip: AnimClip = AnimClip(name = "aipl_test", startFrame = 1, frameCount = 64, fps = 1.0, looping = true, fallbackState = "aipl_test")`, `elapsedSec: float = 1.0`, `pingPong: bool = true`; exercises core body path returning/computing `sampleAnimClipEx(animClipToEx(clip, pingPong), elapsedSec)`.

```aipl
module tests.functions.gfx2d.sprite_anim2d_z14_test
import * from "std/gfx2d/sprite_anim2d"
import { UvRect } from "std/gfx2d/sprite2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sprite_anim2d_sampleAnimClip_14(): int:
  let arg_clip = AnimClip(name = "127.0.0.1", startFrame = 4, frameCount = 4, fps = 1.0, looping = true, fallbackState = "127.0.0.1")
  let edge_clip = AnimClip(name = "127.0.0.1", startFrame = 1, frameCount = 1, fps = 0.5, looping = false, fallbackState = "127.0.0.1")
  let arg_elapsedSec = 1.0
  let edge_elapsedSec = 0.5
  let arg_pingPong = true
  let edge_pingPong = false
  let resNom = sampleAnimClip(arg_clip, arg_elapsedSec, arg_pingPong)
  let resEdge = sampleAnimClip(edge_clip, edge_elapsedSec, edge_pingPong)
  assertEqInt(resNom, 5, "sampleAnimClip nominal resNom == 5")
  assertEqInt(resEdge, 1, "sampleAnimClip boundary resEdge == 1")
  ret 0
```

---

### `createWangBlob47Autotiler` (`std/gfx2d/tilemap_renderer2d.aipl`)

- **Signature**: `pub fn createWangBlob47Autotiler(): WangBlob47Autotiler:`
- **Import**: `import * from "std/gfx2d/tilemap_renderer2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `WangBlob47Autotiler`
- **Unit Test**: `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `createWangBlob47Autotiler` Wang 47-tile blob autotile canonical bitmasking, ASCII tilemap parsing, AABB wall-sliding collision, and Amanatides-Woo DDA raycasting. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `WangBlob47Autotiler(transitionTable = table)`.

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z1_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_createWangBlob47Autotiler_1(): int:
  let resNom = createWangBlob47Autotiler()
  let resEdge = createWangBlob47Autotiler()
  assertEqInt(resNom.transitionTable.len(), 256, "createWangBlob47Autotiler nominal resNom.transitionTable.len() == 256")
  assertEqInt(resEdge.transitionTable.len(), 256, "createWangBlob47Autotiler boundary resEdge.transitionTable.len() == 256")
  ret 0
```

---

### `hasTileAt` (`std/gfx2d/tilemap_renderer2d.aipl`)

- **Signature**: `fn hasTileAt(layer: TilemapLayer2D, c: int, r: int, target: int): bool:`
- **Import**: `import * from "std/gfx2d/tilemap_renderer2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `layer: TilemapLayer2D, c: int, r: int, target: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `hasTileAt` Wang 47-tile blob autotile canonical bitmasking, ASCII tilemap parsing, AABB wall-sliding collision, and Amanatides-Woo DDA raycasting. Concrete nominal inputs: `layer: TilemapLayer2D = TilemapLayer2D(layerId = 1, width = 128, height = 128, tiles = [1], zOrder = 1, opacity = 1.0)`, `c: int = 1`, `r: int = 1`, `target: int = 1`; exercises core body path returning/computing `layer.tiles[idx] == target`.

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z2_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_hasTileAt_2(): int:
  let arg_layer = TilemapLayer2D(layerId = 1, width = 4, height = 4, tiles = [], zOrder = 1, opacity = 1.0)
  let edge_layer = TilemapLayer2D(layerId = 0, width = 4, height = 4, tiles = [], zOrder = 0, opacity = 0.5)
  let arg_c = 2
  let edge_c = 0
  let arg_r = 2
  let edge_r = 0
  let arg_target = 2
  let edge_target = 0
  let resNom = hasTileAt(arg_layer, arg_c, arg_r, arg_target)
  let resEdge = hasTileAt(edge_layer, edge_c, edge_r, edge_target)
  assert(resNom == false, "hasTileAt nominal resNom == false")
  assert(resEdge == false, "hasTileAt boundary resEdge == false")
  ret 0
```

---

### `evaluateAutotileBitmask` (`std/gfx2d/tilemap_renderer2d.aipl`)

- **Signature**: `pub fn evaluateAutotileBitmask(layer: TilemapLayer2D, col: int, row: int, targetTileType: int): int:`
- **Import**: `import * from "std/gfx2d/tilemap_renderer2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `layer: TilemapLayer2D, col: int, row: int, targetTileType: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `evaluateAutotileBitmask` Wang 47-tile blob autotile canonical bitmasking, ASCII tilemap parsing, AABB wall-sliding collision, and Amanatides-Woo DDA raycasting. Concrete nominal inputs: `layer: TilemapLayer2D = TilemapLayer2D(layerId = 1, width = 128, height = 128, tiles = [1], zOrder = 1, opacity = 1.0)`, `col: int = 1`, `row: int = 1`, `targetTileType: int = 1`; exercises core body path returning/computing `mask`.

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z3_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_evaluateAutotileBitmask_3(): int:
  let arg_layer = TilemapLayer2D(layerId = 1, width = 4, height = 4, tiles = [], zOrder = 1, opacity = 1.0)
  let edge_layer = TilemapLayer2D(layerId = 0, width = 4, height = 4, tiles = [], zOrder = 0, opacity = 0.5)
  let arg_col = 1
  let edge_col = 0
  let arg_row = 1
  let edge_row = 0
  let arg_targetTileType = 1
  let edge_targetTileType = 0
  let resNom = evaluateAutotileBitmask(arg_layer, arg_col, arg_row, arg_targetTileType)
  let resEdge = evaluateAutotileBitmask(edge_layer, edge_col, edge_row, edge_targetTileType)
  assertEqInt(resNom, 0, "evaluateAutotileBitmask nominal resNom == 0")
  assertEqInt(resEdge, 0, "evaluateAutotileBitmask boundary resEdge == 0")
  ret 0
```

---

### `resolveWang47TileIndex` (`std/gfx2d/tilemap_renderer2d.aipl`)

- **Signature**: `pub fn resolveWang47TileIndex(autotiler: WangBlob47Autotiler, bitmask8: int): int:`
- **Import**: `import * from "std/gfx2d/tilemap_renderer2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `autotiler: WangBlob47Autotiler, bitmask8: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `resolveWang47TileIndex` Wang 47-tile blob autotile canonical bitmasking, ASCII tilemap parsing, AABB wall-sliding collision, and Amanatides-Woo DDA raycasting. Concrete nominal inputs: `autotiler: WangBlob47Autotiler = WangBlob47Autotiler(transitionTable = [1])`, `bitmask8: int = 1`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z4_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_resolveWang47TileIndex_4(): int:
  let arg_autotiler = WangBlob47Autotiler(transitionTable = [])
  let edge_autotiler = WangBlob47Autotiler(transitionTable = [])
  let arg_bitmask8 = 4
  let edge_bitmask8 = 1
  let resNom = resolveWang47TileIndex(arg_autotiler, arg_bitmask8)
  let resEdge = resolveWang47TileIndex(edge_autotiler, edge_bitmask8)
  assertEqInt(resNom, 0, "resolveWang47TileIndex nominal resNom == 0")
  assertEqInt(resEdge, 0, "resolveWang47TileIndex boundary resEdge == 0")
  ret 0
```

---

### `cullTilemapLayer` (`std/gfx2d/tilemap_renderer2d.aipl`)

- **Signature**: `pub fn cullTilemapLayer(layer: TilemapLayer2D, bounds: ViewportBounds2D, tileW: float, tileH: float): [int]:`
- **Import**: `import * from "std/gfx2d/tilemap_renderer2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `layer: TilemapLayer2D, bounds: ViewportBounds2D, tileW: float, tileH: float` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `cullTilemapLayer` Wang 47-tile blob autotile canonical bitmasking, ASCII tilemap parsing, AABB wall-sliding collision, and Amanatides-Woo DDA raycasting. Concrete nominal inputs: `layer: TilemapLayer2D = TilemapLayer2D(layerId = 1, width = 128, height = 128, tiles = [1], zOrder = 1, opacity = 1.0)`, `bounds: ViewportBounds2D = ViewportBounds2D(minX = 1.0, minY = 1.0, maxX = 1.0, maxY = 1.0)`, `tileW: float = 1.0`, `tileH: float = 1.0`; exercises core body path returning/computing `[minCol, minRow, maxCol, maxRow]`.

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z5_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_cullTilemapLayer_5(): int:
  let arg_layer = TilemapLayer2D(layerId = 1, width = 4, height = 4, tiles = [], zOrder = 1, opacity = 1.0)
  let edge_layer = TilemapLayer2D(layerId = 0, width = 4, height = 4, tiles = [], zOrder = 0, opacity = 0.5)
  let arg_bounds = ViewportBounds2D(minX = 0.0, minY = 0.0, maxX = 2.0, maxY = 2.0)
  let edge_bounds = ViewportBounds2D(minX = 0.0, minY = 0.0, maxX = 1.0, maxY = 1.0)
  let arg_tileW = 2.0
  let edge_tileW = 1.0
  let arg_tileH = 2.0
  let edge_tileH = 1.0
  let resNom = cullTilemapLayer(arg_layer, arg_bounds, arg_tileW, arg_tileH)
  let resEdge = cullTilemapLayer(edge_layer, edge_bounds, edge_tileW, edge_tileH)
  assertEqInt(resNom.len(), 4, "cullTilemapLayer nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 4, "cullTilemapLayer boundary resEdge.len() == 4")
  ret 0
```

---

### `tilemapNew` (`std/gfx2d/tilemap_renderer2d.aipl`)

- **Signature**: `pub fn tilemapNew(width: int, height: int, tileSize: float, defaultTile: int = 0): Tilemap2D:`
- **Import**: `import * from "std/gfx2d/tilemap_renderer2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `width: int, height: int, tileSize: float, defaultTile: int = 0` | **Returns**: `Tilemap2D`
- **Unit Test**: `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `tilemapNew` Wang 47-tile blob autotile canonical bitmasking, ASCII tilemap parsing, AABB wall-sliding collision, and Amanatides-Woo DDA raycasting. Concrete nominal inputs: `width: int = 128`, `height: int = 128`, `tileSize: float = 1.0`, `defaultTile: int = 1`; exercises core body path returning/computing `Tilemap2D(`.

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z6_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_tilemapNew_6(): int:
  let arg_width = 4
  let edge_width = 1
  let arg_height = 4
  let edge_height = 1
  let arg_tileSize = 1.0
  let edge_tileSize = 0.5
  let arg_defaultTile = 2
  let edge_defaultTile = 0
  let resNom = tilemapNew(arg_width, arg_height, arg_tileSize, arg_defaultTile)
  let resEdge = tilemapNew(edge_width, edge_height, edge_tileSize, edge_defaultTile)
  assertEqInt(resNom.width, 4, "tilemapNew nominal resNom.width == 4")
  assertEqInt(resEdge.width, 1, "tilemapNew boundary resEdge.width == 1")
  ret 0
```

---

### `tilemapInBounds` (`std/gfx2d/tilemap_renderer2d.aipl`)

- **Signature**: `pub fn tilemapInBounds(m: Tilemap2D, col: int, row: int): bool:`
- **Import**: `import * from "std/gfx2d/tilemap_renderer2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: Tilemap2D, col: int, row: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `tilemapInBounds` Wang 47-tile blob autotile canonical bitmasking, ASCII tilemap parsing, AABB wall-sliding collision, and Amanatides-Woo DDA raycasting. Concrete nominal inputs: `m: Tilemap2D = Tilemap2D(width = 128, height = 128, tileSize = 1.0, tiles = [1], solidIds = [1], spawnX = 1.0, spawnY = 1.0)`, `col: int = 1`, `row: int = 1`; exercises core body path returning/computing `col >= 0 and col < m.width and row >= 0 and row < m.height`.

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z7_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_tilemapInBounds_7(): int:
  let arg_m = Tilemap2D(width = 4, height = 4, tileSize = 1.0, tiles = [], solidIds = [], spawnX = 2.0, spawnY = 2.0)
  let edge_m = Tilemap2D(width = 4, height = 4, tileSize = 0.5, tiles = [], solidIds = [], spawnX = 1.0, spawnY = 1.0)
  let arg_col = 1
  let edge_col = 0
  let arg_row = 1
  let edge_row = 0
  let resNom = tilemapInBounds(arg_m, arg_col, arg_row)
  let resEdge = tilemapInBounds(edge_m, edge_col, edge_row)
  assert(resNom == true, "tilemapInBounds nominal resNom == true")
  assert(resEdge == true, "tilemapInBounds boundary resEdge == true")
  ret 0
```

---

### `tilemapGet` (`std/gfx2d/tilemap_renderer2d.aipl`)

- **Signature**: `pub fn tilemapGet(m: Tilemap2D, col: int, row: int): int:`
- **Import**: `import * from "std/gfx2d/tilemap_renderer2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: Tilemap2D, col: int, row: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `tilemapGet` Wang 47-tile blob autotile canonical bitmasking, ASCII tilemap parsing, AABB wall-sliding collision, and Amanatides-Woo DDA raycasting. Concrete nominal inputs: `m: Tilemap2D = Tilemap2D(width = 128, height = 128, tileSize = 1.0, tiles = [1], solidIds = [1], spawnX = 1.0, spawnY = 1.0)`, `col: int = 1`, `row: int = 1`; exercises core body path returning/computing `m.tiles[row * m.width + col]`.

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z8_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_tilemapGet_8(): int:
  let arg_m = Tilemap2D(width = 4, height = 4, tileSize = 1.0, tiles = [], solidIds = [], spawnX = 2.0, spawnY = 2.0)
  let edge_m = Tilemap2D(width = 4, height = 4, tileSize = 0.5, tiles = [], solidIds = [], spawnX = 1.0, spawnY = 1.0)
  let arg_col = 1
  let edge_col = 0
  let arg_row = 1
  let edge_row = 0
  let resNom = tilemapGet(arg_m, arg_col, arg_row)
  let resEdge = tilemapGet(edge_m, edge_col, edge_row)
  assertEqStr(str(resNom), "nil", "tilemapGet nominal str(resNom) == nil")
  assertEqStr(str(resEdge), "nil", "tilemapGet boundary str(resEdge) == nil")
  ret 0
```

---

### `tilemapSet` (`std/gfx2d/tilemap_renderer2d.aipl`)

- **Signature**: `pub fn tilemapSet(m: Tilemap2D, col: int, row: int, tileId: int): Tilemap2D:`
- **Import**: `import * from "std/gfx2d/tilemap_renderer2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: Tilemap2D, col: int, row: int, tileId: int` | **Returns**: `Tilemap2D`
- **Unit Test**: `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `tilemapSet` Wang 47-tile blob autotile canonical bitmasking, ASCII tilemap parsing, AABB wall-sliding collision, and Amanatides-Woo DDA raycasting. Concrete nominal inputs: `m: Tilemap2D = Tilemap2D(width = 128, height = 128, tileSize = 1.0, tiles = [1], solidIds = [1], spawnX = 1.0, spawnY = 1.0)`, `col: int = 1`, `row: int = 1`, `tileId: int = 1`; exercises core body path returning/computing `Tilemap2D(`.

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z9_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_tilemapSet_9(): int:
  let arg_m = Tilemap2D(width = 4, height = 4, tileSize = 1.0, tiles = [], solidIds = [], spawnX = 2.0, spawnY = 2.0)
  let edge_m = Tilemap2D(width = 4, height = 4, tileSize = 0.5, tiles = [], solidIds = [], spawnX = 1.0, spawnY = 1.0)
  let arg_col = 1
  let edge_col = 0
  let arg_row = 1
  let edge_row = 0
  let arg_tileId = 1
  let edge_tileId = 0
  let resNom = tilemapSet(arg_m, arg_col, arg_row, arg_tileId)
  let resEdge = tilemapSet(edge_m, edge_col, edge_row, edge_tileId)
  assertEqInt(resNom.width, 4, "tilemapSet nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "tilemapSet boundary resEdge.width == 4")
  ret 0
```

---

### `tilemapSetInPlace` (`std/gfx2d/tilemap_renderer2d.aipl`)

- **Signature**: `pub fn tilemapSetInPlace(mut m: Tilemap2D, col: int, row: int, tileId: int): Tilemap2D:`
- **Import**: `import * from "std/gfx2d/tilemap_renderer2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut m: Tilemap2D, col: int, row: int, tileId: int` | **Returns**: `Tilemap2D`
- **Unit Test**: `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `tilemapSetInPlace` Wang 47-tile blob autotile canonical bitmasking, ASCII tilemap parsing, AABB wall-sliding collision, and Amanatides-Woo DDA raycasting. Concrete nominal inputs: `m: Tilemap2D = Tilemap2D(width = 128, height = 128, tileSize = 1.0, tiles = [1], solidIds = [1], spawnX = 1.0, spawnY = 1.0)`, `col: int = 1`, `row: int = 1`, `tileId: int = 1`; exercises core body path returning/computing `m`.

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z10_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_tilemapSetInPlace_10(): int:
  let arg_m = Tilemap2D(width = 4, height = 4, tileSize = 1.0, tiles = [], solidIds = [], spawnX = 2.0, spawnY = 2.0)
  let edge_m = Tilemap2D(width = 4, height = 4, tileSize = 0.5, tiles = [], solidIds = [], spawnX = 1.0, spawnY = 1.0)
  let arg_col = 1
  let edge_col = 0
  let arg_row = 1
  let edge_row = 0
  let arg_tileId = 1
  let edge_tileId = 0
  let resNom = tilemapSetInPlace(arg_m, arg_col, arg_row, arg_tileId)
  let resEdge = tilemapSetInPlace(edge_m, edge_col, edge_row, edge_tileId)
  assertEqInt(resNom.width, 4, "tilemapSetInPlace nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "tilemapSetInPlace boundary resEdge.width == 4")
  ret 0
```

---

### `tilemapIsSolidAtGrid` (`std/gfx2d/tilemap_renderer2d.aipl`)

- **Signature**: `pub fn tilemapIsSolidAtGrid(m: Tilemap2D, col: int, row: int): bool:`
- **Import**: `import * from "std/gfx2d/tilemap_renderer2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: Tilemap2D, col: int, row: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `tilemapIsSolidAtGrid` Wang 47-tile blob autotile canonical bitmasking, ASCII tilemap parsing, AABB wall-sliding collision, and Amanatides-Woo DDA raycasting. Concrete nominal inputs: `m: Tilemap2D = Tilemap2D(width = 128, height = 128, tileSize = 1.0, tiles = [1], solidIds = [1], spawnX = 1.0, spawnY = 1.0)`, `col: int = 1`, `row: int = 1`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z11_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_tilemapIsSolidAtGrid_11(): int:
  let arg_m = Tilemap2D(width = 4, height = 4, tileSize = 1.0, tiles = [], solidIds = [], spawnX = 2.0, spawnY = 2.0)
  let edge_m = Tilemap2D(width = 4, height = 4, tileSize = 0.5, tiles = [], solidIds = [], spawnX = 1.0, spawnY = 1.0)
  let arg_col = 1
  let edge_col = 0
  let arg_row = 1
  let edge_row = 0
  let resNom = tilemapIsSolidAtGrid(arg_m, arg_col, arg_row)
  let resEdge = tilemapIsSolidAtGrid(edge_m, edge_col, edge_row)
  assert(resNom == false, "tilemapIsSolidAtGrid nominal resNom == false")
  assert(resEdge == false, "tilemapIsSolidAtGrid boundary resEdge == false")
  ret 0
```

---

### `tilemapFromAscii` (`std/gfx2d/tilemap_renderer2d.aipl`)

- **Signature**: `pub fn tilemapFromAscii(rows: [str], tileSize: float): Tilemap2D:`
- **Import**: `import * from "std/gfx2d/tilemap_renderer2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rows: [str], tileSize: float` | **Returns**: `Tilemap2D`
- **Unit Test**: `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `tilemapFromAscii` Wang 47-tile blob autotile canonical bitmasking, ASCII tilemap parsing, AABB wall-sliding collision, and Amanatides-Woo DDA raycasting. Concrete nominal inputs: `rows: [str] = ["aipl_test"]`, `tileSize: float = 1.0`; exercises core body path returning/computing `Tilemap2D(`.

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z12_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_tilemapFromAscii_12(): int:
  let arg_rows = ["test"]
  let edge_rows = []
  let arg_tileSize = 1.0
  let edge_tileSize = 0.5
  let resNom = tilemapFromAscii(arg_rows, arg_tileSize)
  let resEdge = tilemapFromAscii(edge_rows, edge_tileSize)
  assertEqInt(resNom.width, 4, "tilemapFromAscii nominal resNom.width == 4")
  assertEqInt(resEdge.width, 0, "tilemapFromAscii boundary resEdge.width == 0")
  ret 0
```

---

### `tilemapWorldToCol` (`std/gfx2d/tilemap_renderer2d.aipl`)

- **Signature**: `pub fn tilemapWorldToCol(m: Tilemap2D, x: float): int:`
- **Import**: `import * from "std/gfx2d/tilemap_renderer2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: Tilemap2D, x: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `tilemapWorldToCol` Wang 47-tile blob autotile canonical bitmasking, ASCII tilemap parsing, AABB wall-sliding collision, and Amanatides-Woo DDA raycasting. Concrete nominal inputs: `m: Tilemap2D = Tilemap2D(width = 128, height = 128, tileSize = 1.0, tiles = [1], solidIds = [1], spawnX = 1.0, spawnY = 1.0)`, `x: float = 1.0`; exercises core body path returning/computing `int(floor(x / m.tileSize))`.

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z13_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_tilemapWorldToCol_13(): int:
  let arg_m = Tilemap2D(width = 4, height = 4, tileSize = 1.0, tiles = [], solidIds = [], spawnX = 2.0, spawnY = 2.0)
  let edge_m = Tilemap2D(width = 4, height = 4, tileSize = 0.5, tiles = [], solidIds = [], spawnX = 1.0, spawnY = 1.0)
  let arg_x = 1.0
  let edge_x = 0.5
  let resNom = tilemapWorldToCol(arg_m, arg_x)
  let resEdge = tilemapWorldToCol(edge_m, edge_x)
  assertEqInt(resNom, 1, "tilemapWorldToCol nominal resNom == 1")
  assertEqInt(resEdge, 1, "tilemapWorldToCol boundary resEdge == 1")
  ret 0
```

---

### `tilemapWorldToRow` (`std/gfx2d/tilemap_renderer2d.aipl`)

- **Signature**: `pub fn tilemapWorldToRow(m: Tilemap2D, y: float): int:`
- **Import**: `import * from "std/gfx2d/tilemap_renderer2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: Tilemap2D, y: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `tilemapWorldToRow` Wang 47-tile blob autotile canonical bitmasking, ASCII tilemap parsing, AABB wall-sliding collision, and Amanatides-Woo DDA raycasting. Concrete nominal inputs: `m: Tilemap2D = Tilemap2D(width = 128, height = 128, tileSize = 1.0, tiles = [1], solidIds = [1], spawnX = 1.0, spawnY = 1.0)`, `y: float = 1.0`; exercises core body path returning/computing `int(floor(y / m.tileSize))`.

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z14_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_tilemapWorldToRow_14(): int:
  let arg_m = Tilemap2D(width = 4, height = 4, tileSize = 1.0, tiles = [], solidIds = [], spawnX = 2.0, spawnY = 2.0)
  let edge_m = Tilemap2D(width = 4, height = 4, tileSize = 0.5, tiles = [], solidIds = [], spawnX = 1.0, spawnY = 1.0)
  let arg_y = 1.0
  let edge_y = 0.5
  let resNom = tilemapWorldToRow(arg_m, arg_y)
  let resEdge = tilemapWorldToRow(edge_m, edge_y)
  assertEqInt(resNom, 1, "tilemapWorldToRow nominal resNom == 1")
  assertEqInt(resEdge, 1, "tilemapWorldToRow boundary resEdge == 1")
  ret 0
```

---

### `tilemapColToWorld` (`std/gfx2d/tilemap_renderer2d.aipl`)

- **Signature**: `pub fn tilemapColToWorld(m: Tilemap2D, col: int): float:`
- **Import**: `import * from "std/gfx2d/tilemap_renderer2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: Tilemap2D, col: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `tilemapColToWorld` Wang 47-tile blob autotile canonical bitmasking, ASCII tilemap parsing, AABB wall-sliding collision, and Amanatides-Woo DDA raycasting. Concrete nominal inputs: `m: Tilemap2D = Tilemap2D(width = 128, height = 128, tileSize = 1.0, tiles = [1], solidIds = [1], spawnX = 1.0, spawnY = 1.0)`, `col: int = 1`; exercises core body path returning/computing `float(col) * m.tileSize`.

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z15_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_tilemapColToWorld_15(): int:
  let arg_m = Tilemap2D(width = 4, height = 4, tileSize = 1.0, tiles = [], solidIds = [], spawnX = 2.0, spawnY = 2.0)
  let edge_m = Tilemap2D(width = 4, height = 4, tileSize = 0.5, tiles = [], solidIds = [], spawnX = 1.0, spawnY = 1.0)
  let arg_col = 1
  let edge_col = 0
  let resNom = tilemapColToWorld(arg_m, arg_col)
  let resEdge = tilemapColToWorld(edge_m, edge_col)
  assertApproxEq(resNom, 1.0, 0.001, "tilemapColToWorld nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.0, 0.001, "tilemapColToWorld boundary resEdge ~= 0.0")
  ret 0
```

---

### `tilemapRowToWorld` (`std/gfx2d/tilemap_renderer2d.aipl`)

- **Signature**: `pub fn tilemapRowToWorld(m: Tilemap2D, row: int): float:`
- **Import**: `import * from "std/gfx2d/tilemap_renderer2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: Tilemap2D, row: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `tilemapRowToWorld` Wang 47-tile blob autotile canonical bitmasking, ASCII tilemap parsing, AABB wall-sliding collision, and Amanatides-Woo DDA raycasting. Concrete nominal inputs: `m: Tilemap2D = Tilemap2D(width = 128, height = 128, tileSize = 1.0, tiles = [1], solidIds = [1], spawnX = 1.0, spawnY = 1.0)`, `row: int = 1`; exercises core body path returning/computing `float(row) * m.tileSize`.

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z16_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_tilemapRowToWorld_16(): int:
  let arg_m = Tilemap2D(width = 4, height = 4, tileSize = 1.0, tiles = [], solidIds = [], spawnX = 2.0, spawnY = 2.0)
  let edge_m = Tilemap2D(width = 4, height = 4, tileSize = 0.5, tiles = [], solidIds = [], spawnX = 1.0, spawnY = 1.0)
  let arg_row = 1
  let edge_row = 0
  let resNom = tilemapRowToWorld(arg_m, arg_row)
  let resEdge = tilemapRowToWorld(edge_m, edge_row)
  assertApproxEq(resNom, 1.0, 0.001, "tilemapRowToWorld nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.0, 0.001, "tilemapRowToWorld boundary resEdge ~= 0.0")
  ret 0
```

---

### `tilemapCheckAABB` (`std/gfx2d/tilemap_renderer2d.aipl`)

- **Signature**: `pub fn tilemapCheckAABB(m: Tilemap2D, x: float, y: float, w: float, h: float): bool:`
- **Import**: `import * from "std/gfx2d/tilemap_renderer2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: Tilemap2D, x: float, y: float, w: float, h: float` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `tilemapCheckAABB` Wang 47-tile blob autotile canonical bitmasking, ASCII tilemap parsing, AABB wall-sliding collision, and Amanatides-Woo DDA raycasting. Concrete nominal inputs: `m: Tilemap2D = Tilemap2D(width = 128, height = 128, tileSize = 1.0, tiles = [1], solidIds = [1], spawnX = 1.0, spawnY = 1.0)`, `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z17_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_tilemapCheckAABB_17(): int:
  let arg_m = Tilemap2D(width = 4, height = 4, tileSize = 1.0, tiles = [], solidIds = [], spawnX = 2.0, spawnY = 2.0)
  let edge_m = Tilemap2D(width = 4, height = 4, tileSize = 0.5, tiles = [], solidIds = [], spawnX = 1.0, spawnY = 1.0)
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let resNom = tilemapCheckAABB(arg_m, arg_x, arg_y, arg_w, arg_h)
  let resEdge = tilemapCheckAABB(edge_m, edge_x, edge_y, edge_w, edge_h)
  assert(resNom == false, "tilemapCheckAABB nominal resNom == false")
  assert(resEdge == false, "tilemapCheckAABB boundary resEdge == false")
  ret 0
```

---

### `tilemapMoveAndSlide` (`std/gfx2d/tilemap_renderer2d.aipl`)

- **Signature**: `pub fn tilemapMoveAndSlide(m: Tilemap2D, x: float, y: float, w: float, h: float, vx: float, vy: float, dt: float): [float]:`
- **Import**: `import * from "std/gfx2d/tilemap_renderer2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: Tilemap2D, x: float, y: float, w: float, h: float, vx: float, vy: float, dt: float` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `tilemapMoveAndSlide` Wang 47-tile blob autotile canonical bitmasking, ASCII tilemap parsing, AABB wall-sliding collision, and Amanatides-Woo DDA raycasting. Concrete nominal inputs: `m: Tilemap2D = Tilemap2D(width = 128, height = 128, tileSize = 1.0, tiles = [1], solidIds = [1], spawnX = 1.0, spawnY = 1.0)`, `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`, `vx: float = 1.0`, `vy: float = 1.0`, `dt: float = 0.016667`; exercises core body path returning/computing `[finalX, finalY, outVx, outVy]`.

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z18_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_tilemapMoveAndSlide_18(): int:
  let arg_m = Tilemap2D(width = 4, height = 4, tileSize = 1.0, tiles = [], solidIds = [], spawnX = 2.0, spawnY = 2.0)
  let edge_m = Tilemap2D(width = 4, height = 4, tileSize = 0.5, tiles = [], solidIds = [], spawnX = 1.0, spawnY = 1.0)
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let arg_vx = 1.0
  let edge_vx = 0.5
  let arg_vy = 1.0
  let edge_vy = 0.5
  let arg_dt = 2.0
  let edge_dt = 1.0
  let resNom = tilemapMoveAndSlide(arg_m, arg_x, arg_y, arg_w, arg_h, arg_vx, arg_vy, arg_dt)
  let resEdge = tilemapMoveAndSlide(edge_m, edge_x, edge_y, edge_w, edge_h, edge_vx, edge_vy, edge_dt)
  assertEqInt(resNom.len(), 4, "tilemapMoveAndSlide nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 4, "tilemapMoveAndSlide boundary resEdge.len() == 4")
  ret 0
```

---

### `tilemapAutotile16Mask` (`std/gfx2d/tilemap_renderer2d.aipl`)

- **Signature**: `pub fn tilemapAutotile16Mask(m: Tilemap2D, col: int, row: int, targetId: int): int:`
- **Import**: `import * from "std/gfx2d/tilemap_renderer2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: Tilemap2D, col: int, row: int, targetId: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `tilemapAutotile16Mask` Wang 47-tile blob autotile canonical bitmasking, ASCII tilemap parsing, AABB wall-sliding collision, and Amanatides-Woo DDA raycasting. Concrete nominal inputs: `m: Tilemap2D = Tilemap2D(width = 128, height = 128, tileSize = 1.0, tiles = [1], solidIds = [1], spawnX = 1.0, spawnY = 1.0)`, `col: int = 1`, `row: int = 1`, `targetId: int = 1`; exercises core body path returning/computing `mask`.

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z19_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_tilemapAutotile16Mask_19(): int:
  let arg_m = Tilemap2D(width = 4, height = 4, tileSize = 1.0, tiles = [], solidIds = [], spawnX = 2.0, spawnY = 2.0)
  let edge_m = Tilemap2D(width = 4, height = 4, tileSize = 0.5, tiles = [], solidIds = [], spawnX = 1.0, spawnY = 1.0)
  let arg_col = 1
  let edge_col = 0
  let arg_row = 1
  let edge_row = 0
  let arg_targetId = 1
  let edge_targetId = 0
  let resNom = tilemapAutotile16Mask(arg_m, arg_col, arg_row, arg_targetId)
  let resEdge = tilemapAutotile16Mask(edge_m, edge_col, edge_row, edge_targetId)
  assertEqInt(resNom, 0, "tilemapAutotile16Mask nominal resNom == 0")
  assertEqInt(resEdge, 9, "tilemapAutotile16Mask boundary resEdge == 9")
  ret 0
```

---

### `tilemapAutotile47CanonicalMask` (`std/gfx2d/tilemap_renderer2d.aipl`)

- **Signature**: `pub fn tilemapAutotile47CanonicalMask(m: Tilemap2D, col: int, row: int, targetId: int): int:`
- **Import**: `import * from "std/gfx2d/tilemap_renderer2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: Tilemap2D, col: int, row: int, targetId: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `tilemapAutotile47CanonicalMask` Wang 47-tile blob autotile canonical bitmasking, ASCII tilemap parsing, AABB wall-sliding collision, and Amanatides-Woo DDA raycasting. Concrete nominal inputs: `m: Tilemap2D = Tilemap2D(width = 128, height = 128, tileSize = 1.0, tiles = [1], solidIds = [1], spawnX = 1.0, spawnY = 1.0)`, `col: int = 1`, `row: int = 1`, `targetId: int = 1`; exercises core body path returning/computing `mask`.

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z20_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_tilemapAutotile47CanonicalMask_20(): int:
  let arg_m = Tilemap2D(width = 4, height = 4, tileSize = 1.0, tiles = [], solidIds = [], spawnX = 2.0, spawnY = 2.0)
  let edge_m = Tilemap2D(width = 4, height = 4, tileSize = 0.5, tiles = [], solidIds = [], spawnX = 1.0, spawnY = 1.0)
  let arg_col = 1
  let edge_col = 0
  let arg_row = 1
  let edge_row = 0
  let arg_targetId = 1
  let edge_targetId = 0
  let resNom = tilemapAutotile47CanonicalMask(arg_m, arg_col, arg_row, arg_targetId)
  let resEdge = tilemapAutotile47CanonicalMask(edge_m, edge_col, edge_row, edge_targetId)
  assertEqInt(resNom, 0, "tilemapAutotile47CanonicalMask nominal resNom == 0")
  assertEqInt(resEdge, 193, "tilemapAutotile47CanonicalMask boundary resEdge == 193")
  ret 0
```

---

### `tilemapBlobMaskToIndex47` (`std/gfx2d/tilemap_renderer2d.aipl`)

- **Signature**: `pub fn tilemapBlobMaskToIndex47(canonicalMask: int): int:`
- **Import**: `import * from "std/gfx2d/tilemap_renderer2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `canonicalMask: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | **Example**: `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`
- **Behavioral Summary**: Verify `tilemapBlobMaskToIndex47` Wang 47-tile blob autotile canonical bitmasking, ASCII tilemap parsing, AABB wall-sliding collision, and Amanatides-Woo DDA raycasting. Concrete nominal inputs: `canonicalMask: int = 1`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z21_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_tilemapBlobMaskToIndex47_21(): int:
  let arg_canonicalMask = 4
  let edge_canonicalMask = 1
  let resNom = tilemapBlobMaskToIndex47(arg_canonicalMask)
  let resEdge = tilemapBlobMaskToIndex47(edge_canonicalMask)
  assertEqInt(resNom, 2, "tilemapBlobMaskToIndex47 nominal resNom == 2")
  assertEqInt(resEdge, 1, "tilemapBlobMaskToIndex47 boundary resEdge == 1")
  ret 0
```

---

### `tilemapMoveAndSlideEx` (`std/gfx2d/tilemap_renderer2d.aipl`)

- **Signature**: `pub fn tilemapMoveAndSlideEx(m: Tilemap2D, x: float, y: float, w: float, h: float, vx: float, vy: float, dt: float): SlideResult2D:`
- **Import**: `import * from "std/gfx2d/tilemap_renderer2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: Tilemap2D, x: float, y: float, w: float, h: float, vx: float, vy: float, dt: float` | **Returns**: `SlideResult2D`
- **Unit Test**: `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | **Example**: `examples/ex_163_gfx2d_batch2d_ten_thousand_sprites_window.aipl`
- **Behavioral Summary**: Verify `tilemapMoveAndSlideEx` Wang 47-tile blob autotile canonical bitmasking, ASCII tilemap parsing, AABB wall-sliding collision, and Amanatides-Woo DDA raycasting. Concrete nominal inputs: `m: Tilemap2D = Tilemap2D(width = 128, height = 128, tileSize = 1.0, tiles = [1], solidIds = [1], spawnX = 1.0, spawnY = 1.0)`, `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`, `vx: float = 1.0`, `vy: float = 1.0`, `dt: float = 0.016667`; exercises core body path returning/computing `SlideResult2D(x = finalX, y = finalY, vx = outVx, vy = outVy, hitX = hitX, hitY = hitY, onGround = grounded)`.

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z22_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_tilemapMoveAndSlideEx_22(): int:
  let arg_m = Tilemap2D(width = 4, height = 4, tileSize = 1.0, tiles = [], solidIds = [], spawnX = 2.0, spawnY = 2.0)
  let edge_m = Tilemap2D(width = 4, height = 4, tileSize = 0.5, tiles = [], solidIds = [], spawnX = 1.0, spawnY = 1.0)
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let arg_vx = 1.0
  let edge_vx = 0.5
  let arg_vy = 1.0
  let edge_vy = 0.5
  let arg_dt = 2.0
  let edge_dt = 1.0
  let resNom = tilemapMoveAndSlideEx(arg_m, arg_x, arg_y, arg_w, arg_h, arg_vx, arg_vy, arg_dt)
  let resEdge = tilemapMoveAndSlideEx(edge_m, edge_x, edge_y, edge_w, edge_h, edge_vx, edge_vy, edge_dt)
  assertApproxEq(resNom.x, 1.0, 0.001, "tilemapMoveAndSlideEx nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 1.0, 0.001, "tilemapMoveAndSlideEx boundary resEdge.x ~= 1.0")
  ret 0
```

---

### `tilemapRaycastDDA` (`std/gfx2d/tilemap_renderer2d.aipl`)

- **Signature**: `pub fn tilemapRaycastDDA(m: Tilemap2D, startX: float, startY: float, dirX: float, dirY: float, maxDist: float): TileRaycastHit2D:`
- **Import**: `import * from "std/gfx2d/tilemap_renderer2d"` (or barrel `import * from "std/gfx2d/gfx2d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: Tilemap2D, startX: float, startY: float, dirX: float, dirY: float, maxDist: float` | **Returns**: `TileRaycastHit2D`
- **Unit Test**: `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | **Example**: `examples/ex_164_gfx2d_camera2d_trauma_screenshake_window.aipl`
- **Behavioral Summary**: Verify `tilemapRaycastDDA` Wang 47-tile blob autotile canonical bitmasking, ASCII tilemap parsing, AABB wall-sliding collision, and Amanatides-Woo DDA raycasting. Concrete nominal inputs: `m: Tilemap2D = Tilemap2D(width = 128, height = 128, tileSize = 1.0, tiles = [1], solidIds = [1], spawnX = 1.0, spawnY = 1.0)`, `startX: float = 1.0`, `startY: float = 1.0`, `dirX: float = 1.0`, `dirY: float = 1.0`, `maxDist: float = 1.0`; exercises core body path returning/computing `TileRaycastHit2D(hit = false, col = -1, row = -1, hitX = startX + rdx * maxDist, hitY = startY + rdy * maxDist, dist = maxDist, normalX = 0.0, normalY = 0.0)`.

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z23_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_tilemapRaycastDDA_23(): int:
  let arg_m = Tilemap2D(width = 4, height = 4, tileSize = 1.0, tiles = [], solidIds = [], spawnX = 2.0, spawnY = 2.0)
  let edge_m = Tilemap2D(width = 4, height = 4, tileSize = 0.5, tiles = [], solidIds = [], spawnX = 1.0, spawnY = 1.0)
  let arg_startX = 0.0
  let edge_startX = 0.0
  let arg_startY = 0.0
  let edge_startY = 0.0
  let arg_dirX = 1.0
  let edge_dirX = 0.5
  let arg_dirY = 1.0
  let edge_dirY = 0.5
  let arg_maxDist = 2.0
  let edge_maxDist = 1.0
  let resNom = tilemapRaycastDDA(arg_m, arg_startX, arg_startY, arg_dirX, arg_dirY, arg_maxDist)
  let resEdge = tilemapRaycastDDA(edge_m, edge_startX, edge_startY, edge_dirX, edge_dirY, edge_maxDist)
  assert(resNom.hit == false, "tilemapRaycastDDA nominal resNom.hit == false")
  assert(resEdge.hit == false, "tilemapRaycastDDA boundary resEdge.hit == false")
  ret 0
```
