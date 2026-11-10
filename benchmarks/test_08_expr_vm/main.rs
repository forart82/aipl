use std::collections::HashMap;

#[allow(non_snake_case)]
fn precedence(op: &str) -> i32 {
    match op {
        "*" | "/" => 3,
        "+" | "-" => 2,
        ">" | "==" => 1,
        _ => 0,
    }
}

#[allow(non_snake_case)]
fn compileInfixToRpn(expr: &str) -> Vec<String> {
    let mut out: Vec<String> = Vec::new();
    let mut ops: Vec<String> = Vec::new();
    for token in expr.split_whitespace() {
        if token == "(" {
            ops.push(token.to_string());
        } else if token == ")" {
            while let Some(top) = ops.last() {
                if top == "(" {
                    break;
                }
                out.push(ops.pop().unwrap());
            }
            if !ops.is_empty() {
                ops.pop();
            }
        } else if precedence(token) > 0 {
            while let Some(top) = ops.last() {
                if precedence(top) >= precedence(token) {
                    out.push(ops.pop().unwrap());
                } else {
                    break;
                }
            }
            ops.push(token.to_string());
        } else {
            out.push(token.to_string());
        }
    }
    while let Some(op) = ops.pop() {
        out.push(op);
    }
    out
}

#[allow(non_snake_case)]
fn evalRpnVm(tokens: &[String], env: &HashMap<&str, i32>) -> i32 {
    let mut stack: Vec<i32> = Vec::new();
    for token in tokens {
        if precedence(token) > 0 {
            let b = stack.pop().unwrap_or(0);
            let a = stack.pop().unwrap_or(0);
            let val = match token.as_str() {
                "+" => a + b,
                "-" => a - b,
                "*" => a * b,
                "/" => {
                    if b == 0 {
                        panic!("division by zero");
                    }
                    a / b
                }
                ">" => if a > b { 1 } else { 0 },
                "==" => if a == b { 1 } else { 0 },
                _ => 0,
            };
            stack.push(val);
        } else if let Some(&v) = env.get(token.as_str()) {
            stack.push(v);
        } else {
            stack.push(token.parse().unwrap_or(0));
        }
    }
    *stack.last().unwrap_or(&0)
}

fn main() {
    let env = HashMap::from([("x", 12), ("y", 5)]);
    let v1 = evalRpnVm(&compileInfixToRpn("( x + y * 4 ) - 2"), &env);
    let v2 = evalRpnVm(&compileInfixToRpn("x * 2 > y + 10"), &env);
    assert!(v1 == 30 && v2 == 1);
    println!("v1={} v2={}\nBENCH_08_OK", v1, v2);
}
