#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    
    // Min-Heap stores pairs of {cost, point_index}
    // greater<pair<int,int>> ensures the smallest cost stays at the top
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Track which points are already safely inside our MST
    vector<bool> inMST(n, false);
    
    int total_cost = 0;
    int points_connected = 0;
    
    // Start the growth from point 0, with a cost of 0
    pq.push({0, 0});
    
    // Continue until we have connected all N points
    while (!pq.empty() && points_connected < n) {
        auto [cost, curr_point] = pq.top();
        pq.pop();
        
        // If this point was already swallowed by the MST via a different, 
        // cheaper bridge earlier, just skip it.
        if (inMST[curr_point]) continue;
        
        // Formally add it to the MST
        inMST[curr_point] = true;
        total_cost += cost;
        points_connected++;
        
        // Update the radar: Check distances from this newly added point 
        // to all other unvisited points.
        for (int next_point = 0; next_point < n; next_point++) {
            if (!inMST[next_point]) {
                int manhattan_dist = abs(points[curr_point][0] - points[next_point][0]) + 
                                     abs(points[curr_point][1] - points[next_point][1]);
                pq.push({manhattan_dist, next_point});
            }
        }
    }
    
    return total_cost;
}