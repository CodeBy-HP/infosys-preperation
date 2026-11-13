#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

class GraphTraversals {
public:
    // Standard Breadth-First Search (BFS)
    static std::vector<int> bfsTraversal(int V, const std::vector<std::vector<int>>& adj, int startNode = 0) {
        std::vector<int> bfs;
        std::vector<bool> visited(V, false);
        std::queue<int> q;

        visited[startNode] = true;
        q.push(startNode);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return bfs;
    }

    // Depth-First Search (DFS) Helper
    static void dfsHelper(int node, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, std::vector<int>& dfs) {
        visited[node] = true;
        dfs.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, adj, visited, dfs);
            }
        }
    }

    // Standard Depth-First Search (DFS)
    static std::vector<int> dfsTraversal(int V, const std::vector<std::vector<int>>& adj, int startNode = 0) {
        std::vector<int> dfs;
        std::vector<bool> visited(V, false);
        dfsHelper(startNode, adj, visited, dfs);
        return dfs;
    }
};

int main() {
    int V = 5;
    std::vector<std::vector<int>> adj = {
        {1, 2},       // 0
        {0, 3, 4},    // 1
        {0},          // 2
        {1},          // 3
        {1}           // 4
    };

    auto bfs = GraphTraversals::bfsTraversal(V, adj, 0);
    assert(bfs == std::vector<int>({0, 1, 2, 3, 4}));

    auto dfs = GraphTraversals::dfsTraversal(V, adj, 0);
    assert(dfs == std::vector<int>({0, 1, 3, 4, 2}));

    std::cout << "All Graph Traversal Techniques tests passed successfully!\n";
    return 0;
}

