import java.util.*;

public class Main {
    static class Res { int status; String body; Res(int s, String b) { status = s; body = b; } }
    static Res handle(String method, String path, String auth, String body, Map<String, Integer> s) {
        if (path.startsWith("/admin") && !auth.equals("Bearer secret-token")) return new Res(401, "Unauthorized");
        if (method.equals("POST") && path.equals("/session/incr")) {
            int c = s.getOrDefault(body, 0) + 1;
            s.put(body, c);
            return new Res(200, "user=" + body + " count=" + c);
        }
        if (method.equals("GET") && path.equals("/admin/status")) return new Res(200, "status=healthy");
        return new Res(404, "Not Found");
    }
    public static void main(String[] args) {
        Map<String, Integer> s = new HashMap<>();
        handle("POST", "/session/incr", "", "alice", s);
        Res r2 = handle("POST", "/session/incr", "", "alice", s);
        Res r3 = handle("GET", "/admin/status", "bad", "", s);
        Res r4 = handle("GET", "/admin/status", "Bearer secret-token", "", s);
        if (!r2.body.equals("user=alice count=2") || r3.status != 401 || r4.status != 200) throw new AssertionError();
        System.out.println(r2.body + " | " + r4.body + "\nBENCH_11_OK");
    }
}
