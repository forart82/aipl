[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](INDEX.md) | [Cookbook](cookbook.md) | [Stdlib Reference](../STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Chapter 09: 3D Graphics, PBR, Shaders & Particles

> **Chapter Summary**: 3D perspective/orbit cameras, frustum culling, Cook-Torrance GGX PBR materials, cascaded shadow mapping, procedural 3D meshes, dual-quaternion skeletal skinning, 3D FABRIK IK, curl-noise particle emitters, and spatial 3D audio.

## Table of Contents
- [Chapter 09.1: 3D Perspective/Orbit Cameras, Transform Hierarchies & Frustum Culling (std/gfx3d/*)](#chapter-091-3d-perspectiveorbit-cameras-transform-hierarchies--frustum-culling-stdgfx3d)
- [Chapter 09.2: Procedural 3D Meshes, Cook-Torrance GGX PBR Materials, Cascaded Shadows & Skybox (std/gfx3d/*)](#chapter-092-procedural-3d-meshes-cook-torrance-ggx-pbr-materials-cascaded-shadows--skybox-stdgfx3d)
- [Chapter 09.3: Dual-Quaternion Skeletal Skinning, 3D FABRIK IK, Post-Processing & Terrain LOD (std/gfx3d/*)](#chapter-093-dual-quaternion-skeletal-skinning-3d-fabrik-ik-post-processing--terrain-lod-stdgfx3d)
- [Chapter 09.4: 2D/3D Curl-Noise Particle Systems, Trail Ribbons & Polyphonic Spatial Audio (std/particle/*, std/audio/*)](#chapter-094-2d3d-curl-noise-particle-systems-trail-ribbons--polyphonic-spatial-audio-stdparticle-stdaudio)

---

### Chapter 09.1: 3D Perspective/Orbit Cameras, Transform Hierarchies & Frustum Culling (std/gfx3d/*)

#### 1. Concept in 30 Seconds
Teach `camera3d`, `transform3d`, and 6-plane Gribb-Hartmann frustum/occlusion culling (`cull3d`).

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn createPerspectiveCamera3D(pos: Vec3, target: Vec3, fovDeg: float, aspect: float, nearZ: float = 0.1, farZ: float = 1000.0): Camera3D:` from `std/gfx3d/camera3d.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.gfx3d.camera3d_z1_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_createPerspectiveCamera3D_1(): int:
  let arg_pos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_pos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_target = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_target = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_fovDeg = 1.0
  let edge_fovDeg = 0.5
  let arg_aspect = 1.0
  let edge_aspect = 0.5
  let arg_nearZ = 1.0
  let edge_nearZ = 0.5
  let arg_farZ = 1.0
  let edge_farZ = 0.5
  let resNom = createPerspectiveCamera3D(arg_pos, arg_target, arg_fovDeg, arg_aspect, arg_nearZ, arg_farZ)
  let resEdge = createPerspectiveCamera3D(edge_pos, edge_target, edge_fovDeg, edge_aspect, edge_nearZ, edge_farZ)
  assertApproxEq(resNom.fovYRad, 0.017453, 0.001, "createPerspectiveCamera3D nominal resNom.fovYRad ~= 0.017453")
  assertApproxEq(resEdge.fovYRad, 0.008727, 0.001, "createPerspectiveCamera3D boundary resEdge.fovYRad ~= 0.008727")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_174` | [examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl](../../examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl) | `tests/examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window_test.aipl` | `./bin/aipl test tests/examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window_test.aipl` |
| `ex_175` | [examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl](../../examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl) | `tests/examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window_test.aipl` | `./bin/aipl test tests/examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window_test.aipl` |
| `ex_176` | [examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl](../../examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl) | `tests/examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window_test.aipl` | `./bin/aipl test tests/examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window_test.aipl` |

---

### Chapter 09.2: Procedural 3D Meshes, Cook-Torrance GGX PBR Materials, Cascaded Shadows & Skybox (std/gfx3d/*)

#### 1. Concept in 30 Seconds
Teach `std/gfx/*` (`color`, `framebuffer`, `buffer`, `texture`, `shader`, `pipeline`, `render_pass`, `postprocess`) and `std/gfx3d/mesh3d`, `material3d`, `light3d`, `skybox3d`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn createDefaultPbrMaterial(): PbrMaterial3D:` from `std/gfx3d/material3d.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.gfx3d.material3d_z1_test
import * from "std/gfx3d/material3d"
import { PI, EPSILON, maxFloat, clampInt, clampFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8, LinearColorF32 } from "std/gfx/color"
import { lightComputeLambertDiffuseRGB, lightComputeBlinnPhongRGB, lightComputePbrCookTorranceRGB } from "std/gfx3d/light3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_material3d_createDefaultPbrMaterial_1(): int:
  let resNom = createDefaultPbrMaterial()
  let resEdge = createDefaultPbrMaterial()
  assertApproxEq(resNom.metallicFactor, 0.0, 0.001, "createDefaultPbrMaterial nominal resNom.metallicFactor ~= 0.0")
  assertApproxEq(resEdge.metallicFactor, 0.0, 0.001, "createDefaultPbrMaterial boundary resEdge.metallicFactor ~= 0.0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_154` | [examples/ex_154_gfx_color_spaces_and_wcag_palette_window.aipl](../../examples/ex_154_gfx_color_spaces_and_wcag_palette_window.aipl) | `tests/examples/ex_154_gfx_color_spaces_and_wcag_palette_window_test.aipl` | `./bin/aipl test tests/examples/ex_154_gfx_color_spaces_and_wcag_palette_window_test.aipl` |
| `ex_155` | [examples/ex_155_gfx_framebuffer_software_rasterizer_window.aipl](../../examples/ex_155_gfx_framebuffer_software_rasterizer_window.aipl) | `tests/examples/ex_155_gfx_framebuffer_software_rasterizer_window_test.aipl` | `./bin/aipl test tests/examples/ex_155_gfx_framebuffer_software_rasterizer_window_test.aipl` |
| `ex_156` | [examples/ex_156_gfx_gpu_device_and_swapchain_window.aipl](../../examples/ex_156_gfx_gpu_device_and_swapchain_window.aipl) | `tests/examples/ex_156_gfx_gpu_device_and_swapchain_window_test.aipl` | `./bin/aipl test tests/examples/ex_156_gfx_gpu_device_and_swapchain_window_test.aipl` |
| `ex_157` | [examples/ex_157_gfx_gpu_buffer_std140_inspector_window.aipl](../../examples/ex_157_gfx_gpu_buffer_std140_inspector_window.aipl) | `tests/examples/ex_157_gfx_gpu_buffer_std140_inspector_window_test.aipl` | `./bin/aipl test tests/examples/ex_157_gfx_gpu_buffer_std140_inspector_window_test.aipl` |
| `ex_158` | [examples/ex_158_gfx_gpu_texture_mipmap_aniso_window.aipl](../../examples/ex_158_gfx_gpu_texture_mipmap_aniso_window.aipl) | `tests/examples/ex_158_gfx_gpu_texture_mipmap_aniso_window_test.aipl` | `./bin/aipl test tests/examples/ex_158_gfx_gpu_texture_mipmap_aniso_window_test.aipl` |
| `ex_159` | [examples/ex_159_gfx_gpu_shader_wgsl_glsl_viewer_window.aipl](../../examples/ex_159_gfx_gpu_shader_wgsl_glsl_viewer_window.aipl) | `tests/examples/ex_159_gfx_gpu_shader_wgsl_glsl_viewer_window_test.aipl` | `./bin/aipl test tests/examples/ex_159_gfx_gpu_shader_wgsl_glsl_viewer_window_test.aipl` |

---

### Chapter 09.3: Dual-Quaternion Skeletal Skinning, 3D FABRIK IK, Post-Processing & Terrain LOD (std/gfx3d/*)

#### 1. Concept in 30 Seconds
Teach skeletal animation (`rigging3d`), heightmap CDLOD (`terrain3d`), `postfx3d`, and `renderer3d`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `fn composeBoneLocalMatrix(pos: Vec3, rot: Quat, scale: Vec3): Mat4:` from `std/gfx3d/rigging3d.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.gfx3d.rigging3d_z1_test
import * from "std/gfx3d/rigging3d"
import { DEG2RAD, RAD2DEG, EPSILON, absFloat, maxFloat, maxInt, clampFloat } from "std/math/consts"
import { sin, cos, acos, atan2, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigging3d_composeBoneLocalMatrix_1(): int:
  let arg_pos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_pos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_rot = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_rot = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_scale = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_scale = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = composeBoneLocalMatrix(arg_pos, arg_rot, arg_scale)
  let resEdge = composeBoneLocalMatrix(edge_pos, edge_rot, edge_scale)
  assertApproxEq(resNom.m00, 0.428571, 0.001, "composeBoneLocalMatrix nominal resNom.m00 ~= 0.428571")
  assertApproxEq(resEdge.m00, 0.214286, 0.001, "composeBoneLocalMatrix boundary resEdge.m00 ~= 0.214286")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_179` | [examples/ex_179_gfx3d_rigging3d_skeletal_skinning_window.aipl](../../examples/ex_179_gfx3d_rigging3d_skeletal_skinning_window.aipl) | `tests/examples/ex_179_gfx3d_rigging3d_skeletal_skinning_window_test.aipl` | `./bin/aipl test tests/examples/ex_179_gfx3d_rigging3d_skeletal_skinning_window_test.aipl` |
| `ex_181` | [examples/ex_181_gfx3d_terrain3d_cdlod_heightmap_window.aipl](../../examples/ex_181_gfx3d_terrain3d_cdlod_heightmap_window.aipl) | `tests/examples/ex_181_gfx3d_terrain3d_cdlod_heightmap_window_test.aipl` | `./bin/aipl test tests/examples/ex_181_gfx3d_terrain3d_cdlod_heightmap_window_test.aipl` |
| `ex_182` | [examples/ex_182_gfx3d_decal3d_projected_splatter_window.aipl](../../examples/ex_182_gfx3d_decal3d_projected_splatter_window.aipl) | `tests/examples/ex_182_gfx3d_decal3d_projected_splatter_window_test.aipl` | `./bin/aipl test tests/examples/ex_182_gfx3d_decal3d_projected_splatter_window_test.aipl` |
| `ex_183` | [examples/ex_183_particle_emitter2d_fountain_and_fire_window.aipl](../../examples/ex_183_particle_emitter2d_fountain_and_fire_window.aipl) | `tests/examples/ex_183_particle_emitter2d_fountain_and_fire_window_test.aipl` | `./bin/aipl test tests/examples/ex_183_particle_emitter2d_fountain_and_fire_window_test.aipl` |

---

### Chapter 09.4: 2D/3D Curl-Noise Particle Systems, Trail Ribbons & Polyphonic Spatial Audio (std/particle/*, std/audio/*)

#### 1. Concept in 30 Seconds
Teach `std/asset/*`, `std/audio/*` (`synth`, `mixer`, `dsp_effects`, `spatial_audio`), and `std/particle/*` (`emitter2d`, `emitter3d`, `affector`, `trail_ribbon`, `sub_emitter`).

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn createParticlePool2D(maxParticles: int = 1024, emissionRate: float = 100.0): ParticlePool2D:` from `std/particle/emitter2d.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.particle.emitter2d_z1_test
import * from "std/particle/emitter2d"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { ParticleAffector, AFFECTOR_GRAVITY, AFFECTOR_DRAG, AFFECTOR_VORTEX, AFFECTOR_CURL_NOISE, evaluateVortexForce, evaluateCurlNoiseForce } from "std/particle/affector"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_emitter2d_createParticlePool2D_1(): int:
  let arg_maxParticles = 4
  let edge_maxParticles = 1
  let arg_emissionRate = 2.0
  let edge_emissionRate = 1.0
  let resNom = createParticlePool2D(arg_maxParticles, arg_emissionRate)
  let resEdge = createParticlePool2D(edge_maxParticles, edge_emissionRate)
  assertEqInt(resNom.particles.len(), 0, "createParticlePool2D nominal resNom.particles.len() == 0")
  assertEqInt(resEdge.particles.len(), 0, "createParticlePool2D boundary resEdge.particles.len() == 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_142` | [examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl](../../examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl) | `tests/examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window_test.aipl` | `./bin/aipl test tests/examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window_test.aipl` |
| `ex_143` | [examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl](../../examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl) | `tests/examples/ex_143_asset_atlas_packer_shelf_maxrects_window_test.aipl` | `./bin/aipl test tests/examples/ex_143_asset_atlas_packer_shelf_maxrects_window_test.aipl` |
| `ex_144` | [examples/ex_144_asset_font_sdf_text_renderer_window.aipl](../../examples/ex_144_asset_font_sdf_text_renderer_window.aipl) | `tests/examples/ex_144_asset_font_sdf_text_renderer_window_test.aipl` | `./bin/aipl test tests/examples/ex_144_asset_font_sdf_text_renderer_window_test.aipl` |
| `ex_145` | [examples/ex_145_asset_gltf_mesh_inspector_window.aipl](../../examples/ex_145_asset_gltf_mesh_inspector_window.aipl) | `tests/examples/ex_145_asset_gltf_mesh_inspector_window_test.aipl` | `./bin/aipl test tests/examples/ex_145_asset_gltf_mesh_inspector_window_test.aipl` |
| `ex_146` | [examples/ex_146_asset_bundle_pak_archive_viewer_window.aipl](../../examples/ex_146_asset_bundle_pak_archive_viewer_window.aipl) | `tests/examples/ex_146_asset_bundle_pak_archive_viewer_window_test.aipl` | `./bin/aipl test tests/examples/ex_146_asset_bundle_pak_archive_viewer_window_test.aipl` |
| `ex_147` | [examples/ex_147_asset_manager_refcount_hot_reload_window.aipl](../../examples/ex_147_asset_manager_refcount_hot_reload_window.aipl) | `tests/examples/ex_147_asset_manager_refcount_hot_reload_window_test.aipl` | `./bin/aipl test tests/examples/ex_147_asset_manager_refcount_hot_reload_window_test.aipl` |

---

### Chapter 09.5: Building Continuous & UV-Textured 2.5D Isometric Worlds (std/gfx25d)

#### 1. Concept in 30 Seconds
Teach `std/gfx25d/camera25d`, `std/gfx25d/mesh25d`, `std/gfx25d/ribbon25d`, `std/gfx25d/light25d`, `std/gfx25d/sprite25d`, and `std/gfx25d/weather25d` alongside hardware/software Z-buffering (`setDepthTest(true)`, `clearDepth()`), 4 canonical blend modes (`setBlendMode`, `blendModeAlpha`, `blendModeAdditive`, `blendModeMultiplied`, `blendModeScreen`), UV texture & 3D isometric sprite-sheet synthesis (`createProceduralTexture`, `createIsometricSpriteSheet`, `createTextureFromRgba`, `saveTextureToPpm`, `drawTriangle3DTextured`, `drawQuad3DTextured`), and UI hitbox isolation (`beginWorldPass()`, `endWorldPass()`). Use `std/gfx2d/tilemap_renderer2d` for discrete 2D grid games, and `std/gfx25d/*` (`drawHeightfieldPatchTextured25D`, `drawHeightfieldSplat25D`, `drawGroundDecal25D`, `drawSplineRibbonTextured25D`, `drawPrismTextured25D`, `drawIndexedMeshTextured25D`, `renderLightingPass25D`, `drawIsoSpriteRig25D`, `drawBillboardCutout25D`, `drawMistPlanes25D`, `drawWeatherParticles25D`) + `std/gfx3d/terrain3d` for continuous heightfield terrains, rivers, mountains, dark-fantasy ARPG encampments, and isometric/2.5D worlds.

#### 2. Minimal Runnable Example
```aipl
module tests.functions.gfx25d.ch09_5_continuous_world_test
import { Vec3 } from "std/math/vec_math"
import { rgb, setDepthTest, clearDepth, beginWorldPass, endWorldPass, createProceduralTexture } from "std/gfx2d/shape2d"
import { TerrainHeightfield } from "std/gfx3d/terrain3d"
import { Camera25D, createCamera25D, drawHeightfieldPatchTextured25D, drawSplineRibbonTextured25D, drawPrismTextured25D } from "std/gfx25d/gfx25d_mod"
import { assert, assertEqInt } from "std/prelude"

pub fn test_ch09_5_continuous_world_25d(): int:
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

#### 3. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_259` | [examples/ex_259_continuous_world_25d.aipl](../../examples/ex_259_continuous_world_25d.aipl) | `tests/examples/ex_259_continuous_world_25d_test.aipl` | `./bin/aipl test tests/examples/ex_259_continuous_world_25d_test.aipl` |
| `ex_260` | [examples/ex_260_textured_25d_village_and_river_window.aipl](../../examples/ex_260_textured_25d_village_and_river_window.aipl) | `tests/examples/ex_260_textured_25d_village_and_river_window_test.aipl` | `./bin/aipl test tests/examples/ex_260_textured_25d_village_and_river_window_test.aipl` |
| `ex_261` | [examples/ex_261_textured_3d_gallery_and_uv_mesh_window.aipl](../../examples/ex_261_textured_3d_gallery_and_uv_mesh_window.aipl) | `tests/examples/ex_261_textured_3d_gallery_and_uv_mesh_window_test.aipl` | `./bin/aipl test tests/examples/ex_261_textured_3d_gallery_and_uv_mesh_window_test.aipl` |
| `ex_262` | [examples/ex_262_dark_fantasy_encampment_arpg_window.aipl](../../examples/ex_262_dark_fantasy_encampment_arpg_window.aipl) | `tests/examples/ex_262_dark_fantasy_encampment_arpg_window_test.aipl` | `./bin/aipl test tests/examples/ex_262_dark_fantasy_encampment_arpg_window_test.aipl` |
| `ex_263` | [examples/ex_263_isometric_8dir_rig_and_lighting_lab_window.aipl](../../examples/ex_263_isometric_8dir_rig_and_lighting_lab_window.aipl) | `tests/examples/ex_263_isometric_8dir_rig_and_lighting_lab_window_test.aipl` | `./bin/aipl test tests/examples/ex_263_isometric_8dir_rig_and_lighting_lab_window_test.aipl` |
