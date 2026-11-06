#include <iostream>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 1. Find Floor in BST (largest value <= X)
int findFloor(TreeNode* root, int x) {
    int floorVal = -1;
    TreeNode* curr = root;

    while (curr != nullptr) {
        if (curr->val == x) {
            return curr->val;
        }
        if (x > curr->val) {
            // Valid candidate, move right to find larger
            floorVal = curr->val;
            curr = curr->right;
        } else {
            // Value is too big, move left
            curr = curr->left;
        }
    }

    return floorVal;
}

// 2. Find Ceil in BST (smallest value >= X)
int findCeil(TreeNode* root, int x) {
    int ceilVal = -1;
    TreeNode* curr = root;

    while (curr != nullptr) {
        if (curr->val == x) {
            return curr->val;
        }
        if (x < curr->val) {
            // Valid candidate, move left to find smaller
            ceilVal = curr->val;
            curr = curr->left;
        } else {
            // Value is too small, move right
            curr = curr->right;
        }
    }

    return ceilVal;
}

int main() {
    /*
              10
            /    \
           5      13
          / \    /  \
         3   6  11   14
        / \   \
       2   4   9
    */
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(6);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);

    // Target = 8 -> Floor = 6, Ceil = 9
    assert(findFloor(root, 8) == 6);
    assert(findCeil(root, 8) == 9);

    // Exact match: Target = 10 -> Floor = 10, Ceil = 10
    assert(findFloor(root, 10) == 10);
    assert(findCeil(root, 10) == 10);

    // Target = 1 (smaller than min key 2) -> Floor = -1, Ceil = 2
    assert(findFloor(root, 1) == -1);
    assert(findCeil(root, 1) == 2);

    // Target = 15 (larger than max key 14) -> Floor = 14, Ceil = -1
    assert(findFloor(root, 15) == 14);
    assert(findCeil(root, 15) == -1);

    std::cout << "All Floor and Ceil in BST tests passed successfully!\n";
    return 0;
}

