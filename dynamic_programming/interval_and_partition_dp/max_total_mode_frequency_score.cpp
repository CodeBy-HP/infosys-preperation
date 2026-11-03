#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>

/**
 * Maximum Total Mode Frequency Score (Partition DP)
 * 
 * Problem:
 * Given an array of size n and an integer k, partition the array into exactly k
 * non-empty contiguous groups. The score of a group is its mode frequency
 * (the frequency of the most frequent element in that subarray).
 * Maximize the sum of scores across all k groups.
 * 
 * Time Complexity: O(n^2 + k * n^2) = O(k * n^2)
 * Space Complexity: O(n^2) for the mode frequency table + O(n) for DP state
 */

class Solution {
public:
    int maxTotalModeFrequencyScore(const std::vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        if (k <= 0 || k > n) {
            return 0;
        }

        // Step 1: Precompute M[i][j] = mode frequency of nums[i...j]
        // M is an n x n table.
        std::vector<std::vector<int>> M(n, std::vector<int>(n, 0));

        // Coordinate compression or hash map for frequencies
        for (int i = 0; i < n; ++i) {
            std::unordered_map<int, int> freq;
            int max_f = 0;
            for (int j = i; j < n; ++j) {
                int count = ++freq[nums[j]];
                if (count > max_f) {
                    max_f = count;
                }
                M[i][j] = max_f;
            }
        }

        // Step 2: DP formulation
        // dp[j] represents the maximum score partitioning nums[0...j-1] into g groups
        const int NEG_INF = -1e9;
        std::vector<int> prev_dp(n + 1, NEG_INF);
        prev_dp[0] = 0;

        // Base case: g = 1
        for (int j = 1; j <= n; ++j) {
            prev_dp[j] = M[0][j - 1];
        }

        // Transitions for g = 2 to k
        for (int g = 2; g <= k; ++g) {
            std::vector<int> curr_dp(n + 1, NEG_INF);
            for (int j = g; j <= n; ++j) {
                int best = NEG_INF;
                for (int p = g - 1; p < j; ++p) {
                    if (prev_dp[p] != NEG_INF) {
                        int candidate = prev_dp[p] + M[p][j - 1];
                        if (candidate > best) {
                            best = candidate;
                        }
                    }
                }
                curr_dp[j] = best;
            }
            prev_dp = std::move(curr_dp);
        }

        return prev_dp[n];
    }
};

int main() {
    Solution solver;

    // Test Case 1: Standard sample
    {
        std::vector<int> nums = {1, 2, 1, 2, 3, 3, 3};
        int k = 3;
        int ans = solver.maxTotalModeFrequencyScore(nums, k);
        std::cout << "Test 1: Expected = 6, Actual = " << ans << std::endl;
        assert(ans == 6);
    }

    // Test Case 2: All identical elements
    {
        std::vector<int> nums = {4, 4, 4, 4};
        int k = 2;
        int ans = solver.maxTotalModeFrequencyScore(nums, k);
        std::cout << "Test 2: Expected = 4, Actual = " << ans << std::endl;
        assert(ans == 4);
    }

    // Test Case 3: k == n (each element in its own partition)
    {
        std::vector<int> nums = {10, 20, 30, 40};
        int k = 4;
        int ans = solver.maxTotalModeFrequencyScore(nums, k);
        std::cout << "Test 3: Expected = 4, Actual = " << ans << std::endl;
        assert(ans == 4);
    }

    // Test Case 4: k == 1 (entire array mode frequency)
    {
        std::vector<int> nums = {5, 5, 2, 5, 3, 2};
        int k = 1;
        int ans = solver.maxTotalModeFrequencyScore(nums, k);
        std::cout << "Test 4: Expected = 3, Actual = " << ans << std::endl;
        assert(ans == 3);
    }

    // Test Case 5: Distinct clusters
    {
        std::vector<int> nums = {1, 1, 1, 2, 2, 3, 3, 3, 3};
        int k = 3;
        int ans = solver.maxTotalModeFrequencyScore(nums, k);
        std::cout << "Test 5: Expected = 9, Actual = " << ans << std::endl;
        assert(ans == 9);
    }

    std::cout << "All Maximum Total Mode Frequency Score test cases passed successfully!" << std::endl;
    return 0;
}

