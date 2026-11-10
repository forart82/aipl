#include <iostream>
#include <string>
#include <map>
#include <cassert>

struct HttpRequest {
    std::string method;
    std::string path;
    std::string authHeader;
    std::string body;
};

struct HttpResponse {
    int status;
    std::string body;
};

HttpResponse handleRequest(const HttpRequest& req, std::map<std::string, int>& sessions) {
    if (req.path.rfind("/admin", 0) == 0 && req.authHeader != "Bearer secret-token") {
        return {401, "Unauthorized"};
    }
    if (req.method == "POST" && req.path == "/session/incr") {
        std::string user = req.body.empty() ? "guest" : req.body;
        int nextVal = ++sessions[user];
        return {200, "user=" + user + " count=" + std::to_string(nextVal)};
    }
    if (req.method == "GET" && req.path == "/admin/status") {
        return {200, "status=healthy"};
    }
    return {404, "Not Found"};
}

int main() {
    std::map<std::string, int> sessions;
    auto r1 = handleRequest({"POST", "/session/incr", "", "alice"}, sessions);
    auto r2 = handleRequest({"POST", "/session/incr", "", "alice"}, sessions);
    auto r3 = handleRequest({"GET", "/admin/status", "bad", ""}, sessions);
    auto r4 = handleRequest({"GET", "/admin/status", "Bearer secret-token", ""}, sessions);
    assert(r1.status == 200 && r2.status == 200);
    assert(r3.status == 401 && r4.status == 200);
    assert(r2.body == "user=alice count=2");
    assert(r4.body == "status=healthy");
    std::cout << r2.body << " | " << r4.body << "\nBENCH_11_OK\n";
    return 0;
}
