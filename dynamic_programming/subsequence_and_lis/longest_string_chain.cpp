#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cassert>

class LongestStringChain {
public:
    static int longestStrChain(std::vector<std::string>& words) {
        // Sort words by length in ascending order
        std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
            return a.length() < b.length();
        });

        std::unordered_map<std::string, int> dp;
        int maxChain = 1;

        for (const std::string& word : words) {
            dp[word] = 1;
            for (size_t i = 0; i < word.length(); ++i) {
                // Remove character at index i
                std::string pred = word.substr(0, i) + word.substr(i + 1);
                auto it = dp.find(pred);
                if (it != dp.end()) {
                    dp[word] = std::max(dp[word], it->second + 1);
                }
            }
            maxChain = std::max(maxChain, dp[word]);
        }
        return maxChain;
    }
};

int main() {
    std::vector<std::string> w1 = {"a", "b", "ba", "bca", "bda", "bdca"};
    assert(LongestStringChain::longestStrChain(w1) == 4);

    std::vector<std::vector<std::string>> tests = {
        {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"},
        {"abcd", "dbqca"}
    };
    assert(LongestStringChain::longestStrChain(tests[0]) == 5);
    assert(LongestStringChain::longestStrChain(tests[1]) == 1);

    std::cout << "All Longest String Chain tests passed successfully!\n";
    return 0;
}

