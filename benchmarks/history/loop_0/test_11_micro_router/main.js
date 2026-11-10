function handleRequest(req, sessions) {
  if (req.path.startsWith("/admin") && req.auth !== "Bearer secret-token") return { status: 401, body: "Unauthorized" };
  if (req.method === "POST" && req.path === "/session/incr") {
    const c = (sessions.get(req.body) || 0) + 1;
    sessions.set(req.body, c);
    return { status: 200, body: `user=${req.body} count=${c}` };
  }
  if (req.method === "GET" && req.path === "/admin/status") return { status: 200, body: "status=healthy" };
  return { status: 404, body: "Not Found" };
}
const s = new Map();
handleRequest({ method: "POST", path: "/session/incr", auth: "", body: "alice" }, s);
const r2 = handleRequest({ method: "POST", path: "/session/incr", auth: "", body: "alice" }, s);
const r3 = handleRequest({ method: "GET", path: "/admin/status", auth: "bad", body: "" }, s);
const r4 = handleRequest({ method: "GET", path: "/admin/status", auth: "Bearer secret-token", body: "" }, s);
if (r2.body !== "user=alice count=2" || r3.status !== 401 || r4.status !== 200) throw new Error("assert");
console.log(`${r2.body} | ${r4.body}\nBENCH_11_OK`);
