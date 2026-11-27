#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cassert>

using namespace std;

class Solution {
public:
    // Variant A: LeetCode 403 - Frog Jump River Crossing
    bool canCross(const vector<int>& stones) {
        unordered_map<int, unordered_set<int>> dp;
        for (int pos : stones) dp[pos] = {};
        dp[0].insert(0);

        int lastStone = stones.back();
        for (int pos : stones) {
            for (int k : dp[pos]) {
                for (int step = k - 1; step <= k + 1; step++) {
                    if (step > 0 && dp.count(pos + step)) {
                        if (pos + step == lastStone) return true;
                        dp[pos + step].insert(step);
                    }
                }
            }
        }
        return !dp[lastStone].empty();
    }

    // Variant B: Frog Jump with up to K Steps and Fatigue Cost
    long long minFatigueKJump(const vector<int>& h, int K, long long perStepExtra = 0) {
        int n = h.size();
        vector<long long> dp(n, LLONG_MAX);
        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= min(i, K); j++) {
                long long jumpCost = abs(static_cast<long long>(h[i]) - h[i - j]) + perStepExtra * j;
                dp[i] = min(dp[i], dp[i - j] + jumpCost);
            }
        }
        return dp[n - 1];
    }
};

int main() {
    Solution sol;
    assert(sol.canCross({0, 1, 3, 5, 6, 8, 12, 17}) == true);
    assert(sol.canCross({0, 1, 2, 3, 4, 8, 9, 11}) == false);
    assert(sol.minFatigueKJump({10, 30, 40, 50, 20}, 3) == 30);
    cout << "31_frog_jump_with_fatigue passed all tests!\n";
    return 0;
}
