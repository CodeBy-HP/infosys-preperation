# Problem 4: Vertical Order Traversal of a Binary Tree (LeetCode 987)

## Problem Statement

Given the `root` of a binary tree, calculate the **vertical order traversal** of the binary tree.

For each node at position `(row, col)`:
- Its left child will be at `(row + 1, col - 1)`
- Its right child will be at `(row + 1, col + 1)`
- The root is at `(0, 0)`.

The vertical order traversal is a list of top-to-bottom orderings for each column starting from the leftmost column to the rightmost column.
If two nodes have the same row and column, sort them by **their values**.

---

## Examples

### Example 1
```text
      3 (0, 0)
     / \
    9   20
(1,-1)  (1, 1)
        /  \
       15   7
    (2, 0) (2, 2)
```
- **Input:** `root = [3, 9, 20, null, null, 15, 7]`
- **Output:** `[[9], [3, 15], [20], [7]]`

---

## Constraints

- The number of nodes in the tree is in the range $[1, 1000]$.
- $0 \le \text{Node.val} \le 1000$

---

## Pattern: Multi-Key Coordinate Mapping

Assign coordinates `(col, row, val)`:
1. `col` groups vertical columns from left to right.
2. Within each column, sort primarily by `row` (top to bottom).
3. If two nodes share the same `col` and `row`, tie-break by `val` ascending.

Using `map<int, multiset<pair<int, int>>>` or sorting tuples `(col, row, val)`:
- Automatic key ordering naturally yields leftmost column first.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Coordinate Collection + Sort** | $O(N \log N)$ | $O(N)$ | Multi-key sorting |
