#include<bits/stdc++.h>
using namespace std;

int solve(unordered_map<long long, int>& pmap, long long currSum, long long targetSum, TreeNode* node) {
    if (!node) return 0;

    currSum += node->val;
    long long need = currSum - targetSum;

    // Check how many valid paths end at this current node
    int ways = pmap[need];

    // Add current sum to the prefix map
    pmap[currSum] += 1;

    // Pass 'pmap' into the recursive calls!
    ways += solve(pmap, currSum, targetSum, node->left);
    ways += solve(pmap, currSum, targetSum, node->right);
        
    // Backtrack
    pmap[currSum] -= 1;
    if(pmap[currSum] <= 0) pmap.erase(currSum); // memory optimization

    return ways;
}


int main(){


}


