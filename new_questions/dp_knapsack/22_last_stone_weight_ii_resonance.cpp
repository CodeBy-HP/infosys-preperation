#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    int minPowerDifferenceWithResonance(const vector<int>& stones, int R) {
        int n = stones.size();
        if (n == 0) return 0;

        int maxBound = accumulate(stones.begin(), stones.end(), 0) + n * R;
        int offset = maxBound;
        int width = 2 * maxBound + 1;

        // dp[prevSet][diff + offset]
        vector<vector<bool>> dp(2, vector<bool>(width, false));
        dp[0][offset + stones[0]] = true;
        dp[1][offset - stones[0]] = true;

        for (int i = 1; i < n; i++) {
            vector<vector<bool>> nextDp(2, vector<bool>(width, false));
            int w = stones[i];

            for (int d = 0; d < width; d++) {
                if (dp[0][d]) {
                    // Put i in A (same as i-1 -> +w + R)
                    if (d + w + R < width) nextDp[0][d + w + R] = true;
                    // Put i in B (different -> -w)
                    if (d - w >= 0) nextDp[1][d - w] = true;
                }
                if (dp[1][d]) {
                    // Put i in A (different -> +w)
                    if (d + w < width) nextDp[0][d + w] = true;
                    // Put i in B (same as i-1 -> -w - R)
                    if (d - w - R >= 0) nextDp[1][d - w - R] = true;
                }
            }
            dp.swap(nextDp);
        }

        int minDiff = maxBound;
        for (int d = 0; d < width; d++) {
            if (dp[0][d] || dp[1][d]) {
                minDiff = min(minDiff, abs(d - offset));
            }
        }
        return minDiff;
    }
};

int main() {
    Solution sol;
    assert(sol.minPowerDifferenceWithResonance({4, 5, 2}, 2) == 1);
    assert(sol.minPowerDifferenceWithResonance({3, 3}, 5) == 0);
    assert(sol.minPowerDifferenceWithResonance({10}, 5) == 10);
    cout << "22_last_stone_weight_ii_resonance passed all tests!\n";
    return 0;
}
