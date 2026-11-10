package main

import (
	"fmt"
	"strings"
)

type HttpRequest struct {
	method     string
	path       string
	authHeader string
	body       string
}

type HttpResponse struct {
	status int
	body   string
}

func handleRequest(req HttpRequest, sessions map[string]int) HttpResponse {
	if strings.HasPrefix(req.path, "/admin") && req.authHeader != "Bearer secret-token" {
		return HttpResponse{401, "Unauthorized"}
	}
	if req.method == "POST" && req.path == "/session/incr" {
		user := req.body
		if len(user) == 0 {
			user = "guest"
		}
		sessions[user]++
		return HttpResponse{200, fmt.Sprintf("user=%s count=%d", user, sessions[user])}
	}
	if req.method == "GET" && req.path == "/admin/status" {
		return HttpResponse{200, "status=healthy"}
	}
	return HttpResponse{404, "Not Found"}
}

func main() {
	sessions := make(map[string]int)
	r1 := handleRequest(HttpRequest{"POST", "/session/incr", "", "alice"}, sessions)
	r2 := handleRequest(HttpRequest{"POST", "/session/incr", "", "alice"}, sessions)
	r3 := handleRequest(HttpRequest{"GET", "/admin/status", "bad", ""}, sessions)
	r4 := handleRequest(HttpRequest{"GET", "/admin/status", "Bearer secret-token", ""}, sessions)
	if r1.status != 200 || r2.status != 200 || r3.status != 401 || r4.status != 200 {
		panic("assert status")
	}
	if r2.body != "user=alice count=2" || r4.body != "status=healthy" {
		panic("assert body")
	}
	fmt.Printf("%s | %s\nBENCH_11_OK\n", r2.body, r4.body)
}
