import java.util.*;

public class Main {
    static class Goomba { double x = 50, vx = -1; boolean alive = true; }
    public static void main(String[] args) {
        double px = 0, py = 0, vx = 0, vy = 0, camX = 0, goalX = 120, mushX = 40;
        boolean onGround = true, mushTaken = false;
        int power = 0, coins = 0, score = 0, lives = 3;
        String status = "PLAYING";
        List<Double> coinPos = new ArrayList<>(Arrays.asList(30.0, 60.0, 90.0));
        Goomba g = new Goomba();
        for (int f = 0; f < 40 && status.equals("PLAYING"); f++) {
            double dt = 0.2;
            vx = 20.0;
            if (f == 8 && onGround) { vy = 18.0; onGround = false; }
            vy -= 30.0 * dt; px += vx * dt; py += vy * dt;
            if (py <= 0) { py = 0; vy = 0; onGround = true; }
            if (!mushTaken && Math.abs(px - mushX) <= 2.0) { mushTaken = true; power = 1; score += 1000; }
            Iterator<Double> it = coinPos.iterator();
            while (it.hasNext()) {
                if (Math.abs(px - it.next()) <= 2.0) { coins++; score += 200; it.remove(); }
            }
            if (g.alive) {
                g.x += g.vx * dt;
                if (Math.abs(px - g.x) <= 2.5 && py > 0.5 && vy < 0) { g.alive = false; score += 500; vy = 10.0; }
            }
            camX = Math.max(0, px - 20.0);
            if (px >= goalX) { status = "LEVEL_CLEAR"; score += 2000; }
        }
        if (!status.equals("LEVEL_CLEAR") || score != 4100 || coins != 3 || g.alive || camX <= 80.0) throw new AssertionError();
        System.out.println("Mario Status=" + status + " Score=" + score + " Coins=" + coins + "\nBENCH_12_OK");
    }
}
