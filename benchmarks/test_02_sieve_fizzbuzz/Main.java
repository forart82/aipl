import java.util.*;

public class Main {
    static List<Integer> sievePrimes(int limit) {
        boolean[] isPrime = new boolean[limit + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int p = 2; p * p <= limit; p++) {
            if (isPrime[p]) {
                for (int m = p * p; m <= limit; m += p) {
                    isPrime[m] = false;
                }
            }
        }
        List<Integer> out = new ArrayList<>();
        for (int k = 2; k <= limit; k++) {
            if (isPrime[k]) {
                out.add(k);
            }
        }
        return out;
    }

    static String classifyCell(int n, boolean isPrime) {
        if (isPrime) {
            return "PRIME(" + n + ")";
        }
        if (n % 15 == 0) {
            return "FizzBuzz";
        }
        if (n % 3 == 0) {
            return "Fizz";
        }
        if (n % 5 == 0) {
            return "Buzz";
        }
        return String.valueOf(n);
    }

    public static void main(String[] args) {
        List<Integer> primes = sievePrimes(30);
        if (primes.size() != 10 || primes.get(0) != 2 || primes.get(9) != 29) {
            throw new AssertionError();
        }
        Set<Integer> pset = new HashSet<>(primes);
        List<String> rows = new ArrayList<>();
        for (int r = 0; r < 3; r++) {
            List<String> cols = new ArrayList<>();
            for (int c = 1; c <= 5; c++) {
                int v = r * 5 + c;
                cols.add(classifyCell(v, pset.contains(v)));
            }
            rows.add(String.join(" | ", cols));
        }
        if (!rows.get(0).contains("PRIME(2)") || !rows.get(2).contains("FizzBuzz")) {
            throw new AssertionError();
        }
        System.out.println(String.join("\n", rows) + "\nBENCH_02_OK");
    }
}
