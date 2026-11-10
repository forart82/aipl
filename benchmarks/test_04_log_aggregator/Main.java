import java.nio.file.*;
import java.util.*;

public class Main {
    static class LogSummary {
        int totalLines;
        int errorCount;
        int warnCount;
        int infoCount;
        String topEndpoint;
        double errorRatePct;
        LogSummary(int t, int e, int w, int i, String top, double r) {
            totalLines = t;
            errorCount = e;
            warnCount = w;
            infoCount = i;
            topEndpoint = top;
            errorRatePct = r;
        }
    }

    static LogSummary analyzeLogs(String content) {
        int total = 0;
        int errs = 0;
        int warns = 0;
        int infos = 0;
        Map<String, Integer> counts = new HashMap<>();
        String topEp = "";
        int topCnt = 0;
        for (String line : content.split("\n")) {
            String t = line.trim();
            if (!t.isEmpty()) {
                total++;
                String[] parts = t.split("\\s+");
                if (parts.length >= 3) {
                    if (parts[1].equals("ERROR")) {
                        errs++;
                    } else if (parts[1].equals("WARN")) {
                        warns++;
                    } else if (parts[1].equals("INFO")) {
                        infos++;
                    }
                    String ep = parts[2];
                    int c = counts.getOrDefault(ep, 0) + 1;
                    counts.put(ep, c);
                    if (c > topCnt) {
                        topCnt = c;
                        topEp = ep;
                    }
                }
            }
        }
        double rate = total > 0 ? (errs * 100.0) / total : 0.0;
        return new LogSummary(total, errs, warns, infos, topEp, rate);
    }

    public static void main(String[] args) throws Exception {
        Path p = Paths.get("/tmp/bench04_sample.log");
        String sample = "2026-11-02T10:00:01Z INFO /api/login 200\n2026-11-02T10:00:02Z ERROR /api/pay 500\n2026-11-02T10:00:03Z INFO /api/pay 200\n2026-11-02T10:00:04Z WARN /api/login 429\n2026-11-02T10:00:05Z ERROR /api/pay 503\n";
        Files.write(p, sample.getBytes());
        LogSummary s = analyzeLogs(new String(Files.readAllBytes(p)));
        if (s.totalLines != 5 || s.errorCount != 2 || s.warnCount != 1 || s.infoCount != 2 || !s.topEndpoint.equals("/api/pay") || s.errorRatePct < 39.9 || s.errorRatePct > 40.1) {
            throw new AssertionError();
        }
        System.out.println("Total=" + s.totalLines + " Errors=" + s.errorCount + " Top=" + s.topEndpoint + "\nBENCH_04_OK");
    }
}
