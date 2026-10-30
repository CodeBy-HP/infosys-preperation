#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class KthSmallestInBST {
private:
    void inorder(TreeNode* node, int& k, int& result) {
        if (!node || k == 0) return;

        inorder(node->left, k, result);

        k--;
        if (k == 0) {
            result = node->val;
            return;
        }

        if (k > 0) {
            inorder(node->right, k, result);
        }
    }

public:
    // =========================================================================
    // 1. Recursive In-Order with Early Pruning
    // Time Complexity: O(H + k)
    // Space Complexity: O(H)
    // =========================================================================
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        inorder(root, k, result);
        return result;
    }

    // =========================================================================
    // 2. Iterative Stack Approach
    // Time Complexity: O(H + k)
    // Space Complexity: O(H)
    // =========================================================================
    int kthSmallestIterative(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            k--;
            if (k == 0) return curr->val;

            curr = curr->right;
        }

        return -1;
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
    KthSmallestInBST solver;

    // Tree: [5, 3, 6, 2, 4, -1, -1, 1], k = 3 -> Expected: 3
    TreeNode* root = buildTree({5, 3, 6, 2, 4, -1, -1, 1});
    cout << "3rd Smallest (Recursive): " << solver.kthSmallest(root, 3) << " (Expected: 3)\n";
    cout << "3rd Smallest (Iterative): " << solver.kthSmallestIterative(root, 3) << " (Expected: 3)\n";

    freeTree(root);
    return 0;
}
