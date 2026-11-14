// Weighted Coin Change Problem

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Recursive DP with Memoization (Unbounded Knapsack)
    // State: dp[idx][amount] = min weight needed from idx onwards to make amount
    // Each coin has a different weight (cost) associated with it
    
    int n;
    vector<int> coins, weights;
    map<pair<int, int>, int> memo;
    
    int solve(int idx, int amount) {
        // Base case: amount achieved
        if (amount == 0) return 0;
        
        // Base case: no coins left or invalid amount
        if (idx >= n || amount < 0) return INT_MAX - 10000;
        
        // Memoization check
        auto key = make_pair(idx, amount);
        if (memo.find(key) != memo.end()) return memo[key];
        
        // Option 1: Don't take current coin, move to next
        int notTake = solve(idx + 1, amount);
        
        // Option 2: Take current coin (stay at same index - unbounded)
        int take = INT_MAX - 10000;
        if (coins[idx] <= amount) {
            int subproblem = solve(idx, amount - coins[idx]);
            if (subproblem != INT_MAX - 10000) {
                take = weights[idx] + subproblem; // Add weight of current coin
            }
        }
        
        return memo[key] = min(take, notTake);
    }
    
    int minWeight(vector<int>& coins, vector<int>& weights, int target) {
        this->coins = coins;
        this->weights = weights;
        this->n = coins.size();
        memo.clear();
        
        int result = solve(0, target);
        return (result >= INT_MAX - 10000) ? -1 : result;
    }
    
    // Approach 2: Space-Optimized 1D DP (Forward iteration for unbounded)
    int minWeightOptimized(vector<int>& coins, vector<int>& weights, int target) {
        // Use a safe infinity to prevent integer overflow when adding weight[i]
        long long INF = 1e18; 
        vector<long long> dp(target + 1, INF);
        
        // Base state: It takes 0 weight to make an amount of 0.
        dp[0] = 0;
        
        for (int i = 0; i < coins.size(); i++) {
            int coin = coins[i];
            long long weight = weights[i];
            
            // THE FORWARD PASS: Intentional chain-reaction (Infinite supply)
            for (int s = coin; s <= target; s++) {
                
                // The Action Edge (Pulling from 's - coin' and adding custom weight)
                if (dp[s - coin] != INF) {
                    dp[s] = min(dp[s], dp[s - coin] + weight);
                }
            }
        }
        
        return dp[target] == INF ? -1 : dp[target];
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> coins1 = {1, 2, 5};
    vector<int> weights1 = {10, 5, 2};
    cout << "Test 1: " << sol.minWeight(coins1, weights1, 11) << endl; // Expected: 7
    
    // Test case 2
    vector<int> coins2 = {2};
    vector<int> weights2 = {3};
    cout << "Test 2: " << sol.minWeight(coins2, weights2, 3) << endl; // Expected: -1
    
    // Test case 3
    vector<int> coins3 = {1, 2, 5};
    vector<int> weights3 = {1, 1, 1};
    cout << "Test 3: " << sol.minWeight(coins3, weights3, 11) << endl; // Expected: 3
    
    return 0;
}
