#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class CherryPickupII {
public:
    // Approach 1: Memoization - O(R * C^2) Time, O(R * C^2) Space
    static int solveMemo(int i, int j1, int j2, int r, int c, 
                          const std::vector<std::vector<int>>& grid,
                          std::vector<std::vector<std::vector<int>>>& memo) {
        if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c) return -1e8;

        if (i == r - 1) {
            return (j1 == j2) ? grid[i][j1] : (grid[i][j1] + grid[i][j2]);
        }

        if (memo[i][j1][j2] != -1) return memo[i][j1][j2];

        int maxCherries = -1e8;
        for (int dj1 = -1; dj1 <= 1; ++dj1) {
            for (int dj2 = -1; dj2 <= 1; ++dj2) {
                int value = (j1 == j2) ? grid[i][j1] : (grid[i][j1] + grid[i][j2]);
                value += solveMemo(i + 1, j1 + dj1, j2 + dj2, r, c, grid, memo);
                maxCherries = std::max(maxCherries, value);
            }
        }
        return memo[i][j1][j2] = maxCherries;
    }

    static int cherryPickupMemo(const std::vector<std::vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        std::vector<std::vector<std::vector<int>>> memo(
            r, std::vector<std::vector<int>>(c, std::vector<int>(c, -1)));
        return solveMemo(0, 0, c - 1, r, c, grid, memo);
    }

    // Approach 2: Space-Optimized Tabulation - O(R * C^2) Time, O(C^2) Space
    static int cherryPickupOptimized(const std::vector<std::vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        std::vector<std::vector<int>> front(c, std::vector<int>(c, 0));

        // Base case: row r - 1
        for (int j1 = 0; j1 < c; ++j1) {
            for (int j2 = 0; j2 < c; ++j2) {
                front[j1][j2] = (j1 == j2) ? grid[r - 1][j1] : (grid[r - 1][j1] + grid[r - 1][j2]);
            }
        }

        // Bottom-up iteration
        for (int i = r - 2; i >= 0; --i) {
            std::vector<std::vector<int>> curr(c, std::vector<int>(c, 0));
            for (int j1 = 0; j1 < c; ++j1) {
                for (int j2 = 0; j2 < c; ++j2) {
                    int maxCherries = -1e8;
                    for (int dj1 = -1; dj1 <= 1; ++dj1) {
                        for (int dj2 = -1; dj2 <= 1; ++dj2) {
                            int nj1 = j1 + dj1;
                            int nj2 = j2 + dj2;
                            if (nj1 >= 0 && nj1 < c && nj2 >= 0 && nj2 < c) {
                                int val = (j1 == j2) ? grid[i][j1] : (grid[i][j1] + grid[i][j2]);
                                val += front[nj1][nj2];
                                maxCherries = std::max(maxCherries, val);
                            }
                        }
                    }
                    curr[j1][j2] = maxCherries;
                }
            }
            front = curr;
        }
        return front[0][c - 1];
    }
};

int main() {
    std::vector<std::vector<int>> g1 = {
        {3, 1, 1},
        {2, 5, 1},
        {1, 5, 5},
        {2, 1, 1}
    };
    assert(CherryPickupII::cherryPickupMemo(g1) == 24);
    assert(CherryPickupII::cherryPickupOptimized(g1) == 24);

    std::vector<std::vector<int>> g2 = {
        {1, 0, 0, 0, 0, 0, 1},
        {2, 0, 0, 0, 0, 3, 0},
        {2, 0, 9, 0, 0, 0, 0},
        {0, 3, 0, 5, 4, 0, 0},
        {1, 0, 2, 3, 0, 0, 6}
    };
    assert(CherryPickupII::cherryPickupMemo(g2) == 28);
    assert(CherryPickupII::cherryPickupOptimized(g2) == 28);

    std::cout << "All Cherry Pickup II tests passed successfully!\n";
    return 0;
}

