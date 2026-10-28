#include <vector>
#include <queue>

using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    int freshCount = 0;

    // 1. Put all initial rotten oranges in queue and count fresh ones
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }

    // If there are no fresh oranges to begin with, time is 0
    if (freshCount == 0) return 0;

    int minutes = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // 2. Multi-source BFS level by level
    while (!q.empty()) {
        int size = q.size();
        bool rottedThisMinute = false; 

        for (int i = 0; i < size; i++) {
            auto [x, y] = q.front();
            q.pop();

            // Check 4 adjacent directions
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2; // Make it rotten
                    freshCount--;
                    q.push({nx, ny});
                    rottedThisMinute = true;
                }
            }
        }
        
        // Only increment time if we actually rotted something in this wave
        if (rottedThisMinute) minutes++;
    }

    return freshCount == 0 ? minutes : -1;
}