#include <vector>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

// Even if you have walked over cell (2,2) ten times already, if you step onto it for the 11th time carrying a brand new combination of keys that you've never brought to this specific cell before, it is treated as a completely unvisited, brand-new node. It opens up a new timeline of possibilities.

int shortestPathAllKeys(vector<string>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    int start_x = -1, start_y = -1;
    int total_keys = 0;

    // 1. Find the starting point and count total keys
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '@') {
                start_x = i;
                start_y = j;
            } else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                total_keys++;
            }
        }
    }

    // The target bitmask: if total_keys = 3, target is 111 in binary (which is 7)
    // (1 << 3) - 1 = 8 - 1 = 7.
    int target_mask = (1 << total_keys) - 1;

    // Queue stores: {x, y, current_mask, steps}
    queue<vector<int>> q;
    q.push({start_x, start_y, 0, 0});

    // visited[x][y][mask]
    // 64 is enough since there are max 6 keys (1 << 6 = 64)
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(64, false)));
    visited[start_x][start_y][0] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // 2. BFS Traversal
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        int x = curr[0];
        int y = curr[1];
        int mask = curr[2];
        int steps = curr[3];

        // If we have collected all keys, BFS guarantees this is the minimum steps
        if (mask == target_mask) return steps;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#') {
                char cell = grid[nx][ny];
                int next_mask = mask;

                // If it's a lock, check if we have the corresponding key
                if (cell >= 'A' && cell <= 'F') {
                    int key_required = cell - 'A';
                    // Check if the 'key_required' bit is 0 (we don't have the key)
                    if (!(mask & (1 << key_required))) {
                        continue; 
                    }
                }

                // If it's a key, update our bitmask by turning on that key's bit
                if (cell >= 'a' && cell <= 'f') {
                    int key_found = cell - 'a';
                    next_mask = mask | (1 << key_found);
                }

                // If we haven't visited this exact physical cell WITH this exact inventory yet
                if (!visited[nx][ny][next_mask]) {
                    visited[nx][ny][next_mask] = true;
                    q.push({nx, ny, next_mask, steps + 1});
                }
            }
        }
    }

    return -1;
}