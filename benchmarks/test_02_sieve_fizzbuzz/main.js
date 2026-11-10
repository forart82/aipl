function sievePrimes(limit) {
  const isPrime = Array(limit + 1).fill(true);
  isPrime[0] = false;
  isPrime[1] = false;
  for (let p = 2; p * p <= limit; p++) {
    if (isPrime[p]) {
      for (let m = p * p; m <= limit; m += p) {
        isPrime[m] = false;
      }
    }
  }
  const out = [];
  for (let k = 2; k <= limit; k++) {
    if (isPrime[k]) {
      out.push(k);
    }
  }
  return out;
}

function classifyCell(n, isPrime) {
  if (isPrime) {
    return `PRIME(${n})`;
  }
  if (n % 15 === 0) {
    return "FizzBuzz";
  }
  if (n % 3 === 0) {
    return "Fizz";
  }
  if (n % 5 === 0) {
    return "Buzz";
  }
  return String(n);
}

const primes = sievePrimes(30);
if (primes.length !== 10 || primes[0] !== 2 || primes[9] !== 29) {
  throw new Error("assert");
}
const pset = new Set(primes);
const rows = [];
for (let r = 0; r < 3; r++) {
  const cols = [];
  for (let c = 1; c <= 5; c++) {
    const v = r * 5 + c;
    cols.push(classifyCell(v, pset.has(v)));
  }
  rows.push(cols.join(" | "));
}
if (!rows[0].includes("PRIME(2)") || !rows[2].includes("FizzBuzz")) {
  throw new Error("assert");
}
console.log(rows.join("\n") + "\nBENCH_02_OK");
