#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cassert>

class TopologicalSort {
public:
    // Approach 1: Kahn's Algorithm (BFS) - O(V + E) Time, O(V) Space
    static std::vector<int> topoSortKahns(int V, const std::vector<std::vector<int>>& adj) {
        std::vector<int> inDegree(V, 0);
        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                inDegree[v]++;
            }
        }

        std::queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        std::vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return topo;
    }

    // Approach 2: DFS with Stack
    static void dfs(int node, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, std::stack<int>& st) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, st);
            }
        }
        st.push(node);
    }

    static std::vector<int> topoSortDFS(int V, const std::vector<std::vector<int>>& adj) {
        std::vector<bool> visited(V, false);
        std::stack<int> st;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, adj, visited, st);
            }
        }

        std::vector<int> topo;
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};

int main() {
    int V = 6;
    // Edges: 5->0, 5->2, 4->0, 4->1, 2->3, 3->1
    std::vector<std::vector<int>> adj(V);
    adj[5] = {0, 2};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};

    auto topoKahn = TopologicalSort::topoSortKahns(V, adj);
    assert(topoKahn.size() == 6);

    auto topoDFS = TopologicalSort::topoSortDFS(V, adj);
    assert(topoDFS.size() == 6);

    // Verify ordering validity
    std::vector<int> pos(V);
    for (int i = 0; i < V; ++i) pos[topoKahn[i]] = i;
    for (int u = 0; u < V; ++u) {
        for (int v : adj[u]) {
            assert(pos[u] < pos[v]);
        }
    }

    std::cout << "All Topological Sort (Kahn's & DFS) tests passed successfully!\n";
    return 0;
}

