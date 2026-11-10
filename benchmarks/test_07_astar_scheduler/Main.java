import java.util.*;

public class Main {
    static class ScheduledJob {
        int id;
        int priority;
        int durationMs;
        double pathCost;
        ScheduledJob(int id, int priority, int durationMs, double pathCost) {
            this.id = id;
            this.priority = priority;
            this.durationMs = durationMs;
            this.pathCost = pathCost;
        }
    }

    static double astarCost(int[][] g, int sx, int sy, int gx, int gy) {
        int h = g.length;
        int w = g[0].length;
        double[][] dist = new double[h][w];
        boolean[][] visited = new boolean[h][w];
        for (int i = 0; i < h; i++) {
            Arrays.fill(dist[i], 1e9);
        }
        dist[sy][sx] = 0.0;
        int[][] dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
        double[] costs = {1.0, 1.0, 1.0, 1.0, 1.4142, 1.4142, 1.4142, 1.4142};
        while (true) {
            double bestF = 1e9;
            int bx = -1;
            int by = -1;
            boolean found = false;
            for (int y = 0; y < h; y++) {
                for (int x = 0; x < w; x++) {
                    if (!visited[y][x] && dist[y][x] < 1e8) {
                        double f = dist[y][x] + Math.sqrt((gx - x)*(gx - x) + (gy - y)*(gy - y));
                        if (f < bestF) {
                            bestF = f;
                            bx = x;
                            by = y;
                            found = true;
                        }
                    }
                }
            }
            if (!found) return -1.0;
            if (bx == gx && by == gy) return dist[by][bx];
            visited[by][bx] = true;
            for (int i = 0; i < dirs.length; i++) {
                int nx = bx + dirs[i][0];
                int ny = by + dirs[i][1];
                if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
                    if (g[ny][nx] == 0 && dist[by][bx] + costs[i] < dist[ny][nx]) {
                        dist[ny][nx] = dist[by][bx] + costs[i];
                    }
                }
            }
        }
    }

    static List<Integer> scheduleJobsByPriority(List<ScheduledJob> jobs) {
        List<ScheduledJob> sorted = new ArrayList<>(jobs);
        sorted.sort((a, b) -> {
            if (a.priority != b.priority) {
                return Integer.compare(b.priority, a.priority);
            }
            return Double.compare(a.pathCost, b.pathCost);
        });
        List<Integer> order = new ArrayList<>();
        for (ScheduledJob j : sorted) {
            order.add(j.id);
        }
        return order;
    }

    public static void main(String[] args) {
        int[][] g = new int[6][6];
        g[0][2] = 1;
        g[1][2] = 1;
        g[2][2] = 1;
        double c1 = astarCost(g, 0, 0, 5, 0);
        double c2 = astarCost(g, 0, 5, 5, 5);
        if (c1 <= c2 || c2 <= 0.0) throw new AssertionError();
        List<ScheduledJob> jobs = Arrays.asList(
            new ScheduledJob(101, 5, 100, c1),
            new ScheduledJob(102, 10, 200, c1),
            new ScheduledJob(103, 5, 150, c2)
        );
        List<Integer> order = scheduleJobsByPriority(jobs);
        if (order.get(0) != 102 || order.get(1) != 103 || order.get(2) != 101) throw new AssertionError();
        System.out.println("Order=" + order.get(0) + "," + order.get(1) + "," + order.get(2) + "\nBENCH_07_OK");
    }
}
