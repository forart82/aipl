# AIPL v0.9.0 System Architecture Oracle & Constants Specification
**Architectural Truth, Subsystem Invariants & Empirical Constants Reference**

This document serves as the authoritative Single Source of Truth (SSOT) Oracle for all quantitative thresholds, binary layout constants, memory structures, VM opcodes, and compiler diagnostics across **AIPL v0.9.0**.
---

## 1. Memory Model Constants & Alignment Invariants

| Constant Name | Value | Invariant & Architectural Rationale |
| :--- | :--- | :--- |
| `AIPL_VAL_SIZE_BYTES` | `16` | Compact 16-byte tagged value union: 8-byte payload (`int64_t`/`double`/`void*`) + 1-byte tag + 7 bytes padding. |
| `AIPL_ARENA_PAGE_SIZE` | `16777216` (`16 MiB`) | Chained arena page slab size. Eliminates pointer invalidation during dynamic reallocations. |
| `ROBIN_HOOD_MAX_LOAD` | `0.85` | Maximum load factor for `AiplMap` open-addressing hash table with backward-shift deletion and FNV-1a 64-bit hashing. |
| `CACHE_LINE_SIZE` | `64 bytes` | L1d cache line alignment. All Structure of Arrays (SoA) dynamic buffers align to 64-byte boundaries. |
| `WEBGPU_UNIFORM_ALIGN` | `256 bytes` | Hardware uniform buffer offset alignment ($\text{offset} \pmod{256} = 0$) enforced at compile time (`AIPL_E0502`). |
| `MERKLE_CACHE_VERSION` | `"v1"` | Content-addressed incremental HIR cache stored at `.aipl/cache/v1/`. |
| `MAX_VM_REGISTERS_LIMIT` | `1048576` (`1M`) | Dynamic runtime VM register pool limit (`getMaxVmRegistersLimit() >= 1048576`). |
| `MAX_CALL_DEPTH_LIMIT` | `65536` (`64k`) | Maximum runtime recursive call stack limit (`getMaxCallDepthLimit() >= 65536`). |

---

## 2. 32-Bit Register Bytecode VM (`formatVersion = 4`)

The AIPL Virtual Machine executes a 32-bit 3-address register bytecode format with computed-`goto` indirect threaded dispatch.

### 2.1 Binary Header Layout
- **Magic Bytes**: `0x41 0x49 0x50 0x4C` (`"AIPL"`)
- **Format Version**: `4` (`uint32_t`)
- **Constant Pool Count**: `uint32_t`
- **Function Table Count**: `uint32_t`
- **Instruction Stream Length**: `uint32_t`

### 2.2 Core Opcode Registry
- `0x01`: `OP_LOAD_INT` — Load immediate integer into destination register.
- `0x02`: `OP_LOAD_FLOAT` — Load immediate float into destination register.
- `0x03`: `OP_LOAD_STR` — Load constant string reference.
- `0x04`: `OP_MOVE` — Copy register value.
- `0x10`: `OP_ADD_INT`, `OP_SUB_INT`, `OP_MUL_INT`, `OP_DIV_INT`, `OP_MOD_INT` — 64-bit integer arithmetic.
- `0x15`: `OP_ADD_FLOAT`, `OP_SUB_FLOAT`, `OP_MUL_FLOAT`, `OP_DIV_FLOAT` — 64-bit float arithmetic.
- `0x20`: `OP_JUMP` — Unconditional relative branch.
- `0x21`: `OP_JUMP_IF_TRUE`, `OP_JUMP_IF_FALSE` — Conditional branch based on register test.
- `0x30`: `OP_CALL` — Function invocation with argument register window.
- `0x31`: `OP_RET` — Return from current frame with return value register.

---

## 3. WebAssembly 1.0 & WASI Preview 1 Emitter Invariants

The single-pass WASM32 emitter lowers Canonical HIR directly to valid binary WebAssembly modules conforming to WebAssembly 1.0:
- **Magic**: `\0asm` (`0x00 0x61 0x73 0x6D`)
- **Version**: `0x01 0x00 0x00 0x00` (`1`)
- **WASI System Calls Imported**:
  - `wasi_snapshot_preview1::fd_write` (stdout/stderr terminal emission)
  - `wasi_snapshot_preview1::fd_read` (stdin consumption)
  - `wasi_snapshot_preview1::clock_time_get` (high-precision monotonic timestamp)
  - `wasi_snapshot_preview1::proc_exit` (process termination)
