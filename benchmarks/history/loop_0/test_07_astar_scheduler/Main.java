import java.util.*;

public class Main {
    static double astarCost(int[][] g, int sx, int sy, int gx, int gy) {
        int h = g.length, w = g[0].length;
        double[][] dist = new double[h][w];
        boolean[][] vis = new boolean[h][w];
        for (double[] r : dist) Arrays.fill(r, 1e9);
        dist[sy][sx] = 0;
        int[] dx = {1,-1,0,0,1,1,-1,-1}, dy = {0,0,1,-1,1,-1,1,-1};
        while (true) {
            double bestF = 1e9; int bx = -1, by = -1;
            for (int y = 0; y < h; y++) for (int x = 0; x < w; x++) {
                if (!vis[y][x] && dist[y][x] < 1e8) {
                    double f = dist[y][x] + Math.hypot(gx - x, gy - y);
                    if (f < bestF) { bestF = f; bx = x; by = y; }
                }
            }
            if (bx < 0) return -1;
            if (bx == gx && by == gy) return dist[by][bx];
            vis[by][bx] = true;
            for (int d = 0; d < 8; d++) {
                int nx = bx + dx[d], ny = by + dy[d];
                if (nx >= 0 && nx < w && ny >= 0 && ny < h && g[ny][nx] == 0) {
                    double step = (dx[d] != 0 && dy[d] != 0) ? 1.414 : 1.0;
                    if (dist[by][bx] + step < dist[ny][nx]) dist[ny][nx] = dist[by][bx] + step;
                }
            }
        }
    }
    public static void main(String[] args) {
        int[][] g = new int[6][6];
        g[0][2] = g[1][2] = g[2][2] = 1;
        double c1 = astarCost(g, 0, 0, 5, 0), c2 = astarCost(g, 0, 5, 5, 5);
        double[][] jobs = {{101, 5, c1}, {102, 10, c1}, {103, 5, c2}};
        Arrays.sort(jobs, (a, b) -> a[1] != b[1] ? Double.compare(b[1], a[1]) : Double.compare(a[2], b[2]));
        if ((int)jobs[0][0] != 102 || (int)jobs[1][0] != 103) throw new AssertionError();
        System.out.println("Order=" + (int)jobs[0][0] + "," + (int)jobs[1][0] + "," + (int)jobs[2][0] + "\nBENCH_07_OK");
    }
}
