#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> singleNumber(const std::vector<int>& nums) {
        // Step 1: XOR all numbers to get a ^ b
        long long xorAll = 0;
        for (int num : nums) {
            xorAll ^= num;
        }

        // Step 2: Find lowest set bit where a and b differ
        long long lowestBit = xorAll & (-xorAll);

        // Step 3: Divide numbers into two groups and XOR each
        int a = 0, b = 0;
        for (int num : nums) {
            if (num & lowestBit) {
                a ^= num;
            } else {
                b ^= num;
            }
        }

        return {a, b};
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 2, 1, 3, 2, 5};
    std::vector<int> res1 = sol.singleNumber(nums1);

    std::cout << "Test 1 [1, 2, 1, 3, 2, 5]: [ " << res1[0] << " " << res1[1] << " ]\n";
    std::cout << "(Expected: [ 3 5 ] in any order)\n";

    std::vector<int> nums2 = {-1, 0};
    std::vector<int> res2 = sol.singleNumber(nums2);
    std::cout << "Test 2 [-1, 0]:           [ " << res2[0] << " " << res2[1] << " ]\n";

    return 0;
}
