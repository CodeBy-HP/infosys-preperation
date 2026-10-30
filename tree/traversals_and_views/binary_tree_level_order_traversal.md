# Problem 1: Binary Tree Level Order Traversal (LeetCode 102)

## Problem Statement

Given the `root` of a binary tree, return the **level order traversal** of its nodes' values (i.e., from left to right, level by level).

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
- **Output:** `[[3], [9, 20], [15, 7]]`

### Example 2
- **Input:** `root = [1]`
- **Output:** `[[1]]`

### Example 3
- **Input:** `root = []`
- **Output:** `[]`

---

## Constraints

- The number of nodes in the tree is in the range $[0, 2000]$.
- $-1000 \le \text{Node.val} \le 1000$

---

## Pattern: The Level-Size Queue Snapshot

Standard BFS enqueues children and dequeues nodes, but loses track of row boundaries. To partition nodes strictly by levels:
1. Initialize `queue<TreeNode*> q` with `root`.
2. While `q` is not empty:
   - **Take the Snapshot:** `int levelSize = q.size()`. This freezes the count of nodes currently residing on this exact row.
   - Run a loop `levelSize` times:
     - Pop `curr = q.front()`.
     - Push `curr->val` into `currentLevel` array.
     - Enqueue `curr->left` and `curr->right` for the next level.
   - Push `currentLevel` into `results`.

```
Initial:      q = [3]                  -> levelSize = 1 -> row = [3]
After pop 3:  q = [9, 20]              -> levelSize = 2 -> row = [9, 20]
After row 2:  q = [15, 7]              -> levelSize = 2 -> row = [15, 7]
```

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **BFS Level-Size Snapshot** | $O(N)$ | $O(W) \approx O(N)$ | $W$ is max width of tree ($\le N/2$) |
| **DFS with Depth Parameter** | $O(N)$ | $O(H)$ | Appends to `res[depth]` recursively |
