import * as fs from "fs";

interface LogSummary {
  totalLines: number;
  errorCount: number;
  warnCount: number;
  infoCount: number;
  topEndpoint: string;
  errorRatePct: number;
}

function analyzeLogs(content: string): LogSummary {
  let totalLines = 0;
  let errorCount = 0;
  let warnCount = 0;
  let infoCount = 0;
  let bestCount = 0;
  let topEndpoint = "";
  const counts: Record<string, number> = {};
  for (const line of content.split("\n")) {
    const t = line.trim();
    if (t) {
      totalLines += 1;
      const cols = t.split(/\s+/);
      if (cols.length >= 3) {
        const level = cols[1];
        const ep = cols[2];
        if (level === "ERROR") {
          errorCount += 1;
        } else if (level === "WARN") {
          warnCount += 1;
        } else if (level === "INFO") {
          infoCount += 1;
        }
        counts[ep] = (counts[ep] || 0) + 1;
        if (counts[ep] > bestCount) {
          bestCount = counts[ep];
          topEndpoint = ep;
        }
      }
    }
  }
  const errorRatePct = totalLines > 0 ? (errorCount * 100.0) / totalLines : 0.0;
  return {
    totalLines,
    errorCount,
    warnCount,
    infoCount,
    topEndpoint,
    errorRatePct,
  };
}

const p = "/tmp/bench04_sample.log";
const sample = "2026-11-02T10:00:01Z INFO /api/login 200\n2026-11-02T10:00:02Z ERROR /api/pay 500\n2026-11-02T10:00:03Z INFO /api/pay 200\n2026-11-02T10:00:04Z WARN /api/login 429\n2026-11-02T10:00:05Z ERROR /api/pay 503\n";
fs.writeFileSync(p, sample);
const s = analyzeLogs(fs.readFileSync(p, "utf8"));
if (s.totalLines !== 5 || s.errorCount !== 2 || s.warnCount !== 1 || s.infoCount !== 2 || s.topEndpoint !== "/api/pay" || s.errorRatePct < 39.9 || s.errorRatePct > 40.1) {
  throw new Error("assert");
}
console.log(`Total=${s.totalLines} Errors=${s.errorCount} Top=${s.topEndpoint}\nBENCH_04_OK`);
