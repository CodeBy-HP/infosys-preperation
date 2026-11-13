#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <cassert>

class DisjointSetHelper {
    std::vector<int> parent, size;
public:
    DisjointSetHelper(int n) {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
        size.assign(n, 1);
    }
    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    bool unionBySize(int u, int v) {
        int rootU = findUPar(u), rootV = findUPar(v);
        if (rootU == rootV) return false;
        if (size[rootU] < size[rootV]) {
            parent[rootU] = rootV;
            size[rootV] += size[rootU];
        } else {
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
        }
        return true;
    }
};

class MSTWeight {
public:
    // Approach 1: Kruskal's Algorithm - O(E log E) Time, O(V + E) Space
    static int spanningTreeKruskal(int V, const std::vector<std::vector<int>>& edges) {
        // edges format: {u, v, w}
        std::vector<std::vector<int>> sortedEdges = edges;
        std::sort(sortedEdges.begin(), sortedEdges.end(), [](const auto& a, const auto& b) {
            return a[2] < b[2];
        });

        DisjointSetHelper ds(V);
        int mstWeight = 0;
        int edgeCount = 0;

        for (const auto& e : sortedEdges) {
            int u = e[0], v = e[1], w = e[2];
            if (ds.unionBySize(u, v)) {
                mstWeight += w;
                edgeCount++;
                if (edgeCount == V - 1) break;
            }
        }
        return mstWeight;
    }

    // Approach 2: Prim's Algorithm - O(E log V) Time, O(V + E) Space
    static int spanningTreePrim(int V, const std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<std::pair<int, int>>> adj(V);
        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        std::vector<bool> visited(V, false);
        // Min-heap: {weight, node}
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>> pq;

        pq.push({0, 0});
        int mstWeight = 0;

        while (!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();

            if (visited[u]) continue;
            visited[u] = true;
            mstWeight += w;

            for (const auto& [v, weight] : adj[u]) {
                if (!visited[v]) {
                    pq.push({weight, v});
                }
            }
        }
        return mstWeight;
    }
};

int main() {
    int V = 5;
    std::vector<std::vector<int>> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7}
    };
    // MST edges: (0,1,2), (1,2,3), (1,4,5), (0,3,6) -> Sum = 16
    assert(MSTWeight::spanningTreeKruskal(V, edges) == 16);
    assert(MSTWeight::spanningTreePrim(V, edges) == 16);

    std::cout << "All Find MST Weight (Kruskal's & Prim's) tests passed successfully!\n";
    return 0;
}

