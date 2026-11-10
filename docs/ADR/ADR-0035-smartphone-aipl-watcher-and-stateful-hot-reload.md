# ADR-0035: Smartphone AIPL Watcher, Embedded Offline VFS & Stateful Hot-Reload

## Status
Accepted

## Date
2026-11-08

## Deciders
AIPL Mobile Architecture & Systems Team

## Context
Mobile application and game development on Android devices presents unique ergonomics and architectural constraints:
1. **Offline Android Execution**: Smartphones frequently operate in offline, airplane-mode, or restricted sandbox environments. The full AIPL standard library (281 canonical modules across 36 domain groups) must be immediately resolvable without network access or access to host development paths (`/usr`, `/home`, etc.).
2. **Storage Access Framework (SAF) & FileObserver Nuances**: Android editors and IDEs (e.g., Acode, Spck, Termux) modify files using atomic temp-rename sequences, triggering erratic clusters of Linux inotify / `FileObserver` events (`CLOSE_WRITE`, `MOVED_TO`, `ATTRIB`). Without debouncing and cryptographic SHA-256 verification, saving a file can trigger duplicate or corrupt intermediate compilations.
3. **State Loss on Reload**: In interactive simulations, games, and UI workflows, restarting the application from scratch resets user progress, entity positions, player score, and frame counters. A true mobile live-programming experience requires stateful hot-reload.
4. **Syntax Error Resilience**: When typing code directly on virtual smartphone keyboards, syntax errors and incomplete tokens are commonplace. A compiler syntax error must never crash the running application process or tear down the OpenGL/Vulkan rendering surface.

To solve these constraints, AIPL introduces the **Smartphone AIPL Watcher & Live-Reload Player Architecture**.

---

## Decision Drivers
- **Offline Virtual File System (`AndroidStdlibVfs`)**: Embed all 281 canonical standard library modules (251 implementation modules + 30 barrel modules) inside Android APK `assets/std.vfs` with magic `"AIPLVFS1"`, version `1`, and 36 domain groups. Fast O(1) resolution via normalized path keys (`std/<domain>/<module>.aipl`) and FNV-1a 64-bit hashing.
- **Mobile Watcher Engine (`MobileAiplWatcher`)**: A hybrid watcher combining Android `FileObserver` mask filtering (`CLOSE_WRITE = 8`, `MOVED_TO = 128`), SAF `content://` document URI support, SHA-256 content-hash verification, and a 50ms debounce window.
- **Sub-15ms Wi-Fi/LAN Live-Reload Sync (`NetLiveReloadSync`)**: Zero-config LAN synchronization supporting UDP discovery beacons (`AIPL_WATCHER_BEACON|<deviceName>|<wsPort>|v1`) and framed delta updates (`AIPLSYNC|v1|<seq>|<filePath>|<expectedCrc32>|<payload>`) validated with CRC32.
- **Stateful VM Bytecode Hot-Swap (`__AIPL_STATE__`)**: Pre-reload variable snapshot (`snapshotVmGlobalState`), schema-merging state restoration (`restoreVmGlobalState`) preserving existing variable values while adopting newly declared defaults, and atomic bytecode replacement (`hotSwapBytecodeModule`) guarded by rollback on compile error.
- **On-Screen Mobile Watcher HUD (`WatcherHudState`)**: A non-intrusive mobile overlay with Fitts's Law compliant 48dp minimum hitboxes (`createWatcherHudState`), live status pill (`renderWatcherOverlayPill`), structured diagnostic error toasts (`renderWatcherDiagnosticToast`), and slide-out script selector drawer (`toggleWatcherFileDrawer`).

---

## Considered Options

### Option 1: Full Activity Re-creation (`Activity.recreate()`)
Tear down the Android `NativeActivity` and re-execute the target `.aipl` script on file save.
- *Pros*: Simple to implement; clears all native memory.
- *Cons*: **Rejected**. Takes 300–800ms, flickers black screen, loses OpenGL/Vulkan surface context, and destroys all runtime state.

### Option 2: Stateless In-Memory Bytecode Reload
Recompile bytecode and reset the virtual machine global environment to tick 0.
- *Pros*: Faster than restarting the OS process (~30ms).
- *Cons*: **Rejected**. Resets game state, scores, and camera positions; breaks interactive game development flow on smartphones.

### Option 3: Stateful Hot-Reload with Embedded Offline VFS, SHA-256 Watcher, and Rollback Protection
Implement deep memory state snapshots (`snapshotVmGlobalState`), schema merge rules (`restoreVmGlobalState`), atomic generation increments (`hotSwapBytecodeModule`), debounced SHA-256 change detection (`MobileAiplWatcher`), and embedded offline standard library VFS (`AndroidStdlibVfs`).
- *Pros*: **Accepted**. Delivers sub-15ms updates, preserves user state seamlessly across code edits, survives typing syntax errors without crashing, and runs 100% offline on any Android device.

---

## Decision Outcome & Architectural Invariants

### 1. Embedded VFS Specification (`AndroidStdlibVfs`)
- Magic: `"AIPLVFS1"`
- Canonical Module Count: `281`
- Domain Group Count: `36`
- Path Normalization: Rejects paths containing `".."`, requires prefix `"std/"`, ensures `".aipl"` extension.

### 2. Mobile File Watcher Invariants (`MobileAiplWatcher`)
- Default Debounce: `50ms` (minimum allowed: `10ms`).
- Inotify Event Mask: Filters for `CLOSE_WRITE` (8) and `MOVED_TO` (128).
- Change Detection: Cryptographic 64-character hex SHA-256 comparison; ignores transient empty truncations.

### 3. Stateful Bytecode Swap & Recovery Invariants
- Snapshot: Deep copies `liveState` into an immutable snapshot map.
- Schema Merge: Preserves existing values for recognized keys; populates new defaults for newly introduced keys; prunes obsolete keys.
- Rollback: If `compileErrorCount > 0` or candidate functions $\le 0$, the VM retains current bytecode generation and displays the error diagnostic in the HUD pill (`ERR <code > L<line> | #<gen>`) while the current frame continues rendering.

### 4. Touch Ergonomics & Visual HUD Invariants
- Minimum Touch Target: $\ge 48\text{dp}$ conforming to Fitts's Law ergonomics.
- Diagnostic Toast: Automatically categorizes `E1xx` as `"SYNTAX"`, `E2xx` as `"TYPE"`, and `E3xx` as `"CONTRACT"`.
