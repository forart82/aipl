#[derive(Clone, Copy)]
struct Body2D { id: i32, x: f64, y: f64, vx: f64, vy: f64, r: f64, m: f64 }

fn step_world(bodies: &mut [Body2D], dt: f64, w: f64, h: f64) {
    for b in bodies.iter_mut() {
        b.vy += 9.8 * dt;
        b.x += b.vx * dt;
        b.y += b.vy * dt;
        if b.x - b.r < 0.0 { b.x = b.r; b.vx = -b.vx * 0.9; }
        else if b.x + b.r > w { b.x = w - b.r; b.vx = -b.vx * 0.9; }
        if b.y + b.r > h { b.y = h - b.r; b.vy = -b.vy * 0.85; }
    }
    for i in 0..bodies.len() {
        for j in (i + 1)..bodies.len() {
            let (dx, dy) = (bodies[j].x - bodies[i].x, bodies[j].y - bodies[i].y);
            let (d2, min_d) = (dx*dx + dy*dy, bodies[i].r + bodies[j].r);
            if d2 < min_d * min_d && d2 > 1e-4 {
                let d = d2.sqrt();
                let (nx, ny) = (dx / d, dy / d);
                let vn = (bodies[j].vx - bodies[i].vx)*nx + (bodies[j].vy - bodies[i].vy)*ny;
                if vn < 0.0 {
                    let imp = -(1.9 * vn) / (1.0/bodies[i].m + 1.0/bodies[j].m);
                    bodies[i].vx -= (imp / bodies[i].m) * nx;
                    bodies[j].vx += (imp / bodies[j].m) * nx;
                }
            }
        }
    }
}

fn main() {
    let mut world = vec![
        Body2D { id: 1, x: 20.0, y: 50.0, vx: 40.0, vy: 0.0, r: 5.0, m: 1.0 },
        Body2D { id: 2, x: 28.0, y: 50.0, vx: -40.0, vy: 0.0, r: 5.0, m: 1.0 },
    ];
    for _ in 0..5 { step_world(&mut world, 0.05, 100.0, 100.0); }
    assert!(world[0].vx < 0.0 && world[1].vx > 0.0);
    println!("v0={} v1={}\nBENCH_10_OK", world[0].vx, world[1].vx);
}
