function prec(op) {
  if (op === "*" || op === "/") return 3;
  if (op === "+" || op === "-") return 2;
  if (op === ">" || op === "==") return 1;
  return 0;
}
function compileRpn(expr) {
  const out = [], ops = [];
  for (const t of expr.trim().split(/\s+/)) {
    if (t === "(") ops.push(t);
    else if (t === ")") {
      while (ops.length && ops[ops.length - 1] !== "(") out.push(ops.pop());
      ops.pop();
    } else if (prec(t) > 0) {
      while (ops.length && prec(ops[ops.length - 1]) >= prec(t)) out.push(ops.pop());
      ops.push(t);
    } else out.push(t);
  }
  while (ops.length) out.push(ops.pop());
  return out;
}
function evalRpn(toks, env) {
  const st = [];
  for (const t of toks) {
    if (prec(t) > 0) {
      const b = st.pop(), a = st.pop();
      if (t === "+") st.push(a + b);
      else if (t === "-") st.push(a - b);
      else if (t === "*") st.push(a * b);
      else if (t === ">") st.push(a > b ? 1 : 0);
    } else if (t in env) st.push(env[t]);
    else st.push(parseInt(t, 10));
  }
  return st[st.length - 1];
}
const env = { x: 12, y: 5 };
const v1 = evalRpn(compileRpn("( x + y * 4 ) - 2"), env);
const v2 = evalRpn(compileRpn("x * 2 > y + 10"), env);
if (v1 !== 30 || v2 !== 1) throw new Error("assert");
console.log(`v1=${v1} v2=${v2}\nBENCH_08_OK`);
