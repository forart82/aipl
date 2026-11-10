import java.util.*;

public class Main {
    static String formatGreeting(String name, String role, int count) {
        return "Hello, " + name + " [" + role + "]! Welcome #" + count + " to AIPL.";
    }

    static Map<String, String> parseCliArgs(String[] args) {
        Map<String, String> map = new HashMap<>();
        for (String a : args) {
            if (a.startsWith("--") && a.contains("=")) {
                int idx = a.indexOf('=');
                map.put(a.substring(2, idx), a.substring(idx + 1));
            }
        }
        return map;
    }

    public static void main(String[] args) {
        Map<String, String> parsed = parseCliArgs(new String[]{"--name=Developer", "--role=Engineer"});
        String user = parsed.getOrDefault("name", "Developer");
        String role = parsed.getOrDefault("role", "Engineer");
        String msg1 = formatGreeting(user, role, 1);
        String msg2 = formatGreeting("Ada", "Architect", 42);
        if (!msg1.equals("Hello, Developer [Engineer]! Welcome #1 to AIPL.")) {
            throw new AssertionError();
        }
        if (!msg2.equals("Hello, Ada [Architect]! Welcome #42 to AIPL.")) {
            throw new AssertionError();
        }
        System.out.println(msg1 + "\n" + msg2 + "\nBENCH_01_OK");
    }
}
