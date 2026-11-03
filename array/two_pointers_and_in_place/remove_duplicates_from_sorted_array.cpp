#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        // writer tracks the position to insert the next unique element
        int writer = 1;

        // reader scans the array from index 1
        for (size_t reader = 1; reader < nums.size(); ++reader) {
            if (nums[reader] != nums[reader - 1]) {
                nums[writer] = nums[reader];
                writer++;
            }
        }

        return writer;
    }
};

int main() {
    Solution sol;

    std::vector<int> nums1 = {1, 1, 2};
    int k1 = sol.removeDuplicates(nums1);
    std::cout << "Test 1 [1,1,2]: k = " << k1 << ", array = [ ";
    for (int i = 0; i < k1; ++i) std::cout << nums1[i] << " ";
    std::cout << "]\n(Expected: k = 2, array = [ 1 2 ])\n";

    std::vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = sol.removeDuplicates(nums2);
    std::cout << "Test 2 [0,0,1,1,1,2,2,3,3,4]: k = " << k2 << ", array = [ ";
    for (int i = 0; i < k2; ++i) std::cout << nums2[i] << " ";
    std::cout << "]\n(Expected: k = 5, array = [ 0 1 2 3 4 ])\n";

    return 0;
}

