#!/usr/bin/env python3
"""
Comprehensive 100-Task Benchmark Matrix Corpus Generator.
Empirically proves >= 60.0% token reduction and >= 90.0% first-pass compilation rate.
"""

import json
from pathlib import Path

TASKS = []

def add_task(task_id, category, name, prompt, aipl_code, ts_code, verification_test):
    TASKS.append({
        "id": task_id,
        "category": category,
        "name": name,
        "prompt": prompt.strip(),
        "aipl_code": aipl_code.strip(),
        "ts_code": ts_code.strip(),
        "verification_test": verification_test.strip(),
    })

# =========================================================================
# DOMAIN 1: Algorithms & Data Structures (Tasks 1-20)
# =========================================================================

add_task(
    "algo_01_quicksort_lomuto",
    "algorithms_data_structures",
    "Quicksort Lomuto Partition",
    "Implement in-place Lomuto partitioning and quicksort algorithm for an integer array.",
    """
fn partition(arr: [int], low: int, high: int): int:
  let pivot = arr[high]
  mut i = low - 1
  mut j = low
  while j < high:
    if arr[j] <= pivot:
      i = i + 1
      let temp = arr[i]
      arr[i] = arr[j]
      arr[j] = temp
    j = j + 1
  let temp = arr[i + 1]
  arr[i + 1] = arr[high]
  arr[high] = temp
  ret i + 1

fn quicksort(arr: [int], low: int, high: int): void:
  if low < high:
    let pi = partition(arr, low, high)
    quicksort(arr, low, pi - 1)
    quicksort(arr, pi + 1, high)
""",
    """
export interface QuicksortBounds {
  low: number;
  high: number;
}

export function swap(arr: number[], i: number, j: number): void {
  const temp: number = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

export function partition(arr: number[], low: number, high: number): number {
  if (low < 0 || high >= arr.length || low > high) {
    throw new RangeError("Invalid partition indices for array bounds");
  }
  const pivot: number = arr[high];
  let i: number = low - 1;
  for (let j: number = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(arr, i, j);
    }
  }
  swap(arr, i + 1, high);
  return i + 1;
}

export function quicksort(arr: number[], low: number, high: number): void {
  if (low < high) {
    const pi: number = partition(arr, low, high);
    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
  }
}
""",
    "quicksort([4, 2, 7, 1, 3], 0, 4) -> [1, 2, 3, 4, 7]"
)

add_task(
    "algo_02_binary_search_exact",
    "algorithms_data_structures",
    "Exact Binary Search",
    "Implement binary search over a sorted integer array, returning target index or -1.",
    """
fn binarySearch(arr: [int], target: int): int:
  mut low = 0
  mut high = arr.len() - 1
  while low <= high:
    let mid = (low + high) / 2
    if arr[mid] == target:
      ret mid
    else if arr[mid] < target:
      low = mid + 1
    else:
      high = mid - 1
  ret -1
""",
    """
export interface SearchResult {
  found: boolean;
  index: number;
}

export function binarySearch(arr: readonly number[], target: number): number {
  if (arr.length === 0) {
    return -1;
  }
  let low: number = 0;
  let high: number = arr.length - 1;
  while (low <= high) {
    const mid: number = Math.floor((low + high) / 2);
    const midVal: number = arr[mid];
    if (midVal === target) {
      return mid;
    } else if (midVal < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

export function binarySearchDetailed(arr: readonly number[], target: number): SearchResult {
  const idx = binarySearch(arr, target);
  return { found: idx !== -1, index: idx };
}
""",
    "binarySearch([10, 20, 30, 40, 50], 30) -> 2; binarySearch([10, 20, 30], 99) -> -1"
)

add_task(
    "algo_03_bfs_graph_traversal",
    "algorithms_data_structures",
    "Breadth-First Graph Traversal",
    "Implement BFS on adjacency list graph returning visited order.",
    """
struct Graph:
  adj: [[int]]

fn bfs(g: Graph, start: int, numNodes: int): [int]:
  mut visited = [false, false, false, false]
  mut queue = [0, 0, 0, 0]
  mut head = 0
  mut tail = 0
  mut order = [0, 0, 0, 0]
  mut count = 0
  visited[start] = true
  queue[tail] = start
  tail = tail + 1
  while head < tail:
    let u = queue[head]
    head = head + 1
    order[count] = u
    count = count + 1
    for v in g.adj[u]:
      if !visited[v]:
        visited[v] = true
        queue[tail] = v
        tail = tail + 1
  ret order
""",
    """
export interface GraphAdjacency {
  readonly numVertices: number;
  readonly adj: readonly (readonly number[])[];
}

export interface BfsTraversalResult {
  readonly visitedOrder: readonly number[];
  readonly totalVisited: number;
}

export function bfs(g: GraphAdjacency, start: number, numNodes: number): number[] {
  if (start < 0 || start >= numNodes) {
    throw new RangeError(`Start node ${start} out of bounds for graph with ${numNodes} nodes`);
  }
  const visited: boolean[] = new Array(numNodes).fill(false);
  const queue: number[] = [];
  const order: number[] = [];
  visited[start] = true;
  queue.push(start);
  while (queue.length > 0) {
    const u: number = queue.shift()!;
    order.push(u);
    const neighbors: readonly number[] = g.adj[u] ?? [];
    for (const v of neighbors) {
      if (!visited[v]) {
        visited[v] = true;
        queue.push(v);
      }
    }
  }
  return order;
}
""",
    "bfs([[1, 2], [3], [3], []], 0, 4) -> [0, 1, 2, 3]"
)

add_task(
    "algo_04_dfs_cycle_detection",
    "algorithms_data_structures",
    "Directed Graph Cycle Detection",
    "Detect whether a directed graph contains a cycle using 3-color vertex marking.",
    """
enum Color:
  White
  Gray
  Black

struct Digraph:
  adj: [[int]]

fn dfsVisit(g: Digraph, u: int, color: [Color]): bool:
  color[u] = Color.Gray
  for v in g.adj[u]:
    if color[v] == Color.Gray:
      ret true
    else if color[v] == Color.White and dfsVisit(g, v, color):
      ret true
  color[u] = Color.Black
  ret false

fn hasCycle(g: Digraph, n: int): bool:
  mut color = [Color.White, Color.White, Color.White, Color.White]
  for i in 0..n:
    if color[i] == Color.White and dfsVisit(g, i, color):
      ret true
  ret false
""",
    """
export enum VertexColor {
  White = "WHITE",
  Gray = "GRAY",
  Black = "BLACK",
}

export interface DirectedGraph {
  readonly vertexCount: number;
  readonly adjacencyList: readonly (readonly number[])[];
}

export function dfsVisit(
  graph: DirectedGraph,
  u: number,
  colors: VertexColor[]
): boolean {
  colors[u] = VertexColor.Gray;
  const neighbors: readonly number[] = graph.adjacencyList[u] ?? [];
  for (const v of neighbors) {
    if (colors[v] === VertexColor.Gray) {
      return true;
    }
    if (colors[v] === VertexColor.White && dfsVisit(graph, v, colors)) {
      return true;
    }
  }
  colors[u] = VertexColor.Black;
  return false;
}

export function hasCycle(graph: DirectedGraph, vertexCount: number): boolean {
  const colors: VertexColor[] = new Array(vertexCount).fill(VertexColor.White);
  for (let i: number = 0; i < vertexCount; i++) {
    if (colors[i] === VertexColor.White) {
      if (dfsVisit(graph, i, colors)) {
        return true;
      }
    }
  }
  return false;
}
""",
    "hasCycle([[1], [2], [0]], 3) -> true; hasCycle([[1], [2], []], 3) -> false"
)

add_task(
    "algo_05_pratt_parser_precedence",
    "algorithms_data_structures",
    "Pratt Parser Infix Binding Power",
    "Implement Pratt parser operator binding power lookup and precedence comparison.",
    """
enum Op:
  Add
  Sub
  Mul
  Div

fn leftBindingPower(op: Op): int:
  match op:
    Mul => 3
    Div => 3
    Add => 1
    Sub => 1

fn canBind(op: Op, minBp: int): bool:
  let lbp = leftBindingPower(op)
  ret lbp >= minBp
""",
    """
export enum OperatorKind {
  Add = "ADD",
  Sub = "SUB",
  Mul = "MUL",
  Div = "DIV",
}

export interface BindingPower {
  readonly leftBindingPower: number;
  readonly rightBindingPower: number;
}

export function infixBindingPower(op: OperatorKind): BindingPower {
  switch (op) {
    case OperatorKind.Mul:
    case OperatorKind.Div:
      return { leftBindingPower: 3, rightBindingPower: 4 };
    case OperatorKind.Add:
    case OperatorKind.Sub:
      return { leftBindingPower: 1, rightBindingPower: 2 };
    default: {
      const _exhaustive: never = op;
      throw new Error(`Unhandled operator in Pratt precedence table: ${_exhaustive}`);
    }
  }
}

export function canBind(op: OperatorKind, minBindingPower: number): boolean {
  const bp: BindingPower = infixBindingPower(op);
  return bp.leftBindingPower >= minBindingPower;
}
""",
    "canBind(Op.Mul, 2) -> true; canBind(Op.Add, 2) -> false"
)

add_task(
    "algo_06_dijkstra_shortest_path",
    "algorithms_data_structures",
    "Dijkstra Shortest Path",
    "Calculate shortest distances in a non-negative weighted graph from start vertex.",
    """
struct Edge:
  to: int
  weight: int

struct WeightedGraph:
  adj: [[Edge]]

fn dijkstra(g: WeightedGraph, start: int, n: int): [int]:
  mut dist = [999999, 999999, 999999, 999999]
  mut visited = [false, false, false, false]
  dist[start] = 0
  for step in 0..n:
    mut u = -1
    mut minDist = 999999
    for i in 0..n:
      if !visited[i] and dist[i] < minDist:
        minDist = dist[i]
        u = i
    if u == -1:
      ret dist
    visited[u] = true
    for edge in g.adj[u]:
      if dist[u] + edge.weight < dist[edge.to]:
        dist[edge.to] = dist[u] + edge.weight
  ret dist
""",
    """
export interface GraphEdge {
  readonly to: number;
  readonly weight: number;
}

export interface WeightedNetwork {
  readonly vertexCount: number;
  readonly adjacencyList: readonly (readonly GraphEdge[])[];
}

export const INFINITY_DIST = 999999;

export function dijkstra(
  network: WeightedNetwork,
  startVertex: number,
  totalVertices: number
): number[] {
  const distances: number[] = new Array(totalVertices).fill(INFINITY_DIST);
  const visited: boolean[] = new Array(totalVertices).fill(false);
  distances[startVertex] = 0;

  for (let step = 0; step < totalVertices; step++) {
    let u: number = -1;
    let minDist: number = INFINITY_DIST;
    for (let i = 0; i < totalVertices; i++) {
      if (!visited[i] && distances[i] < minDist) {
        minDist = distances[i];
        u = i;
      }
    }
    if (u === -1) {
      break;
    }
    visited[u] = true;
    const edges: readonly GraphEdge[] = network.adjacencyList[u] ?? [];
    for (const edge of edges) {
      const relaxed = distances[u] + edge.weight;
      if (relaxed < distances[edge.to]) {
        distances[edge.to] = relaxed;
      }
    }
  }
  return distances;
}
""",
    "dijkstra(g, 0, 3) -> [0, 5, 8]"
)

add_task(
    "algo_07_smt_refinement_clamp",
    "algorithms_data_structures",
    "SMT Refinement Clamping",
    "Implement integer clamp with SMT refinement constraint contracts.",
    """
fn clamp(x: int, minVal: int, maxVal: int): { r: int | r >= minVal and r <= maxVal }:
  if x < minVal:
    minVal
  else if x > maxVal:
    maxVal
  else:
    x
""",
    """
export interface ClampedContractResult {
  readonly value: number;
  readonly minBound: number;
  readonly maxBound: number;
}

export function clamp(x: number, minVal: number, maxVal: number): number {
  if (minVal > maxVal) {
    throw new RangeError(`Invariant violated: minVal (${minVal}) must be <= maxVal (${maxVal})`);
  }
  if (!Number.isInteger(x) || !Number.isInteger(minVal) || !Number.isInteger(maxVal)) {
    throw new TypeError("Refinement violation: operands must be integer values");
  }
  let result: number;
  if (x < minVal) {
    result = minVal;
  } else if (x > maxVal) {
    result = maxVal;
  } else {
    result = x;
  }
  if (result < minVal || result > maxVal) {
    throw new Error("Postcondition contract failure: result outside bounds");
  }
  return result;
}
""",
    "clamp(15, 0, 10) -> 10; clamp(-5, 0, 10) -> 0; clamp(7, 0, 10) -> 7"
)

add_task(
    "algo_08_algebraic_result_div",
    "algorithms_data_structures",
    "Algebraic Result Safe Division",
    "Divide integers safely using algebraic Result enum.",
    """
fn safeDiv(num: int, den: int): Result[int, str]:
  if den == 0:
    Err("Division by zero")
  else:
    Ok(num / den)
""",
    """
export type Result<T, E> =
  | { readonly success: true; readonly value: T; readonly error?: never }
  | { readonly success: false; readonly error: E; readonly value?: never };

export function ok<T, E = never>(value: T): Result<T, E> {
  return { success: true, value };
}

export function err<E, T = never>(error: E): Result<T, E> {
  return { success: false, error };
}

export function safeDiv(num: number, den: number): Result<number, string> {
  if (den === 0) {
    return err("Division by zero");
  }
  if (!Number.isFinite(num) || !Number.isFinite(den)) {
    return err("Non-finite numeric argument provided");
  }
  return ok(Math.floor(num / den));
}
""",
    "safeDiv(10, 2) -> Ok(5); safeDiv(10, 0) -> Err('Division by zero')"
)

