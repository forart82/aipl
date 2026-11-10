import heapq, math

def astar_cost(g: list[list[int]], sx: int, sy: int, gx: int, gy: int) -> float:
    h, w = len(g), len(g[0])
    dist = {(sx, sy): 0.0}
    pq = [(0.0, sx, sy)]
    dirs = [(1,0,1.0),(-1,0,1.0),(0,1,1.0),(0,-1,1.0),(1,1,1.414),(1,-1,1.414),(-1,1,1.414),(-1,-1,1.414)]
    while pq:
        _, x, y = heapq.heappop(pq)
        if (x, y) == (gx, gy): return dist[(x, y)]
        for dx, dy, step in dirs:
            nx, ny = x + dx, y + dy
            if 0 <= nx < w and 0 <= ny < h and g[ny][nx] == 0:
                nd = dist[(x, y)] + step
                if nd < dist.get((nx, ny), 1e9):
                    dist[(nx, ny)] = nd
                    heapq.heappush(pq, (nd + math.hypot(gx - nx, gy - ny), nx, ny))
    return -1.0

g = [[0]*6 for _ in range(6)]
g[0][2] = g[1][2] = g[2][2] = 1
c1, c2 = astar_cost(g, 0, 0, 5, 0), astar_cost(g, 0, 5, 5, 5)
jobs = [(101, 5, c1), (102, 10, c1), (103, 5, c2)]
jobs.sort(key=lambda j: (-j[1], j[2]))
assert [j[0] for j in jobs] == [102, 103, 101]
print(f"Order={','.join(str(j[0]) for j in jobs)}\nBENCH_07_OK")
