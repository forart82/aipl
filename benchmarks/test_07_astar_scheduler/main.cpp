#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>

struct ScheduledJob {
    int id;
    int priority;
    int durationMs;
    double pathCost;
};

double astarCost(const std::vector<std::vector<int>>& grid, int sx, int sy, int gx, int gy) {
    int h = grid.size();
    int w = grid[0].size();
    std::vector<std::vector<double>> dist(h, std::vector<double>(w, 1e9));
    std::vector<std::vector<bool>> visited(h, std::vector<bool>(w, false));
    dist[sy][sx] = 0.0;
    std::vector<std::pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    std::vector<double> costs = {1.0, 1.0, 1.0, 1.0, 1.4142, 1.4142, 1.4142, 1.4142};
    while (true) {
        double bestF = 1e9;
        int bx = -1;
        int by = -1;
        bool found = false;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (!visited[y][x] && dist[y][x] < 1e8) {
                    double f = dist[y][x] + std::sqrt((gx - x)*(gx - x) + (gy - y)*(gy - y));
                    if (f < bestF) {
                        bestF = f;
                        bx = x;
                        by = y;
                        found = true;
                    }
                }
            }
        }
        if (!found) {
            return -1.0;
        }
        if (bx == gx && by == gy) {
            return dist[by][bx];
        }
        visited[by][bx] = true;
        for (size_t i = 0; i < dirs.size(); ++i) {
            int nx = bx + dirs[i].first;
            int ny = by + dirs[i].second;
            if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
                if (grid[ny][nx] == 0 && dist[by][bx] + costs[i] < dist[ny][nx]) {
                    dist[ny][nx] = dist[by][bx] + costs[i];
                }
            }
        }
    }
}

std::vector<int> scheduleJobsByPriority(std::vector<ScheduledJob> jobs) {
    std::sort(jobs.begin(), jobs.end(), [](const ScheduledJob& a, const ScheduledJob& b) {
        if (a.priority != b.priority) {
            return a.priority > b.priority;
        }
        return a.pathCost < b.pathCost;
    });
    std::vector<int> order;
    for (const auto& j : jobs) {
        order.push_back(j.id);
    }
    return order;
}

int main() {
    std::vector<std::vector<int>> grid(6, std::vector<int>(6, 0));
    grid[0][2] = 1;
    grid[1][2] = 1;
    grid[2][2] = 1;
    double c1 = astarCost(grid, 0, 0, 5, 0);
    double c2 = astarCost(grid, 0, 5, 5, 5);
    assert(c1 > c2 && c2 > 0.0);
    std::vector<ScheduledJob> jobs = {{101, 5, 100, c1}, {102, 10, 200, c1}, {103, 5, 150, c2}};
    auto order = scheduleJobsByPriority(jobs);
    assert(order[0] == 102 && order[1] == 103 && order[2] == 101);
    std::cout << "Order=" << order[0] << "," << order[1] << "," << order[2] << "\nBENCH_07_OK\n";
    return 0;
}
