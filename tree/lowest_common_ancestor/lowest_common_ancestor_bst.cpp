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

class LowestCommonAncestorBST {
public:
    // =========================================================================
    // 1. Optimal Iterative BST Split Point Search
    // Time Complexity: O(H) where H is tree height
    // Space Complexity: O(1)
    // =========================================================================
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;

        while (curr) {
            if (p->val < curr->val && q->val < curr->val) {
                // Both are in the left subtree
                curr = curr->left;
            } else if (p->val > curr->val && q->val > curr->val) {
                // Both are in the right subtree
                curr = curr->right;
            } else {
                // Split point found: curr is the LCA!
                return curr;
            }
        }

        return nullptr;
    }
};

TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    if (val < root->val) return findNode(root->left, val);
    return findNode(root->right, val);
}

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
    LowestCommonAncestorBST solver;

    // BST: [6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5]
    TreeNode* root = buildTree({6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5});
    TreeNode* p = findNode(root, 2);
    TreeNode* q = findNode(root, 8);

    TreeNode* lca1 = solver.lowestCommonAncestor(root, p, q);
    cout << "LCA of 2 and 8 in BST: " << (lca1 ? lca1->val : -1) << " (Expected: 6)\n";

    TreeNode* q2 = findNode(root, 4);
    TreeNode* lca2 = solver.lowestCommonAncestor(root, p, q2);
    cout << "LCA of 2 and 4 in BST: " << (lca2 ? lca2->val : -1) << " (Expected: 2)\n";

    freeTree(root);
    return 0;
}
