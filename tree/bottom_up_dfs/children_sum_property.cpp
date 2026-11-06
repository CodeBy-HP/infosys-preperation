#include <iostream>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 1. Check if tree satisfies Children Sum Property
bool checkChildrenSum(TreeNode* root) {
    if (!root) return true;
    // Leaf nodes satisfy property trivially
    if (!root->left && !root->right) return true;

    int childSum = 0;
    if (root->left) childSum += root->left->val;
    if (root->right) childSum += root->right->val;

    if (root->val != childSum) return false;

    return checkChildrenSum(root->left) && checkChildrenSum(root->right);
}

// 2. Convert tree to satisfy Children Sum Property (increments only)
void changeTree(TreeNode* root) {
    if (!root) return;

    int childSum = 0;
    if (root->left) childSum += root->left->val;
    if (root->right) childSum += root->right->val;

    // Top-down: ensure children are at least as large as parent
    if (childSum >= root->val) {
        root->val = childSum;
    } else {
        if (root->left) root->left->val = root->val;
        if (root->right) root->right->val = root->val;
    }

    // Recurse down
    changeTree(root->left);
    changeTree(root->right);

    // Bottom-up: parent takes the sum of updated children
    int total = 0;
    if (root->left) total += root->left->val;
    if (root->right) total += root->right->val;

    if (root->left || root->right) {
        root->val = total;
    }
}

int main() {
    /*
            10
           /  \
          8    2
         / \    \
        3   5    2
       Valid Children Sum Tree!
    */
    TreeNode* valid = new TreeNode(10);
    valid->left = new TreeNode(8);
    valid->right = new TreeNode(2);
    valid->left->left = new TreeNode(3);
    valid->left->right = new TreeNode(5);
    valid->right->right = new TreeNode(2);

    assert(checkChildrenSum(valid) == true);

    /*
            50
           /  \
          7    2
         / \    \
        3   5    1
       Invalid initially!
    */
    TreeNode* invalid = new TreeNode(50);
    invalid->left = new TreeNode(7);
    invalid->right = new TreeNode(2);
    invalid->left->left = new TreeNode(3);
    invalid->left->right = new TreeNode(5);
    invalid->right->right = new TreeNode(1);

    assert(checkChildrenSum(invalid) == false);

    // Convert invalid tree
    changeTree(invalid);
    assert(checkChildrenSum(invalid) == true);

    std::cout << "All Children Sum Property tests passed successfully!\n";
    return 0;
}

