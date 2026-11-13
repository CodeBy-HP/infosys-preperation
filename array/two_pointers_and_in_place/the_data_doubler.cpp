#include <iostream>
#include <vector>
#include <cassert>

/**
 * The Data Doubler Algorithm (LeetCode 1929: Concatenation of Array)
 * 
 * Problem:
 * Given an array of size n, return an array of size 2n where elements
 * are repeated twice back-to-back using circular modulo traversal.
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

class Solution {
public:
    std::vector<int> getConcatenation(const std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        std::vector<int> result(2 * n);

        for (int i = 0; i < 2 * n; ++i) {
            result[i] = nums[i % n];
        }

        return result;
    }
};

int main() {
    Solution solver;

    // Test 1: [1, 2, 1]
    {
        std::vector<int> nums = {1, 2, 1};
        std::vector<int> expected = {1, 2, 1, 1, 2, 1};
        std::vector<int> actual = solver.getConcatenation(nums);
        assert(actual == expected);
    }

    // Test 2: [1, 3, 2, 1]
    {
        std::vector<int> nums = {1, 3, 2, 1};
        std::vector<int> expected = {1, 3, 2, 1, 1, 3, 2, 1};
        std::vector<int> actual = solver.getConcatenation(nums);
        assert(actual == expected);
    }

    std::cout << "All Data Doubler test cases passed successfully!" << std::endl;
    return 0;
}

