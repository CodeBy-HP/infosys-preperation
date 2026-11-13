#include <iostream>
#include <vector>
#include <cassert>

/**
 * Check If Array Pairs Are Divisible by K (LeetCode 1497)
 * Validates frequency symmetry: count[0] even, count[k/2] even, count[r] == count[k-r].
 * Time Complexity: O(N + K)
 * Space Complexity: O(K)
 */

class Solution {
public:
    bool canArrange(const std::vector<int>& arr, int k) {
        std::vector<int> freq(k, 0);

        for (int x : arr) {
            int rem = ((x % k) + k) % k;
            freq[rem]++;
        }

        // Remainder 0 elements must pair amongst themselves
        if (freq[0] % 2 != 0) {
            return false;
        }

        // Check complementary pairs
        for (int r = 1; r <= k / 2; ++r) {
            if (r == k - r) {
                // If k is even and r = k / 2
                if (freq[r] % 2 != 0) {
                    return false;
                }
            } else {
                if (freq[r] != freq[k - r]) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution solver;

    // Test 1: [1,2,3,4,5,10,6,7,8,9], k = 5 -> true
    assert(solver.canArrange({1, 2, 3, 4, 5, 10, 6, 7, 8, 9}, 5) == true);

    // Test 2: [1,2,3,4,5,6], k = 7 -> true
    assert(solver.canArrange({1, 2, 3, 4, 5, 6}, 7) == true);

    // Test 3: [1,2,3,4,5,6], k = 10 -> false
    assert(solver.canArrange({1, 2, 3, 4, 5, 6}, 10) == false);

    // Test 4: Negative numbers: [-1, 1, -2, 2, -3, 3, -4, 4], k = 3 -> true
    assert(solver.canArrange({-1, 1, -2, 2, -3, 3, -4, 4}, 3) == true);

    std::cout << "All Check Array Pairs Divisible by K tests passed successfully!" << std::endl;
    return 0;
}

