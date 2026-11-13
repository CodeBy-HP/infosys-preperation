#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>

class EventualSafeNodes {
public:
    // Approach 1: Reversed Graph + Kahn's Algorithm
    static std::vector<int> eventualSafeNodesKahn(const std::vector<std::vector<int>>& graph) {
        int V = graph.size();
        std::vector<std::vector<int>> revAdj(V);
        std::vector<int> inDegree(V, 0);

        for (int u = 0; u < V; ++u) {
            for (int v : graph[u]) {
                revAdj[v].push_back(u); // reverse edge u->v into v->u
                inDegree[u]++;           // out-degree in graph is in-degree in revAdj
            }
        }

        std::queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        std::vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for (int neighbor : revAdj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        std::sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }

    // Approach 2: 3-State DFS
    static bool dfs(int node, const std::vector<std::vector<int>>& graph, std::vector<int>& state) {
        state[node] = 1; // Visiting

        for (int neighbor : graph[node]) {
            if (state[neighbor] == 1) return false; // Cycle detected
            if (state[neighbor] == 0) {
                if (!dfs(neighbor, graph, state)) return false;
            }
        }

        state[node] = 2; // Verified safe
        return true;
    }

    static std::vector<int> eventualSafeNodesDFS(const std::vector<std::vector<int>>& graph) {
        int V = graph.size();
        std::vector<int> state(V, 0);
        std::vector<int> safeNodes;

        for (int i = 0; i < V; ++i) {
            if (state[i] == 2 || (state[i] == 0 && dfs(i, graph, state))) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};

int main() {
    std::vector<std::vector<int>> g1 = {
        {1, 2},
        {2, 3},
        {5},
        {0},
        {5},
        {},
        {}
    };
    auto safeKahn = EventualSafeNodes::eventualSafeNodesKahn(g1);
    auto safeDFS = EventualSafeNodes::eventualSafeNodesDFS(g1);
    std::vector<int> expected1 = {2, 4, 5, 6};
    assert(safeKahn == expected1);
    assert(safeDFS == expected1);

    std::vector<std::vector<int>> g2 = {
        {1, 2, 3, 4},
        {1, 2},
        {3, 4},
        {0, 4},
        {}
    };
    auto safe2 = EventualSafeNodes::eventualSafeNodesKahn(g2);
    assert(safe2 == std::vector<int>({4}));

    std::cout << "All Find Eventual Safe States tests passed successfully!\n";
    return 0;
}

