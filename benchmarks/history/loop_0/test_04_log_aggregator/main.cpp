#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cassert>

struct LogSummary {
    int totalLines, errorCount, warnCount, infoCount;
    std::string topEndpoint;
    double errorRatePct;
};

LogSummary analyzeLogs(const std::string& content) {
    int total = 0, errs = 0, warns = 0, infos = 0, bestCount = 0;
    std::string bestEp;
    std::map<std::string, int> counts;
    std::stringstream ss(content);
    std::string line;
    while (std::getline(ss, line)) {
        if (line.empty()) continue;
        total++;
        std::stringstream ls(line);
        std::string ts, lvl, ep;
        ls >> ts >> lvl >> ep;
        if (lvl == "ERROR") errs++;
        else if (lvl == "WARN") warns++;
        else if (lvl == "INFO") infos++;
        int c = ++counts[ep];
        if (c > bestCount) { bestCount = c; bestEp = ep; }
    }
    return {total, errs, warns, infos, bestEp, total > 0 ? (errs * 100.0) / total : 0.0};
}

int main() {
    std::string path = "/tmp/cpp_bench04.log";
    std::string sample = "2026-11-02T10:00:01Z INFO /api/login 200\n2026-11-02T10:00:02Z ERROR /api/pay 500\n2026-11-02T10:00:03Z INFO /api/pay 200\n2026-11-02T10:00:04Z WARN /api/login 429\n2026-11-02T10:00:05Z ERROR /api/pay 503\n";
    { std::ofstream out(path); out << sample; }
    std::ifstream in(path);
    std::stringstream buf; buf << in.rdbuf();
    auto s = analyzeLogs(buf.str());
    assert(s.totalLines == 5 && s.errorCount == 2 && s.topEndpoint == "/api/pay");
    std::cout << "Total=" << s.totalLines << " Errors=" << s.errorCount << " Top=" << s.topEndpoint << "\nBENCH_04_OK\n";
    return 0;
}
