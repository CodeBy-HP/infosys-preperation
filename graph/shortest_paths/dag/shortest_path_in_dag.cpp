#include <iostream>
#include <vector>
#include <stack>
#include <cassert>

class ShortestPathDAG {
public:
    static void topoDFS(int node, const std::vector<std::vector<std::pair<int, int>>>& adj,
                        std::vector<bool>& visited, std::stack<int>& st) {
        visited[node] = true;
        for (const auto& [neighbor, weight] : adj[node]) {
            if (!visited[neighbor]) {
                topoDFS(neighbor, adj, visited, st);
            }
        }
        st.push(node);
    }

    static std::vector<int> shortestPath(int V, int source, const std::vector<std::vector<std::pair<int, int>>>& adj) {
        std::vector<bool> visited(V, false);
        std::stack<int> st;

        // 1. Compute Topological Sort
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                topoDFS(i, adj, visited, st);
            }
        }

        // 2. Linear Relaxation in Topological Order
        const int INF = 1e9;
        std::vector<int> dist(V, INF);
        dist[source] = 0;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            if (dist[u] != INF) {
                for (const auto& [v, weight] : adj[u]) {
                    if (dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        for (int i = 0; i < V; ++i) {
            if (dist[i] == INF) dist[i] = -1; // Unreachable
        }
        return dist;
    }
};

int main() {
    int V = 6;
    std::vector<std::vector<std::pair<int, int>>> adj(V);
    // 0->1 (2), 0->4 (1), 1->2 (3), 4->2 (2), 4->5 (4), 2->3 (6), 5->3 (1)
    adj[0] = {{1, 2}, {4, 1}};
    adj[1] = {{2, 3}};
    adj[2] = {{3, 6}};
    adj[4] = {{2, 2}, {5, 4}};
    adj[5] = {{3, 1}};

    auto dist = ShortestPathDAG::shortestPath(V, 0, adj);
    // Path to 3: 0->4 (1) + 4->5 (4) + 5->3 (1) = 6
    std::vector<int> expected = {0, 2, 3, 6, 1, 5};
    assert(dist == expected);

    std::cout << "All Shortest Path in DAG tests passed successfully!\n";
    return 0;
}

