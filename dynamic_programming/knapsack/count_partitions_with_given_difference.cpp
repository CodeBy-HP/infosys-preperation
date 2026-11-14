// Count Partitions with Given Difference (GFG)

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    // Approach 1: Recursive DP with Memoization
    // Mathematical reduction: S1 - S2 = D and S1 + S2 = totalSum
    // => S1 = (totalSum + D) / 2
    // Problem reduces to counting subsets with sum = target
    
    int n, target;
    vector<int> arr;
    map<pair<int, int>, int> memo;
    
    int solve(int idx, int sum) {
        // Base case: target sum achieved
        if (sum == 0) return 1;
        
        // Base case: no elements left or invalid sum
        if (idx >= n || sum < 0) return 0;
        
        // Memoization check
        auto key = make_pair(idx, sum);
        if (memo.find(key) != memo.end()) return memo[key];
        
        // Option 1: Don't take current element
        int notTake = solve(idx + 1, sum);
        
        // Option 2: Take current element
        int take = solve(idx + 1, sum - arr[idx]);
        
        return memo[key] = (take + notTake) % MOD;
    }
    
    int countPartitions(vector<int>& arr, int D) {
        this->arr = arr;
        this->n = arr.size();
        
        int totalSum = 0;
        for (int num : arr) totalSum += num;
        
        // Check validity: totalSum must be >= D and (totalSum + D) must be even
        if (totalSum < D || (totalSum + D) % 2 != 0) return 0;
        
        target = (totalSum + D) / 2;
        memo.clear();
        
        return solve(0, target);
    }
    
    // Approach 2: Space-Optimized 1D DP
    int countPartitionsOptimized(vector<int>& arr, int D) {
        int totalSum = 0;
        for (int num : arr) totalSum += num;
        
        if (totalSum < D || (totalSum + D) % 2 != 0) return 0;
        
        int target = (totalSum + D) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        for (int num : arr) {
            for (int s = target; s >= num; s--) {
                dp[s] = (dp[s] + dp[s - num]) % MOD;
            }
        }
        
        return dp[target];
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> arr1 = {5, 2, 6, 4};
    cout << "Test 1: " << sol.countPartitions(arr1, 3) << endl; // Expected: 1
    
    // Test case 2
    vector<int> arr2 = {1, 1, 1, 1};
    cout << "Test 2: " << sol.countPartitions(arr2, 0) << endl; // Expected: 6
    
    // Test case 3
    vector<int> arr3 = {1, 2, 1};
    cout << "Test 3: " << sol.countPartitions(arr3, 3) << endl; // Expected: 0
    
    return 0;
}
