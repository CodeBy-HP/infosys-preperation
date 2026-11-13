#include <iostream>
#include <vector>
#include <string>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 1. Return paths as vectors of integers
void getPathsDFS(TreeNode* node, std::vector<int>& current, std::vector<std::vector<int>>& allPaths) {
    if (!node) return;

    current.push_back(node->val);

    // Leaf node check
    if (!node->left && !node->right) {
        allPaths.push_back(current);
    } else {
        if (node->left) getPathsDFS(node->left, current, allPaths);
        if (node->right) getPathsDFS(node->right, current, allPaths);
    }

    // Backtrack
    current.pop_back();
}

std::vector<std::vector<int>> allRootToLeafPaths(TreeNode* root) {
    std::vector<std::vector<int>> allPaths;
    std::vector<int> current;
    getPathsDFS(root, current, allPaths);
    return allPaths;
}

// 2. Return paths formatted as strings: "1->2->5"
void getStringPathsDFS(TreeNode* node, std::string path, std::vector<std::string>& result) {
    if (!node) return;

    if (!path.empty()) path += "->";
    path += std::to_string(node->val);

    if (!node->left && !node->right) {
        result.push_back(path);
        return;
    }

    if (node->left) getStringPathsDFS(node->left, path, result);
    if (node->right) getStringPathsDFS(node->right, path, result);
}

std::vector<std::string> binaryTreePaths(TreeNode* root) {
    std::vector<std::string> result;
    getStringPathsDFS(root, "", result);
    return result;
}

int main() {
    /*
              1
            /   \
           2     3
          / \
         4   5

       Paths:
       [1, 2, 4] -> "1->2->4"
       [1, 2, 5] -> "1->2->5"
       [1, 3]    -> "1->3"
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::vector<std::vector<int>> expectedVectors = {
        {1, 2, 4},
        {1, 2, 5},
        {1, 3}
    };
    std::vector<std::string> expectedStrings = {
        "1->2->4",
        "1->2->5",
        "1->3"
    };

    assert(allRootToLeafPaths(root) == expectedVectors);
    assert(binaryTreePaths(root) == expectedStrings);

    // Empty tree
    assert(allRootToLeafPaths(nullptr).empty());
    assert(binaryTreePaths(nullptr).empty());

    std::cout << "All Root to Leaf Paths tests passed successfully!\n";
    return 0;
}

