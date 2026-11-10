# AIPL Universal HEBAR Bot & Autonomous Referee Engine

The **AIPL Universal HEBAR Bot** (`aipl_hebar_bot/hebar_bot.aipl`) is an autonomous, human-equivalent referee and verification engine supporting multi-instance, multi-target, and multi-player execution across all four AIPL compilation targets:

1. **`aipl`**: JIT / Bytecode / Source execution via `/tmp/aipl_windows/win_<pid>` IPC envelopes.
2. **`native`**: Compiled C99 / X11 ELF binary driving standard headless and windowed frames.
3. **`html`**: Standalone HTML5 + Canvas2D + WebGL2 bundle evaluated via `__aiplHebarBridge`.
4. **`wasm`**: WebAssembly binary bundle executed under WASI / Browser host runtimes.

---

## 1. Five Inviolable HEBAR Kinematic Bounds

The engine strictly enforces human-reflex boundaries per seat:

| Invariant | Bound | Description |
|-----------|-------|-------------|
| **1. FIFO Latency** | $150.0\,\text{ms} \le \tau \le 250.0\,\text{ms}$ | Enqueued commands spend $9..15$ frames in queue before execution |
| **2. Frequency Clamp** | $\le 15.0\,\text{Hz}$ | Minimum inter-command delay $\ge 66.67\,\text{ms}$ ($\ge 4$ frames) |
| **3. Angular Velocity** | $\lvert\frac{d\theta}{dt}\rvert \le 2\pi\,\text{rad/s}$ | Heading adjustments clamped across $[-\pi, +\pi]$ |
| **4. Cursor Trajectory** | $\le 780\,\text{px/s}$ | Continuous interpolation without instantaneous pointer jumps or state tampering |
| **5. Anti-Stall Guard** | $< 120\,\text{idle frames}$ | Detects softlocks, inactivity loops, and campaign stalling |

---

## 2. Multi-Player Seat Arbiter

In shared-window and multi-seat scenarios, the bot enforces cooperative and adversarial refereeing:
- **Round-Robin Turn Handoff**: Token/lease handoff with deterministic hash verification.
- **Out-of-Turn Security Probing**: Validates that inputs from non-active seats are rejected ($100\%$ turn lock).
- **Contention Counting**: Tracks and reports cursor and button race conditions.

---

## 3. Global AIPL `.hebar` Bot Instruction Standard

By default, every HEBAR bot starts with `wait=250` ms reaction delay (`0` ms explicitly selectable, `start=auto`) and runs the **General Visual-Causal Cognitive Brain** (`"auto"`), automatically discovering and interacting with desktop GUI applications, turn-based board games, and real-time games without hardcoded categorization.

To specialize a bot for a specific application or game with maximum intelligence and minimal tokens, load a `.hebar` instruction file (`--strategy=<file.hebar>`, `--instructions=<file.hebar>`, or via the Orchestrator UI). The **Global AIPL `.hebar` Bot Instruction Standard** supports both ultra-compact v2 rules (parameter headers, `if`/`when`, `while`, `for`, `loop`) and legacy v1 behavior tree blocks (`selector`, `sequence`, `parallel`):

### 3.1 `@bot` Header & Parameterization
```hebar
@bot "ChessGrandmaster" wait=0 agg=85 exp=35 start=auto seat=auto
```
- `wait=<ms>`: Reaction wait time in milliseconds (`250` by default; `0` selectable).
- `agg=<0..100>`: Aggression parameter (`0..100`).
- `exp=<0..100>`: Exploration parameter (`0..100`).
- `start=auto|manual`: Auto-start (`ACTIVE`) by default or `manual` (`MANUAL (READY)` waiting for manual **Start** button).
- `seat=auto|1..4`: Target seat assignment.

