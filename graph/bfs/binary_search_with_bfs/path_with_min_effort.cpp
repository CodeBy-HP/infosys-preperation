#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

bool canReach(const vector<vector<int>>& heights, int max_effort) {
    int n = heights.size();
    int m = heights[0].size();
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    
    q.push({0, 0});
    visited[0][0] = true;
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        // If we reached the destination, this max_effort is valid
        if (x == n - 1 && y == m - 1) return true;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                // Only allow the move if the effort is within our guessed limit
                if (abs(heights[nx][ny] - heights[x][y]) <= max_effort) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    return false;
}

int minimumEffortPath(vector<vector<int>>& heights) {
    int low = 0;
    int high = 1e6; // Maximum possible height difference
    int ans = 0;
    
    // Binary search on the answer
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (canReach(heights, mid)) {
            ans = mid;        // Record the valid answer
            high = mid - 1;   // Try to find a smaller valid effort
        } else {
            low = mid + 1;    // The effort was too small, we need a larger limit
        }
    }
    
    return ans;
}