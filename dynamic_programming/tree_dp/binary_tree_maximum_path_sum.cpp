#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTreeMaximumPathSum {
public:
    // =========================================================================
    // 1. Recursive Top-Down Post-Order Traversal (Idiomatic & Standard)
    // Time Complexity: O(N)
    // Space Complexity: O(H) [Call stack, H = height of tree]
    // =========================================================================
    int maxPathSum(TreeNode* root) {
        int overallMax = -1e9;
        solveRecursive(root, overallMax);
        return overallMax;
    }

private:
    int solveRecursive(TreeNode* node, int& overallMax) {
        if (!node) return 0;

        // Prune negative child paths with max(0, ...)
        int leftGain = max(0, solveRecursive(node->left, overallMax));
        int rightGain = max(0, solveRecursive(node->right, overallMax));

        // Evaluate the "Arch" passing through this node
        int archSum = node->val + leftGain + rightGain;
        overallMax = max(overallMax, archSum);

        // Return the best single branch "Straight Line" to the parent
        return node->val + max(leftGain, rightGain);
    }

public:
    // =========================================================================
    // 2. Iterative Post-Order Traversal (Using Explicit Stack & Hash Map)
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    int maxPathSumIterative(TreeNode* root) {
        if (!root) return 0;

        int overallMax = -1e9;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr;

        // Map storing straight-line gain for each processed node
        unordered_map<TreeNode*, int> gain;

        while (curr || !st.empty()) {
            if (curr) {
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* peekNode = st.top();
                if (peekNode->right && lastVisited != peekNode->right) {
                    curr = peekNode->right;
                } else {
                    st.pop();
                    int leftGain = peekNode->left ? max(0, gain[peekNode->left]) : 0;
                    int rightGain = peekNode->right ? max(0, gain[peekNode->right]) : 0;

                    int archSum = peekNode->val + leftGain + rightGain;
                    overallMax = max(overallMax, archSum);

                    gain[peekNode] = peekNode->val + max(leftGain, rightGain);
                    lastVisited = peekNode;
                }
            }
        }

        return overallMax;
    }
};

int main() {
    BinaryTreeMaximumPathSum solver;

    // Construct test tree: [-10, 9, 20, null, null, 15, 7]
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Test Tree [-10, 9, 20, null, null, 15, 7]:\n";
    cout << "  Recursive Post-Order: " << solver.maxPathSum(root) << "\n";
    cout << "  Iterative Post-Order: " << solver.maxPathSumIterative(root) << " (Expected: 42)\n";

    // Clean up
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}

