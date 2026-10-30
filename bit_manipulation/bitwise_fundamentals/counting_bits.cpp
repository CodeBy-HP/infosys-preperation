#include <iostream>
#include <vector>

class Solution {
public:
    // Approach 1: dp[i] = dp[i >> 1] + (i & 1)
    std::vector<int> countBits(int n) {
        std::vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }

    // Approach 2: dp[i] = dp[i & (i - 1)] + 1
    std::vector<int> countBitsKernighan(int n) {
        std::vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i & (i - 1)] + 1;
        }
        return dp;
    }
};

int main() {
    Solution sol;
    int n = 5;
    std::vector<int> res1 = sol.countBits(n);
    std::vector<int> res2 = sol.countBitsKernighan(n);

    std::cout << "countBits(5):          [ ";
    for (int x : res1) std::cout << x << " ";
    std::cout << "]\n(Expected: [ 0 1 1 2 1 2 ])\n";

    std::cout << "countBitsKernighan(5): [ ";
    for (int x : res2) std::cout << x << " ";
    std::cout << "]\n";

    return 0;
}
