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

// Brute Force
class Solution {
    // Takes the node to delete and returns the root of the merged replacement subtree
    TreeNode* deleteTargetNode(TreeNode* toDelete) {
        if (!toDelete->left) return toDelete->right;
        if (!toDelete->right) return toDelete->left;

        // Both children exist: attach toDelete->left to the leftmost node of toDelete->right
        TreeNode* leftMost = toDelete->right;
        while (leftMost->left != nullptr) {
            leftMost = leftMost->left;
        }
        leftMost->left = toDelete->left;

        return toDelete->right;
    }

public:
    // Time Complexity: O(H) - O(log N) balanced, O(N) skewed
    // Space Complexity: O(1) - iterative, no recursion stack
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        // Edge case: root itself is the target (no parent exists)
        if (root->val == key) {
            return deleteTargetNode(root);
        }

        TreeNode* curr = root;
        while (curr != nullptr) {
            if (key < curr->val) {
                if (curr->left && curr->left->val == key) {
                    curr->left = deleteTargetNode(curr->left);
                    break;
                }
                curr = curr->left;
            } else {
                if (curr->right && curr->right->val == key) {
                    curr->right = deleteTargetNode(curr->right);
                    break;
                }
                curr = curr->right;
            }
        }

        return root;
    }
};

class DeleteNodeInBST {
private:
    TreeNode* getMin(TreeNode* node) {
        while (node->left) node = node->left;
        return node;
    }

public:
    // =========================================================================
    // 1. Recursive 3-Case BST Deletion
    // Time Complexity: O(H) where H is tree height
    // Space Complexity: O(H)
    // =========================================================================
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Target found!
            // Case 1 & 2: 0 or 1 child
            if (!root->left) {
                TreeNode* rightChild = root->right;
                delete root;
                return rightChild;
            } else if (!root->right) {
                TreeNode* leftChild = root->left;
                delete root;
                return leftChild;
            }

            // Case 3: 2 children
            TreeNode* successor = getMin(root->right);
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }

        return root;
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

void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    DeleteNodeInBST solver;

    // Tree: [5, 3, 6, 2, 4, -1, 7], delete key = 3
    TreeNode* root = buildTree({5, 3, 6, 2, 4, -1, 7});
    cout << "Original BST: "; printInOrder(root); cout << "\n";

    root = solver.deleteNode(root, 3);
    cout << "After Deleting 3: "; printInOrder(root); cout << "\n(Expected: 2 4 5 6 7)\n";

    freeTree(root);
    return 0;
}
