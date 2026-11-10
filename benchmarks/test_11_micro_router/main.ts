interface HttpRequest {
  method: string;
  path: string;
  authHeader: string;
  body: string;
}

interface HttpResponse {
  status: number;
  body: string;
}

function handleRequest(req: HttpRequest, sessions: Map<string, number>): HttpResponse {
  if (req.path.startsWith("/admin") && req.authHeader !== "Bearer secret-token") {
    return { status: 401, body: "Unauthorized" };
  }
  if (req.method === "POST" && req.path === "/session/incr") {
    const user = req.body || "guest";
    const nextVal = (sessions.get(user) ?? 0) + 1;
    sessions.set(user, nextVal);
    return { status: 200, body: `user=${user} count=${nextVal}` };
  }
  if (req.method === "GET" && req.path === "/admin/status") {
    return { status: 200, body: "status=healthy" };
  }
  return { status: 404, body: "Not Found" };
}

const sessions = new Map<string, number>();
const r1 = handleRequest({ method: "POST", path: "/session/incr", authHeader: "", body: "alice" }, sessions);
const r2 = handleRequest({ method: "POST", path: "/session/incr", authHeader: "", body: "alice" }, sessions);
const r3 = handleRequest({ method: "GET", path: "/admin/status", authHeader: "bad", body: "" }, sessions);
const r4 = handleRequest({ method: "GET", path: "/admin/status", authHeader: "Bearer secret-token", body: "" }, sessions);
if (r1.status !== 200 || r2.status !== 200 || r3.status !== 401 || r4.status !== 200) {
  throw new Error("assert");
}
if (r2.body !== "user=alice count=2" || r4.body !== "status=healthy") {
  throw new Error("assert");
}
console.log(`${r2.body} | ${r4.body}\nBENCH_11_OK`);
