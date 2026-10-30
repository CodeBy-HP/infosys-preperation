# Problem 13: Lowest Common Ancestor of a Binary Tree (LeetCode 236)

## Problem Statement

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes `p` and `q` in the tree.

According to the definition of LCA on Wikipedia: "The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**)."

---

## Examples

### Example 1
```text
        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4
```
- **Input:** `root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1`
- **Output:** `3`

### Example 2
- **Input:** `p = 5, q = 4` (from same tree above)
- **Output:** `5` (since a node can be a descendant of itself)

---

## Constraints

- The number of nodes in the tree is in the range $[2, 10^5]$.
- $-10^9 \le \text{Node.val} \le 10^9$
- All `Node.val` are **unique**.
- `p != q`
- `p` and `q` will exist in the tree.

---

## Bottom-Up "Bubble Up" Scouting Strategy

1. **Discovery (Base Case):**
   - If `node == nullptr`, return `nullptr`.
   - If `node == p || node == q`, return `node` (signal discovery upward!).
2. **Recursive Scouting:**
   - `left = lowestCommonAncestor(node->left, p, q)`
   - `right = lowestCommonAncestor(node->right, p, q)`
3. **Tri-State Convergence:**
   - **Case A (`left && right`):** `p` was found in left subtree, `q` in right. The current node is the exact convergence point: return `node`!
   - **Case B (one of them is non-null):** Both `p` and `q` are situated in that single subtree: return `left ? left : right`.
   - **Case C (both null):** Return `nullptr`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Bottom-Up Post-Order DFS** | $O(N)$ | $O(H)$ recursion stack |
