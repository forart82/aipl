# AIPL Standard Library Master Reference (38 Domains, 299 Modules, 4,379 Functions)
**Single Source of Truth (SSOT) — Standard Library Architecture Hub**

[Home](../README.md) | [Docs Index](INDEX.md) | [Tutorials](tutorials/INDEX.md) | [Cookbook](tutorials/cookbook.md) | [Stdlib Reference](reference/STDLIB_REFERENCE.md) | [CLI Reference](CLI_REFERENCE.md)

> **When to Read This Document**: Read this master reference for an architectural overview of AIPL's 38 standard library domain groups, 299 modules, and 6-layer DAG. For exhaustive function-by-function documentation, signatures, and recipes, consult the [Detailed Standard Library Reference](reference/STDLIB_REFERENCE.md) and individual [Domain References](reference/INDEX.md).

---

## Canonical Project Architecture & Inventory Counts

- **38 Standard Library Domain Groups**: `2` root modules (`std/std_root.aipl`, `std/prelude.aipl`) + `37` canonical domain directories = **`299` `std/` modules** (`262` implementation/root modules + `37` barrel modules).
- **4,379 Total Callable Functions**: **`32` compiler built-ins + `4,347` `std/` functions, constructors & receiver methods**.
- **263 Curated, Fully-Tested Examples**: `examples/ex_001_*.aipl` through `examples/ex_263_*.aipl` (`118` CLI programs + `145` interactive Window applications) with 1-to-1 twin unit tests in `tests/examples/`.
- **37 Architecture Decision Records**: `docs/ADR/ADR-0001-*.md` through `docs/ADR/ADR-0037-*.md` indexed in [`docs/ADR/INDEX.md`](ADR/INDEX.md).
- **653 Canonical Test Suites**: `263` example twin tests + `365` function test suites + `12` scenario suites + `13` complex system integration suites.
---

## 1. 6-Layer Standard Library Architecture DAG

The standard library is organized into a strict, acyclic 6-layer dependency DAG:

- **Layer 0 ($L_0$): Host & Memory Kernels**:
  - `sys` (9 modules, 109 functions) — Low-level syscalls, platform detection, memory mapped files, audio/canvas hardware stubs, Android NDK bridge.
  - `rt` (8 modules, 119 functions) — Pure-AIPL runtime baseline, memory buffers, primitive string/array operations.
  - `alloc` (6 modules, 54 functions) — Deterministic bump arenas, generational object pools, slab allocators, GPA leak detection.
- **Layer 1 ($L_1$): Core Primitives & Math**:
  - `prelude` (3 modules, 74 functions) — Core built-ins, `Option[T]`, `Result[T, E]`, assertions, standard operators.
  - `math` (16 modules, 440 functions) — BigInt, linear algebra (Vec2..4, Mat2..4, Quat), trigonometry, statistics, PRNG.
  - `collections` (14 modules, 220 functions) — Dynamic arrays, hash maps, queues, priority heaps, bitsets, ring buffers.
  - `fmt` (5 modules, 125 functions) — String formatting, numeric parsing, string builders, ANSI terminal colors.
  - `regex` (4 modules, 53 functions) — Thompson NFA linear-time regular expressions, pattern matching, capture groups.
  - `time` (7 modules, 165 functions) — Monotonic clocks, durations, timestamps, cooldown timers, stopwatch profiling.
- **Layer 2 ($L_2$): Serialization, Compression, Crypto & Database**:
  - `encoding` (14 modules, 269 functions) — JSON DOM/streaming parser, XML, AXML manifest, HTML, CSV, Hex, Base64, Protobuf.
  - `compress` (7 modules, 35 functions) — Gzip, Deflate, Zlib, LZ4, Zstandard, APK Zip compression and decompression.
  - `crypto` (8 modules, 64 functions) — SHA-256/512, MD5, HMAC, ChaCha20-Poly1305 AEAD, APK Sig v2, constant-time comparisons.
  - `db` (3 modules, 78 functions) — Embedded key-value store, write-ahead log (WAL), atomic transactions.
