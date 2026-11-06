#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct AllTraversals {
    std::vector<int> preorder;
    std::vector<int> inorder;
    std::vector<int> postorder;
};

AllTraversals preInPostOneTraversal(TreeNode* root) {
    AllTraversals res;
    if (!root) return res;

    // Stack storing pair of: {current_node, state}
    // state 1: Preorder
    // state 2: Inorder
    // state 3: Postorder
    std::stack<std::pair<TreeNode*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        auto [node, state] = st.top();
        st.pop();

        if (state == 1) {
            res.preorder.push_back(node->val);
            st.push({node, 2});
            if (node->left) {
                st.push({node->left, 1});
            }
        } else if (state == 2) {
            res.inorder.push_back(node->val);
            st.push({node, 3});
            if (node->right) {
                st.push({node->right, 1});
            }
        } else { // state == 3
            res.postorder.push_back(node->val);
        }
    }

    return res;
}

int main() {
    /*
            1
           / \
          2   3
         / \
        4   5

       Preorder:  [1, 2, 4, 5, 3]
       Inorder:   [4, 2, 5, 1, 3]
       Postorder: [4, 5, 2, 3, 1]
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    AllTraversals ans = preInPostOneTraversal(root);

    std::vector<int> expPre = {1, 2, 4, 5, 3};
    std::vector<int> expIn = {4, 2, 5, 1, 3};
    std::vector<int> expPost = {4, 5, 2, 3, 1};

    assert(ans.preorder == expPre);
    assert(ans.inorder == expIn);
    assert(ans.postorder == expPost);

    // Empty tree
    AllTraversals emptyAns = preInPostOneTraversal(nullptr);
    assert(emptyAns.preorder.empty());
    assert(emptyAns.inorder.empty());
    assert(emptyAns.postorder.empty());

    std::cout << "All-in-one Traversal tests passed successfully!\n";
    return 0;
}

