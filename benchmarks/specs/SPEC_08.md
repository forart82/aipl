# SPEC_08: Arithmetic/Logical Expression Interpreter & Mini-VM (`test_08_expr_vm`)

- **Tier**: Complex
- **Category**: Shunting-Yard Compiler & RPN Stack Virtual Machine

## 1. Functional Requirements
1. Implement operator precedence `precedence(op)`:
   - `"*"`, `"/"` -> `3`
   - `"+"`, `"-"` -> `2`
   - `">"`, `"=="` -> `1`
   - Otherwise -> `0`
2. Implement `compileInfixToRpn(expr)` using Dijkstra Shunting-Yard algorithm over whitespace-delimited tokens (supporting parentheses `"("`, `")"` and binary operators).
3. Implement `evalRpnVm(tokens, env)` using an integer evaluation stack supporting all 6 operators (`+`, `-`, `*`, `/` with divide-by-zero guard, `>`, `==`), environment variable lookup (`env`), and integer literals.
4. With `env = {"x": 12, "y": 5}`, evaluate:
   - `v1 = evalRpnVm(compileInfixToRpn("( x + y * 4 ) - 2"), env)` -> assert `v1 == 30`
   - `v2 = evalRpnVm(compileInfixToRpn("x * 2 > y + 10"), env)` -> assert `v2 == 1`
5. Print `"v1=30 v2=1"` followed by `BENCH_08_OK`.

## 2. Structural & Algorithmic Parity (Rule B)
- **Normalized Identifiers**: `precedence`, `compileInfixToRpn`, `evalRpnVm`, `env`, `v1`, `v2`.
- **Full Operator Support**: All 8 languages must implement all 6 operators (`+`, `-`, `*`, `/`, `>`, `==`).

## 3. Expected Deterministic Stdout
```text
v1=30 v2=1
BENCH_08_OK
```
