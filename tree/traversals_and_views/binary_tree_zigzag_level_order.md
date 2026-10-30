# Problem 2: Binary Tree Zigzag Level Order Traversal (LeetCode 103)

## Problem Statement

Given the `root` of a binary tree, return the **zigzag level order traversal** of its nodes' values (i.e., from left to right, then right to left for the next level and alternate between).

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
- **Output:** `[[3], [20, 9], [15, 7]]`

---

## Constraints

- The number of nodes in the tree is in the range $[0, 2000]$.
- $-100 \le \text{Node.val} \le 100$

---

## Pattern: Two-Pointer Placement or Boolean Flip

Instead of reversing the array afterwards, we can directly assign elements to their final positions within a pre-allocated vector of size `levelSize`:
- If `leftToRight == true`: place at index `i`.
- If `leftToRight == false`: place at index `levelSize - 1 - i`.
- Flip boolean `leftToRight = !leftToRight` after each level.

```
Level 0 (L -> R): [3]
Level 1 (R -> L): index 0 gets 20, index 1 gets 9 -> [20, 9]
Level 2 (L -> R): [15, 7]
```

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Direct Index Placement** | $O(N)$ | $O(W)$ | Zero extra reversals |
| **Deque / Vector Reverse** | $O(N)$ | $O(W)$ | Reverses alternate levels |
