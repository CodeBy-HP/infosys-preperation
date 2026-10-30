#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:
    bool canSplit(const std::vector<int>& nums, long long maxSum, int k) {
        int subarrays = 1;
        long long currentSum = 0;

        for (int num : nums) {
            if (currentSum + num > maxSum) {
                subarrays++;
                currentSum = 0;
            }
            currentSum += num;
        }

        return subarrays <= k;
    }

public:
    int splitArray(const std::vector<int>& nums, int k) {
        long long left = *std::max_element(nums.begin(), nums.end());
        long long right = std::accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canSplit(nums, mid, k)) {
                ans = mid;
                right = mid - 1; // Try minimizing largest sum
            } else {
                left = mid + 1;
            }
        }

        return (int)ans;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    std::cout << "splitArray([7,2,5,10,8], k=2): " << sol.splitArray(nums, k) 
              << " (Expected: 18)\n";

    return 0;
}
