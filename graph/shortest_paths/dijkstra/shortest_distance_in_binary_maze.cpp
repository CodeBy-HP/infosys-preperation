#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

class ShortestDistanceBinaryMaze {
public:
    static int shortestPath(const std::vector<std::vector<int>>& grid,
                            std::pair<int, int> source,
                            std::pair<int, int> destination) {
        if (grid.empty()) return -1;
        int m = grid.size();
        int n = grid[0].size();

        if (grid[source.first][source.second] == 1 || grid[destination.first][destination.second] == 1) {
            return -1;
        }
        if (source == destination) return 0;

        std::vector<std::vector<int>> dist(m, std::vector<int>(n, 1e9));
        // Queue storing {distance, row, col}
        std::queue<std::tuple<int, int, int>> q;

        dist[source.first][source.second] = 0;
        q.push({0, source.first, source.second});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [d, r, c] = q.front();
            q.pop();

            if (r == destination.first && c == destination.second) {
                return d;
            }

            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    if (d + 1 < dist[nr][nc]) {
                        dist[nr][nc] = d + 1;
                        q.push({d + 1, nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    std::vector<std::vector<int>> maze = {
        {0, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };
    std::pair<int, int> src = {0, 0};
    std::pair<int, int> dst = {4, 3};

    int shortestDist = ShortestDistanceBinaryMaze::shortestPath(maze, src, dst);
    assert(shortestDist == 7);

    // Blocked destination
    std::vector<std::vector<int>> mazeBlocked = {
        {0, 1},
        {1, 0}
    };
    assert(ShortestDistanceBinaryMaze::shortestPath(mazeBlocked, {0, 0}, {1, 1}) == -1);

    std::cout << "All Shortest Distance in Binary Maze tests passed successfully!\n";
    return 0;
}

