#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>



class Solution {
public:
// Approach 1
    vector<vector<int>> fourSum_hash_set(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> result;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                unordered_set<long long> seen;

                for (int k = j + 1; k < n; k++) {

                    long long required = (long long)target
                                    - nums[i] - nums[j] - nums[k];

                    if (seen.count(required)) {
                        vector<int> quad = {
                            nums[i], nums[j], nums[k], (int)required
                        };

                        sort(quad.begin(), quad.end());
                        result.insert(quad);
                    }

                    seen.insert(nums[k]);
                }
            }
        }

        return vector<vector<int>>(result.begin(), result.end());
    }

    /**
 * 4Sum (LeetCode 18)
 * Sort + Fixed Double Pivot + Two Pointers.
 * Time Complexity: O(N^3)
 * Space Complexity: O(1) auxiliary space (excluding result)
 */

    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        int n = static_cast<int>(nums.size());
        std::vector<std::vector<int>> result;
        if (n < 4) return result;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicates for the 1st element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicates for the 2nd element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int k = j + 1;
                int l = n - 1;

                while (k < l) {
                    long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});

                        // Skip duplicates for the 3rd and 4th elements
                        while (k < l && nums[k] == nums[k + 1]) k++;
                        while (k < l && nums[l] == nums[l - 1]) l--;

                        k++;
                        l--;
                    } else if (sum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    Solution solver;

    std::vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    std::vector<std::vector<int>> expected1 = {
        {-2, -1, 1, 2},
        {-2, 0, 0, 2},
        {-1, 0, 0, 1}
    };
    std::vector<std::vector<int>> actual1 = solver.fourSum(nums1, 0);
    assert(actual1 == expected1);

    std::vector<int> nums2 = {2, 2, 2, 2, 2};
    std::vector<std::vector<int>> expected2 = {
        {2, 2, 2, 2}
    };
    assert(solver.fourSum(nums2, 8) == expected2);

    std::cout << "All 4Sum tests passed successfully!" << std::endl;
    return 0;
}

