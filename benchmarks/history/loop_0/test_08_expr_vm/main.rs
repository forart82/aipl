use std::collections::HashMap;

fn prec(op: &str) -> i32 {
    match op { "*" | "/" => 3, "+" | "-" => 2, ">" | "==" => 1, _ => 0 }
}

fn compile_rpn(expr: &str) -> Vec<String> {
    let (mut out, mut ops): (Vec<String>, Vec<String>) = (Vec::new(), Vec::new());
    for t in expr.split_whitespace() {
        if t == "(" { ops.push(t.into()); }
        else if t == ")" {
            while let Some(top) = ops.last() {
                if top == "(" { break; }
                out.push(ops.pop().unwrap());
            }
            ops.pop();
        } else if prec(t) > 0 {
            while let Some(top) = ops.last() {
                if prec(top) >= prec(t) { out.push(ops.pop().unwrap()); } else { break; }
            }
            ops.push(t.into());
        } else { out.push(t.into()); }
    }
    while let Some(op) = ops.pop() { out.push(op); }
    out
}

fn eval_rpn(tokens: &[String], env: &HashMap<&str, i32>) -> i32 {
    let mut st: Vec<i32> = Vec::new();
    for t in tokens {
        if prec(t) > 0 {
            let b = st.pop().unwrap_or(0);
            let a = st.pop().unwrap_or(0);
            let v = match t.as_str() {
                "+" => a + b, "-" => a - b, "*" => a * b,
                "/" => if b != 0 { a / b } else { 0 },
                ">" => if a > b { 1 } else { 0 },
                "==" => if a == b { 1 } else { 0 },
                _ => 0,
            };
            st.push(v);
        } else if let Some(&v) = env.get(t.as_str()) { st.push(v); }
        else { st.push(t.parse().unwrap_or(0)); }
    }
    *st.last().unwrap_or(&0)
}

fn main() {
    let env = HashMap::from([("x", 12), ("y", 5)]);
    let v1 = eval_rpn(&compile_rpn("( x + y * 4 ) - 2"), &env);
    let v2 = eval_rpn(&compile_rpn("x * 2 > y + 10"), &env);
    assert!(v1 == 30 && v2 == 1);
    println!("v1={} v2={}\nBENCH_08_OK", v1, v2);
}
