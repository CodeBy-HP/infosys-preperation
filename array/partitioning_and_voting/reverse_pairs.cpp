#include <iostream>
#include <vector>
#include <cassert>

/**
 * Reverse Pairs (LeetCode 493)
 * Count pairs where nums[i] > 2 * nums[j] (i < j) via Merge Sort.
 * Time Complexity: O(N log N)
 * Space Complexity: O(N)
 */

class Solution {
private:
    int countPairs(std::vector<int>& nums, int l, int mid, int r) {
        int count = 0;
        int right = mid + 1;

        for (int i = l; i <= mid; ++i) {
            while (right <= r && static_cast<long long>(nums[i]) > 2LL * nums[right]) {
                right++;
            }
            count += (right - (mid + 1));
        }

        return count;
    }

    void merge(std::vector<int>& nums, int l, int mid, int r) {
        std::vector<int> temp;
        temp.reserve(r - l + 1);

        int i = l, j = mid + 1;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }

        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= r) temp.push_back(nums[j++]);

        for (int k = l; k <= r; ++k) {
            nums[k] = temp[k - l];
        }
    }

    int mergeSortAndCount(std::vector<int>& nums, int l, int r) {
        if (l >= r) return 0;

        int mid = l + (r - l) / 2;
        int count = mergeSortAndCount(nums, l, mid);
        count += mergeSortAndCount(nums, mid + 1, r);

        // Pre-merge counting step
        count += countPairs(nums, l, mid, r);

        // Standard merge
        merge(nums, l, mid, r);

        return count;
    }

public:
    // Approach 1: Brute Force - O(N^2) Time, O(1) Space
    int reversePairsBrute(const std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (static_cast<long long>(nums[i]) > 2LL * nums[j]) {
                    count++;
                }
            }
        }
        return count;
    }

    // Approach 2: Optimal Merge Sort - O(N log N) Time, O(N) Space
    int reversePairsOptimal(std::vector<int> nums) {
        return mergeSortAndCount(nums, 0, static_cast<int>(nums.size()) - 1);
    }
};

int main() {
    Solution solver;

    std::vector<int> nums1 = {1, 3, 2, 3, 1};
    assert(solver.reversePairsBrute(nums1) == 2);
    assert(solver.reversePairsOptimal(nums1) == 2);

    std::vector<int> nums2 = {2, 4, 3, 5, 1};
    assert(solver.reversePairsBrute(nums2) == 3);
    assert(solver.reversePairsOptimal(nums2) == 3);

    std::cout << "All Reverse Pairs tests passed successfully!" << std::endl;
    return 0;
}