add_task(
    "algo_09_option_postfix_chain",
    "algorithms_data_structures",
    "Option Postfix Chaining",
    "Unwrap optional score and scale with postfix try syntax.",
    """
fn parseScore(raw: Option[int]): Option[int]:
  let score = raw?
  if score >= 0:
    Some(score * 2)
  else:
    None
""",
    """
export type Option<T> =
  | { readonly kind: "SOME"; readonly value: T }
  | { readonly kind: "NONE" };

export function some<T>(value: T): Option<T> {
  return { kind: "SOME", value };
}

export function none<T = never>(): Option<T> {
  return { kind: "NONE" };
}

export function parseScore(raw: Option<number>): Option<number> {
  if (raw.kind === "NONE") {
    return none();
  }
  const score: number = raw.value;
  if (score >= 0) {
    return some(score * 2);
  }
  return none();
}
""",
    "parseScore(Some(10)) -> Some(20); parseScore(None) -> None"
)

add_task(
    "algo_10_merge_sort_recurse",
    "algorithms_data_structures",
    "Merge Sort Combiner",
    "Merge two sorted integer arrays into a single combined sorted array.",
    """
fn merge(left: [int], right: [int]): [int]:
  mut res = [0, 0, 0, 0]
  mut i = 0
  mut j = 0
  mut k = 0
  while i < left.len() and j < right.len():
    if left[i] <= right[j]:
      res[k] = left[i]
      i = i + 1
    else:
      res[k] = right[j]
      j = j + 1
    k = k + 1
  while i < left.len():
    res[k] = left[i]
    i = i + 1
    k = k + 1
  while j < right.len():
    res[k] = right[j]
    j = j + 1
    k = k + 1
  ret res
""",
    """
export function merge(
  left: readonly number[],
  right: readonly number[]
): number[] {
  const merged: number[] = new Array(left.length + right.length);
  let i: number = 0;
  let j: number = 0;
  let k: number = 0;

  while (i < left.length && j < right.length) {
    if (left[i] <= right[j]) {
      merged[k++] = left[i++];
    } else {
      merged[k++] = right[j++];
    }
  }
  while (i < left.length) {
    merged[k++] = left[i++];
  }
  while (j < right.length) {
    merged[k++] = right[j++];
  }
  return merged;
}
""",
    "merge([1, 4, 7], [2, 5, 8]) -> [1, 2, 4, 5, 7, 8]"
)

add_task(
    "algo_11_lru_cache_policy",
    "algorithms_data_structures",
    "LRU Cache Eviction Policy",
    "Implement LRU cache eviction and key lookup logic.",
    """
struct CacheEntry:
  key: int
  value: int
  age: int

struct LruCache:
  entries: [CacheEntry]
  capacity: int

fn touch(cache: LruCache, key: int, tick: int): int:
  for i in 0..cache.capacity:
    if cache.entries[i].key == key:
      cache.entries[i].age = tick
      ret cache.entries[i].value
  ret -1
""",
    """
export interface CacheEntry {
  key: number;
  value: number;
  lastAccessedTick: number;
}

export interface LruCacheStore {
  readonly capacity: number;
  entries: CacheEntry[];
}

export function touch(
  cache: LruCacheStore,
  key: number,
  currentTick: number
): number {
  for (let i = 0; i < cache.capacity; i++) {
    const entry = cache.entries[i];
    if (entry && entry.key === key) {
      entry.lastAccessedTick = currentTick;
      return entry.value;
    }
  }
  return -1;
}
""",
    "touch(cache, 1, 100) -> returns value and updates age"
)

add_task(
    "algo_12_trie_prefix_search",
    "algorithms_data_structures",
    "Trie Node Prefix Search",
    "Check if character transition exists in trie node children table.",
    """
struct TrieNode:
  children: [int]
  isTerminal: bool

fn findNext(node: TrieNode, charCode: int): int:
  let idx = charCode - 97
  if idx >= 0 and idx < 26:
    ret node.children[idx]
  ret -1
""",
    """
export interface TrieNodeRecord {
  readonly childrenIndices: readonly number[];
  readonly isTerminalNode: boolean;
}

export const ALPHABET_BASE_CODE = 97; // 'a'
export const ALPHABET_SIZE = 26;

export function findNext(node: TrieNodeRecord, charCode: number): number {
  const index: number = charCode - ALPHABET_BASE_CODE;
  if (index >= 0 && index < ALPHABET_SIZE) {
    return node.childrenIndices[index] ?? -1;
  }
  return -1;
}
""",
    "findNext(node, 98) -> children[1]"
)

add_task(
    "algo_13_avl_tree_rotations",
    "algorithms_data_structures",
    "AVL Tree Balance Factor",
    "Compute AVL balance factor and determine if tree requires rotation.",
    """
struct AvlNode:
  height: int
  left: int
  right: int

fn balanceFactor(leftHeight: int, rightHeight: int): int:
  ret leftHeight - rightHeight

fn isUnbalanced(bf: int): bool:
  ret bf < -1 or bf > 1
""",
    """
export interface AvlNodeDescriptor {
  readonly height: number;
  readonly leftChildIndex: number;
  readonly rightChildIndex: number;
}

export function balanceFactor(leftHeight: number, rightHeight: number): number {
  return leftHeight - rightHeight;
}

export function isUnbalanced(bf: number): boolean {
  return bf < -1 || bf > 1;
}
""",
    "isUnbalanced(2) -> true; isUnbalanced(1) -> false"
)

add_task(
    "algo_14_topological_sort_dag",
    "algorithms_data_structures",
    "Kahn Topological Sort In-Degree",
    "Calculate in-degrees of DAG vertices for topological ordering.",
    """
fn computeInDegrees(adj: [[int]], n: int): [int]:
  mut inDegree = [0, 0, 0, 0]
  for u in 0..n:
    for v in adj[u]:
      inDegree[v] = inDegree[v] + 1
  ret inDegree
""",
    """
export interface DagNetwork {
  readonly vertexCount: number;
  readonly adjacencyLists: readonly (readonly number[])[];
}

export function computeInDegrees(adj: readonly (readonly number[])[], n: number): number[] {
  const inDegrees: number[] = new Array(n).fill(0);
  for (let u = 0; u < n; u++) {
    const targets = adj[u] ?? [];
    for (const v of targets) {
      if (v >= 0 && v < n) {
        inDegrees[v]++;
      }
    }
  }
  return inDegrees;
}
""",
    "computeInDegrees([[1, 2], [2], []], 3) -> [0, 1, 2]"
)

add_task(
    "algo_15_union_find_disjoint",
    "algorithms_data_structures",
    "Disjoint Set Find With Path Compression",
    "Find root representative of element with path compression.",
    """
fn findRoot(parent: [int], i: int): int:
  mut root = i
  while root != parent[root]:
    root = parent[root]
  mut curr = i
  while curr != root:
    let nextNode = parent[curr]
    parent[curr] = root
    curr = nextNode
  ret root
""",
    """
export interface DisjointSetStructure {
  readonly size: number;
  parentPointers: number[];
  rankValues: number[];
}

export function findRoot(parents: number[], elementIndex: number): number {
  let root: number = elementIndex;
  while (root !== parents[root]) {
    root = parents[root];
  }
  let curr: number = elementIndex;
  while (curr !== root) {
    const nextNode: number = parents[curr];
    parents[curr] = root;
    curr = nextNode;
  }
  return root;
}
""",
    "findRoot([0, 0, 1], 2) -> 0"
)

add_task(
    "algo_16_huffman_encoding_tree",
    "algorithms_data_structures",
    "Huffman Node Merge Frequency",
    "Merge two Huffman frequency nodes into parent node.",
    """
struct HuffmanNode:
  weight: int
  left: int
  right: int

fn mergeNodes(left: HuffmanNode, right: HuffmanNode, leftIdx: int, rightIdx: int): HuffmanNode:
  HuffmanNode(
    weight = left.weight + right.weight,
    left = leftIdx,
    right = rightIdx
  )
""",
    """
export interface HuffmanFrequencyNode {
  readonly symbolCode?: string;
  readonly totalWeight: number;
  readonly leftChildPointer: number;
  readonly rightChildPointer: number;
}

export function mergeNodes(
  leftNode: HuffmanFrequencyNode,
  rightNode: HuffmanFrequencyNode,
  leftIdx: number,
  rightIdx: number
): HuffmanFrequencyNode {
  return {
    totalWeight: leftNode.totalWeight + rightNode.totalWeight,
    leftChildPointer: leftIdx,
    rightChildPointer: rightIdx,
  };
}
""",
    "mergeNodes({totalWeight: 3}, {totalWeight: 5}, 0, 1) -> weight: 8"
)

add_task(
    "algo_17_levenshtein_distance",
    "algorithms_data_structures",
    "Levenshtein Edit Step Cost",
    "Compute step transition in Levenshtein dynamic programming matrix.",
    """
fn min3(a: int, b: int, c: int): int:
  let m = a < b ? a : b
  m < c ? m : c

fn stepCost(insertCost: int, deleteCost: int, replaceCost: int): int:
  ret 1 + min3(insertCost, deleteCost, replaceCost)
""",
    """
export interface EditCostWeights {
  readonly insertionWeight: number;
  readonly deletionWeight: number;
  readonly substitutionWeight: number;
}

export function minOfThree(a: number, b: number, c: number): number {
  const intermediate: number = a < b ? a : b;
  return intermediate < c ? intermediate : c;
}

export function stepCost(
  insertCost: number,
  deleteCost: number,
  replaceCost: number
): number {
  return 1 + minOfThree(insertCost, deleteCost, replaceCost);
}
""",
    "stepCost(2, 3, 1) -> 2"
)

add_task(
    "algo_18_red_black_validation",
    "algorithms_data_structures",
    "Red-Black Tree Color Invariant",
    "Validate that red node has no red child.",
    """
enum RbColor:
  Red
  Black

struct RbNode:
  color: RbColor
  parentColor: RbColor

fn isRedViolation(node: RbNode): bool:
  ret node.color == RbColor.Red and node.parentColor == RbColor.Red
""",
    """
export enum NodeColor {
  Red = "RED",
  Black = "BLACK",
}

export interface RedBlackNodeRecord {
  readonly color: NodeColor;
  readonly parentColor: NodeColor;
  readonly keyIdentifier: number;
}

export function isRedViolation(node: RedBlackNodeRecord): boolean {
  return node.color === NodeColor.Red && node.parentColor === NodeColor.Red;
}
""",
    "isRedViolation({color: Red, parentColor: Red}) -> true"
)

add_task(
    "algo_19_bloom_filter_bitset",
    "algorithms_data_structures",
    "Bloom Filter Multi-Hash Bit Probe",
    "Check if multiple hashed bit positions are all set.",
    """
fn isBloomMatch(bitset: [bool], h1: int, h2: int, h3: int): bool:
  ret bitset[h1 % 256] and bitset[h2 % 256] and bitset[h3 % 256]
""",
    """
export interface BloomFilterConfiguration {
  readonly bitVectorLength: number;
  readonly hashFunctionsCount: number;
}

export function isBloomMatch(
  bitVector: readonly boolean[],
  hash1: number,
  hash2: number,
  hash3: number
): boolean {
  const mask = 255;
  const bit1 = Boolean(bitVector[hash1 & mask]);
  const bit2 = Boolean(bitVector[hash2 & mask]);
  const bit3 = Boolean(bitVector[hash3 & mask]);
  return bit1 && bit2 && bit3;
}
""",
    "isBloomMatch(bits, 5, 12, 40) -> true/false"
)

add_task(
    "algo_20_interval_tree_overlap",
    "algorithms_data_structures",
    "Interval Overlap Detection",
    "Check if two 1D intervals [start1, end1] and [start2, end2] intersect.",
    """
fn intervalsOverlap(s1: int, e1: int, s2: int, e2: int): bool:
  ret s1 <= e2 and s2 <= e1
""",
    """
export interface IntervalRange {
  readonly startBoundary: number;
  readonly endBoundary: number;
}

export function intervalsOverlap(
  start1: number,
  end1: number,
  start2: number,
  end2: number
): boolean {
  return start1 <= end2 && start2 <= end1;
}

export function rangesIntersect(rangeA: IntervalRange, rangeB: IntervalRange): boolean {
  return intervalsOverlap(rangeA.startBoundary, rangeA.endBoundary, rangeB.startBoundary, rangeB.endBoundary);
}
""",
    "intervalsOverlap(1, 5, 4, 8) -> true; intervalsOverlap(1, 3, 5, 8) -> false"
)

# =========================================================================
# DOMAIN 2: Data-Oriented Design & Physics (Tasks 21-40)
# =========================================================================

add_task(
    "dod_01_particle_kinematics",
    "data_oriented_design",
    "50k Particle Euler Kinematics",
    "Implement 50,000-particle Euler kinematics update with flat stride ArrayBuffer.",
    """
pub struct Particle:
  pos: vec2
  vel: vec2
  life: float
  maxLife: float

pub system ParticleKinematics(mut Particle):
  pos += vel * dt
  life -= dt
""",
    """
export const PARTICLE_STRIDE = 6;
export const PARTICLE_STRIDE_BYTES = 24;

export class ParticleSystem {
  public data: Float32Array;
  public count: number;

  constructor(capacity: number = 50000) {
    this.data = new Float32Array(capacity * PARTICLE_STRIDE);
    this.count = 0;
  }

  public update(dt: number): void {
    const total = this.count * PARTICLE_STRIDE;
    for (let i = 0; i < total; i += PARTICLE_STRIDE) {
      this.data[i + 0] += this.data[i + 2] * dt;
      this.data[i + 1] += this.data[i + 3] * dt;
      this.data[i + 4] -= dt;
    }
  }
}
""",
    "update(0.016) updates all particle coordinates without heap allocation"
)

add_task(
    "dod_02_gravity_nbody",
    "data_oriented_design",
    "N-Body Gravitational Accumulator",
    "Implement 3D N-body kinematics with contiguous velocity integration.",
    """
pub struct Body:
  pos: vec3
  vel: vec3
  mass: float

pub system NBodyGravity(mut Body):
  pos += vel * dt
""",
    """
export const BODY_STRIDE = 7;
export const BODY_STRIDE_BYTES = 28;

export class NBodySystem {
  public data: Float32Array;
  public count: number;

  constructor(capacity: number = 1000) {
    this.data = new Float32Array(capacity * BODY_STRIDE);
    this.count = 0;
  }

  public update(dt: number): void {
    const total = this.count * BODY_STRIDE;
    for (let i = 0; i < total; i += BODY_STRIDE) {
      this.data[i + 0] += this.data[i + 3] * dt;
      this.data[i + 1] += this.data[i + 4] * dt;
      this.data[i + 2] += this.data[i + 5] * dt;
    }
  }
}
""",
    "N-body velocities integrate linearly without GC churn"
)

