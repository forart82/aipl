# sources_data.py - Rule B compliant sources for comparison languages

SOURCES = {}

# ==============================================================================
# TEST 01: Hello World & Dynamic CLI Greeting
# ==============================================================================
SOURCES[("01", "cpp")] = """#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cassert>

std::string formatGreeting(const std::string& name, const std::string& role, int count) {
    return "Hello, " + name + " [" + role + "]! Welcome #" + std::to_string(count) + " to AIPL.";
}

std::map<std::string, std::string> parseCliArgs(const std::vector<std::string>& args) {
    std::map<std::string, std::string> opts;
    for (const auto& a : args) {
        if (a.rfind("--", 0) == 0) {
            auto eq = a.find('=');
            if (eq != std::string::npos) {
                opts[a.substr(2, eq - 2)] = a.substr(eq + 1);
            }
        }
    }
    return opts;
}

int main() {
    auto parsed = parseCliArgs({"--name=Developer", "--role=Engineer"});
    std::string user = parsed.count("name") ? parsed["name"] : "Developer";
    std::string role = parsed.count("role") ? parsed["role"] : "Engineer";
    std::string msg1 = formatGreeting(user, role, 1);
    std::string msg2 = formatGreeting("Ada", "Architect", 42);
    assert(msg1 == "Hello, Developer [Engineer]! Welcome #1 to AIPL.");
    assert(msg2 == "Hello, Ada [Architect]! Welcome #42 to AIPL.");
    std::cout << msg1 << "\\n" << msg2 << "\\nBENCH_01_OK\\n";
    return 0;
}
"""

SOURCES[("01", "rs")] = """use std::collections::HashMap;

#[allow(non_snake_case)]
fn formatGreeting(name: &str, role: &str, count: i32) -> String {
    format!("Hello, {} [{}]! Welcome #{} to AIPL.", name, role, count)
}

#[allow(non_snake_case)]
fn parseCliArgs(args: &[&str]) -> HashMap<String, String> {
    let mut map = HashMap::new();
    for a in args {
        if let Some(rest) = a.strip_prefix("--") {
            if let Some((k, v)) = rest.split_once('=') {
                map.insert(k.to_string(), v.to_string());
            }
        }
    }
    map
}

fn main() {
    let parsed = parseCliArgs(&["--name=Developer", "--role=Engineer"]);
    let user = parsed.get("name").map(|s| s.as_str()).unwrap_or("Developer");
    let role = parsed.get("role").map(|s| s.as_str()).unwrap_or("Engineer");
    let msg1 = formatGreeting(user, role, 1);
    let msg2 = formatGreeting("Ada", "Architect", 42);
    assert_eq!(msg1, "Hello, Developer [Engineer]! Welcome #1 to AIPL.");
    assert_eq!(msg2, "Hello, Ada [Architect]! Welcome #42 to AIPL.");
    println!("{}\\n{}\\nBENCH_01_OK", msg1, msg2);
}
"""

SOURCES[("01", "go")] = """package main

import (
\t"fmt"
\t"strings"
)

func formatGreeting(name string, role string, count int) string {
\treturn fmt.Sprintf("Hello, %s [%s]! Welcome #%d to AIPL.", name, role, count)
}

func parseCliArgs(args []string) map[string]string {
\topts := make(map[string]string)
\tfor _, a := range args {
\t\tif strings.HasPrefix(a, "--") {
\t\t\tparts := strings.SplitN(a[2:], "=", 2)
\t\t\tif len(parts) == 2 {
\t\t\t\topts[parts[0]] = parts[1]
\t\t\t}
\t\t}
\t}
\treturn opts
}

func main() {
\tparsed := parseCliArgs([]string{"--name=Developer", "--role=Engineer"})
\tuser := "Developer"
\tif val, ok := parsed["name"]; ok {
\t\tuser = val
\t}
\trole := "Engineer"
\tif val, ok := parsed["role"]; ok {
\t\trole = val
\t}
\tmsg1 := formatGreeting(user, role, 1)
\tmsg2 := formatGreeting("Ada", "Architect", 42)
\tif msg1 != "Hello, Developer [Engineer]! Welcome #1 to AIPL." {
\t\tpanic("assertion failed")
\t}
\tif msg2 != "Hello, Ada [Architect]! Welcome #42 to AIPL." {
\t\tpanic("assertion failed")
\t}
\tfmt.Println(msg1)
\tfmt.Println(msg2)
\tfmt.Println("BENCH_01_OK")
}
"""

SOURCES[("01", "java")] = """import java.util.*;

public class Main {
    static String formatGreeting(String name, String role, int count) {
        return "Hello, " + name + " [" + role + "]! Welcome #" + count + " to AIPL.";
    }

    static Map<String, String> parseCliArgs(String[] args) {
        Map<String, String> map = new HashMap<>();
        for (String a : args) {
            if (a.startsWith("--") && a.contains("=")) {
                int idx = a.indexOf('=');
                map.put(a.substring(2, idx), a.substring(idx + 1));
            }
        }
        return map;
    }

    public static void main(String[] args) {
        Map<String, String> parsed = parseCliArgs(new String[]{"--name=Developer", "--role=Engineer"});
        String user = parsed.getOrDefault("name", "Developer");
        String role = parsed.getOrDefault("role", "Engineer");
        String msg1 = formatGreeting(user, role, 1);
        String msg2 = formatGreeting("Ada", "Architect", 42);
        if (!msg1.equals("Hello, Developer [Engineer]! Welcome #1 to AIPL.")) {
            throw new AssertionError();
        }
        if (!msg2.equals("Hello, Ada [Architect]! Welcome #42 to AIPL.")) {
            throw new AssertionError();
        }
        System.out.println(msg1 + "\\n" + msg2 + "\\nBENCH_01_OK");
    }
}
"""

SOURCES[("01", "js")] = """function formatGreeting(name, role, count) {
  return `Hello, ${name} [${role}]! Welcome #${count} to AIPL.`;
}

function parseCliArgs(args) {
  const opts = {};
  for (const a of args) {
    if (a.startsWith("--") && a.includes("=")) {
      const parts = a.slice(2).split("=");
      opts[parts[0]] = parts[1];
    }
  }
  return opts;
}

const parsed = parseCliArgs(["--name=Developer", "--role=Engineer"]);
const user = parsed.name || "Developer";
const role = parsed.role || "Engineer";
const msg1 = formatGreeting(user, role, 1);
const msg2 = formatGreeting("Ada", "Architect", 42);
if (msg1 !== "Hello, Developer [Engineer]! Welcome #1 to AIPL.") {
  throw new Error("assert");
}
if (msg2 !== "Hello, Ada [Architect]! Welcome #42 to AIPL.") {
  throw new Error("assert");
}
console.log(msg1 + "\\n" + msg2 + "\\nBENCH_01_OK");
"""

SOURCES[("01", "py")] = """def formatGreeting(name: str, role: str, count: int) -> str:
    return f"Hello, {name} [{role}]! Welcome #{count} to AIPL."

def parseCliArgs(args: list[str]) -> dict[str, str]:
    opts: dict[str, str] = {}
    for a in args:
        if a.startswith("--") and "=" in a:
            parts = a[2:].split("=", 1)
            opts[parts[0]] = parts[1]
    return opts

parsed = parseCliArgs(["--name=Developer", "--role=Engineer"])
user = parsed.get("name", "Developer")
role = parsed.get("role", "Engineer")
msg1 = formatGreeting(user, role, 1)
msg2 = formatGreeting("Ada", "Architect", 42)
assert msg1 == "Hello, Developer [Engineer]! Welcome #1 to AIPL."
assert msg2 == "Hello, Ada [Architect]! Welcome #42 to AIPL."
print(f"{msg1}\\n{msg2}\\nBENCH_01_OK")
"""

SOURCES[("01", "ts")] = """function formatGreeting(name: string, role: string, count: number): string {
  return `Hello, ${name} [${role}]! Welcome #${count} to AIPL.`;
}

function parseCliArgs(args: string[]): Record<string, string> {
  const opts: Record<string, string> = {};
  for (const a of args) {
    if (a.startsWith("--") && a.includes("=")) {
      const parts = a.slice(2).split("=");
      opts[parts[0]] = parts[1];
    }
  }
  return opts;
}

const parsed = parseCliArgs(["--name=Developer", "--role=Engineer"]);
const user = parsed["name"] ?? "Developer";
const role = parsed["role"] ?? "Engineer";
const msg1 = formatGreeting(user, role, 1);
const msg2 = formatGreeting("Ada", "Architect", 42);
if (msg1 !== "Hello, Developer [Engineer]! Welcome #1 to AIPL.") {
  throw new Error("assert");
}
if (msg2 !== "Hello, Ada [Architect]! Welcome #42 to AIPL.") {
  throw new Error("assert");
}
console.log(msg1 + "\\n" + msg2 + "\\nBENCH_01_OK");
"""

# ==============================================================================
# TEST 02: Algorithmic Sieve & FizzBuzz Matrix
# ==============================================================================
SOURCES[("02", "cpp")] = """#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cassert>

std::vector<int> sievePrimes(int limit) {
    std::vector<bool> isPrime(limit + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int p = 2; p * p <= limit; ++p) {
        if (isPrime[p]) {
            for (int m = p * p; m <= limit; m += p) {
                isPrime[m] = false;
            }
        }
    }
    std::vector<int> primes;
    for (int k = 2; k <= limit; ++k) {
        if (isPrime[k]) {
            primes.push_back(k);
        }
    }
    return primes;
}

std::string classifyCell(int n, bool isPrime) {
    if (isPrime) {
        return "PRIME(" + std::to_string(n) + ")";
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
            if (c > 1) {
                row += " | ";
            }
            row += classifyCell(val, primeSet.count(val) > 0);
        }
        rows.push_back(row);
    }
    assert(rows[0].find("PRIME(2)") != std::string::npos);
    assert(rows[2].find("FizzBuzz") != std::string::npos);
    std::cout << rows[0] << "\\n" << rows[1] << "\\n" << rows[2] << "\\nBENCH_02_OK\\n";
    return 0;
}
"""

SOURCES[("02", "rs")] = """use std::collections::HashSet;

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
    println!("{}\\nBENCH_02_OK", rows.join("\\n"));
}
"""

SOURCES[("02", "go")] = """package main

import (
\t"fmt"
\t"strings"
)

func sievePrimes(limit int) []int {
\tisPrime := make([]bool, limit+1)
\tfor i := 2; i <= limit; i++ {
\t\tisPrime[i] = true
\t}
\tfor p := 2; p*p <= limit; p++ {
\t\tif isPrime[p] {
\t\t\tfor m := p * p; m <= limit; m += p {
\t\t\t\tisPrime[m] = false
\t\t\t}
\t\t}
\t}
\tvar primes []int
\tfor k := 2; k <= limit; k++ {
\t\tif isPrime[k] {
\t\t\tprimes = append(primes, k)
\t\t}
\t}
\treturn primes
}

func classifyCell(n int, isPrime bool) string {
\tif isPrime {
\t\treturn fmt.Sprintf("PRIME(%d)", n)
\t}
\tif n%15 == 0 {
\t\treturn "FizzBuzz"
\t}
\tif n%3 == 0 {
\t\treturn "Fizz"
\t}
\tif n%5 == 0 {
\t\treturn "Buzz"
\t}
\treturn fmt.Sprintf("%d", n)
}

func main() {
\tprimes := sievePrimes(30)
\tif len(primes) != 10 || primes[0] != 2 || primes[9] != 29 {
\t\tpanic("assert primes failed")
\t}
\tpset := make(map[int]bool)
\tfor _, p := range primes {
\t\tpset[p] = true
\t}
\tvar rows []string
\tfor r := 0; r < 3; r++ {
\t\tvar cols []string
\t\tfor c := 1; c <= 5; c++ {
\t\t\tv := r*5 + c
\t\t\tcols = append(cols, classifyCell(v, pset[v]))
\t\t}
\t\trows = append(rows, strings.Join(cols, " | "))
\t}
\tif !strings.Contains(rows[0], "PRIME(2)") || !strings.Contains(rows[2], "FizzBuzz") {
\t\tpanic("assert rows failed")
\t}
\tfmt.Println(strings.Join(rows, "\\n"))
\tfmt.Println("BENCH_02_OK")
}
"""

SOURCES[("02", "java")] = """import java.util.*;

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
        System.out.println(String.join("\\n", rows) + "\\nBENCH_02_OK");
    }
}
"""

SOURCES[("02", "js")] = """function sievePrimes(limit) {
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
console.log(rows.join("\\n") + "\\nBENCH_02_OK");
"""

SOURCES[("02", "py")] = """def sievePrimes(limit: int) -> list[int]:
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
print("\\n".join(rows) + "\\nBENCH_02_OK")
"""

SOURCES[("02", "ts")] = """function sievePrimes(limit: number): number[] {
  const isPrime: boolean[] = Array(limit + 1).fill(true);
  isPrime[0] = false;
  isPrime[1] = false;
  for (let p = 2; p * p <= limit; p++) {
    if (isPrime[p]) {
      for (let m = p * p; m <= limit; m += p) {
        isPrime[m] = false;
      }
    }
  }
  const out: number[] = [];
  for (let k = 2; k <= limit; k++) {
    if (isPrime[k]) {
      out.push(k);
    }
  }
  return out;
}

function classifyCell(n: number, isPrime: boolean): string {
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
const pset = new Set<number>(primes);
const rows: string[] = [];
for (let r = 0; r < 3; r++) {
  const cols: string[] = [];
  for (let c = 1; c <= 5; c++) {
    const v = r * 5 + c;
    cols.push(classifyCell(v, pset.has(v)));
  }
  rows.push(cols.join(" | "));
}
if (!rows[0].includes("PRIME(2)") || !rows[2].includes("FizzBuzz")) {
  throw new Error("assert");
}
console.log(rows.join("\\n") + "\\nBENCH_02_OK");
"""
# ==============================================================================
# TEST 03: Structured Data Parser & Serializer
# ==============================================================================
SOURCES[("03", "cpp")] = """#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>

struct ConfigRecord {
    std::string service;
    int port;
    bool tls;
    std::vector<std::string> tags;
};

static std::string trim(const std::string& s) {
    size_t a = s.find_first_not_of(" \\t\\r\\n");
    if (a == std::string::npos) {
        return "";
    }
    size_t b = s.find_last_not_of(" \\t\\r\\n");
    return s.substr(a, b - a + 1);
}

static std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> out;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        out.push_back(item);
    }
    return out;
}

std::vector<ConfigRecord> parseRecords(const std::string& src) {
    std::vector<ConfigRecord> out;
    for (const auto& line : split(src, '\\n')) {
        std::string t = trim(line);
        if (!t.empty() && t[0] != '#') {
            auto parts = split(t, '|');
            if (parts.size() >= 4) {
                out.push_back({trim(parts[0]), std::stoi(trim(parts[1])), trim(parts[2]) == "true", split(trim(parts[3]), ',')});
            }
        }
    }
    return out;
}

std::vector<ConfigRecord> validateAndMutate(const std::vector<ConfigRecord>& records) {
    std::vector<ConfigRecord> out;
    for (const auto& r : records) {
        if (!r.service.empty() && r.port > 0 && r.port <= 65535) {
            std::vector<std::string> tags;
            for (const auto& tg : r.tags) {
                tags.push_back(trim(tg));
            }
            tags.push_back("verified");
            out.push_back({r.service, r.port + 100, true, tags});
        }
    }
    return out;
}

std::string serializeJson(const std::vector<ConfigRecord>& records) {
    std::string out = "[";
    for (size_t i = 0; i < records.size(); ++i) {
        if (i > 0) {
            out += ",";
        }
        const auto& r = records[i];
        out += "{\\"service\\":\\"" + r.service + "\\",\\"port\\":" + std::to_string(r.port) + ",\\"tls\\":" + (r.tls ? "true" : "false") + ",\\"tags\\":[";
        for (size_t j = 0; j < r.tags.size(); ++j) {
            if (j > 0) {
                out += ",";
            }
            out += "\\\"" + r.tags[j] + "\\\"";
        }
        out += "]}";
    }
    out += "]";
    return out;
}

int main() {
    std::string raw = "# Services\\nauth | 8000 | false | core,jwt\\ngateway | 8080 | true | edge,http\\ninvalid | -5 | false | bad\\n";
    auto parsed = parseRecords(raw);
    auto valid = validateAndMutate(parsed);
    auto jsonOut = serializeJson(valid);
    assert(parsed.size() == 3);
    assert(valid.size() == 2);
    assert(jsonOut.find("\\\"service\\\":\\\"auth\\\"") != std::string::npos);
    std::cout << jsonOut << "\\nBENCH_03_OK\\n";
    return 0;
}
"""

SOURCES[("03", "rs")] = """#[derive(Clone)]
struct ConfigRecord {
    service: String,
    port: i32,
    tls: bool,
    tags: Vec<String>,
}

#[allow(non_snake_case)]
fn parseRecords(src: &str) -> Vec<ConfigRecord> {
    let mut out = Vec::new();
    for line in src.lines() {
        let t = line.trim();
        if !t.is_empty() && !t.starts_with('#') {
            let parts: Vec<&str> = t.split('|').map(|p| p.trim()).collect();
            if parts.len() >= 4 {
                let service = parts[0].to_string();
                let port = parts[1].parse::<i32>().unwrap_or(0);
                let tls = parts[2] == "true";
                let tags = parts[3].split(',').map(|s| s.trim().to_string()).collect();
                out.push(ConfigRecord { service, port, tls, tags });
            }
        }
    }
    out
}

#[allow(non_snake_case)]
fn validateAndMutate(records: &[ConfigRecord]) -> Vec<ConfigRecord> {
    let mut out = Vec::new();
    for r in records {
        if !r.service.is_empty() && r.port > 0 && r.port <= 65535 {
            let mut tags: Vec<String> = r.tags.iter().map(|t| t.trim().to_string()).collect();
            tags.push("verified".to_string());
            out.push(ConfigRecord {
                service: r.service.clone(),
                port: r.port + 100,
                tls: true,
                tags,
            });
        }
    }
    out
}

#[allow(non_snake_case)]
fn serializeJson(records: &[ConfigRecord]) -> String {
    let mut items = Vec::new();
    for r in records {
        let qtags: Vec<String> = r.tags.iter().map(|t| format!("\\\"{}\\\"", t)).collect();
        items.push(format!(
            "{{\\\"service\\\":\\\"{}\\\",\\\"port\\\":{},\\\"tls\\\":{},\\\"tags\\\":[{}]}}",
            r.service, r.port, r.tls, qtags.join(",")
        ));
    }
    format!("[{}]", items.join(","))
}

fn main() {
    let raw = "# Services\\nauth | 8000 | false | core,jwt\\ngateway | 8080 | true | edge,http\\ninvalid | -5 | false | bad\\n";
    let parsed = parseRecords(raw);
    let valid = validateAndMutate(&parsed);
    let json_out = serializeJson(&valid);
    assert_eq!(parsed.len(), 3);
    assert_eq!(valid.len(), 2);
    assert!(json_out.contains("\\\"service\\\":\\\"auth\\\""));
    println!("{}\\nBENCH_03_OK", json_out);
}
"""

SOURCES[("03", "go")] = """package main

import (
\t"fmt"
\t"strconv"
\t"strings"
)

type ConfigRecord struct {
\tservice string
\tport    int
\ttls     bool
\ttags    []string
}

func parseRecords(src string) []ConfigRecord {
\tvar out []ConfigRecord
\tlines := strings.Split(src, "\\n")
\tfor _, line := range lines {
\t\tt := strings.TrimSpace(line)
\t\tif len(t) > 0 && !strings.HasPrefix(t, "#") {
\t\t\tparts := strings.Split(t, "|")
\t\t\tif len(parts) >= 4 {
\t\t\t\tsvc := strings.TrimSpace(parts[0])
\t\t\t\tport, _ := strconv.Atoi(strings.TrimSpace(parts[1]))
\t\t\t\ttls := strings.TrimSpace(parts[2]) == "true"
\t\t\t\trawTags := strings.Split(strings.TrimSpace(parts[3]), ",")
\t\t\t\tvar tags []string
\t\t\t\tfor _, tg := range rawTags {
\t\t\t\t\ttags = append(tags, strings.TrimSpace(tg))
\t\t\t\t}
\t\t\t\tout = append(out, ConfigRecord{svc, port, tls, tags})
\t\t\t}
\t\t}
\t}
\treturn out
}

func validateAndMutate(records []ConfigRecord) []ConfigRecord {
\tvar out []ConfigRecord
\tfor _, r := range records {
\t\tif len(r.service) > 0 && r.port > 0 && r.port <= 65535 {
\t\t\tvar tags []string
\t\t\tfor _, tg := range r.tags {
\t\t\t\ttags = append(tags, strings.TrimSpace(tg))
\t\t\t}
\t\t\ttags = append(tags, "verified")
\t\t\tout = append(out, ConfigRecord{r.service, r.port + 100, true, tags})
\t\t}
\t}
\treturn out
}

func serializeJson(records []ConfigRecord) string {
\tvar items []string
\tfor _, r := range records {
\t\tvar q []string
\t\tfor _, t := range r.tags {
\t\t\tq = append(q, fmt.Sprintf("\\\"%s\\\"", t))
\t\t}
\t\ttlsStr := "false"
\t\tif r.tls {
\t\t\ttlsStr = "true"
\t\t}
\t\titem := fmt.Sprintf("{\\\"service\\\":\\\"%s\\\",\\\"port\\\":%d,\\\"tls\\\":%s,\\\"tags\\\":[%s]}", r.service, r.port, tlsStr, strings.Join(q, ","))
\t\titems = append(items, item)
\t}
\treturn "[" + strings.Join(items, ",") + "]"
}

func main() {
\traw := "# Services\\nauth | 8000 | false | core,jwt\\ngateway | 8080 | true | edge,http\\ninvalid | -5 | false | bad\\n"
\tparsed := parseRecords(raw)
\tvalid := validateAndMutate(parsed)
\tjsonOut := serializeJson(valid)
\tif len(parsed) != 3 || len(valid) != 2 || !strings.Contains(jsonOut, "\\\"service\\\":\\\"auth\\\"") {
\t\tpanic("assert")
\t}
\tfmt.Println(jsonOut)
\tfmt.Println("BENCH_03_OK")
}
"""

