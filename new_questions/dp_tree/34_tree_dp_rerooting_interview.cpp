#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
    void dfs1(int u, int p, const vector<vector<int>>& adj, vector<int>& sz, vector<int>& ans) {
        sz[u] = 1;
        for (int v : adj[u]) {
            if (v == p) continue;
            dfs1(v, u, adj, sz, ans);
            sz[u] += sz[v];
            ans[u] += ans[v] + sz[v];
        }
    }

    void dfs2(int u, int p, int n, const vector<vector<int>>& adj, const vector<int>& sz, vector<int>& ans) {
        for (int v : adj[u]) {
            if (v == p) continue;
            ans[v] = ans[u] - sz[v] + (n - sz[v]);
            dfs2(v, u, n, adj, sz, ans);
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, const vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> sz(n, 0), ans(n, 0);
        dfs1(0, -1, adj, sz, ans);
        dfs2(0, -1, n, adj, sz, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> expected = {8, 12, 6, 10, 10, 10};
    assert(sol.sumOfDistancesInTree(6, {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}}) == expected);
    assert(sol.sumOfDistancesInTree(1, {}) == vector<int>{0});
    cout << "34_tree_dp_rerooting_interview passed all tests!\n";
    return 0;
}
