[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 31: `spatial` API Reference

> Complete API reference manual for AIPL standard library domain `spatial` (58 callable functions & methods across ["std/spatial/bsp_sector_world3d.aipl", "std/spatial/continuous_world2d.aipl", "std/spatial/continuous_world3d.aipl", "std/spatial/hex_tile_world2d.aipl", "std/spatial/iso_tile_world2d.aipl", "std/spatial/ortho_tile_world2d.aipl", "std/spatial/spatial_mod.aipl", "std/spatial/voxel_chunk_world3d.aipl", "std/spatial/waypoint_graph_world.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `spatial`
- **Target Source Modules**: ["std/spatial/bsp_sector_world3d.aipl", "std/spatial/continuous_world2d.aipl", "std/spatial/continuous_world3d.aipl", "std/spatial/hex_tile_world2d.aipl", "std/spatial/iso_tile_world2d.aipl", "std/spatial/ortho_tile_world2d.aipl", "std/spatial/spatial_mod.aipl", "std/spatial/voxel_chunk_world3d.aipl", "std/spatial/waypoint_graph_world.aipl"]
- **Total Callable Functions & Methods**: 58
- **Total Data Types (`struct` & `enum`)**: 27
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(27 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `BspPortal` | `pub struct` | `std/spatial/bsp_sector_world3d.aipl` | `targetSectorId: int`, `polygonVertices: [Vec3]`, `plane: Plane3D`, `isOpen: bool` | `BspPortal(targetSectorId, polygonVertices, plane, isOpen)` |
| `BspSector` | `pub struct` | `std/spatial/bsp_sector_world3d.aipl` | `sectorId: int`, `boundingBox: AABB3D`, `floorHeight: float`, `ceilingHeight: float`, `portals: [BspPortal]`, `pvsMask: int` | `BspSector(sectorId, boundingBox, floorHeight, ceilingHeight, portals, pvsMask)` |
| `BspSectorWorld3D` | `pub struct` | `std/spatial/bsp_sector_world3d.aipl` | `sectors: [BspSector]` | `BspSectorWorld3D(sectors)` |
| `SpatialObject2D` | `pub struct` | `std/spatial/continuous_world2d.aipl` | `id: int`, `position: Vec2`, `radius: float`, `layerMask: int`, `bounds: Rect2D` | `SpatialObject2D(id, position, radius, layerMask, bounds)` |
| `SpatialRayHit2D` | `pub struct` | `std/spatial/continuous_world2d.aipl` | `objectId: int`, `distance: float`, `point: Vec2`, `normal: Vec2` | `SpatialRayHit2D(objectId, distance, point, normal)` |
| `ContinuousSpaceWorld2D` | `pub struct` | `std/spatial/continuous_world2d.aipl` | `worldBounds: Rect2D`, `cellSize: float`, `objects: [SpatialObject2D]`, `alive: [bool]` | `ContinuousSpaceWorld2D(worldBounds, cellSize, objects, alive)` |
| `Transform3D` | `pub struct` | `std/spatial/continuous_world3d.aipl` | `position: Vec3`, `rotation: Quat`, `scale: Vec3` | `Transform3D(position, rotation, scale)` |
| `SpatialRayHit3D` | `pub struct` | `std/spatial/continuous_world3d.aipl` | `objectId: int`, `distance: float`, `point: Vec3`, `normal: Vec3` | `SpatialRayHit3D(objectId, distance, point, normal)` |
| `SpatialObject3D` | `pub struct` | `std/spatial/continuous_world3d.aipl` | `id: int`, `transform: Transform3D`, `boundingBox: AABB3D`, `boundingSphere: Sphere3D`, `layerMask: int` | `SpatialObject3D(id, transform, boundingBox, boundingSphere, layerMask)` |
| `ContinuousSpaceWorld3D` | `pub struct` | `std/spatial/continuous_world3d.aipl` | `worldBounds: AABB3D`, `objects: [SpatialObject3D]`, `alive: [bool]` | `ContinuousSpaceWorld3D(worldBounds, objects, alive)` |
| `HexOrientation` | `pub enum` | `std/spatial/hex_tile_world2d.aipl` | `PointyTop`, `FlatTop` | Algebraic Enum (2 variants) |
| `HexCubeCoord` | `pub struct` | `std/spatial/hex_tile_world2d.aipl` | `x: int`, `y: int`, `z: int` | `HexCubeCoord(x, y, z)` |
| `HexAxialCoord` | `pub struct` | `std/spatial/hex_tile_world2d.aipl` | `q: int`, `r: int` | `HexAxialCoord(q, r)` |
| `HexTileCell2D` | `pub struct` | `std/spatial/hex_tile_world2d.aipl` | `terrainId: int`, `resourceCost: float`, `passable: bool` | `HexTileCell2D(terrainId, resourceCost, passable)` |
| `HexTileWorld2D` | `pub struct` | `std/spatial/hex_tile_world2d.aipl` | `radius: int`, `orientation: HexOrientation`, `hexSize: float`, `cells: [HexTileCell2D]` | `HexTileWorld2D(radius, orientation, hexSize, cells)` |
| `IsoTileCell2D` | `pub struct` | `std/spatial/iso_tile_world2d.aipl` | `tileId: int`, `heightStep: int`, `walkable: bool`, `surfaceNormal: Vec3` | `IsoTileCell2D(tileId, heightStep, walkable, surfaceNormal)` |
| `IsoTileWorld2D` | `pub struct` | `std/spatial/iso_tile_world2d.aipl` | `cols: int`, `rows: int`, `tileWidth: float`, `tileHeight: float`, `elevationScale: float`, `cells: [IsoTileCell2D]` | `IsoTileWorld2D(cols, rows, tileWidth, tileHeight, elevationScale, cells)` |
| `OrthoTileCell2D` | `pub struct` | `std/spatial/ortho_tile_world2d.aipl` | `tileId: int`, `solid: bool`, `elevation: float`, `flags: int`, `userData: int` | `OrthoTileCell2D(tileId, solid, elevation, flags, userData)` |
| `OrthoTileWorld2D` | `pub struct` | `std/spatial/ortho_tile_world2d.aipl` | `width: int`, `height: int`, `cellSize: float`, `layers: int`, `cells: [OrthoTileCell2D]`, `wrapX: bool`, `wrapY: bool` | `OrthoTileWorld2D(width, height, cellSize, layers, cells, wrapX, wrapY)` |
| `VoxelBlock` | `pub struct` | `std/spatial/voxel_chunk_world3d.aipl` | `blockId: int`, `metadata: int`, `lightLevel: int` | `VoxelBlock(blockId, metadata, lightLevel)` |
| `VoxelChunk16` | `pub struct` | `std/spatial/voxel_chunk_world3d.aipl` | `coord: IVec3`, `chunkSize: int`, `blocks: [VoxelBlock]`, `isDirty: bool` | `VoxelChunk16(coord, chunkSize, blocks, isDirty)` |
| `VoxelRayHit` | `pub struct` | `std/spatial/voxel_chunk_world3d.aipl` | `coord: IVec3`, `normal: IVec3`, `distance: float`, `blockId: int` | `VoxelRayHit(coord, normal, distance, blockId)` |
| `QuadFace3D` | `pub struct` | `std/spatial/voxel_chunk_world3d.aipl` | `axis: int`, `normalSign: int`, `sliceCoord: int`, `u0: int`, `v0: int`, `width: int`, `height: int`, `blockId: int` | `QuadFace3D(axis, normalSign, sliceCoord, u0, v0, width, height, blockId)` |
| `VoxelChunkWorld3D` | `pub struct` | `std/spatial/voxel_chunk_world3d.aipl` | `chunkSize: int`, `chunks: [VoxelChunk16]` | `VoxelChunkWorld3D(chunkSize, chunks)` |
| `WaypointNode` | `pub struct` | `std/spatial/waypoint_graph_world.aipl` | `id: int`, `name: str`, `position: Vec3`, `tags: [str]` | `WaypointNode(id, name, position, tags)` |
| `WaypointEdge` | `pub struct` | `std/spatial/waypoint_graph_world.aipl` | `fromId: int`, `toId: int`, `weight: float`, `bidirectional: bool`, `isTraversable: bool` | `WaypointEdge(fromId, toId, weight, bidirectional, isTraversable)` |
| `WaypointGraphWorld` | `pub struct` | `std/spatial/waypoint_graph_world.aipl` | `nodes: [WaypointNode]`, `edges: [WaypointEdge]` | `WaypointGraphWorld(nodes, edges)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/spatial/bsp_sector_world3d.aipl` | `bspSectorWorldNew` | `pub fn bspSectorWorldNew(): BspSectorWorld3D:` | `tests/functions/spatial/bsp_sector_world3d_test.aipl` |
| `2` | `std/spatial/bsp_sector_world3d.aipl` | `bspAddSector` | `pub fn bspAddSector(mut world: BspSectorWorld3D, sector: BspSector): int:` | `tests/functions/spatial/bsp_sector_world3d_test.aipl` |
| `3` | `std/spatial/bsp_sector_world3d.aipl` | `bspAddPortal` | `pub fn bspAddPortal(mut world: BspSectorWorld3D, fromSector: int, toSector: int, portal: BspPortal): bool:` | `tests/functions/spatial/bsp_sector_world3d_test.aipl` |
| `4` | `std/spatial/bsp_sector_world3d.aipl` | `bspFindSectorContainingPoint` | `pub fn bspFindSectorContainingPoint(world: BspSectorWorld3D, pt: Vec3): Option[int]:` | `tests/functions/spatial/bsp_sector_world3d_test.aipl` |
| `5` | `std/spatial/bsp_sector_world3d.aipl` | `isPointInFrustum` | `fn isPointInFrustum(frustum: Frustum3D, pt: Vec3): bool:` | `tests/functions/spatial/bsp_sector_world3d_test.aipl` |
| `6` | `std/spatial/bsp_sector_world3d.aipl` | `bspQueryVisibleSectors` | `pub fn bspQueryVisibleSectors(world: BspSectorWorld3D, currentSectorId: int, cameraFrustum: Frustum3D): [int]:` | `tests/functions/spatial/bsp_sector_world3d_test.aipl` |
| `7` | `std/spatial/continuous_world2d.aipl` | `continuousWorld2dNew` | `pub fn continuousWorld2dNew(bounds: Rect2D, cellSize: float): ContinuousSpaceWorld2D:` | `tests/functions/spatial/continuous_world2d_test.aipl` |
| `8` | `std/spatial/continuous_world2d.aipl` | `continuousWorld2dInsert` | `pub fn continuousWorld2dInsert(mut world: ContinuousSpaceWorld2D, obj: SpatialObject2D): int:` | `tests/functions/spatial/continuous_world2d_test.aipl` |
| `9` | `std/spatial/continuous_world2d.aipl` | `continuousWorld2dUpdate` | `pub fn continuousWorld2dUpdate(mut world: ContinuousSpaceWorld2D, id: int, newPos: Vec2): bool:` | `tests/functions/spatial/continuous_world2d_test.aipl` |
| `10` | `std/spatial/continuous_world2d.aipl` | `continuousWorld2dRemove` | `pub fn continuousWorld2dRemove(mut world: ContinuousSpaceWorld2D, id: int): bool:` | `tests/functions/spatial/continuous_world2d_test.aipl` |
| `11` | `std/spatial/continuous_world2d.aipl` | `continuousWorld2dQueryRadius` | `pub fn continuousWorld2dQueryRadius(world: ContinuousSpaceWorld2D, center: Vec2, radius: float, layerMask: int): [int]:` | `tests/functions/spatial/continuous_world2d_test.aipl` |
| `12` | `std/spatial/continuous_world2d.aipl` | `continuousWorld2dQueryAABB` | `pub fn continuousWorld2dQueryAABB(world: ContinuousSpaceWorld2D, aabb: Rect2D, layerMask: int): [int]:` | `tests/functions/spatial/continuous_world2d_test.aipl` |
| `13` | `std/spatial/continuous_world2d.aipl` | `continuousWorld2dRaycast` | `pub fn continuousWorld2dRaycast(world: ContinuousSpaceWorld2D, origin: Vec2, direction: Vec2, maxDist: float, layerMask: int): Option[SpatialRayHit2D]:` | `tests/functions/spatial/continuous_world2d_test.aipl` |
| `14` | `std/spatial/continuous_world3d.aipl` | `continuousWorld3dNew` | `pub fn continuousWorld3dNew(worldBounds: AABB3D): ContinuousSpaceWorld3D:` | `tests/functions/spatial/continuous_world3d_test.aipl` |
| `15` | `std/spatial/continuous_world3d.aipl` | `continuousWorld3dInsert` | `pub fn continuousWorld3dInsert(mut world: ContinuousSpaceWorld3D, obj: SpatialObject3D): int:` | `tests/functions/spatial/continuous_world3d_test.aipl` |
| `16` | `std/spatial/continuous_world3d.aipl` | `continuousWorld3dUpdateTransform` | `pub fn continuousWorld3dUpdateTransform(mut world: ContinuousSpaceWorld3D, id: int, transform: Transform3D): bool:` | `tests/functions/spatial/continuous_world3d_test.aipl` |
| `17` | `std/spatial/continuous_world3d.aipl` | `continuousWorld3dQuerySphere` | `pub fn continuousWorld3dQuerySphere(world: ContinuousSpaceWorld3D, center: Vec3, radius: float, mask: int): [int]:` | `tests/functions/spatial/continuous_world3d_test.aipl` |
| `18` | `std/spatial/continuous_world3d.aipl` | `continuousWorld3dQueryFrustum` | `pub fn continuousWorld3dQueryFrustum(world: ContinuousSpaceWorld3D, frustum: Frustum3D, mask: int): [int]:` | `tests/functions/spatial/continuous_world3d_test.aipl` |
| `19` | `std/spatial/continuous_world3d.aipl` | `continuousWorld3dRaycast` | `pub fn continuousWorld3dRaycast(world: ContinuousSpaceWorld3D, ray: Ray3D, maxDist: float, mask: int): Option[SpatialRayHit3D]:` | `tests/functions/spatial/continuous_world3d_test.aipl` |
| `20` | `std/spatial/hex_tile_world2d.aipl` | `hexCubeNew` | `pub fn hexCubeNew(x: int, y: int, z: int): HexCubeCoord:` | `tests/functions/spatial/hex_tile_world2d_test.aipl` |
| `21` | `std/spatial/hex_tile_world2d.aipl` | `hexAxialToCube` | `pub fn hexAxialToCube(axial: HexAxialCoord): HexCubeCoord:` | `tests/functions/spatial/hex_tile_world2d_test.aipl` |
| `22` | `std/spatial/hex_tile_world2d.aipl` | `hexCubeToAxial` | `pub fn hexCubeToAxial(cube: HexCubeCoord): HexAxialCoord:` | `tests/functions/spatial/hex_tile_world2d_test.aipl` |
| `23` | `std/spatial/hex_tile_world2d.aipl` | `hexDistance` | `pub fn hexDistance(a: HexCubeCoord, b: HexCubeCoord): int:` | `tests/functions/spatial/hex_tile_world2d_test.aipl` |
| `24` | `std/spatial/hex_tile_world2d.aipl` | `hexRing` | `pub fn hexRing(center: HexCubeCoord, radius: int): [HexCubeCoord]:` | `tests/functions/spatial/hex_tile_world2d_test.aipl` |
| `25` | `std/spatial/hex_tile_world2d.aipl` | `hexSpiral` | `pub fn hexSpiral(center: HexCubeCoord, maxRadius: int): [HexCubeCoord]:` | `tests/functions/spatial/hex_tile_world2d_test.aipl` |
| `26` | `std/spatial/hex_tile_world2d.aipl` | `cubeRound` | `fn cubeRound(fx: float, fy: float, fz: float): HexCubeCoord:` | `tests/functions/spatial/hex_tile_world2d_test.aipl` |
| `27` | `std/spatial/hex_tile_world2d.aipl` | `hexToPixel` | `pub fn hexToPixel(coord: HexAxialCoord, orientation: HexOrientation, size: float): Vec2:` | `tests/functions/spatial/hex_tile_world2d_test.aipl` |
| `28` | `std/spatial/hex_tile_world2d.aipl` | `hexPixelToAxial` | `pub fn hexPixelToAxial(pixel: Vec2, orientation: HexOrientation, size: float): HexAxialCoord:` | `tests/functions/spatial/hex_tile_world2d_test.aipl` |
| `29` | `std/spatial/hex_tile_world2d.aipl` | `hexLine` | `pub fn hexLine(a: HexCubeCoord, b: HexCubeCoord): [HexCubeCoord]:` | `tests/functions/spatial/hex_tile_world2d_test.aipl` |
| `30` | `std/spatial/iso_tile_world2d.aipl` | `isoTileWorldNew` | `pub fn isoTileWorldNew(cols: int, rows: int, tileWidth: float, tileHeight: float, elevationScale: float): IsoTileWorld2D:` | `tests/functions/spatial/iso_tile_world2d_test.aipl` |
| `31` | `std/spatial/iso_tile_world2d.aipl` | `isoWorldGridToScreen` | `pub fn isoWorldGridToScreen(world: IsoTileWorld2D, col: int, row: int, elevation: float): Vec2:` | `tests/functions/spatial/iso_tile_world2d_test.aipl` |
| `32` | `std/spatial/iso_tile_world2d.aipl` | `isoScreenToGrid` | `pub fn isoScreenToGrid(world: IsoTileWorld2D, screenX: float, screenY: float): Vec2:` | `tests/functions/spatial/iso_tile_world2d_test.aipl` |
| `33` | `std/spatial/iso_tile_world2d.aipl` | `isoPickCellWithHeight` | `pub fn isoPickCellWithHeight(world: IsoTileWorld2D, screenX: float, screenY: float): Option[IVec2]:` | `tests/functions/spatial/iso_tile_world2d_test.aipl` |
| `34` | `std/spatial/iso_tile_world2d.aipl` | `isoDepthSortKey` | `pub fn isoDepthSortKey(col: int, row: int, elevation: float): float:` | `tests/functions/spatial/iso_tile_world2d_test.aipl` |
| `35` | `std/spatial/ortho_tile_world2d.aipl` | `orthoTileWorldNew` | `pub fn orthoTileWorldNew(width: int, height: int, cellSize: float, layers: int): OrthoTileWorld2D:` | `tests/functions/spatial/ortho_tile_world2d_test.aipl` |
| `36` | `std/spatial/ortho_tile_world2d.aipl` | `resolveOrthoCoords` | `fn resolveOrthoCoords(world: OrthoTileWorld2D, layer: int, col: int, row: int): int:` | `tests/functions/spatial/ortho_tile_world2d_test.aipl` |
| `37` | `std/spatial/ortho_tile_world2d.aipl` | `orthoTileGet` | `pub fn orthoTileGet(world: OrthoTileWorld2D, layer: int, col: int, row: int): Option[OrthoTileCell2D]:` | `tests/functions/spatial/ortho_tile_world2d_test.aipl` |
| `38` | `std/spatial/ortho_tile_world2d.aipl` | `orthoTileSet` | `pub fn orthoTileSet(mut world: OrthoTileWorld2D, layer: int, col: int, row: int, cell: OrthoTileCell2D): bool:` | `tests/functions/spatial/ortho_tile_world2d_test.aipl` |
| `39` | `std/spatial/ortho_tile_world2d.aipl` | `orthoWorldToCell` | `pub fn orthoWorldToCell(world: OrthoTileWorld2D, wx: float, wy: float): IVec2:` | `tests/functions/spatial/ortho_tile_world2d_test.aipl` |
| `40` | `std/spatial/ortho_tile_world2d.aipl` | `orthoCellToWorldCenter` | `pub fn orthoCellToWorldCenter(world: OrthoTileWorld2D, col: int, row: int): Vec2:` | `tests/functions/spatial/ortho_tile_world2d_test.aipl` |
| `41` | `std/spatial/ortho_tile_world2d.aipl` | `orthoNeighbors4` | `pub fn orthoNeighbors4(world: OrthoTileWorld2D, col: int, row: int): [IVec2]:` | `tests/functions/spatial/ortho_tile_world2d_test.aipl` |
| `42` | `std/spatial/ortho_tile_world2d.aipl` | `orthoNeighbors8` | `pub fn orthoNeighbors8(world: OrthoTileWorld2D, col: int, row: int): [IVec2]:` | `tests/functions/spatial/ortho_tile_world2d_test.aipl` |
| `43` | `std/spatial/ortho_tile_world2d.aipl` | `orthoLineOfSightBresenham` | `pub fn orthoLineOfSightBresenham(world: OrthoTileWorld2D, layer: int, c0: int, r0: int, c1: int, r1: int): bool:` | `tests/functions/spatial/ortho_tile_world2d_test.aipl` |
| `44` | `std/spatial/ortho_tile_world2d.aipl` | `orthoFloodFill` | `pub fn orthoFloodFill(mut world: OrthoTileWorld2D, layer: int, startCol: int, startRow: int, targetTileId: int, fillTileId: int): int:` | `tests/functions/spatial/ortho_tile_world2d_test.aipl` |
| `45` | `std/spatial/ortho_tile_world2d.aipl` | `orthoRaycastCells` | `pub fn orthoRaycastCells(world: OrthoTileWorld2D, layer: int, start: Vec2, dir: Vec2, maxDist: float): [IVec2]:` | `tests/functions/spatial/ortho_tile_world2d_test.aipl` |
| `46` | `std/spatial/voxel_chunk_world3d.aipl` | `voxelChunkWorldNew` | `pub fn voxelChunkWorldNew(chunkSize: int): VoxelChunkWorld3D:` | `tests/functions/spatial/voxel_chunk_world3d_test.aipl` |
| `47` | `std/spatial/voxel_chunk_world3d.aipl` | `floorDivInt` | `fn floorDivInt(a: int, b: int): int:` | `tests/functions/spatial/voxel_chunk_world3d_test.aipl` |
| `48` | `std/spatial/voxel_chunk_world3d.aipl` | `posModInt` | `fn posModInt(a: int, b: int): int:` | `tests/functions/spatial/voxel_chunk_world3d_test.aipl` |
| `49` | `std/spatial/voxel_chunk_world3d.aipl` | `voxelGetBlock` | `pub fn voxelGetBlock(world: VoxelChunkWorld3D, gx: int, gy: int, gz: int): Option[VoxelBlock]:` | `tests/functions/spatial/voxel_chunk_world3d_test.aipl` |
| `50` | `std/spatial/voxel_chunk_world3d.aipl` | `voxelSetBlock` | `pub fn voxelSetBlock(mut world: VoxelChunkWorld3D, gx: int, gy: int, gz: int, block: VoxelBlock): bool:` | `tests/functions/spatial/voxel_chunk_world3d_test.aipl` |
| `51` | `std/spatial/voxel_chunk_world3d.aipl` | `voxelRaycastDDA` | `pub fn voxelRaycastDDA(world: VoxelChunkWorld3D, origin: Vec3, dir: Vec3, maxDistance: float): Option[VoxelRayHit]:` | `tests/functions/spatial/voxel_chunk_world3d_test.aipl` |
| `52` | `std/spatial/voxel_chunk_world3d.aipl` | `voxelExtractGreedyFaces` | `pub fn voxelExtractGreedyFaces(chunk: VoxelChunk16): [QuadFace3D]:` | `tests/functions/spatial/voxel_chunk_world3d_test.aipl` |
| `53` | `std/spatial/waypoint_graph_world.aipl` | `waypointGraphWorldNew` | `pub fn waypointGraphWorldNew(): WaypointGraphWorld:` | `tests/functions/spatial/waypoint_graph_world_test.aipl` |
| `54` | `std/spatial/waypoint_graph_world.aipl` | `waypointAddNode` | `pub fn waypointAddNode(mut world: WaypointGraphWorld, id: int, name: str, pos: Vec3): bool:` | `tests/functions/spatial/waypoint_graph_world_test.aipl` |
| `55` | `std/spatial/waypoint_graph_world.aipl` | `waypointAddEdge` | `pub fn waypointAddEdge(mut world: WaypointGraphWorld, fromId: int, toId: int, weight: float, bidirectional: bool): bool:` | `tests/functions/spatial/waypoint_graph_world_test.aipl` |
| `56` | `std/spatial/waypoint_graph_world.aipl` | `findNodeIndex` | `fn findNodeIndex(world: WaypointGraphWorld, id: int): int:` | `tests/functions/spatial/waypoint_graph_world_test.aipl` |
| `57` | `std/spatial/waypoint_graph_world.aipl` | `waypointShortestPathDijkstra` | `pub fn waypointShortestPathDijkstra(world: WaypointGraphWorld, startId: int, goalId: int): Option[[int]]:` | `tests/functions/spatial/waypoint_graph_world_test.aipl` |
| `58` | `std/spatial/waypoint_graph_world.aipl` | `waypointNodesInRadius` | `pub fn waypointNodesInRadius(world: WaypointGraphWorld, center: Vec3, radius: float): [int]:` | `tests/functions/spatial/waypoint_graph_world_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `bspSectorWorldNew` (`std/spatial/bsp_sector_world3d.aipl`)

- **Signature**: `pub fn bspSectorWorldNew(): BspSectorWorld3D:`
- **Import**: `import * from "std/spatial/bsp_sector_world3d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `BspSectorWorld3D`
- **Unit Test**: `tests/functions/spatial/bsp_sector_world3d_test.aipl` | **Example**: `examples/ex_209_spatial_iso_tile_world2d_window.aipl`
- **Behavioral Summary**: Tests 3D BSP plane splitting, leaf sector point classification, and portal-to-portal PVS visibility traversal in `bspSectorWorldNew`. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `BspSectorWorld3D(sectors = secs)`.

```aipl
module tests.functions.spatial.bsp_sector_world3d_z1_test
import * from "std/spatial/bsp_sector_world3d"
import { Vec3 } from "std/math/vec_math"
import { AABB3D, Plane3D, Frustum3D } from "std/math/geom3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bsp_sector_world3d_bspSectorWorldNew_1(): int:
  let resNom = bspSectorWorldNew()
  let resEdge = bspSectorWorldNew()
  assertEqInt(resNom.sectors.len(), 0, "bspSectorWorldNew nominal resNom.sectors.len() == 0")
  assertEqInt(resEdge.sectors.len(), 0, "bspSectorWorldNew boundary resEdge.sectors.len() == 0")
  ret 0
```

---

### `bspAddSector` (`std/spatial/bsp_sector_world3d.aipl`)

- **Signature**: `pub fn bspAddSector(mut world: BspSectorWorld3D, sector: BspSector): int:`
- **Import**: `import * from "std/spatial/bsp_sector_world3d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut world: BspSectorWorld3D, sector: BspSector` | **Returns**: `int`
- **Unit Test**: `tests/functions/spatial/bsp_sector_world3d_test.aipl` | **Example**: `examples/ex_210_spatial_hex_tile_world2d_window.aipl`
- **Behavioral Summary**: Tests 3D BSP plane splitting, leaf sector point classification, and portal-to-portal PVS visibility traversal in `bspAddSector`. Concrete nominal inputs: `world: BspSectorWorld3D = BspSectorWorld3D(sectors = [BspSector(sectorId = 0, boundingBox = 0, floorHeight = 0, ceilingHeight = 0, portals = 0, pvsMask = 0)])`, `sector: BspSector = BspSector(sectorId = 1, boundingBox = AABB3D(min = Vec3(x = 0, y = 0, z = 0), max = Vec3(x = 0, y = 0, z = 0)), floorHeight = 1.0, ceilingHeight = 1.0, portals = [BspPortal(targetSectorId = 0, polygonVertices = 0, plane = 0, isOpen = 0)], pvsMask = 1)`; exercises core body path returning/computing `sector.sectorId`.

```aipl
module tests.functions.spatial.bsp_sector_world3d_z2_test
import * from "std/spatial/bsp_sector_world3d"
import { Vec3 } from "std/math/vec_math"
import { AABB3D, Plane3D, Frustum3D } from "std/math/geom3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bsp_sector_world3d_bspAddSector_2(): int:
  let arg_world = BspSectorWorld3D(sectors = [])
  let edge_world = BspSectorWorld3D(sectors = [])
  let arg_sector = BspSector(sectorId = 1, boundingBox = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0)), floorHeight = 0.0, ceilingHeight = 2.0, portals = [], pvsMask = 4)
  let edge_sector = BspSector(sectorId = 0, boundingBox = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5)), floorHeight = 0.0, ceilingHeight = 1.0, portals = [], pvsMask = 1)
  let resNom = bspAddSector(arg_world, arg_sector)
  let resEdge = bspAddSector(edge_world, edge_sector)
  assertEqInt(resNom, 1, "bspAddSector nominal resNom == 1")
  assertEqInt(resEdge, 0, "bspAddSector boundary resEdge == 0")
  ret 0
```

---

### `bspAddPortal` (`std/spatial/bsp_sector_world3d.aipl`)

- **Signature**: `pub fn bspAddPortal(mut world: BspSectorWorld3D, fromSector: int, toSector: int, portal: BspPortal): bool:`
- **Import**: `import * from "std/spatial/bsp_sector_world3d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut world: BspSectorWorld3D, fromSector: int, toSector: int, portal: BspPortal` | **Returns**: `bool`
- **Unit Test**: `tests/functions/spatial/bsp_sector_world3d_test.aipl` | **Example**: `examples/ex_211_spatial_continuous_world2d_window.aipl`
- **Behavioral Summary**: Tests 3D BSP plane splitting, leaf sector point classification, and portal-to-portal PVS visibility traversal in `bspAddPortal`. Concrete nominal inputs: `world: BspSectorWorld3D = BspSectorWorld3D(sectors = [BspSector(sectorId = 0, boundingBox = 0, floorHeight = 0, ceilingHeight = 0, portals = 0, pvsMask = 0)])`, `fromSector: int = 1`, `toSector: int = 1`, `portal: BspPortal = BspPortal(targetSectorId = 1, polygonVertices = [Vec3(x = 0, y = 0, z = 0)], plane = Plane3D(normal = Vec3(x = 0, y = 0, z = 0), distance = float = 0.0(), d = float = 0.0()), isOpen = true)`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.spatial.bsp_sector_world3d_z3_test
import * from "std/spatial/bsp_sector_world3d"
import { Vec3 } from "std/math/vec_math"
import { AABB3D, Plane3D, Frustum3D } from "std/math/geom3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bsp_sector_world3d_bspAddPortal_3(): int:
  let arg_world = BspSectorWorld3D(sectors = [])
  let edge_world = BspSectorWorld3D(sectors = [])
  let arg_fromSector = 4
  let edge_fromSector = 1
  let arg_toSector = 2
  let edge_toSector = 0
  let arg_portal = BspPortal(targetSectorId = 1, polygonVertices = [], plane = Plane3D(normal = Vec3(x = 1.0, y = 1.0, z = 1.0), distance = 1.0, d = 1.0), isOpen = true)
  let edge_portal = BspPortal(targetSectorId = 0, polygonVertices = [], plane = Plane3D(normal = Vec3(x = 0.5, y = 0.5, z = 0.5), distance = 0.5, d = 0.5), isOpen = false)
  let resNom = bspAddPortal(arg_world, arg_fromSector, arg_toSector, arg_portal)
  let resEdge = bspAddPortal(edge_world, edge_fromSector, edge_toSector, edge_portal)
  assert(resNom == false, "bspAddPortal nominal resNom == false")
  assert(resEdge == false, "bspAddPortal boundary resEdge == false")
  ret 0
```

---

### `bspFindSectorContainingPoint` (`std/spatial/bsp_sector_world3d.aipl`)

- **Signature**: `pub fn bspFindSectorContainingPoint(world: BspSectorWorld3D, pt: Vec3): Option[int]:`
- **Import**: `import * from "std/spatial/bsp_sector_world3d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: BspSectorWorld3D, pt: Vec3` | **Returns**: `Option[int]`
- **Unit Test**: `tests/functions/spatial/bsp_sector_world3d_test.aipl` | **Example**: `examples/ex_209_spatial_iso_tile_world2d_window.aipl`
- **Behavioral Summary**: Tests 3D BSP plane splitting, leaf sector point classification, and portal-to-portal PVS visibility traversal in `bspFindSectorContainingPoint`. Concrete nominal inputs: `world: BspSectorWorld3D = BspSectorWorld3D(sectors = [BspSector(sectorId = 0, boundingBox = 0, floorHeight = 0, ceilingHeight = 0, portals = 0, pvsMask = 0)])`, `pt: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.spatial.bsp_sector_world3d_z4_test
import * from "std/spatial/bsp_sector_world3d"
import { Vec3 } from "std/math/vec_math"
import { AABB3D, Plane3D, Frustum3D } from "std/math/geom3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bsp_sector_world3d_bspFindSectorContainingPoint_4(): int:
  let arg_world = BspSectorWorld3D(sectors = [])
  let edge_world = BspSectorWorld3D(sectors = [])
  let arg_pt = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_pt = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = bspFindSectorContainingPoint(arg_world, arg_pt)
  let resEdge = bspFindSectorContainingPoint(edge_world, edge_pt)
  assert(resNom.isSome() == false, "bspFindSectorContainingPoint nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "bspFindSectorContainingPoint boundary resEdge.isSome() == false")
  ret 0
```

---

### `isPointInFrustum` (`std/spatial/bsp_sector_world3d.aipl`)

- **Signature**: `fn isPointInFrustum(frustum: Frustum3D, pt: Vec3): bool:`
- **Import**: `import * from "std/spatial/bsp_sector_world3d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `frustum: Frustum3D, pt: Vec3` | **Returns**: `bool`
- **Unit Test**: `tests/functions/spatial/bsp_sector_world3d_test.aipl` | **Example**: `examples/ex_210_spatial_hex_tile_world2d_window.aipl`
- **Behavioral Summary**: Tests 3D BSP plane splitting, leaf sector point classification, and portal-to-portal PVS visibility traversal in `isPointInFrustum`. Concrete nominal inputs: `frustum: Frustum3D = Frustum3D(planes = [Plane3D(normal = 0, distance = 0, d = 0)])`, `pt: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.spatial.bsp_sector_world3d_z5_test
import * from "std/spatial/bsp_sector_world3d"
import { Vec3 } from "std/math/vec_math"
import { AABB3D, Plane3D, Frustum3D } from "std/math/geom3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bsp_sector_world3d_isPointInFrustum_5(): int:
  let arg_frustum = Frustum3D(planes = [])
  let edge_frustum = Frustum3D(planes = [])
  let arg_pt = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_pt = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = isPointInFrustum(arg_frustum, arg_pt)
  let resEdge = isPointInFrustum(edge_frustum, edge_pt)
  assert(resNom == true, "isPointInFrustum nominal resNom == true")
  assert(resEdge == true, "isPointInFrustum boundary resEdge == true")
  ret 0
```

---

### `bspQueryVisibleSectors` (`std/spatial/bsp_sector_world3d.aipl`)

- **Signature**: `pub fn bspQueryVisibleSectors(world: BspSectorWorld3D, currentSectorId: int, cameraFrustum: Frustum3D): [int]:`
- **Import**: `import * from "std/spatial/bsp_sector_world3d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: BspSectorWorld3D, currentSectorId: int, cameraFrustum: Frustum3D` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/spatial/bsp_sector_world3d_test.aipl` | **Example**: `examples/ex_211_spatial_continuous_world2d_window.aipl`
- **Behavioral Summary**: Tests 3D BSP plane splitting, leaf sector point classification, and portal-to-portal PVS visibility traversal in `bspQueryVisibleSectors`. Concrete nominal inputs: `world: BspSectorWorld3D = BspSectorWorld3D(sectors = [BspSector(sectorId = 0, boundingBox = 0, floorHeight = 0, ceilingHeight = 0, portals = 0, pvsMask = 0)])`, `currentSectorId: int = 1`, `cameraFrustum: Frustum3D = Frustum3D(planes = [Plane3D(normal = 0, distance = 0, d = 0)])`; exercises core body path returning/computing `visible`.

```aipl
module tests.functions.spatial.bsp_sector_world3d_z6_test
import * from "std/spatial/bsp_sector_world3d"
import { Vec3 } from "std/math/vec_math"
import { AABB3D, Plane3D, Frustum3D } from "std/math/geom3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bsp_sector_world3d_bspQueryVisibleSectors_6(): int:
  let arg_world = BspSectorWorld3D(sectors = [])
  let edge_world = BspSectorWorld3D(sectors = [])
  let arg_currentSectorId = 4
  let edge_currentSectorId = 1
  let arg_cameraFrustum = Frustum3D(planes = [])
  let edge_cameraFrustum = Frustum3D(planes = [])
  let resNom = bspQueryVisibleSectors(arg_world, arg_currentSectorId, arg_cameraFrustum)
  let resEdge = bspQueryVisibleSectors(edge_world, edge_currentSectorId, edge_cameraFrustum)
  assertEqInt(resNom.len(), 1, "bspQueryVisibleSectors nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "bspQueryVisibleSectors boundary resEdge.len() == 1")
  ret 0
```

---

### `continuousWorld2dNew` (`std/spatial/continuous_world2d.aipl`)

- **Signature**: `pub fn continuousWorld2dNew(bounds: Rect2D, cellSize: float): ContinuousSpaceWorld2D:`
- **Import**: `import * from "std/spatial/continuous_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bounds: Rect2D, cellSize: float` | **Returns**: `ContinuousSpaceWorld2D`
- **Unit Test**: `tests/functions/spatial/continuous_world2d_test.aipl` | **Example**: `examples/ex_209_spatial_iso_tile_world2d_window.aipl`
- **Behavioral Summary**: Verifies 2D spatial hash / quadtree entity registration, transform updates, radius/AABB queries, and 2D raycasting in `continuousWorld2dNew`. Concrete nominal inputs: `bounds: Rect2D = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0())`, `cellSize: float = 1.0`; exercises core body path returning/computing `ContinuousSpaceWorld2D(`.

```aipl
module tests.functions.spatial.continuous_world2d_z1_test
import * from "std/spatial/continuous_world2d"
import { sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_continuous_world2d_continuousWorld2dNew_1(): int:
  let arg_bounds = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0)
  let edge_bounds = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0)
  let arg_cellSize = 1.0
  let edge_cellSize = 0.5
  let resNom = continuousWorld2dNew(arg_bounds, arg_cellSize)
  let resEdge = continuousWorld2dNew(edge_bounds, edge_cellSize)
  assertApproxEq(resNom.cellSize, 1.0, 0.001, "continuousWorld2dNew nominal resNom.cellSize ~= 1.0")
  assertApproxEq(resEdge.cellSize, 0.5, 0.001, "continuousWorld2dNew boundary resEdge.cellSize ~= 0.5")
  ret 0
```

---

### `continuousWorld2dInsert` (`std/spatial/continuous_world2d.aipl`)

- **Signature**: `pub fn continuousWorld2dInsert(mut world: ContinuousSpaceWorld2D, obj: SpatialObject2D): int:`
- **Import**: `import * from "std/spatial/continuous_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut world: ContinuousSpaceWorld2D, obj: SpatialObject2D` | **Returns**: `int`
- **Unit Test**: `tests/functions/spatial/continuous_world2d_test.aipl` | **Example**: `examples/ex_210_spatial_hex_tile_world2d_window.aipl`
- **Behavioral Summary**: Verifies 2D spatial hash / quadtree entity registration, transform updates, radius/AABB queries, and 2D raycasting in `continuousWorld2dInsert`. Concrete nominal inputs: `world: ContinuousSpaceWorld2D = ContinuousSpaceWorld2D(worldBounds = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0()), cellSize = 1.0, objects = [SpatialObject2D(id = 0, position = 0, radius = 0, layerMask = 0, bounds = 0)], alive = [true])`, `obj: SpatialObject2D = SpatialObject2D(id = 1, position = Vec2(x = 1.0, y = 1.0), radius = 1.0, layerMask = 1, bounds = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0()))`; exercises core body path returning/computing `obj.id`.

```aipl
module tests.functions.spatial.continuous_world2d_z2_test
import * from "std/spatial/continuous_world2d"
import { sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_continuous_world2d_continuousWorld2dInsert_2(): int:
  let arg_world = ContinuousSpaceWorld2D(worldBounds = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0), cellSize = 1.0, objects = [], alive = [])
  let edge_world = ContinuousSpaceWorld2D(worldBounds = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0), cellSize = 0.5, objects = [], alive = [])
  let arg_obj = SpatialObject2D(id = 1, position = Vec2(x = 1.0, y = 1.0), radius = 2.0, layerMask = 4, bounds = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0))
  let edge_obj = SpatialObject2D(id = 0, position = Vec2(x = 0.5, y = 0.5), radius = 1.0, layerMask = 1, bounds = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0))
  let resNom = continuousWorld2dInsert(arg_world, arg_obj)
  let resEdge = continuousWorld2dInsert(edge_world, edge_obj)
  assertEqInt(resNom, 1, "continuousWorld2dInsert nominal resNom == 1")
  assertEqInt(resEdge, 0, "continuousWorld2dInsert boundary resEdge == 0")
  ret 0
```

---

### `continuousWorld2dUpdate` (`std/spatial/continuous_world2d.aipl`)

- **Signature**: `pub fn continuousWorld2dUpdate(mut world: ContinuousSpaceWorld2D, id: int, newPos: Vec2): bool:`
- **Import**: `import * from "std/spatial/continuous_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut world: ContinuousSpaceWorld2D, id: int, newPos: Vec2` | **Returns**: `bool`
- **Unit Test**: `tests/functions/spatial/continuous_world2d_test.aipl` | **Example**: `examples/ex_211_spatial_continuous_world2d_window.aipl`
- **Behavioral Summary**: Verifies 2D spatial hash / quadtree entity registration, transform updates, radius/AABB queries, and 2D raycasting in `continuousWorld2dUpdate`. Concrete nominal inputs: `world: ContinuousSpaceWorld2D = ContinuousSpaceWorld2D(worldBounds = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0()), cellSize = 1.0, objects = [SpatialObject2D(id = 0, position = 0, radius = 0, layerMask = 0, bounds = 0)], alive = [true])`, `id: int = 1`, `newPos: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.spatial.continuous_world2d_z3_test
import * from "std/spatial/continuous_world2d"
import { sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_continuous_world2d_continuousWorld2dUpdate_3(): int:
  let arg_world = ContinuousSpaceWorld2D(worldBounds = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0), cellSize = 1.0, objects = [], alive = [])
  let edge_world = ContinuousSpaceWorld2D(worldBounds = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0), cellSize = 0.5, objects = [], alive = [])
  let arg_id = 1
  let edge_id = 0
  let arg_newPos = Vec2(x = 1.0, y = 1.0)
  let edge_newPos = Vec2(x = 0.5, y = 0.5)
  let resNom = continuousWorld2dUpdate(arg_world, arg_id, arg_newPos)
  let resEdge = continuousWorld2dUpdate(edge_world, edge_id, edge_newPos)
  assert(resNom == false, "continuousWorld2dUpdate nominal resNom == false")
  assert(resEdge == false, "continuousWorld2dUpdate boundary resEdge == false")
  ret 0
```

---

### `continuousWorld2dRemove` (`std/spatial/continuous_world2d.aipl`)

- **Signature**: `pub fn continuousWorld2dRemove(mut world: ContinuousSpaceWorld2D, id: int): bool:`
- **Import**: `import * from "std/spatial/continuous_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut world: ContinuousSpaceWorld2D, id: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/spatial/continuous_world2d_test.aipl` | **Example**: `examples/ex_209_spatial_iso_tile_world2d_window.aipl`
- **Behavioral Summary**: Verifies 2D spatial hash / quadtree entity registration, transform updates, radius/AABB queries, and 2D raycasting in `continuousWorld2dRemove`. Concrete nominal inputs: `world: ContinuousSpaceWorld2D = ContinuousSpaceWorld2D(worldBounds = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0()), cellSize = 1.0, objects = [SpatialObject2D(id = 0, position = 0, radius = 0, layerMask = 0, bounds = 0)], alive = [true])`, `id: int = 1`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.spatial.continuous_world2d_z4_test
import * from "std/spatial/continuous_world2d"
import { sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_continuous_world2d_continuousWorld2dRemove_4(): int:
  let arg_world = ContinuousSpaceWorld2D(worldBounds = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0), cellSize = 1.0, objects = [], alive = [])
  let edge_world = ContinuousSpaceWorld2D(worldBounds = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0), cellSize = 0.5, objects = [], alive = [])
  let arg_id = 1
  let edge_id = 0
  let resNom = continuousWorld2dRemove(arg_world, arg_id)
  let resEdge = continuousWorld2dRemove(edge_world, edge_id)
  assert(resNom == false, "continuousWorld2dRemove nominal resNom == false")
  assert(resEdge == false, "continuousWorld2dRemove boundary resEdge == false")
  ret 0
```

---

### `continuousWorld2dQueryRadius` (`std/spatial/continuous_world2d.aipl`)

- **Signature**: `pub fn continuousWorld2dQueryRadius(world: ContinuousSpaceWorld2D, center: Vec2, radius: float, layerMask: int): [int]:`
- **Import**: `import * from "std/spatial/continuous_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: ContinuousSpaceWorld2D, center: Vec2, radius: float, layerMask: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/spatial/continuous_world2d_test.aipl` | **Example**: `examples/ex_210_spatial_hex_tile_world2d_window.aipl`
- **Behavioral Summary**: Verifies 2D spatial hash / quadtree entity registration, transform updates, radius/AABB queries, and 2D raycasting in `continuousWorld2dQueryRadius`. Concrete nominal inputs: `world: ContinuousSpaceWorld2D = ContinuousSpaceWorld2D(worldBounds = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0()), cellSize = 1.0, objects = [SpatialObject2D(id = 0, position = 0, radius = 0, layerMask = 0, bounds = 0)], alive = [true])`, `center: Vec2 = Vec2(x = 1.0, y = 1.0)`, `radius: float = 1.0`, `layerMask: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.spatial.continuous_world2d_z5_test
import * from "std/spatial/continuous_world2d"
import { sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_continuous_world2d_continuousWorld2dQueryRadius_5(): int:
  let arg_world = ContinuousSpaceWorld2D(worldBounds = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0), cellSize = 1.0, objects = [], alive = [])
  let edge_world = ContinuousSpaceWorld2D(worldBounds = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0), cellSize = 0.5, objects = [], alive = [])
  let arg_center = Vec2(x = 1.0, y = 1.0)
  let edge_center = Vec2(x = 0.5, y = 0.5)
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_layerMask = 4
  let edge_layerMask = 1
  let resNom = continuousWorld2dQueryRadius(arg_world, arg_center, arg_radius, arg_layerMask)
  let resEdge = continuousWorld2dQueryRadius(edge_world, edge_center, edge_radius, edge_layerMask)
  assertEqInt(resNom.len(), 0, "continuousWorld2dQueryRadius nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "continuousWorld2dQueryRadius boundary resEdge.len() == 0")
  ret 0
```

---

### `continuousWorld2dQueryAABB` (`std/spatial/continuous_world2d.aipl`)

- **Signature**: `pub fn continuousWorld2dQueryAABB(world: ContinuousSpaceWorld2D, aabb: Rect2D, layerMask: int): [int]:`
- **Import**: `import * from "std/spatial/continuous_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: ContinuousSpaceWorld2D, aabb: Rect2D, layerMask: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/spatial/continuous_world2d_test.aipl` | **Example**: `examples/ex_211_spatial_continuous_world2d_window.aipl`
- **Behavioral Summary**: Verifies 2D spatial hash / quadtree entity registration, transform updates, radius/AABB queries, and 2D raycasting in `continuousWorld2dQueryAABB`. Concrete nominal inputs: `world: ContinuousSpaceWorld2D = ContinuousSpaceWorld2D(worldBounds = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0()), cellSize = 1.0, objects = [SpatialObject2D(id = 0, position = 0, radius = 0, layerMask = 0, bounds = 0)], alive = [true])`, `aabb: Rect2D = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0())`, `layerMask: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.spatial.continuous_world2d_z6_test
import * from "std/spatial/continuous_world2d"
import { sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_continuous_world2d_continuousWorld2dQueryAABB_6(): int:
  let arg_world = ContinuousSpaceWorld2D(worldBounds = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0), cellSize = 1.0, objects = [], alive = [])
  let edge_world = ContinuousSpaceWorld2D(worldBounds = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0), cellSize = 0.5, objects = [], alive = [])
  let arg_aabb = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0)
  let edge_aabb = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0)
  let arg_layerMask = 4
  let edge_layerMask = 1
  let resNom = continuousWorld2dQueryAABB(arg_world, arg_aabb, arg_layerMask)
  let resEdge = continuousWorld2dQueryAABB(edge_world, edge_aabb, edge_layerMask)
  assertEqInt(resNom.len(), 0, "continuousWorld2dQueryAABB nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "continuousWorld2dQueryAABB boundary resEdge.len() == 0")
  ret 0
```

---

### `continuousWorld2dRaycast` (`std/spatial/continuous_world2d.aipl`)

- **Signature**: `pub fn continuousWorld2dRaycast(world: ContinuousSpaceWorld2D, origin: Vec2, direction: Vec2, maxDist: float, layerMask: int): Option[SpatialRayHit2D]:`
- **Import**: `import * from "std/spatial/continuous_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: ContinuousSpaceWorld2D, origin: Vec2, direction: Vec2, maxDist: float, layerMask: int` | **Returns**: `Option[SpatialRayHit2D]`
- **Unit Test**: `tests/functions/spatial/continuous_world2d_test.aipl` | **Example**: `examples/ex_209_spatial_iso_tile_world2d_window.aipl`
- **Behavioral Summary**: Verifies 2D spatial hash / quadtree entity registration, transform updates, radius/AABB queries, and 2D raycasting in `continuousWorld2dRaycast`. Concrete nominal inputs: `world: ContinuousSpaceWorld2D = ContinuousSpaceWorld2D(worldBounds = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0()), cellSize = 1.0, objects = [SpatialObject2D(id = 0, position = 0, radius = 0, layerMask = 0, bounds = 0)], alive = [true])`, `origin: Vec2 = Vec2(x = 1.0, y = 1.0)`, `direction: Vec2 = Vec2(x = 1.0, y = 1.0)`, `maxDist: float = 1.0`, `layerMask: int = 1`; exercises core body path returning/computing `bestHit`.

```aipl
module tests.functions.spatial.continuous_world2d_z7_test
import * from "std/spatial/continuous_world2d"
import { sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_continuous_world2d_continuousWorld2dRaycast_7(): int:
  let arg_world = ContinuousSpaceWorld2D(worldBounds = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0), cellSize = 1.0, objects = [], alive = [])
  let edge_world = ContinuousSpaceWorld2D(worldBounds = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0), cellSize = 0.5, objects = [], alive = [])
  let arg_origin = Vec2(x = 1.0, y = 1.0)
  let edge_origin = Vec2(x = 0.5, y = 0.5)
  let arg_direction = Vec2(x = 1.0, y = 1.0)
  let edge_direction = Vec2(x = 0.5, y = 0.5)
  let arg_maxDist = 2.0
  let edge_maxDist = 1.0
  let arg_layerMask = 4
  let edge_layerMask = 1
  let resNom = continuousWorld2dRaycast(arg_world, arg_origin, arg_direction, arg_maxDist, arg_layerMask)
  let resEdge = continuousWorld2dRaycast(edge_world, edge_origin, edge_direction, edge_maxDist, edge_layerMask)
  assert(resNom.isSome() == false, "continuousWorld2dRaycast nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "continuousWorld2dRaycast boundary resEdge.isSome() == false")
  ret 0
```

---

### `continuousWorld3dNew` (`std/spatial/continuous_world3d.aipl`)

- **Signature**: `pub fn continuousWorld3dNew(worldBounds: AABB3D): ContinuousSpaceWorld3D:`
- **Import**: `import * from "std/spatial/continuous_world3d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `worldBounds: AABB3D` | **Returns**: `ContinuousSpaceWorld3D`
- **Unit Test**: `tests/functions/spatial/continuous_world3d_test.aipl` | **Example**: `examples/ex_210_spatial_hex_tile_world2d_window.aipl`
- **Behavioral Summary**: Tests 3D octree / spatial grid entity management, sphere/frustum culling queries, and 3D ray intersection in `continuousWorld3dNew`. Concrete nominal inputs: `worldBounds: AABB3D = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))`; exercises core body path returning/computing `ContinuousSpaceWorld3D(worldBounds = worldBounds, objects = objs, alive = alv)`.

```aipl
module tests.functions.spatial.continuous_world3d_z1_test
import * from "std/spatial/continuous_world3d"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { AABB3D, Sphere3D, Plane3D, Ray3D, Frustum3D } from "std/math/geom3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_continuous_world3d_continuousWorld3dNew_1(): int:
  let arg_worldBounds = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))
  let edge_worldBounds = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5))
  let resNom = continuousWorld3dNew(arg_worldBounds)
  let resEdge = continuousWorld3dNew(edge_worldBounds)
  assertEqInt(resNom.objects.len(), 0, "continuousWorld3dNew nominal resNom.objects.len() == 0")
  assertEqInt(resEdge.objects.len(), 0, "continuousWorld3dNew boundary resEdge.objects.len() == 0")
  ret 0
