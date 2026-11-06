#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isLeaf(TreeNode* node) {
    return node && !node->left && !node->right;
}

void addLeftBoundary(TreeNode* root, std::vector<int>& res) {
    TreeNode* curr = root->left;
    while (curr) {
        if (!isLeaf(curr)) {
            res.push_back(curr->val);
        }
        if (curr->left) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
}

void addLeaves(TreeNode* root, std::vector<int>& res) {
    if (!root) return;
    if (isLeaf(root)) {
        res.push_back(root->val);
        return;
    }
    addLeaves(root->left, res);
    addLeaves(root->right, res);
}

void addRightBoundary(TreeNode* root, std::vector<int>& res) {
    TreeNode* curr = root->right;
    std::vector<int> temp;
    while (curr) {
        if (!isLeaf(curr)) {
            temp.push_back(curr->val);
        }
        if (curr->right) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    // Reverse right boundary so it ascends bottom-up
    for (int i = (int)temp.size() - 1; i >= 0; --i) {
        res.push_back(temp[i]);
    }
}

std::vector<int> boundaryTraversal(TreeNode* root) {
    std::vector<int> res;
    if (!root) return res;

    // 1. Root
    if (!isLeaf(root)) {
        res.push_back(root->val);
    }

    // 2. Left boundary (excluding leaves)
    addLeftBoundary(root, res);

    // 3. Leaves (all leaves from left to right)
    addLeaves(root, res);

    // 4. Right boundary (bottom-up, excluding leaves)
    addRightBoundary(root, res);

    return res;
}

int main() {
    /*
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
            / \
           8   9
       Boundary: [1, 2, 4, 8, 9, 6, 7, 3]
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::vector<int> expected = {1, 2, 4, 8, 9, 6, 7, 3};
    assert(boundaryTraversal(root) == expected);

    // Single leaf node
    TreeNode* single = new TreeNode(10);
    assert(boundaryTraversal(single) == std::vector<int>({10}));

    // Empty tree
    assert(boundaryTraversal(nullptr).empty());

    std::cout << "All Boundary Traversal tests passed successfully!\n";
    return 0;
}