### 3.2 Ultra-Compact Conditionals & Loops (Formal `.hebar` Language Grammar)
```ebnf
HebarFile      ::= BotHeader? Statement*
BotHeader      ::= "@bot" StringLit ("wait=" Int | "agg=" Int | "exp=" Int | "start=" ("auto"|"manual") | "seat=" ("auto"|Int))*
Statement      ::= IfStmt | WhileStmt | ForStmt | LoopStmt | V1BranchBlock
IfStmt         ::= ("if" | "when") ConditionExpr "=>" ActionExpr
WhileStmt      ::= "while" ConditionExpr "=>" ActionExpr
ForStmt        ::= "for" Ident "in" Collection ("where" IterPred)? "=>" ActionExpr
LoopStmt       ::= "loop" Int "=>" ActionExpr
Collection     ::= "my_tokens" | "highlights" | "buttons" | "tabs" | "enemies" | "hazards" | "items"
IterPred       ::= "!"? Ident "." ("dead" | "visited" | "clickable")
```
- **Conditionals (`if` / `when`)**: `if <cond> => <action>` or `when <cond> => <action>` (evaluated in top-to-bottom priority order).
- **While Loops (`while`)**: `while <cond> => <action>` (executes every frame with `cooldownMs = 0` while `<cond>` holds).
- **For Collection Loops (`for`)**: `for <var> in <collection> [where <cond>] => <action>` over `my_tokens`, `highlights`, `buttons`, `tabs`, `enemies`, `hazards`, or `items`.
- **Counted Loops (`loop`)**: `loop <N> => <action>` (repeats `<action>` `<N>` times in one command burst).

### 3.3 Complete `.hebar` Scene Sensors, Actions & Generic Tactical Modifiers Reference

| Category | `.hebar` Token / Expression | Meaning & Generic Evaluation |
|----------|-----------------------------|------------------------------|
| **Turn & Seat Sensors** | `self.seat`, `turn.active`, `turn.winner`, `turn.phase`, `turn.number` | Reads active multiplayer seat, winner seat, phase string (`"roll"`, `"move"`, `"play"`), and turn counter. |
| **Scene Count Sensors** | `my_tokens.count`, `highlights.count`, `buttons.count`, `tabs.count`, `enemies.count`, `hazards.count`, `items.count` | Counts live scene-graph nodes/entities matching the collection in the current frame. |
| **UI & Spatial Sensors** | `ui.has("<text>")`, `player.hp`, `env.nearestEnemyDist`, `env.nearestHazardDist` | Checks whether any visible UI node/highlight contains `<text>`, or reads player health / Euclidean threat distance. |
| **UI & Workspace Actions** | `click("<text>")`, `workspace_use()`, `auto_brain()`, `key("<K>")`, `text("<s>")`, `wheel(<d>)`, `wait()` | Clicks matching UI control, exercises workspace tools/canvas, sends keyboard/text/scroll events, or yields turn. |
| **Tactical Highlight Action** | `click_best("target_capture [mods]")`, `click_best("target_move [mods]")` | Scores all visible destination highlights (`target_capture` or `target_move`) using the specified generic tactical modifiers and clicks the highest-scoring target. |
| **Token Selection Action** | `try_token("[mods]")` | Evaluates all selectable tokens belonging to `self.seat` (`"<seat>:<symbol>"`) that are not marked dead in causal memory (`!t.dead`) and clicks the highest-scoring token. |
| **Combat Actions** | `aim_click(nearest_enemy)`, `kite(nearest_enemy)`, `evade(nearest_hazard)` | Aims and fires at the closest enemy, kites away while firing, or steers orthogonal/away from hazards. |
| **Generic Tactical Modifiers** | `+minimax`, `+mvv_lva`, `+see_safe`, `-hang`, `+fork`, `+mate`, `+check`, `+center`, `+develop`, `+forward`, `-blocked`, `+simple` | **100% Generic Visual Modifiers**: `+minimax`/`+mvv_lva` weights target value (`Q`/`9` > `R`/`5` > `B`/`N`/`3` > `P`/`1`); `+see_safe`/`-hang` checks enemy proximity (`< 1.45 * cellStep`); `+fork`/`+mate`/`+check` rewards multi-enemy/leader alignment; `+center`/`+develop`/`+forward`/`-blocked` uses dynamic playfield bounding-box & forward-vector geometry; `+simple` enables casual beginner play. |
| **Token Tier Symbols** | `+Q`, `+R`, `+B`, `+N`, `+P`, `-K` | Boosts or penalizes specific token symbol suffixes (`:Q`, `:R`, `:B`, `:N`, `:P`, `:K`) in any board or tactical game. |

