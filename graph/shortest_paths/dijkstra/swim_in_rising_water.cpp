#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>

class SwimInWater {
public:
    static int swimInWater(const std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));

        // Min-heap storing {time, r, c}
        std::priority_queue<std::tuple<int, int, int>,
                            std::vector<std::tuple<int, int, int>>,
                            std::greater<std::tuple<int, int, int>>> pq;

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [time, r, c] = pq.top();
            pq.pop();

            if (r == n - 1 && c == n - 1) {
                return time;
            }

            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    int nextTime = std::max(time, grid[nr][nc]);
                    pq.push({nextTime, nr, nc});
                }
            }
        }
        return -1;
    }
};

int main() {
    std::vector<std::vector<int>> g1 = {
        {0, 2},
        {1, 3}
    };
    assert(SwimInWater::swimInWater(g1) == 3);

    std::vector<std::vector<int>> g2 = {
        {0, 1, 2, 3, 4},
        {24, 23, 22, 21, 5},
        {12, 13, 14, 15, 16},
        {11, 17, 18, 19, 20},
        {10, 9, 8, 7, 6}
    };
    assert(SwimInWater::swimInWater(g2) == 16);

    std::cout << "All Swim in Rising Water tests passed successfully!\n";
    return 0;
}

