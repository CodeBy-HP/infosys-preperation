# Problem 10: Path Sum II (LeetCode 113)

## Problem Statement

Given the `root` of a binary tree and an integer `targetSum`, return **all root-to-leaf paths** where the sum of the node values in the path equals `targetSum`. Each path should be returned as a list of the node values, not node references.

A **leaf** is a node with no children.

---

## Examples

### Example 1
```text
        5
       / \
      4   8
     /   / \
    11  13  4
   /  \    / \
  7    2  5   1
```
- **Input:** `root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22`
- **Output:** `[[5, 4, 11, 2], [5, 8, 4, 5]]`

---

## Constraints

- The number of nodes in the tree is in the range $[0, 5000]$.
- $-1000 \le \text{Node.val} \le 1000$
- $-1000 \le \text{targetSum} \le 1000$

---

## Pattern: Top-Down DFS with Vector Backtracking

1. **State:** Pass `currentPath` vector by reference to avoid copying at each recursive frame, alongside `remainingSum`.
2. **Process Node:** `currentPath.push_back(node->val)`.
3. **Leaf Validation:** If `!node->left && !node->right && node->val == remainingSum`, push a copy of `currentPath` to `result`.
4. **Recurse:** Continue down left and right subtrees with `remainingSum - node->val`.
5. **Backtrack:** `currentPath.pop_back()` before returning to parent!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **DFS + Backtracking** | $O(N)$ (or $O(N^2)$ worst case) | $O(H)$ | Path copying on valid leaf |
