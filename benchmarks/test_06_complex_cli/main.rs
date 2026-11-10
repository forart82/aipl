struct CliResult {
    exit_code: i32,
    output: String,
}

#[allow(non_snake_case)]
fn executeCliCommand(args: &[&str]) -> CliResult {
    if args.is_empty() || args[0] == "--help" || args[0] == "help" {
        return CliResult {
            exit_code: 0,
            output: "Usage: tool <stats|transform|pipeline> [options]".to_string(),
        };
    }
    if args[0] == "stats" {
        let mut nums = Vec::new();
        for a in &args[1..] {
            if let Some(rest) = a.strip_prefix("--values=") {
                for p in rest.split(',') {
                    if let Ok(n) = p.trim().parse::<i32>() {
                        nums.push(n);
                    }
                }
            }
        }
        if nums.is_empty() {
            return CliResult {
                exit_code: 2,
                output: "Error: --values required".to_string(),
            };
        }
        let sum: i32 = nums.iter().sum();
        let mn = *nums.iter().min().unwrap();
        let mx = *nums.iter().max().unwrap();
        return CliResult {
            exit_code: 0,
            output: format!("count={} sum={} min={} max={}", nums.len(), sum, mn, mx),
        };
    }
    if args[0] == "pipeline" {
        let mut text = String::new();
        let mut upper = false;
        let mut rev = false;
        for a in &args[1..] {
            if let Some(rest) = a.strip_prefix("--input=") {
                text = rest.to_string();
            } else if *a == "--upper" {
                upper = true;
            } else if *a == "--reverse-words" {
                rev = true;
            }
        }
        if text.is_empty() {
            return CliResult {
                exit_code: 1,
                output: "Error: empty input".to_string(),
            };
        }
        if upper {
            text = text.to_uppercase();
        }
        if rev {
            let mut ws: Vec<&str> = text.split_whitespace().collect();
            ws.reverse();
            text = ws.join(" ");
        }
        return CliResult {
            exit_code: 0,
            output: text,
        };
    }
    CliResult {
        exit_code: 127,
        output: format!("Unknown subcommand: {}", args[0]),
    }
}

fn main() {
    let r1 = executeCliCommand(&["--help"]);
    let r2 = executeCliCommand(&["stats", "--values=10,25,5,40"]);
    let r3 = executeCliCommand(&["pipeline", "--input=aipl fast native cli", "--upper", "--reverse-words"]);
    let r4 = executeCliCommand(&["unknown_cmd"]);
    assert_eq!(r1.exit_code, 0);
    assert_eq!(r2.exit_code, 0);
    assert_eq!(r2.output, "count=4 sum=80 min=5 max=40");
    assert_eq!(r3.exit_code, 0);
    assert_eq!(r3.output, "CLI NATIVE FAST AIPL");
    assert_eq!(r4.exit_code, 127);
    println!("{} | {}\nBENCH_06_OK", r2.output, r3.output);
}
