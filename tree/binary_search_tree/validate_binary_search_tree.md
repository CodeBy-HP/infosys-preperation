# Problem 16: Validate Binary Search Tree (LeetCode 98)

## Problem Statement

Given the `root` of a binary tree, determine if it is a **valid binary search tree (BST)**.

A **valid BST** is defined as follows:
- The left subtree of a node contains only nodes with keys **strictly less than** the node's key.
- The right subtree of a node contains only nodes with keys **strictly greater than** the node's key.
- Both the left and right subtrees must also be binary search trees.

---

## Examples

### Example 1
```text
    2
   / \
  1   3
```
- **Input:** `root = [2, 1, 3]`
- **Output:** `true`

### Example 2 (The Trap)
```text
    5
   / \
  1   4
     / \
    3   6
```
- **Input:** `root = [5, 1, 4, null, null, 3, 6]`
- **Output:** `false` (node 3 violates root boundary 5)

---

## Constraints

- The number of nodes in the tree is in the range $[1, 10^4]$.
- $-2^{31} \le \text{Node.val} \le 2^{31} - 1$

---

## Two Sound Paradigms

### 1. Top-Down Range Propagation
Pass allowed interval `(low, high)`:
- Left child constraint: `(low, node->val)`
- Right child constraint: `(node->val, high)`
- Use `long long` or node pointers to handle `INT_MIN` / `INT_MAX`.

### 2. In-Order Traversal Invariant
An in-order traversal of a valid BST must yield **strictly ascending values**:
$$\text{prevVal} < \text{curr->val}$$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Top-Down Range DFS** | $O(N)$ | $O(H)$ recursion stack |
| **In-Order Traversal**  | $O(N)$ | $O(H)$ stack |
