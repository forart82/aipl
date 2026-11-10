def prec(op: str) -> int:
    return 3 if op in ("*", "/") else 2 if op in ("+", "-") else 1 if op in (">", "==") else 0

def compile_rpn(expr: str) -> list[str]:
    out, ops = [], []
    for t in expr.split():
        if t == "(": ops.append(t)
        elif t == ")":
            while ops and ops[-1] != "(": out.append(ops.pop())
            ops.pop()
        elif prec(t) > 0:
            while ops and prec(ops[-1]) >= prec(t): out.append(ops.pop())
            ops.append(t)
        else: out.append(t)
    return out + ops[::-1]

def eval_rpn(toks: list[str], env: dict[str, int]) -> int:
    st: list[int] = []
    for t in toks:
        if prec(t) > 0:
            b, a = st.pop(), st.pop()
            st.append(a + b if t == "+" else a - b if t == "-" else a * b if t == "*" else int(a > b))
        else:
            st.append(env[t] if t in env else int(t))
    return st[-1]

env = {"x": 12, "y": 5}
v1 = eval_rpn(compile_rpn("( x + y * 4 ) - 2"), env)
v2 = eval_rpn(compile_rpn("x * 2 > y + 10"), env)
assert v1 == 30 and v2 == 1
print(f"v1={v1} v2={v2}\nBENCH_08_OK")
