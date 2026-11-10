public class Main {
    static class Body2D {
        int id; double x, y, vx, vy, r, m;
        Body2D(int i, double x, double y, double vx, double vy, double r, double m) {
            this.id = i; this.x = x; this.y = y; this.vx = vx; this.vy = vy; this.r = r; this.m = m;
        }
    }
    static void step(Body2D[] bs, double dt) {
        for (Body2D b : bs) { b.vy += 9.8 * dt; b.x += b.vx * dt; b.y += b.vy * dt; }
        for (int i = 0; i < bs.length; i++) for (int j = i + 1; j < bs.length; j++) {
            Body2D a = bs[i], b = bs[j];
            double dx = b.x - a.x, dy = b.y - a.y, d2 = dx*dx + dy*dy, minD = a.r + b.r;
            if (d2 < minD * minD && d2 > 1e-4) {
                double d = Math.sqrt(d2), nx = dx / d, ny = dy / d;
                double vn = (b.vx - a.vx)*nx + (b.vy - a.vy)*ny;
                if (vn < 0) {
                    double imp = -(1.9 * vn) / (1/a.m + 1/b.m);
                    a.vx -= (imp / a.m) * nx; b.vx += (imp / b.m) * nx;
                }
            }
        }
    }
    public static void main(String[] args) {
        Body2D[] w = { new Body2D(1, 20, 50, 40, 0, 5, 1), new Body2D(2, 28, 50, -40, 0, 5, 1) };
        for (int s = 0; s < 5; s++) step(w, 0.05);
        if (w[0].vx >= 0 || w[1].vx <= 0) throw new AssertionError();
        System.out.println("v0=" + w[0].vx + " v1=" + w[1].vx + "\nBENCH_10_OK");
    }
}
