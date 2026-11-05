#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>

/**
 * Make Sum Divisible by P (LeetCode 1590)
 * Finds the shortest subarray whose removal makes the total sum % p == 0.
 * Time Complexity: O(N)
 * Space Complexity: O(min(N, p))
 */

class Solution {
public:
    int minSubarray(const std::vector<int>& nums, int p) {
        long long total_sum = 0;
        for (int x : nums) {
            total_sum += x;
        }

        int target_rem = total_sum % p;
        if (target_rem == 0) return 0; // Already divisible

        std::unordered_map<int, int> last_seen;
        last_seen[0] = -1; // Empty prefix before index 0

        long long current_prefix = 0;
        int min_len = static_cast<int>(nums.size());

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            current_prefix += nums[i];
            int cur_rem = current_prefix % p;

            // Target prefix remainder that would yield subarray sum % p == target_rem
            int needed = ((cur_rem - target_rem) % p + p) % p;

            if (last_seen.count(needed)) {
                min_len = std::min(min_len, i - last_seen[needed]);
            }

            // Always update to the most recent index to minimize future window lengths
            last_seen[cur_rem] = i;
        }

        return min_len < static_cast<int>(nums.size()) ? min_len : -1;
    }
};

int main() {
    Solution solver;

    // Test 1: [3, 1, 4, 2], p = 6 -> 1 (remove [4])
    assert(solver.minSubarray({3, 1, 4, 2}, 6) == 1);

    // Test 2: [6, 3, 5, 2], p = 9 -> 2 (remove [5, 2])
    assert(solver.minSubarray({6, 3, 5, 2}, 9) == 2);

    // Test 3: [1, 2, 3], p = 3 -> 0 (already divisible)
    assert(solver.minSubarray({1, 2, 3}, 3) == 0);

    // Test 4: Cannot remove entire array
    assert(solver.minSubarray({1, 2, 3}, 7) == -1);

    std::cout << "All Make Sum Divisible by P tests passed successfully!" << std::endl;
    return 0;
}