- **Memory**: Single exported linear memory page starting at 64 KiB (`pages = 1`, max unbounded).

---

## 4. Relational Octagon DBM Formal Verification Solver

The SMT constraint solver tracks relational inequalities between variables using an Octagon Difference-Bound Matrix (DBM):
- **Domain**: Relational constraints of the form $\pm x_i \pm x_j \le c$, encoding intervals ($x \le c$, $-x \le c$) and relational bounds ($x - y \le c$, $x + y \le c$).
- **Closure Algorithm**: $O(N^3)$ Floyd-Warshall all-pairs shortest-path algorithm over the DBM potential graph.
- **Contract Lowering**:
  - `requires` expressions establish initial assumption rows in the entry DBM.
  - `ensures` expressions assert feasibility over the exit DBM.
  - `invariant` expressions verify closure fixpoints across loop back-edges.
  - `decreases` expressions verify strict monotonic descent bounded by zero.

---

## 5. The 7-Pillar Language & Engine Architecture (`v0.8.0`)

AIPL v0.8.0 organizes its core toolchain, compiler, stdlib, graphics, and runtime around 7 foundational pillars:

### Pillar 1: Hierarchical 9-Domain Standard Library
The standard library is structured into 9 canonical functional domains:
- `std/core`: Foundational data structures, SIMD math, bitwise operations, memory arenas, dynamic arrays, threadpools, timers, and crypto.
- `std/io`: Filesystem, streams, process execution, binary buffers, CLI argument parsing, logging, and OS terminal interaction.
- `std/data`: Document processing (PDF, Markdown, HTML, XML), serialization (JSON, YAML, TOML, INI, CSV), ECS registry, diffs, and SQLite3.
- `std/net`: POSIX TCP/UDP sockets, DNS resolution, HTTP/1.1 client/router, WebSockets, and RPC.
- `std/ui`: Immediate-mode UI layout, AuraDS Material Design 3 design system, themes, colors, accessibility, virtualized data tables (`std/ui/datagrid`), and node graph editors (`std/ui/nodegraph`).
- `std/gfx2d`: 2D canvas primitives, sprites, particle systems, tweens, easings, splines, color LUTs, and isometric projection.
- `std/gfx3d`: 3D meshes (`genMeshCube`, `genMeshSphere`, `.obj`/`.gltf`/`.glb`), PBR materials, cameras, lighting, and spatial transforms.
- `std/sim`: Kinematics, 2D/3D collision detection, rigid body dynamics, Verlet ropes, game feel, navigation grids, procedural generation, 2D grid/bin packing & recipes (`std/sim/inventory`), and 2D cellular automata & diffusion (`std/sim/cellular`).
- `std/audio`: 16-voice polyphonic DSP synthesizer, ADSR envelopes, step sequencer, and 3D spatial acoustics with Doppler shifts.
- `std/rt`: Pure-AIPL zero-dependency runtime foundation modules (`alloc`, `array`, `audio`, `canvas_x11`, `crypto_compress`, `json`, `map`, `ptr`, `string`).

Modules can be imported via hierarchical dot syntax (`import std.core.math`, `import std.gfx2d.canvas`) or canonical path strings (`import { clampInt } from "std/core/math"`), with backward compatibility for flat imports.

### Pillar 2: Directional Lossless Numeric Lattice & Explicit Division
- **Lossless Subtyping Lattice**: `byte <: int <: float`. An 8-bit unsigned `byte` losslessly widens to 64-bit signed `int`, which losslessly widens to 64-bit IEEE-754 `float`.
- **Compile-Time Truncation Rejection (`[AIPL312]`)**: Silent narrowing (`let i: int = 3.9` or `let i: int = floatVar`) is rejected at compile time.
- **Postfix Conversions**: Fast hardware-inlined conversions `.i` (truncate towards zero), `.f` (convert to float), `.round` (nearest integer), `.floor` (floor integer), and `.ceil` (ceiling integer).
- **Integer Floor-Division Operator `//`**: Deterministic floor division (`7 // 2 == 3`, `-7 // 2 == -4`, `7.9 // 2.0 == 3`, `-7.1 // 2.0 == -4`). Valid in all statement and expression positions including `.push(...)` arguments and `if`-conditions.

