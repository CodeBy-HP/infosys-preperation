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

class BinaryTreeRightSideView {
public:
    // =========================================================================
    // 1. Reverse Preorder DFS (Root -> Right -> Left)
    // Time Complexity: O(N)
    // Space Complexity: O(H) recursion stack
    // =========================================================================
    void dfs(TreeNode* node, int depth, vector<int>& view) {
        if (!node) return;

        // If visiting this depth for the first time, it's the rightmost node
        if (depth == (int)view.size()) {
            view.push_back(node->val);
        }

        // Visit RIGHT subtree first!
        dfs(node->right, depth + 1, view);
        dfs(node->left, depth + 1, view);
    }

    vector<int> rightSideViewDFS(TreeNode* root) {
        vector<int> view;
        dfs(root, 0, view);
        return view;
    }

    // =========================================================================
    // 2. BFS Level-by-Level Approach
    // Time Complexity: O(N)
    // Space Complexity: O(W)
    // =========================================================================
    vector<int> rightSideViewBFS(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // Last element in this level is visible from right
                if (i == levelSize - 1) {
                    result.push_back(curr->val);
                }

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
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
    BinaryTreeRightSideView solver;

    // Tree: [1, 2, 3, -1, 5, -1, 4]
    TreeNode* root = buildTree({1, 2, 3, -1, 5, -1, 4});

    vector<int> resDFS = solver.rightSideViewDFS(root);
    cout << "Right Side View (DFS): [ ";
    for (int v : resDFS) cout << v << " ";
    cout << "] (Expected: [ 1 3 4 ])\n";

    vector<int> resBFS = solver.rightSideViewBFS(root);
    cout << "Right Side View (BFS): [ ";
    for (int v : resBFS) cout << v << " ";
    cout << "] (Expected: [ 1 3 4 ])\n";

    freeTree(root);
    return 0;
}
