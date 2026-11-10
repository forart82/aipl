import java.util.*;

public class Main {
    static class ConfigRecord {
        String service; int port; boolean tls; List<String> tags;
        ConfigRecord(String s, int p, boolean t, List<String> tg) { service = s; port = p; tls = t; tags = tg; }
    }

    static List<ConfigRecord> parseRecords(String src) {
        List<ConfigRecord> out = new ArrayList<>();
        for (String line : src.split("\n")) {
            String t = line.trim();
            if (!t.isEmpty() && !t.startsWith("#")) {
                String[] parts = t.split("\\|");
                if (parts.length >= 4) {
                    out.add(new ConfigRecord(parts[0].trim(), Integer.parseInt(parts[1].trim()),
                        parts[2].trim().equals("true"), Arrays.asList(parts[3].trim().split(","))));
                }
            }
        }
        return out;
    }

    static List<ConfigRecord> validateAndMutate(List<ConfigRecord> records) {
        List<ConfigRecord> out = new ArrayList<>();
        for (ConfigRecord r : records) {
            if (!r.service.isEmpty() && r.port > 0 && r.port <= 65535) {
                List<String> tags = new ArrayList<>();
                for (String tg : r.tags) tags.add(tg.trim());
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
            for (String tg : r.tags) q.add("\"" + tg + "\"");
            items.add("{\"service\":\"" + r.service + "\",\"port\":" + r.port + ",\"tls\":" + r.tls + ",\"tags\":[" + String.join(",", q) + "]}");
        }
        return "[" + String.join(",", items) + "]";
    }

    public static void main(String[] args) {
        String raw = "# Services\nauth | 8000 | false | core,jwt\ngateway | 8080 | true | edge,http\ninvalid | -5 | false | bad\n";
        List<ConfigRecord> parsed = parseRecords(raw);
        List<ConfigRecord> valid = validateAndMutate(parsed);
        String jsonOut = serializeJson(valid);
        if (parsed.size() != 3 || valid.size() != 2 || !jsonOut.contains("\"service\":\"auth\"")) throw new AssertionError();
        System.out.println(jsonOut + "\nBENCH_03_OK");
    }
}
