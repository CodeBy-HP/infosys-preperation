#include<bits/stdc++.h>
using namespace std;

int solve(unordered_map<long long, int>& pmap, long long currSum, long long targetSum, TreeNode* node) {
 
    TreeNode* curr = root;

    vector<int>inorder;

    while(curr != nullptr){
        if(curr -> left == nullptr){
            inorder.push_back(curr);
            curr = curr->right;
        }
        else{

            TreeNode* rightMost = curr->left;

            while(rightMost->right != nullptr && rightMost->right != curr){
                rightMost = rightMost -> right;
            }

            if(rightMost->right == nullptr){
                // make a link
                rightMost->right = curr;
                curr = curr->left;
            }
            else{
                // 2nd visit
                rightMost->right = nullptr;
                curr = curr->right;
            }
        }
    }


}


int main(){


}


