#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class StockI {
public:
    // Approach 1: Brute Force - O(N^2) Time, O(1) Space
    static int maxProfitBrute(const std::vector<int>& prices) {
        int maxProfit = 0;
        int n = prices.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                maxProfit = std::max(maxProfit, prices[j] - prices[i]);
            }
        }
        return maxProfit;
    }

    // Approach 2: Single-pass Prefix Minimum - O(N) Time, O(1) Space
    static int maxProfitOptimized(const std::vector<int>& prices) {
        int minPrice = 1e9;
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = std::min(minPrice, price);
            maxProfit = std::max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
};

int main() {
    std::vector<int> p1 = {7, 1, 5, 3, 6, 4};
    assert(StockI::maxProfitBrute(p1) == 5);
    assert(StockI::maxProfitOptimized(p1) == 5);

    std::vector<int> p2 = {7, 6, 4, 3, 1};
    assert(StockI::maxProfitBrute(p2) == 0);
    assert(StockI::maxProfitOptimized(p2) == 0);

    std::cout << "All Best Time to Buy and Sell Stock I tests passed successfully!\n";
    return 0;
}

