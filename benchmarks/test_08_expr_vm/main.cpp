#include <iostream>
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
    std::cout << "v1=" << v1 << " v2=" << v2 << "\nBENCH_08_OK\n";
    return 0;
}
