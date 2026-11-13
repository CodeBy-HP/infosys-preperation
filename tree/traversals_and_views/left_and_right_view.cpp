#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 1. Left View via DFS (Root -> Left -> Right)
void leftViewDFS(TreeNode* node, int level, std::vector<int>& res) {
    if (!node) return;
    if (level == (int)res.size()) {
        res.push_back(node->val);
    }
    leftViewDFS(node->left, level + 1, res);
    leftViewDFS(node->right, level + 1, res);
}

std::vector<int> leftSideView(TreeNode* root) {
    std::vector<int> res;
    leftViewDFS(root, 0, res);
    return res;
}

// 2. Right View via DFS (Root -> Right -> Left)
void rightViewDFS(TreeNode* node, int level, std::vector<int>& res) {
    if (!node) return;
    if (level == (int)res.size()) {
        res.push_back(node->val);
    }
    rightViewDFS(node->right, level + 1, res);
    rightViewDFS(node->left, level + 1, res);
}

std::vector<int> rightSideView(TreeNode* root) {
    std::vector<int> res;
    rightViewDFS(root, 0, res);
    return res;
}

// 3. Combined BFS Approach
struct TreeViews {
    std::vector<int> leftView;
    std::vector<int> rightView;
};

TreeViews getBothViewsBFS(TreeNode* root) {
    TreeViews views;
    if (!root) return views;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* curr = q.front();
            q.pop();

            if (i == 0) views.leftView.push_back(curr->val);
            if (i == levelSize - 1) views.rightView.push_back(curr->val);

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }

    return views;
}

int main() {
    /*
              1
            /   \
           2     3
          / \     \
         4   5     6
            /
           7
       Left View:  [1, 2, 4, 7]
       Right View: [1, 3, 6, 7]
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(7);
    root->right->right = new TreeNode(6);

    std::vector<int> expLeft = {1, 2, 4, 7};
    std::vector<int> expRight = {1, 3, 6, 7};

    assert(leftSideView(root) == expLeft);
    assert(rightSideView(root) == expRight);

    TreeViews bfsViews = getBothViewsBFS(root);
    assert(bfsViews.leftView == expLeft);
    assert(bfsViews.rightView == expRight);

    std::cout << "All Left and Right View tests passed successfully!\n";
    return 0;
}

