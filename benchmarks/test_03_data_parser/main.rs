#[derive(Clone)]
struct ConfigRecord {
    service: String,
    port: i32,
    tls: bool,
    tags: Vec<String>,
}

#[allow(non_snake_case)]
fn parseRecords(src: &str) -> Vec<ConfigRecord> {
    let mut out = Vec::new();
    for line in src.lines() {
        let t = line.trim();
        if !t.is_empty() && !t.starts_with('#') {
            let parts: Vec<&str> = t.split('|').map(|p| p.trim()).collect();
            if parts.len() >= 4 {
                let service = parts[0].to_string();
                let port = parts[1].parse::<i32>().unwrap_or(0);
                let tls = parts[2] == "true";
                let tags = parts[3].split(',').map(|s| s.trim().to_string()).collect();
                out.push(ConfigRecord { service, port, tls, tags });
            }
        }
    }
    out
}

#[allow(non_snake_case)]
fn validateAndMutate(records: &[ConfigRecord]) -> Vec<ConfigRecord> {
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

#[allow(non_snake_case)]
fn serializeJson(records: &[ConfigRecord]) -> String {
    let mut items = Vec::new();
    for r in records {
        let qtags: Vec<String> = r.tags.iter().map(|t| format!("\"{}\"", t)).collect();
        items.push(format!(
            "{{\"service\":\"{}\",\"port\":{},\"tls\":{},\"tags\":[{}]}}",
            r.service, r.port, r.tls, qtags.join(",")
        ));
    }
    format!("[{}]", items.join(","))
}

fn main() {
    let raw = "# Services\nauth | 8000 | false | core,jwt\ngateway | 8080 | true | edge,http\ninvalid | -5 | false | bad\n";
    let parsed = parseRecords(raw);
    let valid = validateAndMutate(&parsed);
    let json_out = serializeJson(&valid);
    assert_eq!(parsed.len(), 3);
    assert_eq!(valid.len(), 2);
    assert!(json_out.contains("\"service\":\"auth\""));
    println!("{}\nBENCH_03_OK", json_out);
}
