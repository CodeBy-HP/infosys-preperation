// Rod Cutting Problem (GFG)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Recursive DP with Memoization (Unbounded Knapsack variant)
    // State: dp[length] = max value obtainable from rod of given length
    
    int N;
    vector<int> price;
    int dp[1005];
    
    int solve(int length) {
        // Base case: no length left
        if (length == 0) return 0;
        
        // Memoization check
        if (dp[length] != -1) return dp[length];
        
        int maxValue = 0;
        
        // Try all possible first cuts from 1 to length
        for (int cut = 1; cut <= length; cut++) {
            if (cut <= N) {
                int value = price[cut - 1] + solve(length - cut);
                maxValue = max(maxValue, value);
            }
        }
        
        return dp[length] = maxValue;
    }
    
    int cutRod(vector<int>& price, int N) {
        this->price = price;
        this->N = N;
        memset(dp, -1, sizeof(dp));
        return solve(N);
    }
    
    // Approach 2: Iterative DP (Bottom-up)
    int cutRodIterative(vector<int>& price, int n) {
        // Our states: buckets 0 to n (current length of the rod we've built)
        vector<int> dp(n + 1, 0);
        
        // Loop through all available cut lengths.
        // price[i] is the value for a cut of length (i + 1)
        for (int i = 0; i < n; i++) {
            int cut_length = i + 1;
            int cut_price = price[i];
            
            // THE FORWARD PASS: Intentional chain-reaction (Infinite cuts allowed)
            for (int len = cut_length; len <= n; len++) {
                
                // Action Edge (Pulling from 'len - cut_length')
                dp[len] = max(dp[len], dp[len - cut_length] + cut_price);
                
            }
        }
        
        return dp[n];
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> price1 = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << "Test 1: " << sol.cutRod(price1, 8) << endl; // Expected: 22
    
    // Test case 2
    vector<int> price2 = {3, 5, 8, 9, 10, 17, 17, 20};
    cout << "Test 2: " << sol.cutRod(price2, 8) << endl; // Expected: 24
    
    // Test case 3
    vector<int> price3 = {3};
    cout << "Test 3: " << sol.cutRod(price3, 1) << endl; // Expected: 3
    
    return 0;
}
