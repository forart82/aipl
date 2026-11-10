struct CliResult { exit_code: i32, output: String }

fn execute_cli_command(args: &[&str]) -> CliResult {
    if args.is_empty() || args[0] == "--help" || args[0] == "help" {
        return CliResult { exit_code: 0, output: "Usage: tool <stats|transform|pipeline> [options]".into() };
    }
    match args[0] {
        "stats" => {
            let mut nums: Vec<i32> = Vec::new();
            for a in &args[1..] {
                if let Some(rest) = a.strip_prefix("--values=") {
                    for p in rest.split(',') {
                        if let Ok(n) = p.trim().parse::<i32>() { nums.push(n); }
                    }
                }
            }
            if nums.is_empty() { return CliResult { exit_code: 2, output: "Error: --values required".into() }; }
            let sum: i32 = nums.iter().sum();
            let min_v = *nums.iter().min().unwrap();
            let max_v = *nums.iter().max().unwrap();
            CliResult { exit_code: 0, output: format!("count={} sum={} min={} max={}", nums.len(), sum, min_v, max_v) }
        }
        "pipeline" => {
            let (mut text, mut upper, mut rev) = (String::new(), false, false);
            for a in &args[1..] {
                if let Some(rest) = a.strip_prefix("--input=") { text = rest.to_string(); }
                else if *a == "--upper" { upper = true; }
                else if *a == "--reverse-words" { rev = true; }
            }
            if text.is_empty() { return CliResult { exit_code: 1, output: "Error: empty input".into() }; }
            if upper { text = text.to_uppercase(); }
            if rev {
                let mut ws: Vec<&str> = text.split_whitespace().collect();
                ws.reverse();
                text = ws.join(" ");
            }
            CliResult { exit_code: 0, output: text }
        }
        sub => CliResult { exit_code: 127, output: format!("Unknown subcommand: {}", sub) }
    }
}

fn main() {
    let r2 = execute_cli_command(&["stats", "--values=10,25,5,40"]);
    let r3 = execute_cli_command(&["pipeline", "--input=aipl fast native cli", "--upper", "--reverse-words"]);
    let r4 = execute_cli_command(&["unknown"]);
    assert!(r2.output == "count=4 sum=80 min=5 max=40" && r3.output == "CLI NATIVE FAST AIPL" && r4.exit_code == 127);
    println!("{} | {}\nBENCH_06_OK", r2.output, r3.output);
}
