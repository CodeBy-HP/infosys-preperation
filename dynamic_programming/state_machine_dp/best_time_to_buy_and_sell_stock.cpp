// Best Time to Buy and Sell Stock (LeetCode 121)
// At most one transaction allowed

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Recursive DP with Memoization
    // State: dp[i][buy] = max profit from day i onwards
    // buy = 1: can buy, buy = 0: holding stock (must sell)
    
    int n;
    vector<int> prices;
    int dp[100005][2];
    
    int solve(int idx, int buy, int transactionDone) {
        // Base case: reached end of array
        if (idx >= n) return 0;
        
        // If transaction already completed, no more profit possible
        if (transactionDone) return 0;
        
        // Memoization check
        if (dp[idx][buy] != -1) return dp[idx][buy];
        
        int profit = 0;
        
        if (buy) {
            // Can buy: either buy today or skip
            int buyToday = -prices[idx] + solve(idx + 1, 0, transactionDone);
            int skip = solve(idx + 1, 1, transactionDone);
            profit = max(buyToday, skip);
        } else {
            // Holding stock: either sell today or skip
            int sellToday = prices[idx] + solve(idx + 1, 1, 1); // Transaction completes
            int skip = solve(idx + 1, 0, transactionDone);
            profit = max(sellToday, skip);
        }
        
        return dp[idx][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        this->prices = prices;
        this->n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 0); // Start from day 0, can buy, transaction not done
    }
    
    // Approach 2: Optimized Single Pass (O(1) space)
    int maxProfitOptimized(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }
        
        return maxProfit;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Test 1: " << sol.maxProfit(prices1) << endl; // Expected: 5
    
    // Test case 2
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Test 2: " << sol.maxProfit(prices2) << endl; // Expected: 0
    
    // Test case 3
    vector<int> prices3 = {2, 4, 1};
    cout << "Test 3: " << sol.maxProfit(prices3) << endl; // Expected: 2
    
    return 0;
}
