# AIPL Master Progressive Tutorials Curriculum (12 Chapters)
**Single Source of Truth (SSOT) — Progressive Learning Hub**

[Home](../README.md) | [Docs Index](INDEX.md) | [Tutorials](tutorials/INDEX.md) | [Cookbook](tutorials/cookbook.md) | [Stdlib Reference](reference/STDLIB_REFERENCE.md) | [CLI Reference](CLI_REFERENCE.md)

> **When to Read This Document**: Read this curriculum index to navigate the 12 progressive, step-by-step tutorials from initial language syntax to advanced multi-target systems and autonomous AI agent tooling. For individual chapters, follow the links below into [`docs/tutorials/`](tutorials/INDEX.md).

---

## 1. 12-Chapter Progressive Learning Curriculum

| Chapter | Title | Key Concepts & Primitives | Guide |
| :---: | :--- | :--- | :--- |
| **01** | **Getting Started & Syntax** | 2-space indentation offside rule, `let` vs `mut`, primitives, string interpolation, comments | [01_getting_started_and_syntax.md](tutorials/01_getting_started_and_syntax.md) |
| **02** | **Functions, Closures & Contracts** | Function declarations, first-class closures, `req:` preconditions, `ens:` postconditions, SMT checks | [02_functions_closures_and_contracts.md](tutorials/02_functions_closures_and_contracts.md) |
| **03** | **Structs, Enums, Generics & Match** | Nominal `struct`, functional updates (`orig { field = val }`, `cloneStruct`), algebraic `enum`, generic containers, exhaustive `match`, receiver methods | [03_structs_enums_generics_and_match.md](tutorials/03_structs_enums_generics_and_match.md) |
| **04** | **Memory Model: Arenas, Pools & Zero-GC** | Regional bump arenas (`with arena:`), generational pools, slab allocators, zero GC pauses | [04_memory_arenas_pools_and_zero_gc.md](tutorials/04_memory_arenas_pools_and_zero_gc.md) |
| **05** | **Collections, Math & Text Processing** | Dynamic arrays (`[T]`), hash maps (`Map[K, V]`), linear algebra, Thompson NFA regex, formatting | [05_collections_math_and_text_processing.md](tutorials/05_collections_math_and_text_processing.md) |
| **06** | **Serialization, Compression & Crypto** | JSON DOM parser, Gzip/Deflate compression, SHA-256, ChaCha20-Poly1305, embedded KV database | [06_serialization_compression_crypto_and_databases.md](tutorials/06_serialization_compression_crypto_and_databases.md) |
| **07** | **I/O, Filesystem, Concurrency & Net** | Buffered streams, directory walking, threadpool, fibers, atomic sync, TCP/UDP sockets | [07_io_filesystem_cli_concurrency_and_networking.md](tutorials/07_io_filesystem_cli_concurrency_and_networking.md) |
| **08** | **Windowing, 2D Canvas & Input** | Window creation, event loop, fixed-timestep accumulator, 2D batch renderer, `beginWorldPass`/`endWorldPass`, input action mapping | [08_windowing_2d_canvas_camera_and_input.md](tutorials/08_windowing_2d_canvas_camera_and_input.md) |
| **09** | **2.5D/3D Graphics, PBR & Particles** | Continuous 2.5D/3D isometric worlds (`std/gfx25d/*`), hardware/software Z-buffer (`setDepthTest`, `clearDepth`), Gouraud shading, microfacet PBR, particles | [09_3d_graphics_pbr_shaders_and_particles.md](tutorials/09_3d_graphics_pbr_shaders_and_particles.md) |
| **10** | **Aura UI Framework & Accessibility** | AuraDesign immediate-mode widgets, flexbox/grid layout, MD3 tokens, WCAG 2.1 AA audit | [10_aura_immediate_mode_ui_and_accessibility.md](tutorials/10_aura_immediate_mode_ui_and_accessibility.md) |
| **11** | **ECS, Physics, Procgen & AI** | Archetype ECS, 2D/3D rigid-body physics, Perlin/Simplex noise, Behavior Trees, 5-bound HEBAR referee (`std/hebar/referee`) | [11_ecs_spatial_worlds_physics_procgen_and_ai.md](tutorials/11_ecs_spatial_worlds_physics_procgen_and_ai.md) |
| **12** | **Testing, Fuzzing & Multi-Target Deployment** | Unit test runner, mutational fuzz testing, C99, TypeScript, WebAssembly, single-file HTML5 | [12_testing_fuzzing_and_multi_target_deployment.md](tutorials/12_testing_fuzzing_and_multi_target_deployment.md) |

---

## 2. Production Recipes: The AIPL Cookbook

