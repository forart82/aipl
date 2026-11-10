struct ScheduledJob {
    id: i32,
    priority: i32,
    duration_ms: i32,
    path_cost: f64,
}

#[allow(non_snake_case)]
fn astarCost(grid: &[Vec<i32>], sx: usize, sy: usize, gx: usize, gy: usize) -> f64 {
    let h = grid.len();
    let w = grid[0].len();
    let mut dist = vec![vec![1e9_f64; w]; h];
    let mut visited = vec![vec![false; w]; h];
    dist[sy][sx] = 0.0;
    let dirs: [(isize, isize, f64); 8] = [
        (1, 0, 1.0),
        (-1, 0, 1.0),
        (0, 1, 1.0),
        (0, -1, 1.0),
        (1, 1, 1.4142),
        (1, -1, 1.4142),
        (-1, 1, 1.4142),
        (-1, -1, 1.4142),
    ];
    loop {
        let mut best_f = 1e9;
        let mut bx = 0;
        let mut by = 0;
        let mut found = false;
        for y in 0..h {
            for x in 0..w {
                if !visited[y][x] && dist[y][x] < 1e8 {
                    let f = dist[y][x] + (((gx as isize - x as isize).pow(2) + (gy as isize - y as isize).pow(2)) as f64).sqrt();
                    if f < best_f {
                        best_f = f;
                        bx = x;
                        by = y;
                        found = true;
                    }
                }
            }
        }
        if !found {
            return -1.0;
        }
        if bx == gx && by == gy {
            return dist[by][bx];
        }
        visited[by][bx] = true;
        for (dx, dy, cost) in dirs {
            let nx = bx as isize + dx;
            let ny = by as isize + dy;
            if nx >= 0 && nx < w as isize && ny >= 0 && ny < h as isize {
                let ux = nx as usize;
                let uy = ny as usize;
                if grid[uy][ux] == 0 && dist[by][bx] + cost < dist[uy][ux] {
                    dist[uy][ux] = dist[by][bx] + cost;
                }
            }
        }
    }
}

#[allow(non_snake_case)]
fn scheduleJobsByPriority(mut jobs: Vec<ScheduledJob>) -> Vec<i32> {
    jobs.sort_by(|a, b| {
        if a.priority != b.priority {
            b.priority.cmp(&a.priority)
        } else {
            a.path_cost.partial_cmp(&b.path_cost).unwrap()
        }
    });
    jobs.iter().map(|j| j.id).collect()
}

fn main() {
    let mut grid = vec![vec![0; 6]; 6];
    grid[0][2] = 1;
    grid[1][2] = 1;
    grid[2][2] = 1;
    let c1 = astarCost(&grid, 0, 0, 5, 0);
    let c2 = astarCost(&grid, 0, 5, 5, 5);
    assert!(c1 > c2 && c2 > 0.0);
    let jobs = vec![
        ScheduledJob { id: 101, priority: 5, duration_ms: 100, path_cost: c1 },
        ScheduledJob { id: 102, priority: 10, duration_ms: 200, path_cost: c1 },
        ScheduledJob { id: 103, priority: 5, duration_ms: 150, path_cost: c2 },
    ];
    let order = scheduleJobsByPriority(jobs);
    assert_eq!(order, vec![102, 103, 101]);
    println!("Order={},{},{}\nBENCH_07_OK", order[0], order[1], order[2]);
}
