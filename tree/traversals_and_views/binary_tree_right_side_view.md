# Problem 3: Binary Tree Right Side View (LeetCode 199)

## Problem Statement

Given the `root` of a binary tree, imagine yourself standing on the **right side** of it. Return the values of the nodes you can see ordered from top to bottom.

---

## Examples

### Example 1
```text
      1            <--- 1
    /   \
   2     3         <--- 3
    \     \
     5     4       <--- 4
```
- **Input:** `root = [1, 2, 3, null, 5, null, 4]`
- **Output:** `[1, 3, 4]`

### Example 2 (Deep Left Branch Edge Case)
```text
      1            <--- 1
    /   \
   2     3         <--- 3
  /
 4                 <--- 4 (Visible because right subtree has no depth 3!)
```
- **Output:** `[1, 3, 4]`

---

## Constraints

- The number of nodes in the tree is in the range $[0, 100]$.
- $-100 \le \text{Node.val} \le 100$

---

## Two Core Approaches

### 1. BFS Level-Size Snapshot
At each level, the last node processed in the inner `levelSize` loop (`i == levelSize - 1`) is guaranteed to be the rightmost visible node of that tier.

### 2. Reverse Preorder DFS (`Root -> Right -> Left`)
Traverse the right child first! The first node encountered at any new depth `level == result.size()` must be the rightmost visible node on that level.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Reverse Preorder DFS** | $O(N)$ | $O(H)$ | Strictly $O(H)$ recursion stack |
| **BFS Queue**            | $O(N)$ | $O(W)$ | Level snapshot |