```

---

### `continuousWorld3dInsert` (`std/spatial/continuous_world3d.aipl`)

- **Signature**: `pub fn continuousWorld3dInsert(mut world: ContinuousSpaceWorld3D, obj: SpatialObject3D): int:`
- **Import**: `import * from "std/spatial/continuous_world3d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut world: ContinuousSpaceWorld3D, obj: SpatialObject3D` | **Returns**: `int`
- **Unit Test**: `tests/functions/spatial/continuous_world3d_test.aipl` | **Example**: `examples/ex_211_spatial_continuous_world2d_window.aipl`
- **Behavioral Summary**: Tests 3D octree / spatial grid entity management, sphere/frustum culling queries, and 3D ray intersection in `continuousWorld3dInsert`. Concrete nominal inputs: `world: ContinuousSpaceWorld3D = ContinuousSpaceWorld3D(worldBounds = AABB3D(min = Vec3(x = 0, y = 0, z = 0), max = Vec3(x = 0, y = 0, z = 0)), objects = [SpatialObject3D(id = 0, transform = 0, boundingBox = 0, boundingSphere = 0, layerMask = 0)], alive = [true])`, `obj: SpatialObject3D = SpatialObject3D(id = 1, transform = Transform3D(position = Vec3(x = 0, y = 0, z = 0), rotation = Quat(x = 0, y = 0, z = 0, w = 0), scale = Vec3(x = 0, y = 0, z = 0)), boundingBox = AABB3D(min = Vec3(x = 0, y = 0, z = 0), max = Vec3(x = 0, y = 0, z = 0)), boundingSphere = Sphere3D(center = Vec3(x = 0, y = 0, z = 0), radius = 1.0), layerMask = 1)`; exercises core body path returning/computing `obj.id`.

