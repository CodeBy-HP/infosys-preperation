#include <iostream>
#include <vector>
#include <set>
#include <cassert>

class DistinctIslands {
public:
    static void dfs(int r, int c, int r0, int c0, std::vector<std::vector<int>>& grid,
                    std::vector<std::vector<bool>>& visited, std::vector<std::pair<int, int>>& shape) {
        int n = grid.size();
        int m = grid[0].size();
        visited[r][c] = true;
        shape.push_back({r - r0, c - c0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && !visited[nr][nc]) {
                dfs(nr, nc, r0, c0, grid, visited, shape);
            }
        }
    }

    static int countDistinctIslands(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
        std::set<std::vector<std::pair<int, int>>> uniqueShapes;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (grid[r][c] == 1 && !visited[r][c]) {
                    std::vector<std::pair<int, int>> shape;
                    dfs(r, c, r, c, grid, visited, shape);
                    uniqueShapes.insert(shape);
                }
            }
        }
        return uniqueShapes.size();
    }
};

int main() {
    std::vector<std::vector<int>> g1 = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}
    };
    assert(DistinctIslands::countDistinctIslands(g1) == 1); // identical 2x2 squares

    std::vector<std::vector<int>> g2 = {
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}
    };
    assert(DistinctIslands::countDistinctIslands(g2) == 3);

    std::cout << "All Number of Distinct Islands tests passed successfully!\n";
    return 0;
}

