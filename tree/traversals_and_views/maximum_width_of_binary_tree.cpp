#include <iostream>
#include <queue>
#include <algorithm>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;

    long long maxWidth = 0;
    // Queue holds {node, index}
    std::queue<std::pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});

    while (!q.empty()) {
        int size = q.size();
        unsigned long long minIndex = q.front().second; // minimum index at current level
        unsigned long long first = 0, last = 0;

        for (int i = 0; i < size; ++i) {
            // Normalize index to prevent 64-bit overflow on deep trees
            unsigned long long currIndex = q.front().second - minIndex;
            TreeNode* node = q.front().first;
            q.pop();

            if (i == 0) first = currIndex;
            if (i == size - 1) last = currIndex;

            if (node->left) {
                q.push({node->left, 2 * currIndex + 1});
            }
            if (node->right) {
                q.push({node->right, 2 * currIndex + 2});
            }
        }

        maxWidth = std::max(maxWidth, (long long)(last - first + 1));
    }

    return (int)maxWidth;
}

int main() {
    /*
              1
            /   \
           3     2
          / \     \
         5   3     9
       Level 0: width = 1
       Level 1: width = 2
       Level 2: width = 4 (from 5 to 9)
       Max width = 4
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    assert(widthOfBinaryTree(root) == 4);

    /*
              1
            /   \
           3     2
          /       \
         5         9
        /           \
       6             7
       Max width = 8
    */
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(5);
    root2->right->right = new TreeNode(9);
    root2->left->left->left = new TreeNode(6);
    root2->right->right->right = new TreeNode(7);

    assert(widthOfBinaryTree(root2) == 8);

    // Empty tree
    assert(widthOfBinaryTree(nullptr) == 0);

    // Single node
    TreeNode* single = new TreeNode(1);
    assert(widthOfBinaryTree(single) == 1);

    std::cout << "All Maximum Width of Binary Tree tests passed successfully!\n";
    return 0;
}

