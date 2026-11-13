# Search in a Binary Search Tree

## Problem Statement
Given the `root` of a binary search tree (BST) and an integer `val`:
Find the node in the BST that the node's value equals `val` and return the subtree rooted with that node. If such a node does not exist, return `nullptr`.

```
        4
       / \
      2   7
     / \
    1   3

val = 2
Output Subtree:
    2
   / \
  1   3
```

---

## 1. Algorithmic Approaches

### Approach A: Iterative Search ($O(H)$ time, $O(1)$ space)
Exploiting the BST ordering property eliminates half the search space at each branch:
1. Start at `curr = root`.
2. While `curr != nullptr && curr->val != val`:
   - If `val < curr->val`: move left (`curr = curr->left`).
   - If `val > curr->val`: move right (`curr = curr->right`).
3. Return `curr`.

### Approach B: Recursive Search ($O(H)$ time, $O(H)$ stack)
```cpp
TreeNode* searchBST(TreeNode* root, int val) {
    if (!root || root->val == val) return root;
    if (val < root->val) return searchBST(root->left, val);
    return searchBST(root->right, val);
}
```

---

## 2. Complexity Analysis
- **Time Complexity:** $O(H)$ where $H$ is tree height ($O(\log N)$ balanced, $O(N)$ skewed).
- **Space Complexity:**
  - Iterative: $O(1)$ auxiliary memory.
  - Recursive: $O(H)$ stack frames.

