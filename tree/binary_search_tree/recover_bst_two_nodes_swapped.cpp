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

class Solution {
private:
    TreeNode* first = nullptr;
    TreeNode* middle = nullptr;
    TreeNode* last = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // Check for violation of ascending order
        if (prev != nullptr && root->val < prev->val) {
            if (first == nullptr) {
                // First violation: mark first and middle
                first = prev;
                middle = root;
            } else {
                // Second violation: mark last
                last = root;
            }
        }

        prev = root;

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);

        inorder(root);

        if (first && last) {
            std::swap(first->val, last->val);
        } else if (first && middle) {
            std::swap(first->val, middle->val);
        }

        delete prev;
    }
};

// Verification helper: check if valid BST
bool isValidBST(TreeNode* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValidBST(root->left, minVal, root->val) &&
           isValidBST(root->right, root->val, maxVal);
}

int main() {
    /*
        Mistake Tree 1 (Non-adjacent swapped: 1 and 3):
                1
               /
              3
               \
                2
    */
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->left->right = new TreeNode(2);

    assert(!isValidBST(root1, LLONG_MIN, LLONG_MAX));

    Solution sol1;
    sol1.recoverTree(root1);

    assert(isValidBST(root1, LLONG_MIN, LLONG_MAX));
    assert(root1->val == 3 && root1->left->val == 1 && root1->left->right->val == 2);

    /*
        Mistake Tree 2 (Adjacent swapped: 2 and 3):
                3
               / \
              1   4
                 /
                2
    */
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(2);

    assert(!isValidBST(root2, LLONG_MIN, LLONG_MAX));

    Solution sol2;
    sol2.recoverTree(root2);

    assert(isValidBST(root2, LLONG_MIN, LLONG_MAX));
    assert(root2->val == 2 && root2->right->left->val == 3);

    std::cout << "All Recover BST tests passed successfully!\n";
    return 0;
}

