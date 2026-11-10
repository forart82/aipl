import java.nio.file.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Path p = Paths.get("/tmp/java_bench04.log");
        String sample = "2026-11-02T10:00:01Z INFO /api/login 200\n2026-11-02T10:00:02Z ERROR /api/pay 500\n2026-11-02T10:00:03Z INFO /api/pay 200\n2026-11-02T10:00:04Z WARN /api/login 429\n2026-11-02T10:00:05Z ERROR /api/pay 503\n";
        Files.writeString(p, sample);
        String loaded = Files.readString(p);
        int total = 0, errs = 0, warns = 0, infos = 0, bestCnt = 0;
        String bestEp = "";
        Map<String, Integer> counts = new HashMap<>();
        for (String line : loaded.split("\n")) {
            String t = line.trim();
            if (!t.isEmpty()) {
                total++;
                String[] cols = t.split("\\s+");
                if (cols.length >= 3) {
                    if (cols[1].equals("ERROR")) errs++;
                    else if (cols[1].equals("WARN")) warns++;
                    else if (cols[1].equals("INFO")) infos++;
                    int c = counts.getOrDefault(cols[2], 0) + 1;
                    counts.put(cols[2], c);
                    if (c > bestCnt) { bestCnt = c; bestEp = cols[2]; }
                }
            }
        }
        if (total != 5 || errs != 2 || !bestEp.equals("/api/pay")) throw new AssertionError();
        System.out.println("Total=" + total + " Errors=" + errs + " Top=" + bestEp + "\nBENCH_04_OK");
    }
}
