#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <cassert>

class WordBreak {
public:
    static bool wordBreak(const std::string& s, const std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());
        size_t maxLen = 0;
        for (const auto& w : wordDict) {
            maxLen = std::max(maxLen, w.length());
        }

        int n = s.length();
        std::vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i) {
            for (size_t len = 1; len <= maxLen && len <= static_cast<size_t>(i); ++len) {
                int j = i - len;
                if (dp[j]) {
                    std::string sub = s.substr(j, len);
                    if (dict.count(sub)) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};

int main() {
    assert(WordBreak::wordBreak("leetcode", {"leet", "code"}) == true);
    assert(WordBreak::wordBreak("applepenapple", {"apple", "pen"}) == true);
    assert(WordBreak::wordBreak("catsandog", {"cats", "dog", "sand", "and", "cat"}) == false);

    std::cout << "All Word Break tests passed successfully!\n";
    return 0;
}

