#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class StockII {
public:
    // Approach 1: State Machine Tabulation - O(N) Time, O(1) Space
    static int maxProfitDP(const std::vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        int aheadNotBuy = 0;
        int aheadBuy = 0;

        for (int i = n - 1; i >= 0; --i) {
            int currBuy = std::max(-prices[i] + aheadNotBuy, aheadBuy);
            int currNotBuy = std::max(prices[i] + aheadBuy, aheadNotBuy);
            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }
        return aheadBuy;
    }

    // Approach 2: Greedy Peak-Valley - O(N) Time, O(1) Space
    static int maxProfitGreedy(const std::vector<int>& prices) {
        int profit = 0;
        for (size_t i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                profit += (prices[i] - prices[i - 1]);
            }
        }
        return profit;
    }
};

int main() {
    std::vector<int> p1 = {7, 1, 5, 3, 6, 4};
    assert(StockII::maxProfitDP(p1) == 7);
    assert(StockII::maxProfitGreedy(p1) == 7);

    std::vector<int> p2 = {1, 2, 3, 4, 5};
    assert(StockII::maxProfitDP(p2) == 4);
    assert(StockII::maxProfitGreedy(p2) == 4);

    std::vector<int> p3 = {7, 6, 4, 3, 1};
    assert(StockII::maxProfitDP(p3) == 0);
    assert(StockII::maxProfitGreedy(p3) == 0);

    std::cout << "All Best Time to Buy and Sell Stock II tests passed successfully!\n";
    return 0;
}

