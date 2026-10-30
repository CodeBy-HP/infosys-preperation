#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class LongestIncreasingSubsequence {
public:
    // =========================================================================
    // 1. Top-Down Approach (Recursion + Memoization with Index Shift)
    // Time Complexity: O(N^2)
    // Space Complexity: O(N^2)
    // =========================================================================
    int lengthOfLISMemo(const vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        return solveMemo(0, -1, nums, memo);
    }

private:
    int solveMemo(int curr, int prev, const vector<int>& nums, vector<vector<int>>& memo) {
        if (curr == (int)nums.size()) return 0;

        // prev + 1 maps -1 to index 0
        if (memo[curr][prev + 1] != -1) return memo[curr][prev + 1];

        // Choice A: Skip current number
        int notTake = solveMemo(curr + 1, prev, nums, memo);

        // Choice B: Take current number (if strictly increasing)
        int take = 0;
        if (prev == -1 || nums[curr] > nums[prev]) {
            take = 1 + solveMemo(curr + 1, curr, nums, memo);
        }

        return memo[curr][prev + 1] = max(take, notTake);
    }

public:
    // =========================================================================
    // 2. Bottom-Up Approach (Iterative 1D Tabulation)
    // Time Complexity: O(N^2)
    // Space Complexity: O(N)
    // =========================================================================
    int lengthOfLISTabulation(const vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        // dp[i] stores the length of LIS ending strictly at index i
        vector<int> dp(n, 1);
        int maxLen = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }

    // =========================================================================
    // 3. Patience Sorting / Binary Search Approach
    // Time Complexity: O(N log N)
    // Space Complexity: O(N)
    // =========================================================================
    int lengthOfLISBinarySearch(const vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> tails;

        for (int x : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) {
                tails.push_back(x);
            } else {
                *it = x;
            }
        }

        return tails.size();
    }
};

int main() {
    LongestIncreasingSubsequence solver;

    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Test 1 [10, 9, 2, 5, 3, 7, 101, 18]:\n";
    cout << "  Memoization:   " << solver.lengthOfLISMemo(nums1) << "\n";
    cout << "  Tabulation:    " << solver.lengthOfLISTabulation(nums1) << "\n";
    cout << "  Binary Search: " << solver.lengthOfLISBinarySearch(nums1) << " (Expected: 4)\n";

    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    cout << "Test 2 [0, 1, 0, 3, 2, 3]:\n";
    cout << "  Binary Search: " << solver.lengthOfLISBinarySearch(nums2) << " (Expected: 4)\n";

    return 0;
}

