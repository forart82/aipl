# AIPL Consolidated Documentation & API Reference (v0.9.0)
**Authoritative Single Source of Truth for Autonomous AI Coding Agents & Compiler Engineers**

This document consolidates the complete language specification, syntactic invariants, standard library API signatures, CLI references, and design patterns for the **AIPL** language. Autonomous subagents and orchestrators should use this document for instant reference across compiler conventions and standard library interfaces.

---

## Authoritative Documentation Index

The following documentation files provide deep architectural and practical guidance across the AIPL repository:

| Document | Path | Purpose & Scope |
|---|---|---|
| **AI Agent Invariants Spec** | [`AI_SPEC.md`](AI_SPEC.md) | Tokenomics-optimized grammar rules, strict camelCase, 2-space indentation, numeric lattice (`byte <: int <: float`), floor division `//`, string interpolation, and CLI verification protocols. |
| **Language Specification** | [`docs/SPEC.md`](docs/SPEC.md) | Formal grammar, lexical tokens, EBNF syntax, type checker semantics, memory allocation models, borrow checker, and compilation targets (C99, LLVM, WASM). |
| **Standard Library Reference** | [`docs/STDLIB_REFERENCE.md`](docs/STDLIB_REFERENCE.md) | Exhaustive API signatures, exported types, and usage examples for all 91 `std/` modules and 9 pure-AIPL runtime modules across 9 canonical domains. |
| **CLI & Tooling Reference** | [`docs/CLI_REFERENCE.md`](docs/CLI_REFERENCE.md) | CLI commands (`run`, `build`, `check`, `fmt`, `test`, `bench`, `docs`, `fix`), flags (`-O2`, `--target`, `--profile`), compiler pipeline stages, and debugging diagnostics. |
| **Design Patterns & Cookbook** | [`docs/COOKBOOK.md`](docs/COOKBOOK.md) | Idiomatic code recipes, game loops, ECS entity component systems, socket servers, 2D/3D math routines, audio synthesis, and performance optimization techniques. |

---

# Part 1: AI Agent & LLM Generation Specification (`AI_SPEC.md`)

# AIPL v0.8.0 AI Agent & LLM Generation Specification
**Authoritative Guidelines, Invariants, and Tooling Protocols for Autonomous AI Coding Agents**

This specification defines the exact syntactic, architectural, and verification invariants that autonomous AI coding agents (LLMs) must adhere to when generating, analyzing, or refactoring **AIPL v0.8.0** code.

---

## 1. Tokenomics Optimization & Syntactic Invariants

AIPL syntax is co-designed with the empirical subword token merge behavior of Google SentencePiece 256k (Gemini/Gemma) and OpenAI BPE (`cl100k_base`, `o200k_base`). Violations cause severe token penalties and compiler rejections.

### 1.1 Strict camelCase Invariant & Automated Self-Healing (ADR-0002)
- **Rule**: All variables, parameters, and function names must be `camelCase`. All structs, enums, and type aliases must be `PascalCase`.
- **Constraint**: Underscores (`_`) are strictly forbidden in identifier names, except for the wildcard pattern `_`.
- **Automated Self-Healing (`AIPL_W1003_SNAKE_CASE_AUTOFIX`)**: `aipl fmt` and `aipl fix` automatically heal snake_case identifiers into canonical camelCase / PascalCase while preserving `@extern` foreign symbols and string interpolation literals.

### 1.2 Strict 2-Space Indentation Offside Rule & Automatic Shortest-Syntax Canonicalization
- **Rule**: Indentation depth must be exactly 2 spaces per nesting level with `:` block headers.
- **Constraint**: Tab characters (`\t`) are forbidden (`AIPL_E1002_FORBIDDEN_TAB`). 4-space indentation is rejected.
- **Automatic Source Canonicalization**: `aipl verify`, `build`, `run`, `test`, `fmt`, and `fix` automatically rewrite polyglot/verbose syntax on disk into the shortest canonical AIPL form (`:` over `{}`, `ret` over `return`, `elif` over `else if`, `): Type` over `) -> Type`, `and`/`or`/`not` over `&&`/`||`/`!`, trailing `;` removal, and single-line `fn(...)` and `struct Name(...)` declarations) while preserving string literals, comments, and `test_*` identifiers.
- **Rationale**: 2 leading spaces are absorbed directly into statement keywords by unigram tokenizers (e.g. `  let` is a single token).

### 1.3 Directional Lossless Numeric Lattice & Explicit Floor Division
- **Lossless Subtyping Lattice**: `byte <: int <: float`. Unsigned 8-bit `byte` (0..255) widens losslessly to 64-bit signed `int`, which widens losslessly to 64-bit IEEE-754 `float`.
- **Compile-Time Truncation Rejection (`[AIPL312]`)**: Silent narrowing (`let i: int = 3.9` or `let i: int = floatVar`) is rejected at compile time.
- **Postfix Conversions**: Use postfix conversions `.i` (truncate to int), `.f` (convert to float), `.round` (round to nearest int), `.floor` (floor to int), and `.ceil` (ceil to int).
- **Floor-Division Operator `//`**: Use `//` for integer floor division (`7 // 2 == 3`, `-7 // 2 == -4`, `7.9 // 2.0 == 3`). Valid in all expression positions including arguments and conditions.
- **Primitives**: Always use standard single-token primitives: `int`, `float`, `bool`, `str`, `byte`, `void`, `nil`. Do NOT hallucinate Rust/C++ sized numeric types (`i32`, `u64`, `f64`) in standard code blocks.

### 1.4 Single-Brace String Interpolation
- Use `"Value: {val}"`. Do NOT prefix with Python's `f"..."` or use JavaScript backticks.
- Format specifiers: `{val:02x}`, `{val:>8}`, `{val:.2f}`.

### 1.5 Hierarchical 9-Domain Standard Library Imports
- Import standard modules via hierarchical dot syntax or path strings across the 9 canonical domains:
  - `std/core`: Foundational structures, SIMD math, bitwise, memory arenas, dynamic arrays, threadpools, timers, crypto (`import std.core.math`).
  - `std/io`: Filesystem, streams, process execution, binary buffers, CLI args, logging (`import std.io.fs`).
  - `std/data`: Documents, serialization, ECS registry, diffs, SQLite3 (`import std.data.json`).
  - `std/net`: POSIX TCP/UDP sockets, DNS resolution, HTTP/1.1 client/router, WebSockets, RPC (`import std.net.http`).
  - `std/ui`: Immediate-mode UI layout, AuraDS Material Design 3, themes, colors (`import std.ui.aura`), virtualized tables (`import std.ui.datagrid`), node graph editors (`import std.ui.nodegraph`).
  - `std/gfx2d`: 2D canvas primitives, sprites, particle systems, tweens, easings, splines, color LUTs, isometric projection (`import std.gfx2d.canvas`).
  - `std/gfx3d`: 3D meshes (`genMeshCube`, `genMeshSphere`, `.obj`/`.gltf`/`.glb`), PBR materials, cameras, lighting (`import std.gfx3d.mesh3d`).
  - `std/sim`: Kinematics, 2D/3D collision detection, rigid body dynamics, Verlet ropes, game feel, navigation grids, procedural generation (`import std.sim.game`), grid container packing & recipes (`import std.sim.inventory`), cellular automata & diffusion (`import std.sim.cellular`).
  - `std/audio`: 16-voice polyphonic DSP synthesizer, ADSR envelopes, step sequencer, 3D spatial acoustics (`import std.audio`).
  - `std/rt`: Pure-AIPL zero-dependency runtime foundation modules (`import std.rt.alloc`).

### 1.6 Loop 2 Language Features & Ergonomics
- **Optional `module` Header & Auto-Prelude**: Module headers (`module Name`) are optional. The compiler automatically imports standard prelude symbols: `std.cli` (`parseCliArgs`), `std.grid` (`gridNew`, `gridSet`, `grid2dNew`, `grid2dSet`), and `std.pathfinding` (`gridAStar`).
- **Compact Struct Declarations & Positional Constructors**: Declare single-line structs with parameter syntax: `pub struct Point(x: float, y: float = 0.0)` or `pub struct Point: x: float, y: float`. Construct instances positionally (`Point(1.0, 2.0)`) or with named fields (`Point(x = 1.0, y = 2.0)`), with automatic default field filling.
- **Membership Operator `in`**: Test element containment cleanly: `elem in array`, `key in map`, `elem in set`, `substr in str`.
- **Slices `[start..end]`**: Index strings and arrays via range slicing: `arr[a..b]`, `arr[a..]`, `arr[..b]`.
- **List Comprehensions**: Construct transformed and filtered arrays with concise syntax: `[expr for item in iterable if condition]` or `[expr for item in iterable]`.
- **Coalescing Operator `??`**: Unwrap fallible or optional expressions with fallback: `a ?? b` (coalesces `Option[T]`, `Result[T, E]`, or `nil`).
- **Module-Level Variable Declarations (`let` / `pub let` / `mut` / `pub mut`)**: Declare immutable or mutable module-level constants and variables directly at file scope (`let MAX_SIZE = 100`, `pub let DEFAULT_SPEED: float = 75.0`). These are automatically forward-declared across multi-shard C99 compilation units with weak linkage, accessible across all functions without manual local variable encapsulation.
- **Intrinsic Annotations `@intrinsic`**: Decorates compiler and runtime low-level primitives for direct code generation.

---

## 2. Idiomatic Code Generation Patterns

### 2.1 Structs and Enums
```text
pub struct TaskItem:
  id: int
  title: str
  completed: bool

pub enum Priority:
  Low
  Medium
  High
```

### 2.2 Pattern Matching & Exhaustiveness
Always handle every variant when matching on enums. Unhandled variants trigger `AIPL_E2012_NON_EXHAUSTIVE_MATCH`:
```text
pub fn priorityScore(p: Priority): int:
  match p:
    Priority::Low:
      ret 1
    Priority::Medium:
      ret 5
    Priority::High:
      ret 10
```

### 2.3 Error Handling with Postfix `?`
Return algebraic `Result[T, E]` or `Option[T]` types. Use postfix `?` for early returns:
```text
pub fn parseTask(rawJson: str): Result[TaskItem, str]:
  let task = TaskItem.fromJson(rawJson)?
  ret Ok(task)
```

### 2.4 Formal Contracts & Relational Verification
Use `requires` and `ensures` for function contracts, and `invariant` with `decreases` for loops:
```text
pub fn safeClamp(val: int, minVal: int, maxVal: int): int
  requires minVal <= maxVal
  ensures ret >= minVal and ret <= maxVal:
  if val < minVal:
    ret minVal
  else if val > maxVal:
    ret maxVal
  ret val
```

---

## 3. Agent Tooling Protocol & Workflows

AI agents interacting with AIPL codebases must use the dedicated CLI commands to inspect, edit, and verify code with minimal token consumption:

### 3.1 Skeleton Extraction (`aipl outline`)
Before reading large modules, extract the outline to preserve 80%+ of prompt context:
```bash
aipl outline src/module.aipl --json
```

### 3.2 Surgical Splicing (`aipl splice`)
Never re-emit entire 500-line files to update a single function. Use surgical AST replacement:
```bash
aipl splice src/module.aipl functionName replacement.aipl
```

### 3.3 Static Verification & Diagnostics (`aipl verify --json`)
Always verify code changes with the compiler. Parse the structured JSON output:
```bash
aipl verify src/module.aipl --json
```

Diagnostics adhere to `diagnostic-v1.json` with byte spans and suggested diff candidate repairs:
```json
{
  "code": "AIPL_E2001_TYPE_MISMATCH",
  "message": "Expected type 'int', found 'str'",
  "file": "src/app.aipl",
  "line": 42,
  "col": 10,
  "span": [1024, 1032]
}
```

### 3.4 Autonomous Self-Repair (`aipl fix`)
Run `aipl fix` to automatically clean up unused imports and apply mechanical formatting:
```bash
aipl fix src/module.aipl
```

### 3.5 Standard Library Querying (`aipl docs`)
Query standard library signatures directly instead of guessing APIs:
```bash
aipl docs std/fs
aipl docs std/db
aipl docs std/thread
```

---

## 4. Diagnostic Code Reference for Agents

| Diagnostic Code | Meaning | Agent Repair Action |
| :--- | :--- | :--- |
| `AIPL_E1001` | Syntax Error | Check missing colons, invalid braces, or invalid statement structure |
| `AIPL_E1002` | Forbidden Tab | Replace all tabs with 2 ASCII spaces |
| `AIPL_E1003` | Forbidden Underscore | Rename identifier from `snake_case` to `camelCase` or `PascalCase` |
| `AIPL_W1003` | Snake Case Autofix | Run `aipl fmt` or `aipl fix` to automatically heal snake_case identifiers |
| `AIPL_E2001` | Type Mismatch | Verify assigned expression matches declared variable/parameter type |
| `AIPL_E2002` | Implicit Coercion | Add explicit type cast (e.g. `val.toInt()` or `val.toFloat()`) |
| `AIPL_E0312` | Silent Float Truncation | Silent `float -> int` narrowing rejected (`[AIPL312]`); append `.i` or use `//` floor-div |
| `AIPL_E2007` | SMT Contract Violation | Fix preconditions or adjust arithmetic logic to satisfy postconditions |
| `AIPL_E2012` | Non-Exhaustive Match | Add missing enum variants to `match` expression |
| `AIPL_W0045` | Brace/Arrow Token Penalty | Replace `{ ... }` block delimiters and `->` return arrows with canonical `:` syntax (`aipl fmt`) |

---

## See Also
- [Language Specification](docs/SPEC.md)
- [Architectural Oracle](ORACLE.md)
- [Step-by-Step Tutorial](docs/TUTORIAL.md)
- [Standard Library Reference](docs/STDLIB_REFERENCE.md)
- [Cookbook & Recipes](docs/COOKBOOK.md)


---

# Part 2: Standard Library Reference (`docs/STDLIB_REFERENCE.md`)

# AIPL v0.8.0 Standard Library Reference (91 `std/` Modules & 9 Pure-AIPL Runtime Modules)
**Comprehensive API Reference, Signatures, and Usage Guide**

