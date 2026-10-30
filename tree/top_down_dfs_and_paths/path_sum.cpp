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

class PathSum {
public:
    // =========================================================================
    // 1. Top-Down DFS (Subtract Value at Each Step)
    // Time Complexity: O(N)
    // Space Complexity: O(H) call stack
    // =========================================================================
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        // If it's a leaf node, check if value matches remaining sum
        if (!root->left && !root->right) {
            return root->val == targetSum;
        }

        int remaining = targetSum - root->val;
        return hasPathSum(root->left, remaining) || hasPathSum(root->right, remaining);
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
    PathSum solver;

    // Tree: [5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1]
    TreeNode* root = buildTree({5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1});
    cout << "Has Path Sum 22: " << (solver.hasPathSum(root, 22) ? "true" : "false") << " (Expected: true)\n";
    cout << "Has Path Sum 100: " << (solver.hasPathSum(root, 100) ? "true" : "false") << " (Expected: false)\n";

    freeTree(root);
    return 0;
}