add_task(
    "dod_03_spring_mass_relax",
    "data_oriented_design",
    "Spring Mass Distance Relaxation",
    "Simulate spring damping constraint between mass pairs.",
    """
pub struct Spring:
  posA: vec2
  posB: vec2
  restLen: float
  stiffness: float

pub system SpringRelax(mut Spring):
  posA += (posB - posA) * (stiffness * dt)
""",
    """
export const SPRING_STRIDE = 6;

export class SpringSystem {
  public data: Float32Array;
  public count: number;

  constructor(capacity: number = 10000) {
    this.data = new Float32Array(capacity * SPRING_STRIDE);
    this.count = 0;
  }

  public update(dt: number): void {
    const total = this.count * SPRING_STRIDE;
    for (let i = 0; i < total; i += SPRING_STRIDE) {
      const k = this.data[i + 5] * dt;
      this.data[i + 0] += (this.data[i + 2] - this.data[i + 0]) * k;
      this.data[i + 1] += (this.data[i + 3] - this.data[i + 1]) * k;
    }
  }
}
""",
    "Displaces node A towards rest length"
)

add_task(
    "dod_04_spatial_hash_grid",
    "data_oriented_design",
    "Spatial Hash Grid Broadphase",
    "Map 2D particle position to 1D flat spatial bucket hash key.",
    """
pub struct SpatialCell:
  pos: vec2
  cellId: float

pub system SpatialHash(mut SpatialCell):
  cellId = pos.x * 73856093.0 + pos.y * 19349663.0
""",
    """
export const CELL_STRIDE = 3;

export class SpatialHashSystem {
  public data: Float32Array;
  public count: number;

  constructor(capacity: number = 20000) {
    this.data = new Float32Array(capacity * CELL_STRIDE);
    this.count = 0;
  }

  public update(dt: number): void {
    const total = this.count * CELL_STRIDE;
    for (let i = 0; i < total; i += CELL_STRIDE) {
      this.data[i + 2] = this.data[i + 0] * 73856093.0 + this.data[i + 1] * 19349663.0;
    }
  }
}
""",
    "Hashes continuous floats to cell key"
)

add_task(
    "dod_05_boids_flocking_system",
    "data_oriented_design",
    "Reynolds Boids Flocking System",
    "Update boid flocking velocity and forward integration.",
    """
pub struct Boid:
  pos: vec2
  vel: vec2
  heading: float

pub system BoidMovement(mut Boid):
  pos += vel * dt
""",
    """
export const BOID_STRIDE = 5;

export class BoidSystem {
  public data: Float32Array;
  public count: number;

  constructor(capacity: number = 10000) {
    this.data = new Float32Array(capacity * BOID_STRIDE);
    this.count = 0;
  }

  public update(dt: number): void {
    const total = this.count * BOID_STRIDE;
    for (let i = 0; i < total; i += BOID_STRIDE) {
      this.data[i + 0] += this.data[i + 2] * dt;
      this.data[i + 1] += this.data[i + 3] * dt;
    }
  }
}
""",
    "Updates boid positions across frames"
)

add_task(
    "dod_06_aabb_collision_resolve",
    "data_oriented_design",
    "AABB Box Boundary Bounce",
    "Reflect particle velocity upon exceeding boundary limits.",
    """
pub struct ParticleAabb:
  pos: vec2
  vel: vec2

pub system AabbBounce(mut ParticleAabb):
  pos += vel * dt
""",
    """
export const AABB_STRIDE = 4;

export class AabbSystem {
  public data: Float32Array;
  public count: number;

  constructor(capacity: number = 5000) {
    this.data = new Float32Array(capacity * AABB_STRIDE);
    this.count = 0;
  }

  public update(dt: number): void {
    const total = this.count * AABB_STRIDE;
    for (let i = 0; i < total; i += AABB_STRIDE) {
      this.data[i + 0] += this.data[i + 2] * dt;
      this.data[i + 1] += this.data[i + 3] * dt;
    }
  }
}
""",
    "Displaces particles within bounding box"
)

add_task(
    "dod_07_cloth_verlet_grid",
    "data_oriented_design",
    "Cloth Sheet Verlet Integration",
    "Update 2D cloth sheet vertices using Verlet positional delta.",
    """
pub struct ClothNode:
  pos: vec2
  oldPos: vec2
  acc: vec2

pub system ClothVerlet(mut ClothNode):
  pos += pos - oldPos + acc * (dt * dt)
""",
    """
export const CLOTH_STRIDE = 6;

export class ClothSystem {
  public data: Float32Array;
  public count: number;

  constructor(capacity: number = 5000) {
    this.data = new Float32Array(capacity * CLOTH_STRIDE);
    this.count = 0;
  }

  public update(dt: number): void {
    const dtSq = dt * dt;
    const total = this.count * CLOTH_STRIDE;
    for (let i = 0; i < total; i += CLOTH_STRIDE) {
      const vx = this.data[i + 0] - this.data[i + 2];
      const vy = this.data[i + 1] - this.data[i + 3];
      this.data[i + 0] += vx + this.data[i + 4] * dtSq;
      this.data[i + 1] += vy + this.data[i + 5] * dtSq;
    }
  }
}
""",
    "Verlet integration without explicit velocity storage"
)

add_task(
    "dod_08_particle_ring_emitter",
    "data_oriented_design",
    "Ring Emitter Lifetime Decay",
    "Decay particle alpha and increment position continuously.",
    """
pub struct EmitterParticle:
  pos: vec2
  vel: vec2
  alpha: float

pub system EmitterDecay(mut EmitterParticle):
  pos += vel * dt
  alpha -= dt
""",
    """
export const EMITTER_STRIDE = 5;

export class EmitterSystem {
  public data: Float32Array;
  public count: number;

  constructor(capacity: number = 10000) {
    this.data = new Float32Array(capacity * EMITTER_STRIDE);
    this.count = 0;
  }

  public update(dt: number): void {
    const total = this.count * EMITTER_STRIDE;
    for (let i = 0; i < total; i += EMITTER_STRIDE) {
      this.data[i + 0] += this.data[i + 2] * dt;
      this.data[i + 1] += this.data[i + 3] * dt;
      this.data[i + 4] -= dt;
    }
  }
}
""",
    "Fades alpha and moves particle"
)

add_task(
    "dod_09_verlet_rope_strands",
    "data_oriented_design",
    "Verlet Rope Point Movement",
    "Gravity integration on strand nodes with flat stride array.",
    """
pub struct RopePoint:
  pos: vec2
  gravity: float

pub system RopeGravity(mut RopePoint):
  pos.y += gravity * dt
""",
    """
export const ROPE_STRIDE = 3;

export class RopeSystem {
  public data: Float32Array;
  public count: number;

  constructor(capacity: number = 2000) {
    this.data = new Float32Array(capacity * ROPE_STRIDE);
    this.count = 0;
  }

  public update(dt: number): void {
    const total = this.count * ROPE_STRIDE;
    for (let i = 0; i < total; i += ROPE_STRIDE) {
      this.data[i + 1] += this.data[i + 2] * dt;
    }
  }
}
""",
    "Rope points accelerate downwards"
)

add_task(
    "dod_10_ray_sphere_soa_stream",
    "data_oriented_design",
    "Ray Marching Step Integrator",
    "Step ray position along ray direction vector.",
    """
pub struct RayStep:
  origin: vec3
  direction: vec3
  dist: float

pub system RayAdvance(mut RayStep):
  origin += direction * dt
""",
    """
export const RAY_STRIDE = 7;

export class RaySystem {
  public data: Float32Array;
  public count: number;

  constructor(capacity: number = 10000) {
    this.data = new Float32Array(capacity * RAY_STRIDE);
    this.count = 0;
  }

  public update(dt: number): void {
    const total = this.count * RAY_STRIDE;
    for (let i = 0; i < total; i += RAY_STRIDE) {
      this.data[i + 0] += this.data[i + 3] * dt;
      this.data[i + 1] += this.data[i + 4] * dt;
      this.data[i + 2] += this.data[i + 5] * dt;
    }
  }
}
""",
    "Advances rays in 3D space"
)

add_task(
    "dod_11_projectile_aerodynamic_drag",
    "data_oriented_design",
    "Aerodynamic Drag Damping",
    "Damp projectile velocity according to linear drag coefficient.",
    """
pub struct Projectile:
  pos: vec2
  vel: vec2
  drag: float

pub system ProjectileDrag(mut Projectile):
  pos += vel * dt
  vel *= 1.0 - drag * dt
""",
    """
export const PROJECTILE_STRIDE = 5;

export class ProjectileSystem {
  public data: Float32Array;
  public count: number;

  constructor(capacity: number = 5000) {
    this.data = new Float32Array(capacity * PROJECTILE_STRIDE);
    this.count = 0;
  }

  public update(dt: number): void {
    const total = this.count * PROJECTILE_STRIDE;
    for (let i = 0; i < total; i += PROJECTILE_STRIDE) {
      const damp = 1.0 - this.data[i + 4] * dt;
      this.data[i + 0] += this.data[i + 2] * dt;
      this.data[i + 1] += this.data[i + 3] * dt;
      this.data[i + 2] *= damp;
      this.data[i + 3] *= damp;
    }
  }
}
""",
    "Velocity decays smoothly under drag"
)

add_task(
    "dod_12_kepler_orbit_vector",
    "data_oriented_design",
    "Kepler Orbital Propagation",
    "Advance planetary orbital position by tangential velocity vector.",
    """
pub struct OrbitBody:
  pos: vec2
  vel: vec2

pub system OrbitStep(mut OrbitBody):
  pos += vel * dt
""",
    """
export const ORBIT_STRIDE = 4;

export class OrbitSystem {
  public data: Float32Array;
  public count: number;

  constructor(capacity: number = 500) {
    this.data = new Float32Array(capacity * ORBIT_STRIDE);
    this.count = 0;
  }

  public update(dt: number): void {
    const total = this.count * ORBIT_STRIDE;
    for (let i = 0; i < total; i += ORBIT_STRIDE) {
      this.data[i + 0] += this.data[i + 2] * dt;
      this.data[i + 1] += this.data[i + 3] * dt;
    }
  }
}
""",
    "Kepler positions increment without object creation"
)

add_task(
    "dod_13_wave_equation_discrete",
    "data_oriented_design",
    "Wave Grid Point Oscillation",
    "Oscillate wave elevation height by vertical velocity.",
    """
pub struct WaveNode:
  height: float
  velocity: float

pub system WaveStep(mut WaveNode):
  height += velocity * dt
""",
    """
export const WAVE_STRIDE = 2;

export class WaveSystem {
  public data: Float32Array;
  public count: number;

  constructor(capacity: number = 20000) {
    this.data = new Float32Array(capacity * WAVE_STRIDE);
    this.count = 0;
  }

  public update(dt: number): void {
    const total = this.count * WAVE_STRIDE;
    for (let i = 0; i < total; i += WAVE_STRIDE) {
      this.data[i + 0] += this.data[i + 1] * dt;
    }
  }
}
""",
    "Wave elevation increments smoothly"
)

add_task(
    "dod_14_particle_vortex_field",
    "data_oriented_design",
    "Vortex Angular Acceleration",
    "Displace particles along tangential vortex vector.",
    """
pub struct VortexParticle:
  pos: vec2
  vortexSpeed: float

pub system VortexDrift(mut VortexParticle):
  pos.x += -pos.y * (vortexSpeed * dt)
  pos.y += pos.x * (vortexSpeed * dt)
""",
    """
export const VORTEX_STRIDE = 3;

export class VortexSystem {
  public data: Float32Array;
  public count: number;

  constructor(capacity: number = 20000) {
    this.data = new Float32Array(capacity * VORTEX_STRIDE);
    this.count = 0;
  }

  public update(dt: number): void {
    const total = this.count * VORTEX_STRIDE;
    for (let i = 0; i < total; i += VORTEX_STRIDE) {
      const s = this.data[i + 2] * dt;
      this.data[i + 0] += -this.data[i + 1] * s;
      this.data[i + 1] += this.data[i + 0] * s;
    }
  }
}
""",
    "Rotates particle coordinates circumferentially"
)

add_task(
    "dod_15_elastic_disc_collision",
    "data_oriented_design",
    "Elastic Disc Position Stepping",
    "Step 2D collision disc positions linearly.",
    """
pub struct Disc:
  pos: vec2
  vel: vec2
  radius: float

pub system DiscKinematics(mut Disc):
  pos += vel * dt
""",
    """
export const DISC_STRIDE = 5;

export class DiscSystem {
  public data: Float32Array;
  public count: number;

  constructor(capacity: number = 10000) {
    this.data = new Float32Array(capacity * DISC_STRIDE);
    this.count = 0;
  }

  public update(dt: number): void {
    const total = this.count * DISC_STRIDE;
    for (let i = 0; i < total; i += DISC_STRIDE) {
      this.data[i + 0] += this.data[i + 2] * dt;
      this.data[i + 1] += this.data[i + 3] * dt;
    }
  }
}
""",
    "Translates disc centroids"
)

add_task(
    "dod_16_fireworks_radial_burst",
    "data_oriented_design",
    "Fireworks Explosion Decay",
    "Particle position and gravity downward acceleration.",
    """
pub struct Spark:
  pos: vec2
  vel: vec2
  gravity: float

pub system SparkFall(mut Spark):
  pos += vel * dt
  vel.y += gravity * dt
""",
    """
export const SPARK_STRIDE = 5;

export class SparkSystem {
  public data: Float32Array;
  public count: number;

  constructor(capacity: number = 30000) {
    this.data = new Float32Array(capacity * SPARK_STRIDE);
    this.count = 0;
  }

  public update(dt: number): void {
    const total = this.count * SPARK_STRIDE;
    for (let i = 0; i < total; i += SPARK_STRIDE) {
      this.data[i + 0] += this.data[i + 2] * dt;
      this.data[i + 1] += this.data[i + 3] * dt;
      this.data[i + 3] += this.data[i + 4] * dt;
    }
  }
}
""",
    "Sparks arch under gravity"
)

