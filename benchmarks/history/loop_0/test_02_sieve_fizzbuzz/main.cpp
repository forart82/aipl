#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cassert>

std::vector<int> sievePrimes(int limit) {
    std::vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= limit; ++p) {
        if (isPrime[p]) {
            for (int m = p * p; m <= limit; m += p) isPrime[m] = false;
        }
    }
    std::vector<int> primes;
    for (int k = 2; k <= limit; ++k) if (isPrime[k]) primes.push_back(k);
    return primes;
}

std::string classifyCell(int n, bool isPrime) {
    if (isPrime) return "PRIME(" + std::to_string(n) + ")";
    if (n % 15 == 0) return "FizzBuzz";
    if (n % 3 == 0) return "Fizz";
    if (n % 5 == 0) return "Buzz";
    return std::to_string(n);
}

int main() {
    auto primes = sievePrimes(30);
    assert(primes.size() == 10 && primes[0] == 2 && primes[9] == 29);
    std::set<int> primeSet(primes.begin(), primes.end());
    std::vector<std::string> rows;
    for (int r = 0; r < 3; ++r) {
        std::string row;
        for (int c = 1; c <= 5; ++c) {
            int val = r * 5 + c;
            if (c > 1) row += " | ";
            row += classifyCell(val, primeSet.count(val) > 0);
        }
        rows.push_back(row);
    }
    assert(rows[0].find("PRIME(2)") != std::string::npos);
    assert(rows[2].find("FizzBuzz") != std::string::npos);
    std::cout << rows[0] << "\nBENCH_02_OK\n";
    return 0;
}
