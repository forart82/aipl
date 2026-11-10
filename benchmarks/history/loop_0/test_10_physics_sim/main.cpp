#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

struct Body2D { int id; double x, y, vx, vy, radius, mass; };

void stepPhysicsWorld(std::vector<Body2D>& bodies, double dt, double W, double H) {
    for (auto& b : bodies) {
        b.vy += 9.8 * dt;
        b.x += b.vx * dt;
        b.y += b.vy * dt;
        if (b.x - b.radius < 0) { b.x = b.radius; b.vx = -b.vx * 0.9; }
        else if (b.x + b.radius > W) { b.x = W - b.radius; b.vx = -b.vx * 0.9; }
        if (b.y + b.radius > H) { b.y = H - b.radius; b.vy = -b.vy * 0.85; }
    }
    for (size_t i = 0; i < bodies.size(); ++i) {
        for (size_t j = i + 1; j < bodies.size(); ++j) {
            auto &a = bodies[i], &b = bodies[j];
            double dx = b.x - a.x, dy = b.y - a.y, d2 = dx*dx + dy*dy, minD = a.radius + b.radius;
            if (d2 < minD * minD && d2 > 1e-4) {
                double d = std::sqrt(d2), nx = dx / d, ny = dy / d;
                double vn = (b.vx - a.vx)*nx + (b.vy - a.vy)*ny;
                if (vn < 0) {
                    double imp = -(1.9 * vn) / (1.0/a.mass + 1.0/b.mass);
                    a.vx -= (imp / a.mass) * nx; a.vy -= (imp / a.mass) * ny;
                    b.vx += (imp / b.mass) * nx; b.vy += (imp / b.mass) * ny;
                }
            }
        }
    }
}

int main() {
    std::vector<Body2D> world = {{1, 20, 50, 40, 0, 5, 1}, {2, 28, 50, -40, 0, 5, 1}};
    for (int s = 0; s < 5; ++s) stepPhysicsWorld(world, 0.05, 100, 100);
    assert(world[0].vx < 0 && world[1].vx > 0);
    std::cout << "v0=" << world[0].vx << " v1=" << world[1].vx << "\nBENCH_10_OK\n";
    return 0;
}
