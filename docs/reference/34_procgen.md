[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 34: `procgen` API Reference

> Complete API reference manual for AIPL standard library domain `procgen` (36 callable functions & methods across ["std/procgen/cellular_automata.aipl", "std/procgen/dungeon_graph.aipl", "std/procgen/lsystem.aipl", "std/procgen/marching_isosurface.aipl", "std/procgen/noise_field.aipl", "std/procgen/poisson_disc.aipl", "std/procgen/procgen_mod.aipl", "std/procgen/wfc_solver.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `procgen`
- **Target Source Modules**: ["std/procgen/cellular_automata.aipl", "std/procgen/dungeon_graph.aipl", "std/procgen/lsystem.aipl", "std/procgen/marching_isosurface.aipl", "std/procgen/noise_field.aipl", "std/procgen/poisson_disc.aipl", "std/procgen/procgen_mod.aipl", "std/procgen/wfc_solver.aipl"]
- **Total Callable Functions & Methods**: 36
- **Total Data Types (`struct` & `enum`)**: 19
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(19 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `CaRuleSet` | `pub struct` | `std/procgen/cellular_automata.aipl` | `surviveMask: int`, `birthMask: int`, `numStates: int` | `CaRuleSet(surviveMask, birthMask, numStates)` |
| `GrayScottConfig` | `pub struct` | `std/procgen/cellular_automata.aipl` | `feedRate: float`, `killRate: float`, `diffusionU: float`, `diffusionV: float` | `GrayScottConfig(feedRate, killRate, diffusionU, diffusionV)` |
| `CellularGrid2D` | `pub struct` | `std/procgen/cellular_automata.aipl` | `width: int`, `height: int`, `cells: [int]` | `CellularGrid2D(width, height, cells)` |
| `ScalarField2D` | `pub struct` | `std/procgen/cellular_automata.aipl` | `width: int`, `height: int`, `values: [float]` | `ScalarField2D(width, height, values)` |
| `DungeonRoom` | `pub struct` | `std/procgen/dungeon_graph.aipl` | `id: int`, `bounds: Rect2D`, `center: Vec2`, `connectedRooms: [int]` | `DungeonRoom(id, bounds, center, connectedRooms)` |
| `DungeonCorridor` | `pub struct` | `std/procgen/dungeon_graph.aipl` | `roomA: int`, `roomB: int`, `waypoints: [Vec2]`, `width: float` | `DungeonCorridor(roomA, roomB, waypoints, width)` |
| `DungeonGraphResult` | `pub struct` | `std/procgen/dungeon_graph.aipl` | `rooms: [DungeonRoom]`, `corridors: [DungeonCorridor]`, `grid: CellularGrid2D` | `DungeonGraphResult(rooms, corridors, grid)` |
| `LSystemRule` | `pub struct` | `std/procgen/lsystem.aipl` | `predecessor: str`, `successor: str`, `weight: float` | `LSystemRule(predecessor, successor, weight)` |
| `LSystemGrammar` | `pub struct` | `std/procgen/lsystem.aipl` | `axiom: str`, `rules: [LSystemRule]`, `defaultAngleDegrees: float`, `defaultLength: float` | `LSystemGrammar(axiom, rules, defaultAngleDegrees, defaultLength)` |
| `TurtleSegment3D` | `pub struct` | `std/procgen/lsystem.aipl` | `startPoint: Vec3`, `endPoint: Vec3`, `thickness: float` | `TurtleSegment3D(startPoint, endPoint, thickness)` |
| `IsolineSegment2D` | `pub struct` | `std/procgen/marching_isosurface.aipl` | `startPoint: Vec2`, `endPoint: Vec2` | `IsolineSegment2D(startPoint, endPoint)` |
| `MeshTriangle3D` | `pub struct` | `std/procgen/marching_isosurface.aipl` | `v0: Vec3`, `v1: Vec3`, `v2: Vec3`, `normal: Vec3` | `MeshTriangle3D(v0, v1, v2, normal)` |
| `ScalarField3D` | `pub struct` | `std/procgen/marching_isosurface.aipl` | `width: int`, `height: int`, `depth: int`, `values: [float]` | `ScalarField3D(width, height, depth, values)` |
| `NoiseType` | `pub enum` | `std/procgen/noise_field.aipl` | `Perlin`, `Simplex`, `OpenSimplex2`, `Worley` | Algebraic Enum (4 variants) |
| `FbmConfig` | `pub struct` | `std/procgen/noise_field.aipl` | `octaves: int`, `lacunarity: float`, `persistence: float`, `seed: int` | `FbmConfig(octaves, lacunarity, persistence, seed)` |
| `WorleyResult` | `pub struct` | `std/procgen/noise_field.aipl` | `f1: float`, `f2: float`, `cellId: int`, `cellCenter: Vec2` | `WorleyResult(f1, f2, cellId, cellCenter)` |
| `PoissonDiscConfig2D` | `pub struct` | `std/procgen/poisson_disc.aipl` | `bounds: Rect2D`, `minDistance: float`, `maxCandidates: int`, `seed: int` | `PoissonDiscConfig2D(bounds, minDistance, maxCandidates, seed)` |
| `WfcPattern` | `pub struct` | `std/procgen/wfc_solver.aipl` | `id: int`, `weight: float`, `compatibleNeighbors: [[int]]` | `WfcPattern(id, weight, compatibleNeighbors)` |
| `WfcSolver2D` | `pub struct` | `std/procgen/wfc_solver.aipl` | `width: int`, `height: int`, `numPatterns: int`, `patterns: [WfcPattern]`, `waveMasks: [int]`, `collapsedGrid: [int]`, `isSolved: bool` | `WfcSolver2D(width, height, numPatterns, patterns, waveMasks, collapsedGrid, isSolved)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/procgen/cellular_automata.aipl` | `lcgRandFloat` | `fn lcgRandFloat(state: int): (int, float):` | `tests/functions/procgen/cellular_automata_test.aipl` |
| `2` | `std/procgen/cellular_automata.aipl` | `caveAutomataInit` | `pub fn caveAutomataInit(width: int, height: int, fillProb: float, seed: int): CellularGrid2D:` | `tests/functions/procgen/cellular_automata_test.aipl` |
| `3` | `std/procgen/cellular_automata.aipl` | `countMooreNeighbors` | `fn countMooreNeighbors(grid: CellularGrid2D, cx: int, cy: int, outOfBoundsSolid: bool): int:` | `tests/functions/procgen/cellular_automata_test.aipl` |
| `4` | `std/procgen/cellular_automata.aipl` | `caveAutomataStep` | `pub fn caveAutomataStep(grid: CellularGrid2D, birthLimit: int, deathLimit: int): CellularGrid2D:` | `tests/functions/procgen/cellular_automata_test.aipl` |
| `5` | `std/procgen/cellular_automata.aipl` | `conwayStep2D` | `pub fn conwayStep2D(grid: CellularGrid2D): CellularGrid2D:` | `tests/functions/procgen/cellular_automata_test.aipl` |
| `6` | `std/procgen/cellular_automata.aipl` | `grayScottStep2D` | `pub fn grayScottStep2D(mut gridU: ScalarField2D, mut gridV: ScalarField2D, config: GrayScottConfig, dt: float): void:` | `tests/functions/procgen/cellular_automata_test.aipl` |
| `7` | `std/procgen/dungeon_graph.aipl` | `bspPartitionRooms` | `pub fn bspPartitionRooms(area: Rect2D, minRoomSize: float, maxDepth: int, seed: int): [DungeonRoom]:` | `tests/functions/procgen/dungeon_graph_test.aipl` |
| `8` | `std/procgen/dungeon_graph.aipl` | `delaunayTriangulateRooms` | `pub fn delaunayTriangulateRooms(rooms: [DungeonRoom]): [IVec2]:` | `tests/functions/procgen/dungeon_graph_test.aipl` |
| `9` | `std/procgen/dungeon_graph.aipl` | `minimumSpanningTreeCorridors` | `pub fn minimumSpanningTreeCorridors(rooms: [DungeonRoom], edges: [IVec2], extraEdgeProbability: float, seed: int): [DungeonCorridor]:` | `tests/functions/procgen/dungeon_graph_test.aipl` |
| `10` | `std/procgen/dungeon_graph.aipl` | `carveDungeonGrid` | `pub fn carveDungeonGrid(rooms: [DungeonRoom], corridors: [DungeonCorridor], gridWidth: int, gridHeight: int): CellularGrid2D:` | `tests/functions/procgen/dungeon_graph_test.aipl` |
| `11` | `std/procgen/lsystem.aipl` | `lsystemGrammarNew` | `pub fn lsystemGrammarNew(axiom: str, angleDegrees: float, length: float): LSystemGrammar:` | `tests/functions/procgen/lsystem_test.aipl` |
| `12` | `std/procgen/lsystem.aipl` | `lsystemAddRule` | `pub fn lsystemAddRule(mut grammar: LSystemGrammar, pred: str, succ: str, weight: float): void:` | `tests/functions/procgen/lsystem_test.aipl` |
| `13` | `std/procgen/lsystem.aipl` | `lsystemEvaluate` | `pub fn lsystemEvaluate(grammar: LSystemGrammar, iterations: int, seed: int): str:` | `tests/functions/procgen/lsystem_test.aipl` |
| `14` | `std/procgen/lsystem.aipl` | `lsystemInterpretTurtle3D` | `pub fn lsystemInterpretTurtle3D(sentence: str, angleDegrees: float, length: float): [TurtleSegment3D]:` | `tests/functions/procgen/lsystem_test.aipl` |
| `15` | `std/procgen/marching_isosurface.aipl` | `interpIso` | `fn interpIso(vA: float, vB: float, iso: float): float:` | `tests/functions/procgen/marching_isosurface_test.aipl` |
| `16` | `std/procgen/marching_isosurface.aipl` | `marchingSquaresExtract` | `pub fn marchingSquaresExtract(field: ScalarField2D, isoLevel: float, cellSize: float): [IsolineSegment2D]:` | `tests/functions/procgen/marching_isosurface_test.aipl` |
| `17` | `std/procgen/marching_isosurface.aipl` | `marchingCubesExtract` | `pub fn marchingCubesExtract(densityGrid: ScalarField3D, isoLevel: float, voxelSize: float): [MeshTriangle3D]:` | `tests/functions/procgen/marching_isosurface_test.aipl` |
| `18` | `std/procgen/noise_field.aipl` | `hash2D` | `fn hash2D(ix: int, iy: int, seed: int): int:` | `tests/functions/procgen/noise_field_test.aipl` |
| `19` | `std/procgen/noise_field.aipl` | `hash3D` | `fn hash3D(ix: int, iy: int, iz: int, seed: int): int:` | `tests/functions/procgen/noise_field_test.aipl` |
| `20` | `std/procgen/noise_field.aipl` | `quinticFade` | `fn quinticFade(t: float): float:` | `tests/functions/procgen/noise_field_test.aipl` |
| `21` | `std/procgen/noise_field.aipl` | `lerpScalar` | `fn lerpScalar(a: float, b: float, t: float): float:` | `tests/functions/procgen/noise_field_test.aipl` |
| `22` | `std/procgen/noise_field.aipl` | `gradDot2D` | `fn gradDot2D(ix: int, iy: int, dx: float, dy: float, seed: int): float:` | `tests/functions/procgen/noise_field_test.aipl` |
| `23` | `std/procgen/noise_field.aipl` | `samplePerlin2D` | `pub fn samplePerlin2D(x: float, y: float, seed: int): float:` | `tests/functions/procgen/noise_field_test.aipl` |
| `24` | `std/procgen/noise_field.aipl` | `gradDot3D` | `fn gradDot3D(ix: int, iy: int, iz: int, dx: float, dy: float, dz: float, seed: int): float:` | `tests/functions/procgen/noise_field_test.aipl` |
| `25` | `std/procgen/noise_field.aipl` | `samplePerlin3D` | `pub fn samplePerlin3D(x: float, y: float, z: float, seed: int): float:` | `tests/functions/procgen/noise_field_test.aipl` |
| `26` | `std/procgen/noise_field.aipl` | `sampleSimplex2D` | `pub fn sampleSimplex2D(x: float, y: float, seed: int): float:` | `tests/functions/procgen/noise_field_test.aipl` |
| `27` | `std/procgen/noise_field.aipl` | `sampleWorley2D` | `pub fn sampleWorley2D(x: float, y: float, seed: int): WorleyResult:` | `tests/functions/procgen/noise_field_test.aipl` |
| `28` | `std/procgen/noise_field.aipl` | `sampleFbm2D` | `pub fn sampleFbm2D(x: float, y: float, config: FbmConfig): float:` | `tests/functions/procgen/noise_field_test.aipl` |
| `29` | `std/procgen/noise_field.aipl` | `sampleDomainWarpedFbm2D` | `pub fn sampleDomainWarpedFbm2D(x: float, y: float, config: FbmConfig, warpStrength: float): float:` | `tests/functions/procgen/noise_field_test.aipl` |
| `30` | `std/procgen/poisson_disc.aipl` | `poissonDiscSample2D` | `pub fn poissonDiscSample2D(config: PoissonDiscConfig2D): [Vec2]:` | `tests/functions/procgen/poisson_disc_test.aipl` |
| `31` | `std/procgen/poisson_disc.aipl` | `poissonDiscSample3D` | `pub fn poissonDiscSample3D(bounds: AABB3D, minDistance: float, k: int, seed: int): [Vec3]:` | `tests/functions/procgen/poisson_disc_test.aipl` |
| `32` | `std/procgen/wfc_solver.aipl` | `wfcSolver2dNew` | `pub fn wfcSolver2dNew(width: int, height: int, numPatterns: int): WfcSolver2D:` | `tests/functions/procgen/wfc_solver_test.aipl` |
| `33` | `std/procgen/wfc_solver.aipl` | `wfcAddPattern` | `pub fn wfcAddPattern(mut solver: WfcSolver2D, pattern: WfcPattern): void:` | `tests/functions/procgen/wfc_solver_test.aipl` |
| `34` | `std/procgen/wfc_solver.aipl` | `countSetBits` | `fn countSetBits(mask: int, maxBits: int): int:` | `tests/functions/procgen/wfc_solver_test.aipl` |
| `35` | `std/procgen/wfc_solver.aipl` | `wfcStep` | `pub fn wfcStep(mut solver: WfcSolver2D, seed: int): bool:` | `tests/functions/procgen/wfc_solver_test.aipl` |
| `36` | `std/procgen/wfc_solver.aipl` | `wfcSolve` | `pub fn wfcSolve(mut solver: WfcSolver2D, maxRestarts: int, seed: int): bool:` | `tests/functions/procgen/wfc_solver_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `lcgRandFloat` (`std/procgen/cellular_automata.aipl`)

- **Signature**: `fn lcgRandFloat(state: int): (int, float):`
- **Import**: `import * from "std/procgen/cellular_automata"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: int` | **Returns**: `(int, float)`
- **Unit Test**: `tests/functions/procgen/cellular_automata_test.aipl` | **Example**: `examples/ex_231_procgen_noise_perlin_simplex_worley_window.aipl`
- **Behavioral Summary**: Verifies Conway Game of Life oscillation, cave smoothing birth/survival thresholds, and Gray-Scott reaction-diffusion step in `lcgRandFloat`. Concrete nominal inputs: `state: int): (int = int): (int()`, `float: any = 42`; exercises core body path returning/computing `(nextS, float(nextS % 100000) / 100000.0)`.

```aipl
module tests.functions.procgen.cellular_automata_z1_test
import * from "std/procgen/cellular_automata"
import { clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cellular_automata_lcgRandFloat_1(): int:
  let arg_state = 1
  let edge_state = 0
  let resNom = lcgRandFloat(arg_state)
  let resEdge = lcgRandFloat(edge_state)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0, 1103527590, "lcgRandFloat nominal n_t0 == 1103527590")
  assertEqInt(e_t0, 12345, "lcgRandFloat boundary e_t0 == 12345")
  ret 0
```

---

### `caveAutomataInit` (`std/procgen/cellular_automata.aipl`)

- **Signature**: `pub fn caveAutomataInit(width: int, height: int, fillProb: float, seed: int): CellularGrid2D:`
- **Import**: `import * from "std/procgen/cellular_automata"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `width: int, height: int, fillProb: float, seed: int` | **Returns**: `CellularGrid2D`
- **Unit Test**: `tests/functions/procgen/cellular_automata_test.aipl` | **Example**: `examples/ex_232_procgen_dungeon_bsp_and_corridors_window.aipl`
- **Behavioral Summary**: Verifies Conway Game of Life oscillation, cave smoothing birth/survival thresholds, and Gray-Scott reaction-diffusion step in `caveAutomataInit`. Concrete nominal inputs: `width: int = 128`, `height: int = 128`, `fillProb: float = 1.0`, `seed: int = 42`; exercises core body path returning/computing `CellularGrid2D(width = width, height = height, cells = cells)`.

```aipl
module tests.functions.procgen.cellular_automata_z2_test
import * from "std/procgen/cellular_automata"
import { clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cellular_automata_caveAutomataInit_2(): int:
  let arg_width = 4
  let edge_width = 1
  let arg_height = 4
  let edge_height = 1
  let arg_fillProb = 1.0
  let edge_fillProb = 0.5
  let arg_seed = 1
  let edge_seed = 0
  let resNom = caveAutomataInit(arg_width, arg_height, arg_fillProb, arg_seed)
  let resEdge = caveAutomataInit(edge_width, edge_height, edge_fillProb, edge_seed)
  assertEqInt(resNom.width, 4, "caveAutomataInit nominal resNom.width == 4")
  assertEqInt(resEdge.width, 1, "caveAutomataInit boundary resEdge.width == 1")
  ret 0
```

---

### `countMooreNeighbors` (`std/procgen/cellular_automata.aipl`)

- **Signature**: `fn countMooreNeighbors(grid: CellularGrid2D, cx: int, cy: int, outOfBoundsSolid: bool): int:`
- **Import**: `import * from "std/procgen/cellular_automata"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `grid: CellularGrid2D, cx: int, cy: int, outOfBoundsSolid: bool` | **Returns**: `int`
- **Unit Test**: `tests/functions/procgen/cellular_automata_test.aipl` | **Example**: `examples/ex_233_procgen_cellular_automata_caves_window.aipl`
- **Behavioral Summary**: Verifies Conway Game of Life oscillation, cave smoothing birth/survival thresholds, and Gray-Scott reaction-diffusion step in `countMooreNeighbors`. Concrete nominal inputs: `grid: CellularGrid2D = CellularGrid2D(width = 128, height = 128, cells = [1])`, `cx: int = 1`, `cy: int = 1`, `outOfBoundsSolid: bool = true`; exercises core body path returning/computing `count`.

```aipl
module tests.functions.procgen.cellular_automata_z3_test
import * from "std/procgen/cellular_automata"
import { clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cellular_automata_countMooreNeighbors_3(): int:
  let arg_grid = CellularGrid2D(width = 4, height = 4, cells = [])
  let edge_grid = CellularGrid2D(width = 4, height = 4, cells = [])
  let arg_cx = 1
  let edge_cx = 0
  let arg_cy = 1
  let edge_cy = 0
  let arg_outOfBoundsSolid = true
  let edge_outOfBoundsSolid = false
  let resNom = countMooreNeighbors(arg_grid, arg_cx, arg_cy, arg_outOfBoundsSolid)
  let resEdge = countMooreNeighbors(edge_grid, edge_cx, edge_cy, edge_outOfBoundsSolid)
  assertEqInt(resNom, 8, "countMooreNeighbors nominal resNom == 8")
  assertEqInt(resEdge, 3, "countMooreNeighbors boundary resEdge == 3")
  ret 0
```

---

### `caveAutomataStep` (`std/procgen/cellular_automata.aipl`)

- **Signature**: `pub fn caveAutomataStep(grid: CellularGrid2D, birthLimit: int, deathLimit: int): CellularGrid2D:`
- **Import**: `import * from "std/procgen/cellular_automata"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `grid: CellularGrid2D, birthLimit: int, deathLimit: int` | **Returns**: `CellularGrid2D`
- **Unit Test**: `tests/functions/procgen/cellular_automata_test.aipl` | **Example**: `examples/ex_231_procgen_noise_perlin_simplex_worley_window.aipl`
- **Behavioral Summary**: Verifies Conway Game of Life oscillation, cave smoothing birth/survival thresholds, and Gray-Scott reaction-diffusion step in `caveAutomataStep`. Concrete nominal inputs: `grid: CellularGrid2D = CellularGrid2D(width = 128, height = 128, cells = [1])`, `birthLimit: int = 1`, `deathLimit: int = 1`; exercises core body path returning/computing `CellularGrid2D(width = grid.width, height = grid.height, cells = nextCells)`.

```aipl
module tests.functions.procgen.cellular_automata_z4_test
import * from "std/procgen/cellular_automata"
import { clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cellular_automata_caveAutomataStep_4(): int:
  let arg_grid = CellularGrid2D(width = 4, height = 4, cells = [])
  let edge_grid = CellularGrid2D(width = 4, height = 4, cells = [])
  let arg_birthLimit = 4
  let edge_birthLimit = 1
  let arg_deathLimit = 4
  let edge_deathLimit = 1
  let resNom = caveAutomataStep(arg_grid, arg_birthLimit, arg_deathLimit)
  let resEdge = caveAutomataStep(edge_grid, edge_birthLimit, edge_deathLimit)
  assertEqInt(resNom.width, 4, "caveAutomataStep nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "caveAutomataStep boundary resEdge.width == 4")
  ret 0
```

---

### `conwayStep2D` (`std/procgen/cellular_automata.aipl`)

- **Signature**: `pub fn conwayStep2D(grid: CellularGrid2D): CellularGrid2D:`
- **Import**: `import * from "std/procgen/cellular_automata"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `grid: CellularGrid2D` | **Returns**: `CellularGrid2D`
- **Unit Test**: `tests/functions/procgen/cellular_automata_test.aipl` | **Example**: `examples/ex_232_procgen_dungeon_bsp_and_corridors_window.aipl`
- **Behavioral Summary**: Verifies Conway Game of Life oscillation, cave smoothing birth/survival thresholds, and Gray-Scott reaction-diffusion step in `conwayStep2D`. Concrete nominal inputs: `grid: CellularGrid2D = CellularGrid2D(width = 128, height = 128, cells = [1])`; exercises core body path returning/computing `CellularGrid2D(width = grid.width, height = grid.height, cells = nextCells)`.

```aipl
module tests.functions.procgen.cellular_automata_z5_test
import * from "std/procgen/cellular_automata"
import { clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cellular_automata_conwayStep2D_5(): int:
  let arg_grid = CellularGrid2D(width = 4, height = 4, cells = [])
  let edge_grid = CellularGrid2D(width = 4, height = 4, cells = [])
  let resNom = conwayStep2D(arg_grid)
  let resEdge = conwayStep2D(edge_grid)
  assertEqInt(resNom.width, 4, "conwayStep2D nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "conwayStep2D boundary resEdge.width == 4")
  ret 0
```

---

### `grayScottStep2D` (`std/procgen/cellular_automata.aipl`)

- **Signature**: `pub fn grayScottStep2D(mut gridU: ScalarField2D, mut gridV: ScalarField2D, config: GrayScottConfig, dt: float): void:`
- **Import**: `import * from "std/procgen/cellular_automata"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut gridU: ScalarField2D, mut gridV: ScalarField2D, config: GrayScottConfig, dt: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/procgen/cellular_automata_test.aipl` | **Example**: `examples/ex_233_procgen_cellular_automata_caves_window.aipl`
- **Behavioral Summary**: Verifies Conway Game of Life oscillation, cave smoothing birth/survival thresholds, and Gray-Scott reaction-diffusion step in `grayScottStep2D`. Concrete nominal inputs: `gridU: ScalarField2D = ScalarField2D(width = 128, height = 128, values = [1.0])`, `gridV: ScalarField2D = ScalarField2D(width = 128, height = 128, values = [1.0])`, `config: GrayScottConfig = GrayScottConfig(feedRate = 1.0, killRate = 1.0, diffusionU = 1.0, diffusionV = 1.0)`, `dt: float = 0.016667`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.procgen.cellular_automata_z6_test
import * from "std/procgen/cellular_automata"
import { clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cellular_automata_grayScottStep2D_6(): int:
  let arg_gridU = ScalarField2D(width = 4, height = 4, values = [])
  let edge_gridU = ScalarField2D(width = 4, height = 4, values = [])
  let arg_gridV = ScalarField2D(width = 4, height = 4, values = [])
  let edge_gridV = ScalarField2D(width = 4, height = 4, values = [])
  let arg_config = GrayScottConfig(feedRate = 2.0, killRate = 2.0, diffusionU = 1.0, diffusionV = 1.0)
  let edge_config = GrayScottConfig(feedRate = 1.0, killRate = 1.0, diffusionU = 0.5, diffusionV = 0.5)
  let arg_dt = 2.0
  let edge_dt = 1.0
  grayScottStep2D(arg_gridU, arg_gridV, arg_config, arg_dt)
  grayScottStep2D(edge_gridU, edge_gridV, edge_config, edge_dt)
  assertEqInt(arg_gridU.values.len(), 16, "grayScottStep2D nominal arg_gridU.values.len() == 16")
  assertEqInt(edge_gridU.values.len(), 16, "grayScottStep2D boundary edge_gridU.values.len() == 16")
  ret 0
```

---

### `bspPartitionRooms` (`std/procgen/dungeon_graph.aipl`)

- **Signature**: `pub fn bspPartitionRooms(area: Rect2D, minRoomSize: float, maxDepth: int, seed: int): [DungeonRoom]:`
- **Import**: `import * from "std/procgen/dungeon_graph"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `area: Rect2D, minRoomSize: float, maxDepth: int, seed: int` | **Returns**: `[DungeonRoom]`
- **Unit Test**: `tests/functions/procgen/dungeon_graph_test.aipl` | **Example**: `examples/ex_231_procgen_noise_perlin_simplex_worley_window.aipl`
- **Behavioral Summary**: Tests BSP room splitting, Bowyer-Watson Delaunay triangulation, Kruskal MST corridor extraction, and grid carving in `bspPartitionRooms`. Concrete nominal inputs: `area: Rect2D = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0())`, `minRoomSize: float = 1.0`, `maxDepth: int = 1`, `seed: int = 42`; exercises core body path returning/computing `rooms`.

```aipl
module tests.functions.procgen.dungeon_graph_z1_test
import * from "std/procgen/dungeon_graph"
import { minInt, maxInt, clampInt } from "std/math/consts"
import { floor, sqrt } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { CellularGrid2D } from "std/procgen/cellular_automata"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dungeon_graph_bspPartitionRooms_1(): int:
  let arg_area = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0)
  let edge_area = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0)
  let arg_minRoomSize = 0.0
  let edge_minRoomSize = 0.0
  let arg_maxDepth = 4
  let edge_maxDepth = 1
  let arg_seed = 1
  let edge_seed = 0
  let resNom = bspPartitionRooms(arg_area, arg_minRoomSize, arg_maxDepth, arg_seed)
  let resEdge = bspPartitionRooms(edge_area, edge_minRoomSize, edge_maxDepth, edge_seed)
  assertEqInt(resNom.len(), 16, "bspPartitionRooms nominal resNom.len() == 16")
  assertEqInt(resEdge.len(), 2, "bspPartitionRooms boundary resEdge.len() == 2")
  ret 0
```

---

### `delaunayTriangulateRooms` (`std/procgen/dungeon_graph.aipl`)

- **Signature**: `pub fn delaunayTriangulateRooms(rooms: [DungeonRoom]): [IVec2]:`
- **Import**: `import * from "std/procgen/dungeon_graph"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rooms: [DungeonRoom]` | **Returns**: `[IVec2]`
- **Unit Test**: `tests/functions/procgen/dungeon_graph_test.aipl` | **Example**: `examples/ex_232_procgen_dungeon_bsp_and_corridors_window.aipl`
- **Behavioral Summary**: Tests BSP room splitting, Bowyer-Watson Delaunay triangulation, Kruskal MST corridor extraction, and grid carving in `delaunayTriangulateRooms`. Concrete nominal inputs: `rooms: [DungeonRoom] = [DungeonRoom(id = 1, bounds = Rect2D(x = 0, y = 0, w = 0, h = 0, width = 0, height = 0), center = Vec2(x = 0, y = 0), connectedRooms = [0])]`; exercises core body path returning/computing `edges`.

```aipl
module tests.functions.procgen.dungeon_graph_z2_test
import * from "std/procgen/dungeon_graph"
import { minInt, maxInt, clampInt } from "std/math/consts"
import { floor, sqrt } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { CellularGrid2D } from "std/procgen/cellular_automata"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dungeon_graph_delaunayTriangulateRooms_2(): int:
  let arg_rooms = [DungeonRoom(id = 1, bounds = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0), center = Vec2(x = 1.0, y = 1.0), connectedRooms = [])]
  let edge_rooms = []
  let resNom = delaunayTriangulateRooms(arg_rooms)
  let resEdge = delaunayTriangulateRooms(edge_rooms)
  assertEqInt(resNom.len(), 0, "delaunayTriangulateRooms nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "delaunayTriangulateRooms boundary resEdge.len() == 0")
  ret 0
```

---

### `minimumSpanningTreeCorridors` (`std/procgen/dungeon_graph.aipl`)

- **Signature**: `pub fn minimumSpanningTreeCorridors(rooms: [DungeonRoom], edges: [IVec2], extraEdgeProbability: float, seed: int): [DungeonCorridor]:`
- **Import**: `import * from "std/procgen/dungeon_graph"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rooms: [DungeonRoom], edges: [IVec2], extraEdgeProbability: float, seed: int` | **Returns**: `[DungeonCorridor]`
- **Unit Test**: `tests/functions/procgen/dungeon_graph_test.aipl` | **Example**: `examples/ex_233_procgen_cellular_automata_caves_window.aipl`
- **Behavioral Summary**: Tests BSP room splitting, Bowyer-Watson Delaunay triangulation, Kruskal MST corridor extraction, and grid carving in `minimumSpanningTreeCorridors`. Concrete nominal inputs: `rooms: [DungeonRoom] = [DungeonRoom(id = 1, bounds = Rect2D(x = 0, y = 0, w = 0, h = 0, width = 0, height = 0), center = Vec2(x = 0, y = 0), connectedRooms = [0])]`, `edges: [IVec2] = [IVec2(x = 1, y = 1)]`, `extraEdgeProbability: float = 1.0`, `seed: int = 42`; exercises core body path returning/computing `corridors`.

```aipl
module tests.functions.procgen.dungeon_graph_z3_test
import * from "std/procgen/dungeon_graph"
import { minInt, maxInt, clampInt } from "std/math/consts"
import { floor, sqrt } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { CellularGrid2D } from "std/procgen/cellular_automata"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dungeon_graph_minimumSpanningTreeCorridors_3(): int:
  let arg_rooms = [DungeonRoom(id = 1, bounds = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0), center = Vec2(x = 1.0, y = 1.0), connectedRooms = [])]
  let edge_rooms = []
  let arg_edges = [IVec2(x = 1, y = 1)]
  let edge_edges = []
  let arg_extraEdgeProbability = 1.0
  let edge_extraEdgeProbability = 0.5
  let arg_seed = 1
  let edge_seed = 0
  let resNom = minimumSpanningTreeCorridors(arg_rooms, arg_edges, arg_extraEdgeProbability, arg_seed)
  let resEdge = minimumSpanningTreeCorridors(edge_rooms, edge_edges, edge_extraEdgeProbability, edge_seed)
  assertEqInt(resNom.len(), 1, "minimumSpanningTreeCorridors nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "minimumSpanningTreeCorridors boundary resEdge.len() == 0")
  ret 0
```

---

### `carveDungeonGrid` (`std/procgen/dungeon_graph.aipl`)

- **Signature**: `pub fn carveDungeonGrid(rooms: [DungeonRoom], corridors: [DungeonCorridor], gridWidth: int, gridHeight: int): CellularGrid2D:`
- **Import**: `import * from "std/procgen/dungeon_graph"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rooms: [DungeonRoom], corridors: [DungeonCorridor], gridWidth: int, gridHeight: int` | **Returns**: `CellularGrid2D`
- **Unit Test**: `tests/functions/procgen/dungeon_graph_test.aipl` | **Example**: `examples/ex_231_procgen_noise_perlin_simplex_worley_window.aipl`
- **Behavioral Summary**: Tests BSP room splitting, Bowyer-Watson Delaunay triangulation, Kruskal MST corridor extraction, and grid carving in `carveDungeonGrid`. Concrete nominal inputs: `rooms: [DungeonRoom] = [DungeonRoom(id = 1, bounds = Rect2D(x = 0, y = 0, w = 0, h = 0, width = 0, height = 0), center = Vec2(x = 0, y = 0), connectedRooms = [0])]`, `corridors: [DungeonCorridor] = [DungeonCorridor(roomA = 1, roomB = 1, waypoints = [0], width = 0.016667)]`, `gridWidth: int = 1`, `gridHeight: int = 1`; exercises core body path returning/computing `CellularGrid2D(width = gridWidth, height = gridHeight, cells = cells)`.

```aipl
module tests.functions.procgen.dungeon_graph_z4_test
import * from "std/procgen/dungeon_graph"
import { minInt, maxInt, clampInt } from "std/math/consts"
import { floor, sqrt } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { CellularGrid2D } from "std/procgen/cellular_automata"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dungeon_graph_carveDungeonGrid_4(): int:
  let arg_rooms = [DungeonRoom(id = 1, bounds = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0), center = Vec2(x = 1.0, y = 1.0), connectedRooms = [])]
  let edge_rooms = []
  let arg_corridors = [DungeonCorridor(roomA = 4, roomB = 4, waypoints = [], width = 2.0)]
  let edge_corridors = []
  let arg_gridWidth = 4
  let edge_gridWidth = 1
  let arg_gridHeight = 4
  let edge_gridHeight = 1
  let resNom = carveDungeonGrid(arg_rooms, arg_corridors, arg_gridWidth, arg_gridHeight)
  let resEdge = carveDungeonGrid(edge_rooms, edge_corridors, edge_gridWidth, edge_gridHeight)
  assertEqInt(resNom.width, 4, "carveDungeonGrid nominal resNom.width == 4")
  assertEqInt(resEdge.width, 1, "carveDungeonGrid boundary resEdge.width == 1")
  ret 0
```

---

### `lsystemGrammarNew` (`std/procgen/lsystem.aipl`)

- **Signature**: `pub fn lsystemGrammarNew(axiom: str, angleDegrees: float, length: float): LSystemGrammar:`
- **Import**: `import * from "std/procgen/lsystem"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `axiom: str, angleDegrees: float, length: float` | **Returns**: `LSystemGrammar`
- **Unit Test**: `tests/functions/procgen/lsystem_test.aipl` | **Example**: `examples/ex_232_procgen_dungeon_bsp_and_corridors_window.aipl`
- **Behavioral Summary**: Verifies L-System parallel grammar rewriting and 2D/3D push/pop `[`/`]` turtle geometry interpretation in `lsystemGrammarNew`. Concrete nominal inputs: `axiom: str = "aipl_test"`, `angleDegrees: float = 1.0`, `length: float = 1.0`; exercises core body path returning/computing `LSystemGrammar(`.

```aipl
module tests.functions.procgen.lsystem_z1_test
import * from "std/procgen/lsystem"
import { DEG2RAD } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_lsystem_lsystemGrammarNew_1(): int:
  let arg_axiom = "test"
  let edge_axiom = "a"
  let arg_angleDegrees = 1.0
  let edge_angleDegrees = 0.5
  let arg_length = 2.0
  let edge_length = 1.0
  let resNom = lsystemGrammarNew(arg_axiom, arg_angleDegrees, arg_length)
  let resEdge = lsystemGrammarNew(edge_axiom, edge_angleDegrees, edge_length)
  assertEqStr(resNom.axiom, "test", "lsystemGrammarNew nominal string matches")
  assertEqStr(resEdge.axiom, "a", "lsystemGrammarNew boundary string matches")
  ret 0
```

---

### `lsystemAddRule` (`std/procgen/lsystem.aipl`)

- **Signature**: `pub fn lsystemAddRule(mut grammar: LSystemGrammar, pred: str, succ: str, weight: float): void:`
- **Import**: `import * from "std/procgen/lsystem"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut grammar: LSystemGrammar, pred: str, succ: str, weight: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/procgen/lsystem_test.aipl` | **Example**: `examples/ex_233_procgen_cellular_automata_caves_window.aipl`
- **Behavioral Summary**: Verifies L-System parallel grammar rewriting and 2D/3D push/pop `[`/`]` turtle geometry interpretation in `lsystemAddRule`. Concrete nominal inputs: `grammar: LSystemGrammar = LSystemGrammar(axiom = "aipl_test", rules = [LSystemRule(predecessor = 0, successor = 0, weight = 0)], defaultAngleDegrees = 1.0, defaultLength = 1.0)`, `pred: str = "aipl_test"`, `succ: str = "aipl_test"`, `weight: float = 0.5`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.procgen.lsystem_z2_test
import * from "std/procgen/lsystem"
import { DEG2RAD } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_lsystem_lsystemAddRule_2(): int:
  let arg_grammar = LSystemGrammar(axiom = "test", rules = [], defaultAngleDegrees = 1.0, defaultLength = 2.0)
  let edge_grammar = LSystemGrammar(axiom = "a", rules = [], defaultAngleDegrees = 0.5, defaultLength = 1.0)
  let arg_pred = "test"
  let edge_pred = "a"
  let arg_succ = "test"
  let edge_succ = "a"
  let arg_weight = 2.0
  let edge_weight = 1.0
  lsystemAddRule(arg_grammar, arg_pred, arg_succ, arg_weight)
  lsystemAddRule(edge_grammar, edge_pred, edge_succ, edge_weight)
  assertEqInt(arg_grammar.rules.len(), 1, "lsystemAddRule nominal arg_grammar.rules.len() == 1")
  assertEqInt(edge_grammar.rules.len(), 1, "lsystemAddRule boundary edge_grammar.rules.len() == 1")
  ret 0
```

---

### `lsystemEvaluate` (`std/procgen/lsystem.aipl`)

- **Signature**: `pub fn lsystemEvaluate(grammar: LSystemGrammar, iterations: int, seed: int): str:`
- **Import**: `import * from "std/procgen/lsystem"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `grammar: LSystemGrammar, iterations: int, seed: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/procgen/lsystem_test.aipl` | **Example**: `examples/ex_231_procgen_noise_perlin_simplex_worley_window.aipl`
- **Behavioral Summary**: Verifies L-System parallel grammar rewriting and 2D/3D push/pop `[`/`]` turtle geometry interpretation in `lsystemEvaluate`. Concrete nominal inputs: `grammar: LSystemGrammar = LSystemGrammar(axiom = "aipl_test", rules = [LSystemRule(predecessor = 0, successor = 0, weight = 0)], defaultAngleDegrees = 1.0, defaultLength = 1.0)`, `iterations: int = 1`, `seed: int = 42`; exercises core body path returning/computing `current`.

```aipl
module tests.functions.procgen.lsystem_z3_test
import * from "std/procgen/lsystem"
import { DEG2RAD } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_lsystem_lsystemEvaluate_3(): int:
  let arg_grammar = LSystemGrammar(axiom = "test", rules = [], defaultAngleDegrees = 1.0, defaultLength = 2.0)
  let edge_grammar = LSystemGrammar(axiom = "a", rules = [], defaultAngleDegrees = 0.5, defaultLength = 1.0)
  let arg_iterations = 4
  let edge_iterations = 1
  let arg_seed = 1
  let edge_seed = 0
  let resNom = lsystemEvaluate(arg_grammar, arg_iterations, arg_seed)
  let resEdge = lsystemEvaluate(edge_grammar, edge_iterations, edge_seed)
  assertEqStr(resNom, "test", "lsystemEvaluate nominal string matches")
  assertEqStr(resEdge, "a", "lsystemEvaluate boundary string matches")
  ret 0
```

---

### `lsystemInterpretTurtle3D` (`std/procgen/lsystem.aipl`)

- **Signature**: `pub fn lsystemInterpretTurtle3D(sentence: str, angleDegrees: float, length: float): [TurtleSegment3D]:`
- **Import**: `import * from "std/procgen/lsystem"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sentence: str, angleDegrees: float, length: float` | **Returns**: `[TurtleSegment3D]`
- **Unit Test**: `tests/functions/procgen/lsystem_test.aipl` | **Example**: `examples/ex_232_procgen_dungeon_bsp_and_corridors_window.aipl`
- **Behavioral Summary**: Verifies L-System parallel grammar rewriting and 2D/3D push/pop `[`/`]` turtle geometry interpretation in `lsystemInterpretTurtle3D`. Concrete nominal inputs: `sentence: str = "aipl_test"`, `angleDegrees: float = 1.0`, `length: float = 1.0`; exercises core body path returning/computing `segs`.

```aipl
module tests.functions.procgen.lsystem_z4_test
import * from "std/procgen/lsystem"
import { DEG2RAD } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_lsystem_lsystemInterpretTurtle3D_4(): int:
  let arg_sentence = "42"
  let edge_sentence = "0"
  let arg_angleDegrees = 1.0
  let edge_angleDegrees = 0.5
  let arg_length = 2.0
  let edge_length = 1.0
  let resNom = lsystemInterpretTurtle3D(arg_sentence, arg_angleDegrees, arg_length)
  let resEdge = lsystemInterpretTurtle3D(edge_sentence, edge_angleDegrees, edge_length)
  assertEqInt(resNom.len(), 0, "lsystemInterpretTurtle3D nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "lsystemInterpretTurtle3D boundary resEdge.len() == 0")
  ret 0
```

---

### `interpIso` (`std/procgen/marching_isosurface.aipl`)

- **Signature**: `fn interpIso(vA: float, vB: float, iso: float): float:`
- **Import**: `import * from "std/procgen/marching_isosurface"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `vA: float, vB: float, iso: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/procgen/marching_isosurface_test.aipl` | **Example**: `examples/ex_233_procgen_cellular_automata_caves_window.aipl`
- **Behavioral Summary**: Tests 2D Marching Squares contour segments and 3D Marching Cubes / Surface Nets isosurface mesh extraction in `interpIso`. Concrete nominal inputs: `vA: float = 1.0`, `vB: float = 1.0`, `iso: float = 1.0`; exercises core body path returning/computing `clampFloat((iso - vA) / diff, 0.0, 1.0)`.

```aipl
module tests.functions.procgen.marching_isosurface_z1_test
import * from "std/procgen/marching_isosurface"
import { absFloat, clampFloat } from "std/math/consts"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ScalarField2D } from "std/procgen/cellular_automata"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_marching_isosurface_interpIso_1(): int:
  let arg_vA = 1.0
  let edge_vA = 0.5
  let arg_vB = 1.0
  let edge_vB = 0.5
  let arg_iso = 1.0
  let edge_iso = 0.5
  let resNom = interpIso(arg_vA, arg_vB, arg_iso)
  let resEdge = interpIso(edge_vA, edge_vB, edge_iso)
  assertApproxEq(resNom, 0.5, 0.001, "interpIso nominal resNom ~= 0.5")
  assertApproxEq(resEdge, 0.5, 0.001, "interpIso boundary resEdge ~= 0.5")
  ret 0
```

---

### `marchingSquaresExtract` (`std/procgen/marching_isosurface.aipl`)

- **Signature**: `pub fn marchingSquaresExtract(field: ScalarField2D, isoLevel: float, cellSize: float): [IsolineSegment2D]:`
- **Import**: `import * from "std/procgen/marching_isosurface"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `field: ScalarField2D, isoLevel: float, cellSize: float` | **Returns**: `[IsolineSegment2D]`
- **Unit Test**: `tests/functions/procgen/marching_isosurface_test.aipl` | **Example**: `examples/ex_231_procgen_noise_perlin_simplex_worley_window.aipl`
- **Behavioral Summary**: Tests 2D Marching Squares contour segments and 3D Marching Cubes / Surface Nets isosurface mesh extraction in `marchingSquaresExtract`. Concrete nominal inputs: `field: ScalarField2D = ScalarField2D(width = 128, height = 128, values = [1.0])`, `isoLevel: float = 1.0`, `cellSize: float = 1.0`; exercises core body path returning/computing `segs`.

```aipl
module tests.functions.procgen.marching_isosurface_z2_test
import * from "std/procgen/marching_isosurface"
import { absFloat, clampFloat } from "std/math/consts"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ScalarField2D } from "std/procgen/cellular_automata"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_marching_isosurface_marchingSquaresExtract_2(): int:
  let arg_field = ScalarField2D(width = 4, height = 4, values = [])
  let edge_field = ScalarField2D(width = 4, height = 4, values = [])
  let arg_isoLevel = 1.0
  let edge_isoLevel = 0.5
  let arg_cellSize = 1.0
  let edge_cellSize = 0.5
  let resNom = marchingSquaresExtract(arg_field, arg_isoLevel, arg_cellSize)
  let resEdge = marchingSquaresExtract(edge_field, edge_isoLevel, edge_cellSize)
  assertEqInt(resNom.len(), 0, "marchingSquaresExtract nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "marchingSquaresExtract boundary resEdge.len() == 0")
  ret 0
```

---

### `marchingCubesExtract` (`std/procgen/marching_isosurface.aipl`)

- **Signature**: `pub fn marchingCubesExtract(densityGrid: ScalarField3D, isoLevel: float, voxelSize: float): [MeshTriangle3D]:`
- **Import**: `import * from "std/procgen/marching_isosurface"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `densityGrid: ScalarField3D, isoLevel: float, voxelSize: float` | **Returns**: `[MeshTriangle3D]`
- **Unit Test**: `tests/functions/procgen/marching_isosurface_test.aipl` | **Example**: `examples/ex_232_procgen_dungeon_bsp_and_corridors_window.aipl`
- **Behavioral Summary**: Tests 2D Marching Squares contour segments and 3D Marching Cubes / Surface Nets isosurface mesh extraction in `marchingCubesExtract`. Concrete nominal inputs: `densityGrid: ScalarField3D = ScalarField3D(width = 128, height = 128, depth = 1, values = [1.0])`, `isoLevel: float = 1.0`, `voxelSize: float = 1.0`; exercises core body path returning/computing `tris`.

```aipl
module tests.functions.procgen.marching_isosurface_z3_test
import * from "std/procgen/marching_isosurface"
import { absFloat, clampFloat } from "std/math/consts"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ScalarField2D } from "std/procgen/cellular_automata"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_marching_isosurface_marchingCubesExtract_3(): int:
  let arg_densityGrid = ScalarField3D(width = 4, height = 4, depth = 0, values = [])
  let edge_densityGrid = ScalarField3D(width = 4, height = 4, depth = 0, values = [])
  let arg_isoLevel = 1.0
  let edge_isoLevel = 0.5
  let arg_voxelSize = 1.0
  let edge_voxelSize = 0.5
  let resNom = marchingCubesExtract(arg_densityGrid, arg_isoLevel, arg_voxelSize)
  let resEdge = marchingCubesExtract(edge_densityGrid, edge_isoLevel, edge_voxelSize)
  assertEqInt(resNom.len(), 0, "marchingCubesExtract nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "marchingCubesExtract boundary resEdge.len() == 0")
  ret 0
```

---

### `hash2D` (`std/procgen/noise_field.aipl`)

- **Signature**: `fn hash2D(ix: int, iy: int, seed: int): int:`
- **Import**: `import * from "std/procgen/noise_field"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ix: int, iy: int, seed: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/procgen/noise_field_test.aipl` | **Example**: `examples/ex_233_procgen_cellular_automata_caves_window.aipl`
- **Behavioral Summary**: Tests deterministic spatial hash, quintic fade curve, and Perlin/Simplex/Worley/fBm/domain-warped noise bounds in `hash2D`. Concrete nominal inputs: `ix: int = 1`, `iy: int = 1`, `seed: int = 42`; exercises core body path returning/computing `(h ^ (h >> 16)) & 2147483647`.

```aipl
module tests.functions.procgen.noise_field_z1_test
import * from "std/procgen/noise_field"
import { SQRT3, clampFloat } from "std/math/consts"
import { floor, sqrt, sin, cos } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_noise_field_hash2D_1(): int:
  let arg_ix = 1
  let edge_ix = 0
  let arg_iy = 1
  let edge_iy = 0
  let arg_seed = 1
  let edge_seed = 0
  let resNom = hash2D(arg_ix, arg_iy, arg_seed)
  let resEdge = hash2D(edge_ix, edge_iy, edge_seed)
  assertEqInt(resNom, 630946, "hash2D nominal resNom == 630946")
  assertEqInt(resEdge, 0, "hash2D boundary resEdge == 0")
  ret 0
```

---

### `hash3D` (`std/procgen/noise_field.aipl`)

- **Signature**: `fn hash3D(ix: int, iy: int, iz: int, seed: int): int:`
- **Import**: `import * from "std/procgen/noise_field"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ix: int, iy: int, iz: int, seed: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/procgen/noise_field_test.aipl` | **Example**: `examples/ex_231_procgen_noise_perlin_simplex_worley_window.aipl`
- **Behavioral Summary**: Tests deterministic spatial hash, quintic fade curve, and Perlin/Simplex/Worley/fBm/domain-warped noise bounds in `hash3D`. Concrete nominal inputs: `ix: int = 1`, `iy: int = 1`, `iz: int = 1`, `seed: int = 42`; exercises core body path returning/computing `(h ^ (h >> 16)) & 2147483647`.

```aipl
module tests.functions.procgen.noise_field_z2_test
import * from "std/procgen/noise_field"
import { SQRT3, clampFloat } from "std/math/consts"
import { floor, sqrt, sin, cos } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_noise_field_hash3D_2(): int:
  let arg_ix = 1
  let edge_ix = 0
  let arg_iy = 1
  let edge_iy = 0
  let arg_iz = 1
  let edge_iz = 0
  let arg_seed = 1
  let edge_seed = 0
  let resNom = hash3D(arg_ix, arg_iy, arg_iz, arg_seed)
  let resEdge = hash3D(edge_ix, edge_iy, edge_iz, edge_seed)
  assertEqInt(resNom, 2110963333, "hash3D nominal resNom == 2110963333")
  assertEqInt(resEdge, 0, "hash3D boundary resEdge == 0")
  ret 0
```

---

### `quinticFade` (`std/procgen/noise_field.aipl`)

- **Signature**: `fn quinticFade(t: float): float:`
- **Import**: `import * from "std/procgen/noise_field"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/procgen/noise_field_test.aipl` | **Example**: `examples/ex_232_procgen_dungeon_bsp_and_corridors_window.aipl`
- **Behavioral Summary**: Tests deterministic spatial hash, quintic fade curve, and Perlin/Simplex/Worley/fBm/domain-warped noise bounds in `quinticFade`. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `t * t * t * (t * (t * 6.0 - 15.0) + 10.0)`.

```aipl
module tests.functions.procgen.noise_field_z3_test
import * from "std/procgen/noise_field"
import { SQRT3, clampFloat } from "std/math/consts"
import { floor, sqrt, sin, cos } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_noise_field_quinticFade_3(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = quinticFade(arg_t)
  let resEdge = quinticFade(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "quinticFade nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "quinticFade boundary resEdge ~= 0.5")
  ret 0
```

---

### `lerpScalar` (`std/procgen/noise_field.aipl`)

- **Signature**: `fn lerpScalar(a: float, b: float, t: float): float:`
- **Import**: `import * from "std/procgen/noise_field"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: float, b: float, t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/procgen/noise_field_test.aipl` | **Example**: `examples/ex_233_procgen_cellular_automata_caves_window.aipl`
- **Behavioral Summary**: Tests deterministic spatial hash, quintic fade curve, and Perlin/Simplex/Worley/fBm/domain-warped noise bounds in `lerpScalar`. Concrete nominal inputs: `a: float = 1.0`, `b: float = 1.0`, `t: float = 0.5`; exercises core body path returning/computing `a + (b - a) * t`.

```aipl
module tests.functions.procgen.noise_field_z4_test
import * from "std/procgen/noise_field"
import { SQRT3, clampFloat } from "std/math/consts"
import { floor, sqrt, sin, cos } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_noise_field_lerpScalar_4(): int:
  let arg_a = 1.0
  let edge_a = 0.5
  let arg_b = 1.0
  let edge_b = 0.5
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = lerpScalar(arg_a, arg_b, arg_t)
  let resEdge = lerpScalar(edge_a, edge_b, edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "lerpScalar nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "lerpScalar boundary resEdge ~= 0.5")
  ret 0
```

---

### `gradDot2D` (`std/procgen/noise_field.aipl`)

- **Signature**: `fn gradDot2D(ix: int, iy: int, dx: float, dy: float, seed: int): float:`
- **Import**: `import * from "std/procgen/noise_field"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ix: int, iy: int, dx: float, dy: float, seed: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/procgen/noise_field_test.aipl` | **Example**: `examples/ex_231_procgen_noise_perlin_simplex_worley_window.aipl`
- **Behavioral Summary**: Tests deterministic spatial hash, quintic fade curve, and Perlin/Simplex/Worley/fBm/domain-warped noise bounds in `gradDot2D`. Concrete nominal inputs: `ix: int = 1`, `iy: int = 1`, `dx: float = 1.0`, `dy: float = 1.0`, `seed: int = 42`; exercises core body path returning/computing `-dy`.

```aipl
module tests.functions.procgen.noise_field_z5_test
import * from "std/procgen/noise_field"
import { SQRT3, clampFloat } from "std/math/consts"
import { floor, sqrt, sin, cos } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_noise_field_gradDot2D_5(): int:
  let arg_ix = 1
  let edge_ix = 0
  let arg_iy = 1
  let edge_iy = 0
  let arg_dx = 1.0
  let edge_dx = 0.5
  let arg_dy = 1.0
  let edge_dy = 0.5
  let arg_seed = 1
  let edge_seed = 0
  let resNom = gradDot2D(arg_ix, arg_iy, arg_dx, arg_dy, arg_seed)
  let resEdge = gradDot2D(edge_ix, edge_iy, edge_dx, edge_dy, edge_seed)
  assertApproxEq(resNom, 0.0, 0.001, "gradDot2D nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 1.0, 0.001, "gradDot2D boundary resEdge ~= 1.0")
  ret 0
```

---

### `samplePerlin2D` (`std/procgen/noise_field.aipl`)

- **Signature**: `pub fn samplePerlin2D(x: float, y: float, seed: int): float:`
- **Import**: `import * from "std/procgen/noise_field"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float, seed: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/procgen/noise_field_test.aipl` | **Example**: `examples/ex_232_procgen_dungeon_bsp_and_corridors_window.aipl`
- **Behavioral Summary**: Tests deterministic spatial hash, quintic fade curve, and Perlin/Simplex/Worley/fBm/domain-warped noise bounds in `samplePerlin2D`. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `seed: int = 42`; exercises core body path returning/computing `clampFloat(lerpScalar(nx0, nx1, v) * 0.70710678, -1.0, 1.0)`.

```aipl
module tests.functions.procgen.noise_field_z6_test
import * from "std/procgen/noise_field"
import { SQRT3, clampFloat } from "std/math/consts"
import { floor, sqrt, sin, cos } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_noise_field_samplePerlin2D_6(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_seed = 1
  let edge_seed = 0
  let resNom = samplePerlin2D(arg_x, arg_y, arg_seed)
  let resEdge = samplePerlin2D(edge_x, edge_y, edge_seed)
  assertApproxEq(resNom, 0.0, 0.001, "samplePerlin2D nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "samplePerlin2D boundary resEdge ~= 0.0")
  ret 0
```

---

### `gradDot3D` (`std/procgen/noise_field.aipl`)

- **Signature**: `fn gradDot3D(ix: int, iy: int, iz: int, dx: float, dy: float, dz: float, seed: int): float:`
- **Import**: `import * from "std/procgen/noise_field"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ix: int, iy: int, iz: int, dx: float, dy: float, dz: float, seed: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/procgen/noise_field_test.aipl` | **Example**: `examples/ex_233_procgen_cellular_automata_caves_window.aipl`
- **Behavioral Summary**: Tests deterministic spatial hash, quintic fade curve, and Perlin/Simplex/Worley/fBm/domain-warped noise bounds in `gradDot3D`. Concrete nominal inputs: `ix: int = 1`, `iy: int = 1`, `iz: int = 1`, `dx: float = 1.0`, `dy: float = 1.0`, `dz: float = 1.0`, `seed: int = 42`; exercises core body path returning/computing `su + sv`.

```aipl
module tests.functions.procgen.noise_field_z7_test
import * from "std/procgen/noise_field"
import { SQRT3, clampFloat } from "std/math/consts"
import { floor, sqrt, sin, cos } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_noise_field_gradDot3D_7(): int:
  let arg_ix = 1
  let edge_ix = 0
  let arg_iy = 1
  let edge_iy = 0
  let arg_iz = 1
  let edge_iz = 0
  let arg_dx = 1.0
  let edge_dx = 0.5
  let arg_dy = 1.0
  let edge_dy = 0.5
  let arg_dz = 1.0
  let edge_dz = 0.5
  let arg_seed = 1
  let edge_seed = 0
  let resNom = gradDot3D(arg_ix, arg_iy, arg_iz, arg_dx, arg_dy, arg_dz, arg_seed)
  let resEdge = gradDot3D(edge_ix, edge_iy, edge_iz, edge_dx, edge_dy, edge_dz, edge_seed)
  assertApproxEq(resNom, 0.0, 0.001, "gradDot3D nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 1.0, 0.001, "gradDot3D boundary resEdge ~= 1.0")
  ret 0
```

---

### `samplePerlin3D` (`std/procgen/noise_field.aipl`)

- **Signature**: `pub fn samplePerlin3D(x: float, y: float, z: float, seed: int): float:`
- **Import**: `import * from "std/procgen/noise_field"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float, z: float, seed: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/procgen/noise_field_test.aipl` | **Example**: `examples/ex_231_procgen_noise_perlin_simplex_worley_window.aipl`
- **Behavioral Summary**: Tests deterministic spatial hash, quintic fade curve, and Perlin/Simplex/Worley/fBm/domain-warped noise bounds in `samplePerlin3D`. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `z: float = 1.0`, `seed: int = 42`; exercises core body path returning/computing `clampFloat(lerpScalar(y0v, y1v, w) * 0.57735027, -1.0, 1.0)`.

```aipl
module tests.functions.procgen.noise_field_z8_test
import * from "std/procgen/noise_field"
import { SQRT3, clampFloat } from "std/math/consts"
import { floor, sqrt, sin, cos } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_noise_field_samplePerlin3D_8(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_z = 1.0
  let edge_z = 0.5
  let arg_seed = 1
  let edge_seed = 0
  let resNom = samplePerlin3D(arg_x, arg_y, arg_z, arg_seed)
  let resEdge = samplePerlin3D(edge_x, edge_y, edge_z, edge_seed)
  assertApproxEq(resNom, 0.0, 0.001, "samplePerlin3D nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.144338, 0.001, "samplePerlin3D boundary resEdge ~= 0.144338")
  ret 0
```

---

### `sampleSimplex2D` (`std/procgen/noise_field.aipl`)

- **Signature**: `pub fn sampleSimplex2D(x: float, y: float, seed: int): float:`
- **Import**: `import * from "std/procgen/noise_field"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float, seed: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/procgen/noise_field_test.aipl` | **Example**: `examples/ex_232_procgen_dungeon_bsp_and_corridors_window.aipl`
- **Behavioral Summary**: Tests deterministic spatial hash, quintic fade curve, and Perlin/Simplex/Worley/fBm/domain-warped noise bounds in `sampleSimplex2D`. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `seed: int = 42`; exercises core body path returning/computing `clampFloat(45.0 * (n0 + n1 + n2), -1.0, 1.0)`.

```aipl
module tests.functions.procgen.noise_field_z9_test
import * from "std/procgen/noise_field"
import { SQRT3, clampFloat } from "std/math/consts"
import { floor, sqrt, sin, cos } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_noise_field_sampleSimplex2D_9(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_seed = 1
  let edge_seed = 0
  let resNom = sampleSimplex2D(arg_x, arg_y, arg_seed)
  let resEdge = sampleSimplex2D(edge_x, edge_y, edge_seed)
  assertApproxEq(resNom, -0.581847, 0.001, "sampleSimplex2D nominal resNom ~= -0.581847")
  assertApproxEq(resEdge, -0.394916, 0.001, "sampleSimplex2D boundary resEdge ~= -0.394916")
  ret 0
```

---

### `sampleWorley2D` (`std/procgen/noise_field.aipl`)

- **Signature**: `pub fn sampleWorley2D(x: float, y: float, seed: int): WorleyResult:`
- **Import**: `import * from "std/procgen/noise_field"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float, seed: int` | **Returns**: `WorleyResult`
- **Unit Test**: `tests/functions/procgen/noise_field_test.aipl` | **Example**: `examples/ex_233_procgen_cellular_automata_caves_window.aipl`
- **Behavioral Summary**: Tests deterministic spatial hash, quintic fade curve, and Perlin/Simplex/Worley/fBm/domain-warped noise bounds in `sampleWorley2D`. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `seed: int = 42`; exercises core body path returning/computing `WorleyResult(f1 = f1, f2 = f2, cellId = bestId, cellCenter = bestCenter)`.

```aipl
module tests.functions.procgen.noise_field_z10_test
import * from "std/procgen/noise_field"
import { SQRT3, clampFloat } from "std/math/consts"
import { floor, sqrt, sin, cos } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_noise_field_sampleWorley2D_10(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_seed = 1
  let edge_seed = 0
  let resNom = sampleWorley2D(arg_x, arg_y, arg_seed)
  let resEdge = sampleWorley2D(edge_x, edge_y, edge_seed)
  assertApproxEq(resNom.f1, 0.501577, 0.001, "sampleWorley2D nominal resNom.f1 ~= 0.501577")
  assertApproxEq(resEdge.f1, 0.591113, 0.001, "sampleWorley2D boundary resEdge.f1 ~= 0.591113")
  ret 0
```

---

### `sampleFbm2D` (`std/procgen/noise_field.aipl`)

- **Signature**: `pub fn sampleFbm2D(x: float, y: float, config: FbmConfig): float:`
- **Import**: `import * from "std/procgen/noise_field"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float, config: FbmConfig` | **Returns**: `float`
- **Unit Test**: `tests/functions/procgen/noise_field_test.aipl` | **Example**: `examples/ex_231_procgen_noise_perlin_simplex_worley_window.aipl`
- **Behavioral Summary**: Tests deterministic spatial hash, quintic fade curve, and Perlin/Simplex/Worley/fBm/domain-warped noise bounds in `sampleFbm2D`. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `config: FbmConfig = FbmConfig(octaves = 1, lacunarity = 1.0, persistence = 1.0, seed = 42)`; exercises core body path returning/computing `total`.

```aipl
module tests.functions.procgen.noise_field_z11_test
import * from "std/procgen/noise_field"
import { SQRT3, clampFloat } from "std/math/consts"
import { floor, sqrt, sin, cos } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_noise_field_sampleFbm2D_11(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_config = FbmConfig(octaves = 2, lacunarity = 1.0, persistence = 1.0, seed = 0)
  let edge_config = FbmConfig(octaves = 0, lacunarity = 0.5, persistence = 0.5, seed = 0)
  let resNom = sampleFbm2D(arg_x, arg_y, arg_config)
  let resEdge = sampleFbm2D(edge_x, edge_y, edge_config)
  assertApproxEq(resNom, 0.0, 0.001, "sampleFbm2D nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "sampleFbm2D boundary resEdge ~= 0.0")
  ret 0
```

---

### `sampleDomainWarpedFbm2D` (`std/procgen/noise_field.aipl`)

- **Signature**: `pub fn sampleDomainWarpedFbm2D(x: float, y: float, config: FbmConfig, warpStrength: float): float:`
- **Import**: `import * from "std/procgen/noise_field"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float, config: FbmConfig, warpStrength: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/procgen/noise_field_test.aipl` | **Example**: `examples/ex_232_procgen_dungeon_bsp_and_corridors_window.aipl`
- **Behavioral Summary**: Tests deterministic spatial hash, quintic fade curve, and Perlin/Simplex/Worley/fBm/domain-warped noise bounds in `sampleDomainWarpedFbm2D`. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `config: FbmConfig = FbmConfig(octaves = 1, lacunarity = 1.0, persistence = 1.0, seed = 42)`, `warpStrength: float = 1.0`; exercises core body path returning/computing `sampleFbm2D(x + warpStrength * qx, y + warpStrength * qy, config)`.

```aipl
module tests.functions.procgen.noise_field_z12_test
import * from "std/procgen/noise_field"
import { SQRT3, clampFloat } from "std/math/consts"
import { floor, sqrt, sin, cos } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_noise_field_sampleDomainWarpedFbm2D_12(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_config = FbmConfig(octaves = 2, lacunarity = 1.0, persistence = 1.0, seed = 0)
  let edge_config = FbmConfig(octaves = 0, lacunarity = 0.5, persistence = 0.5, seed = 0)
  let arg_warpStrength = 2.0
  let edge_warpStrength = 1.0
  let resNom = sampleDomainWarpedFbm2D(arg_x, arg_y, arg_config, arg_warpStrength)
  let resEdge = sampleDomainWarpedFbm2D(edge_x, edge_y, edge_config, edge_warpStrength)
  assertApproxEq(resNom, 0.442805, 0.001, "sampleDomainWarpedFbm2D nominal resNom ~= 0.442805")
  assertApproxEq(resEdge, 0.0, 0.001, "sampleDomainWarpedFbm2D boundary resEdge ~= 0.0")
  ret 0
```

---

### `poissonDiscSample2D` (`std/procgen/poisson_disc.aipl`)

- **Signature**: `pub fn poissonDiscSample2D(config: PoissonDiscConfig2D): [Vec2]:`
- **Import**: `import * from "std/procgen/poisson_disc"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `config: PoissonDiscConfig2D` | **Returns**: `[Vec2]`
- **Unit Test**: `tests/functions/procgen/poisson_disc_test.aipl` | **Example**: `examples/ex_233_procgen_cellular_automata_caves_window.aipl`
- **Behavioral Summary**: Verifies Bridson 2D/3D Poisson-disc blue-noise sampling enforces pairwise distance $\ge r - \epsilon$ in `poissonDiscSample2D`. Concrete nominal inputs: `config: PoissonDiscConfig2D = PoissonDiscConfig2D(bounds = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0()), minDistance = 1.0, maxCandidates = 1, seed = 42)`; exercises core body path returning/computing `samples`.

```aipl
module tests.functions.procgen.poisson_disc_z1_test
import * from "std/procgen/poisson_disc"
import { TAU } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec2, Vec3 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { AABB3D } from "std/math/geom3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_poisson_disc_poissonDiscSample2D_1(): int:
  let arg_config = PoissonDiscConfig2D(bounds = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0), minDistance = 0.0, maxCandidates = 4, seed = 0)
  let edge_config = PoissonDiscConfig2D(bounds = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0), minDistance = 0.0, maxCandidates = 1, seed = 0)
  let resNom = poissonDiscSample2D(arg_config)
  let resEdge = poissonDiscSample2D(edge_config)
  assertEqInt(resNom.len(), 256, "poissonDiscSample2D nominal resNom.len() == 256")
  assertEqInt(resEdge.len(), 256, "poissonDiscSample2D boundary resEdge.len() == 256")
  ret 0
```

---

### `poissonDiscSample3D` (`std/procgen/poisson_disc.aipl`)

- **Signature**: `pub fn poissonDiscSample3D(bounds: AABB3D, minDistance: float, k: int, seed: int): [Vec3]:`
- **Import**: `import * from "std/procgen/poisson_disc"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bounds: AABB3D, minDistance: float, k: int, seed: int` | **Returns**: `[Vec3]`
- **Unit Test**: `tests/functions/procgen/poisson_disc_test.aipl` | **Example**: `examples/ex_231_procgen_noise_perlin_simplex_worley_window.aipl`
- **Behavioral Summary**: Verifies Bridson 2D/3D Poisson-disc blue-noise sampling enforces pairwise distance $\ge r - \epsilon$ in `poissonDiscSample3D`. Concrete nominal inputs: `bounds: AABB3D = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))`, `minDistance: float = 1.0`, `k: int = 1`, `seed: int = 42`; exercises core body path returning/computing `samples`.

```aipl
module tests.functions.procgen.poisson_disc_z2_test
import * from "std/procgen/poisson_disc"
import { TAU } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec2, Vec3 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { AABB3D } from "std/math/geom3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_poisson_disc_poissonDiscSample3D_2(): int:
  let arg_bounds = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))
  let edge_bounds = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5))
  let arg_minDistance = 0.0
  let edge_minDistance = 0.0
  let arg_k = 4
  let edge_k = 1
  let arg_seed = 1
  let edge_seed = 0
  let resNom = poissonDiscSample3D(arg_bounds, arg_minDistance, arg_k, arg_seed)
  let resEdge = poissonDiscSample3D(edge_bounds, edge_minDistance, edge_k, edge_seed)
  assertEqInt(resNom.len(), 128, "poissonDiscSample3D nominal resNom.len() == 128")
  assertEqInt(resEdge.len(), 128, "poissonDiscSample3D boundary resEdge.len() == 128")
  ret 0
```

---

### `wfcSolver2dNew` (`std/procgen/wfc_solver.aipl`)

- **Signature**: `pub fn wfcSolver2dNew(width: int, height: int, numPatterns: int): WfcSolver2D:`
- **Import**: `import * from "std/procgen/wfc_solver"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `width: int, height: int, numPatterns: int` | **Returns**: `WfcSolver2D`
- **Unit Test**: `tests/functions/procgen/wfc_solver_test.aipl` | **Example**: `examples/ex_232_procgen_dungeon_bsp_and_corridors_window.aipl`
- **Behavioral Summary**: Tests Wave Function Collapse Shannon entropy selection, adjacency bitmask propagation, and contradiction-free tiling in `wfcSolver2dNew`. Concrete nominal inputs: `width: int = 128`, `height: int = 128`, `numPatterns: int = 1`; exercises core body path returning/computing `WfcSolver2D(`.

```aipl
module tests.functions.procgen.wfc_solver_z1_test
import * from "std/procgen/wfc_solver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_wfc_solver_wfcSolver2dNew_1(): int:
  let arg_width = 4
  let edge_width = 1
  let arg_height = 4
  let edge_height = 1
  let arg_numPatterns = 4
  let edge_numPatterns = 1
  let resNom = wfcSolver2dNew(arg_width, arg_height, arg_numPatterns)
  let resEdge = wfcSolver2dNew(edge_width, edge_height, edge_numPatterns)
  assertEqInt(resNom.width, 4, "wfcSolver2dNew nominal resNom.width == 4")
  assertEqInt(resEdge.width, 1, "wfcSolver2dNew boundary resEdge.width == 1")
  ret 0
```

---

### `wfcAddPattern` (`std/procgen/wfc_solver.aipl`)

- **Signature**: `pub fn wfcAddPattern(mut solver: WfcSolver2D, pattern: WfcPattern): void:`
- **Import**: `import * from "std/procgen/wfc_solver"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut solver: WfcSolver2D, pattern: WfcPattern` | **Returns**: `void`
- **Unit Test**: `tests/functions/procgen/wfc_solver_test.aipl` | **Example**: `examples/ex_233_procgen_cellular_automata_caves_window.aipl`
- **Behavioral Summary**: Tests Wave Function Collapse Shannon entropy selection, adjacency bitmask propagation, and contradiction-free tiling in `wfcAddPattern`. Concrete nominal inputs: `solver: WfcSolver2D = WfcSolver2D(width = 128, height = 128, numPatterns = 1, patterns = [WfcPattern(id = 0, weight = 0, compatibleNeighbors = 0)], waveMasks = [1], collapsedGrid = [1], isSolved = true)`, `pattern: WfcPattern = WfcPattern(id = 1, weight = 0.5, compatibleNeighbors = [[0]])`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.procgen.wfc_solver_z2_test
import * from "std/procgen/wfc_solver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_wfc_solver_wfcAddPattern_2(): int:
  let arg_solver = WfcSolver2D(width = 4, height = 4, numPatterns = 4, patterns = [], waveMasks = [], collapsedGrid = [], isSolved = true)
  let edge_solver = WfcSolver2D(width = 4, height = 4, numPatterns = 1, patterns = [], waveMasks = [], collapsedGrid = [], isSolved = false)
  let arg_pattern = WfcPattern(id = 1, weight = 2.0, compatibleNeighbors = [])
  let edge_pattern = WfcPattern(id = 0, weight = 1.0, compatibleNeighbors = [])
  wfcAddPattern(arg_solver, arg_pattern)
  wfcAddPattern(edge_solver, edge_pattern)
  assertEqInt(arg_solver.patterns.len(), 1, "wfcAddPattern nominal arg_solver.patterns.len() == 1")
  assertEqInt(edge_solver.patterns.len(), 1, "wfcAddPattern boundary edge_solver.patterns.len() == 1")
  ret 0
```

---

### `countSetBits` (`std/procgen/wfc_solver.aipl`)

- **Signature**: `fn countSetBits(mask: int, maxBits: int): int:`
- **Import**: `import * from "std/procgen/wfc_solver"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mask: int, maxBits: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/procgen/wfc_solver_test.aipl` | **Example**: `examples/ex_231_procgen_noise_perlin_simplex_worley_window.aipl`
- **Behavioral Summary**: Tests Wave Function Collapse Shannon entropy selection, adjacency bitmask propagation, and contradiction-free tiling in `countSetBits`. Concrete nominal inputs: `mask: int = 1`, `maxBits: int = 1`; exercises core body path returning/computing `c`.

```aipl
module tests.functions.procgen.wfc_solver_z3_test
import * from "std/procgen/wfc_solver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_wfc_solver_countSetBits_3(): int:
  let arg_mask = 4
  let edge_mask = 1
  let arg_maxBits = 4
  let edge_maxBits = 1
  let resNom = countSetBits(arg_mask, arg_maxBits)
  let resEdge = countSetBits(edge_mask, edge_maxBits)
  assertEqInt(resNom, 1, "countSetBits nominal resNom == 1")
  assertEqInt(resEdge, 1, "countSetBits boundary resEdge == 1")
  ret 0
```

---

### `wfcStep` (`std/procgen/wfc_solver.aipl`)

- **Signature**: `pub fn wfcStep(mut solver: WfcSolver2D, seed: int): bool:`
- **Import**: `import * from "std/procgen/wfc_solver"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut solver: WfcSolver2D, seed: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/procgen/wfc_solver_test.aipl` | **Example**: `examples/ex_232_procgen_dungeon_bsp_and_corridors_window.aipl`
- **Behavioral Summary**: Tests Wave Function Collapse Shannon entropy selection, adjacency bitmask propagation, and contradiction-free tiling in `wfcStep`. Concrete nominal inputs: `solver: WfcSolver2D = WfcSolver2D(width = 128, height = 128, numPatterns = 1, patterns = [WfcPattern(id = 0, weight = 0, compatibleNeighbors = 0)], waveMasks = [1], collapsedGrid = [1], isSolved = true)`, `seed: int = 42`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.procgen.wfc_solver_z4_test
import * from "std/procgen/wfc_solver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_wfc_solver_wfcStep_4(): int:
  let arg_solver = WfcSolver2D(width = 4, height = 4, numPatterns = 4, patterns = [], waveMasks = [], collapsedGrid = [], isSolved = true)
  let edge_solver = WfcSolver2D(width = 4, height = 4, numPatterns = 1, patterns = [], waveMasks = [], collapsedGrid = [], isSolved = false)
  let arg_seed = 1
  let edge_seed = 0
  let resNom = wfcStep(arg_solver, arg_seed)
  let resEdge = wfcStep(edge_solver, edge_seed)
  assert(resNom == true, "wfcStep nominal resNom == true")
  assert(resEdge == true, "wfcStep boundary resEdge == true")
  ret 0
```

---

### `wfcSolve` (`std/procgen/wfc_solver.aipl`)

- **Signature**: `pub fn wfcSolve(mut solver: WfcSolver2D, maxRestarts: int, seed: int): bool:`
- **Import**: `import * from "std/procgen/wfc_solver"` (or barrel `import * from "std/procgen/procgen_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut solver: WfcSolver2D, maxRestarts: int, seed: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/procgen/wfc_solver_test.aipl` | **Example**: `examples/ex_233_procgen_cellular_automata_caves_window.aipl`
- **Behavioral Summary**: Tests Wave Function Collapse Shannon entropy selection, adjacency bitmask propagation, and contradiction-free tiling in `wfcSolve`. Concrete nominal inputs: `solver: WfcSolver2D = WfcSolver2D(width = 128, height = 128, numPatterns = 1, patterns = [WfcPattern(id = 0, weight = 0, compatibleNeighbors = 0)], waveMasks = [1], collapsedGrid = [1], isSolved = true)`, `maxRestarts: int = 1`, `seed: int = 42`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.procgen.wfc_solver_z5_test
import * from "std/procgen/wfc_solver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_wfc_solver_wfcSolve_5(): int:
  let arg_solver = WfcSolver2D(width = 4, height = 4, numPatterns = 4, patterns = [], waveMasks = [], collapsedGrid = [], isSolved = true)
  let edge_solver = WfcSolver2D(width = 4, height = 4, numPatterns = 1, patterns = [], waveMasks = [], collapsedGrid = [], isSolved = false)
  let arg_maxRestarts = 4
  let edge_maxRestarts = 1
  let arg_seed = 1
  let edge_seed = 0
  let resNom = wfcSolve(arg_solver, arg_maxRestarts, arg_seed)
  let resEdge = wfcSolve(edge_solver, edge_maxRestarts, edge_seed)
  assert(resNom == true, "wfcSolve nominal resNom == true")
  assert(resEdge == true, "wfcSolve boundary resEdge == true")
  ret 0
```