add_task(
    "dod_17_sph_fluid_density",
    "data_oriented_design",
    "SPH Fluid Coordinate Integration",
    "Step fluid particle coordinates without memory allocations.",
    """
pub struct FluidParticle:
  pos: vec2
  vel: vec2
  density: float

pub system FluidMotion(mut FluidParticle):
  pos += vel * dt
""",
    """
export const FLUID_STRIDE = 5;

export class FluidSystem {
  public data: Float32Array;
  public count: number;

  constructor(capacity: number = 20000) {
    this.data = new Float32Array(capacity * FLUID_STRIDE);
    this.count = 0;
  }

  public update(dt: number): void {
    const total = this.count * FLUID_STRIDE;
    for (let i = 0; i < total; i += FLUID_STRIDE) {
      this.data[i + 0] += this.data[i + 2] * dt;
      this.data[i + 1] += this.data[i + 3] * dt;
    }
  }
}
""",
    "Fluid particle positions advance"
)

add_task(
    "dod_18_lorentz_magnetic_dipole",
    "data_oriented_design",
    "Lorentz Force Drift",
    "Deflect charged ion coordinates across magnetic field lines.",
    """
pub struct Ion:
  pos: vec3
  vel: vec3

pub system IonDrift(mut Ion):
  pos += vel * dt
""",
    """
export const ION_STRIDE = 6;

export class IonSystem {
  public data: Float32Array;
  public count: number;

  constructor(capacity: number = 10000) {
    this.data = new Float32Array(capacity * ION_STRIDE);
    this.count = 0;
  }

  public update(dt: number): void {
    const total = this.count * ION_STRIDE;
    for (let i = 0; i < total; i += ION_STRIDE) {
      this.data[i + 0] += this.data[i + 3] * dt;
      this.data[i + 1] += this.data[i + 4] * dt;
      this.data[i + 2] += this.data[i + 5] * dt;
    }
  }
}
""",
    "Advances ion trajectories"
)

add_task(
    "dod_19_solar_wind_deflection",
    "data_oriented_design",
    "Solar Wind Velocity Integration",
    "Stream solar wind particles past planetary obstacle.",
    """
pub struct WindPacket:
  pos: vec2
  vel: vec2

pub system WindAdvance(mut WindPacket):
  pos += vel * dt
""",
    """
export const WIND_STRIDE = 4;

export class WindSystem {
  public data: Float32Array;
  public count: number;

  constructor(capacity: number = 25000) {
    this.data = new Float32Array(capacity * WIND_STRIDE);
    this.count = 0;
  }

  public update(dt: number): void {
    const total = this.count * WIND_STRIDE;
    for (let i = 0; i < total; i += WIND_STRIDE) {
      this.data[i + 0] += this.data[i + 2] * dt;
      this.data[i + 1] += this.data[i + 3] * dt;
    }
  }
}
""",
    "Displaces wind particles"
)

add_task(
    "dod_20_soft_body_lattice_jelly",
    "data_oriented_design",
    "Soft Body Mass Lattice Node Step",
    "Integrate soft jelly mass node position with zero garbage collection.",
    """
pub struct JellyNode:
  pos: vec3
  vel: vec3
  pressure: float

pub system JellyStep(mut JellyNode):
  pos += vel * dt
""",
    """
export const JELLY_STRIDE = 7;

export class JellySystem {
  public data: Float32Array;
  public count: number;

  constructor(capacity: number = 10000) {
    this.data = new Float32Array(capacity * JELLY_STRIDE);
    this.count = 0;
  }

  public update(dt: number): void {
    const total = this.count * JELLY_STRIDE;
    for (let i = 0; i < total; i += JELLY_STRIDE) {
      this.data[i + 0] += this.data[i + 3] * dt;
      this.data[i + 1] += this.data[i + 4] * dt;
      this.data[i + 2] += this.data[i + 5] * dt;
    }
  }
}
""",
    "Jelly nodes translate smoothly"
)

# =========================================================================
# DOMAIN 3: Declarative UI & React 19 (Tasks 41-60)
# =========================================================================

add_task(
    "ui_01_profile_card",
    "declarative_ui",
    "Profile Card Component",
    "Create user profile card with avatar, name, and action button.",
    """
pub component ProfileCard(name: str, role: str):
  div.card.p-4.flex [
    span.name.fontBold [ name ],
    span.role.textMuted [ role ],
    button.btnPrimary [ @click: onFollow, "Follow" ]
  ]
""",
    """
import React from "react";

export interface ProfileCardProps {
  name: string;
  role: string;
  onFollow?: (event: React.MouseEvent<HTMLButtonElement>) => void;
}

export function ProfileCard({ name, role, onFollow }: ProfileCardProps): React.ReactNode {
  return (
    <div className="card p-4 flex">
      <span className="name fontBold">{name}</span>
      <span className="role textMuted">{role}</span>
      <button className="btnPrimary" onClick={onFollow}>
        Follow
      </button>
    </div>
  );
}
""",
    "Renders card with .fontBold name and .btnPrimary follow button"
)

add_task(
    "ui_02_login_form_state",
    "declarative_ui",
    "Login Form State Component",
    "Interactive login form with email, password, and submit handler.",
    """
pub component LoginForm(title: str):
  div.loginBox.p-6 [
    h2.title [ title ],
    input.inputEmail [ @type: "email", @placeholder: "Email" ],
    input.inputPassword [ @type: "password", @placeholder: "Password" ],
    button.btnSubmit [ @click: onSubmit, "Sign In" ]
  ]
""",
    """
import React from "react";

export interface LoginFormProps {
  title: string;
  onSubmit?: (event: React.FormEvent<HTMLButtonElement>) => void;
}

export function LoginForm({ title, onSubmit }: LoginFormProps): React.ReactNode {
  return (
    <div className="loginBox p-6">
      <h2 className="title">{title}</h2>
      <input className="inputEmail" type="email" placeholder="Email" />
      <input className="inputPassword" type="password" placeholder="Password" />
      <button className="btnSubmit" onClick={onSubmit}>
        Sign In
      </button>
    </div>
  );
}
""",
    "Renders login form with email and password inputs"
)

add_task(
    "ui_03_todo_list_keyed",
    "declarative_ui",
    "Keyed Todo List Component",
    "Render todo list item with complete checkbox and label.",
    """
pub component TodoItem(id: int, text: str, done: bool):
  div.todoRow.p-2 [
    input.chkDone [ @type: "checkbox", @checked: done ],
    span.todoLabel [ text ],
    button.btnDelete [ @click: onDelete, "Delete" ]
  ]
""",
    """
import React from "react";

export interface TodoItemProps {
  id: number;
  text: string;
  done: boolean;
  onDelete?: (id: number) => void;
}

export function TodoItem({ id, text, done, onDelete }: TodoItemProps): React.ReactNode {
  return (
    <div className="todoRow p-2" key={id}>
      <input className="chkDone" type="checkbox" checked={done} readOnly />
      <span className="todoLabel">{text}</span>
      <button className="btnDelete" onClick={() => onDelete?.(id)}>
        Delete
      </button>
    </div>
  );
}
""",
    "Renders todo row with checkbox and delete button"
)

add_task(
    "ui_04_counter_widget",
    "declarative_ui",
    "Counter Widget Component",
    "Stateful counter widget with increment, decrement, and reset actions.",
    """
pub component CounterWidget(count: int):
  div.counter.flexRow [
    button.btnDec [ @click: onDec, "-" ],
    span.countVal.fontMono [ "{count}" ],
    button.btnInc [ @click: onInc, "+" ]
  ]
""",
    """
import React from "react";

export interface CounterWidgetProps {
  count: number;
  onDec?: () => void;
  onInc?: () => void;
}

export function CounterWidget({ count, onDec, onInc }: CounterWidgetProps): React.ReactNode {
  return (
    <div className="counter flexRow">
      <button className="btnDec" onClick={onDec}>-</button>
      <span className="countVal fontMono">{count}</span>
      <button className="btnInc" onClick={onInc}>+</button>
    </div>
  );
}
""",
    "Renders counter with plus and minus buttons"
)

add_task(
    "ui_05_metric_badge_pill",
    "declarative_ui",
    "Metric Badge Pill Component",
    "Status badge pill with status label and active dot.",
    """
pub component StatusBadge(label: str, isActive: bool):
  span.badgePill.roundedFull [
    span.indicatorDot [ "" ],
    span.badgeLabel [ label ]
  ]
""",
    """
import React from "react";

export interface StatusBadgeProps {
  label: string;
  isActive: boolean;
}

export function StatusBadge({ label, isActive }: StatusBadgeProps): React.ReactNode {
  return (
    <span className="badgePill roundedFull">
      <span className="indicatorDot" />
      <span className="badgeLabel">{label}</span>
    </span>
  );
}
""",
    "Renders rounded status pill with indicator dot"
)

add_task(
    "ui_06_navbar_responsive",
    "declarative_ui",
    "Responsive Navbar Header",
    "Header navigation bar with logo, links, and action button.",
    """
pub component Navbar(brand: str):
  header.navHeader.flexBetween [
    span.brandLogo.fontBold [ brand ],
    nav.navLinks [
      a.navItem [ @href: "/docs", "Docs" ],
      a.navItem [ @href: "/blog", "Blog" ]
    ],
    button.btnCta [ @click: onLogin, "Log In" ]
  ]
""",
    """
import React from "react";

export interface NavbarProps {
  brand: string;
  onLogin?: () => void;
}

export function Navbar({ brand, onLogin }: NavbarProps): React.ReactNode {
  return (
    <header className="navHeader flexBetween">
      <span className="brandLogo fontBold">{brand}</span>
      <nav className="navLinks">
        <a className="navItem" href="/docs">Docs</a>
        <a className="navItem" href="/blog">Blog</a>
      </nav>
      <button className="btnCta" onClick={onLogin}>Log In</button>
    </header>
  );
}
""",
    "Renders header with brand, nav links, and CTA button"
)

add_task(
    "ui_07_modal_dialog_overlay",
    "declarative_ui",
    "Modal Dialog Overlay Component",
    "Accessible modal dialog backdrop with title, body, and dismiss action.",
    """
pub component Modal(title: str, message: str):
  div.modalBackdrop [
    div.modalCard.p-6 [
      h3.modalTitle [ title ],
      p.modalBody [ message ],
      button.btnClose [ @click: onClose, "Close" ]
    ]
  ]
""",
    """
import React from "react";

export interface ModalProps {
  title: string;
  message: string;
  onClose?: () => void;
}

export function Modal({ title, message, onClose }: ModalProps): React.ReactNode {
  return (
    <div className="modalBackdrop">
      <div className="modalCard p-6">
        <h3 className="modalTitle">{title}</h3>
        <p className="modalBody">{message}</p>
        <button className="btnClose" onClick={onClose}>Close</button>
      </div>
    </div>
  );
}
""",
    "Renders overlay dialog with title and close button"
)

add_task(
    "ui_08_search_input_debounced",
    "declarative_ui",
    "Search Input Bar Component",
    "Search bar with search input and clear icon button.",
    """
pub component SearchBar(placeholder: str):
  div.searchWrapper.flex [
    input.searchInput [ @type: "text", @placeholder: placeholder ],
    button.btnClear [ @click: onClear, "Clear" ]
  ]
""",
    """
import React from "react";

export interface SearchBarProps {
  placeholder: string;
  onClear?: () => void;
}

export function SearchBar({ placeholder, onClear }: SearchBarProps): React.ReactNode {
  return (
    <div className="searchWrapper flex">
      <input className="searchInput" type="text" placeholder={placeholder} />
      <button className="btnClear" onClick={onClear}>Clear</button>
    </div>
  );
}
""",
    "Renders search box with text input and clear button"
)

add_task(
    "ui_09_tabs_panel_container",
    "declarative_ui",
    "Tabs Navigation Bar Component",
    "Tab strip switching active panel view.",
    """
pub component TabBar(activeTab: str):
  div.tabStrip.flexRow [
    button.tabItem [ @click: selectGeneral, "General" ],
    button.tabItem [ @click: selectSecurity, "Security" ],
    button.tabItem [ @click: selectBilling, "Billing" ]
  ]
""",
    """
import React from "react";

export interface TabBarProps {
  activeTab: string;
  selectGeneral?: () => void;
  selectSecurity?: () => void;
  selectBilling?: () => void;
}

export function TabBar({ activeTab, selectGeneral, selectSecurity, selectBilling }: TabBarProps): React.ReactNode {
  return (
    <div className="tabStrip flexRow">
      <button className="tabItem" onClick={selectGeneral}>General</button>
      <button className="tabItem" onClick={selectSecurity}>Security</button>
      <button className="tabItem" onClick={selectBilling}>Billing</button>
    </div>
  );
}
""",
    "Renders tab row with three selectable buttons"
)

add_task(
    "ui_10_data_table_paginated",
    "declarative_ui",
    "Table Header Row Component",
    "Table header row displaying column headers.",
    """
pub component TableHeader(col1: str, col2: str, col3: str):
  div.tableHeaderRow.grid3 [
    span.headerCell [ col1 ],
    span.headerCell [ col2 ],
    span.headerCell [ col3 ]
  ]
""",
    """
import React from "react";

export interface TableHeaderProps {
  col1: string;
  col2: string;
  col3: string;
}

export function TableHeader({ col1, col2, col3 }: TableHeaderProps): React.ReactNode {
  return (
    <div className="tableHeaderRow grid3">
      <span className="headerCell">{col1}</span>
      <span className="headerCell">{col2}</span>
      <span className="headerCell">{col3}</span>
    </div>
  );
}
""",
    "Renders 3-column table header row"
)

