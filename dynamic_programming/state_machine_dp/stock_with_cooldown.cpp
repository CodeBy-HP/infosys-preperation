// Best Time to Buy and Sell Stock with Cooldown (LeetCode 309)
// Unlimited transactions with 1-day cooldown after selling

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Recursive DP with Memoization
    // State: dp[i][holding] = max profit from day i onwards
    // holding = 1: currently holding stock, holding = 0: not holding stock
    
    int n;
    vector<int> prices;
    int dp[5005][2];
    
    int solve(int idx, int holding) {
        // Base case: reached end of array
        if (idx >= n) return 0;
        
        // Memoization check
        if (dp[idx][holding] != -1) return dp[idx][holding];
        
        int profit = 0;
        
        if (holding == 0) {
            // Not holding: can buy or skip
            int buyToday = -prices[idx] + solve(idx + 1, 1);
            int skip = solve(idx + 1, 0);
            profit = max(buyToday, skip);
        } else {
            // Holding: can sell (with cooldown) or skip
            // If we sell today, next buy can only happen at idx+2 (cooldown)
            int sellToday = prices[idx] + solve(idx + 2, 0);
            int skip = solve(idx + 1, 1);
            profit = max(sellToday, skip);
        }
        
        return dp[idx][holding] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        this->prices = prices;
        this->n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0); // Start from day 0, not holding
    }
    
    // Approach 2: State Machine with 3 variables (O(1) space)
    // States: hold (holding stock), sold (just sold, in cooldown), rest (not holding, can buy)
    int maxProfitOptimized(vector<int>& prices) {
        int buy = INT_MIN;
        int sell = 0;
        int prev_sell = 0; // Tracks the 'sell' balance from two days ago
        
        for (int price : prices) {
            // Calculate today's potential new states BEFORE updating anything
            int next_buy = max(buy, prev_sell - price);
            int next_sell = max(sell, buy + price);
            
            // The relay race hand-off
            prev_sell = sell; // Yesterday's sell becomes tomorrow's prev_sell
            buy = next_buy;
            sell = next_sell;
        }
        
        return sell;
    } 
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> prices1 = {1, 2, 3, 0, 2};
    cout << "Test 1: " << sol.maxProfit(prices1) << endl; // Expected: 3
    
    // Test case 2
    vector<int> prices2 = {1};
    cout << "Test 2: " << sol.maxProfit(prices2) << endl; // Expected: 0
    
    // Test case 3
    vector<int> prices3 = {1, 2, 4};
    cout << "Test 3: " << sol.maxProfit(prices3) << endl; // Expected: 3
    
    return 0;
}
