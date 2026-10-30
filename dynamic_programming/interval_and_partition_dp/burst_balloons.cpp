#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BurstBalloons {
public:
    // =========================================================================
    // 1. Top-Down Approach (Recursion + Memoization)
    // Time Complexity: O(N^3)
    // Space Complexity: O(N^2)
    // =========================================================================
    int maxCoinsMemo(const vector<int>& nums) {
        int n = nums.size();
        vector<int> a;
        a.push_back(1);
        for (int x : nums) a.push_back(x);
        a.push_back(1);

        vector<vector<int>> memo(n + 2, vector<int>(n + 2, -1));
        return solveMemo(1, n, a, memo);
    }

private:
    int solveMemo(int i, int j, const vector<int>& a, vector<vector<int>>& memo) {
        if (i > j) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        int maxCoins = 0;
        // Try picking balloon k as the LAST balloon to burst in interval [i, j]
        for (int k = i; k <= j; k++) {
            int coins = a[i - 1] * a[k] * a[j + 1]
                      + solveMemo(i, k - 1, a, memo)
                      + solveMemo(k + 1, j, a, memo);
            maxCoins = max(maxCoins, coins);
        }

        return memo[i][j] = maxCoins;
    }

public:
    // =========================================================================
    // 2. Bottom-Up Approach (Interval DP Tabulation)
    // Loops i backwards from n to 1 and j forwards from i to n
    // Time Complexity: O(N^3)
    // Space Complexity: O(N^2)
    // =========================================================================
    int maxCoinsTabulation(const vector<int>& nums) {
        int n = nums.size();
        vector<int> a;
        a.push_back(1);
        for (int x : nums) a.push_back(x);
        a.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                int maxCoins = 0;
                for (int k = i; k <= j; k++) {
                    int coins = a[i - 1] * a[k] * a[j + 1]
                              + dp[i][k - 1]
                              + dp[k + 1][j];
                    maxCoins = max(maxCoins, coins);
                }
                dp[i][j] = maxCoins;
            }
        }

        return dp[1][n];
    }
};

int main() {
    BurstBalloons solver;

    vector<int> nums = {3, 1, 5, 8};
    cout << "Test [3, 1, 5, 8]:\n";
    cout << "  Memoization: " << solver.maxCoinsMemo(nums) << "\n";
    cout << "  Tabulation:  " << solver.maxCoinsTabulation(nums) << " (Expected: 167)\n";

    return 0;
}

