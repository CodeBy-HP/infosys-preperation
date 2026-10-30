# Problem 9: Path Sum (LeetCode 112)

## Problem Statement

Given the `root` of a binary tree and an integer `targetSum`, return `true` if the tree has a **root-to-leaf** path such that adding up all the values along the path equals `targetSum`.

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
   /  \      \
  7    2      1
```
- **Input:** `root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22`
- **Output:** `true` (`5 + 4 + 11 + 2 = 22`)

---

## Constraints

- The number of nodes in the tree is in the range $[0, 5000]$.
- $-1000 \le \text{Node.val} \le 1000$
- $-1000 \le \text{targetSum} \le 1000$

---

## Top-Down State Passing Logic

1. Pass `remainingSum = targetSum - node->val` down to child subtrees.
2. **Leaf Condition:** A path only terminates at a true leaf (`!node->left && !node->right`).
   - If at leaf, return `node->val == targetSum`.
3. Recursively check either subtree:
   `hasPathSum(node->left, remaining) || hasPathSum(node->right, remaining)`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Top-Down DFS** | $O(N)$ | $O(H)$ recursion stack |
