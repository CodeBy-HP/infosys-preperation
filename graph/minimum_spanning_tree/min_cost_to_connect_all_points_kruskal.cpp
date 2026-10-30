#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Standard DSU Class with Path Compression and Union by Rank
class DSU {
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Every node starts as its own root
        }
    }
    
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path compression
    }
    
    bool unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        
        if (rootI != rootJ) {
            if (rank[rootI] < rank[rootJ]) parent[rootI] = rootJ;
            else if (rank[rootI] > rank[rootJ]) parent[rootJ] = rootI;
            else {
                parent[rootJ] = rootI;
                rank[rootI]++;
            }
            return true; // Successfully merged
        }
        return false; // Cycle detected, they were already connected
    }
};

int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    
    // Store edges as {cost, point_A, point_B}
    vector<vector<int>> edges;
    
    // 1. Generate every possible bridge between all points O(N^2)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            edges.push_back({dist, i, j});
        }
    }
    
    // 2. Sort all edges from cheapest to most expensive
    // C++ sorts vector<vector<int>> based on the first element (cost) automatically
    sort(edges.begin(), edges.end());
    
    DSU dsu(n);
    int total_cost = 0;
    int edges_used = 0;
    
    // 3. Greedily pick the cheapest edges
    for (auto& edge : edges) {
        int cost = edge[0];
        int u = edge[1];
        int v = edge[2];
        
        // If unite returns true, no cycle was formed.
        if (dsu.unite(u, v)) {
            total_cost += cost;
            edges_used++;
            
            // 4. Stop early once we have N - 1 edges
            if (edges_used == n - 1) {
                break;
            }
        }
    }
    
    return total_cost;
}