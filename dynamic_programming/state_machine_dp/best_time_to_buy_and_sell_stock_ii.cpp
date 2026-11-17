// Best Time to Buy and Sell Stock II (LeetCode 122)
// Unlimited transactions allowed

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Recursive DP with Memoization
    // State: dp[i][buy] = max profit from day i onwards
    // buy = 1: can buy, buy = 0: holding stock (must sell)
    
    int n;
    vector<int> prices;
    int dp[30005][2];
    
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
            // Holding stock: either sell today or skip
            int sellToday = prices[idx] + solve(idx + 1, 1);
            int skip = solve(idx + 1, 0);
            profit = max(sellToday, skip);
        }
        
        return dp[idx][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        this->prices = prices;
        this->n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 1); // Start from day 0, can buy
    }
    
    // Approach 2: Greedy (Sum all positive slopes)
    int maxProfitGreedy(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Test 1: " << sol.maxProfit(prices1) << endl; // Expected: 7
    
    // Test case 2
    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << "Test 2: " << sol.maxProfit(prices2) << endl; // Expected: 4
    
    // Test case 3
    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << "Test 3: " << sol.maxProfit(prices3) << endl; // Expected: 0
    
    return 0;
}
