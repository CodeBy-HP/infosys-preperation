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

// 1. Recursive Inorder Traversal
void inorderRecursiveHelper(TreeNode* root, std::vector<int>& result) {
    if (!root) return;
    inorderRecursiveHelper(root->left, result);
    result.push_back(root->val);
    inorderRecursiveHelper(root->right, result);
}

std::vector<int> inorderRecursive(TreeNode* root) {
    std::vector<int> result;
    inorderRecursiveHelper(root, result);
    return result;
}

// 2. Iterative Inorder Traversal using explicit stack
std::vector<int> inorderIterative(TreeNode* root) {
    std::vector<int> result;
    std::stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr != nullptr || !st.empty()) {
        // Reach the leftmost node of the current subtree
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }

        // Current must be nullptr here, pop the top element
        curr = st.top();
        st.pop();
        result.push_back(curr->val);

        // We have visited the node and its left subtree; now visit right subtree
        curr = curr->right;
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
       Inorder: [4, 2, 5, 1, 3]
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::vector<int> expected = {4, 2, 5, 1, 3};

    std::vector<int> resRec = inorderRecursive(root);
    std::vector<int> resIter = inorderIterative(root);

    assert(resRec == expected);
    assert(resIter == expected);

    // Single node test
    TreeNode* single = new TreeNode(42);
    assert(inorderRecursive(single) == std::vector<int>({42}));
    assert(inorderIterative(single) == std::vector<int>({42}));

    // Empty tree
    assert(inorderRecursive(nullptr).empty());
    assert(inorderIterative(nullptr).empty());

    std::cout << "All Inorder Traversal tests passed successfully!\n";
    return 0;
}