### 3.4 Catalog of Built-In `.hebar` Specification Files (`aipl_hebar_bot/specs/`)

| File Path | Bot Profile | Purpose |
|-----------|-------------|---------|
| [`aipl_hebar_bot/specs/chess_master.hebar`](specs/chess_master.hebar) | `@bot "ChessGrandmaster" wait=0 agg=95 exp=20` | World-class tactical master using `+minimax +mate +check +mvv_lva +see_safe +fork +center +develop -hang -blocked` (`0ms` explicit choice). |
| [`aipl_hebar_bot/specs/chess_beginner.hebar`](specs/chess_beginner.hebar) | `@bot "ChessBeginner" wait=150 agg=45 exp=80` | Standard casual player using `+simple +forward` with natural `150ms` reaction wait. |
| [`aipl_hebar_bot/specs/multiplayer_board.hebar`](specs/multiplayer_board.hebar) | `@bot "BoardMaster" wait=250 agg=75 exp=40` | Turn-based 2P–4P board games (Ludo, Checkers, Parcheesi, race/dice games). |
| [`aipl_hebar_bot/specs/tactical_combat.hebar`](specs/tactical_combat.hebar) | `@bot "CombatAce" wait=250 agg=85 exp=30` | Real-time ARPG/FPS/arcade combat kiting, hazard evasion, and loot collection. |
| [`aipl_hebar_bot/specs/ui_app_explorer.hebar`](specs/ui_app_explorer.hebar) | `@bot "UiAppExplorer" wait=250 agg=40 exp=90` | Desktop productivity apps (Paint, Notepad, Markdown, Studio) tool/tab/canvas exploration. |
| [`aipl_hebar_bot/specs/default_universal.hebar`](specs/default_universal.hebar) | `@bot "UniversalBot" wait=250 agg=60 exp=60` | Universal cross-genre fallback specification combining board, combat, and UI rules (`250ms` human reflex default; `0ms` selectable). |

### 3.5 Examples: Grandmaster vs Beginner (`chess_master.hebar` & `chess_beginner.hebar`)

**World Chess Grandmaster (`aipl_hebar_bot/specs/chess_master.hebar`)**:
```hebar
@bot "ChessGrandmaster" wait=0 agg=95 exp=20 start=auto seat=auto

if turn.winner > 0 => click("New Match")
if turn.active != self.seat => wait()
while ui.has("target_capture") => click_best("target_capture +minimax +mate +check +mvv_lva +see_safe +fork +center")
while ui.has("target_move") => click_best("target_move +minimax +mate +check +see_safe +fork +center +develop -hang")
for t in my_tokens where !t.dead => try_token("+minimax +mate +check +mvv_lva +see_safe +fork +center +develop +N +B +Q +R +P -hang -blocked -K")
```

**Standard Beginner Chess Player (`aipl_hebar_bot/specs/chess_beginner.hebar`)**:
```hebar
@bot "ChessBeginner" wait=150 agg=45 exp=80 start=auto seat=auto

if turn.winner > 0 => click("New Match")
if turn.active != self.seat => wait()
if ui.has("target_capture") => click_best("target_capture +simple")
if ui.has("target_move") => click_best("target_move +simple +forward")
for t in my_tokens where !t.dead => try_token("+simple +P +N +B +forward -blocked")
```

---

## 4. Dual Closed-Loop Reporting

