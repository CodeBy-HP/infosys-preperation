// Coin Change II (LeetCode 518)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Recursive DP with Memoization (Unbounded Knapsack)
    // State: dp[idx][amount] = number of ways to make amount using coins from idx onwards
    
    int n;
    vector<int> coins;
    map<pair<int, int>, int> memo;
    
    int solve(int idx, int amount) {
        // Base case: amount achieved
        if (amount == 0) return 1;
        
        // Base case: no coins left or invalid amount
        if (idx >= n || amount < 0) return 0;
        
        // Memoization check
        auto key = make_pair(idx, amount);
        if (memo.find(key) != memo.end()) return memo[key];
        
        // Option 1: Don't take current coin, move to next
        int notTake = solve(idx + 1, amount);
        
        // Option 2: Take current coin (stay at same index - unbounded)
        int take = 0;
        if (coins[idx] <= amount) {
            take = solve(idx, amount - coins[idx]); // Stay at idx
        }
        
        return memo[key] = take + notTake;
    }
    
    int change(int amount, vector<int>& coins) {
        this->coins = coins;
        this->n = coins.size();
        memo.clear();
        return solve(0, amount);
    }
    
    // Approach 2: Space-Optimized 1D DP (Forward iteration for combinations)
    int changeOptimized(int amount, vector<int>& coins) {
        // Our states: buckets 0 to amount.
        vector<int> dp(amount + 1, 0);
        
        // Base state: 1 way to make an amount of 0 (use no coins)
        dp[0] = 1;
        
        for (int coin : coins) {
            
            // THE FORWARD PASS: Intentional chain-reaction (Unbounded Knapsack)
            for (int target = coin; target <= amount; target++) {
                
                // The Action Edge adds to the Rest Edge
                dp[target] += dp[target - coin];
                
            }
        }
        
        return dp[amount];
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> coins1 = {1, 2, 5};
    cout << "Test 1: " << sol.change(5, coins1) << endl; // Expected: 4
    
    // Test case 2
    vector<int> coins2 = {2};
    cout << "Test 2: " << sol.change(3, coins2) << endl; // Expected: 0
    
    // Test case 3
    vector<int> coins3 = {10};
    cout << "Test 3: " << sol.change(10, coins3) << endl; // Expected: 1
    
    return 0;
}
