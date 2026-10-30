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

class BinaryTreeZigzagLevelOrder {
public:
    // =========================================================================
    // 1. Direct Index Placement BFS
    // Time Complexity: O(N)
    // Space Complexity: O(W) where W is max level width
    // =========================================================================
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level(levelSize);

            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // Compute destination index based on alternating direction
                int index = leftToRight ? i : (levelSize - 1 - i);
                level[index] = curr->val;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            result.push_back(move(level));
            leftToRight = !leftToRight; // Flip direction
        }

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
    BinaryTreeZigzagLevelOrder solver;

    // Tree: [3, 9, 20, -1, -1, 15, 7]
    TreeNode* root = buildTree({3, 9, 20, -1, -1, 15, 7});
    vector<vector<int>> res = solver.zigzagLevelOrder(root);

    cout << "Zigzag Level Order:\n";
    for (const auto& lvl : res) {
        cout << "  [ ";
        for (int v : lvl) cout << v << " ";
        cout << "]\n";
    }

    freeTree(root);
    return 0;
}
