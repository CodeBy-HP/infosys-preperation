// Best Time to Buy and Sell Stock III (LeetCode 123)
// At most 2 transactions allowed

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Recursive DP with Memoization (3D State)
    // State: dp[i][buy][cap] = max profit from day i onwards
    // buy = 1: can buy, buy = 0: holding stock (must sell)
    // cap = remaining transaction capacity (0, 1, or 2)
    
    int n;
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
    
    int maxProfit(vector<int>& prices) {
        this->prices = prices;
        this->n = prices.size();
        memo.clear();
        return solve(0, 1, 2); // Start from day 0, can buy, 2 transactions allowed
    }
    
    // Approach 2: State Machine with 4 variables (O(1) space)
    // The Relay Race
    int maxProfitOptimized(vector<int>& prices) {
        int firstBuy = INT_MIN, firstSell = 0;
        int secondBuy = INT_MIN, secondSell = 0;
        
        for (int price : prices) {
            firstBuy = max(firstBuy, -price);
            firstSell = max(firstSell, firstBuy + price);
            secondBuy = max(secondBuy, firstSell - price);
            secondSell = max(secondSell, secondBuy + price);
        }
        
        return secondSell;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> prices1 = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << "Test 1: " << sol.maxProfit(prices1) << endl; // Expected: 6
    
    // Test case 2
    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << "Test 2: " << sol.maxProfit(prices2) << endl; // Expected: 4
    
    // Test case 3
    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << "Test 3: " << sol.maxProfit(prices3) << endl; // Expected: 0
    
    return 0;
}
