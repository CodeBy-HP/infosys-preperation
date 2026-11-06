#include <iostream>
#include <climits>
#include <algorithm>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct NodeValue {
    int minNode;
    int maxNode;
    int maxSize;

    NodeValue(int minVal, int maxVal, int size)
        : minNode(minVal), maxNode(maxVal), maxSize(size) {}
};

NodeValue largestBSTSubtreeHelper(TreeNode* root) {
    // An empty tree is a BST of size 0
    if (!root) {
        return NodeValue(INT_MAX, INT_MIN, 0);
    }

    auto left = largestBSTSubtreeHelper(root->left);
    auto right = largestBSTSubtreeHelper(root->right);

    // Current node is greater than max in left and smaller than min in right
    if (left.maxNode < root->val && root->val < right.minNode) {
        // Valid BST
        return NodeValue(
            std::min(root->val, left.minNode),
            std::max(root->val, right.maxNode),
            1 + left.maxSize + right.maxSize
        );
    }

    // Invalid BST: propagate [-INF, +INF] so ancestors fail, and return max size found so far
    return NodeValue(INT_MIN, INT_MAX, std::max(left.maxSize, right.maxSize));
}

int largestBSTSubtree(TreeNode* root) {
    return largestBSTSubtreeHelper(root).maxSize;
}

int main() {
    /*
              10
            /    \
           5      15
          / \       \
         1   8       7
       Largest BST is rooted at 5: size = 3
    */
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);

    assert(largestBSTSubtree(root) == 3);

    /*
        Entire tree is a valid BST:
                4
               / \
              2   5
             / \
            1   3
        Size = 5
    */
    TreeNode* fullBST = new TreeNode(4);
    fullBST->left = new TreeNode(2);
    fullBST->right = new TreeNode(5);
    fullBST->left->left = new TreeNode(1);
    fullBST->left->right = new TreeNode(3);

    assert(largestBSTSubtree(fullBST) == 5);

    // Empty tree
    assert(largestBSTSubtree(nullptr) == 0);

    // Single node
    TreeNode* single = new TreeNode(42);
    assert(largestBSTSubtree(single) == 1);

    std::cout << "All Largest BST in Binary Tree tests passed successfully!\n";
    return 0;
}

