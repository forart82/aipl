package main

import (
	"fmt"
	"strings"
)

type HttpRequest struct{ method, path, auth, body string }
type HttpResponse struct {
	status int
	body   string
}

func handleRequest(req HttpRequest, sessions map[string]int) HttpResponse {
	if strings.HasPrefix(req.path, "/admin") && req.auth != "Bearer secret-token" {
		return HttpResponse{401, "Unauthorized"}
	}
	if req.method == "POST" && req.path == "/session/incr" {
		sessions[req.body]++
		return HttpResponse{200, fmt.Sprintf("user=%s count=%d", req.body, sessions[req.body])}
	}
	if req.method == "GET" && req.path == "/admin/status" {
		return HttpResponse{200, "status=healthy"}
	}
	return HttpResponse{404, "Not Found"}
}

func main() {
	s := map[string]int{}
	_ = handleRequest(HttpRequest{"POST", "/session/incr", "", "alice"}, s)
	r2 := handleRequest(HttpRequest{"POST", "/session/incr", "", "alice"}, s)
	r3 := handleRequest(HttpRequest{"GET", "/admin/status", "bad", ""}, s)
	r4 := handleRequest(HttpRequest{"GET", "/admin/status", "Bearer secret-token", ""}, s)
	if r3.status != 401 || r4.status != 200 { panic("assert") }
	fmt.Printf("%s | %s\nBENCH_11_OK\n", r2.body, r4.body)
}
