// Best Time to Buy and Sell Stock IV (LeetCode 188)
// At most k transactions allowed

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Recursive DP with Memoization (3D State)
    // State: dp[i][buy][cap] = max profit from day i onwards
    // buy = 1: can buy, buy = 0: holding stock (must sell)
    // cap = remaining transaction capacity
    
    int n, K;
    vector<int> prices;
    map<tuple<int, int, int>, int> memo;
    
    int solve(int idx, int buy, int cap) {
        // Base case: reached end of array or no capacity left
        if (idx >= n || cap == 0) return 0;
        
        // Memoization check
        auto key = make_tuple(idx, buy, cap);
        if (memo.find(key) != memo.end()) return memo[key];
        
        int profit = 0;
        
        if (buy) {
            // Can buy: either buy today or skip
            int buyToday = -prices[idx] + solve(idx + 1, 0, cap);
            int skip = solve(idx + 1, 1, cap);
            profit = max(buyToday, skip);
        } else {
            // Holding stock: either sell today (complete transaction) or skip
            int sellToday = prices[idx] + solve(idx + 1, 1, cap - 1);
            int skip = solve(idx + 1, 0, cap);
            profit = max(sellToday, skip);
        }
        
        return memo[key] = profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        this->prices = prices;
        this->n = prices.size();
        this->K = k;
        
        // Optimization: if k >= n/2, we can do unlimited transactions
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; i++) {
                profit += max(0, prices[i] - prices[i - 1]);
            }
            return profit;
        }
        
        memo.clear();
        return solve(0, 1, k); // Start from day 0, can buy, k transactions allowed
    }
    
    // Approach 2: Space-optimized with 1D arrays
    int maxProfitOptimized(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;
        
        // If k >= n/2, unlimited transactions
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; i++) {
                profit += max(0, prices[i] - prices[i - 1]);
            }
            return profit;
        }
        
        // buy[t] = max profit after at most t buys
        // sell[t] = max profit after at most t complete transactions
        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);
        
        for (int price : prices) {
            for (int t = 1; t <= k; t++) {
                buy[t] = max(buy[t], sell[t - 1] - price);
                sell[t] = max(sell[t], buy[t] + price);
            }
        }
        
        return sell[k];
    }


    // int maxProfit(int k, vector<int>& prices) {
    //     if (prices.empty() || k == 0) return 0;
        
    //     // Two arrays to track the 'k' parallel timelines
    //     vector<int> buy(k, INT_MIN);
    //     vector<int> sell(k, 0);
        
    //     for (int price : prices) {
    //         for (int i = 0; i < k; i++) {
    //             // For the very first buy, your previous balance is $0.
    //             // For all other buys, your previous balance is the profit from the previous sell.
    //             int prev_profit = (i == 0) ? 0 : sell[i - 1];
                
    //             // The exact same FSM transitions
    //             buy[i] = max(buy[i], prev_profit - price);
    //             sell[i] = max(sell[i], buy[i] + price);
    //         }
    //     }
        
    //     // The last state in the sell array holds our maximum possible money
    //     return sell[k - 1];
    // }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> prices1 = {2, 4, 1};
    cout << "Test 1: " << sol.maxProfit(2, prices1) << endl; // Expected: 2
    
    // Test case 2
    vector<int> prices2 = {3, 2, 6, 5, 0, 3};
    cout << "Test 2: " << sol.maxProfit(2, prices2) << endl; // Expected: 7
    
    // Test case 3
    vector<int> prices3 = {1, 2, 3, 4, 5};
    cout << "Test 3: " << sol.maxProfit(2, prices3) << endl; // Expected: 4
    
    return 0;
}
