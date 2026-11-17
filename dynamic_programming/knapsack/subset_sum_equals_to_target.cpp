// Subset Sum Equals Target (GFG)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Recursive DP with Memoization
    // State: dp[idx][sum] = can we achieve sum using elements from idx onwards
    
    int n, target;
    vector<int> arr;
    int dp[105][10005];
    
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
        bool take = solve(idx + 1, sum - arr[idx]);
        
        return dp[idx][sum] = (take || notTake);
    }
    
    bool isSubsetSum(vector<int>& arr, int target) {
        this->arr = arr;
        this->n = arr.size();
        this->target = target;
        memset(dp, -1, sizeof(dp));
        return solve(0, target);
    }
    
    // Approach 2: Space-Optimized 1D DP (Finite State Machine) (Backward iteration)
    bool isSubsetSumOptimized(vector<int>& arr, int target) {
        // Our states (Buckets 0 to target).
        vector<bool> dp(target + 1, false);
        
        // Base state: We can always achieve a sum of 0 (empty subset)
        dp[0] = true;
        
        for (int num : arr) {
            // Loop backwards from Target down to 'num'
            // This acts as an invisible snapshot, preventing the cloning glitch!
            for (int sum = target; sum >= num; --sum) {
                
                // Action Edge: If the bucket 'num' steps behind us is reachable,
                // then our current bucket is also reachable.
                if (dp[sum - num] == true) {
                    dp[sum] = true;
                }
            }
        }
        
        return dp[target];
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> arr1 = {3, 34, 4, 12, 5, 2};
    cout << "Test 1: " << (sol.isSubsetSum(arr1, 9) ? "true" : "false") << endl; // Expected: true
    
    // Test case 2
    vector<int> arr2 = {3, 34, 4, 12, 5, 2};
    cout << "Test 2: " << (sol.isSubsetSum(arr2, 30) ? "true" : "false") << endl; // Expected: false
    
    // Test case 3
    vector<int> arr3 = {1, 2, 7};
    cout << "Test 3: " << (sol.isSubsetSum(arr3, 10) ? "true" : "false") << endl; // Expected: true
    
    return 0;
}
