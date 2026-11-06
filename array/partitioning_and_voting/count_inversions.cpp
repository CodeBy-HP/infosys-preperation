#include <iostream>
#include <vector>
#include <cassert>

/**
 * Count Inversions in an Array
 * Brute Force O(N^2) vs Modified Merge Sort O(N log N).
 */

class Solution {
private:
    long long mergeAndCount(std::vector<int>& arr, int l, int mid, int r) {
        std::vector<int> temp;
        temp.reserve(r - l + 1);

        int i = l;
        int j = mid + 1;
        long long inv_count = 0;

        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                // arr[i] > arr[j] implies all elements from i to mid are > arr[j]
                inv_count += (mid - i + 1);
                temp.push_back(arr[j++]);
            }
        }

        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= r) temp.push_back(arr[j++]);

        for (int k = l; k <= r; ++k) {
            arr[k] = temp[k - l];
        }

        return inv_count;
    }

    long long mergeSortAndCount(std::vector<int>& arr, int l, int r) {
        long long count = 0;
        if (l < r) {
            int mid = l + (r - l) / 2;
            count += mergeSortAndCount(arr, l, mid);
            count += mergeSortAndCount(arr, mid + 1, r);
            count += mergeAndCount(arr, l, mid, r);
        }
        return count;
    }

public:
    // Approach 1: Brute Force - O(N^2) Time, O(1) Space
    long long countInversionsBrute(const std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        long long count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] > nums[j]) {
                    count++;
                }
            }
        }
        return count;
    }

    // Approach 2: Optimal Merge Sort - O(N log N) Time, O(N) Space
    long long countInversionsOptimal(std::vector<int> nums) {
        return mergeSortAndCount(nums, 0, static_cast<int>(nums.size()) - 1);
    }
};

int main() {
    Solution solver;

    std::vector<int> nums1 = {2, 4, 1, 3, 5};
    assert(solver.countInversionsBrute(nums1) == 3);
    assert(solver.countInversionsOptimal(nums1) == 3);

    std::vector<int> nums2 = {5, 4, 3, 2, 1};
    assert(solver.countInversionsBrute(nums2) == 10);
    assert(solver.countInversionsOptimal(nums2) == 10);

    std::vector<int> nums3 = {1, 2, 3, 4, 5};
    assert(solver.countInversionsOptimal(nums3) == 0);

    std::cout << "All Count Inversions tests passed successfully!" << std::endl;
    return 0;
}

