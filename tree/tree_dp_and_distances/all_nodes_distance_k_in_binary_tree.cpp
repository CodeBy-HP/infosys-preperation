#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    unordered_map<TreeNode*, TreeNode*> parentMap;
    
    // Phase 1: DFS to map every node to its parent
    void buildParentMap(TreeNode* node, TreeNode* parent) {
        if (!node) return;
        parentMap[node] = parent;
        buildParentMap(node->left, node);
        buildParentMap(node->right, node);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // 1. Build the highways
        buildParentMap(root, nullptr);
        
        // 2. Setup the BFS Water Ripple
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        
        q.push(target);
        visited.insert(target);
        int current_distance = 0;
        
        // Phase 2: Expand outward level by level
        while (!q.empty()) {
            // If our ripples have reached distance K, everything currently
            // in the queue is our exact answer!
            if (current_distance == k) {
                vector<int> result;
                while (!q.empty()) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return result;
            }
            
            // Process the current ripple (current level)
            int level_size = q.size();
            for (int i = 0; i < level_size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                
                // Option A: Go Left
                if (curr->left && visited.find(curr->left) == visited.end()) {
                    visited.insert(curr->left);
                    q.push(curr->left);
                }
                // Option B: Go Right
                if (curr->right && visited.find(curr->right) == visited.end()) {
                    visited.insert(curr->right);
                    q.push(curr->right);
                }
                // Option C: Go UP! (Using our magical parent map)
                TreeNode* parent = parentMap[curr];
                if (parent && visited.find(parent) == visited.end()) {
                    visited.insert(parent);
                    q.push(parent);
                }
            }
            // Finished expanding this ripple, increase distance
            current_distance++;
        }
        
        // If K is larger than the tree, return empty
        return {}; 
    }
};


