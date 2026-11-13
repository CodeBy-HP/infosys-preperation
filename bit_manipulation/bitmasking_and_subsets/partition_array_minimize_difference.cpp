#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <climits>

class Solution {
private:

    

    std::vector<std::vector<int>> generateSubsetSums(const std::vector<int>& arr) {
        int n = arr.size();
        std::vector<std::vector<int>> sumsByCount(n + 1);

        int totalSubsets = 1 << n;
        for (int mask = 0; mask < totalSubsets; ++mask) {
            int sum = 0;
            int count = 0;
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    sum += arr[i];
                    count++;
                }
            }
            sumsByCount[count].push_back(sum);
        }
        return sumsByCount;
    }

public:
    int minimumDifference(std::vector<int>& nums) {
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        int twoN = nums.size();
        int n = twoN / 2;

        std::vector<int> leftHalf(nums.begin(), nums.begin() + n);
        std::vector<int> rightHalf(nums.begin() + n, nums.end());

        auto leftSums = generateSubsetSums(leftHalf);
        auto rightSums = generateSubsetSums(rightHalf);

        int minDiff = INT_MAX;

        // Sort all vectors in rightSums for binary search
        for (int k = 0; k <= n; ++k) {
            std::sort(rightSums[k].begin(), rightSums[k].end());
        }

        // Target for chosen subset sum is totalSum / 2
        for (int k = 0; k <= n; ++k) {
            int rightNeedCount = n - k;
            const auto& rList = rightSums[rightNeedCount];

            for (int sL : leftSums[k]) {
                int idealRight = (totalSum / 2) - sL;

                // Find element closest to idealRight
                auto it = std::lower_bound(rList.begin(), rList.end(), idealRight);

                if (it != rList.end()) {
                    int chosenSum = sL + *it;
                    minDiff = std::min(minDiff, std::abs(totalSum - 2 * chosenSum));
                }
                if (it != rList.begin()) {
                    auto prevIt = std::prev(it);
                    int chosenSum = sL + *prevIt;
                    minDiff = std::min(minDiff, std::abs(totalSum - 2 * chosenSum));
                }
            }
        }

        return minDiff;
    }

    int minDifferenceBruteForce(std::vector<int>& nums) {
        int n = nums.size() / 2;
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        int minDiff = INT_MAX;

        // DFS Helper
        // idx: The current number we are looking at
        // count: How many numbers we have put in Bucket A so far
        // currentSum: The running sum of Bucket A
        auto dfs = [&](auto& self, int idx, int count, int currentSum) -> void {
            // Success: We filled Bucket A with exactly 'n' elements!
            if (count == n) {
                int bucket2Sum = totalSum - currentSum;
                minDiff = std::min(minDiff, std::abs(currentSum - bucket2Sum));
                return;
            }

            // Pruning 1: Ran out of elements
            if (idx == nums.size()) return;

            // Pruning 2: Math Check - Do we have enough elements left to finish?
            // If we need 3 more items, but only 2 items are left in the array, stop early.
            if (nums.size() - idx < n - count) return;

            // Symmetry Breaker (Your nCr / 2 logic!)
            // We force the very first element (idx == 0) to ALWAYS go into Bucket A.
            // This prevents the DFS from generating identical mirror-image buckets.
            if (idx == 0) {
                self(self, idx + 1, count + 1, currentSum + nums[idx]);
                return;
            }

            // Choice 1: Put nums[idx] into Bucket A
            self(self, idx + 1, count + 1, currentSum + nums[idx]);

            // Choice 2: Put nums[idx] into Bucket B (Exclude from A)
            self(self, idx + 1, count, currentSum);
        };

        // Start DFS at index 0, with 0 items picked, and sum 0.
        dfs(dfs, 0, 0, 0);

        return minDiff;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {3, 9, 7, 3};
    std::cout << "Test 1 [3,9,7,3]: " << sol.minimumDifference(nums1) << " (Expected: 2)\n";

    std::vector<int> nums2 = {-36, 36};
    std::cout << "Test 2 [-36,36]:  " << sol.minimumDifference(nums2) << " (Expected: 72)\n";

    std::vector<int> nums3 = {2, -1, 0, 4, -2, -9};
    std::cout << "Test 3:           " << sol.minimumDifference(nums3) << " (Expected: 0)\n";

    return 0;
}