### Pillar 3: Automated `snake_case` -> `camelCase` Self-Healing
- **Canonical Naming Conventions**: Values, variables, and functions must be `camelCase`. Structs, enums, and types must be `PascalCase`.
- **Compiler Diagnostic & Auto-Fix**: The compiler emits `AIPL_W1003_SNAKE_CASE_AUTOFIX` for forbidden snake_case identifiers.
- **Normalizer Engine**: `aipl fmt` and `aipl fix` invoke `normalizeSnakeCaseSource` to automatically rewrite snake_case symbols while preserving `@extern` C-FFI call signatures and string interpolation literals.

### Pillar 4: Self-Contained Canvas Desktop Engine & System I/O
- **IME & Multilingual Composition**: Linux X11 XIM (`Xutf8LookupString`) and Web browser IME composition support with `getCompositionText()` and `getCompositionCursor()`.
- **Native-Free Clipboard**: Fully self-contained desktop and Web clipboard (`getClipboardText()`, `setClipboardText()`) requiring zero external `xclip`/`xsel` binaries.
- **Rich Text Editor**: `AuraTextEditBuffer` immediate-mode text editing engine with undo/redo stacks (`Ctrl+Z`, `Ctrl+Y`), select-all (`Ctrl+A`), cut/copy/paste (`Ctrl+X`, `Ctrl+C`, `Ctrl+V`), and keyboard focus rings via `Tab`.
- **File Dialogs & Atomic I/O**: `auraFileDialogStateNew`, `auraFileDialogSortEntries`, `writeFileAtomic`, positional I/O (`fileOpen`, `fileWriteAt`, `fileTruncate`), and filesystem watching (`watchDir`).

### Pillars 5 & 6: Hardware-Accelerated 3D Engine & Spatial Physics
- **GPU Acceleration**: Dynamic backend detection via `isGpuAccelerated()` and `getGraphicsBackendName()` (WebGL2, WebGPU, or OpenGL/Vulkan desktop).
- **Procedural & Loaded Meshes**: Procedural geometry generators (`genMeshCube`, `genMeshSphere`), mesh skinning (`skinMeshVertices`), and model loaders for `.obj`, `.gltf`, and `.glb`.
- **PBR Materials & Lighting**: Physically Based Rendering materials (`material3DPbr`, `evaluateMaterial3D`), point and spot light attenuation, and directional sunlight.
- **Analytic 3D Collision & Raycasting**: Analytic ray intersections (`rayIntersectSphere`, `rayIntersectAABB`, `rayIntersectMesh`), capsule-AABB tests (`capsuleIntersectsAABB`), and swept-sphere continuous collision resolution (`sweepSphereAABB`).

### Pillar 7: Dynamic Runtime Pools & Register VM
- **High-Capacity VM Register Pools**: Dynamic VM register limit expandable to at least 1,048,576 registers (`getMaxVmRegistersLimit() >= 1048576`).
- **Deep Call Stack Recursion**: Call frame limit expandable to at least 65,536 frames (`getMaxCallDepthLimit() >= 65536`), enabling deep recursive evaluation without stack overflows.

