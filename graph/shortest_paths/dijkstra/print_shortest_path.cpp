#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>

class PrintShortestPath {
public:
    static std::vector<int> shortestPath(int n, int m, const std::vector<std::vector<int>>& edges) {
        (void)m;
        // 1-based indexing for n vertices
        std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        const int INF = 1e9;
        std::vector<int> dist(n + 1, INF);
        std::vector<int> parent(n + 1);
        for (int i = 1; i <= n; ++i) parent[i] = i;

        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>> pq;

        dist[1] = 0;
        pq.push({0, 1});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (const auto& [v, weight] : adj[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        if (dist[n] == INF) return {-1};

        std::vector<int> path;
        int curr = n;
        while (parent[curr] != curr) {
            path.push_back(curr);
            curr = parent[curr];
        }
        path.push_back(1);
        std::reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    int n = 5, m = 6;
    std::vector<std::vector<int>> edges = {
        {1, 2, 2},
        {2, 5, 5},
        {2, 3, 4},
        {1, 4, 1},
        {4, 3, 3},
        {3, 5, 1}
    };
    auto path = PrintShortestPath::shortestPath(n, m, edges);
    // Shortest path: 1 -> 4 -> 3 -> 5 with total weight 1 + 3 + 1 = 5
    std::vector<int> expected = {1, 4, 3, 5};
    assert(path == expected);

    std::cout << "All Print Shortest Path tests passed successfully!\n";
    return 0;
}

