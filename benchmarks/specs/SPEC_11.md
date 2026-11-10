# SPEC_11: Micro-Router & Stateful Protocol Handler (`test_11_micro_router`)

- **Tier**: Very Complex
- **Category**: HTTP Request Routing, Bearer Auth Middleware & Session State

## 1. Functional Requirements
1. Define `HttpRequest(method: str, path: str, authHeader: str, body: str)` and `HttpResponse(status: int, body: str)`.
2. Implement `handleRequest(req, sessions)`:
   - Middleware guard: if `req.path` starts with `"/admin"` and `req.authHeader != "Bearer secret-token"`, return `HttpResponse(401, "Unauthorized")`.
   - Route `POST /session/incr`: let `user = req.body` (or `"guest"` if empty), increment `sessions[user]` (default `0`), return `HttpResponse(200, "user={user} count={nextVal}")`.
   - Route `GET /admin/status`: return `HttpResponse(200, "status=healthy")`.
   - Fallback: return `HttpResponse(404, "Not Found")`.
3. Execute 4 requests (`POST /session/incr` twice for `"alice"`, `GET /admin/status` with invalid token, `GET /admin/status` with valid token), assert statuses (`200`, `200`, `401`, `200`) and bodies, and print `"{r2.body} | {r4.body}"` followed by `BENCH_11_OK`.

## 2. Structural & Algorithmic Parity (Rule B)
- **Normalized Identifiers**: `HttpRequest`, `HttpResponse`, `handleRequest`, `sessions`, `r1`, `r2`, `r3`, `r4`.

## 3. Expected Deterministic Stdout
```text
user=alice count=2 | status=healthy
BENCH_11_OK
```
