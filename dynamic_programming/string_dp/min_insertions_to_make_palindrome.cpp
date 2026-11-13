#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

class MinInsertionsPalindrome {
public:
    static int minInsertions(const std::string& s) {
        int n = s.length();
        std::string revS = s;
        std::reverse(revS.begin(), revS.end());

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

        int lps = prev[n];
        return n - lps;
    }
};

int main() {
    std::string s1 = "zzazz";
    assert(MinInsertionsPalindrome::minInsertions(s1) == 0);

    std::string s2 = "mbadm";
    assert(MinInsertionsPalindrome::minInsertions(s2) == 2);

    std::string s3 = "leetcode";
    assert(MinInsertionsPalindrome::minInsertions(s3) == 5);

    std::cout << "All Minimum Insertions to Make String Palindrome tests passed successfully!\n";
    return 0;
}