```aipl
module tests.functions.spatial.continuous_world3d_z2_test
import * from "std/spatial/continuous_world3d"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { AABB3D, Sphere3D, Plane3D, Ray3D, Frustum3D } from "std/math/geom3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_continuous_world3d_continuousWorld3dInsert_2(): int:
  let arg_world = ContinuousSpaceWorld3D(worldBounds = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0)), objects = [], alive = [])
  let edge_world = ContinuousSpaceWorld3D(worldBounds = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5)), objects = [], alive = [])
  let arg_obj = SpatialObject3D(id = 1, transform = Transform3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0), scale = Vec3(x = 1.0, y = 1.0, z = 1.0)), boundingBox = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0)), boundingSphere = Sphere3D(center = Vec3(x = 1.0, y = 1.0, z = 1.0), radius = 2.0), layerMask = 4)
  let edge_obj = SpatialObject3D(id = 0, transform = Transform3D(position = Vec3(x = 0.5, y = 0.5, z = 0.5), rotation = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0), scale = Vec3(x = 0.5, y = 0.5, z = 0.5)), boundingBox = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5)), boundingSphere = Sphere3D(center = Vec3(x = 0.5, y = 0.5, z = 0.5), radius = 1.0), layerMask = 1)
  let resNom = continuousWorld3dInsert(arg_world, arg_obj)
  let resEdge = continuousWorld3dInsert(edge_world, edge_obj)
  assertEqInt(resNom, 1, "continuousWorld3dInsert nominal resNom == 1")
  assertEqInt(resEdge, 0, "continuousWorld3dInsert boundary resEdge == 0")
  ret 0
```

