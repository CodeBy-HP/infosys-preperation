#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class StockIII {
public:
    // Approach 1: 3D Tabulation Space-Optimized to 2D - O(N) Time, O(1) Space
    static int maxProfitDP(const std::vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        // after[buy][cap]
        std::vector<std::vector<int>> after(2, std::vector<int>(3, 0));
        std::vector<std::vector<int>> curr(2, std::vector<int>(3, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int buy = 0; buy <= 1; ++buy) {
                for (int cap = 1; cap <= 2; ++cap) {
                    if (buy == 1) {
                        curr[buy][cap] = std::max(-prices[i] + after[0][cap], after[1][cap]);
                    } else {
                        curr[buy][cap] = std::max(prices[i] + after[1][cap - 1], after[0][cap]);
                    }
                }
            }
            after = curr;
        }
        return after[1][2];
    }

    // Approach 2: 4-Variable State Optimization - O(N) Time, O(1) Space
    static int maxProfit4States(const std::vector<int>& prices) {
        int buy1 = -1e9, sell1 = 0;
        int buy2 = -1e9, sell2 = 0;

        for (int price : prices) {
            buy1 = std::max(buy1, -price);
            sell1 = std::max(sell1, buy1 + price);
            buy2 = std::max(buy2, sell1 - price);
            sell2 = std::max(sell2, buy2 + price);
        }
        return sell2;
    }
};

int main() {
    std::vector<int> p1 = {3, 3, 5, 0, 0, 3, 1, 4};
    assert(StockIII::maxProfitDP(p1) == 6);
    assert(StockIII::maxProfit4States(p1) == 6);

    std::vector<int> p2 = {1, 2, 3, 4, 5};
    assert(StockIII::maxProfitDP(p2) == 4);
    assert(StockIII::maxProfit4States(p2) == 4);

    std::vector<int> p3 = {7, 6, 4, 3, 1};
    assert(StockIII::maxProfitDP(p3) == 0);
    assert(StockIII::maxProfit4States(p3) == 0);

    std::cout << "All Best Time to Buy and Sell Stock III tests passed successfully!\n";
    return 0;
}