- **Layer 3 ($L_3$): Streaming I/O, Filesystem, OS, Concurrency & Networking**:
  - `io` (6 modules, 54 functions) — Buffered I/O, readers, writers, binary streams, pipes.
  - `fs` (8 modules, 57 functions) — File operations, directory traversal, file watcher, mobile file watcher, Android VFS, path manipulation.
  - `os` (6 modules, 145 functions) — CLI arguments, environment variables, process execution, signals, sandboxing.
  - `sync` (6 modules, 74 functions) — Mutexes, read-write locks, atomic primitives, condition variables, semaphores.
  - `thread` (4 modules, 38 functions) — Threadpool, fiber coroutines, work-stealing job queues.
  - `net` (11 modules, 78 functions) — TCP/UDP sockets, DNS resolution, HTTP client, WebSockets, live reload sync, JSON-RPC.
  - `test` (5 modules, 32 functions) — Unit test framework, assertions, matchers, TAP/JUnit reporters.
- **Layer 4 ($L_4$): Windowing, Input, Assets, Audio & Graphics**:
  - `window` (6 modules, 28 functions) — Native window creation, display management, event loop, fixed-timestep accumulator.
  - `input` (7 modules, 51 functions) — Keyboard, mouse, gamepad, touch gestures, action mapping.
  - `asset` (8 modules, 159 functions) — Binary asset packaging, APK container format, texture loading, font rasterization, sound cache.
  - `audio` (7 modules, 159 functions) — 16-voice polyphonic DSP synthesizer, ADSR envelopes, 3D Doppler spatial audio.
  - `gfx` (10 modules, 55 functions) — Colors, blend modes, GPU buffers, vertex shaders, WGSL validation.
  - `gfx2d` (12 modules, 434 functions) — 2D canvas, sprite batches, affine transforms, hardware/software Z-buffer, 4 canonical blend modes (`setBlendMode`, `getBlendMode`, `blendModeAlpha`, `blendModeAdditive`, `blendModeMultiplied`, `blendModeScreen`), Gouraud & UV-mapped triangle/quad rasterization (`setDepthTest`, `clearDepth`, `beginWorldPass`, `endWorldPass`, `drawTriangleGouraud`, `drawTriangle3DGouraud`, `drawQuad3DGouraud`, `drawTriangle3DTextured`, `drawQuad3DTextured`, `createTextureFromRgba`, `createProceduralTexture`, `createIsometricSpriteSheet`, `saveTextureToPpm`), discrete 2D tilemaps (`tilemap_renderer2d`), camera 2D.
  - `gfx25d` (7 modules, 34 functions) — Continuous 2.5D/3D isometric world engine (`camera25d`, `mesh25d`, `ribbon25d`, `light25d`, `sprite25d`, `weather25d`, `gfx25d_mod`): invertible 3D-to-isometric projection, elevation-aware frustum culling, smooth Gouraud & multi-biome alpha-splatted UV-textured heightfield patches (`drawHeightfieldPatch25D`, `drawHeightfieldPatchTextured25D`, `drawHeightfieldSplat25D`, `drawGroundDecal25D`), depth-buffered volumetric & textured primitives (`drawPrism25D`, `drawPrismTextured25D`, `drawCone25D`, `drawBillboard25D`, `drawIndexedMesh25D`, `drawIndexedMeshTextured25D`), continuous spline & UV-scrolled ribbons (`extrudeSplineRibbon25D`, `drawSplineRibbon25D`, `drawSplineRibbonTextured25D`), 2.5D ambient multiply + additive light cookies (`createPointLight25D`, `drawAmbientDarknessPass25D`, `drawLightCookie25D`, `renderLightingPass25D`), 8-directional pre-rendered 3D isometric sprite rigs (`direction8FromVelocity`, `createIsoSpriteRig25D`, `stepIsoSpriteRig25D`, `drawContactShadow25D`, `drawSpriteBillboard25D`, `drawIsoSpriteRig25D`), and 2.5D atmospheric weather & ground mist (`createRainSystem25D`, `stepAndDrawRain25D`, `createEmberSmokeEmitter25D`, `stepAndDrawEmberSmoke25D`, `drawGroundMist25D`).
  - `gfx3d` (11 modules, 107 functions) — 3D camera, mesh loading, procedural heightfields (`terrain3d`), PBR lighting, frustum culling, raycasting.
  - `particle` (8 modules, 52 functions) — 2D/3D particle simulation, burst emitters, vortex affectors.
  - `ui` (14 modules, 553 functions) — AuraDesign immediate-mode UI, flexbox/grid layout, MD3 tokens, Watcher HUD, accessibility.
