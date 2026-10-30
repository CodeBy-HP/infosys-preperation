#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class DiameterOfBinaryTree {
private:
    int calculateHeight(TreeNode* node, int& maxDiameter) {
        if (!node) return 0;

        // Bottom-up information gathering
        int leftHeight = calculateHeight(node->left, maxDiameter);
        int rightHeight = calculateHeight(node->right, maxDiameter);

        // Update diameter that arches over current node
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        // Return single deepest path to parent
        return 1 + max(leftHeight, rightHeight);
    }

public:
    // =========================================================================
    // 1. Bottom-Up DFS Single Pass
    // Time Complexity: O(N)
    // Space Complexity: O(H)
    // =========================================================================
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        calculateHeight(root, maxDiameter);
        return maxDiameter;
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
    DiameterOfBinaryTree solver;

    // Tree: [1, 2, 3, 4, 5]
    TreeNode* root = buildTree({1, 2, 3, 4, 5});
    cout << "Diameter: " << solver.diameterOfBinaryTree(root) << " (Expected: 3)\n";

    freeTree(root);
    return 0;
}
