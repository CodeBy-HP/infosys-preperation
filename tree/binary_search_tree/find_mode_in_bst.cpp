#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class FindModeInBST {
private:
    int currVal = 0;
    int currCount = 0;
    int maxCount = 0;
    vector<int> modes;

    void handleValue(int val) {
        if (currCount == 0 || val != currVal) {
            currVal = val;
            currCount = 1;
        } else {
            currCount++;
        }

        if (currCount > maxCount) {
            maxCount = currCount;
            modes.clear();
            modes.push_back(currVal);
        } else if (currCount == maxCount) {
            modes.push_back(currVal);
        }
    }

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        handleValue(node->val);
        inorder(node->right);
    }

public:
    // =========================================================================
    // 1. In-Order Streaming Approach (No Hash Map)
    // Time Complexity: O(N)
    // Space Complexity: O(H) recursion stack
    // =========================================================================
    vector<int> findMode(TreeNode* root) {
        currCount = 0;
        maxCount = 0;
        modes.clear();
        inorder(root);
        return modes;
    }
};

TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < nodes.size() && nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    FindModeInBST solver;

    // Tree: [1, -1, 2, 2]
    TreeNode* root = buildTree({1, -1, 2, 2});
    vector<int> modes = solver.findMode(root);

    cout << "Mode(s): [ ";
    for (int m : modes) cout << m << " ";
    cout << "] (Expected: [ 2 ])\n";

    freeTree(root);
    return 0;
}
