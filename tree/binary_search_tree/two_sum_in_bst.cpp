#include <iostream>
#include <stack>
#include <unordered_set>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Bidirectional BST Iterator
class BSTIterator {
private:
    std::stack<TreeNode*> st;
    bool reverse; // false: forward (inorder), true: backward (reverse inorder)

    void pushAll(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            if (!reverse) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
    }

public:
    BSTIterator(TreeNode* root, bool isReverse) : reverse(isReverse) {
        pushAll(root);
    }

    int next() {
        TreeNode* topNode = st.top();
        st.pop();
        if (!reverse) {
            pushAll(topNode->right);
        } else {
            pushAll(topNode->left);
        }
        return topNode->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

// 1. Optimal O(H) space Two-Pointer approach via Dual BST Iterators
bool findTargetDualIterator(TreeNode* root, int k) {
    if (!root) return false;

    BSTIterator l(root, false); // Forward: smallest -> largest
    BSTIterator r(root, true);  // Backward: largest -> smallest

    int i = l.next();
    int j = r.next();

    while (i < j) {
        int sum = i + j;
        if (sum == k) return true;
        if (sum < k) {
            if (l.hasNext()) i = l.next();
            else break;
        } else {
            if (r.hasNext()) j = r.next();
            else break;
        }
    }

    return false;
}

// 2. Hash Set Approach (O(N) space)
bool findTargetHashSetHelper(TreeNode* root, int k, std::unordered_set<int>& set) {
    if (!root) return false;
    if (set.find(k - root->val) != set.end()) return true;
    set.insert(root->val);
    return findTargetHashSetHelper(root->left, k, set) || 
           findTargetHashSetHelper(root->right, k, set);
}

bool findTargetHashSet(TreeNode* root, int k) {
    std::unordered_set<int> set;
    return findTargetHashSetHelper(root, k, set);
}

int main() {
    /*
              5
            /   \
           3     6
          / \     \
         2   4     7
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    // Target = 9 (2 + 7 or 3 + 6 or 4 + 5)
    assert(findTargetDualIterator(root, 9) == true);
    assert(findTargetHashSet(root, 9) == true);

    // Target = 28 (No pair exists)
    assert(findTargetDualIterator(root, 28) == false);
    assert(findTargetHashSet(root, 28) == false);

    // Target = 4 (Cannot use same node 2 twice)
    assert(findTargetDualIterator(root, 4) == false);
    assert(findTargetHashSet(root, 4) == false);

    std::cout << "All Two Sum in BST tests passed successfully!\n";
    return 0;
}

