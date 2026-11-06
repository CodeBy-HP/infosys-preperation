#include <iostream>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 1. Inorder Successor (smallest node > p->val)
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* successor = nullptr;
    TreeNode* curr = root;

    while (curr != nullptr) {
        if (p->val >= curr->val) {
            curr = curr->right;
        } else {
            successor = curr;
            curr = curr->left;
        }
    }

    return successor;
}

// 2. Inorder Predecessor (greatest node < p->val)
TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
    TreeNode* predecessor = nullptr;
    TreeNode* curr = root;

    while (curr != nullptr) {
        if (p->val <= curr->val) {
            curr = curr->left;
        } else {
            predecessor = curr;
            curr = curr->right;
        }
    }

    return predecessor;
}

int main() {
    /*
              5
            /   \
           2     7
          / \   / \
         1   4 6   9
            /     /
           3     8

       Sorted Inorder: [1, 2, 3, 4, 5, 6, 7, 8, 9]
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root->right->right->left = new TreeNode(8);

    // Target = 4 -> Pred = 3, Succ = 5
    TreeNode* p4 = root->left->right;
    TreeNode* succ4 = inorderSuccessor(root, p4);
    TreeNode* pred4 = inorderPredecessor(root, p4);
    assert(succ4 != nullptr && succ4->val == 5);
    assert(pred4 != nullptr && pred4->val == 3);

    // Target = 1 (Minimum) -> Pred = null, Succ = 2
    TreeNode* p1 = root->left->left;
    assert(inorderPredecessor(root, p1) == nullptr);
    assert(inorderSuccessor(root, p1)->val == 2);

    // Target = 9 (Maximum) -> Pred = 8, Succ = null
    TreeNode* p9 = root->right->right;
    assert(inorderPredecessor(root, p9)->val == 8);
    assert(inorderSuccessor(root, p9) == nullptr);

    std::cout << "All Inorder Successor and Predecessor tests passed successfully!\n";
    return 0;
}

