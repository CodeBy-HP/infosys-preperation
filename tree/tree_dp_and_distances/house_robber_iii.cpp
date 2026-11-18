#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recusion with Memo
class Solution {
private:
    // Two maps to track the two different states for each node
    unordered_map<TreeNode*, int> memoToggleOn;
    unordered_map<TreeNode*, int> memoToggleOff;

    int solve(TreeNode* node, bool canRob) {
        if (!node) return 0;

        if (canRob) {
            // Check cache
            if (memoToggleOn.count(node)) return memoToggleOn[node];

            // Choice 1: Pick it (Toggle turns OFF for children)
            int pick = node->val + solve(node->left, false) + solve(node->right, false);
            
            // Choice 2: Not Pick it (Toggle stays ON for children)
            int notPick = solve(node->left, true) + solve(node->right, true);

            // Cache and return the max of both choices
            return memoToggleOn[node] = max(pick, notPick);
            
        } else {
            // Check cache
            if (memoToggleOff.count(node)) return memoToggleOff[node];

            // We CANNOT pick it. 
            // We just skip it, meaning the children are now unlocked (Toggle turns ON)
            int notPick = solve(node->left, true) + solve(node->right, true);

            // Cache and return
            return memoToggleOff[node] = notPick;
        }
    }

public:
    int rob(TreeNode* root) {
        // We start at the root with full permission to rob it
        return solve(root, true);
    }
};

class HouseRobberIII {
private:
    // Returns {rob_this_node, skip_this_node}
    pair<int, int> robDFS(TreeNode* node) {
        if (!node) return {0, 0};

        auto [robLeft, skipLeft] = robDFS(node->left);
        auto [robRight, skipRight] = robDFS(node->right);

        // Case 1: Rob this node (children MUST be skipped)
        int robThis = node->val + skipLeft + skipRight;

        // Case 2: Skip this node (children can be robbed or skipped, take max)
        int skipThis = max(robLeft, skipLeft) + max(robRight, skipRight);

        return {robThis, skipThis};
    }

public:
    // =========================================================================
    // 1. Bottom-Up State Pair DP on Trees
    // Time Complexity: O(N)
    // Space Complexity: O(H) call stack
    // =========================================================================
    int rob(TreeNode* root) {
        auto [robRoot, skipRoot] = robDFS(root);
        return max(robRoot, skipRoot);
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
    HouseRobberIII solver;

    // Tree 1: [3, 2, 3, -1, 3, -1, 1] -> 7
    TreeNode* t1 = buildTree({3, 2, 3, -1, 3, -1, 1});
    cout << "Test 1 Max Robbed Amount: " << solver.rob(t1) << " (Expected: 7)\n";
    freeTree(t1);

    // Tree 2: [3, 4, 5, 1, 3, -1, 1] -> 9
    TreeNode* t2 = buildTree({3, 4, 5, 1, 3, -1, 1});
    cout << "Test 2 Max Robbed Amount: " << solver.rob(t2) << " (Expected: 9)\n";
    freeTree(t2);

    return 0;
}
