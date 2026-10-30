#include <iostream>
#include <vector>

class Solution {
public:
    int totalHammingDistance(const std::vector<int>& nums) {
        int totalDistance = 0;
        int n = nums.size();

        // Examine each of the 32 bit positions independently
        for (int b = 0; b < 32; ++b) {
            int onesCount = 0;
            for (int num : nums) {
                if ((num >> b) & 1) {
                    onesCount++;
                }
            }
            int zeroesCount = n - onesCount;
            totalDistance += onesCount * zeroesCount;
        }

        return totalDistance;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {4, 14, 2};
    std::cout << "Total Hamming Distance [4, 14, 2]: " 
              << sol.totalHammingDistance(nums) << " (Expected: 6)\n";

    return 0;
}
