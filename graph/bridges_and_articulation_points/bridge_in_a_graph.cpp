#include <vector>
#include <algorithm>

using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<int>& disc, vector<int>& low, 
         vector<vector<int>>& adj, vector<vector<int>>& bridges) {
    
    // Stamp the current time on both arrays
    disc[node] = low[node] = timer++;
    
    for (int neighbor : adj[node]) {
        if (neighbor == parent) continue; // Don't look back at the immediate parent
        
        if (disc[neighbor] == 0) { // If unvisited
            dfs(neighbor, node, disc, low, adj, bridges);
            
            // On the backtrack, node asks the neighbor for its lowest reachable time
            low[node] = min(low[node], low[neighbor]);
            
            // THE BRIDGE ALARM:
            // If the neighbor's absolute lowest reachable time is strictly greater 
            // than my discovery time, it means the neighbor has no back-route.
            if (low[neighbor] > disc[node]) {
                bridges.push_back({node, neighbor});
            }
        } else {
            // BACK-EDGE FOUND! 
            // We hit a previously visited node. Update our lowest reachable time.
            low[node] = min(low[node], disc[neighbor]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> adj(n);
    for (auto& conn : connections) {
        adj[conn[0]].push_back(conn[1]);
        adj[conn[1]].push_back(conn[0]);
    }
    
    vector<int> disc(n, 0);
    vector<int> low(n, 0);
    vector<vector<int>> bridges;
    
    // Assuming the graph is a single connected component (as per standard Leetcode rules)
    dfs(0, -1, disc, low, adj, bridges);
    
    return bridges;
}