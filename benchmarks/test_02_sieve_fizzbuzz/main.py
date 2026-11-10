def sievePrimes(limit: int) -> list[int]:
    isPrime = [i >= 2 for i in range(limit + 1)]
    p = 2
    while p * p <= limit:
        if isPrime[p]:
            for m in range(p * p, limit + 1, p):
                isPrime[m] = False
        p += 1
    return [k for k in range(2, limit + 1) if isPrime[k]]

def classifyCell(n: int, isPrime: bool) -> str:
    if isPrime:
        return f"PRIME({n})"
    if n % 15 == 0:
        return "FizzBuzz"
    if n % 3 == 0:
        return "Fizz"
    if n % 5 == 0:
        return "Buzz"
    return str(n)

primes = sievePrimes(30)
assert len(primes) == 10 and primes[0] == 2 and primes[9] == 29
rows: list[str] = []
for r in range(3):
    cols: list[str] = []
    for c in range(1, 6):
        v = r * 5 + c
        cols.append(classifyCell(v, v in primes))
    rows.append(" | ".join(cols))

assert "PRIME(2)" in rows[0] and "FizzBuzz" in rows[2]
print("\n".join(rows) + "\nBENCH_02_OK")
