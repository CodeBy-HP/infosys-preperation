#include <iostream>
#include <queue>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 1. Recursive Check
bool isSameTreeRecursive(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    if (p->val != q->val) return false;

    return isSameTreeRecursive(p->left, q->left) && 
           isSameTreeRecursive(p->right, q->right);
}

// 2. Iterative Check (Simultaneous BFS)
bool isSameTreeIterative(TreeNode* p, TreeNode* q) {
    std::queue<TreeNode*> queue;
    queue.push(p);
    queue.push(q);

    while (!queue.empty()) {
        TreeNode* n1 = queue.front(); queue.pop();
        TreeNode* n2 = queue.front(); queue.pop();

        if (!n1 && !n2) continue;
        if (!n1 || !n2) return false;
        if (n1->val != n2->val) return false;

        queue.push(n1->left);
        queue.push(n2->left);
        queue.push(n1->right);
        queue.push(n2->right);
    }

    return true;
}

int main() {
    // Tree 1: [1, 2, 3]
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);

    // Tree 2: [1, 2, 3]
    TreeNode* t2 = new TreeNode(1);
    t2->left = new TreeNode(2);
    t2->right = new TreeNode(3);

    // Tree 3: [1, 2, null]
    TreeNode* t3 = new TreeNode(1);
    t3->left = new TreeNode(2);

    assert(isSameTreeRecursive(t1, t2) == true);
    assert(isSameTreeIterative(t1, t2) == true);

    assert(isSameTreeRecursive(t1, t3) == false);
    assert(isSameTreeIterative(t1, t3) == false);

    assert(isSameTreeRecursive(nullptr, nullptr) == true);
    assert(isSameTreeIterative(nullptr, nullptr) == true);

    std::cout << "All Identical Binary Tree tests passed successfully!\n";
    return 0;
}

