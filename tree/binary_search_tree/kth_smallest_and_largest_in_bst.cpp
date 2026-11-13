#include <iostream>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 1. K-th Smallest via Inorder (Left -> Root -> Right)
void inorderSmallest(TreeNode* root, int& k, int& result) {
    if (!root || k <= 0) return;

    inorderSmallest(root->left, k, result);

    k--;
    if (k == 0) {
        result = root->val;
        return;
    }

    inorderSmallest(root->right, k, result);
}

int kthSmallest(TreeNode* root, int k) {
    int result = -1;
    inorderSmallest(root, k, result);
    return result;
}

// 2. K-th Largest via Reverse Inorder (Right -> Root -> Left)
void reverseInorderLargest(TreeNode* root, int& k, int& result) {
    if (!root || k <= 0) return;

    reverseInorderLargest(root->right, k, result);

    k--;
    if (k == 0) {
        result = root->val;
        return;
    }

    reverseInorderLargest(root->left, k, result);
}

int kthLargest(TreeNode* root, int k) {
    int result = -1;
    reverseInorderLargest(root, k, result);
    return result;
}

int main() {
    /*
              5
            /   \
           3     6
          / \
         2   4
        /
       1
       Sorted: [1, 2, 3, 4, 5, 6]
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    // 1st Smallest = 1, 1st Largest = 6
    assert(kthSmallest(root, 1) == 1);
    assert(kthLargest(root, 1) == 6);

    // 3rd Smallest = 3, 3rd Largest = 4
    assert(kthSmallest(root, 3) == 3);
    assert(kthLargest(root, 3) == 4);

    // 6th Smallest = 6, 6th Largest = 1
    assert(kthSmallest(root, 6) == 6);
    assert(kthLargest(root, 6) == 1);

    std::cout << "All K-th Smallest and Largest in BST tests passed successfully!\n";
    return 0;
}

