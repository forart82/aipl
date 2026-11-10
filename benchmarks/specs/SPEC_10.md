# SPEC_10: 2D Physics & Particle Simulation Engine (`test_10_physics_sim`)

- **Tier**: Very Complex
- **Category**: Semi-Implicit Euler Integration, Boundary Reflection & Impulse Collision Resolution

## 1. Functional Requirements
1. Define `Body2D(id: int, x: float, y: float, vx: float, vy: float, radius: float, mass: float)`.
2. Implement `stepPhysicsWorld(bodies, dt, worldW, worldH)`:
   - Apply gravity ($g = 9.8$) to `vy` and integrate positions `(x, y)` over timestep `dt`.
   - Resolve horizontal boundary collisions (`x - radius < 0` or `x + radius > worldW`) with restitution `0.9` and vertical floor collision (`y + radius > worldH`) with restitution `0.85`.
   - Resolve pairwise circle-circle elastic collisions (`distSq < (r1 + r2)^2` and `distSq > 0.0001`) along unit normal `(nx, ny)` when `velAlongNormal < 0` using restitution $e = 0.9$ and impulse $j = -(1 + 0.9) v_n / (1/m_1 + 1/m_2)$, updating both `vx` and `vy` for both bodies.
3. Simulate 2 bodies (`Body2D(1, 20.0, 50.0, 40.0, 0.0, 5.0, 1.0)` and `Body2D(2, 28.0, 50.0, -40.0, 0.0, 5.0, 1.0)`) for 5 steps with `dt = 0.05, worldW = 100.0, worldH = 100.0`.
4. Assert velocities reverse (`world[0].vx < 0.0` and `world[1].vx > 0.0`), and print `"v0={vx0} v1={vx1}"` followed by `BENCH_10_OK`.

## 2. Structural & Algorithmic Parity (Rule B)
- **Normalized Identifiers**: `Body2D`, `stepPhysicsWorld`, `world`.
- **Full Physics Parity**: All 8 languages must implement both wall boundary reflections AND full 2D `(vx, vy)` impulse collision resolution.

## 3. Expected Deterministic Stdout
```text
v0=-36.0 v1=36.0
BENCH_10_OK
```