SOURCES[("03", "java")] = """import java.util.*;

public class Main {
    static class ConfigRecord {
        String service;
        int port;
        boolean tls;
        List<String> tags;
        ConfigRecord(String service, int port, boolean tls, List<String> tags) {
            this.service = service;
            this.port = port;
            this.tls = tls;
            this.tags = tags;
        }
    }

    static List<ConfigRecord> parseRecords(String src) {
        List<ConfigRecord> out = new ArrayList<>();
        for (String line : src.split("\\n")) {
            String t = line.trim();
            if (!t.isEmpty() && !t.startsWith("#")) {
                String[] parts = t.split("\\\\|");
                if (parts.length >= 4) {
                    String svc = parts[0].trim();
                    int port = Integer.parseInt(parts[1].trim());
                    boolean tls = parts[2].trim().equals("true");
                    List<String> tags = new ArrayList<>();
                    for (String tg : parts[3].trim().split(",")) {
                        tags.add(tg.trim());
                    }
                    out.add(new ConfigRecord(svc, port, tls, tags));
                }
            }
        }
        return out;
    }

    static List<ConfigRecord> validateAndMutate(List<ConfigRecord> records) {
        List<ConfigRecord> out = new ArrayList<>();
        for (ConfigRecord r : records) {
            if (!r.service.isEmpty() && r.port > 0 && r.port <= 65535) {
                List<String> tags = new ArrayList<>(r.tags);
                tags.add("verified");
                out.add(new ConfigRecord(r.service, r.port + 100, true, tags));
            }
        }
        return out;
    }

    static String serializeJson(List<ConfigRecord> records) {
        List<String> items = new ArrayList<>();
        for (ConfigRecord r : records) {
            List<String> q = new ArrayList<>();
            for (String t : r.tags) {
                q.add("\\\"" + t + "\\\"");
            }
            items.add("{\\\"service\\\":\\\"" + r.service + "\\\",\\\"port\\\":" + r.port + ",\\\"tls\\\":" + r.tls + ",\\\"tags\\\":[" + String.join(",", q) + "]}");
        }
        return "[" + String.join(",", items) + "]";
    }

    public static void main(String[] args) {
        String raw = "# Services\\nauth | 8000 | false | core,jwt\\ngateway | 8080 | true | edge,http\\ninvalid | -5 | false | bad\\n";
        List<ConfigRecord> parsed = parseRecords(raw);
        List<ConfigRecord> valid = validateAndMutate(parsed);
        String jsonOut = serializeJson(valid);
        if (parsed.size() != 3 || valid.size() != 2 || !jsonOut.contains("\\\"service\\\":\\\"auth\\\"")) {
            throw new AssertionError();
        }
        System.out.println(jsonOut + "\\nBENCH_03_OK");
    }
}
"""

SOURCES[("03", "js")] = """class ConfigRecord {
  constructor(service, port, tls, tags) {
    this.service = service;
    this.port = port;
    this.tls = tls;
    this.tags = tags;
  }
}

function parseRecords(src) {
  const records = [];
  for (const line of src.split("\\n")) {
    const t = line.trim();
    if (t && !t.startsWith("#")) {
      const parts = t.split("|").map((p) => p.trim());
      if (parts.length >= 4) {
        const tags = parts[3].split(",").map((t) => t.trim());
        records.push(new ConfigRecord(parts[0], parseInt(parts[1], 10), parts[2] === "true", tags));
      }
    }
  }
  return records;
}

function validateAndMutate(records) {
  const valid = [];
  for (const r of records) {
    if (r.service && r.port > 0 && r.port <= 65535) {
      const tags = r.tags.map((t) => t.trim());
      tags.push("verified");
      valid.push(new ConfigRecord(r.service, r.port + 100, true, tags));
    }
  }
  return valid;
}

function serializeJson(records) {
  const items = records.map((r) => {
    const qtags = r.tags.map((t) => `"${t}"`).join(",");
    return `{"service":"${r.service}","port":${r.port},"tls":${r.tls},"tags":[${qtags}]}`;
  });
  return "[" + items.join(",") + "]";
}

const raw = "# Services\\nauth | 8000 | false | core,jwt\\ngateway | 8080 | true | edge,http\\ninvalid | -5 | false | bad\\n";
const parsed = parseRecords(raw);
const valid = validateAndMutate(parsed);
const jsonOut = serializeJson(valid);
if (parsed.length !== 3 || valid.length !== 2 || !jsonOut.includes('"service":"auth"')) {
  throw new Error("assert");
}
console.log(jsonOut + "\\nBENCH_03_OK");
"""

SOURCES[("03", "py")] = """from dataclasses import dataclass

@dataclass
class ConfigRecord:
    service: str
    port: int
    tls: bool
    tags: list[str]

def parseRecords(src: str) -> list[ConfigRecord]:
    records: list[ConfigRecord] = []
    for line in src.splitlines():
        line = line.strip()
        if line and not line.startswith("#"):
            parts = [p.strip() for p in line.split("|")]
            if len(parts) >= 4:
                tags = [t.strip() for t in parts[3].split(",")]
                records.append(ConfigRecord(parts[0], int(parts[1]), parts[2] == "true", tags))
    return records

def validateAndMutate(records: list[ConfigRecord]) -> list[ConfigRecord]:
    valid: list[ConfigRecord] = []
    for r in records:
        if r.service and 0 < r.port <= 65535:
            tags = [t.strip() for t in r.tags]
            tags.append("verified")
            valid.append(ConfigRecord(r.service, r.port + 100, True, tags))
    return valid

def serializeJson(records: list[ConfigRecord]) -> str:
    items: list[str] = []
    for r in records:
        qtags = ",".join(f'"{t}"' for t in r.tags)
        tls_str = "true" if r.tls else "false"
        items.append(f'{{"service":"{r.service}","port":{r.port},"tls":{tls_str},"tags":[{qtags}]}}')
    return "[" + ",".join(items) + "]"

raw = "# Services\\nauth | 8000 | false | core,jwt\\ngateway | 8080 | true | edge,http\\ninvalid | -5 | false | bad\\n"
parsed = parseRecords(raw)
valid = validateAndMutate(parsed)
jsonOut = serializeJson(valid)
assert len(parsed) == 3
assert len(valid) == 2
assert '"service":"auth"' in jsonOut
print(jsonOut + "\\nBENCH_03_OK")
"""

SOURCES[("03", "ts")] = """interface ConfigRecord {
  service: string;
  port: number;
  tls: boolean;
  tags: string[];
}

function parseRecords(src: string): ConfigRecord[] {
  const records: ConfigRecord[] = [];
  for (const line of src.split("\\n")) {
    const t = line.trim();
    if (t && !t.startsWith("#")) {
      const parts = t.split("|").map((p) => p.trim());
      if (parts.length >= 4) {
        const tags = parts[3].split(",").map((t) => t.trim());
        records.push({
          service: parts[0],
          port: parseInt(parts[1], 10),
          tls: parts[2] === "true",
          tags,
        });
      }
    }
  }
  return records;
}

function validateAndMutate(records: ConfigRecord[]): ConfigRecord[] {
  const valid: ConfigRecord[] = [];
  for (const r of records) {
    if (r.service && r.port > 0 && r.port <= 65535) {
      const tags = r.tags.map((t) => t.trim());
      tags.push("verified");
      valid.push({
        service: r.service,
        port: r.port + 100,
        tls: true,
        tags,
      });
    }
  }
  return valid;
}

function serializeJson(records: ConfigRecord[]): string {
  const items = records.map((r) => {
    const qtags = r.tags.map((t) => `"${t}"`).join(",");
    return `{"service":"${r.service}","port":${r.port},"tls":${r.tls},"tags":[${qtags}]}`;
  });
  return "[" + items.join(",") + "]";
}

const raw = "# Services\\nauth | 8000 | false | core,jwt\\ngateway | 8080 | true | edge,http\\ninvalid | -5 | false | bad\\n";
const parsed = parseRecords(raw);
const valid = validateAndMutate(parsed);
const jsonOut = serializeJson(valid);
if (parsed.length !== 3 || valid.length !== 2 || !jsonOut.includes('"service":"auth"')) {
  throw new Error("assert");
}
console.log(jsonOut + "\\nBENCH_03_OK");
"""

# ==============================================================================
# TEST 04: File System Log Aggregator & Analyzer
# ==============================================================================
SOURCES[("04", "cpp")] = """#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cassert>

struct LogSummary {
    int totalLines;
    int errorCount;
    int warnCount;
    int infoCount;
    std::string topEndpoint;
    double errorRatePct;
};

LogSummary analyzeLogs(const std::string& content) {
    std::stringstream ss(content);
    std::string line;
    int total = 0;
    int errs = 0;
    int warns = 0;
    int infos = 0;
    std::map<std::string, int> counts;
    std::string topEp = "";
    int topCnt = 0;
    while (std::getline(ss, line)) {
        if (line.empty()) {
            continue;
        }
        total += 1;
        std::stringstream ls(line);
        std::string ts, lvl, ep;
        int status;
        if (ls >> ts >> lvl >> ep >> status) {
            if (lvl == "ERROR") {
                errs += 1;
            } else if (lvl == "WARN") {
                warns += 1;
            } else if (lvl == "INFO") {
                infos += 1;
            }
            int c = ++counts[ep];
            if (c > topCnt) {
                topCnt = c;
                topEp = ep;
            }
        }
    }
    double rate = total > 0 ? (errs * 100.0) / total : 0.0;
    return {total, errs, warns, infos, topEp, rate};
}

int main() {
    std::string p = "/tmp/bench04_sample.log";
    std::string sample = "2026-11-02T10:00:01Z INFO /api/login 200\\n2026-11-02T10:00:02Z ERROR /api/pay 500\\n2026-11-02T10:00:03Z INFO /api/pay 200\\n2026-11-02T10:00:04Z WARN /api/login 429\\n2026-11-02T10:00:05Z ERROR /api/pay 503\\n";
    {
        std::ofstream out(p);
        out << sample;
    }
    std::ifstream in(p);
    std::stringstream buffer;
    buffer << in.rdbuf();
    auto s = analyzeLogs(buffer.str());
    assert(s.totalLines == 5);
    assert(s.errorCount == 2);
    assert(s.warnCount == 1);
    assert(s.infoCount == 2);
    assert(s.topEndpoint == "/api/pay");
    assert(s.errorRatePct > 39.9 && s.errorRatePct < 40.1);
    std::cout << "Total=" << s.totalLines << " Errors=" << s.errorCount << " Top=" << s.topEndpoint << "\\nBENCH_04_OK\\n";
    return 0;
}
"""

SOURCES[("04", "rs")] = """use std::collections::HashMap;
use std::fs;

struct LogSummary {
    total_lines: usize,
    error_count: usize,
    warn_count: usize,
    info_count: usize,
    top_endpoint: String,
    error_rate_pct: f64,
}

#[allow(non_snake_case)]
fn analyzeLogs(content: &str) -> LogSummary {
    let mut total = 0;
    let mut errs = 0;
    let mut warns = 0;
    let mut infos = 0;
    let mut counts: HashMap<String, usize> = HashMap::new();
    let mut top_ep = String::new();
    let mut top_cnt = 0;
    for line in content.lines() {
        let t = line.trim();
        if !t.is_empty() {
            total += 1;
            let parts: Vec<&str> = t.split_whitespace().collect();
            if parts.len() >= 3 {
                match parts[1] {
                    "ERROR" => errs += 1,
                    "WARN" => warns += 1,
                    "INFO" => infos += 1,
                    _ => {}
                }
                let ep = parts[2].to_string();
                let c = counts.entry(ep.clone()).or_insert(0);
                *c += 1;
                if *c > top_cnt {
                    top_cnt = *c;
                    top_ep = ep;
                }
            }
        }
    }
    let rate = if total > 0 { (errs as f64 * 100.0) / (total as f64) } else { 0.0 };
    LogSummary {
        total_lines: total,
        error_count: errs,
        warn_count: warns,
        info_count: infos,
        top_endpoint: top_ep,
        error_rate_pct: rate,
    }
}

fn main() {
    let p = "/tmp/bench04_sample.log";
    let sample = "2026-11-02T10:00:01Z INFO /api/login 200\\n2026-11-02T10:00:02Z ERROR /api/pay 500\\n2026-11-02T10:00:03Z INFO /api/pay 200\\n2026-11-02T10:00:04Z WARN /api/login 429\\n2026-11-02T10:00:05Z ERROR /api/pay 503\\n";
    fs::write(p, sample).unwrap();
    let loaded = fs::read_to_string(p).unwrap();
    let s = analyzeLogs(&loaded);
    assert_eq!(s.total_lines, 5);
    assert_eq!(s.error_count, 2);
    assert_eq!(s.warn_count, 1);
    assert_eq!(s.info_count, 2);
    assert_eq!(s.top_endpoint, "/api/pay");
    assert!(s.error_rate_pct > 39.9 && s.error_rate_pct < 40.1);
    println!("Total={} Errors={} Top={}\\nBENCH_04_OK", s.total_lines, s.error_count, s.top_endpoint);
}
"""

SOURCES[("04", "go")] = """package main

import (
\t"fmt"
\t"os"
\t"strings"
)

type LogSummary struct {
\ttotalLines   int
\terrorCount   int
\twarnCount    int
\tinfoCount    int
\ttopEndpoint  string
\terrorRatePct float64
}

func analyzeLogs(content string) LogSummary {
\tlines := strings.Split(content, "\\n")
\ttotal := 0
\terrs := 0
\twarns := 0
\tinfos := 0
\tcounts := make(map[string]int)
\ttopEp := ""
\ttopCnt := 0
\tfor _, line := range lines {
\t\tt := strings.TrimSpace(line)
\t\tif len(t) > 0 {
\t\t\ttotal++
\t\t\tparts := strings.Fields(t)
\t\t\tif len(parts) >= 3 {
\t\t\t\tlvl := parts[1]
\t\t\t\tep := parts[2]
\t\t\t\tif lvl == "ERROR" {
\t\t\t\t\terrs++
\t\t\t\t} else if lvl == "WARN" {
\t\t\t\t\twarns++
\t\t\t\t} else if lvl == "INFO" {
\t\t\t\t\tinfos++
\t\t\t\t}
\t\t\t\tcounts[ep]++
\t\t\t\tif counts[ep] > topCnt {
\t\t\t\t\ttopCnt = counts[ep]
\t\t\t\t\ttopEp = ep
\t\t\t\t}
\t\t\t}
\t\t}
\t}
\trate := 0.0
\tif total > 0 {
\t\trate = (float64(errs) * 100.0) / float64(total)
\t}
\treturn LogSummary{total, errs, warns, infos, topEp, rate}
}

func main() {
\tp := "/tmp/bench04_sample.log"
\tsample := "2026-11-02T10:00:01Z INFO /api/login 200\\n2026-11-02T10:00:02Z ERROR /api/pay 500\\n2026-11-02T10:00:03Z INFO /api/pay 200\\n2026-11-02T10:00:04Z WARN /api/login 429\\n2026-11-02T10:00:05Z ERROR /api/pay 503\\n"
\tos.WriteFile(p, []byte(sample), 0644)
\tdata, _ := os.ReadFile(p)
\ts := analyzeLogs(string(data))
\tif s.totalLines != 5 || s.errorCount != 2 || s.warnCount != 1 || s.infoCount != 2 || s.topEndpoint != "/api/pay" {
\t\tpanic("assert")
\t}
\tfmt.Printf("Total=%d Errors=%d Top=%s\\nBENCH_04_OK\\n", s.totalLines, s.errorCount, s.topEndpoint)
}
"""

SOURCES[("04", "java")] = """import java.nio.file.*;
import java.util.*;

public class Main {
    static class LogSummary {
        int totalLines;
        int errorCount;
        int warnCount;
        int infoCount;
        String topEndpoint;
        double errorRatePct;
        LogSummary(int t, int e, int w, int i, String top, double r) {
            totalLines = t;
            errorCount = e;
            warnCount = w;
            infoCount = i;
            topEndpoint = top;
            errorRatePct = r;
        }
    }

    static LogSummary analyzeLogs(String content) {
        int total = 0;
        int errs = 0;
        int warns = 0;
        int infos = 0;
        Map<String, Integer> counts = new HashMap<>();
        String topEp = "";
        int topCnt = 0;
        for (String line : content.split("\\n")) {
            String t = line.trim();
            if (!t.isEmpty()) {
                total++;
                String[] parts = t.split("\\\\s+");
                if (parts.length >= 3) {
                    if (parts[1].equals("ERROR")) {
                        errs++;
                    } else if (parts[1].equals("WARN")) {
                        warns++;
                    } else if (parts[1].equals("INFO")) {
                        infos++;
                    }
                    String ep = parts[2];
                    int c = counts.getOrDefault(ep, 0) + 1;
                    counts.put(ep, c);
                    if (c > topCnt) {
                        topCnt = c;
                        topEp = ep;
                    }
                }
            }
        }
        double rate = total > 0 ? (errs * 100.0) / total : 0.0;
        return new LogSummary(total, errs, warns, infos, topEp, rate);
    }

    public static void main(String[] args) throws Exception {
        Path p = Paths.get("/tmp/bench04_sample.log");
        String sample = "2026-11-02T10:00:01Z INFO /api/login 200\\n2026-11-02T10:00:02Z ERROR /api/pay 500\\n2026-11-02T10:00:03Z INFO /api/pay 200\\n2026-11-02T10:00:04Z WARN /api/login 429\\n2026-11-02T10:00:05Z ERROR /api/pay 503\\n";
        Files.write(p, sample.getBytes());
        LogSummary s = analyzeLogs(new String(Files.readAllBytes(p)));
        if (s.totalLines != 5 || s.errorCount != 2 || s.warnCount != 1 || s.infoCount != 2 || !s.topEndpoint.equals("/api/pay") || s.errorRatePct < 39.9 || s.errorRatePct > 40.1) {
            throw new AssertionError();
        }
        System.out.println("Total=" + s.totalLines + " Errors=" + s.errorCount + " Top=" + s.topEndpoint + "\\nBENCH_04_OK");
    }
}
"""

SOURCES[("04", "js")] = """const fs = require("fs");

class LogSummary {
  constructor(totalLines, errorCount, warnCount, infoCount, topEndpoint, errorRatePct) {
    this.totalLines = totalLines;
    this.errorCount = errorCount;
    this.warnCount = warnCount;
    this.infoCount = infoCount;
    this.topEndpoint = topEndpoint;
    this.errorRatePct = errorRatePct;
  }
}

function analyzeLogs(content) {
  let totalLines = 0;
  let errorCount = 0;
  let warnCount = 0;
  let infoCount = 0;
  let bestCount = 0;
  let topEndpoint = "";
  const counts = {};
  for (const line of content.split("\\n")) {
    const t = line.trim();
    if (t) {
      totalLines += 1;
      const cols = t.split(/\\s+/);
      if (cols.length >= 3) {
        const level = cols[1];
        const ep = cols[2];
        if (level === "ERROR") {
          errorCount += 1;
        } else if (level === "WARN") {
          warnCount += 1;
        } else if (level === "INFO") {
          infoCount += 1;
        }
        counts[ep] = (counts[ep] || 0) + 1;
        if (counts[ep] > bestCount) {
          bestCount = counts[ep];
          topEndpoint = ep;
        }
      }
    }
  }
  const errorRatePct = totalLines > 0 ? (errorCount * 100.0) / totalLines : 0.0;
  return new LogSummary(totalLines, errorCount, warnCount, infoCount, topEndpoint, errorRatePct);
}

const p = "/tmp/bench04_sample.log";
const sample = "2026-11-02T10:00:01Z INFO /api/login 200\\n2026-11-02T10:00:02Z ERROR /api/pay 500\\n2026-11-02T10:00:03Z INFO /api/pay 200\\n2026-11-02T10:00:04Z WARN /api/login 429\\n2026-11-02T10:00:05Z ERROR /api/pay 503\\n";
fs.writeFileSync(p, sample);
const s = analyzeLogs(fs.readFileSync(p, "utf8"));
if (s.totalLines !== 5 || s.errorCount !== 2 || s.warnCount !== 1 || s.infoCount !== 2 || s.topEndpoint !== "/api/pay" || s.errorRatePct < 39.9 || s.errorRatePct > 40.1) {
  throw new Error("assert");
}
console.log(`Total=${s.totalLines} Errors=${s.errorCount} Top=${s.topEndpoint}\\nBENCH_04_OK`);
"""

SOURCES[("04", "py")] = """from pathlib import Path
from dataclasses import dataclass

@dataclass
class LogSummary:
    totalLines: int
    errorCount: int
    warnCount: int
    infoCount: int
    topEndpoint: str
    errorRatePct: float

def analyzeLogs(content: str) -> LogSummary:
    totalLines = 0
    errorCount = 0
    warnCount = 0
    infoCount = 0
    bestCount = 0
    topEndpoint = ""
    counts: dict[str, int] = {}
    for line in content.splitlines():
        line = line.strip()
        if line:
            totalLines += 1
            cols = line.split()
            if len(cols) >= 3:
                level = cols[1]
                ep = cols[2]
                if level == "ERROR":
                    errorCount += 1
                elif level == "WARN":
                    warnCount += 1
                elif level == "INFO":
                    infoCount += 1
                cnt = counts.get(ep, 0) + 1
                counts[ep] = cnt
                if cnt > bestCount:
                    bestCount = cnt
                    topEndpoint = ep
    errorRatePct = (errorCount * 100.0) / totalLines if totalLines > 0 else 0.0
    return LogSummary(totalLines, errorCount, warnCount, infoCount, topEndpoint, errorRatePct)

p = Path("/tmp/bench04_sample.log")
sample = "2026-11-02T10:00:01Z INFO /api/login 200\\n2026-11-02T10:00:02Z ERROR /api/pay 500\\n2026-11-02T10:00:03Z INFO /api/pay 200\\n2026-11-02T10:00:04Z WARN /api/login 429\\n2026-11-02T10:00:05Z ERROR /api/pay 503\\n"
p.write_text(sample)
summary = analyzeLogs(p.read_text())
assert summary.totalLines == 5
assert summary.errorCount == 2
assert summary.warnCount == 1
assert summary.infoCount == 2
assert summary.topEndpoint == "/api/pay"
assert 39.9 < summary.errorRatePct < 40.1
print(f"Total={summary.totalLines} Errors={summary.errorCount} Top={summary.topEndpoint}\\nBENCH_04_OK")
"""

SOURCES[("04", "ts")] = """import * as fs from "fs";

interface LogSummary {
  totalLines: number;
  errorCount: number;
  warnCount: number;
  infoCount: number;
  topEndpoint: string;
  errorRatePct: number;
}

function analyzeLogs(content: string): LogSummary {
  let totalLines = 0;
  let errorCount = 0;
  let warnCount = 0;
  let infoCount = 0;
  let bestCount = 0;
  let topEndpoint = "";
  const counts: Record<string, number> = {};
  for (const line of content.split("\\n")) {
    const t = line.trim();
    if (t) {
      totalLines += 1;
      const cols = t.split(/\\s+/);
      if (cols.length >= 3) {
        const level = cols[1];
        const ep = cols[2];
        if (level === "ERROR") {
          errorCount += 1;
        } else if (level === "WARN") {
          warnCount += 1;
        } else if (level === "INFO") {
          infoCount += 1;
        }
        counts[ep] = (counts[ep] || 0) + 1;
        if (counts[ep] > bestCount) {
          bestCount = counts[ep];
          topEndpoint = ep;
        }
      }
    }
  }
  const errorRatePct = totalLines > 0 ? (errorCount * 100.0) / totalLines : 0.0;
  return {
    totalLines,
    errorCount,
    warnCount,
    infoCount,
    topEndpoint,
    errorRatePct,
  };
}

const p = "/tmp/bench04_sample.log";
const sample = "2026-11-02T10:00:01Z INFO /api/login 200\\n2026-11-02T10:00:02Z ERROR /api/pay 500\\n2026-11-02T10:00:03Z INFO /api/pay 200\\n2026-11-02T10:00:04Z WARN /api/login 429\\n2026-11-02T10:00:05Z ERROR /api/pay 503\\n";
fs.writeFileSync(p, sample);
const s = analyzeLogs(fs.readFileSync(p, "utf8"));
if (s.totalLines !== 5 || s.errorCount !== 2 || s.warnCount !== 1 || s.infoCount !== 2 || s.topEndpoint !== "/api/pay" || s.errorRatePct < 39.9 || s.errorRatePct > 40.1) {
  throw new Error("assert");
}
console.log(`Total=${s.totalLines} Errors=${s.errorCount} Top=${s.topEndpoint}\\nBENCH_04_OK`);
"""
# ==============================================================================
# TEST 05: Stateful Task/Inventory Engine
# ==============================================================================
SOURCES[("05", "cpp")] = """#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

struct Item {
    int id;
    std::string name;
    int qty;
    int priceCents;
};

struct InventoryStore {
    std::vector<Item> items;
    std::vector<Item> snapshot;
};

void beginTx(InventoryStore& st) {
    st.snapshot = st.items;
}

void rollbackTx(InventoryStore& st) {
    st.items = st.snapshot;
}

void upsertItem(InventoryStore& st, int id, const std::string& name, int qty, int price) {
    for (auto& it : st.items) {
        if (it.id == id) {
            it.name = name;
            it.qty = qty;
            it.priceCents = price;
            return;
        }
    }
    st.items.push_back({id, name, qty, price});
}

void removeItem(InventoryStore& st, int id) {
    st.items.erase(
        std::remove_if(st.items.begin(), st.items.end(), [id](const Item& i) {
            return i.id == id;
        }),
        st.items.end()
    );
}

int totalValuationCents(const InventoryStore& st) {
    int sum = 0;
    for (const auto& it : st.items) {
        sum += it.qty * it.priceCents;
    }
    return sum;
}

int main() {
    InventoryStore st;
    upsertItem(st, 1, "GPU-Node", 4, 250000);
    upsertItem(st, 2, "NVMe-4TB", 10, 30000);
    upsertItem(st, 3, "Switch-100G", 2, 150000);
    assert(totalValuationCents(st) == 1600000);
    beginTx(st);
    removeItem(st, 1);
    upsertItem(st, 2, "NVMe-4TB", 1, 30000);
    assert(totalValuationCents(st) == 330000);
    rollbackTx(st);
    assert(st.items.size() == 3);
    assert(totalValuationCents(st) == 1600000);
    std::cout << "Valuation=" << totalValuationCents(st) << "\\nBENCH_05_OK\\n";
    return 0;
}
"""

