#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class ValidateBST {
private:
    bool validateRange(TreeNode* node, long long low, long long high) {
        if (!node) return true;

        if (node->val <= low || node->val >= high) {
            return false;
        }

        return validateRange(node->left, low, node->val) &&
               validateRange(node->right, node->val, high);
    }

public:
    // =========================================================================
    // 1. Top-Down Range Validation Approach
    // Time Complexity: O(N)
    // Space Complexity: O(H) call stack
    // =========================================================================
    bool isValidBST(TreeNode* root) {
        return validateRange(root, LLONG_MIN, LLONG_MAX);
    }

    // =========================================================================
    // 2. In-Order Traversal Check (Must Be Strictly Increasing)
    // Time Complexity: O(N)
    // Space Complexity: O(H)
    // =========================================================================
    bool inOrderCheck(TreeNode* node, TreeNode*& prev) {
        if (!node) return true;

        if (!inOrderCheck(node->left, prev)) return false;

        if (prev != nullptr && node->val <= prev->val) {
            return false;
        }
        prev = node;

        return inOrderCheck(node->right, prev);
    }

    bool isValidBSTInOrder(TreeNode* root) {
        TreeNode* prev = nullptr;
        return inOrderCheck(root, prev);
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
    ValidateBST solver;

    // Tree 1: [2, 1, 3] -> Valid BST (true)
    TreeNode* t1 = buildTree({2, 1, 3});
    cout << "Tree 1 Valid BST: " << (solver.isValidBST(t1) ? "true" : "false") << " (Expected: true)\n";
    freeTree(t1);

    // Tree 2: [5, 1, 4, -1, -1, 3, 6] -> Invalid BST (false)
    TreeNode* t2 = buildTree({5, 1, 4, -1, -1, 3, 6});
    cout << "Tree 2 Valid BST: " << (solver.isValidBST(t2) ? "true" : "false") << " (Expected: false)\n";
    freeTree(t2);

    return 0;
}
