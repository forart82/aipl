use std::collections::HashMap;

struct HttpRequest<'a> { method: &'a str, path: &'a str, auth: &'a str, body: &'a str }
struct HttpResponse { status: i32, body: String }

fn handle_request(req: HttpRequest, sessions: &mut HashMap<String, i32>) -> HttpResponse {
    if req.path.starts_with("/admin") && req.auth != "Bearer secret-token" {
        return HttpResponse { status: 401, body: "Unauthorized".into() };
    }
    if req.method == "POST" && req.path == "/session/incr" {
        let u = if req.body.is_empty() { "guest" } else { req.body };
        let c = sessions.entry(u.into()).and_modify(|v| *v += 1).or_insert(1);
        return HttpResponse { status: 200, body: format!("user={} count={}", u, c) };
    }
    if req.method == "GET" && req.path == "/admin/status" {
        return HttpResponse { status: 200, body: "status=healthy".into() };
    }
    HttpResponse { status: 404, body: "Not Found".into() }
}

fn main() {
    let mut sessions = HashMap::new();
    let r1 = handle_request(HttpRequest { method: "POST", path: "/session/incr", auth: "", body: "alice" }, &mut sessions);
    let r2 = handle_request(HttpRequest { method: "POST", path: "/session/incr", auth: "", body: "alice" }, &mut sessions);
    let r3 = handle_request(HttpRequest { method: "GET", path: "/admin/status", auth: "bad", body: "" }, &mut sessions);
    let r4 = handle_request(HttpRequest { method: "GET", path: "/admin/status", auth: "Bearer secret-token", body: "" }, &mut sessions);
    assert!(r1.status == 200 && r2.body == "user=alice count=2" && r3.status == 401 && r4.status == 200);
    println!("{} | {}\nBENCH_11_OK", r2.body, r4.body);
}
