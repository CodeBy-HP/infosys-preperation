// Partition Set Into 2 Subsets With Min Absolute Sum Difference (GFG)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Recursive DP to find all possible subset sums
    // Then calculate minimum difference
    
    int n, totalSum;
    vector<int> arr;
    map<pair<int, int>, bool> memo;
    
    bool solve(int idx, int sum) {
        // Base case: target sum achieved
        if (sum == 0) return true;
        
        // Base case: no elements left or invalid sum
        if (idx >= n || sum < 0) return false;
        
        // Memoization check
        auto key = make_pair(idx, sum);
        if (memo.find(key) != memo.end()) return memo[key];
        
        // Option 1: Don't take current element
        bool notTake = solve(idx + 1, sum);
        
        // Option 2: Take current element
        bool take = solve(idx + 1, sum - arr[idx]);
        
        return memo[key] = (take || notTake);
    }
    
    int minDifference(vector<int>& arr) {
        this->arr = arr;
        this->n = arr.size();
        
        totalSum = 0;
        for (int num : arr) totalSum += num;
        
        int minDiff = INT_MAX;
        
        // Try all possible subset sums from 0 to totalSum/2
        for (int s1 = 0; s1 <= totalSum / 2; s1++) {
            memo.clear();
            if (solve(0, s1)) {
                int s2 = totalSum - s1;
                minDiff = min(minDiff, abs(s2 - s1));
            }
        }
        
        return minDiff;
    }
    
    // Approach 2: Optimized - Find all reachable sums using DP
    int minDifferenceOptimized(vector<int>& arr) {
        int totalSum = 0;
        for (int num : arr) totalSum += num;
        
        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        
        // Find all reachable subset sums up to totalSum/2
        for (int num : arr) {
            for (int s = target; s >= num; s--) {
                if (dp[s - num]) dp[s] = true;
            }
        }
        
        // Find maximum subset sum <= totalSum/2
        int maxSum = 0;
        for (int s = target; s >= 0; s--) {
            if (dp[s]) {
                maxSum = s;
                break;
            }
        }
        
        // Minimum difference = totalSum - 2 * maxSum
        return totalSum - 2 * maxSum;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> arr1 = {1, 6, 11, 5};
    cout << "Test 1: " << sol.minDifferenceOptimized(arr1) << endl; // Expected: 1
    
    // Test case 2
    vector<int> arr2 = {1, 4};
    cout << "Test 2: " << sol.minDifferenceOptimized(arr2) << endl; // Expected: 3
    
    // Test case 3
    vector<int> arr3 = {3, 9, 7, 3};
    cout << "Test 3: " << sol.minDifferenceOptimized(arr3) << endl; // Expected: 2
    
    return 0;
}
