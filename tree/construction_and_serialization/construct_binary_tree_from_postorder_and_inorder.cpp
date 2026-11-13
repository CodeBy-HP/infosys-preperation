#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTreeHelper(const std::vector<int>& inorder, int inStart, int inEnd,
                          const std::vector<int>& postorder, int postStart, int postEnd,
                          const std::unordered_map<int, int>& inMap) {
    if (inStart > inEnd || postStart > postEnd) {
        return nullptr;
    }

    int rootVal = postorder[postEnd];
    TreeNode* root = new TreeNode(rootVal);

    int inRoot = inMap.at(rootVal);
    int numsLeft = inRoot - inStart;

    root->left = buildTreeHelper(inorder, inStart, inRoot - 1,
                                 postorder, postStart, postStart + numsLeft - 1,
                                 inMap);

    root->right = buildTreeHelper(inorder, inRoot + 1, inEnd,
                                  postorder, postStart + numsLeft, postEnd - 1,
                                  inMap);

    return root;
}

TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
    if (inorder.empty() || postorder.empty()) return nullptr;

    std::unordered_map<int, int> inMap;
    for (int i = 0; i < (int)inorder.size(); ++i) {
        inMap[inorder[i]] = i;
    }

    return buildTreeHelper(inorder, 0, (int)inorder.size() - 1,
                           postorder, 0, (int)postorder.size() - 1,
                           inMap);
}

// Helper to verify reconstructed tree matches expected traversals
void getInorder(TreeNode* root, std::vector<int>& res) {
    if (!root) return;
    getInorder(root->left, res);
    res.push_back(root->val);
    getInorder(root->right, res);
}

void getPostorder(TreeNode* root, std::vector<int>& res) {
    if (!root) return;
    getPostorder(root->left, res);
    getPostorder(root->right, res);
    res.push_back(root->val);
}

int main() {
    /*
        Tree:
            3
           / \
          9  20
            /  \
           15   7
    */
    std::vector<int> inorder = {9, 3, 15, 20, 7};
    std::vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode* root = buildTree(inorder, postorder);

    std::vector<int> checkIn, checkPost;
    getInorder(root, checkIn);
    getPostorder(root, checkPost);

    assert(checkIn == inorder);
    assert(checkPost == postorder);

    // Single node test
    std::vector<int> singleIn = {42};
    std::vector<int> singlePost = {42};
    TreeNode* singleRoot = buildTree(singleIn, singlePost);
    assert(singleRoot != nullptr && singleRoot->val == 42);

    std::cout << "All Construct BT from Postorder and Inorder tests passed successfully!\n";
    return 0;
}

