interface ScheduledJob {
  id: number;
  priority: number;
  durationMs: number;
  pathCost: number;
}

function astarCost(g: number[][], sx: number, sy: number, gx: number, gy: number): number {
  const h = g.length;
  const w = g[0].length;
  const dist: number[][] = Array.from({ length: h }, () => Array(w).fill(1e9));
  const visited: boolean[][] = Array.from({ length: h }, () => Array(w).fill(false));
  dist[sy][sx] = 0.0;
  const dirs: [number, number, number][] = [
    [1, 0, 1.0], [-1, 0, 1.0], [0, 1, 1.0], [0, -1, 1.0],
    [1, 1, 1.4142], [1, -1, 1.4142], [-1, 1, 1.4142], [-1, -1, 1.4142]
  ];
  while (true) {
    let bestF = 1e9;
    let bx = -1;
    let by = -1;
    let found = false;
    for (let y = 0; y < h; y++) {
      for (let x = 0; x < w; x++) {
        if (!visited[y][x] && dist[y][x] < 1e8) {
          const f = dist[y][x] + Math.sqrt((gx - x) ** 2 + (gy - y) ** 2);
          if (f < bestF) {
            bestF = f;
            bx = x;
            by = y;
            found = true;
          }
        }
      }
    }
    if (!found) {
      return -1.0;
    }
    if (bx === gx && by === gy) {
      return dist[by][bx];
    }
    visited[by][bx] = true;
    for (const [dx, dy, cost] of dirs) {
      const nx = bx + dx;
      const ny = by + dy;
      if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
        if (g[ny][nx] === 0 && dist[by][bx] + cost < dist[ny][nx]) {
          dist[ny][nx] = dist[by][bx] + cost;
        }
      }
    }
  }
}

function scheduleJobsByPriority(jobs: ScheduledJob[]): number[] {
  const sorted = [...jobs].sort((a, b) => {
    if (a.priority !== b.priority) {
      return b.priority - a.priority;
    }
    return a.pathCost - b.pathCost;
  });
  return sorted.map((j) => j.id);
}

const g: number[][] = Array.from({ length: 6 }, () => Array(6).fill(0));
g[0][2] = 1;
g[1][2] = 1;
g[2][2] = 1;
const c1 = astarCost(g, 0, 0, 5, 0);
const c2 = astarCost(g, 0, 5, 5, 5);
if (c1 <= c2 || c2 <= 0.0) {
  throw new Error("assert");
}
const jobs: ScheduledJob[] = [
  { id: 101, priority: 5, durationMs: 100, pathCost: c1 },
  { id: 102, priority: 10, durationMs: 200, pathCost: c1 },
  { id: 103, priority: 5, durationMs: 150, pathCost: c2 },
];
const order = scheduleJobsByPriority(jobs);
if (order[0] !== 102 || order[1] !== 103 || order[2] !== 101) {
  throw new Error("assert");
}
console.log(`Order=${order.join(",")}\nBENCH_07_OK`);
