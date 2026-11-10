# SPEC_07: Graph Pathfinder (A*) & Priority Scheduler (`test_07_astar_scheduler`)

- **Tier**: Complex
- **Category**: 8-Directional A* Graph Search & Multi-Key Priority Scheduling

## 1. Functional Requirements
1. Construct a $6 \times 6$ 2D obstacle grid initialized to `0`, with vertical wall obstacles (`1`) at `(2, 0)`, `(2, 1)`, and `(2, 2)`.
2. Compute 8-directional A* shortest-path cost (cardinal cost $1.0$, diagonal cost $\sqrt{2} \approx 1.4142$, Euclidean heuristic) for:
   - `r1`: `(0, 0) -> (5, 0)` (must route around wall, cost $> 5.0$)
   - `r2`: `(0, 5) -> (5, 5)` (straight unobstructed path, cost $= 5.0$)
3. Define `ScheduledJob(id: int, priority: int, durationMs: int, pathCost: float)`.
4. Implement `scheduleJobsByPriority(jobs)` sorting jobs by descending `priority`, breaking ties by ascending `pathCost`, and returning the ordered list of job IDs `[102, 103, 101]`.

## 2. Structural & Algorithmic Parity (Rule B)
- **Normalized Identifiers**: `ScheduledJob`, `scheduleJobsByPriority`, `jobs`, `order`.
- **Algorithm**: Real 8-directional A* pathfinder + multi-key comparator sort.

## 3. Expected Deterministic Stdout
```text
Order=102,103,101
BENCH_07_OK
```
