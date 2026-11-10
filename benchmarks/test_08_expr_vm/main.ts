function precedence(op: string): number {
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
  for (const token of expr.trim().split(/\s+/)) {
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
console.log(`v1=${v1} v2=${v2}\nBENCH_08_OK`);
