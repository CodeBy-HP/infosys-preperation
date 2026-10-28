#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode():value(0){};
    TreeNode(int value):value(value){};
    TreeNode(int value,TreeNode*left, TreeNode*right): value(value),left(left),right(right) {};
};


string serialize(TreeNode* node){
    string s = "";

    auto traverse = [&](TreeNode* node,auto&self){
        // base case 
        if(node == nullptr){
            s += "#,";
            return;
        }
        s += to_string(node->value) + ",";
        self(node->left,self);
        self(node->right,self);
        return;
    };

    traverse(node,traverse);

    s = s.substr(0,s.size()-1);
    return s;
}


TreeNode* deserialize(string& s) {
    stringstream ss(s);
    queue<string> q; 
    string word = "";

    while(getline(ss, word, ',')){ 
        q.push(word);
    }

    auto build = [&](auto& self) -> TreeNode* {
        if(q.empty()){
            return nullptr;
        }
        
        string curr = q.front();
        q.pop();

        if(curr == "#"){
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(curr));

        node->left = self(self);
        node->right = self(self);

        return node;
    };

    return build(build); 
}

int main(){
    TreeNode* root = new TreeNode(0);

    string s = serialize(root);
}