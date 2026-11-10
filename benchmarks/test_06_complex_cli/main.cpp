#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <cassert>

struct CliResult {
    int exitCode;
    std::string output;
};

CliResult executeCliCommand(const std::vector<std::string>& args) {
    if (args.empty() || args[0] == "--help" || args[0] == "help") {
        return {0, "Usage: tool <stats|transform|pipeline> [options]"};
    }
    if (args[0] == "stats") {
        std::vector<int> nums;
        for (size_t i = 1; i < args.size(); ++i) {
            if (args[i].rfind("--values=", 0) == 0) {
                std::stringstream ss(args[i].substr(9));
                std::string item;
                while (std::getline(ss, item, ',')) {
                    if (!item.empty()) {
                        nums.push_back(std::stoi(item));
                    }
                }
            }
        }
        if (nums.empty()) {
            return {2, "Error: --values required"};
        }
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int mn = *std::min_element(nums.begin(), nums.end());
        int mx = *std::max_element(nums.begin(), nums.end());
        return {0, "count=" + std::to_string(nums.size()) + " sum=" + std::to_string(sum) + " min=" + std::to_string(mn) + " max=" + std::to_string(mx)};
    }
    if (args[0] == "pipeline") {
        std::string text = "";
        bool upper = false;
        bool rev = false;
        for (size_t i = 1; i < args.size(); ++i) {
            if (args[i].rfind("--input=", 0) == 0) {
                text = args[i].substr(8);
            } else if (args[i] == "--upper") {
                upper = true;
            } else if (args[i] == "--reverse-words") {
                rev = true;
            }
        }
        if (text.empty()) {
            return {1, "Error: empty input"};
        }
        if (upper) {
            for (char& c : text) {
                c = std::toupper(c);
            }
        }
        if (rev) {
            std::stringstream ss(text);
            std::string word;
            std::vector<std::string> words;
            while (ss >> word) {
                words.push_back(word);
            }
            std::reverse(words.begin(), words.end());
            text = "";
            for (size_t i = 0; i < words.size(); ++i) {
                if (i > 0) {
                    text += " ";
                }
                text += words[i];
            }
        }
        return {0, text};
    }
    return {127, "Unknown subcommand: " + args[0]};
}

int main() {
    auto r1 = executeCliCommand({"--help"});
    auto r2 = executeCliCommand({"stats", "--values=10,25,5,40"});
    auto r3 = executeCliCommand({"pipeline", "--input=aipl fast native cli", "--upper", "--reverse-words"});
    auto r4 = executeCliCommand({"unknown_cmd"});
    assert(r1.exitCode == 0);
    assert(r2.exitCode == 0 && r2.output == "count=4 sum=80 min=5 max=40");
    assert(r3.exitCode == 0 && r3.output == "CLI NATIVE FAST AIPL");
    assert(r4.exitCode == 127);
    std::cout << r2.output << " | " << r3.output << "\nBENCH_06_OK\n";
    return 0;
}
