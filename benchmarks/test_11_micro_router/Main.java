import java.util.*;

public class Main {
    static class HttpRequest {
        String method;
        String path;
        String authHeader;
        String body;
        HttpRequest(String m, String p, String a, String b) {
            method = m;
            path = p;
            authHeader = a;
            body = b;
        }
    }

    static class HttpResponse {
        int status;
        String body;
        HttpResponse(int s, String b) {
            status = s;
            body = b;
        }
    }

    static HttpResponse handleRequest(HttpRequest req, Map<String, Integer> sessions) {
        if (req.path.startsWith("/admin") && !req.authHeader.equals("Bearer secret-token")) {
            return new HttpResponse(401, "Unauthorized");
        }
        if (req.method.equals("POST") && req.path.equals("/session/incr")) {
            String user = req.body.isEmpty() ? "guest" : req.body;
            int nextVal = sessions.getOrDefault(user, 0) + 1;
            sessions.put(user, nextVal);
            return new HttpResponse(200, "user=" + user + " count=" + nextVal);
        }
        if (req.method.equals("GET") && req.path.equals("/admin/status")) {
            return new HttpResponse(200, "status=healthy");
        }
        return new HttpResponse(404, "Not Found");
    }

    public static void main(String[] args) {
        Map<String, Integer> sessions = new HashMap<>();
        HttpResponse r1 = handleRequest(new HttpRequest("POST", "/session/incr", "", "alice"), sessions);
        HttpResponse r2 = handleRequest(new HttpRequest("POST", "/session/incr", "", "alice"), sessions);
        HttpResponse r3 = handleRequest(new HttpRequest("GET", "/admin/status", "bad", ""), sessions);
        HttpResponse r4 = handleRequest(new HttpRequest("GET", "/admin/status", "Bearer secret-token", ""), sessions);
        if (r1.status != 200 || r2.status != 200 || r3.status != 401 || r4.status != 200) {
            throw new AssertionError();
        }
        if (!r2.body.equals("user=alice count=2") || !r4.body.equals("status=healthy")) {
            throw new AssertionError();
        }
        System.out.println(r2.body + " | " + r4.body + "\nBENCH_11_OK");
    }
}
