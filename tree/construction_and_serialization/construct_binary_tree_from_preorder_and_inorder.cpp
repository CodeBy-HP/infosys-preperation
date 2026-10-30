#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class ConstructBinaryTree {
private:
    int preIndex = 0;
    unordered_map<int, int> inorderMap;

    TreeNode* build(const vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inorderMap[rootVal];

        // Left subtree must be constructed before right (Preorder property: Root, Left, Right)
        root->left = build(preorder, inStart, inIndex - 1);
        root->right = build(preorder, inIndex + 1, inEnd);

        return root;
    }

public:
    // =========================================================================
    // 1. Hash Map Partitioning Approach
    // Time Complexity: O(N)
    // Space Complexity: O(N) for hash map + call stack
    // =========================================================================
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIndex = 0;
        inorderMap.clear();
        for (int i = 0; i < (int)inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return build(preorder, 0, (int)inorder.size() - 1);
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
    ConstructBinaryTree solver;

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = solver.buildTree(preorder, inorder);
    cout << "Reconstructed Tree In-Order: ";
    printInOrder(root);
    cout << "\n(Expected: 9 3 15 20 7)\n";

    freeTree(root);
    return 0;
}
