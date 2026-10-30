#include <vector>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    
    // color array: -1 means Uncolored, 0 means Red, 1 means Blue
    vector<int> color(n, -1);
    
    // We must loop through all nodes in case the graph has disconnected parts.
    // If we only started from node 0, we might miss a separate triangle floating elsewhere.
    for (int i = 0; i < n; i++) {
        // If the node is uncolored, start a new BFS from here
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0; // Start by painting it Red (0)
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                
                // Look at all adjacent neighbors
                for (int neighbor : graph[curr]) {
                    // If the neighbor is uncolored, paint it the OPPOSITE color
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[curr]; // 1 - 0 = 1, 1 - 1 = 0
                        q.push(neighbor);
                    } 
                    // If the neighbor is already colored the SAME color, it's impossible
                    else if (color[neighbor] == color[curr]) {
                        return false; 
                    }
                }
            }
        }
    }
    
    return true; // We successfully colored the entire graph
}