import java.util.*;

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
        for (String token : expr.trim().split("\\s+")) {
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
        System.out.println("v1=" + v1 + " v2=" + v2 + "\nBENCH_08_OK");
    }
}