Each simulation session produces two comprehensive telemetry artifacts:
1. **Loop A — App Verification**:
   - `hebar_app_report.md` & `hebar_telemetry.json` (`"hebarCompliant": true`)
   - Cross-target execution parity matrix, dice/RNG chi-squared fairness stats, Fitts's law ($\ge 48\,\text{px}$) and Weber contrast ($\ge 2.5:1$) audit.
2. **Loop B — Bot Learning**:
   - `hebar_bot_report.md`, `hebar_bot_learning.json`, and `learned_heuristics.json`
   - Decision-tree branch attribution, heuristic weight adjustments, and deterministic replay recordings (`.hebar_replay`).

---

## 5. Interactive HEBAR Bot Orchestrator & Reorganized Orchestra TreeView

The **Live Fleet Control Center** (`--orchestrator` or `--control-center`) provides a reorganized 3-column command dashboard with AuraDesign OS text selection, OS file dialog integration, universal drag-and-drop bot attachment, and multi-mode Orchestra TreeView:

- **Left Column — Window Targets, Saved Bots & Bot Builder (`250ms` default speed, `0ms` selectable)**:
  - **Window Targets (`native`, `aipl`, `html`, `wasm`)**: Launch and discover all 4 AIPL application target types (`native`, `aipl`, `html`, `wasm`) using live `/proc/<pid>` verification, per-bundle browser companion bridges, and one-click `4-Target Proof` verification (`proveAllFourTargetTypes`).
  - **Drag-and-Drop Bot Attachment**: Drag any Saved Bot card, the Bot Builder `[Drag Builder Bot]`, or any Active Bot row and drop it directly onto a Window Target row (`dragDropAttachBotToWindow`) to attach and spawn the bot on that window.
  - **AuraDesign OS File Open Dialog (`Open...`)**: Alongside the `.hebar` combobox in both the Bot Builder and Inspector, click `Open...` (`openHebarFileDialog`) to open the AuraDesign file browser or invoke the native OS file open dialog (`auraOpenOsFileDialog`) to pick any `.hebar` file.
- **Center Column — Reorganized HEBAR Orchestra TreeView**:
  - Displays the hierarchical **Fleet Orchestra TreeView** (`Root -> Target Type [native | aipl | html | wasm] -> Application Window -> Attached Bots -> Live Telemetry`) using AuraDesign's multiple TreeView modes (`Outliner Tree`, `Interactive Tree`, `Path Tree`), followed by compact quick-action fleet controls.
- **Right Column — Multi-Tab Bot Inspector & OS Text Selection**:
  - Full OS text selection and visible blue selection highlighting (`#2563EB` fill, `#FFFFFF` text) on all editable text fields: mouse click-and-drag range selection, double-click word selection, `Shift+Left/Right/Home/End` range extension, `Ctrl+Left/Right` word jump, and `Ctrl+A`/`Ctrl+C`/`Ctrl+X`/`Ctrl+V` substring clipboard operations.
- **Architectural Scope Decision (`getArchitectureScopeDecision`)**:
  - Staying focused on **AIPL programs across all 4 targets (`native`, `aipl`, `html`, `wasm`)** provides vastly greater verification power than generic OS pixel scraping because AIPL controls the compiler and runtime across all 4 backends: deterministic scene-graph JSON telemetry without OCR lag, exact hitboxes ($\ge 48\,\text{px}$) and Weber contrast ($\ge 2.5:1$) auditing, multi-seat turn arbitration, and $1{,}000\times$ headless frame acceleration.

---

## 6. CLI Usage Examples

