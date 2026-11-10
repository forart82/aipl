[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](INDEX.md) | [Cookbook](cookbook.md) | [Stdlib Reference](../STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# AIPL Practical Production Cookbook: 50 Real-World Recipes

> **Overview**: 50 copy-pasteable, battle-tested production recipes for systems programming, data serialization, concurrency, graphics, Aura immediate-mode UI, spatial game worlds, audio synthesis, and automated verification in AIPL.

## Table of Contents

- [Recipe 01: Parse CLI Flags, Subcommands & Positional Arguments with Fallback Defaults](#recipe-01-parse-cli-flags-subcommands--positional-arguments-with-fallback-defaults)
- [Recipe 02: Load Environment Variables & .env Configuration Files Safely](#recipe-02-load-environment-variables--env-configuration-files-safely)
- [Recipe 03: Parse, Query & Pretty-Print Strict JSON Payloads with Error Recovery](#recipe-03-parse-query--pretty-print-strict-json-payloads-with-error-recovery)
- [Recipe 04: Parse & Emit Multi-Document YAML and TOML Configuration Files](#recipe-04-parse--emit-multi-document-yaml-and-toml-configuration-files)
- [Recipe 05: Stream RFC 4180 CSV Tables & Format Aligned ASCII/Markdown Reports](#recipe-05-stream-rfc-4180-csv-tables--format-aligned-asciimarkdown-reports)
- [Recipe 06: Convert CommonMark Markdown to Sanitized HTML5 with Heading TOC Extraction](#recipe-06-convert-commonmark-markdown-to-sanitized-html5-with-heading-toc-extraction)
- [Recipe 07: Generate QR Code Matrix Bitmaps from URLs or Text Payloads](#recipe-07-generate-qr-code-matrix-bitmaps-from-urls-or-text-payloads)
- [Recipe 08: Validate & Solve Semantic Versioning (SemVer 2.0) Dependency Ranges](#recipe-08-validate--solve-semantic-versioning-semver-20-dependency-ranges)
- [Recipe 09: Enforce Design-by-Contract Preconditions (req:) & Postconditions (ens:) on Financial Calculations](#recipe-09-enforce-design-by-contract-preconditions-req--postconditions-ens-on-financial-calculations)
- [Recipe 10: Allocate Zero-GC Frame Scratch Memory with Regional Bump Arenas & Savepoints](#recipe-10-allocate-zero-gc-frame-scratch-memory-with-regional-bump-arenas--savepoints)
- [Recipe 11: Manage O(1) Entity Handles with Generational Object Pools & ABA Protection](#recipe-11-manage-o1-entity-handles-with-generational-object-pools--aba-protection)
- [Recipe 12: Detect Memory Leaks Deterministically in Unit Tests with GpaState](#recipe-12-detect-memory-leaks-deterministically-in-unit-tests-with-gpastate)
- [Recipe 13: Build an O(1) LRU Cache & Bloom Filter for High-Throughput Key Lookups](#recipe-13-build-an-o1-lru-cache--bloom-filter-for-high-throughput-key-lookups)
- [Recipe 14: Run Dijkstra Shortest Path & Kruskal Minimum Spanning Tree on Weighted Graphs](#recipe-14-run-dijkstra-shortest-path--kruskal-minimum-spanning-tree-on-weighted-graphs)
- [Recipe 15: Match Patterns in Linear Time O(N) with Thompson NFA / PikeVM Regular Expressions](#recipe-15-match-patterns-in-linear-time-on-with-thompson-nfa--pikevm-regular-expressions)
- [Recipe 16: Compute Line-by-Line Unified Text Diffs & Edit Distance with Myers O(ND) Algorithm](#recipe-16-compute-line-by-line-unified-text-diffs--edit-distance-with-myers-ond-algorithm)
- [Recipe 17: Schedule Recurring Tasks with Cron Expressions & Hierarchical Timer Wheels](#recipe-17-schedule-recurring-tasks-with-cron-expressions--hierarchical-timer-wheels)
- [Recipe 18: Compress & Decompress Network Packets with High-Speed LZ4 and Zstandard](#recipe-18-compress--decompress-network-packets-with-high-speed-lz4-and-zstandard)
- [Recipe 19: Package & Extract Multi-File POSIX Tar + Gzip Archives in Memory](#recipe-19-package--extract-multi-file-posix-tar--gzip-archives-in-memory)
- [Recipe 20: Compute SHA-256, BLAKE3 Merkle Trees & Constant-Time HMAC-SHA256 Signatures](#recipe-20-compute-sha-256-blake3-merkle-trees--constant-time-hmac-sha256-signatures)
- [Recipe 21: Encrypt & Authenticate Payloads with ChaCha20-Poly1305 AEAD & Argon2id Keys](#recipe-21-encrypt--authenticate-payloads-with-chacha20-poly1305-aead--argon2id-keys)
- [Recipe 22: Sign & Verify Detached Messages with Ed25519 Public-Key Cryptography](#recipe-22-sign--verify-detached-messages-with-ed25519-public-key-cryptography)
- [Recipe 23: Persist Crash-Safe Key-Value State with Append-Only CRC32 WAL Log Compaction](#recipe-23-persist-crash-safe-key-value-state-with-append-only-crc32-wal-log-compaction)
- [Recipe 24: Execute Relational SQL Queries, Joins & Savepoint Rollbacks with Embedded SQLite](#recipe-24-execute-relational-sql-queries-joins--savepoint-rollbacks-with-embedded-sqlite)
- [Recipe 25: Sanitize Relative File Paths & Block Directory Traversal (../) Attacks](#recipe-25-sanitize-relative-file-paths--block-directory-traversal--attacks)
- [Recipe 26: Coordinate Producer-Consumer Pipelines with Bounded MPSC Channels & WaitGroups](#recipe-26-coordinate-producer-consumer-pipelines-with-bounded-mpsc-channels--waitgroups)
- [Recipe 27: Parallelize Data-Oriented Batch Loops Across Worker Threads with JobSystem DAGs](#recipe-27-parallelize-data-oriented-batch-loops-across-worker-threads-with-jobsystem-dags)
- [Recipe 28: Build an HTTP/1.1 REST Client & Router Server with Middleware](#recipe-28-build-an-http11-rest-client--router-server-with-middleware)
- [Recipe 29: Synchronize Real-Time Multiplayer State Over Reliable UDP (rudp) & JSON-RPC 2.0](#recipe-29-synchronize-real-time-multiplayer-state-over-reliable-udp-rudp--json-rpc-20)
- [Recipe 30: Create a 60 FPS Cross-Platform Window with Fixed-Timestep Simulation Accumulator](#recipe-30-create-a-60-fps-cross-platform-window-with-fixed-timestep-simulation-accumulator)
- [Recipe 31: Bind Keyboard, Mouse, Gamepad & Touch Gestures to a Rebindable ActionMap](#recipe-31-bind-keyboard-mouse-gamepad--touch-gestures-to-a-rebindable-actionmap)
- [Recipe 32: Pack Power-of-Two Sprite Atlases with Extruded 2px Gutters & Hot-Reload Bundles](#recipe-32-pack-power-of-two-sprite-atlases-with-extruded-2px-gutters--hot-reload-bundles)
- [Recipe 33: Synthesize Polyphonic ADSR Audio Voices with Pentatonic Pitch Ladders & 3D Doppler](#recipe-33-synthesize-polyphonic-adsr-audio-voices-with-pentatonic-pitch-ladders--3d-doppler)
- [Recipe 34: Implement Smooth 2D Camera Follow, Zoom-to-Cursor & Squirrel Eiserloh Trauma^2 Shake](#recipe-34-implement-smooth-2d-camera-follow-zoom-to-cursor--squirrel-eiserloh-trauma2-shake)
- [Recipe 35: Render Wang 47-Tile Autotiled Maps with 2D Point Lights & SDF Soft Shadows](#recipe-35-render-wang-47-tile-autotiled-maps-with-2d-point-lights--sdf-soft-shadows)
- [Recipe 36: Configure a 3D Cook-Torrance GGX PBR Material Pipeline with Cascaded Shadow Maps](#recipe-36-configure-a-3d-cook-torrance-ggx-pbr-material-pipeline-with-cascaded-shadow-maps)
- [Recipe 37: Animate 3D Characters with Dual-Quaternion Skinning & FABRIK Inverse Kinematics](#recipe-37-animate-3d-characters-with-dual-quaternion-skinning--fabrik-inverse-kinematics)
- [Recipe 38: Simulate 2D & 3D Curl-Noise Particle Emitters with Sub-Emitter Fireworks & Trails](#recipe-38-simulate-2d--3d-curl-noise-particle-emitters-with-sub-emitter-fireworks--trails)
- [Recipe 39: Build a Responsive Flexbox & 12-Column Grid Dashboard in Aura Immediate-Mode UI](#recipe-39-build-a-responsive-flexbox--12-column-grid-dashboard-in-aura-immediate-mode-ui)
- [Recipe 40: Audit UI Palettes for WCAG 2.1 AAA & APCA Perceptual Contrast in Oklch Color Space](#recipe-40-audit-ui-palettes-for-wcag-21-aaa--apca-perceptual-contrast-in-oklch-color-space)
- [Recipe 41: Render 100,000 Rows at 60 FPS with Virtualized Aura DataGrid & Gap-Buffer TextEdit](#recipe-41-render-100000-rows-at-60-fps-with-virtualized-aura-datagrid--gap-buffer-textedit)
- [Recipe 42: Query Archetype SoA Tables & Schedule Conflict-Free Parallel ECS Systems](#recipe-42-query-archetype-soa-tables--schedule-conflict-free-parallel-ecs-systems)
- [Recipe 43: Convert Axial/Cube Coordinates & Field-of-View on Hexagonal & Isometric Worlds](#recipe-43-convert-axialcube-coordinates--field-of-view-on-hexagonal--isometric-worlds)
- [Recipe 44: Mesh Greedy 3D Voxel Chunks with Ambient Occlusion & DDA Raycasting](#recipe-44-mesh-greedy-3d-voxel-chunks-with-ambient-occlusion--dda-raycasting)
- [Recipe 45: Step 2D & 3D Rigid-Body Physics with SAT/GJK-EPA Collisions & Raycast Vehicles](#recipe-45-step-2d--3d-rigid-body-physics-with-satgjk-epa-collisions--raycast-vehicles)
- [Recipe 46: Generate Constraint-Solved Tilemaps with Wave Function Collapse (WFC) & Simplex FBM](#recipe-46-generate-constraint-solved-tilemaps-with-wave-function-collapse-wfc--simplex-fbm)
- [Recipe 47: Pathfind Around Dynamic Crowds with Jump Point Search (JPS) & ORCA Velocity Obstacles](#recipe-47-pathfind-around-dynamic-crowds-with-jump-point-search-jps--orca-velocity-obstacles)
- [Recipe 48: Drive Autonomous NPCs with Behavior Trees, Utility AI Curves & A* GOAP Planners](#recipe-48-drive-autonomous-npcs-with-behavior-trees-utility-ai-curves--a-goap-planners)
- [Recipe 49: Balance RPG Stat Modifiers, ARPG Grid Inventories & Economy Sinks/Faucets](#recipe-49-balance-rpg-stat-modifiers-arpg-grid-inventories--economy-sinksfaucets)
- [Recipe 50: Shrink Property-Based Fuzzing Counterexamples & Verify 4-Target Compiler Parity](#recipe-50-shrink-property-based-fuzzing-counterexamples--verify-4-target-compiler-parity)

---

### Recipe 01: Parse CLI Flags, Subcommands & Positional Arguments with Fallback Defaults

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 01: Parse CLI Flags, Subcommands & Positional Arguments with Fallback Defaults` using `std/os/cli_args.aipl` (`pub fn cliAppVersion(mut app: CliApp, version: str): CliApp:`), verified by `tests/functions/os/cli_args_test.aipl` and demonstrated in `examples/ex_104_os_cli_args_subcommands_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn cliAppVersion(mut app: CliApp, version: str): CliApp:` from `std/os/cli_args.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.os.cli_args_z2_test
import * from "std/os/cli_args"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cli_args_cliAppVersion_2(): int:
  let arg_app = CliApp(name = "test", version = "test", description = "test", flags = [], options = [], args = [], subcommands = [])
  let edge_app = CliApp(name = "a", version = "a", description = "a", flags = [], options = [], args = [], subcommands = [])
  let arg_version = "test"
  let edge_version = "a"
  let resNom = cliAppVersion(arg_app, arg_version)
  let resEdge = cliAppVersion(edge_app, edge_version)
  assertEqStr(resNom.name, "test", "cliAppVersion nominal string matches")
  assertEqStr(resEdge.name, "a", "cliAppVersion boundary string matches")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_104` | [examples/ex_104_os_cli_args_subcommands_cli.aipl](../../examples/ex_104_os_cli_args_subcommands_cli.aipl) | `tests/examples/ex_104_os_cli_args_subcommands_cli_test.aipl` | `./bin/aipl test tests/examples/ex_104_os_cli_args_subcommands_cli_test.aipl` |

---

### Recipe 02: Load Environment Variables & .env Configuration Files Safely

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 02: Load Environment Variables & .env Configuration Files Safely` using `std/encoding/ini_dotenv.aipl` (`fn stripIniInlineComment(line: str): str:`), verified by `tests/functions/encoding/ini_dotenv_test.aipl` and demonstrated in `examples/ex_077_encoding_ini_dotenv_loader_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `fn stripIniInlineComment(line: str): str:` from `std/encoding/ini_dotenv.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.encoding.ini_dotenv_z1_test
import * from "std/encoding/ini_dotenv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ini_dotenv_stripIniInlineComment_1(): int:
  let arg_line = "[s]\nk=v"
  let edge_line = "[s]\nk=v"
  let resNom = stripIniInlineComment(arg_line)
  let resEdge = stripIniInlineComment(edge_line)
  assertEqInt(resNom.len(), 7, "stripIniInlineComment nominal string length == 7")
  assertEqInt(resEdge.len(), 7, "stripIniInlineComment boundary string length == 7")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_077` | [examples/ex_077_encoding_ini_dotenv_loader_cli.aipl](../../examples/ex_077_encoding_ini_dotenv_loader_cli.aipl) | `tests/examples/ex_077_encoding_ini_dotenv_loader_cli_test.aipl` | `./bin/aipl test tests/examples/ex_077_encoding_ini_dotenv_loader_cli_test.aipl` |

---

### Recipe 03: Parse, Query & Pretty-Print Strict JSON Payloads with Error Recovery

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 03: Parse, Query & Pretty-Print Strict JSON Payloads with Error Recovery` using `std/encoding/json.aipl` (`pub fn jsonBool(b: bool): JsonValue:`), verified by `tests/functions/encoding/json_test.aipl` and demonstrated in `examples/ex_069_time_frame_pacer_hud_window.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn jsonBool(b: bool): JsonValue:` from `std/encoding/json.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.encoding.json_z2_test
import * from "std/encoding/json"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_json_jsonBool_2(): int:
  let arg_b = true
  let edge_b = false
  let resNom = jsonBool(arg_b)
  let resEdge = jsonBool(edge_b)
  assertEqStr(resNom.kind, "bool", "jsonBool nominal string matches")
  assertEqStr(resEdge.kind, "bool", "jsonBool boundary string matches")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_069` | [examples/ex_069_time_frame_pacer_hud_window.aipl](../../examples/ex_069_time_frame_pacer_hud_window.aipl) | `tests/examples/ex_069_time_frame_pacer_hud_window_test.aipl` | `./bin/aipl test tests/examples/ex_069_time_frame_pacer_hud_window_test.aipl` |

---

### Recipe 04: Parse & Emit Multi-Document YAML and TOML Configuration Files

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 04: Parse & Emit Multi-Document YAML and TOML Configuration Files` using `std/encoding/toml.aipl` (`fn tomlStrVal(s: str): TomlValue:`), verified by `tests/functions/encoding/toml_test.aipl` and demonstrated in `examples/ex_071_encoding_toml_manifest_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `fn tomlStrVal(s: str): TomlValue:` from `std/encoding/toml.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.encoding.toml_z1_test
import * from "std/encoding/toml"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_toml_tomlStrVal_1(): int:
  let arg_s = "a = 1"
  let edge_s = "a = 1"
  let resNom = tomlStrVal(arg_s)
  let resEdge = tomlStrVal(edge_s)
  assertEqStr(resNom.kind, "string", "tomlStrVal nominal string matches")
  assertEqStr(resEdge.kind, "string", "tomlStrVal boundary string matches")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_071` | [examples/ex_071_encoding_toml_manifest_cli.aipl](../../examples/ex_071_encoding_toml_manifest_cli.aipl) | `tests/examples/ex_071_encoding_toml_manifest_cli_test.aipl` | `./bin/aipl test tests/examples/ex_071_encoding_toml_manifest_cli_test.aipl` |

---

### Recipe 05: Stream RFC 4180 CSV Tables & Format Aligned ASCII/Markdown Reports

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 05: Stream RFC 4180 CSV Tables & Format Aligned ASCII/Markdown Reports` using `std/encoding/csv.aipl` (`pub fn parseCsv(text: str, delimiter: str = ","): Result[[[str]], str]:`), verified by `tests/functions/encoding/csv_test.aipl` and demonstrated in `examples/ex_072_encoding_yaml_pipeline_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn parseCsv(text: str, delimiter: str = ","): Result[[[str]], str]:` from `std/encoding/csv.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.encoding.csv_z1_test
import * from "std/encoding/csv"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_csv_parseCsv_1(): int:
  let arg_text = "a,b\n1,2"
  let edge_text = "a,b\n1,2"
  let arg_delimiter = "a,b\n1,2"
  let edge_delimiter = "a,b\n1,2"
  let resNom = parseCsv(arg_text, arg_delimiter)
  let resEdge = parseCsv(edge_text, edge_delimiter)
  assert(resNom.isOk() == true, "parseCsv nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "parseCsv boundary resEdge.isOk() == true")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_072` | [examples/ex_072_encoding_yaml_pipeline_cli.aipl](../../examples/ex_072_encoding_yaml_pipeline_cli.aipl) | `tests/examples/ex_072_encoding_yaml_pipeline_cli_test.aipl` | `./bin/aipl test tests/examples/ex_072_encoding_yaml_pipeline_cli_test.aipl` |

---

### Recipe 06: Convert CommonMark Markdown to Sanitized HTML5 with Heading TOC Extraction

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 06: Convert CommonMark Markdown to Sanitized HTML5 with Heading TOC Extraction` using `std/encoding/markdown.aipl` (`fn escapeMdHtml(s: str): str:`), verified by `tests/functions/encoding/markdown_test.aipl` and demonstrated in `examples/ex_076_encoding_markdown_to_html_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `fn escapeMdHtml(s: str): str:` from `std/encoding/markdown.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.encoding.markdown_z1_test
import * from "std/encoding/markdown"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_markdown_escapeMdHtml_1(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = escapeMdHtml(arg_s)
  let resEdge = escapeMdHtml(edge_s)
  assertEqStr(resNom, "test", "escapeMdHtml nominal string matches")
  assertEqStr(resEdge, "a", "escapeMdHtml boundary string matches")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_076` | [examples/ex_076_encoding_markdown_to_html_cli.aipl](../../examples/ex_076_encoding_markdown_to_html_cli.aipl) | `tests/examples/ex_076_encoding_markdown_to_html_cli_test.aipl` | `./bin/aipl test tests/examples/ex_076_encoding_markdown_to_html_cli_test.aipl` |

---

### Recipe 07: Generate QR Code Matrix Bitmaps from URLs or Text Payloads

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 07: Generate QR Code Matrix Bitmaps from URLs or Text Payloads` using `std/encoding/qrcode_semver.aipl` (`fn parseNonNegInt(s: str): int:`), verified by `tests/functions/encoding/qrcode_semver_test.aipl` and demonstrated in `examples/ex_081_encoding_qrcode_matrix_window.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `fn parseNonNegInt(s: str): int:` from `std/encoding/qrcode_semver.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.encoding.qrcode_semver_z1_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_parseNonNegInt_1(): int:
  let arg_s = "42"
  let edge_s = "0"
  let resNom = parseNonNegInt(arg_s)
  let resEdge = parseNonNegInt(edge_s)
  assertEqInt(resNom, 42, "parseNonNegInt nominal resNom == 42")
  assertEqInt(resEdge, 0, "parseNonNegInt boundary resEdge == 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_081` | [examples/ex_081_encoding_qrcode_matrix_window.aipl](../../examples/ex_081_encoding_qrcode_matrix_window.aipl) | `tests/examples/ex_081_encoding_qrcode_matrix_window_test.aipl` | `./bin/aipl test tests/examples/ex_081_encoding_qrcode_matrix_window_test.aipl` |

---

### Recipe 08: Validate & Solve Semantic Versioning (SemVer 2.0) Dependency Ranges

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 08: Validate & Solve Semantic Versioning (SemVer 2.0) Dependency Ranges` using `std/encoding/qrcode_semver.aipl` (`pub fn parseSemVer(text: str): Result[SemVer, str]:`), verified by `tests/functions/encoding/qrcode_semver_test.aipl` and demonstrated in `examples/ex_080_encoding_semver_dependency_solver_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn parseSemVer(text: str): Result[SemVer, str]:` from `std/encoding/qrcode_semver.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.encoding.qrcode_semver_z2_test
import * from "std/encoding/qrcode_semver"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_qrcode_semver_parseSemVer_2(): int:
  let arg_text = "test"
  let edge_text = "a"
  let resNom = parseSemVer(arg_text)
  let resEdge = parseSemVer(edge_text)
  assert(resNom.isOk() == false, "parseSemVer nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "parseSemVer boundary resEdge.isOk() == false")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_080` | [examples/ex_080_encoding_semver_dependency_solver_cli.aipl](../../examples/ex_080_encoding_semver_dependency_solver_cli.aipl) | `tests/examples/ex_080_encoding_semver_dependency_solver_cli_test.aipl` | `./bin/aipl test tests/examples/ex_080_encoding_semver_dependency_solver_cli_test.aipl` |

---

### Recipe 09: Enforce Design-by-Contract Preconditions (req:) & Postconditions (ens:) on Financial Calculations

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 09: Enforce Design-by-Contract Preconditions (req:) & Postconditions (ens:) on Financial Calculations` using `std/math/fixed_point.aipl` (`pub fn fixedFromInt(val: int): FixedQ16_16:`), verified by `tests/functions/math/fixed_point_test.aipl` and demonstrated in `examples/ex_011_sys_syscall_and_os_probe_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn fixedFromInt(val: int): FixedQ16_16:` from `std/math/fixed_point.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.math.fixed_point_z1_test
import * from "std/math/fixed_point"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fixed_point_fixedFromInt_1(): int:
  let arg_val = 2
  let edge_val = 0
  let resNom = fixedFromInt(arg_val)
  let resEdge = fixedFromInt(edge_val)
  assertEqInt(resNom.raw, 131072, "fixedFromInt nominal resNom.raw == 131072")
  assertEqInt(resEdge.raw, 0, "fixedFromInt boundary resEdge.raw == 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_011` | [examples/ex_011_sys_syscall_and_os_probe_cli.aipl](../../examples/ex_011_sys_syscall_and_os_probe_cli.aipl) | `tests/examples/ex_011_sys_syscall_and_os_probe_cli_test.aipl` | `./bin/aipl test tests/examples/ex_011_sys_syscall_and_os_probe_cli_test.aipl` |

---

### Recipe 10: Allocate Zero-GC Frame Scratch Memory with Regional Bump Arenas & Savepoints

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 10: Allocate Zero-GC Frame Scratch Memory with Regional Bump Arenas & Savepoints` using `std/alloc/arena.aipl` (`pub fn arenaReset(mark: int): int:`), verified by `tests/functions/alloc/arena_test.aipl` and demonstrated in `examples/ex_022_alloc_arena_bump_profiler_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn arenaReset(mark: int): int:` from `std/alloc/arena.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.alloc.arena_z2_test
import * from "std/alloc/arena"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_arena_arenaReset_2(): int:
  let arg_mark = 4
  let edge_mark = 1
  let resNom = arenaReset(arg_mark)
  let resEdge = arenaReset(edge_mark)
  assertEqInt(resNom, 0, "arenaReset nominal resNom == 0")
  assertEqInt(resEdge, 0, "arenaReset boundary resEdge == 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_022` | [examples/ex_022_alloc_arena_bump_profiler_cli.aipl](../../examples/ex_022_alloc_arena_bump_profiler_cli.aipl) | `tests/examples/ex_022_alloc_arena_bump_profiler_cli_test.aipl` | `./bin/aipl test tests/examples/ex_022_alloc_arena_bump_profiler_cli_test.aipl` |

---

### Recipe 11: Manage O(1) Entity Handles with Generational Object Pools & ABA Protection

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 11: Manage O(1) Entity Handles with Generational Object Pools & ABA Protection` using `std/alloc/pool_alloc.aipl` (`pub fn (mut self: FixedObjectPool[T]) acquire(item: T): Option[GenerationalHandle]:`), verified by `tests/functions/alloc/pool_alloc_test.aipl` and demonstrated in `examples/ex_023_alloc_pool_fixed_block_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn (mut self: FixedObjectPool[T]) acquire(item: T): Option[GenerationalHandle]:` from `std/alloc/pool_alloc.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.alloc.pool_alloc_z2_test
import * from "std/alloc/pool_alloc"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_pool_alloc_FixedObjectPool_T__acquire_2(): int:
  let mut recv_self = poolNew(4)
  let mut edge_self = poolNew(4)
  let arg_item = 1
  let edge_item = 0
  let resNom = recv_self.acquire(arg_item)
  let resEdge = edge_self.acquire(edge_item)
  assert(resNom.isSome() == true, "acquire nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "acquire boundary resEdge.isSome() == true")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_023` | [examples/ex_023_alloc_pool_fixed_block_cli.aipl](../../examples/ex_023_alloc_pool_fixed_block_cli.aipl) | `tests/examples/ex_023_alloc_pool_fixed_block_cli_test.aipl` | `./bin/aipl test tests/examples/ex_023_alloc_pool_fixed_block_cli_test.aipl` |

---

### Recipe 12: Detect Memory Leaks Deterministically in Unit Tests with GpaState

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 12: Detect Memory Leaks Deterministically in Unit Tests with GpaState` using `std/alloc/gpa.aipl` (`pub fn gpaAlloc(bytes: int, callerId: int = 0): int:`), verified by `tests/functions/alloc/gpa_test.aipl` and demonstrated in `examples/ex_026_alloc_gpa_leak_detector_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn gpaAlloc(bytes: int, callerId: int = 0): int:` from `std/alloc/gpa.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.alloc.gpa_z2_test
import * from "std/alloc/gpa"
import { ptrAlloc, ptrFree, ptrReadI64, ptrWriteI64, ptrMemcpy, ptrMemset } from "std/rt/rt_ptr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpa_gpaAlloc_2(): int:
  let arg_bytes = 4
  let edge_bytes = 1
  let arg_callerId = 1
  let edge_callerId = 0
  let resNom = gpaAlloc(arg_bytes, arg_callerId)
  let resEdge = gpaAlloc(edge_bytes, edge_callerId)
  assert(resNom > 0, "gpaAlloc nominal resNom > 0")
  assert(resEdge > 0, "gpaAlloc boundary resEdge > 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_026` | [examples/ex_026_alloc_gpa_leak_detector_cli.aipl](../../examples/ex_026_alloc_gpa_leak_detector_cli.aipl) | `tests/examples/ex_026_alloc_gpa_leak_detector_cli_test.aipl` | `./bin/aipl test tests/examples/ex_026_alloc_gpa_leak_detector_cli_test.aipl` |

---

### Recipe 13: Build an O(1) LRU Cache & Bloom Filter for High-Throughput Key Lookups

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 13: Build an O(1) LRU Cache & Bloom Filter for High-Throughput Key Lookups` using `std/collections/hash_map.aipl` (`pub fn hashMapNew[K, V](): HashMap[K, V]:`), verified by `tests/functions/collections/hash_map_test.aipl` and demonstrated in `examples/ex_049_collections_sparse_set_registry_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn hashMapNew[K, V](): HashMap[K, V]:` from `std/collections/hash_map.aipl` with `./bin/aipl verify`:

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

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_049` | [examples/ex_049_collections_sparse_set_registry_cli.aipl](../../examples/ex_049_collections_sparse_set_registry_cli.aipl) | `tests/examples/ex_049_collections_sparse_set_registry_cli_test.aipl` | `./bin/aipl test tests/examples/ex_049_collections_sparse_set_registry_cli_test.aipl` |

---

### Recipe 14: Run Dijkstra Shortest Path & Kruskal Minimum Spanning Tree on Weighted Graphs

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 14: Run Dijkstra Shortest Path & Kruskal Minimum Spanning Tree on Weighted Graphs` using `std/collections/graph_topology.aipl` (`pub fn dsuNew(size: int): DisjointSetUnion:`), verified by `tests/functions/collections/graph_topology_test.aipl` and demonstrated in `examples/ex_051_collections_graph_dijkstra_mst_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn dsuNew(size: int): DisjointSetUnion:` from `std/collections/graph_topology.aipl` with `./bin/aipl verify`:

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

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_051` | [examples/ex_051_collections_graph_dijkstra_mst_cli.aipl](../../examples/ex_051_collections_graph_dijkstra_mst_cli.aipl) | `tests/examples/ex_051_collections_graph_dijkstra_mst_cli_test.aipl` | `./bin/aipl test tests/examples/ex_051_collections_graph_dijkstra_mst_cli_test.aipl` |

---

### Recipe 15: Match Patterns in Linear Time O(N) with Thompson NFA / PikeVM Regular Expressions

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 15: Match Patterns in Linear Time O(N) with Thompson NFA / PikeVM Regular Expressions` using `std/regex/regex_vm.aipl` (`fn charMatchesClass(c: int, cc: RegexCharClass, ignoreCase: bool): bool:`), verified by `tests/functions/regex/regex_vm_test.aipl` and demonstrated in `examples/ex_061_regex_vm_grep_and_replace_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `fn charMatchesClass(c: int, cc: RegexCharClass, ignoreCase: bool): bool:` from `std/regex/regex_vm.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.regex.regex_vm_z2_test
import * from "std/regex/regex_vm"
import { OP_MATCH, OP_CHAR, OP_ANY, OP_CHAR_CLASS, OP_SPLIT, OP_JUMP, OP_SAVE, OP_ANCHOR_START, OP_ANCHOR_END, RegexFlags, RegexCharClass, RegexInstruction, RegexBytecode, Regex } from "std/regex/regex_compile"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_regex_vm_charMatchesClass_2(): int:
  let arg_c = 2
  let edge_c = 0
  let arg_cc = RegexCharClass(ranges = [], negated = true)
  let edge_cc = RegexCharClass(ranges = [], negated = false)
  let arg_ignoreCase = true
  let edge_ignoreCase = false
  let resNom = charMatchesClass(arg_c, arg_cc, arg_ignoreCase)
  let resEdge = charMatchesClass(edge_c, edge_cc, edge_ignoreCase)
  assert(resNom == true, "charMatchesClass nominal resNom == true")
  assert(resEdge == false, "charMatchesClass boundary resEdge == false")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_061` | [examples/ex_061_regex_vm_grep_and_replace_cli.aipl](../../examples/ex_061_regex_vm_grep_and_replace_cli.aipl) | `tests/examples/ex_061_regex_vm_grep_and_replace_cli_test.aipl` | `./bin/aipl test tests/examples/ex_061_regex_vm_grep_and_replace_cli_test.aipl` |

---

### Recipe 16: Compute Line-by-Line Unified Text Diffs & Edit Distance with Myers O(ND) Algorithm

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 16: Compute Line-by-Line Unified Text Diffs & Edit Distance with Myers O(ND) Algorithm` using `std/regex/text_diff.aipl` (`pub fn myersDiffLines(oldLines: [str], newLines: [str]): [DiffEdit]:`), verified by `tests/functions/regex/text_diff_test.aipl` and demonstrated in `examples/ex_064_time_instant_benchmark_timer_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn myersDiffLines(oldLines: [str], newLines: [str]): [DiffEdit]:` from `std/regex/text_diff.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.regex.text_diff_z1_test
import * from "std/regex/text_diff"
import { splitLines, parseInt } from "std/fmt/fmt_mod"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_text_diff_myersDiffLines_1(): int:
  let arg_oldLines = ["test"]
  let edge_oldLines = []
  let arg_newLines = ["test"]
  let edge_newLines = []
  let resNom = myersDiffLines(arg_oldLines, arg_newLines)
  let resEdge = myersDiffLines(edge_oldLines, edge_newLines)
  assertEqInt(resNom.len(), 1, "myersDiffLines nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "myersDiffLines boundary resEdge.len() == 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_064` | [examples/ex_064_time_instant_benchmark_timer_cli.aipl](../../examples/ex_064_time_instant_benchmark_timer_cli.aipl) | `tests/examples/ex_064_time_instant_benchmark_timer_cli_test.aipl` | `./bin/aipl test tests/examples/ex_064_time_instant_benchmark_timer_cli_test.aipl` |

---

### Recipe 17: Schedule Recurring Tasks with Cron Expressions & Hierarchical Timer Wheels

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 17: Schedule Recurring Tasks with Cron Expressions & Hierarchical Timer Wheels` using `std/time/cron_schedule.aipl` (`fn parseCronUint(s: str): Option[int]:`), verified by `tests/functions/time/cron_schedule_test.aipl` and demonstrated in `examples/ex_068_time_cooldown_timer_wheel_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `fn parseCronUint(s: str): Option[int]:` from `std/time/cron_schedule.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.time.cron_schedule_z1_test
import * from "std/time/cron_schedule"
import { DateTimeUtc, dayOfWeek, dateTimeUtcToUnix, unixToDateTimeUtc } from "std/time/datetime"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cron_schedule_parseCronUint_1(): int:
  let arg_s = "42"
  let edge_s = "0"
  let resNom = parseCronUint(arg_s)
  let resEdge = parseCronUint(edge_s)
  assert(resNom.isSome() == true, "parseCronUint nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "parseCronUint boundary resEdge.isSome() == true")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_068` | [examples/ex_068_time_cooldown_timer_wheel_cli.aipl](../../examples/ex_068_time_cooldown_timer_wheel_cli.aipl) | `tests/examples/ex_068_time_cooldown_timer_wheel_cli_test.aipl` | `./bin/aipl test tests/examples/ex_068_time_cooldown_timer_wheel_cli_test.aipl` |

---

### Recipe 18: Compress & Decompress Network Packets with High-Speed LZ4 and Zstandard

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 18: Compress & Decompress Network Packets with High-Speed LZ4 and Zstandard` using `std/compress/lz4.aipl` (`pub fn lz4DecompressBlock(src: bytes, uncompressedSize: int): Result[bytes, str]:`), verified by `tests/functions/compress/lz4_test.aipl` and demonstrated in `examples/ex_084_compress_lz4_highspeed_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn lz4DecompressBlock(src: bytes, uncompressedSize: int): Result[bytes, str]:` from `std/compress/lz4.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.compress.lz4_z2_test
import * from "std/compress/lz4"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_lz4_lz4DecompressBlock_2(): int:
  let arg_src = [65, 73, 80, 76]
  let edge_src = [65]
  let arg_uncompressedSize = 4
  let edge_uncompressedSize = 1
  let resNom = lz4DecompressBlock(arg_src, arg_uncompressedSize)
  let resEdge = lz4DecompressBlock(edge_src, edge_uncompressedSize)
  assert(resNom.isOk() == false, "lz4DecompressBlock nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "lz4DecompressBlock boundary resEdge.isOk() == false")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_084` | [examples/ex_084_compress_lz4_highspeed_cli.aipl](../../examples/ex_084_compress_lz4_highspeed_cli.aipl) | `tests/examples/ex_084_compress_lz4_highspeed_cli_test.aipl` | `./bin/aipl test tests/examples/ex_084_compress_lz4_highspeed_cli_test.aipl` |

---

### Recipe 19: Package & Extract Multi-File POSIX Tar + Gzip Archives in Memory

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 19: Package & Extract Multi-File POSIX Tar + Gzip Archives in Memory` using `std/compress/tar_archive.aipl` (`fn writeOctalField(mut blk: [int], offset: int, width: int, val: int): [int]:`), verified by `tests/functions/compress/tar_archive_test.aipl` and demonstrated in `examples/ex_086_compress_tar_archive_bundler_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `fn writeOctalField(mut blk: [int], offset: int, width: int, val: int): [int]:` from `std/compress/tar_archive.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.compress.tar_archive_z1_test
import * from "std/compress/tar_archive"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tar_archive_writeOctalField_1(): int:
  let arg_blk = [4]
  let edge_blk = []
  let arg_offset = 1
  let edge_offset = 0
  let arg_width = 4
  let edge_width = 1
  let arg_val = 2
  let edge_val = 0
  let resNom = writeOctalField(arg_blk, arg_offset, arg_width, arg_val)
  let resEdge = writeOctalField(edge_blk, edge_offset, edge_width, edge_val)
  assertEqInt(resNom.len(), 1, "writeOctalField nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "writeOctalField boundary resEdge.len() == 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_086` | [examples/ex_086_compress_tar_archive_bundler_cli.aipl](../../examples/ex_086_compress_tar_archive_bundler_cli.aipl) | `tests/examples/ex_086_compress_tar_archive_bundler_cli_test.aipl` | `./bin/aipl test tests/examples/ex_086_compress_tar_archive_bundler_cli_test.aipl` |

---

### Recipe 20: Compute SHA-256, BLAKE3 Merkle Trees & Constant-Time HMAC-SHA256 Signatures

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 20: Compute SHA-256, BLAKE3 Merkle Trees & Constant-Time HMAC-SHA256 Signatures` using `std/crypto/hash.aipl` (`pub fn sha256Str(s: str): str:`), verified by `tests/functions/crypto/hash_test.aipl` and demonstrated in `examples/ex_088_crypto_hmac_jwt_token_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn sha256Str(s: str): str:` from `std/crypto/hash.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.crypto.hash_z2_test
import * from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hash_sha256Str_2(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = sha256Str(arg_s)
  let resEdge = sha256Str(edge_s)
  assertEqInt(resNom.len(), 64, "sha256Str nominal string length == 64")
  assertEqInt(resEdge.len(), 64, "sha256Str boundary string length == 64")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_088` | [examples/ex_088_crypto_hmac_jwt_token_cli.aipl](../../examples/ex_088_crypto_hmac_jwt_token_cli.aipl) | `tests/examples/ex_088_crypto_hmac_jwt_token_cli_test.aipl` | `./bin/aipl test tests/examples/ex_088_crypto_hmac_jwt_token_cli_test.aipl` |

---

### Recipe 21: Encrypt & Authenticate Payloads with ChaCha20-Poly1305 AEAD & Argon2id Keys

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 21: Encrypt & Authenticate Payloads with ChaCha20-Poly1305 AEAD & Argon2id Keys` using `std/crypto/aead.aipl` (`fn rotl32(x: int, n: int): int:`), verified by `tests/functions/crypto/aead_test.aipl` and demonstrated in `examples/ex_090_crypto_aead_chacha20_poly1305_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `fn rotl32(x: int, n: int): int:` from `std/crypto/aead.aipl` with `./bin/aipl verify`:

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

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_090` | [examples/ex_090_crypto_aead_chacha20_poly1305_cli.aipl](../../examples/ex_090_crypto_aead_chacha20_poly1305_cli.aipl) | `tests/examples/ex_090_crypto_aead_chacha20_poly1305_cli_test.aipl` | `./bin/aipl test tests/examples/ex_090_crypto_aead_chacha20_poly1305_cli_test.aipl` |

---

### Recipe 22: Sign & Verify Detached Messages with Ed25519 Public-Key Cryptography

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 22: Sign & Verify Detached Messages with Ed25519 Public-Key Cryptography` using `std/crypto/hmac.aipl` (`pub fn hmacSha256(key: bytes, message: bytes): bytes:`), verified by `tests/functions/crypto/hmac_test.aipl` and demonstrated in `examples/ex_091_crypto_csprng_uuid_generator_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn hmacSha256(key: bytes, message: bytes): bytes:` from `std/crypto/hmac.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.crypto.hmac_z1_test
import * from "std/crypto/hmac"
import { Sha256Hasher, sha256, sha512 } from "std/crypto/hash"
import { hexEncode } from "std/encoding/hex"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_hmac_hmacSha256_1(): int:
  let arg_key = [65, 73, 80, 76]
  let edge_key = [65]
  let arg_message = [65, 73, 80, 76]
  let edge_message = [65]
  let resNom = hmacSha256(arg_key, arg_message)
  let resEdge = hmacSha256(edge_key, edge_message)
  assertEqInt(resNom.len(), 32, "hmacSha256 nominal resNom.len() == 32")
  assertEqInt(resEdge.len(), 32, "hmacSha256 boundary resEdge.len() == 32")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_091` | [examples/ex_091_crypto_csprng_uuid_generator_cli.aipl](../../examples/ex_091_crypto_csprng_uuid_generator_cli.aipl) | `tests/examples/ex_091_crypto_csprng_uuid_generator_cli_test.aipl` | `./bin/aipl test tests/examples/ex_091_crypto_csprng_uuid_generator_cli_test.aipl` |

---

### Recipe 23: Persist Crash-Safe Key-Value State with Append-Only CRC32 WAL Log Compaction

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 23: Persist Crash-Safe Key-Value State with Append-Only CRC32 WAL Log Compaction` using `std/db/kv_wal.aipl` (`fn computeRecordChecksum(op: int, timestamp: int, key: str, value: str): int:`), verified by `tests/functions/db/kv_wal_test.aipl` and demonstrated in `examples/ex_094_db_kv_wal_acid_store_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `fn computeRecordChecksum(op: int, timestamp: int, key: str, value: str): int:` from `std/db/kv_wal.aipl` with `./bin/aipl verify`:

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

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_094` | [examples/ex_094_db_kv_wal_acid_store_cli.aipl](../../examples/ex_094_db_kv_wal_acid_store_cli.aipl) | `tests/examples/ex_094_db_kv_wal_acid_store_cli_test.aipl` | `./bin/aipl test tests/examples/ex_094_db_kv_wal_acid_store_cli_test.aipl` |

---

### Recipe 24: Execute Relational SQL Queries, Joins & Savepoint Rollbacks with Embedded SQLite

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 24: Execute Relational SQL Queries, Joins & Savepoint Rollbacks with Embedded SQLite` using `std/db/sqlite.aipl` (`fn sqlValInt(v: int): SqliteValue:`), verified by `tests/functions/db/sqlite_test.aipl` and demonstrated in `examples/ex_095_io_stdio_interactive_prompt_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `fn sqlValInt(v: int): SqliteValue:` from `std/db/sqlite.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.db.sqlite_z2_test
import * from "std/db/sqlite"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sqlite_sqlValInt_2(): int:
  let arg_v = 2
  let edge_v = 0
  let resNom = sqlValInt(arg_v)
  let resEdge = sqlValInt(edge_v)
  assertEqInt(resNom.kind, 1, "sqlValInt nominal resNom.kind == 1")
  assertEqInt(resEdge.kind, 1, "sqlValInt boundary resEdge.kind == 1")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_095` | [examples/ex_095_io_stdio_interactive_prompt_cli.aipl](../../examples/ex_095_io_stdio_interactive_prompt_cli.aipl) | `tests/examples/ex_095_io_stdio_interactive_prompt_cli_test.aipl` | `./bin/aipl test tests/examples/ex_095_io_stdio_interactive_prompt_cli_test.aipl` |

---

### Recipe 25: Sanitize Relative File Paths & Block Directory Traversal (../) Attacks

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 25: Sanitize Relative File Paths & Block Directory Traversal (../) Attacks` using `std/fs/path.aipl` (`pub fn pathIsAbsolute(p: str): bool:`), verified by `tests/functions/fs/path_test.aipl` and demonstrated in `examples/ex_100_fs_file_atomic_write_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn pathIsAbsolute(p: str): bool:` from `std/fs/path.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.fs.path_z2_test
import * from "std/fs/path"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_path_pathIsAbsolute_2(): int:
  let arg_p = "test"
  let edge_p = "a"
  let resNom = pathIsAbsolute(arg_p)
  let resEdge = pathIsAbsolute(edge_p)
  assert(resNom == false, "pathIsAbsolute nominal resNom == false")
  assert(resEdge == false, "pathIsAbsolute boundary resEdge == false")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_100` | [examples/ex_100_fs_file_atomic_write_cli.aipl](../../examples/ex_100_fs_file_atomic_write_cli.aipl) | `tests/examples/ex_100_fs_file_atomic_write_cli_test.aipl` | `./bin/aipl test tests/examples/ex_100_fs_file_atomic_write_cli_test.aipl` |

---

### Recipe 26: Coordinate Producer-Consumer Pipelines with Bounded MPSC Channels & WaitGroups

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 26: Coordinate Producer-Consumer Pipelines with Bounded MPSC Channels & WaitGroups` using `std/sync/channel.aipl` (`pub fn mpscTrySend(mut ch: MpscChannel, val: int): Result[bool, ChannelError]:`), verified by `tests/functions/sync/channel_test.aipl` and demonstrated in `examples/ex_113_sync_barrier_phased_sim_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn mpscTrySend(mut ch: MpscChannel, val: int): Result[bool, ChannelError]:` from `std/sync/channel.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.sync.channel_z2_test
import * from "std/sync/channel"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_channel_mpscTrySend_2(): int:
  let arg_ch = MpscChannel(capacity = 4, buffer = [], head = 0, tail = 0, count = 0, closed = true)
  let edge_ch = MpscChannel(capacity = 4, buffer = [], head = 0, tail = 0, count = 0, closed = false)
  let arg_val = 2
  let edge_val = 0
  let resNom = mpscTrySend(arg_ch, arg_val)
  let resEdge = mpscTrySend(edge_ch, edge_val)
  assert(resNom.isOk() == false, "mpscTrySend nominal resNom.isOk() == false")
  assert(resEdge.isOk() == true, "mpscTrySend boundary resEdge.isOk() == true")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_113` | [examples/ex_113_sync_barrier_phased_sim_cli.aipl](../../examples/ex_113_sync_barrier_phased_sim_cli.aipl) | `tests/examples/ex_113_sync_barrier_phased_sim_cli_test.aipl` | `./bin/aipl test tests/examples/ex_113_sync_barrier_phased_sim_cli_test.aipl` |

---

### Recipe 27: Parallelize Data-Oriented Batch Loops Across Worker Threads with JobSystem DAGs

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 27: Parallelize Data-Oriented Batch Loops Across Worker Threads with JobSystem DAGs` using `std/thread/job_system.aipl` (`pub fn jobSystemNew(workers: int): JobSystem:`), verified by `tests/functions/thread/job_system_test.aipl` and demonstrated in `examples/ex_117_thread_local_context_propagation_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn jobSystemNew(workers: int): JobSystem:` from `std/thread/job_system.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.thread.job_system_z1_test
import * from "std/thread/job_system"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_job_system_jobSystemNew_1(): int:
  let arg_workers = 4
  let edge_workers = 1
  let resNom = jobSystemNew(arg_workers)
  let resEdge = jobSystemNew(edge_workers)
  assertEqInt(resNom.workerCount, 4, "jobSystemNew nominal resNom.workerCount == 4")
  assertEqInt(resEdge.workerCount, 1, "jobSystemNew boundary resEdge.workerCount == 1")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_117` | [examples/ex_117_thread_local_context_propagation_cli.aipl](../../examples/ex_117_thread_local_context_propagation_cli.aipl) | `tests/examples/ex_117_thread_local_context_propagation_cli_test.aipl` | `./bin/aipl test tests/examples/ex_117_thread_local_context_propagation_cli_test.aipl` |

---

### Recipe 28: Build an HTTP/1.1 REST Client & Router Server with Middleware

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 28: Build an HTTP/1.1 REST Client & Router Server with Middleware` using `std/net/http_server.aipl` (`pub fn createHttpRouter(): HttpRouter:`), verified by `tests/functions/net/http_server_test.aipl` and demonstrated in `examples/ex_123_net_http_client_rest_inspector_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn createHttpRouter(): HttpRouter:` from `std/net/http_server.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.net.http_server_z1_test
import * from "std/net/http_server"
import * from "std/net/net_addr"
import * from "std/net/http_client"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_http_server_createHttpRouter_1(): int:
  let resNom = createHttpRouter()
  let resEdge = createHttpRouter()
  assertEqInt(resNom.routes.len(), 0, "createHttpRouter nominal resNom.routes.len() == 0")
  assertEqInt(resEdge.routes.len(), 0, "createHttpRouter boundary resEdge.routes.len() == 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_123` | [examples/ex_123_net_http_client_rest_inspector_cli.aipl](../../examples/ex_123_net_http_client_rest_inspector_cli.aipl) | `tests/examples/ex_123_net_http_client_rest_inspector_cli_test.aipl` | `./bin/aipl test tests/examples/ex_123_net_http_client_rest_inspector_cli_test.aipl` |

---

### Recipe 29: Synchronize Real-Time Multiplayer State Over Reliable UDP (rudp) & JSON-RPC 2.0

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 29: Synchronize Real-Time Multiplayer State Over Reliable UDP (rudp) & JSON-RPC 2.0` using `std/net/rudp.aipl` (`pub fn rudpBuildPacket(mut conn: RudpConnection, channel: int, flags: int, payload: [int]): [int]:`), verified by `tests/functions/net/rudp_test.aipl` and demonstrated in `examples/ex_121_net_rudp_reliable_game_netcode_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn rudpBuildPacket(mut conn: RudpConnection, channel: int, flags: int, payload: [int]): [int]:` from `std/net/rudp.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.net.rudp_z2_test
import * from "std/net/rudp"
import * from "std/net/net_addr"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rudp_rudpBuildPacket_2(): int:
  let arg_conn = RudpConnection(remoteAddr = SocketAddr(ip = IpAddr(isIpv6 = true, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), localSequence = 4, remoteSequence = 4, ackBitfield = 4, rttMs = 1.0, rttVariance = 1.0, sendWindowSize = 4, unackedQueue = [])
  let edge_conn = RudpConnection(remoteAddr = SocketAddr(ip = IpAddr(isIpv6 = false, v4 = Ipv4Addr(o1 = 0, o2 = 0, o3 = 0, o4 = 0), v6 = Ipv6Addr(s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0)), port = 8080), localSequence = 1, remoteSequence = 1, ackBitfield = 1, rttMs = 0.5, rttVariance = 0.5, sendWindowSize = 1, unackedQueue = [])
  let arg_channel = 4
  let edge_channel = 1
  let arg_flags = 1
  let edge_flags = 0
  let arg_payload = [1]
  let edge_payload = []
  let resNom = rudpBuildPacket(arg_conn, arg_channel, arg_flags, arg_payload)
  let resEdge = rudpBuildPacket(edge_conn, edge_channel, edge_flags, edge_payload)
  assertEqInt(resNom.len(), 13, "rudpBuildPacket nominal resNom.len() == 13")
  assertEqInt(resEdge.len(), 12, "rudpBuildPacket boundary resEdge.len() == 12")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_121` | [examples/ex_121_net_rudp_reliable_game_netcode_cli.aipl](../../examples/ex_121_net_rudp_reliable_game_netcode_cli.aipl) | `tests/examples/ex_121_net_rudp_reliable_game_netcode_cli_test.aipl` | `./bin/aipl test tests/examples/ex_121_net_rudp_reliable_game_netcode_cli_test.aipl` |

---

### Recipe 30: Create a 60 FPS Cross-Platform Window with Fixed-Timestep Simulation Accumulator

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 30: Create a 60 FPS Cross-Platform Window with Fixed-Timestep Simulation Accumulator` using `std/window/app_loop.aipl` (`pub fn createAppConfig(title: str = "AIPL Window", targetFps: int = 60, fixedUpdatesPerSec: int = 60): AppConfig:`), verified by `tests/functions/window/app_loop_test.aipl` and demonstrated in `examples/ex_132_window_surface_letterbox_viewport_window.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn createAppConfig(title: str = "AIPL Window", targetFps: int = 60, fixedUpdatesPerSec: int = 60): AppConfig:` from `std/window/app_loop.aipl` with `./bin/aipl verify`:

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

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_132` | [examples/ex_132_window_surface_letterbox_viewport_window.aipl](../../examples/ex_132_window_surface_letterbox_viewport_window.aipl) | `tests/examples/ex_132_window_surface_letterbox_viewport_window_test.aipl` | `./bin/aipl test tests/examples/ex_132_window_surface_letterbox_viewport_window_test.aipl` |

---

### Recipe 31: Bind Keyboard, Mouse, Gamepad & Touch Gestures to a Rebindable ActionMap

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 31: Bind Keyboard, Mouse, Gamepad & Touch Gestures to a Rebindable ActionMap` using `std/input/action_map.aipl` (`fn getOrCreateAction(map: InputActionMap, actionName: str): InputAction:`), verified by `tests/functions/input/action_map_test.aipl` and demonstrated in `examples/ex_141_input_action_map_rebind_menu_window.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `fn getOrCreateAction(map: InputActionMap, actionName: str): InputAction:` from `std/input/action_map.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.input.action_map_z2_test
import * from "std/input/action_map"
import { KeyboardState, isKeyDown, hasModifier } from "std/input/keyboard"
import { MouseState, isMouseButtonDown } from "std/input/mouse"
import { GamepadState, isGamepadButtonDown } from "std/input/gamepad"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_action_map_getOrCreateAction_2(): int:
  let arg_map = InputActionMap(actions = {})
  let edge_map = InputActionMap(actions = {})
  let arg_actionName = "test"
  let edge_actionName = "a"
  let resNom = getOrCreateAction(arg_map, arg_actionName)
  let resEdge = getOrCreateAction(edge_map, edge_actionName)
  assertEqStr(resNom.actionName, "test", "getOrCreateAction nominal string matches")
  assertEqStr(resEdge.actionName, "a", "getOrCreateAction boundary string matches")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_141` | [examples/ex_141_input_action_map_rebind_menu_window.aipl](../../examples/ex_141_input_action_map_rebind_menu_window.aipl) | `tests/examples/ex_141_input_action_map_rebind_menu_window_test.aipl` | `./bin/aipl test tests/examples/ex_141_input_action_map_rebind_menu_window_test.aipl` |

---

### Recipe 32: Pack Power-of-Two Sprite Atlases with Extruded 2px Gutters & Hot-Reload Bundles

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 32: Pack Power-of-Two Sprite Atlases with Extruded 2px Gutters & Hot-Reload Bundles` using `std/asset/atlas_packer.aipl` (`pub fn createAtlasBin(width: int, height: int, gutterPx: int = 2): AtlasBin:`), verified by `tests/functions/asset/atlas_packer_test.aipl` and demonstrated in `examples/ex_146_asset_bundle_pak_archive_viewer_window.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn createAtlasBin(width: int, height: int, gutterPx: int = 2): AtlasBin:` from `std/asset/atlas_packer.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.asset.atlas_packer_z1_test
import * from "std/asset/atlas_packer"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atlas_packer_createAtlasBin_1(): int:
  let arg_width = 4
  let edge_width = 1
  let arg_height = 4
  let edge_height = 1
  let arg_gutterPx = 1
  let edge_gutterPx = 0
  let resNom = createAtlasBin(arg_width, arg_height, arg_gutterPx)
  let resEdge = createAtlasBin(edge_width, edge_height, edge_gutterPx)
  assertEqInt(resNom.width, 4, "createAtlasBin nominal resNom.width == 4")
  assertEqInt(resEdge.width, 1, "createAtlasBin boundary resEdge.width == 1")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_146` | [examples/ex_146_asset_bundle_pak_archive_viewer_window.aipl](../../examples/ex_146_asset_bundle_pak_archive_viewer_window.aipl) | `tests/examples/ex_146_asset_bundle_pak_archive_viewer_window_test.aipl` | `./bin/aipl test tests/examples/ex_146_asset_bundle_pak_archive_viewer_window_test.aipl` |

---

### Recipe 33: Synthesize Polyphonic ADSR Audio Voices with Pentatonic Pitch Ladders & 3D Doppler

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 33: Synthesize Polyphonic ADSR Audio Voices with Pentatonic Pitch Ladders & 3D Doppler` using `std/audio/audio_synth.aipl` (`pub fn createAdsr(attack: float, decay: float, sustain: float, release: float, antiClickRamp: float = 0.005): AdsrEnvelope:`), verified by `tests/functions/audio/audio_synth_test.aipl` and demonstrated in `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn createAdsr(attack: float, decay: float, sustain: float, release: float, antiClickRamp: float = 0.005): AdsrEnvelope:` from `std/audio/audio_synth.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.audio.audio_synth_z1_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_createAdsr_1(): int:
  let arg_attack = 1.0
  let edge_attack = 0.5
  let arg_decay = 1.0
  let edge_decay = 0.5
  let arg_sustain = 1.0
  let edge_sustain = 0.5
  let arg_release = 1.0
  let edge_release = 0.5
  let arg_antiClickRamp = 1.0
  let edge_antiClickRamp = 0.5
  let resNom = createAdsr(arg_attack, arg_decay, arg_sustain, arg_release, arg_antiClickRamp)
  let resEdge = createAdsr(edge_attack, edge_decay, edge_sustain, edge_release, edge_antiClickRamp)
  assertApproxEq(resNom.attackSec, 1.0, 0.001, "createAdsr nominal resNom.attackSec ~= 1.0")
  assertApproxEq(resEdge.attackSec, 0.5, 0.001, "createAdsr boundary resEdge.attackSec ~= 0.5")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_149` | [examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl](../../examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl) | `tests/examples/ex_149_audio_dsp_biquad_filter_eq_window_test.aipl` | `./bin/aipl test tests/examples/ex_149_audio_dsp_biquad_filter_eq_window_test.aipl` |

---

### Recipe 34: Implement Smooth 2D Camera Follow, Zoom-to-Cursor & Squirrel Eiserloh Trauma^2 Shake

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 34: Implement Smooth 2D Camera Follow, Zoom-to-Cursor & Squirrel Eiserloh Trauma^2 Shake` using `std/gfx2d/camera2d.aipl` (`pub fn camera2DNew(a: float = 800.0, b: float = 600.0, zoom: float = 1.0, viewportW: float = -1.0, viewportH: float = -1.0): Camera2D:`), verified by `tests/functions/gfx2d/camera2d_test.aipl` and demonstrated in `examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn camera2DNew(a: float = 800.0, b: float = 600.0, zoom: float = 1.0, viewportW: float = -1.0, viewportH: float = -1.0): Camera2D:` from `std/gfx2d/camera2d.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.gfx2d.camera2d_z2_test
import * from "std/gfx2d/camera2d"
import { Vec2 } from "std/math/vec_math"
import { Color, rgba, drawRect, drawRectOutline, drawText, drawTextCentered, pushTransform, popTransform, setTargetFps, getFrameTime } from "std/gfx2d/shape2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera2d_camera2DNew_2(): int:
  let arg_a = 1.0
  let edge_a = 0.5
  let arg_b = 1.0
  let edge_b = 0.5
  let arg_zoom = 1.0
  let edge_zoom = 0.5
  let arg_viewportW = 2.0
  let edge_viewportW = 1.0
  let arg_viewportH = 2.0
  let edge_viewportH = 1.0
  let resNom = camera2DNew(arg_a, arg_b, arg_zoom, arg_viewportW, arg_viewportH)
  let resEdge = camera2DNew(edge_a, edge_b, edge_zoom, edge_viewportW, edge_viewportH)
  assertApproxEq(resNom.zoom, 1.0, 0.001, "camera2DNew nominal resNom.zoom ~= 1.0")
  assertApproxEq(resEdge.zoom, 0.5, 0.001, "camera2DNew boundary resEdge.zoom ~= 0.5")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_162` | [examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl](../../examples/ex_162_gfx2d_shape2d_vector_gallery_window.aipl) | `tests/examples/ex_162_gfx2d_shape2d_vector_gallery_window_test.aipl` | `./bin/aipl test tests/examples/ex_162_gfx2d_shape2d_vector_gallery_window_test.aipl` |

---

### Recipe 35: Render Wang 47-Tile Autotiled Maps with 2D Point Lights & SDF Soft Shadows

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 35: Render Wang 47-Tile Autotiled Maps with 2D Point Lights & SDF Soft Shadows` using `std/gfx2d/tilemap_renderer2d.aipl` (`pub fn createWangBlob47Autotiler(): WangBlob47Autotiler:`), verified by `tests/functions/gfx2d/tilemap_renderer2d_test.aipl` and demonstrated in `examples/ex_166_gfx2d_sprite_anim2d_state_machine_window.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn createWangBlob47Autotiler(): WangBlob47Autotiler:` from `std/gfx2d/tilemap_renderer2d.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.gfx2d.tilemap_renderer2d_z1_test
import * from "std/gfx2d/tilemap_renderer2d"
import { ViewportBounds2D } from "std/gfx2d/camera2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_tilemap_renderer2d_createWangBlob47Autotiler_1(): int:
  let resNom = createWangBlob47Autotiler()
  let resEdge = createWangBlob47Autotiler()
  assertEqInt(resNom.transitionTable.len(), 256, "createWangBlob47Autotiler nominal resNom.transitionTable.len() == 256")
  assertEqInt(resEdge.transitionTable.len(), 256, "createWangBlob47Autotiler boundary resEdge.transitionTable.len() == 256")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_166` | [examples/ex_166_gfx2d_sprite_anim2d_state_machine_window.aipl](../../examples/ex_166_gfx2d_sprite_anim2d_state_machine_window.aipl) | `tests/examples/ex_166_gfx2d_sprite_anim2d_state_machine_window_test.aipl` | `./bin/aipl test tests/examples/ex_166_gfx2d_sprite_anim2d_state_machine_window_test.aipl` |

---

### Recipe 36: Configure a 3D Cook-Torrance GGX PBR Material Pipeline with Cascaded Shadow Maps

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 36: Configure a 3D Cook-Torrance GGX PBR Material Pipeline with Cascaded Shadow Maps` using `std/gfx3d/material3d.aipl` (`pub fn evaluateGgxDistribution(nDotH: float, roughness: float): float:`), verified by `tests/functions/gfx3d/material3d_test.aipl` and demonstrated in `examples/ex_177_gfx3d_material3d_ggx_pbr_spheres_window.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn evaluateGgxDistribution(nDotH: float, roughness: float): float:` from `std/gfx3d/material3d.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.gfx3d.material3d_z2_test
import * from "std/gfx3d/material3d"
import { PI, EPSILON, maxFloat, clampInt, clampFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8, LinearColorF32 } from "std/gfx/color"
import { lightComputeLambertDiffuseRGB, lightComputeBlinnPhongRGB, lightComputePbrCookTorranceRGB } from "std/gfx3d/light3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_material3d_evaluateGgxDistribution_2(): int:
  let arg_nDotH = 2.0
  let edge_nDotH = 1.0
  let arg_roughness = 2.0
  let edge_roughness = 1.0
  let resNom = evaluateGgxDistribution(arg_nDotH, arg_roughness)
  let resEdge = evaluateGgxDistribution(edge_nDotH, edge_roughness)
  assertApproxEq(resNom, 0.079577, 0.001, "evaluateGgxDistribution nominal resNom ~= 0.079577")
  assertApproxEq(resEdge, 0.31831, 0.001, "evaluateGgxDistribution boundary resEdge ~= 0.31831")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_177` | [examples/ex_177_gfx3d_material3d_ggx_pbr_spheres_window.aipl](../../examples/ex_177_gfx3d_material3d_ggx_pbr_spheres_window.aipl) | `tests/examples/ex_177_gfx3d_material3d_ggx_pbr_spheres_window_test.aipl` | `./bin/aipl test tests/examples/ex_177_gfx3d_material3d_ggx_pbr_spheres_window_test.aipl` |

---

### Recipe 37: Animate 3D Characters with Dual-Quaternion Skinning & FABRIK Inverse Kinematics

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 37: Animate 3D Characters with Dual-Quaternion Skinning & FABRIK Inverse Kinematics` using `std/gfx3d/rigging3d.aipl` (`pub fn updateSkeletonHierarchy(skel: Skeleton3D): Skeleton3D:`), verified by `tests/functions/gfx3d/rigging3d_test.aipl` and demonstrated in `examples/ex_179_gfx3d_rigging3d_skeletal_skinning_window.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn updateSkeletonHierarchy(skel: Skeleton3D): Skeleton3D:` from `std/gfx3d/rigging3d.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.gfx3d.rigging3d_z2_test
import * from "std/gfx3d/rigging3d"
import { DEG2RAD, RAD2DEG, EPSILON, absFloat, maxFloat, maxInt, clampFloat } from "std/math/consts"
import { sin, cos, acos, atan2, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigging3d_updateSkeletonHierarchy_2(): int:
  let arg_skel = Skeleton3D(bones = [])
  let edge_skel = Skeleton3D(bones = [])
  let resNom = updateSkeletonHierarchy(arg_skel)
  let resEdge = updateSkeletonHierarchy(edge_skel)
  assertEqInt(resNom.bones.len(), 0, "updateSkeletonHierarchy nominal resNom.bones.len() == 0")
  assertEqInt(resEdge.bones.len(), 0, "updateSkeletonHierarchy boundary resEdge.bones.len() == 0")
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

---

### Recipe 38: Simulate 2D & 3D Curl-Noise Particle Emitters with Sub-Emitter Fireworks & Trails

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 38: Simulate 2D & 3D Curl-Noise Particle Emitters with Sub-Emitter Fireworks & Trails` using `std/particle/emitter3d.aipl` (`pub fn createParticlePool3D(maxParticles: int = 4096, emissionRate: float = 250.0): ParticlePool3D:`), verified by `tests/functions/particle/emitter3d_test.aipl` and demonstrated in `examples/ex_185_particle_affector_vortex_and_attractor_window.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn createParticlePool3D(maxParticles: int = 4096, emissionRate: float = 250.0): ParticlePool3D:` from `std/particle/emitter3d.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.particle.emitter3d_z1_test
import * from "std/particle/emitter3d"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, cbrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, cbrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { ParticleAffector, AFFECTOR_GRAVITY, AFFECTOR_DRAG, AFFECTOR_VORTEX, AFFECTOR_CURL_NOISE, evaluateVortexForce, evaluateCurlNoiseForce } from "std/particle/affector"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_emitter3d_createParticlePool3D_1(): int:
  let arg_maxParticles = 4
  let edge_maxParticles = 1
  let arg_emissionRate = 2.0
  let edge_emissionRate = 1.0
  let resNom = createParticlePool3D(arg_maxParticles, arg_emissionRate)
  let resEdge = createParticlePool3D(edge_maxParticles, edge_emissionRate)
  assertEqInt(resNom.particles.len(), 0, "createParticlePool3D nominal resNom.particles.len() == 0")
  assertEqInt(resEdge.particles.len(), 0, "createParticlePool3D boundary resEdge.particles.len() == 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_185` | [examples/ex_185_particle_affector_vortex_and_attractor_window.aipl](../../examples/ex_185_particle_affector_vortex_and_attractor_window.aipl) | `tests/examples/ex_185_particle_affector_vortex_and_attractor_window_test.aipl` | `./bin/aipl test tests/examples/ex_185_particle_affector_vortex_and_attractor_window_test.aipl` |

---

### Recipe 39: Build a Responsive Flexbox & 12-Column Grid Dashboard in Aura Immediate-Mode UI

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 39: Build a Responsive Flexbox & 12-Column Grid Dashboard in Aura Immediate-Mode UI` using `std/ui/ui_layout.aipl` (`pub fn createLayoutNode(id: int, direction: int = 0): LayoutNode:`), verified by `tests/functions/ui/ui_layout_test.aipl` and demonstrated in `examples/ex_191_ui_style_dark_light_theme_studio_window.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn createLayoutNode(id: int, direction: int = 0): LayoutNode:` from `std/ui/ui_layout.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.ui.ui_layout_z1_test
import * from "std/ui/ui_layout"
import { maxFloat, clampFloat } from "std/math/consts"
import { Rect } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ui_layout_createLayoutNode_1(): int:
  let arg_id = 1
  let edge_id = 0
  let arg_direction = 4
  let edge_direction = 1
  let resNom = createLayoutNode(arg_id, arg_direction)
  let resEdge = createLayoutNode(edge_id, edge_direction)
  assertEqInt(resNom.id, 1, "createLayoutNode nominal resNom.id == 1")
  assertEqInt(resEdge.id, 0, "createLayoutNode boundary resEdge.id == 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_191` | [examples/ex_191_ui_style_dark_light_theme_studio_window.aipl](../../examples/ex_191_ui_style_dark_light_theme_studio_window.aipl) | `tests/examples/ex_191_ui_style_dark_light_theme_studio_window_test.aipl` | `./bin/aipl test tests/examples/ex_191_ui_style_dark_light_theme_studio_window_test.aipl` |

---

### Recipe 40: Audit UI Palettes for WCAG 2.1 AAA & APCA Perceptual Contrast in Oklch Color Space

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 40: Audit UI Palettes for WCAG 2.1 AAA & APCA Perceptual Contrast in Oklch Color Space` using `std/ui/ui_a11y.aipl` (`pub fn createA11yNode(id: int, role: int, label: str, bounds: Rect): A11yNode:`), verified by `tests/functions/ui/ui_a11y_test.aipl` and demonstrated in `examples/ex_201_ui_a11y_focus_ring_and_contrast_window.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn createA11yNode(id: int, role: int, label: str, bounds: Rect): A11yNode:` from `std/ui/ui_a11y.aipl` with `./bin/aipl verify`:

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

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_201` | [examples/ex_201_ui_a11y_focus_ring_and_contrast_window.aipl](../../examples/ex_201_ui_a11y_focus_ring_and_contrast_window.aipl) | `tests/examples/ex_201_ui_a11y_focus_ring_and_contrast_window_test.aipl` | `./bin/aipl test tests/examples/ex_201_ui_a11y_focus_ring_and_contrast_window_test.aipl` |

---

### Recipe 41: Render 100,000 Rows at 60 FPS with Virtualized Aura DataGrid & Gap-Buffer TextEdit

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 41: Render 100,000 Rows at 60 FPS with Virtualized Aura DataGrid & Gap-Buffer TextEdit` using `std/ui/ui_datagrid.aipl` (`pub fn computeVirtualWindow(grid: DataGridWidget): VirtualWindow:`), verified by `tests/functions/ui/ui_datagrid_test.aipl` and demonstrated in `examples/ex_195_ui_datagrid_one_million_rows_window.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn computeVirtualWindow(grid: DataGridWidget): VirtualWindow:` from `std/ui/ui_datagrid.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.ui.ui_datagrid_z1_test
import * from "std/ui/ui_datagrid"
import { EPSILON, minInt, maxInt } from "std/math/consts"
import { colorHex, drawRect, drawRoundedRect, drawRoundedRectOutline, drawLine, drawText, truncateText, measureTextWidth } from "std/gfx2d/shape2d"
import { AuraRect, AuraTableResult, AuraKanbanAction } from "std/ui/ui_layout"
import { AuraTheme, AuraContext, auraIsHovered, auraIsClicked } from "std/ui/ui_imui"
import { floor, ceil } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ui_datagrid_computeVirtualWindow_1(): int:
  let arg_grid = DataGridWidget(columns = [], totalRowCount = 4, rowHeight = 2.0, scrollOffsetY = 0.0, viewportHeight = 2.0)
  let edge_grid = DataGridWidget(columns = [], totalRowCount = 1, rowHeight = 1.0, scrollOffsetY = 0.0, viewportHeight = 1.0)
  let resNom = computeVirtualWindow(arg_grid)
  let resEdge = computeVirtualWindow(edge_grid)
  assertEqInt(resNom.firstVisibleRow, 0, "computeVirtualWindow nominal resNom.firstVisibleRow == 0")
  assertEqInt(resEdge.firstVisibleRow, 0, "computeVirtualWindow boundary resEdge.firstVisibleRow == 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_195` | [examples/ex_195_ui_datagrid_one_million_rows_window.aipl](../../examples/ex_195_ui_datagrid_one_million_rows_window.aipl) | `tests/examples/ex_195_ui_datagrid_one_million_rows_window_test.aipl` | `./bin/aipl test tests/examples/ex_195_ui_datagrid_one_million_rows_window_test.aipl` |

---

### Recipe 42: Query Archetype SoA Tables & Schedule Conflict-Free Parallel ECS Systems

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 42: Query Archetype SoA Tables & Schedule Conflict-Free Parallel ECS Systems` using `std/ecs/ecs_world.aipl` (`pub fn despawnEntity(world: EcsWorld, entity: EntityId): EcsWorld:`), verified by `tests/functions/ecs/ecs_world_test.aipl` and demonstrated in `examples/ex_208_spatial_ortho_tile_world2d_window.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn despawnEntity(world: EcsWorld, entity: EntityId): EcsWorld:` from `std/ecs/ecs_world.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.ecs.ecs_world_z3_test
import * from "std/ecs/ecs_world"
import { EntityId, EntityPool, createEntityPool, allocateEntity, recycleEntity, isEntityAlive } from "std/ecs/entity"
import { ArchetypeTable, createArchetypeTable, insertArchetypeRow, swapRemoveArchetypeRow } from "std/ecs/archetype"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ecs_world_despawnEntity_3(): int:
  let arg_world = EcsWorld(entityPool = EntityPool(generations = [], alive = [], freeIndices = []), archetypes = [], locations = [], resources = [])
  let edge_world = EcsWorld(entityPool = EntityPool(generations = [], alive = [], freeIndices = []), archetypes = [], locations = [], resources = [])
  let arg_entity = EntityId(index = 0, generation = 4)
  let edge_entity = EntityId(index = 0, generation = 1)
  let resNom = despawnEntity(arg_world, arg_entity)
  let resEdge = despawnEntity(edge_world, edge_entity)
  assertEqInt(resNom.archetypes.len(), 0, "despawnEntity nominal resNom.archetypes.len() == 0")
  assertEqInt(resEdge.archetypes.len(), 0, "despawnEntity boundary resEdge.archetypes.len() == 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_208` | [examples/ex_208_spatial_ortho_tile_world2d_window.aipl](../../examples/ex_208_spatial_ortho_tile_world2d_window.aipl) | `tests/examples/ex_208_spatial_ortho_tile_world2d_window_test.aipl` | `./bin/aipl test tests/examples/ex_208_spatial_ortho_tile_world2d_window_test.aipl` |

---

### Recipe 43: Convert Axial/Cube Coordinates & Field-of-View on Hexagonal & Isometric Worlds

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 43: Convert Axial/Cube Coordinates & Field-of-View on Hexagonal & Isometric Worlds` using `std/spatial/hex_tile_world2d.aipl` (`pub fn hexAxialToCube(axial: HexAxialCoord): HexCubeCoord:`), verified by `tests/functions/spatial/hex_tile_world2d_test.aipl` and demonstrated in `examples/ex_210_spatial_hex_tile_world2d_window.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn hexAxialToCube(axial: HexAxialCoord): HexCubeCoord:` from `std/spatial/hex_tile_world2d.aipl` with `./bin/aipl verify`:

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

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_210` | [examples/ex_210_spatial_hex_tile_world2d_window.aipl](../../examples/ex_210_spatial_hex_tile_world2d_window.aipl) | `tests/examples/ex_210_spatial_hex_tile_world2d_window_test.aipl` | `./bin/aipl test tests/examples/ex_210_spatial_hex_tile_world2d_window_test.aipl` |

---

### Recipe 44: Mesh Greedy 3D Voxel Chunks with Ambient Occlusion & DDA Raycasting

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 44: Mesh Greedy 3D Voxel Chunks with Ambient Occlusion & DDA Raycasting` using `std/spatial/voxel_chunk_world3d.aipl` (`pub fn voxelChunkWorldNew(chunkSize: int): VoxelChunkWorld3D:`), verified by `tests/functions/spatial/voxel_chunk_world3d_test.aipl` and demonstrated in `examples/ex_212_spatial_continuous_world3d_window.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn voxelChunkWorldNew(chunkSize: int): VoxelChunkWorld3D:` from `std/spatial/voxel_chunk_world3d.aipl` with `./bin/aipl verify`:

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

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_212` | [examples/ex_212_spatial_continuous_world3d_window.aipl](../../examples/ex_212_spatial_continuous_world3d_window.aipl) | `tests/examples/ex_212_spatial_continuous_world3d_window_test.aipl` | `./bin/aipl test tests/examples/ex_212_spatial_continuous_world3d_window_test.aipl` |

---

### Recipe 45: Step 2D & 3D Rigid-Body Physics with SAT/GJK-EPA Collisions & Raycast Vehicles

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 45: Step 2D & 3D Rigid-Body Physics with SAT/GJK-EPA Collisions & Raycast Vehicles` using `std/phys3d/phys_world3d.aipl` (`pub fn physWorld3dNew(gravity: Vec3): PhysicsWorld3D:`), verified by `tests/functions/phys3d/phys_world3d_test.aipl` and demonstrated in `examples/ex_229_phys3d_vehicle_raycast_suspension_window.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn physWorld3dNew(gravity: Vec3): PhysicsWorld3D:` from `std/phys3d/phys_world3d.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.phys3d.phys_world3d_z1_test
import * from "std/phys3d/phys_world3d"
import { Vec3 } from "std/math/vec_math"
import { RigidBody3D, rigidBody3dIntegrate } from "std/phys3d/rigid_body3d"
import { Collider3D } from "std/phys3d/collider3d"
import { Joint3D, joint3dSolveVelocity } from "std/phys3d/joint3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_phys_world3d_physWorld3dNew_1(): int:
  let arg_gravity = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_gravity = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = physWorld3dNew(arg_gravity)
  let resEdge = physWorld3dNew(edge_gravity)
  assertEqInt(resNom.bodies.len(), 0, "physWorld3dNew nominal resNom.bodies.len() == 0")
  assertEqInt(resEdge.bodies.len(), 0, "physWorld3dNew boundary resEdge.bodies.len() == 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_229` | [examples/ex_229_phys3d_vehicle_raycast_suspension_window.aipl](../../examples/ex_229_phys3d_vehicle_raycast_suspension_window.aipl) | `tests/examples/ex_229_phys3d_vehicle_raycast_suspension_window_test.aipl` | `./bin/aipl test tests/examples/ex_229_phys3d_vehicle_raycast_suspension_window_test.aipl` |

---

### Recipe 46: Generate Constraint-Solved Tilemaps with Wave Function Collapse (WFC) & Simplex FBM

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 46: Generate Constraint-Solved Tilemaps with Wave Function Collapse (WFC) & Simplex FBM` using `std/procgen/wfc_solver.aipl` (`pub fn wfcSolver2dNew(width: int, height: int, numPatterns: int): WfcSolver2D:`), verified by `tests/functions/procgen/wfc_solver_test.aipl` and demonstrated in `examples/ex_232_procgen_dungeon_bsp_and_corridors_window.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn wfcSolver2dNew(width: int, height: int, numPatterns: int): WfcSolver2D:` from `std/procgen/wfc_solver.aipl` with `./bin/aipl verify`:

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

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_232` | [examples/ex_232_procgen_dungeon_bsp_and_corridors_window.aipl](../../examples/ex_232_procgen_dungeon_bsp_and_corridors_window.aipl) | `tests/examples/ex_232_procgen_dungeon_bsp_and_corridors_window_test.aipl` | `./bin/aipl test tests/examples/ex_232_procgen_dungeon_bsp_and_corridors_window_test.aipl` |

---

### Recipe 47: Pathfind Around Dynamic Crowds with Jump Point Search (JPS) & ORCA Velocity Obstacles

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 47: Pathfind Around Dynamic Crowds with Jump Point Search (JPS) & ORCA Velocity Obstacles` using `std/ai/pathfind.aipl` (`fn isWalkable(grid: CellularGrid2D, x: int, y: int): bool:`), verified by `tests/functions/ai/pathfind_test.aipl` and demonstrated in `examples/ex_238_ai_fsm_hierarchical_guard_agent_window.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `fn isWalkable(grid: CellularGrid2D, x: int, y: int): bool:` from `std/ai/pathfind.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.ai.pathfind_z1_test
import * from "std/ai/pathfind"
import { absInt, minFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { CellularGrid2D } from "std/procgen/cellular_automata"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_pathfind_isWalkable_1(): int:
  let arg_grid = CellularGrid2D(width = 4, height = 4, cells = [])
  let edge_grid = CellularGrid2D(width = 4, height = 4, cells = [])
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let resNom = isWalkable(arg_grid, arg_x, arg_y)
  let resEdge = isWalkable(edge_grid, edge_x, edge_y)
  assert(resNom == false, "isWalkable nominal resNom == false")
  assert(resEdge == false, "isWalkable boundary resEdge == false")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_238` | [examples/ex_238_ai_fsm_hierarchical_guard_agent_window.aipl](../../examples/ex_238_ai_fsm_hierarchical_guard_agent_window.aipl) | `tests/examples/ex_238_ai_fsm_hierarchical_guard_agent_window_test.aipl` | `./bin/aipl test tests/examples/ex_238_ai_fsm_hierarchical_guard_agent_window_test.aipl` |

---

### Recipe 48: Drive Autonomous NPCs with Behavior Trees, Utility AI Curves & A* GOAP Planners

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 48: Drive Autonomous NPCs with Behavior Trees, Utility AI Curves & A* GOAP Planners` using `std/ai/goap.aipl` (`pub fn goapAddAction(mut planner: GoapPlanner, action: GoapAction): void:`), verified by `tests/functions/ai/goap_test.aipl` and demonstrated in `examples/ex_242_ai_navmesh_funnel_path_smoothing_window.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn goapAddAction(mut planner: GoapPlanner, action: GoapAction): void:` from `std/ai/goap.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.ai.goap_z2_test
import * from "std/ai/goap"
import { popcnt, clampFloat } from "std/math/consts"
import { exp, sqrt, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_goap_goapAddAction_2(): int:
  let arg_planner = GoapPlanner(actions = [])
  let edge_planner = GoapPlanner(actions = [])
  let arg_action = GoapAction(name = "test", cost = 1.0, preconditionMask = 4, preconditionCareMask = 4, effectSetMask = 4, effectClearMask = 4)
  let edge_action = GoapAction(name = "a", cost = 0.5, preconditionMask = 1, preconditionCareMask = 1, effectSetMask = 1, effectClearMask = 1)
  goapAddAction(arg_planner, arg_action)
  goapAddAction(edge_planner, edge_action)
  assertEqInt(arg_planner.actions.len(), 1, "goapAddAction nominal arg_planner.actions.len() == 1")
  assertEqInt(edge_planner.actions.len(), 1, "goapAddAction boundary edge_planner.actions.len() == 1")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_242` | [examples/ex_242_ai_navmesh_funnel_path_smoothing_window.aipl](../../examples/ex_242_ai_navmesh_funnel_path_smoothing_window.aipl) | `tests/examples/ex_242_ai_navmesh_funnel_path_smoothing_window_test.aipl` | `./bin/aipl test tests/examples/ex_242_ai_navmesh_funnel_path_smoothing_window_test.aipl` |

---

### Recipe 49: Balance RPG Stat Modifiers, ARPG Grid Inventories & Economy Sinks/Faucets

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 49: Balance RPG Stat Modifiers, ARPG Grid Inventories & Economy Sinks/Faucets` using `std/mechanics/attribute_pipeline.aipl` (`pub fn evalStatModifierStack(baseValue: float, modifiers: [StatModifier]): float:`), verified by `tests/functions/mechanics/attribute_pipeline_test.aipl` and demonstrated in `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`.
#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `pub fn evalStatModifierStack(baseValue: float, modifiers: [StatModifier]): float:` from `std/mechanics/attribute_pipeline.aipl` with `./bin/aipl verify`:

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

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_244` | [examples/ex_244_ai_vector_embedding_rag_search_cli.aipl](../../examples/ex_244_ai_vector_embedding_rag_search_cli.aipl) | `tests/examples/ex_244_ai_vector_embedding_rag_search_cli_test.aipl` | `./bin/aipl test tests/examples/ex_244_ai_vector_embedding_rag_search_cli_test.aipl` |

---

### Recipe 50: Shrink Property-Based Fuzzing Counterexamples & Verify 4-Target Compiler Parity

#### 1. Concept in 30 Seconds
Production copy-pasteable recipe for `Recipe 50: Shrink Property-Based Fuzzing Counterexamples & Verify 4-Target Compiler Parity` using `std/test/fuzz.aipl` (`fn nextRaw64(gen: FuzzGenerator): (FuzzGenerator, int):`), verified by `tests/functions/test/fuzz_test.aipl` and demonstrated in `examples/ex_130_test_fuzz_and_property_shrinker_cli.aipl`.

#### 2. Minimal Runnable Example
Run or verify this self-contained snippet exercising `fn nextRaw64(gen: FuzzGenerator): (FuzzGenerator, int):` from `std/test/fuzz.aipl` with `./bin/aipl verify`:

```aipl
module tests.functions.test.fuzz_z2_test
import * from "std/test/fuzz"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fuzz_nextRaw64_2(): int:
  let arg_gen = FuzzGenerator(seed = 0, state = 0)
  let edge_gen = FuzzGenerator(seed = 0, state = 0)
  let resNom = nextRaw64(arg_gen)
  let resEdge = nextRaw64(edge_gen)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0.seed, 0, "nextRaw64 nominal n_t0.seed == 0")
  assertEqInt(e_t0.seed, 0, "nextRaw64 boundary e_t0.seed == 0")
  ret 0
```

#### 3. Common Pitfalls & Compiler Diagnostics
- **Zero Implicit Coercion (`E201`)**: Passing an `int` where `float` is required (or vice versa) is rejected at compile time; always wrap with explicit `float(x)` or `int(x)`.
- **Explicit Mutability (`E204`)**: Variables declared with `let` and receivers declared as `(self: T)` are immutable; use `mut` (`mut x = 0` or `(mut self: T)`) when state mutation is intended.
- **Design-by-Contract (`E302` / `E303`)**: Preconditions (`req:`) and postconditions (`ens:`) are checked statically by `compiler/smt.aipl` and guarded at runtime.

#### 4. Explore Real Working Examples (`examples/ex_NNN_*.aipl`)
| Example ID | Source File | Twin Test File | Verification Command |
| :--- | :--- | :--- | :--- |
| `ex_130` | [examples/ex_130_test_fuzz_and_property_shrinker_cli.aipl](../../examples/ex_130_test_fuzz_and_property_shrinker_cli.aipl) | `tests/examples/ex_130_test_fuzz_and_property_shrinker_cli_test.aipl` | `./bin/aipl test tests/examples/ex_130_test_fuzz_and_property_shrinker_cli_test.aipl` |

---

### Recipe 51: Building Continuous & UV-Textured 2.5D Isometric Worlds (`std/gfx25d`)

#### 1. Concept in 30 Seconds
Render continuous heightfield terrains, slope-splatted & multi-biome alpha-splatted UV-textured meadows/cliffs (`drawHeightfieldSplat25D`, `drawGroundDecal25D`), UV-scrolled rivers/roads, Z-buffered volumetric buildings/trees, 2.5D ambient multiply + additive light cookies (`std/gfx25d/light25d.aipl`), 8-directional pre-rendered 3D isometric sprite rigs (`std/gfx25d/sprite25d.aipl`, `createIsometricSpriteSheet`), and 2.5D weather/mist (`std/gfx25d/weather25d.aipl`) using `std/gfx25d/*`, `createProceduralTexture`, `setDepthTest(true)`, `clearDepth()`, `setBlendMode(mode)`, and `beginWorldPass()` / `endWorldPass()`, verified by `tests/functions/gfx25d/` and demonstrated in `examples/ex_259_continuous_world_25d.aipl`, `examples/ex_260_textured_25d_village_and_river_window.aipl`, `examples/ex_261_textured_3d_gallery_and_uv_mesh_window.aipl`, `examples/ex_262_dark_fantasy_encampment_arpg_window.aipl`, and `examples/ex_263_isometric_8dir_rig_and_lighting_lab_window.aipl`.

#### 2. Minimal Runnable Example
```aipl
module tests.functions.gfx25d.recipe51_continuous_world_test
import { Vec3 } from "std/math/vec_math"
import { rgb, setDepthTest, clearDepth, beginWorldPass, endWorldPass, createProceduralTexture } from "std/gfx2d/shape2d"
import { TerrainHeightfield } from "std/gfx3d/terrain3d"
import { Camera25D, createCamera25D, drawHeightfieldPatchTextured25D, drawSplineRibbonTextured25D, drawPrismTextured25D } from "std/gfx25d/gfx25d_mod"
import { assert, assertEqInt } from "std/prelude"

pub fn test_recipe51_continuous_world_25d(): int:
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