SOURCES[("05", "rs")] = """#[derive(Clone)]
struct Item {
    id: i32,
    name: String,
    qty: i32,
    price_cents: i32,
}

struct InventoryStore {
    items: Vec<Item>,
    snapshot: Vec<Item>,
}

#[allow(non_snake_case)]
fn beginTx(st: &mut InventoryStore) {
    st.snapshot = st.items.clone();
}

#[allow(non_snake_case)]
fn rollbackTx(st: &mut InventoryStore) {
    st.items = st.snapshot.clone();
}

#[allow(non_snake_case)]
fn upsertItem(st: &mut InventoryStore, id: i32, name: &str, qty: i32, price: i32) {
    for it in &mut st.items {
        if it.id == id {
            it.name = name.to_string();
            it.qty = qty;
            it.price_cents = price;
            return;
        }
    }
    st.items.push(Item {
        id,
        name: name.to_string(),
        qty,
        price_cents: price,
    });
}

#[allow(non_snake_case)]
fn removeItem(st: &mut InventoryStore, id: i32) {
    st.items.retain(|i| i.id != id);
}

#[allow(non_snake_case)]
fn totalValuationCents(st: &InventoryStore) -> i32 {
    st.items.iter().map(|i| i.qty * i.price_cents).sum()
}

fn main() {
    let mut st = InventoryStore {
        items: Vec::new(),
        snapshot: Vec::new(),
    };
    upsertItem(&mut st, 1, "GPU-Node", 4, 250000);
    upsertItem(&mut st, 2, "NVMe-4TB", 10, 30000);
    upsertItem(&mut st, 3, "Switch-100G", 2, 150000);
    assert_eq!(totalValuationCents(&st), 1600000);
    beginTx(&mut st);
    removeItem(&mut st, 1);
    upsertItem(&mut st, 2, "NVMe-4TB", 1, 30000);
    assert_eq!(totalValuationCents(&st), 330000);
    rollbackTx(&mut st);
    assert_eq!(st.items.len(), 3);
    assert_eq!(totalValuationCents(&st), 1600000);
    println!("Valuation={}\\nBENCH_05_OK", totalValuationCents(&st));
}
"""

SOURCES[("05", "go")] = """package main

import "fmt"

type Item struct {
\tid         int
\tname       string
\tqty        int
\tpriceCents int
}

type InventoryStore struct {
\titems    []Item
\tsnapshot []Item
}

func beginTx(st *InventoryStore) {
\tst.snapshot = append([]Item(nil), st.items...)
}

func rollbackTx(st *InventoryStore) {
\tst.items = append([]Item(nil), st.snapshot...)
}

func upsertItem(st *InventoryStore, id int, name string, qty int, priceCents int) {
\tfor i := range st.items {
\t\tif st.items[i].id == id {
\t\t\tst.items[i] = Item{id, name, qty, priceCents}
\t\t\treturn
\t\t}
\t}
\tst.items = append(st.items, Item{id, name, qty, priceCents})
}

func removeItem(st *InventoryStore, id int) {
\tvar next []Item
\tfor _, it := range st.items {
\t\tif it.id != id {
\t\t\tnext = append(next, it)
\t\t}
\t}
\tst.items = next
}

func totalValuationCents(st *InventoryStore) int {
\ttotal := 0
\tfor _, it := range st.items {
\t\ttotal += it.qty * it.priceCents
\t}
\treturn total
}

func main() {
\tvar st InventoryStore
\tupsertItem(&st, 1, "GPU-Node", 4, 250000)
\tupsertItem(&st, 2, "NVMe-4TB", 10, 30000)
\tupsertItem(&st, 3, "Switch-100G", 2, 150000)
\tbeginTx(&st)
\tremoveItem(&st, 1)
\tupsertItem(&st, 2, "NVMe-4TB", 1, 30000)
\trollbackTx(&st)
\tif len(st.items) != 3 || totalValuationCents(&st) != 1600000 {
\t\tpanic("assert")
\t}
\tfmt.Printf("Valuation=%d\\nBENCH_05_OK\\n", totalValuationCents(&st))
}
"""

SOURCES[("05", "java")] = """import java.util.*;

public class Main {
    static class Item {
        int id;
        String name;
        int qty;
        int priceCents;
        Item(int id, String name, int qty, int priceCents) {
            this.id = id;
            this.name = name;
            this.qty = qty;
            this.priceCents = priceCents;
        }
        Item copy() {
            return new Item(id, name, qty, priceCents);
        }
    }

    static class InventoryStore {
        List<Item> items = new ArrayList<>();
        List<Item> snapshot = new ArrayList<>();
    }

    static void beginTx(InventoryStore st) {
        st.snapshot.clear();
        for (Item it : st.items) {
            st.snapshot.add(it.copy());
        }
    }

    static void rollbackTx(InventoryStore st) {
        st.items.clear();
        for (Item it : st.snapshot) {
            st.items.add(it.copy());
        }
    }

    static void upsertItem(InventoryStore st, int id, String name, int qty, int priceCents) {
        for (int i = 0; i < st.items.size(); i++) {
            if (st.items.get(i).id == id) {
                st.items.set(i, new Item(id, name, qty, priceCents));
                return;
            }
        }
        st.items.add(new Item(id, name, qty, priceCents));
    }

    static void removeItem(InventoryStore st, int id) {
        st.items.removeIf(i -> i.id == id);
    }

    static int totalValuationCents(InventoryStore st) {
        int sum = 0;
        for (Item it : st.items) {
            sum += it.qty * it.priceCents;
        }
        return sum;
    }

    public static void main(String[] args) {
        InventoryStore st = new InventoryStore();
        upsertItem(st, 1, "GPU-Node", 4, 250000);
        upsertItem(st, 2, "NVMe-4TB", 10, 30000);
        upsertItem(st, 3, "Switch-100G", 2, 150000);
        if (totalValuationCents(st) != 1600000) {
            throw new AssertionError();
        }
        beginTx(st);
        removeItem(st, 1);
        upsertItem(st, 2, "NVMe-4TB", 1, 30000);
        if (totalValuationCents(st) != 330000) {
            throw new AssertionError();
        }
        rollbackTx(st);
        if (st.items.size() != 3 || totalValuationCents(st) != 1600000) {
            throw new AssertionError();
        }
        System.out.println("Valuation=" + totalValuationCents(st) + "\\nBENCH_05_OK");
    }
}
"""

SOURCES[("05", "js")] = """class Item {
  constructor(id, name, qty, priceCents) {
    this.id = id;
    this.name = name;
    this.qty = qty;
    this.priceCents = priceCents;
  }
}

class InventoryStore {
  constructor() {
    this.items = [];
    this.snapshot = [];
  }
}

function beginTx(store) {
  store.snapshot = store.items.map((i) => new Item(i.id, i.name, i.qty, i.priceCents));
}

function rollbackTx(store) {
  store.items = store.snapshot.map((i) => new Item(i.id, i.name, i.qty, i.priceCents));
}

function upsertItem(store, id, name, qty, priceCents) {
  const idx = store.items.findIndex((i) => i.id === id);
  if (idx >= 0) {
    store.items[idx] = new Item(id, name, qty, priceCents);
  } else {
    store.items.push(new Item(id, name, qty, priceCents));
  }
}

function removeItem(store, id) {
  store.items = store.items.filter((i) => i.id !== id);
}

function totalValuationCents(store) {
  return store.items.reduce((sum, i) => sum + i.qty * i.priceCents, 0);
}

const store = new InventoryStore();
upsertItem(store, 1, "GPU-Node", 4, 250000);
upsertItem(store, 2, "NVMe-4TB", 10, 30000);
upsertItem(store, 3, "Switch-100G", 2, 150000);
if (totalValuationCents(store) !== 1600000) {
  throw new Error("assert");
}
beginTx(store);
removeItem(store, 1);
upsertItem(store, 2, "NVMe-4TB", 1, 30000);
if (totalValuationCents(store) !== 330000) {
  throw new Error("assert");
}
rollbackTx(store);
if (store.items.length !== 3 || totalValuationCents(store) !== 1600000) {
  throw new Error("assert");
}
console.log(`Valuation=${totalValuationCents(store)}\\nBENCH_05_OK`);
"""

SOURCES[("05", "py")] = """from dataclasses import dataclass, field

@dataclass
class Item:
    id: int
    name: str
    qty: int
    priceCents: int

@dataclass
class InventoryStore:
    items: list[Item] = field(default_factory=list)
    snapshot: list[Item] = field(default_factory=list)

def beginTx(store: InventoryStore):
    store.snapshot = [Item(i.id, i.name, i.qty, i.priceCents) for i in store.items]

def rollbackTx(store: InventoryStore):
    store.items = [Item(i.id, i.name, i.qty, i.priceCents) for i in store.snapshot]

def upsertItem(store: InventoryStore, id: int, name: str, qty: int, priceCents: int):
    for i, it in enumerate(store.items):
        if it.id == id:
            store.items[i] = Item(id, name, qty, priceCents)
            return
    store.items.append(Item(id, name, qty, priceCents))

def removeItem(store: InventoryStore, id: int):
    store.items = [i for i in store.items if i.id != id]

def totalValuationCents(store: InventoryStore) -> int:
    return sum(i.qty * i.priceCents for i in store.items)

store = InventoryStore()
upsertItem(store, 1, "GPU-Node", 4, 250000)
upsertItem(store, 2, "NVMe-4TB", 10, 30000)
upsertItem(store, 3, "Switch-100G", 2, 150000)
assert totalValuationCents(store) == 1600000
beginTx(store)
removeItem(store, 1)
upsertItem(store, 2, "NVMe-4TB", 1, 30000)
assert totalValuationCents(store) == 330000
rollbackTx(store)
assert len(store.items) == 3
assert totalValuationCents(store) == 1600000
print(f"Valuation={totalValuationCents(store)}\\nBENCH_05_OK")
"""

SOURCES[("05", "ts")] = """interface Item {
  id: number;
  name: string;
  qty: number;
  priceCents: number;
}

interface InventoryStore {
  items: Item[];
  snapshot: Item[];
}

function beginTx(store: InventoryStore): void {
  store.snapshot = store.items.map((i) => ({ ...i }));
}

function rollbackTx(store: InventoryStore): void {
  store.items = store.snapshot.map((i) => ({ ...i }));
}

function upsertItem(store: InventoryStore, id: number, name: string, qty: number, priceCents: number): void {
  const idx = store.items.findIndex((i) => i.id === id);
  if (idx >= 0) {
    store.items[idx] = { id, name, qty, priceCents };
  } else {
    store.items.push({ id, name, qty, priceCents });
  }
}

function removeItem(store: InventoryStore, id: number): void {
  store.items = store.items.filter((i) => i.id !== id);
}

function totalValuationCents(store: InventoryStore): number {
  return store.items.reduce((sum, i) => sum + i.qty * i.priceCents, 0);
}

const store: InventoryStore = { items: [], snapshot: [] };
upsertItem(store, 1, "GPU-Node", 4, 250000);
upsertItem(store, 2, "NVMe-4TB", 10, 30000);
upsertItem(store, 3, "Switch-100G", 2, 150000);
if (totalValuationCents(store) !== 1600000) {
  throw new Error("assert");
}
beginTx(store);
removeItem(store, 1);
upsertItem(store, 2, "NVMe-4TB", 1, 30000);
if (totalValuationCents(store) !== 330000) {
  throw new Error("assert");
}
rollbackTx(store);
if (store.items.length !== 3 || totalValuationCents(store) !== 1600000) {
  throw new Error("assert");
}
console.log(`Valuation=${totalValuationCents(store)}\\nBENCH_05_OK`);
"""

# ==============================================================================
# TEST 06: Complex Console Command Tool (CLI)
# ==============================================================================
SOURCES[("06", "cpp")] = """#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <cassert>

struct CliResult {
    int exitCode;
    std::string output;
};

CliResult executeCliCommand(const std::vector<std::string>& args) {
    if (args.empty() || args[0] == "--help" || args[0] == "help") {
        return {0, "Usage: tool <stats|transform|pipeline> [options]"};
    }
    if (args[0] == "stats") {
        std::vector<int> nums;
        for (size_t i = 1; i < args.size(); ++i) {
            if (args[i].rfind("--values=", 0) == 0) {
                std::stringstream ss(args[i].substr(9));
                std::string item;
                while (std::getline(ss, item, ',')) {
                    if (!item.empty()) {
                        nums.push_back(std::stoi(item));
                    }
                }
            }
        }
        if (nums.empty()) {
            return {2, "Error: --values required"};
        }
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int mn = *std::min_element(nums.begin(), nums.end());
        int mx = *std::max_element(nums.begin(), nums.end());
        return {0, "count=" + std::to_string(nums.size()) + " sum=" + std::to_string(sum) + " min=" + std::to_string(mn) + " max=" + std::to_string(mx)};
    }
    if (args[0] == "pipeline") {
        std::string text = "";
        bool upper = false;
        bool rev = false;
        for (size_t i = 1; i < args.size(); ++i) {
            if (args[i].rfind("--input=", 0) == 0) {
                text = args[i].substr(8);
            } else if (args[i] == "--upper") {
                upper = true;
            } else if (args[i] == "--reverse-words") {
                rev = true;
            }
        }
        if (text.empty()) {
            return {1, "Error: empty input"};
        }
        if (upper) {
            for (char& c : text) {
                c = std::toupper(c);
            }
        }
        if (rev) {
            std::stringstream ss(text);
            std::string word;
            std::vector<std::string> words;
            while (ss >> word) {
                words.push_back(word);
            }
            std::reverse(words.begin(), words.end());
            text = "";
            for (size_t i = 0; i < words.size(); ++i) {
                if (i > 0) {
                    text += " ";
                }
                text += words[i];
            }
        }
        return {0, text};
    }
    return {127, "Unknown subcommand: " + args[0]};
}

int main() {
    auto r1 = executeCliCommand({"--help"});
    auto r2 = executeCliCommand({"stats", "--values=10,25,5,40"});
    auto r3 = executeCliCommand({"pipeline", "--input=aipl fast native cli", "--upper", "--reverse-words"});
    auto r4 = executeCliCommand({"unknown_cmd"});
    assert(r1.exitCode == 0);
    assert(r2.exitCode == 0 && r2.output == "count=4 sum=80 min=5 max=40");
    assert(r3.exitCode == 0 && r3.output == "CLI NATIVE FAST AIPL");
    assert(r4.exitCode == 127);
    std::cout << r2.output << " | " << r3.output << "\\nBENCH_06_OK\\n";
    return 0;
}
"""

SOURCES[("06", "rs")] = """struct CliResult {
    exit_code: i32,
    output: String,
}

#[allow(non_snake_case)]
fn executeCliCommand(args: &[&str]) -> CliResult {
    if args.is_empty() || args[0] == "--help" || args[0] == "help" {
        return CliResult {
            exit_code: 0,
            output: "Usage: tool <stats|transform|pipeline> [options]".to_string(),
        };
    }
    if args[0] == "stats" {
        let mut nums = Vec::new();
        for a in &args[1..] {
            if let Some(rest) = a.strip_prefix("--values=") {
                for p in rest.split(',') {
                    if let Ok(n) = p.trim().parse::<i32>() {
                        nums.push(n);
                    }
                }
            }
        }
        if nums.is_empty() {
            return CliResult {
                exit_code: 2,
                output: "Error: --values required".to_string(),
            };
        }
        let sum: i32 = nums.iter().sum();
        let mn = *nums.iter().min().unwrap();
        let mx = *nums.iter().max().unwrap();
        return CliResult {
            exit_code: 0,
            output: format!("count={} sum={} min={} max={}", nums.len(), sum, mn, mx),
        };
    }
    if args[0] == "pipeline" {
        let mut text = String::new();
        let mut upper = false;
        let mut rev = false;
        for a in &args[1..] {
            if let Some(rest) = a.strip_prefix("--input=") {
                text = rest.to_string();
            } else if *a == "--upper" {
                upper = true;
            } else if *a == "--reverse-words" {
                rev = true;
            }
        }
        if text.is_empty() {
            return CliResult {
                exit_code: 1,
                output: "Error: empty input".to_string(),
            };
        }
        if upper {
            text = text.to_uppercase();
        }
        if rev {
            let mut ws: Vec<&str> = text.split_whitespace().collect();
            ws.reverse();
            text = ws.join(" ");
        }
        return CliResult {
            exit_code: 0,
            output: text,
        };
    }
    CliResult {
        exit_code: 127,
        output: format!("Unknown subcommand: {}", args[0]),
    }
}

fn main() {
    let r1 = executeCliCommand(&["--help"]);
    let r2 = executeCliCommand(&["stats", "--values=10,25,5,40"]);
    let r3 = executeCliCommand(&["pipeline", "--input=aipl fast native cli", "--upper", "--reverse-words"]);
    let r4 = executeCliCommand(&["unknown_cmd"]);
    assert_eq!(r1.exit_code, 0);
    assert_eq!(r2.exit_code, 0);
    assert_eq!(r2.output, "count=4 sum=80 min=5 max=40");
    assert_eq!(r3.exit_code, 0);
    assert_eq!(r3.output, "CLI NATIVE FAST AIPL");
    assert_eq!(r4.exit_code, 127);
    println!("{} | {}\\nBENCH_06_OK", r2.output, r3.output);
}
"""

SOURCES[("06", "go")] = """package main

import (
\t"fmt"
\t"strconv"
\t"strings"
)

type CliResult struct {
\texitCode int
\toutput   string
}

func executeCliCommand(args []string) CliResult {
\tif len(args) == 0 || args[0] == "--help" || args[0] == "help" {
\t\treturn CliResult{0, "Usage: tool <stats|transform|pipeline> [options]"}
\t}
\tif args[0] == "stats" {
\t\tvar nums []int
\t\tfor _, a := range args[1:] {
\t\t\tif strings.HasPrefix(a, "--values=") {
\t\t\t\tfor _, p := range strings.Split(a[9:], ",") {
\t\t\t\t\tif n, err := strconv.Atoi(strings.TrimSpace(p)); err == nil {
\t\t\t\t\t\tnums = append(nums, n)
\t\t\t\t\t}
\t\t\t\t}
\t\t\t}
\t\t}
\t\tif len(nums) == 0 {
\t\t\treturn CliResult{2, "Error: --values required"}
\t\t}
\t\tsum := 0
\t\tmn := nums[0]
\t\tmx := nums[0]
\t\tfor _, n := range nums {
\t\t\tsum += n
\t\t\tif n < mn {
\t\t\t\tmn = n
\t\t\t}
\t\t\tif n > mx {
\t\t\t\tmx = n
\t\t\t}
\t\t}
\t\treturn CliResult{0, fmt.Sprintf("count=%d sum=%d min=%d max=%d", len(nums), sum, mn, mx)}
\t}
\tif args[0] == "pipeline" {
\t\ttext := ""
\t\tupper := false
\t\trev := false
\t\tfor _, a := range args[1:] {
\t\t\tif strings.HasPrefix(a, "--input=") {
\t\t\t\ttext = a[8:]
\t\t\t} else if a == "--upper" {
\t\t\t\tupper = true
\t\t\t} else if a == "--reverse-words" {
\t\t\t\trev = true
\t\t\t}
\t\t}
\t\tif len(text) == 0 {
\t\t\treturn CliResult{1, "Error: empty input"}
\t\t}
\t\tif upper {
\t\t\ttext = strings.ToUpper(text)
\t\t}
\t\tif rev {
\t\t\tws := strings.Fields(text)
\t\t\tfor i, j := 0, len(ws)-1; i < j; i, j = i+1, j-1 {
\t\t\t\tws[i], ws[j] = ws[j], ws[i]
\t\t\t}
\t\t\ttext = strings.Join(ws, " ")
\t\t}
\t\treturn CliResult{0, text}
\t}
\treturn CliResult{127, fmt.Sprintf("Unknown subcommand: %s", args[0])}
}

func main() {
\tr1 := executeCliCommand([]string{"--help"})
\tr2 := executeCliCommand([]string{"stats", "--values=10,25,5,40"})
\tr3 := executeCliCommand([]string{"pipeline", "--input=aipl fast native cli", "--upper", "--reverse-words"})
\tr4 := executeCliCommand([]string{"unknown_cmd"})
\tif r1.exitCode != 0 || r2.exitCode != 0 || r3.exitCode != 0 || r4.exitCode != 127 {
\t\tpanic("assert exit codes")
\t}
\tfmt.Printf("%s | %s\\nBENCH_06_OK\\n", r2.output, r3.output)
}
"""

