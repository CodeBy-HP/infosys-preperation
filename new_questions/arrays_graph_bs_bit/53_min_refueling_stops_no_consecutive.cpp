#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    // Variant A: Standard LeetCode 871 - Max-Heap Retroactive Greedy O(N log N)
    int minRefuelStopsStandard(int target, int startFuel, const vector<vector<int>>& stations) {
        priority_queue<int> pq;
        long long reach = startFuel;
        int stops = 0;
        size_t i = 0;

        while (reach < target) {
            while (i < stations.size() && stations[i][0] <= reach) {
                pq.push(stations[i][1]);
                i++;
            }
            if (pq.empty()) return -1;
            reach += pq.top();
            pq.pop();
            stops++;
        }
        return stops;
    }

    // Variant B: Infosys Twist - No Consecutive Refuels in O(N^2) time
    int minRefuelStopsNoConsecutive(int target, int startFuel, const vector<vector<int>>& stations) {
        if (startFuel >= target) return 0;
        int n = stations.size();
        if (n == 0) return -1;

        // dp[i][k] = max reach when i-th station (0-indexed) is the k-th refuel stop
        // To enforce non-consecutive stops (j <= i - 2), track maxReach[k] up to i - 2
        vector<vector<long long>> dp(n, vector<long long>(n + 1, -1));

        for (int i = 0; i < n; i++) {
            if (startFuel >= stations[i][0]) {
                dp[i][1] = static_cast<long long>(startFuel) + stations[i][1];
            }
        }

        // bestTwoBack[k] stores max(dp[0..i-2][k])
        vector<long long> bestTwoBack(n + 1, -1);
        for (int i = 0; i < n; i++) {
            if (i >= 2) {
                for (int k = 1; k <= i - 1; k++) {
                    bestTwoBack[k] = max(bestTwoBack[k], dp[i - 2][k]);
                }
            }
            for (int k = 2; k <= (i + 2) / 2 + 1 && k <= n; k++) {
                if (bestTwoBack[k - 1] >= stations[i][0]) {
                    dp[i][k] = max(dp[i][k], bestTwoBack[k - 1] + stations[i][1]);
                }
            }
        }

        int minStops = n + 1;
        for (int i = 0; i < n; i++) {
            for (int k = 1; k <= n; k++) {
                if (dp[i][k] >= target) {
                    minStops = min(minStops, k);
                }
            }
        }
        return minStops <= n ? minStops : -1;
    }
};

int main() {
    Solution sol;
    assert(sol.minRefuelStopsStandard(100, 10, {{10, 60}, {20, 30}, {30, 30}, {60, 40}}) == 2);
    assert(sol.minRefuelStopsNoConsecutive(100, 10, {{10, 60}, {20, 30}, {30, 30}, {60, 40}}) == 2);
    assert(sol.minRefuelStopsNoConsecutive(25, 10, {{10, 10}, {20, 10}}) == -1);
    assert(sol.minRefuelStopsStandard(25, 10, {{10, 10}, {20, 10}}) == 2);
    cout << "53_min_refueling_stops_no_consecutive passed all tests!\n";
    return 0;
}
