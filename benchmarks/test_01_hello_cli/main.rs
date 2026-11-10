use std::collections::HashMap;

#[allow(non_snake_case)]
fn formatGreeting(name: &str, role: &str, count: i32) -> String {
    format!("Hello, {} [{}]! Welcome #{} to AIPL.", name, role, count)
}

#[allow(non_snake_case)]
fn parseCliArgs(args: &[&str]) -> HashMap<String, String> {
    let mut map = HashMap::new();
    for a in args {
        if let Some(rest) = a.strip_prefix("--") {
            if let Some((k, v)) = rest.split_once('=') {
                map.insert(k.to_string(), v.to_string());
            }
        }
    }
    map
}

fn main() {
    let parsed = parseCliArgs(&["--name=Developer", "--role=Engineer"]);
    let user = parsed.get("name").map(|s| s.as_str()).unwrap_or("Developer");
    let role = parsed.get("role").map(|s| s.as_str()).unwrap_or("Engineer");
    let msg1 = formatGreeting(user, role, 1);
    let msg2 = formatGreeting("Ada", "Architect", 42);
    assert_eq!(msg1, "Hello, Developer [Engineer]! Welcome #1 to AIPL.");
    assert_eq!(msg2, "Hello, Ada [Architect]! Welcome #42 to AIPL.");
    println!("{}\n{}\nBENCH_01_OK", msg1, msg2);
}
