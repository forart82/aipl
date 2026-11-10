# SPEC_02: Algorithmic Sieve & FizzBuzz Matrix (`test_02_sieve_fizzbuzz`)

- **Tier**: Easy
- **Category**: Number Theory Sieve & 2D Matrix Formatting

## 1. Functional Requirements
1. Implement `sievePrimes(limit)` using the Sieve of Eratosthenes up to `limit` inclusive (`limit = 30`), returning the ordered list of primes `[2, 3, 5, 7, 11, 13, 17, 19, 23, 29]` (length 10).
2. Implement `classifyCell(n, isPrime)`:
   - If `isPrime` is true: `"PRIME({n})"`
   - Else if `n % 15 == 0`: `"FizzBuzz"`
   - Else if `n % 3 == 0`: `"Fizz"`
   - Else if `n % 5 == 0`: `"Buzz"`
   - Else: decimal string of `n`
3. Construct a $3 \times 5$ matrix for values $v = r \cdot 5 + c$ ($r \in [0, 2], c \in [1, 5]$), joining cells in each row with `" | "` and rows with `"\n"`.
4. Assert `primes.len == 10`, row 0 contains `"PRIME(2)"`, row 2 contains `"FizzBuzz"`, print the 3-row matrix, and print `BENCH_02_OK`.

## 2. Structural & Algorithmic Parity (Rule B)
- **Normalized Identifiers**: `sievePrimes`, `classifyCell`, `primes`, `rows`.
- **Algorithm**: True Sieve of Eratosthenes boolean array marking multiples starting at $p^2$, plus $3 \times 5$ grid traversal.
- **Complexity**: $O(N \log \log N)$ time, $O(N)$ space.

## 3. Expected Deterministic Stdout
```text
1 | PRIME(2) | PRIME(3) | 4 | PRIME(5)
Fizz | PRIME(7) | 8 | Fizz | Buzz
PRIME(11) | Fizz | PRIME(13) | 14 | FizzBuzz
BENCH_02_OK
```
