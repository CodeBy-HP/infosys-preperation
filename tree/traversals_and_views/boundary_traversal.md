# Boundary Traversal of Binary Tree

## Problem Statement
Given the `root` of a binary tree, return the values of the boundary nodes in **anti-clockwise** order starting from the root:
1. **Left Boundary** (excluding leaves, top-down).
2. **Leaf Nodes** (all leaf nodes from left to right).
3. **Right Boundary** (excluding leaves, bottom-up / reverse order).

```
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
        / \
       8   9

Anti-clockwise Boundary:
Root: 1
Left Boundary (excl leaf): 2
Leaves: 4, 8, 9, 6, 7
Right Boundary (bottom-up excl leaf): 3
Result: [1, 2, 4, 8, 9, 6, 7, 3]
```

---

## 1. Algorithmic Approach

### Step-by-Step Breakdown
1. **Root Handling:** If the root is not a leaf, add `root->val` to result.
2. **Left Boundary Traversal:**
   - Start from `root->left`.
   - While `curr` is not a leaf:
     - Add `curr->val`.
     - If `curr->left` exists, move left (`curr = curr->left`).
     - Otherwise, move right (`curr = curr->right`).
3. **Leaf Nodes Collection:**
   - Run a simple preorder/inorder traversal across the entire tree.
   - Whenever `!node->left && !node->right`, append `node->val`.
4. **Right Boundary Traversal (Reverse):**
   - Start from `root->right`.
   - Traverse downwards storing non-leaf nodes in a temporary vector or call stack:
     - If `curr->right` exists, move right; else move left.
   - Append nodes in reverse order to achieve bottom-up sequence.

---

## 2. Complexity Analysis
- **Time Complexity:** $O(N)$ — Left boundary takes $O(H)$, leaves take $O(N)$, right boundary takes $O(H)$. Total time is $O(N)$.
- **Space Complexity:** $O(H)$ auxiliary space for leaf traversal recursion stack and right boundary reversal buffer.

