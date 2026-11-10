from pathlib import Path
from dataclasses import dataclass

@dataclass
class LogSummary:
    totalLines: int
    errorCount: int
    warnCount: int
    infoCount: int
    topEndpoint: str
    errorRatePct: float

def analyzeLogs(content: str) -> LogSummary:
    totalLines = 0
    errorCount = 0
    warnCount = 0
    infoCount = 0
    bestCount = 0
    topEndpoint = ""
    counts: dict[str, int] = {}
    for line in content.splitlines():
        line = line.strip()
        if line:
            totalLines += 1
            cols = line.split()
            if len(cols) >= 3:
                level = cols[1]
                ep = cols[2]
                if level == "ERROR":
                    errorCount += 1
                elif level == "WARN":
                    warnCount += 1
                elif level == "INFO":
                    infoCount += 1
                cnt = counts.get(ep, 0) + 1
                counts[ep] = cnt
                if cnt > bestCount:
                    bestCount = cnt
                    topEndpoint = ep
    errorRatePct = (errorCount * 100.0) / totalLines if totalLines > 0 else 0.0
    return LogSummary(totalLines, errorCount, warnCount, infoCount, topEndpoint, errorRatePct)

p = Path("/tmp/bench04_sample.log")
sample = "2026-11-02T10:00:01Z INFO /api/login 200\n2026-11-02T10:00:02Z ERROR /api/pay 500\n2026-11-02T10:00:03Z INFO /api/pay 200\n2026-11-02T10:00:04Z WARN /api/login 429\n2026-11-02T10:00:05Z ERROR /api/pay 503\n"
p.write_text(sample)
summary = analyzeLogs(p.read_text())
assert summary.totalLines == 5
assert summary.errorCount == 2
assert summary.warnCount == 1
assert summary.infoCount == 2
assert summary.topEndpoint == "/api/pay"
assert 39.9 < summary.errorRatePct < 40.1
print(f"Total={summary.totalLines} Errors={summary.errorCount} Top={summary.topEndpoint}\nBENCH_04_OK")
