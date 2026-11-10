import java.util.*;

public class Main {
    static int prec(String op) {
        if (op.equals("*") || op.equals("/")) return 3;
        if (op.equals("+") || op.equals("-")) return 2;
        if (op.equals(">") || op.equals("==")) return 1;
        return 0;
    }
    static List<String> compileRpn(String expr) {
        List<String> out = new ArrayList<>();
        Deque<String> ops = new ArrayDeque<>();
        for (String t : expr.split("\\s+")) {
            if (t.equals("(")) ops.push(t);
            else if (t.equals(")")) {
                while (!ops.isEmpty() && !ops.peek().equals("(")) out.add(ops.pop());
                if (!ops.isEmpty()) ops.pop();
            } else if (prec(t) > 0) {
                while (!ops.isEmpty() && prec(ops.peek()) >= prec(t)) out.add(ops.pop());
                ops.push(t);
            } else out.add(t);
        }
        while (!ops.isEmpty()) out.add(ops.pop());
        return out;
    }
    static int evalRpn(List<String> toks, Map<String, Integer> env) {
        Deque<Integer> st = new ArrayDeque<>();
        for (String t : toks) {
            if (prec(t) > 0) {
                int b = st.pop(), a = st.pop();
                switch (t) {
                    case "+": st.push(a + b); break;
                    case "-": st.push(a - b); break;
                    case "*": st.push(a * b); break;
                    case "/": st.push(b != 0 ? a / b : 0); break;
                    case ">": st.push(a > b ? 1 : 0); break;
                    case "==": st.push(a == b ? 1 : 0); break;
                }
            } else if (env.containsKey(t)) st.push(env.get(t));
            else st.push(Integer.parseInt(t));
        }
        return st.peek();
    }
    public static void main(String[] args) {
        Map<String, Integer> env = Map.of("x", 12, "y", 5);
        int v1 = evalRpn(compileRpn("( x + y * 4 ) - 2"), env);
        int v2 = evalRpn(compileRpn("x * 2 > y + 10"), env);
        if (v1 != 30 || v2 != 1) throw new AssertionError();
        System.out.println("v1=" + v1 + " v2=" + v2 + "\nBENCH_08_OK");
    }
}
