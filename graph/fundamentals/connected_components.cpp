#include <iostream>
#include <vector>
#include <cassert>

class ConnectedComponents {
public:
    static void dfs(int node, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    static int countComponents(int V, const std::vector<std::vector<int>>& adj) {
        std::vector<bool> visited(V, false);
        int components = 0;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                ++components;
                dfs(i, adj, visited);
            }
        }
        return components;
    }
};

int main() {
    int V1 = 5;
    // 3 components: {0, 1}, {2}, {3, 4}
    std::vector<std::vector<int>> adj1 = {
        {1},
        {0},
        {},
        {4},
        {3}
    };
    assert(ConnectedComponents::countComponents(V1, adj1) == 3);

    int V2 = 4;
    // Fully connected: {0, 1, 2, 3}
    std::vector<std::vector<int>> adj2 = {
        {1},
        {0, 2},
        {1, 3},
        {2}
    };
    assert(ConnectedComponents::countComponents(V2, adj2) == 1);

    std::cout << "All Connected Components tests passed successfully!\n";
    return 0;
}