The AIPL Standard Library provides 91 single-responsibility standard library modules organized across 9 canonical functional domains (`std/core`, `std/io`, `std/data`, `std/net`, `std/ui`, `std/gfx2d`, `std/gfx3d`, `std/sim`, `std/audio`) and 9 pure-AIPL runtime foundation modules (`std/rt/*.aipl`, 100 modules total), each documented with a standardized top-of-file `///` specification header (`# Module`, `## Purpose & Domain Scope`, `## Exported Types & Functions`, `## Usage Example`, `## Target Compatibility`).

Every module can be queried interactively in the terminal:
```bash
# General standard library index
aipl docs stdlib

# Inspect any module's /// documentation header, structs, fields, and function signatures
aipl docs std/<domain>/<module>
aipl docs std/<module>
```

---

## 9-Domain Standard Library Architecture

All 91 native standard library modules reside in single-copy domain subfolders:
1. **`std/core`**: Core systems, collections, SIMD math, bitwise ops, memory arenas, dynamic arrays, threadpools, timers, crypto (`std/core/*`).
2. **`std/io`**: Filesystem, streams, child processes, binary buffers, CLI argument parsing, terminal ANSI styling, logging (`std/io/*`).
3. **`std/data`**: Document models (PDF, Markdown, HTML, XML), serialization (JSON, YAML, TOML, INI, CSV), ECS registry, diffs, SQLite3 (`std/data/*`).
4. **`std/net`**: POSIX TCP/UDP sockets, DNS resolution, HTTP/1.1 client/router, WebSockets, RPC (`std/net/*`).
5. **`std/ui`**: Immediate-mode UI layout, AuraDS Material Design 3 design system, themes, colors, accessibility (`std/ui/*`).
6. **`std/gfx2d`**: 2D canvas primitives, sprites, particle systems, tweens, easings, splines, color LUTs, isometric projection (`std/gfx2d/*`).
7. **`std/gfx3d`**: 3D meshes (`genMeshCube`, `genMeshSphere`, `.obj`/`.gltf`/`.glb`), PBR materials, cameras, lighting, spatial transforms (`std/gfx3d/*`).
8. **`std/sim`**: Kinematics, 2D/3D collision detection, rigid body dynamics, Verlet ropes, game feel, navigation grids, procedural generation (`std/sim/*`).
9. **`std/audio`**: 16-voice polyphonic DSP synthesizer, ADSR envelopes, step sequencer, 3D spatial acoustics (`std/audio/*`).
10. **`std/rt`**: Pure-AIPL zero-dependency runtime foundation modules (`alloc`, `array`, `audio`, `canvas_x11`, `crypto_compress`, `json`, `map`, `ptr`, `string`).

Modules can be imported via hierarchical dot paths (`import std.<domain>.<mod>`, e.g. `import std.core.math`, `import std.gfx2d.canvas`) or canonical quoted paths (`import { clampInt } from "std/core/math"`).

---

