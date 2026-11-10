use std::collections::HashMap;

struct HttpRequest {
    method: String,
    path: String,
    auth_header: String,
    body: String,
}

struct HttpResponse {
    status: i32,
    body: String,
}

#[allow(non_snake_case)]
fn handleRequest(req: &HttpRequest, sessions: &mut HashMap<String, i32>) -> HttpResponse {
    if req.path.starts_with("/admin") && req.auth_header != "Bearer secret-token" {
        return HttpResponse {
            status: 401,
            body: "Unauthorized".to_string(),
        };
    }
    if req.method == "POST" && req.path == "/session/incr" {
        let user = if req.body.is_empty() { "guest".to_string() } else { req.body.clone() };
        let count = sessions.entry(user.clone()).or_insert(0);
        *count += 1;
        return HttpResponse {
            status: 200,
            body: format!("user={} count={}", user, count),
        };
    }
    if req.method == "GET" && req.path == "/admin/status" {
        return HttpResponse {
            status: 200,
            body: "status=healthy".to_string(),
        };
    }
    HttpResponse {
        status: 404,
        body: "Not Found".to_string(),
    }
}

fn main() {
    let mut sessions = HashMap::new();
    let r1 = handleRequest(&HttpRequest {
        method: "POST".into(),
        path: "/session/incr".into(),
        auth_header: "".into(),
        body: "alice".into(),
    }, &mut sessions);
    let r2 = handleRequest(&HttpRequest {
        method: "POST".into(),
        path: "/session/incr".into(),
        auth_header: "".into(),
        body: "alice".into(),
    }, &mut sessions);
    let r3 = handleRequest(&HttpRequest {
        method: "GET".into(),
        path: "/admin/status".into(),
        auth_header: "bad".into(),
        body: "".into(),
    }, &mut sessions);
    let r4 = handleRequest(&HttpRequest {
        method: "GET".into(),
        path: "/admin/status".into(),
        auth_header: "Bearer secret-token".into(),
        body: "".into(),
    }, &mut sessions);
    assert_eq!(r1.status, 200);
    assert_eq!(r2.status, 200);
    assert_eq!(r3.status, 401);
    assert_eq!(r4.status, 200);
    assert_eq!(r2.body, "user=alice count=2");
    assert_eq!(r4.body, "status=healthy");
    println!("{} | {}\nBENCH_11_OK", r2.body, r4.body);
}
