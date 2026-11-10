#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cassert>

double astarCost(const std::vector<std::vector<int>>& g, int sx, int sy, int gx, int gy) {
    int H = g.size(), W = g[0].size();
    std::vector<std::vector<double>> dist(H, std::vector<double>(W, 1e9));
    using Node = std::pair<double, std::pair<int, int>>;
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
    dist[sy][sx] = 0.0;
    pq.push({0.0, {sx, sy}});
    int dx[8] = {1,-1,0,0,1,1,-1,-1}, dy[8] = {0,0,1,-1,1,-1,1,-1};
    while (!pq.empty()) {
        auto [_, pos] = pq.top(); pq.pop();
        auto [x, y] = pos;
        if (x == gx && y == gy) return dist[y][x];
        for (int d = 0; d < 8; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < W && ny >= 0 && ny < H && g[ny][nx] == 0) {
                double step = (dx[d] != 0 && dy[d] != 0) ? 1.41421356 : 1.0;
                if (dist[y][x] + step < dist[ny][nx]) {
                    dist[ny][nx] = dist[y][x] + step;
                    pq.push({dist[ny][nx] + std::hypot(gx - nx, gy - ny), {nx, ny}});
                }
            }
        }
    }
    return -1.0;
}

struct Job { int id, priority; double pathCost; };

int main() {
    std::vector<std::vector<int>> g(6, std::vector<int>(6, 0));
    g[0][2] = g[1][2] = g[2][2] = 1;
    double c1 = astarCost(g, 0, 0, 5, 0);
    double c2 = astarCost(g, 0, 5, 5, 5);
    assert(c1 > c2 && c2 > 0);
    std::vector<Job> jobs = {{101, 5, c1}, {102, 10, c1}, {103, 5, c2}};
    std::sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        return a.priority != b.priority ? a.priority > b.priority : a.pathCost < b.pathCost;
    });
    assert(jobs[0].id == 102 && jobs[1].id == 103 && jobs[2].id == 101);
    std::cout << "Order=" << jobs[0].id << "," << jobs[1].id << "," << jobs[2].id << "\nBENCH_07_OK\n";
    return 0;
}
