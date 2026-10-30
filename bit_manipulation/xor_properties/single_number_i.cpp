#include <iostream>
#include <vector>

class Solution {
public:
    int singleNumber(const std::vector<int>& nums) {
        int xorSum = 0;
        for (int x : nums) {
            xorSum ^= x;
        }
        return xorSum;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {2, 2, 1};
    std::vector<int> nums2 = {4, 1, 2, 1, 2};

    std::cout << "Test 1 [2, 2, 1]:       " << sol.singleNumber(nums1) << " (Expected: 1)\n";
    std::cout << "Test 2 [4, 1, 2, 1, 2]: " << sol.singleNumber(nums2) << " (Expected: 4)\n";

    return 0;
}
