#include <iostream>
#include <vector>
#include <cassert>

/**
 * Number of Ways to Reorder Array to Get Same BST (LeetCode 1569)
 * Subtree interleaving combinations using Pascal's triangle table modulo 10^9 + 7.
 * Time Complexity: O(N^2)
 * Space Complexity: O(N^2)
 */

class Solution {
private:
    const long long MOD = 1e9 + 7;
    std::vector<std::vector<long long>> C;

    void precomputeComb(int n) {
        C.assign(n + 1, std::vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            C[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }
    }

    long long dfs(const std::vector<int>& nums) {
        if (nums.size() <= 2) {
            return 1;
        }

        int root = nums[0];
        std::vector<int> left, right;

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        int L = static_cast<int>(left.size());
        int R = static_cast<int>(right.size());

        long long ways_interleave = C[L + R][L];
        long long ways_left = dfs(left);
        long long ways_right = dfs(right);

        return (ways_interleave * ways_left % MOD) * ways_right % MOD;
    }

public:
    int numOfWays(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        precomputeComb(n);
        // Exclude the original ordering (-1)
        long long total = dfs(nums);
        return static_cast<int>((total - 1 + MOD) % MOD);
    }
};

int main() {
    Solution solver;

    // Test 1: [2, 1, 3] -> 1
    std::vector<int> nums1 = {2, 1, 3};
    assert(solver.numOfWays(nums1) == 1);

    // Test 2: [3, 4, 5, 1, 2] -> 5
    std::vector<int> nums2 = {3, 4, 5, 1, 2};
    assert(solver.numOfWays(nums2) == 5);

    // Test 3: [1, 2, 3] -> 0 (only 1 valid BST ordering, which is original)
    std::vector<int> nums3 = {1, 2, 3};
    assert(solver.numOfWays(nums3) == 0);

    std::cout << "All Number of Ways to Reorder for Same BST tests passed successfully!" << std::endl;
    return 0;
}

