#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

struct Body2D {
    int id;
    double x;
    double y;
    double vx;
    double vy;
    double radius;
    double mass;
};

void stepPhysicsWorld(std::vector<Body2D>& bodies, double dt, double worldW, double worldH) {
    for (auto& b : bodies) {
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
    for (size_t i = 0; i < bodies.size(); ++i) {
        for (size_t j = i + 1; j < bodies.size(); ++j) {
            auto& a = bodies[i];
            auto& b = bodies[j];
            double dx = b.x - a.x;
            double dy = b.y - a.y;
            double distSq = dx * dx + dy * dy;
            double minDist = a.radius + b.radius;
            if (distSq < minDist * minDist && distSq > 0.0001) {
                double d = std::sqrt(distSq);
                double nx = dx / d;
                double ny = dy / d;
                double velAlongNormal = (b.vx - a.vx) * nx + (b.vy - a.vy) * ny;
                if (velAlongNormal < 0.0) {
                    double impulse = -(1.9 * velAlongNormal) / (1.0 / a.mass + 1.0 / b.mass);
                    a.vx -= (impulse / a.mass) * nx;
                    a.vy -= (impulse / a.mass) * ny;
                    b.vx += (impulse / b.mass) * nx;
                    b.vy += (impulse / b.mass) * ny;
                }
            }
        }
    }
}

int main() {
    std::vector<Body2D> world = {
        {1, 20.0, 50.0, 40.0, 0.0, 5.0, 1.0},
        {2, 28.0, 50.0, -40.0, 0.0, 5.0, 1.0}
    };
    for (int s = 0; s < 5; ++s) {
        stepPhysicsWorld(world, 0.05, 100.0, 100.0);
    }
    assert(world[0].vx < 0.0 && world[1].vx > 0.0);
    std::cout << "v0=" << static_cast<int>(std::round(world[0].vx)) << " v1=" << static_cast<int>(std::round(world[1].vx)) << "\nBENCH_10_OK\n";
    return 0;
}
