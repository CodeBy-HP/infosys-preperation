#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

class ShortestCommonSupersequence {
public:
    static std::string shortestCommonSupersequence(const std::string& str1, const std::string& str2) {
        int n = str1.length();
        int m = str2.length();

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Backtrack to reconstruct SCS
        int i = n, j = m;
        std::string scs = "";

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                scs.push_back(str1[i - 1]);
                --i;
                --j;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                scs.push_back(str1[i - 1]);
                --i;
            } else {
                scs.push_back(str2[j - 1]);
                --j;
            }
        }

        while (i > 0) {
            scs.push_back(str1[i - 1]);
            --i;
        }
        while (j > 0) {
            scs.push_back(str2[j - 1]);
            --j;
        }

        std::reverse(scs.begin(), scs.end());
        return scs;
    }

    // Helper to verify subsequence property
    static bool isSubsequence(const std::string& sub, const std::string& superStr) {
        size_t pSub = 0, pSuper = 0;
        while (pSub < sub.length() && pSuper < superStr.length()) {
            if (sub[pSub] == superStr[pSuper]) ++pSub;
            ++pSuper;
        }
        return pSub == sub.length();
    }
};

int main() {
    std::string s1 = "abac", s2 = "cab";
    std::string res1 = ShortestCommonSupersequence::shortestCommonSupersequence(s1, s2);
    assert(ShortestCommonSupersequence::isSubsequence(s1, res1));
    assert(ShortestCommonSupersequence::isSubsequence(s2, res1));
    assert(res1.length() == 5); // e.g. "cabac"

    std::string s3 = "aaaaaaaa", s4 = "aaaaaaaa";
    std::string res2 = ShortestCommonSupersequence::shortestCommonSupersequence(s3, s4);
    assert(res2 == "aaaaaaaa");

    std::cout << "All Shortest Common Supersequence tests passed successfully!\n";
    return 0;
}

