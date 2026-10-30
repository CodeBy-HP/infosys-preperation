# Problem 17: Kth Smallest Element in a BST (LeetCode 230)

## Problem Statement

Given the `root` of a binary search tree, and an integer `k`, return the $k^{\text{th}}$ smallest value (**1-indexed**) of all the values of the nodes in the tree.

---

## Examples

### Example 1
```text
        3
       / \
      1   4
       \
        2
```
- **Input:** `root = [3, 1, 4, null, 2], k = 1`
- **Output:** `1`

### Example 2
```text
        5
       / \
      3   6
     / \
    2   4
   /
  1
```
- **Input:** `root = [5, 3, 6, 2, 4, null, null, 1], k = 3`
- **Output:** `3`

---

## Constraints

- The number of nodes in the tree is $n$.
- $1 \le k \le n \le 10^4$
- $0 \le \text{Node.val} \le 10^4$

---

## Pattern: In-Order Traversal with Countdown Pruning

Because an In-Order Traversal (`Left -> Node -> Right`) flattens a BST into strictly ascending order:
1. Traverse left subtree first.
2. When standing at current node, decrement `k--`.
3. If `k == 0`: current node is the answer! Store result and prune further searching.
4. If `k > 0`: traverse right subtree.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Pruned In-Order DFS** | $O(H + k)$ | $O(H)$ | Stops as soon as $k^{\text{th}}$ element found |
| **Iterative Stack**     | $O(H + k)$ | $O(H)$ | Explicit stack control |
