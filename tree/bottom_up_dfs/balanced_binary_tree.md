# Problem 7: Balanced Binary Tree (LeetCode 110)

## Problem Statement

Given a binary tree, determine if it is **height-balanced**.

A height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differs by more than one.

---

## Examples

### Example 1
```text
      3
     / \
    9  20
      /  \
     15   7
```
- **Input:** `root = [3, 9, 20, null, null, 15, 7]`
- **Output:** `true`

### Example 2
```text
        1
       / \
      2   2
     / \
    3   3
   / \
  4   4
```
- **Input:** `root = [1, 2, 2, 3, 3, null, null, 4, 4]`
- **Output:** `false`

---

## Constraints

- The number of nodes in the tree is in the range $[0, 5000]$.
- $-10^4 \le \text{Node.val} \le 10^4$

---

## The $O(N)$ Short-Circuiting Sentinel Pattern

Naive top-down checking calls `height(node)` on every node, taking $O(N^2)$ worst-case time on skewed trees.
Instead, use Bottom-Up DFS with **`-1` as an error signal**:
- If `leftHeight == -1` or `rightHeight == -1`, short-circuit and bubble `-1` up immediately.
- If `|leftHeight - rightHeight| > 1`, report imbalance by returning `-1`.
- Otherwise, return true height: `1 + max(leftHeight, rightHeight)`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Bottom-Up Sentinel Signal** | $O(N)$ | $O(H)$ | Stops early on imbalance |
| **Naive Top-Down Height**     | $O(N^2)$ | $O(H)$ | Recomputes heights repeatedly |