- **Layer 5 ($L_5$): Simulation, Procgen, AI & Capstone Mechanics**:
  - `ecs` (8 modules, 29 functions) — Archetype ECS world, generational entity IDs, query iterators.
  - `spatial` (9 modules, 58 functions) — Spatial partitioning, quadtrees, octrees, BVH, 8 world topologies.
  - `phys2d` (10 modules, 46 functions) — 2D symplectic Euler rigid bodies, continuous collision detection, springs.
  - `phys3d` (9 modules, 35 functions) — 3D rigid bodies, inertia tensors, raycast vehicle suspension.
  - `procgen` (8 modules, 36 functions) — Perlin/Simplex/Worley noise, BSP dungeon carving, cellular cave automata.
  - `ai` (9 modules, 165 functions) & `hebar` (2 modules: `referee` + `hebar_mod`, 16 re-exported functions) — Behavior trees, GOAP planner, Utility AI, boids flocking, 5-bound HEBAR referee guard (`std/ai/hebar_referee`, `std/hebar/referee`, `std/hebar/hebar_mod`).
  - `mechanics` (5 modules, 95 functions) — Stat modifier pipelines, inventories, dialogue DAGs, economy ledgers.

### Architectural Boundary: Discrete 2D Tile Grids vs. Continuous 2.5D/3D Worlds

- **Discrete 2D Grid Games**: Use `std/gfx2d/tilemap_renderer2d` (`Tilemap2D`, `WangBlob47Autotiler`, `tilemapMoveAndSlide`) for classic integer-indexed 2D tilemaps and platformers.
- **Continuous 2.5D/3D Isometric & Organic Worlds**: Never approximate organic rolling hills, curved rivers, or volumetric towns with flat-shaded diamond tile loops (`drawIsoDiamond`). Use `std/gfx25d/*` (`Camera25D`, `drawHeightfieldPatch25D`, `drawHeightfieldPatchTextured25D`, `drawHeightfieldSplat25D`, `drawGroundDecal25D`, `drawSplineRibbon25D`, `drawSplineRibbonTextured25D`, `drawPrism25D`, `drawPrismTextured25D`, `drawCone25D`, `drawBillboard25D`, `renderLightingPass25D`, `drawIsoSpriteRig25D`, `drawSpriteBillboard25D`, `stepAndDrawRain25D`, `stepAndDrawEmberSmoke25D`, `drawGroundMist25D`) paired with `std/gfx3d/terrain3d` (`TerrainHeightfield`, `sampleTerrainHeightBilinear`, `computeTerrainNormal`), `setDepthTest(true)`, `clearDepth()`, `setBlendMode(mode)`, and `beginWorldPass()` / `endWorldPass()`.

---

