#include <iostream>
#include <vector>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 1. Recursive Insertion
TreeNode* insertBSTRecursive(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insertBSTRecursive(root->left, val);
    } else {
        root->right = insertBSTRecursive(root->right, val);
    }
    return root;
}

// 2. Iterative Insertion (O(1) auxiliary space)
TreeNode* insertBSTIterative(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }

    TreeNode* curr = root;
    while (true) {
        if (val < curr->val) {
            if (curr->left != nullptr) {
                curr = curr->left;
            } else {
                curr->left = new TreeNode(val);
                break;
            }
        } else {
            if (curr->right != nullptr) {
                curr = curr->right;
            } else {
                curr->right = new TreeNode(val);
                break;
            }
        }
    }

    return root;
}

// Inorder verification helper
void getInorder(TreeNode* root, std::vector<int>& res) {
    if (!root) return;
    getInorder(root->left, res);
    res.push_back(root->val);
    getInorder(root->right, res);
}

int main() {
    /*
            4
           / \
          2   7
         / \
        1   3
       Insert 5
       Inorder should be: [1, 2, 3, 4, 5, 7]
    */
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root = insertBSTIterative(root, 5);

    std::vector<int> inorder;
    getInorder(root, inorder);
    std::vector<int> expected = {1, 2, 3, 4, 5, 7};
    assert(inorder == expected);

    // Insert into empty tree
    TreeNode* emptyRoot = nullptr;
    emptyRoot = insertBSTRecursive(emptyRoot, 10);
    assert(emptyRoot != nullptr && emptyRoot->val == 10);

    std::cout << "All Insert into BST tests passed successfully!\n";
    return 0;
}

