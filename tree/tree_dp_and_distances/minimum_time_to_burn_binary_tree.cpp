#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Step 1: Map child -> parent and find the start node
TreeNode* mapParentsAndFindTarget(TreeNode* root, int startVal, 
                                 std::unordered_map<TreeNode*, TreeNode*>& parentMap) {
    TreeNode* target = nullptr;
    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr->val == startVal) {
            target = curr;
        }

        if (curr->left) {
            parentMap[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right) {
            parentMap[curr->right] = curr;
            q.push(curr->right);
        }
    }

    return target;
}

// Step 2: Radial BFS burning the tree
int minTimeToBurnTree(TreeNode* root, int startVal) {
    if (!root) return 0;

    std::unordered_map<TreeNode*, TreeNode*> parentMap;
    TreeNode* target = mapParentsAndFindTarget(root, startVal, parentMap);
    if (!target) return 0;

    std::unordered_set<TreeNode*> visited;
    std::queue<TreeNode*> q;
    q.push(target);
    visited.insert(target);

    int time = 0;

    while (!q.empty()) {
        int size = q.size();
        bool burnedAny = false;

        for (int i = 0; i < size; ++i) {
            TreeNode* curr = q.front();
            q.pop();

            // Neighbor 1: Left child
            if (curr->left && visited.find(curr->left) == visited.end()) {
                visited.insert(curr->left);
                q.push(curr->left);
                burnedAny = true;
            }

            // Neighbor 2: Right child
            if (curr->right && visited.find(curr->right) == visited.end()) {
                visited.insert(curr->right);
                q.push(curr->right);
                burnedAny = true;
            }

            // Neighbor 3: Parent
            if (parentMap.find(curr) != parentMap.end()) {
                TreeNode* parent = parentMap[curr];
                if (visited.find(parent) == visited.end()) {
                    visited.insert(parent);
                    q.push(parent);
                    burnedAny = true;
                }
            }
        }

        if (burnedAny) {
            time++;
        }
    }

    return time;
}

int main() {
    /*
              1
            /   \
           2     3
          / \     \
         4   5     6
            / \
           7   8
       Start node = 8
       Time to burn: 5 minutes
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    root->right->right = new TreeNode(6);

    assert(minTimeToBurnTree(root, 8) == 5);

    // Burning from root (1)
    // Level 1: 2, 3 (min 1)
    // Level 2: 4, 5, 6 (min 2)
    // Level 3: 7, 8 (min 3)
    assert(minTimeToBurnTree(root, 1) == 3);

    // Single node tree
    TreeNode* single = new TreeNode(42);
    assert(minTimeToBurnTree(single, 42) == 0);

    std::cout << "All Minimum Time to Burn Binary Tree tests passed successfully!\n";
    return 0;
}