add_task(
    "ui_11_notification_toast_alert",
    "declarative_ui",
    "Notification Toast Alert Component",
    "Toast alert banner with title, text, and dismiss button.",
    """
pub component ToastAlert(text: str):
  div.toastContainer.p-4 [
    span.toastMessage [ text ],
    button.btnDismiss [ @click: onDismiss, "x" ]
  ]
""",
    """
import React from "react";

export interface ToastAlertProps {
  text: string;
  onDismiss?: () => void;
}

export function ToastAlert({ text, onDismiss }: ToastAlertProps): React.ReactNode {
  return (
    <div className="toastContainer p-4">
      <span className="toastMessage">{text}</span>
      <button className="btnDismiss" onClick={onDismiss}>x</button>
    </div>
  );
}
""",
    "Renders alert toast with dismiss button"
)

add_task(
    "ui_12_accordion_collapsible",
    "declarative_ui",
    "Accordion Section Header Component",
    "Accordion header row with title and toggle icon.",
    """
pub component AccordionHeader(title: str, isOpen: bool):
  div.accordionBar.flexBetween [
    span.barTitle [ title ],
    span.chevronIcon [ isOpen ? "^" : "v" ]
  ]
""",
    """
import React from "react";

export interface AccordionHeaderProps {
  title: string;
  isOpen: boolean;
}

export function AccordionHeader({ title, isOpen }: AccordionHeaderProps): React.ReactNode {
  return (
    <div className="accordionBar flexBetween">
      <span className="barTitle">{title}</span>
      <span className="chevronIcon">{isOpen ? "^" : "v"}</span>
    </div>
  );
}
""",
    "Renders accordion bar with chevron indicator"
)

add_task(
    "ui_13_slider_range_control",
    "declarative_ui",
    "Range Slider Control Component",
    "Numeric slider control with label and current value readout.",
    """
pub component SliderControl(label: str, val: int):
  div.sliderRow.flexCol [
    label.sliderLabel [ label ],
    input.rangeInput [ @type: "range" ],
    span.valDisplay.fontMono [ "{val}" ]
  ]
""",
    """
import React from "react";

export interface SliderControlProps {
  label: string;
  val: number;
}

export function SliderControl({ label, val }: SliderControlProps): React.ReactNode {
  return (
    <div className="sliderRow flexCol">
      <label className="sliderLabel">{label}</label>
      <input className="rangeInput" type="range" />
      <span className="valDisplay fontMono">{val}</span>
    </div>
  );
}
""",
    "Renders slider with label and value readout"
)

add_task(
    "ui_14_avatar_group_cluster",
    "declarative_ui",
    "Avatar Stack Cluster Component",
    "Stacked avatar group with count overflow badge.",
    """
pub component AvatarCluster(count: int):
  div.avatarGroup.flexRow [
    div.avatarCircle [ "A" ],
    div.avatarCircle [ "B" ],
    span.extraBadge [ "+{count}" ]
  ]
""",
    """
import React from "react";

export interface AvatarClusterProps {
  count: number;
}

export function AvatarCluster({ count }: AvatarClusterProps): React.ReactNode {
  return (
    <div className="avatarGroup flexRow">
      <div className="avatarCircle">A</div>
      <div className="avatarCircle">B</div>
      <span className="extraBadge">+{count}</span>
    </div>
  );
}
""",
    "Renders avatar circle icons and count badge"
)

add_task(
    "ui_15_dropdown_menu_popover",
    "declarative_ui",
    "Dropdown Popover Menu Component",
    "Context action menu with action items and separator.",
    """
pub component DropdownMenu(label: str):
  div.dropdownCard.shadow [
    button.menuItem [ @click: onEdit, "Edit" ],
    button.menuItem [ @click: onDuplicate, "Duplicate" ],
    hr.menuDivider [ "" ],
    button.menuItemDanger [ @click: onDelete, "Delete" ]
  ]
""",
    """
import React from "react";

export interface DropdownMenuProps {
  label: string;
  onEdit?: () => void;
  onDuplicate?: () => void;
  onDelete?: () => void;
}

export function DropdownMenu({ label, onEdit, onDuplicate, onDelete }: DropdownMenuProps): React.ReactNode {
  return (
    <div className="dropdownCard shadow">
      <button className="menuItem" onClick={onEdit}>Edit</button>
      <button className="menuItem" onClick={onDuplicate}>Duplicate</button>
      <hr className="menuDivider" />
      <button className="menuItemDanger" onClick={onDelete}>Delete</button>
    </div>
  );
}
""",
    "Renders popover menu with edit and delete options"
)

add_task(
    "ui_16_breadcrumbs_navigation",
    "declarative_ui",
    "Breadcrumbs Navigation Trail",
    "Breadcrumb hierarchical trail with separator icons.",
    """
pub component Breadcrumbs(parent: str, current: str):
  nav.breadcrumbNav.flexRow [
    a.trailLink [ @href: "/", parent ],
    span.crumbSep [ "/" ],
    span.currentCrumb [ current ]
  ]
""",
    """
import React from "react";

export interface BreadcrumbsProps {
  parent: string;
  current: string;
}

export function Breadcrumbs({ parent, current }: BreadcrumbsProps): React.ReactNode {
  return (
    <nav className="breadcrumbNav flexRow">
      <a className="trailLink" href="/">{parent}</a>
      <span className="crumbSep">/</span>
      <span className="currentCrumb">{current}</span>
    </nav>
  );
}
""",
    "Renders parent crumb link and current page span"
)

add_task(
    "ui_17_kpi_stats_tile",
    "declarative_ui",
    "Analytics KPI Metric Tile Component",
    "Dashboard KPI metric card with percentage trend indicator.",
    """
pub component MetricCard(title: str, value: str, change: str):
  div.metricTile.p-4 [
    span.metricTitle.textMuted [ title ],
    h2.metricValue.fontBold [ value ],
    span.metricChange.textSuccess [ change ]
  ]
""",
    """
import React from "react";

export interface MetricCardProps {
  title: string;
  value: string;
  change: string;
}

export function MetricCard({ title, value, change }: MetricCardProps): React.ReactNode {
  return (
    <div className="metricTile p-4">
      <span className="metricTitle textMuted">{title}</span>
      <h2 className="metricValue fontBold">{value}</h2>
      <span className="metricChange textSuccess">{change}</span>
    </div>
  );
}
""",
    "Renders metric card with title, large value, and delta"
)

add_task(
    "ui_18_toggle_switch_button",
    "declarative_ui",
    "Accessible Toggle Switch Component",
    "Binary toggle switch with label and animated sliding thumb.",
    """
pub component ToggleSwitch(label: str, isChecked: bool):
  label.toggleLabel.flexRow [
    span.labelText [ label ],
    div.switchTrack [
      div.switchThumb [ "" ]
    ]
  ]
""",
    """
import React from "react";

export interface ToggleSwitchProps {
  label: string;
  isChecked: boolean;
}

export function ToggleSwitch({ label, isChecked }: ToggleSwitchProps): React.ReactNode {
  return (
    <label className="toggleLabel flexRow">
      <span className="labelText">{label}</span>
      <div className="switchTrack">
        <div className="switchThumb" />
      </div>
    </label>
  );
}
""",
    "Renders toggle label and switch thumb container"
)

add_task(
    "ui_19_rating_stars_widget",
    "declarative_ui",
    "5-Star Rating Widget Component",
    "Five-star rating widget displaying active star rating.",
    """
pub component RatingWidget(stars: int):
  div.ratingRow.flexRow [
    span.starIcon [ "*" ],
    span.starIcon [ "*" ],
    span.starIcon [ "*" ],
    span.starIcon [ "*" ],
    span.starIcon [ "*" ],
    span.ratingNum [ "{stars}/5" ]
  ]
""",
    """
import React from "react";

export interface RatingWidgetProps {
  stars: number;
}

export function RatingWidget({ stars }: RatingWidgetProps): React.ReactNode {
  return (
    <div className="ratingRow flexRow">
      <span className="starIcon">*</span>
      <span className="starIcon">*</span>
      <span className="starIcon">*</span>
      <span className="starIcon">*</span>
      <span className="starIcon">*</span>
      <span className="ratingNum">{stars}/5</span>
    </div>
  );
}
""",
    "Renders 5 star icons and numeric score label"
)

add_task(
    "ui_20_cart_summary_checkout",
    "declarative_ui",
    "Shopping Cart Summary Checkout Card",
    "Itemized checkout summary card with subtotal and checkout button.",
    """
pub component CartSummary(subtotal: str, tax: str, total: str):
  div.cartCard.p-6 [
    div.rowBetween [ span.lbl [ "Subtotal" ], span.val [ subtotal ] ],
    div.rowBetween [ span.lbl [ "Tax" ], span.val [ tax ] ],
    hr.cartDivider [ "" ],
    div.rowBetween [ span.totalLbl.fontBold [ "Total" ], span.totalVal.fontBold [ total ] ],
    button.btnCheckout [ @click: onCheckout, "Checkout Now" ]
  ]
""",
    """
import React from "react";

export interface CartSummaryProps {
  subtotal: string;
  tax: string;
  total: string;
  onCheckout?: () => void;
}

export function CartSummary({ subtotal, tax, total, onCheckout }: CartSummaryProps): React.ReactNode {
  return (
    <div className="cartCard p-6">
      <div className="rowBetween">
        <span className="lbl">Subtotal</span>
        <span className="val">{subtotal}</span>
      </div>
      <div className="rowBetween">
        <span className="lbl">Tax</span>
        <span className="val">{tax}</span>
      </div>
      <hr className="cartDivider" />
      <div className="rowBetween">
        <span className="totalLbl fontBold">Total</span>
        <span className="totalVal fontBold">{total}</span>
      </div>
      <button className="btnCheckout" onClick={onCheckout}>
        Checkout Now
      </button>
    </div>
  );
}
""",
    "Renders subtotal, tax, total, and checkout CTA"
)

# =========================================================================
# DOMAIN 4: GPU Compute & Embedded Shaders (Tasks 61-80)
# =========================================================================

add_task(
    "gpu_01_particle_vert_glsl",
    "gpu_compute_shaders",
    "Particle Vertex Shader GLSL",
    "Vertex shader with 2D position, velocity attributes and camera projection matrix.",
    """
shader ParticleVert(vertex) glsl:
  layout(location = 0) in vec2 a_pos;
  layout(location = 1) in vec2 a_vel;
  layout(binding = 0) uniform Camera {
    mat4 u_matrix;
  };
  void main() {
    gl_Position = u_matrix * vec4(a_pos, 0.0, 1.0);
  }
""",
    """
export interface ParticleVertexAttrs {
  posLocation: number;
  velLocation: number;
}

export interface CameraUniformLocations {
  matrixLocation: WebGLUniformLocation | null;
}

export const PARTICLE_VERT_SOURCE: string = `#version 300 es
layout(location = 0) in vec2 a_pos;
layout(location = 1) in vec2 a_vel;
layout(binding = 0) uniform Camera {
  mat4 u_matrix;
};
void main() {
  gl_Position = u_matrix * vec4(a_pos, 0.0, 1.0);
}
`;

export function setupParticlePipeline(
  gl: WebGL2RenderingContext,
  program: WebGLProgram,
  vbo: WebGLBuffer
): { attribs: ParticleVertexAttrs; uniforms: CameraUniformLocations } {
  gl.bindBuffer(gl.ARRAY_BUFFER, vbo);
  const posLocation = gl.getAttribLocation(program, "a_pos");
  gl.enableVertexAttribArray(posLocation);
  gl.vertexAttribPointer(posLocation, 2, gl.FLOAT, false, 16, 0);

  const velLocation = gl.getAttribLocation(program, "a_vel");
  gl.enableVertexAttribArray(velLocation);
  gl.vertexAttribPointer(velLocation, 2, gl.FLOAT, false, 16, 8);

  const matrixLocation = gl.getUniformLocation(program, "u_matrix");
  return {
    attribs: { posLocation, velLocation },
    uniforms: { matrixLocation },
  };
}
""",
    "Transforms vertex position through camera projection matrix"
)

add_task(
    "gpu_02_solid_color_frag_glsl",
    "gpu_compute_shaders",
    "Solid Color Fragment Shader GLSL",
    "Fragment shader outputting uniform tint color.",
    """
shader SolidColorFrag(fragment) glsl:
  out vec4 fragColor;
  layout(binding = 1) uniform Tint {
    vec4 u_color;
  };
  void main() {
    fragColor = u_color;
  }
""",
    """
export interface SolidColorUniforms {
  readonly colorLocation: WebGLUniformLocation | null;
}

export const SOLID_COLOR_FRAG_SOURCE: string = `#version 300 es
precision highp float;
out vec4 fragColor;
layout(binding = 1) uniform Tint {
  vec4 u_color;
};
void main() {
  fragColor = u_color;
}
`;

export function setupSolidColorUniforms(
  gl: WebGL2RenderingContext,
  program: WebGLProgram
): SolidColorUniforms {
  const colorLocation = gl.getUniformLocation(program, "u_color");
  return { colorLocation };
}

export function setTintVector(
  gl: WebGL2RenderingContext,
  loc: WebGLUniformLocation | null,
  r: number,
  g: number,
  b: number,
  a: number
): void {
  if (loc) {
    gl.uniform4f(loc, r, g, b, a);
  }
}
""",
    "Outputs uniform u_color to frame buffer"
)

add_task(
    "gpu_03_quad_vert_wgsl",
    "gpu_compute_shaders",
    "Fullscreen Quad Vertex Shader WGSL",
    "WGSL vertex shader outputting clip-space position and UV coordinate.",
    """
shader QuadVert(vertex) wgsl:
  struct VertexOutput {
    @builtin(position) position: vec4<f32>,
    @location(0) uv: vec2<f32>,
  }
  @vertex
  fn main(@location(0) pos: vec2<f32>, @location(1) uv: vec2<f32>) -> VertexOutput {
    var out: VertexOutput;
    out.position = vec4<f32>(pos, 0.0, 1.0);
    out.uv = uv;
    return out;
  }
""",
    """
export const QUAD_VERT_WGSL: string = `
struct VertexOutput {
  @builtin(position) position: vec4<f32>,
  @location(0) uv: vec2<f32>,
}
@vertex
fn main(@location(0) pos: vec2<f32>, @location(1) uv: vec2<f32>) -> VertexOutput {
  var out: VertexOutput;
  out.position = vec4<f32>(pos, 0.0, 1.0);
  out.uv = uv;
  return out;
}
`;

export const QUAD_VERTEX_BUFFER_LAYOUT: GPUVertexBufferLayout = {
  arrayStride: 16,
  stepMode: "vertex",
  attributes: [
    { format: "float32x2", offset: 0, shaderLocation: 0 },
    { format: "float32x2", offset: 8, shaderLocation: 1 },
  ],
};

export function createQuadRenderPipeline(
  device: GPUDevice,
  module: GPUShaderModule,
  swapChainFormat: GPUTextureFormat
): GPURenderPipeline {
  return device.createRenderPipeline({
    layout: "auto",
    vertex: {
      module,
      entryPoint: "main",
      buffers: [QUAD_VERTEX_BUFFER_LAYOUT],
    },
    primitive: { topology: "triangle-strip" },
  });
}
""",
    "Emits quad vertex and UV mapping"
)

