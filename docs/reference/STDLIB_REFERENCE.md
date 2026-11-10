[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# AIPL Standard Library Reference (36 Domains, 290 Modules, 4,324 Total Functions, 803 Data Types)

> Master Standard Library Architecture, Domain Lookup Tables, and Verified Pedagogical Snippets across all 36 domains.

## 1. Standard Library Architecture & 6-Layer DAG

- **Layer 0: Host & Memory Kernels**: `sys`, `rt`, `alloc`
- **Layer 1: Core Primitives & Math**: `prelude` (`01_builtins_root_and_prelude`), `math`, `collections`, `fmt`, `regex`, `time`
- **Layer 2: Serialization, Compression, Crypto & Database**: `encoding`, `compress`, `crypto`, `db`
- **Layer 3: Streaming I/O, Filesystem, OS, Concurrency, Networking & Testing**: `io`, `fs`, `os`, `sync`, `thread`, `net`, `test`
- **Layer 4: Windowing, Input, Assets, Audio, GPU, 2D/3D Rendering & UI**: `window`, `input`, `asset`, `audio`, `gfx`, `gfx2d`, `gfx3d`, `particle`, `ui`
- **Layer 5: ECS, Spatial Topologies, Physics, Procgen, AI & Generic Mechanics**: `ecs`, `spatial`, `phys2d`, `phys3d`, `procgen`, `ai`, `mechanics`

---

## 2. 36-Domain Master Routing Index


| # | Section / Recipe / Domain Covered | Ground-Truth Source | Exact Verbatim Signature |
| :--- | :--- | :--- | :--- |
| `1` | [01_builtins_root_and_prelude.md](01_builtins_root_and_prelude.md) (`01_builtins_root_and_prelude` — 3 mods, 74 fns, 4 types) | `std/std_root.aipl` | `pub fn stdlibVersion(): StdlibVersion:` |
| `2` | [02_sys.md](02_sys.md) (`sys` — 9 mods, 109 fns, 10 types) | `std/sys/sys_audio.aipl` | `pub fn sysAudioOpenStream(channels: int, sampleRate: int, bufferFrames: int): int:` |
| `3` | [03_rt.md](03_rt.md) (`rt` — 8 mods, 119 fns, 17 types) | `std/rt/rt_alloc.aipl` | `pub fn rtArenaNew(capacity: int): RtArena:` |
| `4` | [04_alloc.md](04_alloc.md) (`alloc` — 6 mods, 54 fns, 9 types) | `std/alloc/arena.aipl` | `pub fn arenaMark(): int:` |
| `5` | [05_math.md](05_math.md) (`math` — 16 mods, 440 fns, 53 types) | `std/math/bigint.aipl` | `fn normalizeLimbs(limbs: [int]): [int]:` |
| `6` | [06_collections.md](06_collections.md) (`collections` — 14 mods, 220 fns, 34 types) | `std/collections/bitset.aipl` | `pub fn bitsetNew(size: int): DynamicBitSet:` |
| `7` | [07_fmt.md](07_fmt.md) (`fmt` — 5 mods, 125 fns, 12 types) | `std/fmt/fmt_mod.aipl` | `pub fn format(templateStr: str, args: [str]): str:` |
| `8` | [08_regex.md](08_regex.md) (`regex` — 4 mods, 53 fns, 11 types) | `std/regex/regex_compile.aipl` | `pub fn defaultRegexFlags(): RegexFlags:` |
| `9` | [09_time.md](09_time.md) (`time` — 7 mods, 165 fns, 17 types) | `std/time/cooldown_timer.aipl` | `pub fn cooldownTimerNew(d: Duration): CooldownTimer:` |
| `10` | [10_encoding.md](10_encoding.md) (`encoding` — 14 mods, 269 fns, 24 types) | `std/encoding/base64.aipl` | `fn b64CharVal(code: int, urlSafe: bool): int:` |
| `11` | [11_compress.md](11_compress.md) (`compress` — 7 mods, 35 fns, 12 types) | `std/compress/compress_mod.aipl` | `pub fn compressGzip(data: bytes): bytes:` |
| `12` | [12_crypto.md](12_crypto.md) (`crypto` — 8 mods, 64 fns, 14 types) | `std/crypto/aead.aipl` | `fn rotl32(x: int, n: int): int:` |
| `13` | [13_db.md](13_db.md) (`db` — 3 mods, 78 fns, 15 types) | `std/db/kv_wal.aipl` | `fn computeRecordChecksum(op: int, timestamp: int, key: str, value: str): int:` |
| `14` | [14_io.md](14_io.md) (`io` — 6 mods, 54 fns, 10 types) | `std/io/buffered_io.aipl` | `pub fn bufReaderNew(source: [int], capacity: int): BufReader:` |
| `15` | [15_fs.md](15_fs.md) (`fs` — 8 mods, 57 fns, 14 types) | `std/fs/dir.aipl` | `pub fn fsDirEntryNew(path: str, nodeType: FsNodeType, depth: int, sizeBytes: int): DirEntry:` |
| `16` | [16_os.md](16_os.md) (`os` — 6 mods, 145 fns, 24 types) | `std/os/ansi_term.aipl` | `fn escSeq(): str:` |
| `17` | [17_sync.md](17_sync.md) (`sync` — 6 mods, 74 fns, 20 types) | `std/sync/atomic.aipl` | `pub fn atomicBoolNew(initial: bool): AtomicBool:` |
| `18` | [18_thread.md](18_thread.md) (`thread` — 4 mods, 38 fns, 13 types) | `std/thread/fiber.aipl` | `pub fn fiberSpawn(steps: int): Fiber:` |
| `19` | [19_net.md](19_net.md) (`net` — 11 mods, 78 fns, 31 types) | `std/net/dns.aipl` | `pub fn buildStandardQuery(domainName: str, qtype: int, packetId: int = 1): DnsPacket:` |
| `20` | [20_test.md](20_test.md) (`test` — 5 mods, 32 fns, 13 types) | `std/test/assert.aipl` | `pub fn testAssert(cond: bool, msg: str = "Assertion failed"): bool:` |
| `21` | [21_window.md](21_window.md) (`window` — 6 mods, 28 fns, 11 types) | `std/window/app_loop.aipl` | `pub fn createAppConfig(title: str = "AIPL Window", targetFps: int = 60, fixedUpdatesPerSec: int = 60): AppConfig:` |
| `22` | [22_input.md](22_input.md) (`input` — 7 mods, 51 fns, 15 types) | `std/input/action_map.aipl` | `pub fn createActionMap(): InputActionMap:` |
| `23` | [23_asset.md](23_asset.md) (`asset` — 8 mods, 159 fns, 25 types) | `std/asset/asset_bundle.aipl` | `pub fn createAssetBundle(entries: [BundleEntry], data: [int]): AssetBundle:` |
| `24` | [24_audio.md](24_audio.md) (`audio` — 7 mods, 159 fns, 25 types) | `std/audio/audio_codec.aipl` | `fn readU16LEWav(b: [int], off: int): int:` |
| `25` | [25_gfx.md](25_gfx.md) (`gfx` — 10 mods, 55 fns, 32 types) | `std/gfx/color.aipl` | `fn clampByte8(v: int): int:` |
| `26` | [26_gfx2d.md](26_gfx2d.md) (`gfx2d` — 12 mods, 420 fns, 65 types) | `std/gfx2d/batch2d.aipl` | `pub fn createSpriteBatch2D(maxQuads: int = 2048): SpriteBatch2D:` |
| `27` | [27_gfx3d.md](27_gfx3d.md) (`gfx3d` — 11 mods, 107 fns, 26 types) | `std/gfx3d/camera3d.aipl` | `pub fn createPerspectiveCamera3D(pos: Vec3, target: Vec3, fovDeg: float, aspect: float, nearZ: float = 0.1, farZ: float = 1000.0): Camera3D:` |
| `28` | [28_particle.md](28_particle.md) (`particle` — 8 mods, 52 fns, 18 types) | `std/particle/affector.aipl` | `pub fn createGravityAffector(gravityVec: Vec3): ParticleAffector:` |
| `29` | [29_ui.md](29_ui.md) (`ui` — 14 mods, 553 fns, 71 types) | `std/ui/ui_a11y.aipl` | `pub fn createA11yNode(id: int, role: int, label: str, bounds: Rect): A11yNode:` |
| `30` | [30_ecs.md](30_ecs.md) (`ecs` — 8 mods, 29 fns, 13 types) | `std/ecs/archetype.aipl` | `pub fn createArchetypeTable(signatureMask: int, componentIds: [int]): ArchetypeTable:` |
| `31` | [31_spatial.md](31_spatial.md) (`spatial` — 9 mods, 58 fns, 27 types) | `std/spatial/bsp_sector_world3d.aipl` | `pub fn bspSectorWorldNew(): BspSectorWorld3D:` |
| `32` | [32_phys2d.md](32_phys2d.md) (`phys2d` — 10 mods, 46 fns, 22 types) | `std/phys2d/broadphase2d.aipl` | `pub fn dynamicAABBTreeNew(): DynamicAABBTree2D:` |
| `33` | [33_phys3d.md](33_phys3d.md) (`phys3d` — 9 mods, 35 fns, 17 types) | `std/phys3d/character3d.aipl` | `pub fn characterControllerNew(settings: CharacterControllerSettings3D, height: float, radius: float): KinematicCharacterController3D:` |
| `34` | [34_procgen.md](34_procgen.md) (`procgen` — 8 mods, 36 fns, 19 types) | `std/procgen/cellular_automata.aipl` | `fn lcgRandFloat(state: int): (int, float):` |
| `35` | [35_ai.md](35_ai.md) (`ai` — 9 mods, 158 fns, 37 types) | `std/ai/btree_ai.aipl` | `pub fn blackboardNew(): Blackboard:` |
| `36` | [36_mechanics.md](36_mechanics.md) (`mechanics` — 5 mods, 95 fns, 23 types) | `std/mechanics/attribute_pipeline.aipl` | `pub fn evalStatModifierStack(baseValue: float, modifiers: [StatModifier]): float:` |

---

## 3. Domain Lookup Tables & Verification Snippets

### Domain 01: `01_builtins_root_and_prelude` (3 Modules, 74 Functions -> `01_builtins_root_and_prelude.md`)

Layer 0/1: Compiler Intrinsics, Root Metadata & Core Prelude (`Option`, `Result`, Assertions).

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `<compiler_builtins>` | `tests/functions/core/compiler_builtins_test.aipl` | 32 | `// Compiler built-in intrinsic (no import required)` |
| `std/std_root.aipl` | `tests/functions/core/std_root_test.aipl` | 12 | `import * from "std/std_root"` |
| `std/prelude.aipl` | `tests/functions/core/prelude_test.aipl` | 30 | `import * from "std/prelude"` |

```aipl
module tests.functions.core.compiler_builtins_int_test
import { assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"

pub fn test_compiler_builtins_int(): int:
  assertEqInt(int(3.99), 3, "float 3.99 truncates to 3")
  assertEqInt(int(-3.99), -3, "float -3.99 truncates to -3")
  assertEqInt(int("42"), 42, "string 42 parses to 42")
  assertEqInt(int("-1024"), -1024, "negative string parses")
  assertEqInt(int(true), 1, "true -> 1")
  assertEqInt(int(false), 0, "false -> 0")
  ret 0
```

---

### Domain 02: `sys` (9 Modules, 109 Functions -> `02_sys.md`)

Layer 0: Low-Level Host Syscall, Memory, Audio, GPU, FS, Net, Android NDK & FFI Kernels.

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/sys/sys_android.aipl` | `tests/functions/sys/sys_android_test.aipl` | 5 | `import * from "std/sys/sys_android"` |
| `std/sys/sys_audio.aipl` | `tests/functions/sys/sys_audio_test.aipl` | 6 | `import * from "std/sys/sys_audio"` |
| `std/sys/sys_ffi.aipl` | `tests/functions/sys/sys_ffi_test.aipl` | 17 | `import * from "std/sys/sys_ffi"` |
| `std/sys/sys_fs.aipl` | `tests/functions/sys/sys_fs_test.aipl` | 13 | `import * from "std/sys/sys_fs"` |
| `std/sys/sys_gpu.aipl` | `tests/functions/sys/sys_gpu_test.aipl` | 6 | `import * from "std/sys/sys_gpu"` |
| `std/sys/sys_mem.aipl` | `tests/functions/sys/sys_mem_test.aipl` | 28 | `import * from "std/sys/sys_mem"` |
| `std/sys/sys_mod.aipl` | `tests/functions/sys/sys_mod_test.aipl` | 0 | `import * from "std/sys/sys_mod"` |
| `std/sys/sys_net.aipl` | `tests/functions/sys/sys_net_test.aipl` | 12 | `import * from "std/sys/sys_net"` |
| `std/sys/sys_syscall.aipl` | `tests/functions/sys/sys_syscall_test.aipl` | 22 | `import * from "std/sys/sys_syscall"` |

```aipl
module tests.functions.sys.sys_audio_z1_test
import * from "std/sys/sys_audio"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_audio_sysAudioOpenStream_1(): int:
  let arg_channels = 4
  let edge_channels = 1
  let arg_sampleRate = 4
  let edge_sampleRate = 1
  let arg_bufferFrames = 4
  let edge_bufferFrames = 1
  let resNom = sysAudioOpenStream(arg_channels, arg_sampleRate, arg_bufferFrames)
  let resEdge = sysAudioOpenStream(edge_channels, edge_sampleRate, edge_bufferFrames)
  assertEqInt(resNom, 1, "sysAudioOpenStream nominal resNom == 1")
  assertEqInt(resEdge, 1, "sysAudioOpenStream boundary resEdge == 1")
  ret 0
```

---

### Domain 03: `rt` (8 Modules, 119 Functions -> `03_rt.md`)

Layer 0: Pure-AIPL Runtime Allocator, String, Array, Map, Pointer, Audio Mixer & X11 Canvas Bridge.

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/rt/rt_alloc.aipl` | `tests/functions/rt/rt_alloc_test.aipl` | 14 | `import * from "std/rt/rt_alloc"` |
| `std/rt/rt_array.aipl` | `tests/functions/rt/rt_array_test.aipl` | 14 | `import * from "std/rt/rt_array"` |
| `std/rt/rt_audio_mixer.aipl` | `tests/functions/rt/rt_audio_mixer_test.aipl` | 10 | `import * from "std/rt/rt_audio_mixer"` |
| `std/rt/rt_canvas_x11.aipl` | `tests/functions/rt/rt_canvas_x11_test.aipl` | 16 | `import * from "std/rt/rt_canvas_x11"` |
| `std/rt/rt_map.aipl` | `tests/functions/rt/rt_map_test.aipl` | 16 | `import * from "std/rt/rt_map"` |
| `std/rt/rt_mod.aipl` | `tests/functions/rt/rt_mod_test.aipl` | 0 | `import * from "std/rt/rt_mod"` |
| `std/rt/rt_ptr.aipl` | `tests/functions/rt/rt_ptr_test.aipl` | 34 | `import * from "std/rt/rt_ptr"` |
| `std/rt/rt_string.aipl` | `tests/functions/rt/rt_string_test.aipl` | 15 | `import * from "std/rt/rt_string"` |

```aipl
module tests.functions.rt.rt_alloc_z1_test
import * from "std/rt/rt_alloc"
import { ptrAlloc, ptrFree, ptrReadI64, ptrWriteI64, ptrMemset } from "std/rt/rt_ptr"
import { ptrAlloc as sysPtrAlloc } from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rt_alloc_rtArenaNew_1(): int:
  let arg_capacity = 4
  let edge_capacity = 1
  let resNom = rtArenaNew(arg_capacity)
  let resEdge = rtArenaNew(edge_capacity)
  assertEqInt(resNom.capacity, 4, "rtArenaNew nominal resNom.capacity == 4")
  assertEqInt(resEdge.capacity, 1, "rtArenaNew boundary resEdge.capacity == 1")
  ret 0
```

---

### Domain 04: `alloc` (6 Modules, 54 Functions -> `04_alloc.md`)

Layer 0: Zero-GC Deterministic Memory Allocators (Bump Arena, Object Pool, Page/Slab, Ring, GPA).

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/alloc/alloc_mod.aipl` | `tests/functions/alloc/alloc_mod_test.aipl` | 0 | `import * from "std/alloc/alloc_mod"` |
| `std/alloc/arena.aipl` | `tests/functions/alloc/arena_test.aipl` | 14 | `import * from "std/alloc/arena"` |
| `std/alloc/gpa.aipl` | `tests/functions/alloc/gpa_test.aipl` | 7 | `import * from "std/alloc/gpa"` |
| `std/alloc/page_alloc.aipl` | `tests/functions/alloc/page_alloc_test.aipl` | 7 | `import * from "std/alloc/page_alloc"` |
| `std/alloc/pool_alloc.aipl` | `tests/functions/alloc/pool_alloc_test.aipl` | 20 | `import * from "std/alloc/pool_alloc"` |
| `std/alloc/ring_alloc.aipl` | `tests/functions/alloc/ring_alloc_test.aipl` | 6 | `import * from "std/alloc/ring_alloc"` |

```aipl
module tests.functions.alloc.arena_z1_test
import * from "std/alloc/arena"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_arena_arenaMark_1(): int:
  let resNom = arenaMark()
  let resEdge = arenaMark()
  assertEqInt(resNom, 0, "arenaMark nominal resNom == 0")
  assertEqInt(resEdge, 0, "arenaMark boundary resEdge == 0")
  ret 0
```

---

### Domain 05: `math` (16 Modules, 440 Functions -> `05_math.md`)

Layer 1: Vectors, Matrices, Quaternions, Fixed-Point Q32.32, Curves, Geometry, BigInt, Stats & SIMD.

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/math/bigint.aipl` | `tests/functions/math/bigint_test.aipl` | 22 | `import * from "std/math/bigint"` |
| `std/math/complex_fft.aipl` | `tests/functions/math/complex_fft_test.aipl` | 7 | `import * from "std/math/complex_fft"` |
| `std/math/consts.aipl` | `tests/functions/math/consts_test.aipl` | 48 | `import * from "std/math/consts"` |
| `std/math/curve.aipl` | `tests/functions/math/curve_test.aipl` | 20 | `import * from "std/math/curve"` |
| `std/math/ease.aipl` | `tests/functions/math/ease_test.aipl` | 22 | `import * from "std/math/ease"` |
| `std/math/fixed_point.aipl` | `tests/functions/math/fixed_point_test.aipl` | 13 | `import * from "std/math/fixed_point"` |
| `std/math/geom2d.aipl` | `tests/functions/math/geom2d_test.aipl` | 52 | `import * from "std/math/geom2d"` |
| `std/math/geom3d.aipl` | `tests/functions/math/geom3d_test.aipl` | 40 | `import * from "std/math/geom3d"` |
| `std/math/mat.aipl` | `tests/functions/math/mat_test.aipl` | 23 | `import * from "std/math/mat"` |
| `std/math/math_mod.aipl` | `tests/functions/math/math_mod_test.aipl` | 0 | `import * from "std/math/math_mod"` |
| `std/math/prng.aipl` | `tests/functions/math/prng_test.aipl` | 26 | `import * from "std/math/prng"` |
| `std/math/prob_stats.aipl` | `tests/functions/math/prob_stats_test.aipl` | 25 | `import * from "std/math/prob_stats"` |
| `std/math/quat.aipl` | `tests/functions/math/quat_test.aipl` | 11 | `import * from "std/math/quat"` |
| `std/math/simd.aipl` | `tests/functions/math/simd_test.aipl` | 32 | `import * from "std/math/simd"` |
| `std/math/trig.aipl` | `tests/functions/math/trig_test.aipl` | 36 | `import * from "std/math/trig"` |
| `std/math/vec_math.aipl` | `tests/functions/math/vec_math_test.aipl` | 63 | `import * from "std/math/vec_math"` |

```aipl
module tests.functions.math.bigint_z1_test
import * from "std/math/bigint"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bigint_normalizeLimbs_1(): int:
  let arg_limbs = [4]
  let edge_limbs = []
  let resNom = normalizeLimbs(arg_limbs)
  let resEdge = normalizeLimbs(edge_limbs)
  assertEqInt(resNom.len(), 1, "normalizeLimbs nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "normalizeLimbs boundary resEdge.len() == 1")
  ret 0
```

---

### Domain 06: `collections` (14 Modules, 220 Functions -> `06_collections.md`)

Layer 1: Cache-Friendly Contiguous Containers, Maps, Heaps, Graphs & Spatial Trees (Quadtree/Octree/BVH).

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/collections/bitset.aipl` | `tests/functions/collections/bitset_test.aipl` | 15 | `import * from "std/collections/bitset"` |
| `std/collections/btree_map.aipl` | `tests/functions/collections/btree_map_test.aipl` | 12 | `import * from "std/collections/btree_map"` |
| `std/collections/bvh_tree.aipl` | `tests/functions/collections/bvh_tree_test.aipl` | 5 | `import * from "std/collections/bvh_tree"` |
| `std/collections/collections_mod.aipl` | `tests/functions/collections/collections_mod_test.aipl` | 0 | `import * from "std/collections/collections_mod"` |
| `std/collections/deque.aipl` | `tests/functions/collections/deque_test.aipl` | 38 | `import * from "std/collections/deque"` |
| `std/collections/dyn_vec.aipl` | `tests/functions/collections/dyn_vec_test.aipl` | 28 | `import * from "std/collections/dyn_vec"` |
| `std/collections/graph_topology.aipl` | `tests/functions/collections/graph_topology_test.aipl` | 8 | `import * from "std/collections/graph_topology"` |
| `std/collections/grid2d_array.aipl` | `tests/functions/collections/grid2d_array_test.aipl` | 12 | `import * from "std/collections/grid2d_array"` |
| `std/collections/hash_map.aipl` | `tests/functions/collections/hash_map_test.aipl` | 38 | `import * from "std/collections/hash_map"` |
| `std/collections/octree.aipl` | `tests/functions/collections/octree_test.aipl` | 6 | `import * from "std/collections/octree"` |
| `std/collections/priority_queue.aipl` | `tests/functions/collections/priority_queue_test.aipl` | 37 | `import * from "std/collections/priority_queue"` |
| `std/collections/quadtree.aipl` | `tests/functions/collections/quadtree_test.aipl` | 6 | `import * from "std/collections/quadtree"` |
| `std/collections/sparse_set.aipl` | `tests/functions/collections/sparse_set_test.aipl` | 10 | `import * from "std/collections/sparse_set"` |
| `std/collections/spatial_hash.aipl` | `tests/functions/collections/spatial_hash_test.aipl` | 5 | `import * from "std/collections/spatial_hash"` |

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

### Domain 07: `fmt` (5 Modules, 125 Functions -> `07_fmt.md`)

Layer 1: Zero-Allocation String Formatting, Numeric Parsers, Hexdumps, ASCII Tables & Unicode.

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/fmt/fmt_mod.aipl` | `tests/functions/fmt/fmt_mod_test.aipl` | 2 | `import * from "std/fmt/fmt_mod"` |
| `std/fmt/num_parse.aipl` | `tests/functions/fmt/num_parse_test.aipl` | 21 | `import * from "std/fmt/num_parse"` |
| `std/fmt/str_builder.aipl` | `tests/functions/fmt/str_builder_test.aipl` | 79 | `import * from "std/fmt/str_builder"` |
| `std/fmt/text_print.aipl` | `tests/functions/fmt/text_print_test.aipl` | 10 | `import * from "std/fmt/text_print"` |
| `std/fmt/unicode_utf8.aipl` | `tests/functions/fmt/unicode_utf8_test.aipl` | 13 | `import * from "std/fmt/unicode_utf8"` |

```aipl
module tests.functions.fmt.fmt_mod_z1_test
import * from "std/fmt/fmt_mod"
import { formatInterpolated, TableColumn, tableNew } from "std/fmt/text_print"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fmt_mod_format_1(): int:
  let arg_templateStr = "test"
  let edge_templateStr = "a"
  let arg_args = ["test"]
  let edge_args = []
  let resNom = format(arg_templateStr, arg_args)
  let resEdge = format(edge_templateStr, edge_args)
  assertEqStr(resNom, "test", "format nominal string matches")
  assertEqStr(resEdge, "a", "format boundary string matches")
  ret 0
```

---

### Domain 08: `regex` (4 Modules, 53 Functions -> `08_regex.md`)

Layer 1: Linear-Time Thompson NFA / PikeVM Regular Expressions, Globbing & Myers O(ND) Diff.

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/regex/regex_compile.aipl` | `tests/functions/regex/regex_compile_test.aipl` | 19 | `import * from "std/regex/regex_compile"` |
| `std/regex/regex_mod.aipl` | `tests/functions/regex/regex_mod_test.aipl` | 9 | `import * from "std/regex/regex_mod"` |
| `std/regex/regex_vm.aipl` | `tests/functions/regex/regex_vm_test.aipl` | 16 | `import * from "std/regex/regex_vm"` |
| `std/regex/text_diff.aipl` | `tests/functions/regex/text_diff_test.aipl` | 9 | `import * from "std/regex/text_diff"` |

```aipl
module tests.functions.regex.regex_compile_z1_test
import * from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_compile_defaultRegexFlags_1(): int:
  let resNom = defaultRegexFlags()
  let resEdge = defaultRegexFlags()
  assert(resNom.ignoreCase == false, "defaultRegexFlags nominal resNom.ignoreCase == false")
  assert(resEdge.ignoreCase == false, "defaultRegexFlags boundary resEdge.ignoreCase == false")
  ret 0
```

---

### Domain 09: `time` (7 Modules, 165 Functions -> `09_time.md`)

Layer 1: Monotonic Clocks, ISO-8601 DateTime, Durations, Stopwatches, Cron & Timer Wheels.

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/time/cooldown_timer.aipl` | `tests/functions/time/cooldown_timer_test.aipl` | 27 | `import * from "std/time/cooldown_timer"` |
| `std/time/cron_schedule.aipl` | `tests/functions/time/cron_schedule_test.aipl` | 8 | `import * from "std/time/cron_schedule"` |
| `std/time/datetime.aipl` | `tests/functions/time/datetime_test.aipl` | 44 | `import * from "std/time/datetime"` |
| `std/time/duration.aipl` | `tests/functions/time/duration_test.aipl` | 44 | `import * from "std/time/duration"` |
| `std/time/frame_pacer.aipl` | `tests/functions/time/frame_pacer_test.aipl` | 9 | `import * from "std/time/frame_pacer"` |
| `std/time/instant.aipl` | `tests/functions/time/instant_test.aipl` | 28 | `import * from "std/time/instant"` |
| `std/time/time_mod.aipl` | `tests/functions/time/time_mod_test.aipl` | 5 | `import * from "std/time/time_mod"` |

```aipl
module tests.functions.time.cooldown_timer_z1_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_cooldownTimerNew_1(): int:
  let arg_d = Duration(nanos = 4)
  let edge_d = Duration(nanos = 1)
  let resNom = cooldownTimerNew(arg_d)
  let resEdge = cooldownTimerNew(edge_d)
  assert(resNom.isReady == true, "cooldownTimerNew nominal resNom.isReady == true")
  assert(resEdge.isReady == true, "cooldownTimerNew boundary resEdge.isReady == true")
  ret 0
```

---

### Domain 10: `encoding` (14 Modules, 269 Functions -> `10_encoding.md`)

Layer 2: Structured Data Serialization (JSON, YAML, TOML, CSV, XML, AXML Manifest, HTML, Markdown, INI, Base64, Bincode, SemVer, QR, UTF-8).

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/encoding/axml_manifest.aipl` | `tests/functions/encoding/axml_manifest_test.aipl` | 4 | `import * from "std/encoding/axml_manifest"` |
| `std/encoding/base64.aipl` | `tests/functions/encoding/base64_test.aipl` | 18 | `import * from "std/encoding/base64"` |
| `std/encoding/bincode.aipl` | `tests/functions/encoding/bincode_test.aipl` | 25 | `import * from "std/encoding/bincode"` |
| `std/encoding/csv.aipl` | `tests/functions/encoding/csv_test.aipl` | 18 | `import * from "std/encoding/csv"` |
| `std/encoding/encoding_mod.aipl` | `tests/functions/encoding/encoding_mod_test.aipl` | 0 | `import * from "std/encoding/encoding_mod"` |
| `std/encoding/hex.aipl` | `tests/functions/encoding/hex_test.aipl` | 12 | `import * from "std/encoding/hex"` |
| `std/encoding/html_dom.aipl` | `tests/functions/encoding/html_dom_test.aipl` | 20 | `import * from "std/encoding/html_dom"` |
| `std/encoding/ini_dotenv.aipl` | `tests/functions/encoding/ini_dotenv_test.aipl` | 18 | `import * from "std/encoding/ini_dotenv"` |
| `std/encoding/json.aipl` | `tests/functions/encoding/json_test.aipl` | 58 | `import * from "std/encoding/json"` |
| `std/encoding/markdown.aipl` | `tests/functions/encoding/markdown_test.aipl` | 16 | `import * from "std/encoding/markdown"` |
| `std/encoding/qrcode_semver.aipl` | `tests/functions/encoding/qrcode_semver_test.aipl` | 25 | `import * from "std/encoding/qrcode_semver"` |
| `std/encoding/toml.aipl` | `tests/functions/encoding/toml_test.aipl` | 18 | `import * from "std/encoding/toml"` |
| `std/encoding/xml.aipl` | `tests/functions/encoding/xml_test.aipl` | 19 | `import * from "std/encoding/xml"` |
| `std/encoding/yaml.aipl` | `tests/functions/encoding/yaml_test.aipl` | 18 | `import * from "std/encoding/yaml"` |

```aipl
module tests.functions.encoding.base64_z1_test
import * from "std/encoding/base64"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_base64_b64CharVal_1(): int:
  let arg_code = 2
  let edge_code = 0
  let arg_urlSafe = true
  let edge_urlSafe = false
  let resNom = b64CharVal(arg_code, arg_urlSafe)
  let resEdge = b64CharVal(edge_code, edge_urlSafe)
  assertEqInt(resNom, -1, "b64CharVal nominal resNom == -1")
  assertEqInt(resEdge, -1, "b64CharVal boundary resEdge == -1")
  ret 0
```

---

### Domain 11: `compress` (7 Modules, 35 Functions -> `11_compress.md`)

Layer 2: Lossless Compression & Archiving (Deflate, Gzip, LZ4, Zstandard, APK Zip, POSIX Tar).

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/compress/apk_zip_writer.aipl` | `tests/functions/compress/apk_zip_writer_test.aipl` | 4 | `import * from "std/compress/apk_zip_writer"` |
| `std/compress/compress_mod.aipl` | `tests/functions/compress/compress_mod_test.aipl` | 6 | `import * from "std/compress/compress_mod"` |
| `std/compress/deflate.aipl` | `tests/functions/compress/deflate_test.aipl` | 4 | `import * from "std/compress/deflate"` |
| `std/compress/gzip.aipl` | `tests/functions/compress/gzip_test.aipl` | 6 | `import * from "std/compress/gzip"` |
| `std/compress/lz4.aipl` | `tests/functions/compress/lz4_test.aipl` | 4 | `import * from "std/compress/lz4"` |
| `std/compress/tar_archive.aipl` | `tests/functions/compress/tar_archive_test.aipl` | 9 | `import * from "std/compress/tar_archive"` |
| `std/compress/zstd.aipl` | `tests/functions/compress/zstd_test.aipl` | 2 | `import * from "std/compress/zstd"` |

```aipl
module tests.functions.compress.compress_mod_z1_test
import * from "std/compress/compress_mod"
import { DeflateOptions, HuffmanTree, Lz77Token, buildHuffmanTree, lz77FindMatches, deflateCompress, deflateDecompress } from "std/compress/deflate"
import { GzipHeader, ZlibHeader, computeAdler32, computeCrc32, gzipCompress, gzipDecompress, zlibCompress, zlibDecompress } from "std/compress/gzip"
import { Lz4BlockHeader, Lz4FrameHeader, lz4CompressBlock, lz4DecompressBlock, lz4CompressFrame, lz4DecompressFrame } from "std/compress/lz4"
import { ZstdFrameHeader, ZstdBlockHeader, zstdCompress, zstdDecompress } from "std/compress/zstd"
import { TarEntry, TarArchive, tarPack, tarUnpack } from "std/compress/tar_archive"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_compress_mod_compressGzip_1(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = compressGzip(arg_data)
  let resEdge = compressGzip(edge_data)
  assertEqInt(resNom.len(), 23, "compressGzip nominal resNom.len() == 23")
  assertEqInt(resEdge.len(), 20, "compressGzip boundary resEdge.len() == 20")
  ret 0
```

---

### Domain 12: `crypto` (8 Modules, 64 Functions -> `12_crypto.md`)

Layer 2: Cryptographic Hashing, AEAD & Signatures (SHA-256, BLAKE3, HMAC, ChaCha20-Poly1305, Ed25519, APK Sig v2, Argon2id, CSPRNG).

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/crypto/aead.aipl` | `tests/functions/crypto/aead_test.aipl` | 11 | `import * from "std/crypto/aead"` |
| `std/crypto/apk_Sig_v2.aipl` | `tests/functions/crypto/apk_sig_v2_test.aipl` | 3 | `import * from "std/crypto/apk_Sig_v2"` |
| `std/crypto/crypto_mod.aipl` | `tests/functions/crypto/crypto_mod_test.aipl` | 4 | `import * from "std/crypto/crypto_mod"` |
| `std/crypto/csprng.aipl` | `tests/functions/crypto/csprng_test.aipl` | 12 | `import * from "std/crypto/csprng"` |
| `std/crypto/hash.aipl` | `tests/functions/crypto/hash_test.aipl` | 18 | `import * from "std/crypto/hash"` |
| `std/crypto/hmac.aipl` | `tests/functions/crypto/hmac_test.aipl` | 6 | `import * from "std/crypto/hmac"` |
| `std/crypto/kdf.aipl` | `tests/functions/crypto/kdf_test.aipl` | 6 | `import * from "std/crypto/kdf"` |
| `std/crypto/tls.aipl` | `tests/functions/crypto/tls_test.aipl` | 4 | `import * from "std/crypto/tls"` |

```aipl
module tests.functions.crypto.aead_z1_test
import * from "std/crypto/aead"
import { hmacSha256, constantTimeEqual } from "std/crypto/hmac"
import { sha256 } from "std/crypto/hash"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_aead_rotl32_1(): int:
  let arg_x = 1
  let edge_x = 0
  let arg_n = 4
  let edge_n = 1
  let resNom = rotl32(arg_x, arg_n)
  let resEdge = rotl32(edge_x, edge_n)
  assertEqInt(resNom, 16, "rotl32 nominal resNom == 16")
  assertEqInt(resEdge, 0, "rotl32 boundary resEdge == 0")
  ret 0
```

---

### Domain 13: `db` (3 Modules, 78 Functions -> `13_db.md`)

Layer 2: Embedded ACID Persistence (CRC32 Append-Only WAL KV Store & B-Tree Relational SQLite Engine).

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/db/db_mod.aipl` | `tests/functions/db/db_mod_test.aipl` | 0 | `import * from "std/db/db_mod"` |
| `std/db/kv_wal.aipl` | `tests/functions/db/kv_wal_test.aipl` | 28 | `import * from "std/db/kv_wal"` |
| `std/db/sqlite.aipl` | `tests/functions/db/sqlite_test.aipl` | 50 | `import * from "std/db/sqlite"` |

```aipl
module tests.functions.db.kv_wal_z1_test
import * from "std/db/kv_wal"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_kv_wal_computeRecordChecksum_1(): int:
  let arg_op = 2
  let edge_op = 0
  let arg_timestamp = 4
  let edge_timestamp = 1
  let arg_key = "test"
  let edge_key = "a"
  let arg_value = "test"
  let edge_value = "a"
  let resNom = computeRecordChecksum(arg_op, arg_timestamp, arg_key, arg_value)
  let resEdge = computeRecordChecksum(edge_op, edge_timestamp, edge_key, edge_value)
  assertEqInt(resNom, 2159647394, "computeRecordChecksum nominal resNom == 2159647394")
  assertEqInt(resEdge, 74317735, "computeRecordChecksum boundary resEdge == 74317735")
  ret 0
```

---

### Domain 14: `io` (6 Modules, 54 Functions -> `14_io.md`)

Layer 3: Buffered Streaming I/O, In-Memory Cursors, Ring Pipes & Reader/Writer Traits.

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/io/buffered_io.aipl` | `tests/functions/io/buffered_io_test.aipl` | 13 | `import * from "std/io/buffered_io"` |
| `std/io/byte_cursor.aipl` | `tests/functions/io/byte_cursor_test.aipl` | 14 | `import * from "std/io/byte_cursor"` |
| `std/io/io_copy.aipl` | `tests/functions/io/io_copy_test.aipl` | 10 | `import * from "std/io/io_copy"` |
| `std/io/io_mod.aipl` | `tests/functions/io/io_mod_test.aipl` | 0 | `import * from "std/io/io_mod"` |
| `std/io/io_traits.aipl` | `tests/functions/io/io_traits_test.aipl` | 7 | `import * from "std/io/io_traits"` |
| `std/io/stdio.aipl` | `tests/functions/io/stdio_test.aipl` | 10 | `import * from "std/io/stdio"` |

```aipl
module tests.functions.io.buffered_io_z1_test
import * from "std/io/buffered_io"
import * from "std/io/io_traits"
import * from "std/io/byte_cursor"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_buffered_io_bufReaderNew_1(): int:
  let arg_source = [2]
  let edge_source = []
  let arg_capacity = 4
  let edge_capacity = 1
  let resNom = bufReaderNew(arg_source, arg_capacity)
  let resEdge = bufReaderNew(edge_source, edge_capacity)
  assertEqInt(resNom.source.len(), 1, "bufReaderNew nominal resNom.source.len() == 1")
  assertEqInt(resEdge.source.len(), 0, "bufReaderNew boundary resEdge.source.len() == 0")
  ret 0
```

---

### Domain 15: `fs` (8 Modules, 57 Functions -> `15_fs.md`)

Layer 3: Capability-Checked Filesystem Operations, Path Sanitization, Android VFS, Mobile Watchers & Metadata.

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/fs/android_vfs.aipl` | `tests/functions/fs/android_vfs_test.aipl` | 4 | `import * from "std/fs/android_vfs"` |
| `std/fs/dir.aipl` | `tests/functions/fs/dir_test.aipl` | 8 | `import * from "std/fs/dir"` |
| `std/fs/file.aipl` | `tests/functions/fs/file_test.aipl` | 14 | `import * from "std/fs/file"` |
| `std/fs/file_watcher_mobile.aipl` | `tests/functions/fs/file_watcher_mobile_test.aipl` | 4 | `import * from "std/fs/file_watcher_mobile"` |
| `std/fs/fs_mod.aipl` | `tests/functions/fs/fs_mod_test.aipl` | 0 | `import * from "std/fs/fs_mod"` |
| `std/fs/metadata.aipl` | `tests/functions/fs/metadata_test.aipl` | 9 | `import * from "std/fs/metadata"` |
| `std/fs/path.aipl` | `tests/functions/fs/path_test.aipl` | 13 | `import * from "std/fs/path"` |
| `std/fs/watch.aipl` | `tests/functions/fs/watch_test.aipl` | 5 | `import * from "std/fs/watch"` |

```aipl
module tests.functions.fs.dir_z1_test
import * from "std/fs/dir"
import * from "std/fs/path"
import * from "std/fs/metadata"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dir_fsDirEntryNew_1(): int:
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let arg_nodeType = FsNodeType.RegularFile
  let edge_nodeType = FsNodeType.RegularFile
  let arg_depth = 4
  let edge_depth = 1
  let arg_sizeBytes = 4
  let edge_sizeBytes = 1
  let resNom = fsDirEntryNew(arg_path, arg_nodeType, arg_depth, arg_sizeBytes)
  let resEdge = fsDirEntryNew(edge_path, edge_nodeType, edge_depth, edge_sizeBytes)
  assertEqStr(resNom.path, "/tmp/aipl_test_path", "fsDirEntryNew nominal string matches")
  assertEqStr(resEdge.path, "/tmp/aipl_test_path", "fsDirEntryNew boundary string matches")
  ret 0
```

---

### Domain 16: `os` (6 Modules, 145 Functions -> `16_os.md`)

Layer 3: CLI Argument Parser, Environment Variables, Subprocesses, Signals & ANSI Terminal TUI.

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/os/ansi_term.aipl` | `tests/functions/os/ansi_term_test.aipl` | 55 | `import * from "std/os/ansi_term"` |
| `std/os/cli_args.aipl` | `tests/functions/os/cli_args_test.aipl` | 28 | `import * from "std/os/cli_args"` |
| `std/os/env.aipl` | `tests/functions/os/env_test.aipl` | 29 | `import * from "std/os/env"` |
| `std/os/os_mod.aipl` | `tests/functions/os/os_mod_test.aipl` | 0 | `import * from "std/os/os_mod"` |
| `std/os/process.aipl` | `tests/functions/os/process_test.aipl` | 25 | `import * from "std/os/process"` |
| `std/os/signal.aipl` | `tests/functions/os/signal_test.aipl` | 8 | `import * from "std/os/signal"` |

```aipl
module tests.functions.os.ansi_term_z1_test
import * from "std/os/ansi_term"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ansi_term_escSeq_1(): int:
  let resNom = escSeq()
  let resEdge = escSeq()
  assertEqStr(resNom, "[", "escSeq nominal string matches")
  assertEqStr(resEdge, "[", "escSeq boundary string matches")
  ret 0
```

---

### Domain 17: `sync` (6 Modules, 74 Functions -> `17_sync.md`)

Layer 3: Lock-Free Atomics, Mutexes, RwLocks, Semaphores, WaitGroups & Bounded MPSC Channels.

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/sync/atomic.aipl` | `tests/functions/sync/atomic_test.aipl` | 19 | `import * from "std/sync/atomic"` |
| `std/sync/barrier.aipl` | `tests/functions/sync/barrier_test.aipl` | 13 | `import * from "std/sync/barrier"` |
| `std/sync/channel.aipl` | `tests/functions/sync/channel_test.aipl` | 18 | `import * from "std/sync/channel"` |
| `std/sync/mutex.aipl` | `tests/functions/sync/mutex_test.aipl` | 12 | `import * from "std/sync/mutex"` |
| `std/sync/rwlock.aipl` | `tests/functions/sync/rwlock_test.aipl` | 12 | `import * from "std/sync/rwlock"` |
| `std/sync/sync_mod.aipl` | `tests/functions/sync/sync_mod_test.aipl` | 0 | `import * from "std/sync/sync_mod"` |

```aipl
module tests.functions.sync.atomic_z1_test
import * from "std/sync/atomic"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atomic_atomicBoolNew_1(): int:
  let arg_initial = true
  let edge_initial = false
  let resNom = atomicBoolNew(arg_initial)
  let resEdge = atomicBoolNew(edge_initial)
  assert(resNom.val == true, "atomicBoolNew nominal resNom.val == true")
  assert(resEdge.val == false, "atomicBoolNew boundary resEdge.val == false")
  ret 0
```

---

### Domain 18: `thread` (4 Modules, 38 Functions -> `18_thread.md`)

Layer 3: OS Thread Pools, Stackful Cooperative Fibers & Work-Stealing DAG Job System.

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/thread/fiber.aipl` | `tests/functions/thread/fiber_test.aipl` | 11 | `import * from "std/thread/fiber"` |
| `std/thread/job_system.aipl` | `tests/functions/thread/job_system_test.aipl` | 16 | `import * from "std/thread/job_system"` |
| `std/thread/thread_local.aipl` | `tests/functions/thread/thread_local_test.aipl` | 11 | `import * from "std/thread/thread_local"` |
| `std/thread/thread_mod.aipl` | `tests/functions/thread/thread_mod_test.aipl` | 0 | `import * from "std/thread/thread_mod"` |

```aipl
module tests.functions.thread.fiber_z1_test
import * from "std/thread/fiber"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fiber_fiberSpawn_1(): int:
  let arg_steps = 4
  let edge_steps = 1
  let resNom = fiberSpawn(arg_steps)
  let resEdge = fiberSpawn(edge_steps)
  assertEqInt(resNom.id, 104, "fiberSpawn nominal resNom.id == 104")
  assertEqInt(resEdge.id, 101, "fiberSpawn boundary resEdge.id == 101")
  ret 0
```

---

### Domain 19: `net` (11 Modules, 78 Functions -> `19_net.md`)

Layer 3: Networking Stack (IPv4/IPv6, DNS, TCP, UDP, Reliable UDP, HTTP/1.1 Client/Server, WebSocket, Live Reload Sync, JSON-RPC 2.0).

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/net/dns.aipl` | `tests/functions/net/dns_test.aipl` | 5 | `import * from "std/net/dns"` |
| `std/net/http_client.aipl` | `tests/functions/net/http_client_test.aipl` | 7 | `import * from "std/net/http_client"` |
| `std/net/http_server.aipl` | `tests/functions/net/http_server_test.aipl` | 5 | `import * from "std/net/http_server"` |
| `std/net/live_reload_sync.aipl` | `tests/functions/net/live_reload_sync_test.aipl` | 3 | `import * from "std/net/live_reload_sync"` |
| `std/net/net_addr.aipl` | `tests/functions/net/net_addr_test.aipl` | 17 | `import * from "std/net/net_addr"` |
| `std/net/net_mod.aipl` | `tests/functions/net/net_mod_test.aipl` | 0 | `import * from "std/net/net_mod"` |
| `std/net/rpc.aipl` | `tests/functions/net/rpc_test.aipl` | 6 | `import * from "std/net/rpc"` |
| `std/net/rudp.aipl` | `tests/functions/net/rudp_test.aipl` | 7 | `import * from "std/net/rudp"` |
| `std/net/tcp.aipl` | `tests/functions/net/tcp_test.aipl` | 10 | `import * from "std/net/tcp"` |
| `std/net/udp.aipl` | `tests/functions/net/udp_test.aipl` | 7 | `import * from "std/net/udp"` |
| `std/net/ws.aipl` | `tests/functions/net/ws_test.aipl` | 11 | `import * from "std/net/ws"` |

```aipl
module tests.functions.net.dns_z1_test
import * from "std/net/dns"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dns_buildStandardQuery_1(): int:
  let arg_domainName = "test"
  let edge_domainName = "a"
  let arg_qtype = 1
  let edge_qtype = 0
  let arg_packetId = 4
  let edge_packetId = 1
  let resNom = buildStandardQuery(arg_domainName, arg_qtype, arg_packetId)
  let resEdge = buildStandardQuery(edge_domainName, edge_qtype, edge_packetId)
  assertEqInt(resNom.id, 4, "buildStandardQuery nominal resNom.id == 4")
  assertEqInt(resEdge.id, 1, "buildStandardQuery boundary resEdge.id == 1")
  ret 0
```

---

### Domain 20: `test` (5 Modules, 32 Functions -> `20_test.md`)

Layer 3: Assertion Matchers, TAP/JUnit Test Runner, Microbenchmarking, PRNG Fuzzing/Shrinking & Call-Spy Mocking.

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/test/assert.aipl` | `tests/functions/test/assert_test.aipl` | 10 | `import * from "std/test/assert"` |
| `std/test/bench.aipl` | `tests/functions/test/bench_test.aipl` | 7 | `import * from "std/test/bench"` |
| `std/test/fuzz.aipl` | `tests/functions/test/fuzz_test.aipl` | 9 | `import * from "std/test/fuzz"` |
| `std/test/test_mod.aipl` | `tests/functions/test/test_mod_test.aipl` | 0 | `import * from "std/test/test_mod"` |
| `std/test/test_runner.aipl` | `tests/functions/test/test_runner_test.aipl` | 6 | `import * from "std/test/test_runner"` |

```aipl
module tests.functions.test.assert_z1_test
import * from "std/test/assert"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_assert_testAssert_1(): int:
  let arg_cond = true
  let edge_cond = true
  let arg_msg = "test"
  let edge_msg = "test"
  let resNom = testAssert(arg_cond, arg_msg)
  let resEdge = testAssert(edge_cond, edge_msg)
  assert(resNom == true, "testAssert nominal resNom == true")
  assert(resEdge == true, "testAssert boundary resEdge == true")
  ret 0
```

---

### Domain 21: `window` (6 Modules, 28 Functions -> `21_window.md`)

Layer 4: Cross-Platform Window Lifecycle, Fixed-Timestep App Loop, HiDPI Monitors, Cursors & Clipboard.

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/window/app_loop.aipl` | `tests/functions/window/app_loop_test.aipl` | 6 | `import * from "std/window/app_loop"` |
| `std/window/clipboard.aipl` | `tests/functions/window/clipboard_test.aipl` | 5 | `import * from "std/window/clipboard"` |
| `std/window/cursor.aipl` | `tests/functions/window/cursor_test.aipl` | 5 | `import * from "std/window/cursor"` |
| `std/window/display.aipl` | `tests/functions/window/display_test.aipl` | 6 | `import * from "std/window/display"` |
| `std/window/surface.aipl` | `tests/functions/window/surface_test.aipl` | 6 | `import * from "std/window/surface"` |
| `std/window/window_mod.aipl` | `tests/functions/window/window_mod_test.aipl` | 0 | `import * from "std/window/window_mod"` |

```aipl
module tests.functions.window.app_loop_z1_test
import * from "std/window/app_loop"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_app_loop_createAppConfig_1(): int:
  let arg_title = "test"
  let edge_title = "a"
  let arg_targetFps = 2
  let edge_targetFps = 0
  let arg_fixedUpdatesPerSec = 1
  let edge_fixedUpdatesPerSec = 0
  let resNom = createAppConfig(arg_title, arg_targetFps, arg_fixedUpdatesPerSec)
  let resEdge = createAppConfig(edge_title, edge_targetFps, edge_fixedUpdatesPerSec)
  assertEqStr(resNom.title, "test", "createAppConfig nominal string matches")
  assertEqStr(resEdge.title, "a", "createAppConfig boundary string matches")
  ret 0
```

---

### Domain 22: `input` (7 Modules, 51 Functions -> `22_input.md`)

Layer 4: Multi-Device Input Polling (Keyboard, Mouse, Radial-Deadzone Gamepad, Multi-Touch, Gestures & ActionMap).

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/input/action_map.aipl` | `tests/functions/input/action_map_test.aipl` | 10 | `import * from "std/input/action_map"` |
| `std/input/gamepad.aipl` | `tests/functions/input/gamepad_test.aipl` | 9 | `import * from "std/input/gamepad"` |
| `std/input/gesture.aipl` | `tests/functions/input/gesture_test.aipl` | 6 | `import * from "std/input/gesture"` |
| `std/input/input_mod.aipl` | `tests/functions/input/input_mod_test.aipl` | 0 | `import * from "std/input/input_mod"` |
| `std/input/keyboard.aipl` | `tests/functions/input/keyboard_test.aipl` | 8 | `import * from "std/input/keyboard"` |
| `std/input/mouse.aipl` | `tests/functions/input/mouse_test.aipl` | 11 | `import * from "std/input/mouse"` |
| `std/input/touch.aipl` | `tests/functions/input/touch_test.aipl` | 7 | `import * from "std/input/touch"` |

```aipl
module tests.functions.input.action_map_z1_test
import * from "std/input/action_map"
import { KeyboardState, isKeyDown, hasModifier } from "std/input/keyboard"
import { MouseState, isMouseButtonDown } from "std/input/mouse"
import { GamepadState, isGamepadButtonDown } from "std/input/gamepad"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_action_map_createActionMap_1(): int:
  let resNom = createActionMap()
  let resEdge = createActionMap()
  assertEqInt(resNom.actions.len(), 0, "createActionMap nominal resNom.actions.len() == 0")
  assertEqInt(resEdge.actions.len(), 0, "createActionMap boundary resEdge.actions.len() == 0")
  ret 0
```

---

### Domain 23: `asset` (8 Modules, 159 Functions -> `23_asset.md`)

Layer 4: Asset Bundles, APK Container Format, Hot-Reloading, Image/Audio/Font/glTF Decoders & Power-of-Two Sprite Atlas Packing.

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/asset/apk_container_format.aipl` | `tests/functions/asset/apk_container_format_test.aipl` | 4 | `import * from "std/asset/apk_container_format"` |
| `std/asset/asset_bundle.aipl` | `tests/functions/asset/asset_bundle_test.aipl` | 6 | `import * from "std/asset/asset_bundle"` |
| `std/asset/asset_manager.aipl` | `tests/functions/asset/asset_manager_test.aipl` | 34 | `import * from "std/asset/asset_manager"` |
| `std/asset/asset_mod.aipl` | `tests/functions/asset/asset_mod_test.aipl` | 0 | `import * from "std/asset/asset_mod"` |
| `std/asset/atlas_packer.aipl` | `tests/functions/asset/atlas_packer_test.aipl` | 9 | `import * from "std/asset/atlas_packer"` |
| `std/asset/font_sdf.aipl` | `tests/functions/asset/font_sdf_test.aipl` | 4 | `import * from "std/asset/font_sdf"` |
| `std/asset/gltf_mesh_loader.aipl` | `tests/functions/asset/gltf_mesh_loader_test.aipl` | 5 | `import * from "std/asset/gltf_mesh_loader"` |
| `std/asset/image_decoder.aipl` | `tests/functions/asset/image_decoder_test.aipl` | 97 | `import * from "std/asset/image_decoder"` |

```aipl
module tests.functions.asset.asset_bundle_z1_test
import * from "std/asset/asset_bundle"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_bundle_createAssetBundle_1(): int:
  let arg_entries = [BundleEntry(pathHash = 2, virtualPath = "/tmp/aipl_test_path", offsetBytes = 4, compressedSize = 4, uncompressedSize = 4, compressionMethod = 4)]
  let edge_entries = []
  let arg_data = [2]
  let edge_data = []
  let resNom = createAssetBundle(arg_entries, arg_data)
  let resEdge = createAssetBundle(edge_entries, edge_data)
  assertEqInt(resNom.archiveData.len(), 1, "createAssetBundle nominal resNom.archiveData.len() == 1")
  assertEqInt(resEdge.archiveData.len(), 0, "createAssetBundle boundary resEdge.archiveData.len() == 0")
  ret 0
```

---

### Domain 24: `audio` (7 Modules, 159 Functions -> `24_audio.md`)

Layer 4: Polyphonic ADSR Synthesizer, 32-Bus Mixer, Biquad/Reverb DSP Effects, 3D Doppler Spatial Audio & WAV Codec.

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/audio/audio_codec.aipl` | `tests/functions/audio/audio_codec_test.aipl` | 14 | `import * from "std/audio/audio_codec"` |
| `std/audio/audio_device.aipl` | `tests/functions/audio/audio_device_test.aipl` | 61 | `import * from "std/audio/audio_device"` |
| `std/audio/audio_dsp.aipl` | `tests/functions/audio/audio_dsp_test.aipl` | 19 | `import * from "std/audio/audio_dsp"` |
| `std/audio/audio_mixer.aipl` | `tests/functions/audio/audio_mixer_test.aipl` | 17 | `import * from "std/audio/audio_mixer"` |
| `std/audio/audio_mod.aipl` | `tests/functions/audio/audio_mod_test.aipl` | 0 | `import * from "std/audio/audio_mod"` |
| `std/audio/audio_spatial.aipl` | `tests/functions/audio/audio_spatial_test.aipl` | 19 | `import * from "std/audio/audio_spatial"` |
| `std/audio/audio_synth.aipl` | `tests/functions/audio/audio_synth_test.aipl` | 29 | `import * from "std/audio/audio_synth"` |

```aipl
module tests.functions.audio.audio_codec_z1_test
import * from "std/audio/audio_codec"
import { absFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { writeBytes } from "std/fs/file"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_codec_readU16LEWav_1(): int:
  let arg_b = [4]
  let edge_b = []
  let arg_off = 2
  let edge_off = 0
  let resNom = readU16LEWav(arg_b, arg_off)
  let resEdge = readU16LEWav(edge_b, edge_off)
  assertEqInt(resNom, 0, "readU16LEWav nominal resNom == 0")
  assertEqInt(resEdge, 0, "readU16LEWav boundary resEdge == 0")
  ret 0
```

---

### Domain 25: `gfx` (10 Modules, 55 Functions -> `25_gfx.md`)

Layer 4: Core Graphics Hardware Abstraction (Oklab/sRGB Color, Framebuffer, GPU Buffers, Textures, Shaders, Pipelines).

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/gfx/color.aipl` | `tests/functions/gfx/color_test.aipl` | 24 | `import * from "std/gfx/color"` |
| `std/gfx/framebuffer.aipl` | `tests/functions/gfx/framebuffer_test.aipl` | 2 | `import * from "std/gfx/framebuffer"` |
| `std/gfx/gfx_mod.aipl` | `tests/functions/gfx/gfx_mod_test.aipl` | 0 | `import * from "std/gfx/gfx_mod"` |
| `std/gfx/gpu_buffer.aipl` | `tests/functions/gfx/gpu_buffer_test.aipl` | 5 | `import * from "std/gfx/gpu_buffer"` |
| `std/gfx/gpu_command.aipl` | `tests/functions/gfx/gpu_command_test.aipl` | 4 | `import * from "std/gfx/gpu_command"` |
| `std/gfx/gpu_device.aipl` | `tests/functions/gfx/gpu_device_test.aipl` | 4 | `import * from "std/gfx/gpu_device"` |
| `std/gfx/gpu_pipeline.aipl` | `tests/functions/gfx/gpu_pipeline_test.aipl` | 4 | `import * from "std/gfx/gpu_pipeline"` |
| `std/gfx/gpu_shader.aipl` | `tests/functions/gfx/gpu_shader_test.aipl` | 2 | `import * from "std/gfx/gpu_shader"` |
| `std/gfx/gpu_texture.aipl` | `tests/functions/gfx/gpu_texture_test.aipl` | 5 | `import * from "std/gfx/gpu_texture"` |
| `std/gfx/postfx_pass.aipl` | `tests/functions/gfx/postfx_pass_test.aipl` | 5 | `import * from "std/gfx/postfx_pass"` |

```aipl
module tests.functions.gfx.color_z1_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_clampByte8_1(): int:
  let arg_v = 2
  let edge_v = 0
  let resNom = clampByte8(arg_v)
  let resEdge = clampByte8(edge_v)
  assertEqInt(resNom, 2, "clampByte8 nominal resNom == 2")
  assertEqInt(resEdge, 0, "clampByte8 boundary resEdge == 0")
  ret 0
```

---

### Domain 26: `gfx2d` (12 Modules, 420 Functions -> `26_gfx2d.md`)

Layer 4: 2D Rendering Engine (Camera2D Trauma Shake, Shapes, Sprites, Wang 47-Tile Tilemaps, Lighting, SDF Shadows, IK).

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/gfx2d/batch2d.aipl` | `tests/functions/gfx2d/batch2d_test.aipl` | 9 | `import * from "std/gfx2d/batch2d"` |
| `std/gfx2d/camera2d.aipl` | `tests/functions/gfx2d/camera2d_test.aipl` | 61 | `import * from "std/gfx2d/camera2d"` |
| `std/gfx2d/filter2d.aipl` | `tests/functions/gfx2d/filter2d_test.aipl` | 39 | `import * from "std/gfx2d/filter2d"` |
| `std/gfx2d/gfx2d_mod.aipl` | `tests/functions/gfx2d/gfx2d_mod_test.aipl` | 0 | `import * from "std/gfx2d/gfx2d_mod"` |
| `std/gfx2d/iso_projector2d.aipl` | `tests/functions/gfx2d/iso_projector2d_test.aipl` | 48 | `import * from "std/gfx2d/iso_projector2d"` |
| `std/gfx2d/light2d.aipl` | `tests/functions/gfx2d/light2d_test.aipl` | 4 | `import * from "std/gfx2d/light2d"` |
| `std/gfx2d/ninepatch2d.aipl` | `tests/functions/gfx2d/ninepatch2d_test.aipl` | 2 | `import * from "std/gfx2d/ninepatch2d"` |
| `std/gfx2d/shape2d.aipl` | `tests/functions/gfx2d/shape2d_test.aipl` | 173 | `import * from "std/gfx2d/shape2d"` |
| `std/gfx2d/skeletal2d.aipl` | `tests/functions/gfx2d/skeletal2d_test.aipl` | 9 | `import * from "std/gfx2d/skeletal2d"` |
| `std/gfx2d/sprite2d.aipl` | `tests/functions/gfx2d/sprite2d_test.aipl` | 38 | `import * from "std/gfx2d/sprite2d"` |
| `std/gfx2d/sprite_anim2d.aipl` | `tests/functions/gfx2d/sprite_anim2d_test.aipl` | 14 | `import * from "std/gfx2d/sprite_anim2d"` |
| `std/gfx2d/tilemap_renderer2d.aipl` | `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` | 23 | `import * from "std/gfx2d/tilemap_renderer2d"` |

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

### Domain 27: `gfx3d` (11 Modules, 107 Functions -> `27_gfx3d.md`)

Layer 4: 3D Rendering Engine (Orbit/FPS Camera3D, Frustum Culling, Cook-Torrance PBR, Cascaded Shadows, Dual-Quat Skinning, Terrain).

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/gfx3d/camera3d.aipl` | `tests/functions/gfx3d/camera3d_test.aipl` | 33 | `import * from "std/gfx3d/camera3d"` |
| `std/gfx3d/cull3d.aipl` | `tests/functions/gfx3d/cull3d_test.aipl` | 3 | `import * from "std/gfx3d/cull3d"` |
| `std/gfx3d/decal3d.aipl` | `tests/functions/gfx3d/decal3d_test.aipl` | 3 | `import * from "std/gfx3d/decal3d"` |
| `std/gfx3d/gfx3d_mod.aipl` | `tests/functions/gfx3d/gfx3d_mod_test.aipl` | 0 | `import * from "std/gfx3d/gfx3d_mod"` |
| `std/gfx3d/light3d.aipl` | `tests/functions/gfx3d/light3d_test.aipl` | 18 | `import * from "std/gfx3d/light3d"` |
| `std/gfx3d/material3d.aipl` | `tests/functions/gfx3d/material3d_test.aipl` | 14 | `import * from "std/gfx3d/material3d"` |
| `std/gfx3d/mesh3d.aipl` | `tests/functions/gfx3d/mesh3d_test.aipl` | 4 | `import * from "std/gfx3d/mesh3d"` |
| `std/gfx3d/primitives3d.aipl` | `tests/functions/gfx3d/primitives3d_test.aipl` | 10 | `import * from "std/gfx3d/primitives3d"` |
| `std/gfx3d/rigging3d.aipl` | `tests/functions/gfx3d/rigging3d_test.aipl` | 16 | `import * from "std/gfx3d/rigging3d"` |
| `std/gfx3d/skybox3d.aipl` | `tests/functions/gfx3d/skybox3d_test.aipl` | 2 | `import * from "std/gfx3d/skybox3d"` |
| `std/gfx3d/terrain3d.aipl` | `tests/functions/gfx3d/terrain3d_test.aipl` | 4 | `import * from "std/gfx3d/terrain3d"` |

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

---

### Domain 28: `particle` (8 Modules, 52 Functions -> `28_particle.md`)

Layer 4: 2D & 3D Particle Systems, Curl-Noise Affectors, Sub-Emitter Fireworks, Trail Ribbons & Particle Pools.

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/particle/affector.aipl` | `tests/functions/particle/affector_test.aipl` | 11 | `import * from "std/particle/affector"` |
| `std/particle/curve_prop.aipl` | `tests/functions/particle/curve_prop_test.aipl` | 8 | `import * from "std/particle/curve_prop"` |
| `std/particle/emitter2d.aipl` | `tests/functions/particle/emitter2d_test.aipl` | 8 | `import * from "std/particle/emitter2d"` |
| `std/particle/emitter3d.aipl` | `tests/functions/particle/emitter3d_test.aipl` | 7 | `import * from "std/particle/emitter3d"` |
| `std/particle/gpu_compute_particles.aipl` | `tests/functions/particle/gpu_compute_particles_test.aipl` | 5 | `import * from "std/particle/gpu_compute_particles"` |
| `std/particle/particle_mod.aipl` | `tests/functions/particle/particle_mod_test.aipl` | 0 | `import * from "std/particle/particle_mod"` |
| `std/particle/ribbon_trail.aipl` | `tests/functions/particle/ribbon_trail_test.aipl` | 8 | `import * from "std/particle/ribbon_trail"` |
| `std/particle/sub_emitter.aipl` | `tests/functions/particle/sub_emitter_test.aipl` | 5 | `import * from "std/particle/sub_emitter"` |

```aipl
module tests.functions.particle.affector_z1_test
import * from "std/particle/affector"
import { EPSILON, maxFloat } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_affector_createGravityAffector_1(): int:
  let arg_gravityVec = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_gravityVec = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = createGravityAffector(arg_gravityVec)
  let resEdge = createGravityAffector(edge_gravityVec)
  assertEqInt(resNom.affectorType, 1, "createGravityAffector nominal resNom.affectorType == 1")
  assertEqInt(resEdge.affectorType, 1, "createGravityAffector boundary resEdge.affectorType == 1")
  ret 0
```

---

### Domain 29: `ui` (14 Modules, 553 Functions -> `29_ui.md`)

Layer 4: Aura Immediate-Mode UI Framework (Flexbox/Grid Layout, Oklch Themes, Widgets, Gap-Buffer TextEdit, Virtual DataGrid, NodeGraph, Watcher HUD, WCAG A11y).

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/ui/ui_a11y.aipl` | `tests/functions/ui/ui_a11y_test.aipl` | 5 | `import * from "std/ui/ui_a11y"` |
| `std/ui/ui_anim.aipl` | `tests/functions/ui/ui_anim_test.aipl` | 1 | `import * from "std/ui/ui_anim"` |
| `std/ui/ui_canvas.aipl` | `tests/functions/ui/ui_canvas_test.aipl` | 37 | `import * from "std/ui/ui_canvas"` |
| `std/ui/ui_charts.aipl` | `tests/functions/ui/ui_charts_test.aipl` | 4 | `import * from "std/ui/ui_charts"` |
| `std/ui/ui_datagrid.aipl` | `tests/functions/ui/ui_datagrid_test.aipl` | 3 | `import * from "std/ui/ui_datagrid"` |
| `std/ui/ui_hud.aipl` | `tests/functions/ui/ui_hud_test.aipl` | 2 | `import * from "std/ui/ui_hud"` |
| `std/ui/ui_imui.aipl` | `tests/functions/ui/ui_imui_test.aipl` | 367 | `import * from "std/ui/ui_imui"` |
| `std/ui/ui_layout.aipl` | `tests/functions/ui/ui_layout_test.aipl` | 23 | `import * from "std/ui/ui_layout"` |
| `std/ui/ui_mod.aipl` | `tests/functions/ui/ui_mod_test.aipl` | 0 | `import * from "std/ui/ui_mod"` |
| `std/ui/ui_nodegraph.aipl` | `tests/functions/ui/ui_nodegraph_test.aipl` | 8 | `import * from "std/ui/ui_nodegraph"` |
| `std/ui/ui_style.aipl` | `tests/functions/ui/ui_style_test.aipl` | 68 | `import * from "std/ui/ui_style"` |
| `std/ui/ui_text.aipl` | `tests/functions/ui/ui_text_test.aipl` | 6 | `import * from "std/ui/ui_text"` |
| `std/ui/ui_watcher_hud.aipl` | `tests/functions/ui/ui_watcher_hud_test.aipl` | 4 | `import * from "std/ui/ui_watcher_hud"` |
| `std/ui/ui_widget.aipl` | `tests/functions/ui/ui_widget_test.aipl` | 25 | `import * from "std/ui/ui_widget"` |

```aipl
module tests.functions.ui.ui_a11y_z1_test
import * from "std/ui/ui_a11y"
import { Rect } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ui_a11y_createA11yNode_1(): int:
  let arg_id = 1
  let edge_id = 0
  let arg_role = 2
  let edge_role = 0
  let arg_label = "test"
  let edge_label = "a"
  let arg_bounds = Rect(x = 1.0, y = 1.0, w = 2.0, h = 2.0)
  let edge_bounds = Rect(x = 0.5, y = 0.5, w = 1.0, h = 1.0)
  let resNom = createA11yNode(arg_id, arg_role, arg_label, arg_bounds)
  let resEdge = createA11yNode(edge_id, edge_role, edge_label, edge_bounds)
  assertEqInt(resNom.nodeId, 1, "createA11yNode nominal resNom.nodeId == 1")
  assertEqInt(resEdge.nodeId, 0, "createA11yNode boundary resEdge.nodeId == 0")
  ret 0
```

---

### Domain 30: `ecs` (8 Modules, 29 Functions -> `30_ecs.md`)

Layer 5: Archetype Structure-of-Arrays (SoA) Entity Component System, Queries, Commands, Events & Parallel DAG Scheduler.

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/ecs/archetype.aipl` | `tests/functions/ecs/archetype_test.aipl` | 4 | `import * from "std/ecs/archetype"` |
| `std/ecs/ecs_command.aipl` | `tests/functions/ecs/ecs_command_test.aipl` | 4 | `import * from "std/ecs/ecs_command"` |
| `std/ecs/ecs_event.aipl` | `tests/functions/ecs/ecs_event_test.aipl` | 4 | `import * from "std/ecs/ecs_event"` |
| `std/ecs/ecs_mod.aipl` | `tests/functions/ecs/ecs_mod_test.aipl` | 0 | `import * from "std/ecs/ecs_mod"` |
| `std/ecs/ecs_query.aipl` | `tests/functions/ecs/ecs_query_test.aipl` | 3 | `import * from "std/ecs/ecs_query"` |
| `std/ecs/ecs_schedule.aipl` | `tests/functions/ecs/ecs_schedule_test.aipl` | 3 | `import * from "std/ecs/ecs_schedule"` |
| `std/ecs/ecs_world.aipl` | `tests/functions/ecs/ecs_world_test.aipl` | 5 | `import * from "std/ecs/ecs_world"` |
| `std/ecs/entity.aipl` | `tests/functions/ecs/entity_test.aipl` | 6 | `import * from "std/ecs/entity"` |

```aipl
module tests.functions.ecs.archetype_z1_test
import * from "std/ecs/archetype"
import { EntityId } from "std/ecs/entity"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_archetype_createArchetypeTable_1(): int:
  let arg_signatureMask = 4
  let edge_signatureMask = 1
  let arg_componentIds = [4]
  let edge_componentIds = []
  let resNom = createArchetypeTable(arg_signatureMask, arg_componentIds)
  let resEdge = createArchetypeTable(edge_signatureMask, edge_componentIds)
  assertEqInt(resNom.signatureMask, 4, "createArchetypeTable nominal resNom.signatureMask == 4")
  assertEqInt(resEdge.signatureMask, 1, "createArchetypeTable boundary resEdge.signatureMask == 1")
  ret 0
```

---

### Domain 31: `spatial` (9 Modules, 58 Functions -> `31_spatial.md`)

Layer 5: 2D & 3D Spatial World Topologies (Grid2D, Axial/Cube HexGrid, Isometric, 3D Voxel Chunks, Octree, BSP Portals, NavMesh).

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/spatial/bsp_sector_world3d.aipl` | `tests/functions/spatial/bsp_sector_world3d_test.aipl` | 6 | `import * from "std/spatial/bsp_sector_world3d"` |
| `std/spatial/continuous_world2d.aipl` | `tests/functions/spatial/continuous_world2d_test.aipl` | 7 | `import * from "std/spatial/continuous_world2d"` |
| `std/spatial/continuous_world3d.aipl` | `tests/functions/spatial/continuous_world3d_test.aipl` | 6 | `import * from "std/spatial/continuous_world3d"` |
| `std/spatial/hex_tile_world2d.aipl` | `tests/functions/spatial/hex_tile_world2d_test.aipl` | 10 | `import * from "std/spatial/hex_tile_world2d"` |
| `std/spatial/iso_tile_world2d.aipl` | `tests/functions/spatial/iso_tile_world2d_test.aipl` | 5 | `import * from "std/spatial/iso_tile_world2d"` |
| `std/spatial/ortho_tile_world2d.aipl` | `tests/functions/spatial/ortho_tile_world2d_test.aipl` | 11 | `import * from "std/spatial/ortho_tile_world2d"` |
| `std/spatial/spatial_mod.aipl` | `tests/functions/spatial/spatial_mod_test.aipl` | 0 | `import * from "std/spatial/spatial_mod"` |
| `std/spatial/voxel_chunk_world3d.aipl` | `tests/functions/spatial/voxel_chunk_world3d_test.aipl` | 7 | `import * from "std/spatial/voxel_chunk_world3d"` |
| `std/spatial/waypoint_graph_world.aipl` | `tests/functions/spatial/waypoint_graph_world_test.aipl` | 6 | `import * from "std/spatial/waypoint_graph_world"` |

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

### Domain 32: `phys2d` (10 Modules, 46 Functions -> `32_phys2d.md`)

Layer 5: 2D Physics Engine (Rigid Bodies, Colliders, Sweep-and-Prune, SAT/GJK Narrowphase, Joints, Raycasts, Verlet Cloth & PBF Fluid2D).

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/phys2d/broadphase2d.aipl` | `tests/functions/phys2d/broadphase2d_test.aipl` | 8 | `import * from "std/phys2d/broadphase2d"` |
| `std/phys2d/collider2d.aipl` | `tests/functions/phys2d/collider2d_test.aipl` | 5 | `import * from "std/phys2d/collider2d"` |
| `std/phys2d/fluid2d.aipl` | `tests/functions/phys2d/fluid2d_test.aipl` | 3 | `import * from "std/phys2d/fluid2d"` |
| `std/phys2d/joint2d.aipl` | `tests/functions/phys2d/joint2d_test.aipl` | 5 | `import * from "std/phys2d/joint2d"` |
| `std/phys2d/narrowphase2d.aipl` | `tests/functions/phys2d/narrowphase2d_test.aipl` | 5 | `import * from "std/phys2d/narrowphase2d"` |
| `std/phys2d/phys2d_mod.aipl` | `tests/functions/phys2d/phys2d_mod_test.aipl` | 0 | `import * from "std/phys2d/phys2d_mod"` |
| `std/phys2d/phys_query2d.aipl` | `tests/functions/phys2d/phys_query2d_test.aipl` | 5 | `import * from "std/phys2d/phys_query2d"` |
| `std/phys2d/phys_world2d.aipl` | `tests/functions/phys2d/phys_world2d_test.aipl` | 5 | `import * from "std/phys2d/phys_world2d"` |
| `std/phys2d/rigid_body2d.aipl` | `tests/functions/phys2d/rigid_body2d_test.aipl` | 7 | `import * from "std/phys2d/rigid_body2d"` |
| `std/phys2d/verlet2d.aipl` | `tests/functions/phys2d/verlet2d_test.aipl` | 3 | `import * from "std/phys2d/verlet2d"` |

```aipl
module tests.functions.phys2d.broadphase2d_z1_test
import * from "std/phys2d/broadphase2d"
import { Vec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_broadphase2d_dynamicAABBTreeNew_1(): int:
  let resNom = dynamicAABBTreeNew()
  let resEdge = dynamicAABBTreeNew()
  assertEqInt(resNom.nodes.len(), 0, "dynamicAABBTreeNew nominal resNom.nodes.len() == 0")
  assertEqInt(resEdge.nodes.len(), 0, "dynamicAABBTreeNew boundary resEdge.nodes.len() == 0")
  ret 0
```

---

### Domain 33: `phys3d` (9 Modules, 35 Functions -> `33_phys3d.md`)

Layer 5: 3D Physics Engine (3D Inertia Tensors, AABB Tree Broadphase, 3D GJK/EPA, Ragdoll Joints, Character Controller & Raycast Vehicle).

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/phys3d/character3d.aipl` | `tests/functions/phys3d/character3d_test.aipl` | 3 | `import * from "std/phys3d/character3d"` |
| `std/phys3d/collider3d.aipl` | `tests/functions/phys3d/collider3d_test.aipl` | 5 | `import * from "std/phys3d/collider3d"` |
| `std/phys3d/joint3d.aipl` | `tests/functions/phys3d/joint3d_test.aipl` | 4 | `import * from "std/phys3d/joint3d"` |
| `std/phys3d/narrowphase3d.aipl` | `tests/functions/phys3d/narrowphase3d_test.aipl` | 4 | `import * from "std/phys3d/narrowphase3d"` |
| `std/phys3d/phys3d_mod.aipl` | `tests/functions/phys3d/phys3d_mod_test.aipl` | 0 | `import * from "std/phys3d/phys3d_mod"` |
| `std/phys3d/phys_query3d.aipl` | `tests/functions/phys3d/phys_query3d_test.aipl` | 4 | `import * from "std/phys3d/phys_query3d"` |
| `std/phys3d/phys_world3d.aipl` | `tests/functions/phys3d/phys_world3d_test.aipl` | 5 | `import * from "std/phys3d/phys_world3d"` |
| `std/phys3d/rigid_body3d.aipl` | `tests/functions/phys3d/rigid_body3d_test.aipl` | 7 | `import * from "std/phys3d/rigid_body3d"` |
| `std/phys3d/vehicle3d.aipl` | `tests/functions/phys3d/vehicle3d_test.aipl` | 3 | `import * from "std/phys3d/vehicle3d"` |

```aipl
module tests.functions.phys3d.character3d_z1_test
import * from "std/phys3d/character3d"
import { minFloat } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { PhysicsWorld3D } from "std/phys3d/phys_world3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_character3d_characterControllerNew_1(): int:
  let arg_settings = CharacterControllerSettings3D(stepHeight = 2.0, slopeLimitRadians = 0.0, skinWidth = 2.0, gravity = Vec3(x = 1.0, y = 1.0, z = 1.0), groundFriction = 1.0, airControl = 1.0)
  let edge_settings = CharacterControllerSettings3D(stepHeight = 1.0, slopeLimitRadians = 0.0, skinWidth = 1.0, gravity = Vec3(x = 0.5, y = 0.5, z = 0.5), groundFriction = 0.5, airControl = 0.5)
  let arg_height = 2.0
  let edge_height = 1.0
  let arg_radius = 2.0
  let edge_radius = 1.0
  let resNom = characterControllerNew(arg_settings, arg_height, arg_radius)
  let resEdge = characterControllerNew(edge_settings, edge_height, edge_radius)
  assertApproxEq(resNom.height, 2.0, 0.001, "characterControllerNew nominal resNom.height ~= 2.0")
  assertApproxEq(resEdge.height, 1.0, 0.001, "characterControllerNew boundary resEdge.height ~= 1.0")
  ret 0
```

---

### Domain 34: `procgen` (8 Modules, 36 Functions -> `34_procgen.md`)

Layer 5: Deterministic Procedural Generation (Simplex/Worley FBM Noise, WFC, Cellular Automata, BSP Dungeons, Delaunay/Voronoi, L-Systems, Loot).

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/procgen/cellular_automata.aipl` | `tests/functions/procgen/cellular_automata_test.aipl` | 6 | `import * from "std/procgen/cellular_automata"` |
| `std/procgen/dungeon_graph.aipl` | `tests/functions/procgen/dungeon_graph_test.aipl` | 4 | `import * from "std/procgen/dungeon_graph"` |
| `std/procgen/lsystem.aipl` | `tests/functions/procgen/lsystem_test.aipl` | 4 | `import * from "std/procgen/lsystem"` |
| `std/procgen/marching_isosurface.aipl` | `tests/functions/procgen/marching_isosurface_test.aipl` | 3 | `import * from "std/procgen/marching_isosurface"` |
| `std/procgen/noise_field.aipl` | `tests/functions/procgen/noise_field_test.aipl` | 12 | `import * from "std/procgen/noise_field"` |
| `std/procgen/poisson_disc.aipl` | `tests/functions/procgen/poisson_disc_test.aipl` | 2 | `import * from "std/procgen/poisson_disc"` |
| `std/procgen/procgen_mod.aipl` | `tests/functions/procgen/procgen_mod_test.aipl` | 0 | `import * from "std/procgen/procgen_mod"` |
| `std/procgen/wfc_solver.aipl` | `tests/functions/procgen/wfc_solver_test.aipl` | 5 | `import * from "std/procgen/wfc_solver"` |

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

### Domain 35: `ai` (9 Modules, 158 Functions -> `35_ai.md`)

Layer 5: Autonomous Game & Agent AI (A*/JPS Pathfinding, ORCA Crowd Steering, Behavior Trees, HFSM, Utility AI, GOAP, Influence Maps, HEBAR Referee).

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/ai/ai_mod.aipl` | `tests/functions/ai/ai_mod_test.aipl` | 0 | `import * from "std/ai/ai_mod"` |
| `std/ai/btree_ai.aipl` | `tests/functions/ai/btree_ai_test.aipl` | 15 | `import * from "std/ai/btree_ai"` |
| `std/ai/fsm.aipl` | `tests/functions/ai/fsm_test.aipl` | 9 | `import * from "std/ai/fsm"` |
| `std/ai/goap.aipl` | `tests/functions/ai/goap_test.aipl` | 14 | `import * from "std/ai/goap"` |
| `std/ai/hebar_referee.aipl` | `tests/functions/ai/hebar_referee_test.aipl` | 10 | `import * from "std/ai/hebar_referee"` |
| `std/ai/navmesh.aipl` | `tests/functions/ai/navmesh_test.aipl` | 16 | `import * from "std/ai/navmesh"` |
| `std/ai/pathfind.aipl` | `tests/functions/ai/pathfind_test.aipl` | 58 | `import * from "std/ai/pathfind"` |
| `std/ai/steering.aipl` | `tests/functions/ai/steering_test.aipl` | 19 | `import * from "std/ai/steering"` |
| `std/ai/vector_embedding.aipl` | `tests/functions/ai/vector_embedding_test.aipl` | 17 | `import * from "std/ai/vector_embedding"` |

```aipl
module tests.functions.ai.btree_ai_z1_test
import * from "std/ai/btree_ai"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_btree_ai_blackboardNew_1(): int:
  let resNom = blackboardNew()
  let resEdge = blackboardNew()
  assertEqInt(resNom.entries.len(), 0, "blackboardNew nominal resNom.entries.len() == 0")
  assertEqInt(resEdge.entries.len(), 0, "blackboardNew boundary resEdge.entries.len() == 0")
  ret 0
```

---

### Domain 36: `mechanics` (5 Modules, 95 Functions -> `36_mechanics.md`)

Layer 5: RPG & Strategy Mechanics (Attribute Modifier Pipelines, Grid/Slot Inventories, Double-Entry Economy Ledgers & Branching Dialogue DAGs).

| Source Module | Unit Test File | Callable Functions | Canonical Import Syntax |
| :--- | :--- | :--- | :--- |
| `std/mechanics/attribute_pipeline.aipl` | `tests/functions/mechanics/attribute_pipeline_test.aipl` | 24 | `import * from "std/mechanics/attribute_pipeline"` |
| `std/mechanics/dialogue_dag.aipl` | `tests/functions/mechanics/dialogue_dag_test.aipl` | 22 | `import * from "std/mechanics/dialogue_dag"` |
| `std/mechanics/economy_ledger.aipl` | `tests/functions/mechanics/economy_ledger_test.aipl` | 24 | `import * from "std/mechanics/economy_ledger"` |
| `std/mechanics/inventory_container.aipl` | `tests/functions/mechanics/inventory_container_test.aipl` | 25 | `import * from "std/mechanics/inventory_container"` |
| `std/mechanics/mechanics_mod.aipl` | `tests/functions/mechanics/mechanics_mod_test.aipl` | 0 | `import * from "std/mechanics/mechanics_mod"` |

```aipl
module tests.functions.mechanics.attribute_pipeline_z1_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_evalStatModifierStack_1(): int:
  let arg_baseValue = 1.0
  let edge_baseValue = 0.5
  let arg_modifiers = [StatModifier(id = 1, statTag = "test", stage = ModifierStage.FlatAdd, value = 1.0, durationRemaining = 1.0, isPermanent = true)]
  let edge_modifiers = []
  let resNom = evalStatModifierStack(arg_baseValue, arg_modifiers)
  let resEdge = evalStatModifierStack(edge_baseValue, edge_modifiers)
  assertApproxEq(resNom, 2.0, 0.001, "evalStatModifierStack nominal resNom ~= 2.0")
  assertApproxEq(resEdge, 0.5, 0.001, "evalStatModifierStack boundary resEdge ~= 0.5")
  ret 0
```
