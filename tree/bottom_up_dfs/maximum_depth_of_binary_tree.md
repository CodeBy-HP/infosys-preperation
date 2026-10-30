# Problem 5: Maximum Depth of Binary Tree (LeetCode 104)

## Problem Statement

Given the `root` of a binary tree, return its **maximum depth**.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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
- **Output:** `3`

---

## Constraints

- The number of nodes in the tree is in the range $[0, 10^4]$.
- $-100 \le \text{Node.val} \le 100$

---

## Fundamental Bottom-Up Recurrence

Depth of a tree at node $u$:
$$\text{Depth}(u) = 1 + \max(\text{Depth}(u\to\text{left}), \text{Depth}(u\to\text{right}))$$
Base case:
$$\text{Depth}(\text{null}) = 0$$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Recursive Bottom-Up DFS** | $O(N)$ | $O(H)$ recursion stack |
| **Iterative BFS Level Count**| $O(N)$ | $O(W)$ queue width |
