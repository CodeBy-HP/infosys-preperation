# Bottom View of Binary Tree

## Problem Statement
Given the `root` of a binary tree, return the **bottom view** of the binary tree from left to right.

A node is included in the bottom view if it is the **bottom-most** (lowest visible) node at its vertical column coordinate. If multiple nodes share the same vertical column and depth, the one visited latest in level order is taken.

```
          1 (col 0)
        /   \
(col -1) 2   3 (col +1)
        / \   \
(col -2) 4 5   6 (col +2)
          \
           7 (col +1)

Bottom View: [4, 2, 5, 7, 6] (Node 5 is lowest at col 0; Node 7 overwrites 3 at col +1)
```

---

## 1. Algorithmic Approach (Level Order BFS with Overwrite)

### Core Invariant
- Horizontal column coordinate:
  $$\text{col}(\text{root}) = 0, \quad \text{col}(\text{left}) = \text{col} - 1, \quad \text{col}(\text{right}) = \text{col} + 1$$
- Use BFS queue with `std::pair<TreeNode*, int> {node, col}`.
- Unlike Top View (which only inserts on first discovery), Bottom View unconditionally **overwrites**:
  $$\text{bottomNode}[\text{col}] = \text{node}\to\text{val}$$
- Because BFS traverses level-by-level downwards, the final write at any column `col` is guaranteed to be from the lowest level!

---

## 2. Complexity Analysis
- **Time Complexity:** $O(N \log N)$ using `std::map` ordered extraction (or $O(N)$ with min/max column bounds).
- **Space Complexity:** $O(N)$ for BFS queue and map.
