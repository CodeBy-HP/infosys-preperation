#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<int> bottomView(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;

    // Map: column -> bottom-most node value
    std::map<int, int> bottomNode;

    // Queue: {node, col}
    std::queue<std::pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, col] = q.front();
        q.pop();

        // In bottom view, every level-order visit overwrites the column value
        bottomNode[col] = node->val;

        if (node->left) q.push({node->left, col - 1});
        if (node->right) q.push({node->right, col + 1});
    }

    // Extract ordered columns
    for (auto const& [col, val] : bottomNode) {
        result.push_back(val);
    }

    return result;
}

int main() {
    /*
              1
            /   \
           2     3
          / \     \
         4   5     6
              \
               7
       Columns:
       col -2: 4
       col -1: 2
       col 0:  1, then 5 (Bottom-most at col 0 is 5)
       col +1: 3, then 7 (Bottom-most at col +1 is 7)
       col +2: 6
       Bottom view: [4, 2, 5, 7, 6]
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(6);

    std::vector<int> expected = {4, 2, 5, 7, 6};
    assert(bottomView(root) == expected);

    // Empty tree
    assert(bottomView(nullptr).empty());

    std::cout << "All Bottom View of Binary Tree tests passed successfully!\n";
    return 0;
}