SOURCES[("06", "java")] = """import java.util.*;

public class Main {
    static class CliResult {
        int exitCode;
        String output;
        CliResult(int c, String o) {
            exitCode = c;
            output = o;
        }
    }

    static CliResult executeCliCommand(String[] args) {
        if (args.length == 0 || args[0].equals("--help") || args[0].equals("help")) {
            return new CliResult(0, "Usage: tool <stats|transform|pipeline> [options]");
        }
        if (args[0].equals("stats")) {
            List<Integer> nums = new ArrayList<>();
            for (int i = 1; i < args.length; i++) {
                if (args[i].startsWith("--values=")) {
                    for (String p : args[i].substring(9).split(",")) {
                        nums.add(Integer.parseInt(p.trim()));
                    }
                }
            }
            if (nums.isEmpty()) {
                return new CliResult(2, "Error: --values required");
            }
            int sum = 0;
            int mn = nums.get(0);
            int mx = nums.get(0);
            for (int n : nums) {
                sum += n;
                if (n < mn) mn = n;
                if (n > mx) mx = n;
            }
            return new CliResult(0, "count=" + nums.size() + " sum=" + sum + " min=" + mn + " max=" + mx);
        }
        if (args[0].equals("pipeline")) {
            String text = "";
            boolean upper = false;
            boolean rev = false;
            for (int i = 1; i < args.length; i++) {
                if (args[i].startsWith("--input=")) {
                    text = args[i].substring(8);
                } else if (args[i].equals("--upper")) {
                    upper = true;
                } else if (args[i].equals("--reverse-words")) {
                    rev = true;
                }
            }
            if (text.isEmpty()) {
                return new CliResult(1, "Error: empty input");
            }
            if (upper) {
                text = text.toUpperCase();
            }
            if (rev) {
                String[] ws = text.split("\\\\s+");
                Collections.reverse(Arrays.asList(ws));
                text = String.join(" ", ws);
            }
            return new CliResult(0, text);
        }
        return new CliResult(127, "Unknown subcommand: " + args[0]);
    }

    public static void main(String[] args) {
        CliResult r1 = executeCliCommand(new String[]{"--help"});
        CliResult r2 = executeCliCommand(new String[]{"stats", "--values=10,25,5,40"});
        CliResult r3 = executeCliCommand(new String[]{"pipeline", "--input=aipl fast native cli", "--upper", "--reverse-words"});
        CliResult r4 = executeCliCommand(new String[]{"unknown_cmd"});
        if (r1.exitCode != 0 || r2.exitCode != 0 || !r2.output.equals("count=4 sum=80 min=5 max=40") || r3.exitCode != 0 || !r3.output.equals("CLI NATIVE FAST AIPL") || r4.exitCode != 127) {
            throw new AssertionError();
        }
        System.out.println(r2.output + " | " + r3.output + "\\nBENCH_06_OK");
    }
}
"""

SOURCES[("06", "js")] = """class CliResult {
  constructor(exitCode, output) {
    this.exitCode = exitCode;
    this.output = output;
  }
}

function executeCliCommand(args) {
  if (args.length === 0 || args[0] === "--help" || args[0] === "help") {
    return new CliResult(0, "Usage: tool <stats|transform|pipeline> [options]");
  }
  if (args[0] === "stats") {
    const nums = [];
    for (const a of args.slice(1)) {
      if (a.startsWith("--values=")) {
        for (const p of a.slice(9).split(",")) {
          nums.push(parseInt(p.trim(), 10));
        }
      }
    }
    if (nums.length === 0) {
      return new CliResult(2, "Error: --values required");
    }
    const sum = nums.reduce((a, b) => a + b, 0);
    const mn = Math.min(...nums);
    const mx = Math.max(...nums);
    return new CliResult(0, `count=${nums.length} sum=${sum} min=${mn} max=${mx}`);
  }
  if (args[0] === "pipeline") {
    let text = "";
    let upper = false;
    let rev = false;
    for (const a of args.slice(1)) {
      if (a.startsWith("--input=")) {
        text = a.slice(8);
      } else if (a === "--upper") {
        upper = true;
      } else if (a === "--reverse-words") {
        rev = true;
      }
    }
    if (!text) {
      return new CliResult(1, "Error: empty input");
    }
    if (upper) {
      text = text.toUpperCase();
    }
    if (rev) {
      text = text.split(" ").reverse().join(" ");
    }
    return new CliResult(0, text);
  }
  return new CliResult(127, `Unknown subcommand: ${args[0]}`);
}

const r1 = executeCliCommand(["--help"]);
const r2 = executeCliCommand(["stats", "--values=10,25,5,40"]);
const r3 = executeCliCommand(["pipeline", "--input=aipl fast native cli", "--upper", "--reverse-words"]);
const r4 = executeCliCommand(["unknown_cmd"]);
if (r1.exitCode !== 0 || r2.exitCode !== 0 || r2.output !== "count=4 sum=80 min=5 max=40" || r3.exitCode !== 0 || r3.output !== "CLI NATIVE FAST AIPL" || r4.exitCode !== 127) {
  throw new Error("assert");
}
console.log(`${r2.output} | ${r3.output}\\nBENCH_06_OK`);
"""

SOURCES[("06", "py")] = """from dataclasses import dataclass

@dataclass
class CliResult:
    exitCode: int
    output: str

def executeCliCommand(args: list[str]) -> CliResult:
    if not args or args[0] == "--help" or args[0] == "help":
        return CliResult(0, "Usage: tool <stats|transform|pipeline> [options]")
    if args[0] == "stats":
        nums: list[int] = []
        for a in args[1:]:
            if a.startswith("--values="):
                for p in a[9:].split(","):
                    p = p.strip()
                    if p:
                        nums.append(int(p))
        if not nums:
            return CliResult(2, "Error: --values required")
        count = len(nums)
        s = sum(nums)
        mn = min(nums)
        mx = max(nums)
        return CliResult(0, f"count={count} sum={s} min={mn} max={mx}")
    if args[0] == "pipeline":
        text = ""
        upper = False
        rev = False
        for a in args[1:]:
            if a.startswith("--input="):
                text = a[8:]
            elif a == "--upper":
                upper = True
            elif a == "--reverse-words":
                rev = True
        if not text:
            return CliResult(1, "Error: empty input")
        if upper:
            text = text.upper()
        if rev:
            text = " ".join(reversed(text.split()))
        return CliResult(0, text)
    return CliResult(127, f"Unknown subcommand: {args[0]}")

r1 = executeCliCommand(["--help"])
r2 = executeCliCommand(["stats", "--values=10,25,5,40"])
r3 = executeCliCommand(["pipeline", "--input=aipl fast native cli", "--upper", "--reverse-words"])
r4 = executeCliCommand(["unknown_cmd"])
assert r1.exitCode == 0
assert r2.exitCode == 0 and r2.output == "count=4 sum=80 min=5 max=40"
assert r3.exitCode == 0 and r3.output == "CLI NATIVE FAST AIPL"
assert r4.exitCode == 127
print(f"{r2.output} | {r3.output}\\nBENCH_06_OK")
"""

SOURCES[("06", "ts")] = """interface CliResult {
  exitCode: number;
  output: string;
}

function executeCliCommand(args: string[]): CliResult {
  if (args.length === 0 || args[0] === "--help" || args[0] === "help") {
    return { exitCode: 0, output: "Usage: tool <stats|transform|pipeline> [options]" };
  }
  if (args[0] === "stats") {
    const nums: number[] = [];
    for (const a of args.slice(1)) {
      if (a.startsWith("--values=")) {
        for (const p of a.slice(9).split(",")) {
          nums.push(parseInt(p.trim(), 10));
        }
      }
    }
    if (nums.length === 0) {
      return { exitCode: 2, output: "Error: --values required" };
    }
    const sum = nums.reduce((a, b) => a + b, 0);
    const mn = Math.min(...nums);
    const mx = Math.max(...nums);
    return { exitCode: 0, output: `count=${nums.length} sum=${sum} min=${mn} max=${mx}` };
  }
  if (args[0] === "pipeline") {
    let text = "";
    let upper = false;
    let rev = false;
    for (const a of args.slice(1)) {
      if (a.startsWith("--input=")) {
        text = a.slice(8);
      } else if (a === "--upper") {
        upper = true;
      } else if (a === "--reverse-words") {
        rev = true;
      }
    }
    if (!text) {
      return { exitCode: 1, output: "Error: empty input" };
    }
    if (upper) {
      text = text.toUpperCase();
    }
    if (rev) {
      text = text.split(" ").reverse().join(" ");
    }
    return { exitCode: 0, output: text };
  }
  return { exitCode: 127, output: `Unknown subcommand: ${args[0]}` };
}

const r1 = executeCliCommand(["--help"]);
const r2 = executeCliCommand(["stats", "--values=10,25,5,40"]);
const r3 = executeCliCommand(["pipeline", "--input=aipl fast native cli", "--upper", "--reverse-words"]);
const r4 = executeCliCommand(["unknown_cmd"]);
if (r1.exitCode !== 0 || r2.exitCode !== 0 || r2.output !== "count=4 sum=80 min=5 max=40" || r3.exitCode !== 0 || r3.output !== "CLI NATIVE FAST AIPL" || r4.exitCode !== 127) {
  throw new Error("assert");
}
console.log(`${r2.output} | ${r3.output}\\nBENCH_06_OK`);
"""
# ==============================================================================
# TEST 07: Graph Pathfinder (A*) & Priority Scheduler
# ==============================================================================
SOURCES[("07", "cpp")] = """#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>

struct ScheduledJob {
    int id;
    int priority;
    int durationMs;
    double pathCost;
};

double astarCost(const std::vector<std::vector<int>>& grid, int sx, int sy, int gx, int gy) {
    int h = grid.size();
    int w = grid[0].size();
    std::vector<std::vector<double>> dist(h, std::vector<double>(w, 1e9));
    std::vector<std::vector<bool>> visited(h, std::vector<bool>(w, false));
    dist[sy][sx] = 0.0;
    std::vector<std::pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    std::vector<double> costs = {1.0, 1.0, 1.0, 1.0, 1.4142, 1.4142, 1.4142, 1.4142};
    while (true) {
        double bestF = 1e9;
        int bx = -1;
        int by = -1;
        bool found = false;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (!visited[y][x] && dist[y][x] < 1e8) {
                    double f = dist[y][x] + std::sqrt((gx - x)*(gx - x) + (gy - y)*(gy - y));
                    if (f < bestF) {
                        bestF = f;
                        bx = x;
                        by = y;
                        found = true;
                    }
                }
            }
        }
        if (!found) {
            return -1.0;
        }
        if (bx == gx && by == gy) {
            return dist[by][bx];
        }
        visited[by][bx] = true;
        for (size_t i = 0; i < dirs.size(); ++i) {
            int nx = bx + dirs[i].first;
            int ny = by + dirs[i].second;
            if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
                if (grid[ny][nx] == 0 && dist[by][bx] + costs[i] < dist[ny][nx]) {
                    dist[ny][nx] = dist[by][bx] + costs[i];
                }
            }
        }
    }
}

std::vector<int> scheduleJobsByPriority(std::vector<ScheduledJob> jobs) {
    std::sort(jobs.begin(), jobs.end(), [](const ScheduledJob& a, const ScheduledJob& b) {
        if (a.priority != b.priority) {
            return a.priority > b.priority;
        }
        return a.pathCost < b.pathCost;
    });
    std::vector<int> order;
    for (const auto& j : jobs) {
        order.push_back(j.id);
    }
    return order;
}

int main() {
    std::vector<std::vector<int>> grid(6, std::vector<int>(6, 0));
    grid[0][2] = 1;
    grid[1][2] = 1;
    grid[2][2] = 1;
    double c1 = astarCost(grid, 0, 0, 5, 0);
    double c2 = astarCost(grid, 0, 5, 5, 5);
    assert(c1 > c2 && c2 > 0.0);
    std::vector<ScheduledJob> jobs = {{101, 5, 100, c1}, {102, 10, 200, c1}, {103, 5, 150, c2}};
    auto order = scheduleJobsByPriority(jobs);
    assert(order[0] == 102 && order[1] == 103 && order[2] == 101);
    std::cout << "Order=" << order[0] << "," << order[1] << "," << order[2] << "\\nBENCH_07_OK\\n";
    return 0;
}
"""

SOURCES[("07", "rs")] = """struct ScheduledJob {
    id: i32,
    priority: i32,
    duration_ms: i32,
    path_cost: f64,
}

#[allow(non_snake_case)]
fn astarCost(grid: &[Vec<i32>], sx: usize, sy: usize, gx: usize, gy: usize) -> f64 {
    let h = grid.len();
    let w = grid[0].len();
    let mut dist = vec![vec![1e9_f64; w]; h];
    let mut visited = vec![vec![false; w]; h];
    dist[sy][sx] = 0.0;
    let dirs: [(isize, isize, f64); 8] = [
        (1, 0, 1.0),
        (-1, 0, 1.0),
        (0, 1, 1.0),
        (0, -1, 1.0),
        (1, 1, 1.4142),
        (1, -1, 1.4142),
        (-1, 1, 1.4142),
        (-1, -1, 1.4142),
    ];
    loop {
        let mut best_f = 1e9;
        let mut bx = 0;
        let mut by = 0;
        let mut found = false;
        for y in 0..h {
            for x in 0..w {
                if !visited[y][x] && dist[y][x] < 1e8 {
                    let f = dist[y][x] + (((gx as isize - x as isize).pow(2) + (gy as isize - y as isize).pow(2)) as f64).sqrt();
                    if f < best_f {
                        best_f = f;
                        bx = x;
                        by = y;
                        found = true;
                    }
                }
            }
        }
        if !found {
            return -1.0;
        }
        if bx == gx && by == gy {
            return dist[by][bx];
        }
        visited[by][bx] = true;
        for (dx, dy, cost) in dirs {
            let nx = bx as isize + dx;
            let ny = by as isize + dy;
            if nx >= 0 && nx < w as isize && ny >= 0 && ny < h as isize {
                let ux = nx as usize;
                let uy = ny as usize;
                if grid[uy][ux] == 0 && dist[by][bx] + cost < dist[uy][ux] {
                    dist[uy][ux] = dist[by][bx] + cost;
                }
            }
        }
    }
}

#[allow(non_snake_case)]
fn scheduleJobsByPriority(mut jobs: Vec<ScheduledJob>) -> Vec<i32> {
    jobs.sort_by(|a, b| {
        if a.priority != b.priority {
            b.priority.cmp(&a.priority)
        } else {
            a.path_cost.partial_cmp(&b.path_cost).unwrap()
        }
    });
    jobs.iter().map(|j| j.id).collect()
}

fn main() {
    let mut grid = vec![vec![0; 6]; 6];
    grid[0][2] = 1;
    grid[1][2] = 1;
    grid[2][2] = 1;
    let c1 = astarCost(&grid, 0, 0, 5, 0);
    let c2 = astarCost(&grid, 0, 5, 5, 5);
    assert!(c1 > c2 && c2 > 0.0);
    let jobs = vec![
        ScheduledJob { id: 101, priority: 5, duration_ms: 100, path_cost: c1 },
        ScheduledJob { id: 102, priority: 10, duration_ms: 200, path_cost: c1 },
        ScheduledJob { id: 103, priority: 5, duration_ms: 150, path_cost: c2 },
    ];
    let order = scheduleJobsByPriority(jobs);
    assert_eq!(order, vec![102, 103, 101]);
    println!("Order={},{},{}\\nBENCH_07_OK", order[0], order[1], order[2]);
}
"""

SOURCES[("07", "go")] = """package main

import (
\t"fmt"
\t"math"
\t"sort"
)

type ScheduledJob struct {
\tid         int
\tpriority   int
\tdurationMs int
\tpathCost   float64
}

func astarCost(g [][]int, sx, sy, gx, gy int) float64 {
\th := len(g)
\tw := len(g[0])
\tdist := make([][]float64, h)
\tvisited := make([][]bool, h)
\tfor i := range dist {
\t\tdist[i] = make([]float64, w)
\t\tvisited[i] = make([]bool, w)
\t\tfor j := range dist[i] {
\t\t\tdist[i][j] = 1e9
\t\t}
\t}
\tdist[sy][sx] = 0.0
\tdirs := [][3]float64{
\t\t{1, 0, 1.0}, {-1, 0, 1.0}, {0, 1, 1.0}, {0, -1, 1.0},
\t\t{1, 1, 1.4142}, {1, -1, 1.4142}, {-1, 1, 1.4142}, {-1, -1, 1.4142},
\t}
\tfor {
\t\tbestF := 1e9
\t\tbx := -1
\t\tby := -1
\t\tfound := false
\t\tfor y := 0; y < h; y++ {
\t\t\tfor x := 0; x < w; x++ {
\t\t\t\tif !visited[y][x] && dist[y][x] < 1e8 {
\t\t\t\t\tf := dist[y][x] + math.Sqrt(float64((gx-x)*(gx-x)+(gy-y)*(gy-y)))
\t\t\t\t\tif f < bestF {
\t\t\t\t\t\tbestF = f
\t\t\t\t\t\tbx = x
\t\t\t\t\t\tby = y
\t\t\t\t\t\tfound = true
\t\t\t\t\t}
\t\t\t\t}
\t\t\t}
\t\t}
\t\tif !found {
\t\t\treturn -1.0
\t\t}
\t\tif bx == gx && by == gy {
\t\t\treturn dist[by][bx]
\t\t}
\t\tvisited[by][bx] = true
\t\tfor _, d := range dirs {
\t\t\tnx := bx + int(d[0])
\t\t\tny := by + int(d[1])
\t\t\tif nx >= 0 && nx < w && ny >= 0 && ny < h {
\t\t\t\tif g[ny][nx] == 0 && dist[by][bx]+d[2] < dist[ny][nx] {
\t\t\t\t\tdist[ny][nx] = dist[by][bx] + d[2]
\t\t\t\t}
\t\t\t}
\t\t}
\t}
}

func scheduleJobsByPriority(jobs []ScheduledJob) []int {
\tsorted := make([]ScheduledJob, len(jobs))
\tcopy(sorted, jobs)
\tsort.Slice(sorted, func(i, j int) bool {
\t\tif sorted[i].priority != sorted[j].priority {
\t\t\treturn sorted[i].priority > sorted[j].priority
\t\t}
\t\treturn sorted[i].pathCost < sorted[j].pathCost
\t})
\tvar order []int
\tfor _, j := range sorted {
\t\torder = append(order, j.id)
\t}
\treturn order
}

func main() {
\tg := make([][]int, 6)
\tfor i := range g {
\t\tg[i] = make([]int, 6)
\t}
\tg[0][2] = 1
\tg[1][2] = 1
\tg[2][2] = 1
\tc1 := astarCost(g, 0, 0, 5, 0)
\tc2 := astarCost(g, 0, 5, 5, 5)
\tif c1 <= c2 || c2 <= 0.0 {
\t\tpanic("assert")
\t}
\tjobs := []ScheduledJob{
\t\t{101, 5, 100, c1},
\t\t{102, 10, 200, c1},
\t\t{103, 5, 150, c2},
\t}
\torder := scheduleJobsByPriority(jobs)
\tif order[0] != 102 || order[1] != 103 || order[2] != 101 {
\t\tpanic("assert order")
\t}
\tfmt.Printf("Order=%d,%d,%d\\nBENCH_07_OK\\n", order[0], order[1], order[2])
}
"""

SOURCES[("07", "java")] = """import java.util.*;

public class Main {
    static class ScheduledJob {
        int id;
        int priority;
        int durationMs;
        double pathCost;
        ScheduledJob(int id, int priority, int durationMs, double pathCost) {
            this.id = id;
            this.priority = priority;
            this.durationMs = durationMs;
            this.pathCost = pathCost;
        }
    }

    static double astarCost(int[][] g, int sx, int sy, int gx, int gy) {
        int h = g.length;
        int w = g[0].length;
        double[][] dist = new double[h][w];
        boolean[][] visited = new boolean[h][w];
        for (int i = 0; i < h; i++) {
            Arrays.fill(dist[i], 1e9);
        }
        dist[sy][sx] = 0.0;
        int[][] dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
        double[] costs = {1.0, 1.0, 1.0, 1.0, 1.4142, 1.4142, 1.4142, 1.4142};
        while (true) {
            double bestF = 1e9;
            int bx = -1;
            int by = -1;
            boolean found = false;
            for (int y = 0; y < h; y++) {
                for (int x = 0; x < w; x++) {
                    if (!visited[y][x] && dist[y][x] < 1e8) {
                        double f = dist[y][x] + Math.sqrt((gx - x)*(gx - x) + (gy - y)*(gy - y));
                        if (f < bestF) {
                            bestF = f;
                            bx = x;
                            by = y;
                            found = true;
                        }
                    }
                }
            }
            if (!found) return -1.0;
            if (bx == gx && by == gy) return dist[by][bx];
            visited[by][bx] = true;
            for (int i = 0; i < dirs.length; i++) {
                int nx = bx + dirs[i][0];
                int ny = by + dirs[i][1];
                if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
                    if (g[ny][nx] == 0 && dist[by][bx] + costs[i] < dist[ny][nx]) {
                        dist[ny][nx] = dist[by][bx] + costs[i];
                    }
                }
            }
        }
    }

    static List<Integer> scheduleJobsByPriority(List<ScheduledJob> jobs) {
        List<ScheduledJob> sorted = new ArrayList<>(jobs);
        sorted.sort((a, b) -> {
            if (a.priority != b.priority) {
                return Integer.compare(b.priority, a.priority);
            }
            return Double.compare(a.pathCost, b.pathCost);
        });
        List<Integer> order = new ArrayList<>();
        for (ScheduledJob j : sorted) {
            order.add(j.id);
        }
        return order;
    }

    public static void main(String[] args) {
        int[][] g = new int[6][6];
        g[0][2] = 1;
        g[1][2] = 1;
        g[2][2] = 1;
        double c1 = astarCost(g, 0, 0, 5, 0);
        double c2 = astarCost(g, 0, 5, 5, 5);
        if (c1 <= c2 || c2 <= 0.0) throw new AssertionError();
        List<ScheduledJob> jobs = Arrays.asList(
            new ScheduledJob(101, 5, 100, c1),
            new ScheduledJob(102, 10, 200, c1),
            new ScheduledJob(103, 5, 150, c2)
        );
        List<Integer> order = scheduleJobsByPriority(jobs);
        if (order.get(0) != 102 || order.get(1) != 103 || order.get(2) != 101) throw new AssertionError();
        System.out.println("Order=" + order.get(0) + "," + order.get(1) + "," + order.get(2) + "\\nBENCH_07_OK");
    }
}
"""

SOURCES[("07", "js")] = """class ScheduledJob {
  constructor(id, priority, durationMs, pathCost) {
    this.id = id;
    this.priority = priority;
    this.durationMs = durationMs;
    this.pathCost = pathCost;
  }
}

function astarCost(g, sx, sy, gx, gy) {
  const h = g.length;
  const w = g[0].length;
  const dist = Array.from({ length: h }, () => Array(w).fill(1e9));
  const visited = Array.from({ length: h }, () => Array(w).fill(false));
  dist[sy][sx] = 0.0;
  const dirs = [
    [1, 0, 1.0], [-1, 0, 1.0], [0, 1, 1.0], [0, -1, 1.0],
    [1, 1, 1.4142], [1, -1, 1.4142], [-1, 1, 1.4142], [-1, -1, 1.4142]
  ];
  while (true) {
    let bestF = 1e9;
    let bx = -1;
    let by = -1;
    let found = false;
    for (let y = 0; y < h; y++) {
      for (let x = 0; x < w; x++) {
        if (!visited[y][x] && dist[y][x] < 1e8) {
          const f = dist[y][x] + Math.sqrt((gx - x) ** 2 + (gy - y) ** 2);
          if (f < bestF) {
            bestF = f;
            bx = x;
            by = y;
            found = true;
          }
        }
      }
    }
    if (!found) {
      return -1.0;
    }
    if (bx === gx && by === gy) {
      return dist[by][bx];
    }
    visited[by][bx] = true;
    for (const [dx, dy, cost] of dirs) {
      const nx = bx + dx;
      const ny = by + dy;
      if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
        if (g[ny][nx] === 0 && dist[by][bx] + cost < dist[ny][nx]) {
          dist[ny][nx] = dist[by][bx] + cost;
        }
      }
    }
  }
}

function scheduleJobsByPriority(jobs) {
  const sorted = [...jobs].sort((a, b) => {
    if (a.priority !== b.priority) {
      return b.priority - a.priority;
    }
    return a.pathCost - b.pathCost;
  });
  return sorted.map((j) => j.id);
}

const g = Array.from({ length: 6 }, () => Array(6).fill(0));
g[0][2] = 1;
g[1][2] = 1;
g[2][2] = 1;
const c1 = astarCost(g, 0, 0, 5, 0);
const c2 = astarCost(g, 0, 5, 5, 5);
if (c1 <= c2 || c2 <= 0.0) {
  throw new Error("assert");
}
const jobs = [
  new ScheduledJob(101, 5, 100, c1),
  new ScheduledJob(102, 10, 200, c1),
  new ScheduledJob(103, 5, 150, c2),
];
const order = scheduleJobsByPriority(jobs);
if (order[0] !== 102 || order[1] !== 103 || order[2] !== 101) {
  throw new Error("assert");
}
console.log(`Order=${order.join(",")}\\nBENCH_07_OK`);
"""

