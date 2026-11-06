#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

class NumberOfIslands {
public:
    static void bfsSink(int r, int c, std::vector<std::vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        grid[r][c] = '0'; // Sink

        std::queue<std::pair<int, int>> q;
        q.push({r, c});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [currR, currC] = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int nr = currR + dr[d];
                int nc = currC + dc[d];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1') {
                    grid[nr][nc] = '0';
                    q.push({nr, nc});
                }
            }
        }
    }

    static int numIslands(std::vector<std::vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == '1') {
                    ++count;
                    bfsSink(r, c, grid);
                }
            }
        }
        return count;
    }
};

int main() {
    std::vector<std::vector<char>> g1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    assert(NumberOfIslands::numIslands(g1) == 1);

    std::vector<std::vector<char>> g2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    assert(NumberOfIslands::numIslands(g2) == 3);

    std::cout << "All Number of Islands tests passed successfully!\n";
    return 0;
}

