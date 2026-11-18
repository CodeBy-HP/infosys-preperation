#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>


using namespace std;

// 1. DFS solution
class Solution {
private:
    // col -> row -> sorted values
    map<int, map<int, multiset<int>>> nodes;
    
    void dfs(TreeNode* root, int col, int row) {
        if (!root) return;
        
        // Log the node at its exact 2D coordinate
        nodes[col][row].insert(root->val);
        
        // Traverse Left: X decreases, Y increases
        dfs(root->left, col - 1, row + 1);
        
        // Traverse Right: X increases, Y increases
        dfs(root->right, col + 1, row + 1);
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Build the 3D map
        dfs(root, 0, 0);
        
        vector<vector<int>> result;
        
        // The outer map is already sorted from leftmost column to rightmost
        for (auto& [col, rowMap] : nodes) {
            vector<int> current_column;
            
            // The inner map is already sorted from top row to bottom row
            for (auto& [row, values] : rowMap) {
                
                // The multiset is already sorted by value
                for (int val : values) {
                    current_column.push_back(val);
                }
            }
            result.push_back(current_column);
        }
        
        return result;
    }
};

// 2. BFS Solution
class BFS_Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Final blueprint: col -> all values top-to-bottom
        map<int, vector<int>> columns; 
        
        // Queue stores {Node, Column}
        queue<pair<TreeNode*, int>> q; 
        if (root) q.push({root, 0});
        
        while (!q.empty()) {
            int level_size = q.size();
            
            // STAGING AREA: col -> sorted values (for the CURRENT ROW only)
            map<int, multiset<int>> current_row_staging;
            
            // 1. Unload the entire row into the staging area
            for (int i = 0; i < level_size; i++) {
                auto [node, col] = q.front();
                q.pop();
                
                // Multiset automatically sorts any overlapping nodes (even if there are 6 of them!)
                current_row_staging[col].insert(node->val);
                
                if (node->left) q.push({node->left, col - 1});
                if (node->right) q.push({node->right, col + 1});
            }
            
            // 2. The row is finished. Append the sorted staging area to the final blueprint.
            for (auto& [col, sorted_values] : current_row_staging) {
                for (int val : sorted_values) {
                    columns[col].push_back(val);
                }
            }
        }
        
        // Format the final output
        vector<vector<int>> result;
        for (auto& [col, values] : columns) {
            result.push_back(values);
        }
        
        return result;
    }
};


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class VerticalOrderTraversal {
private:
    struct NodeInfo {
        int col;
        int row;
        int val;
    };

public:
    // =========================================================================
    // 3. BFS Coordinate Assignment + Tuple Sorting
    // Time Complexity: O(N log N)
    // Space Complexity: O(N)
    // =========================================================================
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        vector<NodeInfo> nodes;
        // Queue stores {TreeNode*, {col, row}}
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto [curr, coords] = q.front();
            q.pop();

            int col = coords.first;
            int row = coords.second;

            nodes.push_back({col, row, curr->val});

            if (curr->left) q.push({curr->left, {col - 1, row + 1}});
            if (curr->right) q.push({curr->right, {col + 1, row + 1}});
        }

        // Sort by col, then by row, then by value
        sort(nodes.begin(), nodes.end(), [](const NodeInfo& a, const NodeInfo& b) {
            if (a.col != b.col) return a.col < b.col;
            if (a.row != b.row) return a.row < b.row;
            return a.val < b.val;
        });

        // Group by column
        int prevCol = nodes[0].col;
        vector<int> currColVals;

        for (const auto& node : nodes) {
            if (node.col != prevCol) {
                result.push_back(move(currColVals));
                currColVals = {};
                prevCol = node.col;
            }
            currColVals.push_back(node.val);
        }
        result.push_back(move(currColVals));

        return result;
    }
};

TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < nodes.size() && nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    VerticalOrderTraversal solver;

    // Tree: [3, 9, 20, -1, -1, 15, 7]
    TreeNode* root = buildTree({3, 9, 20, -1, -1, 15, 7});

    vector<vector<int>> res = solver.verticalTraversal(root);
    cout << "Vertical Order Traversal:\n";
    for (const auto& col : res) {
        cout << "  [ ";
        for (int v : col) cout << v << " ";
        cout << "]\n";
    }

    freeTree(root);
    return 0;
}
