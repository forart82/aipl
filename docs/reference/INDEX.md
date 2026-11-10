[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# AIPL Standard Library & Domain API Reference Index

> Canonical documentation portal index for all 38 AIPL standard library domains, 299 modules, 4,347 library functions/methods, 32 compiler built-ins (4,379 total functions), and 816 public data types (799 structs, 17 enums).

## Quick Links

- [Master Standard Library Reference](STDLIB_REFERENCE.md) — 38-Domain lookup tables, layer architecture, and domain overviews.
- [AIPL Language Specification](../SPEC.md) — Formal syntax, types, and semantics.
- [Progressive Tutorials](../TUTORIAL.md) — 12 guided step-by-step chapters.
- [Cookbook Recipes](../COOKBOOK.md) — 51 production recipes.
- [CLI Reference](../CLI_REFERENCE.md) — Full CLI command manual.

## 38 Domain Reference Manuals
| Domain # | Domain Name | Target File | Modules | Functions | Types | Architecture Layer & Scope |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 01 | `builtins_root_and_prelude` | [01_builtins_root_and_prelude.md](01_builtins_root_and_prelude.md) | 3 | 74 | 4 | Layer 0/1: Compiler Intrinsics, Root Metadata & Core Prelude |
| 02 | `sys` | [02_sys.md](02_sys.md) | 9 | 109 | 10 | Layer 0: Host Syscall, Low-Level Memory, GPU, Audio, Android NDK & FFI |
| 03 | `rt` | [03_rt.md](03_rt.md) | 8 | 119 | 17 | Layer 0: Pure-AIPL Runtime Memory, Pointers, Arrays, Strings & Maps |
| 04 | `alloc` | [04_alloc.md](04_alloc.md) | 6 | 54 | 9 | Layer 0: Deterministic Allocators (Arena, Pool, Ring, GPA, Page) |
| 05 | `math` | [05_math.md](05_math.md) | 16 | 440 | 53 | Layer 1: Fixed/BigInt, Complex/FFT, Vectors, Matrices, Quaternions, Curves, SIMD |
| 06 | `collections` | [06_collections.md](06_collections.md) | 14 | 220 | 34 | Layer 1: Bitsets, Deques, Dynamic Vectors, BTree/HashMaps, Spatial BVH/Octree |
| 07 | `fmt` | [07_fmt.md](07_fmt.md) | 5 | 125 | 12 | Layer 1: String Formatting, Number Parsing, Unicode/UTF-8 & Text Printing |
| 08 | `regex` | [08_regex.md](08_regex.md) | 4 | 53 | 11 | Layer 1: Regex Compilation, VM Engine & Myers/Hirschberg Text Diffing |
| 09 | `time` | [09_time.md](09_time.md) | 7 | 165 | 17 | Layer 1: Instant, Duration, DateTime, Frame Pacer, Timers & Cron |
| 10 | `encoding` | [10_encoding.md](10_encoding.md) | 14 | 269 | 24 | Layer 2: JSON, TOML, YAML, XML, AXML Manifest, CSV, HTML DOM, Markdown, Base64/Hex |
| 11 | `compress` | [11_compress.md](11_compress.md) | 7 | 35 | 12 | Layer 2: Deflate, Gzip, LZ4, Zstandard, APK Zip & Tar Archive Streaming |
| 12 | `crypto` | [12_crypto.md](12_crypto.md) | 8 | 64 | 14 | Layer 2: Cryptographic Hashes (SHA/BLAKE), HMAC, HKDF, AEAD, APK Sig v2, CSPRNG & TLS |
| 13 | `db` | [13_db.md](13_db.md) | 3 | 78 | 15 | Layer 2: Embedded Key-Value WAL & SQLite Database Engines |
| 14 | `io` | [14_io.md](14_io.md) | 6 | 54 | 10 | Layer 3: Buffered I/O, Byte Cursors, StdIO & Stream Copying |
| 15 | `fs` | [15_fs.md](15_fs.md) | 8 | 57 | 14 | Layer 3: File System I/O, Directory Traversal, Path Parsing, Android VFS & Mobile Watcher |
| 16 | `os` | [16_os.md](16_os.md) | 6 | 145 | 24 | Layer 3: CLI Args, Environment, Process Execution, Signals & ANSI Colors |
| 17 | `sync` | [17_sync.md](17_sync.md) | 6 | 74 | 20 | Layer 3: Atomics, Mutex, RwLock, Channels & Barriers |
| 18 | `thread` | [18_thread.md](18_thread.md) | 4 | 38 | 13 | Layer 3: Cooperative Fibers, Work-Stealing Job System & Thread Locals |
| 19 | `net` | [19_net.md](19_net.md) | 11 | 78 | 31 | Layer 3: TCP/UDP, DNS, HTTP Client/Server, Live Reload Sync, Reliable UDP & WebSockets |
| 20 | `test` | [20_test.md](20_test.md) | 5 | 32 | 13 | Layer 3: Assertions, Benchmarking, Fuzzing & Test Runner |
| 21 | `window` | [21_window.md](21_window.md) | 6 | 28 | 11 | Layer 4: Desktop Canvas Window, Display Modes, Surface & Event Loop |
| 22 | `input` | [22_input.md](22_input.md) | 7 | 51 | 15 | Layer 4: Keyboard, Mouse, Touch, Gamepad & Virtual Action Maps |
| 23 | `asset` | [23_asset.md](23_asset.md) | 8 | 159 | 25 | Layer 4: Asset Bundle, APK Container Format, Image Decoder, Atlas Packer, SDF Fonts & GLTF |
| 24 | `audio` | [24_audio.md](24_audio.md) | 7 | 159 | 25 | Layer 4: Audio Device, Polyphonic Synth, DSP Filters, Mixer & 3D Spatial |
| 25 | `gfx` | [25_gfx.md](25_gfx.md) | 10 | 55 | 32 | Layer 4: GPU Device, Pipelines, Shaders, Buffers, Textures & PostFX |
| 26 | `gfx2d` | [26_gfx2d.md](26_gfx2d.md) | 12 | 434 | 65 | Layer 4: 2D Sprite Batches, Camera2D, Shapes, Z-Buffer/Gouraud, Skeletal Anim, Tilemaps |
| 27 | `gfx3d` | [27_gfx3d.md](27_gfx3d.md) | 11 | 107 | 26 | Layer 4: 3D Camera, Meshes, PBR Materials, Lighting, Decals, Rigging & Skybox |
| 28 | `particle` | [28_particle.md](28_particle.md) | 8 | 52 | 18 | Layer 4: 2D/3D Particle Emitters, GPU Compute Particles, Ribbons & Affectors |
| 29 | `ui` | [29_ui.md](29_ui.md) | 14 | 553 | 71 | Layer 4: Immediate-Mode Aura UI, Layout Engine, Widgets, Canvas, Watcher HUD, NodeGraph |
| 30 | `ecs` | [30_ecs.md](30_ecs.md) | 8 | 29 | 13 | Layer 5: Archetype Entity-Component-System World, Queries & Scheduler |
| 31 | `spatial` | [31_spatial.md](31_spatial.md) | 9 | 58 | 27 | Layer 5: Continuous 2D/3D Worlds, Hex/Iso/Ortho Grids, Voxel Chunks, BSP |
| 32 | `phys2d` | [32_phys2d.md](32_phys2d.md) | 10 | 46 | 22 | Layer 5: 2D Rigid Bodies, Dynamic AABB, Broad/Narrow Phase, Joints, Fluids |
| 33 | `phys3d` | [33_phys3d.md](33_phys3d.md) | 9 | 35 | 17 | Layer 5: 3D Rigid Bodies, Kinematic Character Controllers, Vehicles, Colliders |
| 34 | `procgen` | [34_procgen.md](34_procgen.md) | 8 | 36 | 19 | Layer 5: Cellular Automata, Dungeon Graphs, Wave Function Collapse, Noise |
| 35 | `ai` | [35_ai.md](35_ai.md) | 9 | 165 | 37 | Layer 5: Behavior Trees, GOAP, FSM, NavMesh/A*, Steering & HEBAR Referee |
| 36 | `mechanics` | [36_mechanics.md](36_mechanics.md) | 5 | 95 | 23 | Layer 5: Stat Modifier Pipelines, Inventories, Dialogue DAGs & Economy Ledgers |
| 37 | `gfx25d` | [37_gfx25d.md](37_gfx25d.md) | 7 | 34 | 13 | Layer 4: Continuous 2.5D/3D Isometric Camera, Heightfield Splatting, Ribbons, Lighting, Rigs & Weather |
| 38 | `hebar` | [38_hebar.md](38_hebar.md) | 2 | 16 (re-export) | 2 (re-export) | Layer 5: Canonical Human-Equivalent Bot Automated Referee (`std/hebar/referee`, `std/hebar/hebar_mod`) |

---

*Total Inventory: 38 Domains, 299 Standard Library Modules, 4,347 Standard Library Functions & Methods + 32 Built-ins = 4,379 Total Functions; 799 Public Structs, 17 Public Enums (816 Total Data Types).*