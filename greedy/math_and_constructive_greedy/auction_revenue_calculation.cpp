#include <iostream>
#include <vector>
#include <cassert>

/**
 * Auction Revenue Calculation (Greedy State-Tracking Simulation)
 * 
 * Problem:
 * N items auctioned sequentially in strict order 0 to N - 1.
 * M bidders, each with a budget B_j and bid matrix Bid[j][i].
 * A bid is valid if Bid[j][i] <= B_j.
 * The highest valid bidder wins the item; ties broken by smaller bidder index.
 * Each bidder can win at most one item. Once won, they are excluded from future items.
 * Calculate total revenue across all N items.
 * 
 * Time Complexity: O(N * M)
 * Space Complexity: O(M) for tracking used bidders
 */

class Solution {
public:
    long long calculateAuctionRevenue(int n, int m,
                                      const std::vector<long long>& budgets,
                                      const std::vector<std::vector<long long>>& bids) {
        // used[j] = true if bidder j has already won an item
        std::vector<bool> used(m, false);
        long long total_revenue = 0;

        for (int i = 0; i < n; ++i) {
            long long max_valid_bid = -1;
            int winning_bidder = -1;

            for (int j = 0; j < m; ++j) {
                // Bidder must not have won already, and bid must be <= budget
                if (!used[j] && bids[j][i] <= budgets[j]) {
                    // Strict greater ensures lower bidder index wins ties
                    if (bids[j][i] > max_valid_bid) {
                        max_valid_bid = bids[j][i];
                        winning_bidder = j;
                    }
                }
            }

            // Award item to the winning bidder
            if (winning_bidder != -1) {
                total_revenue += max_valid_bid;
                used[winning_bidder] = true;
            }
        }

        return total_revenue;
    }
};

int main() {
    Solution solver;

    // Test 1: Example 1 from problem statement
    {
        int n = 2, m = 3;
        std::vector<long long> budgets = {100, 200, 150};
        std::vector<std::vector<long long>> bids = {
            {80, 90},    // Bidder 0
            {120, 150},  // Bidder 1
            {70, 160}    // Bidder 2
        };
        long long ans = solver.calculateAuctionRevenue(n, m, budgets, bids);
        std::cout << "Test 1: Expected = 210, Actual = " << ans << std::endl;
        assert(ans == 210);
    }

    // Test 2: Tie breaking by lower bidder index
    {
        int n = 1, m = 2;
        std::vector<long long> budgets = {100, 100};
        std::vector<std::vector<long long>> bids = {
            {50},  // Bidder 0
            {50}   // Bidder 1
        };
        long long ans = solver.calculateAuctionRevenue(n, m, budgets, bids);
        std::cout << "Test 2: Expected = 50, Actual = " << ans << std::endl;
        assert(ans == 50);
    }

    // Test 3: All bids exceed budget
    {
        int n = 2, m = 1;
        std::vector<long long> budgets = {50};
        std::vector<std::vector<long long>> bids = {
            {60, 70}
        };
        long long ans = solver.calculateAuctionRevenue(n, m, budgets, bids);
        std::cout << "Test 3: Expected = 0, Actual = " << ans << std::endl;
        assert(ans == 0);
    }

    // Test 4: More items than bidders
    {
        int n = 3, m = 2;
        std::vector<long long> budgets = {100, 100};
        std::vector<std::vector<long long>> bids = {
            {10, 20, 30},
            {15, 25, 35}
        };
        // Item 0: Bidder 1 wins with 15 (Bidder 1 removed)
        // Item 1: Bidder 0 wins with 20 (Bidder 0 removed)
        // Item 2: No available bidders, unsold (0)
        // Total = 15 + 20 = 35
        long long ans = solver.calculateAuctionRevenue(n, m, budgets, bids);
        std::cout << "Test 4: Expected = 35, Actual = " << ans << std::endl;
        assert(ans == 35);
    }

    std::cout << "All Auction Revenue Calculation test cases passed successfully!" << std::endl;
    return 0;
}

