#include <iostream>
#include <vector>
#include <string>
#include <cassert>

class CountPalindromicSubsequences {
public:
    static const int MOD = 1e9 + 7;

    static long long countPalindromes(const std::string& s) {
        int n = s.length();
        if (n == 0) return 0;

        std::vector<std::vector<long long>> dp(n, std::vector<long long>(n, 0));

        // Base case: length 1 substrings
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        // Interval DP by increasing substring length
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1) % MOD;
                } else {
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    assert(CountPalindromicSubsequences::countPalindromes("abcd") == 4);
    assert(CountPalindromicSubsequences::countPalindromes("aab") == 4); // "a", "a", "b", "aa"
    assert(CountPalindromicSubsequences::countPalindromes("aaaa") == 15); // 2^4 - 1 = 15

    std::cout << "All Count Palindromic Subsequences tests passed successfully!\n";
    return 0;
}

