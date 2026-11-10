#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

struct EnemyGoomba { double x, y, vx; bool alive; };
struct MarioWorld {
    double px = 0, py = 0, vx = 0, vy = 0, cameraX = 0, goalX = 120, mushroomX = 40;
    bool onGround = true, mushroomTaken = false;
    int powerUp = 0, coins = 0, score = 0, lives = 3;
    std::string status = "PLAYING";
    std::vector<double> coinPositions = {30.0, 60.0, 90.0};
    std::vector<EnemyGoomba> enemies = {{50.0, 0.0, -1.0, true}};
};

void stepMarioFrame(MarioWorld& w, double moveDir, bool jump, double dt) {
    if (w.status != "PLAYING") return;
    w.vx = moveDir * 20.0;
    if (jump && w.onGround) { w.vy = 18.0; w.onGround = false; }
    w.vy -= 30.0 * dt;
    w.px += w.vx * dt;
    w.py += w.vy * dt;
    if (w.py <= 0.0) { w.py = 0.0; w.vy = 0.0; w.onGround = true; }
    if (!w.mushroomTaken && w.px >= w.mushroomX - 2.0 && w.px <= w.mushroomX + 2.0) {
        w.mushroomTaken = true; w.powerUp = 1; w.score += 1000;
    }
    std::vector<double> rem;
    for (double cx : w.coinPositions) {
        if (w.px >= cx - 2.0 && w.px <= cx + 2.0) { w.coins++; w.score += 200; }
        else rem.push_back(cx);
    }
    w.coinPositions = rem;
    for (auto& e : w.enemies) {
        if (!e.alive) continue;
        e.x += e.vx * dt;
        bool hitX = (w.px >= e.x - 2.5 && w.px <= e.x + 2.5);
        if (hitX && w.py > 0.5 && w.vy < 0.0) {
            e.alive = false; w.score += 500; w.vy = 10.0;
        } else if (hitX && w.py <= 0.5) {
            if (w.powerUp > 0) w.powerUp = 0;
            else if (--w.lives <= 0) w.status = "GAME_OVER";
        }
    }
    w.cameraX = std::max(0.0, w.px - 20.0);
    if (w.px >= w.goalX) { w.status = "LEVEL_CLEAR"; w.score += 2000; }
}

int main() {
    MarioWorld w;
    for (int f = 0; f < 40 && w.status == "PLAYING"; ++f) stepMarioFrame(w, 1.0, f == 8, 0.2);
    assert(w.status == "LEVEL_CLEAR" && w.mushroomTaken && w.powerUp == 1 && w.coins == 3 && !w.enemies[0].alive && w.score == 4100 && w.cameraX > 80.0);
    std::cout << "Mario Status=" << w.status << " Score=" << w.score << " Coins=" << w.coins << "\nBENCH_12_OK\n";
    return 0;
}
