#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    long long maxTriggerSubsequenceScore(const std::vector<int>& nums, int k) {
        int n = nums.size();
        const long long NEG_INF = -1e18;

        // dp[state]:
        // state 0: 0 items picked
        // state 1..(k-1): count % k == state
        // state k: count > 0 and count % k == 0 (checkpoint hit!)
        std::vector<long long> dp(k + 1, NEG_INF);
        dp[0] = 0; // 0 earnings with 0 items

        for (int x : nums) {
            std::vector<long long> next_dp = dp; // Choice 1: Skip x

            // Choice 2: Pick x from each reachable state
            for (int s = 0; s <= k; ++s) {
                if (dp[s] == NEG_INF) continue;

                // Determine multiplier and next state
                long long gain = 0;
                int next_s = 0;

                if (s == 0) {
                    // First item picked: multiplier 1
                    gain = x;
                    next_s = (k == 1 ? 1 : 1);
                } else if (s == k) {
                    // Item immediately after checkpoint: multiplier 2!
                    gain = 2LL * x;
                    next_s = (k == 1 ? 1 : 1);
                } else {
                    // Normal item: multiplier 1
                    gain = x;
                    if (s + 1 == k) {
                        next_s = k; // Checkpoint reached
                    } else {
                        next_s = s + 1;
                    }
                }

                next_dp[next_s] = std::max(next_dp[next_s], dp[s] + gain);
            }

            dp = std::move(next_dp);
        }

        // The answer can be any non-empty subsequence (or 0 if all items are negative)
        long long maxScore = 0;
        for (int s = 0; s <= k; ++s) {
            maxScore = std::max(maxScore, dp[s]);
        }

        return maxScore;
    }
};

int main() {
    Solution sol;

    // Test 1: [10, 20, 30, 40], k = 2
    // Pick 10 (normal), 20 (checkpoint), 30 (double=60), 40 (checkpoint)
    // 10 + 20 + 60 + 40 = 130
    std::vector<int> nums1 = {10, 20, 30, 40};
    int k1 = 2;
    std::cout << "Test 1 [10, 20, 30, 40], k=2: " 
              << sol.maxTriggerSubsequenceScore(nums1, k1) << " (Expected: 130)\n";

    // Test 2: Negative elements that shouldn't be picked unless beneficial
    std::vector<int> nums2 = {-5, 10, -2, 50};
    int k2 = 2;
    std::cout << "Test 2 [-5, 10, -2, 50], k=2: " 
              << sol.maxTriggerSubsequenceScore(nums2, k2) << " (Expected: 108)\n";
    // Explanation: Pick 10 (1st, 10), -2 (2nd, checkpoint, -2), 50 (3rd, double=100) -> 108!

    // Test 3: k = 1 (every item is a checkpoint, so item 2, 3, 4 are all doubles!)
    std::vector<int> nums3 = {5, 10, 15};
    int k3 = 1;
    std::cout << "Test 3 [5, 10, 15], k=1:      " 
              << sol.maxTriggerSubsequenceScore(nums3, k3) << " (Expected: 55)\n";
    // 5 + 2*10 + 2*15 = 5 + 20 + 30 = 55

    return 0;
}

