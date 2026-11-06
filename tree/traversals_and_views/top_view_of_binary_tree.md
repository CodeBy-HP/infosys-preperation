# Top View of Binary Tree

## Problem Statement
Given the `root` of a binary tree, return the **top view** of the binary tree from left to right.

A node is included in the top view if it is the **topmost** node at its vertical column coordinate. If two nodes are at the same vertical column and the same level, the one occurring first in level order is chosen.

```
          1 (col 0)
        /   \
(col -1) 2   3 (col +1)
        / \   \
(col -2) 4 5   6 (col +2)
          \
           7 (col 0 - hidden by 1)

Top View: [4, 2, 1, 3, 6]
```

---

## 1. Algorithmic Approach (Level Order BFS + Column Map)

### Coordinate System
Assign horizontal distance (column index):
- $\text{col}(\text{root}) = 0$
- $\text{col}(\text{node}\to\text{left}) = \text{col} - 1$
- $\text{col}(\text{node}\to\text{right}) = \text{col} + 1$

### Why Level-Order BFS is Required (Not DFS)
BFS naturally processes nodes **top-down level-by-level**.
- Maintain a `std::map<int, int> topNode` mapping `col -> node->val`.
- Queue holds `std::pair<TreeNode*, int> {node, col}`.
- Whenever a column `col` is encountered for the **first time** (`topNode.find(col) == topNode.end()`), insert `topNode[col] = node->val`.
- Any subsequent nodes visited at that column on deeper levels are naturally ignored because the map already holds the topmost node!
- Inorder traversal of the sorted map produces the left-to-right top view.

---

## 2. Complexity Analysis
- **Time Complexity:** $O(N \log N)$ using `std::map` (or $O(N)$ tracking `minCol` and `maxCol` with an array/hash map).
- **Space Complexity:** $O(N)$ for the queue and map storing nodes and column coordinates.

