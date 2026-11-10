import math
from dataclasses import dataclass

@dataclass
class ScheduledJob:
    id: int
    priority: int
    durationMs: int
    pathCost: float

def astarCost(grid: list[list[int]], sx: int, sy: int, gx: int, gy: int) -> float:
    h = len(grid)
    w = len(grid[0])
    dist = [[1e9 for _ in range(w)] for _ in range(h)]
    visited = [[False for _ in range(w)] for _ in range(h)]
    dist[sy][sx] = 0.0
    dirs = [
        (1, 0, 1.0),
        (-1, 0, 1.0),
        (0, 1, 1.0),
        (0, -1, 1.0),
        (1, 1, 1.4142),
        (1, -1, 1.4142),
        (-1, 1, 1.4142),
        (-1, -1, 1.4142),
    ]
    while True:
        bestF = 1e9
        bx = -1
        by = -1
        found = False
        for y in range(h):
            for x in range(w):
                if not visited[y][x] and dist[y][x] < 1e8:
                    f = dist[y][x] + math.sqrt((gx - x) ** 2 + (gy - y) ** 2)
                    if f < bestF:
                        bestF = f
                        bx = x
                        by = y
                        found = True
        if not found:
            return -1.0
        if bx == gx and by == gy:
            return dist[by][bx]
        visited[by][bx] = True
        for dx, dy, cost in dirs:
            nx = bx + dx
            ny = by + dy
            if 0 <= nx < w and 0 <= ny < h:
                if grid[ny][nx] == 0 and dist[by][bx] + cost < dist[ny][nx]:
                    dist[ny][nx] = dist[by][bx] + cost

def scheduleJobsByPriority(jobs: list[ScheduledJob]) -> list[int]:
    sortedJobs = sorted(jobs, key=lambda j: (-j.priority, j.pathCost))
    return [j.id for j in sortedJobs]

grid = [[0 for _ in range(6)] for _ in range(6)]
grid[0][2] = 1
grid[1][2] = 1
grid[2][2] = 1
c1 = astarCost(grid, 0, 0, 5, 0)
c2 = astarCost(grid, 0, 5, 5, 5)
assert c1 > c2 and c2 > 0.0
jobs = [
    ScheduledJob(101, 5, 100, c1),
    ScheduledJob(102, 10, 200, c1),
    ScheduledJob(103, 5, 150, c2),
]
order = scheduleJobsByPriority(jobs)
assert order == [102, 103, 101]
print(f"Order={','.join(str(i) for i in order)}\nBENCH_07_OK")
