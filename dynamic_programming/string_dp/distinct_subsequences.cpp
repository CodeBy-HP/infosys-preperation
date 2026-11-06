#include <iostream>
#include <vector>
#include <string>
#include <cassert>

class DistinctSubsequences {
public:
    // Space-Optimized 1D Vector - O(N * M) Time, O(M) Space
    static int numDistinct(const std::string& s, const std::string& t) {
        int n = s.length();
        int m = t.length();

        // Using unsigned long long to avoid intermediate overflow
        std::vector<unsigned long long> dp(m + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = m; j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[m];
    }
};

int main() {
    std::string s1 = "rabbbit", t1 = "rabbit";
    assert(DistinctSubsequences::numDistinct(s1, t1) == 3);

    std::string s2 = "babgbag", t2 = "bag";
    assert(DistinctSubsequences::numDistinct(s2, t2) == 5);

    std::cout << "All Distinct Subsequences tests passed successfully!\n";
    return 0;
}

