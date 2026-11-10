[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 06: `collections` API Reference

> Complete API reference manual for AIPL standard library domain `collections` (220 callable functions & methods across ["std/collections/bitset.aipl", "std/collections/btree_map.aipl", "std/collections/bvh_tree.aipl", "std/collections/collections_mod.aipl", "std/collections/deque.aipl", "std/collections/dyn_vec.aipl", "std/collections/graph_topology.aipl", "std/collections/grid2d_array.aipl", "std/collections/hash_map.aipl", "std/collections/octree.aipl", "std/collections/priority_queue.aipl", "std/collections/quadtree.aipl", "std/collections/sparse_set.aipl", "std/collections/spatial_hash.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `collections`
- **Target Source Modules**: ["std/collections/bitset.aipl", "std/collections/btree_map.aipl", "std/collections/bvh_tree.aipl", "std/collections/collections_mod.aipl", "std/collections/deque.aipl", "std/collections/dyn_vec.aipl", "std/collections/graph_topology.aipl", "std/collections/grid2d_array.aipl", "std/collections/hash_map.aipl", "std/collections/octree.aipl", "std/collections/priority_queue.aipl", "std/collections/quadtree.aipl", "std/collections/sparse_set.aipl", "std/collections/spatial_hash.aipl"]
- **Total Callable Functions & Methods**: 220
- **Total Data Types (`struct` & `enum`)**: 34
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(34 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `DynamicBitSet` | `pub struct` | `std/collections/bitset.aipl` | `words: [int]`, `bitCount: int` | `DynamicBitSet(words, bitCount)` |
| `BloomFilter` | `pub struct` | `std/collections/bitset.aipl` | `bits: DynamicBitSet`, `numHashes: int` | `BloomFilter(bits, numHashes)` |
| `BTreeNode[K, V]` | `pub struct` | `std/collections/btree_map.aipl` | `isLeaf: bool`, `keys: [K]`, `values: [V]`, `children: [BTreeNode[K, V]]` | `BTreeNode(isLeaf, keys, values, children)` |
| `BTreeMap[K, V]` | `pub struct` | `std/collections/btree_map.aipl` | `root: Option[BTreeNode[K, V]]`, `order: int`, `count: int` | `BTreeMap(root, order, count)` |
| `BvhAabb` | `pub struct` | `std/collections/bvh_tree.aipl` | `minX: float`, `minY: float`, `minZ: float`, `maxX: float`, `maxY: float`, `maxZ: float` | `BvhAabb(minX, minY, minZ, maxX, maxY, maxZ)` |
| `BvhNode` | `pub struct` | `std/collections/bvh_tree.aipl` | `bounds: BvhAabb`, `leftChild: int`, `rightChild: int`, `primitiveIndex: int`, `isLeaf: bool` | `BvhNode(bounds, leftChild, rightChild, primitiveIndex, isLeaf)` |
| `BvhTree3D` | `pub struct` | `std/collections/bvh_tree.aipl` | `nodes: [BvhNode]`, `rootIndex: int` | `BvhTree3D(nodes, rootIndex)` |
| `Deque[T]` | `pub struct` | `std/collections/deque.aipl` | `front: [T]`, `back: [T]` | `Deque(front, back)` |
| `CircularRingQueue[T]` | `pub struct` | `std/collections/deque.aipl` | `buffer: [T]`, `head: int`, `tail: int`, `capacity: int`, `count: int` | `CircularRingQueue(buffer, head, tail, capacity, count)` |
| `UndoStack` | `pub struct` | `std/collections/deque.aipl` | `past: [any]`, `future: [any]`, `maxDepth: int` | `UndoStack(past, future, maxDepth)` |
| `DynVec[T]` | `pub struct` | `std/collections/dyn_vec.aipl` | `items: [T]`, `capacity: int` | `DynVec(items, capacity)` |
| `ArraySlice[T]` | `pub struct` | `std/collections/dyn_vec.aipl` | `items: [T]`, `start: int`, `end: int` | `ArraySlice(items, start, end)` |
| `DisjointSetUnion` | `pub struct` | `std/collections/graph_topology.aipl` | `parent: [int]`, `rank: [int]`, `numSets: int` | `DisjointSetUnion(parent, rank, numSets)` |
| `DirectedGraph` | `pub struct` | `std/collections/graph_topology.aipl` | `numNodes: int`, `adjacency: [[int]]`, `weights: [[int]]` | `DirectedGraph(numNodes, adjacency, weights)` |
| `FlatArray2D[T]` | `pub struct` | `std/collections/grid2d_array.aipl` | `width: int`, `height: int`, `data: [T]` | `FlatArray2D(width, height, data)` |
| `FlatArray3D[T]` | `pub struct` | `std/collections/grid2d_array.aipl` | `width: int`, `height: int`, `depth: int`, `data: [T]` | `FlatArray3D(width, height, depth, data)` |
| `HashMap[K, V]` | `pub struct` | `std/collections/hash_map.aipl` | `keys: [K]`, `values: [V]`, `ctrl: [int]`, `capacity: int`, `count: int` | `HashMap(keys, values, ctrl, capacity, count)` |
| `HashSet[T]` | `pub struct` | `std/collections/hash_map.aipl` | `map: HashMap[T, bool]` | `HashSet(map)` |
| `LruCache[K, V]` | `pub struct` | `std/collections/hash_map.aipl` | `map: HashMap[K, V]`, `order: [K]`, `maxEntries: int` | `LruCache(map, order, maxEntries)` |
| `OctreeItem[T]` | `pub struct` | `std/collections/octree.aipl` | `x: float`, `y: float`, `z: float`, `payload: T` | `OctreeItem(x, y, z, payload)` |
| `OctreeNode[T]` | `pub struct` | `std/collections/octree.aipl` | `minX: float`, `minY: float`, `minZ: float`, `maxX: float`, `maxY: float`, `maxZ: float`, `capacity: int`, `items: [OctreeItem[T]]`, `divided: bool`, `children: [Option[OctreeNode[T]]]` | `OctreeNode(minX, minY, minZ, maxX, maxY, maxZ, capacity, items, divided, children)` |
| `BinaryMinHeap[T]` | `pub struct` | `std/collections/priority_queue.aipl` | `items: [T]`, `priorities: [int]` | `BinaryMinHeap(items, priorities)` |
| `BinaryMaxHeap[T]` | `pub struct` | `std/collections/priority_queue.aipl` | `items: [T]`, `priorities: [int]` | `BinaryMaxHeap(items, priorities)` |
| `IndexedPriorityQueue` | `pub struct` | `std/collections/priority_queue.aipl` | `priorities: [int]`, `heapIndices: [int]`, `inverseHeap: [int]` | `IndexedPriorityQueue(priorities, heapIndices, inverseHeap)` |
| `PriorityQueue` | `pub struct` | `std/collections/priority_queue.aipl` | `nodes: [int]`, `costs: [int]` | `PriorityQueue(nodes, costs)` |
| `HeapItem` | `pub struct` | `std/collections/priority_queue.aipl` | `priority: float`, `item: any` | `HeapItem(priority, item)` |
| `MinHeap` | `pub struct` | `std/collections/priority_queue.aipl` | `items: [HeapItem]` | `MinHeap(items)` |
| `BinaryHeap` | `pub struct` | `std/collections/priority_queue.aipl` | `priorities: [int]`, `values: [any]`, `isMax: bool` | `BinaryHeap(priorities, values, isMax)` |
| `HeapPopResult` | `pub struct` | `std/collections/priority_queue.aipl` | `heap: BinaryHeap`, `value: any`, `priority: int` | `HeapPopResult(heap, value, priority)` |
| `QuadtreeItem[T]` | `pub struct` | `std/collections/quadtree.aipl` | `x: float`, `y: float`, `payload: T` | `QuadtreeItem(x, y, payload)` |
| `QuadtreeNode[T]` | `pub struct` | `std/collections/quadtree.aipl` | `boundaryX: float`, `boundaryY: float`, `boundaryW: float`, `boundaryH: float`, `capacity: int`, `items: [QuadtreeItem[T]]`, `divided: bool`, `nw: Option[QuadtreeNode[T]]`, `ne: Option[QuadtreeNode[T]]`, `sw: Option[QuadtreeNode[T]]`, `se: Option[QuadtreeNode[T]]` | `QuadtreeNode(boundaryX, boundaryY, boundaryW, boundaryH, capacity, items, divided, nw, ne, sw, se)` |
| `SparseSet[T]` | `pub struct` | `std/collections/sparse_set.aipl` | `dense: [int]`, `sparse: [int]`, `values: [T]`, `count: int` | `SparseSet(dense, sparse, values, count)` |
| `SpatialHashEntry2D[T]` | `pub struct` | `std/collections/spatial_hash.aipl` | `x: float`, `y: float`, `val: T` | `SpatialHashEntry2D(x, y, val)` |
| `SpatialHashGrid2D[T]` | `pub struct` | `std/collections/spatial_hash.aipl` | `cellSize: float`, `buckets: HashMap[int, [SpatialHashEntry2D[T]]]`, `entries: [SpatialHashEntry2D[T]]` | `SpatialHashGrid2D(cellSize, buckets, entries)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/collections/bitset.aipl` | `bitsetNew` | `pub fn bitsetNew(size: int): DynamicBitSet:` | `tests/functions/collections/bitset_test.aipl` |
| `2` | `std/collections/bitset.aipl` | `set` | `pub fn (mut self: DynamicBitSet) set(index: int): void:` | `tests/functions/collections/bitset_test.aipl` |
| `3` | `std/collections/bitset.aipl` | `clear` | `pub fn (mut self: DynamicBitSet) clear(index: int): void:` | `tests/functions/collections/bitset_test.aipl` |
| `4` | `std/collections/bitset.aipl` | `toggle` | `pub fn (mut self: DynamicBitSet) toggle(index: int): void:` | `tests/functions/collections/bitset_test.aipl` |
| `5` | `std/collections/bitset.aipl` | `test` | `pub fn (self: DynamicBitSet) test(index: int): bool:` | `tests/functions/collections/bitset_test.aipl` |
| `6` | `std/collections/bitset.aipl` | `countOnes` | `pub fn (self: DynamicBitSet) countOnes(): int:` | `tests/functions/collections/bitset_test.aipl` |
| `7` | `std/collections/bitset.aipl` | `countZeros` | `pub fn (self: DynamicBitSet) countZeros(): int:` | `tests/functions/collections/bitset_test.aipl` |
| `8` | `std/collections/bitset.aipl` | `clearAll` | `pub fn (mut self: DynamicBitSet) clearAll(): void:` | `tests/functions/collections/bitset_test.aipl` |
| `9` | `std/collections/bitset.aipl` | `bitwiseAnd` | `pub fn (mut self: DynamicBitSet) bitwiseAnd(other: DynamicBitSet): void:` | `tests/functions/collections/bitset_test.aipl` |
| `10` | `std/collections/bitset.aipl` | `bitwiseOr` | `pub fn (mut self: DynamicBitSet) bitwiseOr(other: DynamicBitSet): void:` | `tests/functions/collections/bitset_test.aipl` |
| `11` | `std/collections/bitset.aipl` | `bitwiseXor` | `pub fn (mut self: DynamicBitSet) bitwiseXor(other: DynamicBitSet): void:` | `tests/functions/collections/bitset_test.aipl` |
| `12` | `std/collections/bitset.aipl` | `bloomHashStr` | `pub fn bloomHashStr(strKey: str, seed: int): int:` | `tests/functions/collections/bitset_test.aipl` |
| `13` | `std/collections/bitset.aipl` | `bloomFilterNew` | `pub fn bloomFilterNew(capacity: int, fpp: float): BloomFilter:` | `tests/functions/collections/bitset_test.aipl` |
| `14` | `std/collections/bitset.aipl` | `add` | `pub fn (mut self: BloomFilter) add(strKey: str): void:` | `tests/functions/collections/bitset_test.aipl` |
| `15` | `std/collections/bitset.aipl` | `contains` | `pub fn (self: BloomFilter) contains(strKey: str): bool:` | `tests/functions/collections/bitset_test.aipl` |
| `16` | `std/collections/btree_map.aipl` | `btreeNodeNew` | `pub fn btreeNodeNew[K, V](isLeaf: bool): BTreeNode[K, V]:` | `tests/functions/collections/btree_map_test.aipl` |
| `17` | `std/collections/btree_map.aipl` | `btreeMapNew` | `pub fn btreeMapNew[K, V](order: int): BTreeMap[K, V]:` | `tests/functions/collections/btree_map_test.aipl` |
| `18` | `std/collections/btree_map.aipl` | `insert` | `pub fn (mut self: BTreeMap[K, V]) insert(key: K, val: V): void:` | `tests/functions/collections/btree_map_test.aipl` |
| `19` | `std/collections/btree_map.aipl` | `get` | `pub fn (self: BTreeMap[K, V]) get(key: K): Option[V]:` | `tests/functions/collections/btree_map_test.aipl` |
| `20` | `std/collections/btree_map.aipl` | `containsKey` | `pub fn (self: BTreeMap[K, V]) containsKey(key: K): bool:` | `tests/functions/collections/btree_map_test.aipl` |
| `21` | `std/collections/btree_map.aipl` | `len` | `pub fn (self: BTreeMap[K, V]) len(): int:` | `tests/functions/collections/btree_map_test.aipl` |
| `22` | `std/collections/btree_map.aipl` | `isEmpty` | `pub fn (self: BTreeMap[K, V]) isEmpty(): bool:` | `tests/functions/collections/btree_map_test.aipl` |
| `23` | `std/collections/btree_map.aipl` | `range` | `pub fn (self: BTreeMap[K, V]) range(minKey: K, maxKey: K): [V]:` | `tests/functions/collections/btree_map_test.aipl` |
| `24` | `std/collections/btree_map.aipl` | `minKey` | `pub fn (self: BTreeMap[K, V]) minKey(): Option[K]:` | `tests/functions/collections/btree_map_test.aipl` |
| `25` | `std/collections/btree_map.aipl` | `maxKey` | `pub fn (self: BTreeMap[K, V]) maxKey(): Option[K]:` | `tests/functions/collections/btree_map_test.aipl` |
| `26` | `std/collections/btree_map.aipl` | `keys` | `pub fn (self: BTreeMap[K, V]) keys(): [K]:` | `tests/functions/collections/btree_map_test.aipl` |
| `27` | `std/collections/btree_map.aipl` | `values` | `pub fn (self: BTreeMap[K, V]) values(): [V]:` | `tests/functions/collections/btree_map_test.aipl` |
| `28` | `std/collections/bvh_tree.aipl` | `bvhAabbUnion` | `pub fn bvhAabbUnion(a: BvhAabb, b: BvhAabb): BvhAabb:` | `tests/functions/collections/bvh_tree_test.aipl` |
| `29` | `std/collections/bvh_tree.aipl` | `bvhAabbSurfaceArea` | `pub fn bvhAabbSurfaceArea(b: BvhAabb): float:` | `tests/functions/collections/bvh_tree_test.aipl` |
| `30` | `std/collections/bvh_tree.aipl` | `bvhAabbRayHit` | `pub fn bvhAabbRayHit(b: BvhAabb, ox: float, oy: float, oz: float, dx: float, dy: float, dz: float): bool:` | `tests/functions/collections/bvh_tree_test.aipl` |
| `31` | `std/collections/bvh_tree.aipl` | `bvhBuildSAH` | `pub fn bvhBuildSAH(boxes: [BvhAabb]): BvhTree3D:` | `tests/functions/collections/bvh_tree_test.aipl` |
| `32` | `std/collections/bvh_tree.aipl` | `rayIntersect` | `pub fn (self: BvhTree3D) rayIntersect(rayOriginX: float, rayOriginY: float, rayOriginZ: float, rayDirX: float, rayDirY: float, rayDirZ: float): [int]:` | `tests/functions/collections/bvh_tree_test.aipl` |
| `33` | `std/collections/deque.aipl` | `dequeNew` | `pub fn dequeNew[T](): Deque[T]:` | `tests/functions/collections/deque_test.aipl` |
| `34` | `std/collections/deque.aipl` | `pushFront` | `pub fn (mut self: Deque[T]) pushFront(item: T): void:` | `tests/functions/collections/deque_test.aipl` |
| `35` | `std/collections/deque.aipl` | `pushBack` | `pub fn (mut self: Deque[T]) pushBack(item: T): void:` | `tests/functions/collections/deque_test.aipl` |
| `36` | `std/collections/deque.aipl` | `popFront` | `pub fn (mut self: Deque[T]) popFront(): Option[T]:` | `tests/functions/collections/deque_test.aipl` |
| `37` | `std/collections/deque.aipl` | `popBack` | `pub fn (mut self: Deque[T]) popBack(): Option[T]:` | `tests/functions/collections/deque_test.aipl` |
| `38` | `std/collections/deque.aipl` | `peekFront` | `pub fn (self: Deque[T]) peekFront(): Option[T]:` | `tests/functions/collections/deque_test.aipl` |
| `39` | `std/collections/deque.aipl` | `peekBack` | `pub fn (self: Deque[T]) peekBack(): Option[T]:` | `tests/functions/collections/deque_test.aipl` |
| `40` | `std/collections/deque.aipl` | `len` | `pub fn (self: Deque[T]) len(): int:` | `tests/functions/collections/deque_test.aipl` |
| `41` | `std/collections/deque.aipl` | `isEmpty` | `pub fn (self: Deque[T]) isEmpty(): bool:` | `tests/functions/collections/deque_test.aipl` |
| `42` | `std/collections/deque.aipl` | `clear` | `pub fn (mut self: Deque[T]) clear(): void:` | `tests/functions/collections/deque_test.aipl` |
| `43` | `std/collections/deque.aipl` | `toArray` | `pub fn (self: Deque[T]) toArray(): [T]:` | `tests/functions/collections/deque_test.aipl` |
| `44` | `std/collections/deque.aipl` | `dequeLen` | `pub fn dequeLen[T](d: Deque[T]): int:` | `tests/functions/collections/deque_test.aipl` |
| `45` | `std/collections/deque.aipl` | `dequeIsEmpty` | `pub fn dequeIsEmpty[T](d: Deque[T]): bool:` | `tests/functions/collections/deque_test.aipl` |
| `46` | `std/collections/deque.aipl` | `dequePushBack` | `pub fn dequePushBack[T](mut d: Deque[T], item: T): Deque[T]:` | `tests/functions/collections/deque_test.aipl` |
| `47` | `std/collections/deque.aipl` | `dequePushFront` | `pub fn dequePushFront[T](mut d: Deque[T], item: T): Deque[T]:` | `tests/functions/collections/deque_test.aipl` |
| `48` | `std/collections/deque.aipl` | `dequePopBack` | `pub fn dequePopBack[T](mut d: Deque[T]): Option[T]:` | `tests/functions/collections/deque_test.aipl` |
| `49` | `std/collections/deque.aipl` | `dequePopFront` | `pub fn dequePopFront[T](mut d: Deque[T]): Option[T]:` | `tests/functions/collections/deque_test.aipl` |
| `50` | `std/collections/deque.aipl` | `dequePeekFront` | `pub fn dequePeekFront[T](d: Deque[T]): Option[T]:` | `tests/functions/collections/deque_test.aipl` |
| `51` | `std/collections/deque.aipl` | `dequePeekBack` | `pub fn dequePeekBack[T](d: Deque[T]): Option[T]:` | `tests/functions/collections/deque_test.aipl` |
| `52` | `std/collections/deque.aipl` | `dequeToArray` | `pub fn dequeToArray[T](d: Deque[T]): [T]:` | `tests/functions/collections/deque_test.aipl` |
| `53` | `std/collections/deque.aipl` | `circularRingQueueNew` | `pub fn circularRingQueueNew[T](capacity: int): CircularRingQueue[T]:` | `tests/functions/collections/deque_test.aipl` |
| `54` | `std/collections/deque.aipl` | `enqueue` | `pub fn (mut self: CircularRingQueue[T]) enqueue(item: T): bool:` | `tests/functions/collections/deque_test.aipl` |
| `55` | `std/collections/deque.aipl` | `dequeue` | `pub fn (mut self: CircularRingQueue[T]) dequeue(): Option[T]:` | `tests/functions/collections/deque_test.aipl` |
| `56` | `std/collections/deque.aipl` | `len` | `pub fn (self: CircularRingQueue[T]) len(): int:` | `tests/functions/collections/deque_test.aipl` |
| `57` | `std/collections/deque.aipl` | `isEmpty` | `pub fn (self: CircularRingQueue[T]) isEmpty(): bool:` | `tests/functions/collections/deque_test.aipl` |
| `58` | `std/collections/deque.aipl` | `isFull` | `pub fn (self: CircularRingQueue[T]) isFull(): bool:` | `tests/functions/collections/deque_test.aipl` |
| `59` | `std/collections/deque.aipl` | `ringBufferNew` | `pub fn ringBufferNew[T](capacity: int): CircularRingQueue[T]:` | `tests/functions/collections/deque_test.aipl` |
| `60` | `std/collections/deque.aipl` | `ringBufferLen` | `pub fn ringBufferLen[T](rb: CircularRingQueue[T]): int:` | `tests/functions/collections/deque_test.aipl` |
| `61` | `std/collections/deque.aipl` | `ringBufferIsEmpty` | `pub fn ringBufferIsEmpty[T](rb: CircularRingQueue[T]): bool:` | `tests/functions/collections/deque_test.aipl` |
| `62` | `std/collections/deque.aipl` | `ringBufferPush` | `pub fn ringBufferPush[T](mut rb: CircularRingQueue[T], item: T): CircularRingQueue[T]:` | `tests/functions/collections/deque_test.aipl` |
| `63` | `std/collections/deque.aipl` | `ringBufferGet` | `pub fn ringBufferGet[T](rb: CircularRingQueue[T], idx: int): Option[T]:` | `tests/functions/collections/deque_test.aipl` |
| `64` | `std/collections/deque.aipl` | `ringBufferToArray` | `pub fn ringBufferToArray[T](rb: CircularRingQueue[T]): [T]:` | `tests/functions/collections/deque_test.aipl` |
| `65` | `std/collections/deque.aipl` | `undoStackNew` | `pub fn undoStackNew(maxDepth: int = 50): UndoStack:` | `tests/functions/collections/deque_test.aipl` |
| `66` | `std/collections/deque.aipl` | `undoCanUndo` | `pub fn undoCanUndo(us: UndoStack): bool:` | `tests/functions/collections/deque_test.aipl` |
| `67` | `std/collections/deque.aipl` | `undoCanRedo` | `pub fn undoCanRedo(us: UndoStack): bool:` | `tests/functions/collections/deque_test.aipl` |
| `68` | `std/collections/deque.aipl` | `undoPush` | `pub fn undoPush(mut us: UndoStack, item: any): UndoStack:` | `tests/functions/collections/deque_test.aipl` |
| `69` | `std/collections/deque.aipl` | `undoStep` | `pub fn undoStep(mut us: UndoStack): Option[any]:` | `tests/functions/collections/deque_test.aipl` |
| `70` | `std/collections/deque.aipl` | `redoStep` | `pub fn redoStep(mut us: UndoStack): Option[any]:` | `tests/functions/collections/deque_test.aipl` |
| `71` | `std/collections/dyn_vec.aipl` | `dynVecNew` | `pub fn dynVecNew[T](): DynVec[T]:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `72` | `std/collections/dyn_vec.aipl` | `dynVecWithCapacity` | `pub fn dynVecWithCapacity[T](capacity: int): DynVec[T]:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `73` | `std/collections/dyn_vec.aipl` | `len` | `pub fn (self: DynVec[T]) len(): int:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `74` | `std/collections/dyn_vec.aipl` | `cap` | `pub fn (self: DynVec[T]) cap(): int:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `75` | `std/collections/dyn_vec.aipl` | `isEmpty` | `pub fn (self: DynVec[T]) isEmpty(): bool:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `76` | `std/collections/dyn_vec.aipl` | `push` | `pub fn (mut self: DynVec[T]) push(val: T): void:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `77` | `std/collections/dyn_vec.aipl` | `pop` | `pub fn (mut self: DynVec[T]) pop(): Option[T]:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `78` | `std/collections/dyn_vec.aipl` | `get` | `pub fn (self: DynVec[T]) get(index: int): Option[T]:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `79` | `std/collections/dyn_vec.aipl` | `set` | `pub fn (mut self: DynVec[T]) set(index: int, val: T): bool:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `80` | `std/collections/dyn_vec.aipl` | `insert` | `pub fn (mut self: DynVec[T]) insert(index: int, val: T): bool:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `81` | `std/collections/dyn_vec.aipl` | `remove` | `pub fn (mut self: DynVec[T]) remove(index: int): Option[T]:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `82` | `std/collections/dyn_vec.aipl` | `swapRemove` | `pub fn (mut self: DynVec[T]) swapRemove(index: int): Option[T]:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `83` | `std/collections/dyn_vec.aipl` | `clear` | `pub fn (mut self: DynVec[T]) clear(): void:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `84` | `std/collections/dyn_vec.aipl` | `reserve` | `pub fn (mut self: DynVec[T]) reserve(additional: int): void:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `85` | `std/collections/dyn_vec.aipl` | `first` | `pub fn (self: DynVec[T]) first(): Option[T]:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `86` | `std/collections/dyn_vec.aipl` | `last` | `pub fn (self: DynVec[T]) last(): Option[T]:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `87` | `std/collections/dyn_vec.aipl` | `toArray` | `pub fn (self: DynVec[T]) toArray(): [T]:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `88` | `std/collections/dyn_vec.aipl` | `reverse` | `pub fn (mut self: DynVec[T]) reverse(): void:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `89` | `std/collections/dyn_vec.aipl` | `asSlice` | `pub fn (self: DynVec[T]) asSlice(start: int, end: int): ArraySlice[T]:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `90` | `std/collections/dyn_vec.aipl` | `len` | `pub fn (self: ArraySlice[T]) len(): int:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `91` | `std/collections/dyn_vec.aipl` | `isEmpty` | `pub fn (self: ArraySlice[T]) isEmpty(): bool:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `92` | `std/collections/dyn_vec.aipl` | `get` | `pub fn (self: ArraySlice[T]) get(index: int): Option[T]:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `93` | `std/collections/dyn_vec.aipl` | `toArray` | `pub fn (self: ArraySlice[T]) toArray(): [T]:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `94` | `std/collections/dyn_vec.aipl` | `sortInts` | `pub fn sortInts(arr: [int]): [int]:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `95` | `std/collections/dyn_vec.aipl` | `sortStrings` | `pub fn sortStrings(arr: [str]): [str]:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `96` | `std/collections/dyn_vec.aipl` | `isDigitCodeSort` | `fn isDigitCodeSort(c: int): bool:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `97` | `std/collections/dyn_vec.aipl` | `naturalLess` | `fn naturalLess(a: str, b: str): bool:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `98` | `std/collections/dyn_vec.aipl` | `sortStringsNatural` | `pub fn sortStringsNatural(arr: [str]): [str]:` | `tests/functions/collections/dyn_vec_test.aipl` |
| `99` | `std/collections/graph_topology.aipl` | `dsuNew` | `pub fn dsuNew(size: int): DisjointSetUnion:` | `tests/functions/collections/graph_topology_test.aipl` |
| `100` | `std/collections/graph_topology.aipl` | `find` | `pub fn (mut self: DisjointSetUnion) find(x: int): int:` | `tests/functions/collections/graph_topology_test.aipl` |
| `101` | `std/collections/graph_topology.aipl` | `union` | `pub fn (mut self: DisjointSetUnion) union(x: int, y: int): bool:` | `tests/functions/collections/graph_topology_test.aipl` |
| `102` | `std/collections/graph_topology.aipl` | `connected` | `pub fn (mut self: DisjointSetUnion) connected(x: int, y: int): bool:` | `tests/functions/collections/graph_topology_test.aipl` |
| `103` | `std/collections/graph_topology.aipl` | `countSets` | `pub fn (self: DisjointSetUnion) countSets(): int:` | `tests/functions/collections/graph_topology_test.aipl` |
| `104` | `std/collections/graph_topology.aipl` | `directedGraphNew` | `pub fn directedGraphNew(numNodes: int): DirectedGraph:` | `tests/functions/collections/graph_topology_test.aipl` |
| `105` | `std/collections/graph_topology.aipl` | `addEdge` | `pub fn (mut self: DirectedGraph) addEdge(u: int, v: int, weight: int): void:` | `tests/functions/collections/graph_topology_test.aipl` |
| `106` | `std/collections/graph_topology.aipl` | `dijkstraShortestPath` | `pub fn (self: DirectedGraph) dijkstraShortestPath(startNode: int, endNode: int): Option[[int]]:` | `tests/functions/collections/graph_topology_test.aipl` |
| `107` | `std/collections/grid2d_array.aipl` | `flatArray2DNew` | `pub fn flatArray2DNew[T](width: int, height: int, defaultVal: T): FlatArray2D[T]:` | `tests/functions/collections/grid2d_array_test.aipl` |
| `108` | `std/collections/grid2d_array.aipl` | `inBounds` | `pub fn (self: FlatArray2D[T]) inBounds(x: int, y: int): bool:` | `tests/functions/collections/grid2d_array_test.aipl` |
| `109` | `std/collections/grid2d_array.aipl` | `index` | `pub fn (self: FlatArray2D[T]) index(x: int, y: int): int:` | `tests/functions/collections/grid2d_array_test.aipl` |
| `110` | `std/collections/grid2d_array.aipl` | `get` | `pub fn (self: FlatArray2D[T]) get(x: int, y: int): Option[T]:` | `tests/functions/collections/grid2d_array_test.aipl` |
| `111` | `std/collections/grid2d_array.aipl` | `set` | `pub fn (mut self: FlatArray2D[T]) set(x: int, y: int, val: T): bool:` | `tests/functions/collections/grid2d_array_test.aipl` |
| `112` | `std/collections/grid2d_array.aipl` | `fill` | `pub fn (mut self: FlatArray2D[T]) fill(val: T): void:` | `tests/functions/collections/grid2d_array_test.aipl` |
| `113` | `std/collections/grid2d_array.aipl` | `neighbors4` | `pub fn (self: FlatArray2D[T]) neighbors4(x: int, y: int): [T]:` | `tests/functions/collections/grid2d_array_test.aipl` |
| `114` | `std/collections/grid2d_array.aipl` | `neighbors8` | `pub fn (self: FlatArray2D[T]) neighbors8(x: int, y: int): [T]:` | `tests/functions/collections/grid2d_array_test.aipl` |
| `115` | `std/collections/grid2d_array.aipl` | `flatArray3DNew` | `pub fn flatArray3DNew[T](width: int, height: int, depth: int, defaultVal: T): FlatArray3D[T]:` | `tests/functions/collections/grid2d_array_test.aipl` |
| `116` | `std/collections/grid2d_array.aipl` | `inBounds` | `pub fn (self: FlatArray3D[T]) inBounds(x: int, y: int, z: int): bool:` | `tests/functions/collections/grid2d_array_test.aipl` |
| `117` | `std/collections/grid2d_array.aipl` | `get` | `pub fn (self: FlatArray3D[T]) get(x: int, y: int, z: int): Option[T]:` | `tests/functions/collections/grid2d_array_test.aipl` |
| `118` | `std/collections/grid2d_array.aipl` | `set` | `pub fn (mut self: FlatArray3D[T]) set(x: int, y: int, z: int, val: T): bool:` | `tests/functions/collections/grid2d_array_test.aipl` |
| `119` | `std/collections/hash_map.aipl` | `hashMapNew` | `pub fn hashMapNew[K, V](): HashMap[K, V]:` | `tests/functions/collections/hash_map_test.aipl` |
| `120` | `std/collections/hash_map.aipl` | `hashMapWithCapacity` | `pub fn hashMapWithCapacity[K, V](capacity: int): HashMap[K, V]:` | `tests/functions/collections/hash_map_test.aipl` |
| `121` | `std/collections/hash_map.aipl` | `insert` | `pub fn (mut self: HashMap[K, V]) insert(key: K, val: V): Option[V]:` | `tests/functions/collections/hash_map_test.aipl` |
| `122` | `std/collections/hash_map.aipl` | `get` | `pub fn (self: HashMap[K, V]) get(key: K): Option[V]:` | `tests/functions/collections/hash_map_test.aipl` |
| `123` | `std/collections/hash_map.aipl` | `containsKey` | `pub fn (self: HashMap[K, V]) containsKey(key: K): bool:` | `tests/functions/collections/hash_map_test.aipl` |
| `124` | `std/collections/hash_map.aipl` | `remove` | `pub fn (mut self: HashMap[K, V]) remove(key: K): Option[V]:` | `tests/functions/collections/hash_map_test.aipl` |
| `125` | `std/collections/hash_map.aipl` | `len` | `pub fn (self: HashMap[K, V]) len(): int:` | `tests/functions/collections/hash_map_test.aipl` |
| `126` | `std/collections/hash_map.aipl` | `isEmpty` | `pub fn (self: HashMap[K, V]) isEmpty(): bool:` | `tests/functions/collections/hash_map_test.aipl` |
| `127` | `std/collections/hash_map.aipl` | `clear` | `pub fn (mut self: HashMap[K, V]) clear(): void:` | `tests/functions/collections/hash_map_test.aipl` |
| `128` | `std/collections/hash_map.aipl` | `keys` | `pub fn (self: HashMap[K, V]) keys(): [K]:` | `tests/functions/collections/hash_map_test.aipl` |
| `129` | `std/collections/hash_map.aipl` | `values` | `pub fn (self: HashMap[K, V]) values(): [V]:` | `tests/functions/collections/hash_map_test.aipl` |
| `130` | `std/collections/hash_map.aipl` | `hashSetNew` | `pub fn hashSetNew[T](): HashSet[T]:` | `tests/functions/collections/hash_map_test.aipl` |
| `131` | `std/collections/hash_map.aipl` | `add` | `pub fn (mut self: HashSet[T]) add(item: T): bool:` | `tests/functions/collections/hash_map_test.aipl` |
| `132` | `std/collections/hash_map.aipl` | `contains` | `pub fn (self: HashSet[T]) contains(item: T): bool:` | `tests/functions/collections/hash_map_test.aipl` |
| `133` | `std/collections/hash_map.aipl` | `remove` | `pub fn (mut self: HashSet[T]) remove(item: T): bool:` | `tests/functions/collections/hash_map_test.aipl` |
| `134` | `std/collections/hash_map.aipl` | `len` | `pub fn (self: HashSet[T]) len(): int:` | `tests/functions/collections/hash_map_test.aipl` |
| `135` | `std/collections/hash_map.aipl` | `isEmpty` | `pub fn (self: HashSet[T]) isEmpty(): bool:` | `tests/functions/collections/hash_map_test.aipl` |
| `136` | `std/collections/hash_map.aipl` | `toArray` | `pub fn (self: HashSet[T]) toArray(): [T]:` | `tests/functions/collections/hash_map_test.aipl` |
| `137` | `std/collections/hash_map.aipl` | `lruCacheNew` | `pub fn lruCacheNew[K, V](maxEntries: int): LruCache[K, V]:` | `tests/functions/collections/hash_map_test.aipl` |
| `138` | `std/collections/hash_map.aipl` | `put` | `pub fn (mut self: LruCache[K, V]) put(key: K, val: V): void:` | `tests/functions/collections/hash_map_test.aipl` |
| `139` | `std/collections/hash_map.aipl` | `get` | `pub fn (mut self: LruCache[K, V]) get(key: K): Option[V]:` | `tests/functions/collections/hash_map_test.aipl` |
| `140` | `std/collections/hash_map.aipl` | `len` | `pub fn (self: LruCache[K, V]) len(): int:` | `tests/functions/collections/hash_map_test.aipl` |
| `141` | `std/collections/hash_map.aipl` | `mapNew` | `pub fn mapNew(): any:` | `tests/functions/collections/hash_map_test.aipl` |
| `142` | `std/collections/hash_map.aipl` | `setNew` | `pub fn setNew(): any:` | `tests/functions/collections/hash_map_test.aipl` |
| `143` | `std/collections/hash_map.aipl` | `mapGet` | `pub fn mapGet(m: any, key: any): Option[any]:` | `tests/functions/collections/hash_map_test.aipl` |
| `144` | `std/collections/hash_map.aipl` | `mapSet` | `pub fn mapSet(mut m: any, key: any, val: any): any:` | `tests/functions/collections/hash_map_test.aipl` |
| `145` | `std/collections/hash_map.aipl` | `mapGetOr` | `pub fn mapGetOr(m: any, key: any, defaultVal: any): any:` | `tests/functions/collections/hash_map_test.aipl` |
| `146` | `std/collections/hash_map.aipl` | `mapGetOrDefault` | `pub fn mapGetOrDefault(m: any, key: any, defaultVal: any): any:` | `tests/functions/collections/hash_map_test.aipl` |
| `147` | `std/collections/hash_map.aipl` | `mapGetOrInsert` | `pub fn mapGetOrInsert(mut m: any, key: any, defaultVal: any): any:` | `tests/functions/collections/hash_map_test.aipl` |
| `148` | `std/collections/hash_map.aipl` | `mapContainsKey` | `pub fn mapContainsKey(m: any, key: any): bool:` | `tests/functions/collections/hash_map_test.aipl` |
| `149` | `std/collections/hash_map.aipl` | `mapKeys` | `pub fn mapKeys(m: any): [str]:` | `tests/functions/collections/hash_map_test.aipl` |
| `150` | `std/collections/hash_map.aipl` | `mapValues` | `pub fn mapValues(m: any): [any]:` | `tests/functions/collections/hash_map_test.aipl` |
| `151` | `std/collections/hash_map.aipl` | `mapRemove` | `pub fn mapRemove(mut m: any, key: any): bool:` | `tests/functions/collections/hash_map_test.aipl` |
| `152` | `std/collections/hash_map.aipl` | `setInsert` | `pub fn setInsert(mut s: any, val: any): any:` | `tests/functions/collections/hash_map_test.aipl` |
| `153` | `std/collections/hash_map.aipl` | `setContains` | `pub fn setContains(s: any, val: any): bool:` | `tests/functions/collections/hash_map_test.aipl` |
| `154` | `std/collections/hash_map.aipl` | `setRemove` | `pub fn setRemove(mut s: any, val: any): bool:` | `tests/functions/collections/hash_map_test.aipl` |
| `155` | `std/collections/hash_map.aipl` | `setToArray` | `pub fn setToArray(s: any): [str]:` | `tests/functions/collections/hash_map_test.aipl` |
| `156` | `std/collections/hash_map.aipl` | `setFromArray` | `pub fn setFromArray(arr: [any]): any:` | `tests/functions/collections/hash_map_test.aipl` |
| `157` | `std/collections/octree.aipl` | `octreeNew` | `pub fn octreeNew[T](minX: float, minY: float, minZ: float, maxX: float, maxY: float, maxZ: float, capacity: int): OctreeNode[T]:` | `tests/functions/collections/octree_test.aipl` |
| `158` | `std/collections/octree.aipl` | `containsPoint` | `pub fn (self: OctreeNode[T]) containsPoint(px: float, py: float, pz: float): bool:` | `tests/functions/collections/octree_test.aipl` |
| `159` | `std/collections/octree.aipl` | `intersectsBox` | `pub fn (self: OctreeNode[T]) intersectsBox(qMinX: float, qMinY: float, qMinZ: float, qMaxX: float, qMaxY: float, qMaxZ: float): bool:` | `tests/functions/collections/octree_test.aipl` |
| `160` | `std/collections/octree.aipl` | `insert` | `pub fn (mut self: OctreeNode[T]) insert(item: OctreeItem[T]): bool:` | `tests/functions/collections/octree_test.aipl` |
| `161` | `std/collections/octree.aipl` | `queryBox` | `pub fn (self: OctreeNode[T]) queryBox(qMinX: float, qMinY: float, qMinZ: float, qMaxX: float, qMaxY: float, qMaxZ: float): [T]:` | `tests/functions/collections/octree_test.aipl` |
| `162` | `std/collections/octree.aipl` | `count` | `pub fn (self: OctreeNode[T]) count(): int:` | `tests/functions/collections/octree_test.aipl` |
| `163` | `std/collections/priority_queue.aipl` | `minHeapNew` | `pub fn minHeapNew[T](): BinaryMinHeap[T]:` | `tests/functions/collections/priority_queue_test.aipl` |
| `164` | `std/collections/priority_queue.aipl` | `push` | `pub fn (mut self: BinaryMinHeap[T]) push(item: T, priority: int): void:` | `tests/functions/collections/priority_queue_test.aipl` |
| `165` | `std/collections/priority_queue.aipl` | `pop` | `pub fn (mut self: BinaryMinHeap[T]) pop(): Option[T]:` | `tests/functions/collections/priority_queue_test.aipl` |
| `166` | `std/collections/priority_queue.aipl` | `peek` | `pub fn (self: BinaryMinHeap[T]) peek(): Option[T]:` | `tests/functions/collections/priority_queue_test.aipl` |
| `167` | `std/collections/priority_queue.aipl` | `peekPriority` | `pub fn (self: BinaryMinHeap[T]) peekPriority(): Option[int]:` | `tests/functions/collections/priority_queue_test.aipl` |
| `168` | `std/collections/priority_queue.aipl` | `len` | `pub fn (self: BinaryMinHeap[T]) len(): int:` | `tests/functions/collections/priority_queue_test.aipl` |
| `169` | `std/collections/priority_queue.aipl` | `isEmpty` | `pub fn (self: BinaryMinHeap[T]) isEmpty(): bool:` | `tests/functions/collections/priority_queue_test.aipl` |
| `170` | `std/collections/priority_queue.aipl` | `clear` | `pub fn (mut self: BinaryMinHeap[T]) clear(): void:` | `tests/functions/collections/priority_queue_test.aipl` |
| `171` | `std/collections/priority_queue.aipl` | `minHeapLen` | `pub fn minHeapLen[T](h: BinaryMinHeap[T]): int:` | `tests/functions/collections/priority_queue_test.aipl` |
| `172` | `std/collections/priority_queue.aipl` | `minHeapIsEmpty` | `pub fn minHeapIsEmpty[T](h: BinaryMinHeap[T]): bool:` | `tests/functions/collections/priority_queue_test.aipl` |
| `173` | `std/collections/priority_queue.aipl` | `minHeapPeek` | `pub fn minHeapPeek[T](h: BinaryMinHeap[T]): Option[T]:` | `tests/functions/collections/priority_queue_test.aipl` |
| `174` | `std/collections/priority_queue.aipl` | `minHeapPeekPriority` | `pub fn minHeapPeekPriority[T](h: BinaryMinHeap[T]): Option[int]:` | `tests/functions/collections/priority_queue_test.aipl` |
| `175` | `std/collections/priority_queue.aipl` | `minHeapPush` | `pub fn minHeapPush[T](mut h: BinaryMinHeap[T], priority: float, item: T): BinaryMinHeap[T]:` | `tests/functions/collections/priority_queue_test.aipl` |
| `176` | `std/collections/priority_queue.aipl` | `minHeapPop` | `pub fn minHeapPop[T](mut h: BinaryMinHeap[T]): Option[T]:` | `tests/functions/collections/priority_queue_test.aipl` |
| `177` | `std/collections/priority_queue.aipl` | `maxHeapNew` | `pub fn maxHeapNew[T](): BinaryMaxHeap[T]:` | `tests/functions/collections/priority_queue_test.aipl` |
| `178` | `std/collections/priority_queue.aipl` | `push` | `pub fn (mut self: BinaryMaxHeap[T]) push(item: T, priority: int): void:` | `tests/functions/collections/priority_queue_test.aipl` |
| `179` | `std/collections/priority_queue.aipl` | `pop` | `pub fn (mut self: BinaryMaxHeap[T]) pop(): Option[T]:` | `tests/functions/collections/priority_queue_test.aipl` |
| `180` | `std/collections/priority_queue.aipl` | `peek` | `pub fn (self: BinaryMaxHeap[T]) peek(): Option[T]:` | `tests/functions/collections/priority_queue_test.aipl` |
| `181` | `std/collections/priority_queue.aipl` | `peekPriority` | `pub fn (self: BinaryMaxHeap[T]) peekPriority(): Option[int]:` | `tests/functions/collections/priority_queue_test.aipl` |
| `182` | `std/collections/priority_queue.aipl` | `len` | `pub fn (self: BinaryMaxHeap[T]) len(): int:` | `tests/functions/collections/priority_queue_test.aipl` |
| `183` | `std/collections/priority_queue.aipl` | `isEmpty` | `pub fn (self: BinaryMaxHeap[T]) isEmpty(): bool:` | `tests/functions/collections/priority_queue_test.aipl` |
| `184` | `std/collections/priority_queue.aipl` | `indexedPqNew` | `pub fn indexedPqNew(maxId: int): IndexedPriorityQueue:` | `tests/functions/collections/priority_queue_test.aipl` |
| `185` | `std/collections/priority_queue.aipl` | `pqNew` | `pub fn pqNew(): PriorityQueue:` | `tests/functions/collections/priority_queue_test.aipl` |
| `186` | `std/collections/priority_queue.aipl` | `PriorityQueue.new` | `pub fn PriorityQueue.new(): PriorityQueue:` | `tests/functions/collections/priority_queue_test.aipl` |
| `187` | `std/collections/priority_queue.aipl` | `pqLen` | `pub fn pqLen(pq: PriorityQueue): int:` | `tests/functions/collections/priority_queue_test.aipl` |
| `188` | `std/collections/priority_queue.aipl` | `len` | `pub fn (self: PriorityQueue) len(): int:` | `tests/functions/collections/priority_queue_test.aipl` |
| `189` | `std/collections/priority_queue.aipl` | `pqIsEmpty` | `pub fn pqIsEmpty(pq: PriorityQueue): bool:` | `tests/functions/collections/priority_queue_test.aipl` |
| `190` | `std/collections/priority_queue.aipl` | `isEmpty` | `pub fn (self: PriorityQueue) isEmpty(): bool:` | `tests/functions/collections/priority_queue_test.aipl` |
| `191` | `std/collections/priority_queue.aipl` | `pqPeek` | `pub fn pqPeek(pq: PriorityQueue): Option[int]:` | `tests/functions/collections/priority_queue_test.aipl` |
| `192` | `std/collections/priority_queue.aipl` | `peek` | `pub fn (self: PriorityQueue) peek(): Option[int]:` | `tests/functions/collections/priority_queue_test.aipl` |
| `193` | `std/collections/priority_queue.aipl` | `pqPeekCost` | `pub fn pqPeekCost(pq: PriorityQueue): Option[int]:` | `tests/functions/collections/priority_queue_test.aipl` |
| `194` | `std/collections/priority_queue.aipl` | `pqPush` | `pub fn pqPush(mut pq: PriorityQueue, node: int, cost: int): PriorityQueue:` | `tests/functions/collections/priority_queue_test.aipl` |
| `195` | `std/collections/priority_queue.aipl` | `pqPopMin` | `pub fn pqPopMin(mut pq: PriorityQueue): Option[int]:` | `tests/functions/collections/priority_queue_test.aipl` |
| `196` | `std/collections/priority_queue.aipl` | `pqDecreaseKey` | `pub fn pqDecreaseKey(mut pq: PriorityQueue, node: int, newCost: int): bool:` | `tests/functions/collections/priority_queue_test.aipl` |
| `197` | `std/collections/priority_queue.aipl` | `BinaryHeap.new` | `pub fn BinaryHeap.new(): BinaryHeap:` | `tests/functions/collections/priority_queue_test.aipl` |
| `198` | `std/collections/priority_queue.aipl` | `len` | `pub fn (self: BinaryHeap) len(): int:` | `tests/functions/collections/priority_queue_test.aipl` |
| `199` | `std/collections/priority_queue.aipl` | `isEmpty` | `pub fn (self: BinaryHeap) isEmpty(): bool:` | `tests/functions/collections/priority_queue_test.aipl` |
| `200` | `std/collections/quadtree.aipl` | `quadtreeNew` | `pub fn quadtreeNew[T](x: float, y: float, w: float, h: float, capacity: int): QuadtreeNode[T]:` | `tests/functions/collections/quadtree_test.aipl` |
| `201` | `std/collections/quadtree.aipl` | `containsPoint` | `pub fn (self: QuadtreeNode[T]) containsPoint(px: float, py: float): bool:` | `tests/functions/collections/quadtree_test.aipl` |
| `202` | `std/collections/quadtree.aipl` | `intersectsRange` | `pub fn (self: QuadtreeNode[T]) intersectsRange(qx: float, qy: float, qw: float, qh: float): bool:` | `tests/functions/collections/quadtree_test.aipl` |
| `203` | `std/collections/quadtree.aipl` | `insert` | `pub fn (mut self: QuadtreeNode[T]) insert(item: QuadtreeItem[T]): bool:` | `tests/functions/collections/quadtree_test.aipl` |
| `204` | `std/collections/quadtree.aipl` | `queryRange` | `pub fn (self: QuadtreeNode[T]) queryRange(qx: float, qy: float, qw: float, qh: float): [T]:` | `tests/functions/collections/quadtree_test.aipl` |
| `205` | `std/collections/quadtree.aipl` | `count` | `pub fn (self: QuadtreeNode[T]) count(): int:` | `tests/functions/collections/quadtree_test.aipl` |
| `206` | `std/collections/sparse_set.aipl` | `sparseSetNew` | `pub fn sparseSetNew[T](maxIndex: int): SparseSet[T]:` | `tests/functions/collections/sparse_set_test.aipl` |
| `207` | `std/collections/sparse_set.aipl` | `contains` | `pub fn (self: SparseSet[T]) contains(id: int): bool:` | `tests/functions/collections/sparse_set_test.aipl` |
| `208` | `std/collections/sparse_set.aipl` | `insert` | `pub fn (mut self: SparseSet[T]) insert(id: int, val: T): bool:` | `tests/functions/collections/sparse_set_test.aipl` |
| `209` | `std/collections/sparse_set.aipl` | `remove` | `pub fn (mut self: SparseSet[T]) remove(id: int): bool:` | `tests/functions/collections/sparse_set_test.aipl` |
| `210` | `std/collections/sparse_set.aipl` | `get` | `pub fn (self: SparseSet[T]) get(id: int): Option[T]:` | `tests/functions/collections/sparse_set_test.aipl` |
| `211` | `std/collections/sparse_set.aipl` | `len` | `pub fn (self: SparseSet[T]) len(): int:` | `tests/functions/collections/sparse_set_test.aipl` |
| `212` | `std/collections/sparse_set.aipl` | `isEmpty` | `pub fn (self: SparseSet[T]) isEmpty(): bool:` | `tests/functions/collections/sparse_set_test.aipl` |
| `213` | `std/collections/sparse_set.aipl` | `clear` | `pub fn (mut self: SparseSet[T]) clear(): void:` | `tests/functions/collections/sparse_set_test.aipl` |
| `214` | `std/collections/sparse_set.aipl` | `ids` | `pub fn (self: SparseSet[T]) ids(): [int]:` | `tests/functions/collections/sparse_set_test.aipl` |
| `215` | `std/collections/sparse_set.aipl` | `denseValues` | `pub fn (self: SparseSet[T]) denseValues(): [T]:` | `tests/functions/collections/sparse_set_test.aipl` |
| `216` | `std/collections/spatial_hash.aipl` | `spatialCellHash2D` | `pub fn spatialCellHash2D(cx: int, cy: int): int:` | `tests/functions/collections/spatial_hash_test.aipl` |
| `217` | `std/collections/spatial_hash.aipl` | `spatialHash2DNew` | `pub fn spatialHash2DNew[T](cellSize: float): SpatialHashGrid2D[T]:` | `tests/functions/collections/spatial_hash_test.aipl` |
| `218` | `std/collections/spatial_hash.aipl` | `insert` | `pub fn (mut self: SpatialHashGrid2D[T]) insert(x: float, y: float, val: T): void:` | `tests/functions/collections/spatial_hash_test.aipl` |
| `219` | `std/collections/spatial_hash.aipl` | `queryRadius` | `pub fn (self: SpatialHashGrid2D[T]) queryRadius(x: float, y: float, radius: float): [T]:` | `tests/functions/collections/spatial_hash_test.aipl` |
| `220` | `std/collections/spatial_hash.aipl` | `clear` | `pub fn (mut self: SpatialHashGrid2D[T]) clear(): void:` | `tests/functions/collections/spatial_hash_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `bitsetNew` (`std/collections/bitset.aipl`)

- **Signature**: `pub fn bitsetNew(size: int): DynamicBitSet:`
- **Import**: `import * from "std/collections/bitset"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `size: int` | **Returns**: `DynamicBitSet`
- **Unit Test**: `tests/functions/collections/bitset_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `bitsetNew` (`free fn`) multi-word bitset / Bloom filter invariant across 64-bit word boundaries (`0, 63, 64, 127`), De Morgan bitwise algebra, and zero false negatives. Concrete nominal inputs: `size: int = 64`; exercises core body path returning/computing `DynamicBitSet(words = w, bitCount = sz)`.

```aipl
module tests.functions.collections.bitset_z1_test
import * from "std/collections/bitset"
import { popcount64 } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bitset_bitsetNew_1(): int:
  let arg_size = 4
  let edge_size = 1
  let resNom = bitsetNew(arg_size)
  let resEdge = bitsetNew(edge_size)
  assertEqInt(resNom.words.len(), 1, "bitsetNew nominal resNom.words.len() == 1")
  assertEqInt(resEdge.words.len(), 1, "bitsetNew boundary resEdge.words.len() == 1")
  ret 0
```

---

### `set` (`std/collections/bitset.aipl`)

- **Signature**: `pub fn (mut self: DynamicBitSet) set(index: int): void:`
- **Import**: `import * from "std/collections/bitset"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: DynamicBitSet` | **Parameters**: `index: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/bitset_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `set` (`mut self: DynamicBitSet`) multi-word bitset / Bloom filter invariant across 64-bit word boundaries (`0, 63, 64, 127`), De Morgan bitwise algebra, and zero false negatives. Concrete nominal inputs: receiver `recvObj: DynamicBitSet = DynamicBitSet(words = [1], bitCount = 64)`, `index: int = 0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.bitset_z2_test
import * from "std/collections/bitset"
import { popcount64 } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bitset_DynamicBitSet_set_2(): int:
  let mut recv_self = DynamicBitSet(words = [0], bitCount = 64)
  let mut edge_self = DynamicBitSet(words = [0], bitCount = 64)
  let arg_index = 2
  let edge_index = 0
  recv_self.set(arg_index)
  edge_self.set(edge_index)
  assertEqInt(recv_self.words[0], 4, "set nominal recv_self.words[0] == 4")
  assertEqInt(edge_self.words[0], 1, "set boundary edge_self.words[0] == 1")
  ret 0
```

---

### `clear` (`std/collections/bitset.aipl`)

- **Signature**: `pub fn (mut self: DynamicBitSet) clear(index: int): void:`
- **Import**: `import * from "std/collections/bitset"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: DynamicBitSet` | **Parameters**: `index: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/bitset_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `clear` (`mut self: DynamicBitSet`) multi-word bitset / Bloom filter invariant across 64-bit word boundaries (`0, 63, 64, 127`), De Morgan bitwise algebra, and zero false negatives. Concrete nominal inputs: receiver `recvObj: DynamicBitSet = DynamicBitSet(words = [1], bitCount = 64)`, `index: int = 0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.bitset_z3_test
import * from "std/collections/bitset"
import { popcount64 } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bitset_DynamicBitSet_clear_3(): int:
  let mut recv_self = DynamicBitSet(words = [0], bitCount = 64)
  let mut edge_self = DynamicBitSet(words = [0], bitCount = 64)
  let arg_index = 2
  let edge_index = 0
  recv_self.clear(arg_index)
  edge_self.clear(edge_index)
  assertEqInt(recv_self.words[0], 0, "clear nominal recv_self.words[0] == 0")
  assertEqInt(edge_self.words[0], 0, "clear boundary edge_self.words[0] == 0")
  ret 0
```

---

### `toggle` (`std/collections/bitset.aipl`)

- **Signature**: `pub fn (mut self: DynamicBitSet) toggle(index: int): void:`
- **Import**: `import * from "std/collections/bitset"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: DynamicBitSet` | **Parameters**: `index: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/bitset_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `toggle` (`mut self: DynamicBitSet`) multi-word bitset / Bloom filter invariant across 64-bit word boundaries (`0, 63, 64, 127`), De Morgan bitwise algebra, and zero false negatives. Concrete nominal inputs: receiver `recvObj: DynamicBitSet = DynamicBitSet(words = [1], bitCount = 64)`, `index: int = 0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.bitset_z4_test
import * from "std/collections/bitset"
import { popcount64 } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bitset_DynamicBitSet_toggle_4(): int:
  let mut recv_self = DynamicBitSet(words = [0], bitCount = 64)
  let mut edge_self = DynamicBitSet(words = [0], bitCount = 64)
  let arg_index = 2
  let edge_index = 0
  recv_self.toggle(arg_index)
  edge_self.toggle(edge_index)
  assertEqInt(recv_self.words[0], 4, "toggle nominal recv_self.words[0] == 4")
  assertEqInt(edge_self.words[0], 1, "toggle boundary edge_self.words[0] == 1")
  ret 0
```

---

### `test` (`std/collections/bitset.aipl`)

- **Signature**: `pub fn (self: DynamicBitSet) test(index: int): bool:`
- **Import**: `import * from "std/collections/bitset"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: DynamicBitSet` | **Parameters**: `index: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/bitset_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `test` (`self: DynamicBitSet`) multi-word bitset / Bloom filter invariant across 64-bit word boundaries (`0, 63, 64, 127`), De Morgan bitwise algebra, and zero false negatives. Concrete nominal inputs: receiver `recvObj: DynamicBitSet = DynamicBitSet(words = [1], bitCount = 64)`, `index: int = 0`; exercises core body path returning/computing `((self.words[wordIdx] >> bitIdx) & 1) != 0`.

```aipl
module tests.functions.collections.bitset_z5_test
import * from "std/collections/bitset"
import { popcount64 } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bitset_DynamicBitSet_test_5(): int:
  let recv_self = DynamicBitSet(words = [], bitCount = 4)
  let edge_self = DynamicBitSet(words = [], bitCount = 1)
  let arg_index = 4
  let edge_index = 1
  let resNom = recv_self.test(arg_index)
  let resEdge = edge_self.test(edge_index)
  assert(resNom == false, "test nominal resNom == false")
  assert(resEdge == false, "test boundary resEdge == false")
  ret 0
```

---

### `countOnes` (`std/collections/bitset.aipl`)

- **Signature**: `pub fn (self: DynamicBitSet) countOnes(): int:`
- **Import**: `import * from "std/collections/bitset"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: DynamicBitSet` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/bitset_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `countOnes` (`self: DynamicBitSet`) multi-word bitset / Bloom filter invariant across 64-bit word boundaries (`0, 63, 64, 127`), De Morgan bitwise algebra, and zero false negatives. Concrete nominal inputs: receiver `recvObj: DynamicBitSet = DynamicBitSet(words = [1], bitCount = 64)`; exercises core body path returning/computing `total`.

```aipl
module tests.functions.collections.bitset_z6_test
import * from "std/collections/bitset"
import { popcount64 } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bitset_DynamicBitSet_countOnes_6(): int:
  let recv_self = DynamicBitSet(words = [], bitCount = 4)
  let edge_self = DynamicBitSet(words = [], bitCount = 1)
  let resNom = recv_self.countOnes()
  let resEdge = edge_self.countOnes()
  assertEqInt(resNom, 0, "countOnes nominal resNom == 0")
  assertEqInt(resEdge, 0, "countOnes boundary resEdge == 0")
  ret 0
```

---

### `countZeros` (`std/collections/bitset.aipl`)

- **Signature**: `pub fn (self: DynamicBitSet) countZeros(): int:`
- **Import**: `import * from "std/collections/bitset"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: DynamicBitSet` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/bitset_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `countZeros` (`self: DynamicBitSet`) multi-word bitset / Bloom filter invariant across 64-bit word boundaries (`0, 63, 64, 127`), De Morgan bitwise algebra, and zero false negatives. Concrete nominal inputs: receiver `recvObj: DynamicBitSet = DynamicBitSet(words = [1], bitCount = 64)`; exercises core body path returning/computing `self.bitCount - self.countOnes()`.

```aipl
module tests.functions.collections.bitset_z7_test
import * from "std/collections/bitset"
import { popcount64 } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bitset_DynamicBitSet_countZeros_7(): int:
  let recv_self = DynamicBitSet(words = [], bitCount = 4)
  let edge_self = DynamicBitSet(words = [], bitCount = 1)
  let resNom = recv_self.countZeros()
  let resEdge = edge_self.countZeros()
  assertEqInt(resNom, 4, "countZeros nominal resNom == 4")
  assertEqInt(resEdge, 1, "countZeros boundary resEdge == 1")
  ret 0
```

---

### `clearAll` (`std/collections/bitset.aipl`)

- **Signature**: `pub fn (mut self: DynamicBitSet) clearAll(): void:`
- **Import**: `import * from "std/collections/bitset"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: DynamicBitSet` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/bitset_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `clearAll` (`mut self: DynamicBitSet`) multi-word bitset / Bloom filter invariant across 64-bit word boundaries (`0, 63, 64, 127`), De Morgan bitwise algebra, and zero false negatives. Concrete nominal inputs: receiver `recvObj: DynamicBitSet = DynamicBitSet(words = [1], bitCount = 64)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.bitset_z8_test
import * from "std/collections/bitset"
import { popcount64 } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bitset_DynamicBitSet_clearAll_8(): int:
  let mut recv_self = DynamicBitSet(words = [0], bitCount = 64)
  let mut edge_self = DynamicBitSet(words = [0], bitCount = 64)
  recv_self.clearAll()
  edge_self.clearAll()
  assertEqInt(recv_self.words[0], 0, "clearAll nominal recv_self.words[0] == 0")
  assertEqInt(edge_self.words[0], 0, "clearAll boundary edge_self.words[0] == 0")
  ret 0
```

---

### `bitwiseAnd` (`std/collections/bitset.aipl`)

- **Signature**: `pub fn (mut self: DynamicBitSet) bitwiseAnd(other: DynamicBitSet): void:`
- **Import**: `import * from "std/collections/bitset"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: DynamicBitSet` | **Parameters**: `other: DynamicBitSet` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/bitset_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `bitwiseAnd` (`mut self: DynamicBitSet`) multi-word bitset / Bloom filter invariant across 64-bit word boundaries (`0, 63, 64, 127`), De Morgan bitwise algebra, and zero false negatives. Concrete nominal inputs: receiver `recvObj: DynamicBitSet = DynamicBitSet(words = [1], bitCount = 64)`, `other: DynamicBitSet = DynamicBitSet(words = [1], bitCount = 64)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.bitset_z9_test
import * from "std/collections/bitset"
import { popcount64 } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bitset_DynamicBitSet_bitwiseAnd_9(): int:
  let mut recv_self = DynamicBitSet(words = [0], bitCount = 64)
  let mut edge_self = DynamicBitSet(words = [0], bitCount = 64)
  let arg_other = DynamicBitSet(words = [0], bitCount = 64)
  let edge_other = DynamicBitSet(words = [0], bitCount = 64)
  recv_self.bitwiseAnd(arg_other)
  edge_self.bitwiseAnd(edge_other)
  assertEqInt(recv_self.words[0], 0, "bitwiseAnd nominal recv_self.words[0] == 0")
  assertEqInt(edge_self.words[0], 0, "bitwiseAnd boundary edge_self.words[0] == 0")
  ret 0
```

---

### `bitwiseOr` (`std/collections/bitset.aipl`)

- **Signature**: `pub fn (mut self: DynamicBitSet) bitwiseOr(other: DynamicBitSet): void:`
- **Import**: `import * from "std/collections/bitset"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: DynamicBitSet` | **Parameters**: `other: DynamicBitSet` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/bitset_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `bitwiseOr` (`mut self: DynamicBitSet`) multi-word bitset / Bloom filter invariant across 64-bit word boundaries (`0, 63, 64, 127`), De Morgan bitwise algebra, and zero false negatives. Concrete nominal inputs: receiver `recvObj: DynamicBitSet = DynamicBitSet(words = [1], bitCount = 64)`, `other: DynamicBitSet = DynamicBitSet(words = [1], bitCount = 64)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.bitset_z10_test
import * from "std/collections/bitset"
import { popcount64 } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bitset_DynamicBitSet_bitwiseOr_10(): int:
  let mut recv_self = DynamicBitSet(words = [0], bitCount = 64)
  let mut edge_self = DynamicBitSet(words = [0], bitCount = 64)
  let arg_other = DynamicBitSet(words = [0], bitCount = 64)
  let edge_other = DynamicBitSet(words = [0], bitCount = 64)
  recv_self.bitwiseOr(arg_other)
  edge_self.bitwiseOr(edge_other)
  assertEqInt(recv_self.words[0], 0, "bitwiseOr nominal recv_self.words[0] == 0")
  assertEqInt(edge_self.words[0], 0, "bitwiseOr boundary edge_self.words[0] == 0")
  ret 0
```

---

### `bitwiseXor` (`std/collections/bitset.aipl`)

- **Signature**: `pub fn (mut self: DynamicBitSet) bitwiseXor(other: DynamicBitSet): void:`
- **Import**: `import * from "std/collections/bitset"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: DynamicBitSet` | **Parameters**: `other: DynamicBitSet` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/bitset_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `bitwiseXor` (`mut self: DynamicBitSet`) multi-word bitset / Bloom filter invariant across 64-bit word boundaries (`0, 63, 64, 127`), De Morgan bitwise algebra, and zero false negatives. Concrete nominal inputs: receiver `recvObj: DynamicBitSet = DynamicBitSet(words = [1], bitCount = 64)`, `other: DynamicBitSet = DynamicBitSet(words = [1], bitCount = 64)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.bitset_z11_test
import * from "std/collections/bitset"
import { popcount64 } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bitset_DynamicBitSet_bitwiseXor_11(): int:
  let mut recv_self = DynamicBitSet(words = [0], bitCount = 64)
  let mut edge_self = DynamicBitSet(words = [0], bitCount = 64)
  let arg_other = DynamicBitSet(words = [0], bitCount = 64)
  let edge_other = DynamicBitSet(words = [0], bitCount = 64)
  recv_self.bitwiseXor(arg_other)
  edge_self.bitwiseXor(edge_other)
  assertEqInt(recv_self.words[0], 0, "bitwiseXor nominal recv_self.words[0] == 0")
  assertEqInt(edge_self.words[0], 0, "bitwiseXor boundary edge_self.words[0] == 0")
  ret 0
```

---

### `bloomHashStr` (`std/collections/bitset.aipl`)

- **Signature**: `pub fn bloomHashStr(strKey: str, seed: int): int:`
- **Import**: `import * from "std/collections/bitset"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `strKey: str, seed: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/bitset_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `bloomHashStr` (`free fn`) multi-word bitset / Bloom filter invariant across 64-bit word boundaries (`0, 63, 64, 127`), De Morgan bitwise algebra, and zero false negatives. Concrete nominal inputs: `strKey: str = "aipl_test"`, `seed: int = 42`; exercises core body path returning/computing `h`.

```aipl
module tests.functions.collections.bitset_z12_test
import * from "std/collections/bitset"
import { popcount64 } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bitset_bloomHashStr_12(): int:
  let arg_strKey = "test"
  let edge_strKey = "a"
  let arg_seed = 1
  let edge_seed = 0
  let resNom = bloomHashStr(arg_strKey, arg_seed)
  let resEdge = bloomHashStr(edge_strKey, edge_seed)
  assertEqInt(resNom, 3710413597007460320, "bloomHashStr nominal resNom == 3710413597007460320")
  assertEqInt(resEdge, 36342608335481132, "bloomHashStr boundary resEdge == 36342608335481132")
  ret 0
```

---

### `bloomFilterNew` (`std/collections/bitset.aipl`)

- **Signature**: `pub fn bloomFilterNew(capacity: int, fpp: float): BloomFilter:`
- **Import**: `import * from "std/collections/bitset"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `capacity: int, fpp: float` | **Returns**: `BloomFilter`
- **Unit Test**: `tests/functions/collections/bitset_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `bloomFilterNew` (`free fn`) multi-word bitset / Bloom filter invariant across 64-bit word boundaries (`0, 63, 64, 127`), De Morgan bitwise algebra, and zero false negatives. Concrete nominal inputs: `capacity: int = 64`, `fpp: float = 1.0`; exercises core body path returning/computing `BloomFilter(bits = bs, numHashes = kHashes)`.

```aipl
module tests.functions.collections.bitset_z13_test
import * from "std/collections/bitset"
import { popcount64 } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bitset_bloomFilterNew_13(): int:
  let arg_capacity = 4
  let edge_capacity = 1
  let arg_fpp = 1.0
  let edge_fpp = 0.5
  let resNom = bloomFilterNew(arg_capacity, arg_fpp)
  let resEdge = bloomFilterNew(edge_capacity, edge_fpp)
  assertEqInt(resNom.numHashes, 3, "bloomFilterNew nominal resNom.numHashes == 3")
  assertEqInt(resEdge.numHashes, 3, "bloomFilterNew boundary resEdge.numHashes == 3")
  ret 0
```

---

### `add` (`std/collections/bitset.aipl`)

- **Signature**: `pub fn (mut self: BloomFilter) add(strKey: str): void:`
- **Import**: `import * from "std/collections/bitset"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: BloomFilter` | **Parameters**: `strKey: str` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/bitset_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `add` (`mut self: BloomFilter`) multi-word bitset / Bloom filter invariant across 64-bit word boundaries (`0, 63, 64, 127`), De Morgan bitwise algebra, and zero false negatives. Concrete nominal inputs: receiver `recvObj: BloomFilter = BloomFilter(bits = DynamicBitSet(words = [0], bitCount = 64), numHashes = 1)`, `strKey: str = "aipl_test"`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.bitset_z14_test
import * from "std/collections/bitset"
import { popcount64 } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bitset_BloomFilter_add_14(): int:
  let mut recv_self = BloomFilter(bits = DynamicBitSet(words = [0], bitCount = 64), numHashes = 4)
  let mut edge_self = BloomFilter(bits = DynamicBitSet(words = [0], bitCount = 64), numHashes = 1)
  let arg_strKey = "test"
  let edge_strKey = "a"
  recv_self.add(arg_strKey)
  edge_self.add(edge_strKey)
  assertEqInt(recv_self.numHashes, 4, "add nominal recv_self.numHashes == 4")
  assertEqInt(edge_self.numHashes, 1, "add boundary edge_self.numHashes == 1")
  ret 0
```

---

### `contains` (`std/collections/bitset.aipl`)

- **Signature**: `pub fn (self: BloomFilter) contains(strKey: str): bool:`
- **Import**: `import * from "std/collections/bitset"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: BloomFilter` | **Parameters**: `strKey: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/bitset_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `contains` (`self: BloomFilter`) multi-word bitset / Bloom filter invariant across 64-bit word boundaries (`0, 63, 64, 127`), De Morgan bitwise algebra, and zero false negatives. Concrete nominal inputs: receiver `recvObj: BloomFilter = BloomFilter(bits = DynamicBitSet(words = [0], bitCount = 64), numHashes = 1)`, `strKey: str = "aipl_test"`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.collections.bitset_z15_test
import * from "std/collections/bitset"
import { popcount64 } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bitset_BloomFilter_contains_15(): int:
  let recv_self = BloomFilter(bits = DynamicBitSet(words = [], bitCount = 4), numHashes = 4)
  let edge_self = BloomFilter(bits = DynamicBitSet(words = [], bitCount = 1), numHashes = 1)
  let arg_strKey = "test"
  let edge_strKey = "a"
  let resNom = recv_self.contains(arg_strKey)
  let resEdge = edge_self.contains(edge_strKey)
  assert(resNom == false, "contains nominal resNom == false")
  assert(resEdge == false, "contains boundary resEdge == false")
  ret 0
```

---

### `btreeNodeNew` (`std/collections/btree_map.aipl`)

- **Signature**: `pub fn btreeNodeNew[K, V](isLeaf: bool): BTreeNode[K, V]:`
- **Import**: `import * from "std/collections/btree_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `isLeaf: bool` | **Returns**: `BTreeNode[K, V]`
- **Unit Test**: `tests/functions/collections/btree_map_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `btreeNodeNew` (`free fn`) ordered B-Tree map invariant on scrambled key insertions, strictly sorted `.keys()`, `.minKey()`/`.maxKey()`, and inclusive `.range(lo, hi)` queries. Concrete nominal inputs: `isLeaf: bool = true`; exercises core body path returning/computing `BTreeNode(isLeaf = isLeaf, keys = k, values = v, children = c)`.

```aipl
module tests.functions.collections.btree_map_z1_test
import * from "std/collections/btree_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_btree_map_btreeNodeNew_1(): int:
  let arg_isLeaf = true
  let edge_isLeaf = false
  let resNom = btreeNodeNew(arg_isLeaf)
  let resEdge = btreeNodeNew(edge_isLeaf)
  assert(resNom.isLeaf == true, "btreeNodeNew nominal resNom.isLeaf == true")
  assert(resEdge.isLeaf == false, "btreeNodeNew boundary resEdge.isLeaf == false")
  ret 0
```

---

### `btreeMapNew` (`std/collections/btree_map.aipl`)

- **Signature**: `pub fn btreeMapNew[K, V](order: int): BTreeMap[K, V]:`
- **Import**: `import * from "std/collections/btree_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `order: int` | **Returns**: `BTreeMap[K, V]`
- **Unit Test**: `tests/functions/collections/btree_map_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `btreeMapNew` (`free fn`) ordered B-Tree map invariant on scrambled key insertions, strictly sorted `.keys()`, `.minKey()`/`.maxKey()`, and inclusive `.range(lo, hi)` queries. Concrete nominal inputs: `order: int = 1`; exercises core body path returning/computing `BTreeMap(root = None, order = ord, count = 0)`.

```aipl
module tests.functions.collections.btree_map_z2_test
import * from "std/collections/btree_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_btree_map_btreeMapNew_2(): int:
  let arg_order = 2
  let edge_order = 0
  let resNom = btreeMapNew(arg_order)
  let resEdge = btreeMapNew(edge_order)
  assertEqInt(resNom.order, 2, "btreeMapNew nominal resNom.order == 2")
  assertEqInt(resEdge.order, 2, "btreeMapNew boundary resEdge.order == 2")
  ret 0
```

---

### `insert` (`std/collections/btree_map.aipl`)

- **Signature**: `pub fn (mut self: BTreeMap[K, V]) insert(key: K, val: V): void:`
- **Import**: `import * from "std/collections/btree_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: BTreeMap[K, V]` | **Parameters**: `key: K, val: V` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/btree_map_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `insert` (`mut self: BTreeMap[K, V]`) ordered B-Tree map invariant on scrambled key insertions, strictly sorted `.keys()`, `.minKey()`/`.maxKey()`, and inclusive `.range(lo, hi)` queries. Concrete nominal inputs: receiver `recvObj: BTreeMap[K, V] = BTreeMap(root = Some(BTreeNode(isLeaf = 0, keys = 0, values = 0, children = 0)), order = 1, count = 64)`, `key: K = 42`, `val: V = 42`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.btree_map_z3_test
import * from "std/collections/btree_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_btree_map_BTreeMap_K__V__insert_3(): int:
  let mut recv_self = BTreeMap(root = None(), order = 2, count = 0)
  let mut edge_self = BTreeMap(root = None(), order = 0, count = 0)
  let arg_key = 1
  let edge_key = 0
  let arg_val = 1
  let edge_val = 0
  recv_self.insert(arg_key, arg_val)
  edge_self.insert(edge_key, edge_val)
  assertEqInt(recv_self.count, 1, "insert nominal recv_self.count == 1")
  assertEqInt(edge_self.count, 1, "insert boundary edge_self.count == 1")
  ret 0
```

---

### `get` (`std/collections/btree_map.aipl`)

- **Signature**: `pub fn (self: BTreeMap[K, V]) get(key: K): Option[V]:`
- **Import**: `import * from "std/collections/btree_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: BTreeMap[K, V]` | **Parameters**: `key: K` | **Returns**: `Option[V]`
- **Unit Test**: `tests/functions/collections/btree_map_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `get` (`self: BTreeMap[K, V]`) ordered B-Tree map invariant on scrambled key insertions, strictly sorted `.keys()`, `.minKey()`/`.maxKey()`, and inclusive `.range(lo, hi)` queries. Concrete nominal inputs: receiver `recvObj: BTreeMap[K, V] = BTreeMap(root = Some(BTreeNode(isLeaf = 0, keys = 0, values = 0, children = 0)), order = 1, count = 64)`, `key: K = 42`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.collections.btree_map_z4_test
import * from "std/collections/btree_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_btree_map_BTreeMap_K__V__get_4(): int:
  let recv_self = BTreeMap(root = None(), order = 2, count = 0)
  let edge_self = BTreeMap(root = None(), order = 0, count = 0)
  let arg_key = 1
  let edge_key = 0
  let resNom = recv_self.get(arg_key)
  let resEdge = edge_self.get(edge_key)
  assert(resNom.isSome() == false, "get nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "get boundary resEdge.isSome() == false")
  ret 0
```

---

### `containsKey` (`std/collections/btree_map.aipl`)

- **Signature**: `pub fn (self: BTreeMap[K, V]) containsKey(key: K): bool:`
- **Import**: `import * from "std/collections/btree_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: BTreeMap[K, V]` | **Parameters**: `key: K` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/btree_map_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `containsKey` (`self: BTreeMap[K, V]`) ordered B-Tree map invariant on scrambled key insertions, strictly sorted `.keys()`, `.minKey()`/`.maxKey()`, and inclusive `.range(lo, hi)` queries. Concrete nominal inputs: receiver `recvObj: BTreeMap[K, V] = BTreeMap(root = Some(BTreeNode(isLeaf = 0, keys = 0, values = 0, children = 0)), order = 1, count = 64)`, `key: K = 42`; exercises core body path returning/computing `res.isSome()`.

```aipl
module tests.functions.collections.btree_map_z5_test
import * from "std/collections/btree_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_btree_map_BTreeMap_K__V__containsKey_5(): int:
  let recv_self = BTreeMap(root = None(), order = 2, count = 0)
  let edge_self = BTreeMap(root = None(), order = 0, count = 0)
  let arg_key = 1
  let edge_key = 0
  let resNom = recv_self.containsKey(arg_key)
  let resEdge = edge_self.containsKey(edge_key)
  assert(resNom == false, "containsKey nominal resNom == false")
  assert(resEdge == false, "containsKey boundary resEdge == false")
  ret 0
```

---

### `len` (`std/collections/btree_map.aipl`)

- **Signature**: `pub fn (self: BTreeMap[K, V]) len(): int:`
- **Import**: `import * from "std/collections/btree_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: BTreeMap[K, V]` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/btree_map_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `len` (`self: BTreeMap[K, V]`) ordered B-Tree map invariant on scrambled key insertions, strictly sorted `.keys()`, `.minKey()`/`.maxKey()`, and inclusive `.range(lo, hi)` queries. Concrete nominal inputs: receiver `recvObj: BTreeMap[K, V] = BTreeMap(root = Some(BTreeNode(isLeaf = 0, keys = 0, values = 0, children = 0)), order = 1, count = 64)`; exercises core body path returning/computing `self.count`.

```aipl
module tests.functions.collections.btree_map_z6_test
import * from "std/collections/btree_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_btree_map_BTreeMap_K__V__len_6(): int:
  let recv_self = BTreeMap(root = None(), order = 2, count = 0)
  let edge_self = BTreeMap(root = None(), order = 0, count = 0)
  let resNom = recv_self.len()
  let resEdge = edge_self.len()
  assertEqInt(resNom, 0, "len nominal resNom == 0")
  assertEqInt(resEdge, 0, "len boundary resEdge == 0")
  ret 0
```

---

### `isEmpty` (`std/collections/btree_map.aipl`)

- **Signature**: `pub fn (self: BTreeMap[K, V]) isEmpty(): bool:`
- **Import**: `import * from "std/collections/btree_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: BTreeMap[K, V]` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/btree_map_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `isEmpty` (`self: BTreeMap[K, V]`) ordered B-Tree map invariant on scrambled key insertions, strictly sorted `.keys()`, `.minKey()`/`.maxKey()`, and inclusive `.range(lo, hi)` queries. Concrete nominal inputs: receiver `recvObj: BTreeMap[K, V] = BTreeMap(root = Some(BTreeNode(isLeaf = 0, keys = 0, values = 0, children = 0)), order = 1, count = 64)`; exercises core body path returning/computing `self.count == 0`.

```aipl
module tests.functions.collections.btree_map_z7_test
import * from "std/collections/btree_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_btree_map_BTreeMap_K__V__isEmpty_7(): int:
  let recv_self = BTreeMap(root = None(), order = 2, count = 0)
  let edge_self = BTreeMap(root = None(), order = 0, count = 0)
  let resNom = recv_self.isEmpty()
  let resEdge = edge_self.isEmpty()
  assert(resNom == true, "isEmpty nominal resNom == true")
  assert(resEdge == true, "isEmpty boundary resEdge == true")
  ret 0
```

---

### `range` (`std/collections/btree_map.aipl`)

- **Signature**: `pub fn (self: BTreeMap[K, V]) range(minKey: K, maxKey: K): [V]:`
- **Import**: `import * from "std/collections/btree_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: BTreeMap[K, V]` | **Parameters**: `minKey: K, maxKey: K` | **Returns**: `[V]`
- **Unit Test**: `tests/functions/collections/btree_map_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `range` (`self: BTreeMap[K, V]`) ordered B-Tree map invariant on scrambled key insertions, strictly sorted `.keys()`, `.minKey()`/`.maxKey()`, and inclusive `.range(lo, hi)` queries. Concrete nominal inputs: receiver `recvObj: BTreeMap[K, V] = BTreeMap(root = Some(BTreeNode(isLeaf = 0, keys = 0, values = 0, children = 0)), order = 1, count = 64)`, `minKey: K = 42`, `maxKey: K = 42`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.collections.btree_map_z8_test
import * from "std/collections/btree_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_btree_map_BTreeMap_K__V__range_8(): int:
  let recv_self = BTreeMap(root = None(), order = 2, count = 0)
  let edge_self = BTreeMap(root = None(), order = 0, count = 0)
  let arg_minKey = 1
  let edge_minKey = 0
  let arg_maxKey = 1
  let edge_maxKey = 0
  let resNom = recv_self.range(arg_minKey, arg_maxKey)
  let resEdge = edge_self.range(edge_minKey, edge_maxKey)
  assertEqInt(resNom.len(), 0, "range nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "range boundary resEdge.len() == 0")
  ret 0
```

---

### `minKey` (`std/collections/btree_map.aipl`)

- **Signature**: `pub fn (self: BTreeMap[K, V]) minKey(): Option[K]:`
- **Import**: `import * from "std/collections/btree_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: BTreeMap[K, V]` | **Parameters**: `none` | **Returns**: `Option[K]`
- **Unit Test**: `tests/functions/collections/btree_map_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `minKey` (`self: BTreeMap[K, V]`) ordered B-Tree map invariant on scrambled key insertions, strictly sorted `.keys()`, `.minKey()`/`.maxKey()`, and inclusive `.range(lo, hi)` queries. Concrete nominal inputs: receiver `recvObj: BTreeMap[K, V] = BTreeMap(root = Some(BTreeNode(isLeaf = 0, keys = 0, values = 0, children = 0)), order = 1, count = 64)`; exercises core body path returning/computing `Some(node.keys[0])`.

```aipl
module tests.functions.collections.btree_map_z9_test
import * from "std/collections/btree_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_btree_map_BTreeMap_K__V__minKey_9(): int:
  let recv_self = BTreeMap(root = None(), order = 2, count = 0)
  let edge_self = BTreeMap(root = None(), order = 0, count = 0)
  let resNom = recv_self.minKey()
  let resEdge = edge_self.minKey()
  assert(resNom.isSome() == false, "minKey nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "minKey boundary resEdge.isSome() == false")
  ret 0
```

---

### `maxKey` (`std/collections/btree_map.aipl`)

- **Signature**: `pub fn (self: BTreeMap[K, V]) maxKey(): Option[K]:`
- **Import**: `import * from "std/collections/btree_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: BTreeMap[K, V]` | **Parameters**: `none` | **Returns**: `Option[K]`
- **Unit Test**: `tests/functions/collections/btree_map_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `maxKey` (`self: BTreeMap[K, V]`) ordered B-Tree map invariant on scrambled key insertions, strictly sorted `.keys()`, `.minKey()`/`.maxKey()`, and inclusive `.range(lo, hi)` queries. Concrete nominal inputs: receiver `recvObj: BTreeMap[K, V] = BTreeMap(root = Some(BTreeNode(isLeaf = 0, keys = 0, values = 0, children = 0)), order = 1, count = 64)`; exercises core body path returning/computing `Some(node.keys[node.keys.len - 1])`.

```aipl
module tests.functions.collections.btree_map_z10_test
import * from "std/collections/btree_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_btree_map_BTreeMap_K__V__maxKey_10(): int:
  let recv_self = BTreeMap(root = None(), order = 2, count = 0)
  let edge_self = BTreeMap(root = None(), order = 0, count = 0)
  let resNom = recv_self.maxKey()
  let resEdge = edge_self.maxKey()
  assert(resNom.isSome() == false, "maxKey nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "maxKey boundary resEdge.isSome() == false")
  ret 0
```

---

### `keys` (`std/collections/btree_map.aipl`)

- **Signature**: `pub fn (self: BTreeMap[K, V]) keys(): [K]:`
- **Import**: `import * from "std/collections/btree_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: BTreeMap[K, V]` | **Parameters**: `none` | **Returns**: `[K]`
- **Unit Test**: `tests/functions/collections/btree_map_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `keys` (`self: BTreeMap[K, V]`) ordered B-Tree map invariant on scrambled key insertions, strictly sorted `.keys()`, `.minKey()`/`.maxKey()`, and inclusive `.range(lo, hi)` queries. Concrete nominal inputs: receiver `recvObj: BTreeMap[K, V] = BTreeMap(root = Some(BTreeNode(isLeaf = 0, keys = 0, values = 0, children = 0)), order = 1, count = 64)`; exercises core body path returning/computing `node.keys`.

```aipl
module tests.functions.collections.btree_map_z11_test
import * from "std/collections/btree_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_btree_map_BTreeMap_K__V__keys_11(): int:
  let recv_self = BTreeMap(root = None(), order = 2, count = 0)
  let edge_self = BTreeMap(root = None(), order = 0, count = 0)
  let resNom = recv_self.keys()
  let resEdge = edge_self.keys()
  assertEqInt(resNom.len(), 0, "keys nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "keys boundary resEdge.len() == 0")
  ret 0
```

---

### `values` (`std/collections/btree_map.aipl`)

- **Signature**: `pub fn (self: BTreeMap[K, V]) values(): [V]:`
- **Import**: `import * from "std/collections/btree_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: BTreeMap[K, V]` | **Parameters**: `none` | **Returns**: `[V]`
- **Unit Test**: `tests/functions/collections/btree_map_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `values` (`self: BTreeMap[K, V]`) ordered B-Tree map invariant on scrambled key insertions, strictly sorted `.keys()`, `.minKey()`/`.maxKey()`, and inclusive `.range(lo, hi)` queries. Concrete nominal inputs: receiver `recvObj: BTreeMap[K, V] = BTreeMap(root = Some(BTreeNode(isLeaf = 0, keys = 0, values = 0, children = 0)), order = 1, count = 64)`; exercises core body path returning/computing `node.values`.

```aipl
module tests.functions.collections.btree_map_z12_test
import * from "std/collections/btree_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_btree_map_BTreeMap_K__V__values_12(): int:
  let recv_self = BTreeMap(root = None(), order = 2, count = 0)
  let edge_self = BTreeMap(root = None(), order = 0, count = 0)
  let resNom = recv_self.values()
  let resEdge = edge_self.values()
  assertEqInt(resNom.len(), 0, "values nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "values boundary resEdge.len() == 0")
  ret 0
```

---

### `bvhAabbUnion` (`std/collections/bvh_tree.aipl`)

- **Signature**: `pub fn bvhAabbUnion(a: BvhAabb, b: BvhAabb): BvhAabb:`
- **Import**: `import * from "std/collections/bvh_tree"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: BvhAabb, b: BvhAabb` | **Returns**: `BvhAabb`
- **Unit Test**: `tests/functions/collections/bvh_tree_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `bvhAabbUnion` (`free fn`) Surface Area Heuristic (SAH) 3D Bounding Volume Hierarchy construction and nearest-hit `rayIntersect` accuracy. Concrete nominal inputs: `a: BvhAabb = BvhAabb(minX = 1.0, minY = 1.0, minZ = 1.0, maxX = 1.0, maxY = 1.0, maxZ = 1.0)`, `b: BvhAabb = BvhAabb(minX = 1.0, minY = 1.0, minZ = 1.0, maxX = 1.0, maxY = 1.0, maxZ = 1.0)`; exercises core body path returning/computing `BvhAabb(`.

```aipl
module tests.functions.collections.bvh_tree_z1_test
import * from "std/collections/bvh_tree"
import { minFloat, maxFloat } from "std/prelude"
import { absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bvh_tree_bvhAabbUnion_1(): int:
  let arg_a = BvhAabb(minX = 0.0, minY = 0.0, minZ = 0.0, maxX = 2.0, maxY = 2.0, maxZ = 2.0)
  let edge_a = BvhAabb(minX = 0.0, minY = 0.0, minZ = 0.0, maxX = 1.0, maxY = 1.0, maxZ = 1.0)
  let arg_b = BvhAabb(minX = 0.0, minY = 0.0, minZ = 0.0, maxX = 2.0, maxY = 2.0, maxZ = 2.0)
  let edge_b = BvhAabb(minX = 0.0, minY = 0.0, minZ = 0.0, maxX = 1.0, maxY = 1.0, maxZ = 1.0)
  let resNom = bvhAabbUnion(arg_a, arg_b)
  let resEdge = bvhAabbUnion(edge_a, edge_b)
  assertApproxEq(resNom.minX, 0.0, 0.001, "bvhAabbUnion nominal resNom.minX ~= 0.0")
  assertApproxEq(resEdge.minX, 0.0, 0.001, "bvhAabbUnion boundary resEdge.minX ~= 0.0")
  ret 0
```

---

### `bvhAabbSurfaceArea` (`std/collections/bvh_tree.aipl`)

- **Signature**: `pub fn bvhAabbSurfaceArea(b: BvhAabb): float:`
- **Import**: `import * from "std/collections/bvh_tree"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `b: BvhAabb` | **Returns**: `float`
- **Unit Test**: `tests/functions/collections/bvh_tree_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `bvhAabbSurfaceArea` (`free fn`) Surface Area Heuristic (SAH) 3D Bounding Volume Hierarchy construction and nearest-hit `rayIntersect` accuracy. Concrete nominal inputs: `b: BvhAabb = BvhAabb(minX = 1.0, minY = 1.0, minZ = 1.0, maxX = 1.0, maxY = 1.0, maxZ = 1.0)`; exercises core body path returning/computing `2.0 * (dx * dy + dy * dz + dz * dx)`.

```aipl
module tests.functions.collections.bvh_tree_z2_test
import * from "std/collections/bvh_tree"
import { minFloat, maxFloat } from "std/prelude"
import { absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bvh_tree_bvhAabbSurfaceArea_2(): int:
  let arg_b = BvhAabb(minX = 0.0, minY = 0.0, minZ = 0.0, maxX = 2.0, maxY = 2.0, maxZ = 2.0)
  let edge_b = BvhAabb(minX = 0.0, minY = 0.0, minZ = 0.0, maxX = 1.0, maxY = 1.0, maxZ = 1.0)
  let resNom = bvhAabbSurfaceArea(arg_b)
  let resEdge = bvhAabbSurfaceArea(edge_b)
  assertApproxEq(resNom, 24.0, 0.001, "bvhAabbSurfaceArea nominal resNom ~= 24.0")
  assertApproxEq(resEdge, 6.0, 0.001, "bvhAabbSurfaceArea boundary resEdge ~= 6.0")
  ret 0
```

---

### `bvhAabbRayHit` (`std/collections/bvh_tree.aipl`)

- **Signature**: `pub fn bvhAabbRayHit(b: BvhAabb, ox: float, oy: float, oz: float, dx: float, dy: float, dz: float): bool:`
- **Import**: `import * from "std/collections/bvh_tree"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `b: BvhAabb, ox: float, oy: float, oz: float, dx: float, dy: float, dz: float` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/bvh_tree_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `bvhAabbRayHit` (`free fn`) Surface Area Heuristic (SAH) 3D Bounding Volume Hierarchy construction and nearest-hit `rayIntersect` accuracy. Concrete nominal inputs: `b: BvhAabb = BvhAabb(minX = 1.0, minY = 1.0, minZ = 1.0, maxX = 1.0, maxY = 1.0, maxZ = 1.0)`, `ox: float = 1.0`, `oy: float = 1.0`, `oz: float = 1.0`, `dx: float = 1.0`, `dy: float = 1.0`, `dz: float = 1.0`; exercises core body path returning/computing `tmax >= maxFloat(0.0, tmin)`.

```aipl
module tests.functions.collections.bvh_tree_z3_test
import * from "std/collections/bvh_tree"
import { minFloat, maxFloat } from "std/prelude"
import { absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bvh_tree_bvhAabbRayHit_3(): int:
  let arg_b = BvhAabb(minX = 0.0, minY = 0.0, minZ = 0.0, maxX = 2.0, maxY = 2.0, maxZ = 2.0)
  let edge_b = BvhAabb(minX = 0.0, minY = 0.0, minZ = 0.0, maxX = 1.0, maxY = 1.0, maxZ = 1.0)
  let arg_ox = 1.0
  let edge_ox = 0.5
  let arg_oy = 1.0
  let edge_oy = 0.5
  let arg_oz = 1.0
  let edge_oz = 0.5
  let arg_dx = 1.0
  let edge_dx = 0.5
  let arg_dy = 1.0
  let edge_dy = 0.5
  let arg_dz = 1.0
  let edge_dz = 0.5
  let resNom = bvhAabbRayHit(arg_b, arg_ox, arg_oy, arg_oz, arg_dx, arg_dy, arg_dz)
  let resEdge = bvhAabbRayHit(edge_b, edge_ox, edge_oy, edge_oz, edge_dx, edge_dy, edge_dz)
  assert(resNom == true, "bvhAabbRayHit nominal resNom == true")
  assert(resEdge == true, "bvhAabbRayHit boundary resEdge == true")
  ret 0
```

---

### `bvhBuildSAH` (`std/collections/bvh_tree.aipl`)

- **Signature**: `pub fn bvhBuildSAH(boxes: [BvhAabb]): BvhTree3D:`
- **Import**: `import * from "std/collections/bvh_tree"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `boxes: [BvhAabb]` | **Returns**: `BvhTree3D`
- **Unit Test**: `tests/functions/collections/bvh_tree_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `bvhBuildSAH` (`free fn`) Surface Area Heuristic (SAH) 3D Bounding Volume Hierarchy construction and nearest-hit `rayIntersect` accuracy. Concrete nominal inputs: `boxes: [BvhAabb] = [BvhAabb(minX = 1.0, minY = 1.0, minZ = 1.0, maxX = 1.0, maxY = 1.0, maxZ = 1.0)]`; exercises core body path returning/computing `BvhTree3D(nodes = nodes, rootIndex = activeIndices[0])`.

```aipl
module tests.functions.collections.bvh_tree_z4_test
import * from "std/collections/bvh_tree"
import { minFloat, maxFloat } from "std/prelude"
import { absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bvh_tree_bvhBuildSAH_4(): int:
  let arg_boxes = [BvhAabb(minX = 0.0, minY = 0.0, minZ = 0.0, maxX = 2.0, maxY = 2.0, maxZ = 2.0)]
  let edge_boxes = []
  let resNom = bvhBuildSAH(arg_boxes)
  let resEdge = bvhBuildSAH(edge_boxes)
  assertEqInt(resNom.nodes.len(), 1, "bvhBuildSAH nominal resNom.nodes.len() == 1")
  assertEqInt(resEdge.nodes.len(), 0, "bvhBuildSAH boundary resEdge.nodes.len() == 0")
  ret 0
```

---

### `rayIntersect` (`std/collections/bvh_tree.aipl`)

- **Signature**: `pub fn (self: BvhTree3D) rayIntersect(rayOriginX: float, rayOriginY: float, rayOriginZ: float, rayDirX: float, rayDirY: float, rayDirZ: float): [int]:`
- **Import**: `import * from "std/collections/bvh_tree"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: BvhTree3D` | **Parameters**: `rayOriginX: float, rayOriginY: float, rayOriginZ: float, rayDirX: float, rayDirY: float, rayDirZ: float` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/collections/bvh_tree_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `rayIntersect` (`self: BvhTree3D`) Surface Area Heuristic (SAH) 3D Bounding Volume Hierarchy construction and nearest-hit `rayIntersect` accuracy. Concrete nominal inputs: receiver `recvObj: BvhTree3D = BvhTree3D(nodes = [BvhNode(bounds = 0, leftChild = 0, rightChild = 0, primitiveIndex = 0, isLeaf = 0)], rootIndex = 0)`, `rayOriginX: float = 1.0`, `rayOriginY: float = 1.0`, `rayOriginZ: float = 1.0`, `rayDirX: float = 1.0`, `rayDirY: float = 1.0`, `rayDirZ: float = 1.0`; exercises core body path returning/computing `hits`.

```aipl
module tests.functions.collections.bvh_tree_z5_test
import * from "std/collections/bvh_tree"
import { minFloat, maxFloat } from "std/prelude"
import { absFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bvh_tree_BvhTree3D_rayIntersect_5(): int:
  let recv_self = BvhTree3D(nodes = [], rootIndex = 4)
  let edge_self = BvhTree3D(nodes = [], rootIndex = 1)
  let arg_rayOriginX = 1.0
  let edge_rayOriginX = 0.5
  let arg_rayOriginY = 1.0
  let edge_rayOriginY = 0.5
  let arg_rayOriginZ = 1.0
  let edge_rayOriginZ = 0.5
  let arg_rayDirX = 1.0
  let edge_rayDirX = 0.5
  let arg_rayDirY = 1.0
  let edge_rayDirY = 0.5
  let arg_rayDirZ = 1.0
  let edge_rayDirZ = 0.5
  let resNom = recv_self.rayIntersect(arg_rayOriginX, arg_rayOriginY, arg_rayOriginZ, arg_rayDirX, arg_rayDirY, arg_rayDirZ)
  let resEdge = edge_self.rayIntersect(edge_rayOriginX, edge_rayOriginY, edge_rayOriginZ, edge_rayDirX, edge_rayDirY, edge_rayDirZ)
  assertEqInt(resNom.len(), 0, "rayIntersect nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "rayIntersect boundary resEdge.len() == 0")
  ret 0
```

---

### `dequeNew` (`std/collections/deque.aipl`)

- **Signature**: `pub fn dequeNew[T](): Deque[T]:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Deque[T]`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `dequeNew` (`free fn`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Deque(front = f, back = b)`.

```aipl
module tests.functions.collections.deque_z1_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_dequeNew_1(): int:
  let resNom = dequeNew()
  let resEdge = dequeNew()
  assertEqInt(resNom.front.len(), 0, "dequeNew nominal resNom.front.len() == 0")
  assertEqInt(resEdge.front.len(), 0, "dequeNew boundary resEdge.front.len() == 0")
  ret 0
```

---

### `pushFront` (`std/collections/deque.aipl`)

- **Signature**: `pub fn (mut self: Deque[T]) pushFront(item: T): void:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: Deque[T]` | **Parameters**: `item: T` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `pushFront` (`mut self: Deque[T]`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: receiver `recvObj: Deque[T] = Deque(front = [42], back = [42])`, `item: T = 42`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.deque_z2_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_Deque_T__pushFront_2(): int:
  let mut recv_self = Deque(front = [], back = [])
  let mut edge_self = Deque(front = [], back = [])
  let arg_item = 1
  let edge_item = 0
  recv_self.pushFront(arg_item)
  edge_self.pushFront(edge_item)
  assertEqInt(recv_self.front.len(), 1, "pushFront nominal recv_self.front.len() == 1")
  assertEqInt(edge_self.front.len(), 1, "pushFront boundary edge_self.front.len() == 1")
  ret 0
```

---

### `pushBack` (`std/collections/deque.aipl`)

- **Signature**: `pub fn (mut self: Deque[T]) pushBack(item: T): void:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: Deque[T]` | **Parameters**: `item: T` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `pushBack` (`mut self: Deque[T]`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: receiver `recvObj: Deque[T] = Deque(front = [42], back = [42])`, `item: T = 42`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.deque_z3_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_Deque_T__pushBack_3(): int:
  let mut recv_self = Deque(front = [], back = [])
  let mut edge_self = Deque(front = [], back = [])
  let arg_item = 1
  let edge_item = 0
  recv_self.pushBack(arg_item)
  edge_self.pushBack(edge_item)
  assertEqInt(recv_self.back.len(), 1, "pushBack nominal recv_self.back.len() == 1")
  assertEqInt(edge_self.back.len(), 1, "pushBack boundary edge_self.back.len() == 1")
  ret 0
```

---

### `popFront` (`std/collections/deque.aipl`)

- **Signature**: `pub fn (mut self: Deque[T]) popFront(): Option[T]:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: Deque[T]` | **Parameters**: `none` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `popFront` (`mut self: Deque[T]`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: receiver `recvObj: Deque[T] = Deque(front = [42], back = [42])`; exercises core body path returning/computing `Some(first)`.

```aipl
module tests.functions.collections.deque_z4_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_Deque_T__popFront_4(): int:
  let mut recv_self = Deque(front = [], back = [])
  let mut edge_self = Deque(front = [], back = [])
  let resNom = recv_self.popFront()
  let resEdge = edge_self.popFront()
  assert(resNom.isSome() == false, "popFront nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "popFront boundary resEdge.isSome() == false")
  ret 0
```

---

### `popBack` (`std/collections/deque.aipl`)

- **Signature**: `pub fn (mut self: Deque[T]) popBack(): Option[T]:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: Deque[T]` | **Parameters**: `none` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `popBack` (`mut self: Deque[T]`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: receiver `recvObj: Deque[T] = Deque(front = [42], back = [42])`; exercises core body path returning/computing `Some(first)`.

```aipl
module tests.functions.collections.deque_z5_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_Deque_T__popBack_5(): int:
  let mut recv_self = Deque(front = [], back = [])
  let mut edge_self = Deque(front = [], back = [])
  let resNom = recv_self.popBack()
  let resEdge = edge_self.popBack()
  assert(resNom.isSome() == false, "popBack nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "popBack boundary resEdge.isSome() == false")
  ret 0
```

---

### `peekFront` (`std/collections/deque.aipl`)

- **Signature**: `pub fn (self: Deque[T]) peekFront(): Option[T]:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: Deque[T]` | **Parameters**: `none` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `peekFront` (`self: Deque[T]`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: receiver `recvObj: Deque[T] = Deque(front = [42], back = [42])`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.collections.deque_z6_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_Deque_T__peekFront_6(): int:
  let recv_self = Deque(front = [], back = [])
  let edge_self = Deque(front = [], back = [])
  let resNom = recv_self.peekFront()
  let resEdge = edge_self.peekFront()
  assert(resNom.isSome() == false, "peekFront nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "peekFront boundary resEdge.isSome() == false")
  ret 0
```

---

### `peekBack` (`std/collections/deque.aipl`)

- **Signature**: `pub fn (self: Deque[T]) peekBack(): Option[T]:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: Deque[T]` | **Parameters**: `none` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `peekBack` (`self: Deque[T]`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: receiver `recvObj: Deque[T] = Deque(front = [42], back = [42])`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.collections.deque_z7_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_Deque_T__peekBack_7(): int:
  let recv_self = Deque(front = [], back = [])
  let edge_self = Deque(front = [], back = [])
  let resNom = recv_self.peekBack()
  let resEdge = edge_self.peekBack()
  assert(resNom.isSome() == false, "peekBack nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "peekBack boundary resEdge.isSome() == false")
  ret 0
```

---

### `len` (`std/collections/deque.aipl`)

- **Signature**: `pub fn (self: Deque[T]) len(): int:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: Deque[T]` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `len` (`self: Deque[T]`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: receiver `recvObj: Deque[T] = Deque(front = [42], back = [42])`; exercises core body path returning/computing `self.front.len + self.back.len`.

```aipl
module tests.functions.collections.deque_z8_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_Deque_T__len_8(): int:
  let recv_self = Deque(front = [], back = [])
  let edge_self = Deque(front = [], back = [])
  let resNom = recv_self.len()
  let resEdge = edge_self.len()
  assertEqInt(resNom, 0, "len nominal resNom == 0")
  assertEqInt(resEdge, 0, "len boundary resEdge == 0")
  ret 0
```

---

### `isEmpty` (`std/collections/deque.aipl`)

- **Signature**: `pub fn (self: Deque[T]) isEmpty(): bool:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: Deque[T]` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `isEmpty` (`self: Deque[T]`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: receiver `recvObj: Deque[T] = Deque(front = [42], back = [42])`; exercises core body path returning/computing `(self.front.len + self.back.len) == 0`.

```aipl
module tests.functions.collections.deque_z9_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_Deque_T__isEmpty_9(): int:
  let recv_self = Deque(front = [], back = [])
  let edge_self = Deque(front = [], back = [])
  let resNom = recv_self.isEmpty()
  let resEdge = edge_self.isEmpty()
  assert(resNom == true, "isEmpty nominal resNom == true")
  assert(resEdge == true, "isEmpty boundary resEdge == true")
  ret 0
```

---

### `clear` (`std/collections/deque.aipl`)

- **Signature**: `pub fn (mut self: Deque[T]) clear(): void:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: Deque[T]` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `clear` (`mut self: Deque[T]`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: receiver `recvObj: Deque[T] = Deque(front = [42], back = [42])`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.deque_z10_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_Deque_T__clear_10(): int:
  let mut recv_self = Deque(front = [], back = [])
  let mut edge_self = Deque(front = [], back = [])
  recv_self.clear()
  edge_self.clear()
  assertEqInt(recv_self.front.len(), 0, "clear nominal recv_self.front.len() == 0")
  assertEqInt(edge_self.front.len(), 0, "clear boundary edge_self.front.len() == 0")
  ret 0
```

---

### `toArray` (`std/collections/deque.aipl`)

- **Signature**: `pub fn (self: Deque[T]) toArray(): [T]:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: Deque[T]` | **Parameters**: `none` | **Returns**: `[T]`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `toArray` (`self: Deque[T]`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: receiver `recvObj: Deque[T] = Deque(front = [42], back = [42])`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.collections.deque_z11_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_Deque_T__toArray_11(): int:
  let recv_self = Deque(front = [], back = [])
  let edge_self = Deque(front = [], back = [])
  let resNom = recv_self.toArray()
  let resEdge = edge_self.toArray()
  assertEqInt(resNom.len(), 0, "toArray nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "toArray boundary resEdge.len() == 0")
  ret 0
```

---

### `dequeLen` (`std/collections/deque.aipl`)

- **Signature**: `pub fn dequeLen[T](d: Deque[T]): int:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `d: Deque[T]` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `dequeLen` (`free fn`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: `d: Deque[T] = Deque(front = [42], back = [42])`; exercises core body path returning/computing `d.len()`.

```aipl
module tests.functions.collections.deque_z12_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_dequeLen_12(): int:
  let arg_d = Deque(front = [], back = [])
  let edge_d = Deque(front = [], back = [])
  let resNom = dequeLen(arg_d)
  let resEdge = dequeLen(edge_d)
  assertEqInt(resNom, 0, "dequeLen nominal resNom == 0")
  assertEqInt(resEdge, 0, "dequeLen boundary resEdge == 0")
  ret 0
```

---

### `dequeIsEmpty` (`std/collections/deque.aipl`)

- **Signature**: `pub fn dequeIsEmpty[T](d: Deque[T]): bool:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `d: Deque[T]` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `dequeIsEmpty` (`free fn`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: `d: Deque[T] = Deque(front = [42], back = [42])`; exercises core body path returning/computing `d.isEmpty()`.

```aipl
module tests.functions.collections.deque_z13_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_dequeIsEmpty_13(): int:
  let arg_d = Deque(front = [], back = [])
  let edge_d = Deque(front = [], back = [])
  let resNom = dequeIsEmpty(arg_d)
  let resEdge = dequeIsEmpty(edge_d)
  assert(resNom == true, "dequeIsEmpty nominal resNom == true")
  assert(resEdge == true, "dequeIsEmpty boundary resEdge == true")
  ret 0
```

---

### `dequePushBack` (`std/collections/deque.aipl`)

- **Signature**: `pub fn dequePushBack[T](mut d: Deque[T], item: T): Deque[T]:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut d: Deque[T], item: T` | **Returns**: `Deque[T]`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `dequePushBack` (`free fn`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: `d: Deque[T] = Deque(front = [42], back = [42])`, `item: T = 42`; exercises core body path returning/computing `d`.

```aipl
module tests.functions.collections.deque_z14_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_dequePushBack_14(): int:
  let arg_d = Deque(front = [], back = [])
  let edge_d = Deque(front = [], back = [])
  let arg_item = 1
  let edge_item = 0
  let resNom = dequePushBack(arg_d, arg_item)
  let resEdge = dequePushBack(edge_d, edge_item)
  assertEqInt(resNom.front.len(), 0, "dequePushBack nominal resNom.front.len() == 0")
  assertEqInt(resEdge.front.len(), 0, "dequePushBack boundary resEdge.front.len() == 0")
  ret 0
```

---

### `dequePushFront` (`std/collections/deque.aipl`)

- **Signature**: `pub fn dequePushFront[T](mut d: Deque[T], item: T): Deque[T]:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut d: Deque[T], item: T` | **Returns**: `Deque[T]`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `dequePushFront` (`free fn`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: `d: Deque[T] = Deque(front = [42], back = [42])`, `item: T = 42`; exercises core body path returning/computing `d`.

```aipl
module tests.functions.collections.deque_z15_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_dequePushFront_15(): int:
  let arg_d = Deque(front = [], back = [])
  let edge_d = Deque(front = [], back = [])
  let arg_item = 1
  let edge_item = 0
  let resNom = dequePushFront(arg_d, arg_item)
  let resEdge = dequePushFront(edge_d, edge_item)
  assertEqInt(resNom.front.len(), 1, "dequePushFront nominal resNom.front.len() == 1")
  assertEqInt(resEdge.front.len(), 1, "dequePushFront boundary resEdge.front.len() == 1")
  ret 0
```

---

### `dequePopBack` (`std/collections/deque.aipl`)

- **Signature**: `pub fn dequePopBack[T](mut d: Deque[T]): Option[T]:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut d: Deque[T]` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `dequePopBack` (`free fn`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: `d: Deque[T] = Deque(front = [42], back = [42])`; exercises core body path returning/computing `d.popBack()`.

```aipl
module tests.functions.collections.deque_z16_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_dequePopBack_16(): int:
  let arg_d = Deque(front = [], back = [])
  let edge_d = Deque(front = [], back = [])
  let resNom = dequePopBack(arg_d)
  let resEdge = dequePopBack(edge_d)
  assert(resNom.isSome() == false, "dequePopBack nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "dequePopBack boundary resEdge.isSome() == false")
  ret 0
```

---

### `dequePopFront` (`std/collections/deque.aipl`)

- **Signature**: `pub fn dequePopFront[T](mut d: Deque[T]): Option[T]:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut d: Deque[T]` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `dequePopFront` (`free fn`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: `d: Deque[T] = Deque(front = [42], back = [42])`; exercises core body path returning/computing `d.popFront()`.

```aipl
module tests.functions.collections.deque_z17_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_dequePopFront_17(): int:
  let arg_d = Deque(front = [], back = [])
  let edge_d = Deque(front = [], back = [])
  let resNom = dequePopFront(arg_d)
  let resEdge = dequePopFront(edge_d)
  assert(resNom.isSome() == false, "dequePopFront nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "dequePopFront boundary resEdge.isSome() == false")
  ret 0
```

---

### `dequePeekFront` (`std/collections/deque.aipl`)

- **Signature**: `pub fn dequePeekFront[T](d: Deque[T]): Option[T]:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `d: Deque[T]` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `dequePeekFront` (`free fn`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: `d: Deque[T] = Deque(front = [42], back = [42])`; exercises core body path returning/computing `d.peekFront()`.

```aipl
module tests.functions.collections.deque_z18_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_dequePeekFront_18(): int:
  let arg_d = Deque(front = [], back = [])
  let edge_d = Deque(front = [], back = [])
  let resNom = dequePeekFront(arg_d)
  let resEdge = dequePeekFront(edge_d)
  assert(resNom.isSome() == false, "dequePeekFront nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "dequePeekFront boundary resEdge.isSome() == false")
  ret 0
```

---

### `dequePeekBack` (`std/collections/deque.aipl`)

- **Signature**: `pub fn dequePeekBack[T](d: Deque[T]): Option[T]:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `d: Deque[T]` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `dequePeekBack` (`free fn`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: `d: Deque[T] = Deque(front = [42], back = [42])`; exercises core body path returning/computing `d.peekBack()`.

```aipl
module tests.functions.collections.deque_z19_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_dequePeekBack_19(): int:
  let arg_d = Deque(front = [], back = [])
  let edge_d = Deque(front = [], back = [])
  let resNom = dequePeekBack(arg_d)
  let resEdge = dequePeekBack(edge_d)
  assert(resNom.isSome() == false, "dequePeekBack nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "dequePeekBack boundary resEdge.isSome() == false")
  ret 0
```

---

### `dequeToArray` (`std/collections/deque.aipl`)

- **Signature**: `pub fn dequeToArray[T](d: Deque[T]): [T]:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `d: Deque[T]` | **Returns**: `[T]`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `dequeToArray` (`free fn`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: `d: Deque[T] = Deque(front = [42], back = [42])`; exercises core body path returning/computing `d.toArray()`.

```aipl
module tests.functions.collections.deque_z20_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_dequeToArray_20(): int:
  let arg_d = Deque(front = [], back = [])
  let edge_d = Deque(front = [], back = [])
  let resNom = dequeToArray(arg_d)
  let resEdge = dequeToArray(edge_d)
  assertEqInt(resNom.len(), 0, "dequeToArray nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "dequeToArray boundary resEdge.len() == 0")
  ret 0
```

---

### `circularRingQueueNew` (`std/collections/deque.aipl`)

- **Signature**: `pub fn circularRingQueueNew[T](capacity: int): CircularRingQueue[T]:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `capacity: int` | **Returns**: `CircularRingQueue[T]`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `circularRingQueueNew` (`free fn`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: `capacity: int = 64`; exercises core body path returning/computing `CircularRingQueue(buffer = buf, head = 0, tail = 0, capacity = cap, count = 0)`.

```aipl
module tests.functions.collections.deque_z21_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_circularRingQueueNew_21(): int:
  let arg_capacity = 4
  let edge_capacity = 1
  let resNom = circularRingQueueNew(arg_capacity)
  let resEdge = circularRingQueueNew(edge_capacity)
  assertEqInt(resNom.buffer.len(), 0, "circularRingQueueNew nominal resNom.buffer.len() == 0")
  assertEqInt(resEdge.buffer.len(), 0, "circularRingQueueNew boundary resEdge.buffer.len() == 0")
  ret 0
```

---

### `enqueue` (`std/collections/deque.aipl`)

- **Signature**: `pub fn (mut self: CircularRingQueue[T]) enqueue(item: T): bool:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: CircularRingQueue[T]` | **Parameters**: `item: T` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `enqueue` (`mut self: CircularRingQueue[T]`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: receiver `recvObj: CircularRingQueue[T] = CircularRingQueue(buffer = [42], head = 1, tail = 1, capacity = 64, count = 64)`, `item: T = 42`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.collections.deque_z22_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_CircularRingQueue_T__enqueue_22(): int:
  let mut recv_self = CircularRingQueue(buffer = [], head = 0, tail = 0, capacity = 4, count = 0)
  let mut edge_self = CircularRingQueue(buffer = [], head = 0, tail = 0, capacity = 4, count = 0)
  let arg_item = 1
  let edge_item = 0
  let resNom = recv_self.enqueue(arg_item)
  let resEdge = edge_self.enqueue(edge_item)
  assert(resNom == true, "enqueue nominal resNom == true")
  assert(resEdge == true, "enqueue boundary resEdge == true")
  ret 0
```

---

### `dequeue` (`std/collections/deque.aipl`)

- **Signature**: `pub fn (mut self: CircularRingQueue[T]) dequeue(): Option[T]:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: CircularRingQueue[T]` | **Parameters**: `none` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `dequeue` (`mut self: CircularRingQueue[T]`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: receiver `recvObj: CircularRingQueue[T] = CircularRingQueue(buffer = [42], head = 1, tail = 1, capacity = 64, count = 64)`; exercises core body path returning/computing `Some(v)`.

```aipl
module tests.functions.collections.deque_z23_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_CircularRingQueue_T__dequeue_23(): int:
  let mut recv_self = CircularRingQueue(buffer = [], head = 0, tail = 0, capacity = 4, count = 0)
  let mut edge_self = CircularRingQueue(buffer = [], head = 0, tail = 0, capacity = 4, count = 0)
  let resNom = recv_self.dequeue()
  let resEdge = edge_self.dequeue()
  assert(resNom.isSome() == false, "dequeue nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "dequeue boundary resEdge.isSome() == false")
  ret 0
```

---

### `len` (`std/collections/deque.aipl`)

- **Signature**: `pub fn (self: CircularRingQueue[T]) len(): int:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: CircularRingQueue[T]` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `len` (`self: CircularRingQueue[T]`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: receiver `recvObj: CircularRingQueue[T] = CircularRingQueue(buffer = [42], head = 1, tail = 1, capacity = 64, count = 64)`; exercises core body path returning/computing `self.count`.

```aipl
module tests.functions.collections.deque_z24_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_CircularRingQueue_T__len_24(): int:
  let recv_self = CircularRingQueue(buffer = [], head = 0, tail = 0, capacity = 4, count = 0)
  let edge_self = CircularRingQueue(buffer = [], head = 0, tail = 0, capacity = 4, count = 0)
  let resNom = recv_self.len()
  let resEdge = edge_self.len()
  assertEqInt(resNom, 0, "len nominal resNom == 0")
  assertEqInt(resEdge, 0, "len boundary resEdge == 0")
  ret 0
```

---

### `isEmpty` (`std/collections/deque.aipl`)

- **Signature**: `pub fn (self: CircularRingQueue[T]) isEmpty(): bool:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: CircularRingQueue[T]` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `isEmpty` (`self: CircularRingQueue[T]`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: receiver `recvObj: CircularRingQueue[T] = CircularRingQueue(buffer = [42], head = 1, tail = 1, capacity = 64, count = 64)`; exercises core body path returning/computing `self.count == 0`.

```aipl
module tests.functions.collections.deque_z25_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_CircularRingQueue_T__isEmpty_25(): int:
  let recv_self = CircularRingQueue(buffer = [], head = 0, tail = 0, capacity = 4, count = 0)
  let edge_self = CircularRingQueue(buffer = [], head = 0, tail = 0, capacity = 4, count = 0)
  let resNom = recv_self.isEmpty()
  let resEdge = edge_self.isEmpty()
  assert(resNom == true, "isEmpty nominal resNom == true")
  assert(resEdge == true, "isEmpty boundary resEdge == true")
  ret 0
```

---

### `isFull` (`std/collections/deque.aipl`)

- **Signature**: `pub fn (self: CircularRingQueue[T]) isFull(): bool:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: CircularRingQueue[T]` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `isFull` (`self: CircularRingQueue[T]`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: receiver `recvObj: CircularRingQueue[T] = CircularRingQueue(buffer = [42], head = 1, tail = 1, capacity = 64, count = 64)`; exercises core body path returning/computing `self.count >= self.capacity`.

```aipl
module tests.functions.collections.deque_z26_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_CircularRingQueue_T__isFull_26(): int:
  let recv_self = CircularRingQueue(buffer = [], head = 0, tail = 0, capacity = 4, count = 0)
  let edge_self = CircularRingQueue(buffer = [], head = 0, tail = 0, capacity = 4, count = 0)
  let resNom = recv_self.isFull()
  let resEdge = edge_self.isFull()
  assert(resNom == false, "isFull nominal resNom == false")
  assert(resEdge == false, "isFull boundary resEdge == false")
  ret 0
```

---

### `ringBufferNew` (`std/collections/deque.aipl`)

- **Signature**: `pub fn ringBufferNew[T](capacity: int): CircularRingQueue[T]:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `capacity: int` | **Returns**: `CircularRingQueue[T]`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `ringBufferNew` (`free fn`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: `capacity: int = 64`; exercises core body path returning/computing `circularRingQueueNew[T](capacity)`.

```aipl
module tests.functions.collections.deque_z27_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_ringBufferNew_27(): int:
  let arg_capacity = 4
  let edge_capacity = 1
  let resNom = ringBufferNew(arg_capacity)
  let resEdge = ringBufferNew(edge_capacity)
  assertEqInt(resNom.buffer.len(), 0, "ringBufferNew nominal resNom.buffer.len() == 0")
  assertEqInt(resEdge.buffer.len(), 0, "ringBufferNew boundary resEdge.buffer.len() == 0")
  ret 0
```

---

### `ringBufferLen` (`std/collections/deque.aipl`)

- **Signature**: `pub fn ringBufferLen[T](rb: CircularRingQueue[T]): int:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rb: CircularRingQueue[T]` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `ringBufferLen` (`free fn`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: `rb: CircularRingQueue[T] = CircularRingQueue(buffer = [42], head = 1, tail = 1, capacity = 64, count = 64)`; exercises core body path returning/computing `rb.count`.

```aipl
module tests.functions.collections.deque_z28_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_ringBufferLen_28(): int:
  let arg_rb = CircularRingQueue(buffer = [], head = 0, tail = 0, capacity = 4, count = 0)
  let edge_rb = CircularRingQueue(buffer = [], head = 0, tail = 0, capacity = 4, count = 0)
  let resNom = ringBufferLen(arg_rb)
  let resEdge = ringBufferLen(edge_rb)
  assertEqInt(resNom, 0, "ringBufferLen nominal resNom == 0")
  assertEqInt(resEdge, 0, "ringBufferLen boundary resEdge == 0")
  ret 0
```

---

### `ringBufferIsEmpty` (`std/collections/deque.aipl`)

- **Signature**: `pub fn ringBufferIsEmpty[T](rb: CircularRingQueue[T]): bool:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rb: CircularRingQueue[T]` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `ringBufferIsEmpty` (`free fn`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: `rb: CircularRingQueue[T] = CircularRingQueue(buffer = [42], head = 1, tail = 1, capacity = 64, count = 64)`; exercises core body path returning/computing `rb.count == 0`.

```aipl
module tests.functions.collections.deque_z29_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_ringBufferIsEmpty_29(): int:
  let arg_rb = CircularRingQueue(buffer = [], head = 0, tail = 0, capacity = 4, count = 0)
  let edge_rb = CircularRingQueue(buffer = [], head = 0, tail = 0, capacity = 4, count = 0)
  let resNom = ringBufferIsEmpty(arg_rb)
  let resEdge = ringBufferIsEmpty(edge_rb)
  assert(resNom == true, "ringBufferIsEmpty nominal resNom == true")
  assert(resEdge == true, "ringBufferIsEmpty boundary resEdge == true")
  ret 0
```

---

### `ringBufferPush` (`std/collections/deque.aipl`)

- **Signature**: `pub fn ringBufferPush[T](mut rb: CircularRingQueue[T], item: T): CircularRingQueue[T]:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut rb: CircularRingQueue[T], item: T` | **Returns**: `CircularRingQueue[T]`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `ringBufferPush` (`free fn`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: `rb: CircularRingQueue[T] = CircularRingQueue(buffer = [42], head = 1, tail = 1, capacity = 64, count = 64)`, `item: T = 42`; exercises core body path returning/computing `rb`.

```aipl
module tests.functions.collections.deque_z30_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_ringBufferPush_30(): int:
  let arg_rb = CircularRingQueue(buffer = [], head = 0, tail = 0, capacity = 4, count = 0)
  let edge_rb = CircularRingQueue(buffer = [], head = 0, tail = 0, capacity = 4, count = 0)
  let arg_item = 1
  let edge_item = 0
  let resNom = ringBufferPush(arg_rb, arg_item)
  let resEdge = ringBufferPush(edge_rb, edge_item)
  assertEqInt(resNom.buffer.len(), 1, "ringBufferPush nominal resNom.buffer.len() == 1")
  assertEqInt(resEdge.buffer.len(), 1, "ringBufferPush boundary resEdge.buffer.len() == 1")
  ret 0
```

---

### `ringBufferGet` (`std/collections/deque.aipl`)

- **Signature**: `pub fn ringBufferGet[T](rb: CircularRingQueue[T], idx: int): Option[T]:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rb: CircularRingQueue[T], idx: int` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `ringBufferGet` (`free fn`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: `rb: CircularRingQueue[T] = CircularRingQueue(buffer = [42], head = 1, tail = 1, capacity = 64, count = 64)`, `idx: int = 0`; exercises core body path returning/computing `Some(rb.buffer[realIdx])`.

```aipl
module tests.functions.collections.deque_z31_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_ringBufferGet_31(): int:
  let arg_rb = CircularRingQueue(buffer = [], head = 0, tail = 0, capacity = 4, count = 0)
  let edge_rb = CircularRingQueue(buffer = [], head = 0, tail = 0, capacity = 4, count = 0)
  let arg_idx = 1
  let edge_idx = 0
  let resNom = ringBufferGet(arg_rb, arg_idx)
  let resEdge = ringBufferGet(edge_rb, edge_idx)
  assert(resNom.isSome() == false, "ringBufferGet nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "ringBufferGet boundary resEdge.isSome() == false")
  ret 0
```

---

### `ringBufferToArray` (`std/collections/deque.aipl`)

- **Signature**: `pub fn ringBufferToArray[T](rb: CircularRingQueue[T]): [T]:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rb: CircularRingQueue[T]` | **Returns**: `[T]`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `ringBufferToArray` (`free fn`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: `rb: CircularRingQueue[T] = CircularRingQueue(buffer = [42], head = 1, tail = 1, capacity = 64, count = 64)`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.collections.deque_z32_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_ringBufferToArray_32(): int:
  let arg_rb = CircularRingQueue(buffer = [], head = 0, tail = 0, capacity = 4, count = 0)
  let edge_rb = CircularRingQueue(buffer = [], head = 0, tail = 0, capacity = 4, count = 0)
  let resNom = ringBufferToArray(arg_rb)
  let resEdge = ringBufferToArray(edge_rb)
  assertEqInt(resNom.len(), 0, "ringBufferToArray nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "ringBufferToArray boundary resEdge.len() == 0")
  ret 0
```

---

### `undoStackNew` (`std/collections/deque.aipl`)

- **Signature**: `pub fn undoStackNew(maxDepth: int = 50): UndoStack:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `maxDepth: int = 50` | **Returns**: `UndoStack`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `undoStackNew` (`free fn`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: `maxDepth: int = 1`; exercises core body path returning/computing `UndoStack(past = p, future = f, maxDepth = md)`.

```aipl
module tests.functions.collections.deque_z33_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_undoStackNew_33(): int:
  let arg_maxDepth = 4
  let edge_maxDepth = 1
  let resNom = undoStackNew(arg_maxDepth)
  let resEdge = undoStackNew(edge_maxDepth)
  assertEqInt(resNom.past.len(), 0, "undoStackNew nominal resNom.past.len() == 0")
  assertEqInt(resEdge.past.len(), 0, "undoStackNew boundary resEdge.past.len() == 0")
  ret 0
```

---

### `undoCanUndo` (`std/collections/deque.aipl`)

- **Signature**: `pub fn undoCanUndo(us: UndoStack): bool:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `us: UndoStack` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `undoCanUndo` (`free fn`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: `us: UndoStack = UndoStack(past = [42], future = [42], maxDepth = 1)`; exercises core body path returning/computing `us.past.len > 0`.

```aipl
module tests.functions.collections.deque_z34_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_undoCanUndo_34(): int:
  let arg_us = UndoStack(past = [], future = [], maxDepth = 4)
  let edge_us = UndoStack(past = [], future = [], maxDepth = 4)
  let resNom = undoCanUndo(arg_us)
  let resEdge = undoCanUndo(edge_us)
  assert(resNom == false, "undoCanUndo nominal resNom == false")
  assert(resEdge == false, "undoCanUndo boundary resEdge == false")
  ret 0
```

---

### `undoCanRedo` (`std/collections/deque.aipl`)

- **Signature**: `pub fn undoCanRedo(us: UndoStack): bool:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `us: UndoStack` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `undoCanRedo` (`free fn`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: `us: UndoStack = UndoStack(past = [42], future = [42], maxDepth = 1)`; exercises core body path returning/computing `us.future.len > 0`.

```aipl
module tests.functions.collections.deque_z35_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_undoCanRedo_35(): int:
  let arg_us = UndoStack(past = [], future = [], maxDepth = 4)
  let edge_us = UndoStack(past = [], future = [], maxDepth = 4)
  let resNom = undoCanRedo(arg_us)
  let resEdge = undoCanRedo(edge_us)
  assert(resNom == false, "undoCanRedo nominal resNom == false")
  assert(resEdge == false, "undoCanRedo boundary resEdge == false")
  ret 0
```

---

### `undoPush` (`std/collections/deque.aipl`)

- **Signature**: `pub fn undoPush(mut us: UndoStack, item: any): UndoStack:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut us: UndoStack, item: any` | **Returns**: `UndoStack`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `undoPush` (`free fn`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: `us: UndoStack = UndoStack(past = [42], future = [42], maxDepth = 1)`, `item: any = 42`; exercises core body path returning/computing `us`.

```aipl
module tests.functions.collections.deque_z36_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_undoPush_36(): int:
  let arg_us = UndoStack(past = [], future = [], maxDepth = 4)
  let edge_us = UndoStack(past = [], future = [], maxDepth = 4)
  let arg_item = 1
  let edge_item = 0
  let resNom = undoPush(arg_us, arg_item)
  let resEdge = undoPush(edge_us, edge_item)
  assertEqInt(resNom.past.len(), 1, "undoPush nominal resNom.past.len() == 1")
  assertEqInt(resEdge.past.len(), 1, "undoPush boundary resEdge.past.len() == 1")
  ret 0
```

---

### `undoStep` (`std/collections/deque.aipl`)

- **Signature**: `pub fn undoStep(mut us: UndoStack): Option[any]:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut us: UndoStack` | **Returns**: `Option[any]`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `undoStep` (`free fn`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: `us: UndoStack = UndoStack(past = [42], future = [42], maxDepth = 1)`; exercises core body path returning/computing `Some(item)`.

```aipl
module tests.functions.collections.deque_z37_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_undoStep_37(): int:
  let arg_us = UndoStack(past = [], future = [], maxDepth = 4)
  let edge_us = UndoStack(past = [], future = [], maxDepth = 4)
  let resNom = undoStep(arg_us)
  let resEdge = undoStep(edge_us)
  assert(resNom.isSome() == false, "undoStep nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "undoStep boundary resEdge.isSome() == false")
  ret 0
```

---

### `redoStep` (`std/collections/deque.aipl`)

- **Signature**: `pub fn redoStep(mut us: UndoStack): Option[any]:`
- **Import**: `import * from "std/collections/deque"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut us: UndoStack` | **Returns**: `Option[any]`
- **Unit Test**: `tests/functions/collections/deque_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `redoStep` (`free fn`) double-ended queue / circular ring / undo-redo stack invariant across head/tail wrap-around seams, full/empty boundaries, and redo branch truncation. Concrete nominal inputs: `us: UndoStack = UndoStack(past = [42], future = [42], maxDepth = 1)`; exercises core body path returning/computing `Some(item)`.

```aipl
module tests.functions.collections.deque_z38_test
import * from "std/collections/deque"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_deque_redoStep_38(): int:
  let arg_us = UndoStack(past = [], future = [], maxDepth = 4)
  let edge_us = UndoStack(past = [], future = [], maxDepth = 4)
  let resNom = redoStep(arg_us)
  let resEdge = redoStep(edge_us)
  assert(resNom.isSome() == false, "redoStep nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "redoStep boundary resEdge.isSome() == false")
  ret 0
```

---

### `dynVecNew` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn dynVecNew[T](): DynVec[T]:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `DynVec[T]`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `dynVecNew` (`free fn`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `DynVec(items = empty, capacity = 16)`.

```aipl
module tests.functions.collections.dyn_vec_z1_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_dynVecNew_1(): int:
  let resNom = dynVecNew()
  let resEdge = dynVecNew()
  assertEqInt(resNom.items.len(), 0, "dynVecNew nominal resNom.items.len() == 0")
  assertEqInt(resEdge.items.len(), 0, "dynVecNew boundary resEdge.items.len() == 0")
  ret 0
```

---

### `dynVecWithCapacity` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn dynVecWithCapacity[T](capacity: int): DynVec[T]:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `capacity: int` | **Returns**: `DynVec[T]`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `dynVecWithCapacity` (`free fn`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: `capacity: int = 64`; exercises core body path returning/computing `DynVec(items = empty, capacity = cap)`.

```aipl
module tests.functions.collections.dyn_vec_z2_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_dynVecWithCapacity_2(): int:
  let arg_capacity = 4
  let edge_capacity = 1
  let resNom = dynVecWithCapacity(arg_capacity)
  let resEdge = dynVecWithCapacity(edge_capacity)
  assertEqInt(resNom.items.len(), 0, "dynVecWithCapacity nominal resNom.items.len() == 0")
  assertEqInt(resEdge.items.len(), 0, "dynVecWithCapacity boundary resEdge.items.len() == 0")
  ret 0
```

---

### `len` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn (self: DynVec[T]) len(): int:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: DynVec[T]` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `len` (`self: DynVec[T]`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: receiver `recvObj: DynVec[T] = DynVec(items = [42], capacity = 64)`; exercises core body path returning/computing `self.items.len`.

```aipl
module tests.functions.collections.dyn_vec_z3_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_DynVec_T__len_3(): int:
  let recv_self = DynVec(items = [], capacity = 4)
  let edge_self = DynVec(items = [], capacity = 4)
  let resNom = recv_self.len()
  let resEdge = edge_self.len()
  assertEqInt(resNom, 0, "len nominal resNom == 0")
  assertEqInt(resEdge, 0, "len boundary resEdge == 0")
  ret 0
```

---

### `cap` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn (self: DynVec[T]) cap(): int:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: DynVec[T]` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `cap` (`self: DynVec[T]`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: receiver `recvObj: DynVec[T] = DynVec(items = [42], capacity = 64)`; exercises core body path returning/computing `self.capacity`.

```aipl
module tests.functions.collections.dyn_vec_z4_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_DynVec_T__cap_4(): int:
  let recv_self = DynVec(items = [], capacity = 4)
  let edge_self = DynVec(items = [], capacity = 4)
  let resNom = recv_self.cap()
  let resEdge = edge_self.cap()
  assertEqInt(resNom, 4, "cap nominal resNom == 4")
  assertEqInt(resEdge, 4, "cap boundary resEdge == 4")
  ret 0
```

---

### `isEmpty` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn (self: DynVec[T]) isEmpty(): bool:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: DynVec[T]` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `isEmpty` (`self: DynVec[T]`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: receiver `recvObj: DynVec[T] = DynVec(items = [42], capacity = 64)`; exercises core body path returning/computing `self.items.len == 0`.

```aipl
module tests.functions.collections.dyn_vec_z5_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_DynVec_T__isEmpty_5(): int:
  let recv_self = DynVec(items = [], capacity = 4)
  let edge_self = DynVec(items = [], capacity = 4)
  let resNom = recv_self.isEmpty()
  let resEdge = edge_self.isEmpty()
  assert(resNom == true, "isEmpty nominal resNom == true")
  assert(resEdge == true, "isEmpty boundary resEdge == true")
  ret 0
```

---

### `push` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn (mut self: DynVec[T]) push(val: T): void:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: DynVec[T]` | **Parameters**: `val: T` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `push` (`mut self: DynVec[T]`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: receiver `recvObj: DynVec[T] = DynVec(items = [42], capacity = 64)`, `val: T = 42`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.dyn_vec_z6_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_DynVec_T__push_6(): int:
  let mut recv_self = DynVec(items = [], capacity = 4)
  let mut edge_self = DynVec(items = [], capacity = 4)
  let arg_val = 1
  let edge_val = 0
  recv_self.push(arg_val)
  edge_self.push(edge_val)
  assertEqInt(recv_self.items.len(), 1, "push nominal recv_self.items.len() == 1")
  assertEqInt(edge_self.items.len(), 1, "push boundary edge_self.items.len() == 1")
  ret 0
```

---

### `pop` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn (mut self: DynVec[T]) pop(): Option[T]:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: DynVec[T]` | **Parameters**: `none` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `pop` (`mut self: DynVec[T]`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: receiver `recvObj: DynVec[T] = DynVec(items = [42], capacity = 64)`; exercises core body path returning/computing `Some(v)`.

```aipl
module tests.functions.collections.dyn_vec_z7_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_DynVec_T__pop_7(): int:
  let mut recv_self = DynVec(items = [], capacity = 4)
  let mut edge_self = DynVec(items = [], capacity = 4)
  let resNom = recv_self.pop()
  let resEdge = edge_self.pop()
  assert(resNom.isSome() == false, "pop nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "pop boundary resEdge.isSome() == false")
  ret 0
```

---

### `get` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn (self: DynVec[T]) get(index: int): Option[T]:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: DynVec[T]` | **Parameters**: `index: int` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `get` (`self: DynVec[T]`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: receiver `recvObj: DynVec[T] = DynVec(items = [42], capacity = 64)`, `index: int = 0`; exercises core body path returning/computing `Some(self.items[index])`.

```aipl
module tests.functions.collections.dyn_vec_z8_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_DynVec_T__get_8(): int:
  let recv_self = DynVec(items = [], capacity = 4)
  let edge_self = DynVec(items = [], capacity = 4)
  let arg_index = 4
  let edge_index = 1
  let resNom = recv_self.get(arg_index)
  let resEdge = edge_self.get(edge_index)
  assert(resNom.isSome() == false, "get nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "get boundary resEdge.isSome() == false")
  ret 0
```

---

### `set` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn (mut self: DynVec[T]) set(index: int, val: T): bool:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: DynVec[T]` | **Parameters**: `index: int, val: T` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `set` (`mut self: DynVec[T]`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: receiver `recvObj: DynVec[T] = DynVec(items = [42], capacity = 64)`, `index: int = 0`, `val: T = 42`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.collections.dyn_vec_z9_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_DynVec_T__set_9(): int:
  let mut recv_self = DynVec(items = [], capacity = 4)
  let mut edge_self = DynVec(items = [], capacity = 4)
  let arg_index = 4
  let edge_index = 1
  let arg_val = 1
  let edge_val = 0
  let resNom = recv_self.set(arg_index, arg_val)
  let resEdge = edge_self.set(edge_index, edge_val)
  assert(resNom == false, "set nominal resNom == false")
  assert(resEdge == false, "set boundary resEdge == false")
  ret 0
```

---

### `insert` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn (mut self: DynVec[T]) insert(index: int, val: T): bool:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: DynVec[T]` | **Parameters**: `index: int, val: T` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `insert` (`mut self: DynVec[T]`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: receiver `recvObj: DynVec[T] = DynVec(items = [42], capacity = 64)`, `index: int = 0`, `val: T = 42`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.collections.dyn_vec_z10_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_DynVec_T__insert_10(): int:
  let mut recv_self = DynVec(items = [], capacity = 4)
  let mut edge_self = DynVec(items = [], capacity = 4)
  let arg_index = 4
  let edge_index = 1
  let arg_val = 1
  let edge_val = 0
  let resNom = recv_self.insert(arg_index, arg_val)
  let resEdge = edge_self.insert(edge_index, edge_val)
  assert(resNom == false, "insert nominal resNom == false")
  assert(resEdge == false, "insert boundary resEdge == false")
  ret 0
```

---

### `remove` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn (mut self: DynVec[T]) remove(index: int): Option[T]:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: DynVec[T]` | **Parameters**: `index: int` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `remove` (`mut self: DynVec[T]`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: receiver `recvObj: DynVec[T] = DynVec(items = [42], capacity = 64)`, `index: int = 0`; exercises core body path returning/computing `Some(removed)`.

```aipl
module tests.functions.collections.dyn_vec_z11_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_DynVec_T__remove_11(): int:
  let mut recv_self = DynVec(items = [], capacity = 4)
  let mut edge_self = DynVec(items = [], capacity = 4)
  let arg_index = 4
  let edge_index = 1
  let resNom = recv_self.remove(arg_index)
  let resEdge = edge_self.remove(edge_index)
  assert(resNom.isSome() == false, "remove nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "remove boundary resEdge.isSome() == false")
  ret 0
```

---

### `swapRemove` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn (mut self: DynVec[T]) swapRemove(index: int): Option[T]:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: DynVec[T]` | **Parameters**: `index: int` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `swapRemove` (`mut self: DynVec[T]`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: receiver `recvObj: DynVec[T] = DynVec(items = [42], capacity = 64)`, `index: int = 0`; exercises core body path returning/computing `Some(removed)`.

```aipl
module tests.functions.collections.dyn_vec_z12_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_DynVec_T__swapRemove_12(): int:
  let mut recv_self = DynVec(items = [], capacity = 4)
  let mut edge_self = DynVec(items = [], capacity = 4)
  let arg_index = 4
  let edge_index = 1
  let resNom = recv_self.swapRemove(arg_index)
  let resEdge = edge_self.swapRemove(edge_index)
  assert(resNom.isSome() == false, "swapRemove nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "swapRemove boundary resEdge.isSome() == false")
  ret 0
```

---

### `clear` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn (mut self: DynVec[T]) clear(): void:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: DynVec[T]` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `clear` (`mut self: DynVec[T]`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: receiver `recvObj: DynVec[T] = DynVec(items = [42], capacity = 64)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.dyn_vec_z13_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_DynVec_T__clear_13(): int:
  let mut recv_self = DynVec(items = [], capacity = 4)
  let mut edge_self = DynVec(items = [], capacity = 4)
  recv_self.clear()
  edge_self.clear()
  assertEqInt(recv_self.items.len(), 0, "clear nominal recv_self.items.len() == 0")
  assertEqInt(edge_self.items.len(), 0, "clear boundary edge_self.items.len() == 0")
  ret 0
```

---

### `reserve` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn (mut self: DynVec[T]) reserve(additional: int): void:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: DynVec[T]` | **Parameters**: `additional: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `reserve` (`mut self: DynVec[T]`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: receiver `recvObj: DynVec[T] = DynVec(items = [42], capacity = 64)`, `additional: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.dyn_vec_z14_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_DynVec_T__reserve_14(): int:
  let mut recv_self = DynVec(items = [], capacity = 4)
  let mut edge_self = DynVec(items = [], capacity = 4)
  let arg_additional = 4
  let edge_additional = 1
  recv_self.reserve(arg_additional)
  edge_self.reserve(edge_additional)
  assertEqInt(recv_self.items.len(), 0, "reserve nominal recv_self.items.len() == 0")
  assertEqInt(edge_self.items.len(), 0, "reserve boundary edge_self.items.len() == 0")
  ret 0
```

---

### `first` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn (self: DynVec[T]) first(): Option[T]:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: DynVec[T]` | **Parameters**: `none` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `first` (`self: DynVec[T]`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: receiver `recvObj: DynVec[T] = DynVec(items = [42], capacity = 64)`; exercises core body path returning/computing `Some(self.items[0])`.

```aipl
module tests.functions.collections.dyn_vec_z15_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_DynVec_T__first_15(): int:
  let recv_self = DynVec(items = [], capacity = 4)
  let edge_self = DynVec(items = [], capacity = 4)
  let resNom = recv_self.first()
  let resEdge = edge_self.first()
  assert(resNom.isSome() == false, "first nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "first boundary resEdge.isSome() == false")
  ret 0
```

---

### `last` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn (self: DynVec[T]) last(): Option[T]:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: DynVec[T]` | **Parameters**: `none` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `last` (`self: DynVec[T]`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: receiver `recvObj: DynVec[T] = DynVec(items = [42], capacity = 64)`; exercises core body path returning/computing `Some(self.items[self.items.len - 1])`.

```aipl
module tests.functions.collections.dyn_vec_z16_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_DynVec_T__last_16(): int:
  let recv_self = DynVec(items = [], capacity = 4)
  let edge_self = DynVec(items = [], capacity = 4)
  let resNom = recv_self.last()
  let resEdge = edge_self.last()
  assert(resNom.isSome() == false, "last nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "last boundary resEdge.isSome() == false")
  ret 0
```

---

### `toArray` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn (self: DynVec[T]) toArray(): [T]:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: DynVec[T]` | **Parameters**: `none` | **Returns**: `[T]`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `toArray` (`self: DynVec[T]`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: receiver `recvObj: DynVec[T] = DynVec(items = [42], capacity = 64)`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.collections.dyn_vec_z17_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_DynVec_T__toArray_17(): int:
  let recv_self = DynVec(items = [], capacity = 4)
  let edge_self = DynVec(items = [], capacity = 4)
  let resNom = recv_self.toArray()
  let resEdge = edge_self.toArray()
  assertEqInt(resNom.len(), 0, "toArray nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "toArray boundary resEdge.len() == 0")
  ret 0
```

---

### `reverse` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn (mut self: DynVec[T]) reverse(): void:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: DynVec[T]` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `reverse` (`mut self: DynVec[T]`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: receiver `recvObj: DynVec[T] = DynVec(items = [42], capacity = 64)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.dyn_vec_z18_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_DynVec_T__reverse_18(): int:
  let mut recv_self = DynVec(items = [], capacity = 4)
  let mut edge_self = DynVec(items = [], capacity = 4)
  recv_self.reverse()
  edge_self.reverse()
  assertEqInt(recv_self.items.len(), 0, "reverse nominal recv_self.items.len() == 0")
  assertEqInt(edge_self.items.len(), 0, "reverse boundary edge_self.items.len() == 0")
  ret 0
```

---

### `asSlice` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn (self: DynVec[T]) asSlice(start: int, end: int): ArraySlice[T]:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: DynVec[T]` | **Parameters**: `start: int, end: int` | **Returns**: `ArraySlice[T]`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `asSlice` (`self: DynVec[T]`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: receiver `recvObj: DynVec[T] = DynVec(items = [42], capacity = 64)`, `start: int = 1`, `end: int = 1`; exercises core body path returning/computing `ArraySlice(items = self.items, start = s, end = e)`.

```aipl
module tests.functions.collections.dyn_vec_z19_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_DynVec_T__asSlice_19(): int:
  let recv_self = DynVec(items = [], capacity = 4)
  let edge_self = DynVec(items = [], capacity = 4)
  let arg_start = 1
  let edge_start = 0
  let arg_end = 4
  let edge_end = 1
  let resNom = recv_self.asSlice(arg_start, arg_end)
  let resEdge = edge_self.asSlice(edge_start, edge_end)
  assertEqInt(resNom.items.len(), 0, "asSlice nominal resNom.items.len() == 0")
  assertEqInt(resEdge.items.len(), 0, "asSlice boundary resEdge.items.len() == 0")
  ret 0
```

---

### `len` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn (self: ArraySlice[T]) len(): int:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: ArraySlice[T]` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `len` (`self: ArraySlice[T]`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: receiver `recvObj: ArraySlice[T] = ArraySlice(items = [42], start = 1, end = 1)`; exercises core body path returning/computing `self.end - self.start`.

```aipl
module tests.functions.collections.dyn_vec_z20_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_ArraySlice_T__len_20(): int:
  let recv_self = ArraySlice(items = [], start = 1, end = 4)
  let edge_self = ArraySlice(items = [], start = 0, end = 1)
  let resNom = recv_self.len()
  let resEdge = edge_self.len()
  assertEqInt(resNom, 3, "len nominal resNom == 3")
  assertEqInt(resEdge, 1, "len boundary resEdge == 1")
  ret 0
```

---

### `isEmpty` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn (self: ArraySlice[T]) isEmpty(): bool:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: ArraySlice[T]` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `isEmpty` (`self: ArraySlice[T]`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: receiver `recvObj: ArraySlice[T] = ArraySlice(items = [42], start = 1, end = 1)`; exercises core body path returning/computing `self.end <= self.start`.

```aipl
module tests.functions.collections.dyn_vec_z21_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_ArraySlice_T__isEmpty_21(): int:
  let recv_self = ArraySlice(items = [], start = 1, end = 4)
  let edge_self = ArraySlice(items = [], start = 0, end = 1)
  let resNom = recv_self.isEmpty()
  let resEdge = edge_self.isEmpty()
  assert(resNom == false, "isEmpty nominal resNom == false")
  assert(resEdge == false, "isEmpty boundary resEdge == false")
  ret 0
```

---

### `get` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn (self: ArraySlice[T]) get(index: int): Option[T]:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: ArraySlice[T]` | **Parameters**: `index: int` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `get` (`self: ArraySlice[T]`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: receiver `recvObj: ArraySlice[T] = ArraySlice(items = [42], start = 1, end = 1)`, `index: int = 0`; exercises core body path returning/computing `Some(self.items[realIdx])`.

```aipl
module tests.functions.collections.dyn_vec_z22_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_ArraySlice_T__get_22(): int:
  let recv_self = ArraySlice(items = [], start = 1, end = 4)
  let edge_self = ArraySlice(items = [], start = 0, end = 1)
  let arg_index = 4
  let edge_index = 1
  let resNom = recv_self.get(arg_index)
  let resEdge = edge_self.get(edge_index)
  assert(resNom.isSome() == false, "get nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "get boundary resEdge.isSome() == false")
  ret 0
```

---

### `toArray` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn (self: ArraySlice[T]) toArray(): [T]:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: ArraySlice[T]` | **Parameters**: `none` | **Returns**: `[T]`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `toArray` (`self: ArraySlice[T]`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: receiver `recvObj: ArraySlice[T] = ArraySlice(items = [42], start = 1, end = 1)`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.collections.dyn_vec_z23_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_ArraySlice_T__toArray_23(): int:
  let recv_self = ArraySlice(items = [], start = 1, end = 4)
  let edge_self = ArraySlice(items = [], start = 0, end = 1)
  let resNom = recv_self.toArray()
  let resEdge = edge_self.toArray()
  assertEqInt(resNom.len(), 3, "toArray nominal resNom.len() == 3")
  assertEqInt(resEdge.len(), 1, "toArray boundary resEdge.len() == 1")
  ret 0
```

---

### `sortInts` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn sortInts(arr: [int]): [int]:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `arr: [int]` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `sortInts` (`free fn`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: `arr: [int] = [1]`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.collections.dyn_vec_z24_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_sortInts_24(): int:
  let arg_arr = [2]
  let edge_arr = []
  let resNom = sortInts(arg_arr)
  let resEdge = sortInts(edge_arr)
  assertEqInt(resNom.len(), 1, "sortInts nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "sortInts boundary resEdge.len() == 0")
  ret 0
```

---

### `sortStrings` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn sortStrings(arr: [str]): [str]:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `arr: [str]` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `sortStrings` (`free fn`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: `arr: [str] = ["aipl_test"]`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.collections.dyn_vec_z25_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_sortStrings_25(): int:
  let arg_arr = ["test"]
  let edge_arr = []
  let resNom = sortStrings(arg_arr)
  let resEdge = sortStrings(edge_arr)
  assertEqInt(resNom.len(), 1, "sortStrings nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "sortStrings boundary resEdge.len() == 0")
  ret 0
```

---

### `isDigitCodeSort` (`std/collections/dyn_vec.aipl`)

- **Signature**: `fn isDigitCodeSort(c: int): bool:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `isDigitCodeSort` (`free fn`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: `c: int = 1`; exercises core body path returning/computing `c >= 48 and c <= 57`.

```aipl
module tests.functions.collections.dyn_vec_z26_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_isDigitCodeSort_26(): int:
  let arg_c = 2
  let edge_c = 0
  let resNom = isDigitCodeSort(arg_c)
  let resEdge = isDigitCodeSort(edge_c)
  assert(resNom == false, "isDigitCodeSort nominal resNom == false")
  assert(resEdge == false, "isDigitCodeSort boundary resEdge == false")
  ret 0
```

---

### `naturalLess` (`std/collections/dyn_vec.aipl`)

- **Signature**: `fn naturalLess(a: str, b: str): bool:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: str, b: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `naturalLess` (`free fn`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: `a: str = "aipl_test"`, `b: str = "aipl_test"`; exercises core body path returning/computing `a.len < b.len`.

```aipl
module tests.functions.collections.dyn_vec_z27_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_naturalLess_27(): int:
  let arg_a = "test"
  let edge_a = "a"
  let arg_b = "test"
  let edge_b = "a"
  let resNom = naturalLess(arg_a, arg_b)
  let resEdge = naturalLess(edge_a, edge_b)
  assert(resNom == false, "naturalLess nominal resNom == false")
  assert(resEdge == false, "naturalLess boundary resEdge == false")
  ret 0
```

---

### `sortStringsNatural` (`std/collections/dyn_vec.aipl`)

- **Signature**: `pub fn sortStringsNatural(arr: [str]): [str]:`
- **Import**: `import * from "std/collections/dyn_vec"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `arr: [str]` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/collections/dyn_vec_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `sortStringsNatural` (`free fn`) dynamic vector/slice/sort invariant across empty `[]`, geometric capacity growth, order-preserving vs O(1) swap-remove, and natural alphanumeric ordering. Concrete nominal inputs: `arr: [str] = ["aipl_test"]`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.collections.dyn_vec_z28_test
import * from "std/collections/dyn_vec"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dyn_vec_sortStringsNatural_28(): int:
  let arg_arr = ["test"]
  let edge_arr = []
  let resNom = sortStringsNatural(arg_arr)
  let resEdge = sortStringsNatural(edge_arr)
  assertEqInt(resNom.len(), 1, "sortStringsNatural nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "sortStringsNatural boundary resEdge.len() == 0")
  ret 0
```

---

### `dsuNew` (`std/collections/graph_topology.aipl`)

- **Signature**: `pub fn dsuNew(size: int): DisjointSetUnion:`
- **Import**: `import * from "std/collections/graph_topology"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `size: int` | **Returns**: `DisjointSetUnion`
- **Unit Test**: `tests/functions/collections/graph_topology_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `dsuNew` (`free fn`) Disjoint-Set Union path compression / union-by-rank component tracking or Dijkstra shortest-path optimality on weighted directed graphs. Concrete nominal inputs: `size: int = 64`; exercises core body path returning/computing `DisjointSetUnion(parent = p, rank = r, numSets = sz)`.

```aipl
module tests.functions.collections.graph_topology_z1_test
import * from "std/collections/graph_topology"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_graph_topology_dsuNew_1(): int:
  let arg_size = 4
  let edge_size = 1
  let resNom = dsuNew(arg_size)
  let resEdge = dsuNew(edge_size)
  assertEqInt(resNom.parent.len(), 4, "dsuNew nominal resNom.parent.len() == 4")
  assertEqInt(resEdge.parent.len(), 1, "dsuNew boundary resEdge.parent.len() == 1")
  ret 0
```

---

### `find` (`std/collections/graph_topology.aipl`)

- **Signature**: `pub fn (mut self: DisjointSetUnion) find(x: int): int:`
- **Import**: `import * from "std/collections/graph_topology"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: DisjointSetUnion` | **Parameters**: `x: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/graph_topology_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `find` (`mut self: DisjointSetUnion`) Disjoint-Set Union path compression / union-by-rank component tracking or Dijkstra shortest-path optimality on weighted directed graphs. Concrete nominal inputs: receiver `recvObj: DisjointSetUnion = DisjointSetUnion(parent = [1], rank = [1], numSets = 1)`, `x: int = 1`; exercises core body path returning/computing `root`.

```aipl
module tests.functions.collections.graph_topology_z2_test
import * from "std/collections/graph_topology"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_graph_topology_DisjointSetUnion_find_2(): int:
  let mut recv_self = DisjointSetUnion(parent = [], rank = [], numSets = 4)
  let mut edge_self = DisjointSetUnion(parent = [], rank = [], numSets = 1)
  let arg_x = 1
  let edge_x = 0
  let resNom = recv_self.find(arg_x)
  let resEdge = edge_self.find(edge_x)
  assertEqInt(resNom, -1, "find nominal resNom == -1")
  assertEqInt(resEdge, -1, "find boundary resEdge == -1")
  ret 0
```

---

### `union` (`std/collections/graph_topology.aipl`)

- **Signature**: `pub fn (mut self: DisjointSetUnion) union(x: int, y: int): bool:`
- **Import**: `import * from "std/collections/graph_topology"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: DisjointSetUnion` | **Parameters**: `x: int, y: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/graph_topology_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `union` (`mut self: DisjointSetUnion`) Disjoint-Set Union path compression / union-by-rank component tracking or Dijkstra shortest-path optimality on weighted directed graphs. Concrete nominal inputs: receiver `recvObj: DisjointSetUnion = DisjointSetUnion(parent = [1], rank = [1], numSets = 1)`, `x: int = 1`, `y: int = 1`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.collections.graph_topology_z3_test
import * from "std/collections/graph_topology"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_graph_topology_DisjointSetUnion_union_3(): int:
  let mut recv_self = DisjointSetUnion(parent = [], rank = [], numSets = 4)
  let mut edge_self = DisjointSetUnion(parent = [], rank = [], numSets = 1)
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let resNom = recv_self.union(arg_x, arg_y)
  let resEdge = edge_self.union(edge_x, edge_y)
  assert(resNom == false, "union nominal resNom == false")
  assert(resEdge == false, "union boundary resEdge == false")
  ret 0
```

---

### `connected` (`std/collections/graph_topology.aipl`)

- **Signature**: `pub fn (mut self: DisjointSetUnion) connected(x: int, y: int): bool:`
- **Import**: `import * from "std/collections/graph_topology"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: DisjointSetUnion` | **Parameters**: `x: int, y: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/graph_topology_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `connected` (`mut self: DisjointSetUnion`) Disjoint-Set Union path compression / union-by-rank component tracking or Dijkstra shortest-path optimality on weighted directed graphs. Concrete nominal inputs: receiver `recvObj: DisjointSetUnion = DisjointSetUnion(parent = [1], rank = [1], numSets = 1)`, `x: int = 1`, `y: int = 1`; exercises core body path returning/computing `rx >= 0 and rx == ry`.

```aipl
module tests.functions.collections.graph_topology_z4_test
import * from "std/collections/graph_topology"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_graph_topology_DisjointSetUnion_connected_4(): int:
  let mut recv_self = DisjointSetUnion(parent = [], rank = [], numSets = 4)
  let mut edge_self = DisjointSetUnion(parent = [], rank = [], numSets = 1)
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let resNom = recv_self.connected(arg_x, arg_y)
  let resEdge = edge_self.connected(edge_x, edge_y)
  assert(resNom == false, "connected nominal resNom == false")
  assert(resEdge == false, "connected boundary resEdge == false")
  ret 0
```

---

### `countSets` (`std/collections/graph_topology.aipl`)

- **Signature**: `pub fn (self: DisjointSetUnion) countSets(): int:`
- **Import**: `import * from "std/collections/graph_topology"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: DisjointSetUnion` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/graph_topology_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `countSets` (`self: DisjointSetUnion`) Disjoint-Set Union path compression / union-by-rank component tracking or Dijkstra shortest-path optimality on weighted directed graphs. Concrete nominal inputs: receiver `recvObj: DisjointSetUnion = DisjointSetUnion(parent = [1], rank = [1], numSets = 1)`; exercises core body path returning/computing `self.numSets`.

```aipl
module tests.functions.collections.graph_topology_z5_test
import * from "std/collections/graph_topology"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_graph_topology_DisjointSetUnion_countSets_5(): int:
  let recv_self = DisjointSetUnion(parent = [], rank = [], numSets = 4)
  let edge_self = DisjointSetUnion(parent = [], rank = [], numSets = 1)
  let resNom = recv_self.countSets()
  let resEdge = edge_self.countSets()
  assertEqInt(resNom, 4, "countSets nominal resNom == 4")
  assertEqInt(resEdge, 1, "countSets boundary resEdge == 1")
  ret 0
```

---

### `directedGraphNew` (`std/collections/graph_topology.aipl`)

- **Signature**: `pub fn directedGraphNew(numNodes: int): DirectedGraph:`
- **Import**: `import * from "std/collections/graph_topology"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `numNodes: int` | **Returns**: `DirectedGraph`
- **Unit Test**: `tests/functions/collections/graph_topology_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `directedGraphNew` (`free fn`) Disjoint-Set Union path compression / union-by-rank component tracking or Dijkstra shortest-path optimality on weighted directed graphs. Concrete nominal inputs: `numNodes: int = 1`; exercises core body path returning/computing `DirectedGraph(numNodes = n, adjacency = adj, weights = wts)`.

```aipl
module tests.functions.collections.graph_topology_z6_test
import * from "std/collections/graph_topology"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_graph_topology_directedGraphNew_6(): int:
  let arg_numNodes = 4
  let edge_numNodes = 1
  let resNom = directedGraphNew(arg_numNodes)
  let resEdge = directedGraphNew(edge_numNodes)
  assertEqInt(resNom.numNodes, 4, "directedGraphNew nominal resNom.numNodes == 4")
  assertEqInt(resEdge.numNodes, 1, "directedGraphNew boundary resEdge.numNodes == 1")
  ret 0
```

---

### `addEdge` (`std/collections/graph_topology.aipl`)

- **Signature**: `pub fn (mut self: DirectedGraph) addEdge(u: int, v: int, weight: int): void:`
- **Import**: `import * from "std/collections/graph_topology"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: DirectedGraph` | **Parameters**: `u: int, v: int, weight: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/graph_topology_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `addEdge` (`mut self: DirectedGraph`) Disjoint-Set Union path compression / union-by-rank component tracking or Dijkstra shortest-path optimality on weighted directed graphs. Concrete nominal inputs: receiver `recvObj: DirectedGraph = DirectedGraph(numNodes = 1, adjacency = [[0]], weights = [[0]])`, `u: int = 1`, `v: int = 1`, `weight: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.graph_topology_z7_test
import * from "std/collections/graph_topology"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_graph_topology_DirectedGraph_addEdge_7(): int:
  let mut recv_self = DirectedGraph(numNodes = 4, adjacency = [], weights = [])
  let mut edge_self = DirectedGraph(numNodes = 1, adjacency = [], weights = [])
  let arg_u = 2
  let edge_u = 0
  let arg_v = 2
  let edge_v = 0
  let arg_weight = 2
  let edge_weight = 0
  recv_self.addEdge(arg_u, arg_v, arg_weight)
  edge_self.addEdge(edge_u, edge_v, edge_weight)
  assertEqInt(recv_self.numNodes, 4, "addEdge nominal recv_self.numNodes == 4")
  assertEqInt(edge_self.numNodes, 1, "addEdge boundary edge_self.numNodes == 1")
  ret 0
```

---

### `dijkstraShortestPath` (`std/collections/graph_topology.aipl`)

- **Signature**: `pub fn (self: DirectedGraph) dijkstraShortestPath(startNode: int, endNode: int): Option[[int]]:`
- **Import**: `import * from "std/collections/graph_topology"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: DirectedGraph` | **Parameters**: `startNode: int, endNode: int` | **Returns**: `Option[[int]]`
- **Unit Test**: `tests/functions/collections/graph_topology_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `dijkstraShortestPath` (`self: DirectedGraph`) Disjoint-Set Union path compression / union-by-rank component tracking or Dijkstra shortest-path optimality on weighted directed graphs. Concrete nominal inputs: receiver `recvObj: DirectedGraph = DirectedGraph(numNodes = 1, adjacency = [[0]], weights = [[0]])`, `startNode: int = 1`, `endNode: int = 1`; exercises core body path returning/computing `Some(path)`.

```aipl
module tests.functions.collections.graph_topology_z8_test
import * from "std/collections/graph_topology"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_graph_topology_DirectedGraph_dijkstraShortestPath_8(): int:
  let recv_self = DirectedGraph(numNodes = 4, adjacency = [], weights = [])
  let edge_self = DirectedGraph(numNodes = 1, adjacency = [], weights = [])
  let arg_startNode = 4
  let edge_startNode = 1
  let arg_endNode = 4
  let edge_endNode = 1
  let resNom = recv_self.dijkstraShortestPath(arg_startNode, arg_endNode)
  let resEdge = edge_self.dijkstraShortestPath(edge_startNode, edge_endNode)
  assert(resNom.isSome() == false, "dijkstraShortestPath nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "dijkstraShortestPath boundary resEdge.isSome() == false")
  ret 0
```

---

### `flatArray2DNew` (`std/collections/grid2d_array.aipl`)

- **Signature**: `pub fn flatArray2DNew[T](width: int, height: int, defaultVal: T): FlatArray2D[T]:`
- **Import**: `import * from "std/collections/grid2d_array"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `width: int, height: int, defaultVal: T` | **Returns**: `FlatArray2D[T]`
- **Unit Test**: `tests/functions/collections/grid2d_array_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `flatArray2DNew` (`free fn`) 2D/3D flat grid row-major indexing, corner/edge/interior 4-way and 8-way neighbor counts, and out-of-bounds safety. Concrete nominal inputs: `width: int = 128`, `height: int = 128`, `defaultVal: T = 42`; exercises core body path returning/computing `FlatArray2D(width = w, height = h, data = d)`.

```aipl
module tests.functions.collections.grid2d_array_z1_test
import * from "std/collections/grid2d_array"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_grid2d_array_flatArray2DNew_1(): int:
  let arg_width = 4
  let edge_width = 1
  let arg_height = 4
  let edge_height = 1
  let arg_defaultVal = 1
  let edge_defaultVal = 0
  let resNom = flatArray2DNew(arg_width, arg_height, arg_defaultVal)
  let resEdge = flatArray2DNew(edge_width, edge_height, edge_defaultVal)
  assertEqInt(resNom.width, 4, "flatArray2DNew nominal resNom.width == 4")
  assertEqInt(resEdge.width, 1, "flatArray2DNew boundary resEdge.width == 1")
  ret 0
```

---

### `inBounds` (`std/collections/grid2d_array.aipl`)

- **Signature**: `pub fn (self: FlatArray2D[T]) inBounds(x: int, y: int): bool:`
- **Import**: `import * from "std/collections/grid2d_array"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: FlatArray2D[T]` | **Parameters**: `x: int, y: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/grid2d_array_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `inBounds` (`self: FlatArray2D[T]`) 2D/3D flat grid row-major indexing, corner/edge/interior 4-way and 8-way neighbor counts, and out-of-bounds safety. Concrete nominal inputs: receiver `recvObj: FlatArray2D[T] = FlatArray2D(width = 128, height = 128, data = [42])`, `x: int = 1`, `y: int = 1`; exercises core body path returning/computing `x >= 0 and x < self.width and y >= 0 and y < self.height`.

```aipl
module tests.functions.collections.grid2d_array_z2_test
import * from "std/collections/grid2d_array"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_grid2d_array_FlatArray2D_T__inBounds_2(): int:
  let recv_self = FlatArray2D(width = 4, height = 4, data = [])
  let edge_self = FlatArray2D(width = 4, height = 4, data = [])
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let resNom = recv_self.inBounds(arg_x, arg_y)
  let resEdge = edge_self.inBounds(edge_x, edge_y)
  assert(resNom == true, "inBounds nominal resNom == true")
  assert(resEdge == true, "inBounds boundary resEdge == true")
  ret 0
```

---

### `index` (`std/collections/grid2d_array.aipl`)

- **Signature**: `pub fn (self: FlatArray2D[T]) index(x: int, y: int): int:`
- **Import**: `import * from "std/collections/grid2d_array"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: FlatArray2D[T]` | **Parameters**: `x: int, y: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/grid2d_array_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `index` (`self: FlatArray2D[T]`) 2D/3D flat grid row-major indexing, corner/edge/interior 4-way and 8-way neighbor counts, and out-of-bounds safety. Concrete nominal inputs: receiver `recvObj: FlatArray2D[T] = FlatArray2D(width = 128, height = 128, data = [42])`, `x: int = 1`, `y: int = 1`; exercises core body path returning/computing `y * self.width + x`.

```aipl
module tests.functions.collections.grid2d_array_z3_test
import * from "std/collections/grid2d_array"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_grid2d_array_FlatArray2D_T__index_3(): int:
  let recv_self = FlatArray2D(width = 4, height = 4, data = [])
  let edge_self = FlatArray2D(width = 4, height = 4, data = [])
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let resNom = recv_self.index(arg_x, arg_y)
  let resEdge = edge_self.index(edge_x, edge_y)
  assertEqInt(resNom, 5, "index nominal resNom == 5")
  assertEqInt(resEdge, 0, "index boundary resEdge == 0")
  ret 0
```

---

### `get` (`std/collections/grid2d_array.aipl`)

- **Signature**: `pub fn (self: FlatArray2D[T]) get(x: int, y: int): Option[T]:`
- **Import**: `import * from "std/collections/grid2d_array"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: FlatArray2D[T]` | **Parameters**: `x: int, y: int` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/grid2d_array_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `get` (`self: FlatArray2D[T]`) 2D/3D flat grid row-major indexing, corner/edge/interior 4-way and 8-way neighbor counts, and out-of-bounds safety. Concrete nominal inputs: receiver `recvObj: FlatArray2D[T] = FlatArray2D(width = 128, height = 128, data = [42])`, `x: int = 1`, `y: int = 1`; exercises core body path returning/computing `Some(self.data[idx])`.

```aipl
module tests.functions.collections.grid2d_array_z4_test
import * from "std/collections/grid2d_array"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_grid2d_array_FlatArray2D_T__get_4(): int:
  let recv_self = FlatArray2D(width = 4, height = 4, data = [])
  let edge_self = FlatArray2D(width = 4, height = 4, data = [])
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let resNom = recv_self.get(arg_x, arg_y)
  let resEdge = edge_self.get(edge_x, edge_y)
  assert(resNom.isSome() == true, "get nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "get boundary resEdge.isSome() == true")
  ret 0
```

---

### `set` (`std/collections/grid2d_array.aipl`)

- **Signature**: `pub fn (mut self: FlatArray2D[T]) set(x: int, y: int, val: T): bool:`
- **Import**: `import * from "std/collections/grid2d_array"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: FlatArray2D[T]` | **Parameters**: `x: int, y: int, val: T` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/grid2d_array_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `set` (`mut self: FlatArray2D[T]`) 2D/3D flat grid row-major indexing, corner/edge/interior 4-way and 8-way neighbor counts, and out-of-bounds safety. Concrete nominal inputs: receiver `recvObj: FlatArray2D[T] = FlatArray2D(width = 128, height = 128, data = [42])`, `x: int = 1`, `y: int = 1`, `val: T = 42`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.collections.grid2d_array_z5_test
import * from "std/collections/grid2d_array"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_grid2d_array_FlatArray2D_T__set_5(): int:
  let mut recv_self = FlatArray2D(width = 4, height = 4, data = [])
  let mut edge_self = FlatArray2D(width = 4, height = 4, data = [])
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let arg_val = 1
  let edge_val = 0
  let resNom = recv_self.set(arg_x, arg_y, arg_val)
  let resEdge = edge_self.set(edge_x, edge_y, edge_val)
  assert(resNom == true, "set nominal resNom == true")
  assert(resEdge == true, "set boundary resEdge == true")
  ret 0
```

---

### `fill` (`std/collections/grid2d_array.aipl`)

- **Signature**: `pub fn (mut self: FlatArray2D[T]) fill(val: T): void:`
- **Import**: `import * from "std/collections/grid2d_array"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: FlatArray2D[T]` | **Parameters**: `val: T` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/grid2d_array_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `fill` (`mut self: FlatArray2D[T]`) 2D/3D flat grid row-major indexing, corner/edge/interior 4-way and 8-way neighbor counts, and out-of-bounds safety. Concrete nominal inputs: receiver `recvObj: FlatArray2D[T] = FlatArray2D(width = 128, height = 128, data = [42])`, `val: T = 42`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.grid2d_array_z6_test
import * from "std/collections/grid2d_array"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_grid2d_array_FlatArray2D_T__fill_6(): int:
  let mut recv_self = FlatArray2D(width = 4, height = 4, data = [])
  let mut edge_self = FlatArray2D(width = 4, height = 4, data = [])
  let arg_val = 1
  let edge_val = 0
  recv_self.fill(arg_val)
  edge_self.fill(edge_val)
  assertEqInt(recv_self.width, 4, "fill nominal recv_self.width == 4")
  assertEqInt(edge_self.width, 4, "fill boundary edge_self.width == 4")
  ret 0
```

---

### `neighbors4` (`std/collections/grid2d_array.aipl`)

- **Signature**: `pub fn (self: FlatArray2D[T]) neighbors4(x: int, y: int): [T]:`
- **Import**: `import * from "std/collections/grid2d_array"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: FlatArray2D[T]` | **Parameters**: `x: int, y: int` | **Returns**: `[T]`
- **Unit Test**: `tests/functions/collections/grid2d_array_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `neighbors4` (`self: FlatArray2D[T]`) 2D/3D flat grid row-major indexing, corner/edge/interior 4-way and 8-way neighbor counts, and out-of-bounds safety. Concrete nominal inputs: receiver `recvObj: FlatArray2D[T] = FlatArray2D(width = 128, height = 128, data = [42])`, `x: int = 1`, `y: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.collections.grid2d_array_z7_test
import * from "std/collections/grid2d_array"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_grid2d_array_FlatArray2D_T__neighbors4_7(): int:
  let recv_self = FlatArray2D(width = 4, height = 4, data = [])
  let edge_self = FlatArray2D(width = 4, height = 4, data = [])
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let resNom = recv_self.neighbors4(arg_x, arg_y)
  let resEdge = edge_self.neighbors4(edge_x, edge_y)
  assertEqInt(resNom.len(), 4, "neighbors4 nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 2, "neighbors4 boundary resEdge.len() == 2")
  ret 0
```

---

### `neighbors8` (`std/collections/grid2d_array.aipl`)

- **Signature**: `pub fn (self: FlatArray2D[T]) neighbors8(x: int, y: int): [T]:`
- **Import**: `import * from "std/collections/grid2d_array"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: FlatArray2D[T]` | **Parameters**: `x: int, y: int` | **Returns**: `[T]`
- **Unit Test**: `tests/functions/collections/grid2d_array_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `neighbors8` (`self: FlatArray2D[T]`) 2D/3D flat grid row-major indexing, corner/edge/interior 4-way and 8-way neighbor counts, and out-of-bounds safety. Concrete nominal inputs: receiver `recvObj: FlatArray2D[T] = FlatArray2D(width = 128, height = 128, data = [42])`, `x: int = 1`, `y: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.collections.grid2d_array_z8_test
import * from "std/collections/grid2d_array"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_grid2d_array_FlatArray2D_T__neighbors8_8(): int:
  let recv_self = FlatArray2D(width = 4, height = 4, data = [])
  let edge_self = FlatArray2D(width = 4, height = 4, data = [])
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let resNom = recv_self.neighbors8(arg_x, arg_y)
  let resEdge = edge_self.neighbors8(edge_x, edge_y)
  assertEqInt(resNom.len(), 8, "neighbors8 nominal resNom.len() == 8")
  assertEqInt(resEdge.len(), 3, "neighbors8 boundary resEdge.len() == 3")
  ret 0
```

---

### `flatArray3DNew` (`std/collections/grid2d_array.aipl`)

- **Signature**: `pub fn flatArray3DNew[T](width: int, height: int, depth: int, defaultVal: T): FlatArray3D[T]:`
- **Import**: `import * from "std/collections/grid2d_array"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `width: int, height: int, depth: int, defaultVal: T` | **Returns**: `FlatArray3D[T]`
- **Unit Test**: `tests/functions/collections/grid2d_array_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `flatArray3DNew` (`free fn`) 2D/3D flat grid row-major indexing, corner/edge/interior 4-way and 8-way neighbor counts, and out-of-bounds safety. Concrete nominal inputs: `width: int = 128`, `height: int = 128`, `depth: int = 1`, `defaultVal: T = 42`; exercises core body path returning/computing `FlatArray3D(width = w, height = h, depth = dp, data = d)`.

```aipl
module tests.functions.collections.grid2d_array_z9_test
import * from "std/collections/grid2d_array"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_grid2d_array_flatArray3DNew_9(): int:
  let arg_width = 4
  let edge_width = 1
  let arg_height = 4
  let edge_height = 1
  let arg_depth = 4
  let edge_depth = 1
  let arg_defaultVal = 1
  let edge_defaultVal = 0
  let resNom = flatArray3DNew(arg_width, arg_height, arg_depth, arg_defaultVal)
  let resEdge = flatArray3DNew(edge_width, edge_height, edge_depth, edge_defaultVal)
  assertEqInt(resNom.width, 4, "flatArray3DNew nominal resNom.width == 4")
  assertEqInt(resEdge.width, 1, "flatArray3DNew boundary resEdge.width == 1")
  ret 0
```

---

### `inBounds` (`std/collections/grid2d_array.aipl`)

- **Signature**: `pub fn (self: FlatArray3D[T]) inBounds(x: int, y: int, z: int): bool:`
- **Import**: `import * from "std/collections/grid2d_array"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: FlatArray3D[T]` | **Parameters**: `x: int, y: int, z: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/grid2d_array_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `inBounds` (`self: FlatArray3D[T]`) 2D/3D flat grid row-major indexing, corner/edge/interior 4-way and 8-way neighbor counts, and out-of-bounds safety. Concrete nominal inputs: receiver `recvObj: FlatArray3D[T] = FlatArray3D(width = 128, height = 128, depth = 1, data = [42])`, `x: int = 1`, `y: int = 1`, `z: int = 1`; exercises core body path returning/computing `x >= 0 and x < self.width and y >= 0 and y < self.height and z >= 0 and z < self.depth`.

```aipl
module tests.functions.collections.grid2d_array_z10_test
import * from "std/collections/grid2d_array"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_grid2d_array_FlatArray3D_T__inBounds_10(): int:
  let recv_self = FlatArray3D(width = 4, height = 4, depth = 0, data = [])
  let edge_self = FlatArray3D(width = 4, height = 4, depth = 0, data = [])
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let arg_z = 1
  let edge_z = 0
  let resNom = recv_self.inBounds(arg_x, arg_y, arg_z)
  let resEdge = edge_self.inBounds(edge_x, edge_y, edge_z)
  assert(resNom == false, "inBounds nominal resNom == false")
  assert(resEdge == false, "inBounds boundary resEdge == false")
  ret 0
```

---

### `get` (`std/collections/grid2d_array.aipl`)

- **Signature**: `pub fn (self: FlatArray3D[T]) get(x: int, y: int, z: int): Option[T]:`
- **Import**: `import * from "std/collections/grid2d_array"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: FlatArray3D[T]` | **Parameters**: `x: int, y: int, z: int` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/grid2d_array_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `get` (`self: FlatArray3D[T]`) 2D/3D flat grid row-major indexing, corner/edge/interior 4-way and 8-way neighbor counts, and out-of-bounds safety. Concrete nominal inputs: receiver `recvObj: FlatArray3D[T] = FlatArray3D(width = 128, height = 128, depth = 1, data = [42])`, `x: int = 1`, `y: int = 1`, `z: int = 1`; exercises core body path returning/computing `Some(self.data[idx])`.

```aipl
module tests.functions.collections.grid2d_array_z11_test
import * from "std/collections/grid2d_array"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_grid2d_array_FlatArray3D_T__get_11(): int:
  let recv_self = FlatArray3D(width = 4, height = 4, depth = 0, data = [])
  let edge_self = FlatArray3D(width = 4, height = 4, depth = 0, data = [])
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let arg_z = 1
  let edge_z = 0
  let resNom = recv_self.get(arg_x, arg_y, arg_z)
  let resEdge = edge_self.get(edge_x, edge_y, edge_z)
  assert(resNom.isSome() == false, "get nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "get boundary resEdge.isSome() == false")
  ret 0
```

---

### `set` (`std/collections/grid2d_array.aipl`)

- **Signature**: `pub fn (mut self: FlatArray3D[T]) set(x: int, y: int, z: int, val: T): bool:`
- **Import**: `import * from "std/collections/grid2d_array"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: FlatArray3D[T]` | **Parameters**: `x: int, y: int, z: int, val: T` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/grid2d_array_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `set` (`mut self: FlatArray3D[T]`) 2D/3D flat grid row-major indexing, corner/edge/interior 4-way and 8-way neighbor counts, and out-of-bounds safety. Concrete nominal inputs: receiver `recvObj: FlatArray3D[T] = FlatArray3D(width = 128, height = 128, depth = 1, data = [42])`, `x: int = 1`, `y: int = 1`, `z: int = 1`, `val: T = 42`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.collections.grid2d_array_z12_test
import * from "std/collections/grid2d_array"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_grid2d_array_FlatArray3D_T__set_12(): int:
  let mut recv_self = FlatArray3D(width = 4, height = 4, depth = 0, data = [])
  let mut edge_self = FlatArray3D(width = 4, height = 4, depth = 0, data = [])
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let arg_z = 1
  let edge_z = 0
  let arg_val = 1
  let edge_val = 0
  let resNom = recv_self.set(arg_x, arg_y, arg_z, arg_val)
  let resEdge = edge_self.set(edge_x, edge_y, edge_z, edge_val)
  assert(resNom == false, "set nominal resNom == false")
  assert(resEdge == false, "set boundary resEdge == false")
  ret 0
```

---

### `hashMapNew` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn hashMapNew[K, V](): HashMap[K, V]:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `HashMap[K, V]`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `hashMapNew` (`free fn`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `HashMap(keys = k, values = v, ctrl = c, capacity = 16, count = 0)`.

```aipl
module tests.functions.collections.hash_map_z1_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_hashMapNew_1(): int:
  let resNom = hashMapNew()
  let resEdge = hashMapNew()
  assertEqInt(resNom.values.len(), 0, "hashMapNew nominal resNom.values.len() == 0")
  assertEqInt(resEdge.values.len(), 0, "hashMapNew boundary resEdge.values.len() == 0")
  ret 0
```

---

### `hashMapWithCapacity` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn hashMapWithCapacity[K, V](capacity: int): HashMap[K, V]:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `capacity: int` | **Returns**: `HashMap[K, V]`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `hashMapWithCapacity` (`free fn`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: `capacity: int = 64`; exercises core body path returning/computing `HashMap(keys = k, values = v, ctrl = c, capacity = cap, count = 0)`.

```aipl
module tests.functions.collections.hash_map_z2_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_hashMapWithCapacity_2(): int:
  let arg_capacity = 4
  let edge_capacity = 1
  let resNom = hashMapWithCapacity(arg_capacity)
  let resEdge = hashMapWithCapacity(edge_capacity)
  assertEqInt(resNom.values.len(), 0, "hashMapWithCapacity nominal resNom.values.len() == 0")
  assertEqInt(resEdge.values.len(), 0, "hashMapWithCapacity boundary resEdge.values.len() == 0")
  ret 0
```

---

### `insert` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn (mut self: HashMap[K, V]) insert(key: K, val: V): Option[V]:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: HashMap[K, V]` | **Parameters**: `key: K, val: V` | **Returns**: `Option[V]`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `insert` (`mut self: HashMap[K, V]`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: receiver `recvObj: HashMap[K, V] = HashMap(keys = [42], values = [42], ctrl = [1], capacity = 64, count = 64)`, `key: K = 42`, `val: V = 42`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.collections.hash_map_z3_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_HashMap_K__V__insert_3(): int:
  let mut recv_self = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0)
  let mut edge_self = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0)
  let arg_key = 1
  let edge_key = 0
  let arg_val = 1
  let edge_val = 0
  let resNom = recv_self.insert(arg_key, arg_val)
  let resEdge = edge_self.insert(edge_key, edge_val)
  assert(resNom.isSome() == false, "insert nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "insert boundary resEdge.isSome() == false")
  ret 0
```

---

### `get` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn (self: HashMap[K, V]) get(key: K): Option[V]:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: HashMap[K, V]` | **Parameters**: `key: K` | **Returns**: `Option[V]`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `get` (`self: HashMap[K, V]`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: receiver `recvObj: HashMap[K, V] = HashMap(keys = [42], values = [42], ctrl = [1], capacity = 64, count = 64)`, `key: K = 42`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.collections.hash_map_z4_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_HashMap_K__V__get_4(): int:
  let recv_self = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0)
  let edge_self = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0)
  let arg_key = 1
  let edge_key = 0
  let resNom = recv_self.get(arg_key)
  let resEdge = edge_self.get(edge_key)
  assert(resNom.isSome() == false, "get nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "get boundary resEdge.isSome() == false")
  ret 0
```

---

### `containsKey` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn (self: HashMap[K, V]) containsKey(key: K): bool:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: HashMap[K, V]` | **Parameters**: `key: K` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `containsKey` (`self: HashMap[K, V]`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: receiver `recvObj: HashMap[K, V] = HashMap(keys = [42], values = [42], ctrl = [1], capacity = 64, count = 64)`, `key: K = 42`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.collections.hash_map_z5_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_HashMap_K__V__containsKey_5(): int:
  let recv_self = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0)
  let edge_self = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0)
  let arg_key = 1
  let edge_key = 0
  let resNom = recv_self.containsKey(arg_key)
  let resEdge = edge_self.containsKey(edge_key)
  assert(resNom == false, "containsKey nominal resNom == false")
  assert(resEdge == false, "containsKey boundary resEdge == false")
  ret 0
```

---

### `remove` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn (mut self: HashMap[K, V]) remove(key: K): Option[V]:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: HashMap[K, V]` | **Parameters**: `key: K` | **Returns**: `Option[V]`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `remove` (`mut self: HashMap[K, V]`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: receiver `recvObj: HashMap[K, V] = HashMap(keys = [42], values = [42], ctrl = [1], capacity = 64, count = 64)`, `key: K = 42`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.collections.hash_map_z6_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_HashMap_K__V__remove_6(): int:
  let mut recv_self = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0)
  let mut edge_self = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0)
  let arg_key = 1
  let edge_key = 0
  let resNom = recv_self.remove(arg_key)
  let resEdge = edge_self.remove(edge_key)
  assert(resNom.isSome() == false, "remove nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "remove boundary resEdge.isSome() == false")
  ret 0
```

---

### `len` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn (self: HashMap[K, V]) len(): int:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: HashMap[K, V]` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `len` (`self: HashMap[K, V]`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: receiver `recvObj: HashMap[K, V] = HashMap(keys = [42], values = [42], ctrl = [1], capacity = 64, count = 64)`; exercises core body path returning/computing `self.count`.

```aipl
module tests.functions.collections.hash_map_z7_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_HashMap_K__V__len_7(): int:
  let recv_self = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0)
  let edge_self = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0)
  let resNom = recv_self.len()
  let resEdge = edge_self.len()
  assertEqInt(resNom, 0, "len nominal resNom == 0")
  assertEqInt(resEdge, 0, "len boundary resEdge == 0")
  ret 0
```

---

### `isEmpty` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn (self: HashMap[K, V]) isEmpty(): bool:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: HashMap[K, V]` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `isEmpty` (`self: HashMap[K, V]`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: receiver `recvObj: HashMap[K, V] = HashMap(keys = [42], values = [42], ctrl = [1], capacity = 64, count = 64)`; exercises core body path returning/computing `self.count == 0`.

```aipl
module tests.functions.collections.hash_map_z8_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_HashMap_K__V__isEmpty_8(): int:
  let recv_self = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0)
  let edge_self = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0)
  let resNom = recv_self.isEmpty()
  let resEdge = edge_self.isEmpty()
  assert(resNom == true, "isEmpty nominal resNom == true")
  assert(resEdge == true, "isEmpty boundary resEdge == true")
  ret 0
```

---

### `clear` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn (mut self: HashMap[K, V]) clear(): void:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: HashMap[K, V]` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `clear` (`mut self: HashMap[K, V]`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: receiver `recvObj: HashMap[K, V] = HashMap(keys = [42], values = [42], ctrl = [1], capacity = 64, count = 64)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.hash_map_z9_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_HashMap_K__V__clear_9(): int:
  let mut recv_self = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0)
  let mut edge_self = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0)
  recv_self.clear()
  edge_self.clear()
  assertEqInt(recv_self.keys.len(), 0, "clear nominal recv_self.keys.len() == 0")
  assertEqInt(edge_self.keys.len(), 0, "clear boundary edge_self.keys.len() == 0")
  ret 0
```

---

### `keys` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn (self: HashMap[K, V]) keys(): [K]:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: HashMap[K, V]` | **Parameters**: `none` | **Returns**: `[K]`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `keys` (`self: HashMap[K, V]`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: receiver `recvObj: HashMap[K, V] = HashMap(keys = [42], values = [42], ctrl = [1], capacity = 64, count = 64)`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.collections.hash_map_z10_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_HashMap_K__V__keys_10(): int:
  let recv_self = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0)
  let edge_self = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0)
  let resNom = recv_self.keys()
  let resEdge = edge_self.keys()
  assertEqInt(resNom.len(), 0, "keys nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "keys boundary resEdge.len() == 0")
  ret 0
```

---

### `values` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn (self: HashMap[K, V]) values(): [V]:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: HashMap[K, V]` | **Parameters**: `none` | **Returns**: `[V]`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `values` (`self: HashMap[K, V]`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: receiver `recvObj: HashMap[K, V] = HashMap(keys = [42], values = [42], ctrl = [1], capacity = 64, count = 64)`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.collections.hash_map_z11_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_HashMap_K__V__values_11(): int:
  let recv_self = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0)
  let edge_self = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0)
  let resNom = recv_self.values()
  let resEdge = edge_self.values()
  assertEqInt(resNom.len(), 0, "values nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "values boundary resEdge.len() == 0")
  ret 0
```

---

### `hashSetNew` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn hashSetNew[T](): HashSet[T]:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `HashSet[T]`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `hashSetNew` (`free fn`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `HashSet(map = m)`.

```aipl
module tests.functions.collections.hash_map_z12_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_hashSetNew_12(): int:
  let resNom = hashSetNew()
  let resEdge = hashSetNew()
  assertEqInt(resNom.map.values.len(), 0, "hashSetNew nominal resNom.map.values.len() == 0")
  assertEqInt(resEdge.map.values.len(), 0, "hashSetNew boundary resEdge.map.values.len() == 0")
  ret 0
```

---

### `add` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn (mut self: HashSet[T]) add(item: T): bool:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: HashSet[T]` | **Parameters**: `item: T` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `add` (`mut self: HashSet[T]`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: receiver `recvObj: HashSet[T] = HashSet(map = HashMap(keys = [0], values = [0], ctrl = [0], capacity = 64, count = 64))`, `item: T = 42`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.collections.hash_map_z13_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_HashSet_T__add_13(): int:
  let mut recv_self = HashSet(map = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0))
  let mut edge_self = HashSet(map = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0))
  let arg_item = 1
  let edge_item = 0
  let resNom = recv_self.add(arg_item)
  let resEdge = edge_self.add(edge_item)
  assert(resNom == true, "add nominal resNom == true")
  assert(resEdge == true, "add boundary resEdge == true")
  ret 0
```

---

### `contains` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn (self: HashSet[T]) contains(item: T): bool:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: HashSet[T]` | **Parameters**: `item: T` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `contains` (`self: HashSet[T]`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: receiver `recvObj: HashSet[T] = HashSet(map = HashMap(keys = [0], values = [0], ctrl = [0], capacity = 64, count = 64))`, `item: T = 42`; exercises core body path returning/computing `self.map.containsKey(item)`.

```aipl
module tests.functions.collections.hash_map_z14_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_HashSet_T__contains_14(): int:
  let recv_self = HashSet(map = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0))
  let edge_self = HashSet(map = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0))
  let arg_item = 1
  let edge_item = 0
  let resNom = recv_self.contains(arg_item)
  let resEdge = edge_self.contains(edge_item)
  assert(resNom == false, "contains nominal resNom == false")
  assert(resEdge == false, "contains boundary resEdge == false")
  ret 0
```

---

### `remove` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn (mut self: HashSet[T]) remove(item: T): bool:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: HashSet[T]` | **Parameters**: `item: T` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `remove` (`mut self: HashSet[T]`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: receiver `recvObj: HashSet[T] = HashSet(map = HashMap(keys = [0], values = [0], ctrl = [0], capacity = 64, count = 64))`, `item: T = 42`; exercises core body path returning/computing `res.isSome()`.

```aipl
module tests.functions.collections.hash_map_z15_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_HashSet_T__remove_15(): int:
  let mut recv_self = HashSet(map = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0))
  let mut edge_self = HashSet(map = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0))
  let arg_item = 1
  let edge_item = 0
  let resNom = recv_self.remove(arg_item)
  let resEdge = edge_self.remove(edge_item)
  assert(resNom == false, "remove nominal resNom == false")
  assert(resEdge == false, "remove boundary resEdge == false")
  ret 0
```

---

### `len` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn (self: HashSet[T]) len(): int:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: HashSet[T]` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `len` (`self: HashSet[T]`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: receiver `recvObj: HashSet[T] = HashSet(map = HashMap(keys = [0], values = [0], ctrl = [0], capacity = 64, count = 64))`; exercises core body path returning/computing `self.map.len()`.

```aipl
module tests.functions.collections.hash_map_z16_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_HashSet_T__len_16(): int:
  let recv_self = HashSet(map = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0))
  let edge_self = HashSet(map = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0))
  let resNom = recv_self.len()
  let resEdge = edge_self.len()
  assertEqInt(resNom, 0, "len nominal resNom == 0")
  assertEqInt(resEdge, 0, "len boundary resEdge == 0")
  ret 0
```

---

### `isEmpty` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn (self: HashSet[T]) isEmpty(): bool:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: HashSet[T]` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `isEmpty` (`self: HashSet[T]`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: receiver `recvObj: HashSet[T] = HashSet(map = HashMap(keys = [0], values = [0], ctrl = [0], capacity = 64, count = 64))`; exercises core body path returning/computing `self.map.isEmpty()`.

```aipl
module tests.functions.collections.hash_map_z17_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_HashSet_T__isEmpty_17(): int:
  let recv_self = HashSet(map = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0))
  let edge_self = HashSet(map = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0))
  let resNom = recv_self.isEmpty()
  let resEdge = edge_self.isEmpty()
  assert(resNom == true, "isEmpty nominal resNom == true")
  assert(resEdge == true, "isEmpty boundary resEdge == true")
  ret 0
```

---

### `toArray` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn (self: HashSet[T]) toArray(): [T]:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: HashSet[T]` | **Parameters**: `none` | **Returns**: `[T]`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `toArray` (`self: HashSet[T]`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: receiver `recvObj: HashSet[T] = HashSet(map = HashMap(keys = [0], values = [0], ctrl = [0], capacity = 64, count = 64))`; exercises core body path returning/computing `self.map.keys()`.

```aipl
module tests.functions.collections.hash_map_z18_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_HashSet_T__toArray_18(): int:
  let recv_self = HashSet(map = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0))
  let edge_self = HashSet(map = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0))
  let resNom = recv_self.toArray()
  let resEdge = edge_self.toArray()
  assertEqInt(resNom.len(), 0, "toArray nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "toArray boundary resEdge.len() == 0")
  ret 0
```

---

### `lruCacheNew` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn lruCacheNew[K, V](maxEntries: int): LruCache[K, V]:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `maxEntries: int` | **Returns**: `LruCache[K, V]`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `lruCacheNew` (`free fn`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: `maxEntries: int = 1`; exercises core body path returning/computing `LruCache(map = m, order = ord, maxEntries = cap)`.

```aipl
module tests.functions.collections.hash_map_z19_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_lruCacheNew_19(): int:
  let arg_maxEntries = 4
  let edge_maxEntries = 1
  let resNom = lruCacheNew(arg_maxEntries)
  let resEdge = lruCacheNew(edge_maxEntries)
  assertEqInt(resNom.order.len(), 0, "lruCacheNew nominal resNom.order.len() == 0")
  assertEqInt(resEdge.order.len(), 0, "lruCacheNew boundary resEdge.order.len() == 0")
  ret 0
```

---

### `put` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn (mut self: LruCache[K, V]) put(key: K, val: V): void:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: LruCache[K, V]` | **Parameters**: `key: K, val: V` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `put` (`mut self: LruCache[K, V]`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: receiver `recvObj: LruCache[K, V] = LruCache(map = HashMap(keys = [0], values = [0], ctrl = [0], capacity = 64, count = 64), order = [42], maxEntries = 1)`, `key: K = 42`, `val: V = 42`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.hash_map_z20_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_LruCache_K__V__put_20(): int:
  let mut recv_self = LruCache(map = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0), order = [], maxEntries = 4)
  let mut edge_self = LruCache(map = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0), order = [], maxEntries = 1)
  let arg_key = 1
  let edge_key = 0
  let arg_val = 1
  let edge_val = 0
  recv_self.put(arg_key, arg_val)
  edge_self.put(edge_key, edge_val)
  assertEqInt(recv_self.order.len(), 1, "put nominal recv_self.order.len() == 1")
  assertEqInt(edge_self.order.len(), 1, "put boundary edge_self.order.len() == 1")
  ret 0
```

---

### `get` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn (mut self: LruCache[K, V]) get(key: K): Option[V]:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: LruCache[K, V]` | **Parameters**: `key: K` | **Returns**: `Option[V]`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `get` (`mut self: LruCache[K, V]`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: receiver `recvObj: LruCache[K, V] = LruCache(map = HashMap(keys = [0], values = [0], ctrl = [0], capacity = 64, count = 64), order = [42], maxEntries = 1)`, `key: K = 42`; exercises core body path returning/computing `res`.

```aipl
module tests.functions.collections.hash_map_z21_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_LruCache_K__V__get_21(): int:
  let mut recv_self = LruCache(map = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0), order = [], maxEntries = 4)
  let mut edge_self = LruCache(map = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0), order = [], maxEntries = 1)
  let arg_key = 1
  let edge_key = 0
  let resNom = recv_self.get(arg_key)
  let resEdge = edge_self.get(edge_key)
  assert(resNom.isSome() == false, "get nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "get boundary resEdge.isSome() == false")
  ret 0
```

---

### `len` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn (self: LruCache[K, V]) len(): int:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: LruCache[K, V]` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `len` (`self: LruCache[K, V]`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: receiver `recvObj: LruCache[K, V] = LruCache(map = HashMap(keys = [0], values = [0], ctrl = [0], capacity = 64, count = 64), order = [42], maxEntries = 1)`; exercises core body path returning/computing `self.map.len()`.

```aipl
module tests.functions.collections.hash_map_z22_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_LruCache_K__V__len_22(): int:
  let recv_self = LruCache(map = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0), order = [], maxEntries = 4)
  let edge_self = LruCache(map = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0), order = [], maxEntries = 1)
  let resNom = recv_self.len()
  let resEdge = edge_self.len()
  assertEqInt(resNom, 0, "len nominal resNom == 0")
  assertEqInt(resEdge, 0, "len boundary resEdge == 0")
  ret 0
```

---

### `mapNew` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn mapNew(): any:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `any`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `mapNew` (`free fn`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Map()`.

```aipl
module tests.functions.collections.hash_map_z23_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_mapNew_23(): int:
  let resNom = mapNew()
  let resEdge = mapNew()
  assertEqInt(mapKeys(resNom).len(), 0, "mapNew nominal mapKeys(resNom).len() == 0")
  assertEqInt(mapKeys(resEdge).len(), 0, "mapNew boundary mapKeys(resEdge).len() == 0")
  ret 0
```

---

### `setNew` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn setNew(): any:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `any`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `setNew` (`free fn`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Set()`.

```aipl
module tests.functions.collections.hash_map_z24_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_setNew_24(): int:
  let resNom = setNew()
  let resEdge = setNew()
  assertEqInt(setToArray(resNom).len(), 0, "setNew nominal setToArray(resNom).len() == 0")
  assertEqInt(setToArray(resEdge).len(), 0, "setNew boundary setToArray(resEdge).len() == 0")
  ret 0
```

---

### `mapGet` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn mapGet(m: any, key: any): Option[any]:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: any, key: any` | **Returns**: `Option[any]`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `mapGet` (`free fn`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: `m: any = 42`, `key: any = 42`; exercises core body path returning/computing `m.get(key)`.

```aipl
module tests.functions.collections.hash_map_z25_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_mapGet_25(): int:
  let arg_m = mapNew()
  let edge_m = mapNew()
  let arg_key = "k"
  let edge_key = ""
  let resNom = mapGet(arg_m, arg_key)
  let resEdge = mapGet(edge_m, edge_key)
  assert(resNom.isSome() == false, "mapGet nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "mapGet boundary resEdge.isSome() == false")
  ret 0
```

---

### `mapSet` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn mapSet(mut m: any, key: any, val: any): any:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut m: any, key: any, val: any` | **Returns**: `any`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `mapSet` (`free fn`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: `m: any = 42`, `key: any = 42`, `val: any = 42`; exercises core body path returning/computing `m`.

```aipl
module tests.functions.collections.hash_map_z26_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_mapSet_26(): int:
  let arg_m = mapNew()
  let edge_m = mapNew()
  let arg_key = "k"
  let edge_key = ""
  let arg_val = 42
  let edge_val = 0
  let resNom = mapSet(arg_m, arg_key, arg_val)
  let resEdge = mapSet(edge_m, edge_key, edge_val)
  assertEqInt(mapKeys(resNom).len(), 1, "mapSet nominal mapKeys(resNom).len() == 1")
  assertEqInt(mapKeys(resEdge).len(), 1, "mapSet boundary mapKeys(resEdge).len() == 1")
  ret 0
```

---

### `mapGetOr` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn mapGetOr(m: any, key: any, defaultVal: any): any:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: any, key: any, defaultVal: any` | **Returns**: `any`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `mapGetOr` (`free fn`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: `m: any = 42`, `key: any = 42`, `defaultVal: any = 42`; exercises core body path returning/computing `defaultVal`.

```aipl
module tests.functions.collections.hash_map_z27_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_mapGetOr_27(): int:
  let arg_m = mapNew()
  let edge_m = mapNew()
  let arg_key = "k"
  let edge_key = ""
  let arg_defaultVal = 42
  let edge_defaultVal = 0
  let resNom = mapGetOr(arg_m, arg_key, arg_defaultVal)
  let resEdge = mapGetOr(edge_m, edge_key, edge_defaultVal)
  assertEqInt(int(resNom), 42, "mapGetOr nominal int(resNom) == 42")
  assertEqInt(int(resEdge), 0, "mapGetOr boundary int(resEdge) == 0")
  ret 0
```

---

### `mapGetOrDefault` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn mapGetOrDefault(m: any, key: any, defaultVal: any): any:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: any, key: any, defaultVal: any` | **Returns**: `any`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `mapGetOrDefault` (`free fn`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: `m: any = 42`, `key: any = 42`, `defaultVal: any = 42`; exercises core body path returning/computing `mapGetOr(m, key, defaultVal)`.

```aipl
module tests.functions.collections.hash_map_z28_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_mapGetOrDefault_28(): int:
  let arg_m = mapNew()
  let edge_m = mapNew()
  let arg_key = "k"
  let edge_key = ""
  let arg_defaultVal = 42
  let edge_defaultVal = 0
  let resNom = mapGetOrDefault(arg_m, arg_key, arg_defaultVal)
  let resEdge = mapGetOrDefault(edge_m, edge_key, edge_defaultVal)
  assertEqInt(int(resNom), 42, "mapGetOrDefault nominal int(resNom) == 42")
  assertEqInt(int(resEdge), 0, "mapGetOrDefault boundary int(resEdge) == 0")
  ret 0
```

---

### `mapGetOrInsert` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn mapGetOrInsert(mut m: any, key: any, defaultVal: any): any:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut m: any, key: any, defaultVal: any` | **Returns**: `any`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `mapGetOrInsert` (`free fn`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: `m: any = 42`, `key: any = 42`, `defaultVal: any = 42`; exercises core body path returning/computing `defaultVal`.

```aipl
module tests.functions.collections.hash_map_z29_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_mapGetOrInsert_29(): int:
  let arg_m = mapNew()
  let edge_m = mapNew()
  let arg_key = "k"
  let edge_key = ""
  let arg_defaultVal = 42
  let edge_defaultVal = 0
  let resNom = mapGetOrInsert(arg_m, arg_key, arg_defaultVal)
  let resEdge = mapGetOrInsert(edge_m, edge_key, edge_defaultVal)
  assertEqInt(int(resNom), 42, "mapGetOrInsert nominal int(resNom) == 42")
  assertEqInt(int(resEdge), 0, "mapGetOrInsert boundary int(resEdge) == 0")
  ret 0
```

---

### `mapContainsKey` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn mapContainsKey(m: any, key: any): bool:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: any, key: any` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `mapContainsKey` (`free fn`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: `m: any = 42`, `key: any = 42`; exercises core body path returning/computing `m.containsKey(key)`.

```aipl
module tests.functions.collections.hash_map_z30_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_mapContainsKey_30(): int:
  let arg_m = mapNew()
  let edge_m = mapNew()
  let arg_key = "k"
  let edge_key = ""
  let resNom = mapContainsKey(arg_m, arg_key)
  let resEdge = mapContainsKey(edge_m, edge_key)
  assert(resNom == false, "mapContainsKey nominal resNom == false")
  assert(resEdge == false, "mapContainsKey boundary resEdge == false")
  ret 0
```

---

### `mapKeys` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn mapKeys(m: any): [str]:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: any` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `mapKeys` (`free fn`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: `m: any = 42`; exercises core body path returning/computing `m.keys()`.

```aipl
module tests.functions.collections.hash_map_z31_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_mapKeys_31(): int:
  let arg_m = mapNew()
  let edge_m = mapNew()
  let resNom = mapKeys(arg_m)
  let resEdge = mapKeys(edge_m)
  assertEqInt(resNom.len(), 0, "mapKeys nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "mapKeys boundary resEdge.len() == 0")
  ret 0
```

---

### `mapValues` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn mapValues(m: any): [any]:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: any` | **Returns**: `[any]`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `mapValues` (`free fn`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: `m: any = 42`; exercises core body path returning/computing `m.values()`.

```aipl
module tests.functions.collections.hash_map_z32_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_mapValues_32(): int:
  let arg_m = mapNew()
  let edge_m = mapNew()
  let resNom = mapValues(arg_m)
  let resEdge = mapValues(edge_m)
  assertEqInt(resNom.len(), 0, "mapValues nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "mapValues boundary resEdge.len() == 0")
  ret 0
```

---

### `mapRemove` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn mapRemove(mut m: any, key: any): bool:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut m: any, key: any` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `mapRemove` (`free fn`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: `m: any = 42`, `key: any = 42`; exercises core body path returning/computing `m.remove(key)`.

```aipl
module tests.functions.collections.hash_map_z33_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_mapRemove_33(): int:
  let mut arg_m = {}
  let mut edge_m = {}
  let arg_key = "k"
  let edge_key = ""
  let resNom = mapRemove(arg_m, arg_key)
  let resEdge = mapRemove(edge_m, edge_key)
  assert(resNom == false, "mapRemove nominal resNom == false")
  assert(resEdge == false, "mapRemove boundary resEdge == false")
  ret 0
```

---

### `setInsert` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn setInsert(mut s: any, val: any): any:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut s: any, val: any` | **Returns**: `any`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `setInsert` (`free fn`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: `s: any = 42`, `val: any = 42`; exercises core body path returning/computing `s`.

```aipl
module tests.functions.collections.hash_map_z34_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_setInsert_34(): int:
  let arg_s = setNew()
  let edge_s = setNew()
  let arg_val = 42
  let edge_val = 0
  let resNom = setInsert(arg_s, arg_val)
  let resEdge = setInsert(edge_s, edge_val)
  assertEqInt(setToArray(resNom).len(), 1, "setInsert nominal setToArray(resNom).len() == 1")
  assertEqInt(setToArray(resEdge).len(), 1, "setInsert boundary setToArray(resEdge).len() == 1")
  ret 0
```

---

### `setContains` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn setContains(s: any, val: any): bool:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: any, val: any` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `setContains` (`free fn`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: `s: any = 42`, `val: any = 42`; exercises core body path returning/computing `s.contains(val)`.

```aipl
module tests.functions.collections.hash_map_z35_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_setContains_35(): int:
  let arg_s = setNew()
  let edge_s = setNew()
  let arg_val = 42
  let edge_val = 0
  let resNom = setContains(arg_s, arg_val)
  let resEdge = setContains(edge_s, edge_val)
  assert(resNom == false, "setContains nominal resNom == false")
  assert(resEdge == false, "setContains boundary resEdge == false")
  ret 0
```

---

### `setRemove` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn setRemove(mut s: any, val: any): bool:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut s: any, val: any` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `setRemove` (`free fn`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: `s: any = 42`, `val: any = 42`; exercises core body path returning/computing `s.remove(val)`.

```aipl
module tests.functions.collections.hash_map_z36_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_setRemove_36(): int:
  let mut arg_s = {}
  let mut edge_s = {}
  let arg_val = 42
  let edge_val = 0
  let resNom = setRemove(arg_s, arg_val)
  let resEdge = setRemove(edge_s, edge_val)
  assert(resNom == false, "setRemove nominal resNom == false")
  assert(resEdge == false, "setRemove boundary resEdge == false")
  ret 0
```

---

### `setToArray` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn setToArray(s: any): [str]:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: any` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `setToArray` (`free fn`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: `s: any = 42`; exercises core body path returning/computing `s.keys()`.

```aipl
module tests.functions.collections.hash_map_z37_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_setToArray_37(): int:
  let arg_s = setNew()
  let edge_s = setNew()
  let resNom = setToArray(arg_s)
  let resEdge = setToArray(edge_s)
  assertEqInt(resNom.len(), 0, "setToArray nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "setToArray boundary resEdge.len() == 0")
  ret 0
```

---

### `setFromArray` (`std/collections/hash_map.aipl`)

- **Signature**: `pub fn setFromArray(arr: [any]): any:`
- **Import**: `import * from "std/collections/hash_map"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `arr: [any]` | **Returns**: `any`
- **Unit Test**: `tests/functions/collections/hash_map_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `setFromArray` (`free fn`) hash table / set / LRU cache invariant across key overwrites, resize rehashes, tombstone deletions, and least-recently-used eviction order. Concrete nominal inputs: `arr: [any] = [42]`; exercises core body path returning/computing `s`.

```aipl
module tests.functions.collections.hash_map_z38_test
import * from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_map_setFromArray_38(): int:
  let arg_arr = [1]
  let edge_arr = []
  let resNom = setFromArray(arg_arr)
  let resEdge = setFromArray(edge_arr)
  assertEqInt(setToArray(resNom).len(), 1, "setFromArray nominal setToArray(resNom).len() == 1")
  assertEqInt(setToArray(resEdge).len(), 0, "setFromArray boundary setToArray(resEdge).len() == 0")
  ret 0
```

---

### `octreeNew` (`std/collections/octree.aipl`)

- **Signature**: `pub fn octreeNew[T](minX: float, minY: float, minZ: float, maxX: float, maxY: float, maxZ: float, capacity: int): OctreeNode[T]:`
- **Import**: `import * from "std/collections/octree"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `minX: float, minY: float, minZ: float, maxX: float, maxY: float, maxZ: float, capacity: int` | **Returns**: `OctreeNode[T]`
- **Unit Test**: `tests/functions/collections/octree_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `octreeNew` (`free fn`) 3D Octree 8-octant subdivision and exact `queryBox` 3D AABB point retrieval. Concrete nominal inputs: `minX: float = 1.0`, `minY: float = 1.0`, `minZ: float = 1.0`, `maxX: float = 1.0`, `maxY: float = 1.0`, `maxZ: float = 1.0`, `capacity: int = 64`; exercises core body path returning/computing `OctreeNode(`.

```aipl
module tests.functions.collections.octree_z1_test
import * from "std/collections/octree"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_octree_octreeNew_1(): int:
  let arg_minX = 0.0
  let edge_minX = 0.0
  let arg_minY = 0.0
  let edge_minY = 0.0
  let arg_minZ = 0.0
  let edge_minZ = 0.0
  let arg_maxX = 2.0
  let edge_maxX = 1.0
  let arg_maxY = 2.0
  let edge_maxY = 1.0
  let arg_maxZ = 2.0
  let edge_maxZ = 1.0
  let arg_capacity = 4
  let edge_capacity = 1
  let resNom = octreeNew(arg_minX, arg_minY, arg_minZ, arg_maxX, arg_maxY, arg_maxZ, arg_capacity)
  let resEdge = octreeNew(edge_minX, edge_minY, edge_minZ, edge_maxX, edge_maxY, edge_maxZ, edge_capacity)
  assertApproxEq(resNom.minX, 0.0, 0.001, "octreeNew nominal resNom.minX ~= 0.0")
  assertApproxEq(resEdge.minX, 0.0, 0.001, "octreeNew boundary resEdge.minX ~= 0.0")
  ret 0
```

---

### `containsPoint` (`std/collections/octree.aipl`)

- **Signature**: `pub fn (self: OctreeNode[T]) containsPoint(px: float, py: float, pz: float): bool:`
- **Import**: `import * from "std/collections/octree"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: OctreeNode[T]` | **Parameters**: `px: float, py: float, pz: float` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/octree_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `containsPoint` (`self: OctreeNode[T]`) 3D Octree 8-octant subdivision and exact `queryBox` 3D AABB point retrieval. Concrete nominal inputs: receiver `recvObj: OctreeNode[T] = OctreeNode(minX = 1.0, minY = 1.0, minZ = 1.0, maxX = 1.0, maxY = 1.0, maxZ = 1.0, capacity = 64, items = [OctreeItem(x = 0, y = 0, z = 0, payload = 0)], divided = true, children = [Some(0)])`, `px: float = 1.0`, `py: float = 1.0`, `pz: float = 1.0`; exercises core body path returning/computing `px >= self.minX and px <= self.maxX and py >= self.minY and py <= self.maxY and pz >= self.minZ and pz <= self.maxZ`.

```aipl
module tests.functions.collections.octree_z2_test
import * from "std/collections/octree"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_octree_OctreeNode_T__containsPoint_2(): int:
  let recv_self = OctreeNode(minX = 0.0, minY = 0.0, minZ = 0.0, maxX = 2.0, maxY = 2.0, maxZ = 2.0, capacity = 4, items = [], divided = true, children = [])
  let edge_self = OctreeNode(minX = 0.0, minY = 0.0, minZ = 0.0, maxX = 1.0, maxY = 1.0, maxZ = 1.0, capacity = 4, items = [], divided = false, children = [])
  let arg_px = 1.0
  let edge_px = 0.5
  let arg_py = 1.0
  let edge_py = 0.5
  let arg_pz = 1.0
  let edge_pz = 0.5
  let resNom = recv_self.containsPoint(arg_px, arg_py, arg_pz)
  let resEdge = edge_self.containsPoint(edge_px, edge_py, edge_pz)
  assert(resNom == true, "containsPoint nominal resNom == true")
  assert(resEdge == true, "containsPoint boundary resEdge == true")
  ret 0
```

---

### `intersectsBox` (`std/collections/octree.aipl`)

- **Signature**: `pub fn (self: OctreeNode[T]) intersectsBox(qMinX: float, qMinY: float, qMinZ: float, qMaxX: float, qMaxY: float, qMaxZ: float): bool:`
- **Import**: `import * from "std/collections/octree"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: OctreeNode[T]` | **Parameters**: `qMinX: float, qMinY: float, qMinZ: float, qMaxX: float, qMaxY: float, qMaxZ: float` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/octree_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `intersectsBox` (`self: OctreeNode[T]`) 3D Octree 8-octant subdivision and exact `queryBox` 3D AABB point retrieval. Concrete nominal inputs: receiver `recvObj: OctreeNode[T] = OctreeNode(minX = 1.0, minY = 1.0, minZ = 1.0, maxX = 1.0, maxY = 1.0, maxZ = 1.0, capacity = 64, items = [OctreeItem(x = 0, y = 0, z = 0, payload = 0)], divided = true, children = [Some(0)])`, `qMinX: float = 1.0`, `qMinY: float = 1.0`, `qMinZ: float = 1.0`, `qMaxX: float = 1.0`, `qMaxY: float = 1.0`, `qMaxZ: float = 1.0`; exercises core body path returning/computing `not (qMinX > self.maxX or qMaxX < self.minX or qMinY > self.maxY or qMaxY < self.minY or qMinZ > self.maxZ or qMaxZ < self.minZ)`.

```aipl
module tests.functions.collections.octree_z3_test
import * from "std/collections/octree"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_octree_OctreeNode_T__intersectsBox_3(): int:
  let recv_self = OctreeNode(minX = 0.0, minY = 0.0, minZ = 0.0, maxX = 2.0, maxY = 2.0, maxZ = 2.0, capacity = 4, items = [], divided = true, children = [])
  let edge_self = OctreeNode(minX = 0.0, minY = 0.0, minZ = 0.0, maxX = 1.0, maxY = 1.0, maxZ = 1.0, capacity = 4, items = [], divided = false, children = [])
  let arg_qMinX = 0.0
  let edge_qMinX = 0.0
  let arg_qMinY = 0.0
  let edge_qMinY = 0.0
  let arg_qMinZ = 0.0
  let edge_qMinZ = 0.0
  let arg_qMaxX = 2.0
  let edge_qMaxX = 1.0
  let arg_qMaxY = 2.0
  let edge_qMaxY = 1.0
  let arg_qMaxZ = 2.0
  let edge_qMaxZ = 1.0
  let resNom = recv_self.intersectsBox(arg_qMinX, arg_qMinY, arg_qMinZ, arg_qMaxX, arg_qMaxY, arg_qMaxZ)
  let resEdge = edge_self.intersectsBox(edge_qMinX, edge_qMinY, edge_qMinZ, edge_qMaxX, edge_qMaxY, edge_qMaxZ)
  assert(resNom == true, "intersectsBox nominal resNom == true")
  assert(resEdge == true, "intersectsBox boundary resEdge == true")
  ret 0
```

---

### `insert` (`std/collections/octree.aipl`)

- **Signature**: `pub fn (mut self: OctreeNode[T]) insert(item: OctreeItem[T]): bool:`
- **Import**: `import * from "std/collections/octree"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: OctreeNode[T]` | **Parameters**: `item: OctreeItem[T]` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/octree_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `insert` (`mut self: OctreeNode[T]`) 3D Octree 8-octant subdivision and exact `queryBox` 3D AABB point retrieval. Concrete nominal inputs: receiver `recvObj: OctreeNode[T] = OctreeNode(minX = 1.0, minY = 1.0, minZ = 1.0, maxX = 1.0, maxY = 1.0, maxZ = 1.0, capacity = 64, items = [OctreeItem(x = 0, y = 0, z = 0, payload = 0)], divided = true, children = [Some(0)])`, `item: OctreeItem[T] = OctreeItem(x = 1.0, y = 1.0, z = 1.0, payload = 42)`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.collections.octree_z4_test
import * from "std/collections/octree"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_octree_OctreeNode_T__insert_4(): int:
  let mut recv_self = OctreeNode(minX = 0.0, minY = 0.0, minZ = 0.0, maxX = 2.0, maxY = 2.0, maxZ = 2.0, capacity = 4, items = [], divided = true, children = [])
  let mut edge_self = OctreeNode(minX = 0.0, minY = 0.0, minZ = 0.0, maxX = 1.0, maxY = 1.0, maxZ = 1.0, capacity = 4, items = [], divided = false, children = [])
  let arg_item = OctreeItem(x = 1.0, y = 1.0, z = 1.0, payload = 1)
  let edge_item = OctreeItem(x = 0.5, y = 0.5, z = 0.5, payload = 0)
  let resNom = recv_self.insert(arg_item)
  let resEdge = edge_self.insert(edge_item)
  assert(resNom == true, "insert nominal resNom == true")
  assert(resEdge == true, "insert boundary resEdge == true")
  ret 0
```

---

### `queryBox` (`std/collections/octree.aipl`)

- **Signature**: `pub fn (self: OctreeNode[T]) queryBox(qMinX: float, qMinY: float, qMinZ: float, qMaxX: float, qMaxY: float, qMaxZ: float): [T]:`
- **Import**: `import * from "std/collections/octree"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: OctreeNode[T]` | **Parameters**: `qMinX: float, qMinY: float, qMinZ: float, qMaxX: float, qMaxY: float, qMaxZ: float` | **Returns**: `[T]`
- **Unit Test**: `tests/functions/collections/octree_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `queryBox` (`self: OctreeNode[T]`) 3D Octree 8-octant subdivision and exact `queryBox` 3D AABB point retrieval. Concrete nominal inputs: receiver `recvObj: OctreeNode[T] = OctreeNode(minX = 1.0, minY = 1.0, minZ = 1.0, maxX = 1.0, maxY = 1.0, maxZ = 1.0, capacity = 64, items = [OctreeItem(x = 0, y = 0, z = 0, payload = 0)], divided = true, children = [Some(0)])`, `qMinX: float = 1.0`, `qMinY: float = 1.0`, `qMinZ: float = 1.0`, `qMaxX: float = 1.0`, `qMaxY: float = 1.0`, `qMaxZ: float = 1.0`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.collections.octree_z5_test
import * from "std/collections/octree"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_octree_OctreeNode_T__queryBox_5(): int:
  let recv_self = OctreeNode(minX = 0.0, minY = 0.0, minZ = 0.0, maxX = 2.0, maxY = 2.0, maxZ = 2.0, capacity = 4, items = [], divided = true, children = [])
  let edge_self = OctreeNode(minX = 0.0, minY = 0.0, minZ = 0.0, maxX = 1.0, maxY = 1.0, maxZ = 1.0, capacity = 4, items = [], divided = false, children = [])
  let arg_qMinX = 0.0
  let edge_qMinX = 0.0
  let arg_qMinY = 0.0
  let edge_qMinY = 0.0
  let arg_qMinZ = 0.0
  let edge_qMinZ = 0.0
  let arg_qMaxX = 2.0
  let edge_qMaxX = 1.0
  let arg_qMaxY = 2.0
  let edge_qMaxY = 1.0
  let arg_qMaxZ = 2.0
  let edge_qMaxZ = 1.0
  let resNom = recv_self.queryBox(arg_qMinX, arg_qMinY, arg_qMinZ, arg_qMaxX, arg_qMaxY, arg_qMaxZ)
  let resEdge = edge_self.queryBox(edge_qMinX, edge_qMinY, edge_qMinZ, edge_qMaxX, edge_qMaxY, edge_qMaxZ)
  assertEqInt(resNom.len(), 0, "queryBox nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "queryBox boundary resEdge.len() == 0")
  ret 0
```

---

### `count` (`std/collections/octree.aipl`)

- **Signature**: `pub fn (self: OctreeNode[T]) count(): int:`
- **Import**: `import * from "std/collections/octree"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: OctreeNode[T]` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/octree_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `count` (`self: OctreeNode[T]`) 3D Octree 8-octant subdivision and exact `queryBox` 3D AABB point retrieval. Concrete nominal inputs: receiver `recvObj: OctreeNode[T] = OctreeNode(minX = 1.0, minY = 1.0, minZ = 1.0, maxX = 1.0, maxY = 1.0, maxZ = 1.0, capacity = 64, items = [OctreeItem(x = 0, y = 0, z = 0, payload = 0)], divided = true, children = [Some(0)])`; exercises core body path returning/computing `total`.

```aipl
module tests.functions.collections.octree_z6_test
import * from "std/collections/octree"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_octree_OctreeNode_T__count_6(): int:
  let recv_self = OctreeNode(minX = 0.0, minY = 0.0, minZ = 0.0, maxX = 2.0, maxY = 2.0, maxZ = 2.0, capacity = 4, items = [], divided = true, children = [])
  let edge_self = OctreeNode(minX = 0.0, minY = 0.0, minZ = 0.0, maxX = 1.0, maxY = 1.0, maxZ = 1.0, capacity = 4, items = [], divided = false, children = [])
  let resNom = recv_self.count()
  let resEdge = edge_self.count()
  assertEqInt(resNom, 0, "count nominal resNom == 0")
  assertEqInt(resEdge, 0, "count boundary resEdge == 0")
  ret 0
```

---

### `minHeapNew` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn minHeapNew[T](): BinaryMinHeap[T]:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `BinaryMinHeap[T]`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `minHeapNew` (`free fn`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `BinaryMinHeap(items = it, priorities = pr)`.

```aipl
module tests.functions.collections.priority_queue_z1_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_minHeapNew_1(): int:
  let resNom = minHeapNew()
  let resEdge = minHeapNew()
  assertEqInt(resNom.items.len(), 0, "minHeapNew nominal resNom.items.len() == 0")
  assertEqInt(resEdge.items.len(), 0, "minHeapNew boundary resEdge.items.len() == 0")
  ret 0
```

---

### `push` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn (mut self: BinaryMinHeap[T]) push(item: T, priority: int): void:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: BinaryMinHeap[T]` | **Parameters**: `item: T, priority: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `push` (`mut self: BinaryMinHeap[T]`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: receiver `recvObj: BinaryMinHeap[T] = BinaryMinHeap(items = [42], priorities = [1])`, `item: T = 42`, `priority: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.priority_queue_z2_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_BinaryMinHeap_T__push_2(): int:
  let mut recv_self = BinaryMinHeap(items = [], priorities = [])
  let mut edge_self = BinaryMinHeap(items = [], priorities = [])
  let arg_item = 1
  let edge_item = 0
  let arg_priority = 1
  let edge_priority = 0
  recv_self.push(arg_item, arg_priority)
  edge_self.push(edge_item, edge_priority)
  assertEqInt(recv_self.items.len(), 1, "push nominal recv_self.items.len() == 1")
  assertEqInt(edge_self.items.len(), 1, "push boundary edge_self.items.len() == 1")
  ret 0
```

---

### `pop` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn (mut self: BinaryMinHeap[T]) pop(): Option[T]:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: BinaryMinHeap[T]` | **Parameters**: `none` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `pop` (`mut self: BinaryMinHeap[T]`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: receiver `recvObj: BinaryMinHeap[T] = BinaryMinHeap(items = [42], priorities = [1])`; exercises core body path returning/computing `Some(topItem)`.

```aipl
module tests.functions.collections.priority_queue_z3_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_BinaryMinHeap_T__pop_3(): int:
  let mut recv_self = BinaryMinHeap(items = [], priorities = [])
  let mut edge_self = BinaryMinHeap(items = [], priorities = [])
  let resNom = recv_self.pop()
  let resEdge = edge_self.pop()
  assert(resNom.isSome() == false, "pop nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "pop boundary resEdge.isSome() == false")
  ret 0
```

---

### `peek` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn (self: BinaryMinHeap[T]) peek(): Option[T]:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: BinaryMinHeap[T]` | **Parameters**: `none` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `peek` (`self: BinaryMinHeap[T]`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: receiver `recvObj: BinaryMinHeap[T] = BinaryMinHeap(items = [42], priorities = [1])`; exercises core body path returning/computing `Some(self.items[0])`.

```aipl
module tests.functions.collections.priority_queue_z4_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_BinaryMinHeap_T__peek_4(): int:
  let recv_self = BinaryMinHeap(items = [], priorities = [])
  let edge_self = BinaryMinHeap(items = [], priorities = [])
  let resNom = recv_self.peek()
  let resEdge = edge_self.peek()
  assert(resNom.isSome() == false, "peek nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "peek boundary resEdge.isSome() == false")
  ret 0
```

---

### `peekPriority` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn (self: BinaryMinHeap[T]) peekPriority(): Option[int]:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: BinaryMinHeap[T]` | **Parameters**: `none` | **Returns**: `Option[int]`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `peekPriority` (`self: BinaryMinHeap[T]`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: receiver `recvObj: BinaryMinHeap[T] = BinaryMinHeap(items = [42], priorities = [1])`; exercises core body path returning/computing `Some(self.priorities[0])`.

```aipl
module tests.functions.collections.priority_queue_z5_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_BinaryMinHeap_T__peekPriority_5(): int:
  let recv_self = BinaryMinHeap(items = [], priorities = [])
  let edge_self = BinaryMinHeap(items = [], priorities = [])
  let resNom = recv_self.peekPriority()
  let resEdge = edge_self.peekPriority()
  assert(resNom.isSome() == false, "peekPriority nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "peekPriority boundary resEdge.isSome() == false")
  ret 0
```

---

### `len` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn (self: BinaryMinHeap[T]) len(): int:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: BinaryMinHeap[T]` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `len` (`self: BinaryMinHeap[T]`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: receiver `recvObj: BinaryMinHeap[T] = BinaryMinHeap(items = [42], priorities = [1])`; exercises core body path returning/computing `self.items.len`.

```aipl
module tests.functions.collections.priority_queue_z6_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_BinaryMinHeap_T__len_6(): int:
  let recv_self = BinaryMinHeap(items = [], priorities = [])
  let edge_self = BinaryMinHeap(items = [], priorities = [])
  let resNom = recv_self.len()
  let resEdge = edge_self.len()
  assertEqInt(resNom, 0, "len nominal resNom == 0")
  assertEqInt(resEdge, 0, "len boundary resEdge == 0")
  ret 0
```

---

### `isEmpty` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn (self: BinaryMinHeap[T]) isEmpty(): bool:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: BinaryMinHeap[T]` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `isEmpty` (`self: BinaryMinHeap[T]`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: receiver `recvObj: BinaryMinHeap[T] = BinaryMinHeap(items = [42], priorities = [1])`; exercises core body path returning/computing `self.items.len == 0`.

```aipl
module tests.functions.collections.priority_queue_z7_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_BinaryMinHeap_T__isEmpty_7(): int:
  let recv_self = BinaryMinHeap(items = [], priorities = [])
  let edge_self = BinaryMinHeap(items = [], priorities = [])
  let resNom = recv_self.isEmpty()
  let resEdge = edge_self.isEmpty()
  assert(resNom == true, "isEmpty nominal resNom == true")
  assert(resEdge == true, "isEmpty boundary resEdge == true")
  ret 0
```

---

### `clear` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn (mut self: BinaryMinHeap[T]) clear(): void:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: BinaryMinHeap[T]` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `clear` (`mut self: BinaryMinHeap[T]`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: receiver `recvObj: BinaryMinHeap[T] = BinaryMinHeap(items = [42], priorities = [1])`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.priority_queue_z8_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_BinaryMinHeap_T__clear_8(): int:
  let mut recv_self = BinaryMinHeap(items = [], priorities = [])
  let mut edge_self = BinaryMinHeap(items = [], priorities = [])
  recv_self.clear()
  edge_self.clear()
  assertEqInt(recv_self.items.len(), 0, "clear nominal recv_self.items.len() == 0")
  assertEqInt(edge_self.items.len(), 0, "clear boundary edge_self.items.len() == 0")
  ret 0
```

---

### `minHeapLen` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn minHeapLen[T](h: BinaryMinHeap[T]): int:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `h: BinaryMinHeap[T]` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `minHeapLen` (`free fn`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: `h: BinaryMinHeap[T] = BinaryMinHeap(items = [42], priorities = [1])`; exercises core body path returning/computing `h.len()`.

```aipl
module tests.functions.collections.priority_queue_z9_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_minHeapLen_9(): int:
  let arg_h = BinaryMinHeap(items = [], priorities = [])
  let edge_h = BinaryMinHeap(items = [], priorities = [])
  let resNom = minHeapLen(arg_h)
  let resEdge = minHeapLen(edge_h)
  assertEqInt(resNom, 0, "minHeapLen nominal resNom == 0")
  assertEqInt(resEdge, 0, "minHeapLen boundary resEdge == 0")
  ret 0
```

---

### `minHeapIsEmpty` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn minHeapIsEmpty[T](h: BinaryMinHeap[T]): bool:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `h: BinaryMinHeap[T]` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `minHeapIsEmpty` (`free fn`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: `h: BinaryMinHeap[T] = BinaryMinHeap(items = [42], priorities = [1])`; exercises core body path returning/computing `h.isEmpty()`.

```aipl
module tests.functions.collections.priority_queue_z10_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_minHeapIsEmpty_10(): int:
  let arg_h = BinaryMinHeap(items = [], priorities = [])
  let edge_h = BinaryMinHeap(items = [], priorities = [])
  let resNom = minHeapIsEmpty(arg_h)
  let resEdge = minHeapIsEmpty(edge_h)
  assert(resNom == true, "minHeapIsEmpty nominal resNom == true")
  assert(resEdge == true, "minHeapIsEmpty boundary resEdge == true")
  ret 0
```

---

### `minHeapPeek` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn minHeapPeek[T](h: BinaryMinHeap[T]): Option[T]:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `h: BinaryMinHeap[T]` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `minHeapPeek` (`free fn`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: `h: BinaryMinHeap[T] = BinaryMinHeap(items = [42], priorities = [1])`; exercises core body path returning/computing `h.peek()`.

```aipl
module tests.functions.collections.priority_queue_z11_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_minHeapPeek_11(): int:
  let arg_h = BinaryMinHeap(items = [], priorities = [])
  let edge_h = BinaryMinHeap(items = [], priorities = [])
  let resNom = minHeapPeek(arg_h)
  let resEdge = minHeapPeek(edge_h)
  assert(resNom.isSome() == false, "minHeapPeek nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "minHeapPeek boundary resEdge.isSome() == false")
  ret 0
```

---

### `minHeapPeekPriority` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn minHeapPeekPriority[T](h: BinaryMinHeap[T]): Option[int]:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `h: BinaryMinHeap[T]` | **Returns**: `Option[int]`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `minHeapPeekPriority` (`free fn`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: `h: BinaryMinHeap[T] = BinaryMinHeap(items = [42], priorities = [1])`; exercises core body path returning/computing `h.peekPriority()`.

```aipl
module tests.functions.collections.priority_queue_z12_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_minHeapPeekPriority_12(): int:
  let arg_h = BinaryMinHeap(items = [], priorities = [])
  let edge_h = BinaryMinHeap(items = [], priorities = [])
  let resNom = minHeapPeekPriority(arg_h)
  let resEdge = minHeapPeekPriority(edge_h)
  assert(resNom.isSome() == false, "minHeapPeekPriority nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "minHeapPeekPriority boundary resEdge.isSome() == false")
  ret 0
```

---

### `minHeapPush` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn minHeapPush[T](mut h: BinaryMinHeap[T], priority: float, item: T): BinaryMinHeap[T]:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut h: BinaryMinHeap[T], priority: float, item: T` | **Returns**: `BinaryMinHeap[T]`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `minHeapPush` (`free fn`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: `h: BinaryMinHeap[T] = BinaryMinHeap(items = [42], priorities = [1])`, `priority: float = 1.0`, `item: T = 42`; exercises core body path returning/computing `h`.

```aipl
module tests.functions.collections.priority_queue_z13_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_minHeapPush_13(): int:
  let arg_h = BinaryMinHeap(items = [], priorities = [])
  let edge_h = BinaryMinHeap(items = [], priorities = [])
  let arg_priority = 1.0
  let edge_priority = 0.5
  let arg_item = 1
  let edge_item = 0
  let resNom = minHeapPush(arg_h, arg_priority, arg_item)
  let resEdge = minHeapPush(edge_h, edge_priority, edge_item)
  assertEqInt(resNom.items.len(), 1, "minHeapPush nominal resNom.items.len() == 1")
  assertEqInt(resEdge.items.len(), 1, "minHeapPush boundary resEdge.items.len() == 1")
  ret 0
```

---

### `minHeapPop` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn minHeapPop[T](mut h: BinaryMinHeap[T]): Option[T]:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut h: BinaryMinHeap[T]` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `minHeapPop` (`free fn`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: `h: BinaryMinHeap[T] = BinaryMinHeap(items = [42], priorities = [1])`; exercises core body path returning/computing `h.pop()`.

```aipl
module tests.functions.collections.priority_queue_z14_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_minHeapPop_14(): int:
  let arg_h = BinaryMinHeap(items = [], priorities = [])
  let edge_h = BinaryMinHeap(items = [], priorities = [])
  let resNom = minHeapPop(arg_h)
  let resEdge = minHeapPop(edge_h)
  assert(resNom.isSome() == false, "minHeapPop nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "minHeapPop boundary resEdge.isSome() == false")
  ret 0
```

---

### `maxHeapNew` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn maxHeapNew[T](): BinaryMaxHeap[T]:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `BinaryMaxHeap[T]`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `maxHeapNew` (`free fn`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `BinaryMaxHeap(items = it, priorities = pr)`.

```aipl
module tests.functions.collections.priority_queue_z15_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_maxHeapNew_15(): int:
  let resNom = maxHeapNew()
  let resEdge = maxHeapNew()
  assertEqInt(resNom.items.len(), 0, "maxHeapNew nominal resNom.items.len() == 0")
  assertEqInt(resEdge.items.len(), 0, "maxHeapNew boundary resEdge.items.len() == 0")
  ret 0
```

---

### `push` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn (mut self: BinaryMaxHeap[T]) push(item: T, priority: int): void:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: BinaryMaxHeap[T]` | **Parameters**: `item: T, priority: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `push` (`mut self: BinaryMaxHeap[T]`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: receiver `recvObj: BinaryMaxHeap[T] = BinaryMaxHeap(items = [42], priorities = [1])`, `item: T = 42`, `priority: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.priority_queue_z16_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_BinaryMaxHeap_T__push_16(): int:
  let mut recv_self = BinaryMaxHeap(items = [], priorities = [])
  let mut edge_self = BinaryMaxHeap(items = [], priorities = [])
  let arg_item = 1
  let edge_item = 0
  let arg_priority = 1
  let edge_priority = 0
  recv_self.push(arg_item, arg_priority)
  edge_self.push(edge_item, edge_priority)
  assertEqInt(recv_self.items.len(), 1, "push nominal recv_self.items.len() == 1")
  assertEqInt(edge_self.items.len(), 1, "push boundary edge_self.items.len() == 1")
  ret 0
```

---

### `pop` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn (mut self: BinaryMaxHeap[T]) pop(): Option[T]:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: BinaryMaxHeap[T]` | **Parameters**: `none` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `pop` (`mut self: BinaryMaxHeap[T]`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: receiver `recvObj: BinaryMaxHeap[T] = BinaryMaxHeap(items = [42], priorities = [1])`; exercises core body path returning/computing `Some(topItem)`.

```aipl
module tests.functions.collections.priority_queue_z17_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_BinaryMaxHeap_T__pop_17(): int:
  let mut recv_self = BinaryMaxHeap(items = [], priorities = [])
  let mut edge_self = BinaryMaxHeap(items = [], priorities = [])
  let resNom = recv_self.pop()
  let resEdge = edge_self.pop()
  assert(resNom.isSome() == false, "pop nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "pop boundary resEdge.isSome() == false")
  ret 0
```

---

### `peek` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn (self: BinaryMaxHeap[T]) peek(): Option[T]:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: BinaryMaxHeap[T]` | **Parameters**: `none` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `peek` (`self: BinaryMaxHeap[T]`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: receiver `recvObj: BinaryMaxHeap[T] = BinaryMaxHeap(items = [42], priorities = [1])`; exercises core body path returning/computing `Some(self.items[0])`.

```aipl
module tests.functions.collections.priority_queue_z18_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_BinaryMaxHeap_T__peek_18(): int:
  let recv_self = BinaryMaxHeap(items = [], priorities = [])
  let edge_self = BinaryMaxHeap(items = [], priorities = [])
  let resNom = recv_self.peek()
  let resEdge = edge_self.peek()
  assert(resNom.isSome() == false, "peek nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "peek boundary resEdge.isSome() == false")
  ret 0
```

---

### `peekPriority` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn (self: BinaryMaxHeap[T]) peekPriority(): Option[int]:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: BinaryMaxHeap[T]` | **Parameters**: `none` | **Returns**: `Option[int]`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `peekPriority` (`self: BinaryMaxHeap[T]`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: receiver `recvObj: BinaryMaxHeap[T] = BinaryMaxHeap(items = [42], priorities = [1])`; exercises core body path returning/computing `Some(self.priorities[0])`.

```aipl
module tests.functions.collections.priority_queue_z19_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_BinaryMaxHeap_T__peekPriority_19(): int:
  let recv_self = BinaryMaxHeap(items = [], priorities = [])
  let edge_self = BinaryMaxHeap(items = [], priorities = [])
  let resNom = recv_self.peekPriority()
  let resEdge = edge_self.peekPriority()
  assert(resNom.isSome() == false, "peekPriority nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "peekPriority boundary resEdge.isSome() == false")
  ret 0
```

---

### `len` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn (self: BinaryMaxHeap[T]) len(): int:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: BinaryMaxHeap[T]` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `len` (`self: BinaryMaxHeap[T]`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: receiver `recvObj: BinaryMaxHeap[T] = BinaryMaxHeap(items = [42], priorities = [1])`; exercises core body path returning/computing `self.items.len`.

```aipl
module tests.functions.collections.priority_queue_z20_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_BinaryMaxHeap_T__len_20(): int:
  let recv_self = BinaryMaxHeap(items = [], priorities = [])
  let edge_self = BinaryMaxHeap(items = [], priorities = [])
  let resNom = recv_self.len()
  let resEdge = edge_self.len()
  assertEqInt(resNom, 0, "len nominal resNom == 0")
  assertEqInt(resEdge, 0, "len boundary resEdge == 0")
  ret 0
```

---

### `isEmpty` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn (self: BinaryMaxHeap[T]) isEmpty(): bool:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: BinaryMaxHeap[T]` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `isEmpty` (`self: BinaryMaxHeap[T]`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: receiver `recvObj: BinaryMaxHeap[T] = BinaryMaxHeap(items = [42], priorities = [1])`; exercises core body path returning/computing `self.items.len == 0`.

```aipl
module tests.functions.collections.priority_queue_z21_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_BinaryMaxHeap_T__isEmpty_21(): int:
  let recv_self = BinaryMaxHeap(items = [], priorities = [])
  let edge_self = BinaryMaxHeap(items = [], priorities = [])
  let resNom = recv_self.isEmpty()
  let resEdge = edge_self.isEmpty()
  assert(resNom == true, "isEmpty nominal resNom == true")
  assert(resEdge == true, "isEmpty boundary resEdge == true")
  ret 0
```

---

### `indexedPqNew` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn indexedPqNew(maxId: int): IndexedPriorityQueue:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `maxId: int` | **Returns**: `IndexedPriorityQueue`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `indexedPqNew` (`free fn`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: `maxId: int = 1`; exercises core body path returning/computing `IndexedPriorityQueue(priorities = pr, heapIndices = hi, inverseHeap = inv)`.

```aipl
module tests.functions.collections.priority_queue_z22_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_indexedPqNew_22(): int:
  let arg_maxId = 4
  let edge_maxId = 1
  let resNom = indexedPqNew(arg_maxId)
  let resEdge = indexedPqNew(edge_maxId)
  assertEqInt(resNom.priorities.len(), 0, "indexedPqNew nominal resNom.priorities.len() == 0")
  assertEqInt(resEdge.priorities.len(), 0, "indexedPqNew boundary resEdge.priorities.len() == 0")
  ret 0
```

---

### `pqNew` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn pqNew(): PriorityQueue:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `PriorityQueue`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `pqNew` (`free fn`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `PriorityQueue(nodes = emptyNodes, costs = emptyCosts)`.

```aipl
module tests.functions.collections.priority_queue_z23_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_pqNew_23(): int:
  let resNom = pqNew()
  let resEdge = pqNew()
  assertEqInt(resNom.nodes.len(), 0, "pqNew nominal resNom.nodes.len() == 0")
  assertEqInt(resEdge.nodes.len(), 0, "pqNew boundary resEdge.nodes.len() == 0")
  ret 0
```

---

### `PriorityQueue.new` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn PriorityQueue.new(): PriorityQueue:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `PriorityQueue`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `PriorityQueue.new` (`free fn`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `pqNew()`.

```aipl
module tests.functions.collections.priority_queue_z24_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_PriorityQueue_new_24(): int:
  let resNom = PriorityQueue.new()
  let resEdge = PriorityQueue.new()
  assertEqInt(resNom.nodes.len(), 0, "PriorityQueue.new nominal resNom.nodes.len() == 0")
  assertEqInt(resEdge.nodes.len(), 0, "PriorityQueue.new boundary resEdge.nodes.len() == 0")
  ret 0
```

---

### `pqLen` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn pqLen(pq: PriorityQueue): int:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pq: PriorityQueue` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `pqLen` (`free fn`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: `pq: PriorityQueue = PriorityQueue(nodes = [1], costs = [1])`; exercises core body path returning/computing `pq.nodes.len`.

```aipl
module tests.functions.collections.priority_queue_z25_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_pqLen_25(): int:
  let arg_pq = PriorityQueue(nodes = [], costs = [])
  let edge_pq = PriorityQueue(nodes = [], costs = [])
  let resNom = pqLen(arg_pq)
  let resEdge = pqLen(edge_pq)
  assertEqInt(resNom, 0, "pqLen nominal resNom == 0")
  assertEqInt(resEdge, 0, "pqLen boundary resEdge == 0")
  ret 0
```

---

### `len` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn (self: PriorityQueue) len(): int:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: PriorityQueue` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `len` (`self: PriorityQueue`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: receiver `recvObj: PriorityQueue = PriorityQueue(nodes = [1], costs = [1])`; exercises core body path returning/computing `self.nodes.len`.

```aipl
module tests.functions.collections.priority_queue_z26_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_PriorityQueue_len_26(): int:
  let recv_self = PriorityQueue(nodes = [], costs = [])
  let edge_self = PriorityQueue(nodes = [], costs = [])
  let resNom = recv_self.len()
  let resEdge = edge_self.len()
  assertEqInt(resNom, 0, "len nominal resNom == 0")
  assertEqInt(resEdge, 0, "len boundary resEdge == 0")
  ret 0
```

---

### `pqIsEmpty` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn pqIsEmpty(pq: PriorityQueue): bool:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pq: PriorityQueue` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `pqIsEmpty` (`free fn`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: `pq: PriorityQueue = PriorityQueue(nodes = [1], costs = [1])`; exercises core body path returning/computing `pq.nodes.len == 0`.

```aipl
module tests.functions.collections.priority_queue_z27_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_pqIsEmpty_27(): int:
  let arg_pq = PriorityQueue(nodes = [], costs = [])
  let edge_pq = PriorityQueue(nodes = [], costs = [])
  let resNom = pqIsEmpty(arg_pq)
  let resEdge = pqIsEmpty(edge_pq)
  assert(resNom == true, "pqIsEmpty nominal resNom == true")
  assert(resEdge == true, "pqIsEmpty boundary resEdge == true")
  ret 0
```

---

### `isEmpty` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn (self: PriorityQueue) isEmpty(): bool:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: PriorityQueue` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `isEmpty` (`self: PriorityQueue`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: receiver `recvObj: PriorityQueue = PriorityQueue(nodes = [1], costs = [1])`; exercises core body path returning/computing `self.nodes.len == 0`.

```aipl
module tests.functions.collections.priority_queue_z28_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_PriorityQueue_isEmpty_28(): int:
  let recv_self = PriorityQueue(nodes = [], costs = [])
  let edge_self = PriorityQueue(nodes = [], costs = [])
  let resNom = recv_self.isEmpty()
  let resEdge = edge_self.isEmpty()
  assert(resNom == true, "isEmpty nominal resNom == true")
  assert(resEdge == true, "isEmpty boundary resEdge == true")
  ret 0
```

---

### `pqPeek` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn pqPeek(pq: PriorityQueue): Option[int]:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pq: PriorityQueue` | **Returns**: `Option[int]`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `pqPeek` (`free fn`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: `pq: PriorityQueue = PriorityQueue(nodes = [1], costs = [1])`; exercises core body path returning/computing `Some(pq.nodes[0])`.

```aipl
module tests.functions.collections.priority_queue_z29_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_pqPeek_29(): int:
  let arg_pq = PriorityQueue(nodes = [], costs = [])
  let edge_pq = PriorityQueue(nodes = [], costs = [])
  let resNom = pqPeek(arg_pq)
  let resEdge = pqPeek(edge_pq)
  assert(resNom.isSome() == false, "pqPeek nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "pqPeek boundary resEdge.isSome() == false")
  ret 0
```

---

### `peek` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn (self: PriorityQueue) peek(): Option[int]:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: PriorityQueue` | **Parameters**: `none` | **Returns**: `Option[int]`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `peek` (`self: PriorityQueue`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: receiver `recvObj: PriorityQueue = PriorityQueue(nodes = [1], costs = [1])`; exercises core body path returning/computing `pqPeek(self)`.

```aipl
module tests.functions.collections.priority_queue_z30_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_PriorityQueue_peek_30(): int:
  let recv_self = PriorityQueue(nodes = [], costs = [])
  let edge_self = PriorityQueue(nodes = [], costs = [])
  let resNom = recv_self.peek()
  let resEdge = edge_self.peek()
  assert(resNom.isSome() == false, "peek nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "peek boundary resEdge.isSome() == false")
  ret 0
```

---

### `pqPeekCost` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn pqPeekCost(pq: PriorityQueue): Option[int]:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pq: PriorityQueue` | **Returns**: `Option[int]`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `pqPeekCost` (`free fn`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: `pq: PriorityQueue = PriorityQueue(nodes = [1], costs = [1])`; exercises core body path returning/computing `Some(pq.costs[0])`.

```aipl
module tests.functions.collections.priority_queue_z31_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_pqPeekCost_31(): int:
  let arg_pq = PriorityQueue(nodes = [], costs = [])
  let edge_pq = PriorityQueue(nodes = [], costs = [])
  let resNom = pqPeekCost(arg_pq)
  let resEdge = pqPeekCost(edge_pq)
  assert(resNom.isSome() == false, "pqPeekCost nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "pqPeekCost boundary resEdge.isSome() == false")
  ret 0
```

---

### `pqPush` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn pqPush(mut pq: PriorityQueue, node: int, cost: int): PriorityQueue:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut pq: PriorityQueue, node: int, cost: int` | **Returns**: `PriorityQueue`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `pqPush` (`free fn`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: `pq: PriorityQueue = PriorityQueue(nodes = [1], costs = [1])`, `node: int = 1`, `cost: int = 1`; exercises core body path returning/computing `pq`.

```aipl
module tests.functions.collections.priority_queue_z32_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_pqPush_32(): int:
  let arg_pq = PriorityQueue(nodes = [], costs = [])
  let edge_pq = PriorityQueue(nodes = [], costs = [])
  let arg_node = 4
  let edge_node = 1
  let arg_cost = 2
  let edge_cost = 0
  let resNom = pqPush(arg_pq, arg_node, arg_cost)
  let resEdge = pqPush(edge_pq, edge_node, edge_cost)
  assertEqInt(resNom.nodes.len(), 1, "pqPush nominal resNom.nodes.len() == 1")
  assertEqInt(resEdge.nodes.len(), 1, "pqPush boundary resEdge.nodes.len() == 1")
  ret 0
```

---

### `pqPopMin` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn pqPopMin(mut pq: PriorityQueue): Option[int]:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut pq: PriorityQueue` | **Returns**: `Option[int]`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `pqPopMin` (`free fn`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: `pq: PriorityQueue = PriorityQueue(nodes = [1], costs = [1])`; exercises core body path returning/computing `Some(minNode)`.

```aipl
module tests.functions.collections.priority_queue_z33_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_pqPopMin_33(): int:
  let arg_pq = PriorityQueue(nodes = [], costs = [])
  let edge_pq = PriorityQueue(nodes = [], costs = [])
  let resNom = pqPopMin(arg_pq)
  let resEdge = pqPopMin(edge_pq)
  assert(resNom.isSome() == false, "pqPopMin nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "pqPopMin boundary resEdge.isSome() == false")
  ret 0
```

---

### `pqDecreaseKey` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn pqDecreaseKey(mut pq: PriorityQueue, node: int, newCost: int): bool:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut pq: PriorityQueue, node: int, newCost: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `pqDecreaseKey` (`free fn`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: `pq: PriorityQueue = PriorityQueue(nodes = [1], costs = [1])`, `node: int = 1`, `newCost: int = 1`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.collections.priority_queue_z34_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_pqDecreaseKey_34(): int:
  let arg_pq = PriorityQueue(nodes = [], costs = [])
  let edge_pq = PriorityQueue(nodes = [], costs = [])
  let arg_node = 4
  let edge_node = 1
  let arg_newCost = 4
  let edge_newCost = 1
  let resNom = pqDecreaseKey(arg_pq, arg_node, arg_newCost)
  let resEdge = pqDecreaseKey(edge_pq, edge_node, edge_newCost)
  assert(resNom == false, "pqDecreaseKey nominal resNom == false")
  assert(resEdge == false, "pqDecreaseKey boundary resEdge == false")
  ret 0
```

---

### `BinaryHeap.new` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn BinaryHeap.new(): BinaryHeap:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `BinaryHeap`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `BinaryHeap.new` (`free fn`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `BinaryHeap(priorities = p, values = v, isMax = false)`.

```aipl
module tests.functions.collections.priority_queue_z35_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_BinaryHeap_new_35(): int:
  let resNom = BinaryHeap.new()
  let resEdge = BinaryHeap.new()
  assertEqInt(resNom.priorities.len(), 0, "BinaryHeap.new nominal resNom.priorities.len() == 0")
  assertEqInt(resEdge.priorities.len(), 0, "BinaryHeap.new boundary resEdge.priorities.len() == 0")
  ret 0
```

---

### `len` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn (self: BinaryHeap) len(): int:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: BinaryHeap` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `len` (`self: BinaryHeap`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: receiver `recvObj: BinaryHeap = BinaryHeap(priorities = [1], values = [42], isMax = true)`; exercises core body path returning/computing `self.priorities.len`.

```aipl
module tests.functions.collections.priority_queue_z36_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_BinaryHeap_len_36(): int:
  let recv_self = BinaryHeap(priorities = [], values = [], isMax = true)
  let edge_self = BinaryHeap(priorities = [], values = [], isMax = false)
  let resNom = recv_self.len()
  let resEdge = edge_self.len()
  assertEqInt(resNom, 0, "len nominal resNom == 0")
  assertEqInt(resEdge, 0, "len boundary resEdge == 0")
  ret 0
```

---

### `isEmpty` (`std/collections/priority_queue.aipl`)

- **Signature**: `pub fn (self: BinaryHeap) isEmpty(): bool:`
- **Import**: `import * from "std/collections/priority_queue"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: BinaryHeap` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/priority_queue_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `isEmpty` (`self: BinaryHeap`) binary heap / indexed priority queue ordering invariant across out-of-order pushes, `pqDecreaseKey` priority updates, and monotonic pop sequences. Concrete nominal inputs: receiver `recvObj: BinaryHeap = BinaryHeap(priorities = [1], values = [42], isMax = true)`; exercises core body path returning/computing `self.priorities.len == 0`.

```aipl
module tests.functions.collections.priority_queue_z37_test
import * from "std/collections/priority_queue"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_priority_queue_BinaryHeap_isEmpty_37(): int:
  let recv_self = BinaryHeap(priorities = [], values = [], isMax = true)
  let edge_self = BinaryHeap(priorities = [], values = [], isMax = false)
  let resNom = recv_self.isEmpty()
  let resEdge = edge_self.isEmpty()
  assert(resNom == true, "isEmpty nominal resNom == true")
  assert(resEdge == true, "isEmpty boundary resEdge == true")
  ret 0
```

---

### `quadtreeNew` (`std/collections/quadtree.aipl`)

- **Signature**: `pub fn quadtreeNew[T](x: float, y: float, w: float, h: float, capacity: int): QuadtreeNode[T]:`
- **Import**: `import * from "std/collections/quadtree"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float, w: float, h: float, capacity: int` | **Returns**: `QuadtreeNode[T]`
- **Unit Test**: `tests/functions/collections/quadtree_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `quadtreeNew` (`free fn`) 2D Quadtree spatial insertion, 4-quadrant node split when capacity is exceeded, and 100% recall on `queryRange` AABB searches. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`, `capacity: int = 64`; exercises core body path returning/computing `QuadtreeNode(`.

```aipl
module tests.functions.collections.quadtree_z1_test
import * from "std/collections/quadtree"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_quadtree_quadtreeNew_1(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let arg_capacity = 4
  let edge_capacity = 1
  let resNom = quadtreeNew(arg_x, arg_y, arg_w, arg_h, arg_capacity)
  let resEdge = quadtreeNew(edge_x, edge_y, edge_w, edge_h, edge_capacity)
  assertApproxEq(resNom.boundaryX, 1.0, 0.001, "quadtreeNew nominal resNom.boundaryX ~= 1.0")
  assertApproxEq(resEdge.boundaryX, 0.5, 0.001, "quadtreeNew boundary resEdge.boundaryX ~= 0.5")
  ret 0
```

---

### `containsPoint` (`std/collections/quadtree.aipl`)

- **Signature**: `pub fn (self: QuadtreeNode[T]) containsPoint(px: float, py: float): bool:`
- **Import**: `import * from "std/collections/quadtree"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: QuadtreeNode[T]` | **Parameters**: `px: float, py: float` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/quadtree_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `containsPoint` (`self: QuadtreeNode[T]`) 2D Quadtree spatial insertion, 4-quadrant node split when capacity is exceeded, and 100% recall on `queryRange` AABB searches. Concrete nominal inputs: receiver `recvObj: QuadtreeNode[T] = QuadtreeNode(boundaryX = 1.0, boundaryY = 1.0, boundaryW = 1.0, boundaryH = 1.0, capacity = 64, items = [QuadtreeItem(x = 0, y = 0, payload = 0)], divided = true, nw = Some(QuadtreeNode(boundaryX = 0, boundaryY = 0, boundaryW = 0, boundaryH = 0, capacity = 0, items = 0, divided = 0, nw = 0, ne = 0, sw = 0, se = 0)), ne = Some(QuadtreeNode(boundaryX = 0, boundaryY = 0, boundaryW = 0, boundaryH = 0, capacity = 0, items = 0, divided = 0, nw = 0, ne = 0, sw = 0, se = 0)), sw = Some(QuadtreeNode(boundaryX = 0, boundaryY = 0, boundaryW = 0, boundaryH = 0, capacity = 0, items = 0, divided = 0, nw = 0, ne = 0, sw = 0, se = 0)), se = Some(QuadtreeNode(boundaryX = 0, boundaryY = 0, boundaryW = 0, boundaryH = 0, capacity = 0, items = 0, divided = 0, nw = 0, ne = 0, sw = 0, se = 0)))`, `px: float = 1.0`, `py: float = 1.0`; exercises core body path returning/computing `px >= self.boundaryX and px < (self.boundaryX + self.boundaryW) and py >= self.boundaryY and py < (self.boundaryY + self.boundaryH)`.

```aipl
module tests.functions.collections.quadtree_z2_test
import * from "std/collections/quadtree"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_quadtree_QuadtreeNode_T__containsPoint_2(): int:
  let recv_self = QuadtreeNode(boundaryX = 1.0, boundaryY = 1.0, boundaryW = 2.0, boundaryH = 2.0, capacity = 4, items = [], divided = true, nw = None(), ne = None(), sw = None(), se = None())
  let edge_self = QuadtreeNode(boundaryX = 0.5, boundaryY = 0.5, boundaryW = 1.0, boundaryH = 1.0, capacity = 4, items = [], divided = false, nw = None(), ne = None(), sw = None(), se = None())
  let arg_px = 1.0
  let edge_px = 0.5
  let arg_py = 1.0
  let edge_py = 0.5
  let resNom = recv_self.containsPoint(arg_px, arg_py)
  let resEdge = edge_self.containsPoint(edge_px, edge_py)
  assert(resNom == true, "containsPoint nominal resNom == true")
  assert(resEdge == true, "containsPoint boundary resEdge == true")
  ret 0
```

---

### `intersectsRange` (`std/collections/quadtree.aipl`)

- **Signature**: `pub fn (self: QuadtreeNode[T]) intersectsRange(qx: float, qy: float, qw: float, qh: float): bool:`
- **Import**: `import * from "std/collections/quadtree"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: QuadtreeNode[T]` | **Parameters**: `qx: float, qy: float, qw: float, qh: float` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/quadtree_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `intersectsRange` (`self: QuadtreeNode[T]`) 2D Quadtree spatial insertion, 4-quadrant node split when capacity is exceeded, and 100% recall on `queryRange` AABB searches. Concrete nominal inputs: receiver `recvObj: QuadtreeNode[T] = QuadtreeNode(boundaryX = 1.0, boundaryY = 1.0, boundaryW = 1.0, boundaryH = 1.0, capacity = 64, items = [QuadtreeItem(x = 0, y = 0, payload = 0)], divided = true, nw = Some(QuadtreeNode(boundaryX = 0, boundaryY = 0, boundaryW = 0, boundaryH = 0, capacity = 0, items = 0, divided = 0, nw = 0, ne = 0, sw = 0, se = 0)), ne = Some(QuadtreeNode(boundaryX = 0, boundaryY = 0, boundaryW = 0, boundaryH = 0, capacity = 0, items = 0, divided = 0, nw = 0, ne = 0, sw = 0, se = 0)), sw = Some(QuadtreeNode(boundaryX = 0, boundaryY = 0, boundaryW = 0, boundaryH = 0, capacity = 0, items = 0, divided = 0, nw = 0, ne = 0, sw = 0, se = 0)), se = Some(QuadtreeNode(boundaryX = 0, boundaryY = 0, boundaryW = 0, boundaryH = 0, capacity = 0, items = 0, divided = 0, nw = 0, ne = 0, sw = 0, se = 0)))`, `qx: float = 1.0`, `qy: float = 1.0`, `qw: float = 1.0`, `qh: float = 1.0`; exercises core body path returning/computing `not (qx > self.boundaryX + self.boundaryW or qx + qw < self.boundaryX or qy > self.boundaryY + self.boundaryH or qy + qh < self.boundaryY)`.

```aipl
module tests.functions.collections.quadtree_z3_test
import * from "std/collections/quadtree"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_quadtree_QuadtreeNode_T__intersectsRange_3(): int:
  let recv_self = QuadtreeNode(boundaryX = 1.0, boundaryY = 1.0, boundaryW = 2.0, boundaryH = 2.0, capacity = 4, items = [], divided = true, nw = None(), ne = None(), sw = None(), se = None())
  let edge_self = QuadtreeNode(boundaryX = 0.5, boundaryY = 0.5, boundaryW = 1.0, boundaryH = 1.0, capacity = 4, items = [], divided = false, nw = None(), ne = None(), sw = None(), se = None())
  let arg_qx = 1.0
  let edge_qx = 0.5
  let arg_qy = 1.0
  let edge_qy = 0.5
  let arg_qw = 2.0
  let edge_qw = 1.0
  let arg_qh = 2.0
  let edge_qh = 1.0
  let resNom = recv_self.intersectsRange(arg_qx, arg_qy, arg_qw, arg_qh)
  let resEdge = edge_self.intersectsRange(edge_qx, edge_qy, edge_qw, edge_qh)
  assert(resNom == true, "intersectsRange nominal resNom == true")
  assert(resEdge == true, "intersectsRange boundary resEdge == true")
  ret 0
```

---

### `insert` (`std/collections/quadtree.aipl`)

- **Signature**: `pub fn (mut self: QuadtreeNode[T]) insert(item: QuadtreeItem[T]): bool:`
- **Import**: `import * from "std/collections/quadtree"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: QuadtreeNode[T]` | **Parameters**: `item: QuadtreeItem[T]` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/quadtree_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `insert` (`mut self: QuadtreeNode[T]`) 2D Quadtree spatial insertion, 4-quadrant node split when capacity is exceeded, and 100% recall on `queryRange` AABB searches. Concrete nominal inputs: receiver `recvObj: QuadtreeNode[T] = QuadtreeNode(boundaryX = 1.0, boundaryY = 1.0, boundaryW = 1.0, boundaryH = 1.0, capacity = 64, items = [QuadtreeItem(x = 0, y = 0, payload = 0)], divided = false, nw = Some(QuadtreeNode(boundaryX = 0, boundaryY = 0, boundaryW = 0, boundaryH = 0, capacity = 0, items = 0, divided = 0, nw = 0, ne = 0, sw = 0, se = 0)), ne = Some(QuadtreeNode(boundaryX = 0, boundaryY = 0, boundaryW = 0, boundaryH = 0, capacity = 0, items = 0, divided = 0, nw = 0, ne = 0, sw = 0, se = 0)), sw = Some(QuadtreeNode(boundaryX = 0, boundaryY = 0, boundaryW = 0, boundaryH = 0, capacity = 0, items = 0, divided = 0, nw = 0, ne = 0, sw = 0, se = 0)), se = Some(QuadtreeNode(boundaryX = 0, boundaryY = 0, boundaryW = 0, boundaryH = 0, capacity = 0, items = 0, divided = 0, nw = 0, ne = 0, sw = 0, se = 0)))`, `item: QuadtreeItem[T] = QuadtreeItem(x = 1.0, y = 1.0, payload = 42)`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.collections.quadtree_z4_test
import * from "std/collections/quadtree"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_quadtree_QuadtreeNode_T__insert_4(): int:
  let mut recv_self = QuadtreeNode(boundaryX = 1.0, boundaryY = 1.0, boundaryW = 2.0, boundaryH = 2.0, capacity = 4, items = [], divided = false, nw = None(), ne = None(), sw = None(), se = None())
  let mut edge_self = QuadtreeNode(boundaryX = 0.5, boundaryY = 0.5, boundaryW = 1.0, boundaryH = 1.0, capacity = 4, items = [], divided = false, nw = None(), ne = None(), sw = None(), se = None())
  let arg_item = QuadtreeItem(x = 1.0, y = 1.0, payload = 1)
  let edge_item = QuadtreeItem(x = 0.5, y = 0.5, payload = 0)
  let resNom = recv_self.insert(arg_item)
  let resEdge = edge_self.insert(edge_item)
  assert(resNom == true, "insert nominal resNom == true")
  assert(resEdge == true, "insert boundary resEdge == true")
  ret 0
```

---

### `queryRange` (`std/collections/quadtree.aipl`)

- **Signature**: `pub fn (self: QuadtreeNode[T]) queryRange(qx: float, qy: float, qw: float, qh: float): [T]:`
- **Import**: `import * from "std/collections/quadtree"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: QuadtreeNode[T]` | **Parameters**: `qx: float, qy: float, qw: float, qh: float` | **Returns**: `[T]`
- **Unit Test**: `tests/functions/collections/quadtree_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `queryRange` (`self: QuadtreeNode[T]`) 2D Quadtree spatial insertion, 4-quadrant node split when capacity is exceeded, and 100% recall on `queryRange` AABB searches. Concrete nominal inputs: receiver `recvObj: QuadtreeNode[T] = QuadtreeNode(boundaryX = 1.0, boundaryY = 1.0, boundaryW = 1.0, boundaryH = 1.0, capacity = 64, items = [QuadtreeItem(x = 0, y = 0, payload = 0)], divided = false, nw = Some(QuadtreeNode(boundaryX = 0, boundaryY = 0, boundaryW = 0, boundaryH = 0, capacity = 0, items = 0, divided = 0, nw = 0, ne = 0, sw = 0, se = 0)), ne = Some(QuadtreeNode(boundaryX = 0, boundaryY = 0, boundaryW = 0, boundaryH = 0, capacity = 0, items = 0, divided = 0, nw = 0, ne = 0, sw = 0, se = 0)), sw = Some(QuadtreeNode(boundaryX = 0, boundaryY = 0, boundaryW = 0, boundaryH = 0, capacity = 0, items = 0, divided = 0, nw = 0, ne = 0, sw = 0, se = 0)), se = Some(QuadtreeNode(boundaryX = 0, boundaryY = 0, boundaryW = 0, boundaryH = 0, capacity = 0, items = 0, divided = 0, nw = 0, ne = 0, sw = 0, se = 0)))`, `qx: float = 1.0`, `qy: float = 1.0`, `qw: float = 1.0`, `qh: float = 1.0`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.collections.quadtree_z5_test
import * from "std/collections/quadtree"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_quadtree_QuadtreeNode_T__queryRange_5(): int:
  let recv_self = QuadtreeNode(boundaryX = 1.0, boundaryY = 1.0, boundaryW = 2.0, boundaryH = 2.0, capacity = 4, items = [], divided = false, nw = None(), ne = None(), sw = None(), se = None())
  let edge_self = QuadtreeNode(boundaryX = 0.5, boundaryY = 0.5, boundaryW = 1.0, boundaryH = 1.0, capacity = 4, items = [], divided = false, nw = None(), ne = None(), sw = None(), se = None())
  let arg_qx = 1.0
  let edge_qx = 0.5
  let arg_qy = 1.0
  let edge_qy = 0.5
  let arg_qw = 2.0
  let edge_qw = 1.0
  let arg_qh = 2.0
  let edge_qh = 1.0
  let resNom = recv_self.queryRange(arg_qx, arg_qy, arg_qw, arg_qh)
  let resEdge = edge_self.queryRange(edge_qx, edge_qy, edge_qw, edge_qh)
  assertEqInt(resNom.len(), 0, "queryRange nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "queryRange boundary resEdge.len() == 0")
  ret 0
```

---

### `count` (`std/collections/quadtree.aipl`)

- **Signature**: `pub fn (self: QuadtreeNode[T]) count(): int:`
- **Import**: `import * from "std/collections/quadtree"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: QuadtreeNode[T]` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/quadtree_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `count` (`self: QuadtreeNode[T]`) 2D Quadtree spatial insertion, 4-quadrant node split when capacity is exceeded, and 100% recall on `queryRange` AABB searches. Concrete nominal inputs: receiver `recvObj: QuadtreeNode[T] = QuadtreeNode(boundaryX = 1.0, boundaryY = 1.0, boundaryW = 1.0, boundaryH = 1.0, capacity = 64, items = [QuadtreeItem(x = 0, y = 0, payload = 0)], divided = false, nw = Some(QuadtreeNode(boundaryX = 0, boundaryY = 0, boundaryW = 0, boundaryH = 0, capacity = 0, items = 0, divided = 0, nw = 0, ne = 0, sw = 0, se = 0)), ne = Some(QuadtreeNode(boundaryX = 0, boundaryY = 0, boundaryW = 0, boundaryH = 0, capacity = 0, items = 0, divided = 0, nw = 0, ne = 0, sw = 0, se = 0)), sw = Some(QuadtreeNode(boundaryX = 0, boundaryY = 0, boundaryW = 0, boundaryH = 0, capacity = 0, items = 0, divided = 0, nw = 0, ne = 0, sw = 0, se = 0)), se = Some(QuadtreeNode(boundaryX = 0, boundaryY = 0, boundaryW = 0, boundaryH = 0, capacity = 0, items = 0, divided = 0, nw = 0, ne = 0, sw = 0, se = 0)))`; exercises core body path returning/computing `total`.

```aipl
module tests.functions.collections.quadtree_z6_test
import * from "std/collections/quadtree"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_quadtree_QuadtreeNode_T__count_6(): int:
  let recv_self = QuadtreeNode(boundaryX = 1.0, boundaryY = 1.0, boundaryW = 2.0, boundaryH = 2.0, capacity = 4, items = [], divided = false, nw = None(), ne = None(), sw = None(), se = None())
  let edge_self = QuadtreeNode(boundaryX = 0.5, boundaryY = 0.5, boundaryW = 1.0, boundaryH = 1.0, capacity = 4, items = [], divided = false, nw = None(), ne = None(), sw = None(), se = None())
  let resNom = recv_self.count()
  let resEdge = edge_self.count()
  assertEqInt(resNom, 0, "count nominal resNom == 0")
  assertEqInt(resEdge, 0, "count boundary resEdge == 0")
  ret 0
```

---

### `sparseSetNew` (`std/collections/sparse_set.aipl`)

- **Signature**: `pub fn sparseSetNew[T](maxIndex: int): SparseSet[T]:`
- **Import**: `import * from "std/collections/sparse_set"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `maxIndex: int` | **Returns**: `SparseSet[T]`
- **Unit Test**: `tests/functions/collections/sparse_set_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `sparseSetNew` (`free fn`) O(1) sparse-to-dense entity mapping across non-contiguous ID insertions and swap-and-pop removal without invalidating remaining IDs. Concrete nominal inputs: `maxIndex: int = 0`; exercises core body path returning/computing `SparseSet(dense = d, sparse = s, values = v, count = 0)`.

```aipl
module tests.functions.collections.sparse_set_z1_test
import * from "std/collections/sparse_set"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sparse_set_sparseSetNew_1(): int:
  let arg_maxIndex = 4
  let edge_maxIndex = 1
  let resNom = sparseSetNew(arg_maxIndex)
  let resEdge = sparseSetNew(edge_maxIndex)
  assertEqInt(resNom.dense.len(), 0, "sparseSetNew nominal resNom.dense.len() == 0")
  assertEqInt(resEdge.dense.len(), 0, "sparseSetNew boundary resEdge.dense.len() == 0")
  ret 0
```

---

### `contains` (`std/collections/sparse_set.aipl`)

- **Signature**: `pub fn (self: SparseSet[T]) contains(id: int): bool:`
- **Import**: `import * from "std/collections/sparse_set"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: SparseSet[T]` | **Parameters**: `id: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/sparse_set_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `contains` (`self: SparseSet[T]`) O(1) sparse-to-dense entity mapping across non-contiguous ID insertions and swap-and-pop removal without invalidating remaining IDs. Concrete nominal inputs: receiver `recvObj: SparseSet[T] = SparseSet(dense = [1], sparse = [1], values = [42], count = 64)`, `id: int = 1`; exercises core body path returning/computing `self.dense[denseIdx] == id`.

```aipl
module tests.functions.collections.sparse_set_z2_test
import * from "std/collections/sparse_set"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sparse_set_SparseSet_T__contains_2(): int:
  let recv_self = SparseSet(dense = [], sparse = [], values = [], count = 0)
  let edge_self = SparseSet(dense = [], sparse = [], values = [], count = 0)
  let arg_id = 1
  let edge_id = 0
  let resNom = recv_self.contains(arg_id)
  let resEdge = edge_self.contains(edge_id)
  assert(resNom == false, "contains nominal resNom == false")
  assert(resEdge == false, "contains boundary resEdge == false")
  ret 0
```

---

### `insert` (`std/collections/sparse_set.aipl`)

- **Signature**: `pub fn (mut self: SparseSet[T]) insert(id: int, val: T): bool:`
- **Import**: `import * from "std/collections/sparse_set"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: SparseSet[T]` | **Parameters**: `id: int, val: T` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/sparse_set_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `insert` (`mut self: SparseSet[T]`) O(1) sparse-to-dense entity mapping across non-contiguous ID insertions and swap-and-pop removal without invalidating remaining IDs. Concrete nominal inputs: receiver `recvObj: SparseSet[T] = SparseSet(dense = [1], sparse = [1], values = [42], count = 64)`, `id: int = 1`, `val: T = 42`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.collections.sparse_set_z3_test
import * from "std/collections/sparse_set"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sparse_set_SparseSet_T__insert_3(): int:
  let mut recv_self = SparseSet(dense = [], sparse = [], values = [], count = 0)
  let mut edge_self = SparseSet(dense = [], sparse = [], values = [], count = 0)
  let arg_id = 1
  let edge_id = 0
  let arg_val = 1
  let edge_val = 0
  let resNom = recv_self.insert(arg_id, arg_val)
  let resEdge = edge_self.insert(edge_id, edge_val)
  assert(resNom == true, "insert nominal resNom == true")
  assert(resEdge == true, "insert boundary resEdge == true")
  ret 0
```

---

### `remove` (`std/collections/sparse_set.aipl`)

- **Signature**: `pub fn (mut self: SparseSet[T]) remove(id: int): bool:`
- **Import**: `import * from "std/collections/sparse_set"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: SparseSet[T]` | **Parameters**: `id: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/sparse_set_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `remove` (`mut self: SparseSet[T]`) O(1) sparse-to-dense entity mapping across non-contiguous ID insertions and swap-and-pop removal without invalidating remaining IDs. Concrete nominal inputs: receiver `recvObj: SparseSet[T] = SparseSet(dense = [1], sparse = [1], values = [42], count = 64)`, `id: int = 1`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.collections.sparse_set_z4_test
import * from "std/collections/sparse_set"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sparse_set_SparseSet_T__remove_4(): int:
  let mut recv_self = SparseSet(dense = [], sparse = [], values = [], count = 0)
  let mut edge_self = SparseSet(dense = [], sparse = [], values = [], count = 0)
  let arg_id = 1
  let edge_id = 0
  let resNom = recv_self.remove(arg_id)
  let resEdge = edge_self.remove(edge_id)
  assert(resNom == false, "remove nominal resNom == false")
  assert(resEdge == false, "remove boundary resEdge == false")
  ret 0
```

---

### `get` (`std/collections/sparse_set.aipl`)

- **Signature**: `pub fn (self: SparseSet[T]) get(id: int): Option[T]:`
- **Import**: `import * from "std/collections/sparse_set"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: SparseSet[T]` | **Parameters**: `id: int` | **Returns**: `Option[T]`
- **Unit Test**: `tests/functions/collections/sparse_set_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `get` (`self: SparseSet[T]`) O(1) sparse-to-dense entity mapping across non-contiguous ID insertions and swap-and-pop removal without invalidating remaining IDs. Concrete nominal inputs: receiver `recvObj: SparseSet[T] = SparseSet(dense = [1], sparse = [1], values = [42], count = 64)`, `id: int = 1`; exercises core body path returning/computing `Some(self.values[denseIdx])`.

```aipl
module tests.functions.collections.sparse_set_z5_test
import * from "std/collections/sparse_set"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sparse_set_SparseSet_T__get_5(): int:
  let recv_self = SparseSet(dense = [], sparse = [], values = [], count = 0)
  let edge_self = SparseSet(dense = [], sparse = [], values = [], count = 0)
  let arg_id = 1
  let edge_id = 0
  let resNom = recv_self.get(arg_id)
  let resEdge = edge_self.get(edge_id)
  assert(resNom.isSome() == false, "get nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "get boundary resEdge.isSome() == false")
  ret 0
```

---

### `len` (`std/collections/sparse_set.aipl`)

- **Signature**: `pub fn (self: SparseSet[T]) len(): int:`
- **Import**: `import * from "std/collections/sparse_set"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: SparseSet[T]` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/sparse_set_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `len` (`self: SparseSet[T]`) O(1) sparse-to-dense entity mapping across non-contiguous ID insertions and swap-and-pop removal without invalidating remaining IDs. Concrete nominal inputs: receiver `recvObj: SparseSet[T] = SparseSet(dense = [1], sparse = [1], values = [42], count = 64)`; exercises core body path returning/computing `self.count`.

```aipl
module tests.functions.collections.sparse_set_z6_test
import * from "std/collections/sparse_set"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sparse_set_SparseSet_T__len_6(): int:
  let recv_self = SparseSet(dense = [], sparse = [], values = [], count = 0)
  let edge_self = SparseSet(dense = [], sparse = [], values = [], count = 0)
  let resNom = recv_self.len()
  let resEdge = edge_self.len()
  assertEqInt(resNom, 0, "len nominal resNom == 0")
  assertEqInt(resEdge, 0, "len boundary resEdge == 0")
  ret 0
```

---

### `isEmpty` (`std/collections/sparse_set.aipl`)

- **Signature**: `pub fn (self: SparseSet[T]) isEmpty(): bool:`
- **Import**: `import * from "std/collections/sparse_set"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: SparseSet[T]` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/collections/sparse_set_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `isEmpty` (`self: SparseSet[T]`) O(1) sparse-to-dense entity mapping across non-contiguous ID insertions and swap-and-pop removal without invalidating remaining IDs. Concrete nominal inputs: receiver `recvObj: SparseSet[T] = SparseSet(dense = [1], sparse = [1], values = [42], count = 64)`; exercises core body path returning/computing `self.count == 0`.

```aipl
module tests.functions.collections.sparse_set_z7_test
import * from "std/collections/sparse_set"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sparse_set_SparseSet_T__isEmpty_7(): int:
  let recv_self = SparseSet(dense = [], sparse = [], values = [], count = 0)
  let edge_self = SparseSet(dense = [], sparse = [], values = [], count = 0)
  let resNom = recv_self.isEmpty()
  let resEdge = edge_self.isEmpty()
  assert(resNom == true, "isEmpty nominal resNom == true")
  assert(resEdge == true, "isEmpty boundary resEdge == true")
  ret 0
```

---

### `clear` (`std/collections/sparse_set.aipl`)

- **Signature**: `pub fn (mut self: SparseSet[T]) clear(): void:`
- **Import**: `import * from "std/collections/sparse_set"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: SparseSet[T]` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/sparse_set_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `clear` (`mut self: SparseSet[T]`) O(1) sparse-to-dense entity mapping across non-contiguous ID insertions and swap-and-pop removal without invalidating remaining IDs. Concrete nominal inputs: receiver `recvObj: SparseSet[T] = SparseSet(dense = [1], sparse = [1], values = [42], count = 64)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.sparse_set_z8_test
import * from "std/collections/sparse_set"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sparse_set_SparseSet_T__clear_8(): int:
  let mut recv_self = SparseSet(dense = [], sparse = [], values = [], count = 0)
  let mut edge_self = SparseSet(dense = [], sparse = [], values = [], count = 0)
  recv_self.clear()
  edge_self.clear()
  assertEqInt(recv_self.dense.len(), 0, "clear nominal recv_self.dense.len() == 0")
  assertEqInt(edge_self.dense.len(), 0, "clear boundary edge_self.dense.len() == 0")
  ret 0
```

---

### `ids` (`std/collections/sparse_set.aipl`)

- **Signature**: `pub fn (self: SparseSet[T]) ids(): [int]:`
- **Import**: `import * from "std/collections/sparse_set"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: SparseSet[T]` | **Parameters**: `none` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/collections/sparse_set_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `ids` (`self: SparseSet[T]`) O(1) sparse-to-dense entity mapping across non-contiguous ID insertions and swap-and-pop removal without invalidating remaining IDs. Concrete nominal inputs: receiver `recvObj: SparseSet[T] = SparseSet(dense = [1], sparse = [1], values = [42], count = 64)`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.collections.sparse_set_z9_test
import * from "std/collections/sparse_set"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sparse_set_SparseSet_T__ids_9(): int:
  let recv_self = SparseSet(dense = [], sparse = [], values = [], count = 0)
  let edge_self = SparseSet(dense = [], sparse = [], values = [], count = 0)
  let resNom = recv_self.ids()
  let resEdge = edge_self.ids()
  assertEqInt(resNom.len(), 0, "ids nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "ids boundary resEdge.len() == 0")
  ret 0
```

---

### `denseValues` (`std/collections/sparse_set.aipl`)

- **Signature**: `pub fn (self: SparseSet[T]) denseValues(): [T]:`
- **Import**: `import * from "std/collections/sparse_set"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: SparseSet[T]` | **Parameters**: `none` | **Returns**: `[T]`
- **Unit Test**: `tests/functions/collections/sparse_set_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `denseValues` (`self: SparseSet[T]`) O(1) sparse-to-dense entity mapping across non-contiguous ID insertions and swap-and-pop removal without invalidating remaining IDs. Concrete nominal inputs: receiver `recvObj: SparseSet[T] = SparseSet(dense = [1], sparse = [1], values = [42], count = 64)`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.collections.sparse_set_z10_test
import * from "std/collections/sparse_set"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sparse_set_SparseSet_T__denseValues_10(): int:
  let recv_self = SparseSet(dense = [], sparse = [], values = [], count = 0)
  let edge_self = SparseSet(dense = [], sparse = [], values = [], count = 0)
  let resNom = recv_self.denseValues()
  let resEdge = edge_self.denseValues()
  assertEqInt(resNom.len(), 0, "denseValues nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "denseValues boundary resEdge.len() == 0")
  ret 0
```

---

### `spatialCellHash2D` (`std/collections/spatial_hash.aipl`)

- **Signature**: `pub fn spatialCellHash2D(cx: int, cy: int): int:`
- **Import**: `import * from "std/collections/spatial_hash"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cx: int, cy: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/collections/spatial_hash_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `spatialCellHash2D` (`free fn`) 2D spatial hash bucket hashing and cross-cell boundary `queryRadius` neighbor lookup. Concrete nominal inputs: `cx: int = 1`, `cy: int = 1`; exercises core body path returning/computing `(cx * 73856093) ^ (cy * 19349663)`.

```aipl
module tests.functions.collections.spatial_hash_z1_test
import * from "std/collections/spatial_hash"
import { floor } from "std/math/trig"
import { HashMap, hashMapNew } from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_spatial_hash_spatialCellHash2D_1(): int:
  let arg_cx = 1
  let edge_cx = 0
  let arg_cy = 1
  let edge_cy = 0
  let resNom = spatialCellHash2D(arg_cx, arg_cy)
  let resEdge = spatialCellHash2D(edge_cx, edge_cy)
  assertEqInt(resNom, 88192194, "spatialCellHash2D nominal resNom == 88192194")
  assertEqInt(resEdge, 0, "spatialCellHash2D boundary resEdge == 0")
  ret 0
```

---

### `spatialHash2DNew` (`std/collections/spatial_hash.aipl`)

- **Signature**: `pub fn spatialHash2DNew[T](cellSize: float): SpatialHashGrid2D[T]:`
- **Import**: `import * from "std/collections/spatial_hash"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cellSize: float` | **Returns**: `SpatialHashGrid2D[T]`
- **Unit Test**: `tests/functions/collections/spatial_hash_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `spatialHash2DNew` (`free fn`) 2D spatial hash bucket hashing and cross-cell boundary `queryRadius` neighbor lookup. Concrete nominal inputs: `cellSize: float = 1.0`; exercises core body path returning/computing `SpatialHashGrid2D(cellSize = cs, buckets = b, entries = e)`.

```aipl
module tests.functions.collections.spatial_hash_z2_test
import * from "std/collections/spatial_hash"
import { floor } from "std/math/trig"
import { HashMap, hashMapNew } from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_spatial_hash_spatialHash2DNew_2(): int:
  let arg_cellSize = 1.0
  let edge_cellSize = 0.5
  let resNom = spatialHash2DNew(arg_cellSize)
  let resEdge = spatialHash2DNew(edge_cellSize)
  assertApproxEq(resNom.cellSize, 1.0, 0.001, "spatialHash2DNew nominal resNom.cellSize ~= 1.0")
  assertApproxEq(resEdge.cellSize, 0.5, 0.001, "spatialHash2DNew boundary resEdge.cellSize ~= 0.5")
  ret 0
```

---

### `insert` (`std/collections/spatial_hash.aipl`)

- **Signature**: `pub fn (mut self: SpatialHashGrid2D[T]) insert(x: float, y: float, val: T): void:`
- **Import**: `import * from "std/collections/spatial_hash"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: SpatialHashGrid2D[T]` | **Parameters**: `x: float, y: float, val: T` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/spatial_hash_test.aipl` | **Example**: `examples/ex_044_collections_deque_sliding_window_cli.aipl`
- **Behavioral Summary**: Verify `insert` (`mut self: SpatialHashGrid2D[T]`) 2D spatial hash bucket hashing and cross-cell boundary `queryRadius` neighbor lookup. Concrete nominal inputs: receiver `recvObj: SpatialHashGrid2D[T] = SpatialHashGrid2D(cellSize = 1.0, buckets = HashMap(keys = [0], values = [0], ctrl = [0], capacity = 64, count = 64), entries = [SpatialHashEntry2D(x = 0, y = 0, val = 0)])`, `x: float = 1.0`, `y: float = 1.0`, `val: T = 42`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.spatial_hash_z3_test
import * from "std/collections/spatial_hash"
import { floor } from "std/math/trig"
import { HashMap, hashMapNew } from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_spatial_hash_SpatialHashGrid2D_T__insert_3(): int:
  let mut recv_self = SpatialHashGrid2D(cellSize = 1.0, buckets = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0), entries = [])
  let mut edge_self = SpatialHashGrid2D(cellSize = 0.5, buckets = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0), entries = [])
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_val = 1
  let edge_val = 0
  recv_self.insert(arg_x, arg_y, arg_val)
  edge_self.insert(edge_x, edge_y, edge_val)
  assertEqInt(recv_self.entries.len(), 1, "insert nominal recv_self.entries.len() == 1")
  assertEqInt(edge_self.entries.len(), 1, "insert boundary edge_self.entries.len() == 1")
  ret 0
```

---

### `queryRadius` (`std/collections/spatial_hash.aipl`)

- **Signature**: `pub fn (self: SpatialHashGrid2D[T]) queryRadius(x: float, y: float, radius: float): [T]:`
- **Import**: `import * from "std/collections/spatial_hash"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `self: SpatialHashGrid2D[T]` | **Parameters**: `x: float, y: float, radius: float` | **Returns**: `[T]`
- **Unit Test**: `tests/functions/collections/spatial_hash_test.aipl` | **Example**: `examples/ex_045_collections_hash_map_word_freq_cli.aipl`
- **Behavioral Summary**: Verify `queryRadius` (`self: SpatialHashGrid2D[T]`) 2D spatial hash bucket hashing and cross-cell boundary `queryRadius` neighbor lookup. Concrete nominal inputs: receiver `recvObj: SpatialHashGrid2D[T] = SpatialHashGrid2D(cellSize = 1.0, buckets = HashMap(keys = [0], values = [0], ctrl = [0], capacity = 64, count = 64), entries = [SpatialHashEntry2D(x = 0, y = 0, val = 0)])`, `x: float = 1.0`, `y: float = 1.0`, `radius: float = 1.0`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.collections.spatial_hash_z4_test
import * from "std/collections/spatial_hash"
import { floor } from "std/math/trig"
import { HashMap, hashMapNew } from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_spatial_hash_SpatialHashGrid2D_T__queryRadius_4(): int:
  let recv_self = SpatialHashGrid2D(cellSize = 1.0, buckets = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0), entries = [])
  let edge_self = SpatialHashGrid2D(cellSize = 0.5, buckets = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0), entries = [])
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_radius = 2.0
  let edge_radius = 1.0
  let resNom = recv_self.queryRadius(arg_x, arg_y, arg_radius)
  let resEdge = edge_self.queryRadius(edge_x, edge_y, edge_radius)
  assertEqInt(resNom.len(), 0, "queryRadius nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "queryRadius boundary resEdge.len() == 0")
  ret 0
```

---

### `clear` (`std/collections/spatial_hash.aipl`)

- **Signature**: `pub fn (mut self: SpatialHashGrid2D[T]) clear(): void:`
- **Import**: `import * from "std/collections/spatial_hash"` (or barrel `import * from "std/collections/collections_mod"`)
- **Receiver**: `mut self: SpatialHashGrid2D[T]` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/collections/spatial_hash_test.aipl` | **Example**: `examples/ex_043_collections_dyn_vec_and_sort_cli.aipl`
- **Behavioral Summary**: Verify `clear` (`mut self: SpatialHashGrid2D[T]`) 2D spatial hash bucket hashing and cross-cell boundary `queryRadius` neighbor lookup. Concrete nominal inputs: receiver `recvObj: SpatialHashGrid2D[T] = SpatialHashGrid2D(cellSize = 1.0, buckets = HashMap(keys = [0], values = [0], ctrl = [0], capacity = 64, count = 64), entries = [SpatialHashEntry2D(x = 0, y = 0, val = 0)])`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.collections.spatial_hash_z5_test
import * from "std/collections/spatial_hash"
import { floor } from "std/math/trig"
import { HashMap, hashMapNew } from "std/collections/hash_map"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_spatial_hash_SpatialHashGrid2D_T__clear_5(): int:
  let mut recv_self = SpatialHashGrid2D(cellSize = 1.0, buckets = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0), entries = [])
  let mut edge_self = SpatialHashGrid2D(cellSize = 0.5, buckets = HashMap(keys = [], values = [], ctrl = [], capacity = 4, count = 0), entries = [])
  recv_self.clear()
  edge_self.clear()
  assertApproxEq(recv_self.cellSize, 1.0, 0.0001, "clear nominal recv_self.cellSize approx 1.0")
  assertApproxEq(edge_self.cellSize, 0.5, 0.0001, "clear boundary edge_self.cellSize approx 0.5")
  ret 0
```
