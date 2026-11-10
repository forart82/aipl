#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>

struct ConfigRecord {
    std::string service;
    int port;
    bool tls;
    std::vector<std::string> tags;
};

static std::string trim(const std::string& s) {
    size_t a = s.find_first_not_of(" \t\r\n");
    if (a == std::string::npos) return "";
    size_t b = s.find_last_not_of(" \t\r\n");
    return s.substr(a, b - a + 1);
}

static std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> out;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) out.push_back(item);
    return out;
}

std::vector<ConfigRecord> parseRecords(const std::string& src) {
    std::vector<ConfigRecord> out;
    for (const auto& line : split(src, '\n')) {
        std::string t = trim(line);
        if (!t.empty() && t[0] != '#') {
            auto parts = split(t, '|');
            if (parts.size() >= 4) {
                out.push_back({trim(parts[0]), std::stoi(trim(parts[1])), trim(parts[2]) == "true", split(trim(parts[3]), ',')});
            }
        }
    }
    return out;
}

std::vector<ConfigRecord> validateAndMutate(const std::vector<ConfigRecord>& records) {
    std::vector<ConfigRecord> out;
    for (const auto& r : records) {
        if (!r.service.empty() && r.port > 0 && r.port <= 65535) {
            std::vector<std::string> tags;
            for (const auto& tg : r.tags) tags.push_back(trim(tg));
            tags.push_back("verified");
            out.push_back({r.service, r.port + 100, true, tags});
        }
    }
    return out;
}

std::string serializeJson(const std::vector<ConfigRecord>& records) {
    std::string out = "[";
    for (size_t i = 0; i < records.size(); ++i) {
        if (i > 0) out += ",";
        const auto& r = records[i];
        out += "{\"service\":\"" + r.service + "\",\"port\":" + std::to_string(r.port) + ",\"tls\":" + (r.tls ? "true" : "false") + ",\"tags\":[";
        for (size_t j = 0; j < r.tags.size(); ++j) {
            if (j > 0) out += ",";
            out += "\"" + r.tags[j] + "\"";
        }
        out += "]}";
    }
    return out + "]";
}

int main() {
    std::string raw = "# Services\nauth | 8000 | false | core,jwt\ngateway | 8080 | true | edge,http\ninvalid | -5 | false | bad\n";
    auto parsed = parseRecords(raw);
    assert(parsed.size() == 3);
    auto valid = validateAndMutate(parsed);
    assert(valid.size() == 2 && valid[0].port == 8100 && valid[0].tls);
    std::string jsonOut = serializeJson(valid);
    assert(jsonOut.find("\"service\":\"auth\"") != std::string::npos);
    std::cout << jsonOut << "\nBENCH_03_OK\n";
    return 0;
}
