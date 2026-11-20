#include <iostream>
#include <vector>
#include <climits>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// Tracking with [minValue,maxValue]
class Solution {
    int i = 0;

    TreeNode* build(vector<int>& preorder, long minVal, long maxVal) {
        // Stop if we used all elements OR current element doesn't fit in this subtree's range
        if (i == preorder.size() || preorder[i] < minVal || preorder[i] > maxVal) {
            return nullptr;
        }

        int val = preorder[i++];
        TreeNode* root = new TreeNode(val);

        // Left child must be strictly smaller than val
        root->left = build(preorder, minVal, (long)val - 1);

        // Right child must be strictly greater than val
        root->right = build(preorder, (long)val + 1, maxVal);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        i = 0;
        return build(preorder, LONG_MIN, LONG_MAX);
    }
};

// Optimal O(N) single-pass with upper bound
TreeNode* buildHelper(const std::vector<int>& preorder, int& idx, int bound) {
    if (idx == (int)preorder.size() || preorder[idx] > bound) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[idx++]);
    root->left = buildHelper(preorder, idx, root->val);
    root->right = buildHelper(preorder, idx, bound);

    return root;
}

TreeNode* bstFromPreorder(const std::vector<int>& preorder) {
    int idx = 0;
    return buildHelper(preorder, idx, INT_MAX);
}

// Verification helper: extract preorder from reconstructed tree
void getPreorder(TreeNode* root, std::vector<int>& res) {
    if (!root) return;
    res.push_back(root->val);
    getPreorder(root->left, res);
    getPreorder(root->right, res);
}

// Verification helper: check if valid BST
bool isValidBST(TreeNode* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValidBST(root->left, minVal, root->val) &&
           isValidBST(root->right, root->val, maxVal);
}

int main() {
    /*
        Preorder: [8, 5, 1, 7, 10, 12]
        Reconstructed BST:
                  8
                /   \
               5     10
              / \      \
             1   7      12
    */
    std::vector<int> preorder = {8, 5, 1, 7, 10, 12};
    TreeNode* root = bstFromPreorder(preorder);

    assert(isValidBST(root, LLONG_MIN, LLONG_MAX));

    std::vector<int> checkPre;
    getPreorder(root, checkPre);
    assert(checkPre == preorder);

    // Single element
    TreeNode* single = bstFromPreorder({50});
    assert(single != nullptr && single->val == 50);

    // Empty array
    assert(bstFromPreorder({}) == nullptr);

    std::cout << "All Construct BST from Preorder tests passed successfully!\n";
    return 0;
}

