#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class PartitionEqualSubsetSum {
public:
    // =========================================================================
    // 1. Top-Down Approach (Recursion + Memoization)
    // Time Complexity: O(N * Target)
    // Space Complexity: O(N * Target)
    // =========================================================================
    bool canPartitionMemo(const vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(target + 1, -1));

        return solveMemo(n - 1, target, nums, memo);
    }

private:
    bool solveMemo(int i, int target, const vector<int>& nums, vector<vector<int>>& memo) {
        if (target == 0) return true;
        if (i < 0 || target < 0) return false;

        if (memo[i][target] != -1) return memo[i][target];

        bool notPick = solveMemo(i - 1, target, nums, memo);
        bool pick = false;
        if (target >= nums[i]) {
            pick = solveMemo(i - 1, target - nums[i], nums, memo);
        }

        return memo[i][target] = (pick || notPick);
    }

public:
    // =========================================================================
    // 2. Bottom-Up Approach (2D Tabulation)
    // Time Complexity: O(N * Target)
    // Space Complexity: O(N * Target)
    // =========================================================================
    bool canPartitionTabulation(const vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i = 0; i < n; i++) dp[i][0] = true;
        if (nums[0] <= target) dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                bool notPick = dp[i - 1][j];
                bool pick = (j >= nums[i]) ? dp[i - 1][j - nums[i]] : false;
                dp[i][j] = notPick || pick;
            }
        }

        return dp[n - 1][target];
    }

    // =========================================================================
    // 3. Space-Optimized Approach (1D Array with Backwards Loop)
    // Time Complexity: O(N * Target)
    // Space Complexity: O(Target)
    // =========================================================================
    bool canPartitionSpaceOptimized(const vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            // Loop backwards to ensure 0/1 (at most single use) semantics
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
            if (dp[target]) return true;
        }

        return dp[target];
    }
};

int main() {
    PartitionEqualSubsetSum solver;

    vector<int> test1 = {1, 5, 11, 5};
    cout << "Test 1 [1, 5, 11, 5]:\n";
    cout << "  Memoization:     " << (solver.canPartitionMemo(test1) ? "true" : "false") << "\n";
    cout << "  Tabulation:      " << (solver.canPartitionTabulation(test1) ? "true" : "false") << "\n";
    cout << "  Space-Optimized: " << (solver.canPartitionSpaceOptimized(test1) ? "true" : "false") << " (Expected: true)\n";

    vector<int> test2 = {1, 2, 3, 5};
    cout << "Test 2 [1, 2, 3, 5]:\n";
    cout << "  Space-Optimized: " << (solver.canPartitionSpaceOptimized(test2) ? "true" : "false") << " (Expected: false)\n";

    return 0;
}

