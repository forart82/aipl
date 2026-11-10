[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](INDEX.md) | [Cookbook](cookbook.md) | [Stdlib Reference](../STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Chapter 11: ECS, Spatial Worlds, Physics, Procgen & AI

> **Chapter Summary**: Archetype SoA Entity-Component-System (ECS) with change detection, 2D/3D spatial partitions (Hex, Iso, Voxel, NavMesh), 2D/3D rigid-body dynamics with SAT/GJK-EPA contacts, Wave Function Collapse (WFC) procgen, and autonomous NPC AI (A*, JPS, ORCA, GOAP, Behavior Trees).

## Table of Contents
- [Chapter 11.1: Archetype SoA Entity Component System, Change Detection & Parallel System DAG (std/ecs/*)](#chapter-111-archetype-soa-entity-component-system-change-detection--parallel-system-dag-stdecs)
- [Chapter 11.2: 2D/3D Spatial Worlds (Grid2D, HexGrid, IsoGrid, VoxelChunk3D, NavMesh, PortalGraph) (std/spatial/*)](#chapter-112-2d3d-spatial-worlds-grid2d-hexgrid-isogrid-voxelchunk3d-navmesh-portalgraph-stdspatial)
- [Chapter 11.3: 2D & 3D Rigid-Body Dynamics, SAT/GJK-EPA, Raycast Vehicles, Cloth & Fluids (std/phys2d/*, std/phys3d/*)](#chapter-113-2d--3d-rigid-body-dynamics-satgjk-epa-raycast-vehicles-cloth--fluids-stdphys2d-stdphys3d)
- [Chapter 11.4: Procedural Generation, Autonomous Game AI & RPG/Economy Mechanics (std/procgen/*, std/ai/*, std/mechanics/*)](#chapter-114-procedural-generation-autonomous-game-ai--rpgeconomy-mechanics-stdprocgen-stdai-stdmechanics)

---

### Chapter 11.1: Archetype SoA Entity Component System, Change Detection & Parallel System DAG (std/ecs/*)

#### 1. Concept in 30 Seconds
Teach `entity`, `archetype`, `query`, `command`, `event`, `schedule`, and `world` in `std/ecs/*`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn createEcsWorld(): EcsWorld:` from `std/ecs/ecs_world.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.ecs.ecs_world_z1_test
import * from "std/ecs/ecs_world"
import { EntityId, EntityPool, createEntityPool, allocateEntity, recycleEntity, isEntityAlive } from "std/ecs/entity"
import { ArchetypeTable, createArchetypeTable, insertArchetypeRow, swapRemoveArchetypeRow } from "std/ecs/archetype"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ecs_world_createEcsWorld_1(): int:
  let resNom = createEcsWorld()
  let resEdge = createEcsWorld()
  assertEqInt(resNom.archetypes.len(), 1, "createEcsWorld nominal resNom.archetypes.len() == 1")
  assertEqInt(resEdge.archetypes.len(), 1, "createEcsWorld boundary resEdge.archetypes.len() == 1")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_202` | [examples/ex_202_ecs_entity_generational_arena_window.aipl](../../examples/ex_202_ecs_entity_generational_arena_window.aipl) | `tests/examples/ex_202_ecs_entity_generational_arena_window_test.aipl` | `./bin/aipl test tests/examples/ex_202_ecs_entity_generational_arena_window_test.aipl` |
| `ex_203` | [examples/ex_203_ecs_archetype_table_migration_window.aipl](../../examples/ex_203_ecs_archetype_table_migration_window.aipl) | `tests/examples/ex_203_ecs_archetype_table_migration_window_test.aipl` | `./bin/aipl test tests/examples/ex_203_ecs_archetype_table_migration_window_test.aipl` |
| `ex_204` | [examples/ex_204_ecs_query_filter_radar_window.aipl](../../examples/ex_204_ecs_query_filter_radar_window.aipl) | `tests/examples/ex_204_ecs_query_filter_radar_window_test.aipl` | `./bin/aipl test tests/examples/ex_204_ecs_query_filter_radar_window_test.aipl` |
| `ex_205` | [examples/ex_205_ecs_command_deferred_spawner_window.aipl](../../examples/ex_205_ecs_command_deferred_spawner_window.aipl) | `tests/examples/ex_205_ecs_command_deferred_spawner_window_test.aipl` | `./bin/aipl test tests/examples/ex_205_ecs_command_deferred_spawner_window_test.aipl` |
| `ex_206` | [examples/ex_206_ecs_event_double_buffered_bus_window.aipl](../../examples/ex_206_ecs_event_double_buffered_bus_window.aipl) | `tests/examples/ex_206_ecs_event_double_buffered_bus_window_test.aipl` | `./bin/aipl test tests/examples/ex_206_ecs_event_double_buffered_bus_window_test.aipl` |
| `ex_207` | [examples/ex_207_ecs_world_and_system_schedule_window.aipl](../../examples/ex_207_ecs_world_and_system_schedule_window.aipl) | `tests/examples/ex_207_ecs_world_and_system_schedule_window_test.aipl` | `./bin/aipl test tests/examples/ex_207_ecs_world_and_system_schedule_window_test.aipl` |

---

### Chapter 11.2: 2D/3D Spatial Worlds (Grid2D, HexGrid, IsoGrid, VoxelChunk3D, NavMesh, PortalGraph) (std/spatial/*)

#### 1. Concept in 30 Seconds
Teach `grid2d`, `hex_tile_world2d`, `iso_world2d`, `voxel_chunk_world3d`, `octree_world3d`, `bsp_portal3d`, `navmesh`, and `spatial_interest`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn hexCubeNew(x: int, y: int, z: int): HexCubeCoord:` from `std/spatial/hex_tile_world2d.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.spatial.hex_tile_world2d_z1_test
import * from "std/spatial/hex_tile_world2d"
import { SQRT3, absInt, absFloat } from "std/math/consts"
import { round } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hex_tile_world2d_hexCubeNew_1(): int:
  let arg_x = 1
  let edge_x = 0
  let arg_y = -1
  let edge_y = 0
  let arg_z = 0
  let edge_z = 0
  let resNom = hexCubeNew(arg_x, arg_y, arg_z)
  let resEdge = hexCubeNew(edge_x, edge_y, edge_z)
  assertEqInt(resNom.x, 1, "hexCubeNew nominal resNom.x == 1")
  assertEqInt(resEdge.x, 0, "hexCubeNew boundary resEdge.x == 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_209` | [examples/ex_209_spatial_iso_tile_world2d_window.aipl](../../examples/ex_209_spatial_iso_tile_world2d_window.aipl) | `tests/examples/ex_209_spatial_iso_tile_world2d_window_test.aipl` | `./bin/aipl test tests/examples/ex_209_spatial_iso_tile_world2d_window_test.aipl` |
| `ex_210` | [examples/ex_210_spatial_hex_tile_world2d_window.aipl](../../examples/ex_210_spatial_hex_tile_world2d_window.aipl) | `tests/examples/ex_210_spatial_hex_tile_world2d_window_test.aipl` | `./bin/aipl test tests/examples/ex_210_spatial_hex_tile_world2d_window_test.aipl` |
| `ex_211` | [examples/ex_211_spatial_continuous_world2d_window.aipl](../../examples/ex_211_spatial_continuous_world2d_window.aipl) | `tests/examples/ex_211_spatial_continuous_world2d_window_test.aipl` | `./bin/aipl test tests/examples/ex_211_spatial_continuous_world2d_window_test.aipl` |
| `ex_212` | [examples/ex_212_spatial_continuous_world3d_window.aipl](../../examples/ex_212_spatial_continuous_world3d_window.aipl) | `tests/examples/ex_212_spatial_continuous_world3d_window_test.aipl` | `./bin/aipl test tests/examples/ex_212_spatial_continuous_world3d_window_test.aipl` |
| `ex_213` | [examples/ex_213_spatial_voxel_chunk_world3d_window.aipl](../../examples/ex_213_spatial_voxel_chunk_world3d_window.aipl) | `tests/examples/ex_213_spatial_voxel_chunk_world3d_window_test.aipl` | `./bin/aipl test tests/examples/ex_213_spatial_voxel_chunk_world3d_window_test.aipl` |
| `ex_214` | [examples/ex_214_spatial_bsp_sector_world3d_window.aipl](../../examples/ex_214_spatial_bsp_sector_world3d_window.aipl) | `tests/examples/ex_214_spatial_bsp_sector_world3d_window_test.aipl` | `./bin/aipl test tests/examples/ex_214_spatial_bsp_sector_world3d_window_test.aipl` |

---

### Chapter 11.3: 2D & 3D Rigid-Body Dynamics, SAT/GJK-EPA, Raycast Vehicles, Cloth & Fluids (std/phys2d/*, std/phys3d/*)

#### 1. Concept in 30 Seconds
Teach `std/phys2d/*` (including `std/phys2d/fluid2d`) and `std/phys3d/*` (`rigid_body3d`, `collider3d`, `broadphase3d`, `narrowphase3d`, `joint3d`, `character3d`, `vehicle3d`, `phys_query3d`, `phys_world3d`).

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn physWorld2dNew(gravity: Vec2): PhysicsWorld2D:` from `std/phys2d/phys_world2d.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.phys2d.phys_world2d_z1_test
import * from "std/phys2d/phys_world2d"
import { Vec2 } from "std/math/vec_math"
import { Vec2 } from "std/math/vec_math"
import { RigidBody2D, rigidBody2dIntegrateVelocity, rigidBody2dIntegratePosition } from "std/phys2d/rigid_body2d"
import { Collider2D, colliderComputeAABB } from "std/phys2d/collider2d"
import { DynamicAABBTree2D, dynamicAABBTreeNew, dynamicAABBTreeInsert } from "std/phys2d/broadphase2d"
import { Joint2D, jointSolveVelocity, jointSolvePosition } from "std/phys2d/joint2d"
import { Collider2D, colliderComputeAABB } from "std/phys2d/collider2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_phys_world2d_physWorld2dNew_1(): int:
  let arg_gravity = Vec2(x = 1.0, y = 1.0)
  let edge_gravity = Vec2(x = 0.5, y = 0.5)
  let resNom = physWorld2dNew(arg_gravity)
  let resEdge = physWorld2dNew(edge_gravity)
  assertEqInt(resNom.bodies.len(), 0, "physWorld2dNew nominal resNom.bodies.len() == 0")
  assertEqInt(resEdge.bodies.len(), 0, "physWorld2dNew boundary resEdge.bodies.len() == 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_217` | [examples/ex_217_phys2d_collider_sat_polygons_window.aipl](../../examples/ex_217_phys2d_collider_sat_polygons_window.aipl) | `tests/examples/ex_217_phys2d_collider_sat_polygons_window_test.aipl` | `./bin/aipl test tests/examples/ex_217_phys2d_collider_sat_polygons_window_test.aipl` |
| `ex_218` | [examples/ex_218_phys2d_broadphase_sap_grid_window.aipl](../../examples/ex_218_phys2d_broadphase_sap_grid_window.aipl) | `tests/examples/ex_218_phys2d_broadphase_sap_grid_window_test.aipl` | `./bin/aipl test tests/examples/ex_218_phys2d_broadphase_sap_grid_window_test.aipl` |
| `ex_219` | [examples/ex_219_phys2d_joint_pendulum_and_bridge_window.aipl](../../examples/ex_219_phys2d_joint_pendulum_and_bridge_window.aipl) | `tests/examples/ex_219_phys2d_joint_pendulum_and_bridge_window_test.aipl` | `./bin/aipl test tests/examples/ex_219_phys2d_joint_pendulum_and_bridge_window_test.aipl` |
| `ex_220` | [examples/ex_220_phys2d_query_raycast_and_laser_window.aipl](../../examples/ex_220_phys2d_query_raycast_and_laser_window.aipl) | `tests/examples/ex_220_phys2d_query_raycast_and_laser_window_test.aipl` | `./bin/aipl test tests/examples/ex_220_phys2d_query_raycast_and_laser_window_test.aipl` |
| `ex_221` | [examples/ex_221_phys2d_verlet_cloth_and_rope_window.aipl](../../examples/ex_221_phys2d_verlet_cloth_and_rope_window.aipl) | `tests/examples/ex_221_phys2d_verlet_cloth_and_rope_window_test.aipl` | `./bin/aipl test tests/examples/ex_221_phys2d_verlet_cloth_and_rope_window_test.aipl` |
| `ex_222` | [examples/ex_222_phys2d_fluid_sph_water_tank_window.aipl](../../examples/ex_222_phys2d_fluid_sph_water_tank_window.aipl) | `tests/examples/ex_222_phys2d_fluid_sph_water_tank_window_test.aipl` | `./bin/aipl test tests/examples/ex_222_phys2d_fluid_sph_water_tank_window_test.aipl` |

---

### Chapter 11.4: Procedural Generation, Autonomous Game AI & RPG/Economy Mechanics (std/procgen/*, std/ai/*, std/mechanics/*)

#### 1. Concept in 30 Seconds
Teach `std/procgen/*` (`noise_field`, `wfc`, `cellular_automata`, `dungeon_bsp`, `delaunay_voronoi`, `lsystem`, `loot_table`), `std/ai/*` (`pathfind`, `steering`, `btree_ai`, `fsm`, `utility_ai`, `goap`, `influence_map`, `hebar_referee`), and `std/mechanics/*` (`attribute_pipeline`, `inventory_container`, `economy_ledger`, `dialogue_dag`).

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn goapPlannerNew(): GoapPlanner:` from `std/ai/goap.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.ai.goap_z1_test
import * from "std/ai/goap"
import { popcnt, clampFloat } from "std/math/consts"
import { exp, sqrt, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_goap_goapPlannerNew_1(): int:
  let resNom = goapPlannerNew()
  let resEdge = goapPlannerNew()
  assertEqInt(resNom.actions.len(), 0, "goapPlannerNew nominal resNom.actions.len() == 0")
  assertEqInt(resEdge.actions.len(), 0, "goapPlannerNew boundary resEdge.actions.len() == 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_231` | [examples/ex_231_procgen_noise_perlin_simplex_worley_window.aipl](../../examples/ex_231_procgen_noise_perlin_simplex_worley_window.aipl) | `tests/examples/ex_231_procgen_noise_perlin_simplex_worley_window_test.aipl` | `./bin/aipl test tests/examples/ex_231_procgen_noise_perlin_simplex_worley_window_test.aipl` |
| `ex_232` | [examples/ex_232_procgen_dungeon_bsp_and_corridors_window.aipl](../../examples/ex_232_procgen_dungeon_bsp_and_corridors_window.aipl) | `tests/examples/ex_232_procgen_dungeon_bsp_and_corridors_window_test.aipl` | `./bin/aipl test tests/examples/ex_232_procgen_dungeon_bsp_and_corridors_window_test.aipl` |
| `ex_233` | [examples/ex_233_procgen_cellular_automata_caves_window.aipl](../../examples/ex_233_procgen_cellular_automata_caves_window.aipl) | `tests/examples/ex_233_procgen_cellular_automata_caves_window_test.aipl` | `./bin/aipl test tests/examples/ex_233_procgen_cellular_automata_caves_window_test.aipl` |
| `ex_234` | [examples/ex_234_procgen_wfc_tile_synthesizer_window.aipl](../../examples/ex_234_procgen_wfc_tile_synthesizer_window.aipl) | `tests/examples/ex_234_procgen_wfc_tile_synthesizer_window_test.aipl` | `./bin/aipl test tests/examples/ex_234_procgen_wfc_tile_synthesizer_window_test.aipl` |
| `ex_235` | [examples/ex_235_procgen_lsystem_fractal_trees_window.aipl](../../examples/ex_235_procgen_lsystem_fractal_trees_window.aipl) | `tests/examples/ex_235_procgen_lsystem_fractal_trees_window_test.aipl` | `./bin/aipl test tests/examples/ex_235_procgen_lsystem_fractal_trees_window_test.aipl` |
| `ex_236` | [examples/ex_236_procgen_marching_squares_contours_window.aipl](../../examples/ex_236_procgen_marching_squares_contours_window.aipl) | `tests/examples/ex_236_procgen_marching_squares_contours_window_test.aipl` | `./bin/aipl test tests/examples/ex_236_procgen_marching_squares_contours_window_test.aipl` |
