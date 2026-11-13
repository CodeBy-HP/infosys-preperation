#include <iostream>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper: Measure depth along left boundary
int getLeftHeight(TreeNode* node) {
    int h = 0;
    while (node) {
        h++;
        node = node->left;
    }
    return h;
}

// Helper: Measure depth along right boundary
int getRightHeight(TreeNode* node) {
    int h = 0;
    while (node) {
        h++;
        node = node->right;
    }
    return h;
}

// O(log^2 N) Optimal Count
int countNodes(TreeNode* root) {
    if (!root) return 0;

    int lh = getLeftHeight(root);
    int rh = getRightHeight(root);

    // If left height == right height, it is a perfect binary tree
    if (lh == rh) {
        return (1 << lh) - 1;
    }

    // Otherwise, 1 (root) + left subtree + right subtree
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// O(N) Naive DFS verification
int countNodesNaive(TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodesNaive(root->left) + countNodesNaive(root->right);
}

int main() {
    /*
            1
           / \
          2   3
         / \  /
        4  5 6
       Complete Binary Tree with 6 nodes.
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    assert(countNodes(root) == 6);
    assert(countNodesNaive(root) == 6);

    // Perfect binary tree of depth 3 (7 nodes)
    root->right->right = new TreeNode(7);
    assert(countNodes(root) == 7);
    assert(countNodesNaive(root) == 7);

    // Empty tree
    assert(countNodes(nullptr) == 0);

    // Single node
    TreeNode* single = new TreeNode(10);
    assert(countNodes(single) == 1);

    std::cout << "All Count Complete Tree Nodes tests passed successfully!\n";
    return 0;
}

