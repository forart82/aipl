struct EnemyGoomba {
    x: f64,
    y: f64,
    vx: f64,
    alive: bool,
}

struct MarioWorld {
    player_x: f64,
    player_y: f64,
    player_vx: f64,
    player_vy: f64,
    on_ground: bool,
    power_up_state: i32,
    coins: i32,
    score: i32,
    lives: i32,
    camera_x: f64,
    goal_x: f64,
    status: String,
    coin_positions: Vec<f64>,
    mushroom_x: f64,
    mushroom_taken: bool,
    enemies: Vec<EnemyGoomba>,
}

#[allow(non_snake_case)]
fn createMarioLevel() -> MarioWorld {
    MarioWorld {
        player_x: 0.0,
        player_y: 0.0,
        player_vx: 0.0,
        player_vy: 0.0,
        on_ground: true,
        power_up_state: 0,
        coins: 0,
        score: 0,
        lives: 3,
        camera_x: 0.0,
        goal_x: 120.0,
        status: "PLAYING".to_string(),
        coin_positions: vec![30.0, 60.0, 90.0],
        mushroom_x: 40.0,
        mushroom_taken: false,
        enemies: vec![EnemyGoomba { x: 50.0, y: 0.0, vx: -1.0, alive: true }],
    }
}

#[allow(non_snake_case)]
fn stepMarioFrame(w: &mut MarioWorld, move_dir: f64, jump_pressed: bool, dt: f64) {
    if w.status != "PLAYING" {
        return;
    }
    w.player_vx = move_dir * 20.0;
    if jump_pressed && w.on_ground {
        w.player_vy = 18.0;
        w.on_ground = false;
    }
    w.player_vy -= 30.0 * dt;
    w.player_x += w.player_vx * dt;
    w.player_y += w.player_vy * dt;
    if w.player_y <= 0.0 {
        w.player_y = 0.0;
        w.player_vy = 0.0;
        w.on_ground = true;
    }
    if !w.mushroom_taken && (w.player_x - w.mushroom_x).abs() <= 2.0 {
        w.mushroom_taken = true;
        w.power_up_state = 1;
        w.score += 1000;
    }
    let px = w.player_x;
    let before = w.coin_positions.len();
    w.coin_positions.retain(|&cx| (px - cx).abs() > 2.0);
    let gained = (before - w.coin_positions.len()) as i32;
    w.coins += gained;
    w.score += gained * 200;
    for e in &mut w.enemies {
        if !e.alive {
            continue;
        }
        e.x += e.vx * dt;
        if (w.player_x - e.x).abs() <= 2.5 {
            if w.player_y > 0.5 && w.player_vy < 0.0 {
                e.alive = false;
                w.score += 500;
                w.player_vy = 10.0;
            } else if w.player_y <= 0.5 {
                if w.power_up_state > 0 {
                    w.power_up_state = 0;
                } else {
                    w.lives -= 1;
                    if w.lives <= 0 {
                        w.status = "GAME_OVER".to_string();
                    }
                }
            }
        }
    }
    w.camera_x = (w.player_x - 20.0).max(0.0);
    if w.player_x >= w.goal_x {
        w.status = "LEVEL_CLEAR".to_string();
        w.score += 2000;
    }
}

fn main() {
    let mut world = createMarioLevel();
    for frame in 0..40 {
        if world.status != "PLAYING" {
            break;
        }
        stepMarioFrame(&mut world, 1.0, frame == 8, 0.2);
    }
    assert_eq!(world.status, "LEVEL_CLEAR");
    assert_eq!(world.score, 4100);
    assert_eq!(world.coins, 3);
    assert!(!world.enemies[0].alive);
    assert!(world.camera_x > 80.0);
    println!("Mario Status={} Score={} Coins={}\nBENCH_12_OK", world.status, world.score, world.coins);
}