### Loop 2 Language Features & Ergonomics
- **Optional `module` Header & Auto-Prelude**: Module headers (`module Name`) are optional. The compiler automatically imports standard prelude symbols: `std.cli` (`parseCliArgs`), `std.grid` (`gridNew`, `gridSet`, `grid2dNew`, `grid2dSet`), and `std.pathfinding` (`gridAStar`).
- **Compact Struct Declarations & Positional Constructors**: Declare single-line structs with parameter syntax: `pub struct Point(x: float, y: float = 0.0)` or `pub struct Point: x: float, y: float`. Construct instances positionally (`Point(1.0, 2.0)`) or with named fields (`Point(x = 1.0, y = 2.0)`), with automatic default field filling.
- **Membership Operator `in`**: Test element containment cleanly: `elem in array`, `key in map`, `elem in set`, `substr in str`.
- **Slices `[start..end]`**: Index strings and arrays via range slicing: `arr[a..b]`, `arr[a..]`, `arr[..b]`.
- **List Comprehensions**: Construct transformed and filtered arrays with concise syntax: `[expr for item in iterable if condition]` or `[expr for item in iterable]`.
- **Coalescing Operator `??`**: Unwrap fallible or optional expressions with fallback: `a ?? b` (coalesces `Option[T]`, `Result[T, E]`, or `nil`).
- **Intrinsic Annotations `@intrinsic`**: Decorates compiler and runtime low-level primitives for direct code generation.

---

## 6. Universal Multi-Instance, Multi-Target HEBAR Bot (`aipl_hebar_bot/`)

AIPL v0.8.0 features a universal autonomous testing, game playing, and referee bot engine residing in `aipl_hebar_bot/`:
- **Kinematic Guard (`aipl_hebar_bot/core/kinematic_guard.aipl` & `std/hebar/referee.aipl`)**: Enforces all 5 canonical human-equivalent bounds:
  1. Reaction latency FIFO queue (`150–250 ms` via `hebarClampReactionDelayMs`, `hebarEnqueueAction`, `hebarPopReadyActions`)
  2. Input frequency ceiling ($\le 15$ Hz / $900$ APM via `hebarIsWithinApmLimit`)
  3. Cursor trajectory interpolation ceiling ($\le 780\text{ px/s}$ via `hebarStepCursorTrajectory`)
  4. Angular velocity slew ceiling ($\le 2\pi\text{ rad/s}$ via `hebarClampAngularSlew`)
  5. Zero direct memory/state tampering verification (`hebarVerifyZeroTampering`, `connectTargetWindow`, `renderHebarRefereeDashboard`, `exportHebarTelemetryJson`).
- **Scene Sensor (`aipl_hebar_bot/core/scene_sensor.aipl`)**: Ingests structured JSON scene snapshots (`parseSceneSnapshotJson`) and verifies UX ergonomics and layout contrast.
- **Seat Arbiter (`aipl_hebar_bot/core/seat_arbiter.aipl`)**: Coordinates multi-player turns and local multi-window seat arbitration (`tryAcquireSeatCursorLease`, `releaseSeatCursorLease`).
- **Behavior Tree & Learner (`aipl_hebar_bot/core/behavior_tree.aipl`, `aipl_hebar_bot/reporting/bot_learner.aipl`)**: Evaluates hierarchical strategy trees and persists learned game heuristics (`writeLearnedHeuristicsJson`).
- **Multi-Seat IPC Adapter (`aipl_hebar_bot/adapters/ipc_window_adapter.aipl`)**: Dispatches simulated input events across separate OS windows (`targetWindowSeatAction`).
- **Tri-Target Portability**: Compiles and runs identically as a native binary (`hebar_bot_bin`), single-file HTML5 app (`hebar_bot.html`), or WebAssembly module (`hebar_bot.wasm`), with a live multi-player test arena in `aipl_hebar_bot/demos/ludo_chess_arena.aipl`.

---

## 7. Complete Standard Library Catalog (3-Layer Stratified Package Hierarchy)

The standard library is structured into 3 architectural layers: Layer 0 Runtime Intrinsics (`std/sys`), Layer 1 Universal Core (`std/core`, `std/math`, `std/collections`, `std/time`, `std/text`, `std/serde`, `std/io`, `std/net`), and Layer 2 Engine Kits (`std/gfx`, `std/ui`, `std/sim`, `std/audio`) with backward-compatible re-export facades, importable via hierarchical dot paths (`import std.<domain>.<mod>`) or canonical paths (`"std/<domain>/<mod>"`):

