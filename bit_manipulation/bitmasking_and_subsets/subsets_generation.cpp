#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(const std::vector<int>& nums) {
        int n = nums.size();
        int total = 1 << n; // 2^n
        std::vector<std::vector<int>> result;
        result.reserve(total);

        for (int mask = 0; mask < total; ++mask) {
            std::vector<int> sub;
            for (int j = 0; j < n; ++j) {
                if ((mask >> j) & 1) {
                    sub.push_back(nums[j]);
                }
            }
            result.push_back(sub);
        }

        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> subs = sol.subsets(nums);

    std::cout << "All Subsets of [1, 2, 3] (" << subs.size() << " subsets):\n";
    for (const auto& s : subs) {
        std::cout << "[ ";
        for (int x : s) std::cout << x << " ";
        std::cout << "]\n";
    }

    return 0;
}
