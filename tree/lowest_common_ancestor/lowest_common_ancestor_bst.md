# Problem 14: Lowest Common Ancestor of a Binary Search Tree (LeetCode 235)

## Problem Statement

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes `p` and `q` in the BST.

According to the definition of LCA on Wikipedia: "The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**)."

---

## Examples

### Example 1
```text
        6
       / \
      2   8
     / \ / \
    0  4 7  9
      / \
     3   5
```
- **Input:** `root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8`
- **Output:** `6`

### Example 2
- **Input:** `p = 2, q = 4` (same BST)
- **Output:** `2`

---

## Constraints

- The number of nodes in the tree is in the range $[2, 10^5]$.
- $-10^9 \le \text{Node.val} \le 10^9$
- All `Node.val` are **unique**.
- `p != q`
- `p` and `q` will exist in the BST.

---

## Exploiting BST Math: The Split Point

In a standard binary tree, finding LCA takes $O(N)$ time by scouting all branches.
In a **BST**, we can discard half the tree at each step in $O(H)$ time:
- **Both nodes are smaller than root:** Both `p` and `q` lie entirely in the left subtree. Move `curr = curr->left`.
- **Both nodes are greater than root:** Both `p` and `q` lie entirely in the right subtree. Move `curr = curr->right`.
- **Split Point:** If one is on the left and the other is on the right (or `curr == p` or `curr == q`), `curr` is the **LCA**. Stop immediately!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Iterative Split Search** | $O(H)$ | $O(1)$ | Strictly $O(1)$ auxiliary space |
| **Recursive BST Search**  | $O(H)$ | $O(H)$ | Recursion stack |
