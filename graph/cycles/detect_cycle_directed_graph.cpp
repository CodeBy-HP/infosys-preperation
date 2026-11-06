#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

class DetectCycleDirected {
public:
    // Approach 1: Kahn's Algorithm (BFS) - O(V + E) Time, O(V) Space
    static bool isCyclicBFS(int V, const std::vector<std::vector<int>>& adj) {
        std::vector<int> inDegree(V, 0);
        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                inDegree[v]++;
            }
        }

        std::queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return count != V; // If count < V, cycle exists!
    }

    // Approach 2: DFS with Path-Visited Array
    static bool dfsCheck(int node, const std::vector<std::vector<int>>& adj,
                         std::vector<bool>& visited, std::vector<bool>& pathVisited) {
        visited[node] = true;
        pathVisited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfsCheck(neighbor, adj, visited, pathVisited)) return true;
            } else if (pathVisited[neighbor]) {
                return true; // Back-edge detected!
            }
        }

        pathVisited[node] = false; // Backtrack
        return false;
    }

    static bool isCyclicDFS(int V, const std::vector<std::vector<int>>& adj) {
        std::vector<bool> visited(V, false);
        std::vector<bool> pathVisited(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (dfsCheck(i, adj, visited, pathVisited)) return true;
            }
        }
        return false;
    }
};

int main() {
    int V1 = 4;
    // 0->1, 1->2, 2->3, 3->1 (cycle 1-2-3-1)
    std::vector<std::vector<int>> adj1 = {
        {1},
        {2},
        {3},
        {1}
    };
    assert(DetectCycleDirected::isCyclicBFS(V1, adj1) == true);
    assert(DetectCycleDirected::isCyclicDFS(V1, adj1) == true);

    int V2 = 4;
    // DAG: 0->1, 0->2, 1->3, 2->3
    std::vector<std::vector<int>> adj2 = {
        {1, 2},
        {3},
        {3},
        {}
    };
    assert(DetectCycleDirected::isCyclicBFS(V2, adj2) == false);
    assert(DetectCycleDirected::isCyclicDFS(V2, adj2) == false);

    std::cout << "All Detect Cycle in Directed Graph tests passed successfully!\n";
    return 0;
}

