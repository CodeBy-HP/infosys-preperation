#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HouseRobber {
public:
    // =========================================================================
    // 1. Top-Down Approach (Recursion + Memoization)
    // Time Complexity: O(N)
    // Space Complexity: O(N) [Memo array + Call stack]
    // =========================================================================
    int robMemo(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> memo(n, -1);
        return solveMemo(0, nums, memo);
    }

private:
    int solveMemo(int i, const vector<int>& nums, vector<int>& memo) {
        if (i >= (int)nums.size()) return 0;
        if (memo[i] != -1) return memo[i];

        // Choice 1: Rob house i and jump to i + 2
        int robCurrent = nums[i] + solveMemo(i + 2, nums, memo);

        // Choice 2: Skip house i and move to i + 1
        int skipCurrent = solveMemo(i + 1, nums, memo);

        return memo[i] = max(robCurrent, skipCurrent);
    }

public:
    // =========================================================================
    // 2. Bottom-Up Approach (Iterative Tabulation)
    // Time Complexity: O(N)
    // Space Complexity: O(N) [DP array]
    // =========================================================================
    int robTabulation(const vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];
    }

    // =========================================================================
    // 3. Space-Optimized Approach (Two Variables)
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int robSpaceOptimized(const vector<int>& nums) {
        int prev2 = 0; // Represents dp[i - 2]
        int prev1 = 0; // Represents dp[i - 1]

        for (int money : nums) {
            int current = max(prev1, prev2 + money);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};

int main() {
    HouseRobber solver;

    vector<int> test1 = {2, 7, 9, 3, 1};
    cout << "Test 1 [2, 7, 9, 3, 1]:\n";
    cout << "  Memoization:     " << solver.robMemo(test1) << "\n";
    cout << "  Tabulation:      " << solver.robTabulation(test1) << "\n";
    cout << "  Space-Optimized: " << solver.robSpaceOptimized(test1) << "\n";

    vector<int> test2 = {2, 1, 1, 2};
    cout << "Test 2 [2, 1, 1, 2]:\n";
    cout << "  Space-Optimized: " << solver.robSpaceOptimized(test2) << " (Expected: 4)\n";

    return 0;
}

