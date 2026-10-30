#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTreeMaximumPathSum {
private:
    int maxGain(TreeNode* node, int& globalMax) {
        if (!node) return 0;

        // Prune negative contributions by taking max with 0
        int leftGain = max(0, maxGain(node->left, globalMax));
        int rightGain = max(0, maxGain(node->right, globalMax));

        // Path sum with current node as the highest bridge
        int currentArchSum = node->val + leftGain + rightGain;
        globalMax = max(globalMax, currentArchSum);

        // Return max contribution towards parent
        return node->val + max(leftGain, rightGain);
    }

public:
    // =========================================================================
    // 1. Single Pass Bottom-Up DP on Trees
    // Time Complexity: O(N)
    // Space Complexity: O(H)
    // =========================================================================
    int maxPathSum(TreeNode* root) {
        int globalMax = INT_MIN;
        maxGain(root, globalMax);
        return globalMax;
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
    BinaryTreeMaximumPathSum solver;

    // Tree 1: [1, 2, 3] -> 6
    TreeNode* t1 = buildTree({1, 2, 3});
    cout << "Test 1 Max Path Sum: " << solver.maxPathSum(t1) << " (Expected: 6)\n";
    freeTree(t1);

    // Tree 2: [-10, 9, 20, -1, -1, 15, 7] -> 42
    TreeNode* t2 = buildTree({-10, 9, 20, -1, -1, 15, 7});
    cout << "Test 2 Max Path Sum: " << solver.maxPathSum(t2) << " (Expected: 42)\n";
    freeTree(t2);

    return 0;
}
