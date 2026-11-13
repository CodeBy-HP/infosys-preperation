#include <iostream>
#include <vector>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<int> morrisInorder(TreeNode* root) {
    std::vector<int> inorder;
    TreeNode* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            // Case 1: No left subtree, visit node and go right
            inorder.push_back(curr->val);
            curr = curr->right;
        } else {
            // Case 2: Find in-order predecessor
            TreeNode* prev = curr->left;
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }

            if (prev->right == nullptr) {
                // Thread creation
                prev->right = curr;
                curr = curr->left;
            } else {
                // Thread cut (return from left subtree)
                prev->right = nullptr;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }

    return inorder;
}

int main() {
    /*
              1
            /   \
           2     3
          / \
         4   5
       Inorder: [4, 2, 5, 1, 3]
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::vector<int> expected = {4, 2, 5, 1, 3};
    assert(morrisInorder(root) == expected);

    // Verify tree pointers are restored after Morris traversal
    assert(root->val == 1);
    assert(root->left->val == 2);
    assert(root->left->right->right == nullptr);

    // Empty tree
    assert(morrisInorder(nullptr).empty());

    // Single node
    TreeNode* single = new TreeNode(42);
    assert(morrisInorder(single) == std::vector<int>({42}));

    std::cout << "All Morris Inorder Traversal tests passed successfully!\n";
    return 0;
}

