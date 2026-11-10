import java.util.*;

public class Main {
    static class EnemyGoomba {
        double x;
        double y;
        double vx;
        boolean alive;
        EnemyGoomba(double x, double y, double vx, boolean alive) {
            this.x = x;
            this.y = y;
            this.vx = vx;
            this.alive = alive;
        }
    }

    static class MarioWorld {
        double playerX;
        double playerY;
        double playerVx;
        double playerVy;
        boolean onGround;
        int powerUpState;
        int coins;
        int score;
        int lives;
        double cameraX;
        double goalX;
        String status;
        List<Double> coinPositions;
        double mushroomX;
        boolean mushroomTaken;
        List<EnemyGoomba> enemies;
    }

    static MarioWorld createMarioLevel() {
        MarioWorld w = new MarioWorld();
        w.playerX = 0.0;
        w.playerY = 0.0;
        w.playerVx = 0.0;
        w.playerVy = 0.0;
        w.onGround = true;
        w.powerUpState = 0;
        w.coins = 0;
        w.score = 0;
        w.lives = 3;
        w.cameraX = 0.0;
        w.goalX = 120.0;
        w.status = "PLAYING";
        w.coinPositions = new ArrayList<>(Arrays.asList(30.0, 60.0, 90.0));
        w.mushroomX = 40.0;
        w.mushroomTaken = false;
        w.enemies = new ArrayList<>();
        w.enemies.add(new EnemyGoomba(50.0, 0.0, -1.0, true));
        return w;
    }

    static void stepMarioFrame(MarioWorld w, double moveDir, boolean jumpPressed, double dt) {
        if (!w.status.equals("PLAYING")) {
            return;
        }
        w.playerVx = moveDir * 20.0;
        if (jumpPressed && w.onGround) {
            w.playerVy = 18.0;
            w.onGround = false;
        }
        w.playerVy -= 30.0 * dt;
        w.playerX += w.playerVx * dt;
        w.playerY += w.playerVy * dt;
        if (w.playerY <= 0.0) {
            w.playerY = 0.0;
            w.playerVy = 0.0;
            w.onGround = true;
        }
        if (!w.mushroomTaken && Math.abs(w.playerX - w.mushroomX) <= 2.0) {
            w.mushroomTaken = true;
            w.powerUpState = 1;
            w.score += 1000;
        }
        List<Double> remCoins = new ArrayList<>();
        for (double cx : w.coinPositions) {
            if (Math.abs(w.playerX - cx) <= 2.0) {
                w.coins += 1;
                w.score += 200;
            } else {
                remCoins.add(cx);
            }
        }
        w.coinPositions = remCoins;
        for (EnemyGoomba e : w.enemies) {
            if (!e.alive) {
                continue;
            }
            e.x += e.vx * dt;
            if (Math.abs(w.playerX - e.x) <= 2.5) {
                if (w.playerY > 0.5 && w.playerVy < 0.0) {
                    e.alive = false;
                    w.score += 500;
                    w.playerVy = 10.0;
                } else if (w.playerY <= 0.5) {
                    if (w.powerUpState > 0) {
                        w.powerUpState = 0;
                    } else {
                        w.lives -= 1;
                        if (w.lives <= 0) {
                            w.status = "GAME_OVER";
                        }
                    }
                }
            }
        }
        w.cameraX = Math.max(0.0, w.playerX - 20.0);
        if (w.playerX >= w.goalX) {
            w.status = "LEVEL_CLEAR";
            w.score += 2000;
        }
    }

    public static void main(String[] args) {
        MarioWorld world = createMarioLevel();
        for (int frame = 0; frame < 40; frame++) {
            if (!world.status.equals("PLAYING")) {
                break;
            }
            stepMarioFrame(world, 1.0, frame == 8, 0.2);
        }
        if (!world.status.equals("LEVEL_CLEAR") || world.score != 4100 || world.coins != 3 || world.enemies.get(0).alive || world.cameraX <= 80.0) {
            throw new AssertionError();
        }
        System.out.println("Mario Status=" + world.status + " Score=" + world.score + " Coins=" + world.coins + "\nBENCH_12_OK");
    }
}
