import math
from dataclasses import dataclass

@dataclass
class Body2D:
    id: int
    x: float
    y: float
    vx: float
    vy: float
    radius: float
    mass: float

def stepPhysicsWorld(bodies: list[Body2D], dt: float, worldW: float, worldH: float):
    for b in bodies:
        b.vy += 9.8 * dt
        b.x += b.vx * dt
        b.y += b.vy * dt
        if b.x - b.radius < 0.0:
            b.x = b.radius
            b.vx = -b.vx * 0.9
        elif b.x + b.radius > worldW:
            b.x = worldW - b.radius
            b.vx = -b.vx * 0.9
        if b.y + b.radius > worldH:
            b.y = worldH - b.radius
            b.vy = -b.vy * 0.85
    n = len(bodies)
    for i in range(n):
        for j in range(i + 1, n):
            a = bodies[i]
            b = bodies[j]
            dx = b.x - a.x
            dy = b.y - a.y
            distSq = dx * dx + dy * dy
            minDist = a.radius + b.radius
            if 0.0001 < distSq < minDist * minDist:
                d = math.sqrt(distSq)
                nx = dx / d
                ny = dy / d
                velAlongNormal = (b.vx - a.vx) * nx + (b.vy - a.vy) * ny
                if velAlongNormal < 0.0:
                    impulse = -(1.9 * velAlongNormal) / (1.0 / a.mass + 1.0 / b.mass)
                    a.vx -= (impulse / a.mass) * nx
                    a.vy -= (impulse / a.mass) * ny
                    b.vx += (impulse / b.mass) * nx
                    b.vy += (impulse / b.mass) * ny

world = [
    Body2D(1, 20.0, 50.0, 40.0, 0.0, 5.0, 1.0),
    Body2D(2, 28.0, 50.0, -40.0, 0.0, 5.0, 1.0),
]
for _ in range(5):
    stepPhysicsWorld(world, 0.05, 100.0, 100.0)

assert world[0].vx < 0.0 and world[1].vx > 0.0
print(f"v0={int(round(world[0].vx))} v1={int(round(world[1].vx))}\nBENCH_10_OK")
