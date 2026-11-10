#[derive(Clone)]
struct ConfigRecord {
    service: String,
    port: i32,
    tls: bool,
    tags: Vec<String>,
}

fn parse_records(src: &str) -> Vec<ConfigRecord> {
    let mut out = Vec::new();
    for line in src.lines() {
        let t = line.trim();
        if !t.is_empty() && !t.starts_with('#') {
            let parts: Vec<&str> = t.split('|').collect();
            if parts.len() >= 4 {
                out.push(ConfigRecord {
                    service: parts[0].trim().to_string(),
                    port: parts[1].trim().parse().unwrap_or(0),
                    tls: parts[2].trim() == "true",
                    tags: parts[3].trim().split(',').map(|s| s.to_string()).collect(),
                });
            }
        }
    }
    out
}

fn validate_and_mutate(records: &[ConfigRecord]) -> Vec<ConfigRecord> {
    let mut out = Vec::new();
    for r in records {
        if !r.service.is_empty() && r.port > 0 && r.port <= 65535 {
            let mut tags: Vec<String> = r.tags.iter().map(|t| t.trim().to_string()).collect();
            tags.push("verified".to_string());
            out.push(ConfigRecord {
                service: r.service.clone(),
                port: r.port + 100,
                tls: true,
                tags,
            });
        }
    }
    out
}

fn serialize_json(records: &[ConfigRecord]) -> String {
    let items: Vec<String> = records.iter().map(|r| {
        let qtags: Vec<String> = r.tags.iter().map(|t| format!("\"{}\"", t)).collect();
        format!("{{\"service\":\"{}\",\"port\":{},\"tls\":{},\"tags\":[{}]}}", r.service, r.port, r.tls, qtags.join(","))
    }).collect();
    format!("[{}]", items.join(","))
}

fn main() {
    let raw = "# Services\nauth | 8000 | false | core,jwt\ngateway | 8080 | true | edge,http\ninvalid | -5 | false | bad\n";
    let parsed = parse_records(raw);
    assert_eq!(parsed.len(), 3);
    let valid = validate_and_mutate(&parsed);
    assert_eq!(valid.len(), 2);
    assert!(valid[0].port == 8100 && valid[0].tls);
    let json_out = serialize_json(&valid);
    assert!(json_out.contains("\"service\":\"auth\"") && json_out.contains("\"verified\""));
    println!("{}\nBENCH_03_OK", json_out);
}
