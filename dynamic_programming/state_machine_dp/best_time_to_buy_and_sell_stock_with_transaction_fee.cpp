// Best Time to Buy and Sell Stock with Transaction Fee (LeetCode 714)
// Unlimited transactions with a transaction fee

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Recursive DP with Memoization
    // State: dp[i][buy] = max profit from day i onwards
    // buy = 1: can buy, buy = 0: holding stock (must sell)
    
    int n, fee;
    vector<int> prices;
    int dp[50005][2];
    
    int solve(int idx, int buy) {
        // Base case: reached end of array
        if (idx >= n) return 0;
        
        // Memoization check
        if (dp[idx][buy] != -1) return dp[idx][buy];
        
        int profit = 0;
        
        if (buy) {
            // Can buy: either buy today or skip
            int buyToday = -prices[idx] + solve(idx + 1, 0);
            int skip = solve(idx + 1, 1);
            profit = max(buyToday, skip);
        } else {
            // Holding stock: either sell today (pay fee) or skip
            int sellToday = prices[idx] - fee + solve(idx + 1, 1);
            int skip = solve(idx + 1, 0);
            profit = max(sellToday, skip);
        }
        
        return dp[idx][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        this->prices = prices;
        this->n = prices.size();
        this->fee = fee;
        memset(dp, -1, sizeof(dp));
        return solve(0, 1); // Start from day 0, can buy
    }
    
    // Approach 2: State Machine with 2 variables (O(1) space)
    int maxProfitOptimized(vector<int>& prices, int fee) {
        int buy = INT_MIN;
        int sell = 0;
        
        for (int price : prices) {
            buy = max(buy, sell - price);
            sell = max(sell, buy + price - fee);
        }
        
        return sell;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> prices1 = {1, 3, 2, 8, 4, 9};
    cout << "Test 1: " << sol.maxProfit(prices1, 2) << endl; // Expected: 8
    
    // Test case 2
    vector<int> prices2 = {1, 3, 7, 5, 10, 3};
    cout << "Test 2: " << sol.maxProfit(prices2, 3) << endl; // Expected: 6
    
    return 0;
}
