#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class PathSumII {
private:
    void dfs(TreeNode* node, int remainingSum, vector<int>& path, vector<vector<int>>& result) {
        if (!node) return;

        // Add current node to path
        path.push_back(node->val);

        // Check if valid leaf matching remaining sum
        if (!node->left && !node->right && node->val == remainingSum) {
            result.push_back(path); // Save matching path
        } else {
            dfs(node->left, remainingSum - node->val, path, result);
            dfs(node->right, remainingSum - node->val, path, result);
        }

        // Backtrack
        path.pop_back();
    }

public:
    // =========================================================================
    // 1. Top-Down DFS with Backtracking
    // Time Complexity: O(N) average, O(N^2) worst case when copying paths
    // Space Complexity: O(H) recursion stack + current path
    // =========================================================================
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, targetSum, path, result);
        return result;
    }
};

TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < nodes.size() && nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    PathSumII solver;

    // Tree: [5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, 5, 1]
    TreeNode* root = buildTree({5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, 5, 1});
    vector<vector<int>> paths = solver.pathSum(root, 22);

    cout << "Path Sum II (target 22):\n";
    for (const auto& p : paths) {
        cout << "  [ ";
        for (int v : p) cout << v << " ";
        cout << "]\n";
    }

    freeTree(root);
    return 0;
}