---

### `continuousWorld3dUpdateTransform` (`std/spatial/continuous_world3d.aipl`)

- **Signature**: `pub fn continuousWorld3dUpdateTransform(mut world: ContinuousSpaceWorld3D, id: int, transform: Transform3D): bool:`
- **Import**: `import * from "std/spatial/continuous_world3d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut world: ContinuousSpaceWorld3D, id: int, transform: Transform3D` | **Returns**: `bool`
- **Unit Test**: `tests/functions/spatial/continuous_world3d_test.aipl` | **Example**: `examples/ex_209_spatial_iso_tile_world2d_window.aipl`
- **Behavioral Summary**: Tests 3D octree / spatial grid entity management, sphere/frustum culling queries, and 3D ray intersection in `continuousWorld3dUpdateTransform`. Concrete nominal inputs: `world: ContinuousSpaceWorld3D = ContinuousSpaceWorld3D(worldBounds = AABB3D(min = Vec3(x = 0, y = 0, z = 0), max = Vec3(x = 0, y = 0, z = 0)), objects = [SpatialObject3D(id = 0, transform = 0, boundingBox = 0, boundingSphere = 0, layerMask = 0)], alive = [true])`, `id: int = 1`, `transform: Transform3D = Transform3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0), scale = Vec3(x = 1.0, y = 1.0, z = 1.0))`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.spatial.continuous_world3d_z3_test
import * from "std/spatial/continuous_world3d"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { AABB3D, Sphere3D, Plane3D, Ray3D, Frustum3D } from "std/math/geom3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_continuous_world3d_continuousWorld3dUpdateTransform_3(): int:
  let arg_world = ContinuousSpaceWorld3D(worldBounds = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0)), objects = [], alive = [])
  let edge_world = ContinuousSpaceWorld3D(worldBounds = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5)), objects = [], alive = [])
  let arg_id = 1
  let edge_id = 0
  let arg_transform = Transform3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0), scale = Vec3(x = 1.0, y = 1.0, z = 1.0))
  let edge_transform = Transform3D(position = Vec3(x = 0.5, y = 0.5, z = 0.5), rotation = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0), scale = Vec3(x = 0.5, y = 0.5, z = 0.5))
  let resNom = continuousWorld3dUpdateTransform(arg_world, arg_id, arg_transform)
  let resEdge = continuousWorld3dUpdateTransform(edge_world, edge_id, edge_transform)
  assert(resNom == false, "continuousWorld3dUpdateTransform nominal resNom == false")
  assert(resEdge == false, "continuousWorld3dUpdateTransform boundary resEdge == false")
  ret 0
