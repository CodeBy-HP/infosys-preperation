#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int shortestPathLength(const std::vector<std::vector<int>>& graph) {
        int n = graph.size();
        if (n <= 1) return 0;

        int finalMask = (1 << n) - 1;
        // dist[node][mask]
        std::vector<std::vector<int>> dist(n, std::vector<int>(1 << n, -1));
        std::queue<std::pair<int, int>> q; // {node, mask}

        // Multi-source BFS: initialize with all starting nodes
        for (int i = 0; i < n; ++i) {
            q.push({i, 1 << i});
            dist[i][1 << i] = 0;
        }

        while (!q.empty()) {
            auto [u, mask] = q.front();
            q.pop();

            int d = dist[u][mask];
            if (mask == finalMask) {
                return d;
            }

            for (int v : graph[u]) {
                int nextMask = mask | (1 << v);
                if (dist[v][nextMask] == -1) {
                    dist[v][nextMask] = d + 1;
                    q.push({v, nextMask});
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> graph1 = {{1, 2, 3}, {0}, {0}, {0}};
    std::cout << "Test 1: " << sol.shortestPathLength(graph1) << " (Expected: 4)\n";

    std::vector<std::vector<int>> graph2 = {{1}, {0, 2, 4}, {1, 3, 4}, {2}, {1, 2}};
    std::cout << "Test 2: " << sol.shortestPathLength(graph2) << " (Expected: 4)\n";

    return 0;
}
