#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cassert>

using namespace std;

class Solution {
public:
    // Approach 1: O(N * M^2) Rolling DP
    long long minThermostatCost(const vector<int>& target, vector<int> modes, long long switchCost) {
        int n = target.size();
        int m = modes.size();
        sort(modes.begin(), modes.end());

        vector<long long> dp(m);
        for (int j = 0; j < m; j++) {
            dp[j] = abs(target[0] - modes[j]);
        }

        for (int i = 1; i < n; i++) {
            vector<long long> nextDp(m, LLONG_MAX);
            for (int j = 0; j < m; j++) {
                long long opCost = abs(target[i] - modes[j]);
                for (int p = 0; p < m; p++) {
                    long long trans = dp[p] + switchCost * abs(p - j);
                    nextDp[j] = min(nextDp[j], opCost + trans);
                }
            }
            dp.swap(nextDp);
        }

        return *min_element(dp.begin(), dp.end());
    }

    // Approach 2: Optimal O(N * M) Two-Pass Prefix/Suffix Sweep
    long long minThermostatCostOptimal(const vector<int>& target, vector<int> modes, long long switchCost) {
        int n = target.size();
        int m = modes.size();
        sort(modes.begin(), modes.end());

        vector<long long> dp(m);
        for (int j = 0; j < m; j++) {
            dp[j] = abs(target[0] - modes[j]);
        }

        for (int i = 1; i < n; i++) {
            vector<long long> leftBest(m), rightBest(m), nextDp(m);

            // Left-to-right sweep: dp[p] + switchCost * (j - p) = (dp[p] - switchCost * p) + switchCost * j
            leftBest[0] = dp[0];
            for (int j = 1; j < m; j++) {
                leftBest[j] = min(leftBest[j - 1] + switchCost, dp[j]);
            }

            // Right-to-left sweep: dp[p] + switchCost * (p - j)
            rightBest[m - 1] = dp[m - 1];
            for (int j = m - 2; j >= 0; j--) {
                rightBest[j] = min(rightBest[j + 1] + switchCost, dp[j]);
            }

            for (int j = 0; j < m; j++) {
                nextDp[j] = abs(target[i] - modes[j]) + min(leftBest[j], rightBest[j]);
            }
            dp.swap(nextDp);
        }

        return *min_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution sol;
    assert(sol.minThermostatCost({20, 25, 22}, {18, 22, 26}, 2) == 5);
    assert(sol.minThermostatCostOptimal({20, 25, 22}, {18, 22, 26}, 2) == 5);
    assert(sol.minThermostatCost({10, 50, 10}, {10, 30, 50}, 5) ==
           sol.minThermostatCostOptimal({10, 50, 10}, {10, 30, 50}, 5));
    cout << "10_thermostat_schedule passed all tests!\n";
    return 0;
}
