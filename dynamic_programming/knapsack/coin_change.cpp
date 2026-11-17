// Coin Change (LeetCode 322)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Recursive DP with Memoization (Unbounded Knapsack)
    // State: dp[idx][amount] = min coins needed from idx onwards to make amount
    
    int n;
    vector<int> coins;
    map<pair<int, int>, int> memo;
    
    int solve(int idx, int amount) {
        // Base case: amount achieved
        if (amount == 0) return 0;
        
        // Base case: no coins left or invalid amount
        if (idx >= n || amount < 0) return INT_MAX - 1;
        
        // Memoization check
        auto key = make_pair(idx, amount);
        if (memo.find(key) != memo.end()) return memo[key];
        
        // Option 1: Don't take current coin, move to next
        int notTake = solve(idx + 1, amount);
        
        // Option 2: Take current coin (stay at same index - unbounded)
        int take = INT_MAX - 1;
        if (coins[idx] <= amount) {
            take = 1 + solve(idx, amount - coins[idx]); // Stay at idx
        }
        
        return memo[key] = min(take, notTake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        this->coins = coins;
        this->n = coins.size();
        memo.clear();
        
        int result = solve(0, amount);
        return (result >= INT_MAX - 1) ? -1 : result;
    }
    
    // Approach 2: Space-Optimized 1D DP (Forward iteration for unbounded)
    int coinChangeOptimized(vector<int>& coins, int amount) {
        // A common trick: Instead of INT_MAX (which overflows if you add 1), 
        // we use (amount + 1). It is mathematically impossible to need more 
        // coins than the total amount (e.g., amount 11 using all 1-cent coins takes 11 coins).
        int INF = amount + 1;
        vector<int> dp(amount + 1, INF);
        
        // Base state: It takes 0 coins to make an amount of 0.
        dp[0] = 0;
        
        for (int coin : coins) {
            
            // THE FORWARD PASS: Intentional chain-reaction (Unbounded Knapsack)
            for (int s = coin; s <= amount; s++) {
                
                // The Action Edge (Pulling from 's - coin')
                if (dp[s - coin] != INF) {
                    dp[s] = min(dp[s], dp[s - coin] + 1);
                }
            }
        }
        
        // If the final bucket still has our infinity lock, the amount is unreachable.
        return dp[amount] == INF ? -1 : dp[amount];
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> coins1 = {1, 2, 5};
    cout << "Test 1: " << sol.coinChange(coins1, 11) << endl; // Expected: 3
    
    // Test case 2
    vector<int> coins2 = {2};
    cout << "Test 2: " << sol.coinChange(coins2, 3) << endl; // Expected: -1
    
    // Test case 3
    vector<int> coins3 = {1};
    cout << "Test 3: " << sol.coinChange(coins3, 0) << endl; // Expected: 0
    
    return 0;
}