## 2. 38-Domain Master Navigation Table
| # | Domain | Modules | Functions | Primary Guide | Unit Test Directory |
| :---: | :--- | :---: | :---: | :--- | :--- |
| **01** | `core` (builtins & prelude) | 3 | 74 | [01_builtins_root_and_prelude.md](reference/01_builtins_root_and_prelude.md) | `tests/functions/core/` |
| **02** | `sys` | 9 | 109 | [02_sys.md](reference/02_sys.md) | `tests/functions/sys/` |
| **03** | `rt` | 8 | 119 | [03_rt.md](reference/03_rt.md) | `tests/functions/rt/` |
| **04** | `alloc` | 6 | 54 | [04_alloc.md](reference/04_alloc.md) | `tests/functions/alloc/` |
| **05** | `math` | 16 | 440 | [05_math.md](reference/05_math.md) | `tests/functions/math/` |
| **06** | `collections` | 14 | 220 | [06_collections.md](reference/06_collections.md) | `tests/functions/collections/` |
| **07** | `fmt` | 5 | 125 | [07_fmt.md](reference/07_fmt.md) | `tests/functions/fmt/` |
| **08** | `regex` | 4 | 53 | [08_regex.md](reference/08_regex.md) | `tests/functions/regex/` |
| **09** | `time` | 7 | 165 | [09_time.md](reference/09_time.md) | `tests/functions/time/` |
| **10** | `encoding` | 14 | 269 | [10_encoding.md](reference/10_encoding.md) | `tests/functions/encoding/` |
| **11** | `compress` | 7 | 35 | [11_compress.md](reference/11_compress.md) | `tests/functions/compress/` |
| **12** | `crypto` | 8 | 64 | [12_crypto.md](reference/12_crypto.md) | `tests/functions/crypto/` |
| **13** | `db` | 3 | 78 | [13_db.md](reference/13_db.md) | `tests/functions/db/` |
| **14** | `io` | 6 | 54 | [14_io.md](reference/14_io.md) | `tests/functions/io/` |
| **15** | `fs` | 8 | 57 | [15_fs.md](reference/15_fs.md) | `tests/functions/fs/` |
| **16** | `os` | 6 | 145 | [16_os.md](reference/16_os.md) | `tests/functions/os/` |
| **17** | `sync` | 6 | 74 | [17_sync.md](reference/17_sync.md) | `tests/functions/sync/` |
| **18** | `thread` | 4 | 38 | [18_thread.md](reference/18_thread.md) | `tests/functions/thread/` |
| **19** | `net` | 11 | 78 | [19_net.md](reference/19_net.md) | `tests/functions/net/` |
| **20** | `test` | 5 | 32 | [20_test.md](reference/20_test.md) | `tests/functions/test/` |
| **21** | `window` | 6 | 28 | [21_window.md](reference/21_window.md) | `tests/functions/window/` |
| **22** | `input` | 7 | 51 | [22_input.md](reference/22_input.md) | `tests/functions/input/` |
| **23** | `asset` | 8 | 159 | [23_asset.md](reference/23_asset.md) | `tests/functions/asset/` |
| **24** | `audio` | 7 | 159 | [24_audio.md](reference/24_audio.md) | `tests/functions/audio/` |
| **25** | `gfx` | 10 | 55 | [25_gfx.md](reference/25_gfx.md) | `tests/functions/gfx/` |
| **26** | `gfx2d` | 12 | 434 | [26_gfx2d.md](reference/26_gfx2d.md) | `tests/functions/gfx2d/` |
| **27** | `gfx3d` | 11 | 107 | [27_gfx3d.md](reference/27_gfx3d.md) | `tests/functions/gfx3d/` |
| **28** | `particle` | 8 | 52 | [28_particle.md](reference/28_particle.md) | `tests/functions/particle/` |
| **29** | `ui` | 14 | 553 | [29_ui.md](reference/29_ui.md) | `tests/functions/ui/` |
| **30** | `ecs` | 8 | 29 | [30_ecs.md](reference/30_ecs.md) | `tests/functions/ecs/` |
| **31** | `spatial` | 9 | 58 | [31_spatial.md](reference/31_spatial.md) | `tests/functions/spatial/` |
| **32** | `phys2d` | 10 | 46 | [32_phys2d.md](reference/32_phys2d.md) | `tests/functions/phys2d/` |
| **33** | `phys3d` | 9 | 35 | [33_phys3d.md](reference/33_phys3d.md) | `tests/functions/phys3d/` |
| **34** | `procgen` | 8 | 36 | [34_procgen.md](reference/34_procgen.md) | `tests/functions/procgen/` |
| **35** | `ai` | 9 | 165 | [35_ai.md](reference/35_ai.md) | `tests/functions/ai/` |
| **36** | `mechanics` | 5 | 95 | [36_mechanics.md](reference/36_mechanics.md) | `tests/functions/mechanics/` |
| **37** | `gfx25d` | 7 | 34 | [37_gfx25d.md](reference/37_gfx25d.md) | `tests/functions/gfx25d/` |
| **38** | `hebar` | 2 | 16 (re-export) | [38_hebar.md](reference/38_hebar.md) | `tests/functions/hebar/` |
### 2.1 Continuous 2.5D/3D World Engine (`std/gfx25d/*`), Hardware Depth/Gouraud Intrinsics & HEBAR Referee Signatures

