#include <iostream>
#include <queue>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 1. Recursive Mirror DFS
bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    if (t1->val != t2->val) return false;

    // Outer pair (t1->left, t2->right) and inner pair (t1->right, t2->left)
    return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

bool isSymmetricRecursive(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

// 2. Iterative Mirror BFS
bool isSymmetricIterative(TreeNode* root) {
    if (!root) return true;

    std::queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);

    while (!q.empty()) {
        TreeNode* t1 = q.front(); q.pop();
        TreeNode* t2 = q.front(); q.pop();

        if (!t1 && !t2) continue;
        if (!t1 || !t2) return false;
        if (t1->val != t2->val) return false;

        // Push mirror pairs: (t1 left, t2 right) and (t1 right, t2 left)
        q.push(t1->left);
        q.push(t2->right);
        q.push(t1->right);
        q.push(t2->left);
    }

    return true;
}

int main() {
    /*
            1
          /   \
         2     2
        / \   / \
       3   4 4   3
    */
    TreeNode* sym = new TreeNode(1);
    sym->left = new TreeNode(2);
    sym->right = new TreeNode(2);
    sym->left->left = new TreeNode(3);
    sym->left->right = new TreeNode(4);
    sym->right->left = new TreeNode(4);
    sym->right->right = new TreeNode(3);

    /*
            1
          /   \
         2     2
          \     \
           3     3
    */
    TreeNode* asym = new TreeNode(1);
    asym->left = new TreeNode(2);
    asym->right = new TreeNode(2);
    asym->left->right = new TreeNode(3);
    asym->right->right = new TreeNode(3);

    assert(isSymmetricRecursive(sym) == true);
    assert(isSymmetricIterative(sym) == true);

    assert(isSymmetricRecursive(asym) == false);
    assert(isSymmetricIterative(asym) == false);

    assert(isSymmetricRecursive(nullptr) == true);
    assert(isSymmetricIterative(nullptr) == true);

    std::cout << "All Symmetric Binary Tree tests passed successfully!\n";
    return 0;
}

