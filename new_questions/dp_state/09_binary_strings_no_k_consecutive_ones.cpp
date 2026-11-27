#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
    static constexpr long long MOD = 1e9 + 7;

public:
    // Approach 1: O(N * K) State DP tracking trailing consecutive ones
    int countBinaryStringsDP(int n, int k) {
        vector<long long> dp(k, 0);
        dp[0] = 1; // empty string: 0 trailing 1s

        for (int i = 0; i < n; i++) {
            vector<long long> nextDp(k, 0);
            for (int c = 0; c < k; c++) {
                // Place '0': resets trailing ones to 0
                nextDp[0] = (nextDp[0] + dp[c]) % MOD;
                // Place '1': allowed if c + 1 < k
                if (c + 1 < k) {
                    nextDp[c + 1] = (nextDp[c + 1] + dp[c]) % MOD;
                }
            }
            dp.swap(nextDp);
        }

        long long ans = 0;
        for (long long v : dp) ans = (ans + v) % MOD;
        return ans;
    }

    // Approach 2: Optimal O(N) using Sliding Window Prefix Sum
    int countBinaryStringsOptimal(int n, int k) {
        if (k <= 1) return n == 0 ? 1 : 0;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        long long windowSum = 1; // tracks sum of valid dp states
        for (int i = 1; i <= n; i++) {
            dp[i] = windowSum;
            if (i < k) {
                windowSum = (windowSum + dp[i]) % MOD;
            } else {
                // Remove dp[i - k] from the window, add dp[i]
                // Wait: for valid strings of length i ending in <= k-1 ones:
                // dp[i] = sum(dp[i-1] .. dp[i-k]) when i >= k?
                // Let's check n=3, k=2: dp[0]=1, dp[1]=2, dp[2]=3, dp[3]=5.
                // Notice dp[2] = dp[1] + dp[0] = 3!
                // Wait: for i=1: dp[1]=2 (not 1!). Why? Because length 1 has "0", "1" (2 ways).
                // Let's adjust base case for standard recurrence: dp[i] = 2^i for i < k.
            }
        }

        // Exact O(N) recurrence:
        // dp[0] = 1, for 1 <= i < k: dp[i] = (dp[i-1] * 2) % MOD.
        // For i == k: dp[k] = (dp[k-1] * 2 - 1 + MOD) % MOD.
        // For i > k: dp[i] = (2 * dp[i-1] - dp[i-k-1] + MOD) % MOD.
        vector<long long> f(n + 1, 0);
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (i < k) {
                f[i] = (f[i - 1] * 2) % MOD;
            } else if (i == k) {
                f[i] = (f[i - 1] * 2 - 1 + MOD) % MOD;
            } else {
                f[i] = (2 * f[i - 1] % MOD - f[i - k - 1] + MOD) % MOD;
            }
        }
        return f[n];
    }
};

int main() {
    Solution sol;
    assert(sol.countBinaryStringsDP(3, 2) == 5);
    assert(sol.countBinaryStringsOptimal(3, 2) == 5);
    assert(sol.countBinaryStringsDP(3, 3) == 7);
    assert(sol.countBinaryStringsOptimal(3, 3) == 7);
    assert(sol.countBinaryStringsDP(5, 3) == sol.countBinaryStringsOptimal(5, 3));
    cout << "09_binary_strings_no_k_consecutive_ones passed all tests!\n";
    return 0;
}
