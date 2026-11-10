const fs = require("fs");
function analyzeLogs(content) {
  let total = 0, errs = 0, warns = 0, infos = 0, bestCnt = 0, bestEp = "";
  const counts = new Map();
  for (const line of content.split("\n")) {
    const t = line.trim();
    if (t.length > 0) {
      total++;
      const cols = t.split(/\s+/);
      if (cols.length >= 3) {
        if (cols[1] === "ERROR") errs++;
        else if (cols[1] === "WARN") warns++;
        else if (cols[1] === "INFO") infos++;
        const c = (counts.get(cols[2]) || 0) + 1;
        counts.set(cols[2], c);
        if (c > bestCnt) { bestCnt = c; bestEp = cols[2]; }
      }
    }
  }
  return { totalLines: total, errorCount: errs, warnCount: warns, infoCount: infos, topEndpoint: bestEp, errorRatePct: (errs * 100) / total };
}
const p = "/tmp/js_bench04.log";
const sample = "2026-11-02T10:00:01Z INFO /api/login 200\n2026-11-02T10:00:02Z ERROR /api/pay 500\n2026-11-02T10:00:03Z INFO /api/pay 200\n2026-11-02T10:00:04Z WARN /api/login 429\n2026-11-02T10:00:05Z ERROR /api/pay 503\n";
fs.writeFileSync(p, sample);
const s = analyzeLogs(fs.readFileSync(p, "utf8"));
if (s.totalLines !== 5 || s.errorCount !== 2 || s.topEndpoint !== "/api/pay") throw new Error("assert");
console.log(`Total=${s.totalLines} Errors=${s.errorCount} Top=${s.topEndpoint}\nBENCH_04_OK`);
