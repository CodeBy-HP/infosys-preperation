#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode() : value(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : value(x), left(l), right(r) {}
}; 

vector<int> serialize(TreeNode* node) {
    vector<int> arr;

    auto traverse = [&](TreeNode* curr, auto& self) {
        if (curr == nullptr) {
            arr.push_back(INT_MIN);
            return;
        }

        arr.push_back(curr->value);
        self(curr->left, self);
        self(curr->right, self);
    };
    
    traverse(node, traverse);
    return arr;
}

TreeNode* deserialize(vector<int>& arr) {
    int ind = 0;

    int n = arr.size();
    auto build = [&](auto& self) -> TreeNode* {
        if(ind >= n){
            return nullptr;
        }
        if (arr[ind] == INT_MIN) { 
            ind++; 
            return nullptr;
        }

        TreeNode* node = new TreeNode(arr[ind]);
        ind++; 

        node->left = self(self);
        node->right = self(self);

        return node;
    };

    return build(build); 
}

int main() {
    TreeNode* root = new TreeNode(0);
    vector<int> arr = serialize(root);
    TreeNode* reconstructedRoot = deserialize(arr);
    return 0;
}