#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

/**
 * Minimum Swaps to Segregate Even and Odd Numbers
 * 
 * Problem:
 * Find minimum adjacent swaps to place all evens on one side and all odds
 * on the other (evaluating both evens first vs odds first).
 * 
 * Inversion counting with parity complementarity:
 * swaps(even_first) + swaps(odd_first) = E * O
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

class Solution {
public:
    long long minSwapsEvenOdd(const std::vector<int>& nums) {
        long long odds_before = 0;
        long long swaps_even_first = 0;
        long long total_evens = 0;
        long long total_odds = 0;

        for (int x : nums) {
            if (std::abs(x) % 2 == 0) {
                swaps_even_first += odds_before;
                total_evens++;
            } else {
                odds_before++;
                total_odds++;
            }
        }

        long long swaps_odd_first = (total_evens * total_odds) - swaps_even_first;
        return std::min(swaps_even_first, swaps_odd_first);
    }
};

int main() {
    Solution solver;

    // Test 1: [1, 2, 3, 4] -> min is 1 (odd first: [1, 3, 2, 4])
    {
        std::vector<int> nums = {1, 2, 3, 4};
        long long ans = solver.minSwapsEvenOdd(nums);
        std::cout << "Test 1: Expected = 1, Actual = " << ans << std::endl;
        assert(ans == 1);
    }

    // Test 2: Already segregated
    {
        std::vector<int> nums = {2, 4, 6, 1, 3};
        long long ans = solver.minSwapsEvenOdd(nums);
        std::cout << "Test 2: Expected = 0, Actual = " << ans << std::endl;
        assert(ans == 0);
    }

    // Test 3: Alternating parity [2, 1, 4, 3, 6, 5]
    {
        std::vector<int> nums = {2, 1, 4, 3, 6, 5};
        // Evens: 3, Odds: 3.
        // Even first: 0 + 1 + 2 = 3 swaps -> [2, 4, 6, 1, 3, 5]
        // Odd first: 9 - 3 = 6 swaps.
        // Min = 3
        long long ans = solver.minSwapsEvenOdd(nums);
        std::cout << "Test 3: Expected = 3, Actual = " << ans << std::endl;
        assert(ans == 3);
    }

    // Test 4: All evens or all odds
    {
        std::vector<int> nums = {2, 4, 6, 8};
        long long ans = solver.minSwapsEvenOdd(nums);
        std::cout << "Test 4: Expected = 0, Actual = " << ans << std::endl;
        assert(ans == 0);
    }

    std::cout << "All Minimum Swaps Even/Odd test cases passed successfully!" << std::endl;
    return 0;
}

