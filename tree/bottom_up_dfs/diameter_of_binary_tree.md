# Problem 6: Diameter of Binary Tree (LeetCode 543)

## Problem Statement

Given the `root` of a binary tree, return the length of the **diameter** of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

---

## Examples

### Example 1
```text
          1
         / \
        2   3
       / \     
      4   5    
```
- **Input:** `root = [1, 2, 3, 4, 5]`
- **Output:** `3`
- **Explanation:** 3 is the length of the path `[4, 2, 1, 3]` or `[5, 2, 1, 3]`.

---

## Constraints

- The number of nodes in the tree is in the range $[1, 10^4]$.
- $-100 \le \text{Node.val} \le 100$

---

## Bottom-Up DFS Pattern: "Pass Up Height, Update Arch Diameter"

If you want to find the longest path bridging across a specific node:
1. **Ask Children for Depth:** `leftDepth = getDepth(node->left)`, `rightDepth = getDepth(node->right)`.
2. **Local Arch Calculation:** The longest path that curves through the current node is `leftDepth + rightDepth`.
3. **Global Update:** `maxDiameter = max(maxDiameter, leftDepth + rightDepth)`.
4. **Return Upward:** A straight path cannot fork in two directions to parent; it must return a single branch: `1 + max(leftDepth, rightDepth)`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Bottom-Up DFS** | $O(N)$ | $O(H)$ recursion stack |
