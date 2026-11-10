interface Goomba { x: number; vx: number; alive: boolean; }
interface MarioWorld {
  px: number; py: number; vx: number; vy: number; camX: number; goalX: number; mushX: number;
  onGround: boolean; mushTaken: boolean; power: number; coins: number; score: number; lives: number;
  status: string; coinPos: number[]; enemies: Goomba[];
}
const w: MarioWorld = {
  px: 0, py: 0, vx: 0, vy: 0, camX: 0, goalX: 120, mushX: 40,
  onGround: true, mushTaken: false, power: 0, coins: 0, score: 0, lives: 3,
  status: "PLAYING", coinPos: [30, 60, 90], enemies: [{ x: 50, vx: -1, alive: true }],
};
for (let f = 0; f < 40 && w.status === "PLAYING"; f++) {
  const dt = 0.2;
  w.vx = 20;
  if (f === 8 && w.onGround) { w.vy = 18; w.onGround = false; }
  w.vy -= 30 * dt; w.px += w.vx * dt; w.py += w.vy * dt;
  if (w.py <= 0) { w.py = 0; w.vy = 0; w.onGround = true; }
  if (!w.mushTaken && Math.abs(w.px - w.mushX) <= 2) { w.mushTaken = true; w.power = 1; w.score += 1000; }
  w.coinPos = w.coinPos.filter((cx) => {
    if (Math.abs(w.px - cx) <= 2) { w.coins++; w.score += 200; return false; }
    return true;
  });
  for (const e of w.enemies) {
    if (!e.alive) continue;
    e.x += e.vx * dt;
    if (Math.abs(w.px - e.x) <= 2.5 && w.py > 0.5 && w.vy < 0) { e.alive = false; w.score += 500; w.vy = 10; }
  }
  w.camX = Math.max(0, w.px - 20);
  if (w.px >= w.goalX) { w.status = "LEVEL_CLEAR"; w.score += 2000; }
}
if (w.status !== "LEVEL_CLEAR" || w.score !== 4100 || w.coins !== 3 || w.enemies[0].alive) throw new Error("assert");
console.log(`Mario Status=${w.status} Score=${w.score} Coins=${w.coins}\nBENCH_12_OK`);
