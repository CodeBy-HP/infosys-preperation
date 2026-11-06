#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

class DetectCycleUndirected {
public:
    // Approach 1: BFS with Queue of {node, parent}
    static bool bfsCheck(int start, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited) {
        visited[start] = true;
        std::queue<std::pair<int, int>> q; // {node, parent}
        q.push({start, -1});

        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, node});
                } else if (neighbor != parent) {
                    return true; // Cycle detected!
                }
            }
        }
        return false;
    }

    // Approach 2: DFS with parent parameter
    static bool dfsCheck(int node, int parent, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfsCheck(neighbor, node, adj, visited)) return true;
            } else if (neighbor != parent) {
                return true; // Cycle detected!
            }
        }
        return false;
    }

    static bool isCycle(int V, const std::vector<std::vector<int>>& adj) {
        std::vector<bool> visited(V, false);
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (bfsCheck(i, adj, visited)) return true;
            }
        }
        return false;
    }
};

int main() {
    int V1 = 4;
    // Triangle cycle: 0-1, 1-2, 2-0, 2-3
    std::vector<std::vector<int>> adj1 = {
        {1, 2},
        {0, 2},
        {0, 1, 3},
        {2}
    };
    assert(DetectCycleUndirected::isCycle(V1, adj1) == true);

    int V2 = 4;
    // Tree (no cycles): 0-1, 1-2, 2-3
    std::vector<std::vector<int>> adj2 = {
        {1},
        {0, 2},
        {1, 3},
        {2}
    };
    assert(DetectCycleUndirected::isCycle(V2, adj2) == false);

    std::cout << "All Detect Cycle in Undirected Graph tests passed successfully!\n";
    return 0;
}

