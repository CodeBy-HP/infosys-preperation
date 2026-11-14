// Unbounded Knapsack Problem (GFG)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Recursive DP with Memoization
    // State: dp[idx][cap] = max value from index idx onwards with capacity cap
    // Key difference from 0/1: when taking item, stay at same index (allow reuse)
    
    int n, W;
    vector<int> wt, val;
    int dp[1005][1005];
    
    int solve(int idx, int capacity) {
        // Base case: no items left or no capacity
        if (idx >= n || capacity == 0) return 0;
        
        // Memoization check
        if (dp[idx][capacity] != -1) return dp[idx][capacity];
        
        // Option 1: Don't take current item, move to next
        int notTake = solve(idx + 1, capacity);
        
        // Option 2: Take current item (stay at same index - unbounded)
        int take = 0;
        if (wt[idx] <= capacity) {
            take = val[idx] + solve(idx, capacity - wt[idx]); // Stay at idx
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
    
    // Approach 2: Space-Optimized 1D DP (Forward iteration for unbounded)
    int knapSackOptimized(int W, vector<int>& wt, vector<int>& val, int n) {
        vector<int> dp(W + 1, 0);
        
        for (int i = 0; i < N; i++) {
            
            // THE FORWARD PASS: Intentional chain-reaction
            for (int w = wt[i]; w <= W; w++) {
                
                // Action Edge (Pulling from 'w - wt[i]')
                dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
                
            }
        }
        
        return dp[W];
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> val1 = {1, 1};
    vector<int> wt1 = {2, 1};
    cout << "Test 1: " << sol.knapSack(3, wt1, val1, 2) << endl; // Expected: 3
    
    // Test case 2
    vector<int> val2 = {10, 40, 50, 70};
    vector<int> wt2 = {1, 3, 4, 5};
    cout << "Test 2: " << sol.knapSack(8, wt2, val2, 4) << endl; // Expected: 110
    
    // Test case 3
    vector<int> val3 = {1, 2, 3};
    vector<int> wt3 = {4, 5, 1};
    cout << "Test 3: " << sol.knapSack(4, wt3, val3, 3) << endl; // Expected: 12
    
    return 0;
}
