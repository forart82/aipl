#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cassert>

struct CliResult { int exitCode; std::string output; };

CliResult executeCliCommand(const std::vector<std::string>& args) {
    if (args.empty() || args[0] == "--help" || args[0] == "help")
        return {0, "Usage: tool <stats|transform|pipeline> [options]"};
    const std::string& sub = args[0];
    if (sub == "stats") {
        std::vector<int> nums;
        for (size_t i = 1; i < args.size(); ++i) {
            if (args[i].rfind("--values=", 0) == 0) {
                std::stringstream ss(args[i].substr(9));
                std::string tok;
                while (std::getline(ss, tok, ',')) if (!tok.empty()) nums.push_back(std::stoi(tok));
            }
        }
        if (nums.empty()) return {2, "Error: --values required"};
        int sum = 0, minV = nums[0], maxV = nums[0];
        for (int n : nums) { sum += n; minV = std::min(minV, n); maxV = std::max(maxV, n); }
        return {0, "count=" + std::to_string(nums.size()) + " sum=" + std::to_string(sum) + " min=" + std::to_string(minV) + " max=" + std::to_string(maxV)};
    }
    if (sub == "pipeline") {
        std::string text; bool upper = false, rev = false;
        for (size_t i = 1; i < args.size(); ++i) {
            if (args[i].rfind("--input=", 0) == 0) text = args[i].substr(8);
            else if (args[i] == "--upper") upper = true;
            else if (args[i] == "--reverse-words") rev = true;
        }
        if (text.empty()) return {1, "Error: empty input"};
        if (upper) for (char& c : text) c = std::toupper(c);
        if (rev) {
            std::stringstream ss(text); std::string w; std::vector<std::string> ws;
            while (ss >> w) ws.push_back(w);
            std::reverse(ws.begin(), ws.end());
            text.clear();
            for (size_t i = 0; i < ws.size(); ++i) text += (i ? " " : "") + ws[i];
        }
        return {0, text};
    }
    return {127, "Unknown subcommand: " + sub};
}

int main() {
    auto r1 = executeCliCommand({"--help"});
    auto r2 = executeCliCommand({"stats", "--values=10,25,5,40"});
    auto r3 = executeCliCommand({"pipeline", "--input=aipl fast native cli", "--upper", "--reverse-words"});
    auto r4 = executeCliCommand({"unknown"});
    assert(r1.exitCode == 0 && r2.output == "count=4 sum=80 min=5 max=40" && r3.output == "CLI NATIVE FAST AIPL" && r4.exitCode == 127);
    std::cout << r2.output << " | " << r3.output << "\nBENCH_06_OK\n";
    return 0;
}
