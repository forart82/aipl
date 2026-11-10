from dataclasses import dataclass, field

@dataclass
class EnemyGoomba:
    x: float
    y: float
    vx: float
    alive: bool

@dataclass
class MarioWorld:
    playerX: float = 0.0
    playerY: float = 0.0
    playerVx: float = 0.0
    playerVy: float = 0.0
    onGround: bool = True
    powerUpState: int = 0
    coins: int = 0
    score: int = 0
    lives: int = 3
    cameraX: float = 0.0
    goalX: float = 120.0
    status: str = "PLAYING"
    coinPositions: list[float] = field(default_factory=lambda: [30.0, 60.0, 90.0])
    mushroomX: float = 40.0
    mushroomTaken: bool = False
    enemies: list[EnemyGoomba] = field(default_factory=list)

def createMarioLevel() -> MarioWorld:
    return MarioWorld(
        playerX=0.0,
        playerY=0.0,
        playerVx=0.0,
        playerVy=0.0,
        onGround=True,
        powerUpState=0,
        coins=0,
        score=0,
        lives=3,
        cameraX=0.0,
        goalX=120.0,
        status="PLAYING",
        coinPositions=[30.0, 60.0, 90.0],
        mushroomX=40.0,
        mushroomTaken=False,
        enemies=[EnemyGoomba(50.0, 0.0, -1.0, True)],
    )

def stepMarioFrame(w: MarioWorld, moveDir: float, jumpPressed: bool, dt: float):
    if w.status != "PLAYING":
        return
    w.playerVx = moveDir * 20.0
    if jumpPressed and w.onGround:
        w.playerVy = 18.0
        w.onGround = False
    w.playerVy -= 30.0 * dt
    w.playerX += w.playerVx * dt
    w.playerY += w.playerVy * dt
    if w.playerY <= 0.0:
        w.playerY = 0.0
        w.playerVy = 0.0
        w.onGround = True
    if not w.mushroomTaken and abs(w.playerX - w.mushroomX) <= 2.0:
        w.mushroomTaken = True
        w.powerUpState = 1
        w.score += 1000
    remCoins: list[float] = []
    for cx in w.coinPositions:
        if abs(w.playerX - cx) <= 2.0:
            w.coins += 1
            w.score += 200
        else:
            remCoins.append(cx)
    w.coinPositions = remCoins
    for e in w.enemies:
        if not e.alive:
            continue
        e.x += e.vx * dt
        if abs(w.playerX - e.x) <= 2.5:
            if w.playerY > 0.5 and w.playerVy < 0.0:
                e.alive = False
                w.score += 500
                w.playerVy = 10.0
            elif w.playerY <= 0.5:
                if w.powerUpState > 0:
                    w.powerUpState = 0
                else:
                    w.lives -= 1
                    if w.lives <= 0:
                        w.status = "GAME_OVER"
    w.cameraX = max(0.0, w.playerX - 20.0)
    if w.playerX >= w.goalX:
        w.status = "LEVEL_CLEAR"
        w.score += 2000

world = createMarioLevel()
for frame in range(40):
    if world.status != "PLAYING":
        break
    stepMarioFrame(world, 1.0, frame == 8, 0.2)

assert world.status == "LEVEL_CLEAR"
assert world.score == 4100
assert world.coins == 3
assert not world.enemies[0].alive
assert world.cameraX > 80.0
print(f"Mario Status={world.status} Score={world.score} Coins={world.coins}\nBENCH_12_OK")
