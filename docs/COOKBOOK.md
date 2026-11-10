# AIPL 51-Recipe Production Cookbook
**Single Source of Truth (SSOT) — Production Recipes Routing Hub**

[Home](../README.md) | [Docs Index](INDEX.md) | [Tutorials](tutorials/INDEX.md) | [Cookbook](tutorials/cookbook.md) | [Stdlib Reference](reference/STDLIB_REFERENCE.md) | [CLI Reference](CLI_REFERENCE.md)

> **When to Read This Document**: Read this index to locate immediate, tested, production-ready recipes across all 38 standard library domain groups. For full source code, contract annotations, and runnable snippets, navigate directly to the complete [51-Recipe Cookbook in docs/tutorials/cookbook.md](tutorials/cookbook.md).

---

## Cookbook Category Breakdown (51 Recipes)
1. **Category 1: Core Systems & Memory Architecture (Recipes 01–06)**:
   - Scoped Scratch Arena Allocation (`withScratchArena`)
   - Generational Object Pool Management
   - Zero-Copy Ring Buffer Streaming
   - Slabs and Fixed-Size Chunk Allocators
   - Memory Leak Profiling & GPA Tracking
   - Custom Linear Lifetimes & Arena Evacuation
2. **Category 2: Data Structures & High-Performance Collections (Recipes 07–12)**:
   - Contiguous Open-Addressing Hash Map
   - Priority Queue & Min-Max Heap
   - Dynamic BitSet with Popcount SIMD
   - Least-Recently Used (LRU) Cache
   - In-Memory Tri-Directional Radix Sort
   - Fast Circular Deque
3. **Category 3: String Processing, Formatting & Regular Expressions (Recipes 13–18)**:
   - ANSI Color Terminal Output Formatting
   - Thompson NFA Linear-Time Regex Matching
   - Zero-Allocation String Slicing & Word Wrapping
   - Float-to-Fixed and Hex Formatting
   - Fast UTF-8 Character Slicing & Validation
   - Custom String Template Interpolation
4. **Category 4: Serialization, Compression & Database Persistence (Recipes 19–24)**:
   - Streaming JSON DOM Traversal & Path Queries
   - Gzip Compression & In-Memory Deflate Streams
   - ChaCha20-Poly1305 AEAD Cryptographic Encryption
   - Single-File Write-Ahead Log (WAL) Key-Value Store
   - Base64 URL-Safe Serialization
   - CSV Delimited Table Parser
5. **Category 5: Streaming I/O, OS Integration & Networking (Recipes 25–30)**:
   - Buffered File Readers with Custom Buffers
   - Cross-Platform Child Process Execution
   - TCP Socket Client/Server Connection Handshake
   - UDP Datagram Broadcast & Packet Assembly
   - Non-Blocking File Watcher (`watchDir`)
   - Positional File Reads & Atomic Writes
6. **Category 6: Multithreading, Concurrency & Synchronization (Recipes 31–34)**:
   - Work-Stealing Parallel Task System
   - Atomic Primitives & Lock-Free Spinlocks
   - Scoped Fiber Coroutines & Yielding
   - Bounded Channel Producer-Consumer Queue
7. **Category 7: Windowing, Input & Audio Synthesis (Recipes 35–38)**:
   - 60/144 FPS Fixed-Timestep Window Game Loop
   - Multi-Device Input Action Map (Keyboard, Mouse, Gamepad)
   - 16-Voice Polyphonic Audio Tone Synthesis
   - 3D Doppler Spatial Audio Attenuation
8. **Category 8: 2D, 2.5D & 3D Graphics, Shaders & Particles (Recipes 39–43, 51)**:
   - High-Throughput 2D Sprite Batching
   - 3D Perspective Orbit Camera with Frustum Culling
   - Physically Based Rendering (PBR) Lambertian Mesh
   - Zero-Allocation Burst Particle Emitter
   - Continuous 2D Canvas Affine Matrix Transforms
   - Continuous 2.5D/3D Isometric Heightfield, Multi-Biome Splatting, 2.5D Lighting, 8-Dir Sprite Rigs & Weather (`std/gfx25d/*`, `beginWorldPass`/`endWorldPass` — Recipe 51)
9. **Category 9: AuraDesign Immediate-Mode UI & Layout (Recipes 44–47)**:
   - Responsive Two-Pass Flexbox & Grid Layout
   - Dynamic Telemetry Sparklines & Gauges
   - Accessible Keyboard-Navigable Form Controls
   - Modal Dialogs & Topmost Dropdown Overlays
