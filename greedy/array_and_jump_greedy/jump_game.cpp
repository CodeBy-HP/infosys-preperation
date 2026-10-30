#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class JumpGame {
public:
    // =========================================================================
    // 1. Forward Greedy Approach (Rolling Maximum Reach)
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    bool canJumpForwardGreedy(const vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;

        for (int i = 0; i < n; i++) {
            if (i > farthest) {
                return false; // Trapped in an unreachable gap
            }

            farthest = max(farthest, i + nums[i]);
            if (farthest >= n - 1) {
                return true; // Reached end early
            }
        }

        return true;
    }

    // =========================================================================
    // 2. Backward Greedy Approach (Goal Shrinking)
    // Start at the target and greedily pull the goal backwards to index 0.
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    bool canJumpBackwardGreedy(const vector<int>& nums) {
        int goal = nums.size() - 1;

        for (int i = (int)nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= goal) {
                goal = i; // Index i can reach the goal, so i becomes our new target
            }
        }

        return goal == 0;
    }

    // =========================================================================
    // 3. Dynamic Programming Approach (Educational Baseline)
    // Time Complexity: O(N^2)
    // Space Complexity: O(N)
    // =========================================================================
    bool canJumpDP(const vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[0] = true;

        for (int i = 0; i < n; i++) {
            if (!dp[i]) continue;
            int maxReach = min(n - 1, i + nums[i]);
            for (int j = i + 1; j <= maxReach; j++) {
                dp[j] = true;
            }
            if (dp[n - 1]) return true;
        }

        return dp[n - 1];
    }
};

int main() {
    JumpGame solver;

    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Test 1 [2, 3, 1, 1, 4]:\n";
    cout << "  Forward Greedy:  " << (solver.canJumpForwardGreedy(nums1) ? "true" : "false") << "\n";
    cout << "  Backward Greedy: " << (solver.canJumpBackwardGreedy(nums1) ? "true" : "false") << "\n";
    cout << "  DP:              " << (solver.canJumpDP(nums1) ? "true" : "false") << " (Expected: true)\n";

    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "Test 2 [3, 2, 1, 0, 4]:\n";
    cout << "  Forward Greedy:  " << (solver.canJumpForwardGreedy(nums2) ? "true" : "false") << " (Expected: false)\n";

    return 0;
}

