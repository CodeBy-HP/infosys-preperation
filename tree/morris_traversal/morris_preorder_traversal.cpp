#include <iostream>
#include <vector>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<int> morrisPreorder(TreeNode* root) {
    std::vector<int> preorder;
    TreeNode* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            // Case 1: No left child, visit root and move right
            preorder.push_back(curr->val);
            curr = curr->right;
        } else {
            // Case 2: Find in-order predecessor
            TreeNode* prev = curr->left;
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }

            if (prev->right == nullptr) {
                // Thread creation: Visit Root before diving left
                preorder.push_back(curr->val);
                prev->right = curr;
                curr = curr->left;
            } else {
                // Thread cut: Returning from left, move right without re-visiting
                prev->right = nullptr;
                curr = curr->right;
            }
        }
    }

    return preorder;
}

int main() {
    /*
              1
            /   \
           2     3
          / \
         4   5
       Preorder: [1, 2, 4, 5, 3]
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::vector<int> expected = {1, 2, 4, 5, 3};
    assert(morrisPreorder(root) == expected);

    // Verify tree restoration
    assert(root->val == 1);
    assert(root->left->val == 2);
    assert(root->left->right->right == nullptr);

    // Empty tree
    assert(morrisPreorder(nullptr).empty());

    // Single node
    TreeNode* single = new TreeNode(100);
    assert(morrisPreorder(single) == std::vector<int>({100}));

    std::cout << "All Morris Preorder Traversal tests passed successfully!\n";
    return 0;
}

