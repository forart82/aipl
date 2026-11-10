import java.util.*;

public class Main {
    static class Body2D {
        int id;
        double x;
        double y;
        double vx;
        double vy;
        double radius;
        double mass;
        Body2D(int id, double x, double y, double vx, double vy, double radius, double mass) {
            this.id = id;
            this.x = x;
            this.y = y;
            this.vx = vx;
            this.vy = vy;
            this.radius = radius;
            this.mass = mass;
        }
    }

    static void stepPhysicsWorld(List<Body2D> bodies, double dt, double worldW, double worldH) {
        for (Body2D b : bodies) {
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
        int n = bodies.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                Body2D a = bodies.get(i);
                Body2D b = bodies.get(j);
                double dx = b.x - a.x;
                double dy = b.y - a.y;
                double distSq = dx * dx + dy * dy;
                double minDist = a.radius + b.radius;
                if (distSq < minDist * minDist && distSq > 0.0001) {
                    double d = Math.sqrt(distSq);
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

    public static void main(String[] args) {
        List<Body2D> world = new ArrayList<>();
        world.add(new Body2D(1, 20.0, 50.0, 40.0, 0.0, 5.0, 1.0));
        world.add(new Body2D(2, 28.0, 50.0, -40.0, 0.0, 5.0, 1.0));
        for (int s = 0; s < 5; s++) {
            stepPhysicsWorld(world, 0.05, 100.0, 100.0);
        }
        if (world.get(0).vx >= 0.0 || world.get(1).vx <= 0.0) {
            throw new AssertionError();
        }
        System.out.println("v0=" + (int)Math.round(world.get(0).vx) + " v1=" + (int)Math.round(world.get(1).vx) + "\nBENCH_10_OK");
    }
}
