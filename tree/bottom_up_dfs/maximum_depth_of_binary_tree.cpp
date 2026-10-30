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

class MaximumDepthOfBinaryTree {
public:
    // =========================================================================
    // 1. Recursive Bottom-Up DFS
    // Time Complexity: O(N)
    // Space Complexity: O(H) call stack
    // =========================================================================
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    // =========================================================================
    // 2. Iterative BFS Level Count
    // Time Complexity: O(N)
    // Space Complexity: O(W)
    // =========================================================================
    int maxDepthBFS(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty()) {
            int sz = q.size();
            depth++;
            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }

        return depth;
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
    MaximumDepthOfBinaryTree solver;

    // Tree: [3, 9, 20, -1, -1, 15, 7]
    TreeNode* root = buildTree({3, 9, 20, -1, -1, 15, 7});
    cout << "Max Depth (Recursive): " << solver.maxDepth(root) << " (Expected: 3)\n";
    cout << "Max Depth (BFS):       " << solver.maxDepthBFS(root) << " (Expected: 3)\n";

    freeTree(root);
    return 0;
}
