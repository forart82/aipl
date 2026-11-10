function astarCost(g, sx, sy, gx, gy) {
  const h = g.length, w = g[0].length;
  const dist = Array.from({ length: h }, () => Array(w).fill(1e9));
  const vis = Array.from({ length: h }, () => Array(w).fill(false));
  dist[sy][sx] = 0;
  const dirs = [[1,0,1],[-1,0,1],[0,1,1],[0,-1,1],[1,1,1.414],[1,-1,1.414],[-1,1,1.414],[-1,-1,1.414]];
  while (true) {
    let bestF = 1e9, bx = -1, by = -1;
    for (let y = 0; y < h; y++) for (let x = 0; x < w; x++) {
      if (!vis[y][x] && dist[y][x] < 1e8) {
        const f = dist[y][x] + Math.hypot(gx - x, gy - y);
        if (f < bestF) { bestF = f; bx = x; by = y; }
      }
    }
    if (bx < 0) return -1;
    if (bx === gx && by === gy) return dist[by][bx];
    vis[by][bx] = true;
    for (const [dx, dy, step] of dirs) {
      const nx = bx + dx, ny = by + dy;
      if (nx >= 0 && nx < w && ny >= 0 && ny < h && g[ny][nx] === 0 && dist[by][bx] + step < dist[ny][nx]) {
        dist[ny][nx] = dist[by][bx] + step;
      }
    }
  }
}
const g = Array.from({ length: 6 }, () => Array(6).fill(0));
g[0][2] = g[1][2] = g[2][2] = 1;
const c1 = astarCost(g, 0, 0, 5, 0), c2 = astarCost(g, 0, 5, 5, 5);
const jobs = [{ id: 101, prio: 5, cost: c1 }, { id: 102, prio: 10, cost: c1 }, { id: 103, prio: 5, cost: c2 }];
jobs.sort((a, b) => b.prio - a.prio || a.cost - b.cost);
if (jobs[0].id !== 102 || jobs[1].id !== 103) throw new Error("assert");
console.log(`Order=${jobs.map((j) => j.id).join(",")}\nBENCH_07_OK`);
