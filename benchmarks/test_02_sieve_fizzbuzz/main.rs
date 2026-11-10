use std::collections::HashSet;

#[allow(non_snake_case)]
fn sievePrimes(limit: usize) -> Vec<i32> {
    let mut isPrime = vec![true; limit + 1];
    isPrime[0] = false;
    isPrime[1] = false;
    let mut p = 2;
    while p * p <= limit {
        if isPrime[p] {
            let mut m = p * p;
            while m <= limit {
                isPrime[m] = false;
                m += p;
            }
        }
        p += 1;
    }
    let mut primes = Vec::new();
    for k in 2..=limit {
        if isPrime[k] {
            primes.push(k as i32);
        }
    }
    primes
}

#[allow(non_snake_case)]
fn classifyCell(n: i32, isPrime: bool) -> String {
    if isPrime {
        return format!("PRIME({})", n);
    }
    if n % 15 == 0 {
        return "FizzBuzz".to_string();
    }
    if n % 3 == 0 {
        return "Fizz".to_string();
    }
    if n % 5 == 0 {
        return "Buzz".to_string();
    }
    n.to_string()
}

fn main() {
    let primes = sievePrimes(30);
    assert!(primes.len() == 10 && primes[0] == 2 && primes[9] == 29);
    let pset: HashSet<i32> = primes.iter().copied().collect();
    let mut rows = Vec::new();
    for r in 0..3 {
        let mut cols = Vec::new();
        for c in 1..=5 {
            let v = r * 5 + c;
            cols.push(classifyCell(v, pset.contains(&v)));
        }
        rows.push(cols.join(" | "));
    }
    assert!(rows[0].contains("PRIME(2)") && rows[2].contains("FizzBuzz"));
    println!("{}\nBENCH_02_OK", rows.join("\n"));
}
