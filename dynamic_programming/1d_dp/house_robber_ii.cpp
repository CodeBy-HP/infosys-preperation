#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HouseRobberII {
public:
    // =========================================================================
    // 1. Top-Down Approach (Recursion + Memoization on 2 Slices)
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    int robMemo(const vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> memo1(n, -1);
        vector<int> memo2(n, -1);

        // Universe A: 0 to n - 2
        int ans1 = solveMemo(0, n - 2, nums, memo1);
        // Universe B: 1 to n - 1
        int ans2 = solveMemo(1, n - 1, nums, memo2);

        return max(ans1, ans2);
    }

private:
    int solveMemo(int i, int end, const vector<int>& nums, vector<int>& memo) {
        if (i > end) return 0;
        if (memo[i] != -1) return memo[i];

        int robCurrent = nums[i] + solveMemo(i + 2, end, nums, memo);
        int skipCurrent = solveMemo(i + 1, end, nums, memo);

        return memo[i] = max(robCurrent, skipCurrent);
    }

public:
    // =========================================================================
    // 2. Bottom-Up Approach (Tabulation on 2 Slices)
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    int robTabulation(const vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        auto tabulateRange = [&](int start, int end) {
            int len = end - start + 1;
            if (len == 1) return nums[start];
            vector<int> dp(len, 0);
            dp[0] = nums[start];
            dp[1] = max(nums[start], nums[start + 1]);

            for (int i = 2; i < len; i++) {
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i]);
            }
            return dp[len - 1];
        };

        return max(tabulateRange(0, n - 2), tabulateRange(1, n - 1));
    }

    // =========================================================================
    // 3. Space-Optimized Approach (Two Variables, O(1) Space)
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int robSpaceOptimized(const vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }

private:
    int robLinear(const vector<int>& nums, int start, int end) {
        int prev2 = 0;
        int prev1 = 0;

        for (int i = start; i <= end; i++) {
            int current = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};

int main() {
    HouseRobberII solver;

    vector<int> test1 = {2, 3, 2};
    cout << "Test 1 [2, 3, 2]:\n";
    cout << "  Memoization:     " << solver.robMemo(test1) << "\n";
    cout << "  Tabulation:      " << solver.robTabulation(test1) << "\n";
    cout << "  Space-Optimized: " << solver.robSpaceOptimized(test1) << "\n";

    vector<int> test2 = {1, 2, 3, 1};
    cout << "Test 2 [1, 2, 3, 1]:\n";
    cout << "  Space-Optimized: " << solver.robSpaceOptimized(test2) << " (Expected: 4)\n";

    return 0;
}

