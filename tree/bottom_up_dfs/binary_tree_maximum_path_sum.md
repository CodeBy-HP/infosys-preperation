# Problem 8: Binary Tree Maximum Path Sum (LeetCode 124)

## Problem Statement

A **path** in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence **at most once**. Note that the path does not need to pass through the root.

The **path sum** of a path is the sum of the node's values in the path.

Given the `root` of a binary tree, return the **maximum path sum** of any non-empty path.

---

## Examples

### Example 1
```text
    1
   / \
  2   3
```
- **Input:** `root = [1, 2, 3]`
- **Output:** `6` (`2 + 1 + 3`)

### Example 2
```text
       -10
       /  \
      9   20
         /  \
        15   7
```
- **Input:** `root = [-10, 9, 20, null, null, 15, 7]`
- **Output:** `42` (`15 + 20 + 7`)

---

## Constraints

- The number of nodes in the tree is in the range $[1, 3 \times 10^4]$.
- $-1000 \le \text{Node.val} \le 1000$

---

## DP on Trees: Pruning Negative Gains

For each node $u$:
1. **Recursive Call:** Calculate max single-branch contribution from left and right children.
2. **Negative Gain Pruning:** If a child's contribution is negative, choose not to include it:
   $$\text{leftGain} = \max(0, \text{dfs}(u\to\text{left}))$$
   $$\text{rightGain} = \max(0, \text{dfs}(u\to\text{right}))$$
3. **Local Arch Sum:** The path bridging through $u$ is:
   $$\text{currentPathSum} = u\to\text{val} + \text{leftGain} + \text{rightGain}$$
   Update global maximum: $\text{maxSum} = \max(\text{maxSum}, \text{currentPathSum})$.
4. **Return Upward:** Return the maximum single branch extension to parent:
   $$u\to\text{val} + \max(\text{leftGain}, \text{rightGain})$$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Bottom-Up DP on Trees** | $O(N)$ | $O(H)$ recursion stack |
