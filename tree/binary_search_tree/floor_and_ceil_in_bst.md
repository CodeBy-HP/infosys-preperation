# Floor and Ceil in a Binary Search Tree (BST)

## Problem Definitions

Given the `root` of a BST and a target key `X`:

1. **Floor of X:** The **maximum** value in the BST that is **less than or equal to** `X`:
   $$\text{floor}(X) = \max \{ v \in \text{BST} \mid v \le X \}$$
2. **Ceil of X:** The **minimum** value in the BST that is **greater than or equal to** `X`:
   $$\text{ceil}(X) = \min \{ v \in \text{BST} \mid v \ge X \}$$

If no such node exists, return `-1`.

```
          10
        /    \
       5      13
      / \    /  \
     3   6  11   14
    / \   \
   2   4   9

Target X = 8:
- Floor(8) = 6 (Largest key <= 8)
- Ceil(8)  = 9 (Smallest key >= 8)

Target X = 10:
- Floor(10) = 10
- Ceil(10)  = 10
```

---

## 1. Algorithmic Approach

### A. Finding Floor ($O(H)$ time, $O(1)$ space)
- Initialize `floorVal = -1`.
- While `curr != nullptr`:
  - If `curr->val == X`: exact match! Return `X`.
  - If `X > curr->val`:
    - `curr->val` is a valid candidate for floor! Record `floorVal = curr->val`.
    - Try to find an even larger value $\le X$ by moving **right**: `curr = curr->right`.
  - If `X < curr->val`:
    - `curr->val` is too large to be a floor. Move **left**: `curr = curr->left`.

### B. Finding Ceil ($O(H)$ time, $O(1)$ space)
- Initialize `ceilVal = -1`.
- While `curr != nullptr`:
  - If `curr->val == X`: exact match! Return `X`.
  - If `X < curr->val`:
    - `curr->val` is a valid candidate for ceil! Record `ceilVal = curr->val`.
    - Try to find an even smaller value $\ge X$ by moving **left**: `curr = curr->left`.
  - If `X > curr->val`:
    - `curr->val` is too small to be a ceil. Move **right**: `curr = curr->right`.

---

## 2. Complexity Analysis
- **Time Complexity:** $O(H)$ — Traverses down a single branch from root to leaf ($O(\log N)$ balanced, $O(N)$ worst-case).
- **Space Complexity:** $O(1)$ auxiliary memory (iterative pointers).

