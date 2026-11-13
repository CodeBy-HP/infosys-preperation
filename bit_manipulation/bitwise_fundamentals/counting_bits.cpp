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

    // Approach 3: O(log n)
    // Helper to find the highest power of 2 less than or equal to n
    int getHighestPowerOf2(int n) {
        int x = 0;
        while ((1 << x) <= n) {
            x++;
        }
        return x - 1;
    }

    int countSetBits(int n) {
        if (n <= 0) return 0;

        int x = getHighestPowerOf2(n);

        // 1. Bits up to 2^x - 1
        int bitsUpTo2x = x * (1 << (x - 1)); 

        // 2. MSBs from 2^x to n
        int msbFrom2xToN = n - (1 << x) + 1; 

        // 3. Remaining bits (recursive call)
        int rest = n - (1 << x); 

        return bitsUpTo2x + msbFrom2xToN + countSetBits(rest);
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



// 00001
// 00010
// 00011
// 00100
// 00101
// 00110
// 00111
// 01000