| # | Module | Domain | Highlights & Capabilities |
| :---: | :--- | :--- | :--- |
| 1 | `std/ai` | AI / Math | Multi-provider prompt generation, tool calling, token estimation, cosine similarity |
| 2 | `std/analytics` | Analytics | Tiered commission accelerators, RevOps attainment metrics, financial forecasting |
| 3 | `std/anim` | Graphics | Sprite-sheet animation state machines, keyframe timelines, 2D FK/IK bone solvers |
| 4 | `std/arena` | Memory | Regional bump arena allocation, $O(1)$ reclamation with `arenaMark`/`arenaReset` |
| 5 | `std/array` | Collections | Dynamic arrays, resizing, insertions, in-place filtering, element searches |
| 6 | `std/asset` | Graphics | Static asset loading, spritesheet extraction, texture registration |
| 7 | `std/async` | Concurrency | Asynchronous promise combinators, task chains, delay timers |
| 8 | `std/audio` | Audio | Procedural sound generation, ADSR envelope shaping, 16-voice polyphonic synthesis |
| 9 | `std/aura` | UI / HUD | AuraDS Material Design 3 immediate-mode UI, 24 themes, `AuraFlowContainer`, game HUDs |
| 10 | `std/buffer` | System | Flat binary `ByteBuffer` with endian-aware primitives and canonical `RingBuffer` |
| 11 | `std/canvas` | Graphics | Hardware-accelerated 2D canvas, shapes, lines, SoA batching, affine transform stack |
| 12 | `std/charbody` | Graphics | Procedural multi-limb character rigs, pose interpolation, first-person weapon rigs |
| 13 | `std/cli` | System | Argument parsing, subcommands, typed flags (`getStr`, `getInt`, `getBool`) |
| 14 | `std/collections`| Collections | Hash maps, sets, FIFO queues, LIFO stacks, priority queues, ring buffer wrappers |
| 15 | `std/color` | Graphics | Color models (RGB, RGBA, HSL, Hex), linear interpolation, palette blending |
| 16 | `std/compress` | Formats | Deflate / Inflate algorithms, gzip binary compression and decompression |
| 17 | `std/cron` | Time | Cron syntax parsing, schedule validation, next execution calculation |
| 18 | `std/crypto` | Security | SHA-256, SHA-512, MD5, HMAC-SHA256, ChaCha20/AES-GCM, random byte generator |
| 19 | `std/csv` | Formats | RFC 4180 CSV parsing, quoted field escaping, tabular stringification |
| 20 | `std/date` | Time | Calendar date arithmetic (`Date`), `isLeapYear`, `daysInMonth`, `dateDayOfWeek` |
| 21 | `std/datetime` | Time | Civil timestamps (`DateTime`, `CivilDateTime`), ISO 8601 & RFC 2822/822, Unix epoch math |
| 22 | `std/db` | Database | Embedded SQLite3 engine, parameterized queries, transaction commits/rollbacks |
| 23 | `std/diff` | Formats | Myers line-diff algorithm, unified diff emission, change hunk analysis |
| 24 | `std/dns` | Networking | Native `getaddrinfo` IPv4/IPv6 domain resolution over POSIX sockets |
| 25 | `std/doc` | Documents | `UniversalDocument` model, PDF-1.4 emitter/extractor, RTF/LaTeX/HTML, slide decks |
| 26 | `std/dotenv` | System | `.env` configuration file loader and parser |
| 27 | `std/ecs` | Collections | Archetype & bitmask Entity Component System (ECS) world registry and spatial queries |
| 28 | `std/encoding` | Formats | Base64, Hexadecimal, and canonical URL percent-encoding / decoding (`urlEncode`, `urlDecode`) |
| 29 | `std/env` | System | Environment variable reads/writes, current working directory, platform detection |
| 30 | `std/ffi` | Systems | Zero-FFI dynamic shared library loading (`dlopen`/`dlsym`/`dlclose`) |
| 31 | `std/fs` | System | File reads/writes, atomic writes, recursive directory walking, file stats |
| 32 | `std/fx` | Graphics | Trauma² camera shake, hit-stop freeze frames, post-processing shaders, particle bursts |
| 33 | `std/game` | Game Engine | `Camera2D`, `SpriteAnimator`, `PlatformerFeel`, steering behaviors, genre math helpers |
| 34 | `std/geom2d` | Math | Canonical 2D vectors (`Vec2`), `SweptHit`/`sweptAabb`, bounding boxes, rays, collisions |
| 35 | `std/geom3d` | Math | 3D vectors, matrices, quaternions, camera view-projection, depth-sorted mesh rendering |
| 36 | `std/gpu` | Graphics | WebGPU WGSL compute pipeline codegen, triple-buffered staging rings, 64-bit bitboards |
| 37 | `std/gravity` | Physics | N-body point-mass gravitational wells, softened inverse-square fields, blast falloff |
| 38 | `std/grid` | Collections | 2D/3D dense spatial grids, coordinate clamping, neighbor queries |
| 39 | `std/heap` | Collections | Binary min-heap and max-heap priority queues with $O(\log N)$ push/pop |
| 40 | `std/html` | Formats | HTML entity encoding/decoding, tag stripping, minimal DOM building |
| 41 | `std/http` | Networking | Canonical HTTP 1.1 client & router (`HttpRequest`, `HttpResponse`, `httpGet`, `httpPost`, `httpFetch`) |
| 42 | `std/image` | Graphics | Universal 12-format image detector, RGBA pixel manipulation, sprite slicing, filters |
| 43 | `std/ini` | Formats | INI configuration parser and serializer with `[section]` hierarchy |
| 44 | `std/io` | System | Standard I/O streams (`print`, `println`, `eprint`, `eprintln`, `readLine`, `streamLines`) |
| 45 | `std/iso` | Graphics | 2.5D isometric grid projection, axial hex coordinates, heightfield prisms, portals |
| 46 | `std/json` | Formats | RFC 8259 JSON parser, serializer, Draft 2020-12 schema validation |
| 47 | `std/lighting` | Graphics | 2D/3D point & spot light attenuation, Lambertian diffuse shading, 2D shadow raycasting |
| 48 | `std/lut` | Graphics | 3D color-grading LUTs, cubic tone curves, gamma levels, night-vision scanlines |
| 49 | `std/markdown` | Formats | CommonMark parsing, header extraction, HTML conversion |
| 50 | `std/math` | Math | Hardware-accelerated SIMD math (AVX-512/AVX2/NEON), trig functions, flat buffers |
| 51 | `std/navgrid` | Math / AI | Octile navigation heuristics, Bresenham line-of-sight, bhop physics, cellular automata |
| 52 | `std/net` | Networking | IPv4/IPv6 validation, `SocketAddr`, `Url` parser, and raw TCP socket primitives |
| 53 | `std/particles` | Graphics | Parabolic ribbon arcs, jagged lightning ribbons, missile wakes, decals, 30-bit dispersion |
| 54 | `std/path` | System | Cross-platform file path manipulation, normalization, extension checks |
| 55 | `std/pathfinding`| Math | A* and Dijkstra pathfinding over 2D cost grids |
| 56 | `std/physics` | Physics | 2D rigid body dynamics, Hooke's springs, Verlet soft-body/rope constraints, raycasts |
| 57 | `std/physics2d3d`| Physics | Unified 2D/3D symplectic Euler kinematics, 3D AABB/sphere overlap, Sobel normal maps |
| 58 | `std/pool` | Memory | Generic object pooling and slab reuse for zero-allocation hot paths |
| 59 | `std/process` | System | Child process spawning, command execution, exit codes, single-instance locks |
| 60 | `std/procgen` | Math | Seeded PRNG, 2D Value noise, Fractal Brownian Motion (fBm), BSP dungeon & cave gen |
| 61 | `std/qrcode` | Formats | QR Code matrix generator with Reed-Solomon error correction |
| 62 | `std/random` | Math | Pseudo-random generators (Mersenne Twister, Xoshiro256), uniform distributions |
| 63 | `std/regex` | Formats | Linear-time regular expression matcher and substitution engine |
| 64 | `std/rt/alloc` | Runtime | Pure-AIPL bump arena and free-list memory allocator (`rtAlloc`, `rtFree`) |
| 65 | `std/rt/array` | Runtime | Pure-AIPL contiguous dynamically growable vector buffer (`rtArrayNew`, `rtArrayPush`) |
| 66 | `std/rt/audio` | Runtime | Pure-AIPL 44.1kHz 16-bit PCM RIFF WAV loader and audio mixer + C runtime multi-backend polyphonic synthesizer (`PulseAudio` / `ALSA` / `SDL2`, `ex_256`–`ex_258`) |
| 67 | `std/rt/canvas_x11` | Runtime | Pure-AIPL Linux X11 wire-protocol display connection + Dual Window Mode (`setWindowMode("x11" \| "glx")`: X11 MIT-SHM & GLX `libGL.so.1`, `ex_251`–`ex_255`) |
| 68 | `std/rt/crypto_compress` | Runtime | Pure-AIPL SHA-256, ChaCha20, CRC32, and Deflate/Inflate compression |
| 69 | `std/rt/json` | Runtime | Pure-AIPL RFC 8259 JSON parser, serializer, and schema validator |
| 70 | `std/rt/map` | Runtime | Pure-AIPL open-addressed SwissTable hash map with FNV-1a 64-bit hashing |
| 71 | `std/rt/ptr` | Runtime | Low-level memory pointer, `PtrSlice`, and IEEE-754 bitcast primitives |
| 72 | `std/rt/string` | Runtime | Pure-AIPL UTF-8 string slice operations, concatenation, and substring search |
| 73 | `std/semver` | Utility | Semantic Versioning (SemVer 2.0.0) parser and constraint comparator |
| 74 | `std/skeletal` | Graphics | 2D/3D bone joint forward kinematics, two-bone analytical IK, Hermite keyframe curves |
| 75 | `std/sort` | Collections | Quicksort, mergesort, radixsort for primitives and custom comparator sorting |
| 76 | `std/spatial_audio` | Audio | 3D distance attenuation, 2D stereo panning, Doppler pitch shift, wall occlusion, reverb |
| 77 | `std/spline` | Math | Catmull-Rom and Cubic Bezier spline trajectory evaluators |
| 78 | `std/spring` | Physics | Damped harmonic oscillator physics for responsive animations |
| 79 | `std/string` | Collections | String slicing, splitting, joining, trimming, case conversions, `StringBuilder` |
| 80 | `std/syscall` | Systems | Direct Linux kernel syscall ABI (`x86_64` `syscall` / `arm64` `svc #0`) |
| 81 | `std/tar` | Formats | POSIX tar archive packaging and extraction |
| 82 | `std/term` | System | Terminal ANSI styling, colors, cursor repositioning, dimensions |
| 83 | `std/test` | Testing | Assertion suite, unit test runner, property-based tests with shrinking |
| 84 | `std/thread` | Concurrency | POSIX work-stealing threadpool, MPSC channels, `hardwareConcurrency()`, `execParallel` |
| 85 | `std/tilemap` | Game Engine | 2D tilemaps, ASCII level loading, `tilemapMoveAndSlide`, RPG dialogue & inventory |
| 86 | `std/time` | Time | High-resolution monotonic timers, epoch milliseconds, sleep delays |
| 87 | `std/toml` | Formats | TOML v1.0.0 configuration parser and serializer |
| 88 | `std/transform` | Graphics | 2D affine transform matrix stack (`pushMatrix`, `popMatrix`, `rotate2D`, `rotateAround`) |
| 89 | `std/tween` | Graphics | Interpolation curves (EaseIn, EaseOut, Elastic, Bounce) and property tweens |
| 90 | `std/ui` | UI Engine | Immediate-mode layout boxes, KPI cards, tabs, waterfall step bars, hit testing |
| 91 | `std/uuid` | Security | RFC 4122 Version 4 & Version 5 UUID generation and parsing |
| 92 | `std/viewport` | Graphics | Aspect-ratio viewport scaling, mouse unprojection, perspective guides, liquify warp |
| 93 | `std/weather` | Graphics | Rain/snow wind drift, fractal lightning bolts, 2D value/fBm noise, precipitation overlays |
| 94 | `std/worldgen` | Graphics | Multi-perspective 2D/2.5D/Iso/3D world projection, blocks, corridors, heightmaps |
| 95 | `std/xml` | Formats | Lightweight XML parser and element node traversal |
| 96 | `std/yaml` | Formats | YAML 1.2 subset parser, emitter, and JSON converter |
| 97 | `std/sim/inventory` | Simulation | Generic 2D grid/bin container packing, weighted modifier tables, recipe matching, DAG unlocks |
| 98 | `std/sim/cellular` | Simulation | Generic 2D cellular automata density swapping, reaction rules, Laplacian diffusion, dirty chunks |
| 99 | `std/ui/datagrid` | UI Engine | Virtualized data tables, sorting/filtering, inline sparklines, swimlane boards, command palette |
| 100 | `std/ui/nodegraph` | UI Engine | Cubic Bezier node-graph editor, port hit-testing, topological evaluation, split dock layout, undo/redo |
| 101 | `std/gfx25d` | Graphics | Continuous 2.5D/3D isometric world engine (`camera25d`, `mesh25d`, `ribbon25d`, `light25d`, `sprite25d`, `weather25d`), Gouraud & multi-biome alpha-splatted heightfields (`drawHeightfieldPatchTextured25D`, `drawHeightfieldSplat25D`, `drawGroundDecal25D`), UV-scrolled ribbons (`drawSplineRibbonTextured25D`), Z-buffered volumetrics (`drawPrismTextured25D`, `drawIndexedMeshTextured25D`), ambient multiply + additive light cookies (`renderLightingPass25D`), 8-directional isometric sprite rigs (`drawIsoSpriteRig25D`, `drawBillboardCutout25D`), and 2.5D weather/mist (`drawMistPlanes25D`, `drawWeatherParticles25D`) |
| 102 | `std/hebar/referee` | AI / Testing | Canonical 5-bound HEBAR referee alias, deterministic `connectTargetWindow` IPC handshake, dashboard & telemetry export |

