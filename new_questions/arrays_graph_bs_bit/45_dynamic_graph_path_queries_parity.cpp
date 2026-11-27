#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    // Variant A: LeetCode 1129 - Shortest Path with Alternating Red/Blue Colors
    vector<int> shortestAlternatingPaths(int n, const vector<vector<int>>& redEdges, const vector<vector<int>>& blueEdges) {
        // adj[node][color]: 0 = red, 1 = blue
        vector<vector<vector<int>>> adj(n, vector<vector<int>>(2));
        for (const auto& e : redEdges) adj[e[0]][0].push_back(e[1]);
        for (const auto& e : blueEdges) adj[e[0]][1].push_back(e[1]);

        vector<vector<int>> dist(n, vector<int>(2, -1));
        queue<pair<int, int>> q;

        dist[0][0] = dist[0][1] = 0;
        q.push({0, 0}); // can start by taking blue next
        q.push({0, 1}); // can start by taking red next

        while (!q.empty()) {
            auto [u, lastColor] = q.front();
            q.pop();

            int nextColor = lastColor ^ 1;
            for (int v : adj[u][nextColor]) {
                if (dist[v][nextColor] == -1) {
                    dist[v][nextColor] = dist[u][lastColor] + 1;
                    q.push({v, nextColor});
                }
            }
        }

        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            if (dist[i][0] != -1 && dist[i][1] != -1) ans[i] = min(dist[i][0], dist[i][1]);
            else ans[i] = max(dist[i][0], dist[i][1]);
        }
        return ans;
    }

    // Variant B: Shortest Path of Target Parity (0=even, 1=odd) from source 0
    vector<vector<int>> shortestPathsByParity(int n, const vector<pair<int, int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e.first].push_back(e.second);
            adj[e.second].push_back(e.first);
        }

        vector<vector<int>> dist(n, vector<int>(2, -1));
        queue<pair<int, int>> q;
        dist[0][0] = 0;
        q.push({0, 0});

        while (!q.empty()) {
            auto [u, par] = q.front();
            q.pop();
            int npar = par ^ 1;
            for (int v : adj[u]) {
                if (dist[v][npar] == -1) {
                    dist[v][npar] = dist[u][par] + 1;
                    q.push({v, npar});
                }
            }
        }
        return dist;
    }
};

int main() {
    Solution sol;
    assert((sol.shortestAlternatingPaths(3, {{0, 1}, {1, 2}}, {}) == vector<int>{0, 1, -1}));
    assert((sol.shortestAlternatingPaths(3, {{0, 1}}, {{2, 1}}) == vector<int>{0, 1, -1}));
    auto pDist = sol.shortestPathsByParity(4, {{0, 1}, {1, 2}, {2, 0}, {1, 3}});
    assert(pDist[3][0] == 2); // 0 -> 1 -> 3 (even length 2)
    assert(pDist[3][1] == 3); // 0 -> 2 -> 1 -> 3 (odd length 3)
    cout << "45_dynamic_graph_path_queries_parity passed all tests!\n";
    return 0;
}
