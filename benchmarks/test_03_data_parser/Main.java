import java.util.*;

public class Main {
    static class ConfigRecord {
        String service;
        int port;
        boolean tls;
        List<String> tags;
        ConfigRecord(String service, int port, boolean tls, List<String> tags) {
            this.service = service;
            this.port = port;
            this.tls = tls;
            this.tags = tags;
        }
    }

    static List<ConfigRecord> parseRecords(String src) {
        List<ConfigRecord> out = new ArrayList<>();
        for (String line : src.split("\n")) {
            String t = line.trim();
            if (!t.isEmpty() && !t.startsWith("#")) {
                String[] parts = t.split("\\|");
                if (parts.length >= 4) {
                    String svc = parts[0].trim();
                    int port = Integer.parseInt(parts[1].trim());
                    boolean tls = parts[2].trim().equals("true");
                    List<String> tags = new ArrayList<>();
                    for (String tg : parts[3].trim().split(",")) {
                        tags.add(tg.trim());
                    }
                    out.add(new ConfigRecord(svc, port, tls, tags));
                }
            }
        }
        return out;
    }

    static List<ConfigRecord> validateAndMutate(List<ConfigRecord> records) {
        List<ConfigRecord> out = new ArrayList<>();
        for (ConfigRecord r : records) {
            if (!r.service.isEmpty() && r.port > 0 && r.port <= 65535) {
                List<String> tags = new ArrayList<>(r.tags);
                tags.add("verified");
                out.add(new ConfigRecord(r.service, r.port + 100, true, tags));
            }
        }
        return out;
    }

    static String serializeJson(List<ConfigRecord> records) {
        List<String> items = new ArrayList<>();
        for (ConfigRecord r : records) {
            List<String> q = new ArrayList<>();
            for (String t : r.tags) {
                q.add("\"" + t + "\"");
            }
            items.add("{\"service\":\"" + r.service + "\",\"port\":" + r.port + ",\"tls\":" + r.tls + ",\"tags\":[" + String.join(",", q) + "]}");
        }
        return "[" + String.join(",", items) + "]";
    }

    public static void main(String[] args) {
        String raw = "# Services\nauth | 8000 | false | core,jwt\ngateway | 8080 | true | edge,http\ninvalid | -5 | false | bad\n";
        List<ConfigRecord> parsed = parseRecords(raw);
        List<ConfigRecord> valid = validateAndMutate(parsed);
        String jsonOut = serializeJson(valid);
        if (parsed.size() != 3 || valid.size() != 2 || !jsonOut.contains("\"service\":\"auth\"")) {
            throw new AssertionError();
        }
        System.out.println(jsonOut + "\nBENCH_03_OK");
    }
}