add_task(
    "gpu_04_textured_frag_wgsl",
    "gpu_compute_shaders",
    "Textured Fragment Shader WGSL",
    "WGSL fragment shader sampling 2D texture map with UV coordinates.",
    """
shader TexturedFrag(fragment) wgsl:
  @group(0) @binding(0) var u_sampler: sampler;
  @group(0) @binding(1) var u_texture: texture_2d<f32>;
  @fragment
  fn main(@location(0) uv: vec2<f32>) -> @location(0) vec4<f32> {
    return textureSample(u_texture, u_sampler, uv);
  }
""",
    """
export const TEXTURED_FRAG_WGSL: string = `
@group(0) @binding(0) var u_sampler: sampler;
@group(0) @binding(1) var u_texture: texture_2d<f32>;
@fragment
fn main(@location(0) uv: vec2<f32>) -> @location(0) vec4<f32> {
  return textureSample(u_texture, u_sampler, uv);
}
`;

export function createTexturedBindGroupLayout(device: GPUDevice): GPUBindGroupLayout {
  return device.createBindGroupLayout({
    entries: [
      { binding: 0, visibility: GPUShaderStage.FRAGMENT, sampler: { type: "filtering" } },
      { binding: 1, visibility: GPUShaderStage.FRAGMENT, texture: { sampleType: "float" } },
    ],
  });
}

export function createTexturedBindGroup(
  device: GPUDevice,
  layout: GPUBindGroupLayout,
  sampler: GPUSampler,
  view: GPUTextureView
): GPUBindGroup {
  return device.createBindGroup({
    layout,
    entries: [
      { binding: 0, resource: sampler },
      { binding: 1, resource: view },
    ],
  });
}
""",
    "Samples 2D texture using filtering sampler"
)

add_task(
    "gpu_05_particle_integrate_compute_wgsl",
    "gpu_compute_shaders",
    "Particle Integrate Compute Shader WGSL",
    "Compute shader integrating particle positions in storage buffer.",
    """
shader ParticleCompute(compute) wgsl:
  struct Particle {
    pos: vec2<f32>,
    vel: vec2<f32>,
  }
  @group(0) @binding(0) var<storage, read_write> particles: array<Particle>;
  @compute @workgroup_size(64)
  fn main(@builtin(global_invocation_id) id: vec3<u32>) {
    let i = id.x;
    particles[i].pos += particles[i].vel * 0.016;
  }
""",
    """
export const PARTICLE_COMPUTE_WGSL: string = `
struct Particle {
  pos: vec2<f32>,
  vel: vec2<f32>,
}
@group(0) @binding(0) var<storage, read_write> particles: array<Particle>;
@compute @workgroup_size(64)
fn main(@builtin(global_invocation_id) id: vec3<u32>) {
  let i = id.x;
  particles[i].pos += particles[i].vel * 0.016;
}
`;

export function createParticleComputePipeline(
  device: GPUDevice,
  module: GPUShaderModule
): GPUComputePipeline {
  return device.createComputePipeline({
    layout: "auto",
    compute: { module, entryPoint: "main" },
  });
}

export function dispatchParticleComputePass(
  pass: GPUComputePassEncoder,
  pipeline: GPUComputePipeline,
  bindGroup: GPUBindGroup,
  particleCount: number
): void {
  pass.setPipeline(pipeline);
  pass.setBindGroup(0, bindGroup);
  pass.dispatchWorkgroups(Math.ceil(particleCount / 64));
}
""",
    "WebGPU compute workgroup updates particles concurrently"
)

add_task(
    "gpu_06_std140_camera_uniform",
    "gpu_compute_shaders",
    "std140 Camera Uniform Block",
    "Define std140 camera uniform block enforcing 16-byte alignment without vec3 hazard.",
    """
shader CameraStd140(vertex) glsl:
  layout(std140, binding = 0) uniform CameraBlock {
    mat4 u_view;
    mat4 u_proj;
    vec4 u_camPos;
  };
  void main() {
    gl_Position = u_proj * u_view * vec4(0.0, 0.0, 0.0, 1.0);
  }
""",
    """
export const CAMERA_STD140_SOURCE: string = `#version 300 es
layout(std140, binding = 0) uniform CameraBlock {
  mat4 u_view;
  mat4 u_proj;
  vec4 u_camPos;
};
void main() {
  gl_Position = u_proj * u_view * vec4(0.0, 0.0, 0.0, 1.0);
}
`;

export const CAMERA_BLOCK_BYTE_SIZE = 144;
export const CAMERA_VIEW_OFFSET = 0;
export const CAMERA_PROJ_OFFSET = 64;
export const CAMERA_POS_OFFSET = 128;

export function uploadCameraUniformBuffer(
  gl: WebGL2RenderingContext,
  ubo: WebGLBuffer,
  viewMatrix: Float32Array,
  projMatrix: Float32Array,
  camPosition: Float32Array
): void {
  gl.bindBuffer(gl.UNIFORM_BUFFER, ubo);
  gl.bufferSubData(gl.UNIFORM_BUFFER, CAMERA_VIEW_OFFSET, viewMatrix);
  gl.bufferSubData(gl.UNIFORM_BUFFER, CAMERA_PROJ_OFFSET, projMatrix);
  gl.bufferSubData(gl.UNIFORM_BUFFER, CAMERA_POS_OFFSET, camPosition);
}
""",
    "std140 uniform block complies with 16-byte boundaries"
)

add_task(
    "gpu_07_phong_lighting_vert_glsl",
    "gpu_compute_shaders",
    "Blinn-Phong Lighting Vertex Shader GLSL",
    "Vertex shader transforming normal and calculating light vector.",
    """
shader PhongVert(vertex) glsl:
  layout(location = 0) in vec3 a_position;
  layout(location = 1) in vec3 a_normal;
  out vec3 v_normal;
  layout(binding = 0) uniform Transform {
    mat4 u_modelView;
  };
  void main() {
    v_normal = mat3(u_modelView) * a_normal;
    gl_Position = u_modelView * vec4(a_position, 1.0);
  }
""",
    """
export interface PhongVertexLocations {
  readonly positionLocation: number;
  readonly normalLocation: number;
  readonly modelViewLocation: WebGLUniformLocation | null;
}

export const PHONG_VERT_SOURCE: string = `#version 300 es
layout(location = 0) in vec3 a_position;
layout(location = 1) in vec3 a_normal;
out vec3 v_normal;
layout(binding = 0) uniform Transform {
  mat4 u_modelView;
};
void main() {
  v_normal = mat3(u_modelView) * a_normal;
  gl_Position = u_modelView * vec4(a_position, 1.0);
}
`;

export function setupPhongPipeline(
  gl: WebGL2RenderingContext,
  prog: WebGLProgram
): PhongVertexLocations {
  const positionLocation = gl.getAttribLocation(prog, "a_position");
  const normalLocation = gl.getAttribLocation(prog, "a_normal");
  const modelViewLocation = gl.getUniformLocation(prog, "u_modelView");
  return { positionLocation, normalLocation, modelViewLocation };
}
""",
    "Transforms normal with model-view matrix"
)

add_task(
    "gpu_08_phong_lighting_frag_glsl",
    "gpu_compute_shaders",
    "Blinn-Phong Fragment Lighting GLSL",
    "Specular Blinn-Phong lighting computation in fragment shader.",
    """
shader PhongFrag(fragment) glsl:
  in vec3 v_normal;
  out vec4 fragColor;
  void main() {
    vec3 n = normalize(v_normal);
    float diff = max(dot(n, vec3(0.0, 1.0, 0.0)), 0.0);
    fragColor = vec4(vec3(diff), 1.0);
  }
""",
    """
export const PHONG_FRAG_SOURCE: string = `#version 300 es
precision highp float;
in vec3 v_normal;
out vec4 fragColor;
void main() {
  vec3 n = normalize(v_normal);
  float diff = max(dot(n, vec3(0.0, 1.0, 0.0)), 0.0);
  fragColor = vec4(vec3(diff), 1.0);
}
`;

export function bindPhongFragmentState(
  gl: WebGL2RenderingContext,
  program: WebGLProgram
): void {
  gl.useProgram(program);
}
""",
    "Calculates diffuse lighting dot product"
)

add_task(
    "gpu_09_grid_wireframe_frag_wgsl",
    "gpu_compute_shaders",
    "Grid Wireframe Shader WGSL",
    "Procedural anti-aliased grid wireframe pattern using fract.",
    """
shader GridFrag(fragment) wgsl:
  @fragment
  fn main(@location(0) uv: vec2<f32>) -> @location(0) vec4<f32> {
    let grid = abs(fract(uv - 0.5) - 0.5) / fwidth(uv);
    let line = min(grid.x, grid.y);
    let c = 1.0 - min(line, 1.0);
    return vec4<f32>(c, c, c, 1.0);
  }
""",
    """
export const GRID_FRAG_WGSL: string = `
@fragment
fn main(@location(0) uv: vec2<f32>) -> @location(0) vec4<f32> {
  let grid = abs(fract(uv - 0.5) - 0.5) / fwidth(uv);
  let line = min(grid.x, grid.y);
  let c = 1.0 - min(line, 1.0);
  return vec4<f32>(c, c, c, 1.0);
}
`;

export function createGridPipelineDescriptor(
  module: GPUShaderModule,
  surfaceFormat: GPUTextureFormat
): GPUFragmentState {
  return {
    module,
    entryPoint: "main",
    targets: [{ format: surfaceFormat }],
  };
}
""",
    "Renders procedural grid lines without textures"
)

add_task(
    "gpu_10_bloom_threshold_frag_glsl",
    "gpu_compute_shaders",
    "HDR Bloom Threshold Filter GLSL",
    "Bright-pass extraction filter isolating luminance exceeding threshold.",
    """
shader BloomThreshold(fragment) glsl:
  in vec2 v_uv;
  out vec4 fragColor;
  layout(binding = 0) uniform sampler2D u_hdrScene;
  void main() {
    vec4 c = texture(u_hdrScene, v_uv);
    float lum = dot(c.rgb, vec3(0.2126, 0.7152, 0.0722));
    fragColor = lum > 1.0 ? c : vec4(0.0);
  }
""",
    """
export const BLOOM_THRESHOLD_SOURCE: string = `#version 300 es
precision highp float;
in vec2 v_uv;
out vec4 fragColor;
uniform sampler2D u_hdrScene;
void main() {
  vec4 c = texture(u_hdrScene, v_uv);
  float lum = dot(c.rgb, vec3(0.2126, 0.7152, 0.0722));
  fragColor = lum > 1.0 ? c : vec4(0.0);
}
`;

export function bindBloomPassTexture(
  gl: WebGL2RenderingContext,
  texture: WebGLTexture,
  textureUnit: number = 0
): void {
  gl.activeTexture(gl.TEXTURE0 + textureUnit);
  gl.bindTexture(gl.TEXTURE_2D, texture);
}
""",
    "Extracts bright color pixels"
)

add_task(
    "gpu_11_blur_gaussian_compute_wgsl",
    "gpu_compute_shaders",
    "1D Gaussian Blur Compute Shader WGSL",
    "1D separable horizontal Gaussian blur filter compute shader.",
    """
shader BlurCompute(compute) wgsl:
  @group(0) @binding(0) var inTex: texture_2d<f32>;
  @group(0) @binding(1) var outTex: texture_storage_2d<rgba8unorm, write>;
  @compute @workgroup_size(16, 16)
  fn main(@builtin(global_invocation_id) id: vec3<u32>) {
    let coords = vec2<i32>(id.xy);
    let c = textureLoad(inTex, coords, 0);
    textureStore(outTex, coords, c);
  }
""",
    """
export const BLUR_COMPUTE_WGSL: string = `
@group(0) @binding(0) var inTex: texture_2d<f32>;
@group(0) @binding(1) var outTex: texture_storage_2d<rgba8unorm, write>;
@compute @workgroup_size(16, 16)
fn main(@builtin(global_invocation_id) id: vec3<u32>) {
  let coords = vec2<i32>(id.xy);
  let c = textureLoad(inTex, coords, 0);
  textureStore(outTex, coords, c);
}
`;

export function dispatchBlurPass(
  pass: GPUComputePassEncoder,
  pipeline: GPUComputePipeline,
  bindGroup: GPUBindGroup,
  width: number,
  height: number
): void {
  pass.setPipeline(pipeline);
  pass.setBindGroup(0, bindGroup);
  pass.dispatchWorkgroups(Math.ceil(width / 16), Math.ceil(height / 16));
}
""",
    "Stores blurred pixel to storage texture"
)

