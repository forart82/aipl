#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cassert>

int precedence(const std::string& op) {
    if (op == "*" || op == "/") return 3;
    if (op == "+" || op == "-") return 2;
    if (op == ">" || op == "==") return 1;
    return 0;
}

std::vector<std::string> compileInfixToRpn(const std::string& expr) {
    std::stringstream ss(expr);
    std::string tok;
    std::vector<std::string> out, ops;
    while (ss >> tok) {
        if (tok == "(") ops.push_back(tok);
        else if (tok == ")") {
            while (!ops.empty() && ops.back() != "(") { out.push_back(ops.back()); ops.pop_back(); }
            if (!ops.empty()) ops.pop_back();
        } else if (precedence(tok) > 0) {
            while (!ops.empty() && precedence(ops.back()) >= precedence(tok)) { out.push_back(ops.back()); ops.pop_back(); }
            ops.push_back(tok);
        } else out.push_back(tok);
    }
    while (!ops.empty()) { out.push_back(ops.back()); ops.pop_back(); }
    return out;
}

int evalRpnVm(const std::vector<std::string>& tokens, const std::map<std::string, int>& env) {
    std::vector<int> st;
    for (const auto& t : tokens) {
        if (precedence(t) > 0) {
            int b = st.back(); st.pop_back();
            int a = st.back(); st.pop_back();
            if (t == "+") st.push_back(a + b);
            else if (t == "-") st.push_back(a - b);
            else if (t == "*") st.push_back(a * b);
            else if (t == "/") st.push_back(b ? a / b : 0);
            else if (t == ">") st.push_back(a > b ? 1 : 0);
            else if (t == "==") st.push_back(a == b ? 1 : 0);
        } else if (env.count(t)) st.push_back(env.at(t));
        else st.push_back(std::stoi(t));
    }
    return st.empty() ? 0 : st.back();
}

int main() {
    std::map<std::string, int> env = {{"x", 12}, {"y", 5}};
    int v1 = evalRpnVm(compileInfixToRpn("( x + y * 4 ) - 2"), env);
    int v2 = evalRpnVm(compileInfixToRpn("x * 2 > y + 10"), env);
    assert(v1 == 30 && v2 == 1);
    std::cout << "v1=" << v1 << " v2=" << v2 << "\nBENCH_08_OK\n";
    return 0;
}
