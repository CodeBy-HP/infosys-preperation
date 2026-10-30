#include <vector>
#include <queue>

using namespace std;

int shortestPath(vector<vector<int>>& grid, int k) {
    int n = grid.size();
    int m = grid[0].size();
    
    // Edge case: If you have enough k to just walk the Manhattan distance, return it immediately.
    if (k >= n + m - 2) return n + m - 2;

    // Queue stores: {x, y, remaining_k, steps}
    queue<vector<int>> q;
    q.push({0, 0, k, 0});

    // visited[i][j] will store the MAXIMUM remaining_k we had when we visited cell (i, j).
    // Initialize with -1 to indicate unvisited.
    vector<vector<int>> visited(n, vector<int>(m, -1));
    visited[0][0] = k;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        
        int x = curr[0];
        int y = curr[1];
        int curr_k = curr[2];
        int steps = curr[3];

        // If we reach the bottom-right corner, return steps (BFS guarantees it's the minimum)
        if (x == n - 1 && y == m - 1) return steps;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                // Calculate how much k we would have left if we step here
                int next_k = curr_k - grid[nx][ny];

                // If we have valid k, AND this path leaves us with MORE k than previous visits to (nx, ny)
                if (next_k >= 0 && next_k > visited[nx][ny]) {
                    visited[nx][ny] = next_k;
                    q.push({nx, ny, next_k, steps + 1});
                }
            }
        }
    }

    return -1; // Path not found
}