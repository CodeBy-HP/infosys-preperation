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

class LowestCommonAncestorBinaryTree {
public:
    // =========================================================================
    // 1. Bottom-Up Scouting DFS
    // Time Complexity: O(N)
    // Space Complexity: O(H) call stack
    // =========================================================================
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base Case 1: Dead end
        if (!root) return nullptr;
        
        // Base Case 2: We found one of the VIPs! Report back immediately.
        if (root == p || root == q) return root;
        
        // Send search parties down both branches
        TreeNode* left_report = lowestCommonAncestor(root->left, p, q);
        TreeNode* right_report = lowestCommonAncestor(root->right, p, q);
        
        // INTERSECTION FOUND: If both branches found a target, this node is the LCA.
        if (left_report != nullptr && right_report != nullptr) {
            return root;
        }
        
        // ONLY ONE FOUND: Pass the successful report up the chain.
        // If left found something, return left. Else, return right (which might be null).
        if (left_report != nullptr) {
            return left_report;
        } else {
            return right_report;
        }
    }
};

TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    TreeNode* left = findNode(root->left, val);
    if (left) return left;
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
    LowestCommonAncestorBinaryTree solver;

    // Tree: [3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4]
    TreeNode* root = buildTree({3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4});
    TreeNode* p = findNode(root, 5);
    TreeNode* q = findNode(root, 1);

    TreeNode* lca1 = solver.lowestCommonAncestor(root, p, q);
    cout << "LCA of 5 and 1: " << (lca1 ? lca1->val : -1) << " (Expected: 3)\n";

    TreeNode* q2 = findNode(root, 4);
    TreeNode* lca2 = solver.lowestCommonAncestor(root, p, q2);
    cout << "LCA of 5 and 4: " << (lca2 ? lca2->val : -1) << " (Expected: 5)\n";

    freeTree(root);
    return 0;
}
