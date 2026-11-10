interface Body2D { id: number; x: number; y: number; vx: number; vy: number; r: number; m: number; }
function stepWorld(bs: Body2D[], dt: number): void {
  for (const b of bs) { b.vy += 9.8 * dt; b.x += b.vx * dt; b.y += b.vy * dt; }
  for (let i = 0; i < bs.length; i++) for (let j = i + 1; j < bs.length; j++) {
    const a = bs[i], b = bs[j], dx = b.x - a.x, dy = b.y - a.y, d2 = dx*dx + dy*dy, minD = a.r + b.r;
    if (d2 < minD * minD && d2 > 1e-4) {
      const d = Math.sqrt(d2), nx = dx / d, ny = dy / d, vn = (b.vx - a.vx)*nx + (b.vy - a.vy)*ny;
      if (vn < 0) {
        const imp = -(1.9 * vn) / (1/a.m + 1/b.m);
        a.vx -= (imp / a.m) * nx; b.vx += (imp / b.m) * nx;
      }
    }
  }
}
const w: Body2D[] = [{ id: 1, x: 20, y: 50, vx: 40, vy: 0, r: 5, m: 1 }, { id: 2, x: 28, y: 50, vx: -40, vy: 0, r: 5, m: 1 }];
for (let s = 0; s < 5; s++) stepWorld(w, 0.05);
if (w[0].vx >= 0 || w[1].vx <= 0) throw new Error("assert");
console.log(`v0=${w[0].vx} v1=${w[1].vx}\nBENCH_10_OK`);
