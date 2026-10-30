#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BalancedBinaryTree {
private:
    // Returns height of node, or -1 if the subtree is already unbalanced
    int checkHeight(TreeNode* node) {
        if (!node) return 0;

        int leftH = checkHeight(node->left);
        if (leftH == -1) return -1; // Propagate failure immediately

        int rightH = checkHeight(node->right);
        if (rightH == -1) return -1; // Propagate failure immediately

        if (abs(leftH - rightH) > 1) return -1; // Imbalance detected!

        return 1 + max(leftH, rightH);
    }

public:
    // =========================================================================
    // 1. Optimal Bottom-Up DFS with -1 Short-Circuit
    // Time Complexity: O(N)
    // Space Complexity: O(H)
    // =========================================================================
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
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
    BalancedBinaryTree solver;

    // Test 1: Balanced tree [3, 9, 20, -1, -1, 15, 7] -> true
    TreeNode* t1 = buildTree({3, 9, 20, -1, -1, 15, 7});
    cout << "Tree 1 Balanced: " << (solver.isBalanced(t1) ? "true" : "false") << " (Expected: true)\n";
    freeTree(t1);

    // Test 2: Unbalanced tree [1, 2, 2, 3, 3, -1, -1, 4, 4] -> false
    TreeNode* t2 = buildTree({1, 2, 2, 3, 3, -1, -1, 4, 4});
    cout << "Tree 2 Balanced: " << (solver.isBalanced(t2) ? "true" : "false") << " (Expected: false)\n";
    freeTree(t2);

    return 0;
}