| Module | Public Structs & Function Signatures |
| :--- | :--- |
| `std/gfx25d/camera25d` | `AABB2D(minX, minY, maxX, maxY)`, `Camera25D(worldX, worldY, worldZ, zoom, yawRad, pitchRad, viewportW, viewportH, depthNear, depthFar, followSharpness)`, `createCamera25D(viewportW: float, viewportH: float, zoom: float = 1.0, yawDeg: float = 45.0, pitchDeg: float = 30.0): Camera25D`, `project3DToIso(cam: Camera25D, wx: float, wy: float, wz: float): Vec3`, `unprojectIsoTo3D(cam: Camera25D, sx: float, sy: float, planeWz: float): Vec3`, `getVisibleWorldAABB(cam: Camera25D, minElevation: float, maxElevation: float): AABB2D`, `updateCamera25D(cam: Camera25D, targetWx: float, targetWy: float, terrainWz: float, dt: float): Camera25D` |
| `std/gfx25d/mesh25d` | `Vertex25D(pos: Vec3, normal: Vec3, color: Color)`, `IndexedMesh25D(vertices: [Vertex25D], indices: [int])`, `Vertex25DTextured(pos: Vec3, normal: Vec3, uv: Vec2, color: Color)`, `IndexedMesh25DTextured(vertices: [Vertex25DTextured], indices: [int], texId: int)`, `shadeVertex25D(baseColor: Color, normal: Vec3, sunDir: Vec3, ambient: float = 0.35): Color`, `drawHeightfieldPatch25D(cam: Camera25D, terrain: TerrainHeightfield, startGx: int, startGz: int, cellsX: int, cellsZ: int, sunDir: Vec3, lowColor: Color, highColor: Color): int`, `drawHeightfieldPatchTextured25D(cam: Camera25D, terrain: TerrainHeightfield, startGx: int, startGz: int, cellsX: int, cellsZ: int, sunDir: Vec3, flatTexId: int, slopeTexId: int, uvScale: float = 0.25): int`, `drawHeightfieldSplat25D(cam: Camera25D, terrain: TerrainHeightfield, startGx: int, startGz: int, cellsX: int, cellsZ: int, sunDir: Vec3, grassTexId: int, dirtTexId: int, rockTexId: int, cobbleTexId: int, roadCenterWx: float, roadCenterWy: float, roadRadius: float, uvScale: float = 0.35): int`, `drawGroundDecal25D(cam: Camera25D, texId: int, wx: float, wy: float, wz: float, radiusX: float, radiusY: float, rotRad: float, tintColor: Color, zLift: float = 0.15): int`, `drawIndexedMesh25D(cam: Camera25D, mesh: IndexedMesh25D, sunDir: Vec3): int`, `drawIndexedMeshTextured25D(cam: Camera25D, mesh: IndexedMesh25DTextured, sunDir: Vec3): int`, `drawPrism25D(cam: Camera25D, centerWx: float, centerWy: float, baseWz: float, sizeX: float, sizeY: float, heightZ: float, baseColor: Color, sunDir: Vec3): int`, `drawPrismTextured25D(cam: Camera25D, centerWx: float, centerWy: float, baseWz: float, sizeX: float, sizeY: float, heightZ: float, wallTexId: int, roofTexId: int, baseColor: Color, sunDir: Vec3): int`, `drawCone25D(cam: Camera25D, centerWx: float, centerWy: float, baseWz: float, radius: float, heightZ: float, baseColor: Color, sunDir: Vec3, segments: int = 8): int`, `drawBillboard25D(cam: Camera25D, wx: float, wy: float, wz: float, pixelW: float, pixelH: float, topColor: Color, bottomColor: Color): int` |
| `std/gfx25d/ribbon25d` | `RibbonVertex25D(centerPt: Vec3, tangent: Vec3, normal: Vec3, leftPt: Vec3, rightPt: Vec3, leftFeatherPt: Vec3, rightFeatherPt: Vec3)`, `extrudeSplineRibbon25D(nodes: [Vec3], halfWidth: float, featherWidth: float = 2.0): [RibbonVertex25D]`, `drawSplineRibbon25D(cam: Camera25D, nodes: [Vec3], halfWidth: float, centerColor: Color, edgeColor: Color, featherWidth: float = 2.0): int`, `drawSplineRibbonTextured25D(cam: Camera25D, nodes: [Vec3], halfWidth: float, texId: int, uvScrollU: float, uvScale: float, tintColor: Color, zLift: float = 0.25): int` |
| `std/gfx25d/light25d` | `PointLight25D(wx: float, wy: float, wz: float, radius: float, color: Color, intensity: float, flickerAmp: float, flickerSpeed: float)`, `createPointLight25D(wx: float, wy: float, wz: float, radius: float, color: Color, intensity: float = 1.0, flickerAmp: float = 0.12, flickerSpeed: float = 7.0): PointLight25D`, `drawAmbientDarknessPass25D(viewportW: float, viewportH: float, ambientColor: Color): int`, `drawLightCookie25D(cam: Camera25D, lightCookieTexId: int, light: PointLight25D, timeSec: float): int`, `renderLightingPass25D(cam: Camera25D, viewportW: float, viewportH: float, ambientColor: Color, lightCookieTexId: int, lights: [PointLight25D], timeSec: float): int` |
| `std/gfx25d/sprite25d` | `IsoSpriteRig25D(sheetTexId: int, frameW: int, frameH: int, dirs: int, framesPerDir: int, wx: float, wy: float, wz: float, vx: float, vy: float, dir8: int, animFrame: int, animTimer: float, fps: float, scale: float)`, `direction8FromVelocity(vx: float, vy: float, fallbackDir8: int = 4): int`, `createIsoSpriteRig25D(sheetTexId: int, frameW: int, frameH: int, dirs: int, framesPerDir: int, wx: float, wy: float, wz: float, scale: float = 1.0, fps: float = 10.0): IsoSpriteRig25D`, `stepIsoSpriteRig25D(rig: IsoSpriteRig25D, vx: float, vy: float, terrainWz: float, dt: float): IsoSpriteRig25D`, `drawContactShadow25D(cam: Camera25D, shadowCookieTexId: int, wx: float, wy: float, wz: float, pixelW: float, pixelH: float, alpha: float = 0.55): int`, `drawSpriteBillboard25D(cam: Camera25D, sheetTexId: int, wx: float, wy: float, wz: float, pixelW: float, pixelH: float, u0: float, v0: float, u1: float, v1: float, tintColor: Color): int`, `drawIsoSpriteRig25D(cam: Camera25D, rig: IsoSpriteRig25D, shadowCookieTexId: int, tintColor: Color): int` |
| `std/gfx25d/weather25d` | `RainDrop25D(wx: float, wy: float, wz: float, groundWz: float, splashTime: float, splashMax: float)`, `RainSystem25D(drops: [RainDrop25D], windVx: float, windVy: float, fallSpeed: float, areaHalfExtent: float)`, `EmberParticle25D(wx: float, wy: float, wz: float, vx: float, vy: float, vz: float, life: float, maxLife: float, isSmoke: bool, sizePx: float)`, `EmberSmokeEmitter25D(originWx: float, originWy: float, originWz: float, particles: [EmberParticle25D], timeAccum: float)`, `createRainSystem25D(dropCount: int, areaHalfExtent: float, windVx: float = -18.0, windVy: float = 12.0, fallSpeed: float = 110.0): RainSystem25D`, `stepAndDrawRain25D(cam: Camera25D, mut rain: RainSystem25D, centerWx: float, centerWy: float, groundWz: float, dt: float): RainSystem25D`, `createEmberSmokeEmitter25D(originWx: float, originWy: float, originWz: float, particleCount: int = 36): EmberSmokeEmitter25D`, `stepAndDrawEmberSmoke25D(cam: Camera25D, mut emitter: EmberSmokeEmitter25D, cookieTexId: int, dt: float): EmberSmokeEmitter25D`, `drawGroundMist25D(cam: Camera25D, mistTexId: int, centerWx: float, centerWy: float, baseWz: float, extent: float, timeSec: float, tintColor: Color): int` |
| `std/gfx25d/gfx25d_mod` | Barrel module re-exporting all public structs and functions from `camera25d`, `mesh25d`, `ribbon25d`, `light25d`, `sprite25d`, and `weather25d`. |
| `std/gfx2d/shape2d` (2.5D/3D, Blend Modes, UV Texture & UI Pass Intrinsics) | `setDepthTest(enabled: bool): void`, `clearDepth(): void`, `setBlendMode(mode: int): void`, `getBlendMode(): int`, `blendModeAlpha(): int`, `blendModeAdditive(): int`, `blendModeMultiplied(): int`, `blendModeScreen(): int`, `beginWorldPass(): void`, `endWorldPass(): void`, `setUiTracking(enabled: bool): void`, `drawTriangleGouraud(x1: float, y1: float, x2: float, y2: float, x3: float, y3: float, c1: Color, c2: Color, c3: Color): void`, `drawTriangle3DGouraud(x1: float, y1: float, z1: float, x2: float, y2: float, z2: float, x3: float, y3: float, z3: float, c1: Color, c2: Color, c3: Color): void`, `drawQuad3DGouraud(x1: float, y1: float, z1: float, x2: float, y2: float, z2: float, x3: float, y3: float, z3: float, x4: float, y4: float, z4: float, c1: Color, c2: Color, c3: Color, c4: Color): void`, `drawTriangle3DTextured(texId: int, x1: float, y1: float, z1: float, u1: float, v1: float, x2: float, y2: float, z2: float, u2: float, v2: float, x3: float, y3: float, z3: float, u3: float, v3: float, c1: Color, c2: Color, c3: Color): void`, `drawQuad3DTextured(texId: int, x1: float, y1: float, z1: float, u1: float, v1: float, x2: float, y2: float, z2: float, u2: float, v2: float, x3: float, y3: float, z3: float, u3: float, v3: float, x4: float, y4: float, z4: float, u4: float, v4: float, c1: Color, c2: Color, c3: Color, c4: Color): void`, `createTextureFromRgba(width: int, height: int, packedRgbaPixels: [int]): int`, `createProceduralTexture(kind: str, width: int, height: int, seed: int): int`, `createIsometricSpriteSheet(archetype: str, frameW: int, frameH: int, dirs: int, framesPerDir: int, seed: int): int`, `saveTextureToPpm(texId: int, filePath: str): bool` |
| `std/ai/hebar_referee`, `std/hebar/referee` & `std/hebar/hebar_mod` | `HebarActionRecord`, `HebarReferee`, `hebarRefereeNew(minDelayMs: int = 150, maxDelayMs: int = 250, maxApm: int = 900): HebarReferee`, `hebarEnqueueAction(mut referee: HebarReferee, action: HebarActionRecord, currentTimestampMs: int): bool`, `hebarPopReadyActions(mut referee: HebarReferee, currentTimestampMs: int): [HebarActionRecord]`, `hebarIsWithinApmLimit(actionsInWindow: int, windowDurationMs: int, maxApm: int = 900): bool`, `hebarClampReactionDelayMs(delayMs: int, minMs: int = 150, maxMs: int = 250): int`, `hebarStepCursorTrajectory(currentPos: Vec2, targetPos: Vec2, maxSpeedPxPerSec: float = 780.0, dtSec: float = 0.016667): Vec2`, `hebarClampAngularSlew(currentAngleRad: float, targetAngleRad: float, maxSlewRadPerSec: float = 6.283185307179586, dtSec: float = 0.016667): float`, `hebarVerifyZeroTampering(referee: HebarReferee, directMemoryWrites: int = 0): bool`, `connectTargetWindow(titleOrPid: str, timeoutMs: int = 3000): int`, `renderHebarRefereeDashboard(referee: HebarReferee, x: float, y: float, w: float, h: float): void`, `exportHebarTelemetryJson(referee: HebarReferee, filePath: str): bool`, `hebarQuantizeFloat(val: float): int`, `hebarHashInt(hashState: int, value: int): int`, `hebarHashFloat(hashState: int, value: float): int`, `hebarVerifyDeterminism(hashesA: [int], hashesB: [int]): bool`, `hebarStepDamageTrail(trailHp: float, currentHp: float, drainSpeed: float, dt: float): float` |
---

## 3. Standard Library Verification Check

```aipl
module tests.functions.core.std_root_stdlibDomainCount_test
import * from "std/std_root"
import * from "std/prelude"

pub fn test_std_root_stdlibDomainCount(): int:
  let doms = stdlibCanonicalDomains()
  assertEqInt(doms.len(), 37, "37 canonical domain directories")
  assertEqInt(stdlibLayerCount(), 6, "6 layers (0..5)")
  assert(stdlibIsCanonicalDomain("math") == true, "math is canonical domain")
  assert(stdlibIsCanonicalDomain("ui") == true, "ui is canonical domain")
  ret 0
```
