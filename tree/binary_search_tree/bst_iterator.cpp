#include <iostream>
#include <stack>
#include <vector>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
private:
    std::stack<TreeNode*> st;

    // Helper: Push all left descendants onto stack
    void pushAllLeft(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }

    int next() {
        TreeNode* topNode = st.top();
        st.pop();
        if (topNode->right != nullptr) {
            pushAllLeft(topNode->right);
        }
        return topNode->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

int main() {
    /*
            7
           / \
          3   15
             /  \
            9   20
    */
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator it(root);

    assert(it.hasNext() == true);
    assert(it.next() == 3);
    assert(it.next() == 7);
    assert(it.hasNext() == true);
    assert(it.next() == 9);
    assert(it.hasNext() == true);
    assert(it.next() == 15);
    assert(it.hasNext() == true);
    assert(it.next() == 20);
    assert(it.hasNext() == false);

    std::cout << "All BST Iterator tests passed successfully!\n";
    return 0;
}

