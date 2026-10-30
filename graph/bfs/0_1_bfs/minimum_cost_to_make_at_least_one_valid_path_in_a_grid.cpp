#include <vector>
#include <deque>

using namespace std;

int minCost(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    // Directions mapping: 1=Right, 2=Left, 3=Down, 4=Up
    // Our array index (0 to 3) + 1 will perfectly match the grid's signs
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    // Deque allows push_front (for 0 cost) and push_back (for 1 cost)
    deque<pair<int, int>> dq;
    
    // Track minimum cost to reach each cell. Initialize to infinity (1e9).
    vector<vector<int>> cost(n, vector<int>(m, 1e9));
    
    dq.push_front({0, 0});
    cost[0][0] = 0;
    
    while (!dq.empty()) {
        auto [x, y] = dq.front();
        dq.pop_front();
        
        // 0-1 BFS guarantees the first time we pop the destination, it is the absolute minimum cost
        if (x == n - 1 && y == m - 1) {
            return cost[x][y];
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                // If the sign matches our direction (i + 1), cost is 0. Otherwise, cost is 1.
                int moveCost = (grid[x][y] == i + 1) ? 0 : 1;
                
                // If we found a cheaper way to reach (nx, ny)
                if (cost[x][y] + moveCost < cost[nx][ny]) {
                    cost[nx][ny] = cost[x][y] + moveCost;
                    
                    // The 0-1 BFS trick:
                    if (moveCost == 0) {
                        dq.push_front({nx, ny}); // Free move! Skip to the front of the line.
                    } else {
                        dq.push_back({nx, ny});  // Paid move. Wait at the back of the line.
                    }
                }
            }
        }
    }
    
    return 0;
}