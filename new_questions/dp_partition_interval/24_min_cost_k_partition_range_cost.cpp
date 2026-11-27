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
    long long minCostKPartitionRange(const vector<int>& nums, int k, bool includeEndpointDiff = true) {
        int n = nums.size();
        // Precompute cost[l][r]
        vector<vector<long long>> segCost(n, vector<long long>(n, 0));
        for (int l = 0; l < n; l++) {
            int mn = nums[l], mx = nums[l];
            for (int r = l; r < n; r++) {
                mn = min(mn, nums[r]);
                mx = max(mx, nums[r]);
                long long rangePart = static_cast<long long>(mx) - mn;
                long long endPart = includeEndpointDiff ? abs(static_cast<long long>(nums[l]) - nums[r]) : 0;
                segCost[l][r] = rangePart + endPart;
            }
        }

        // dp[i] for current number of partitions p
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int p = 1; p <= k; p++) {
            vector<long long> nextDp(n + 1, INF);
            for (int i = p; i <= n; i++) {
                for (int j = p - 1; j < i; j++) {
                    if (dp[j] < INF) {
                        nextDp[i] = min(nextDp[i], dp[j] + segCost[j][i - 1]);
                    }
                }
            }
            dp.swap(nextDp);
        }

        return dp[n];
    }
};

int main() {
    Solution sol;
    assert(sol.minCostKPartitionRange({1, 5, 2, 8}, 2, true) == 5);
    assert(sol.minCostKPartitionRange({1, 5, 2, 8}, 2, false) == 4);
    assert(sol.minCostKPartitionRange({10, 20, 30}, 3, true) == 0);
    cout << "24_min_cost_k_partition_range_cost passed all tests!\n";
    return 0;
}
