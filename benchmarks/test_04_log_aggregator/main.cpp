#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cassert>

struct LogSummary {
    int totalLines;
    int errorCount;
    int warnCount;
    int infoCount;
    std::string topEndpoint;
    double errorRatePct;
};

LogSummary analyzeLogs(const std::string& content) {
    std::stringstream ss(content);
    std::string line;
    int total = 0;
    int errs = 0;
    int warns = 0;
    int infos = 0;
    std::map<std::string, int> counts;
    std::string topEp = "";
    int topCnt = 0;
    while (std::getline(ss, line)) {
        if (line.empty()) {
            continue;
        }
        total += 1;
        std::stringstream ls(line);
        std::string ts, lvl, ep;
        int status;
        if (ls >> ts >> lvl >> ep >> status) {
            if (lvl == "ERROR") {
                errs += 1;
            } else if (lvl == "WARN") {
                warns += 1;
            } else if (lvl == "INFO") {
                infos += 1;
            }
            int c = ++counts[ep];
            if (c > topCnt) {
                topCnt = c;
                topEp = ep;
            }
        }
    }
    double rate = total > 0 ? (errs * 100.0) / total : 0.0;
    return {total, errs, warns, infos, topEp, rate};
}

int main() {
    std::string p = "/tmp/bench04_sample.log";
    std::string sample = "2026-11-02T10:00:01Z INFO /api/login 200\n2026-11-02T10:00:02Z ERROR /api/pay 500\n2026-11-02T10:00:03Z INFO /api/pay 200\n2026-11-02T10:00:04Z WARN /api/login 429\n2026-11-02T10:00:05Z ERROR /api/pay 503\n";
    {
        std::ofstream out(p);
        out << sample;
    }
    std::ifstream in(p);
    std::stringstream buffer;
    buffer << in.rdbuf();
    auto s = analyzeLogs(buffer.str());
    assert(s.totalLines == 5);
    assert(s.errorCount == 2);
    assert(s.warnCount == 1);
    assert(s.infoCount == 2);
    assert(s.topEndpoint == "/api/pay");
    assert(s.errorRatePct > 39.9 && s.errorRatePct < 40.1);
    std::cout << "Total=" << s.totalLines << " Errors=" << s.errorCount << " Top=" << s.topEndpoint << "\nBENCH_04_OK\n";
    return 0;
}
