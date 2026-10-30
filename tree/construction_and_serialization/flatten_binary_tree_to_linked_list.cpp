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

class FlattenBinaryTree {
private:
    TreeNode* prev = nullptr;

public:
    // =========================================================================
    // 1. Optimal Morris-Style In-Place Splicing
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    void flattenMorris(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                // Find rightmost node of left subtree
                TreeNode* rightmost = curr->left;
                while (rightmost->right != nullptr) {
                    rightmost = rightmost->right;
                }

                // Splice original right subtree behind rightmost
                rightmost->right = curr->right;

                // Move left subtree to right
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }

    // =========================================================================
    // 2. Reverse Post-Order Traversal (Right -> Left -> Root)
    // Time Complexity: O(N)
    // Space Complexity: O(H) call stack
    // =========================================================================
    void flattenRecursive(TreeNode* root) {
        if (!root) return;

        flattenRecursive(root->right);
        flattenRecursive(root->left);

        root->right = prev;
        root->left = nullptr;
        prev = root;
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

void printFlattened(TreeNode* root) {
    TreeNode* curr = root;
    while (curr) {
        cout << curr->val;
        if (curr->right) cout << " -> ";
        curr = curr->right;
    }
    cout << "\n";
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    FlattenBinaryTree solver;

    // Tree: [1, 2, 5, 3, 4, -1, 6]
    TreeNode* root = buildTree({1, 2, 5, 3, 4, -1, 6});
    solver.flattenMorris(root);

    cout << "Flattened Tree (Morris O(1) space): ";
    printFlattened(root);
    cout << "(Expected: 1 -> 2 -> 3 -> 4 -> 5 -> 6)\n";

    freeTree(root);
    return 0;
}
