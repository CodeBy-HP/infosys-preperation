#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class StockWithFee {
public:
    // Approach: State Machine 2-Variable Optimization - O(N) Time, O(1) Space
    static int maxProfit(const std::vector<int>& prices, int fee) {
        int n = prices.size();
        if (n <= 1) return 0;

        int cash = 0;
        int hold = -prices[0];

        for (int i = 1; i < n; ++i) {
            cash = std::max(cash, hold + prices[i] - fee);
            hold = std::max(hold, cash - prices[i]);
        }
        return cash;
    }
};

int main() {
    std::vector<int> p1 = {1, 3, 2, 8, 4, 9};
    int fee1 = 2;
    assert(StockWithFee::maxProfit(p1, fee1) == 8);

    std::vector<int> p2 = {1, 3, 7, 5, 10, 3};
    int fee2 = 3;
    assert(StockWithFee::maxProfit(p2, fee2) == 6);

    std::cout << "All Best Time to Buy and Sell Stock with Transaction Fee tests passed successfully!\n";
    return 0;
}

