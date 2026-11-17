// Target Sum (LeetCode 494)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Recursive DP with Memoization
    // Mathematical reduction: P - N = target and P + N = totalSum
    // => P = (totalSum + target) / 2
    // Problem reduces to counting subsets with sum = P
    
    int n, targetSum;
    vector<int> nums;
    map<pair<int, int>, int> memo;
    
    int solve(int idx, int sum) {
        // Base case: processed all elements
        if (idx >= n) {
            return (sum == 0) ? 1 : 0;
        }
        
        // Memoization check
        auto key = make_pair(idx, sum);
        if (memo.find(key) != memo.end()) return memo[key];
        
        // Option 1: Don't take current element
        int notTake = solve(idx + 1, sum);
        
        // Option 2: Take current element
        int take = 0;
        if (sum >= nums[idx]) {
            take = solve(idx + 1, sum - nums[idx]);
        }
        
        return memo[key] = take + notTake;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        this->nums = nums;
        this->n = nums.size();
        
        int totalSum = 0;
        for (int num : nums) totalSum += num;
        
        // Check validity: |target| <= totalSum and (totalSum + target) must be even
        if (abs(target) > totalSum || (totalSum + target) % 2 != 0) return 0;
        
        targetSum = (totalSum + target) / 2;
        memo.clear();
        
        return solve(0, targetSum);
    }
    
    // Approach 2: Space-Optimized 1D DP (Finite State Machine)
    int findTargetSumWaysOptimized(vector<int>& nums, int target) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        // Edge Case 1: Target is physically unreachable
        // Edge Case 2: (target + total_sum) must be even for S1 to be an integer
        if (abs(target) > total_sum || (target + total_sum) % 2 != 0) {
            return 0;
        }
        
        // The mathematical reduction
        int subset_sum = (target + total_sum) / 2;
        
        // FSM Buckets: size is exactly what we need, nothing more.
        vector<int> dp(subset_sum + 1, 0);
        
        // Base state: 1 way to reach a sum of 0 (using no elements)
        dp[0] = 1;
        
        // The 0/1 Knapsack Engine
        for (int num : nums) {
            // Invisible Snapshot: Looping backwards prevents the cloning glitch
            for (int s = subset_sum; s >= num; --s) {
                
                // Action Edge + Rest Edge
                dp[s] = dp[s] + dp[s - num];
            }
        }
        
        return dp[subset_sum];
    }


    // Approach 3 : (finite State Machine Brute force)
    int findTargetSumWaysFSM(vector<int>& nums, int target) {
        int offset = 1000;
        // The constraints say the sum of elements won't exceed 1000.
        // So our buckets go from -1000 to +1000, mapped to indices 0 to 2000.
        vector<int> dp(2001, 0);
        
        // Base state: 1 way to reach a sum of 0 (with no elements)
        dp[0 + offset] = 1; 
        
        for (int num : nums) {
            // Take the snapshot! All buckets start empty for today.
            vector<int> next_dp(2001, 0);
            
            // We iterate through all physically possible bucket sums
            for (int s = -1000; s <= 1000; s++) {
                if (dp[s + offset] > 0) {
                    
                    // Action Edge 1: Assign '+'
                    next_dp[(s + num) + offset] += dp[s + offset];
                    
                    // Action Edge 2: Assign '-'
                    next_dp[(s - num) + offset] += dp[s + offset];
                }
            }
            // Commit the state hand-off
            dp = next_dp;
        }
        
        // If the target is wildly out of bounds, return 0.
        if (abs(target) > 1000) return 0;
        
        return dp[target + offset];
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {1, 1, 1, 1, 1};
    cout << "Test 1: " << sol.findTargetSumWays(nums1, 3) << endl; // Expected: 5
    
    // Test case 2
    vector<int> nums2 = {1};
    cout << "Test 2: " << sol.findTargetSumWays(nums2, 1) << endl; // Expected: 1
    
    // Test case 3
    vector<int> nums3 = {1};
    cout << "Test 3: " << sol.findTargetSumWays(nums3, 2) << endl; // Expected: 0
    
    return 0;
}
