#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    // Variant A: At most 1 transaction with dynamic settlement delay (prices[i] % 10 + 1)
    long long maxProfitSingleWithSettlementDelay(const vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        vector<int> suffixMax(n, 0);
        suffixMax[n - 1] = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(prices[i], suffixMax[i + 1]);
        }

        long long maxProfit = 0;
        for (int i = 0; i < n; i++) {
            int delay = (prices[i] % 10) + 1;
            int earliestSell = i + delay;
            if (earliestSell < n) {
                maxProfit = max(maxProfit, static_cast<long long>(suffixMax[earliestSell]) - prices[i]);
            }
        }
        return maxProfit;
    }

    // Variant B: Unlimited transactions with dynamic settlement delay in strict O(N) time
    long long maxProfitUnlimitedWithSettlementDelay(const vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        vector<long long> dp(n + 1, 0);             // max profit starting at day i (not holding)
        vector<long long> suffixBestSell(n + 1, 0); // max_{j >= k} (prices[j] + dp[j + 1])

        suffixBestSell[n - 1] = prices[n - 1];
        dp[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--) {
            int delay = (prices[i] % 10) + 1;
            int earliestSell = i + delay;

            long long buyProfit = 0;
            if (earliestSell < n) {
                buyProfit = -static_cast<long long>(prices[i]) + suffixBestSell[earliestSell];
            }

            dp[i] = max(dp[i + 1], buyProfit);
            suffixBestSell[i] = max(suffixBestSell[i + 1], static_cast<long long>(prices[i]) + dp[i + 1]);
        }
        return dp[0];
    }
};

int main() {
    Solution sol;
    assert(sol.maxProfitSingleWithSettlementDelay({11, 20, 15, 18}) == 7);
    assert(sol.maxProfitUnlimitedWithSettlementDelay({1, 5, 2, 8}) == 7);
    cout << "52_stock_settlement_delay passed all tests!\n";
    return 0;
}
