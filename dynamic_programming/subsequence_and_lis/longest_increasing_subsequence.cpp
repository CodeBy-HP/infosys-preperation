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

    // Finite State Machine Approach
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int INF = 1e9; // Safe infinity for elements
        
        // Buckets represent the LENGTH of the sequence.
        // They hold the smallest ending element for that length.
        vector<int> dp(n + 1, INF);
        
        // Base state: A sequence of length 0 effectively ends in -INF
        dp[0] = -INF; 
        
        int max_length = 0;
        
        for (int curr : nums) {
            
            // THE BACKWARD PASS: (0/1 Knapsack style, use element once)
            for (int len = n; len >= 1; len--) {
                
                // Action Edge: We can only extend if we are strictly greater 
                // than the ending element of the previous length bucket.
                if (dp[len - 1] < curr) {
                    
                    // Pull and minimize the ending element
                    dp[len] = min(dp[len], curr);
                    
                    // Keep track of the furthest bucket we've successfully filled
                    if (dp[len] != INF) {
                        max_length = max(max_length, len);
                    }
                }
            }
        }
        
        return max_length;
    }

    // =========================================================================
    // 3. Patience Sorting / Binary Search Approach
    // Time Complexity: O(N log N)
    // Space Complexity: O(N)
    // =========================================================================
    int lengthOfLISBinarySearch(const vector<int>& nums) {
        // This vector dynamically represents our valid buckets
        vector<int> buckets; 
        
        for (int curr : nums) {
            // Binary search to find the first bucket whose ending element is >= curr
            auto it = lower_bound(buckets.begin(), buckets.end(), curr);
            
            if (it == buckets.end()) {
                // If curr is bigger than ALL buckets, it extends our max length!
                // Create a brand new bucket at the end.
                buckets.push_back(curr);
            } else {
                // Otherwise, it overwrites an existing bucket with a smaller ending element
                // This is your exact logic: bucket[length] = min(bucket[length], curr)
                *it = curr; 
            }
        }
        
        // The number of valid buckets created is our Longest Increasing Subsequence
        return buckets.size();
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

