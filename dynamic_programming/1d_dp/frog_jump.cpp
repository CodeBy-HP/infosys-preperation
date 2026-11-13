#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>

class FrogJump {
public:
    // Approach 1: Memoized Recursion - O(N) Time, O(N) Space
    static int solveMemo(int i, const std::vector<int>& height, std::vector<int>& memo) {
        if (i == 0) return 0;
        if (memo[i] != -1) return memo[i];

        int jumpOne = solveMemo(i - 1, height, memo) + std::abs(height[i] - height[i - 1]);
        int jumpTwo = 1e9;
        if (i > 1) {
            jumpTwo = solveMemo(i - 2, height, memo) + std::abs(height[i] - height[i - 2]);
        }
        return memo[i] = std::min(jumpOne, jumpTwo);
    }

    static int minEnergyMemo(const std::vector<int>& height) {
        int n = height.size();
        if (n <= 1) return 0;
        std::vector<int> memo(n, -1);
        return solveMemo(n - 1, height, memo);
    }

    // Approach 2: Space-Optimized Tabulation - O(N) Time, O(1) Space
    static int minEnergyOptimized(const std::vector<int>& height) {
        int n = height.size();
        if (n <= 1) return 0;

        int prev2 = 0;
        int prev1 = std::abs(height[1] - height[0]);

        for (int i = 2; i < n; ++i) {
            int jumpOne = prev1 + std::abs(height[i] - height[i - 1]);
            int jumpTwo = prev2 + std::abs(height[i] - height[i - 2]);
            int curr = std::min(jumpOne, jumpTwo);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main() {
    std::vector<int> h1 = {10, 20, 30, 10};
    assert(FrogJump::minEnergyMemo(h1) == 20);
    assert(FrogJump::minEnergyOptimized(h1) == 20);

    std::vector<int> h2 = {10, 50, 10};
    assert(FrogJump::minEnergyMemo(h2) == 0);
    assert(FrogJump::minEnergyOptimized(h2) == 0);

    std::vector<int> h3 = {30, 10, 60, 10, 60, 50};
    assert(FrogJump::minEnergyMemo(h3) == 40);
    assert(FrogJump::minEnergyOptimized(h3) == 40);

    std::cout << "All Frog Jump tests passed successfully!\n";
    return 0;
}

