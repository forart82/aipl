#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cassert>

std::string formatGreeting(const std::string& name, const std::string& role, int count) {
    return "Hello, " + name + " [" + role + "]! Welcome #" + std::to_string(count) + " to AIPL.";
}

std::map<std::string, std::string> parseCliArgs(const std::vector<std::string>& args) {
    std::map<std::string, std::string> opts;
    for (const auto& a : args) {
        if (a.rfind("--", 0) == 0) {
            auto eq = a.find('=');
            if (eq != std::string::npos) {
                opts[a.substr(2, eq - 2)] = a.substr(eq + 1);
            }
        }
    }
    return opts;
}

int main() {
    auto parsed = parseCliArgs({"--name=Developer", "--role=Engineer"});
    std::string user = parsed.count("name") ? parsed["name"] : "Developer";
    std::string role = parsed.count("role") ? parsed["role"] : "Engineer";
    std::string msg1 = formatGreeting(user, role, 1);
    std::string msg2 = formatGreeting("Ada", "Architect", 42);
    assert(msg1 == "Hello, Developer [Engineer]! Welcome #1 to AIPL.");
    assert(msg2 == "Hello, Ada [Architect]! Welcome #42 to AIPL.");
    std::cout << msg1 << "\n" << msg2 << "\nBENCH_01_OK\n";
    return 0;
}
