#include <iostream>
#include <climits>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 1. Find Minimum Element in BST (Leftmost node)
int findMin(TreeNode* root) {
    if (!root) return -1;
    TreeNode* curr = root;
    while (curr->left != nullptr) {
        curr = curr->left;
    }
    return curr->val;
}

// 2. Find Maximum Element in BST (Rightmost node)
int findMax(TreeNode* root) {
    if (!root) return -1;
    TreeNode* curr = root;
    while (curr->right != nullptr) {
        curr = curr->right;
    }
    return curr->val;
}

int main() {
    /*
              10
            /    \
           5      20
          / \    /  \
         2   8  15  25
        /
       1
    */
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(8);
    root->left->left->left = new TreeNode(1);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(25);

    assert(findMin(root) == 1);
    assert(findMax(root) == 25);

    // Single node tree
    TreeNode* single = new TreeNode(42);
    assert(findMin(single) == 42);
    assert(findMax(single) == 42);

    // Empty tree
    assert(findMin(nullptr) == -1);
    assert(findMax(nullptr) == -1);

    std::cout << "All Minimum and Maximum in BST tests passed successfully!\n";
    return 0;
}

