# Inorder Successor and Predecessor in a BST

## Problem Statement
Given the `root` of a binary search tree (BST) and a target node `p`:
1. **Inorder Successor:** Find the node with the smallest key strictly greater than `p->val`.
2. **Inorder Predecessor:** Find the node with the greatest key strictly less than `p->val`.

If no such node exists, return `nullptr`.

```
          5
        /   \
       2     7
      / \   / \
     1   4 6   9
        /     /
       3     8

Target p = 4:
Inorder: [1, 2, 3, 4, 5, 6, 7, 8, 9]
Predecessor(4) = 3 (immediate predecessor in sorted sequence)
Successor(4)   = 5 (immediate successor in sorted sequence)
```

---

## 1. Algorithmic Approach ($O(H)$ Time, $O(1)$ Space)

### Finding Inorder Successor
The successor must have a key $> p\to\text{val}$.
1. Initialize `successor = nullptr`, `curr = root`.
2. While `curr != nullptr`:
   - If `p->val >= curr->val`:
     - The current node and its entire left subtree are $\le p\to\text{val}$.
     - The successor must lie strictly in the **right subtree**: `curr = curr->right`.
   - If `p->val < curr->val`:
     - `curr` is strictly greater than `p`, making it a valid successor candidate!
     - Save `successor = curr`.
     - Try to find an even smaller valid candidate by moving **left**: `curr = curr->left`.

---

### Finding Inorder Predecessor
The predecessor must have a key $< p\to\text{val}$.
1. Initialize `predecessor = nullptr`, `curr = root`.
2. While `curr != nullptr`:
   - If `p->val <= curr->val`:
     - The current node and its entire right subtree are $\ge p\to\text{val}$.
     - The predecessor must lie strictly in the **left subtree**: `curr = curr->left`.
   - If `p->val > curr->val`:
     - `curr` is strictly less than `p`, making it a valid predecessor candidate!
     - Save `predecessor = curr`.
     - Try to find an even larger valid candidate by moving **right**: `curr = curr->right`.

---

## 2. Complexity Analysis
- **Time Complexity:** $O(H)$ — Traverses down a single root-to-leaf path ($O(\log N)$ balanced, $O(N)$ skewed).
- **Space Complexity:** $O(1)$ — Strictly constant auxiliary memory.