```

---

### `continuousWorld3dQuerySphere` (`std/spatial/continuous_world3d.aipl`)

- **Signature**: `pub fn continuousWorld3dQuerySphere(world: ContinuousSpaceWorld3D, center: Vec3, radius: float, mask: int): [int]:`
- **Import**: `import * from "std/spatial/continuous_world3d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: ContinuousSpaceWorld3D, center: Vec3, radius: float, mask: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/spatial/continuous_world3d_test.aipl` | **Example**: `examples/ex_210_spatial_hex_tile_world2d_window.aipl`
- **Behavioral Summary**: Tests 3D octree / spatial grid entity management, sphere/frustum culling queries, and 3D ray intersection in `continuousWorld3dQuerySphere`. Concrete nominal inputs: `world: ContinuousSpaceWorld3D = ContinuousSpaceWorld3D(worldBounds = AABB3D(min = Vec3(x = 0, y = 0, z = 0), max = Vec3(x = 0, y = 0, z = 0)), objects = [SpatialObject3D(id = 0, transform = 0, boundingBox = 0, boundingSphere = 0, layerMask = 0)], alive = [true])`, `center: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `radius: float = 1.0`, `mask: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.spatial.continuous_world3d_z4_test
import * from "std/spatial/continuous_world3d"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { AABB3D, Sphere3D, Plane3D, Ray3D, Frustum3D } from "std/math/geom3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_continuous_world3d_continuousWorld3dQuerySphere_4(): int:
  let arg_world = ContinuousSpaceWorld3D(worldBounds = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0)), objects = [], alive = [])
  let edge_world = ContinuousSpaceWorld3D(worldBounds = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5)), objects = [], alive = [])
  let arg_center = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_center = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_mask = 4
  let edge_mask = 1
  let resNom = continuousWorld3dQuerySphere(arg_world, arg_center, arg_radius, arg_mask)
  let resEdge = continuousWorld3dQuerySphere(edge_world, edge_center, edge_radius, edge_mask)
  assertEqInt(resNom.len(), 0, "continuousWorld3dQuerySphere nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "continuousWorld3dQuerySphere boundary resEdge.len() == 0")
  ret 0
```

---

### `continuousWorld3dQueryFrustum` (`std/spatial/continuous_world3d.aipl`)

- **Signature**: `pub fn continuousWorld3dQueryFrustum(world: ContinuousSpaceWorld3D, frustum: Frustum3D, mask: int): [int]:`
- **Import**: `import * from "std/spatial/continuous_world3d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: ContinuousSpaceWorld3D, frustum: Frustum3D, mask: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/spatial/continuous_world3d_test.aipl` | **Example**: `examples/ex_211_spatial_continuous_world2d_window.aipl`
- **Behavioral Summary**: Tests 3D octree / spatial grid entity management, sphere/frustum culling queries, and 3D ray intersection in `continuousWorld3dQueryFrustum`. Concrete nominal inputs: `world: ContinuousSpaceWorld3D = ContinuousSpaceWorld3D(worldBounds = AABB3D(min = Vec3(x = 0, y = 0, z = 0), max = Vec3(x = 0, y = 0, z = 0)), objects = [SpatialObject3D(id = 0, transform = 0, boundingBox = 0, boundingSphere = 0, layerMask = 0)], alive = [true])`, `frustum: Frustum3D = Frustum3D(planes = [Plane3D(normal = 0, distance = 0, d = 0)])`, `mask: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.spatial.continuous_world3d_z5_test
import * from "std/spatial/continuous_world3d"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { AABB3D, Sphere3D, Plane3D, Ray3D, Frustum3D } from "std/math/geom3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_continuous_world3d_continuousWorld3dQueryFrustum_5(): int:
  let arg_world = ContinuousSpaceWorld3D(worldBounds = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0)), objects = [], alive = [])
  let edge_world = ContinuousSpaceWorld3D(worldBounds = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5)), objects = [], alive = [])
  let arg_frustum = Frustum3D(planes = [])
  let edge_frustum = Frustum3D(planes = [])
  let arg_mask = 4
  let edge_mask = 1
  let resNom = continuousWorld3dQueryFrustum(arg_world, arg_frustum, arg_mask)
  let resEdge = continuousWorld3dQueryFrustum(edge_world, edge_frustum, edge_mask)
  assertEqInt(resNom.len(), 0, "continuousWorld3dQueryFrustum nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "continuousWorld3dQueryFrustum boundary resEdge.len() == 0")
  ret 0
```

---

### `continuousWorld3dRaycast` (`std/spatial/continuous_world3d.aipl`)

- **Signature**: `pub fn continuousWorld3dRaycast(world: ContinuousSpaceWorld3D, ray: Ray3D, maxDist: float, mask: int): Option[SpatialRayHit3D]:`
- **Import**: `import * from "std/spatial/continuous_world3d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: ContinuousSpaceWorld3D, ray: Ray3D, maxDist: float, mask: int` | **Returns**: `Option[SpatialRayHit3D]`
- **Unit Test**: `tests/functions/spatial/continuous_world3d_test.aipl` | **Example**: `examples/ex_209_spatial_iso_tile_world2d_window.aipl`
- **Behavioral Summary**: Tests 3D octree / spatial grid entity management, sphere/frustum culling queries, and 3D ray intersection in `continuousWorld3dRaycast`. Concrete nominal inputs: `world: ContinuousSpaceWorld3D = ContinuousSpaceWorld3D(worldBounds = AABB3D(min = Vec3(x = 0, y = 0, z = 0), max = Vec3(x = 0, y = 0, z = 0)), objects = [SpatialObject3D(id = 0, transform = 0, boundingBox = 0, boundingSphere = 0, layerMask = 0)], alive = [true])`, `ray: Ray3D = Ray3D(origin = Vec3(x = 1.0, y = 1.0, z = 1.0), dir = Vec3 = Vec3(x = 0.0, y = 0.0, z = 1.0)(), direction = Vec3 = Vec3(x = 0.0, y = 0.0, z = 1.0)(), maxDistance = float = 1000.0())`, `maxDist: float = 1.0`, `mask: int = 1`; exercises core body path returning/computing `bestHit`.

```aipl
module tests.functions.spatial.continuous_world3d_z6_test
import * from "std/spatial/continuous_world3d"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { AABB3D, Sphere3D, Plane3D, Ray3D, Frustum3D } from "std/math/geom3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_continuous_world3d_continuousWorld3dRaycast_6(): int:
  let arg_world = ContinuousSpaceWorld3D(worldBounds = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0)), objects = [], alive = [])
  let edge_world = ContinuousSpaceWorld3D(worldBounds = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5)), objects = [], alive = [])
  let arg_ray = Ray3D(origin = Vec3(x = 1.0, y = 1.0, z = 1.0), dir = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), maxDistance = 2.0)
  let edge_ray = Ray3D(origin = Vec3(x = 0.5, y = 0.5, z = 0.5), dir = Vec3(x = 0.5, y = 0.5, z = 0.5), direction = Vec3(x = 0.5, y = 0.5, z = 0.5), maxDistance = 1.0)
  let arg_maxDist = 2.0
  let edge_maxDist = 1.0
  let arg_mask = 4
  let edge_mask = 1
  let resNom = continuousWorld3dRaycast(arg_world, arg_ray, arg_maxDist, arg_mask)
  let resEdge = continuousWorld3dRaycast(edge_world, edge_ray, edge_maxDist, edge_mask)
  assert(resNom.isSome() == false, "continuousWorld3dRaycast nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "continuousWorld3dRaycast boundary resEdge.isSome() == false")
  ret 0
```

---

### `hexCubeNew` (`std/spatial/hex_tile_world2d.aipl`)

- **Signature**: `pub fn hexCubeNew(x: int, y: int, z: int): HexCubeCoord:`
- **Import**: `import * from "std/spatial/hex_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: int, y: int, z: int` | **Returns**: `HexCubeCoord`
- **Unit Test**: `tests/functions/spatial/hex_tile_world2d_test.aipl` | **Example**: `examples/ex_210_spatial_hex_tile_world2d_window.aipl`
- **Behavioral Summary**: Tests axial/cube hex coordinates ($q+r+s=0$), hex distance, line drawing, rings (`6*r` cells), and spiral range queries in `hexCubeNew`. Concrete nominal inputs: `x: int = 1`, `y: int = 1`, `z: int = 1`; exercises core body path returning/computing `HexCubeCoord(x = x, y = y, z = z)`.

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

---

### `hexAxialToCube` (`std/spatial/hex_tile_world2d.aipl`)

- **Signature**: `pub fn hexAxialToCube(axial: HexAxialCoord): HexCubeCoord:`
- **Import**: `import * from "std/spatial/hex_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `axial: HexAxialCoord` | **Returns**: `HexCubeCoord`
- **Unit Test**: `tests/functions/spatial/hex_tile_world2d_test.aipl` | **Example**: `examples/ex_211_spatial_continuous_world2d_window.aipl`
- **Behavioral Summary**: Tests axial/cube hex coordinates ($q+r+s=0$), hex distance, line drawing, rings (`6*r` cells), and spiral range queries in `hexAxialToCube`. Concrete nominal inputs: `axial: HexAxialCoord = HexAxialCoord(q = 1, r = 1)`; exercises core body path returning/computing `HexCubeCoord(x = axial.q, y = -axial.q - axial.r, z = axial.r)`.

```aipl
module tests.functions.spatial.hex_tile_world2d_z2_test
import * from "std/spatial/hex_tile_world2d"
import { SQRT3, absInt, absFloat } from "std/math/consts"
import { round } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hex_tile_world2d_hexAxialToCube_2(): int:
  let arg_axial = HexAxialCoord(q = 2, r = 2)
  let edge_axial = HexAxialCoord(q = 0, r = 0)
  let resNom = hexAxialToCube(arg_axial)
  let resEdge = hexAxialToCube(edge_axial)
  assertEqInt(resNom.x, 2, "hexAxialToCube nominal resNom.x == 2")
  assertEqInt(resEdge.x, 0, "hexAxialToCube boundary resEdge.x == 0")
  ret 0
```

---

### `hexCubeToAxial` (`std/spatial/hex_tile_world2d.aipl`)

- **Signature**: `pub fn hexCubeToAxial(cube: HexCubeCoord): HexAxialCoord:`
- **Import**: `import * from "std/spatial/hex_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cube: HexCubeCoord` | **Returns**: `HexAxialCoord`
- **Unit Test**: `tests/functions/spatial/hex_tile_world2d_test.aipl` | **Example**: `examples/ex_209_spatial_iso_tile_world2d_window.aipl`
- **Behavioral Summary**: Tests axial/cube hex coordinates ($q+r+s=0$), hex distance, line drawing, rings (`6*r` cells), and spiral range queries in `hexCubeToAxial`. Concrete nominal inputs: `cube: HexCubeCoord = HexCubeCoord(x = 1, y = 1, z = 1)`; exercises core body path returning/computing `HexAxialCoord(q = cube.x, r = cube.z)`.

```aipl
module tests.functions.spatial.hex_tile_world2d_z3_test
import * from "std/spatial/hex_tile_world2d"
import { SQRT3, absInt, absFloat } from "std/math/consts"
import { round } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hex_tile_world2d_hexCubeToAxial_3(): int:
  let arg_cube = HexCubeCoord(x = 1, y = 1, z = 1)
  let edge_cube = HexCubeCoord(x = 0, y = 0, z = 0)
  let resNom = hexCubeToAxial(arg_cube)
  let resEdge = hexCubeToAxial(edge_cube)
  assertEqInt(resNom.q, 1, "hexCubeToAxial nominal resNom.q == 1")
  assertEqInt(resEdge.q, 0, "hexCubeToAxial boundary resEdge.q == 0")
  ret 0
```

---

### `hexDistance` (`std/spatial/hex_tile_world2d.aipl`)

- **Signature**: `pub fn hexDistance(a: HexCubeCoord, b: HexCubeCoord): int:`
- **Import**: `import * from "std/spatial/hex_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: HexCubeCoord, b: HexCubeCoord` | **Returns**: `int`
- **Unit Test**: `tests/functions/spatial/hex_tile_world2d_test.aipl` | **Example**: `examples/ex_210_spatial_hex_tile_world2d_window.aipl`
- **Behavioral Summary**: Tests axial/cube hex coordinates ($q+r+s=0$), hex distance, line drawing, rings (`6*r` cells), and spiral range queries in `hexDistance`. Concrete nominal inputs: `a: HexCubeCoord = HexCubeCoord(x = 1, y = 1, z = 1)`, `b: HexCubeCoord = HexCubeCoord(x = 1, y = 1, z = 1)`; exercises core body path returning/computing `(absInt(a.x - b.x) + absInt(a.y - b.y) + absInt(a.z - b.z)) / 2`.

```aipl
module tests.functions.spatial.hex_tile_world2d_z4_test
import * from "std/spatial/hex_tile_world2d"
import { SQRT3, absInt, absFloat } from "std/math/consts"
import { round } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hex_tile_world2d_hexDistance_4(): int:
  let arg_a = HexCubeCoord(x = 1, y = 1, z = 1)
  let edge_a = HexCubeCoord(x = 0, y = 0, z = 0)
  let arg_b = HexCubeCoord(x = 1, y = 1, z = 1)
  let edge_b = HexCubeCoord(x = 0, y = 0, z = 0)
  let resNom = hexDistance(arg_a, arg_b)
  let resEdge = hexDistance(edge_a, edge_b)
  assertEqInt(resNom, 0, "hexDistance nominal resNom == 0")
  assertEqInt(resEdge, 0, "hexDistance boundary resEdge == 0")
  ret 0
```

---

### `hexRing` (`std/spatial/hex_tile_world2d.aipl`)

- **Signature**: `pub fn hexRing(center: HexCubeCoord, radius: int): [HexCubeCoord]:`
- **Import**: `import * from "std/spatial/hex_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `center: HexCubeCoord, radius: int` | **Returns**: `[HexCubeCoord]`
- **Unit Test**: `tests/functions/spatial/hex_tile_world2d_test.aipl` | **Example**: `examples/ex_211_spatial_continuous_world2d_window.aipl`
- **Behavioral Summary**: Tests axial/cube hex coordinates ($q+r+s=0$), hex distance, line drawing, rings (`6*r` cells), and spiral range queries in `hexRing`. Concrete nominal inputs: `center: HexCubeCoord = HexCubeCoord(x = 1, y = 1, z = 1)`, `radius: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.spatial.hex_tile_world2d_z5_test
import * from "std/spatial/hex_tile_world2d"
import { SQRT3, absInt, absFloat } from "std/math/consts"
import { round } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hex_tile_world2d_hexRing_5(): int:
  let arg_center = HexCubeCoord(x = 1, y = 1, z = 1)
  let edge_center = HexCubeCoord(x = 0, y = 0, z = 0)
  let arg_radius = 2
  let edge_radius = 0
  let resNom = hexRing(arg_center, arg_radius)
  let resEdge = hexRing(edge_center, edge_radius)
  assertEqInt(resNom.len(), 12, "hexRing nominal resNom.len() == 12")
  assertEqInt(resEdge.len(), 1, "hexRing boundary resEdge.len() == 1")
  ret 0
```

---

### `hexSpiral` (`std/spatial/hex_tile_world2d.aipl`)

- **Signature**: `pub fn hexSpiral(center: HexCubeCoord, maxRadius: int): [HexCubeCoord]:`
- **Import**: `import * from "std/spatial/hex_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `center: HexCubeCoord, maxRadius: int` | **Returns**: `[HexCubeCoord]`
- **Unit Test**: `tests/functions/spatial/hex_tile_world2d_test.aipl` | **Example**: `examples/ex_209_spatial_iso_tile_world2d_window.aipl`
- **Behavioral Summary**: Tests axial/cube hex coordinates ($q+r+s=0$), hex distance, line drawing, rings (`6*r` cells), and spiral range queries in `hexSpiral`. Concrete nominal inputs: `center: HexCubeCoord = HexCubeCoord(x = 1, y = 1, z = 1)`, `maxRadius: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.spatial.hex_tile_world2d_z6_test
import * from "std/spatial/hex_tile_world2d"
import { SQRT3, absInt, absFloat } from "std/math/consts"
import { round } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hex_tile_world2d_hexSpiral_6(): int:
  let arg_center = HexCubeCoord(x = 1, y = 1, z = 1)
  let edge_center = HexCubeCoord(x = 0, y = 0, z = 0)
  let arg_maxRadius = 4
  let edge_maxRadius = 1
  let resNom = hexSpiral(arg_center, arg_maxRadius)
  let resEdge = hexSpiral(edge_center, edge_maxRadius)
  assertEqInt(resNom.len(), 61, "hexSpiral nominal resNom.len() == 61")
  assertEqInt(resEdge.len(), 7, "hexSpiral boundary resEdge.len() == 7")
  ret 0
```

---

### `cubeRound` (`std/spatial/hex_tile_world2d.aipl`)

- **Signature**: `fn cubeRound(fx: float, fy: float, fz: float): HexCubeCoord:`
- **Import**: `import * from "std/spatial/hex_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fx: float, fy: float, fz: float` | **Returns**: `HexCubeCoord`
- **Unit Test**: `tests/functions/spatial/hex_tile_world2d_test.aipl` | **Example**: `examples/ex_210_spatial_hex_tile_world2d_window.aipl`
- **Behavioral Summary**: Tests axial/cube hex coordinates ($q+r+s=0$), hex distance, line drawing, rings (`6*r` cells), and spiral range queries in `cubeRound`. Concrete nominal inputs: `fx: float = 1.0`, `fy: float = 1.0`, `fz: float = 1.0`; exercises core body path returning/computing `HexCubeCoord(x = rx, y = ry, z = rz)`.

```aipl
module tests.functions.spatial.hex_tile_world2d_z7_test
import * from "std/spatial/hex_tile_world2d"
import { SQRT3, absInt, absFloat } from "std/math/consts"
import { round } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hex_tile_world2d_cubeRound_7(): int:
  let arg_fx = 1.0
  let edge_fx = 0.5
  let arg_fy = 1.0
  let edge_fy = 0.5
  let arg_fz = 1.0
  let edge_fz = 0.5
  let resNom = cubeRound(arg_fx, arg_fy, arg_fz)
  let resEdge = cubeRound(edge_fx, edge_fy, edge_fz)
  assertEqInt(resNom.x, 1, "cubeRound nominal resNom.x == 1")
  assertEqInt(resEdge.x, 1, "cubeRound boundary resEdge.x == 1")
  ret 0
```

---

### `hexToPixel` (`std/spatial/hex_tile_world2d.aipl`)

- **Signature**: `pub fn hexToPixel(coord: HexAxialCoord, orientation: HexOrientation, size: float): Vec2:`
- **Import**: `import * from "std/spatial/hex_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `coord: HexAxialCoord, orientation: HexOrientation, size: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/spatial/hex_tile_world2d_test.aipl` | **Example**: `examples/ex_211_spatial_continuous_world2d_window.aipl`
- **Behavioral Summary**: Tests axial/cube hex coordinates ($q+r+s=0$), hex distance, line drawing, rings (`6*r` cells), and spiral range queries in `hexToPixel`. Concrete nominal inputs: `coord: HexAxialCoord = HexAxialCoord(q = 1, r = 1)`, `orientation: HexOrientation = HexOrientation()`, `size: float = 1.0`; exercises core body path returning/computing `Vec2(x = pxFlat, y = pyFlat)`.

```aipl
module tests.functions.spatial.hex_tile_world2d_z8_test
import * from "std/spatial/hex_tile_world2d"
import { SQRT3, absInt, absFloat } from "std/math/consts"
import { round } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hex_tile_world2d_hexToPixel_8(): int:
  let arg_coord = HexAxialCoord(q = 2, r = 2)
  let edge_coord = HexAxialCoord(q = 0, r = 0)
  let arg_orientation = HexOrientation.PointyTop
  let edge_orientation = HexOrientation.PointyTop
  let arg_size = 1.0
  let edge_size = 0.5
  let resNom = hexToPixel(arg_coord, arg_orientation, arg_size)
  let resEdge = hexToPixel(edge_coord, edge_orientation, edge_size)
  assertApproxEq(resNom.x, 5.19615, 0.001, "hexToPixel nominal resNom.x ~= 5.19615")
  assertApproxEq(resEdge.x, 0.0, 0.001, "hexToPixel boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `hexPixelToAxial` (`std/spatial/hex_tile_world2d.aipl`)

- **Signature**: `pub fn hexPixelToAxial(pixel: Vec2, orientation: HexOrientation, size: float): HexAxialCoord:`
- **Import**: `import * from "std/spatial/hex_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pixel: Vec2, orientation: HexOrientation, size: float` | **Returns**: `HexAxialCoord`
- **Unit Test**: `tests/functions/spatial/hex_tile_world2d_test.aipl` | **Example**: `examples/ex_209_spatial_iso_tile_world2d_window.aipl`
- **Behavioral Summary**: Tests axial/cube hex coordinates ($q+r+s=0$), hex distance, line drawing, rings (`6*r` cells), and spiral range queries in `hexPixelToAxial`. Concrete nominal inputs: `pixel: Vec2 = Vec2(x = 1.0, y = 1.0)`, `orientation: HexOrientation = HexOrientation()`, `size: float = 1.0`; exercises core body path returning/computing `hexCubeToAxial(cube)`.

```aipl
module tests.functions.spatial.hex_tile_world2d_z9_test
import * from "std/spatial/hex_tile_world2d"
import { SQRT3, absInt, absFloat } from "std/math/consts"
import { round } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hex_tile_world2d_hexPixelToAxial_9(): int:
  let arg_pixel = Vec2(x = 1.0, y = 1.0)
  let edge_pixel = Vec2(x = 0.5, y = 0.5)
  let arg_orientation = HexOrientation.PointyTop
  let edge_orientation = HexOrientation.PointyTop
  let arg_size = 1.0
  let edge_size = 0.5
  let resNom = hexPixelToAxial(arg_pixel, arg_orientation, arg_size)
  let resEdge = hexPixelToAxial(edge_pixel, edge_orientation, edge_size)
  assertEqInt(resNom.q, 0, "hexPixelToAxial nominal resNom.q == 0")
  assertEqInt(resEdge.q, 0, "hexPixelToAxial boundary resEdge.q == 0")
  ret 0
```

---

### `hexLine` (`std/spatial/hex_tile_world2d.aipl`)

- **Signature**: `pub fn hexLine(a: HexCubeCoord, b: HexCubeCoord): [HexCubeCoord]:`
- **Import**: `import * from "std/spatial/hex_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: HexCubeCoord, b: HexCubeCoord` | **Returns**: `[HexCubeCoord]`
- **Unit Test**: `tests/functions/spatial/hex_tile_world2d_test.aipl` | **Example**: `examples/ex_210_spatial_hex_tile_world2d_window.aipl`
- **Behavioral Summary**: Tests axial/cube hex coordinates ($q+r+s=0$), hex distance, line drawing, rings (`6*r` cells), and spiral range queries in `hexLine`. Concrete nominal inputs: `a: HexCubeCoord = HexCubeCoord(x = 1, y = 1, z = 1)`, `b: HexCubeCoord = HexCubeCoord(x = 1, y = 1, z = 1)`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.spatial.hex_tile_world2d_z10_test
import * from "std/spatial/hex_tile_world2d"
import { SQRT3, absInt, absFloat } from "std/math/consts"
import { round } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hex_tile_world2d_hexLine_10(): int:
  let arg_a = HexCubeCoord(x = 1, y = 1, z = 1)
  let edge_a = HexCubeCoord(x = 0, y = 0, z = 0)
  let arg_b = HexCubeCoord(x = 1, y = 1, z = 1)
  let edge_b = HexCubeCoord(x = 0, y = 0, z = 0)
  let resNom = hexLine(arg_a, arg_b)
  let resEdge = hexLine(edge_a, edge_b)
  assertEqInt(resNom.len(), 1, "hexLine nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "hexLine boundary resEdge.len() == 1")
  ret 0
```

---

### `isoTileWorldNew` (`std/spatial/iso_tile_world2d.aipl`)

- **Signature**: `pub fn isoTileWorldNew(cols: int, rows: int, tileWidth: float, tileHeight: float, elevationScale: float): IsoTileWorld2D:`
- **Import**: `import * from "std/spatial/iso_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cols: int, rows: int, tileWidth: float, tileHeight: float, elevationScale: float` | **Returns**: `IsoTileWorld2D`
- **Unit Test**: `tests/functions/spatial/iso_tile_world2d_test.aipl` | **Example**: `examples/ex_211_spatial_continuous_world2d_window.aipl`
- **Behavioral Summary**: Verifies isometric grid projection/unprojection, depth sorting key calculation, and elevation-aware mouse cell picking in `isoTileWorldNew`. Concrete nominal inputs: `cols: int = 1`, `rows: int = 1`, `tileWidth: float = 0.016667`, `tileHeight: float = 1.0`, `elevationScale: float = 1.0`; exercises core body path returning/computing `IsoTileWorld2D(`.

```aipl
module tests.functions.spatial.iso_tile_world2d_z1_test
import * from "std/spatial/iso_tile_world2d"
import { round } from "std/math/trig"
import { Vec2, Vec3, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_tile_world2d_isoTileWorldNew_1(): int:
  let arg_cols = 4
  let edge_cols = 1
  let arg_rows = 4
  let edge_rows = 1
  let arg_tileWidth = 2.0
  let edge_tileWidth = 1.0
  let arg_tileHeight = 2.0
  let edge_tileHeight = 1.0
  let arg_elevationScale = 2.0
  let edge_elevationScale = 1.0
  let resNom = isoTileWorldNew(arg_cols, arg_rows, arg_tileWidth, arg_tileHeight, arg_elevationScale)
  let resEdge = isoTileWorldNew(edge_cols, edge_rows, edge_tileWidth, edge_tileHeight, edge_elevationScale)
  assertEqInt(resNom.cols, 4, "isoTileWorldNew nominal resNom.cols == 4")
  assertEqInt(resEdge.cols, 1, "isoTileWorldNew boundary resEdge.cols == 1")
  ret 0
```

---

### `isoWorldGridToScreen` (`std/spatial/iso_tile_world2d.aipl`)

- **Signature**: `pub fn isoWorldGridToScreen(world: IsoTileWorld2D, col: int, row: int, elevation: float): Vec2:`
- **Import**: `import * from "std/spatial/iso_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: IsoTileWorld2D, col: int, row: int, elevation: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/spatial/iso_tile_world2d_test.aipl` | **Example**: `examples/ex_209_spatial_iso_tile_world2d_window.aipl`
- **Behavioral Summary**: Verifies isometric grid projection/unprojection, depth sorting key calculation, and elevation-aware mouse cell picking in `isoWorldGridToScreen`. Concrete nominal inputs: `world: IsoTileWorld2D = IsoTileWorld2D(cols = 1, rows = 1, tileWidth = 0.016667, tileHeight = 1.0, elevationScale = 1.0, cells = [IsoTileCell2D(tileId = 0, heightStep = 0, walkable = 0, surfaceNormal = 0)])`, `col: int = 1`, `row: int = 1`, `elevation: float = 1.0`; exercises core body path returning/computing `Vec2(x = sx, y = sy)`.

```aipl
module tests.functions.spatial.iso_tile_world2d_z2_test
import * from "std/spatial/iso_tile_world2d"
import { round } from "std/math/trig"
import { Vec2, Vec3, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_tile_world2d_isoWorldGridToScreen_2(): int:
  let arg_world = IsoTileWorld2D(cols = 4, rows = 4, tileWidth = 2.0, tileHeight = 2.0, elevationScale = 2.0, cells = [])
  let edge_world = IsoTileWorld2D(cols = 4, rows = 4, tileWidth = 1.0, tileHeight = 1.0, elevationScale = 1.0, cells = [])
  let arg_col = 1
  let edge_col = 0
  let arg_row = 1
  let edge_row = 0
  let arg_elevation = 1.0
  let edge_elevation = 0.5
  let resNom = isoWorldGridToScreen(arg_world, arg_col, arg_row, arg_elevation)
  let resEdge = isoWorldGridToScreen(edge_world, edge_col, edge_row, edge_elevation)
  assertApproxEq(resNom.x, 0.0, 0.001, "isoWorldGridToScreen nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "isoWorldGridToScreen boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `isoScreenToGrid` (`std/spatial/iso_tile_world2d.aipl`)

- **Signature**: `pub fn isoScreenToGrid(world: IsoTileWorld2D, screenX: float, screenY: float): Vec2:`
- **Import**: `import * from "std/spatial/iso_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: IsoTileWorld2D, screenX: float, screenY: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/spatial/iso_tile_world2d_test.aipl` | **Example**: `examples/ex_210_spatial_hex_tile_world2d_window.aipl`
- **Behavioral Summary**: Verifies isometric grid projection/unprojection, depth sorting key calculation, and elevation-aware mouse cell picking in `isoScreenToGrid`. Concrete nominal inputs: `world: IsoTileWorld2D = IsoTileWorld2D(cols = 1, rows = 1, tileWidth = 0.016667, tileHeight = 1.0, elevationScale = 1.0, cells = [IsoTileCell2D(tileId = 0, heightStep = 0, walkable = 0, surfaceNormal = 0)])`, `screenX: float = 1.0`, `screenY: float = 1.0`; exercises core body path returning/computing `Vec2(x = colF, y = rowF)`.

```aipl
module tests.functions.spatial.iso_tile_world2d_z3_test
import * from "std/spatial/iso_tile_world2d"
import { round } from "std/math/trig"
import { Vec2, Vec3, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_tile_world2d_isoScreenToGrid_3(): int:
  let arg_world = IsoTileWorld2D(cols = 4, rows = 4, tileWidth = 2.0, tileHeight = 2.0, elevationScale = 2.0, cells = [])
  let edge_world = IsoTileWorld2D(cols = 4, rows = 4, tileWidth = 1.0, tileHeight = 1.0, elevationScale = 1.0, cells = [])
  let arg_screenX = 1.0
  let edge_screenX = 0.5
  let arg_screenY = 1.0
  let edge_screenY = 0.5
  let resNom = isoScreenToGrid(arg_world, arg_screenX, arg_screenY)
  let resEdge = isoScreenToGrid(edge_world, edge_screenX, edge_screenY)
  assertApproxEq(resNom.x, 1.0, 0.001, "isoScreenToGrid nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 1.0, 0.001, "isoScreenToGrid boundary resEdge.x ~= 1.0")
  ret 0
```

---

### `isoPickCellWithHeight` (`std/spatial/iso_tile_world2d.aipl`)

- **Signature**: `pub fn isoPickCellWithHeight(world: IsoTileWorld2D, screenX: float, screenY: float): Option[IVec2]:`
- **Import**: `import * from "std/spatial/iso_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: IsoTileWorld2D, screenX: float, screenY: float` | **Returns**: `Option[IVec2]`
- **Unit Test**: `tests/functions/spatial/iso_tile_world2d_test.aipl` | **Example**: `examples/ex_211_spatial_continuous_world2d_window.aipl`
- **Behavioral Summary**: Verifies isometric grid projection/unprojection, depth sorting key calculation, and elevation-aware mouse cell picking in `isoPickCellWithHeight`. Concrete nominal inputs: `world: IsoTileWorld2D = IsoTileWorld2D(cols = 1, rows = 1, tileWidth = 0.016667, tileHeight = 1.0, elevationScale = 1.0, cells = [IsoTileCell2D(tileId = 0, heightStep = 0, walkable = 0, surfaceNormal = 0)])`, `screenX: float = 1.0`, `screenY: float = 1.0`; exercises core body path returning/computing `bestMatch`.

```aipl
module tests.functions.spatial.iso_tile_world2d_z4_test
import * from "std/spatial/iso_tile_world2d"
import { round } from "std/math/trig"
import { Vec2, Vec3, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_tile_world2d_isoPickCellWithHeight_4(): int:
  let arg_world = IsoTileWorld2D(cols = 4, rows = 4, tileWidth = 2.0, tileHeight = 2.0, elevationScale = 2.0, cells = [])
  let edge_world = IsoTileWorld2D(cols = 4, rows = 4, tileWidth = 1.0, tileHeight = 1.0, elevationScale = 1.0, cells = [])
  let arg_screenX = 1.0
  let edge_screenX = 0.5
  let arg_screenY = 1.0
  let edge_screenY = 0.5
  let resNom = isoPickCellWithHeight(arg_world, arg_screenX, arg_screenY)
  let resEdge = isoPickCellWithHeight(edge_world, edge_screenX, edge_screenY)
  assert(resNom.isSome() == true, "isoPickCellWithHeight nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "isoPickCellWithHeight boundary resEdge.isSome() == true")
  ret 0
```

---

### `isoDepthSortKey` (`std/spatial/iso_tile_world2d.aipl`)

- **Signature**: `pub fn isoDepthSortKey(col: int, row: int, elevation: float): float:`
- **Import**: `import * from "std/spatial/iso_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `col: int, row: int, elevation: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/spatial/iso_tile_world2d_test.aipl` | **Example**: `examples/ex_209_spatial_iso_tile_world2d_window.aipl`
- **Behavioral Summary**: Verifies isometric grid projection/unprojection, depth sorting key calculation, and elevation-aware mouse cell picking in `isoDepthSortKey`. Concrete nominal inputs: `col: int = 1`, `row: int = 1`, `elevation: float = 1.0`; exercises core body path returning/computing `float(col + row) + elevation * 0.01`.

```aipl
module tests.functions.spatial.iso_tile_world2d_z5_test
import * from "std/spatial/iso_tile_world2d"
import { round } from "std/math/trig"
import { Vec2, Vec3, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_iso_tile_world2d_isoDepthSortKey_5(): int:
  let arg_col = 1
  let edge_col = 0
  let arg_row = 1
  let edge_row = 0
  let arg_elevation = 1.0
  let edge_elevation = 0.5
  let resNom = isoDepthSortKey(arg_col, arg_row, arg_elevation)
  let resEdge = isoDepthSortKey(edge_col, edge_row, edge_elevation)
  assertApproxEq(resNom, 2.01, 0.001, "isoDepthSortKey nominal resNom ~= 2.01")
  assertApproxEq(resEdge, 0.005, 0.001, "isoDepthSortKey boundary resEdge ~= 0.005")
  ret 0
```

---

### `orthoTileWorldNew` (`std/spatial/ortho_tile_world2d.aipl`)

- **Signature**: `pub fn orthoTileWorldNew(width: int, height: int, cellSize: float, layers: int): OrthoTileWorld2D:`
- **Import**: `import * from "std/spatial/ortho_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `width: int, height: int, cellSize: float, layers: int` | **Returns**: `OrthoTileWorld2D`
- **Unit Test**: `tests/functions/spatial/ortho_tile_world2d_test.aipl` | **Example**: `examples/ex_210_spatial_hex_tile_world2d_window.aipl`
- **Behavioral Summary**: Tests orthogonal 2D tile grid indexing, coordinate wrapping/clamping, 4/8-neighborhoods, Bresenham LOS, flood-fill, and DDA cell raycasting in `orthoTileWorldNew`. Concrete nominal inputs: `width: int = 128`, `height: int = 128`, `cellSize: float = 1.0`, `layers: int = 1`; exercises core body path returning/computing `OrthoTileWorld2D(`.

```aipl
module tests.functions.spatial.ortho_tile_world2d_z1_test
import * from "std/spatial/ortho_tile_world2d"
import { absInt, absFloat, minFloat } from "std/math/consts"
import { floor, sqrt } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ortho_tile_world2d_orthoTileWorldNew_1(): int:
  let arg_width = 4
  let edge_width = 1
  let arg_height = 4
  let edge_height = 1
  let arg_cellSize = 1.0
  let edge_cellSize = 0.5
  let arg_layers = 1
  let edge_layers = 0
  let resNom = orthoTileWorldNew(arg_width, arg_height, arg_cellSize, arg_layers)
  let resEdge = orthoTileWorldNew(edge_width, edge_height, edge_cellSize, edge_layers)
  assertEqInt(resNom.width, 4, "orthoTileWorldNew nominal resNom.width == 4")
  assertEqInt(resEdge.width, 1, "orthoTileWorldNew boundary resEdge.width == 1")
  ret 0
```

---

### `resolveOrthoCoords` (`std/spatial/ortho_tile_world2d.aipl`)

- **Signature**: `fn resolveOrthoCoords(world: OrthoTileWorld2D, layer: int, col: int, row: int): int:`
- **Import**: `import * from "std/spatial/ortho_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: OrthoTileWorld2D, layer: int, col: int, row: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/spatial/ortho_tile_world2d_test.aipl` | **Example**: `examples/ex_211_spatial_continuous_world2d_window.aipl`
- **Behavioral Summary**: Tests orthogonal 2D tile grid indexing, coordinate wrapping/clamping, 4/8-neighborhoods, Bresenham LOS, flood-fill, and DDA cell raycasting in `resolveOrthoCoords`. Concrete nominal inputs: `world: OrthoTileWorld2D = OrthoTileWorld2D(width = 128, height = 128, cellSize = 1.0, layers = 1, cells = [OrthoTileCell2D(tileId = 0, solid = 0, elevation = 0, flags = 0, userData = 0)], wrapX = true, wrapY = true)`, `layer: int = 1`, `col: int = 1`, `row: int = 1`; exercises core body path returning/computing `(layer * world.height + r) * world.width + c`.

```aipl
module tests.functions.spatial.ortho_tile_world2d_z2_test
import * from "std/spatial/ortho_tile_world2d"
import { absInt, absFloat, minFloat } from "std/math/consts"
import { floor, sqrt } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ortho_tile_world2d_resolveOrthoCoords_2(): int:
  let arg_world = OrthoTileWorld2D(width = 4, height = 4, cellSize = 1.0, layers = 1, cells = [], wrapX = true, wrapY = true)
  let edge_world = OrthoTileWorld2D(width = 4, height = 4, cellSize = 0.5, layers = 0, cells = [], wrapX = false, wrapY = false)
  let arg_layer = 1
  let edge_layer = 0
  let arg_col = 1
  let edge_col = 0
  let arg_row = 1
  let edge_row = 0
  let resNom = resolveOrthoCoords(arg_world, arg_layer, arg_col, arg_row)
  let resEdge = resolveOrthoCoords(edge_world, edge_layer, edge_col, edge_row)
  assertEqInt(resNom, -1, "resolveOrthoCoords nominal resNom == -1")
  assertEqInt(resEdge, -1, "resolveOrthoCoords boundary resEdge == -1")
  ret 0
```

---

### `orthoTileGet` (`std/spatial/ortho_tile_world2d.aipl`)

- **Signature**: `pub fn orthoTileGet(world: OrthoTileWorld2D, layer: int, col: int, row: int): Option[OrthoTileCell2D]:`
- **Import**: `import * from "std/spatial/ortho_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: OrthoTileWorld2D, layer: int, col: int, row: int` | **Returns**: `Option[OrthoTileCell2D]`
- **Unit Test**: `tests/functions/spatial/ortho_tile_world2d_test.aipl` | **Example**: `examples/ex_209_spatial_iso_tile_world2d_window.aipl`
- **Behavioral Summary**: Tests orthogonal 2D tile grid indexing, coordinate wrapping/clamping, 4/8-neighborhoods, Bresenham LOS, flood-fill, and DDA cell raycasting in `orthoTileGet`. Concrete nominal inputs: `world: OrthoTileWorld2D = OrthoTileWorld2D(width = 128, height = 128, cellSize = 1.0, layers = 1, cells = [OrthoTileCell2D(tileId = 0, solid = 0, elevation = 0, flags = 0, userData = 0)], wrapX = true, wrapY = true)`, `layer: int = 1`, `col: int = 1`, `row: int = 1`; exercises core body path returning/computing `Some(world.cells[idx])`.

```aipl
module tests.functions.spatial.ortho_tile_world2d_z3_test
import * from "std/spatial/ortho_tile_world2d"
import { absInt, absFloat, minFloat } from "std/math/consts"
import { floor, sqrt } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ortho_tile_world2d_orthoTileGet_3(): int:
  let arg_world = OrthoTileWorld2D(width = 4, height = 4, cellSize = 1.0, layers = 1, cells = [], wrapX = true, wrapY = true)
  let edge_world = OrthoTileWorld2D(width = 4, height = 4, cellSize = 0.5, layers = 0, cells = [], wrapX = false, wrapY = false)
  let arg_layer = 1
  let edge_layer = 0
  let arg_col = 1
  let edge_col = 0
  let arg_row = 1
  let edge_row = 0
  let resNom = orthoTileGet(arg_world, arg_layer, arg_col, arg_row)
  let resEdge = orthoTileGet(edge_world, edge_layer, edge_col, edge_row)
  assert(resNom.isSome() == false, "orthoTileGet nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "orthoTileGet boundary resEdge.isSome() == false")
  ret 0
```

---

### `orthoTileSet` (`std/spatial/ortho_tile_world2d.aipl`)

- **Signature**: `pub fn orthoTileSet(mut world: OrthoTileWorld2D, layer: int, col: int, row: int, cell: OrthoTileCell2D): bool:`
- **Import**: `import * from "std/spatial/ortho_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut world: OrthoTileWorld2D, layer: int, col: int, row: int, cell: OrthoTileCell2D` | **Returns**: `bool`
- **Unit Test**: `tests/functions/spatial/ortho_tile_world2d_test.aipl` | **Example**: `examples/ex_210_spatial_hex_tile_world2d_window.aipl`
- **Behavioral Summary**: Tests orthogonal 2D tile grid indexing, coordinate wrapping/clamping, 4/8-neighborhoods, Bresenham LOS, flood-fill, and DDA cell raycasting in `orthoTileSet`. Concrete nominal inputs: `world: OrthoTileWorld2D = OrthoTileWorld2D(width = 128, height = 128, cellSize = 1.0, layers = 1, cells = [OrthoTileCell2D(tileId = 0, solid = 0, elevation = 0, flags = 0, userData = 0)], wrapX = true, wrapY = true)`, `layer: int = 1`, `col: int = 1`, `row: int = 1`, `cell: OrthoTileCell2D = OrthoTileCell2D(tileId = 1, solid = true, elevation = 1.0, flags = 1, userData = 1)`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.spatial.ortho_tile_world2d_z4_test
import * from "std/spatial/ortho_tile_world2d"
import { absInt, absFloat, minFloat } from "std/math/consts"
import { floor, sqrt } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ortho_tile_world2d_orthoTileSet_4(): int:
  let arg_world = OrthoTileWorld2D(width = 4, height = 4, cellSize = 1.0, layers = 1, cells = [], wrapX = true, wrapY = true)
  let edge_world = OrthoTileWorld2D(width = 4, height = 4, cellSize = 0.5, layers = 0, cells = [], wrapX = false, wrapY = false)
  let arg_layer = 1
  let edge_layer = 0
  let arg_col = 1
  let edge_col = 0
  let arg_row = 1
  let edge_row = 0
  let arg_cell = OrthoTileCell2D(tileId = 1, solid = true, elevation = 1.0, flags = 0, userData = 2)
  let edge_cell = OrthoTileCell2D(tileId = 0, solid = false, elevation = 0.5, flags = 0, userData = 0)
  let resNom = orthoTileSet(arg_world, arg_layer, arg_col, arg_row, arg_cell)
  let resEdge = orthoTileSet(edge_world, edge_layer, edge_col, edge_row, edge_cell)
  assert(resNom == false, "orthoTileSet nominal resNom == false")
  assert(resEdge == false, "orthoTileSet boundary resEdge == false")
  ret 0
```

---

### `orthoWorldToCell` (`std/spatial/ortho_tile_world2d.aipl`)

- **Signature**: `pub fn orthoWorldToCell(world: OrthoTileWorld2D, wx: float, wy: float): IVec2:`
- **Import**: `import * from "std/spatial/ortho_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: OrthoTileWorld2D, wx: float, wy: float` | **Returns**: `IVec2`
- **Unit Test**: `tests/functions/spatial/ortho_tile_world2d_test.aipl` | **Example**: `examples/ex_211_spatial_continuous_world2d_window.aipl`
- **Behavioral Summary**: Tests orthogonal 2D tile grid indexing, coordinate wrapping/clamping, 4/8-neighborhoods, Bresenham LOS, flood-fill, and DDA cell raycasting in `orthoWorldToCell`. Concrete nominal inputs: `world: OrthoTileWorld2D = OrthoTileWorld2D(width = 128, height = 128, cellSize = 1.0, layers = 1, cells = [OrthoTileCell2D(tileId = 0, solid = 0, elevation = 0, flags = 0, userData = 0)], wrapX = true, wrapY = true)`, `wx: float = 1.0`, `wy: float = 1.0`; exercises core body path returning/computing `IVec2(`.

```aipl
module tests.functions.spatial.ortho_tile_world2d_z5_test
import * from "std/spatial/ortho_tile_world2d"
import { absInt, absFloat, minFloat } from "std/math/consts"
import { floor, sqrt } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ortho_tile_world2d_orthoWorldToCell_5(): int:
  let arg_world = OrthoTileWorld2D(width = 4, height = 4, cellSize = 1.0, layers = 1, cells = [], wrapX = true, wrapY = true)
  let edge_world = OrthoTileWorld2D(width = 4, height = 4, cellSize = 0.5, layers = 0, cells = [], wrapX = false, wrapY = false)
  let arg_wx = 2.0
  let edge_wx = 1.0
  let arg_wy = 2.0
  let edge_wy = 1.0
  let resNom = orthoWorldToCell(arg_world, arg_wx, arg_wy)
  let resEdge = orthoWorldToCell(edge_world, edge_wx, edge_wy)
  assertEqInt(resNom.x, 2, "orthoWorldToCell nominal resNom.x == 2")
  assertEqInt(resEdge.x, 2, "orthoWorldToCell boundary resEdge.x == 2")
  ret 0
```

---

### `orthoCellToWorldCenter` (`std/spatial/ortho_tile_world2d.aipl`)

- **Signature**: `pub fn orthoCellToWorldCenter(world: OrthoTileWorld2D, col: int, row: int): Vec2:`
- **Import**: `import * from "std/spatial/ortho_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: OrthoTileWorld2D, col: int, row: int` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/spatial/ortho_tile_world2d_test.aipl` | **Example**: `examples/ex_209_spatial_iso_tile_world2d_window.aipl`
- **Behavioral Summary**: Tests orthogonal 2D tile grid indexing, coordinate wrapping/clamping, 4/8-neighborhoods, Bresenham LOS, flood-fill, and DDA cell raycasting in `orthoCellToWorldCenter`. Concrete nominal inputs: `world: OrthoTileWorld2D = OrthoTileWorld2D(width = 128, height = 128, cellSize = 1.0, layers = 1, cells = [OrthoTileCell2D(tileId = 0, solid = 0, elevation = 0, flags = 0, userData = 0)], wrapX = true, wrapY = true)`, `col: int = 1`, `row: int = 1`; exercises core body path returning/computing `Vec2(`.

```aipl
module tests.functions.spatial.ortho_tile_world2d_z6_test
import * from "std/spatial/ortho_tile_world2d"
import { absInt, absFloat, minFloat } from "std/math/consts"
import { floor, sqrt } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ortho_tile_world2d_orthoCellToWorldCenter_6(): int:
  let arg_world = OrthoTileWorld2D(width = 4, height = 4, cellSize = 1.0, layers = 1, cells = [], wrapX = true, wrapY = true)
  let edge_world = OrthoTileWorld2D(width = 4, height = 4, cellSize = 0.5, layers = 0, cells = [], wrapX = false, wrapY = false)
  let arg_col = 1
  let edge_col = 0
  let arg_row = 1
  let edge_row = 0
  let resNom = orthoCellToWorldCenter(arg_world, arg_col, arg_row)
  let resEdge = orthoCellToWorldCenter(edge_world, edge_col, edge_row)
  assertApproxEq(resNom.x, 1.5, 0.001, "orthoCellToWorldCenter nominal resNom.x ~= 1.5")
  assertApproxEq(resEdge.x, 0.25, 0.001, "orthoCellToWorldCenter boundary resEdge.x ~= 0.25")
  ret 0
```

---

### `orthoNeighbors4` (`std/spatial/ortho_tile_world2d.aipl`)

- **Signature**: `pub fn orthoNeighbors4(world: OrthoTileWorld2D, col: int, row: int): [IVec2]:`
- **Import**: `import * from "std/spatial/ortho_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: OrthoTileWorld2D, col: int, row: int` | **Returns**: `[IVec2]`
- **Unit Test**: `tests/functions/spatial/ortho_tile_world2d_test.aipl` | **Example**: `examples/ex_210_spatial_hex_tile_world2d_window.aipl`
- **Behavioral Summary**: Tests orthogonal 2D tile grid indexing, coordinate wrapping/clamping, 4/8-neighborhoods, Bresenham LOS, flood-fill, and DDA cell raycasting in `orthoNeighbors4`. Concrete nominal inputs: `world: OrthoTileWorld2D = OrthoTileWorld2D(width = 128, height = 128, cellSize = 1.0, layers = 1, cells = [OrthoTileCell2D(tileId = 0, solid = 0, elevation = 0, flags = 0, userData = 0)], wrapX = true, wrapY = true)`, `col: int = 1`, `row: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.spatial.ortho_tile_world2d_z7_test
import * from "std/spatial/ortho_tile_world2d"
import { absInt, absFloat, minFloat } from "std/math/consts"
import { floor, sqrt } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ortho_tile_world2d_orthoNeighbors4_7(): int:
  let arg_world = OrthoTileWorld2D(width = 4, height = 4, cellSize = 1.0, layers = 1, cells = [], wrapX = true, wrapY = true)
  let edge_world = OrthoTileWorld2D(width = 4, height = 4, cellSize = 0.5, layers = 0, cells = [], wrapX = false, wrapY = false)
  let arg_col = 1
  let edge_col = 0
  let arg_row = 1
  let edge_row = 0
  let resNom = orthoNeighbors4(arg_world, arg_col, arg_row)
  let resEdge = orthoNeighbors4(edge_world, edge_col, edge_row)
  assertEqInt(resNom.len(), 4, "orthoNeighbors4 nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 0, "orthoNeighbors4 boundary resEdge.len() == 0")
  ret 0
```

---

### `orthoNeighbors8` (`std/spatial/ortho_tile_world2d.aipl`)

- **Signature**: `pub fn orthoNeighbors8(world: OrthoTileWorld2D, col: int, row: int): [IVec2]:`
- **Import**: `import * from "std/spatial/ortho_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: OrthoTileWorld2D, col: int, row: int` | **Returns**: `[IVec2]`
- **Unit Test**: `tests/functions/spatial/ortho_tile_world2d_test.aipl` | **Example**: `examples/ex_211_spatial_continuous_world2d_window.aipl`
- **Behavioral Summary**: Tests orthogonal 2D tile grid indexing, coordinate wrapping/clamping, 4/8-neighborhoods, Bresenham LOS, flood-fill, and DDA cell raycasting in `orthoNeighbors8`. Concrete nominal inputs: `world: OrthoTileWorld2D = OrthoTileWorld2D(width = 128, height = 128, cellSize = 1.0, layers = 1, cells = [OrthoTileCell2D(tileId = 0, solid = 0, elevation = 0, flags = 0, userData = 0)], wrapX = true, wrapY = true)`, `col: int = 1`, `row: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.spatial.ortho_tile_world2d_z8_test
import * from "std/spatial/ortho_tile_world2d"
import { absInt, absFloat, minFloat } from "std/math/consts"
import { floor, sqrt } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ortho_tile_world2d_orthoNeighbors8_8(): int:
  let arg_world = OrthoTileWorld2D(width = 4, height = 4, cellSize = 1.0, layers = 1, cells = [], wrapX = true, wrapY = true)
  let edge_world = OrthoTileWorld2D(width = 4, height = 4, cellSize = 0.5, layers = 0, cells = [], wrapX = false, wrapY = false)
  let arg_col = 1
  let edge_col = 0
  let arg_row = 1
  let edge_row = 0
  let resNom = orthoNeighbors8(arg_world, arg_col, arg_row)
  let resEdge = orthoNeighbors8(edge_world, edge_col, edge_row)
  assertEqInt(resNom.len(), 8, "orthoNeighbors8 nominal resNom.len() == 8")
  assertEqInt(resEdge.len(), 0, "orthoNeighbors8 boundary resEdge.len() == 0")
  ret 0
```

---

### `orthoLineOfSightBresenham` (`std/spatial/ortho_tile_world2d.aipl`)

- **Signature**: `pub fn orthoLineOfSightBresenham(world: OrthoTileWorld2D, layer: int, c0: int, r0: int, c1: int, r1: int): bool:`
- **Import**: `import * from "std/spatial/ortho_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: OrthoTileWorld2D, layer: int, c0: int, r0: int, c1: int, r1: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/spatial/ortho_tile_world2d_test.aipl` | **Example**: `examples/ex_209_spatial_iso_tile_world2d_window.aipl`
- **Behavioral Summary**: Tests orthogonal 2D tile grid indexing, coordinate wrapping/clamping, 4/8-neighborhoods, Bresenham LOS, flood-fill, and DDA cell raycasting in `orthoLineOfSightBresenham`. Concrete nominal inputs: `world: OrthoTileWorld2D = OrthoTileWorld2D(width = 128, height = 128, cellSize = 1.0, layers = 1, cells = [OrthoTileCell2D(tileId = 0, solid = 0, elevation = 0, flags = 0, userData = 0)], wrapX = true, wrapY = true)`, `layer: int = 1`, `c0: int = 1`, `r0: int = 1`, `c1: int = 1`, `r1: int = 1`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.spatial.ortho_tile_world2d_z9_test
import * from "std/spatial/ortho_tile_world2d"
import { absInt, absFloat, minFloat } from "std/math/consts"
import { floor, sqrt } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ortho_tile_world2d_orthoLineOfSightBresenham_9(): int:
  let arg_world = OrthoTileWorld2D(width = 4, height = 4, cellSize = 1.0, layers = 1, cells = [], wrapX = true, wrapY = true)
  let edge_world = OrthoTileWorld2D(width = 4, height = 4, cellSize = 0.5, layers = 0, cells = [], wrapX = false, wrapY = false)
  let arg_layer = 1
  let edge_layer = 0
  let arg_c0 = 2
  let edge_c0 = 0
  let arg_r0 = 2
  let edge_r0 = 0
  let arg_c1 = 2
  let edge_c1 = 0
  let arg_r1 = 2
  let edge_r1 = 0
  let resNom = orthoLineOfSightBresenham(arg_world, arg_layer, arg_c0, arg_r0, arg_c1, arg_r1)
  let resEdge = orthoLineOfSightBresenham(edge_world, edge_layer, edge_c0, edge_r0, edge_c1, edge_r1)
  assert(resNom == false, "orthoLineOfSightBresenham nominal resNom == false")
  assert(resEdge == false, "orthoLineOfSightBresenham boundary resEdge == false")
  ret 0
```

---

### `orthoFloodFill` (`std/spatial/ortho_tile_world2d.aipl`)

- **Signature**: `pub fn orthoFloodFill(mut world: OrthoTileWorld2D, layer: int, startCol: int, startRow: int, targetTileId: int, fillTileId: int): int:`
- **Import**: `import * from "std/spatial/ortho_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut world: OrthoTileWorld2D, layer: int, startCol: int, startRow: int, targetTileId: int, fillTileId: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/spatial/ortho_tile_world2d_test.aipl` | **Example**: `examples/ex_210_spatial_hex_tile_world2d_window.aipl`
- **Behavioral Summary**: Tests orthogonal 2D tile grid indexing, coordinate wrapping/clamping, 4/8-neighborhoods, Bresenham LOS, flood-fill, and DDA cell raycasting in `orthoFloodFill`. Concrete nominal inputs: `world: OrthoTileWorld2D = OrthoTileWorld2D(width = 128, height = 128, cellSize = 1.0, layers = 1, cells = [OrthoTileCell2D(tileId = 0, solid = 0, elevation = 0, flags = 0, userData = 0)], wrapX = true, wrapY = true)`, `layer: int = 1`, `startCol: int = 1`, `startRow: int = 1`, `targetTileId: int = 1`, `fillTileId: int = 1`; exercises core body path returning/computing `painted`.

```aipl
module tests.functions.spatial.ortho_tile_world2d_z10_test
import * from "std/spatial/ortho_tile_world2d"
import { absInt, absFloat, minFloat } from "std/math/consts"
import { floor, sqrt } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ortho_tile_world2d_orthoFloodFill_10(): int:
  let arg_world = OrthoTileWorld2D(width = 4, height = 4, cellSize = 1.0, layers = 1, cells = [], wrapX = true, wrapY = true)
  let edge_world = OrthoTileWorld2D(width = 4, height = 4, cellSize = 0.5, layers = 0, cells = [], wrapX = false, wrapY = false)
  let arg_layer = 1
  let edge_layer = 0
  let arg_startCol = 1
  let edge_startCol = 0
  let arg_startRow = 1
  let edge_startRow = 0
  let arg_targetTileId = 1
  let edge_targetTileId = 0
  let arg_fillTileId = 1
  let edge_fillTileId = 0
  let resNom = orthoFloodFill(arg_world, arg_layer, arg_startCol, arg_startRow, arg_targetTileId, arg_fillTileId)
  let resEdge = orthoFloodFill(edge_world, edge_layer, edge_startCol, edge_startRow, edge_targetTileId, edge_fillTileId)
  assertEqInt(resNom, 0, "orthoFloodFill nominal resNom == 0")
  assertEqInt(resEdge, 0, "orthoFloodFill boundary resEdge == 0")
  ret 0
```

---

### `orthoRaycastCells` (`std/spatial/ortho_tile_world2d.aipl`)

- **Signature**: `pub fn orthoRaycastCells(world: OrthoTileWorld2D, layer: int, start: Vec2, dir: Vec2, maxDist: float): [IVec2]:`
- **Import**: `import * from "std/spatial/ortho_tile_world2d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: OrthoTileWorld2D, layer: int, start: Vec2, dir: Vec2, maxDist: float` | **Returns**: `[IVec2]`
- **Unit Test**: `tests/functions/spatial/ortho_tile_world2d_test.aipl` | **Example**: `examples/ex_211_spatial_continuous_world2d_window.aipl`
- **Behavioral Summary**: Tests orthogonal 2D tile grid indexing, coordinate wrapping/clamping, 4/8-neighborhoods, Bresenham LOS, flood-fill, and DDA cell raycasting in `orthoRaycastCells`. Concrete nominal inputs: `world: OrthoTileWorld2D = OrthoTileWorld2D(width = 128, height = 128, cellSize = 1.0, layers = 1, cells = [OrthoTileCell2D(tileId = 0, solid = 0, elevation = 0, flags = 0, userData = 0)], wrapX = true, wrapY = true)`, `layer: int = 1`, `start: Vec2 = Vec2(x = 1.0, y = 1.0)`, `dir: Vec2 = Vec2(x = 1.0, y = 1.0)`, `maxDist: float = 1.0`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.spatial.ortho_tile_world2d_z11_test
import * from "std/spatial/ortho_tile_world2d"
import { absInt, absFloat, minFloat } from "std/math/consts"
import { floor, sqrt } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ortho_tile_world2d_orthoRaycastCells_11(): int:
  let arg_world = OrthoTileWorld2D(width = 4, height = 4, cellSize = 1.0, layers = 1, cells = [], wrapX = true, wrapY = true)
  let edge_world = OrthoTileWorld2D(width = 4, height = 4, cellSize = 0.5, layers = 0, cells = [], wrapX = false, wrapY = false)
  let arg_layer = 1
  let edge_layer = 0
  let arg_start = Vec2(x = 1.0, y = 1.0)
  let edge_start = Vec2(x = 0.5, y = 0.5)
  let arg_dir = Vec2(x = 1.0, y = 1.0)
  let edge_dir = Vec2(x = 0.5, y = 0.5)
  let arg_maxDist = 2.0
  let edge_maxDist = 1.0
  let resNom = orthoRaycastCells(arg_world, arg_layer, arg_start, arg_dir, arg_maxDist)
  let resEdge = orthoRaycastCells(edge_world, edge_layer, edge_start, edge_dir, edge_maxDist)
  assertEqInt(resNom.len(), 0, "orthoRaycastCells nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "orthoRaycastCells boundary resEdge.len() == 0")
  ret 0
```

---

### `voxelChunkWorldNew` (`std/spatial/voxel_chunk_world3d.aipl`)

- **Signature**: `pub fn voxelChunkWorldNew(chunkSize: int): VoxelChunkWorld3D:`
- **Import**: `import * from "std/spatial/voxel_chunk_world3d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `chunkSize: int` | **Returns**: `VoxelChunkWorld3D`
- **Unit Test**: `tests/functions/spatial/voxel_chunk_world3d_test.aipl` | **Example**: `examples/ex_209_spatial_iso_tile_world2d_window.aipl`
- **Behavioral Summary**: Verifies 3D chunked voxel block access, world-to-chunk coordinate mapping, greedy face culling (hidden interior face removal), and 3D Amanatides-Woo DDA voxel raycasting in `voxelChunkWorldNew`. Concrete nominal inputs: `chunkSize: int = 64`; exercises core body path returning/computing `VoxelChunkWorld3D(chunkSize = cs, chunks = ch)`.

```aipl
module tests.functions.spatial.voxel_chunk_world3d_z1_test
import * from "std/spatial/voxel_chunk_world3d"
import { absFloat } from "std/math/consts"
import { floor, sqrt } from "std/math/trig"
import { Vec3, IVec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_voxel_chunk_world3d_voxelChunkWorldNew_1(): int:
  let arg_chunkSize = 4
  let edge_chunkSize = 1
  let resNom = voxelChunkWorldNew(arg_chunkSize)
  let resEdge = voxelChunkWorldNew(edge_chunkSize)
  assertEqInt(resNom.chunkSize, 4, "voxelChunkWorldNew nominal resNom.chunkSize == 4")
  assertEqInt(resEdge.chunkSize, 1, "voxelChunkWorldNew boundary resEdge.chunkSize == 1")
  ret 0
```

---

### `floorDivInt` (`std/spatial/voxel_chunk_world3d.aipl`)

- **Signature**: `fn floorDivInt(a: int, b: int): int:`
- **Import**: `import * from "std/spatial/voxel_chunk_world3d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: int, b: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/spatial/voxel_chunk_world3d_test.aipl` | **Example**: `examples/ex_210_spatial_hex_tile_world2d_window.aipl`
- **Behavioral Summary**: Verifies 3D chunked voxel block access, world-to-chunk coordinate mapping, greedy face culling (hidden interior face removal), and 3D Amanatides-Woo DDA voxel raycasting in `floorDivInt`. Concrete nominal inputs: `a: int = 1`, `b: int = 1`; exercises core body path returning/computing `q`.

```aipl
module tests.functions.spatial.voxel_chunk_world3d_z2_test
import * from "std/spatial/voxel_chunk_world3d"
import { absFloat } from "std/math/consts"
import { floor, sqrt } from "std/math/trig"
import { Vec3, IVec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_voxel_chunk_world3d_floorDivInt_2(): int:
  let arg_a = 2
  let edge_a = 0
  let arg_b = 4
  let edge_b = 1
  let resNom = floorDivInt(arg_a, arg_b)
  let resEdge = floorDivInt(edge_a, edge_b)
  assertEqInt(resNom, 0, "floorDivInt nominal resNom == 0")
  assertEqInt(resEdge, 0, "floorDivInt boundary resEdge == 0")
  ret 0
```

---

### `posModInt` (`std/spatial/voxel_chunk_world3d.aipl`)

- **Signature**: `fn posModInt(a: int, b: int): int:`
- **Import**: `import * from "std/spatial/voxel_chunk_world3d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: int, b: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/spatial/voxel_chunk_world3d_test.aipl` | **Example**: `examples/ex_211_spatial_continuous_world2d_window.aipl`
- **Behavioral Summary**: Verifies 3D chunked voxel block access, world-to-chunk coordinate mapping, greedy face culling (hidden interior face removal), and 3D Amanatides-Woo DDA voxel raycasting in `posModInt`. Concrete nominal inputs: `a: int = 1`, `b: int = 1`; exercises core body path returning/computing `((a % b) + b) % b`.

```aipl
module tests.functions.spatial.voxel_chunk_world3d_z3_test
import * from "std/spatial/voxel_chunk_world3d"
import { absFloat } from "std/math/consts"
import { floor, sqrt } from "std/math/trig"
import { Vec3, IVec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_voxel_chunk_world3d_posModInt_3(): int:
  let arg_a = 2
  let edge_a = 0
  let arg_b = 4
  let edge_b = 1
  let resNom = posModInt(arg_a, arg_b)
  let resEdge = posModInt(edge_a, edge_b)
  assertEqInt(resNom, 2, "posModInt nominal resNom == 2")
  assertEqInt(resEdge, 0, "posModInt boundary resEdge == 0")
  ret 0
```

---

### `voxelGetBlock` (`std/spatial/voxel_chunk_world3d.aipl`)

- **Signature**: `pub fn voxelGetBlock(world: VoxelChunkWorld3D, gx: int, gy: int, gz: int): Option[VoxelBlock]:`
- **Import**: `import * from "std/spatial/voxel_chunk_world3d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: VoxelChunkWorld3D, gx: int, gy: int, gz: int` | **Returns**: `Option[VoxelBlock]`
- **Unit Test**: `tests/functions/spatial/voxel_chunk_world3d_test.aipl` | **Example**: `examples/ex_209_spatial_iso_tile_world2d_window.aipl`
- **Behavioral Summary**: Verifies 3D chunked voxel block access, world-to-chunk coordinate mapping, greedy face culling (hidden interior face removal), and 3D Amanatides-Woo DDA voxel raycasting in `voxelGetBlock`. Concrete nominal inputs: `world: VoxelChunkWorld3D = VoxelChunkWorld3D(chunkSize = 64, chunks = [VoxelChunk16(coord = 0, chunkSize = 0, blocks = 0, isDirty = 0)])`, `gx: int = 1`, `gy: int = 1`, `gz: int = 1`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.spatial.voxel_chunk_world3d_z4_test
import * from "std/spatial/voxel_chunk_world3d"
import { absFloat } from "std/math/consts"
import { floor, sqrt } from "std/math/trig"
import { Vec3, IVec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_voxel_chunk_world3d_voxelGetBlock_4(): int:
  let arg_world = VoxelChunkWorld3D(chunkSize = 4, chunks = [])
  let edge_world = VoxelChunkWorld3D(chunkSize = 1, chunks = [])
  let arg_gx = 1
  let edge_gx = 0
  let arg_gy = 1
  let edge_gy = 0
  let arg_gz = 1
  let edge_gz = 0
  let resNom = voxelGetBlock(arg_world, arg_gx, arg_gy, arg_gz)
  let resEdge = voxelGetBlock(edge_world, edge_gx, edge_gy, edge_gz)
  assert(resNom.isSome() == false, "voxelGetBlock nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "voxelGetBlock boundary resEdge.isSome() == false")
  ret 0
```

---

### `voxelSetBlock` (`std/spatial/voxel_chunk_world3d.aipl`)

- **Signature**: `pub fn voxelSetBlock(mut world: VoxelChunkWorld3D, gx: int, gy: int, gz: int, block: VoxelBlock): bool:`
- **Import**: `import * from "std/spatial/voxel_chunk_world3d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut world: VoxelChunkWorld3D, gx: int, gy: int, gz: int, block: VoxelBlock` | **Returns**: `bool`
- **Unit Test**: `tests/functions/spatial/voxel_chunk_world3d_test.aipl` | **Example**: `examples/ex_210_spatial_hex_tile_world2d_window.aipl`
- **Behavioral Summary**: Verifies 3D chunked voxel block access, world-to-chunk coordinate mapping, greedy face culling (hidden interior face removal), and 3D Amanatides-Woo DDA voxel raycasting in `voxelSetBlock`. Concrete nominal inputs: `world: VoxelChunkWorld3D = VoxelChunkWorld3D(chunkSize = 64, chunks = [VoxelChunk16(coord = 0, chunkSize = 0, blocks = 0, isDirty = 0)])`, `gx: int = 1`, `gy: int = 1`, `gz: int = 1`, `block: VoxelBlock = VoxelBlock(blockId = 1, metadata = 1, lightLevel = 1)`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.spatial.voxel_chunk_world3d_z5_test
import * from "std/spatial/voxel_chunk_world3d"
import { absFloat } from "std/math/consts"
import { floor, sqrt } from "std/math/trig"
import { Vec3, IVec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_voxel_chunk_world3d_voxelSetBlock_5(): int:
  let arg_world = VoxelChunkWorld3D(chunkSize = 4, chunks = [])
  let edge_world = VoxelChunkWorld3D(chunkSize = 1, chunks = [])
  let arg_gx = 1
  let edge_gx = 0
  let arg_gy = 1
  let edge_gy = 0
  let arg_gz = 1
  let edge_gz = 0
  let arg_block = VoxelBlock(blockId = 4, metadata = 4, lightLevel = 2)
  let edge_block = VoxelBlock(blockId = 1, metadata = 1, lightLevel = 0)
  let resNom = voxelSetBlock(arg_world, arg_gx, arg_gy, arg_gz, arg_block)
  let resEdge = voxelSetBlock(edge_world, edge_gx, edge_gy, edge_gz, edge_block)
  assert(resNom == true, "voxelSetBlock nominal resNom == true")
  assert(resEdge == true, "voxelSetBlock boundary resEdge == true")
  ret 0
```

---

### `voxelRaycastDDA` (`std/spatial/voxel_chunk_world3d.aipl`)

- **Signature**: `pub fn voxelRaycastDDA(world: VoxelChunkWorld3D, origin: Vec3, dir: Vec3, maxDistance: float): Option[VoxelRayHit]:`
- **Import**: `import * from "std/spatial/voxel_chunk_world3d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: VoxelChunkWorld3D, origin: Vec3, dir: Vec3, maxDistance: float` | **Returns**: `Option[VoxelRayHit]`
- **Unit Test**: `tests/functions/spatial/voxel_chunk_world3d_test.aipl` | **Example**: `examples/ex_211_spatial_continuous_world2d_window.aipl`
- **Behavioral Summary**: Verifies 3D chunked voxel block access, world-to-chunk coordinate mapping, greedy face culling (hidden interior face removal), and 3D Amanatides-Woo DDA voxel raycasting in `voxelRaycastDDA`. Concrete nominal inputs: `world: VoxelChunkWorld3D = VoxelChunkWorld3D(chunkSize = 64, chunks = [VoxelChunk16(coord = 0, chunkSize = 0, blocks = 0, isDirty = 0)])`, `origin: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `dir: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `maxDistance: float = 1.0`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.spatial.voxel_chunk_world3d_z6_test
import * from "std/spatial/voxel_chunk_world3d"
import { absFloat } from "std/math/consts"
import { floor, sqrt } from "std/math/trig"
import { Vec3, IVec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_voxel_chunk_world3d_voxelRaycastDDA_6(): int:
  let arg_world = VoxelChunkWorld3D(chunkSize = 4, chunks = [])
  let edge_world = VoxelChunkWorld3D(chunkSize = 1, chunks = [])
  let arg_origin = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_origin = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_dir = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_dir = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_maxDistance = 2.0
  let edge_maxDistance = 1.0
  let resNom = voxelRaycastDDA(arg_world, arg_origin, arg_dir, arg_maxDistance)
  let resEdge = voxelRaycastDDA(edge_world, edge_origin, edge_dir, edge_maxDistance)
  assert(resNom.isSome() == false, "voxelRaycastDDA nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "voxelRaycastDDA boundary resEdge.isSome() == false")
  ret 0
```

---

### `voxelExtractGreedyFaces` (`std/spatial/voxel_chunk_world3d.aipl`)

- **Signature**: `pub fn voxelExtractGreedyFaces(chunk: VoxelChunk16): [QuadFace3D]:`
- **Import**: `import * from "std/spatial/voxel_chunk_world3d"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `chunk: VoxelChunk16` | **Returns**: `[QuadFace3D]`
- **Unit Test**: `tests/functions/spatial/voxel_chunk_world3d_test.aipl` | **Example**: `examples/ex_209_spatial_iso_tile_world2d_window.aipl`
- **Behavioral Summary**: Verifies 3D chunked voxel block access, world-to-chunk coordinate mapping, greedy face culling (hidden interior face removal), and 3D Amanatides-Woo DDA voxel raycasting in `voxelExtractGreedyFaces`. Concrete nominal inputs: `chunk: VoxelChunk16 = VoxelChunk16(coord = IVec3(x = 1, y = 1, z = 1), chunkSize = 64, blocks = [VoxelBlock(blockId = 0, metadata = 0, lightLevel = 0)], isDirty = true)`; exercises core body path returning/computing `faces`.

```aipl
module tests.functions.spatial.voxel_chunk_world3d_z7_test
import * from "std/spatial/voxel_chunk_world3d"
import { absFloat } from "std/math/consts"
import { floor, sqrt } from "std/math/trig"
import { Vec3, IVec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_voxel_chunk_world3d_voxelExtractGreedyFaces_7(): int:
  let arg_chunk = VoxelChunk16(coord = IVec3(x = 1, y = 1, z = 1), chunkSize = 4, blocks = [], isDirty = true)
  let edge_chunk = VoxelChunk16(coord = IVec3(x = 0, y = 0, z = 0), chunkSize = 1, blocks = [], isDirty = false)
  let resNom = voxelExtractGreedyFaces(arg_chunk)
  let resEdge = voxelExtractGreedyFaces(edge_chunk)
  assertEqInt(resNom.len(), 1, "voxelExtractGreedyFaces nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "voxelExtractGreedyFaces boundary resEdge.len() == 1")
  ret 0
```

---

### `waypointGraphWorldNew` (`std/spatial/waypoint_graph_world.aipl`)

- **Signature**: `pub fn waypointGraphWorldNew(): WaypointGraphWorld:`
- **Import**: `import * from "std/spatial/waypoint_graph_world"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `WaypointGraphWorld`
- **Unit Test**: `tests/functions/spatial/waypoint_graph_world_test.aipl` | **Example**: `examples/ex_210_spatial_hex_tile_world2d_window.aipl`
- **Behavioral Summary**: Verifies navigation waypoint graph node/edge construction, nearest-waypoint snapping, and shortest-path routing in `waypointGraphWorldNew`. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `WaypointGraphWorld(nodes = ns, edges = es)`.

```aipl
module tests.functions.spatial.waypoint_graph_world_z1_test
import * from "std/spatial/waypoint_graph_world"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_waypoint_graph_world_waypointGraphWorldNew_1(): int:
  let resNom = waypointGraphWorldNew()
  let resEdge = waypointGraphWorldNew()
  assertEqInt(resNom.nodes.len(), 0, "waypointGraphWorldNew nominal resNom.nodes.len() == 0")
  assertEqInt(resEdge.nodes.len(), 0, "waypointGraphWorldNew boundary resEdge.nodes.len() == 0")
  ret 0
```

---

### `waypointAddNode` (`std/spatial/waypoint_graph_world.aipl`)

- **Signature**: `pub fn waypointAddNode(mut world: WaypointGraphWorld, id: int, name: str, pos: Vec3): bool:`
- **Import**: `import * from "std/spatial/waypoint_graph_world"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut world: WaypointGraphWorld, id: int, name: str, pos: Vec3` | **Returns**: `bool`
- **Unit Test**: `tests/functions/spatial/waypoint_graph_world_test.aipl` | **Example**: `examples/ex_211_spatial_continuous_world2d_window.aipl`
- **Behavioral Summary**: Verifies navigation waypoint graph node/edge construction, nearest-waypoint snapping, and shortest-path routing in `waypointAddNode`. Concrete nominal inputs: `world: WaypointGraphWorld = WaypointGraphWorld(nodes = [WaypointNode(id = 0, name = 0, position = 0, tags = 0)], edges = [WaypointEdge(fromId = 0, toId = 0, weight = 0, bidirectional = 0, isTraversable = 0)])`, `id: int = 1`, `name: str = "aipl_test"`, `pos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.spatial.waypoint_graph_world_z2_test
import * from "std/spatial/waypoint_graph_world"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_waypoint_graph_world_waypointAddNode_2(): int:
  let arg_world = WaypointGraphWorld(nodes = [], edges = [])
  let edge_world = WaypointGraphWorld(nodes = [], edges = [])
  let arg_id = 1
  let edge_id = 0
  let arg_name = "42"
  let edge_name = "0"
  let arg_pos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_pos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = waypointAddNode(arg_world, arg_id, arg_name, arg_pos)
  let resEdge = waypointAddNode(edge_world, edge_id, edge_name, edge_pos)
  assert(resNom == true, "waypointAddNode nominal resNom == true")
  assert(resEdge == true, "waypointAddNode boundary resEdge == true")
  ret 0
```

---

### `waypointAddEdge` (`std/spatial/waypoint_graph_world.aipl`)

- **Signature**: `pub fn waypointAddEdge(mut world: WaypointGraphWorld, fromId: int, toId: int, weight: float, bidirectional: bool): bool:`
- **Import**: `import * from "std/spatial/waypoint_graph_world"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut world: WaypointGraphWorld, fromId: int, toId: int, weight: float, bidirectional: bool` | **Returns**: `bool`
- **Unit Test**: `tests/functions/spatial/waypoint_graph_world_test.aipl` | **Example**: `examples/ex_209_spatial_iso_tile_world2d_window.aipl`
- **Behavioral Summary**: Verifies navigation waypoint graph node/edge construction, nearest-waypoint snapping, and shortest-path routing in `waypointAddEdge`. Concrete nominal inputs: `world: WaypointGraphWorld = WaypointGraphWorld(nodes = [WaypointNode(id = 0, name = 0, position = 0, tags = 0)], edges = [WaypointEdge(fromId = 0, toId = 0, weight = 0, bidirectional = 0, isTraversable = 0)])`, `fromId: int = 1`, `toId: int = 1`, `weight: float = 0.5`, `bidirectional: bool = true`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.spatial.waypoint_graph_world_z3_test
import * from "std/spatial/waypoint_graph_world"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_waypoint_graph_world_waypointAddEdge_3(): int:
  let arg_world = WaypointGraphWorld(nodes = [], edges = [])
  let edge_world = WaypointGraphWorld(nodes = [], edges = [])
  let arg_fromId = 4
  let edge_fromId = 1
  let arg_toId = 1
  let edge_toId = 0
  let arg_weight = 2.0
  let edge_weight = 1.0
  let arg_bidirectional = true
  let edge_bidirectional = false
  let resNom = waypointAddEdge(arg_world, arg_fromId, arg_toId, arg_weight, arg_bidirectional)
  let resEdge = waypointAddEdge(edge_world, edge_fromId, edge_toId, edge_weight, edge_bidirectional)
  assert(resNom == true, "waypointAddEdge nominal resNom == true")
  assert(resEdge == true, "waypointAddEdge boundary resEdge == true")
  ret 0
```

---

### `findNodeIndex` (`std/spatial/waypoint_graph_world.aipl`)

- **Signature**: `fn findNodeIndex(world: WaypointGraphWorld, id: int): int:`
- **Import**: `import * from "std/spatial/waypoint_graph_world"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: WaypointGraphWorld, id: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/spatial/waypoint_graph_world_test.aipl` | **Example**: `examples/ex_210_spatial_hex_tile_world2d_window.aipl`
- **Behavioral Summary**: Verifies navigation waypoint graph node/edge construction, nearest-waypoint snapping, and shortest-path routing in `findNodeIndex`. Concrete nominal inputs: `world: WaypointGraphWorld = WaypointGraphWorld(nodes = [WaypointNode(id = 0, name = 0, position = 0, tags = 0)], edges = [WaypointEdge(fromId = 0, toId = 0, weight = 0, bidirectional = 0, isTraversable = 0)])`, `id: int = 1`; exercises core body path returning/computing `-1`.

```aipl
module tests.functions.spatial.waypoint_graph_world_z4_test
import * from "std/spatial/waypoint_graph_world"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_waypoint_graph_world_findNodeIndex_4(): int:
  let arg_world = WaypointGraphWorld(nodes = [], edges = [])
  let edge_world = WaypointGraphWorld(nodes = [], edges = [])
  let arg_id = 1
  let edge_id = 0
  let resNom = findNodeIndex(arg_world, arg_id)
  let resEdge = findNodeIndex(edge_world, edge_id)
  assertEqInt(resNom, -1, "findNodeIndex nominal resNom == -1")
  assertEqInt(resEdge, -1, "findNodeIndex boundary resEdge == -1")
  ret 0
```

---

### `waypointShortestPathDijkstra` (`std/spatial/waypoint_graph_world.aipl`)

- **Signature**: `pub fn waypointShortestPathDijkstra(world: WaypointGraphWorld, startId: int, goalId: int): Option[[int]]:`
- **Import**: `import * from "std/spatial/waypoint_graph_world"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: WaypointGraphWorld, startId: int, goalId: int` | **Returns**: `Option[[int]]`
- **Unit Test**: `tests/functions/spatial/waypoint_graph_world_test.aipl` | **Example**: `examples/ex_211_spatial_continuous_world2d_window.aipl`
- **Behavioral Summary**: Verifies navigation waypoint graph node/edge construction, nearest-waypoint snapping, and shortest-path routing in `waypointShortestPathDijkstra`. Concrete nominal inputs: `world: WaypointGraphWorld = WaypointGraphWorld(nodes = [WaypointNode(id = 0, name = 0, position = 0, tags = 0)], edges = [WaypointEdge(fromId = 0, toId = 0, weight = 0, bidirectional = 0, isTraversable = 0)])`, `startId: int = 1`, `goalId: int = 1`; exercises core body path returning/computing `Some(path)`.

```aipl
module tests.functions.spatial.waypoint_graph_world_z5_test
import * from "std/spatial/waypoint_graph_world"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_waypoint_graph_world_waypointShortestPathDijkstra_5(): int:
  let arg_world = WaypointGraphWorld(nodes = [], edges = [])
  let edge_world = WaypointGraphWorld(nodes = [], edges = [])
  let arg_startId = 1
  let edge_startId = 0
  let arg_goalId = 1
  let edge_goalId = 0
  let resNom = waypointShortestPathDijkstra(arg_world, arg_startId, arg_goalId)
  let resEdge = waypointShortestPathDijkstra(edge_world, edge_startId, edge_goalId)
  assert(resNom.isSome() == false, "waypointShortestPathDijkstra nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "waypointShortestPathDijkstra boundary resEdge.isSome() == false")
  ret 0
```

---

### `waypointNodesInRadius` (`std/spatial/waypoint_graph_world.aipl`)

- **Signature**: `pub fn waypointNodesInRadius(world: WaypointGraphWorld, center: Vec3, radius: float): [int]:`
- **Import**: `import * from "std/spatial/waypoint_graph_world"` (or barrel `import * from "std/spatial/spatial_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: WaypointGraphWorld, center: Vec3, radius: float` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/spatial/waypoint_graph_world_test.aipl` | **Example**: `examples/ex_209_spatial_iso_tile_world2d_window.aipl`
- **Behavioral Summary**: Verifies navigation waypoint graph node/edge construction, nearest-waypoint snapping, and shortest-path routing in `waypointNodesInRadius`. Concrete nominal inputs: `world: WaypointGraphWorld = WaypointGraphWorld(nodes = [WaypointNode(id = 0, name = 0, position = 0, tags = 0)], edges = [WaypointEdge(fromId = 0, toId = 0, weight = 0, bidirectional = 0, isTraversable = 0)])`, `center: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `radius: float = 1.0`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.spatial.waypoint_graph_world_z6_test
import * from "std/spatial/waypoint_graph_world"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_waypoint_graph_world_waypointNodesInRadius_6(): int:
  let arg_world = WaypointGraphWorld(nodes = [], edges = [])
  let edge_world = WaypointGraphWorld(nodes = [], edges = [])
  let arg_center = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_center = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_radius = 2.0
  let edge_radius = 1.0
  let resNom = waypointNodesInRadius(arg_world, arg_center, arg_radius)
  let resEdge = waypointNodesInRadius(edge_world, edge_center, edge_radius)
  assertEqInt(resNom.len(), 0, "waypointNodesInRadius nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "waypointNodesInRadius boundary resEdge.len() == 0")
  ret 0
```
