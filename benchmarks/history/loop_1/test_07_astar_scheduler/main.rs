use std::cmp::Ordering;

fn astar_cost(grid: &[Vec<i32>], sx: usize, sy: usize, gx: usize, gy: usize) -> f64 {
    let (h, w) = (grid.len(), grid[0].len());
    let mut dist = vec![vec![1e9_f64; w]; h];
    let mut visited = vec![vec![false; w]; h];
    dist[sy][sx] = 0.0;
    let dirs: [(isize, isize, f64); 8] = [(1,0,1.0),(-1,0,1.0),(0,1,1.0),(0,-1,1.0),(1,1,1.414),(1,-1,1.414),(-1,1,1.414),(-1,-1,1.414)];
    loop {
        let (mut best_f, mut bx, mut by, mut found) = (1e9, 0, 0, false);
        for y in 0..h {
            for x in 0..w {
                if !visited[y][x] && dist[y][x] < 1e8 {
                    let f = dist[y][x] + (((gx as isize - x as isize).pow(2) + (gy as isize - y as isize).pow(2)) as f64).sqrt();
                    if f < best_f { best_f = f; bx = x; by = y; found = true; }
                }
            }
        }
        if !found { return -1.0; }
        if bx == gx && by == gy { return dist[by][bx]; }
        visited[by][bx] = true;
        for (dx, dy, cost) in dirs {
            let (nx, ny) = (bx as isize + dx, by as isize + dy);
            if nx >= 0 && nx < w as isize && ny >= 0 && ny < h as isize {
                let (ux, uy) = (nx as usize, ny as usize);
                if grid[uy][ux] == 0 && dist[by][bx] + cost < dist[uy][ux] {
                    dist[uy][ux] = dist[by][bx] + cost;
                }
            }
        }
    }
}

fn main() {
    let mut g = vec![vec![0; 6]; 6];
    g[0][2] = 1; g[1][2] = 1; g[2][2] = 1;
    let c1 = astar_cost(&g, 0, 0, 5, 0);
    let c2 = astar_cost(&g, 0, 5, 5, 5);
    assert!(c1 > c2 && c2 > 0.0);
    let mut jobs = vec![(101, 5, c1), (102, 10, c1), (103, 5, c2)];
    jobs.sort_by(|a, b| b.1.cmp(&a.1).then_with(|| a.2.partial_cmp(&b.2).unwrap_or(Ordering::Equal)));
    assert!(jobs[0].0 == 102 && jobs[1].0 == 103 && jobs[2].0 == 101);
    println!("Order={},{},{}\nBENCH_07_OK", jobs[0].0, jobs[1].0, jobs[2].0);
}