10. **Category 10: ECS, Simulation, AI & Autonomous Tooling (Recipes 48–50)**:
    - Sparse-Set Generational Entity-Component-System
    - Composable Behavior Tree AI Decision Making & 5-Bound HEBAR Referee (`std/hebar/referee`, `connectTargetWindow`)
    - Deterministic Wave Function Collapse, Noise Procgen & 4-Target Fuzzing Parity
---

## Cookbook Verification Example

```aipl
module tests.tutorials.cookbook_hub_verify
import * from "std/prelude"

pub fn verify_cookbook_hub(): int:
  let recipeCount = 51
  assertEqInt(recipeCount, 51, "51 production recipes cataloged")
  ret 0
```

---

## Building Continuous & UV-Textured 2.5D Isometric Worlds (`std/gfx25d`)

Use `Camera25D`, `createProceduralTexture`, `createIsometricSpriteSheet`, `drawHeightfieldPatch25D`, `drawHeightfieldPatchTextured25D`, `drawHeightfieldSplat25D`, `drawGroundDecal25D`, `drawSplineRibbon25D`, `drawSplineRibbonTextured25D`, `drawPrism25D`, `drawPrismTextured25D`, `renderLightingPass25D`, `stepIsoSpriteRig25D`, `drawSpriteBillboard25D`, `drawIsoSpriteRig25D`, `stepAndDrawRain25D`, `stepAndDrawEmberSmoke25D`, `drawGroundMist25D`, `setDepthTest(true)`, `clearDepth()`, `setBlendMode(mode)`, and `beginWorldPass()` / `endWorldPass()` to render seamless heightfield terrains, multi-biome alpha splatting, UV-scrolled rivers, Z-buffered volumetric buildings, 8-directional sprite rigs, and 2.5D light cookies without flat-shaded diamond tile seams:

```aipl
module tests.tutorials.gfx25d_continuous_world_cookbook
import { Vec3 } from "std/math/vec_math"
import { rgb, setDepthTest, clearDepth, beginWorldPass, endWorldPass, createProceduralTexture } from "std/gfx2d/shape2d"
import { TerrainHeightfield } from "std/gfx3d/terrain3d"
import { Camera25D, createCamera25D, drawHeightfieldPatchTextured25D, drawSplineRibbonTextured25D, drawPrismTextured25D } from "std/gfx25d/gfx25d_mod"
import { assert, assertEqInt } from "std/prelude"

pub fn test_continuous_world_25d_cookbook(): int:
  let cam: Camera25D = createCamera25D(800.0, 600.0, 1.25, 45.0, 30.0)
  let heights: [float] = [0.1, 0.2, 0.4, 0.2, 0.3, 0.6, 0.3, 0.5, 0.8]
  let terrain = TerrainHeightfield(width = 3, depth = 3, heightValues = heights, heightScale = 30.0, horizontalScale = 24.0)
  let sunDir = Vec3(x = -0.45, y = -0.55, z = 0.70)
  let riverNodes: [Vec3] = [Vec3(x = 0.0, y = 0.0, z = 4.0), Vec3(x = 24.0, y = 24.0, z = 6.0), Vec3(x = 48.0, y = 48.0, z = 8.0)]
  let grassTex = createProceduralTexture("grass", 16, 16, 101)
  let rockTex = createProceduralTexture("rock", 16, 16, 202)
  let waterTex = createProceduralTexture("water", 16, 16, 303)
  let brickTex = createProceduralTexture("brick", 16, 16, 404)
  let roofTex = createProceduralTexture("roof", 16, 16, 505)
  setDepthTest(true)
  clearDepth()
  beginWorldPass()
  let quads = drawHeightfieldPatchTextured25D(cam, terrain, 0, 0, 2, 2, sunDir, grassTex, rockTex, 0.25)
  let rQuads = drawSplineRibbonTextured25D(cam, riverNodes, 6.0, waterTex, 0.15, 0.08, rgb(195, 232, 255), 0.25)
  let pFaces = drawPrismTextured25D(cam, 24.0, 24.0, 6.0, 14.0, 14.0, 20.0, brickTex, roofTex, rgb(245, 238, 228), sunDir)
  endWorldPass()
  setDepthTest(false)
  assertEqInt(quads, 4, "2x2 textured heightfield patch draws 4 quads")
  assert(rQuads >= 2, "textured spline ribbon draws river segments")
  assertEqInt(pFaces, 5, "textured volumetric prism draws 5 shaded faces")
  ret 0
```
