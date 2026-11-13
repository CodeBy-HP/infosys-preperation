#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>

/**
 * Merge Two Sorted Arrays Without Extra Space
 * Formulation 1: LeetCode 88 (Three Pointers from Back)
 * Formulation 2: Disjoint Arrays (The Gap Method / Shell Sort)
 */

class Solution {
public:
    // Formulation 1: LeetCode 88 - O(M + N) Time, O(1) Space
    void mergeLeetCode88(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;

        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p--] = nums1[p1--];
            } else {
                nums1[p--] = nums2[p2--];
            }
        }

        // Copy remaining elements from nums2 if any
        while (p2 >= 0) {
            nums1[p--] = nums2[p2--];
        }
    }

    // Formulation 2: The Gap Method for Disjoint Arrays - O((M + N) log(M + N)) Time, O(1) Space
    void mergeGapMethod(std::vector<int>& a, std::vector<int>& b) {
        int m = static_cast<int>(a.size());
        int n = static_cast<int>(b.size());
        int len = m + n;
        int gap = (len / 2) + (len % 2);

        auto swapIfGreater = [&](std::vector<int>& arr1, std::vector<int>& arr2, int idx1, int idx2) {
            if (arr1[idx1] > arr2[idx2]) {
                std::swap(arr1[idx1], arr2[idx2]);
            }
        };

        while (gap > 0) {
            int left = 0;
            int right = left + gap;

            while (right < len) {
                // Case 1: left in a, right in a
                if (left < m && right < m) {
                    swapIfGreater(a, a, left, right);
                }
                // Case 2: left in a, right in b
                else if (left < m && right >= m) {
                    swapIfGreater(a, b, left, right - m);
                }
                // Case 3: left in b, right in b
                else {
                    swapIfGreater(b, b, left - m, right - m);
                }
                left++;
                right++;
            }

            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
    }
};

int main() {
    Solution solver;

    // Test 1: LeetCode 88
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    solver.mergeLeetCode88(nums1, 3, nums2, 3);
    std::vector<int> expected1 = {1, 2, 2, 3, 5, 6};
    assert(nums1 == expected1);

    // Test 2: The Gap Method
    std::vector<int> a = {1, 4, 8, 10};
    std::vector<int> b = {2, 3, 9};
    solver.mergeGapMethod(a, b);
    std::vector<int> expected_a = {1, 2, 3, 4};
    std::vector<int> expected_b = {8, 9, 10};
    assert(a == expected_a);
    assert(b == expected_b);

    std::cout << "All Merge Sorted Arrays Without Extra Space tests passed successfully!" << std::endl;
    return 0;
}

