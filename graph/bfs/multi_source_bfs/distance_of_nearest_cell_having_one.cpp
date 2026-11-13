#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

class NearestCellHavingOne {
public:
    static std::vector<std::vector<int>> nearest(const std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        std::vector<std::vector<int>> dist(n, std::vector<int>(m, -1));
        std::queue<std::pair<int, int>> q;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (grid[r][c] == 1) {
                    dist[r][c] = 0;
                    q.push({r, c});
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return dist;
    }
};

int main() {
    std::vector<std::vector<int>> g1 = {
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1}
    };
    auto res1 = NearestCellHavingOne::nearest(g1);
    std::vector<std::vector<int>> expected1 = {
        {1, 0, 0, 1},
        {0, 0, 1, 1},
        {1, 1, 0, 0}
    };
    assert(res1 == expected1);

    std::vector<std::vector<int>> g2 = {
        {1, 0, 1},
        {1, 1, 0},
        {1, 0, 0}
    };
    auto res2 = NearestCellHavingOne::nearest(g2);
    std::vector<std::vector<int>> expected2 = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 1, 2}
    };
    assert(res2 == expected2);

    std::cout << "All Distance of Nearest Cell Having 1 tests passed successfully!\n";
    return 0;
}

