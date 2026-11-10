# SPEC_12: Complex Super Mario Platformer Game (`test_12_super_mario`)

- **Tier**: Extreme Complexity
- **Category**: 2D Platformer Game Loop, Entity Collision, Power-Ups, Enemies & Camera Tracking

## 1. Functional Requirements
1. Define `EnemyGoomba(x: float, y: float, vx: float, alive: bool)` and `MarioWorld(playerX: float, playerY: float, playerVx: float, playerVy: float, onGround: bool, powerUpState: int, coins: int, score: int, lives: int, cameraX: float, goalX: float, status: str, coinPositions: [float], mushroomX: float, mushroomTaken: bool, enemies: [EnemyGoomba])`.
2. Implement `createMarioLevel()` initializing Mario at `(0, 0)`, `lives = 3`, `goalX = 120.0`, `status = "PLAYING"`, `coinPositions = [30.0, 60.0, 90.0]`, `mushroomX = 40.0`, and `[EnemyGoomba(50.0, 0.0, -1.0, true)]`.
3. Implement `stepMarioFrame(w, moveDir, jumpPressed, dt)`:
   - Early return if `w.status != "PLAYING"`.
   - Horizontal velocity `playerVx = moveDir * 20.0`; jump impulse `playerVy = 18.0, onGround = false` if `jumpPressed and onGround`.
   - Gravity `playerVy -= 30.0 * dt`; integrate `playerX`, `playerY`; clamp ground `playerY <= 0.0 -> playerY = 0.0, playerVy = 0.0, onGround = true`.
   - Mushroom pickup: if `not mushroomTaken` and `|playerX - mushroomX| <= 2.0`, set `mushroomTaken = true, powerUpState = 1, score += 1000`.
   - Coin pickup: filter `coinPositions`; for each coin with `|playerX - cx| <= 2.0`, increment `coins += 1, score += 200`.
   - Enemy AI & collision: for each alive enemy, integrate `x += vx * dt`. If `|playerX - ex| <= 2.5`:
     - Stomp (`playerY > 0.5 and playerVy < 0.0`): `score += 500, playerVy = 10.0, enemy.alive = false`.
     - Ground hit (`playerY <= 0.5`): if `powerUpState > 0` set `powerUpState = 0`, else decrement `lives` and if `lives <= 0` set `status = "GAME_OVER"`.
   - Camera & Flagpole: `cameraX = max(0.0, playerX - 20.0)`; if `playerX >= goalX`, set `status = "LEVEL_CLEAR", score += 2000`.
4. Simulate up to 40 frames with `moveDir = 1.0, jumpPressed = (frame == 8), dt = 0.2`. Assert `status == "LEVEL_CLEAR"`, `score == 4100`, `coins == 3`, `not enemies[0].alive`, `cameraX > 80.0`, and print `"Mario Status=LEVEL_CLEAR Score=4100 Coins=3"` followed by `BENCH_12_OK`.

## 2. Structural & Algorithmic Parity (Rule B)
- **Normalized Identifiers**: `EnemyGoomba`, `MarioWorld`, `createMarioLevel`, `stepMarioFrame`, `world`.
- **Full Game Logic Parity**: All 8 languages must define `EnemyGoomba` and `MarioWorld`, `createMarioLevel`, and `stepMarioFrame` including the ground-hit damage/lives branch.

## 3. Expected Deterministic Stdout
```text
Mario Status=LEVEL_CLEAR Score=4100 Coins=3
BENCH_12_OK
```
