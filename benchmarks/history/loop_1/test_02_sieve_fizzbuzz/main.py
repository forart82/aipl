def sieve_primes(limit: int) -> list[int]:
    is_prime = [i >= 2 for i in range(limit + 1)]
    p = 2
    while p * p <= limit:
        if is_prime[p]:
            for m in range(p * p, limit + 1, p):
                is_prime[m] = False
        p += 1
    return [k for k in range(2, limit + 1) if is_prime[k]]

def classify_cell(n: int, is_prime: bool) -> str:
    if is_prime: return f"PRIME({n})"
    if n % 15 == 0: return "FizzBuzz"
    if n % 3 == 0: return "Fizz"
    if n % 5 == 0: return "Buzz"
    return str(n)

primes = sieve_primes(30)
pset = set(primes)
rows = [" | ".join(classify_cell(r * 5 + c, (r * 5 + c) in pset) for c in range(1, 6)) for r in range(3)]
assert "PRIME(2)" in rows[0] and "FizzBuzz" in rows[2]
print("\n".join(rows) + "\nBENCH_02_OK")
