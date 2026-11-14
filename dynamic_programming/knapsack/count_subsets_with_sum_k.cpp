// Count Subsets with Sum K (Perfect Sum Problem / GFG)

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    // Approach 1: Recursive DP with Memoization
    // State: dp[idx][sum] = number of subsets from idx onwards that sum to 'sum'
    
    int n, target;
    vector<int> arr;
    int dp[1005][1005];
    
    int solve(int idx, int sum) {
        // Base case: target sum achieved
        if (sum == 0) return 1;
        
        // Base case: no elements left or invalid sum
        if (idx >= n || sum < 0) return 0;
        
        // Memoization check
        if (dp[idx][sum] != -1) return dp[idx][sum];
        
        // Option 1: Don't take current element
        int notTake = solve(idx + 1, sum);
        
        // Option 2: Take current element
        int take = solve(idx + 1, sum - arr[idx]);
        
        return dp[idx][sum] = (take + notTake) % MOD;
    }
    
    int perfectSum(vector<int>& arr, int target) {
        this->arr = arr;
        this->n = arr.size();
        this->target = target;
        memset(dp, -1, sizeof(dp));
        return solve(0, target);
    }
    
    // Approach 2: Space-Optimized 1D DP ( FSM )
    int perfectSumOptimized(vector<int>& arr, int target) {
        // Buckets now hold the count of ways
        vector<int> dp(sum + 1, 0);
        
        // Base state: 1 way to make a sum of 0 (the empty subset)
        dp[0] = 1;
        
        for (int i = 0; i < n; i++) {
            int num = arr[i];
            
            // The invisible snapshot (looping backwards)
            for (int s = sum; s >= num; s--) {
                // Action Edge adds to the Rest Edge
                dp[s] = (dp[s] + dp[s - num]) % MOD;
            }
        }
        
        return dp[sum];
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> arr1 = {5, 2, 3, 10, 6, 8};
    cout << "Test 1: " << sol.perfectSum(arr1, 10) << endl; // Expected: 3
    
    // Test case 2
    vector<int> arr2 = {0, 0, 1};
    cout << "Test 2: " << sol.perfectSum(arr2, 1) << endl; // Expected: 4
    
    // Test case 3
    vector<int> arr3 = {1, 2, 3, 4, 5};
    cout << "Test 3: " << sol.perfectSum(arr3, 5) << endl; // Expected: 3
    
    return 0;
}
