struct EnemyGoomba { x: f64, vx: f64, alive: bool }
struct MarioWorld {
    px: f64, py: f64, vx: f64, vy: f64, cam_x: f64, goal_x: f64, mush_x: f64,
    on_ground: bool, mush_taken: bool, power: i32, coins: i32, score: i32, lives: i32,
    status: String, coin_pos: Vec<f64>, enemies: Vec<EnemyGoomba>,
}

impl MarioWorld {
    fn new() -> Self {
        Self {
            px: 0.0, py: 0.0, vx: 0.0, vy: 0.0, cam_x: 0.0, goal_x: 120.0, mush_x: 40.0,
            on_ground: true, mush_taken: false, power: 0, coins: 0, score: 0, lives: 3,
            status: "PLAYING".into(), coin_pos: vec![30.0, 60.0, 90.0],
            enemies: vec![EnemyGoomba { x: 50.0, vx: -1.0, alive: true }],
        }
    }
    fn step(&mut self, dir: f64, jump: bool, dt: f64) {
        if self.status != "PLAYING" { return; }
        self.vx = dir * 20.0;
        if jump && self.on_ground { self.vy = 18.0; self.on_ground = false; }
        self.vy -= 30.0 * dt;
        self.px += self.vx * dt;
        self.py += self.vy * dt;
        if self.py <= 0.0 { self.py = 0.0; self.vy = 0.0; self.on_ground = true; }
        if !self.mush_taken && (self.px - self.mush_x).abs() <= 2.0 {
            self.mush_taken = true; self.power = 1; self.score += 1000;
        }
        let px = self.px;
        let before = self.coin_pos.len();
        self.coin_pos.retain(|&cx| (px - cx).abs() > 2.0);
        let gained = (before - self.coin_pos.len()) as i32;
        self.coins += gained;
        self.score += gained * 200;
        for e in &mut self.enemies {
            if !e.alive { continue; }
            e.x += e.vx * dt;
            if (self.px - e.x).abs() <= 2.5 {
                if self.py > 0.5 && self.vy < 0.0 { e.alive = false; self.score += 500; self.vy = 10.0; }
                else if self.py <= 0.5 {
                    if self.power > 0 { self.power = 0; }
                    else { self.lives -= 1; if self.lives <= 0 { self.status = "GAME_OVER".into(); } }
                }
            }
        }
        self.cam_x = (self.px - 20.0).max(0.0);
        if self.px >= self.goal_x { self.status = "LEVEL_CLEAR".into(); self.score += 2000; }
    }
}

fn main() {
    let mut w = MarioWorld::new();
    for f in 0..40 {
        if w.status != "PLAYING" { break; }
        w.step(1.0, f == 8, 0.2);
    }
    assert!(w.status == "LEVEL_CLEAR" && w.mush_taken && w.power == 1 && w.coins == 3 && !w.enemies[0].alive && w.score == 4100 && w.cam_x > 80.0);
    println!("Mario Status={} Score={} Coins={}\nBENCH_12_OK", w.status, w.score, w.coins);
}
