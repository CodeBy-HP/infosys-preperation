#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                long long rem = static_cast<long long>(target) - nums[i] - nums[j];
                int left = j + 1, right = n - 1;

                while (left < right) {
                    long long twoSum = static_cast<long long>(nums[left]) + nums[right];
                    if (twoSum < rem) {
                        left++;
                    } else if (twoSum > rem) {
                        right--;
                    } else {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    auto r1 = sol.fourSum({1, 0, -1, 0, -2, 2}, 0);
    assert(r1.size() == 3);
    auto r2 = sol.fourSum({2, 2, 2, 2, 2}, 8);
    assert(r2.size() == 1);
    cout << "51_four_sum passed all tests!\n";
    return 0;
}
