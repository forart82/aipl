use std::collections::HashMap;
use std::fs;

struct LogSummary {
    total_lines: usize,
    error_count: usize,
    warn_count: usize,
    info_count: usize,
    top_endpoint: String,
    error_rate_pct: f64,
}

fn analyze_logs(content: &str) -> LogSummary {
    let (mut total, mut errs, mut warns, mut infos, mut best_cnt) = (0, 0, 0, 0, 0);
    let mut best_ep = String::new();
    let mut counts: HashMap<String, usize> = HashMap::new();
    for line in content.lines() {
        let t = line.trim();
        if !t.is_empty() {
            total += 1;
            let cols: Vec<&str> = t.split_whitespace().collect();
            if cols.len() >= 3 {
                match cols[1] {
                    "ERROR" => errs += 1,
                    "WARN" => warns += 1,
                    "INFO" => infos += 1,
                    _ => {}
                }
                let c = counts.entry(cols[2].to_string()).and_modify(|v| *v += 1).or_insert(1);
                if *c > best_cnt {
                    best_cnt = *c;
                    best_ep = cols[2].to_string();
                }
            }
        }
    }
    let rate = if total > 0 { (errs as f64 * 100.0) / total as f64 } else { 0.0 };
    LogSummary { total_lines: total, error_count: errs, warn_count: warns, info_count: infos, top_endpoint: best_ep, error_rate_pct: rate }
}

fn main() {
    let path = "/tmp/rs_bench04.log";
    let sample = "2026-11-02T10:00:01Z INFO /api/login 200\n2026-11-02T10:00:02Z ERROR /api/pay 500\n2026-11-02T10:00:03Z INFO /api/pay 200\n2026-11-02T10:00:04Z WARN /api/login 429\n2026-11-02T10:00:05Z ERROR /api/pay 503\n";
    fs::write(path, sample).unwrap();
    let loaded = fs::read_to_string(path).unwrap();
    let s = analyze_logs(&loaded);
    assert!(s.total_lines == 5 && s.error_count == 2 && s.warn_count == 1 && s.info_count == 2 && s.top_endpoint == "/api/pay" && (s.error_rate_pct - 40.0).abs() < 0.1);
    println!("Total={} Errors={} Top={}\nBENCH_04_OK", s.total_lines, s.error_count, s.top_endpoint);
}
