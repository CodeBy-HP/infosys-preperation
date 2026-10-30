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

class BinaryTreeLevelOrderTraversal {
public:
    // =========================================================================
    // 1. BFS Level-Size Snapshot Approach
    // Time Complexity: O(N)
    // Space Complexity: O(W) where W is the maximum width of the tree
    // =========================================================================
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size(); // Freeze row count
            vector<int> currentLevel;
            currentLevel.reserve(levelSize);

            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();

                currentLevel.push_back(curr->val);

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            result.push_back(move(currentLevel));
        }

        return result;
    }

    // =========================================================================
    // 2. DFS Preorder with Depth Indexing
    // Time Complexity: O(N)
    // Space Complexity: O(H) recursion stack
    // =========================================================================
    void dfs(TreeNode* node, int depth, vector<vector<int>>& result) {
        if (!node) return;
        if (depth == (int)result.size()) {
            result.push_back({});
        }
        result[depth].push_back(node->val);
        dfs(node->left, depth + 1, result);
        dfs(node->right, depth + 1, result);
    }

    vector<vector<int>> levelOrderDFS(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, 0, result);
        return result;
    }
};

// Helper: build tree from level order array (-1 represents null)
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
    BinaryTreeLevelOrderTraversal solver;

    // Tree: [3, 9, 20, -1, -1, 15, 7]
    TreeNode* root = buildTree({3, 9, 20, -1, -1, 15, 7});

    vector<vector<int>> res = solver.levelOrder(root);
    cout << "Level Order Traversal:\n";
    for (const auto& level : res) {
        cout << "  [ ";
        for (int v : level) cout << v << " ";
        cout << "]\n";
    }

    freeTree(root);
    return 0;
}
