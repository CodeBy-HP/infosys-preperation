// 0/1 Knapsack Problem (GFG)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Recursive DP with Memoization
    // State: dp[idx][cap] = max value from index idx onwards with capacity cap
    
    int n, W;
    vector<int> wt, val;
    int dp[1005][1005];
    
    int solve(int idx, int capacity) {
        // Base case: no items left or no capacity
        if (idx >= n || capacity == 0) return 0;
        
        // Memoization check
        if (dp[idx][capacity] != -1) return dp[idx][capacity];
        
        // Option 1: Don't take current item
        int notTake = solve(idx + 1, capacity);
        
        // Option 2: Take current item (if it fits)
        int take = 0;
        if (wt[idx] <= capacity) {
            take = val[idx] + solve(idx + 1, capacity - wt[idx]);
        }
        
        return dp[idx][capacity] = max(take, notTake);
    }
    
    int knapSack(int W, vector<int>& wt, vector<int>& val, int n) {
        this->W = W;
        this->n = n;
        this->wt = wt;
        this->val = val;
        memset(dp, -1, sizeof(dp));
        return solve(0, W);
    }
    
    // Approach 2: Space-Optimized 1D DP (Backward iteration) (FSM)
    int knapSackOptimized(int W, vector<int>& wt, vector<int>& val, int n) {
        // Our states (Buckets 0 to W). Initialized to 0 value.
        vector<int> dp(W + 1, 0);
        
        for (int i = 0; i < n; i++) {
            int current_weight = wt[i];
            int current_value = val[i];
            
            // The Backward Pass: Prevents the item from being used multiple times
            for (int wei = W; wei >= current_weight; wei--) {
                
                // State Transition: Max of Rest Edge vs Action Edge
                dp[wei] = max(dp[wei], dp[wei - current_weight] + current_value);
                
            }
        }
        
        // The maximum value could be at exactly W weight, or slightly less,
        // but since our FSM naturally carries max values forward, dp[W] 
        // will always hold the absolute maximum possible value.
        return dp[W];
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> val1 = {1, 2, 3};
    vector<int> wt1 = {4, 5, 1};
    cout << "Test 1: " << sol.knapSack(4, wt1, val1, 3) << endl; // Expected: 3
    
    // Test case 2
    vector<int> val2 = {1, 2, 3};
    vector<int> wt2 = {4, 5, 6};
    cout << "Test 2: " << sol.knapSack(3, wt2, val2, 3) << endl; // Expected: 0
    
    // Test case 3
    vector<int> val3 = {10, 40, 30, 50};
    vector<int> wt3 = {5, 4, 6, 3};
    cout << "Test 3: " << sol.knapSack(5, wt3, val3, 4) << endl; // Expected: 50
    
    return 0;
}
