#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
    static constexpr long long MOD = 1e9 + 7;

public:
    // Count subsequences without 2 consecutive skips whose sum has targetParity (0=even, 1=odd)
    int countQuantumParityNoConsecSkip(const vector<int>& nums, int targetParity) {
        int n = nums.size();
        if (n == 0) return targetParity == 0 ? 1 : 0;

        // dp[taken (0 or 1)][parity (0 or 1)]
        long long dp[2][2] = {};
        int p0 = nums[0] & 1;
        dp[0][0] = 1;    // skipped index 0 (sum = 0, even)
        dp[1][p0] = 1;   // picked index 0 (sum parity = p0)

        for (int i = 1; i < n; i++) {
            long long nextDp[2][2] = {};
            int p = nums[i] & 1;

            for (int par = 0; par < 2; par++) {
                // Skip nums[i]: allowed only if i-1 was taken
                nextDp[0][par] = (nextDp[0][par] + dp[1][par]) % MOD;

                // Pick nums[i]: allowed regardless of whether i-1 was taken or skipped
                long long ways = (dp[0][par] + dp[1][par]) % MOD;
                nextDp[1][par ^ p] = (nextDp[1][par ^ p] + ways) % MOD;
            }

            for (int t = 0; t < 2; t++)
                for (int par = 0; par < 2; par++)
                    dp[t][par] = nextDp[t][par];
        }

        return (dp[0][targetParity] + dp[1][targetParity]) % MOD;
    }

    // Standard Parity Subset Count (no consecutive-skip restriction)
    long long countAllSubsetsWithParity(const vector<int>& nums, int targetParity) {
        long long even = 1, odd = 0; // empty subset has sum 0 (even)
        for (int x : nums) {
            if (x & 1) {
                long long nextWays = (even + odd) % MOD;
                even = nextWays;
                odd = nextWays;
            } else {
                even = (even * 2) % MOD;
                odd = (odd * 2) % MOD;
            }
        }
        return targetParity == 0 ? even : odd;
    }
};

int main() {
    Solution sol;
    // Valid no-consec-skip subsets of [1, 2, 3]: [1,2,3](6), [1,2](3), [1,3](4), [2,3](5), [2](2)
    assert(sol.countQuantumParityNoConsecSkip({1, 2, 3}, 1) == 2);
    assert(sol.countQuantumParityNoConsecSkip({1, 2, 3}, 0) == 3);
    assert(sol.countAllSubsetsWithParity({1, 2, 3}, 1) == 4);
    assert(sol.countAllSubsetsWithParity({1, 2, 3}, 0) == 4);
    cout << "08_quantum_core_parity passed all tests!\n";
    return 0;
}
