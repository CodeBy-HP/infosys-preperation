#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();
    
    // Min-heap priority queue storing {effort, x, y}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    
    // Track the minimum effort required to reach each cell
    vector<vector<int>> effortToReach(n, vector<int>(m, 1e9));
    
    pq.push({0, 0, 0});
    effortToReach[0][0] = 0;
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        
        int current_effort = curr[0];
        int x = curr[1];
        int y = curr[2];
        
        // Because it's a min-heap, the first time we pop the destination, it is the optimal path
        if (x == n - 1 && y == m - 1) {
            return current_effort;
        }
        
        // Optimization: If we already found a better path to this cell earlier, skip processing
        if (current_effort > effortToReach[x][y]) continue;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                // The effort for this specific step
                int step_effort = abs(heights[nx][ny] - heights[x][y]);
                
                // The max effort of the path up to the new cell
                int next_effort = max(current_effort, step_effort);
                
                // Update if we found a path with a strictly lower maximum effort
                if (next_effort < effortToReach[nx][ny]) {
                    effortToReach[nx][ny] = next_effort;
                    pq.push({next_effort, nx, ny});
                }
            }
        }
    }
    
    return 0; 
}