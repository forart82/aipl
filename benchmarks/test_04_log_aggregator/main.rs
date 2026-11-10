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

#[allow(non_snake_case)]
fn analyzeLogs(content: &str) -> LogSummary {
    let mut total = 0;
    let mut errs = 0;
    let mut warns = 0;
    let mut infos = 0;
    let mut counts: HashMap<String, usize> = HashMap::new();
    let mut top_ep = String::new();
    let mut top_cnt = 0;
    for line in content.lines() {
        let t = line.trim();
        if !t.is_empty() {
            total += 1;
            let parts: Vec<&str> = t.split_whitespace().collect();
            if parts.len() >= 3 {
                match parts[1] {
                    "ERROR" => errs += 1,
                    "WARN" => warns += 1,
                    "INFO" => infos += 1,
                    _ => {}
                }
                let ep = parts[2].to_string();
                let c = counts.entry(ep.clone()).or_insert(0);
                *c += 1;
                if *c > top_cnt {
                    top_cnt = *c;
                    top_ep = ep;
                }
            }
        }
    }
    let rate = if total > 0 { (errs as f64 * 100.0) / (total as f64) } else { 0.0 };
    LogSummary {
        total_lines: total,
        error_count: errs,
        warn_count: warns,
        info_count: infos,
        top_endpoint: top_ep,
        error_rate_pct: rate,
    }
}

fn main() {
    let p = "/tmp/bench04_sample.log";
    let sample = "2026-11-02T10:00:01Z INFO /api/login 200\n2026-11-02T10:00:02Z ERROR /api/pay 500\n2026-11-02T10:00:03Z INFO /api/pay 200\n2026-11-02T10:00:04Z WARN /api/login 429\n2026-11-02T10:00:05Z ERROR /api/pay 503\n";
    fs::write(p, sample).unwrap();
    let loaded = fs::read_to_string(p).unwrap();
    let s = analyzeLogs(&loaded);
    assert_eq!(s.total_lines, 5);
    assert_eq!(s.error_count, 2);
    assert_eq!(s.warn_count, 1);
    assert_eq!(s.info_count, 2);
    assert_eq!(s.top_endpoint, "/api/pay");
    assert!(s.error_rate_pct > 39.9 && s.error_rate_pct < 40.1);
    println!("Total={} Errors={} Top={}\nBENCH_04_OK", s.total_lines, s.error_count, s.top_endpoint);
}
