#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 1. Recursive Postorder Traversal
void postorderRecursiveHelper(TreeNode* root, std::vector<int>& result) {
    if (!root) return;
    postorderRecursiveHelper(root->left, result);
    postorderRecursiveHelper(root->right, result);
    result.push_back(root->val);
}

std::vector<int> postorderRecursive(TreeNode* root) {
    std::vector<int> result;
    postorderRecursiveHelper(root, result);
    return result;
}

// 2. Iterative Postorder using 2 Stacks
std::vector<int> postorder2Stacks(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;

    std::stack<TreeNode*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        TreeNode* curr = st1.top();
        st1.pop();
        st2.push(curr);

        if (curr->left) st1.push(curr->left);
        if (curr->right) st1.push(curr->right);
    }

    while (!st2.empty()) {
        result.push_back(st2.top()->val);
        st2.pop();
    }

    return result;
}

// 3. Iterative Postorder using 1 Stack & lastVisited pointer
std::vector<int> postorder1Stack(TreeNode* root) {
    std::vector<int> result;
    std::stack<TreeNode*> st;
    TreeNode* curr = root;
    TreeNode* lastVisited = nullptr;

    while (curr != nullptr || !st.empty()) {
        if (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        } else {
            TreeNode* peekNode = st.top();
            // If right child exists and traversing from left child
            if (peekNode->right != nullptr && lastVisited != peekNode->right) {
                curr = peekNode->right;
            } else {
                result.push_back(peekNode->val);
                lastVisited = peekNode;
                st.pop();
            }
        }
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
       Postorder: [4, 5, 2, 3, 1]
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::vector<int> expected = {4, 5, 2, 3, 1};

    assert(postorderRecursive(root) == expected);
    assert(postorder2Stacks(root) == expected);
    assert(postorder1Stack(root) == expected);

    // Empty tree
    assert(postorderRecursive(nullptr).empty());
    assert(postorder2Stacks(nullptr).empty());
    assert(postorder1Stack(nullptr).empty());

    std::cout << "All Postorder Traversal tests passed successfully!\n";
    return 0;
}