Looking for immediate, copy-pasteable solutions to common systems and application patterns? Browse the [AIPL 50-Recipe Production Cookbook](tutorials/cookbook.md) covering:
- **Core Systems & Memory** (Recipes 01–06): Scoped scratch arenas, generational handles, ring buffers.
- **Data Structures & Algorithms** (Recipes 07–12): LRU cache, A* pathfinding, Myers diff, topological sort.
- **Serialization & Networking** (Recipes 13–18): Safe JSON decoding, streaming HTTP, binary RPC packets.
- **Concurrency & Multithreading** (Recipes 19–23): Work-stealing pool, actor channels, atomic spinlocks.
- **Graphics & Visualization** (Recipes 24–30): Sprite batching, 3D orbit camera, particle systems, procedural noise.
- **User Interface & Layout** (Recipes 31–36): Responsive grid cards, modal dialogs, accessible forms.
- **Game Engine & Simulation** (Recipes 37–43): Platformer kinematics, spatial hash broadphase, dialogue trees.
- **Testing, Profiling & Tooling** (Recipes 44–50): Fuzz testing, TAP output, AST splicing.

---

## 3. Quickstart Verification Example

```aipl
module tests.tutorials.quickstart_verify
import * from "std/prelude"

pub fn verify_quickstart_tutorial(): int:
  let message = "Welcome to AIPL"
  assertEqStr(message, "Welcome to AIPL", "tutorial greeting matches")
  ret 0
```

---

## 4. Building Continuous & UV-Textured 2.5D Isometric Worlds (`std/gfx25d`)

For continuous heightfield terrains, multi-biome alpha splatting, UV-scrolled rivers, textured volumetric buildings, 8-directional isometric sprite rigs, and 2.5D lighting/weather, combine `std/gfx25d/*` (`Camera25D`, `drawHeightfieldPatch25D`, `drawHeightfieldPatchTextured25D`, `drawHeightfieldSplat25D`, `drawGroundDecal25D`, `drawSplineRibbon25D`, `drawSplineRibbonTextured25D`, `drawPrism25D`, `drawPrismTextured25D`, `drawCone25D`, `renderLightingPass25D`, `drawIsoSpriteRig25D`, `drawMistPlanes25D`, `drawWeatherParticles25D`) with `std/gfx3d/terrain3d`, `createProceduralTexture`, `createIsometricSpriteSheet`, and hardware/software depth testing & blend modes (`setDepthTest(true)`, `clearDepth()`, `setBlendMode(mode)`, `beginWorldPass()`, `endWorldPass()`; showcased in `ex_259`, `ex_260`, `ex_261`, `ex_262`, and `ex_263`):

```aipl
module tests.tutorials.gfx25d_tutorial_verify
import { Vec3 } from "std/math/vec_math"
import { rgb, setDepthTest, clearDepth, beginWorldPass, endWorldPass } from "std/gfx2d/shape2d"
import { TerrainHeightfield } from "std/gfx3d/terrain3d"
import { Camera25D, createCamera25D, drawHeightfieldPatch25D, drawSplineRibbon25D, drawPrism25D } from "std/gfx25d/gfx25d_mod"
import { assert, assertEqInt } from "std/prelude"

pub fn test_tutorial_continuous_world_25d(): int:
  let cam: Camera25D = createCamera25D(800.0, 600.0, 1.25, 45.0, 30.0)
  let heights: [float] = [0.1, 0.2, 0.4, 0.2, 0.3, 0.6, 0.3, 0.5, 0.8]
  let terrain = TerrainHeightfield(width = 3, depth = 3, heightValues = heights, heightScale = 30.0, horizontalScale = 24.0)
  let sunDir = Vec3(x = -0.45, y = -0.55, z = 0.70)
  let riverNodes: [Vec3] = [Vec3(x = 0.0, y = 0.0, z = 4.0), Vec3(x = 24.0, y = 24.0, z = 6.0), Vec3(x = 48.0, y = 48.0, z = 8.0)]
  setDepthTest(true)
  clearDepth()
  beginWorldPass()
  let quads = drawHeightfieldPatch25D(cam, terrain, 0, 0, 2, 2, sunDir, rgb(58, 128, 68), rgb(156, 172, 142))
  let rQuads = drawSplineRibbon25D(cam, riverNodes, 6.0, rgb(28, 118, 206), rgb(96, 182, 245), 2.0)
  let pFaces = drawPrism25D(cam, 24.0, 24.0, 6.0, 14.0, 14.0, 20.0, rgb(210, 185, 145), sunDir)
  endWorldPass()
  setDepthTest(false)
  assertEqInt(quads, 4, "2x2 heightfield patch draws 4 Gouraud quads")
  assert(rQuads >= 4, "spline ribbon draws river core and feathered banks")
  assertEqInt(pFaces, 5, "volumetric prism draws 5 shaded faces")
  ret 0
```
