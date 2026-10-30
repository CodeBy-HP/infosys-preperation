#include <vector>

using namespace std;

vector<int> bellmanFord(int n, vector<vector<int>>& edges, int src) {
    // 1e8 is used instead of INT_MAX to prevent integer overflow when adding weights
    vector<int> dist(n, 1e8);
    dist[src] = 0;

    // Step 1: Relax all edges exactly N - 1 times
    for (int i = 0; i < n - 1; i++) {
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            // If we have reached node 'u', and the new path to 'v' is cheaper
            if (dist[u] != 1e8 && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Step 2: The N-th iteration to check for Negative Cycles
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];

        // If a distance STILL updates on the N-th pass, there is a negative cycle!
        if (dist[u] != 1e8 && dist[u] + weight < dist[v]) {
            // Returning {-1} as a flag that the graph is trapped in an infinite loop
            return {-1}; 
        }
    }

    return dist;
}