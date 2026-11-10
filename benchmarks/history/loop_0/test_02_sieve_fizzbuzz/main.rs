use std::collections::HashSet;

fn sieve_primes(limit: usize) -> Vec<i32> {
    let mut is_prime = vec![true; limit + 1];
    is_prime[0] = false;
    is_prime[1] = false;
    let mut p = 2;
    while p * p <= limit {
        if is_prime[p] {
            let mut m = p * p;
            while m <= limit {
                is_prime[m] = false;
                m += p;
            }
        }
        p += 1;
    }
    (2..=limit).filter(|&k| is_prime[k]).map(|k| k as i32).collect()
}

fn classify_cell(n: i32, is_prime: bool) -> String {
    if is_prime { return format!("PRIME({})", n); }
    if n % 15 == 0 { return "FizzBuzz".to_string(); }
    if n % 3 == 0 { return "Fizz".to_string(); }
    if n % 5 == 0 { return "Buzz".to_string(); }
    n.to_string()
}

fn main() {
    let primes = sieve_primes(30);
    assert_eq!(primes.len(), 10);
    let pset: HashSet<i32> = primes.iter().copied().collect();
    let mut rows = Vec::new();
    for r in 0..3 {
        let mut cols = Vec::new();
        for c in 1..=5 {
            let v = r * 5 + c;
            cols.push(classify_cell(v, pset.contains(&v)));
        }
        rows.push(cols.join(" | "));
    }
    assert!(rows[0].contains("PRIME(2)") && rows[2].contains("FizzBuzz"));
    println!("{}\nBENCH_02_OK", rows.join("\n"));
}
