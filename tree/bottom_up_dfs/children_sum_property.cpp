#include <iostream>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 1. Check if tree satisfies Children Sum Property
bool checkChildrenSum(TreeNode* root) {
    if (!root) return true;
    // Leaf nodes satisfy property trivially
    if (!root->left && !root->right) return true;

    int childSum = 0;
    if (root->left) childSum += root->left->val;
    if (root->right) childSum += root->right->val;

    if (root->val != childSum) return false;

    return checkChildrenSum(root->left) && checkChildrenSum(root->right);
}

// 2. Convert tree to satisfy Children Sum Property (increments only)
void changeTree(TreeNode* root) {
    if (!root) return;

    int childSum = 0;
    if (root->left) childSum += root->left->val;
    if (root->right) childSum += root->right->val;

    // Top-down: ensure children are at least as large as parent
    if (childSum >= root->val) {
        root->val = childSum;
    } else {
        if (root->left) root->left->val = root->val;
        if (root->right) root->right->val = root->val;
    }

    // Recurse down
    changeTree(root->left);
    changeTree(root->right);

    // Bottom-up: parent takes the sum of updated children
    int total = 0;
    if (root->left) total += root->left->val;
    if (root->right) total += root->right->val;

    if (root->left || root->right) {
        root->val = total;
    }
}


// Transformation
class Solution {
private:
    // Pass 1: Post-Order (Bottom-Up)
    // Ensures every parent is >= the sum of its children.
    void inflateParents(TreeNode* node) {
        if (!node) return;
        
        // 1. Traverse all the way to the leaves first
        inflateParents(node->left);
        inflateParents(node->right);
        
        // 2. Ignore leaf nodes
        if (!node->left && !node->right) return;
        
        // 3. Calculate children's sum
        int child_sum = 0;
        if (node->left) child_sum += node->left->val;
        if (node->right) child_sum += node->right->val;
        
        // 4. If children are heavier, inflate the parent
        if (child_sum > node->val) {
            node->val = child_sum;
        }
    }

    // Pass 2: Pre-Order (Top-Down)
    // Pushes any parent surplus down to the leaves.
    void inflateChildren(TreeNode* node) {
        if (!node) return;
        
        // 1. Ignore leaf nodes
        if (!node->left && !node->right) return;
        
        // 2. Calculate current children's sum
        int child_sum = 0;
        if (node->left) child_sum += node->left->val;
        if (node->right) child_sum += node->right->val;
        
        // 3. Because of Pass 1, node->val is GUARANTEED to be >= child_sum.
        // We find the deficit and give it to one of the children.
        int deficit = node->val - child_sum;
        if (deficit > 0) {
            if (node->left) {
                node->left->val += deficit;
            } else {
                node->right->val += deficit;
            }
        }
        
        // 4. Recurse down. The child we just inflated will now act as a 
        // heavy parent and push that surplus down its own subtree!
        inflateChildren(node->left);
        inflateChildren(node->right);
    }

public:
    void changeTree(TreeNode* root) {
        // Run Pass 1
        inflateParents(root);
        // Run Pass 2
        inflateChildren(root);
    }
};

int main() {
    /*
            10
           /  \
          8    2
         / \    \
        3   5    2
       Valid Children Sum Tree!
    */
    TreeNode* valid = new TreeNode(10);
    valid->left = new TreeNode(8);
    valid->right = new TreeNode(2);
    valid->left->left = new TreeNode(3);
    valid->left->right = new TreeNode(5);
    valid->right->right = new TreeNode(2);

    assert(checkChildrenSum(valid) == true);

    /*
            50
           /  \
          7    2
         / \    \
        3   5    1
       Invalid initially!
    */
    TreeNode* invalid = new TreeNode(50);
    invalid->left = new TreeNode(7);
    invalid->right = new TreeNode(2);
    invalid->left->left = new TreeNode(3);
    invalid->left->right = new TreeNode(5);
    invalid->right->right = new TreeNode(1);

    assert(checkChildrenSum(invalid) == false);

    // Convert invalid tree
    changeTree(invalid);
    assert(checkChildrenSum(invalid) == true);

    std::cout << "All Children Sum Property tests passed successfully!\n";
    return 0;
}

