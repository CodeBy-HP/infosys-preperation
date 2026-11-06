#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class StockIV {
public:
    // Approach: Space-Optimized DP - O(N * K) Time, O(K) Space
    static int maxProfit(int k, const std::vector<int>& prices) {
        int n = prices.size();
        if (n <= 1 || k == 0) return 0;

        // If k >= n / 2, equivalent to infinite transactions (Stock II)
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1]) {
                    profit += (prices[i] - prices[i - 1]);
                }
            }
            return profit;
        }

        std::vector<std::vector<int>> after(2, std::vector<int>(k + 1, 0));
        std::vector<std::vector<int>> curr(2, std::vector<int>(k + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int buy = 0; buy <= 1; ++buy) {
                for (int cap = 1; cap <= k; ++cap) {
                    if (buy == 1) {
                        curr[buy][cap] = std::max(-prices[i] + after[0][cap], after[1][cap]);
                    } else {
                        curr[buy][cap] = std::max(prices[i] + after[1][cap - 1], after[0][cap]);
                    }
                }
            }
            after = curr;
        }
        return after[1][k];
    }
};

int main() {
    std::vector<int> p1 = {2, 4, 1};
    assert(StockIV::maxProfit(2, p1) == 2);

    std::vector<int> p2 = {3, 2, 6, 5, 0, 3};
    assert(StockIV::maxProfit(2, p2) == 7);

    std::cout << "All Best Time to Buy and Sell Stock IV tests passed successfully!\n";
    return 0;
}