SOURCES[("07", "py")] = """import math
from dataclasses import dataclass

@dataclass
class ScheduledJob:
    id: int
    priority: int
    durationMs: int
    pathCost: float

def astarCost(grid: list[list[int]], sx: int, sy: int, gx: int, gy: int) -> float:
    h = len(grid)
    w = len(grid[0])
    dist = [[1e9 for _ in range(w)] for _ in range(h)]
    visited = [[False for _ in range(w)] for _ in range(h)]
    dist[sy][sx] = 0.0
    dirs = [
        (1, 0, 1.0),
        (-1, 0, 1.0),
        (0, 1, 1.0),
        (0, -1, 1.0),
        (1, 1, 1.4142),
        (1, -1, 1.4142),
        (-1, 1, 1.4142),
        (-1, -1, 1.4142),
    ]
    while True:
        bestF = 1e9
        bx = -1
        by = -1
        found = False
        for y in range(h):
            for x in range(w):
                if not visited[y][x] and dist[y][x] < 1e8:
                    f = dist[y][x] + math.sqrt((gx - x) ** 2 + (gy - y) ** 2)
                    if f < bestF:
                        bestF = f
                        bx = x
                        by = y
                        found = True
        if not found:
            return -1.0
        if bx == gx and by == gy:
            return dist[by][bx]
        visited[by][bx] = True
        for dx, dy, cost in dirs:
            nx = bx + dx
            ny = by + dy
            if 0 <= nx < w and 0 <= ny < h:
                if grid[ny][nx] == 0 and dist[by][bx] + cost < dist[ny][nx]:
                    dist[ny][nx] = dist[by][bx] + cost

def scheduleJobsByPriority(jobs: list[ScheduledJob]) -> list[int]:
    sortedJobs = sorted(jobs, key=lambda j: (-j.priority, j.pathCost))
    return [j.id for j in sortedJobs]

grid = [[0 for _ in range(6)] for _ in range(6)]
grid[0][2] = 1
grid[1][2] = 1
grid[2][2] = 1
c1 = astarCost(grid, 0, 0, 5, 0)
c2 = astarCost(grid, 0, 5, 5, 5)
assert c1 > c2 and c2 > 0.0
jobs = [
    ScheduledJob(101, 5, 100, c1),
    ScheduledJob(102, 10, 200, c1),
    ScheduledJob(103, 5, 150, c2),
]
order = scheduleJobsByPriority(jobs)
assert order == [102, 103, 101]
print(f"Order={','.join(str(i) for i in order)}\\nBENCH_07_OK")
"""

SOURCES[("07", "ts")] = """interface ScheduledJob {
  id: number;
  priority: number;
  durationMs: number;
  pathCost: number;
}

function astarCost(g: number[][], sx: number, sy: number, gx: number, gy: number): number {
  const h = g.length;
  const w = g[0].length;
  const dist: number[][] = Array.from({ length: h }, () => Array(w).fill(1e9));
  const visited: boolean[][] = Array.from({ length: h }, () => Array(w).fill(false));
  dist[sy][sx] = 0.0;
  const dirs: [number, number, number][] = [
    [1, 0, 1.0], [-1, 0, 1.0], [0, 1, 1.0], [0, -1, 1.0],
    [1, 1, 1.4142], [1, -1, 1.4142], [-1, 1, 1.4142], [-1, -1, 1.4142]
  ];
  while (true) {
    let bestF = 1e9;
    let bx = -1;
    let by = -1;
    let found = false;
    for (let y = 0; y < h; y++) {
      for (let x = 0; x < w; x++) {
        if (!visited[y][x] && dist[y][x] < 1e8) {
          const f = dist[y][x] + Math.sqrt((gx - x) ** 2 + (gy - y) ** 2);
          if (f < bestF) {
            bestF = f;
            bx = x;
            by = y;
            found = true;
          }
        }
      }
    }
    if (!found) {
      return -1.0;
    }
    if (bx === gx && by === gy) {
      return dist[by][bx];
    }
    visited[by][bx] = true;
    for (const [dx, dy, cost] of dirs) {
      const nx = bx + dx;
      const ny = by + dy;
      if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
        if (g[ny][nx] === 0 && dist[by][bx] + cost < dist[ny][nx]) {
          dist[ny][nx] = dist[by][bx] + cost;
        }
      }
    }
  }
}

function scheduleJobsByPriority(jobs: ScheduledJob[]): number[] {
  const sorted = [...jobs].sort((a, b) => {
    if (a.priority !== b.priority) {
      return b.priority - a.priority;
    }
    return a.pathCost - b.pathCost;
  });
  return sorted.map((j) => j.id);
}

const g: number[][] = Array.from({ length: 6 }, () => Array(6).fill(0));
g[0][2] = 1;
g[1][2] = 1;
g[2][2] = 1;
const c1 = astarCost(g, 0, 0, 5, 0);
const c2 = astarCost(g, 0, 5, 5, 5);
if (c1 <= c2 || c2 <= 0.0) {
  throw new Error("assert");
}
const jobs: ScheduledJob[] = [
  { id: 101, priority: 5, durationMs: 100, pathCost: c1 },
  { id: 102, priority: 10, durationMs: 200, pathCost: c1 },
  { id: 103, priority: 5, durationMs: 150, pathCost: c2 },
];
const order = scheduleJobsByPriority(jobs);
if (order[0] !== 102 || order[1] !== 103 || order[2] !== 101) {
  throw new Error("assert");
}
console.log(`Order=${order.join(",")}\\nBENCH_07_OK`);
"""

# ==============================================================================
# TEST 08: Arithmetic/Logical Expression Interpreter & Mini-VM
# ==============================================================================
SOURCES[("08", "cpp")] = """#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <cassert>

int precedence(const std::string& op) {
    if (op == "*" || op == "/") {
        return 3;
    }
    if (op == "+" || op == "-") {
        return 2;
    }
    if (op == ">" || op == "==") {
        return 1;
    }
    return 0;
}

std::vector<std::string> compileInfixToRpn(const std::string& expr) {
    std::vector<std::string> out;
    std::vector<std::string> ops;
    std::stringstream ss(expr);
    std::string token;
    while (ss >> token) {
        if (token == "(") {
            ops.push_back(token);
        } else if (token == ")") {
            while (!ops.empty() && ops.back() != "(") {
                out.push_back(ops.back());
                ops.pop_back();
            }
            if (!ops.empty()) {
                ops.pop_back();
            }
        } else if (precedence(token) > 0) {
            while (!ops.empty() && precedence(ops.back()) >= precedence(token)) {
                out.push_back(ops.back());
                ops.pop_back();
            }
            ops.push_back(token);
        } else {
            out.push_back(token);
        }
    }
    while (!ops.empty()) {
        out.push_back(ops.back());
        ops.pop_back();
    }
    return out;
}

int evalRpnVm(const std::vector<std::string>& tokens, const std::map<std::string, int>& env) {
    std::vector<int> stack;
    for (const auto& token : tokens) {
        if (precedence(token) > 0) {
            int b = stack.back();
            stack.pop_back();
            int a = stack.back();
            stack.pop_back();
            if (token == "+") {
                stack.push_back(a + b);
            } else if (token == "-") {
                stack.push_back(a - b);
            } else if (token == "*") {
                stack.push_back(a * b);
            } else if (token == "/") {
                if (b == 0) {
                    throw std::runtime_error("division by zero");
                }
                stack.push_back(a / b);
            } else if (token == ">") {
                stack.push_back(a > b ? 1 : 0);
            } else if (token == "==") {
                stack.push_back(a == b ? 1 : 0);
            }
        } else if (env.count(token)) {
            stack.push_back(env.at(token));
        } else {
            stack.push_back(std::stoi(token));
        }
    }
    return stack.back();
}

int main() {
    std::map<std::string, int> env = {{"x", 12}, {"y", 5}};
    int v1 = evalRpnVm(compileInfixToRpn("( x + y * 4 ) - 2"), env);
    int v2 = evalRpnVm(compileInfixToRpn("x * 2 > y + 10"), env);
    assert(v1 == 30 && v2 == 1);
    std::cout << "v1=" << v1 << " v2=" << v2 << "\\nBENCH_08_OK\\n";
    return 0;
}
"""

SOURCES[("08", "rs")] = """use std::collections::HashMap;

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
    println!("v1={} v2={}\\nBENCH_08_OK", v1, v2);
}
"""

SOURCES[("08", "go")] = """package main

import (
\t"fmt"
\t"strconv"
\t"strings"
)

func precedence(op string) int {
\tif op == "*" || op == "/" {
\t\treturn 3
\t}
\tif op == "+" || op == "-" {
\t\treturn 2
\t}
\tif op == ">" || op == "==" {
\t\treturn 1
\t}
\treturn 0
}

func compileInfixToRpn(expr string) []string {
\tvar out []string
\tvar ops []string
\ttokens := strings.Fields(expr)
\tfor _, token := range tokens {
\t\tif token == "(" {
\t\t\tops = append(ops, token)
\t\t} else if token == ")" {
\t\t\tfor len(ops) > 0 && ops[len(ops)-1] != "(" {
\t\t\t\tout = append(out, ops[len(ops)-1])
\t\t\t\tops = ops[:len(ops)-1]
\t\t\t}
\t\t\tif len(ops) > 0 {
\t\t\t\tops = ops[:len(ops)-1]
\t\t\t}
\t\t} else if precedence(token) > 0 {
\t\t\tfor len(ops) > 0 && precedence(ops[len(ops)-1]) >= precedence(token) {
\t\t\t\tout = append(out, ops[len(ops)-1])
\t\t\t\tops = ops[:len(ops)-1]
\t\t\t}
\t\t\tops = append(ops, token)
\t\t} else {
\t\t\tout = append(out, token)
\t\t}
\t}
\tfor len(ops) > 0 {
\t\tout = append(out, ops[len(ops)-1])
\t\tops = ops[:len(ops)-1]
\t}
\treturn out
}

func evalRpnVm(tokens []string, env map[string]int) int {
\tvar stack []int
\tfor _, token := range tokens {
\t\tif precedence(token) > 0 {
\t\t\tb := stack[len(stack)-1]
\t\t\tstack = stack[:len(stack)-1]
\t\t\ta := stack[len(stack)-1]
\t\t\tstack = stack[:len(stack)-1]
\t\t\tswitch token {
\t\t\tcase "+":
\t\t\t\tstack = append(stack, a+b)
\t\t\tcase "-":
\t\t\t\tstack = append(stack, a-b)
\t\t\tcase "*":
\t\t\t\tstack = append(stack, a*b)
\t\t\tcase "/":
\t\t\t\tif b == 0 {
\t\t\t\t\tpanic("division by zero")
\t\t\t\t}
\t\t\t\tstack = append(stack, a/b)
\t\t\tcase ">":
\t\t\t\tif a > b {
\t\t\t\t\tstack = append(stack, 1)
\t\t\t\t} else {
\t\t\t\t\tstack = append(stack, 0)
\t\t\t\t}
\t\t\tcase "==":
\t\t\t\tif a == b {
\t\t\t\t\tstack = append(stack, 1)
\t\t\t\t} else {
\t\t\t\t\tstack = append(stack, 0)
\t\t\t\t}
\t\t\t}
\t\t} else if val, ok := env[token]; ok {
\t\t\tstack = append(stack, val)
\t\t} else {
\t\t\tn, _ := strconv.Atoi(token)
\t\t\tstack = append(stack, n)
\t\t}
\t}
\treturn stack[len(stack)-1]
}

func main() {
\tenv := map[string]int{"x": 12, "y": 5}
\tv1 := evalRpnVm(compileInfixToRpn("( x + y * 4 ) - 2"), env)
\tv2 := evalRpnVm(compileInfixToRpn("x * 2 > y + 10"), env)
\tif v1 != 30 || v2 != 1 {
\t\tpanic("assert")
\t}
\tfmt.Printf("v1=%d v2=%d\\nBENCH_08_OK\\n", v1, v2)
}
"""

SOURCES[("08", "java")] = """import java.util.*;

public class Main {
    static int precedence(String op) {
        if (op.equals("*") || op.equals("/")) {
            return 3;
        }
        if (op.equals("+") || op.equals("-")) {
            return 2;
        }
        if (op.equals(">") || op.equals("==")) {
            return 1;
        }
        return 0;
    }

    static List<String> compileInfixToRpn(String expr) {
        List<String> out = new ArrayList<>();
        Stack<String> ops = new Stack<>();
        for (String token : expr.trim().split("\\\\s+")) {
            if (token.equals("(")) {
                ops.push(token);
            } else if (token.equals(")")) {
                while (!ops.isEmpty() && !ops.peek().equals("(")) {
                    out.add(ops.pop());
                }
                if (!ops.isEmpty()) {
                    ops.pop();
                }
            } else if (precedence(token) > 0) {
                while (!ops.isEmpty() && precedence(ops.peek()) >= precedence(token)) {
                    out.add(ops.pop());
                }
                ops.push(token);
            } else {
                out.add(token);
            }
        }
        while (!ops.isEmpty()) {
            out.add(ops.pop());
        }
        return out;
    }

    static int evalRpnVm(List<String> tokens, Map<String, Integer> env) {
        Stack<Integer> stack = new Stack<>();
        for (String token : tokens) {
            if (precedence(token) > 0) {
                int b = stack.pop();
                int a = stack.pop();
                if (token.equals("+")) {
                    stack.push(a + b);
                } else if (token.equals("-")) {
                    stack.push(a - b);
                } else if (token.equals("*")) {
                    stack.push(a * b);
                } else if (token.equals("/")) {
                    if (b == 0) {
                        throw new ArithmeticException("division by zero");
                    }
                    stack.push(a / b);
                } else if (token.equals(">")) {
                    stack.push(a > b ? 1 : 0);
                } else if (token.equals("==")) {
                    stack.push(a == b ? 1 : 0);
                }
            } else if (env.containsKey(token)) {
                stack.push(env.get(token));
            } else {
                stack.push(Integer.parseInt(token));
            }
        }
        return stack.peek();
    }

    public static void main(String[] args) {
        Map<String, Integer> env = new HashMap<>();
        env.put("x", 12);
        env.put("y", 5);
        int v1 = evalRpnVm(compileInfixToRpn("( x + y * 4 ) - 2"), env);
        int v2 = evalRpnVm(compileInfixToRpn("x * 2 > y + 10"), env);
        if (v1 != 30 || v2 != 1) {
            throw new AssertionError();
        }
        System.out.println("v1=" + v1 + " v2=" + v2 + "\\nBENCH_08_OK");
    }
}
"""

SOURCES[("08", "js")] = """function precedence(op) {
  if (op === "*" || op === "/") {
    return 3;
  }
  if (op === "+" || op === "-") {
    return 2;
  }
  if (op === ">" || op === "==") {
    return 1;
  }
  return 0;
}

function compileInfixToRpn(expr) {
  const out = [];
  const ops = [];
  for (const token of expr.trim().split(/\\s+/)) {
    if (token === "(") {
      ops.push(token);
    } else if (token === ")") {
      while (ops.length > 0 && ops[ops.length - 1] !== "(") {
        out.push(ops.pop());
      }
      if (ops.length > 0) {
        ops.pop();
      }
    } else if (precedence(token) > 0) {
      while (ops.length > 0 && precedence(ops[ops.length - 1]) >= precedence(token)) {
        out.push(ops.pop());
      }
      ops.push(token);
    } else {
      out.push(token);
    }
  }
  while (ops.length > 0) {
    out.push(ops.pop());
  }
  return out;
}

function evalRpnVm(tokens, env) {
  const stack = [];
  for (const token of tokens) {
    if (precedence(token) > 0) {
      const b = stack.pop();
      const a = stack.pop();
      if (token === "+") {
        stack.push(a + b);
      } else if (token === "-") {
        stack.push(a - b);
      } else if (token === "*") {
        stack.push(a * b);
      } else if (token === "/") {
        if (b === 0) {
          throw new Error("division by zero");
        }
        stack.push(Math.trunc(a / b));
      } else if (token === ">") {
        stack.push(a > b ? 1 : 0);
      } else if (token === "==") {
        stack.push(a === b ? 1 : 0);
      }
    } else if (token in env) {
      stack.push(env[token]);
    } else {
      stack.push(parseInt(token, 10));
    }
  }
  return stack[stack.length - 1];
}

const env = { x: 12, y: 5 };
const v1 = evalRpnVm(compileInfixToRpn("( x + y * 4 ) - 2"), env);
const v2 = evalRpnVm(compileInfixToRpn("x * 2 > y + 10"), env);
if (v1 !== 30 || v2 !== 1) {
  throw new Error("assert");
}
console.log(`v1=${v1} v2=${v2}\\nBENCH_08_OK`);
"""

SOURCES[("08", "py")] = """def precedence(op: str) -> int:
    if op == "*" or op == "/":
        return 3
    if op == "+" or op == "-":
        return 2
    if op == ">" or op == "==":
        return 1
    return 0

def compileInfixToRpn(expr: str) -> list[str]:
    out: list[str] = []
    ops: list[str] = []
    for token in expr.split():
        if token == "(":
            ops.append(token)
        elif token == ")":
            while ops and ops[-1] != "(":
                out.append(ops.pop())
            if ops:
                ops.pop()
        elif precedence(token) > 0:
            while ops and precedence(ops[-1]) >= precedence(token):
                out.append(ops.pop())
            ops.append(token)
        else:
            out.append(token)
    while ops:
        out.append(ops.pop())
    return out

def evalRpnVm(tokens: list[str], env: dict[str, int]) -> int:
    stack: list[int] = []
    for token in tokens:
        if precedence(token) > 0:
            b = stack.pop()
            a = stack.pop()
            if token == "+":
                stack.append(a + b)
            elif token == "-":
                stack.append(a - b)
            elif token == "*":
                stack.append(a * b)
            elif token == "/":
                if b == 0:
                    raise ZeroDivisionError("division by zero")
                stack.append(a // b)
            elif token == ">":
                stack.append(1 if a > b else 0)
            elif token == "==":
                stack.append(1 if a == b else 0)
        elif token in env:
            stack.append(env[token])
        else:
            stack.append(int(token))
    return stack[-1]

env = {"x": 12, "y": 5}
v1 = evalRpnVm(compileInfixToRpn("( x + y * 4 ) - 2"), env)
v2 = evalRpnVm(compileInfixToRpn("x * 2 > y + 10"), env)
assert v1 == 30 and v2 == 1
print(f"v1={v1} v2={v2}\\nBENCH_08_OK")
"""

SOURCES[("08", "ts")] = """function precedence(op: string): number {
  if (op === "*" || op === "/") {
    return 3;
  }
  if (op === "+" || op === "-") {
    return 2;
  }
  if (op === ">" || op === "==") {
    return 1;
  }
  return 0;
}

function compileInfixToRpn(expr: string): string[] {
  const out: string[] = [];
  const ops: string[] = [];
  for (const token of expr.trim().split(/\\s+/)) {
    if (token === "(") {
      ops.push(token);
    } else if (token === ")") {
      while (ops.length > 0 && ops[ops.length - 1] !== "(") {
        out.push(ops.pop()!);
      }
      if (ops.length > 0) {
        ops.pop();
      }
    } else if (precedence(token) > 0) {
      while (ops.length > 0 && precedence(ops[ops.length - 1]) >= precedence(token)) {
        out.push(ops.pop()!);
      }
      ops.push(token);
    } else {
      out.push(token);
    }
  }
  while (ops.length > 0) {
    out.push(ops.pop()!);
  }
  return out;
}

function evalRpnVm(tokens: string[], env: Record<string, number>): number {
  const stack: number[] = [];
  for (const token of tokens) {
    if (precedence(token) > 0) {
      const b = stack.pop()!;
      const a = stack.pop()!;
      if (token === "+") {
        stack.push(a + b);
      } else if (token === "-") {
        stack.push(a - b);
      } else if (token === "*") {
        stack.push(a * b);
      } else if (token === "/") {
        if (b === 0) {
          throw new Error("division by zero");
        }
        stack.push(Math.trunc(a / b));
      } else if (token === ">") {
        stack.push(a > b ? 1 : 0);
      } else if (token === "==") {
        stack.push(a === b ? 1 : 0);
      }
    } else if (token in env) {
      stack.push(env[token]);
    } else {
      stack.push(parseInt(token, 10));
    }
  }
  return stack[stack.length - 1];
}

const env: Record<string, number> = { x: 12, y: 5 };
const v1 = evalRpnVm(compileInfixToRpn("( x + y * 4 ) - 2"), env);
const v2 = evalRpnVm(compileInfixToRpn("x * 2 > y + 10"), env);
if (v1 !== 30 || v2 !== 1) {
  throw new Error("assert");
}
console.log(`v1=${v1} v2=${v2}\\nBENCH_08_OK`);
"""
# ==============================================================================
# TEST 09: Simple Notepad Program
# ==============================================================================
SOURCES[("09", "cpp")] = """#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

struct NotepadDoc {
    std::string text;
    size_t cursor;
    std::vector<std::string> undoStack;
    std::vector<std::string> redoStack;
};

NotepadDoc notepadNew(const std::string& initial) {
    return {initial, initial.size(), {}, {}};
}

void notepadInsert(NotepadDoc& doc, const std::string& ins) {
    doc.undoStack.push_back(doc.text);
    doc.redoStack.clear();
    doc.cursor = std::min(doc.cursor, doc.text.size());
    doc.text.insert(doc.cursor, ins);
    doc.cursor += ins.size();
}

void notepadReplaceAll(NotepadDoc& doc, const std::string& target, const std::string& repl) {
    doc.undoStack.push_back(doc.text);
    doc.redoStack.clear();
    size_t pos = 0;
    while ((pos = doc.text.find(target, pos)) != std::string::npos) {
        doc.text.replace(pos, target.size(), repl);
        pos += repl.size();
    }
    doc.cursor = doc.text.size();
}

void notepadUndo(NotepadDoc& doc) {
    if (!doc.undoStack.empty()) {
        doc.redoStack.push_back(doc.text);
        doc.text = doc.undoStack.back();
        doc.undoStack.pop_back();
        doc.cursor = doc.text.size();
    }
}

void notepadRedo(NotepadDoc& doc) {
    if (!doc.redoStack.empty()) {
        doc.undoStack.push_back(doc.text);
        doc.text = doc.redoStack.back();
        doc.redoStack.pop_back();
        doc.cursor = doc.text.size();
    }
}

int main() {
    auto doc = notepadNew("Hello World");
    notepadInsert(doc, " AIPL");
    assert(doc.text == "Hello World AIPL");
    notepadReplaceAll(doc, "World", "Studio");
    assert(doc.text == "Hello Studio AIPL");
    notepadUndo(doc);
    assert(doc.text == "Hello World AIPL");
    notepadRedo(doc);
    assert(doc.text == "Hello Studio AIPL");
    std::string path = "/tmp/bench09_notepad.txt";
    {
        std::ofstream out(path);
        out << doc.text;
    }
    std::ifstream in(path);
    std::stringstream ss;
    ss << in.rdbuf();
    assert(ss.str() == "Hello Studio AIPL");
    std::cout << ss.str() << "\\nBENCH_09_OK\\n";
    return 0;
}
"""

