def handle_request(method: str, path: str, auth: str, body: str, sessions: dict[str, int]) -> tuple[int, str]:
    if path.startswith("/admin") and auth != "Bearer secret-token":
        return 401, "Unauthorized"
    if method == "POST" and path == "/session/incr":
        sessions[body] = sessions.get(body, 0) + 1
        return 200, f"user={body} count={sessions[body]}"
    if method == "GET" and path == "/admin/status":
        return 200, "status=healthy"
    return 404, "Not Found"

s: dict[str, int] = {}
handle_request("POST", "/session/incr", "", "alice", s)
_, b2 = handle_request("POST", "/session/incr", "", "alice", s)
c3, _ = handle_request("GET", "/admin/status", "bad", "", s)
c4, b4 = handle_request("GET", "/admin/status", "Bearer secret-token", "", s)
assert b2 == "user=alice count=2" and c3 == 401 and c4 == 200
print(f"{b2} | {b4}\nBENCH_11_OK")
