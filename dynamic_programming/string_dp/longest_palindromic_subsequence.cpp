#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

class LongestPalindromicSubsequence {
public:
    static int longestPalindromeSubseq(const std::string& s) {
        std::string revS = s;
        std::reverse(revS.begin(), revS.end());
        int n = s.length();

        std::vector<int> prev(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            std::vector<int> curr(n + 1, 0);
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == revS[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = std::max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};

int main() {
    std::string s1 = "bbbab";
    assert(LongestPalindromicSubsequence::longestPalindromeSubseq(s1) == 4); // "bbbb"

    std::string s2 = "cbbd";
    assert(LongestPalindromicSubsequence::longestPalindromeSubseq(s2) == 2); // "bb"

    std::string s3 = "a";
    assert(LongestPalindromicSubsequence::longestPalindromeSubseq(s3) == 1);

    std::cout << "All Longest Palindromic Subsequence tests passed successfully!\n";
    return 0;
}

