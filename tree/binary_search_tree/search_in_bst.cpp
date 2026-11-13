#include <iostream>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 1. Recursive Search in BST
TreeNode* searchBSTRecursive(TreeNode* root, int val) {
    if (!root || root->val == val) {
        return root;
    }
    if (val < root->val) {
        return searchBSTRecursive(root->left, val);
    }
    return searchBSTRecursive(root->right, val);
}

// 2. Iterative Search in BST (O(1) auxiliary space)
TreeNode* searchBSTIterative(TreeNode* root, int val) {
    TreeNode* curr = root;
    while (curr != nullptr && curr->val != val) {
        if (val < curr->val) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return curr;
}

int main() {
    /*
            4
           / \
          2   7
         / \
        1   3
    */
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    // Search for 2
    TreeNode* resRec = searchBSTRecursive(root, 2);
    TreeNode* resIter = searchBSTIterative(root, 2);
    assert(resRec != nullptr && resRec->val == 2);
    assert(resIter != nullptr && resIter->val == 2);

    // Search for 5 (not in tree)
    assert(searchBSTRecursive(root, 5) == nullptr);
    assert(searchBSTIterative(root, 5) == nullptr);

    // Search for root (4)
    assert(searchBSTIterative(root, 4) == root);

    // Search on empty tree
    assert(searchBSTIterative(nullptr, 10) == nullptr);

    std::cout << "All Search in BST tests passed successfully!\n";
    return 0;
}

