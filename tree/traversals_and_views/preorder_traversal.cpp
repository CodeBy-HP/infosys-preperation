#include <iostream>
#include <vector>
#include <stack>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 1. Recursive Preorder Traversal
void preorderRecursiveHelper(TreeNode* root, std::vector<int>& result) {
    if (!root) return;
    result.push_back(root->val);
    preorderRecursiveHelper(root->left, result);
    preorderRecursiveHelper(root->right, result);
}

std::vector<int> preorderRecursive(TreeNode* root) {
    std::vector<int> result;
    preorderRecursiveHelper(root, result);
    return result;
}

// 2. Iterative Preorder Traversal using explicit stack
std::vector<int> preorderIterative(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;

    std::stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* curr = st.top();
        st.pop();
        result.push_back(curr->val);

        // Push right first so that left is processed first
        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
    }

    return result;
}

int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
       Preorder: [1, 2, 4, 5, 3]
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::vector<int> expected = {1, 2, 4, 5, 3};

    std::vector<int> resRec = preorderRecursive(root);
    std::vector<int> resIter = preorderIterative(root);

    assert(resRec == expected);
    assert(resIter == expected);

    // Empty tree test
    assert(preorderRecursive(nullptr).empty());
    assert(preorderIterative(nullptr).empty());

    std::cout << "All Preorder Traversal tests passed successfully!\n";
    return 0;
}

