from dataclasses import dataclass

@dataclass
class HttpRequest:
    method: str
    path: str
    authHeader: str
    body: str

@dataclass
class HttpResponse:
    status: int
    body: str

def handleRequest(req: HttpRequest, sessions: dict[str, int]) -> HttpResponse:
    if req.path.startswith("/admin") and req.authHeader != "Bearer secret-token":
        return HttpResponse(401, "Unauthorized")
    if req.method == "POST" and req.path == "/session/incr":
        user = req.body if req.body else "guest"
        count = sessions.get(user, 0) + 1
        sessions[user] = count
        return HttpResponse(200, f"user={user} count={count}")
    if req.method == "GET" and req.path == "/admin/status":
        return HttpResponse(200, "status=healthy")
    return HttpResponse(404, "Not Found")

sessions: dict[str, int] = {}
r1 = handleRequest(HttpRequest("POST", "/session/incr", "", "alice"), sessions)
r2 = handleRequest(HttpRequest("POST", "/session/incr", "", "alice"), sessions)
r3 = handleRequest(HttpRequest("GET", "/admin/status", "bad", ""), sessions)
r4 = handleRequest(HttpRequest("GET", "/admin/status", "Bearer secret-token", ""), sessions)
assert r1.status == 200 and r2.status == 200
assert r3.status == 401 and r4.status == 200
assert r2.body == "user=alice count=2"
assert r4.body == "status=healthy"
print(f"{r2.body} | {r4.body}\nBENCH_11_OK")
