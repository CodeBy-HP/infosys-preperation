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
    long long solve(int L, int R, long long current_floor, vector<int>& A, long long X, long long Y) {
        // Base Case: There are no buildings left in this block
        if (L > R) return 0;
        
        // 1. Find the shortest skyscraper in the current block
        int min_idx = L;
        for (int i = L + 1; i <= R; i++) {
            if (A[i] < A[min_idx]) {
                min_idx = i;
            }
        }
        
        // --- OPTION A: Vertical Wrecking Ball ---
        // Destroy every building in this block individually
        long long wrecking_ball_cost = (R - L + 1) * Y;
        
        // --- OPTION B: Horizontal Laser ---
        // Fire the laser until the shortest building is destroyed.
        // We only need to shoot from our current_floor up to the top of the shortest building.
        long long laser_shots = A[min_idx] - current_floor;
        long long laser_cost = laser_shots * X;
        
        // The shortest building is now gone! Split the city into Left and Right subproblems.
        // The new 'current_floor' for the subproblems is the height of the building we just destroyed.
        long long left_city = solve(L, min_idx - 1, A[min_idx], A, X, Y);
        long long right_city = solve(min_idx + 1, R, A[min_idx], A, X, Y);
        
        long long total_laser_cost = laser_cost + left_city + right_city;
        
        // Return the absolute cheapest demolition method for this block
        return min(wrecking_ball_cost, total_laser_cost);
    }

public:
    long long minCostToZero(vector<int>& A, long long X, long long Y) {
        int n = A.size();
        // Start with the full city (0 to n-1), standing on the ground (floor 0)
        return solve(0, n - 1, 0, A, X, Y);
    }
};

int main() {
    Solution solver;

    // Test 1: Subarray decrement is cheaper
    {
        std::vector<long long> A = {1, 2, 3, 2, 1};
        long long X = 2, Y = 3;
        long long ans = solver.minCostToZero(A, X, Y);
        std::cout << "Test 1: Expected = 6, Actual = " << ans << std::endl;
        assert(ans == 6);
    }

    // Test 2: Point resets are cheaper
    {
        std::vector<long long> A = {10, 10, 10};
        long long X = 5, Y = 2;
        long long ans = solver.minCostToZero(A, X, Y);
        std::cout << "Test 2: Expected = 6, Actual = " << ans << std::endl;
        assert(ans == 6);
    }

    // Test 3: Single element
    {
        std::vector<long long> A = {5};
        long long X = 2, Y = 7;
        // Op 1: 5 * 2 = 10, Op 2: 7 -> min is 7
        long long ans = solver.minCostToZero(A, X, Y);
        std::cout << "Test 3: Expected = 7, Actual = " << ans << std::endl;
        assert(ans == 7);
    }

    std::cout << "All Minimum Cost to Make Array Zero test cases passed successfully!" << std::endl;
    return 0;
}