---

## 8. Compiler Diagnostic Code Registry

| Diagnostic Code | Canonical Identifier | Severity | Category | Description |
| :--- | :--- | :--- | :--- | :--- |
| `AIPL_E1001` | `PARSE_SYNTAX_ERROR` | Fatal | Syntax | General syntactic parse failure |
| `AIPL_E1002` | `FORBIDDEN_TAB` | Fatal | Lexer | Tab character used in indentation |
| `AIPL_E1003` | `FORBIDDEN_UNDERSCORE` | Fatal | Lexer | Identifier contains forbidden underscore (`_`) |
| `AIPL_W1003` | `SNAKE_CASE_AUTOFIX` | Warning | Style | Identifier in `snake_case` automatically fixable via `aipl fmt`/`aipl fix` |
| `AIPL_E2001` | `TYPE_MISMATCH` | Fatal | Types | Expression type is incompatible with destination type |
| `AIPL_E2002` | `IMPLICIT_COERCION` | Fatal | Types | Attempted implicit numeric or string type conversion |
| `AIPL_E0312` | `SILENT_FLOAT_TRUNCATION` | Fatal | Types | Silent `float -> int` narrowing rejected (`[AIPL312]`); requires `.i` or explicit cast |
| `AIPL_E2007` | `CONTRACT_VIOLATION` | Fatal | SMT | Precondition, postcondition, or invariant refuted |
| `AIPL_E2012` | `NON_EXHAUSTIVE_MATCH` | Fatal | Types | Algebraic enum pattern match does not cover all variants |
| `AIPL_E0502` | `UNIFORM_OFFSET_NOT_ALIGNED_256` | Fatal | WebGPU | WebGPU uniform buffer offset not aligned to 256 bytes |
| `AIPL_E0503` | `VERTEX_ATTRIBUTE_MISMATCH` | Fatal | Graphics | Vertex buffer attribute layout mismatch |

---

## Cross References
- [AIPL Language Specification](docs/SPEC.md)
- [AIPL Agent Specification](AI_SPEC.md)
- [AIPL Recipes Cookbook](docs/COOKBOOK.md)
- [AIPL Standard Library Reference](docs/STDLIB_REFERENCE.md)
- [AIPL Architecture](docs/ARCHITECTURE.md)
- [AIPL CLI Reference](docs/CLI_REFERENCE.md)
