#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class JumpGameII {
public:
    // =========================================================================
    // 1. Optimal Greedy Approach (Implicit BFS Window)
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int jumpGreedy(const vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int jumps = 0;
        int currentEnd = 0; // Boundary of current jump window
        int farthest = 0;   // Maximum reachable index from current window

        // Loop up to the second-to-last element (n - 2)
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            // When we exhaust our current jump reach, commit to the next jump
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;

                if (currentEnd >= n - 1) break;
            }
        }

        return jumps;
    }

    // =========================================================================
    // 2. Bottom-Up Dynamic Programming Approach
    // dp[i] = min jumps to reach index i from index 0
    // Time Complexity: O(N^2)
    // Space Complexity: O(N)
    // =========================================================================
    int jumpDP(const vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        vector<int> dp(n, 1e9);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == 1e9) continue;
            int maxReach = min(n - 1, i + nums[i]);
            for (int j = i + 1; j <= maxReach; j++) {
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }

        return dp[n - 1];
    }

    // =========================================================================
    // 3. Top-Down Approach (Recursion + Memoization)
    // Time Complexity: O(N^2)
    // Space Complexity: O(N)
    // =========================================================================
    int jumpMemo(const vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);
        return solveMemo(0, nums, memo);
    }

private:
    int solveMemo(int i, const vector<int>& nums, vector<int>& memo) {
        int n = nums.size();
        if (i >= n - 1) return 0;
        if (memo[i] != -1) return memo[i];

        int minJumps = 1e9;
        int maxReach = min(n - 1, i + nums[i]);
        for (int j = i + 1; j <= maxReach; j++) {
            minJumps = min(minJumps, 1 + solveMemo(j, nums, memo));
        }

        return memo[i] = minJumps;
    }
};

int main() {
    JumpGameII solver;

    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Test 1 [2, 3, 1, 1, 4]:\n";
    cout << "  Greedy:      " << solver.jumpGreedy(nums1) << "\n";
    cout << "  DP:          " << solver.jumpDP(nums1) << "\n";
    cout << "  Memoization: " << solver.jumpMemo(nums1) << " (Expected: 2)\n";

    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << "Test 2 [2, 3, 0, 1, 4]:\n";
    cout << "  Greedy:      " << solver.jumpGreedy(nums2) << " (Expected: 2)\n";

    return 0;
}

