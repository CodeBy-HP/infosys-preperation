#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

class Solution {
public:
    // Variant A: Stock Buy/Sell with 1-Day Cooldown (State Machine O(N), O(1))
    int maxProfitWithCooldown(const vector<int>& prices) {
        if (prices.empty()) return 0;
        int hold = -prices[0];
        int sold = 0;
        int rest = 0;

        for (size_t i = 1; i < prices.size(); i++) {
            int prevSold = sold;
            sold = hold + prices[i];
            hold = max(hold, rest - prices[i]);
            rest = max(rest, prevSold);
        }
        return max(sold, rest);
    }

    // Variant B: Longest Subsequence with Cooldown K (cannot pick within cooldown steps after picking)
    int maxLenSubsequenceWithCooldown(const vector<int>& nums, int k, int minGap) {
        int n = nums.size();
        if (n == 0) return 0;
        // dp[i] = max length ending at or before i where consecutive elements satisfy |nums[i] - nums[j]| <= minGap and j <= i - k - 1
        vector<int> dp(n, 1);
        int best = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i - k - 1; j++) {
                if (abs(nums[i] - nums[j]) <= minGap) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            best = max(best, dp[i]);
        }
        return best;
    }
};

int main() {
    Solution sol;
    assert(sol.maxProfitWithCooldown({1, 2, 3, 0, 2}) == 3);
    assert(sol.maxProfitWithCooldown({1}) == 0);
    assert(sol.maxLenSubsequenceWithCooldown({1, 3, 2, 3, 4}, 1, 2) == 3); // indices 0(1), 2(2), 4(4)
    cout << "12_max_length_subsequence_cooldown passed all tests!\n";
    return 0;
}
