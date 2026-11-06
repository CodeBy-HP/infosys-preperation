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

std::vector<int> topView(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;

    // Map: column -> topmost node value
    std::map<int, int> topNode;

    // Queue: {node, col}
    std::queue<std::pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, col] = q.front();
        q.pop();

        // If this column is visited for the first time, record it
        if (topNode.find(col) == topNode.end()) {
            topNode[col] = node->val;
        }

        if (node->left) q.push({node->left, col - 1});
        if (node->right) q.push({node->right, col + 1});
    }

    // Extract sorted columns from left to right
    for (auto const& [col, val] : topNode) {
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
       col 0:  1, 5, 7 -> Topmost is 1
       col +1: 3
       col +2: 6
       Top view: [4, 2, 1, 3, 6]
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(6);

    std::vector<int> expected = {4, 2, 1, 3, 6};
    assert(topView(root) == expected);

    // Empty tree
    assert(topView(nullptr).empty());

    // Single node
    TreeNode* single = new TreeNode(99);
    assert(topView(single) == std::vector<int>({99}));

    std::cout << "All Top View of Binary Tree tests passed successfully!\n";
    return 0;
}

