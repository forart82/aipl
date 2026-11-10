def precedence(op: str) -> int:
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
print(f"v1={v1} v2={v2}\nBENCH_08_OK")
