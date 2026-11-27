#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

class Solution {
public:
    // Variant A: Pick at most one element per (index % k) residue class
    long long maxSumByIndexModK(const vector<int>& nums, int k, bool allowSkipAllInClass = true) {
        int n = nums.size();
        int buckets = min(n, k);
        vector<long long> best(buckets, LLONG_MIN);

        for (int i = 0; i < n; i++) {
            int r = i % k;
            best[r] = max(best[r], static_cast<long long>(nums[i]));
        }

        long long total = 0;
        for (int r = 0; r < buckets; r++) {
            if (allowSkipAllInClass) {
                if (best[r] > 0) total += best[r];
            } else {
                total += best[r];
            }
        }
        return total;
    }

    // Variant B: Subsequence trigger doubling every k-th item's successor
    long long maxScoreTriggerSubsequence(const vector<int>& nums, int k) {
        // State 0..k-1: normal count mod k; state k: just hit k-th trigger (next earns 2x)
        const long long NEG_INF = -1e18;
        vector<long long> dp(k + 1, NEG_INF);
        dp[0] = 0;

        for (long long val : nums) {
            vector<long long> nextDp = dp;
            // Transition from state 0
            if (k == 1) {
                nextDp[1] = max(nextDp[1], dp[0] + val);
            } else {
                nextDp[1] = max(nextDp[1], dp[0] + val);
            }
            for (int r = 1; r < k; r++) {
                if (dp[r] == NEG_INF) continue;
                int nxt = (r + 1 == k) ? k : (r + 1);
                nextDp[nxt] = max(nextDp[nxt], dp[r] + val);
            }
            if (dp[k] != NEG_INF) {
                int nxt = (k == 1) ? k : 1;
                nextDp[nxt] = max(nextDp[nxt], dp[k] + 2 * val);
            }
            dp.swap(nextDp);
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution sol;
    assert(sol.maxSumByIndexModK({4, -1, 7, 2, 9, 3}, 3) == 20);
    assert(sol.maxSumByIndexModK({-5, -2, -8, -1}, 2, true) == 0);
    assert(sol.maxScoreTriggerSubsequence({10, 20, 30, 40}, 2) == 130);
    cout << "41_max_sum_selection_index_mod_k passed all tests!\n";
    return 0;
}
