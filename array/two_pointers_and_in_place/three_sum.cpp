#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ThreeSum {
public:
    // =========================================================================
    // 1. Sort + Two-Pointer Search with Duplicate Skipping
    // Time Complexity: O(N^2)
    // Space Complexity: O(1) auxiliary space (excluding result)
    // =========================================================================
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 3) return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            // If the smallest number of the triplet is > 0, sum cannot be 0
            if (nums[i] > 0) break;

            // Skip duplicate pivot values
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate left values
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // Skip duplicate right values
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return result;
    }
};

int main() {
    ThreeSum solver;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> triplets = solver.threeSum(nums);

    cout << "3Sum Triplets:\n";
    for (const auto& t : triplets) {
        cout << "  [ " << t[0] << " " << t[1] << " " << t[2] << " ]\n";
    }

    return 0;
}