SOURCES[("09", "rs")] = """use std::fs;

struct NotepadDoc {
    text: String,
    cursor: usize,
    undo_stack: Vec<String>,
    redo_stack: Vec<String>,
}

#[allow(non_snake_case)]
fn notepadNew(initial: &str) -> NotepadDoc {
    NotepadDoc {
        text: initial.to_string(),
        cursor: initial.len(),
        undo_stack: Vec::new(),
        redo_stack: Vec::new(),
    }
}

#[allow(non_snake_case)]
fn notepadInsert(doc: &mut NotepadDoc, ins: &str) {
    doc.undo_stack.push(doc.text.clone());
    doc.redo_stack.clear();
    doc.cursor = doc.cursor.min(doc.text.len());
    doc.text.insert_str(doc.cursor, ins);
    doc.cursor += ins.len();
}

#[allow(non_snake_case)]
fn notepadReplaceAll(doc: &mut NotepadDoc, target: &str, repl: &str) {
    doc.undo_stack.push(doc.text.clone());
    doc.redo_stack.clear();
    doc.text = doc.text.replace(target, repl);
    doc.cursor = doc.text.len();
}

#[allow(non_snake_case)]
fn notepadUndo(doc: &mut NotepadDoc) {
    if let Some(prev) = doc.undo_stack.pop() {
        doc.redo_stack.push(doc.text.clone());
        doc.text = prev;
        doc.cursor = doc.text.len();
    }
}

#[allow(non_snake_case)]
fn notepadRedo(doc: &mut NotepadDoc) {
    if let Some(next) = doc.redo_stack.pop() {
        doc.undo_stack.push(doc.text.clone());
        doc.text = next;
        doc.cursor = doc.text.len();
    }
}

fn main() {
    let mut doc = notepadNew("Hello World");
    notepadInsert(&mut doc, " AIPL");
    assert_eq!(doc.text, "Hello World AIPL");
    notepadReplaceAll(&mut doc, "World", "Studio");
    assert_eq!(doc.text, "Hello Studio AIPL");
    notepadUndo(&mut doc);
    assert_eq!(doc.text, "Hello World AIPL");
    notepadRedo(&mut doc);
    assert_eq!(doc.text, "Hello Studio AIPL");
    let path = "/tmp/bench09_notepad.txt";
    fs::write(path, &doc.text).unwrap();
    let loaded = fs::read_to_string(path).unwrap();
    assert_eq!(loaded, "Hello Studio AIPL");
    println!("{}\\nBENCH_09_OK", loaded);
}
"""

SOURCES[("09", "go")] = """package main

import (
\t"fmt"
\t"os"
\t"strings"
)

type NotepadDoc struct {
\ttext      string
\tcursor    int
\tundoStack []string
\tredoStack []string
}

func notepadNew(initial string) NotepadDoc {
\treturn NotepadDoc{
\t\ttext:   initial,
\t\tcursor: len(initial),
\t}
}

func notepadInsert(doc *NotepadDoc, ins string) {
\tdoc.undoStack = append(doc.undoStack, doc.text)
\tdoc.redoStack = nil
\tif doc.cursor > len(doc.text) {
\t\tdoc.cursor = len(doc.text)
\t}
\tif doc.cursor < 0 {
\t\tdoc.cursor = 0
\t}
\tdoc.text = doc.text[:doc.cursor] + ins + doc.text[doc.cursor:]
\tdoc.cursor += len(ins)
}

func notepadReplaceAll(doc *NotepadDoc, target, repl string) {
\tdoc.undoStack = append(doc.undoStack, doc.text)
\tdoc.redoStack = nil
\tdoc.text = strings.ReplaceAll(doc.text, target, repl)
\tdoc.cursor = len(doc.text)
}

func notepadUndo(doc *NotepadDoc) {
\tif len(doc.undoStack) > 0 {
\t\tdoc.redoStack = append(doc.redoStack, doc.text)
\t\tdoc.text = doc.undoStack[len(doc.undoStack)-1]
\t\tdoc.undoStack = doc.undoStack[:len(doc.undoStack)-1]
\t\tdoc.cursor = len(doc.text)
\t}
}

func notepadRedo(doc *NotepadDoc) {
\tif len(doc.redoStack) > 0 {
\t\tdoc.undoStack = append(doc.undoStack, doc.text)
\t\tdoc.text = doc.redoStack[len(doc.redoStack)-1]
\t\tdoc.redoStack = doc.redoStack[:len(doc.redoStack)-1]
\t\tdoc.cursor = len(doc.text)
\t}
}

func main() {
\tdoc := notepadNew("Hello World")
\tnotepadInsert(&doc, " AIPL")
\tnotepadReplaceAll(&doc, "World", "Studio")
\tnotepadUndo(&doc)
\tif doc.text != "Hello World AIPL" {
\t\tpanic("assert")
\t}
\tnotepadRedo(&doc)
\tif doc.text != "Hello Studio AIPL" {
\t\tpanic("assert")
\t}
\tp := "/tmp/bench09_notepad.txt"
\tos.WriteFile(p, []byte(doc.text), 0644)
\tdata, _ := os.ReadFile(p)
\tif string(data) != "Hello Studio AIPL" {
\t\tpanic("assert")
\t}
\tfmt.Printf("%s\\nBENCH_09_OK\\n", string(data))
}
"""

SOURCES[("09", "java")] = """import java.nio.file.*;
import java.util.*;

public class Main {
    static class NotepadDoc {
        String text;
        int cursor;
        List<String> undoStack = new ArrayList<>();
        List<String> redoStack = new ArrayList<>();
        NotepadDoc(String t) {
            text = t;
            cursor = t.length();
        }
    }

    static NotepadDoc notepadNew(String initial) {
        return new NotepadDoc(initial);
    }

    static void notepadInsert(NotepadDoc doc, String ins) {
        doc.undoStack.add(doc.text);
        doc.redoStack.clear();
        doc.cursor = Math.max(0, Math.min(doc.cursor, doc.text.length()));
        doc.text = doc.text.substring(0, doc.cursor) + ins + doc.text.substring(doc.cursor);
        doc.cursor += ins.length();
    }

    static void notepadReplaceAll(NotepadDoc doc, String target, String repl) {
        doc.undoStack.add(doc.text);
        doc.redoStack.clear();
        doc.text = doc.text.replace(target, repl);
        doc.cursor = doc.text.length();
    }

    static void notepadUndo(NotepadDoc doc) {
        if (!doc.undoStack.isEmpty()) {
            doc.redoStack.add(doc.text);
            doc.text = doc.undoStack.remove(doc.undoStack.size() - 1);
            doc.cursor = doc.text.length();
        }
    }

    static void notepadRedo(NotepadDoc doc) {
        if (!doc.redoStack.isEmpty()) {
            doc.undoStack.add(doc.text);
            doc.text = doc.redoStack.remove(doc.redoStack.size() - 1);
            doc.cursor = doc.text.length();
        }
    }

    public static void main(String[] args) throws Exception {
        NotepadDoc doc = notepadNew("Hello World");
        notepadInsert(doc, " AIPL");
        if (!doc.text.equals("Hello World AIPL")) throw new AssertionError();
        notepadReplaceAll(doc, "World", "Studio");
        if (!doc.text.equals("Hello Studio AIPL")) throw new AssertionError();
        notepadUndo(doc);
        if (!doc.text.equals("Hello World AIPL")) throw new AssertionError();
        notepadRedo(doc);
        if (!doc.text.equals("Hello Studio AIPL")) throw new AssertionError();
        Path p = Paths.get("/tmp/bench09_notepad.txt");
        Files.write(p, doc.text.getBytes());
        String loaded = new String(Files.readAllBytes(p));
        if (!loaded.equals("Hello Studio AIPL")) throw new AssertionError();
        System.out.println(loaded + "\\nBENCH_09_OK");
    }
}
"""

SOURCES[("09", "js")] = """const fs = require("fs");

class NotepadDoc {
  constructor(text) {
    this.text = text;
    this.cursor = text.length;
    this.undoStack = [];
    this.redoStack = [];
  }
}

function notepadNew(initial) {
  return new NotepadDoc(initial);
}

function notepadInsert(doc, ins) {
  doc.undoStack.push(doc.text);
  doc.redoStack = [];
  doc.cursor = Math.max(0, Math.min(doc.cursor, doc.text.length));
  doc.text = doc.text.slice(0, doc.cursor) + ins + doc.text.slice(doc.cursor);
  doc.cursor += ins.length;
}

function notepadReplaceAll(doc, target, repl) {
  doc.undoStack.push(doc.text);
  doc.redoStack = [];
  doc.text = doc.text.split(target).join(repl);
  doc.cursor = doc.text.length;
}

function notepadUndo(doc) {
  if (doc.undoStack.length > 0) {
    doc.redoStack.push(doc.text);
    doc.text = doc.undoStack.pop();
    doc.cursor = doc.text.length;
  }
}

function notepadRedo(doc) {
  if (doc.redoStack.length > 0) {
    doc.undoStack.push(doc.text);
    doc.text = doc.redoStack.pop();
    doc.cursor = doc.text.length;
  }
}

const doc = notepadNew("Hello World");
notepadInsert(doc, " AIPL");
if (doc.text !== "Hello World AIPL") {
  throw new Error("assert");
}
notepadReplaceAll(doc, "World", "Studio");
if (doc.text !== "Hello Studio AIPL") {
  throw new Error("assert");
}
notepadUndo(doc);
if (doc.text !== "Hello World AIPL") {
  throw new Error("assert");
}
notepadRedo(doc);
if (doc.text !== "Hello Studio AIPL") {
  throw new Error("assert");
}
const p = "/tmp/bench09_notepad.txt";
fs.writeFileSync(p, doc.text);
const loaded = fs.readFileSync(p, "utf8");
if (loaded !== "Hello Studio AIPL") {
  throw new Error("assert");
}
console.log(`${loaded}\\nBENCH_09_OK`);
"""

SOURCES[("09", "py")] = """from pathlib import Path
from dataclasses import dataclass, field

@dataclass
class NotepadDoc:
    text: str
    cursor: int
    undoStack: list[str] = field(default_factory=list)
    redoStack: list[str] = field(default_factory=list)

def notepadNew(initial: str) -> NotepadDoc:
    return NotepadDoc(text=initial, cursor=len(initial))

def notepadInsert(doc: NotepadDoc, ins: str):
    doc.undoStack.append(doc.text)
    doc.redoStack.clear()
    doc.cursor = max(0, min(doc.cursor, len(doc.text)))
    doc.text = doc.text[:doc.cursor] + ins + doc.text[doc.cursor:]
    doc.cursor += len(ins)

def notepadReplaceAll(doc: NotepadDoc, target: str, repl: str):
    doc.undoStack.append(doc.text)
    doc.redoStack.clear()
    doc.text = doc.text.replace(target, repl)
    doc.cursor = len(doc.text)

def notepadUndo(doc: NotepadDoc):
    if doc.undoStack:
        doc.redoStack.append(doc.text)
        doc.text = doc.undoStack.pop()
        doc.cursor = len(doc.text)

def notepadRedo(doc: NotepadDoc):
    if doc.redoStack:
        doc.undoStack.append(doc.text)
        doc.text = doc.redoStack.pop()
        doc.cursor = len(doc.text)

doc = notepadNew("Hello World")
notepadInsert(doc, " AIPL")
assert doc.text == "Hello World AIPL"
notepadReplaceAll(doc, "World", "Studio")
assert doc.text == "Hello Studio AIPL"
notepadUndo(doc)
assert doc.text == "Hello World AIPL"
notepadRedo(doc)
assert doc.text == "Hello Studio AIPL"
p = Path("/tmp/bench09_notepad.txt")
p.write_text(doc.text)
loaded = p.read_text()
assert loaded == "Hello Studio AIPL"
print(f"{loaded}\\nBENCH_09_OK")
"""

SOURCES[("09", "ts")] = """import * as fs from "fs";

interface NotepadDoc {
  text: string;
  cursor: number;
  undoStack: string[];
  redoStack: string[];
}

function notepadNew(initial: string): NotepadDoc {
  return {
    text: initial,
    cursor: initial.len ?? initial.length,
    undoStack: [],
    redoStack: [],
  };
}

function notepadInsert(doc: NotepadDoc, ins: string): void {
  doc.undoStack.push(doc.text);
  doc.redoStack = [];
  doc.cursor = Math.max(0, Math.min(doc.cursor, doc.text.length));
  doc.text = doc.text.slice(0, doc.cursor) + ins + doc.text.slice(doc.cursor);
  doc.cursor += ins.length;
}

function notepadReplaceAll(doc: NotepadDoc, target: string, repl: string): void {
  doc.undoStack.push(doc.text);
  doc.redoStack = [];
  doc.text = doc.text.split(target).join(repl);
  doc.cursor = doc.text.length;
}

function notepadUndo(doc: NotepadDoc): void {
  if (doc.undoStack.length > 0) {
    doc.redoStack.push(doc.text);
    doc.text = doc.undoStack.pop()!;
    doc.cursor = doc.text.length;
  }
}

function notepadRedo(doc: NotepadDoc): void {
  if (doc.redoStack.length > 0) {
    doc.undoStack.push(doc.text);
    doc.text = doc.redoStack.pop()!;
    doc.cursor = doc.text.length;
  }
}

const doc = notepadNew("Hello World");
notepadInsert(doc, " AIPL");
if (doc.text !== "Hello World AIPL") {
  throw new Error("assert");
}
notepadReplaceAll(doc, "World", "Studio");
if (doc.text !== "Hello Studio AIPL") {
  throw new Error("assert");
}
notepadUndo(doc);
if (doc.text !== "Hello World AIPL") {
  throw new Error("assert");
}
notepadRedo(doc);
if (doc.text !== "Hello Studio AIPL") {
  throw new Error("assert");
}
const p = "/tmp/bench09_notepad.txt";
fs.writeFileSync(p, doc.text);
const loaded = fs.readFileSync(p, "utf8");
if (loaded !== "Hello Studio AIPL") {
  throw new Error("assert");
}
console.log(`${loaded}\\nBENCH_09_OK`);
"""

# ==============================================================================
# TEST 10: 2D Physics & Particle Simulation Engine
# ==============================================================================
SOURCES[("10", "cpp")] = """#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

struct Body2D {
    int id;
    double x;
    double y;
    double vx;
    double vy;
    double radius;
    double mass;
};

void stepPhysicsWorld(std::vector<Body2D>& bodies, double dt, double worldW, double worldH) {
    for (auto& b : bodies) {
        b.vy += 9.8 * dt;
        b.x += b.vx * dt;
        b.y += b.vy * dt;
        if (b.x - b.radius < 0.0) {
            b.x = b.radius;
            b.vx = -b.vx * 0.9;
        } else if (b.x + b.radius > worldW) {
            b.x = worldW - b.radius;
            b.vx = -b.vx * 0.9;
        }
        if (b.y + b.radius > worldH) {
            b.y = worldH - b.radius;
            b.vy = -b.vy * 0.85;
        }
    }
    for (size_t i = 0; i < bodies.size(); ++i) {
        for (size_t j = i + 1; j < bodies.size(); ++j) {
            auto& a = bodies[i];
            auto& b = bodies[j];
            double dx = b.x - a.x;
            double dy = b.y - a.y;
            double distSq = dx * dx + dy * dy;
            double minDist = a.radius + b.radius;
            if (distSq < minDist * minDist && distSq > 0.0001) {
                double d = std::sqrt(distSq);
                double nx = dx / d;
                double ny = dy / d;
                double velAlongNormal = (b.vx - a.vx) * nx + (b.vy - a.vy) * ny;
                if (velAlongNormal < 0.0) {
                    double impulse = -(1.9 * velAlongNormal) / (1.0 / a.mass + 1.0 / b.mass);
                    a.vx -= (impulse / a.mass) * nx;
                    a.vy -= (impulse / a.mass) * ny;
                    b.vx += (impulse / b.mass) * nx;
                    b.vy += (impulse / b.mass) * ny;
                }
            }
        }
    }
}

int main() {
    std::vector<Body2D> world = {
        {1, 20.0, 50.0, 40.0, 0.0, 5.0, 1.0},
        {2, 28.0, 50.0, -40.0, 0.0, 5.0, 1.0}
    };
    for (int s = 0; s < 5; ++s) {
        stepPhysicsWorld(world, 0.05, 100.0, 100.0);
    }
    assert(world[0].vx < 0.0 && world[1].vx > 0.0);
    std::cout << "v0=" << static_cast<int>(std::round(world[0].vx)) << " v1=" << static_cast<int>(std::round(world[1].vx)) << "\\nBENCH_10_OK\\n";
    return 0;
}
"""

SOURCES[("10", "rs")] = """#[derive(Clone, Copy)]
struct Body2D {
    id: i32,
    x: f64,
    y: f64,
    vx: f64,
    vy: f64,
    radius: f64,
    mass: f64,
}

#[allow(non_snake_case)]
fn stepPhysicsWorld(bodies: &mut [Body2D], dt: f64, worldW: f64, worldH: f64) {
    for b in bodies.iter_mut() {
        b.vy += 9.8 * dt;
        b.x += b.vx * dt;
        b.y += b.vy * dt;
        if b.x - b.radius < 0.0 {
            b.x = b.radius;
            b.vx = -b.vx * 0.9;
        } else if b.x + b.radius > worldW {
            b.x = worldW - b.radius;
            b.vx = -b.vx * 0.9;
        }
        if b.y + b.radius > worldH {
            b.y = worldH - b.radius;
            b.vy = -b.vy * 0.85;
        }
    }
    let n = bodies.len();
    for i in 0..n {
        for j in (i + 1)..n {
            let dx = bodies[j].x - bodies[i].x;
            let dy = bodies[j].y - bodies[i].y;
            let dist_sq = dx * dx + dy * dy;
            let min_dist = bodies[i].radius + bodies[j].radius;
            if dist_sq < min_dist * min_dist && dist_sq > 0.0001 {
                let d = dist_sq.sqrt();
                let nx = dx / d;
                let ny = dy / d;
                let vel_along_normal = (bodies[j].vx - bodies[i].vx) * nx + (bodies[j].vy - bodies[i].vy) * ny;
                if vel_along_normal < 0.0 {
                    let impulse = -(1.9 * vel_along_normal) / (1.0 / bodies[i].mass + 1.0 / bodies[j].mass);
                    bodies[i].vx -= (impulse / bodies[i].mass) * nx;
                    bodies[i].vy -= (impulse / bodies[i].mass) * ny;
                    bodies[j].vx += (impulse / bodies[j].mass) * nx;
                    bodies[j].vy += (impulse / bodies[j].mass) * ny;
                }
            }
        }
    }
}

fn main() {
    let mut world = vec![
        Body2D { id: 1, x: 20.0, y: 50.0, vx: 40.0, vy: 0.0, radius: 5.0, mass: 1.0 },
        Body2D { id: 2, x: 28.0, y: 50.0, vx: -40.0, vy: 0.0, radius: 5.0, mass: 1.0 },
    ];
    for _ in 0..5 {
        stepPhysicsWorld(&mut world, 0.05, 100.0, 100.0);
    }
    assert!(world[0].vx < 0.0 && world[1].vx > 0.0);
    println!("v0={} v1={}\\nBENCH_10_OK", world[0].vx.round() as i32, world[1].vx.round() as i32);
}
"""

SOURCES[("10", "go")] = """package main

import (
\t"fmt"
\t"math"
)

type Body2D struct {
\tid     int
\tx      float64
\ty      float64
\tvx     float64
\tvy     float64
\tradius float64
\tmass   float64
}

func stepPhysicsWorld(bodies []Body2D, dt float64, worldW float64, worldH float64) {
\tfor i := range bodies {
\t\tbodies[i].vy += 9.8 * dt
\t\tbodies[i].x += bodies[i].vx * dt
\t\tbodies[i].y += bodies[i].vy * dt
\t\tif bodies[i].x-bodies[i].radius < 0.0 {
\t\t\tbodies[i].x = bodies[i].radius
\t\t\tbodies[i].vx = -bodies[i].vx * 0.9
\t\t} else if bodies[i].x+bodies[i].radius > worldW {
\t\t\tbodies[i].x = worldW - bodies[i].radius
\t\t\tbodies[i].vx = -bodies[i].vx * 0.9
\t\t}
\t\tif bodies[i].y+bodies[i].radius > worldH {
\t\t\tbodies[i].y = worldH - bodies[i].radius
\t\t\tbodies[i].vy = -bodies[i].vy * 0.85
\t\t}
\t}
\tn := len(bodies)
\tfor i := 0; i < n; i++ {
\t\tfor j := i + 1; j < n; j++ {
\t\t\tdx := bodies[j].x - bodies[i].x
\t\t\tdy := bodies[j].y - bodies[i].y
\t\t\tdistSq := dx*dx + dy*dy
\t\t\tminDist := bodies[i].radius + bodies[j].radius
\t\t\tif distSq < minDist*minDist && distSq > 0.0001 {
\t\t\t\td := math.Sqrt(distSq)
\t\t\t\tnx := dx / d
\t\t\t\tny := dy / d
\t\t\t\tvelAlongNormal := (bodies[j].vx-bodies[i].vx)*nx + (bodies[j].vy-bodies[i].vy)*ny
\t\t\t\tif velAlongNormal < 0.0 {
\t\t\t\t\timpulse := -(1.9 * velAlongNormal) / (1.0/bodies[i].mass + 1.0/bodies[j].mass)
\t\t\t\t\tbodies[i].vx -= (impulse / bodies[i].mass) * nx
\t\t\t\t\tbodies[i].vy -= (impulse / bodies[i].mass) * ny
\t\t\t\t\tbodies[j].vx += (impulse / bodies[j].mass) * nx
\t\t\t\t\tbodies[j].vy += (impulse / bodies[j].mass) * ny
\t\t\t\t}
\t\t\t}
\t\t}
\t}
}

func main() {
\tworld := []Body2D{
\t\t{1, 20.0, 50.0, 40.0, 0.0, 5.0, 1.0},
\t\t{2, 28.0, 50.0, -40.0, 0.0, 5.0, 1.0},
\t}
\tfor s := 0; s < 5; s++ {
\t\tstepPhysicsWorld(world, 0.05, 100.0, 100.0)
\t}
\tif world[0].vx >= 0.0 || world[1].vx <= 0.0 {
\t\tpanic("assert")
\t}
\tfmt.Printf("v0=%d v1=%d\\nBENCH_10_OK\\n", int(math.Round(world[0].vx)), int(math.Round(world[1].vx)))
}
"""

