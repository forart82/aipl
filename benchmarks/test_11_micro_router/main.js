class HttpRequest {
  constructor(method, path, authHeader, body) {
    this.method = method;
    this.path = path;
    this.authHeader = authHeader;
    this.body = body;
  }
}

class HttpResponse {
  constructor(status, body) {
    this.status = status;
    this.body = body;
  }
}

function handleRequest(req, sessions) {
  if (req.path.startsWith("/admin") && req.authHeader !== "Bearer secret-token") {
    return new HttpResponse(401, "Unauthorized");
  }
  if (req.method === "POST" && req.path === "/session/incr") {
    const user = req.body || "guest";
    const nextVal = (sessions.get(user) || 0) + 1;
    sessions.set(user, nextVal);
    return new HttpResponse(200, `user=${user} count=${nextVal}`);
  }
  if (req.method === "GET" && req.path === "/admin/status") {
    return new HttpResponse(200, "status=healthy");
  }
  return new HttpResponse(404, "Not Found");
}

const sessions = new Map();
const r1 = handleRequest(new HttpRequest("POST", "/session/incr", "", "alice"), sessions);
const r2 = handleRequest(new HttpRequest("POST", "/session/incr", "", "alice"), sessions);
const r3 = handleRequest(new HttpRequest("GET", "/admin/status", "bad", ""), sessions);
const r4 = handleRequest(new HttpRequest("GET", "/admin/status", "Bearer secret-token", ""), sessions);
if (r1.status !== 200 || r2.status !== 200 || r3.status !== 401 || r4.status !== 200) {
  throw new Error("assert");
}
if (r2.body !== "user=alice count=2" || r4.body !== "status=healthy") {
  throw new Error("assert");
}
console.log(`${r2.body} | ${r4.body}\nBENCH_11_OK`);
