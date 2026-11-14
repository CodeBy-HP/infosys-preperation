// Partition Equal Subset Sum (LeetCode 416)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Recursive DP with Memoization
    // Reduce to subset sum problem: find if subset with sum = totalSum/2 exists
    
    int n, target;
    vector<int> nums;
    int dp[205][20005];
    
    bool solve(int idx, int sum) {
        // Base case: target sum achieved
        if (sum == 0) return true;
        
        // Base case: no elements left or invalid sum
        if (idx >= n || sum < 0) return false;
        
        // Memoization check
        if (dp[idx][sum] != -1) return dp[idx][sum];
        
        // Option 1: Don't take current element
        bool notTake = solve(idx + 1, sum);
        
        // Option 2: Take current element
        bool take = solve(idx + 1, sum - nums[idx]);
        
        return dp[idx][sum] = (take || notTake);
    }
    
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;
        
        // If total sum is odd, cannot partition equally
        if (totalSum % 2 != 0) return false;
        
        this->nums = nums;
        this->n = nums.size();
        this->target = totalSum / 2;
        memset(dp, -1, sizeof(dp));
        
        return solve(0, target);
    }
    
    // Approach 2: Space-Optimized 1D DP
    bool canPartitionOptimized(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;
        
        if (totalSum % 2 != 0) return false;
        
        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        
        for (int num : nums) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        
        return dp[target];
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {1, 5, 11, 5};
    cout << "Test 1: " << (sol.canPartition(nums1) ? "true" : "false") << endl; // Expected: true
    
    // Test case 2
    vector<int> nums2 = {1, 2, 3, 5};
    cout << "Test 2: " << (sol.canPartition(nums2) ? "true" : "false") << endl; // Expected: false
    
    // Test case 3
    vector<int> nums3 = {1, 2, 5};
    cout << "Test 3: " << (sol.canPartition(nums3) ? "true" : "false") << endl; // Expected: false
    
    return 0;
}