SOURCES[("10", "java")] = """import java.util.*;

public class Main {
    static class Body2D {
        int id;
        double x;
        double y;
        double vx;
        double vy;
        double radius;
        double mass;
        Body2D(int id, double x, double y, double vx, double vy, double radius, double mass) {
            this.id = id;
            this.x = x;
            this.y = y;
            this.vx = vx;
            this.vy = vy;
            this.radius = radius;
            this.mass = mass;
        }
    }

    static void stepPhysicsWorld(List<Body2D> bodies, double dt, double worldW, double worldH) {
        for (Body2D b : bodies) {
            b.vy += 9.8 * dt;
            b.x += b.vx * dt;
            b.y += b.vy * dt;
            if (b.x - b.radius < 0.0) {
                b.x = b.radius;
                b.vx = -b.vx * 0.9;
            } else if (b.x + b.radius > worldW) {
                b.x = worldW - b.radius;
                b.vx = -b.vx * 0.9;
            }
            if (b.y + b.radius > worldH) {
                b.y = worldH - b.radius;
                b.vy = -b.vy * 0.85;
            }
        }
        int n = bodies.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                Body2D a = bodies.get(i);
                Body2D b = bodies.get(j);
                double dx = b.x - a.x;
                double dy = b.y - a.y;
                double distSq = dx * dx + dy * dy;
                double minDist = a.radius + b.radius;
                if (distSq < minDist * minDist && distSq > 0.0001) {
                    double d = Math.sqrt(distSq);
                    double nx = dx / d;
                    double ny = dy / d;
                    double velAlongNormal = (b.vx - a.vx) * nx + (b.vy - a.vy) * ny;
                    if (velAlongNormal < 0.0) {
                        double impulse = -(1.9 * velAlongNormal) / (1.0 / a.mass + 1.0 / b.mass);
                        a.vx -= (impulse / a.mass) * nx;
                        a.vy -= (impulse / a.mass) * ny;
                        b.vx += (impulse / b.mass) * nx;
                        b.vy += (impulse / b.mass) * ny;
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        List<Body2D> world = new ArrayList<>();
        world.add(new Body2D(1, 20.0, 50.0, 40.0, 0.0, 5.0, 1.0));
        world.add(new Body2D(2, 28.0, 50.0, -40.0, 0.0, 5.0, 1.0));
        for (int s = 0; s < 5; s++) {
            stepPhysicsWorld(world, 0.05, 100.0, 100.0);
        }
        if (world.get(0).vx >= 0.0 || world.get(1).vx <= 0.0) {
            throw new AssertionError();
        }
        System.out.println("v0=" + (int)Math.round(world.get(0).vx) + " v1=" + (int)Math.round(world.get(1).vx) + "\\nBENCH_10_OK");
    }
}
"""

SOURCES[("10", "js")] = """class Body2D {
  constructor(id, x, y, vx, vy, radius, mass) {
    this.id = id;
    this.x = x;
    this.y = y;
    this.vx = vx;
    this.vy = vy;
    this.radius = radius;
    this.mass = mass;
  }
}

function stepPhysicsWorld(bodies, dt, worldW, worldH) {
  for (const b of bodies) {
    b.vy += 9.8 * dt;
    b.x += b.vx * dt;
    b.y += b.vy * dt;
    if (b.x - b.radius < 0.0) {
      b.x = b.radius;
      b.vx = -b.vx * 0.9;
    } else if (b.x + b.radius > worldW) {
      b.x = worldW - b.radius;
      b.vx = -b.vx * 0.9;
    }
    if (b.y + b.radius > worldH) {
      b.y = worldH - b.radius;
      b.vy = -b.vy * 0.85;
    }
  }
  const n = bodies.length;
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      const a = bodies[i];
      const b = bodies[j];
      const dx = b.x - a.x;
      const dy = b.y - a.y;
      const distSq = dx * dx + dy * dy;
      const minDist = a.radius + b.radius;
      if (distSq < minDist * minDist && distSq > 0.0001) {
        const d = Math.sqrt(distSq);
        const nx = dx / d;
        const ny = dy / d;
        const velAlongNormal = (b.vx - a.vx) * nx + (b.vy - a.vy) * ny;
        if (velAlongNormal < 0.0) {
          const impulse = -(1.9 * velAlongNormal) / (1.0 / a.mass + 1.0 / b.mass);
          a.vx -= (impulse / a.mass) * nx;
          a.vy -= (impulse / a.mass) * ny;
          b.vx += (impulse / b.mass) * nx;
          b.vy += (impulse / b.mass) * ny;
        }
      }
    }
  }
}

const world = [
  new Body2D(1, 20.0, 50.0, 40.0, 0.0, 5.0, 1.0),
  new Body2D(2, 28.0, 50.0, -40.0, 0.0, 5.0, 1.0)
];
for (let s = 0; s < 5; s++) {
  stepPhysicsWorld(world, 0.05, 100.0, 100.0);
}
if (world[0].vx >= 0.0 || world[1].vx <= 0.0) {
  throw new Error("assert");
}
console.log(`v0=${Math.round(world[0].vx)} v1=${Math.round(world[1].vx)}\\nBENCH_10_OK`);
"""

SOURCES[("10", "py")] = """import math
from dataclasses import dataclass

@dataclass
class Body2D:
    id: int
    x: float
    y: float
    vx: float
    vy: float
    radius: float
    mass: float

def stepPhysicsWorld(bodies: list[Body2D], dt: float, worldW: float, worldH: float):
    for b in bodies:
        b.vy += 9.8 * dt
        b.x += b.vx * dt
        b.y += b.vy * dt
        if b.x - b.radius < 0.0:
            b.x = b.radius
            b.vx = -b.vx * 0.9
        elif b.x + b.radius > worldW:
            b.x = worldW - b.radius
            b.vx = -b.vx * 0.9
        if b.y + b.radius > worldH:
            b.y = worldH - b.radius
            b.vy = -b.vy * 0.85
    n = len(bodies)
    for i in range(n):
        for j in range(i + 1, n):
            a = bodies[i]
            b = bodies[j]
            dx = b.x - a.x
            dy = b.y - a.y
            distSq = dx * dx + dy * dy
            minDist = a.radius + b.radius
            if 0.0001 < distSq < minDist * minDist:
                d = math.sqrt(distSq)
                nx = dx / d
                ny = dy / d
                velAlongNormal = (b.vx - a.vx) * nx + (b.vy - a.vy) * ny
                if velAlongNormal < 0.0:
                    impulse = -(1.9 * velAlongNormal) / (1.0 / a.mass + 1.0 / b.mass)
                    a.vx -= (impulse / a.mass) * nx
                    a.vy -= (impulse / a.mass) * ny
                    b.vx += (impulse / b.mass) * nx
                    b.vy += (impulse / b.mass) * ny

world = [
    Body2D(1, 20.0, 50.0, 40.0, 0.0, 5.0, 1.0),
    Body2D(2, 28.0, 50.0, -40.0, 0.0, 5.0, 1.0),
]
for _ in range(5):
    stepPhysicsWorld(world, 0.05, 100.0, 100.0)

assert world[0].vx < 0.0 and world[1].vx > 0.0
print(f"v0={int(round(world[0].vx))} v1={int(round(world[1].vx))}\\nBENCH_10_OK")
"""

SOURCES[("10", "ts")] = """interface Body2D {
  id: number;
  x: number;
  y: number;
  vx: number;
  vy: number;
  radius: number;
  mass: number;
}

function stepPhysicsWorld(bodies: Body2D[], dt: number, worldW: number, worldH: number): void {
  for (const b of bodies) {
    b.vy += 9.8 * dt;
    b.x += b.vx * dt;
    b.y += b.vy * dt;
    if (b.x - b.radius < 0.0) {
      b.x = b.radius;
      b.vx = -b.vx * 0.9;
    } else if (b.x + b.radius > worldW) {
      b.x = worldW - b.radius;
      b.vx = -b.vx * 0.9;
    }
    if (b.y + b.radius > worldH) {
      b.y = worldH - b.radius;
      b.vy = -b.vy * 0.85;
    }
  }
  const n = bodies.length;
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      const a = bodies[i];
      const b = bodies[j];
      const dx = b.x - a.x;
      const dy = b.y - a.y;
      const distSq = dx * dx + dy * dy;
      const minDist = a.radius + b.radius;
      if (distSq < minDist * minDist && distSq > 0.0001) {
        const d = Math.sqrt(distSq);
        const nx = dx / d;
        const ny = dy / d;
        const velAlongNormal = (b.vx - a.vx) * nx + (b.vy - a.vy) * ny;
        if (velAlongNormal < 0.0) {
          const impulse = -(1.9 * velAlongNormal) / (1.0 / a.mass + 1.0 / b.mass);
          a.vx -= (impulse / a.mass) * nx;
          a.vy -= (impulse / a.mass) * ny;
          b.vx += (impulse / b.mass) * nx;
          b.vy += (impulse / b.mass) * ny;
        }
      }
    }
  }
}

const world: Body2D[] = [
  { id: 1, x: 20.0, y: 50.0, vx: 40.0, vy: 0.0, radius: 5.0, mass: 1.0 },
  { id: 2, x: 28.0, y: 50.0, vx: -40.0, vy: 0.0, radius: 5.0, mass: 1.0 },
];
for (let s = 0; s < 5; s++) {
  stepPhysicsWorld(world, 0.05, 100.0, 100.0);
}
if (world[0].vx >= 0.0 || world[1].vx <= 0.0) {
  throw new Error("assert");
}
console.log(`v0=${Math.round(world[0].vx)} v1=${Math.round(world[1].vx)}\\nBENCH_10_OK`);
"""
# ==============================================================================
# TEST 11: Micro-Router & Stateful Protocol Handler
# ==============================================================================
SOURCES[("11", "cpp")] = """#include <iostream>
#include <string>
#include <map>
#include <cassert>

struct HttpRequest {
    std::string method;
    std::string path;
    std::string authHeader;
    std::string body;
};

struct HttpResponse {
    int status;
    std::string body;
};

HttpResponse handleRequest(const HttpRequest& req, std::map<std::string, int>& sessions) {
    if (req.path.rfind("/admin", 0) == 0 && req.authHeader != "Bearer secret-token") {
        return {401, "Unauthorized"};
    }
    if (req.method == "POST" && req.path == "/session/incr") {
        std::string user = req.body.empty() ? "guest" : req.body;
        int nextVal = ++sessions[user];
        return {200, "user=" + user + " count=" + std::to_string(nextVal)};
    }
    if (req.method == "GET" && req.path == "/admin/status") {
        return {200, "status=healthy"};
    }
    return {404, "Not Found"};
}

int main() {
    std::map<std::string, int> sessions;
    auto r1 = handleRequest({"POST", "/session/incr", "", "alice"}, sessions);
    auto r2 = handleRequest({"POST", "/session/incr", "", "alice"}, sessions);
    auto r3 = handleRequest({"GET", "/admin/status", "bad", ""}, sessions);
    auto r4 = handleRequest({"GET", "/admin/status", "Bearer secret-token", ""}, sessions);
    assert(r1.status == 200 && r2.status == 200);
    assert(r3.status == 401 && r4.status == 200);
    assert(r2.body == "user=alice count=2");
    assert(r4.body == "status=healthy");
    std::cout << r2.body << " | " << r4.body << "\\nBENCH_11_OK\\n";
    return 0;
}
"""

SOURCES[("11", "rs")] = """use std::collections::HashMap;

struct HttpRequest {
    method: String,
    path: String,
    auth_header: String,
    body: String,
}

struct HttpResponse {
    status: i32,
    body: String,
}

#[allow(non_snake_case)]
fn handleRequest(req: &HttpRequest, sessions: &mut HashMap<String, i32>) -> HttpResponse {
    if req.path.starts_with("/admin") && req.auth_header != "Bearer secret-token" {
        return HttpResponse {
            status: 401,
            body: "Unauthorized".to_string(),
        };
    }
    if req.method == "POST" && req.path == "/session/incr" {
        let user = if req.body.is_empty() { "guest".to_string() } else { req.body.clone() };
        let count = sessions.entry(user.clone()).or_insert(0);
        *count += 1;
        return HttpResponse {
            status: 200,
            body: format!("user={} count={}", user, count),
        };
    }
    if req.method == "GET" && req.path == "/admin/status" {
        return HttpResponse {
            status: 200,
            body: "status=healthy".to_string(),
        };
    }
    HttpResponse {
        status: 404,
        body: "Not Found".to_string(),
    }
}

fn main() {
    let mut sessions = HashMap::new();
    let r1 = handleRequest(&HttpRequest {
        method: "POST".into(),
        path: "/session/incr".into(),
        auth_header: "".into(),
        body: "alice".into(),
    }, &mut sessions);
    let r2 = handleRequest(&HttpRequest {
        method: "POST".into(),
        path: "/session/incr".into(),
        auth_header: "".into(),
        body: "alice".into(),
    }, &mut sessions);
    let r3 = handleRequest(&HttpRequest {
        method: "GET".into(),
        path: "/admin/status".into(),
        auth_header: "bad".into(),
        body: "".into(),
    }, &mut sessions);
    let r4 = handleRequest(&HttpRequest {
        method: "GET".into(),
        path: "/admin/status".into(),
        auth_header: "Bearer secret-token".into(),
        body: "".into(),
    }, &mut sessions);
    assert_eq!(r1.status, 200);
    assert_eq!(r2.status, 200);
    assert_eq!(r3.status, 401);
    assert_eq!(r4.status, 200);
    assert_eq!(r2.body, "user=alice count=2");
    assert_eq!(r4.body, "status=healthy");
    println!("{} | {}\\nBENCH_11_OK", r2.body, r4.body);
}
"""

SOURCES[("11", "go")] = """package main

import (
\t"fmt"
\t"strings"
)

type HttpRequest struct {
\tmethod     string
\tpath       string
\tauthHeader string
\tbody       string
}

type HttpResponse struct {
\tstatus int
\tbody   string
}

func handleRequest(req HttpRequest, sessions map[string]int) HttpResponse {
\tif strings.HasPrefix(req.path, "/admin") && req.authHeader != "Bearer secret-token" {
\t\treturn HttpResponse{401, "Unauthorized"}
\t}
\tif req.method == "POST" && req.path == "/session/incr" {
\t\tuser := req.body
\t\tif len(user) == 0 {
\t\t\tuser = "guest"
\t\t}
\t\tsessions[user]++
\t\treturn HttpResponse{200, fmt.Sprintf("user=%s count=%d", user, sessions[user])}
\t}
\tif req.method == "GET" && req.path == "/admin/status" {
\t\treturn HttpResponse{200, "status=healthy"}
\t}
\treturn HttpResponse{404, "Not Found"}
}

func main() {
\tsessions := make(map[string]int)
\tr1 := handleRequest(HttpRequest{"POST", "/session/incr", "", "alice"}, sessions)
\tr2 := handleRequest(HttpRequest{"POST", "/session/incr", "", "alice"}, sessions)
\tr3 := handleRequest(HttpRequest{"GET", "/admin/status", "bad", ""}, sessions)
\tr4 := handleRequest(HttpRequest{"GET", "/admin/status", "Bearer secret-token", ""}, sessions)
\tif r1.status != 200 || r2.status != 200 || r3.status != 401 || r4.status != 200 {
\t\tpanic("assert status")
\t}
\tif r2.body != "user=alice count=2" || r4.body != "status=healthy" {
\t\tpanic("assert body")
\t}
\tfmt.Printf("%s | %s\\nBENCH_11_OK\\n", r2.body, r4.body)
}
"""

SOURCES[("11", "java")] = """import java.util.*;

public class Main {
    static class HttpRequest {
        String method;
        String path;
        String authHeader;
        String body;
        HttpRequest(String m, String p, String a, String b) {
            method = m;
            path = p;
            authHeader = a;
            body = b;
        }
    }

    static class HttpResponse {
        int status;
        String body;
        HttpResponse(int s, String b) {
            status = s;
            body = b;
        }
    }

    static HttpResponse handleRequest(HttpRequest req, Map<String, Integer> sessions) {
        if (req.path.startsWith("/admin") && !req.authHeader.equals("Bearer secret-token")) {
            return new HttpResponse(401, "Unauthorized");
        }
        if (req.method.equals("POST") && req.path.equals("/session/incr")) {
            String user = req.body.isEmpty() ? "guest" : req.body;
            int nextVal = sessions.getOrDefault(user, 0) + 1;
            sessions.put(user, nextVal);
            return new HttpResponse(200, "user=" + user + " count=" + nextVal);
        }
        if (req.method.equals("GET") && req.path.equals("/admin/status")) {
            return new HttpResponse(200, "status=healthy");
        }
        return new HttpResponse(404, "Not Found");
    }

    public static void main(String[] args) {
        Map<String, Integer> sessions = new HashMap<>();
        HttpResponse r1 = handleRequest(new HttpRequest("POST", "/session/incr", "", "alice"), sessions);
        HttpResponse r2 = handleRequest(new HttpRequest("POST", "/session/incr", "", "alice"), sessions);
        HttpResponse r3 = handleRequest(new HttpRequest("GET", "/admin/status", "bad", ""), sessions);
        HttpResponse r4 = handleRequest(new HttpRequest("GET", "/admin/status", "Bearer secret-token", ""), sessions);
        if (r1.status != 200 || r2.status != 200 || r3.status != 401 || r4.status != 200) {
            throw new AssertionError();
        }
        if (!r2.body.equals("user=alice count=2") || !r4.body.equals("status=healthy")) {
            throw new AssertionError();
        }
        System.out.println(r2.body + " | " + r4.body + "\\nBENCH_11_OK");
    }
}
"""

SOURCES[("11", "js")] = """class HttpRequest {
  constructor(method, path, authHeader, body) {
    this.method = method;
    this.path = path;
    this.authHeader = authHeader;
    this.body = body;
  }
}

class HttpResponse {
  constructor(status, body) {
    this.status = status;
    this.body = body;
  }
}

function handleRequest(req, sessions) {
  if (req.path.startsWith("/admin") && req.authHeader !== "Bearer secret-token") {
    return new HttpResponse(401, "Unauthorized");
  }
  if (req.method === "POST" && req.path === "/session/incr") {
    const user = req.body || "guest";
    const nextVal = (sessions.get(user) || 0) + 1;
    sessions.set(user, nextVal);
    return new HttpResponse(200, `user=${user} count=${nextVal}`);
  }
  if (req.method === "GET" && req.path === "/admin/status") {
    return new HttpResponse(200, "status=healthy");
  }
  return new HttpResponse(404, "Not Found");
}

const sessions = new Map();
const r1 = handleRequest(new HttpRequest("POST", "/session/incr", "", "alice"), sessions);
const r2 = handleRequest(new HttpRequest("POST", "/session/incr", "", "alice"), sessions);
const r3 = handleRequest(new HttpRequest("GET", "/admin/status", "bad", ""), sessions);
const r4 = handleRequest(new HttpRequest("GET", "/admin/status", "Bearer secret-token", ""), sessions);
if (r1.status !== 200 || r2.status !== 200 || r3.status !== 401 || r4.status !== 200) {
  throw new Error("assert");
}
if (r2.body !== "user=alice count=2" || r4.body !== "status=healthy") {
  throw new Error("assert");
}
console.log(`${r2.body} | ${r4.body}\\nBENCH_11_OK`);
"""

SOURCES[("11", "py")] = """from dataclasses import dataclass

@dataclass
class HttpRequest:
    method: str
    path: str
    authHeader: str
    body: str

@dataclass
class HttpResponse:
    status: int
    body: str

def handleRequest(req: HttpRequest, sessions: dict[str, int]) -> HttpResponse:
    if req.path.startswith("/admin") and req.authHeader != "Bearer secret-token":
        return HttpResponse(401, "Unauthorized")
    if req.method == "POST" and req.path == "/session/incr":
        user = req.body if req.body else "guest"
        count = sessions.get(user, 0) + 1
        sessions[user] = count
        return HttpResponse(200, f"user={user} count={count}")
    if req.method == "GET" and req.path == "/admin/status":
        return HttpResponse(200, "status=healthy")
    return HttpResponse(404, "Not Found")

sessions: dict[str, int] = {}
r1 = handleRequest(HttpRequest("POST", "/session/incr", "", "alice"), sessions)
r2 = handleRequest(HttpRequest("POST", "/session/incr", "", "alice"), sessions)
r3 = handleRequest(HttpRequest("GET", "/admin/status", "bad", ""), sessions)
r4 = handleRequest(HttpRequest("GET", "/admin/status", "Bearer secret-token", ""), sessions)
assert r1.status == 200 and r2.status == 200
assert r3.status == 401 and r4.status == 200
assert r2.body == "user=alice count=2"
assert r4.body == "status=healthy"
print(f"{r2.body} | {r4.body}\\nBENCH_11_OK")
"""

SOURCES[("11", "ts")] = """interface HttpRequest {
  method: string;
  path: string;
  authHeader: string;
  body: string;
}

interface HttpResponse {
  status: number;
  body: string;
}

function handleRequest(req: HttpRequest, sessions: Map<string, number>): HttpResponse {
  if (req.path.startsWith("/admin") && req.authHeader !== "Bearer secret-token") {
    return { status: 401, body: "Unauthorized" };
  }
  if (req.method === "POST" && req.path === "/session/incr") {
    const user = req.body || "guest";
    const nextVal = (sessions.get(user) ?? 0) + 1;
    sessions.set(user, nextVal);
    return { status: 200, body: `user=${user} count=${nextVal}` };
  }
  if (req.method === "GET" && req.path === "/admin/status") {
    return { status: 200, body: "status=healthy" };
  }
  return { status: 404, body: "Not Found" };
}

const sessions = new Map<string, number>();
const r1 = handleRequest({ method: "POST", path: "/session/incr", authHeader: "", body: "alice" }, sessions);
const r2 = handleRequest({ method: "POST", path: "/session/incr", authHeader: "", body: "alice" }, sessions);
const r3 = handleRequest({ method: "GET", path: "/admin/status", authHeader: "bad", body: "" }, sessions);
const r4 = handleRequest({ method: "GET", path: "/admin/status", authHeader: "Bearer secret-token", body: "" }, sessions);
if (r1.status !== 200 || r2.status !== 200 || r3.status !== 401 || r4.status !== 200) {
  throw new Error("assert");
}
if (r2.body !== "user=alice count=2" || r4.body !== "status=healthy") {
  throw new Error("assert");
}
console.log(`${r2.body} | ${r4.body}\\nBENCH_11_OK`);
"""

# ==============================================================================
# TEST 12: Complex Super Mario Platformer Game
# ==============================================================================
SOURCES[("12", "cpp")] = """#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cassert>

struct EnemyGoomba {
    double x;
    double y;
    double vx;
    bool alive;
};

struct MarioWorld {
    double playerX;
    double playerY;
    double playerVx;
    double playerVy;
    bool onGround;
    int powerUpState;
    int coins;
    int score;
    int lives;
    double cameraX;
    double goalX;
    std::string status;
    std::vector<double> coinPositions;
    double mushroomX;
    bool mushroomTaken;
    std::vector<EnemyGoomba> enemies;
};

MarioWorld createMarioLevel() {
    return {
        0.0,
        0.0,
        0.0,
        0.0,
        true,
        0,
        0,
        0,
        3,
        0.0,
        120.0,
        "PLAYING",
        {30.0, 60.0, 90.0},
        40.0,
        false,
        {{50.0, 0.0, -1.0, true}}
    };
}

void stepMarioFrame(MarioWorld& w, double moveDir, bool jumpPressed, double dt) {
    if (w.status != "PLAYING") {
        return;
    }
    w.playerVx = moveDir * 20.0;
    if (jumpPressed && w.onGround) {
        w.playerVy = 18.0;
        w.onGround = false;
    }
    w.playerVy -= 30.0 * dt;
    w.playerX += w.playerVx * dt;
    w.playerY += w.playerVy * dt;
    if (w.playerY <= 0.0) {
        w.playerY = 0.0;
        w.playerVy = 0.0;
        w.onGround = true;
    }
    if (!w.mushroomTaken && std::abs(w.playerX - w.mushroomX) <= 2.0) {
        w.mushroomTaken = true;
        w.powerUpState = 1;
        w.score += 1000;
    }
    std::vector<double> remainingCoins;
    for (double cx : w.coinPositions) {
        if (std::abs(w.playerX - cx) <= 2.0) {
            w.coins += 1;
            w.score += 200;
        } else {
            remainingCoins.push_back(cx);
        }
    }
    w.coinPositions = remainingCoins;
    for (auto& e : w.enemies) {
        if (!e.alive) {
            continue;
        }
        e.x += e.vx * dt;
        if (std::abs(w.playerX - e.x) <= 2.5) {
            if (w.playerY > 0.5 && w.playerVy < 0.0) {
                e.alive = false;
                w.score += 500;
                w.playerVy = 10.0;
            } else if (w.playerY <= 0.5) {
                if (w.powerUpState > 0) {
                    w.powerUpState = 0;
                } else {
                    w.lives -= 1;
                    if (w.lives <= 0) {
                        w.status = "GAME_OVER";
                    }
                }
            }
        }
    }
    w.cameraX = std::max(0.0, w.playerX - 20.0);
    if (w.playerX >= w.goalX) {
        w.status = "LEVEL_CLEAR";
        w.score += 2000;
    }
}

int main() {
    auto world = createMarioLevel();
    for (int frame = 0; frame < 40; ++frame) {
        if (world.status != "PLAYING") {
            break;
        }
        stepMarioFrame(world, 1.0, frame == 8, 0.2);
    }
    assert(world.status == "LEVEL_CLEAR");
    assert(world.score == 4100);
    assert(world.coins == 3);
    assert(!world.enemies[0].alive);
    assert(world.cameraX > 80.0);
    std::cout << "Mario Status=" << world.status << " Score=" << world.score << " Coins=" << world.coins << "\\nBENCH_12_OK\\n";
    return 0;
}
"""