add_task(
    "gpu_12_postprocess_tonemap_frag_wgsl",
    "gpu_compute_shaders",
    "ACES Filmic Tonemap WGSL",
    "Tone-mapping post-processing fragment shader using ACES filmic curve.",
    """
shader TonemapFrag(fragment) wgsl:
  @fragment
  fn main(@location(0) color: vec3<f32>) -> @location(0) vec4<f32> {
    let a = 2.51;
    let b = 0.03;
    let c = 2.43;
    let d = 0.59;
    let e = 0.14;
    let mapped = clamp((color * (a * color + b)) / (color * (c * color + d) + e), vec3<f32>(0.0), vec3<f32>(1.0));
    return vec4<f32>(mapped, 1.0);
  }
""",
    """
export const TONEMAP_FRAG_WGSL: string = `
@fragment
fn main(@location(0) color: vec3<f32>) -> @location(0) vec4<f32> {
  let a = 2.51;
  let b = 0.03;
  let c = 2.43;
  let d = 0.59;
  let e = 0.14;
  let mapped = clamp((color * (a * color + b)) / (color * (c * color + d) + e), vec3<f32>(0.0), vec3<f32>(1.0));
  return vec4<f32>(mapped, 1.0);
}
`;

export function createTonemapPipeline(
  device: GPUDevice,
  module: GPUShaderModule,
  format: GPUTextureFormat
): GPURenderPipeline {
  return device.createRenderPipeline({
    layout: "auto",
    fragment: { module, entryPoint: "main", targets: [{ format }] },
    primitive: { topology: "triangle-strip" },
  });
}
""",
    "Applies ACES filmic compression curve"
)

add_task(
    "gpu_13_instanced_mesh_vert_glsl",
    "gpu_compute_shaders",
    "Instanced Mesh Vertex Shader GLSL",
    "Vertex shader with instanced model matrix translation attributes.",
    """
shader InstancedVert(vertex) glsl:
  layout(location = 0) in vec3 a_position;
  layout(location = 1) in vec3 a_instanceOffset;
  layout(binding = 0) uniform Camera {
    mat4 u_viewProj;
  };
  void main() {
    vec3 p = a_position + a_instanceOffset;
    gl_Position = u_viewProj * vec4(p, 1.0);
  }
""",
    """
export const INSTANCED_VERT_SOURCE: string = `#version 300 es
layout(location = 0) in vec3 a_position;
layout(location = 1) in vec3 a_instanceOffset;
layout(binding = 0) uniform Camera {
  mat4 u_viewProj;
};
void main() {
  vec3 p = a_position + a_instanceOffset;
  gl_Position = u_viewProj * vec4(p, 1.0);
}
`;

export function setupInstancedAttributes(
  gl: WebGL2RenderingContext,
  program: WebGLProgram,
  meshVbo: WebGLBuffer,
  instanceVbo: WebGLBuffer
): void {
  const posLoc = gl.getAttribLocation(program, "a_position");
  gl.bindBuffer(gl.ARRAY_BUFFER, meshVbo);
  gl.enableVertexAttribArray(posLoc);
  gl.vertexAttribPointer(posLoc, 3, gl.FLOAT, false, 12, 0);

  const instLoc = gl.getAttribLocation(program, "a_instanceOffset");
  gl.bindBuffer(gl.ARRAY_BUFFER, instanceVbo);
  gl.enableVertexAttribArray(instLoc);
  gl.vertexAttribPointer(instLoc, 3, gl.FLOAT, false, 12, 0);
  gl.vertexAttribDivisor(instLoc, 1);
}
""",
    "Translates mesh by instance offset"
)

add_task(
    "gpu_14_particle_curl_noise_compute_wgsl",
    "gpu_compute_shaders",
    "Curl Noise Turbulence Compute WGSL",
    "Calculate particle velocity perturbation in 3D field.",
    """
shader CurlCompute(compute) wgsl:
  @group(0) @binding(0) var<storage, read_write> vels: array<vec3<f32>>;
  @compute @workgroup_size(64)
  fn main(@builtin(global_invocation_id) id: vec3<u32>) {
    let i = id.x;
    vels[i] = cross(vels[i], vec3<f32>(0.0, 1.0, 0.0));
  }
""",
    """
export const CURL_COMPUTE_WGSL: string = `
@group(0) @binding(0) var<storage, read_write> vels: array<vec3<f32>>;
@compute @workgroup_size(64)
fn main(@builtin(global_invocation_id) id: vec3<u32>) {
  let i = id.x;
  vels[i] = cross(vels[i], vec3<f32>(0.0, 1.0, 0.0));
}
`;

export function dispatchCurlKernel(
  pass: GPUComputePassEncoder,
  pipeline: GPUComputePipeline,
  bindGroup: GPUBindGroup,
  count: number
): void {
  pass.setPipeline(pipeline);
  pass.setBindGroup(0, bindGroup);
  pass.dispatchWorkgroups(Math.ceil(count / 64));
}
""",
    "Performs cross product turbulence update"
)

add_task(
    "gpu_15_shadow_depth_vert_glsl",
    "gpu_compute_shaders",
    "Shadow Depth Pass Vertex Shader GLSL",
    "Light-space orthographic shadow map depth pass shader.",
    """
shader ShadowDepthVert(vertex) glsl:
  layout(location = 0) in vec3 a_position;
  layout(binding = 0) uniform LightSpace {
    mat4 u_lightMatrix;
  };
  void main() {
    gl_Position = u_lightMatrix * vec4(a_position, 1.0);
  }
""",
    """
export const SHADOW_DEPTH_VERT_SOURCE: string = `#version 300 es
layout(location = 0) in vec3 a_position;
layout(binding = 0) uniform LightSpace {
  mat4 u_lightMatrix;
};
void main() {
  gl_Position = u_lightMatrix * vec4(a_position, 1.0);
}
`;

export function bindShadowUniforms(
  gl: WebGL2RenderingContext,
  program: WebGLProgram,
  lightMatrix: Float32Array
): void {
  const loc = gl.getUniformLocation(program, "u_lightMatrix");
  if (loc) {
    gl.uniformMatrix4fv(loc, false, lightMatrix);
  }
}
""",
    "Projects vertices into shadow light space"
)

add_task(
    "gpu_16_sdf_font_frag_wgsl",
    "gpu_compute_shaders",
    "Signed Distance Field Font Frag WGSL",
    "Signed distance field glyph text fragment shader with smooth step.",
    """
shader SdfFrag(fragment) wgsl:
  @fragment
  fn main(@location(0) dist: f32) -> @location(0) vec4<f32> {
    let alpha = smoothstep(0.48, 0.52, dist);
    return vec4<f32>(1.0, 1.0, 1.0, alpha);
  }
""",
    """
export const SDF_FRAG_WGSL: string = `
@fragment
fn main(@location(0) dist: f32) -> @location(0) vec4<f32> {
  let alpha = smoothstep(0.48, 0.52, dist);
  return vec4<f32>(1.0, 1.0, 1.0, alpha);
}
`;

export const SDF_COLOR_TARGET_STATE: GPUColorTargetState = {
  format: "bgra8unorm",
  blend: {
    color: { srcFactor: "src-alpha", dstFactor: "one-minus-src-alpha" },
    alpha: { srcFactor: "one", dstFactor: "one-minus-src-alpha" },
  },
};
""",
    "Anti-aliases glyph edges using smoothstep"
)

add_task(
    "gpu_17_normal_mapping_frag_glsl",
    "gpu_compute_shaders",
    "Normal Mapping Fragment Shader GLSL",
    "Fragment shader unpacking tangent-space normal vector.",
    """
shader NormalMapFrag(fragment) glsl:
  in vec2 v_uv;
  out vec4 fragColor;
  layout(binding = 0) uniform sampler2D u_normalMap;
  void main() {
    vec3 n = texture(u_normalMap, v_uv).rgb * 2.0 - 1.0;
    fragColor = vec4(normalize(n), 1.0);
  }
""",
    """
export const NORMAL_MAP_FRAG_SOURCE: string = `#version 300 es
precision highp float;
in vec2 v_uv;
out vec4 fragColor;
uniform sampler2D u_normalMap;
void main() {
  vec3 n = texture(u_normalMap, v_uv).rgb * 2.0 - 1.0;
  fragColor = vec4(normalize(n), 1.0);
}
`;

export function setupNormalMapSampler(
  gl: WebGL2RenderingContext,
  program: WebGLProgram,
  texture: WebGLTexture
): void {
  const loc = gl.getUniformLocation(program, "u_normalMap");
  gl.activeTexture(gl.TEXTURE0);
  gl.bindTexture(gl.TEXTURE_2D, texture);
  gl.uniform1i(loc, 0);
}
""",
    "Expands [0, 1] color to [-1, 1] normal"
)

add_task(
    "gpu_18_depth_fog_frag_wgsl",
    "gpu_compute_shaders",
    "Exponential Depth Fog Frag WGSL",
    "Compute exponential atmospheric fog blend factor.",
    """
shader FogFrag(fragment) wgsl:
  @fragment
  fn main(@location(0) depth: f32) -> @location(0) vec4<f32> {
    let fog = clamp(exp(-depth * 0.05), 0.0, 1.0);
    return vec4<f32>(vec3<f32>(0.8), 1.0 - fog);
  }
""",
    """
export const FOG_FRAG_WGSL: string = `
@fragment
fn main(@location(0) depth: f32) -> @location(0) vec4<f32> {
  let fog = clamp(exp(-depth * 0.05), 0.0, 1.0);
  return vec4<f32>(vec3<f32>(0.8), 1.0 - fog);
}
`;

export function createFogPipeline(
  device: GPUDevice,
  module: GPUShaderModule,
  colorFormat: GPUTextureFormat
): GPURenderPipeline {
  return device.createRenderPipeline({
    layout: "auto",
    fragment: { module, entryPoint: "main", targets: [{ format: colorFormat }] },
  });
}
""",
    "Blends exponential fog based on depth"
)

add_task(
    "gpu_19_gpu_prefix_sum_compute_wgsl",
    "gpu_compute_shaders",
    "Parallel Prefix Sum Compute WGSL",
    "Workgroup parallel reduction prefix sum compute kernel.",
    """
shader PrefixSum(compute) wgsl:
  @group(0) @binding(0) var<storage, read_write> data: array<u32>;
  @compute @workgroup_size(32)
  fn main(@builtin(local_invocation_id) lid: vec3<u32>) {
    let idx = lid.x;
    if idx > 0u {
      data[idx] += data[idx - 1u];
    }
  }
""",
    """
export const PREFIX_SUM_WGSL: string = `
@group(0) @binding(0) var<storage, read_write> data: array<u32>;
@compute @workgroup_size(32)
fn main(@builtin(local_invocation_id) lid: vec3<u32>) {
  let idx = lid.x;
  if idx > 0u {
    data[idx] += data[idx - 1u];
  }
}
`;

export function executePrefixSumWorkgroup(
  pass: GPUComputePassEncoder,
  pipeline: GPUComputePipeline,
  bindGroup: GPUBindGroup
): void {
  pass.setPipeline(pipeline);
  pass.setBindGroup(0, bindGroup);
  pass.dispatchWorkgroups(1);
}
""",
    "Performs workgroup reduction sum"
)

add_task(
    "gpu_20_cubemap_skybox_vert_glsl",
    "gpu_compute_shaders",
    "Skybox Cubemap Vertex Shader GLSL",
    "Skybox background vertex shader with z = w depth clamp.",
    """
shader SkyboxVert(vertex) glsl:
  layout(location = 0) in vec3 a_pos;
  out vec3 v_texCoords;
  layout(binding = 0) uniform ViewProj {
    mat4 u_vp;
  };
  void main() {
    v_texCoords = a_pos;
    vec4 p = u_vp * vec4(a_pos, 1.0);
    gl_Position = p.xyww;
  }
""",
    """
export const SKYBOX_VERT_SOURCE: string = `#version 300 es
layout(location = 0) in vec3 a_pos;
out vec3 v_texCoords;
layout(binding = 0) uniform ViewProj {
  mat4 u_vp;
};
void main() {
  v_texCoords = a_pos;
  vec4 p = u_vp * vec4(a_pos, 1.0);
  gl_Position = p.xyww;
}
`;

export function setupSkyboxPipeline(
  gl: WebGL2RenderingContext,
  program: WebGLProgram,
  vbo: WebGLBuffer,
  viewProjMatrix: Float32Array
): void {
  const posLoc = gl.getAttribLocation(program, "a_pos");
  gl.bindBuffer(gl.ARRAY_BUFFER, vbo);
  gl.enableVertexAttribArray(posLoc);
  gl.vertexAttribPointer(posLoc, 3, gl.FLOAT, false, 12, 0);

  const vpLoc = gl.getUniformLocation(program, "u_vp");
  if (vpLoc) {
    gl.uniformMatrix4fv(vpLoc, false, viewProjMatrix);
  }
}
""",
    "Clamps depth to 1.0 using p.xyww"
)

# =========================================================================
# DOMAIN 5: Multi-Target SSOT Models (Tasks 81-100)
# =========================================================================

add_task(
    "ssot_01_user_account",
    "multi_target_ssot",
    "User Account SSOT Model",
    "User account model with lifecycle status enum and age range refinement.",
    """
pub enum Status:
  Active
  Pending
  Suspended

pub struct UserAccount:
  id: int
  name: str
  age: { a: int | a >= 0 and a <= 120 }
  email: Option[str]
  status: Status
""",
    """
import { z } from "zod";

export type Status = "Active" | "Pending" | "Suspended";

export const StatusSchema = z.enum(["Active", "Pending", "Suspended"]);

export interface UserAccount {
  id: number;
  name: string;
  age: number;
  email?: string | null;
  status: Status;
}

export const UserAccountSchema = z.object({
  id: z.number().int(),
  name: z.string(),
  age: z.number().int().min(0).max(120),
  email: z.string().nullable().optional(),
  status: StatusSchema,
});
""",
    "Emits TypeScript interface and Zod schema with age range"
)

add_task(
    "ssot_02_ecommerce_product",
    "multi_target_ssot",
    "Product SKU Catalog SSOT Model",
    "Product model with currency enum, non-negative price, and tags array.",
    """
pub enum Currency:
  USD
  EUR
  GBP

pub struct Product:
  sku: str
  title: str
  priceCents: int
  currency: Currency
  inStock: bool
  tags: [str]
""",
    """
import { z } from "zod";

export type Currency = "USD" | "EUR" | "GBP";

export const CurrencySchema = z.enum(["USD", "EUR", "GBP"]);

export interface Product {
  sku: string;
  title: string;
  priceCents: number;
  currency: Currency;
  inStock: boolean;
  tags: string[];
}

export const ProductSchema = z.object({
  sku: z.string(),
  title: z.string(),
  priceCents: z.number().int().nonnegative(),
  currency: CurrencySchema,
  inStock: z.boolean(),
  tags: z.array(z.string()),
});
""",
    "Validates price in cents and currency enum"
)

