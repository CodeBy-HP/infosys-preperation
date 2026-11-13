#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

class NumberOfEnclaves {
public:
    static int numEnclaves(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        std::queue<std::pair<int, int>> q;

        // Push all boundary land cells
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (r == 0 || r == m - 1 || c == 0 || c == n - 1) {
                    if (grid[r][c] == 1) {
                        grid[r][c] = 0; // mark visited/sunk
                        q.push({r, c});
                    }
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Multi-source BFS sinking all boundary-connected land
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 0;
                    q.push({nr, nc});
                }
            }
        }

        // Count isolated interior enclaves
        int enclaves = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    ++enclaves;
                }
            }
        }
        return enclaves;
    }
};

int main() {
    std::vector<std::vector<int>> g1 = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };
    assert(NumberOfEnclaves::numEnclaves(g1) == 3);

    std::vector<std::vector<int>> g2 = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
    };
    assert(NumberOfEnclaves::numEnclaves(g2) == 0);

    std::cout << "All Number of Enclaves tests passed successfully!\n";
    return 0;
}