SOURCES[("12", "rs")] = """struct EnemyGoomba {
    x: f64,
    y: f64,
    vx: f64,
    alive: bool,
}

struct MarioWorld {
    player_x: f64,
    player_y: f64,
    player_vx: f64,
    player_vy: f64,
    on_ground: bool,
    power_up_state: i32,
    coins: i32,
    score: i32,
    lives: i32,
    camera_x: f64,
    goal_x: f64,
    status: String,
    coin_positions: Vec<f64>,
    mushroom_x: f64,
    mushroom_taken: bool,
    enemies: Vec<EnemyGoomba>,
}

#[allow(non_snake_case)]
fn createMarioLevel() -> MarioWorld {
    MarioWorld {
        player_x: 0.0,
        player_y: 0.0,
        player_vx: 0.0,
        player_vy: 0.0,
        on_ground: true,
        power_up_state: 0,
        coins: 0,
        score: 0,
        lives: 3,
        camera_x: 0.0,
        goal_x: 120.0,
        status: "PLAYING".to_string(),
        coin_positions: vec![30.0, 60.0, 90.0],
        mushroom_x: 40.0,
        mushroom_taken: false,
        enemies: vec![EnemyGoomba { x: 50.0, y: 0.0, vx: -1.0, alive: true }],
    }
}

#[allow(non_snake_case)]
fn stepMarioFrame(w: &mut MarioWorld, move_dir: f64, jump_pressed: bool, dt: f64) {
    if w.status != "PLAYING" {
        return;
    }
    w.player_vx = move_dir * 20.0;
    if jump_pressed && w.on_ground {
        w.player_vy = 18.0;
        w.on_ground = false;
    }
    w.player_vy -= 30.0 * dt;
    w.player_x += w.player_vx * dt;
    w.player_y += w.player_vy * dt;
    if w.player_y <= 0.0 {
        w.player_y = 0.0;
        w.player_vy = 0.0;
        w.on_ground = true;
    }
    if !w.mushroom_taken && (w.player_x - w.mushroom_x).abs() <= 2.0 {
        w.mushroom_taken = true;
        w.power_up_state = 1;
        w.score += 1000;
    }
    let px = w.player_x;
    let before = w.coin_positions.len();
    w.coin_positions.retain(|&cx| (px - cx).abs() > 2.0);
    let gained = (before - w.coin_positions.len()) as i32;
    w.coins += gained;
    w.score += gained * 200;
    for e in &mut w.enemies {
        if !e.alive {
            continue;
        }
        e.x += e.vx * dt;
        if (w.player_x - e.x).abs() <= 2.5 {
            if w.player_y > 0.5 && w.player_vy < 0.0 {
                e.alive = false;
                w.score += 500;
                w.player_vy = 10.0;
            } else if w.player_y <= 0.5 {
                if w.power_up_state > 0 {
                    w.power_up_state = 0;
                } else {
                    w.lives -= 1;
                    if w.lives <= 0 {
                        w.status = "GAME_OVER".to_string();
                    }
                }
            }
        }
    }
    w.camera_x = (w.player_x - 20.0).max(0.0);
    if w.player_x >= w.goal_x {
        w.status = "LEVEL_CLEAR".to_string();
        w.score += 2000;
    }
}

fn main() {
    let mut world = createMarioLevel();
    for frame in 0..40 {
        if world.status != "PLAYING" {
            break;
        }
        stepMarioFrame(&mut world, 1.0, frame == 8, 0.2);
    }
    assert_eq!(world.status, "LEVEL_CLEAR");
    assert_eq!(world.score, 4100);
    assert_eq!(world.coins, 3);
    assert!(!world.enemies[0].alive);
    assert!(world.camera_x > 80.0);
    println!("Mario Status={} Score={} Coins={}\\nBENCH_12_OK", world.status, world.score, world.coins);
}
"""

SOURCES[("12", "go")] = """package main

import (
\t"fmt"
\t"math"
)

type EnemyGoomba struct {
\tx     float64
\ty     float64
\tvx    float64
\talive bool
}

type MarioWorld struct {
\tplayerX       float64
\tplayerY       float64
\tplayerVx      float64
\tplayerVy      float64
\tonGround      bool
\tpowerUpState  int
\tcoins         int
\tscore         int
\tlives         int
\tcameraX       float64
\tgoalX         float64
\tstatus        string
\tcoinPositions []float64
\tmushroomX     float64
\tmushroomTaken bool
\tenemies       []EnemyGoomba
}

func createMarioLevel() MarioWorld {
\treturn MarioWorld{
\t\tplayerX:       0.0,
\t\tplayerY:       0.0,
\t\tplayerVx:      0.0,
\t\tplayerVy:      0.0,
\t\tonGround:      true,
\t\tpowerUpState:  0,
\t\tcoins:         0,
\t\tscore:         0,
\t\tlives:         3,
\t\tcameraX:       0.0,
\t\tgoalX:         120.0,
\t\tstatus:        "PLAYING",
\t\tcoinPositions: []float64{30.0, 60.0, 90.0},
\t\tmushroomX:     40.0,
\t\tmushroomTaken: false,
\t\tenemies:       []EnemyGoomba{{50.0, 0.0, -1.0, true}},
\t}
}

func stepMarioFrame(w *MarioWorld, moveDir float64, jumpPressed bool, dt float64) {
\tif w.status != "PLAYING" {
\t\treturn
\t}
\tw.playerVx = moveDir * 20.0
\tif jumpPressed && w.onGround {
\t\tw.playerVy = 18.0
\t\tw.onGround = false
\t}
\tw.playerVy -= 30.0 * dt
\tw.playerX += w.playerVx * dt
\tw.playerY += w.playerVy * dt
\tif w.playerY <= 0.0 {
\t\tw.playerY = 0.0
\t\tw.playerVy = 0.0
\t\tw.onGround = true
\t}
\tif !w.mushroomTaken && math.Abs(w.playerX-w.mushroomX) <= 2.0 {
\t\tw.mushroomTaken = true
\t\tw.powerUpState = 1
\t\tw.score += 1000
\t}
\tvar rem []float64
\tfor _, cx := range w.coinPositions {
\t\tif math.Abs(w.playerX-cx) <= 2.0 {
\t\t\tw.coins++
\t\t\tw.score += 200
\t\t} else {
\t\t\trem = append(rem, cx)
\t\t}
\t}
\tw.coinPositions = rem
\tfor i := range w.enemies {
\t\te := &w.enemies[i]
\t\tif !e.alive {
\t\t\tcontinue
\t\t}
\t\te.x += e.vx * dt
\t\tif math.Abs(w.playerX-e.x) <= 2.5 {
\t\t\tif w.playerY > 0.5 && w.playerVy < 0.0 {
\t\t\t\te.alive = false
\t\t\t\tw.score += 500
\t\t\t\tw.playerVy = 10.0
\t\t\t} else if w.playerY <= 0.5 {
\t\t\t\tif w.powerUpState > 0 {
\t\t\t\t\tw.powerUpState = 0
\t\t\t\t} else {
\t\t\t\t\tw.lives--
\t\t\t\t\tif w.lives <= 0 {
\t\t\t\t\t\tw.status = "GAME_OVER"
\t\t\t\t\t}
\t\t\t\t}
\t\t\t}
\t\t}
\t}
\tw.cameraX = math.Max(0.0, w.playerX-20.0)
\tif w.playerX >= w.goalX {
\t\tw.status = "LEVEL_CLEAR"
\t\tw.score += 2000
\t}
}

func main() {
\tw := createMarioLevel()
\tfor f := 0; f < 40; f++ {
\t\tif w.status != "PLAYING" {
\t\t\tbreak
\t\t}
\t\tstepMarioFrame(&w, 1.0, f == 8, 0.2)
\t}
\tif w.status != "LEVEL_CLEAR" || w.score != 4100 || w.coins != 3 || w.enemies[0].alive || w.cameraX <= 80.0 {
\t\tpanic("assert")
\t}
\tfmt.Printf("Mario Status=%s Score=%d Coins=%d\\nBENCH_12_OK\\n", w.status, w.score, w.coins)
}
"""

SOURCES[("12", "java")] = """import java.util.*;

public class Main {
    static class EnemyGoomba {
        double x;
        double y;
        double vx;
        boolean alive;
        EnemyGoomba(double x, double y, double vx, boolean alive) {
            this.x = x;
            this.y = y;
            this.vx = vx;
            this.alive = alive;
        }
    }

    static class MarioWorld {
        double playerX;
        double playerY;
        double playerVx;
        double playerVy;
        boolean onGround;
        int powerUpState;
        int coins;
        int score;
        int lives;
        double cameraX;
        double goalX;
        String status;
        List<Double> coinPositions;
        double mushroomX;
        boolean mushroomTaken;
        List<EnemyGoomba> enemies;
    }

    static MarioWorld createMarioLevel() {
        MarioWorld w = new MarioWorld();
        w.playerX = 0.0;
        w.playerY = 0.0;
        w.playerVx = 0.0;
        w.playerVy = 0.0;
        w.onGround = true;
        w.powerUpState = 0;
        w.coins = 0;
        w.score = 0;
        w.lives = 3;
        w.cameraX = 0.0;
        w.goalX = 120.0;
        w.status = "PLAYING";
        w.coinPositions = new ArrayList<>(Arrays.asList(30.0, 60.0, 90.0));
        w.mushroomX = 40.0;
        w.mushroomTaken = false;
        w.enemies = new ArrayList<>();
        w.enemies.add(new EnemyGoomba(50.0, 0.0, -1.0, true));
        return w;
    }

    static void stepMarioFrame(MarioWorld w, double moveDir, boolean jumpPressed, double dt) {
        if (!w.status.equals("PLAYING")) {
            return;
        }
        w.playerVx = moveDir * 20.0;
        if (jumpPressed && w.onGround) {
            w.playerVy = 18.0;
            w.onGround = false;
        }
        w.playerVy -= 30.0 * dt;
        w.playerX += w.playerVx * dt;
        w.playerY += w.playerVy * dt;
        if (w.playerY <= 0.0) {
            w.playerY = 0.0;
            w.playerVy = 0.0;
            w.onGround = true;
        }
        if (!w.mushroomTaken && Math.abs(w.playerX - w.mushroomX) <= 2.0) {
            w.mushroomTaken = true;
            w.powerUpState = 1;
            w.score += 1000;
        }
        List<Double> remCoins = new ArrayList<>();
        for (double cx : w.coinPositions) {
            if (Math.abs(w.playerX - cx) <= 2.0) {
                w.coins += 1;
                w.score += 200;
            } else {
                remCoins.add(cx);
            }
        }
        w.coinPositions = remCoins;
        for (EnemyGoomba e : w.enemies) {
            if (!e.alive) {
                continue;
            }
            e.x += e.vx * dt;
            if (Math.abs(w.playerX - e.x) <= 2.5) {
                if (w.playerY > 0.5 && w.playerVy < 0.0) {
                    e.alive = false;
                    w.score += 500;
                    w.playerVy = 10.0;
                } else if (w.playerY <= 0.5) {
                    if (w.powerUpState > 0) {
                        w.powerUpState = 0;
                    } else {
                        w.lives -= 1;
                        if (w.lives <= 0) {
                            w.status = "GAME_OVER";
                        }
                    }
                }
            }
        }
        w.cameraX = Math.max(0.0, w.playerX - 20.0);
        if (w.playerX >= w.goalX) {
            w.status = "LEVEL_CLEAR";
            w.score += 2000;
        }
    }

    public static void main(String[] args) {
        MarioWorld world = createMarioLevel();
        for (int frame = 0; frame < 40; frame++) {
            if (!world.status.equals("PLAYING")) {
                break;
            }
            stepMarioFrame(world, 1.0, frame == 8, 0.2);
        }
        if (!world.status.equals("LEVEL_CLEAR") || world.score != 4100 || world.coins != 3 || world.enemies.get(0).alive || world.cameraX <= 80.0) {
            throw new AssertionError();
        }
        System.out.println("Mario Status=" + world.status + " Score=" + world.score + " Coins=" + world.coins + "\\nBENCH_12_OK");
    }
}
"""

SOURCES[("12", "js")] = """class EnemyGoomba {
  constructor(x, y, vx, alive) {
    this.x = x;
    this.y = y;
    this.vx = vx;
    this.alive = alive;
  }
}

class MarioWorld {
  constructor() {
    this.playerX = 0.0;
    this.playerY = 0.0;
    this.playerVx = 0.0;
    this.playerVy = 0.0;
    this.onGround = true;
    this.powerUpState = 0;
    this.coins = 0;
    this.score = 0;
    this.lives = 3;
    this.cameraX = 0.0;
    this.goalX = 120.0;
    this.status = "PLAYING";
    this.coinPositions = [30.0, 60.0, 90.0];
    this.mushroomX = 40.0;
    this.mushroomTaken = false;
    this.enemies = [new EnemyGoomba(50.0, 0.0, -1.0, true)];
  }
}

function createMarioLevel() {
  return new MarioWorld();
}

function stepMarioFrame(w, moveDir, jumpPressed, dt) {
  if (w.status !== "PLAYING") {
    return;
  }
  w.playerVx = moveDir * 20.0;
  if (jumpPressed && w.onGround) {
    w.playerVy = 18.0;
    w.onGround = false;
  }
  w.playerVy -= 30.0 * dt;
  w.playerX += w.playerVx * dt;
  w.playerY += w.playerVy * dt;
  if (w.playerY <= 0.0) {
    w.playerY = 0.0;
    w.playerVy = 0.0;
    w.onGround = true;
  }
  if (!w.mushroomTaken && Math.abs(w.playerX - w.mushroomX) <= 2.0) {
    w.mushroomTaken = true;
    w.powerUpState = 1;
    w.score += 1000;
  }
  w.coinPositions = w.coinPositions.filter((cx) => {
    if (Math.abs(w.playerX - cx) <= 2.0) {
      w.coins += 1;
      w.score += 200;
      return false;
    }
    return true;
  });
  for (const e of w.enemies) {
    if (!e.alive) {
      continue;
    }
    e.x += e.vx * dt;
    if (Math.abs(w.playerX - e.x) <= 2.5) {
      if (w.playerY > 0.5 && w.playerVy < 0.0) {
        e.alive = false;
        w.score += 500;
        w.playerVy = 10.0;
      } else if (w.playerY <= 0.5) {
        if (w.powerUpState > 0) {
          w.powerUpState = 0;
        } else {
          w.lives -= 1;
          if (w.lives <= 0) {
            w.status = "GAME_OVER";
          }
        }
      }
    }
  }
  w.cameraX = Math.max(0.0, w.playerX - 20.0);
  if (w.playerX >= w.goalX) {
    w.status = "LEVEL_CLEAR";
    w.score += 2000;
  }
}

const world = createMarioLevel();
for (let frame = 0; frame < 40; frame++) {
  if (world.status !== "PLAYING") {
    break;
  }
  stepMarioFrame(world, 1.0, frame === 8, 0.2);
}
if (world.status !== "LEVEL_CLEAR" || world.score !== 4100 || world.coins !== 3 || world.enemies[0].alive || world.cameraX <= 80.0) {
  throw new Error("assert");
}
console.log(`Mario Status=${world.status} Score=${world.score} Coins=${world.coins}\\nBENCH_12_OK`);
"""

SOURCES[("12", "py")] = """from dataclasses import dataclass, field

@dataclass
class EnemyGoomba:
    x: float
    y: float
    vx: float
    alive: bool

@dataclass
class MarioWorld:
    playerX: float = 0.0
    playerY: float = 0.0
    playerVx: float = 0.0
    playerVy: float = 0.0
    onGround: bool = True
    powerUpState: int = 0
    coins: int = 0
    score: int = 0
    lives: int = 3
    cameraX: float = 0.0
    goalX: float = 120.0
    status: str = "PLAYING"
    coinPositions: list[float] = field(default_factory=lambda: [30.0, 60.0, 90.0])
    mushroomX: float = 40.0
    mushroomTaken: bool = False
    enemies: list[EnemyGoomba] = field(default_factory=list)

def createMarioLevel() -> MarioWorld:
    return MarioWorld(
        playerX=0.0,
        playerY=0.0,
        playerVx=0.0,
        playerVy=0.0,
        onGround=True,
        powerUpState=0,
        coins=0,
        score=0,
        lives=3,
        cameraX=0.0,
        goalX=120.0,
        status="PLAYING",
        coinPositions=[30.0, 60.0, 90.0],
        mushroomX=40.0,
        mushroomTaken=False,
        enemies=[EnemyGoomba(50.0, 0.0, -1.0, True)],
    )

def stepMarioFrame(w: MarioWorld, moveDir: float, jumpPressed: bool, dt: float):
    if w.status != "PLAYING":
        return
    w.playerVx = moveDir * 20.0
    if jumpPressed and w.onGround:
        w.playerVy = 18.0
        w.onGround = False
    w.playerVy -= 30.0 * dt
    w.playerX += w.playerVx * dt
    w.playerY += w.playerVy * dt
    if w.playerY <= 0.0:
        w.playerY = 0.0
        w.playerVy = 0.0
        w.onGround = True
    if not w.mushroomTaken and abs(w.playerX - w.mushroomX) <= 2.0:
        w.mushroomTaken = True
        w.powerUpState = 1
        w.score += 1000
    remCoins: list[float] = []
    for cx in w.coinPositions:
        if abs(w.playerX - cx) <= 2.0:
            w.coins += 1
            w.score += 200
        else:
            remCoins.append(cx)
    w.coinPositions = remCoins
    for e in w.enemies:
        if not e.alive:
            continue
        e.x += e.vx * dt
        if abs(w.playerX - e.x) <= 2.5:
            if w.playerY > 0.5 and w.playerVy < 0.0:
                e.alive = False
                w.score += 500
                w.playerVy = 10.0
            elif w.playerY <= 0.5:
                if w.powerUpState > 0:
                    w.powerUpState = 0
                else:
                    w.lives -= 1
                    if w.lives <= 0:
                        w.status = "GAME_OVER"
    w.cameraX = max(0.0, w.playerX - 20.0)
    if w.playerX >= w.goalX:
        w.status = "LEVEL_CLEAR"
        w.score += 2000

world = createMarioLevel()
for frame in range(40):
    if world.status != "PLAYING":
        break
    stepMarioFrame(world, 1.0, frame == 8, 0.2)

assert world.status == "LEVEL_CLEAR"
assert world.score == 4100
assert world.coins == 3
assert not world.enemies[0].alive
assert world.cameraX > 80.0
print(f"Mario Status={world.status} Score={world.score} Coins={world.coins}\\nBENCH_12_OK")
"""

SOURCES[("12", "ts")] = """interface EnemyGoomba {
  x: number;
  y: number;
  vx: number;
  alive: boolean;
}

interface MarioWorld {
  playerX: number;
  playerY: number;
  playerVx: number;
  playerVy: number;
  onGround: boolean;
  powerUpState: number;
  coins: number;
  score: number;
  lives: number;
  cameraX: number;
  goalX: number;
  status: string;
  coinPositions: number[];
  mushroomX: number;
  mushroomTaken: boolean;
  enemies: EnemyGoomba[];
}

function createMarioLevel(): MarioWorld {
  return {
    playerX: 0.0,
    playerY: 0.0,
    playerVx: 0.0,
    playerVy: 0.0,
    onGround: true,
    powerUpState: 0,
    coins: 0,
    score: 0,
    lives: 3,
    cameraX: 0.0,
    goalX: 120.0,
    status: "PLAYING",
    coinPositions: [30.0, 60.0, 90.0],
    mushroomX: 40.0,
    mushroomTaken: false,
    enemies: [{ x: 50.0, y: 0.0, vx: -1.0, alive: true }],
  };
}

function stepMarioFrame(w: MarioWorld, moveDir: number, jumpPressed: boolean, dt: number): void {
  if (w.status !== "PLAYING") {
    return;
  }
  w.playerVx = moveDir * 20.0;
  if (jumpPressed && w.onGround) {
    w.playerVy = 18.0;
    w.onGround = false;
  }
  w.playerVy -= 30.0 * dt;
  w.playerX += w.playerVx * dt;
  w.playerY += w.playerVy * dt;
  if (w.playerY <= 0.0) {
    w.playerY = 0.0;
    w.playerVy = 0.0;
    w.onGround = true;
  }
  if (!w.mushroomTaken && Math.abs(w.playerX - w.mushroomX) <= 2.0) {
    w.mushroomTaken = true;
    w.powerUpState = 1;
    w.score += 1000;
  }
  w.coinPositions = w.coinPositions.filter((cx) => {
    if (Math.abs(w.playerX - cx) <= 2.0) {
      w.coins += 1;
      w.score += 200;
      return false;
    }
    return true;
  });
  for (const e of w.enemies) {
    if (!e.alive) {
      continue;
    }
    e.x += e.vx * dt;
    if (Math.abs(w.playerX - e.x) <= 2.5) {
      if (w.playerY > 0.5 && w.playerVy < 0.0) {
        e.alive = false;
        w.score += 500;
        w.playerVy = 10.0;
      } else if (w.playerY <= 0.5) {
        if (w.powerUpState > 0) {
          w.powerUpState = 0;
        } else {
          w.lives -= 1;
          if (w.lives <= 0) {
            w.status = "GAME_OVER";
          }
        }
      }
    }
  }
  w.cameraX = Math.max(0.0, w.playerX - 20.0);
  if (w.playerX >= w.goalX) {
    w.status = "LEVEL_CLEAR";
    w.score += 2000;
  }
}

const world = createMarioLevel();
for (let frame = 0; frame < 40; frame++) {
  if (world.status !== "PLAYING") {
    break;
  }
  stepMarioFrame(world, 1.0, frame === 8, 0.2);
}
if (world.status !== "LEVEL_CLEAR" || world.score !== 4100 || world.coins !== 3 || world.enemies[0].alive || world.cameraX <= 80.0) {
  throw new Error("assert");
}
console.log(`Mario Status=${world.status} Score=${world.score} Coins=${world.coins}\\nBENCH_12_OK`);
"""
