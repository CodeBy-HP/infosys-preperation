#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class NinjasTraining {
public:
    // Approach 1: Memoized Recursion - O(N) Time, O(N * 4) Space
    static int solveMemo(int day, int last, const std::vector<std::vector<int>>& points, std::vector<std::vector<int>>& memo) {
        if (day == 0) {
            int maxi = 0;
            for (int task = 0; task < 3; ++task) {
                if (task != last) {
                    maxi = std::max(maxi, points[0][task]);
                }
            }
            return maxi;
        }
        if (memo[day][last] != -1) return memo[day][last];

        int maxi = 0;
        for (int task = 0; task < 3; ++task) {
            if (task != last) {
                int pts = points[day][task] + solveMemo(day - 1, task, points, memo);
                maxi = std::max(maxi, pts);
            }
        }
        return memo[day][last] = maxi;
    }

    static int ninjaTrainingMemo(int n, const std::vector<std::vector<int>>& points) {
        std::vector<std::vector<int>> memo(n, std::vector<int>(4, -1));
        return solveMemo(n - 1, 3, points, memo);
    }

    // Approach 2: Space-Optimized Tabulation - O(N) Time, O(1) Space
    static int ninjaTrainingOptimized(int n, const std::vector<std::vector<int>>& points) {
        std::vector<int> prev(4, 0);

        prev[0] = std::max(points[0][1], points[0][2]);
        prev[1] = std::max(points[0][0], points[0][2]);
        prev[2] = std::max(points[0][0], points[0][1]);
        prev[3] = std::max({points[0][0], points[0][1], points[0][2]});

        for (int day = 1; day < n; ++day) {
            std::vector<int> curr(4, 0);
            for (int last = 0; last < 4; ++last) {
                int maxi = 0;
                for (int task = 0; task < 3; ++task) {
                    if (task != last) {
                        maxi = std::max(maxi, points[day][task] + prev[task]);
                    }
                }
                curr[last] = maxi;
            }
            prev = curr;
        }
        return prev[3];
    }
};

int main() {
    std::vector<std::vector<int>> points1 = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };
    assert(NinjasTraining::ninjaTrainingMemo(3, points1) == 210);
    assert(NinjasTraining::ninjaTrainingOptimized(3, points1) == 210);

    std::vector<std::vector<int>> points2 = {
        {1, 2, 5},
        {3, 1, 1},
        {3, 3, 3}
    };
    assert(NinjasTraining::ninjaTrainingMemo(3, points2) == 11);
    assert(NinjasTraining::ninjaTrainingOptimized(3, points2) == 11);

    std::cout << "All Ninja's Training tests passed successfully!\n";
    return 0;
}

