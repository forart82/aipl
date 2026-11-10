from pathlib import Path

def analyze_logs(content: str) -> dict:
    total = errs = warns = infos = best_cnt = 0
    best_ep = ""
    counts: dict[str, int] = {}
    for line in content.splitlines():
        t = line.strip()
        if t:
            total += 1
            cols = t.split()
            if len(cols) >= 3:
                errs += cols[1] == "ERROR"
                warns += cols[1] == "WARN"
                infos += cols[1] == "INFO"
                c = counts.get(cols[2], 0) + 1
                counts[cols[2]] = c
                if c > best_cnt:
                    best_cnt, best_ep = c, cols[2]
    return {"total": total, "errs": errs, "top": best_ep, "rate": (errs * 100.0) / total if total else 0.0}

p = Path("/tmp/py_bench04.log")
p.write_text("2026-11-02T10:00:01Z INFO /api/login 200\n2026-11-02T10:00:02Z ERROR /api/pay 500\n2026-11-02T10:00:03Z INFO /api/pay 200\n2026-11-02T10:00:04Z WARN /api/login 429\n2026-11-02T10:00:05Z ERROR /api/pay 503\n")
s = analyze_logs(p.read_text())
assert s["total"] == 5 and s["errs"] == 2 and s["top"] == "/api/pay"
print(f"Total={s['total']} Errors={s['errs']} Top={s['top']}\nBENCH_04_OK")
