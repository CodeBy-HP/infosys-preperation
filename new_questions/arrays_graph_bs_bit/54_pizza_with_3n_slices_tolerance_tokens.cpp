#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

class Solution {
    static constexpr int NEG_INF = -1e9;

public:
    int maxSizeSlicesWithTolerance(const vector<int>& slices, int K) {
        int m = slices.size();
        int n = m / 3;
        if (n == 0) return 0;

        int globalBest = NEG_INF;

        // Solve twice: pickFirst = 0 (skip index 0) and pickFirst = 1 (pick index 0)
        for (int pickFirst = 0; pickFirst <= 1; pickFirst++) {
            // dp[cnt][tol][lastPicked]
            vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(K + 1, vector<int>(2, NEG_INF)));

            if (pickFirst == 0) {
                dp[0][0][0] = 0;
            } else {
                dp[1][0][1] = slices[0];
            }

            for (int i = 1; i < m; i++) {
                vector<vector<vector<int>>> nextDp(n + 1, vector<vector<int>>(K + 1, vector<int>(2, NEG_INF)));
                for (int cnt = 0; cnt <= n; cnt++) {
                    for (int tol = 0; tol <= K; tol++) {
                        // Option 1: Skip slices[i]
                        int bestPrev = max(dp[cnt][tol][0], dp[cnt][tol][1]);
                        nextDp[cnt][tol][0] = max(nextDp[cnt][tol][0], bestPrev);

                        // Option 2: Pick slices[i]
                        if (cnt + 1 <= n) {
                            if (dp[cnt][tol][0] != NEG_INF) {
                                nextDp[cnt + 1][tol][1] = max(nextDp[cnt + 1][tol][1], dp[cnt][tol][0] + slices[i]);
                            }
                            if (dp[cnt][tol][1] != NEG_INF && tol + 1 <= K) {
                                nextDp[cnt + 1][tol + 1][1] = max(nextDp[cnt + 1][tol + 1][1], dp[cnt][tol][1] + slices[i]);
                            }
                        }
                    }
                }
                dp.swap(nextDp);
            }

            for (int tol = 0; tol <= K; tol++) {
                globalBest = max(globalBest, dp[n][tol][0]);
                // If both index 0 and index m - 1 were picked, wrap-around adjacency consumes 1 token
                int extraWrapToken = (pickFirst == 1 && m > 1) ? 1 : 0;
                if (tol + extraWrapToken <= K) {
                    globalBest = max(globalBest, dp[n][tol][1]);
                }
            }
        }

        return globalBest;
    }
};

int main() {
    Solution sol;
    assert(sol.maxSizeSlicesWithTolerance({1, 2, 3, 4, 5, 6}, 0) == 10);
    assert(sol.maxSizeSlicesWithTolerance({8, 9, 8, 6, 1, 1}, 0) == 16);
    assert(sol.maxSizeSlicesWithTolerance({1, 2, 3, 4, 5, 6}, 1) == 11); // [5, 6] using 1 token
    assert(sol.maxSizeSlicesWithTolerance({5, 1, 1, 1, 1, 5}, 1) == 10); // wrap-around [0] & [5] using 1 token
    cout << "54_pizza_with_3n_slices_tolerance_tokens passed all tests!\n";
    return 0;
}