```bash
# 1. Launch Interactive Live Fleet Orchestrator & Control Center
aipl run aipl_hebar_bot/hebar_bot.aipl -- --orchestrator

# 2. Run multi-player arena showcase in headless mode
aipl run aipl_hebar_bot/hebar_bot.aipl -- --target=aipl_hebar_bot/demos/ludo_chess_arena.aipl --headless --frames=120 --out-dir=/tmp/aipl_hebar_arena

# 3. Benchmark frame rate uncapped (>= 120 FPS target)
aipl run aipl_hebar_bot/hebar_bot.aipl -- --target=examples/04_game_loop_and_ecs.aipl --BenchmarkWindowFps --out-dir=/tmp/aipl_hebar_bench

# 4. Target specific seat with declarative strategy specification
aipl run aipl_hebar_bot/hebar_bot.aipl -- --target=aipl_hebar_bot/demos/ludo_chess_arena.aipl --seat=2 --strategy=aipl_hebar_bot/specs/multiplayer_board.hebar --out-dir=/tmp/aipl_hebar_seat2

# 5. Record and replay deterministic sessions
aipl run aipl_hebar_bot/hebar_bot.aipl -- --target=aipl_hebar_bot/demos/ludo_chess_arena.aipl --record-replay=/tmp/match.hebar_replay --out-dir=/tmp/aipl_hebar_rec
aipl run aipl_hebar_bot/hebar_bot.aipl -- --target=aipl_hebar_bot/demos/ludo_chess_arena.aipl --replay=/tmp/match.hebar_replay --out-dir=/tmp/aipl_hebar_replay
```

---

## Live Fleet Orchestrator: Named/Saved Bots, 4-Instance Selector & OS Mechanics

Launch the interactive 3-panel **Live Fleet Orchestrator** control center:
```bash
./bin/aipl run aipl_hebar_bot/hebar_bot.aipl -- --orchestrator --windowed
```

### Key Capabilities in the Orchestrator (`aipl_hebar_bot/core/orchestrator.aipl`)
1. **100% Generic Tactical Bot Engine (`aipl_hebar_bot/core/behavior_tree.aipl`)**:
   - Evaluates any board game, tactical arena, or desktop GUI application dynamically from visual scene-graph geometry (`GenericPlayfieldGeometry`), token symbols (`1:Q`, `2:K`, etc.), highlight targets (`target_capture`, `target_move`), MVV-LVA capture weighting (`+minimax`, `+mvv_lva`), SEE threat safety (`+see_safe`, `-hang`), multi-target forks (`+fork`, `+mate`, `+check`), and causal memory (`deadCoords`, `visitedCoords`).
2. **All 4 AIPL Runtime Instances Selectable (`native`, `aipl`, `html`, `wasm`)**:
   - Choose `native`, `aipl`, `html`, or `wasm` directly in the **Instance Type Combobox** (`setTargetInstanceType`, `launchTargetApplicationWithType`) and attach/run bots across any combination of instances simultaneously.
3. **Bot Naming, Description, Live Updating, Saving & Unlimited Spawning**:
   - Assign a custom **Bot Name** and **Description** in the **Custom Bot Builder** (`createCustomNamedBot`), update them live at any time in the **Bot Inspector** (`updateBotIdentity`), persist profiles to `aipl_hebar_bot/saved_bots.tsv` (`saveBotProfile`), and spawn saved bots unlimited times onto any `native`, `aipl`, `html`, or `wasm` instance (`spawnSavedBot`).
4. **AuraDesign (`std/ui/aura.aipl`) OS Mechanics**:
   - **Text Fields**: Full OS clipboard & selection shortcuts (`Ctrl+C` Copy, `Ctrl+X` Cut, `Ctrl+V` Paste, `Ctrl+A` Select All with blue highlight box, `Backspace`/`Delete`, `Tab` field focus navigation, `Escape` deselection).
   - **Multi-Selection (`AuraMultiSelectState`)**: `Click` (single select), `Ctrl+Click` (toggle bot selection), `Shift+Click` (contiguous range selection), and `Ctrl+A` (select all bots in fleet).
   - **Dropdown Menus & Comboboxes**: Clean topmost Z-layer combobox overlays for Application, Instance Type (`native`/`aipl`/`html`/`wasm`), Saved Bot Library, `.hebar` Instructions, Player Seat, Reaction Wait Time, Start Mode, and Play Style.
