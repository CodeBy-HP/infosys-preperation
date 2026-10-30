#include <vector>
#include <stack>

using namespace std;

// Step 1: DFS to find the finishing order
void dfs1(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs1(neighbor, adj, visited, st);
        }
    }
    // Push to stack ONLY after all neighbors are fully explored
    st.push(node);
}

// Step 3: DFS to extract the SCC on the reversed graph
void dfs2(int node, vector<vector<int>>& rev_adj, vector<bool>& visited, vector<int>& current_scc) {
    visited[node] = true;
    current_scc.push_back(node);
    for (int neighbor : rev_adj[node]) {
        if (!visited[neighbor]) {
            dfs2(neighbor, rev_adj, visited, current_scc);
        }
    }
}

vector<vector<int>> getSCCs(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    vector<vector<int>> rev_adj(n);
    
    // Build both the Original Graph and the Reversed Graph
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        rev_adj[edge[1]].push_back(edge[0]); // Reversed edge!
    }
    
    stack<int> st;
    vector<bool> visited(n, false);
    
    // Step 1: Fill the Stack with finishing times
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs1(i, adj, visited, st);
        }
    }
    
    // Step 2 & 3: Process the Stack on the Reversed Graph
    fill(visited.begin(), visited.end(), false); // Reset visited array
    vector<vector<int>> all_sccs;
    
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        
        if (!visited[node]) {
            vector<int> current_scc;
            dfs2(node, rev_adj, visited, current_scc);
            all_sccs.push_back(current_scc); // We successfully trapped an SCC!
        }
    }
    
    return all_sccs;
}