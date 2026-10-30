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

class AllNodesDistanceK {
private:
    void mapParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left) {
                parentMap[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parentMap[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

public:
    // =========================================================================
    // 1. Parent Mapping + Radial BFS
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root || !target) return {};

        unordered_map<TreeNode*, TreeNode*> parentMap;
        mapParents(root, parentMap);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;

        q.push(target);
        visited.insert(target);
        int currentDistance = 0;

        while (!q.empty()) {
            if (currentDistance == k) {
                vector<int> result;
                while (!q.empty()) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return result;
            }

            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // Check left child
                if (curr->left && !visited.count(curr->left)) {
                    visited.insert(curr->left);
                    q.push(curr->left);
                }
                // Check right child
                if (curr->right && !visited.count(curr->right)) {
                    visited.insert(curr->right);
                    q.push(curr->right);
                }
                // Check parent
                if (parentMap.count(curr) && !visited.count(parentMap[curr])) {
                    visited.insert(parentMap[curr]);
                    q.push(parentMap[curr]);
                }
            }
            currentDistance++;
        }

        return {};
    }
};

TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    TreeNode* left = findNode(root->left, val);
    if (left) return left;
    return findNode(root->right, val);
}

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
    AllNodesDistanceK solver;

    // Tree: [3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4], target = 5, k = 2
    TreeNode* root = buildTree({3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4});
    TreeNode* target = findNode(root, 5);

    vector<int> res = solver.distanceK(root, target, 2);
    cout << "Nodes at Distance 2 from 5: [ ";
    for (int v : res) cout << v << " ";
    cout << "]\n(Expected: [ 7 4 1 ] in any order)\n";

    freeTree(root);
    return 0;
}
