#[derive(Clone, Copy)]
struct Body2D {
    id: i32,
    x: f64,
    y: f64,
    vx: f64,
    vy: f64,
    radius: f64,
    mass: f64,
}

#[allow(non_snake_case)]
fn stepPhysicsWorld(bodies: &mut [Body2D], dt: f64, worldW: f64, worldH: f64) {
    for b in bodies.iter_mut() {
        b.vy += 9.8 * dt;
        b.x += b.vx * dt;
        b.y += b.vy * dt;
        if b.x - b.radius < 0.0 {
            b.x = b.radius;
            b.vx = -b.vx * 0.9;
        } else if b.x + b.radius > worldW {
            b.x = worldW - b.radius;
            b.vx = -b.vx * 0.9;
        }
        if b.y + b.radius > worldH {
            b.y = worldH - b.radius;
            b.vy = -b.vy * 0.85;
        }
    }
    let n = bodies.len();
    for i in 0..n {
        for j in (i + 1)..n {
            let dx = bodies[j].x - bodies[i].x;
            let dy = bodies[j].y - bodies[i].y;
            let dist_sq = dx * dx + dy * dy;
            let min_dist = bodies[i].radius + bodies[j].radius;
            if dist_sq < min_dist * min_dist && dist_sq > 0.0001 {
                let d = dist_sq.sqrt();
                let nx = dx / d;
                let ny = dy / d;
                let vel_along_normal = (bodies[j].vx - bodies[i].vx) * nx + (bodies[j].vy - bodies[i].vy) * ny;
                if vel_along_normal < 0.0 {
                    let impulse = -(1.9 * vel_along_normal) / (1.0 / bodies[i].mass + 1.0 / bodies[j].mass);
                    bodies[i].vx -= (impulse / bodies[i].mass) * nx;
                    bodies[i].vy -= (impulse / bodies[i].mass) * ny;
                    bodies[j].vx += (impulse / bodies[j].mass) * nx;
                    bodies[j].vy += (impulse / bodies[j].mass) * ny;
                }
            }
        }
    }
}

fn main() {
    let mut world = vec![
        Body2D { id: 1, x: 20.0, y: 50.0, vx: 40.0, vy: 0.0, radius: 5.0, mass: 1.0 },
        Body2D { id: 2, x: 28.0, y: 50.0, vx: -40.0, vy: 0.0, radius: 5.0, mass: 1.0 },
    ];
    for _ in 0..5 {
        stepPhysicsWorld(&mut world, 0.05, 100.0, 100.0);
    }
    assert!(world[0].vx < 0.0 && world[1].vx > 0.0);
    println!("v0={} v1={}\nBENCH_10_OK", world[0].vx.round() as i32, world[1].vx.round() as i32);
}
