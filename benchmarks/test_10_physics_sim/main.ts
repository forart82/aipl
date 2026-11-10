interface Body2D {
  id: number;
  x: number;
  y: number;
  vx: number;
  vy: number;
  radius: number;
  mass: number;
}

function stepPhysicsWorld(bodies: Body2D[], dt: number, worldW: number, worldH: number): void {
  for (const b of bodies) {
    b.vy += 9.8 * dt;
    b.x += b.vx * dt;
    b.y += b.vy * dt;
    if (b.x - b.radius < 0.0) {
      b.x = b.radius;
      b.vx = -b.vx * 0.9;
    } else if (b.x + b.radius > worldW) {
      b.x = worldW - b.radius;
      b.vx = -b.vx * 0.9;
    }
    if (b.y + b.radius > worldH) {
      b.y = worldH - b.radius;
      b.vy = -b.vy * 0.85;
    }
  }
  const n = bodies.length;
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      const a = bodies[i];
      const b = bodies[j];
      const dx = b.x - a.x;
      const dy = b.y - a.y;
      const distSq = dx * dx + dy * dy;
      const minDist = a.radius + b.radius;
      if (distSq < minDist * minDist && distSq > 0.0001) {
        const d = Math.sqrt(distSq);
        const nx = dx / d;
        const ny = dy / d;
        const velAlongNormal = (b.vx - a.vx) * nx + (b.vy - a.vy) * ny;
        if (velAlongNormal < 0.0) {
          const impulse = -(1.9 * velAlongNormal) / (1.0 / a.mass + 1.0 / b.mass);
          a.vx -= (impulse / a.mass) * nx;
          a.vy -= (impulse / a.mass) * ny;
          b.vx += (impulse / b.mass) * nx;
          b.vy += (impulse / b.mass) * ny;
        }
      }
    }
  }
}

const world: Body2D[] = [
  { id: 1, x: 20.0, y: 50.0, vx: 40.0, vy: 0.0, radius: 5.0, mass: 1.0 },
  { id: 2, x: 28.0, y: 50.0, vx: -40.0, vy: 0.0, radius: 5.0, mass: 1.0 },
];
for (let s = 0; s < 5; s++) {
  stepPhysicsWorld(world, 0.05, 100.0, 100.0);
}
if (world[0].vx >= 0.0 || world[1].vx <= 0.0) {
  throw new Error("assert");
}
console.log(`v0=${Math.round(world[0].vx)} v1=${Math.round(world[1].vx)}\nBENCH_10_OK`);
