
#include <vector>
#include <algorithm>

using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<int>& disc, vector<int>& low, 
         vector<vector<int>>& adj, vector<int>& is_articulation) {
    
    disc[node] = low[node] = timer++;
    int children = 0; // Track how many independent paths launch from this node
    
    for (int neighbor : adj[node]) {
        if (neighbor == parent) continue; // Don't look at the parent
        
        if (disc[neighbor] == 0) { // If unvisited
            children++;
            dfs(neighbor, node, disc, low, adj, is_articulation);
            
            low[node] = min(low[node], low[neighbor]);
            
            // TWEAK 1: The >= condition (Node is a bottleneck for this neighbor)
            // We also ensure this rule isn't applied to the Root (parent == -1)
            if (parent != -1 && low[neighbor] >= disc[node]) {
                is_articulation[node] = 1;
            }
        } else {
            // BACK-EDGE FOUND!
            low[node] = min(low[node], disc[neighbor]);
        }
    }
    
    // TWEAK 2: The Root Exception
    // If it's the start node and it launched multiple branches, it's a hub!
    if (parent == -1 && children > 1) {
        is_articulation[node] = 1;
    }
}

vector<int> getArticulationPoints(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    
    vector<int> disc(n, 0);
    vector<int> low(n, 0);
    vector<int> is_articulation(n, 0); // Acts as a set to avoid duplicates
    vector<int> result;
    
    // Check all nodes in case the graph is disconnected
    for (int i = 0; i < n; i++) {
        if (disc[i] == 0) {
            dfs(i, -1, disc, low, adj, is_articulation);
        }
    }
    
    // Collect the flagged servers
    for (int i = 0; i < n; i++) {
        if (is_articulation[i] == 1) {
            result.push_back(i);
        }
    }
    
    return result;
}

