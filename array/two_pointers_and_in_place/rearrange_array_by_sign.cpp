#include <iostream>
#include <vector>
#include <cassert>

/**
 * Rearrange Array Elements by Sign (LeetCode 2149)
 * Two Passes (Separate Buffers) vs Single Pass (Dual Index Pointers).
 */

class Solution {
public:
    // Approach 1: Two Buffer Vectors - O(N) Time, O(N) Auxiliary Space
    std::vector<int> rearrangeArrayBrute(const std::vector<int>& nums) {
        std::vector<int> pos, neg;
        for (int x : nums) {
            if (x > 0) pos.push_back(x);
            else neg.push_back(x);
        }

        std::vector<int> res(nums.size());
        for (size_t i = 0; i < pos.size(); ++i) {
            res[2 * i] = pos[i];
            res[2 * i + 1] = neg[i];
        }
        return res;
    }

    // Approach 2: Optimal Single Pass Dual Pointers - O(N) Time, O(1) Auxiliary Space
    std::vector<int> rearrangeArrayOptimal(const std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        std::vector<int> res(n);
        int pos_idx = 0;
        int neg_idx = 1;

        for (int x : nums) {
            if (x > 0) {
                res[pos_idx] = x;
                pos_idx += 2;
            } else {
                res[neg_idx] = x;
                neg_idx += 2;
            }
        }

        return res;
    }
};

int main() {
    Solution solver;

    std::vector<int> nums1 = {3, 1, -2, -5, 2, -4};
    std::vector<int> expected1 = {3, -2, 1, -5, 2, -4};

    assert(solver.rearrangeArrayBrute(nums1) == expected1);
    assert(solver.rearrangeArrayOptimal(nums1) == expected1);

    std::vector<int> nums2 = {-1, 1};
    std::vector<int> expected2 = {1, -1};
    assert(solver.rearrangeArrayOptimal(nums2) == expected2);

    std::cout << "All Rearrange Array Elements by Sign tests passed successfully!" << std::endl;
    return 0;
}

