#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class PathSumIII {
private:
    void dfs(TreeNode* node, long long currentSum, int targetSum,
             unordered_map<long long, int>& prefixCount, int& totalPaths) {
        if (!node) return;

        currentSum += node->val;

        // Check if there is a prefix sum that makes a sub-path equal to targetSum
        if (prefixCount.count(currentSum - targetSum)) {
            totalPaths += prefixCount[currentSum - targetSum];
        }

        // Add current prefix sum to map
        prefixCount[currentSum]++;

        dfs(node->left, currentSum, targetSum, prefixCount, totalPaths);
        dfs(node->right, currentSum, targetSum, prefixCount, totalPaths);

        // Backtrack: remove current sum before returning to parent
        prefixCount[currentSum]--;
    }

public:
    // =========================================================================
    // 1. Optimal Prefix Sum Hash Map Approach
    // Time Complexity: O(N)
    // Space Complexity: O(H)
    // =========================================================================
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixCount;
        prefixCount[0] = 1; // Base case: path starting directly from root
        int totalPaths = 0;
        dfs(root, 0, targetSum, prefixCount, totalPaths);
        return totalPaths;
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
    PathSumIII solver;

    // Tree: [10, 5, -3, 3, 2, -1, 11, 3, -2, -1, 1]
    TreeNode* root = buildTree({10, 5, -3, 3, 2, -1, 11, 3, -2, -1, 1});
    cout << "Total Paths Summing to 8: " << solver.pathSum(root, 8) << " (Expected: 3)\n";

    freeTree(root);
    return 0;
}
