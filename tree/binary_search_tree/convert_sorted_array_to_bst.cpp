#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class ConvertSortedArrayToBST {
private:
    TreeNode* buildBST(const vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);

        return root;
    }

public:
    // =========================================================================
    // 1. Recursive Divide & Conquer
    // Time Complexity: O(N)
    // Space Complexity: O(log N) recursion depth
    // =========================================================================
    TreeNode* sortedArrayToBST(const vector<int>& nums) {
        return buildBST(nums, 0, (int)nums.size() - 1);
    }
};

void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    ConvertSortedArrayToBST solver;

    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = solver.sortedArrayToBST(nums);

    cout << "Converted BST In-Order Traversal: ";
    printInOrder(root);
    cout << "\n(Expected: -10 -3 0 5 9)\n";

    freeTree(root);
    return 0;
}
