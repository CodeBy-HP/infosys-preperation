#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

class Dijkstra {
public:
    static std::vector<int> dijkstra(int V, const std::vector<std::vector<std::pair<int, int>>>& adj, int S) {
        const int INF = 1e9;
        std::vector<int> dist(V, INF);
        // Min-heap storing {distance, node}
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>> pq;

        dist[S] = 0;
        pq.push({0, S});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            // Ignore stale entries in priority queue
            if (d > dist[u]) continue;

            for (const auto& [v, weight] : adj[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};

int main() {
    int V = 5;
    std::vector<std::vector<std::pair<int, int>>> adj(V);
    // Undirected graph:
    // 0-1 (4), 0-2 (1), 2-1 (2), 1-3 (1), 2-3 (5), 3-4 (3)
    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };
    addEdge(0, 1, 4);
    addEdge(0, 2, 1);
    addEdge(2, 1, 2);
    addEdge(1, 3, 1);
    addEdge(2, 3, 5);
    addEdge(3, 4, 3);

    auto dist = Dijkstra::dijkstra(V, adj, 0);
    // dist: 0->0=0, 0->2=1, 0->2->1=3, 0->2->1->3=4, 0->2->1->3->4=7
    std::vector<int> expected = {0, 3, 1, 4, 7};
    assert(dist == expected);

    std::cout << "All Dijkstra's Algorithm tests passed successfully!\n";
    return 0;
}

