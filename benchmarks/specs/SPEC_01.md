# SPEC_01: Hello World & Dynamic CLI Greeting (`test_01_hello_cli`)

- **Tier**: Very Easy
- **Category**: CLI Argument Parsing & String Interpolation

## 1. Functional Requirements
1. Implement `formatGreeting(name, role, count)` returning `"Hello, {name} [{role}]! Welcome #{count} to AIPL."`.
2. Implement or invoke `parseCliArgs(args)` to parse `--key=value` CLI flags into a key-value map/dictionary.
3. Parse `["--name=Developer", "--role=Engineer"]`, extract `"name"` (default `"Developer"`) and `"role"` (default `"Engineer"`).
4. Format two greetings:
   - `msg1 = formatGreeting(user, role, 1)`
   - `msg2 = formatGreeting("Ada", "Architect", 42)`
5. Assert both strings match expected output and print both lines followed by `BENCH_01_OK`.

## 2. Structural & Algorithmic Parity (Rule B)
- **Normalized Identifiers**: `formatGreeting`, `parseCliArgs`, `parsed`, `msg1`, `msg2`.
- **Formatting**: 1 statement per line; no single-letter obfuscation.
- **Complexity**: $O(N)$ over CLI arguments.

## 3. Expected Deterministic Stdout
```text
Hello, Developer [Engineer]! Welcome #1 to AIPL.
Hello, Ada [Architect]! Welcome #42 to AIPL.
BENCH_01_OK
```