## Table of Contents
1. [Domain 1: Core & Collections](#domain-1-core--collections)
2. [Domain 2: I/O & Operating System](#domain-2-io--operating-system)
3. [Domain 3: Networking & Web](#domain-3-networking--web)
4. [Domain 4: Database & Cryptography](#domain-4-database--cryptography)
5. [Domain 5: Data Formats & Serialization](#domain-5-data-formats--serialization)
6. [Domain 6: Math, SIMD Tensors & AI](#domain-6-math-simd-tensors--ai)
7. [Domain 7: Concurrency & Memory Arenas](#domain-7-concurrency--memory-arenas)
8. [Domain 8: 2D/3D Graphics, Audio & Physics](#domain-8-2d3d-graphics-audio--physics)
9. [Domain 9: Systems, Linux Kernel ABI & Pure-AIPL Runtime Suite](#domain-9-systems-linux-kernel-abi--pure-aipl-runtime-suite)
10. [Domain 10: Time, Testing & SemVer](#domain-10-time-testing--semver)

---

## Domain 1: Core & Collections

### `std/array`
Contiguous dynamic array operations with linear memory allocation.
- **Key Functions**: `arrayPush[T](arr, item)`, `arrayPop[T](arr)`, `arrayInsert[T](arr, idx, item)`, `arrayRemove[T](arr, idx)`, `arrayClear[T](arr)`, `arrayContains[T](arr, item)`, `arrayIndexOf[T](arr, item)`.

### `std/collections`
Associative data structures and algorithms (delegating ring buffer operations to `std/buffer`).
- **Key Structs**: `HashMap[K, V]`, `HashSet[T]`, `Queue[T]`, `Stack[T]`, `PriorityQueue[T]`, `RingBuffer`.
- **Key Functions**: `mapGet[K, V](m, k)`, `mapSet[K, V](m, k, v)`, `mapHas[K, V](m, k)`, `mapDelete[K, V](m, k)`, `setAdd[T](s, v)`, `setHas[T](s, v)`, `pqDecreaseKey(pq, node, newCost)`, `ringBufferNew(capacity)`, `ringBufferPush(rb, val)`, `ringBufferToArray(rb)`.

### `std/ecs`
Archetype and bitmask Entity Component System (ECS) world registry, generational entity IDs, component bitmasks, and spatial hash broadphase queries.
- **Key Structs**: `EcsWorld`, `SpatialBody2D`.
- **Key Functions**: `ecsWorldNew(capacity)`, `ecsSpawn(w, mask)`, `ecsDespawn(w, id)`, `ecsIsAlive(w, id)`, `ecsSetMask(w, id, mask)`, `ecsGetMask(w, id)`, `ecsQueryMask(w, queryMask)`, `ecsCountAlive(w)`.

### `std/grid`
2D and 3D dense grid storage with flat spatial indexing, compact bitmask grids (`DenseBitGrid2D`) offering 32x memory compression for passability and visibility maps, and symmetric bit matrices (`SymmetricBitMatrix2D`) for PVS visibility and graph adjacency.
- **Key Structs**: `Grid2D[T]`, `Grid3D[T]`, `DenseBitGrid2D`, `SymmetricBitMatrix2D`.
- **Key Functions**: `gridCreate[T](w, h, defaultVal)`, `gridGet[T](g, x, y)`, `gridSet[T](g, x, y, val)`, `gridBoundsCheck(g, x, y)`, `denseBitGridNew(w, h)`, `denseBitGridInBounds(g, x, y)`, `denseBitGridGet(g, x, y)`, `denseBitGridSet(g, x, y, val)`, `denseBitGridStampCircle(g, cx, cy, radius, val)`, `denseBitGridCountOnes(g)`, `denseBitGridBitwiseAnd(a, b)`, `denseBitGridBitwiseOr(a, b)`, `symmetricBitMatrixNew(size)`, `symmetricBitMatrixInBounds(m, a, b)`, `symmetricBitMatrixGet(m, a, b)`, `symmetricBitMatrixSet(m, a, b, val)`, `symmetricBitMatrixSetAll(m, val)`.

### `std/heap`
Binary min-heap and max-heap priority queues with $O(\log N)$ push/pop and $O(1)$ peek operations.
- **Key Structs**: `MinHeap[T]`, `MaxHeap[T]`, `HeapEntry[T]`.
- **Key Functions**: `newMinHeap[T]()`, `newMaxHeap[T]()`, `push[T](h, priority, item)`, `pop[T](h)`, `peek[T](h)`, `peekPriority[T](h)`, `len[T](h)`, `isEmpty[T](h)`.

### `std/pool`
Object pooling and slab memory recycling for low-latency systems.
- **Key Structs**: `ObjectPool[T]`.
- **Key Functions**: `poolCreate[T](factoryFn, initialCap)`, `poolAcquire[T](p)`, `poolRelease[T](p, obj)`, `poolDrain[T](p)`.

### `std/sort`
Sorting algorithms including quicksort, mergesort, and radixsort.
- **Key Functions**: `sortInts(arr)`, `sortFloats(arr)`, `sortStrings(arr)`, `sortBy[T](arr, compareFn)`.

### `std/string`
High-performance UTF-8 string manipulation, `StringBuilder` buffer accumulation, and zero-copy slicing.
- **Key Structs**: `StringBuilder`.
- **Key Functions**: `strSplit(s, delim)`, `strJoin(arr, sep)`, `strTrim(s)`, `strStartsWith(s, prefix)`, `strEndsWith(s, suffix)`, `strReplace(s, target, repl)`, `strSlice(s, start, end)`, `sbNew()`, `sbAppend(sb, s)`, `sbToString(sb)`.

---

## Domain 2: I/O & Operating System

### `std/buffer`
Contiguous binary `ByteBuffer` manipulation, endian-aware byte encoding, and canonical circular `RingBuffer` queues.
- **Key Structs**: `ByteBuffer`, `RingBuffer`.
- **Key Functions**: `byteBufNew()`, `byteBufWriteByte(b, v)`, `byteBufWriteU16BE(b, v)`, `byteBufWriteU32BE(b, v)`, `byteBufReadU16BE(b, offset)`, `byteBufReadU32BE(b, offset)`, `ringNew(capacity)`, `ringPush(rb, val)`, `ringToArray(rb)`.

### `std/cli`
Command-line argument parsing and flag extraction.
- **Key Structs**: `CliParser`, `CliFlag`.
- **Key Functions**: `parseCliArgs()`, `getFlagStr(name, default)`, `getFlagInt(name, default)`, `getFlagBool(name)`.

### `std/dotenv`
`.env` file loader and parser for environment variables.
- **Key Functions**: `loadDotenv(filePath)`, `parseDotenvString(content)`.

### `std/env`
Platform environment variable access and current working directory.
- **Key Functions**: `getEnv(name)`, `setEnv(name, value)`, `hasEnv(name)`, `getCwd()`, `getPlatform()`.

### `std/fs`
Filesystem access, atomic file writes, directory traversal, and file stats.
- **Key Structs**: `FileStat`, `FileHandle`.
- **Key Functions**: `readFile(path)`, `writeFile(path, content)`, `writeFileAtomic(path, content)`, `appendFile(path, content)`, `fileExists(path)`, `isDir(path)`, `readDir(path)`, `walkDir(path)`, `mkdirAll(path)`, `removeFile(path)`, `removeDirAll(path)`.

### `std/io`
Standard input, output, and error streams with formatted printing, plus streaming line and chunk iterators for $O(1)$-memory processing of large files and pipes.
- **Key Functions**: `print(s)`, `println(s)`, `eprint(s)`, `eprintln(s)`, `readLine()`, `readAllStdin()`, `readLines(path)`, `eachLine(path, fn)`, `streamLines(path, fn)`, `streamStdin(fn)`, `streamReaderFromFile(path, chunkSize)`, `streamReadChunk(reader)`.

### `std/path`
Cross-platform path manipulation, normalization, and extension extraction.
- **Key Functions**: `pathJoin(parts)`, `pathDirname(p)`, `pathBasename(p)`, `pathExtname(p)`, `pathNormalize(p)`, `pathIsAbsolute(p)`.

### `std/process`
Child process execution, exit codes, process status, and process spawning.
- **Key Structs**: `ProcessResult`, `SpawnOptions`.
- **Key Functions**: `execCommand(cmd, args)`, `spawnProcess(cmd, args, opts)`, `getProcessId()`, `exitProcess(code)`, `isPidAlive(pid)`.

### `std/term`
Terminal ANSI color escape sequences, cursor controls, and text styling.
- **Key Functions**: `termColor(text, color)`, `termBold(text)`, `termClear()`, `termMoveCursor(row, col)`, `termGetSize()`.

---

## Domain 3: Networking & Web

### `std/dns`
Native DNS resolution over POSIX `getaddrinfo` sockets.
- **Key Functions**: `resolveIpv4(host)`, `resolveAll(host)`, `isIpAddress(host)`.

### `std/html`
HTML tag sanitization, entity encoding/decoding, and minimal DOM scraping.
- **Key Functions**: `escapeHtml(text)`, `unescapeHtml(text)`, `stripHtmlTags(html)`.

### `std/http`
Canonical HTTP/1.1 & HTTPS client and router supporting GET, POST, PUT, DELETE, custom headers, multipart uploads, and query/cookie parsing (re-exporting `urlEncode`/`urlDecode` from `std/encoding`).
- **Key Structs**: `HttpRequest`, `HttpResponse`, `Route`.
- **Key Functions**: `httpGet(url)`, `httpsGet(url)`, `httpPost(url, body, contentType)`, `httpFetch(req)`, `parseQueryParams(queryStr)`, `urlEncode(s)`, `urlDecode(s)`.

### `std/net`
IPv4/IPv6 address validation, `SocketAddr`, `Url` parsing, and low-level TCP socket client/server primitives.
- **Key Structs**: `SocketAddr`, `Url`.
- **Key Functions**: `isValidIpv4(ip)`, `isValidIpv6(ip)`, `isValidPort(port)`, `formatSocketAddr(addr)`, `parseSocketAddr(raw)`, `parseUrl(raw)`, `tcpConnect(host, port)`, `tcpSend(fd, data)`, `tcpClose(fd)`.

---

## Domain 4: Database & Cryptography

### `std/crypto`
Cryptographic hashing (SHA-256, SHA-512, MD5, HMAC) and random byte generation.
- **Key Functions**: `sha256(data)`, `sha512(data)`, `hmacSha256(key, message)`, `md5(data)`, `cryptoRandomBytes(n)`.

### `std/db`
Embedded SQLite3 driver with statement caching, parameterized queries, and transactions.
- **Key Structs**: `DbConn`, `DbRow`, `DbResult`.
- **Key Functions**: `dbOpen(path)`, `dbExec(conn, sql, params)`, `dbQuery(conn, sql, params)`, `dbClose(conn)`, `dbBegin(conn)`, `dbCommit(conn)`, `dbRollback(conn)`.

### `std/uuid`
UUID v4 generation and formatting.
- **Key Functions**: `uuidV4()`, `uuidParse(s)`, `uuidIsValid(s)`.

---

## Domain 5: Data Formats & Serialization

### `std/compress`
Deflate and gzip binary compression and decompression.
- **Key Functions**: `gzipCompress(bytes)`, `gzipDecompress(bytes)`, `deflate(bytes)`, `inflate(bytes)`.

### `std/csv`
RFC 4180 compliant CSV serialization and parsing.
- **Key Functions**: `csvParse(text)`, `csvStringify(rows)`, `csvParseRow(line)`.

### `std/diff`
Myers difference algorithm and unified diff generator.
- **Key Structs**: `DiffHunk`, `DiffChange`.
- **Key Functions**: `computeDiff(oldText, newText)`, `renderUnifiedDiff(oldPath, newPath, diff)`.

### `std/doc`
Universal document model (`UniversalDocument`), spec-compliant `%PDF-1.4` emitter and text extractor, RTF/LaTeX/HTML exporters, relational table queries, and MD3 HTML5 slide decks.
- **Key Structs**: `UniversalDocument`, `DocumentSection`, `Document`, `DocMeta`.
- **Key Functions**: `newUniversalDocument(title, author, format)`, `addDocumentSection(doc, heading, body, level)`, `renderDocumentToPdf(doc)`, `extractTextFromPdf(pdfContent)`, `renderDocumentToRtf(doc)`, `renderDocumentToLatex(doc)`, `renderDocumentToHtml(doc)`, `docMarkdownToSlideDeckHtml(md, deckTitle)`.

### `std/encoding`
Base64, Hexadecimal, and canonical URL percent-encoding.
- **Key Functions**: `base64Encode(bytes)`, `base64Decode(str)`, `hexEncode(bytes)`, `hexDecode(str)`, `urlEncode(s)`, `urlDecode(s)`.

### `std/ini`
INI configuration file parser and serializer with `[section]` hierarchy.
- **Key Functions**: `parseIni(src)`, `parseIniSection(src, section)`, `parseIniSections(src)`, `getIniValue(src, section, key, defaultVal)`, `toIni(section, m)`.

### `std/json`
RFC 8259 JSON parser, serializer, and Draft 2020-12 schema validator.
- **Key Functions**: `jsonParse(str)`, `jsonStringify(val)`, `jsonPrettyPrint(val, indent)`, `jsonGetPathStr(jsonText, path, fallback)`, `jsonGetPathFloat(jsonText, path, fallback = 0.0)`, `jsonGetPathInt(jsonText, path, fallback = 0)`, `jsonStringifyIntArray(arr)`, `jsonGetPathIntArray(jsonText, path)`.

### `std/markdown`
CommonMark subset markdown parser and HTML converter.
- **Key Functions**: `markdownToHtml(md)`, `extractMarkdownHeaders(md)`.

### `std/qrcode`
QR Code matrix generation and ASCII/PNG rendering.
- **Key Structs**: `QrMatrix`.
- **Key Functions**: `qrGenerate(text, eccLevel)`, `qrToAscii(matrix)`.

### `std/regex`
Linear-time regular expression pattern matching and search.
- **Key Structs**: `RegexMatch`.
- **Key Functions**: `regexMatch(pattern, text)`, `regexFind(pattern, text)`, `regexReplaceAll(pattern, text, repl)`.

### `std/tar`
Tar archive file extraction and packaging.
- **Key Structs**: `TarHeader`, `TarArchive`.
- **Key Functions**: `tarCreate(entries)`, `tarExtract(bytes, destDir)`.

### `std/toml`
TOML v1.0.0 configuration parser and serializer supporting `[table]` sections and key-value extraction.
- **Key Functions**: `parseToml(src)`, `parseTomlSection(src, section)`, `parseTomlSections(src)`, `getTomlValue(src, section, key, defaultVal)`, `toToml(m, section)`.

### `std/xml`
Lightweight XML parsing and node traversal.
- **Key Structs**: `XmlNode`.
- **Key Functions**: `xmlParse(text)`, `xmlFindElement(node, tagName)`.

### `std/yaml`
YAML 1.2 subset parser and emitter supporting indentation-scoped mappings, sequences, and JSON conversion.
- **Key Structs**: `YamlEntry`.
- **Key Functions**: `parseYamlMap(src)`, `parseYamlEntries(src)`, `getYamlValue(src, key, defaultVal)`, `parseYamlList(src)`, `toYamlMap(m)`, `yamlToJson(src)`.

---

## Domain 6: Math, SIMD Tensors & AI

### `std/ai`
Multi-provider AI tooling (Gemini, OpenAI, Anthropic, Ollama), embeddings, and cosine similarity.
- **Key Structs**: `AiPrompt`, `AiResponse`, `AiToolDef`.
- **Key Functions**: `cosineSimilarity(vecA, vecB)`, `normalizeVector(vec)`, `estimateTokenCount(text)`.

### `std/math`
Trigonometric, logarithmic, hardware-accelerated SIMD vector operations (AVX-512/AVX2/NEON), loop auto-vectorization planning, 64-bit bitboard intrinsics, byte angle wrapping, and robust prescaled floating-point arithmetic.
- **Key Structs**: `Float64Buffer`, `Int64Buffer`, `SimdLoopVectorPlan`.
- **Key Functions**: `sin(x)`, `cos(x)`, `tan(x)`, `sqrt(x)`, `atan2(y, x)`, `wrapAngle(angle)`, `wrapAnglePi(angle)`, `angleDeltaRad(target, source)`, `wrapAngleDeg(deg)`, `angleDeltaDeg(targetDeg, sourceDeg)`, `wrapAngleByte(b)`, `angleDeltaByte(targetByte, sourceByte)`, `stepAngleByte(currentByte, targetByte, maxStep)`, `vec2RotateFixed(x, y, angleBytes)`, `dotProductFloats(a, b)`, `axpyFloats(alpha, x, y)`, `sumFloatsFast(buf)`, `sumIntsFast(buf)`, `analyzeSimdLoopAutoVectorization(strideElem, tripCount, hasLoopCarriedDep, targetBits)`, `simdDotProduct8Wide(a, b)`, `simdAxpy8Wide(alpha, x, y)`, `simdFma4Wide(a, b, c)`, `simdMatmul4x4Tiled(a, b, n)`, `popcnt64(x)`, `ctz64(x)`, `clz64(x)`, `ldexpFloat(m, exp2)`, `sqrtSafePrescaled(x)`.

### `std/procgen`
Deterministic seeded PRNG, 2D Value noise, Fractal Brownian Motion (fBm), BSP dungeon room generation, and cellular automata cave generation.
- **Key Structs**: `Prng`.
- **Key Functions**: `prngNew(seed)`, `prngNext(rng)`, `prngRange(seed, step, minVal, maxVal)`, `valueNoise2D(x, y, seed)`, `fbm2D(x, y, octaves, persistence, lacunarity, seed)`, `generateDungeonRooms(width, height, maxRooms, tileSize, seed)`, `generateCaveCellular(width, height, fillPercent, iterations, tileSize, seed)`.

### `std/random`
Mersenne Twister and Xoshiro256 pseudo-random number generation.
- **Key Structs**: `RandomGenerator`.
- **Key Functions**: `randFloat()`, `randInt(min, max)`, `randBool()`, `seedRandom(seed)`.

---

## Domain 7: Concurrency & Memory Arenas

### `std/arena`
Task-local scoped bump arena allocation with $O(1)$ bulk reclamation and deep return-value evacuation.
- **Key Structs**: `ScratchArena`.
- **Key Functions**: `arenaMark()`, `arenaReset()`, `arenaAlloc(size)`, `arenaActiveDepth()`, `arenaPopEvacuate(mark, val)`, `arenaStats()`, `withScratchArena(closure)`, `with arena:`.

### `std/async`
Asynchronous promise combinators and event loops.
- **Key Structs**: `Promise[T]`, `Future[T]`.
- **Key Functions**: `asyncAll(promises)`, `asyncRace(promises)`, `asyncDelay(ms)`.

### `std/thread`
Multi-core work-stealing threadpool, lock-free MPSC channels, CPU core topology discovery, and parallel process execution.
- **Key Structs**: `ThreadPool`, `Sender[T]`, `Receiver[T]`, `MpscChannel`.
- **Key Functions**: `ThreadPool.create(workers)`, `channel[T]()`, `spawn(taskFn)`, `pool.submit(taskFn)`, `pool.shutdown()`, `hardwareConcurrency()`, `defaultJobs()`, `execParallel(cmds, maxJobs)`, `parallelMatmulInt(a, b, m, n, k, numThreads)`.

---

## Domain 8: 2D/3D Graphics, Audio & Physics

### `std/asset`
Asset loader for textures, sprites, sound effects, and fonts.
- **Key Structs**: `AssetRegistry`.
- **Key Functions**: `loadTexture(path)`, `loadSound(path)`, `registerAsset(key, path)`.

### `std/audio`
Procedural sound synthesis, ADSR envelopes, 16-voice polyphony, RIFF WAV PCM loader, and raw/normalized sample buffer playback.
- **Key Structs**: `AudioBuffer`, `AdsrEnvelope`.
- **Key Functions**: `playTone(freqHz, durationMs)`, `synthesizeWave(shape, freqHz, envelope)`, `loadSound(path)`, `loadWavPcm16(path)`, `playPcmBuffer(samples, sampleRate, channels)`, `playSoundEx(handle, volume, pitch, pan)`.

### `std/aura`
Material Design 3 / Radix / Shadcn / Fluent 2 / ImGui-inspired immediate-mode vector UI, responsive layout & auto-fit container system, data visualization telemetry, and genre-authentic Game HUD library (`AuraDS 6.1`).
- **Key Structs**: `AuraTheme`, `AuraRect`, `AuraFlowContainer`, `AuraContext`, `AuraTextResult`, `AuraSplitState`, `AuraListState`, `AuraToastItem`, `AuraFindReplaceState`, `AuraKanbanAction`, `AuraDocTabResult`, `AuraHeatmapCell`.
- **Themes & Typography Scales**: `auraThemeDark()`, `auraThemeLight()`, `auraThemeArcadeNeon()`, `auraThemeCyberpunk()`, `auraThemeHighContrast()`, `auraThemeNord()`, `auraThemeSolarized()`, `auraThemeByIndex(idx)`, `auraScrimColor(scrimHex)`, `auraGlassColor(glassHex)`, `auraFontSizeSmall()`, `auraFontSizeBody()`, `auraFontSizeTitle()`, `auraFontSizeDisplay()`, `auraHeading(ctx, x, y, text)`, `auraSubheading(ctx, x, y, text)`.
- **Responsive Layout & Containers**: `auraWindowRect()`, `auraContentRect(topBarH, pad)`, `auraFlexRow`, `auraFlexCol`, `auraGridCell`, `auraSplitHorizontal`, `auraSplitContainerVertical(container, topRatio, gap, isTop)`, `auraContainerBegin`, `auraFlowText`, `auraFlowBadge`, `auraFlowButton`, `auraFlowNewline`, `auraContainerEnd`, `auraAutoWindowSize`.
- **Rich Containers, Cards & Navigation Bars**: `auraCard`, `auraElevatedCard(ctx, rect, elevation)`, `auraGlassCard(ctx, rect, title)`, `auraCollapsiblePanel(ctx, id, rect, title, expanded)`, `auraAccordionItem(ctx, id, rect, title, contentText, expanded)`, `auraStatusBar(ctx, rect, leftItems, rightItems)`, `auraMenuBar(ctx, id, rect, menus, activeIdx)`, `auraToolbarRibbon(ctx, id, rect, tools, activeIdx)`, `auraBreadcrumbs(ctx, id, rect, crumbs)`, `auraPaginationBar(ctx, id, rect, currentPage, totalPages)`, `auraEmptyStateCard(ctx, rect, iconText, title, subtitle, actionLabel)`, `auraAlertBanner(ctx, rect, severity, title, message, dismissible)`, `auraAvatar(ctx, cx, cy, radius, initials, bgColor)`, `auraModalDialogRect(ctx, title, w, h)`.
- **Virtualized Lists, Tables & Specialized App Widgets**: `auraDataTable`, `auraInteractiveDataTable`, `auraSortableDataTable(ctx, id, rect, headers, rows, colWidths, selectedRow, sortCol, sortAscending)`, `auraKanbanBoardInteractive(ctx, id, rect, columns, colSubtitles, cardLists, selectedCol, selectedCard)`, `auraKanbanSwimlaneHeader(ctx, rect, title, dealCount, wipLimit, totalValueStr)`, `auraKanbanFrontmatterBoard(x, y, w, h, backlogCnt, inProgCnt, reviewCnt, doneCnt, wipLimit)`, `auraDealRoomContractSigner(x, y, w, h, dealTitle, arrValue, signerName, signedStatus, docusignId)`, `auraAttributionTouchpointBar(x, y, w, h, modelName, firstTouchPct, linearPct, wShapePct)`, `auraTerritoryQuotaHeatmapCard(x, y, w, h, regionLabel, attainmentPct, repCount)`, `auraRevenueWaterfallChart(ctx, rect, startArrK, expandArrK, churnArrK, netNdrPct)`, `auraSankeyConversionFlow(ctx, rect, stageNames, stageValues, conversionPcts)`, `auraTimelineFeed(ctx, rect, timestamps, actors, descriptions, types)`, `auraDocumentTabs(ctx, id, rect, titles, dirtyFlags, activeIdx)`, `auraShortcutPressed(ctx, keyName)`, `auraModShortcutPressed(ctrl, shift, key)`, `auraVirtualizedList(ctx, id, rect, items, rowHeight, scrollOffset, selectedIdx)`, `auraRichListItem(ctx, id, rect, title, subtitle, badgeText, selected)`, `auraPropertyGridRow(ctx, id, rect, propName, propValue, editable)`, `auraColorSwatchGrid(ctx, id, rect, colors, cols, selectedColor)`, `auraLayerListRow(ctx, id, rect, layerName, visible, locked, opacityPct, active)`, `auraMarkdownBlock(ctx, rect, lines)`, `auraCalloutFoldableAdmonition(x, y, w, h, tierName, title, bodySummary, isExpanded)`, `auraCitationBibtexInspector(x, y, w, h, citeKey, doiString, cslStyle)`, `auraSplitDiffReviewPane(ctx, rect, leftLine, rightLine, addCount, delCount)`, `auraCodeBlockView(ctx, rect, title, codeLines, highlightLine)`, `auraFindReplaceBar(ctx, id, rect, findQuery, replaceQuery, matchCount)`, `auraCommandPaletteModal(ctx, rect, queryText, commands, shortcuts, selectedIdx)`, `auraShortcutPill(ctx, x, y, keys)`, `auraColorStudioPanel(ctx, id, rect, primaryColor, secondaryColor, swatches, cols)`, `auraHsvToRgbHex(hDeg, sPct, vPct)`, `auraHsvColorWheel(ctx, cx, cy, rOuter, rInner, hDeg, sPct, vPct)`, `auraColorHarmonyWheelCard(x, y, w, h, harmonyMode, primaryHex, compHex, triadHex)`, `auraCMYKSoftProofHistogram(x, y, w, h, iccProfile, gamutWarnPct, inkCoveragePct)`, `auraLiquifyWarpMeshGrid(ctx, rect, modeName, brushRadiusPx, strengthPct)`, `auraLayerStack(ctx, id, rect, names, visibles, lockeds, opacities, activeIdx)`, `auraCanvasViewport(ctx, id, rect, zoomPct, cursorGridX, cursorGridY, canvasW, canvasH)`, `auraSplitPaneInteractive(ctx, id, rect, ratio, horizontal)`, `auraSplitDiffView(ctx, id, rect, leftTitle, leftLines, rightTitle, rightLines, scrollY)`, `auraSplitDiffMinimap(ctx, rect, addedLines, removedLines, totalLines, viewportRatio)`, `auraSymbolOutlineTree(x, y, w, h, activeFn, fnCount, structCount, lineNum)`, `auraRefactorRenamePreview(x, y, w, h, oldSym, newSym, refCount, fileCount)`, `auraHexBinaryInspectorStrip(x, y, w, h, offsetHex, bytesHex, asciiPreview)`, `auraRegexAstExplainCard(ctx, rect, patternStr, groupSummary, stepCount)`, `auraInlineMathPill(ctx, x, y, mathText)`, `auraKaTeXMathBlock(ctx, rect, latexExpr, caption)`, `auraBidirectionalGraph(ctx, rect, centerLabel, outLabels, inLabels)`, `auraMermaidClassBox(ctx, rect, className, fields, methods)`, `auraMermaidSequenceLifeline(ctx, rect, actorLeft, actorRight, msgLabel, isAsync, loopDepth)`, `auraFunnelChart(ctx, rect, stages, values)`, `auraStackedAreaChartDomain(ctx, rect, seriesA, seriesB, minVal, maxVal)`, `auraPixelRulerBar(ctx, rect, horizontal, maxUnits, cursorUnit)`, `auraTimelineCelStrip(ctx, rect, frameCount, activeFrame, onionSkin)`, `auraAnimationOnionSkin(ctx, rect, prevAlphaPct, nextAlphaPct, fps, playing)`, `auraTimelineKeyframeTrack(x, y, w, h, trackName, curFrame, totalFrames, fps)`, `auraBezierPathInspector(ctx, rect, p0Str, c1Str, c2Str, p3Str, closedPath)`, `auraThermalScaleLegend(ctx, rect, minTempK, maxTempK, currentTempK)`, `auraSubGridProfilerBar(ctx, rect, caStepMs, airStepMs, renderMs, activeParticles, fps)`, `auraParticleSpectrumHistogram(x, y, w, h, topElem, solidPct, liquidPct, gasPct, plasmaPct)`, `auraParticleSpectrometerCard(ctx, rect, elemName, wavelengthNm, tempK, count)`, `auraFluidStreamlineLegend(x, y, w, h, machNum, reynoldsNum, curlMax)`, `auraLogicGateTruthTableCard(x, y, w, h, gateType, busHex, propDelayNs)`, `auraMinimapScrollbar(ctx, id, rect, lineLengths, scrollLine, visibleLines, totalLines)`, `auraMermaidFlowchart(ctx, rect, nodeLabels, edgeFrom, edgeTo)`, `auraHeatmapGrid(ctx, id, rect, rowLabels, colLabels, values, selectedRow, selectedCol)`, `auraSlaCountdownRow(ctx, id, rect, title, owner, remainingMins, breached, acked)`.
- **Genre-Authentic Game HUD Suite**: `auraHealthBar`, `auraAbilitySlot`, `auraRadialCooldownSlot(ctx, rect, label, hotkey, cooldownRatio, isAutocast)`, `auraBossHealthBar(ctx, rect, bossName, hpRatio, immunities)`, `auraAutomapOverlay(ctx, rect, playerX, playerY, zoom)`, `auraHeroSkillTreeConnector(ctx, x1, y1, x2, y2, unlocked)`, `auraSocketedRuneBadge(ctx, cx, cy, radius, runeName, glowHex)`, `auraKillfeedBanner(ctx, rect, killer, weapon, victim, isHeadshot, streakCount)`, `auraSpectatorHudBar(ctx, rect, mapName, roundTimeStr, ctScore, tScore, specTargetName, specWeapon, hltvViewers)`, `auraDemoPlaybackBar(x, y, w, h, demoName, curTick, maxTick, netGraphFps, lerpMs)`, `auraDemoTimelineScrubberBar(ctx, rect, demoName, curTick, maxTick, speedLabel)`, `auraVoiceCommRosterStrip(x, y, w, h, squadLabel, activeSpeaker, codecInfo)`, `auraTacticalRadarMinimap(x, y, radius, mapName, yawDeg, sweepDeg, hostagesRescued, hostagesTotal)`, `auraInventoryCombineCard(ctx, rect, itemA, itemB, resultItem, description)`, `auraPuzzleWireCircuitBox(x, y, w, h, title, voltage, targetVoltage, isSolved)`, `auraChemicalMixValvePanel(x, y, w, h, chemFormula, valve1, valve2, valve3)`, `auraSafeCombinationDial(x, y, w, h, safeName, dialSequence, unlockReward)`, `auraEcgVitalMonitorStrip(ctx, rect, statusLabel, bpm, poisonFlag)`, `auraTechTreeTierCard(ctx, rect, tierLevel, tierName, prereqText, progressPct)`, `auraReplayTimelineScrubber(x, y, w, h, replayName, curSec, totalSec, speedMult, apm)`, `auraReplayActionFeedCard(ctx, rect, playerName, apm, lastAction)`, `auraUpkeepScoreSummary(x, y, w, h, heroScore, unitScore, resScore, mvpHero)`, `auraWorldEditorTriggerTree(x, y, w, h, mapTitle, eventLine, actionLine)`, `auraArpgItemCompareCard(ctx, rect, equippedTitle, hoveredTitle, statDeltas, deltaPositive)`, `auraRealmDifficultyBanner(x, y, w, h, diffName, playersScale, resPenalty, terrorZone)`, `auraCubeRecipeScrollCard(x, y, w, h, recipeName, inputRunes, outputItem, ilvl)`, `auraCubeRecipeTransmuteGrid(ctx, rect, recipeTitle, inputSummary, outputSummary)`, `auraRelicKeyShardTracker(x, y, w, h, keysStatus, organsStatus, torchRoll)`, `auraECGHeartbeatMonitor(ctx, rect, bpm, conditionLabel, phase)`, `auraRadialMenu`, `auraVirtualJoystick`, `auraComboCounter`, `auraFloatingCombatText`, `auraMinimapFrame`, `auraGameOverlay`, `auraDialogueBox`, `auraCrosshairDynamic(ctx, cx, cy, gap, length, color, hitMarker)`, `auraKillFeedEntry(ctx, x, y, killer, weapon, victim, isHeadshot)`, `auraKillFeedEntryColored(ctx, x, y, killer, killerCol, weapon, victim, victimCol, isHeadshot)`, `auraRadarMinimap(ctx, cx, cy, radius, playerYawRad, blipOffsets, blipColors)`, `auraResourceBarRTS(ctx, rect, names, amounts, rates, colors)`, `auraCommandCardGrid(ctx, id, rect, cols, rows, labels, hotkeys, costs, disabledMask)`, `auraMinimapRTS(ctx, rect, mapW, mapH, camX, camY, viewW, viewH, unitXs, unitYs, unitColors)`, `auraHeroPortraitStackRTS(ctx, id, x, y, names, levels, hpRatios, manaRatios, selectedIdx)`, `auraSubgroupStripRTS(ctx, x, y, slotW, slotH, gap, names, hpRatios, manaRatios, activeIdx)`, `auraOrbsHealthMana(ctx, leftX, rightX, bottomY, radius, hpRatio, manaRatio)`, `auraOrbsHealthManaCentered(ctx, leftX, rightX, centerY, radius, hpRatio, manaRatio)`, `auraECGStatusMonitor(ctx, rect, phase, healthPct, statusLabel)`, `auraElementToolbarStrip(ctx, id, rect, elements, colors, activeIdx)`, `auraElementToolbarStripIds(ctx, id, rect, elements, ids, colors, activeId)`, `auraInventoryGridSlot(ctx, id, rect, itemLabel, quantity, equipped, selected, rarityColor)`, `auraSkillTreeNode(ctx, id, rect, title, rank, maxRank, unlocked, parentCenterX, parentBottomY)`, `auraItemTooltipCard(ctx, x, y, title, titleColor, subtitle, affixes, sockets)`, `auraBuyMenuOverlay(ctx, id, rect, title, items, prices, playerCash, selectedIdx)`.

### `std/canvas`
Hardware-accelerated 2D canvas drawing (circles, rects, lines, text, paths, affine matrix stack), contiguous pixel framebuffer uploads, raycasting/scanline helpers, subpixel LCD anti-aliasing, tapered particle ribbons, configurable max FPS & live frame-time telemetry, and Structure-of-Arrays (SoA) batch primitives.
- **Key Structs**: `Canvas`, `Color`, `Vec2`, `PointerEvent`.
- **Key Functions**: `canvasCreate(w, h)`, `canvas.clear(color)`, `canvas.fillRect(x, y, w, h, c)`, `canvas.fillCircle(x, y, r, c)`, `canvas.pushMatrix()`, `canvas.popMatrix()`, `setTargetFps(fps)`, `getFrameTime()`, `setMaxFps(maxFps)`, `getCurrentFps()`, `getFrameTimeMs()`, `drawPixelBuffer(pixels, gridW, gridH, dstX, dstY, dstW, dstH)`, `drawCirclesSoA(xs, ys, radii, colors, count)`, `drawRectsSoA(xs, ys, ws, hs, colors, count)`, `drawTexturedWallStrip(x, yTop, colW, wallH, texColumnColors, shade)`, `drawFloorCeilingScanlines(x, y, w, h, horizonY, skyColorTop, floorColorNear, bands)`, `drawDepthColumnsSoA(xs, yTops, heights, colors, colW, count)`, `drawPerspectiveQuad(x1, y1, x2, y2, x3, y3, x4, y4, col)`, `drawGlowCircle(x, y, radius, colorHexVal, intensity)`, `drawDashedRectOutline(x, y, w, h, dashLen, gapLen, col, thickness)`, `drawVectorField2D(xs, ys, vxs, vys, scale, col, count)`, `drawCrosshairSniperScope(cx, cy, radius, screenW, screenH, milDots)`, `drawIsometricWallSegment(x1, y1, x2, y2, wallHeight, topColor, faceColor)`, `drawRadialRadarSweep(cx, cy, radius, angleDeg, sweepColorHex)`, `drawPerspectiveCheckerFloor(x, y, w, h, rows, cols, colA, colB)`, `drawVolumetricFogLayer(x, y, w, h, densityPct, fogHex)`, `drawBezierRibbonConnection(x1, y1, x2, y2, thickness, colStart, colEnd)`, `drawNormalLitSurface(x, y, w, h, lightAzimuth, lightElevation, baseHex, specHex)`, `drawAudioSpectrumBars(x, y, w, h, numBands, peakDb, accentHex)`, `drawSubpixelAASpan(x, y, w, h, coverage, fgHex, bgHex)`, `drawParticleRibbonTrail(x1, y1, x2, y2, widthStart, widthEnd, colHex)`, `drawRibbonTrail(x1, y1, x2, y2, segments, startWidth, coreHex, fadeHex)`, `drawSubpixelRect(x, y, w, h, fgHex, bgHex)`, `drawSubpixelTextSpan(x, y, text, fontPx, textHex, bgPlateHex)`, `listRunningWindowsFiltered(titleSubstr)`.

### `std/charbody`
Universal procedural articulated multi-limb character body, 8-way/4-way facing pose interpolation, melee swing / recoil kinetics, status aura rings, and first-person viewmodel rig across all game genres (`0=SpecOps`, `1=SurvivalHorror`, `2=RTSHero`, `3=DarkARPG`, `4=SandboxExplorer`).
- **Key Structs**: `CharBodySpec`.
- **Key Functions**: `drawCharacterBody(spec)`, `drawFirstPersonWeaponRig(x, y, w, h, weaponKind, recoilOffset, inspectPhase, gunMetalHex, accentHex, gloveHex)`, `quantizeFacingOctant(facingDeg)`, `quantizeFacingQuadrant(facingDeg)`, `interpolateFacingDeg(curDeg, targetDeg, turnRateDeg, dt)`, `computeMeleeSwingArcOffset(swingPhase, swingRadius)`, `computeRecoilKickOffset(shotsFired, recoveryPhase)`, `drawCharacterMeleeSwingTrail(spec, swingPhase, trailHex)`, `drawCharacterStatusAuraRing(spec, auraKind, radiusScale, auraHex, pulsePhase)`.

### `std/color`
Color space manipulation (RGB, RGBA, HSL, Hex, color lerping).
- **Key Structs**: `Color`.
- **Key Functions**: `rgb(r, g, b)`, `rgba(r, g, b, a)`, `hsl(h, s, l)`, `colorLerp(c1, c2, t)`, `hexToColor(hexStr)`.

### `std/fx`
Post-processing visual effects (bloom, blur, chromatic aberration, vignette).
- **Key Functions**: `applyVignette(canvas, strength)`, `applyChromaticAberration(canvas, offset)`.

### `std/game`
Game loop state manager, Camera2D trauma shake, swept AABB collision, sprite animation state machine, platformer feel, autonomous steering, configurable Max FPS & live frame-time telemetry, and genre math helpers (RTS APM, ARPG cube crafting `ilvl` & Ebug defense, survival horror P-Q-R-S-T ECG waveform).
- **Key Structs**: `Camera2D`, `SweptHit`, `SpriteClip`, `SpriteAnimator`, `PlatformerFeel`, `FpsTelemetry`.
- **Key Functions**: `camera2DNew(viewW, viewH)`, `camera2DFollow(cam, targetX, targetY, smoothSpeed, dt, frameSeed)`, `sweptAabb(x1, y1, w1, h1, vx, vy, x2, y2, w2, h2)`, `spriteAnimatorUpdate(anim, clip, dt)`, `platformerFeelStep(feel, dt, isGrounded, jumpPressed, coyoteDuration, bufferDuration)`, `steerSeek(x, y, tx, ty, maxSpeed)`, `steerFlee(x, y, tx, ty, maxSpeed)`, `steerArrive(x, y, tx, ty, maxSpeed, slowRadius)`, `configureGameMaxFps(maxFps)`, `setGameMaxFps(maxFps)`, `getGameCurrentFps()`, `getGameFrameTimeMs()`, `sampleFpsTelemetry(maxFps)`, `computeApmCounter(validActions, elapsedMs)`, `computeCraftedItemLevel(charLevel, inputItemLevel)`, `computeEtherealBugDefense(baseDef)`, `evaluateEcgWaveform(bpm, phaseSec, conditionTier)`, `parabolicProjectilePosY(startY, vy0, gravity, t)`.

### `std/particles`
Universal multi-perspective particle emitters, ballistic parabolic grenade/acid-shell ribbon trails, jagged multi-segment lightning arcs, Archimedean spiral & pinwheel missile wakes, multi-lobe muzzle-flash billboards, world-space impact decals (`{scorch1`, `{shot1..5`, acid pools), volumetric smoke clouds, and 30-bit sub-atomic optical wavelength dispersion (`v0.4.0`).
- **Key Structs**: `ParticleEmitterSpec`, `DecalStampSpec`.
- **Key Functions**: `decodeSpectrum30Bit(ctype)`, `computePrismDispersionDeg(incidentDeg, bandIndex)`, `drawRibbonTrail(x1, y1, x2, y2, segments, startWidth, coreHex, fadeHex)`, `drawParabolicRibbonArc(x1, y1, x2, y2, apexHeight, segments, widthStart, widthEnd, coreHex, fadeHex, drawBounceNode)`, `drawJaggedLightningRibbon(x1, y1, x2, y2, segments, jitterAmp, thickness, coreHex, glowHex, seed)`, `drawSpiralMissileWake(cx, cy, startRadius, endRadius, turns, phaseRad, steps, coreHex, trailHex)`, `drawMuzzleFlashStar(x, y, radius, angleDeg, coreHex, midHex, coronaHex)`, `drawWorldSurfaceDecal(spec)`, `drawVolumetricSmokePuffs(cx, cy, radius, puffCount, tick, smokeHex, alphaPct)`, `drawParticleEmitterBurst(spec, elapsedSec)`.

### `std/viewport`
Dynamic aspect-ratio viewport scaling, letterbox/pillarbox framing, mouse coordinate unprojection, HUD corner anchors, DPI font scaling, and configurable Max FPS & live measured FPS telemetry HUD badges.
- **Key Structs**: `AspectViewport`.
- **Key Functions**: `computeAspectViewport(winW, winH, logicalW, logicalH)`, `drawAspectLetterboxBars(vp, barHex)`, `configureViewportMaxFps(maxFps)`, `getMaxFps(configuredMaxFps)`, `drawViewportFpsHudBadge(vp, x, y, label, maxFps, accentHex)`, `drawViewportResolutionHudBadge(vp, x, y, label, accentHex)`, `unprojectMouseX(vp, rawX)`, `unprojectMouseY(vp, rawY)`, `projectLogicalToScreenX(vp, logicalX)`, `projectLogicalToScreenY(vp, logicalY)`, `clampViewportX(vp, logicalX, margin)`, `clampViewportY(vp, logicalY, margin)`, `viewportCenterX(vp)`, `viewportCenterY(vp)`, `viewportAnchorTopLeft(vp, padX, padY)`, `viewportAnchorTopRight(vp, elemW, padX, padY)`, `viewportAnchorBottomLeft(vp, elemH, padX, padY)`, `viewportAnchorBottomRight(vp, elemW, elemH, padX, padY)`, `viewportEffectiveDpiScale(vp, systemDpiScale)`, `viewportScaleFontPx(vp, basePx, minPx, maxPx)`.

### `std/worldgen`
Universal multi-perspective 3D environment & map engine supporting `0=2D`, `1=2.5D`, `2=Isometric`, `3=Fixed-Cam 3D`, and `4=Free 3D` cameras with terrain heightmap sampling, Lambertian normal shading, projected floor tile grids, portal archways, and weather emitters.
- **Key Structs**: `CameraViewpoint`.
- **Key Functions**: `worldProjectPoint(vp, wx, wy, wz)`, `worldRenderEnvironmentBackdrop(vp, skyTopHex, skyBotHex, groundHex, gridHex, fogDensity)`, `worldRenderBlock3D(vp, wx, wy, wz, dx, dy, dz, topHex, frontHex, sideHex)`, `worldRenderWeatherParticles(vp, weatherKind, density, tick, tintHex)`, `worldSampleTerrainHeight(wx, wy, amp, freq, seed)`, `worldComputeLambertShade(nx, ny, nz, lightAzimuthDeg, lightElevDeg, ambientMin)`, `worldShadeHexColor(baseHex, shadeFactor)`, `worldIsPointInFrustum(vp, wx, wy, wz, marginPx)`, `worldRenderFloorTileGrid(vp, originX, originY, originZ, cols, rows, tileSize, evenHex, oddHex, mortarHex)`, `worldRenderPortalArchway(vp, wx, wy, wz, width, height, frameHex, portalGlowHex, pulsePhase)`.

### `std/geom2d`
2D vectors, line segments, rays, and collision intersections.
- **Key Structs**: `Vec2`, `Ray2D`, `Circle2D`, `Rect2D`.
- **Key Functions**: `vec2(x, y)`, `vec2Dot(a, b)`, `vec2Cross(a, b)`, `intersectCircleRect(c, r)`, `pointInRect(px, py, rx, ry, rw, rh)`, `pointInRectInt(px, py, rx, ry, rw, rh)`.

### `std/geom3d`
3D vectors, quaternions, camera matrices, depth-sorted mesh rasterizer, point-light attenuation, and Lambertian shading, plus AABB ray intersection, cylinder ray intersection, and Euler orientation vectors.
- **Key Structs**: `Vec3`, `Mat4`, `Camera3D`, `Mesh3D`, `AABB3D`, `EulerVectors`.
- **Key Functions**: `vec3(x, y, z)`, `mat4Perspective(fov, aspect, near, far)`, `aabbFromCenterExtents(cx, cy, cz, hx, hy, hz)`, `aabb2DTo3D(minX, minY, maxX, maxY, minZ, maxZ)`, `aabbContainsPoint(box, pt)`, `aabbIntersects3D(a, b)`, `eulerToAngleVectors(pitchDeg, yawDeg, rollDeg)`, `rayIntersectsAABB(rayOrigin, rayDir, box)`, `rayIntersectsCylinder(rayOrigin, rayDir, cylCenter, radius, height)`, `radialAttenuation(origin, target, maxRadius, curve = 1.0)`, `drawCubeMesh(canvas, camera, rot)`, `computePointLightAttenuation(dist, radius, minAmbient)`, `drawBillboardSprite3D(pos, w, h, color, cameraDist, screenW, screenH, focalLength)`, `drawFirstPersonViewmodelPrism(x1, y1, x2, y2, thickness, baseHex, rimHex)`.

### `std/iso`
Isometric 2.5D grid projection, heightmaps, axial hex grids, depth sorting, and lighting primitives.
- **Key Structs**: `IsoTile`, `HexCoord`.
- **Key Functions**: `isoToScreen(gx, gy, gz, tileW, tileH, originX, originY)`, `screenToIso(sx, sy, tileW, tileH, originX, originY)`, `drawIsoDiamond(cx, cy, tileW, tileH, fillCol, outlineCol)`, `drawIsoPrism(gx, gy, gz, heightPx, tileW, tileH, originX, originY, topCol, leftCol, rightCol, outlineCol)`, `isoSortIndicesByDepth(gxList, gyList)`, `drawIsoShadow(cx, cy, radiusX, radiusY, alphaPct)`, `drawIsoLightHalo(cx, cy, radius, colorHexVal, alphaPct)`, `drawIsoTexturedTile(cx, cy, tileW, tileH, baseColorHex, accentColorHex, borderHex, lightMul)`, `drawIsoAutomapDiamond(cx, cy, tileW, tileH, color)`.

### `std/gpu`
WebGPU compute pipeline code generation targeting WGSL with workgroup shared memory, triple-buffered staging rings, and 64-bit SWAR bitboard intrinsics.
- **Key Structs**: `WgslComputePipeline`, `StagingRingBuffer`.
- **Key Functions**: `compileWgslComputePipeline(name, wgX, wgY, wgZ, sharedMemFloats, bodyExpr)`, `createStagingRingBuffer(capacityBytes)`, `advanceStagingRingTripleBuffer(ring)`, `dispatchWebGpuComputePass2D(pipe, gridW, gridH)`, `bitboardShl64(a, shift)`, `bitboardShr64(a, shift)`, `bitboardAnd64(a, b)`, `bitboardOr64(a, b)`, `bitboardXor64(a, b)`, `bitboardPopcnt64(a)`.

### `std/image`
Raster image manipulation, pixel buffer blitting, and PNG/BMP decoders.
- **Key Structs**: `ImageBuffer`.
- **Key Functions**: `createImage(w, h)`, `imageGetPixel(img, x, y)`, `imageSetPixel(img, x, y, color)`.

### `std/pathfinding`
A* and Dijkstra graph traversal over 2D grid maps.
- **Key Structs**: `PathNode`.
- **Key Functions**: `findPathAStar(grid, startX, startY, endX, endY)`.

### `std/physics`
2D rigid body dynamics, Hooke's law springs, and Euler velocity integrators.
- **Key Structs**: `RigidBody2D`, `Spring2D`.
- **Key Functions**: `stepPhysics(bodies, dt)`, `applyForce(body, fx, fy)`.

### `std/sim/inventory`
Generic 2D grid/bin container packing, weighted modifier table rolling, N-to-1 transformation recipe matching, and DAG prerequisite node unlocking.
- **Key Structs**: `GridItem`, `GridContainer`, `ModifierRollEntry`, `RecipeIngredient`, `TransformRecipe`, `DagPrereqNode`, `DagTree`.
- **Key Functions**: `gridContainerCreate(w, h)`, `gridContainerCanFit(container, item, targetX, targetY)`, `gridContainerPlace(container, item, targetX, targetY)`, `gridContainerRemove(container, instanceId)`, `rollWeightedModifier(entries, totalWeight, rollValue)`, `matchTransformRecipe(recipes, availableItemIds)`, `dagCanUnlockNode(dag, nodeId, unlockedNodeIds)`, `dagAllocateNodePoint(dag, nodeId, unlockedNodeIds, availablePoints)`.

### `std/sim/cellular`
Generic 2D cellular automata stepping, pairwise reaction lookup matrices, 4-neighbor Laplacian scalar field diffusion, dirty-chunk bitmask tracking, and circular stencil stamping.
- **Key Structs**: `CellularGrid2D`, `PairwiseReactionRule`, `ScalarField2D`, `DirtyChunkTracker2D`.
- **Key Functions**: `cellularStepDensitySwap(grid, x, y, belowX, belowY, densityThreshold)`, `cellularApplyPairwiseRule(rules, cellA, cellB)`, `scalarFieldStepLaplacian(field, scratch, diffRate, decayRate, dt)`, `dirtyChunkMarkRegion(tracker, minX, minY, maxX, maxY)`, `gridStampCircle(grid, cx, cy, radius, fillValue)`.

### `std/spline`
Catmull-Rom and Cubic Bezier spline interpolation.
- **Key Functions**: `sampleCatmullRom(points, t)`, `sampleBezier(p0, p1, p2, p3, t)`.

### `std/spring`
Harmonic oscillator physics for responsive UI animations.
- **Key Structs**: `SpringState`.
- **Key Functions**: `updateSpring(state, target, stiffness, damping, dt)`.

### `std/anim`
Sprite-sheet frame animation controllers, keyframe playback timelines, loop/ping-pong/one-shot modes, and 2D forward/inverse kinematics (`solveChainFK2D`, `solveTwoBoneIK2D`).
- **Key Structs**: `AnimClip`, `AnimStateMachine`, `Bone2D`.
- **Key Functions**: `animMachineNew(initialState, clips)`, `animSetState(sm, newState)`, `animStep(sm, dtMs)`, `animCurrentSpriteFrame(sm)`, `solveChainFK2D(rootX, rootY, bones)`, `solveTwoBoneIK2D(rootX, rootY, len1, len2, targetX, targetY, bendPositive)`.

### `std/tilemap`
2D orthogonal tilemap layers, ASCII level loading, kinematic `tilemapMoveAndSlide` collision, branching RPG dialogue trees, and item inventories.
- **Key Structs**: `Tilemap2D`, `DialogueChoice`, `DialogueNode`, `InventoryItem`, `Inventory`.
- **Key Functions**: `tilemapNew(width, height, tileSize, defaultTile)`, `tilemapFromAscii(rows, tileSize)`, `tilemapGet(m, col, row)`, `tilemapSet(m, col, row, tileId)`, `tilemapCheckAABB(m, x, y, w, h)`, `tilemapMoveAndSlide(m, x, y, w, h, vx, vy, dt)`, `dialogueNodeNew(id, speaker, text, choices)`, `inventoryNew(capacity)`.

### `std/transform`
Hierarchical 2D affine matrix stack and transforms.
- **Key Structs**: `MatrixStack`.
- **Key Functions**: `translate2D(tx, ty)`, `rotate2D(rad)`, `scale2D(sx, sy)`, `shear2D(shx, shy)`, `rotateAround(point, pivot, angleRad)`.

### `std/tween`
Easing curves (Linear, Quad, Cubic, Elastic, Bounce) and property tweens.
- **Key Functions**: `easeInQuad(t)`, `easeOutQuad(t)`, `easeInOutCubic(t)`, `easeOutBounce(t)`.

### `std/ui`
Immediate-mode UI panels, KPI cards, interactive buttons, tab bars, progress bars, keycap badges, split-diff headers, scope breadcrumb bars, and RevOps waterfall step bars.
- **Key Functions**: `drawPanel(x, y, w, h, bgColor, borderColor, borderThickness)`, `drawCard(x, y, w, h, title, value, subtitle, bgColor, accentColor)`, `drawBadge(text, x, y, bgColor, textColor)`, `drawButton(label, x, y, w, h, bgColor, textColor)`, `drawTabs(labels, activeIdx, x, y, tabW, tabH, activeColor, inactiveColor)`, `drawRoundRect(x, y, w, h, radius, color)`, `drawProgressBarUI(x, y, w, h, ratio, fillCol, bgCol, borderCol)`, `drawKeycapBadge(keyLabel, x, y, bgCol, textCol)`, `drawSplitHeaderBar(x, y, w, h, leftTitle, rightTitle, bgCol, borderCol, textCol)`, `drawBreadcrumbTrailBar(x, y, w, h, crumbs, bgCol, accentCol, textCol)`, `drawWaterfallStepBar(x, yTop, w, h, label, deltaText, barCol, connectorXNext, connectorY, connectorCol)`, `drawMetricPill(x, y, label, valueText, bgCol, accentCol, textCol)`.

### `std/ui/datagrid`
Generic virtualized data tables, column sorting/filtering, inline sparklines, multi-column swimlane boards, command palette fuzzy search, and multi-select state machine.
- **Key Structs**: `DataGridColumn`, `DataGridRow`, `DataGridState`, `SwimlaneCard`, `SwimlaneBoard`, `CommandPaletteItem`, `CommandPaletteState`.
- **Key Functions**: `dataGridSortRows(rows, colIdx, ascending)`, `dataGridFilterRows(rows, filterQuery)`, `dataGridRenderVisibleRows(state, rows, scrollTop, viewportHeight, rowHeight)`, `drawDataGridSparkline(values, x, y, w, h, lineColor)`, `swimlaneMoveCard(board, cardId, targetLaneId)`, `commandPaletteFuzzySearch(items, query)`.

### `std/ui/nodegraph`
Generic cubic Bezier node-graph editor, port hit-testing, topological node evaluation, split dock layout, minimap radar, and undo/redo history stack.
- **Key Structs**: `GraphPort`, `GraphNode`, `GraphConnection`, `NodeGraphState`, `DockPanelLayout`.
- **Key Functions**: `nodeGraphAddNode(state, node)`, `nodeGraphConnectPorts(state, fromNode, fromPort, toNode, toPort)`, `nodeGraphHitTestPort(state, mouseX, mouseY)`, `nodeGraphTopologicalSort(state)`, `drawCubicBezierWire(x1, y1, x2, y2, wireColor, wireThickness)`, `nodeGraphPushHistory(state)`, `nodeGraphUndo(state)`, `nodeGraphRedo(state)`.

---

## Domain 9: Systems, Linux Kernel ABI & Pure-AIPL Runtime Suite

### `std/ffi`
Dynamic foreign function interface via `dlopen`/`dlsym` for calling C libraries without static bindings.
- **Key Structs**: `FfiHandle`.
- **Key Functions**: `ffiOpen(libPath)`, `ffiHasSymbol(handle, sym)`, `ffiCallInt(handle, sym, args)`, `ffiCallFloat(handle, sym, args)`, `ffiCallStr(handle, sym, args)`, `ffiClose(handle)`.

### `std/syscall`
Direct Linux kernel ABI interface emitting raw `syscall` (or `svc #0` on ARM64) machine instructions without `libc`.
- **Key Constants**: `SYS_READ`, `SYS_WRITE`, `SYS_CLOSE`, `SYS_MMAP`, `SYS_MUNMAP`, `SYS_SOCKET`, `SYS_CLONE`, `SYS_EXECVE`, `SYS_EXIT`, `SYS_WAIT4`, `SYS_FUTEX`, `SYS_CLOCK_GETTIME`, `SYS_OPENAT`.
- **Key Functions**: `rawSyscall(nr, a1..a6)`, `syscall0(nr)`..`syscall6(nr, a1..a6)`, `sysRead(fd, buf, count)`, `sysWrite(fd, buf, count)`, `sysOpenat(dfd, path, flags, mode)`, `sysClose(fd)`, `sysMmap(addr, len, prot, flags, fd, off)`, `sysMunmap(addr, len)`, `sysExit(status)`.

### `std/rt/ptr`
Low-level memory pointer, slice, and bitcast primitives for pure-AIPL systems programming.
- **Key Structs**: `PtrSlice`.
- **Key Functions**: `ptrSliceNew(addr, len, cap)`, `ptrAlloc(size)`, `ptrFree(ptr)`, `ptrReadU8(ptr, off)`, `ptrWriteU8(ptr, off, val)`, `ptrReadI64(ptr, off)`, `ptrWriteI64(ptr, off, val)`, `sizeofType(name)`, `bitcastF64ToI64(f)`, `bitcastI64ToF64(i)`.

### `std/rt/alloc`
Task-scoped regional bump arena and free-list memory allocator ensuring zero-leak long-running game and compiler loops.
- **Key Functions**: `rtAlloc(size)`, `rtFree(ptr)`, `rtArenaPush()`, `rtArenaPop()`.

### `std/rt/string`
Zero-copy UTF-8 string slice operations, concatenation, search, and formatting.
- **Key Functions**: `rtStrFromRaw(ptr, len)`, `rtStrConcat(a, b)`, `rtStrSlice(s, start, end)`, `rtStrFind(haystack, needle)`.

### `std/rt/array`
Contiguous dynamically growable linear vector buffer implementation.
- **Key Functions**: `rtArrayNew(elemSize, cap)`, `rtArrayPush(arr, itemPtr)`, `rtArrayPop(arr)`, `rtArrayGet(arr, idx)`.

### `std/rt/map`
Open-addressed SwissTable hash map with FNV-1a hashing, replacing $O(N)$ linear scans with $O(1)$ amortized lookups.
- **Key Functions**: `rtMapNew()`, `rtMapGet(m, key)`, `rtMapSet(m, key, val)`, `rtMapDelete(m, key)`, `rtMapHas(m, key)`.

### `std/rt/json`
Pure-AIPL RFC 8259 JSON parser, serializer, and Draft 2020-12 schema validator.
- **Key Functions**: `rtJsonParse(src)`, `rtJsonStringify(val)`, `rtJsonValidateSchema(val, schema)`.

### `std/rt/crypto_compress`
Pure-AIPL implementations of cryptographic hashing (SHA-256), stream cipher (ChaCha20), checksums (CRC32), and Deflate/Gzip compression.
- **Key Functions**: `rtSha256(data)`, `rtChaCha20(key, nonce, data)`, `rtCrc32(data)`, `rtDeflate(bytes)`, `rtInflate(bytes)`.

### `std/rt/canvas_x11`
Pure-AIPL Linux X11 display server connection, event queue listener, and `XPutImage` shared framebuffer blitter.
- **Key Functions**: `rtX11OpenWindow(w, h, title)`, `rtX11BlitFramebuffer(pixels, w, h)`, `rtX11PollEvents()`.

### `std/rt/audio`
Pure-AIPL 44.1kHz 16-bit PCM RIFF audio loader, mixer, and sound output driver.
- **Key Functions**: `rtAudioInit()`, `rtAudioMixPcm(samples)`, `rtAudioLoadWav(path)`.

### `std/viewport` (Wave 10 `v0.4.0`)
Dynamic aspect-ratio preserving viewport scaling, letterbox/pillarbox bar calculation, and display-to-logical mouse coordinate unprojection.
- **Key Structs**: `AspectViewport`.
- **Key Functions**: `computeAspectViewport(winW, winH, refW, refH)`, `projectViewportX(vp, lx)`, `projectViewportY(vp, ly)`, `unprojectMouseX(vp, screenX)`, `unprojectMouseY(vp, screenY)`, `drawAspectLetterboxBars(vp, barHex)`, `drawViewportResolutionHudBadge(vp, x, y, engineTag, accentHex)`.

### `std/worldgen` (Wave 10 `v0.4.0`)
Multi-perspective 2D/3D procedural environment, block/corridor, sky/floor horizon, and weather particle generator (`perspectiveMode`: `0=TopDown2D`, `1=Iso25D`, `2=FixedCam3D`, `3=FirstPerson3D`, `4=FreeOrbit3D`).
- **Key Structs**: `CameraViewpoint`, `ProjectedVert`.
- **Key Functions**: `worldProjectPoint(cam, wx, wy, wz)`, `worldRenderSkyAndFloor(cam, skyTopHex, skyHorizonHex, floorNearHex, floorFarHex, gridHex)`, `worldRenderBlock3D(cam, bx, by, bz, bw, bd, bh, topHex, leftHex, rightHex)`, `worldRenderWeatherParticles(cam, weatherKind, density, tick, tintHex)`, `worldRenderCorridorSegment(cam, zStart, zEnd, halfW, ceilH, wallHex, trimHex, torchFlicker)`.

### `std/charbody` (Wave 10 `v0.4.0`)
Procedural multi-perspective articulated 14-joint humanoid character rig, pose solver, and layered equipment renderer (`archetype`: `0=TacticalOperator`, `1=SurvivalOperative`, `2=HeroicPaladin`, `3=DarkKnight`, `4=HazmatScientist`).
- **Key Structs**: `CharBodySpec`, `BodyJoint2D`.
- **Key Functions**: `solveHumanoidJoints(spec)`, `drawCharacterBody(spec)`, `drawCharacterInspectorPreview(x, y, w, h, spec, title)`.

### `std/canvas` (`std/gfx2d/shape2d.aipl`) Dual Window Modes, Analytical Scanline Spans & Hardware Audio
- **Dual Window Modes**: `setWindowMode("x11" | "glx" | "auto")` and `getWindowMode(): str` (plus `--window-mode=x11|glx|auto`, `--x11`, `--gl`, `--software`, and `AIPL_WINDOW_MODE`) select between Mode 1 (`"x11"` / `"app"`: zero-copy X11 + MIT-SHM `XShmPutImage` 32-bit BGRA desktop app backend, `examples/ex_251`–`ex_252`) and Mode 2 (`"glx"` / `"game"`: X11 + `libGL.so.1` GLX hardware vertex batching via `glDrawArrays` and `glXSwapBuffers`, `examples/ex_253`–`ex_255`).
- **Multi-Backend Polyphonic Hardware Audio (`std/audio/audio_device.aipl`, `runtime/rt_gui_audio.c`)**: Bridges `playToneEx`, `playNote`, `playChord`, `playPcmBuffer`, and `sysAudioWriteFrames` to the C runtime 32-voice synthesizer (`PulseAudio` -> `ALSA` -> `SDL2`) with exponential ADSR, 1-pole LPF warmth filtering, 9 timbres, stereo chorus, and `tanh` limiting (`examples/ex_256`–`ex_258`).
- **Configurable Frame Pacing & Telemetry**: `setMaxFps(fps)` (`0` = uncapped; also supports `--MaxFps=<N>` CLI flag and `AIPL_MAX_FPS=<N>` env var), `getMaxFps()`, `getCurrentFps()`, `getFrameTimeMs()`, plus `--BenchmarkWindowFps` CLI flag (runs 5 warmup + 120 timed full-resolution every-frame presented window-mode frames and enforces `>= 120.0 FPS`).
- **Wave 10 High-Precision Primitives**: `drawSubpixelAASpan(x, y, w, h, coverage, fgHex, bgHex)`, `drawParticleRibbonTrail(x0, y0, x1, y1, widthStart, widthEnd, colorHex)`.

### `std/navgrid` & Wave 11 (`v0.4.0`) Multi-Genre Game/App Additions
- **`std/navgrid`**: `NavWaypoint`, `GravitySource`, `navHeuristicOctile(x0, y0, x1, y1)`, `navStepTowardTarget(x0, y0, x1, y1)`, `navBresenhamLineOfSight(x0, y0, x1, y1, blockedX, blockedY)`, `navComputeBhopVelocity(curSpeed, wishSpeed, airAccel, dt, onGround, jumpQueued)`, `navComputeGravityAccel(px, py, wellX, wellY, mass, gConst)`, `navStepGameOfLifeCell(alive, neighbors, ruleMaskB, ruleMaskS)`, `drawNavRadarMinimap(rx, ry, rw, rh, playerX, playerY, worldW, worldH, targetX, targetY, colHex)`, `drawPerspectiveHorizonGrid(rx, ry, rw, rh, vpX, vpY, rays, colHex)`.
- **Upgraded `std/worldgen`, `std/charbody`, `std/viewport`, `std/particles`, `std/game`, `std/ui`**: `worldRenderTurntablePedestal3D`, `worldRenderGravityWellRings`, `drawCharacterWeaponViewmodel3D`, `drawCharacterOnionSkinGhost`, `viewportClampScrollOffset`, `drawViewportMinimapFrame`, `particleComputeRadialAttractorDv`, `drawParticleVelocityVectors`, `gameComputeMagicFindEffective`, `gameComputeMonteCarloPercentile`, `drawCallStackStripUI`, `drawOnionSkinTimelineBarUI`.

### `std/physics2d3d` & Wave 12 (`v0.4.0`) Multi-Genre Kinematics, Normal Map & Game/App Additions
- **`std/physics2d3d`**: `RigidBody3D`, `AABBBox3D`, `physIntegrateSymplecticEuler(px, py, vx, vy, ax, ay, damping, dt)`, `physCheckAabbOverlap2D(ax, ay, aw, ah, bx, by, bw, bh)`, `physCheckAabbOverlap3D(a, b)`, `physCheckSphereOverlap3D(x0, y0, z0, r0, x1, y1, z1, r1)`, `physResolveElasticImpulse1D(v1, m1, v2, m2, restitution)`, `physSpringDamperForce(pos, target, vel, stiffness, damping)`, `physComputeSobelNormalRGB(hLeft, hRight, hUp, hDown, strength)`, `physToroidalWrapCoord(coord, span)`, `drawPhysVelocityVectorArrow(x, y, vx, vy, scale, color)`.
- **Upgraded `std/worldgen`, `std/charbody`, `std/viewport`, `std/particles`, `std/navgrid`, `std/game`, `std/ui`**: `worldRenderNormalMapReliefQuad`, `worldRenderToroidalWrapGrid`, `computeWeaponSilencerSpreadMod`, `drawCharacterWeaponSilencerAttachment`, `viewportWrapToroidalPoint`, `drawViewportQuadrantGrid`, `drawSoapPolymerLinkNetwork`, `drawBleedHemorrhageBurst`, `navIsWithinLeashRadius`, `drawNavLeashRadiusRing`, `computeCrushingBlowDamage`, `computeDeadlyStrikeDamage`, `computeOpenWoundsBleedPerSec`, `computeSm2NextEasiness`, `computeSm2NextIntervalDays`, `drawNetGraphPacketBar`, `drawSm2FlashcardMasteryBar`.

### `std/iso` Multi-Perspective Tilemap, Hex Axial & Heightfield Extensions (`v0.4.0`–`v0.8.0`)
- **`std/iso` (Consolidated 2.5D Isometric, Axial Hex & Heightfield Module)**: `IsoCamera25D`, `HexCoordAxial`, `tileWorldToIsoScreenX(wx, wy, wz, tileW, tileH, originX)`, `tileWorldToIsoScreenY(wx, wy, wz, tileW, tileH, heightScale, originY)`, `tileIsoScreenToWorldX(sx, sy, tileW, tileH, originX, originY)`, `tileIsoScreenToWorldY(sx, sy, tileW, tileH, originX, originY)`, `tileHexAxialToPixelX(q, r, hexRadius, originX)`, `tileHexAxialToPixelY(q, r, hexRadius, originY)`, `tileHexAxialDistance(q1, r1, q2, r2)`, `tileIsChunkInViewportFrustum(chunkMinX, chunkMinY, chunkMaxX, chunkMaxY, viewX, viewY, viewW, viewH, marginPx)`, `tileBilinearHeightSample(h00, h10, h01, h11, fracX, fracY)`, `tileComputeLightRadiusFogAlpha`, `tileComputePortalTeleportX`, `tileComputePortalTeleportY`, `tileComputePortalFormationSlotX`, `tileComputePortalFormationSlotY`, `tileComputePortalVortexX`, `tileComputePortalVortexY`, `drawTileIsoDiamondWireframe(cx, cy, tileW, tileH, r, g, b, a)`, `drawTileHeightfieldPrism25D(cx, cy, tileW, tileH, extrudeH, r, g, b, a)`.
- **Upgraded `std/physics2d3d`, `std/navgrid`, `std/charbody`, `std/worldgen`, `std/viewport`, `std/ui`**: `physComputeGravFieldInverseSq`, `physReflectVelocityWall2D`, `navComputeUpkeepTaxPct`, `navStepCellularPipeTransfer`, `rollItemAffixBonus`, `charStepMercenaryFollowAI`, `worldComputeBreakableShardTrajectory`, `viewportPanZoomBoardToScreenX`, `viewportPanZoomBoardToScreenY`, `uiComputeLiquifyPushOffset`.

### `std/lighting` & `std/skeletal` (`v0.4.0`–`v0.8.0`) Dynamic Lighting, Shadow Raycaster & Skeletal IK Modules
- **`std/lighting`**: `LightSource3D`, `lightComputePointAttenuation(distSq, radius, intensity, falloffExp)`, `lightComputeLambertDiffuseRGB(nx, ny, nz, lx, ly, lz, baseR, baseG, baseB, lightR, lightG, lightB, ambientPct)`, `lightCast2DShadowVisibility(ox, oy, tx, ty, blockerMinX, blockerMinY, blockerMaxX, blockerMaxY)`, `lightComputeSpotConeAttenuation`, `lightComputeLightningFlashAmbientBoost`, `lightComputeNvgPhosphorGain`.
- **`std/skeletal`**: `BoneJoint2D3D`, `skelForwardKinematics2D_X(parentX, boneLength, worldAngleDeg)`, `skelForwardKinematics2D_Y(parentY, boneLength, worldAngleDeg)`, `skelSolveTwoBoneIKAngleDeg(rootX, rootY, targetX, targetY, len1, len2)`, `skelInterpolateKeyframeHermite(v0, m0, v1, m1, t01)`, `drawSkelArticulatedBiped2D(cx, cy, scale, walkPhaseRad, r, g, b, a)`.
- **Upgraded `std/physics2d3d`, `std/navgrid`, `std/charbody`, `std/worldgen`, `std/viewport`, `std/ui`**: `physBitwisePhotonFilter30Bit`, `navComputeNavMeshAreaCost`, `charComputeSunderCharmResist`, `worldEvaluateChemicalMixStoichiometry`, `viewportComputeReplayTimelineScrubTick`, `uiComputeChannelMixerChannel`.

### `std/spatial_audio` & `std/particles` (`v0.4.0`–`v0.8.0`) Spatial Acoustics, Doppler Shift, Room Reverb & Particle Ribbon FX
- **`std/spatial_audio`**: `SoundEmitter3D`, `audioComputeDistanceGain(srcX, srcY, srcZ, lisX, lisY, lisZ, minDist, maxDist)`, `audioComputeStereoPan2D(srcX, srcY, lisX, lisY, lisYawRad, maxPanDist)`, `audioComputeDopplerPitchMultiplier(srcX, srcY, srcVx, srcVy, lisX, lisY, lisVx, lisVy, speedOfSound)`, `audioComputeWallOcclusionLowpass(wallHits, baseCutoffHz, attenuationPerWall)`, `audioComputeReverbDecayGain(elapsedMs, rt60Ms, wetMix)`, `audioComputeThunderDelaySeconds`, `audioComputeC4BeepIntervalMs`, `drawFxSpatialSoundWaveRings2D(cx, cy, baseRadius, ringCount, phaseZeroToOne, colorHex, alpha)`.
- **`std/particles` (Ribbon Trail Extensions)**: `ParticleRibbonNode2D`, `fxUpdateParticleTrailNodeX(prevX, targetX, followFactor)`, `fxUpdateParticleTrailNodeY(prevY, targetY, followFactor)`, `drawFxRibbonSegment2D(x0, y0, x1, y1, thickness, coreHex, glowHex)`.
- **Upgraded `std/physics2d3d`, `std/navgrid`, `std/charbody`, `std/viewport`, `std/ui`**: `physComputeAcousticWaveNext`, `navComputeSoundPropagateRadius`, `charComputeAttackFrameBreakpoint`, `viewportComputePipInsetRectX`, `viewportComputePipInsetRectY`, `uiComputeMandalaSymmetryPointX`, `uiComputeMandalaSymmetryPointY`.

### `std/weather` & `std/viewport` (`v0.4.0`–`v0.8.0`) Procedural Weather, Fractal Lightning Step-Leader, Value/fBm Noise, Perspective Guides & Liquify Mesh Warp
- **`std/weather`**: `WeatherState3D`, `weatherComputeRainWindDriftX(baseX, fallY, windVelX, fallSpeed)`, `weatherComputeSnowTurbulenceOffset(tick, particleId, amplitude)`, `weatherStepFractalLightningMidpointX(x1, x2, jitterSpan, seed)`, `weatherStepFractalLightningMidpointY(y1, y2, jitterSpan, seed)`, `procgenValueNoise2D(gridX, gridY, seed)`, `procgenFbmTerrainHeight(x, y, octaves, seed)`, `procgenJitterSketchCoord(coord, seed, roughness)`, `drawFxFractalLightningBolt2D(x1, y1, x2, y2, branches, colorHex)`, `drawFxWeatherPrecipitationOverlay2D(viewX, viewY, viewW, viewH, tick, precipType, windVelX)`.
- **`std/viewport` (Perspective & Liquify Warp Extensions)**: `VanishingPointGuide2D`, `perspProjectToVanishingPointX(cursorX, cursorY, vpX, vpY, tFactor)`, `perspProjectToVanishingPointY(cursorX, cursorY, vpX, vpY, tFactor)`, `warpComputeLiquifyRadialDisplaceX(px, py, brushX, brushY, radius, pushDx)`, `warpComputeLiquifyRadialDisplaceY(px, py, brushX, brushY, radius, pushDy)`, `viewportSnapCursorToPerspectiveRayX`, `viewportSnapCursorToPerspectiveRayY`, `viewportComputeHistogramBinHeight`.
- **Upgraded `std/physics2d3d`, `std/navgrid`, `std/charbody`**: `physComputeBallisticShieldReflectAngleDeg`, `navStepRayLogicGatePropagation`, `computeLinearScaledCost`, `recipeOutputLevel`.

### `std/lut`, `std/gravity` & `std/analytics` (`v0.4.0`–`v0.8.0`) 3D Color Grading LUT, N-Body Point-Mass Gravity Well & Revenue Accelerator Modules
- **`std/lut`**: `ColorGradeLut3D`, `lutEvalCubicCurveChannel(val255, shadowLift, midtoneBias, highlightGainPct)`, `lutApplyLevelsGammaChannel(val255, inBlack, inWhite, outBlack, outWhite)`, `lutMapGradientStopColor(luma255, lowHex, midHex, highHex)`, `drawFxNightVisionPhosphorScanlines2D(viewX, viewY, viewW, viewH, tick, phosphorHex)`.
- **`std/gravity`**: `GravityWellNode2D`, `gravComputePointWellAccelX(px, py, wellX, wellY, massG, softeningSq)`, `gravComputePointWellAccelY(px, py, wellX, wellY, massG, softeningSq)`, `gravComputeRadialBlastFalloff(baseDamage, distUnits, maxRadiusUnits)`, `drawFxGravityWellFieldLines2D(cx, cy, radius, rings, colorHex)`.
- **`std/analytics`**: `commComputeTieredAcceleratorPayout(attainmentPct, baseCommission, tier1MultPct, tier2MultPct)`.
- **Upgraded `std/physics2d3d`, `std/charbody`**: `physEvaluateSensorThresholdGate(measuredVal, thresholdVal, invertMode)`, `inventorySlotCanAccept(itemCategory, ilvl, itemQuality)`, `charComputeUltimateLv6CooldownSec(heroClassId, cdrPct)`.

---

## Domain 10: Time, Testing & SemVer

### `std/cron`
Cron expression parser and next-execution timestamp calculator.
- **Key Structs**: `CronSchedule`.
- **Key Functions**: `parseCron(expr)`, `nextCronExecution(schedule, fromMs)`.

### `std/date`
Calendar date arithmetic (`Date`: year, month, day, leap years, epoch days, and day-of-week).
- **Key Structs**: `Date`.
- **Key Functions**: `makeDate(y, m, d)`, `isLeapYear(year)`, `daysInMonth(year, month)`, `dateToEpochDays(d)`, `epochDaysToDate(days)`, `dateAddDays(date, n)`, `dateDiffDays(d1, d2)`, `dateDayOfWeek(d)`.

### `std/datetime`
Civil timestamps (`DateTime`, `CivilDateTime`), Hinnant Unix epoch conversion, timezone offsets, ISO-8601 and RFC-2822/822 parsing/formatting, and duration formatting.
- **Key Structs**: `DateTime`, `CivilDateTime`.
- **Key Functions**: `now()`, `unixToCivil(epochSec)`, `civilToUnix(dt)`, `formatIso8601(dt)`, `parseIso8601(s)`, `formatRfc822(dt)`, `parseRfc2822(s)`, `formatDurationHhMmSsMs(totalMs)`.

### `std/semver`
Semantic Versioning (SemVer 2.0.0) parsing, comparison, and constraint checking.
- **Key Structs**: `SemVer`.
- **Key Functions**: `parseSemver(s)`, `semverCompare(v1, v2)`, `semverSatisfies(v, range)`.

### `std/test`
Test runner framework, assertions, and property-based test generator with shrinking.
- **Key Structs**: `TestSuite`, `TestResult`.
- **Key Functions**: `suite(name)`, `assert(cond, msg)`, `assertEqual[T](a, b, msg)`, `assertTrue(cond, msg)`, `propTest(name, runnerFn)`.

### `std/time`
High-resolution monotonic timer and sleep delays.
- **Key Functions**: `nowMs()`, `nowMicroseconds()`, `sleepMs(ms)`.

---

## Deep Research Audit & Wave Remediation Additions (Reports 01–11)

### Report 01: `std/ui/{color,lut,theme,layout,aura}` (AuraDesign v7.0)
- **Perceptual Color Science (`std/color`, `std/lut`, `std/theme`)**: `OklabColor`, `OklchColor`, `rgbToOklab`, `oklabToRgb`, `rgbToOklch`, `oklchToRgb`, `oklchToRgbGamutMapped`, `lerpOklabHex`, `apcaContrastLc`, `apcaSelectAccessibleForeground`, `generateRadixScale12`, `lutCreateIdentity3D`, `lutSampleTrilinear`, `generateSemanticThemeFromHue`.
- **Two-Pass Flexbox & Clay Layout (`std/layout`, `std/aura`)**: `FlexChildSpec`, `computeFlexRowTwoPass`, `computeGridTrackPositions`, `computeResponsiveColumns`, `AuraIdStack`, `auraIdHash`, `auraTreeBuildFlatOrder`, `auraVirtualRangeCompute`, `auraDockSplitNode`, `auraAnimateTowards`.

### Reports 02 & 03: `std/gfx2d/{canvas,geom2d,sprite,particles2d,particles,fx,filter2d,spline,easing,tween,anim,image,iso,tilemap}`
- **2D Rendering, Geometry & FX**: `Mat2D`, `mat2dIdentity`, `mat2dMultiply`, `mat2dTransformX`, `mat2dTransformY`, `blendPorterDuffSrcOver`, `polygonTriangulateEarClip`, `polylineStrokeExpand`, `rectNineSliceCompute`, `packSpritesMaxRects`, `verletRopeCreate2D`, `verletRopeStep2D`, `fxBloomSeparable1D`, `filter2dOrderedDitherBayer4x4`, `splineBuildArcLengthLut`, `splineSampleUniformArcLength`.
- **Easings, Tweens, Image & Isometric**: Complete 30-curve Robert Penner easing suite (`evalEase`), `TweenSequence` (`tweenSequenceNew`, `stepTweenSequence`), `AnimBlend1D`, `AnimStateMachine`, `imageScaleBicubic`, `imageConvolve3x3`, `isoDepthSortPainter`, `tilemapLoadTiledJson`, `tilemapAutoTileBitmask4`, `tilemapAutoTileBitmask8`, `tilemapBuildCollisionPolys`.

### Report 04: `std/gfx3d/{geom3d,camera3d,transform,mesh3d,material3d,lighting,skeletal,gpu}`
- **3D Math, PBR, Shadows, Dual Quaternions & RenderGraph**: `Vec4`, `Mat3`, `Capsule3D`, `capsuleIntersectsAABB`, `quatFromAxisAngle`, `quatRotateVec3`, `quatSlerp`, `extractFrustumPlanes`, `computeNormalMatrix9`, `computeMeshTangents`, `generateMeshLod`, `evalCookTorrancePbrRGB`, `computeCascadedShadowSplits`, `sampleShadowPcf3x3`, `DualQuat`, `dualQuatSkinPoint`, `solveFabrikChain3D`, `RenderGraph`, `compileRenderGraph`.

### Reports 05 & 06: `std/sim/{spring,ecs,nav,game,procgen,gravity,hebar,physics,physics2d3d,charbody,grid,pathfinding,navgrid}`
- **Simulation, Archetype ECS, Physics & Navigation**: Exact analytical RK4/damped-harmonic spring (`springStepExact`), Archetype SoA ECS (`EcsArchetypeWorld`, `ecsWorldSaveJson`), ORCA reciprocal velocity obstacles (`orcaComputeSafeVelocity2D`), Utility AI (`utilitySelectBestAction`), GOAP planner (`goapPlanBfs`), `SimplexNoise2D3D`, `WaveFunctionCollapse2D`, `BarnesHutQuadtree2D`, Padé symplectic damping (`physIntegrateSymplecticEulerPade`), Box2D v3 soft constraints (`solveContactPGS2D`), `BvhTree3D`, `charMoveAndSlide2D`, `ChunkedAutomataGrid2D`, Harabor & Grastien Jump Point Search (`gridJumpPointSearch`), and 3-layer `FlowField2D` (`navBuildFlowField2D`).

### Report 07: `std/audio/{synth,audio,spatial_audio}`
- **Studio Synthesis & DSP**: `midiNoteToFreqHz`, `polyBlep`, `oscSamplePolyBlep`, Kellet 7-state `PinkNoiseState`, `AhdsrEnvelope`, 4-Operator FM (`renderFm4OpNote`), Karplus-Strong (`renderKarplusStrong`), 20-parameter ZzFX/sfxr (`SfxPatch`, `renderSfxPatch`), Andrew Simper Cytomic ZDF SVF (`CytomicSvf`, `fxApplySvf`), 6-stage `fxApplyPhaser`, Schroeder-Moorer `fxApplyFreeverb`, `fxApplyCompressor`, Bjorklund `euclideanRhythm`, and 3D listener basis (`computeSpatialAudioListener3D`, `applySpatialAudioDsp3D`).

### Report 08: `std/core/{math,sort,random,pool,test}`, `std/data/{regex,qrcode,crypto}`, `std/net/{http,url,websocket}`
- **Core Math, Data & Net**: Constant-time range-reduced `sin`/`cos`/`atan`/`asin`/`acos`, fractional float `pow`, prescaled `sqrtSafePrescaled`, $O(N \log N)$ `summaryStats`, zero-clone `sortInts`/`sortFloats`/`sortStrings`, `sortIntsRadix`, SplitMix64/PCG32 PRNG, generational `PoolHandle`, Thompson NFA linear-time regex (`regexMatchLinearNfa`), GF(256) Reed-Solomon QR code (`qrComputeReedSolomonEcc`), bitwise constant-time crypto comparison, and strict HTTPS verification (`httpsGetStrict`).

### Reports 09, 10 & 11: Compiler (`compiler/*`) & Hebar Bot (`aipl_hebar_bot/*`)
- **Compiler & Formal Verification**: Recursive generic type argument soundness across `Array[T]`, `Map[K, V]`, `Set[T]`, `Option[T]`, and `Result[T, E]`; C99 dead `return aipl_nil()` elimination; WASM 64-bit SLEB128 and struct/array/index emission; C99 & TypeScript runtime contract assertion emission for `requires`, `ensures`, `invariant`, and `decreases`; tri-state SMT classification (`STATUS_PROVEN_STATIC`, `STATUS_REFUTED_STATIC`, `STATUS_UNKNOWN_DYNAMIC`); and configurable `HebarDomainProfile` (`resolveHebarDomainProfile`) in `aipl_hebar_bot`.

### Loop 1 & Loop 2 Language & Stdlib Evolution (`v0.5.0` — Fresh-Write Benchmark Suite)
- **Coalescing & Membership Operators**: `a ?? b` (`Option[T]` / `Result[T, E]` / `nil` unwrap-or coalescing) and `elem in collection` (membership check on `Array`, `Map`, `Set`, and `str`).
- **Optional Type Annotations & Auto-Prelude**: Optional parameter, return, and compact struct-field type annotations (`struct Point(x, y)`, `fn add(a, b) = a + b`); automatic prelude imports for `std.cli` (`parseCliArgs`), `std.grid` (`gridNew`, `gridSet`, `grid2dNew`, `grid2dSet`), and `std.pathfinding` (`gridAStar`).
- **High-Density Collection & String Combinators**: `.sum()`, `.sum(|x| ...)`, `.min()`, `.max()`, `.ints()`, `.floats()`, `.first`, `.last`, `.peek`, `.count(|x| ...)`, `.retain(|x| ...)`, `.sortBy(|x| [k1, k2])` (lexicographical array comparison), structural `Array` equality (`arr1 == arr2`), `int + bool` / `int += bool` branchless accumulation, and string-key indexing on structs (`parsed["name"]`).

### Standard Library Evolution & Generic Modules (`v0.8.0`)
- **`std/sim/inventory.aipl`**: Generic 2D grid/bin container packing (`gridContainerCreate`, `gridContainerCanFit`, `gridContainerPlace`, `gridContainerRemove`), weighted modifier/attribute table rolling (`rollWeightedModifier`), N-to-1 transformation recipe matching (`matchTransformRecipe`), and DAG prerequisite node unlocking (`dagCanUnlockNode`, `dagAllocateNodePoint`).
- **`std/sim/cellular.aipl`**: Generic 2D cellular automata stepping (`cellularStepDensitySwap`), pairwise reaction lookup matrix (`cellularApplyPairwiseRule`), 4-neighbor Laplacian scalar field diffusion (`scalarFieldStepLaplacian`), dirty-chunk bitmask tracking (`dirtyChunkMarkRegion`), and circular stencil stamping (`gridStampCircle`).
- **`std/ui/datagrid.aipl`**: Generic virtualized data tables, column sorting/filtering, inline sparklines, multi-column swimlane boards, command palette fuzzy search, and multi-select state machine.
- **`std/ui/nodegraph.aipl`**: Generic cubic Bezier node-graph editor, port hit-testing, topological node evaluation, split dock layout, minimap radar, and undo/redo history stack.
- **Wave 8 Receiver Inference, Indexed Collection Dispatch & Zero-Allocation Serde (`std/serde/mod.aipl`)**:
  - **Compiler Receiver Type Propagation**: Unannotated local variables (`let x = obj.update()`), factory functions (`let sb = createScoreboard()`), variable aliases/reassignments (`mut bSim = b; bSim = bSim.update()`), nested block scopes, and `for` loop element bindings (`for it in items: it.method()`) preserve struct receiver types across method chains.
  - **Direct Indexed Collection Receiver Dispatch**: `items[i].method()`, `state.players[i].get()`, and `makeList()[0].method()` resolve element struct types directly in HIR and C99 codegen.
  - **Zero-Allocation Slice-Scanning Serde (`std/serde/mod`)**: `fastJsonGetInt(jsonText: str, key: str, fallback: int): int`, `fastJsonGetFloat(jsonText: str, key: str, fallback: float): float`, `fastJsonGetStr(jsonText: str, key: str, fallback: str): str`, `fastJsonGetIntArray(jsonText: str, key: str): [int]`, and `fastIniGetValue(src: str, section: str, key: str, defaultVal: str): str`.
- **Wave 9 & Wave 10 Serde, Spatial, 3D Math, Time & Graph Primitives**: `formatDurationHMS(totalSeconds)`, `formatDurationMS(totalSeconds)` (`std/time`), `padLeft(s, len, pad)`, `padRight(s, len, pad)`, `formatIntPadded(val, width)` (`std/string`), `jsonFieldInt`, `jsonFieldFloat`, `jsonFieldStr`, `jsonFieldBool`, `jsonObject2`..`jsonObject8`, `jsonObjectFields(fields)`, `jsonArrayFields(items)` (`std/serde/mod` & `std/json`), `gridFillDisk(grid, w, h, cx, cy, radius, val)`, `gridQueryDisk(w, h, cx, cy, radius)`, `grid2dFillDisk(g, cx, cy, radius, val)` (`std/grid`), `vec3DistanceSquared(a, b)`, `vec3Lerp(a, b, t)` (`std/geom3d` & `std/math/mod`), `worldToDisc2D(origin2D, target2D, headingRad, discCenter, discRadius, maxRange)` (`std/geom2d`), and `intGraphShortestPath(nodeCount, edgeFrom, edgeTo, startNode, goalNode)` (`std/pathfinding`).
- **Continuous 2.5D/3D World Engine (`std/gfx25d/*`), Hardware/Software Z-Buffer, Blend Modes & 5-Bound HEBAR Referee (`std/hebar/referee`)**:
  - **`std/gfx25d/camera25d.aipl`**: `AABB2D`, `Camera25D`, `createCamera25D(viewportW, viewportH, zoom, yawDeg, pitchDeg)`, invertible `project3DToIso(cam, wx, wy, wz) -> Vec3` and `unprojectIsoTo3D(cam, sx, sy, planeWz) -> Vec3`, elevation-aware frustum culling `getVisibleWorldAABB(cam, minElevation, maxElevation)`, and smooth height tracking `updateCamera25D(cam, targetWx, targetWy, terrainWz, dt)`.
  - **`std/gfx25d/mesh25d.aipl` & `std/gfx25d/ribbon25d.aipl`**: `Vertex25D`, `IndexedMesh25D`, `Vertex25DTextured`, `IndexedMesh25DTextured`, `shadeVertex25D`, `drawHeightfieldPatch25D`, `drawHeightfieldPatchTextured25D`, `drawHeightfieldSplat25D`, `drawGroundDecal25D`, `drawIndexedMesh25D`, `drawIndexedMeshTextured25D`, `drawPrism25D`, `drawPrismTextured25D`, `drawCone25D`, `drawBillboard25D`, `RibbonVertex25D`, `extrudeSplineRibbon25D`, `drawSplineRibbon25D`, and `drawSplineRibbonTextured25D`.
  - **`std/gfx25d/light25d.aipl`, `std/gfx25d/sprite25d.aipl` & `std/gfx25d/weather25d.aipl`**: `PointLight25D`, `createPointLight25D`, `drawAmbientDarknessPass25D`, `drawLightCookie25D`, `renderLightingPass25D`, `IsoSpriteRig25D`, `direction8FromVelocity`, `createIsoSpriteRig25D`, `updateIsoSpriteRig25D`, `drawContactShadow25D`, `drawIsoSpriteRig25D`, `drawBillboardCutout25D`, `WeatherParticle25D`, `WeatherEmitter25D`, `createWeather25D`, `stepWeather25D`, `drawMistPlanes25D`, and `drawWeatherParticles25D`.
  - **Runtime Z-Buffer, Blend Modes, Alpha-Tested Depth Cutouts, Gouraud Shading, UV Texture Mapping & World-Pass Telemetry Guard (`std/gfx2d/shape2d.aipl`)**: `setDepthTest(enabled)`, `clearDepth()`, `setBlendMode(mode)`, `getBlendMode()`, `blendModeAlpha()`, `blendModeAdditive()`, `blendModeMultiplied()`, `blendModeScreen()`, `beginWorldPass()`, `endWorldPass()`, `setUiTracking(enabled)`, `drawTriangleGouraud`, `drawTriangle3DGouraud`, `drawQuad3DGouraud`, `drawTriangle3DTextured`, `drawQuad3DTextured`, `createTextureFromRgba`, `createProceduralTexture` (`"grass"`, `"rock"`, `"cliff"`, `"dirt"`, `"cobble"`, `"water"`, `"wood"`, `"bark"`, `"foliage"`, `"brick"`, `"roof"`, `"sand"`, `"snow"`, `"light_cookie"`, `"radial_light"`, `"mist"`, `"fog"`, `"palisade"`, `"spiked_log"`), `createIsometricSpriteSheet` (`"hero_knight"`, `"paladin"`, `"rogue"`, `"skeleton"`, `"demon"`, `"campfire"`, `"gothic_tree"`, `"dead_tree"`), and `saveTextureToPpm` (plus X11 compositor alpha-channel lock `glColorMask(1,1,1,0)`, GLX `saveScreenshot` VRAM readback, and smart window clamping/auto-tiling; showcased in `ex_259`, `ex_260`, `ex_261`, `ex_262`, and `ex_263`).
  - **Postfix Struct Update & Deep Struct Cloning (`std/prelude.aipl`)**: `orig { field = val }` functional struct update syntax and `cloneStruct(s)`.
  - **5-Bound HEBAR Referee (`std/ai/hebar_referee.aipl` & `std/hebar/referee.aipl`)**: `hebarStepCursorTrajectory` ($\le 780\text{ px/s}$), `hebarClampAngularSlew` ($\le 2\pi\text{ rad/s}$), `hebarVerifyZeroTampering`, `connectTargetWindow(titleOrPid, timeoutMs)`, `renderHebarRefereeDashboard`, and `exportHebarTelemetryJson`.

---

## See Also
- [AIPL Tutorial](docs/TUTORIAL.md)
- [AIPL Recipes Cookbook](docs/COOKBOOK.md)
- [AIPL CLI Reference](docs/CLI_REFERENCE.md)

