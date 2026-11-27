#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    // Returns {take_root, skip_root}
    pair<int, int> dfsBinary(TreeNode* root) {
        if (!root) return {0, 0};
        auto left = dfsBinary(root->left);
        auto right = dfsBinary(root->right);

        int take = root->val + left.second + right.second;
        int skip = max(left.first, left.second) + max(right.first, right.second);
        return {take, skip};
    }

    pair<long long, long long> dfsNary(int u, int p, const vector<vector<int>>& adj, const vector<int>& val) {
        long long take = max(0, val[u]);
        long long skip = 0;

        for (int v : adj[u]) {
            if (v == p) continue;
            auto child = dfsNary(v, u, adj, val);
            take += child.second;
            skip += max(child.first, child.second);
        }
        return {take, skip};
    }

public:
    // Binary Tree: LeetCode 337
    int robBinaryTree(TreeNode* root) {
        auto res = dfsBinary(root);
        return max(res.first, res.second);
    }

    // General Undirected N-ary Tree OA Version
    long long maxWeightIndependentSet(int n, const vector<pair<int, int>>& edges, const vector<int>& val) {
        if (n == 0) return 0;
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e.first].push_back(e.second);
            adj[e.second].push_back(e.first);
        }
        auto res = dfsNary(0, -1, adj, val);
        return max(res.first, res.second);
    }
};

int main() {
    Solution sol;

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    assert(sol.robBinaryTree(root) == 7);

    assert(sol.maxWeightIndependentSet(4, {{0, 1}, {0, 2}, {0, 3}}, {5, 3, 4, 2}) == 9);

    // Cleanup binary tree
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    cout << "33_tree_dp_house_robber_iii passed all tests!\n";
    return 0;
}
