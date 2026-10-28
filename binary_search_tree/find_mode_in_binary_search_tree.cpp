#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): value(0), left(nullptr), right(nullptr){};
    TreeNode(int val): value(val), left(nullptr), right(nullptr){};
    TreeNode(int val, TreeNode* l , TreeNode* r): value(val), left(l), right(r){};
};


vector<int> find_modes(TreeNode* root){
    int curr_value = INT_MAX;
    int curr_count = 0;
    int max_count = 0;
    vector<int> modes;

    auto in_order_traversal = [&](TreeNode* node, auto& self){
        if(node == nullptr) return;

        self(node->left, self);

        if(node->value != curr_value){
            curr_value = node->value;
            curr_count = 1;
        }
        else{
            curr_count++;
        }

        if(curr_count == max_count){
            modes.push_back(curr_value);
        }
        else if(curr_count > max_count){
            max_count = curr_count;
            modes = {curr_value};
        }

        self(node->right, self);
    };

    in_order_traversal(root, in_order_traversal);
    
    return modes; 
}

int main(){
    TreeNode root(0);
    
    vector<int> result = find_modes(&root);
    
    cout << "Modes: ";
    for(int mode : result) {
        cout << mode << " ";
    }
    cout << endl;
    return 0;
}