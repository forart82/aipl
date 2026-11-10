class EnemyGoomba {
  constructor(x, y, vx, alive) {
    this.x = x;
    this.y = y;
    this.vx = vx;
    this.alive = alive;
  }
}

class MarioWorld {
  constructor() {
    this.playerX = 0.0;
    this.playerY = 0.0;
    this.playerVx = 0.0;
    this.playerVy = 0.0;
    this.onGround = true;
    this.powerUpState = 0;
    this.coins = 0;
    this.score = 0;
    this.lives = 3;
    this.cameraX = 0.0;
    this.goalX = 120.0;
    this.status = "PLAYING";
    this.coinPositions = [30.0, 60.0, 90.0];
    this.mushroomX = 40.0;
    this.mushroomTaken = false;
    this.enemies = [new EnemyGoomba(50.0, 0.0, -1.0, true)];
  }
}

function createMarioLevel() {
  return new MarioWorld();
}

function stepMarioFrame(w, moveDir, jumpPressed, dt) {
  if (w.status !== "PLAYING") {
    return;
  }
  w.playerVx = moveDir * 20.0;
  if (jumpPressed && w.onGround) {
    w.playerVy = 18.0;
    w.onGround = false;
  }
  w.playerVy -= 30.0 * dt;
  w.playerX += w.playerVx * dt;
  w.playerY += w.playerVy * dt;
  if (w.playerY <= 0.0) {
    w.playerY = 0.0;
    w.playerVy = 0.0;
    w.onGround = true;
  }
  if (!w.mushroomTaken && Math.abs(w.playerX - w.mushroomX) <= 2.0) {
    w.mushroomTaken = true;
    w.powerUpState = 1;
    w.score += 1000;
  }
  w.coinPositions = w.coinPositions.filter((cx) => {
    if (Math.abs(w.playerX - cx) <= 2.0) {
      w.coins += 1;
      w.score += 200;
      return false;
    }
    return true;
  });
  for (const e of w.enemies) {
    if (!e.alive) {
      continue;
    }
    e.x += e.vx * dt;
    if (Math.abs(w.playerX - e.x) <= 2.5) {
      if (w.playerY > 0.5 && w.playerVy < 0.0) {
        e.alive = false;
        w.score += 500;
        w.playerVy = 10.0;
      } else if (w.playerY <= 0.5) {
        if (w.powerUpState > 0) {
          w.powerUpState = 0;
        } else {
          w.lives -= 1;
          if (w.lives <= 0) {
            w.status = "GAME_OVER";
          }
        }
      }
    }
  }
  w.cameraX = Math.max(0.0, w.playerX - 20.0);
  if (w.playerX >= w.goalX) {
    w.status = "LEVEL_CLEAR";
    w.score += 2000;
  }
}

const world = createMarioLevel();
for (let frame = 0; frame < 40; frame++) {
  if (world.status !== "PLAYING") {
    break;
  }
  stepMarioFrame(world, 1.0, frame === 8, 0.2);
}
if (world.status !== "LEVEL_CLEAR" || world.score !== 4100 || world.coins !== 3 || world.enemies[0].alive || world.cameraX <= 80.0) {
  throw new Error("assert");
}
console.log(`Mario Status=${world.status} Score=${world.score} Coins=${world.coins}\nBENCH_12_OK`);
