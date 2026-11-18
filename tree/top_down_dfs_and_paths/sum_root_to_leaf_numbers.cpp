#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
private:
    void solve(TreeNode* node, int currentNumber, int& totalSum) {
        if (!node) return;
        
        // Build the number for this specific timeline
        currentNumber = currentNumber * 10 + node->val;
        
        // Leaf node reached: dump the built number into the global bucket
        if (!node->left && !node->right) {
            totalSum += currentNumber;
            return;
        }
        
        // Continue driving the vehicle down the branches
        solve(node->left, currentNumber, totalSum);
        solve(node->right, currentNumber, totalSum);
    }

public:
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        // Pass totalSum by reference (&) so all branches share the same bucket
        solve(root, 0, totalSum); 
        return totalSum;
    }
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class SumRootToLeafNumbers {
private:
    int dfs(TreeNode* node, int currentSum) {
        if (!node) return 0;

        currentSum = currentSum * 10 + node->val;

        // If it's a leaf, this path number is complete
        if (!node->left && !node->right) {
            return currentSum;
        }

        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }

public:
    // =========================================================================
    // 1. Top-Down Digit Accumulation DFS
    // Time Complexity: O(N)
    // Space Complexity: O(H) call stack
    // =========================================================================
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
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
    SumRootToLeafNumbers solver;

    // Tree: [4, 9, 0, 5, 1] -> 1026
    TreeNode* root = buildTree({4, 9, 0, 5, 1});
    cout << "Sum Root to Leaf Numbers: " << solver.sumNumbers(root) << " (Expected: 1026)\n";

    freeTree(root);
    return 0;
}
