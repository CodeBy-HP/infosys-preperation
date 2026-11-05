#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

/**
 * Continuous Subarray Sum (LeetCode 523)
 * Finds if there exists a subarray of length >= 2 with sum % k == 0.
 * Time Complexity: O(N)
 * Space Complexity: O(min(N, K))
 */

class Solution {
public:
    bool checkSubarraySum(const std::vector<int>& nums, int k) {
        std::unordered_map<int, int> rem_to_index;
        rem_to_index[0] = -1; // Base case for prefix sum starting from index 0

        int prefix_sum = 0;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            prefix_sum += nums[i];
            int rem = ((prefix_sum % k) + k) % k;

            if (rem_to_index.count(rem)) {
                if (i - rem_to_index[rem] >= 2) {
                    return true;
                }
            } else {
                rem_to_index[rem] = i; // Record earliest occurrence only
            }
        }

        return false;
    }
};

int main() {
    Solution solver;

    // Test 1: [23, 2, 4, 6, 7], k = 6 -> true ([2, 4] sum = 6)
    assert(solver.checkSubarraySum({23, 2, 4, 6, 7}, 6) == true);

    // Test 2: [23, 2, 6, 4, 7], k = 6 -> true
    assert(solver.checkSubarraySum({23, 2, 6, 4, 7}, 6) == true);

    // Test 3: [23, 2, 6, 4, 7], k = 13 -> false
    assert(solver.checkSubarraySum({23, 2, 6, 4, 7}, 13) == false);

    // Test 4: [0, 0], k = 1 -> true (sum 0 % 1 == 0, length 2)
    assert(solver.checkSubarraySum({0, 0}, 1) == true);

    std::cout << "All Continuous Subarray Sum tests passed successfully!" << std::endl;
    return 0;
}

