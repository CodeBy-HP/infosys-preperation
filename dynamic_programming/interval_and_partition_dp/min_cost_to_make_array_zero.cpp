#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

/**
 * Minimum Cost to Make Array Zero (Divide & Conquer / Cartesian Tree DP)
 * 
 * Problem:
 * Transform array A to all zeros using:
 * - Op 1: Subarray decrement by 1 (cost X)
 * - Op 2: Point reset to 0 (cost Y)
 * 
 * Time Complexity: O(N log N) average, O(N^2) worst case
 * Space Complexity: O(N) recursion stack
 */

class Solution {
private:
    long long solve(int l, int r, long long base, long long X, long long Y, const std::vector<long long>& A) {
        if (l > r) return 0;

        long long length = r - l + 1;
        long long option_all_resets = length * Y;

        // Find the minimum value in A[l...r]
        long long min_val = A[l];
        for (int i = l + 1; i <= r; ++i) {
            if (A[i] < min_val) {
                min_val = A[i];
            }
        }

        // Cost of reducing baseline to min_val using Operation 1
        long long cost_op1 = (min_val - base) * X;

        // Recursively conquer subsegments separated by min_val
        int i = l;
        while (i <= r) {
            if (A[i] > min_val) {
                int j = i;
                while (j <= r && A[j] > min_val) {
                    j++;
                }
                cost_op1 += solve(i, j - 1, min_val, X, Y, A);
                i = j;
            } else {
                i++;
            }
        }

        return std::min(option_all_resets, cost_op1);
    }

public:
    long long minCostToMakeArrayZero(const std::vector<long long>& A, long long X, long long Y) {
        int n = static_cast<int>(A.size());
        if (n == 0) return 0;
        return solve(0, n - 1, 0, X, Y, A);
    }
};

int main() {
    Solution solver;

    // Test 1: Subarray decrement is cheaper
    {
        std::vector<long long> A = {1, 2, 3, 2, 1};
        long long X = 2, Y = 3;
        long long ans = solver.minCostToMakeArrayZero(A, X, Y);
        std::cout << "Test 1: Expected = 6, Actual = " << ans << std::endl;
        assert(ans == 6);
    }

    // Test 2: Point resets are cheaper
    {
        std::vector<long long> A = {10, 10, 10};
        long long X = 5, Y = 2;
        long long ans = solver.minCostToMakeArrayZero(A, X, Y);
        std::cout << "Test 2: Expected = 6, Actual = " << ans << std::endl;
        assert(ans == 6);
    }

    // Test 3: Single element
    {
        std::vector<long long> A = {5};
        long long X = 2, Y = 7;
        // Op 1: 5 * 2 = 10, Op 2: 7 -> min is 7
        long long ans = solver.minCostToMakeArrayZero(A, X, Y);
        std::cout << "Test 3: Expected = 7, Actual = " << ans << std::endl;
        assert(ans == 7);
    }

    std::cout << "All Minimum Cost to Make Array Zero test cases passed successfully!" << std::endl;
    return 0;
}