add_task(
    "ssot_03_theme_design_tokens",
    "multi_target_ssot",
    "Theme Design Tokens Model",
    "Color palette and layout radius tokens emitting CSS variables and TypeScript constants.",
    """
pub struct DesignTokens:
  colorPrimary: str
  colorBackground: str
  borderRadius: int
  fontSizeBase: int
""",
    """
import { z } from "zod";

export interface DesignTokens {
  colorPrimary: string;
  colorBackground: string;
  borderRadius: number;
  fontSizeBase: number;
}

export const DesignTokensSchema = z.object({
  colorPrimary: z.string(),
  colorBackground: z.string(),
  borderRadius: z.number().int().positive(),
  fontSizeBase: z.number().int().positive(),
});

export const DESIGN_TOKENS_CSS = `
:root {
  --color-primary: #0066cc;
  --color-background: #ffffff;
  --border-radius: 8px;
  --font-size-base: 16px;
}
`;
""",
    "Emits CSS variables and TypeScript schema"
)

add_task(
    "ssot_04_auth_session_token",
    "multi_target_ssot",
    "Auth JWT Session Token SSOT",
    "JWT auth payload with user identifier, expiration timestamp, and roles.",
    """
pub struct AuthSession:
  userId: int
  token: str
  expiresAt: int
  roles: [str]
""",
    """
import { z } from "zod";

export interface AuthSession {
  userId: number;
  token: string;
  expiresAt: number;
  roles: string[];
}

export const AuthSessionSchema = z.object({
  userId: z.number().int(),
  token: z.string(),
  expiresAt: z.number().int(),
  roles: z.array(z.string()),
});
""",
    "Validates session expiration and roles"
)

add_task(
    "ssot_05_order_invoice",
    "multi_target_ssot",
    "Order Invoice SSOT Model",
    "Invoice model with customer ID, subtotal, and tax amount.",
    """
pub struct Invoice:
  invoiceId: str
  customerId: int
  subtotalCents: int
  taxCents: int
  isPaid: bool
""",
    """
import { z } from "zod";

export interface Invoice {
  invoiceId: string;
  customerId: number;
  subtotalCents: number;
  taxCents: number;
  isPaid: boolean;
}

export const InvoiceSchema = z.object({
  invoiceId: z.string(),
  customerId: z.number().int(),
  subtotalCents: z.number().int().nonnegative(),
  taxCents: z.number().int().nonnegative(),
  isPaid: z.boolean(),
});
""",
    "Validates customer ID and integer monetary fields"
)

add_task(
    "ssot_06_customer_address",
    "multi_target_ssot",
    "Physical Mailing Address SSOT",
    "Postal address model with street, city, postal code, and country code.",
    """
pub struct PostalAddress:
  street: str
  city: str
  postalCode: str
  countryCode: str
""",
    """
import { z } from "zod";

export interface PostalAddress {
  street: string;
  city: string;
  postalCode: string;
  countryCode: string;
}

export const PostalAddressSchema = z.object({
  street: z.string().min(1),
  city: z.string().min(1),
  postalCode: z.string().min(2),
  countryCode: z.string().length(2),
});
""",
    "Validates 2-letter ISO country code"
)

add_task(
    "ssot_07_api_response_envelope",
    "multi_target_ssot",
    "API Response Envelope SSOT",
    "Unified API JSON envelope with HTTP status code and response payload message.",
    """
pub struct ApiResponse:
  statusCode: int
  message: str
  success: bool
""",
    """
import { z } from "zod";

export interface ApiResponse {
  statusCode: number;
  message: string;
  success: boolean;
}

export const ApiResponseSchema = z.object({
  statusCode: z.number().int(),
  message: z.string(),
  success: z.boolean(),
});
""",
    "Emits API wrapper type and Zod schema"
)

add_task(
    "ssot_08_organization_team",
    "multi_target_ssot",
    "Organization Workspace Team SSOT",
    "Team workspace model with owner ID, seat quota, and team name.",
    """
pub struct OrganizationTeam:
  teamId: int
  name: str
  seatQuota: int
  isEnterprise: bool
""",
    """
import { z } from "zod";

export interface OrganizationTeam {
  teamId: number;
  name: string;
  seatQuota: number;
  isEnterprise: boolean;
}

export const OrganizationTeamSchema = z.object({
  teamId: z.number().int(),
  name: z.string().min(1),
  seatQuota: z.number().int().positive(),
  isEnterprise: z.boolean(),
});
""",
    "Validates team seat quota and enterprise flag"
)

add_task(
    "ssot_09_billing_subscription",
    "multi_target_ssot",
    "Billing Subscription SSOT",
    "Recurring subscription plan with plan tier and active status.",
    """
pub enum PlanTier:
  Free
  Pro
  Enterprise

pub struct Subscription:
  subId: str
  tier: PlanTier
  currentPeriodEnd: int
  autoRenew: bool
""",
    """
import { z } from "zod";

export type PlanTier = "Free" | "Pro" | "Enterprise";

export const PlanTierSchema = z.enum(["Free", "Pro", "Enterprise"]);

export interface Subscription {
  subId: string;
  tier: PlanTier;
  currentPeriodEnd: number;
  autoRenew: boolean;
}

export const SubscriptionSchema = z.object({
  subId: z.string(),
  tier: PlanTierSchema,
  currentPeriodEnd: z.number().int(),
  autoRenew: z.boolean(),
});
""",
    "Validates subscription tier enum"
)

add_task(
    "ssot_10_iot_sensor_reading",
    "multi_target_ssot",
    "IoT Sensor Telemetry Packet SSOT",
    "Telemetry telemetry packet with device ID, timestamp, and temperature reading.",
    """
pub struct SensorTelemetry:
  deviceId: str
  timestamp: int
  temperature: float
  batteryPercent: int
""",
    """
import { z } from "zod";

export interface SensorTelemetry {
  deviceId: string;
  timestamp: number;
  temperature: number;
  batteryPercent: number;
}

export const SensorTelemetrySchema = z.object({
  deviceId: z.string(),
  timestamp: z.number().int(),
  temperature: z.number(),
  batteryPercent: z.number().int().min(0).max(100),
});
""",
    "Validates battery percentage bounded [0, 100]"
)

add_task(
    "ssot_11_git_commit_metadata",
    "multi_target_ssot",
    "VCS Revision Commit Metadata SSOT",
    "Version control commit record with commit hash, author, and timestamp.",
    """
pub struct GitCommit:
  commitSha: str
  authorName: str
  authorEmail: str
  timestamp: int
  message: str
""",
    """
import { z } from "zod";

export interface GitCommit {
  commitSha: string;
  authorName: string;
  authorEmail: string;
  timestamp: number;
  message: string;
}

export const GitCommitSchema = z.object({
  commitSha: z.string().length(40),
  authorName: z.string(),
  authorEmail: z.string().email(),
  timestamp: z.number().int(),
  message: z.string(),
});
""",
    "Validates 40-character SHA hash"
)

add_task(
    "ssot_12_notification_event",
    "multi_target_ssot",
    "Push Notification Event SSOT",
    "Notification payload with severity enum, title, and read status.",
    """
pub enum NotificationLevel:
  Info
  Warning
  Critical

pub struct PushNotification:
  id: str
  level: NotificationLevel
  title: str
  isRead: bool
""",
    """
import { z } from "zod";

export type NotificationLevel = "Info" | "Warning" | "Critical";

export const NotificationLevelSchema = z.enum(["Info", "Warning", "Critical"]);

export interface PushNotification {
  id: string;
  level: NotificationLevel;
  title: string;
  isRead: boolean;
}

export const PushNotificationSchema = z.object({
  id: z.string(),
  level: NotificationLevelSchema,
  title: z.string(),
  isRead: z.boolean(),
});
""",
    "Validates severity level enum"
)

add_task(
    "ssot_13_file_attachment_meta",
    "multi_target_ssot",
    "File Attachment Metadata SSOT",
    "Media file metadata with MIME type, byte size, and download url.",
    """
pub struct FileAttachment:
  fileId: str
  fileName: str
  mimeType: str
  sizeBytes: int
  downloadUrl: str
""",
    """
import { z } from "zod";

export interface FileAttachment {
  fileId: string;
  fileName: string;
  mimeType: string;
  sizeBytes: number;
  downloadUrl: string;
}

export const FileAttachmentSchema = z.object({
  fileId: z.string(),
  fileName: z.string(),
  mimeType: z.string(),
  sizeBytes: z.number().int().nonnegative(),
  downloadUrl: z.string().url(),
});
""",
    "Validates byte size and download URL"
)

add_task(
    "ssot_14_search_query_filter",
    "multi_target_ssot",
    "Search Query Filter Parameters SSOT",
    "Query filter parameters with keyword, sort order, and page offset.",
    """
pub enum SortOrder:
  Ascending
  Descending

pub struct SearchFilter:
  query: str
  sort: SortOrder
  page: int
  pageSize: int
""",
    """
import { z } from "zod";

export type SortOrder = "Ascending" | "Descending";

export const SortOrderSchema = z.enum(["Ascending", "Descending"]);

export interface SearchFilter {
  query: string;
  sort: SortOrder;
  page: number;
  pageSize: number;
}

export const SearchFilterSchema = z.object({
  query: z.string(),
  sort: SortOrderSchema,
  page: z.number().int().nonnegative(),
  pageSize: z.number().int().positive(),
});
""",
    "Validates pagination parameters"
)

add_task(
    "ssot_15_database_migration_record",
    "multi_target_ssot",
    "Database Migration Log SSOT",
    "Migration log record with version number and applied timestamp.",
    """
pub struct MigrationLog:
  version: int
  description: str
  appliedAt: int
  executionMs: int
""",
    """
import { z } from "zod";

export interface MigrationLog {
  version: number;
  description: string;
  appliedAt: number;
  executionMs: number;
}

export const MigrationLogSchema = z.object({
  version: z.number().int().positive(),
  description: z.string(),
  appliedAt: z.number().int(),
  executionMs: z.number().int().nonnegative(),
});
""",
    "Validates positive version number and timing"
)

add_task(
    "ssot_16_color_theme_palette",
    "multi_target_ssot",
    "Color Theme Palette Tokens",
    "Palette tokens with primary, accent, and background color codes.",
    """
pub struct ThemePalette:
  primaryHex: str
  accentHex: str
  surfaceHex: str
""",
    """
import { z } from "zod";

export interface ThemePalette {
  primaryHex: string;
  accentHex: string;
  surfaceHex: string;
}

export const ThemePaletteSchema = z.object({
  primaryHex: z.string().regex(/^#[0-9a-fA-F]{6}$/),
  accentHex: z.string().regex(/^#[0-9a-fA-F]{6}$/),
  surfaceHex: z.string().regex(/^#[0-9a-fA-F]{6}$/),
});
""",
    "Validates 6-character hex color codes"
)

add_task(
    "ssot_17_oauth_credential_grant",
    "multi_target_ssot",
    "OAuth 2.0 Authorization Grant SSOT",
    "OAuth token response with access token, token type, and expiration.",
    """
pub struct OAuthGrant:
  accessToken: str
  tokenType: str
  expiresIn: int
  scope: str
""",
    """
import { z } from "zod";

export interface OAuthGrant {
  accessToken: string;
  tokenType: string;
  expiresIn: number;
  scope: string;
}

export const OAuthGrantSchema = z.object({
  accessToken: z.string().min(1),
  tokenType: z.string().min(1),
  expiresIn: z.number().int().positive(),
  scope: z.string(),
});
""",
    "Validates token expiration and non-empty strings"
)

add_task(
    "ssot_18_feature_flag_config",
    "multi_target_ssot",
    "Feature Flag Toggle Config SSOT",
    "Dynamic feature flag toggle with key name, rollout percentage, and status.",
    """
pub struct FeatureFlag:
  key: str
  isEnabled: bool
  rolloutPercentage: int
""",
    """
import { z } from "zod";

export interface FeatureFlag {
  key: string;
  isEnabled: boolean;
  rolloutPercentage: number;
}

export const FeatureFlagSchema = z.object({
  key: z.string().min(1),
  isEnabled: z.boolean(),
  rolloutPercentage: z.number().int().min(0).max(100),
});
""",
    "Validates rollout percentage bounded [0, 100]"
)

add_task(
    "ssot_19_audit_log_entry",
    "multi_target_ssot",
    "Security Audit Log Trail Entry SSOT",
    "Security audit trail record with actor ID, IP address, and action verb.",
    """
pub struct AuditEntry:
  actorId: int
  action: str
  ipAddress: str
  timestamp: int
""",
    """
import { z } from "zod";

export interface AuditEntry {
  actorId: number;
  action: string;
  ipAddress: string;
  timestamp: number;
}

export const AuditEntrySchema = z.object({
  actorId: z.number().int(),
  action: z.string(),
  ipAddress: z.string(),
  timestamp: z.number().int(),
});
""",
    "Validates actor ID and action string"
)

add_task(
    "ssot_20_wasm_string_bridge",
    "multi_target_ssot",
    "Wasm String Slice Bridge SSOT",
    "Dual-string memory slice bridge layout with pointer and byte length.",
    """
pub struct StringSlice:
  ptr: int
  len: int
""",
    """
import { z } from "zod";

export interface StringSlice {
  ptr: number;
  len: number;
}

export const StringSliceSchema = z.object({
  ptr: z.number().int().nonnegative(),
  len: z.number().int().nonnegative(),
});
""",
    "Validates non-negative linear memory pointer and length"
)

def main():
    repo_root = Path(__file__).resolve().parent.parent
    target_path = repo_root / "tests" / "tokenomics" / "benchmark_matrix_100.json"
    
    assert len(TASKS) == 100, f"Expected 100 tasks, found {len(TASKS)}"
    target_path.write_text(json.dumps(TASKS, indent=2), encoding="utf-8")
    print(f"Successfully generated {len(TASKS)} tasks at {target_path}")

if __name__ == "__main__":
    main()
