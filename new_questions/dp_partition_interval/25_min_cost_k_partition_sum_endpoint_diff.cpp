#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cassert>

using namespace std;

class Solution {
    static constexpr long long INF = 1e18;

public:
    long long minCostSumEndpointDiff(const vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int p = 1; p <= k; p++) {
            vector<long long> nextDp(n + 1, INF);
            for (int i = p; i <= n; i++) {
                for (int j = p - 1; j < i; j++) {
                    if (dp[j] >= INF) continue;
                    long long segSum = pref[i] - pref[j];
                    long long endDiff = abs(static_cast<long long>(nums[j]) - nums[i - 1]);
                    nextDp[i] = min(nextDp[i], dp[j] + segSum * endDiff);
                }
            }
            dp.swap(nextDp);
        }

        return dp[n];
    }
};

int main() {
    Solution sol;
    assert(sol.minCostSumEndpointDiff({2, 6, 3, 5}, 2) == 11);
    assert(sol.minCostSumEndpointDiff({1, 2, 3}, 3) == 0);
    cout << "25_min_cost_k_partition_sum_endpoint_diff passed all tests!\n";
    return 0;
}
