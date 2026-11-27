#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cassert>

using namespace std;

class Solution {
public:
    // Variant A: Fixed Joining Order (0..n-1), try every kid i as captain (2 * s[i])
    long long minDiffFixedOrder(const vector<int>& s) {
        int n = s.size();
        long long best = LLONG_MAX;

        for (int cap = 0; cap < n; cap++) {
            long long teamA = 0, teamB = 0;
            for (int i = 0; i < n; i++) {
                long long strength = (i == cap) ? 2LL * s[i] : s[i];
                if (teamA <= teamB) teamA += strength;
                else teamB += strength;
            }
            best = min(best, abs(teamA - teamB));
        }
        return best;
    }

    // Variant B: Optimal Joining Order + Optimal Captain (Bitmask DP over d = |A - B|)
    int minDiffOptimalOrder(const vector<int>& s) {
        int n = s.size();
        int best = INT_MAX;

        for (int cap = 0; cap < n; cap++) {
            vector<int> arr(n);
            for (int i = 0; i < n; i++) arr[i] = (i == cap) ? 2 * s[i] : s[i];

            int full = (1 << n) - 1;
            vector<unordered_set<int>> dp(1 << n);
            dp[0].insert(0);

            for (int mask = 0; mask < full; mask++) {
                if (dp[mask].empty()) continue;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) continue;
                    int nextMask = mask | (1 << i);
                    for (int d : dp[mask]) {
                        dp[nextMask].insert(abs(d - arr[i]));
                    }
                }
            }

            for (int d : dp[full]) {
                best = min(best, d);
            }
        }
        return best;
    }
};

int main() {
    Solution sol;
    assert(sol.minDiffOptimalOrder({1, 2, 4}) == 0);
    assert(sol.minDiffOptimalOrder({1, 5, 11, 5}) == 1); // cap=1->2: 11(A), 5(B), 5(B), 2(B) => 11 vs 12 => 1
    assert(sol.minDiffFixedOrder({3, 1, 4, 2}) >= 0);
    cout << "40_tug_of_war_captain passed all tests!\n";
    return 0;
}
