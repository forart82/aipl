[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](INDEX.md) | [Cookbook](cookbook.md) | [Stdlib Reference](../STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# AIPL Progressive Language Curriculum & Learning Hub

Welcome to the **AIPL (AI-Programming Language)** progressive curriculum. This learning path takes you from first principles (clean 2-space indentation offside rule, strict immutability, zero implicit coercion, nominal types, and Design-by-Contract) all the way to advanced real-world systems programming (bump arenas, generational object pools, 2D/3D graphics with Cook-Torrance PBR, Aura immediate-mode UI, archetype ECS, and multi-target native C99 / HTML5 Canvas / WebAssembly deployment).

---

## 12-Chapter Progressive Learning Curriculum

| Chapter | Title | Focus Areas | Key Verified Examples |
| :--- | :--- | :--- | :--- |
| [01](01_getting_started_and_syntax.md) | **Getting Started & Fundamental Syntax** | Variables `let`/`mut`, primitive scalars, strict 2-space indentation, UTF-8 strings, dynamic arrays `[T]`, maps | `ex_001`–`ex_006` |
| [02](02_functions_closures_and_contracts.md) | **Functions, Closures, Contracts & Modules** | `fn`/`pub fn`, closures, `req:`/`ens:` SMT verification, multi-file barrel modules | `ex_004`, `ex_010` |
| [03](03_structs_enums_generics_and_match.md) | **Structs, Enums, Generics & Pattern Matching** | Nominal structs, receiver methods, algebraic enum ADTs, `Option[T]`, `Result[T, E]`, `?` propagation, `match` | `ex_005`, `ex_007`–`ex_011` |
| [04](04_memory_arenas_pools_and_zero_gc.md) | **Memory Management, Arenas, Pools & Zero-GC** | Regional bump arenas, generational object pools, slab allocators, GPA leak detection | `ex_022`–`ex_027` |
| [05](05_collections_math_and_text_processing.md) | **Collections, Linear Algebra & Text Processing** | `DynVec`, `HashMap`, `BTreeMap`, `Vec2`/`Vec3`/`Mat4`, SIMD, string formatting, PikeVM regex, Myers diff | `ex_028`–`ex_062` |
| [06](06_serialization_compression_crypto_and_databases.md) | **Serialization, Compression, Cryptography & Databases** | JSON, YAML, TOML, CSV, Markdown, QR, Deflate, LZ4, SHA-256, ChaCha20-Poly1305, KV-WAL, SQLite | `ex_069`–`ex_096` |
| [07](07_io_filesystem_cli_concurrency_and_networking.md) | **I/O, Filesystem, Concurrency & Networking** | Buffered streams, path safety, CLI parser, ANSI UI, atomics, MPSC channels, job DAGs, TCP/UDP/HTTP/RPC | `ex_097`–`ex_126` |
| [08](08_windowing_2d_canvas_camera_and_input.md) | **Windowing, 2D Canvas, Camera & Input** | `initWindow`, fixed-timestep loop, 2D vector shapes, camera trauma shake, Wang 47 autotiling, ActionMap | `ex_131`–`ex_173` |
| [09](09_3d_graphics_pbr_shaders_and_particles.md) | **3D Graphics, PBR, Shaders & Particles** | 3D orbit/FPS cameras, frustum culling, Cook-Torrance PBR, cascaded shadows, skinning, curl-noise particles | `ex_150`–`ex_189` |
| [10](10_aura_immediate_mode_ui_and_accessibility.md) | **Aura Immediate-Mode UI & Accessibility** | Flexbox layout, Oklch palettes, WCAG/APCA contrast checks, TextEdit, virtualized DataGrid, node graph | `ex_190`–`ex_201` |
| [11](11_ecs_spatial_worlds_physics_procgen_and_ai.md) | **ECS, Spatial Worlds, Physics, Procgen & AI** | Archetype ECS, Hex/Iso/Voxel worlds, 2D/3D physics, WFC procgen, A*/JPS/ORCA/GOAP/BehaviorTree AI | `ex_202`–`ex_245` |
| [12](12_testing_fuzzing_and_multi_target_deployment.md) | **Testing, Property Fuzzing & Multi-Target Deployment** | Assertion matchers, TAP/JUnit runner, property fuzzing, native C99, HTML5 Canvas, WASM, AI agent tooling | `ex_127`–`ex_130`, `ex_246`–`ex_250` |
| [Cookbook](cookbook.md) | **Practical Production Cookbook** | 50 copy-pasteable production recipes for systems, media, games, and web backends | `ex_001`–`ex_250` |

---

### Curriculum Section 1: Master Learning Path & 12-Chapter Progression Architecture

#### 1. Concept in 30 Seconds
Introduce the 12-chapter progressive AIPL curriculum from basic 2-space block syntax and Design-by-Contract (`req:`/`ens:`) to zero-GC regional memory, 2D/3D PBR rendering, immediate-mode Aura UI, ECS physics, and multi-target deployment.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn stdlibVersion(): StdlibVersion:` from `std/std_root.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.core.std_root_stdlibVersion_test
import * from "std/std_root"
import * from "std/prelude"

pub fn test_std_root_stdlibVersion(): int:
  let v = stdlibVersion()
  assertEqInt(v.major, 4, "major == 4")
  assertEqInt(v.minor, 0, "minor == 0")
  assertEqInt(v.patch, 0, "patch == 0")
  assertEqStr(v.prerelease, "", "prerelease empty")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_001` | [examples/ex_001_hello_world_and_io_cli.aipl](../../examples/ex_001_hello_world_and_io_cli.aipl) | `tests/examples/ex_001_hello_world_and_io_cli_test.aipl` | `./bin/aipl test tests/examples/ex_001_hello_world_and_io_cli_test.aipl` |
| `ex_002` | [examples/ex_002_primitives_and_bitwise_cli.aipl](../../examples/ex_002_primitives_and_bitwise_cli.aipl) | `tests/examples/ex_002_primitives_and_bitwise_cli_test.aipl` | `./bin/aipl test tests/examples/ex_002_primitives_and_bitwise_cli_test.aipl` |
| `ex_003` | [examples/ex_003_strings_and_interpolation_cli.aipl](../../examples/ex_003_strings_and_interpolation_cli.aipl) | `tests/examples/ex_003_strings_and_interpolation_cli_test.aipl` | `./bin/aipl test tests/examples/ex_003_strings_and_interpolation_cli_test.aipl` |

---

### Curriculum Section 2: The 3-Part Pedagogical Formula (Concept in 30s + Minimal Runnable Example + Common Pitfalls)

#### 1. Concept in 30 Seconds
Explain the standardized 3-part tutorial structure and show how AIPL compiler diagnostics (`E1xx` syntax, `E2xx` type/coercion, `E3xx` contract/SMT) guide developers and AI agents.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn Some(val: any):` from `std/prelude.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.core.prelude_Some_test
import * from "std/prelude"

pub fn test_prelude_Some(): int:
  let a = Some(42)
  let b = Some(0)
  assert(a.isSome() == true, "Some(42) isSome")
  assertEqInt(a.unwrap(), 42, "Some(42) unwraps to 42")
  assert(b.isSome() == true, "Some(0) isSome")
  assertEqInt(b.unwrap(), 0, "Some(0) unwraps to 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_004` | [examples/ex_004_control_flow_and_loops_cli.aipl](../../examples/ex_004_control_flow_and_loops_cli.aipl) | `tests/examples/ex_004_control_flow_and_loops_cli_test.aipl` | `./bin/aipl test tests/examples/ex_004_control_flow_and_loops_cli_test.aipl` |
| `ex_005` | [examples/ex_005_structs_methods_and_immutability_cli.aipl](../../examples/ex_005_structs_methods_and_immutability_cli.aipl) | `tests/examples/ex_005_structs_methods_and_immutability_cli_test.aipl` | `./bin/aipl test tests/examples/ex_005_structs_methods_and_immutability_cli_test.aipl` |
| `ex_006` | [examples/ex_006_enums_and_pattern_matching_cli.aipl](../../examples/ex_006_enums_and_pattern_matching_cli.aipl) | `tests/examples/ex_006_enums_and_pattern_matching_cli_test.aipl` | `./bin/aipl test tests/examples/ex_006_enums_and_pattern_matching_cli_test.aipl` |

---

### Curriculum Section 3: Complete Mapping of All 250 Curated Examples (ex_001..ex_250) & Twin Tests

#### 1. Concept in 30 Seconds
Map all 250 curated examples (`118` CLI + `132` Window apps in `examples/ex_001_hello_world_and_io_cli.aipl` .. `ex_250_*.aipl`) and their post-`step_16` twin tests (`tests/examples/ex_001_*_test.aipl` .. `ex_250_*_test.aipl`) across Chapters 01–12.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn stdlibVersionString(): str:` from `std/std_root.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.core.std_root_stdlibVersionString_test
import * from "std/std_root"
import * from "std/prelude"

pub fn test_std_root_stdlibVersionString(): int:
  let v = stdlibVersion()
  let s = stdlibVersionString()
  assertEqStr(s, "4.0.0", "version string is 4.0.0")
  assertEqStr(s, str(v.major) + "." + str(v.minor) + "." + str(v.patch), "matches struct fields")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_010` | [examples/ex_010_modules_and_multi_file_imports_cli.aipl](../../examples/ex_010_modules_and_multi_file_imports_cli.aipl) | `tests/examples/ex_010_modules_and_multi_file_imports_cli_test.aipl` | `./bin/aipl test tests/examples/ex_010_modules_and_multi_file_imports_cli_test.aipl` |
| `ex_100` | [examples/ex_100_fs_file_atomic_write_cli.aipl](../../examples/ex_100_fs_file_atomic_write_cli.aipl) | `tests/examples/ex_100_fs_file_atomic_write_cli_test.aipl` | `./bin/aipl test tests/examples/ex_100_fs_file_atomic_write_cli_test.aipl` |
| `ex_200` | [examples/ex_200_ui_anim_spring_transitions_window.aipl](../../examples/ex_200_ui_anim_spring_transitions_window.aipl) | `tests/examples/ex_200_ui_anim_spring_transitions_window_test.aipl` | `./bin/aipl test tests/examples/ex_200_ui_anim_spring_transitions_window_test.aipl` |
| `ex_250` | [examples/ex_250_mechanics_full_capstone_application_window.aipl](../../examples/ex_250_mechanics_full_capstone_application_window.aipl) | `tests/examples/ex_250_mechanics_full_capstone_application_window_test.aipl` | `./bin/aipl test tests/examples/ex_250_mechanics_full_capstone_application_window_test.aipl` |

---

### Curriculum Section 4: Multi-Target Execution Guide (Interpreter, Native C99, HTML5 Canvas, WebAssembly)

#### 1. Concept in 30 Seconds
Document how to run every tutorial snippet and example across the bytecode interpreter (`./bin/aipl run`), native C99 (`--native`), standalone browser HTML5 (`--target html`), and WebAssembly (`--target wasm`).

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn createWindowSurface(title: str, width: int, height: int, presentMode: int = 2): WindowSurface:` from `std/window/surface.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.window.surface_z1_test
import * from "std/window/surface"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_surface_createWindowSurface_1(): int:
  let arg_title = "test"
  let edge_title = "a"
  let arg_width = 4
  let edge_width = 1
  let arg_height = 4
  let edge_height = 1
  let arg_presentMode = 4
  let edge_presentMode = 1
  let resNom = createWindowSurface(arg_title, arg_width, arg_height, arg_presentMode)
  let resEdge = createWindowSurface(edge_title, edge_width, edge_height, edge_presentMode)
  assertEqInt(resNom.handle, 1, "createWindowSurface nominal resNom.handle == 1")
  assertEqInt(resEdge.handle, 1, "createWindowSurface boundary resEdge.handle == 1")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_015` | [examples/ex_015_sys_ffi_c_abi_bridge_cli.aipl](../../examples/ex_015_sys_ffi_c_abi_bridge_cli.aipl) | `tests/examples/ex_015_sys_ffi_c_abi_bridge_cli_test.aipl` | `./bin/aipl test tests/examples/ex_015_sys_ffi_c_abi_bridge_cli_test.aipl` |
| `ex_016` | [examples/ex_016_sys_audio_pcm_ring_cli.aipl](../../examples/ex_016_sys_audio_pcm_ring_cli.aipl) | `tests/examples/ex_016_sys_audio_pcm_ring_cli_test.aipl` | `./bin/aipl test tests/examples/ex_016_sys_audio_pcm_ring_cli_test.aipl` |
| `ex_131` | [examples/ex_131_window_app_loop_fixed_timestep_window.aipl](../../examples/ex_131_window_app_loop_fixed_timestep_window.aipl) | `tests/examples/ex_131_window_app_loop_fixed_timestep_window_test.aipl` | `./bin/aipl test tests/examples/ex_131_window_app_loop_fixed_timestep_window_test.aipl` |
| `ex_246` | [examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl](../../examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl) | `tests/examples/ex_246_mechanics_attribute_modifier_sheet_window_test.aipl` | `./bin/aipl test tests/examples/ex_246_mechanics_attribute_modifier_sheet_window_test.aipl` |
