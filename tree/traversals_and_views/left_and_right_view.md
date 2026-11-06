# Left and Right View of Binary Tree

## Problem Statement
Given the `root` of a binary tree:
1. **Right View:** Return the values of nodes visible when looking at the tree from the **right side** (top to bottom).
2. **Left View:** Return the values of nodes visible when looking at the tree from the **left side** (top to bottom).

```
          1
        /   \
       2     3
      / \     \
     4   5     6
        /
       7

Left View:  [1, 2, 4, 7]  (First node visible at each level)
Right View: [1, 3, 6, 7]  (Last node visible at each level)
```

---

## 1. Algorithmic Approaches

### Approach A: Reverse Preorder DFS ($O(N)$ time, $O(H)$ space)
Maintain the current `level` (0-indexed). Compare with `result.size()`:
- **Left View:** Traverse `Root -> Left -> Right`.
  - When reaching a new level for the first time (`level == result.size()`), add `node->val`.
  - Because `Left` is visited before `Right`, the leftmost node is captured first.
- **Right View:** Traverse `Root -> Right -> Left`.
  - When reaching a new level for the first time (`level == result.size()`), add `node->val`.
  - Because `Right` is visited before `Left`, the rightmost node is captured first.

### Approach B: Level Order BFS ($O(N)$ time, $O(W)$ space)
Using `levelSize = q.size()`:
- The node at index `0` of the level is part of the **Left View**.
- The node at index `levelSize - 1` of the level is part of the **Right View**.

---

## 2. Complexity Analysis
- **Time Complexity:** $O(N)$ — Every node is visited once.
- **Space Complexity:** $O(H)$ for DFS call stack, or $O(W)$ for BFS queue where $W \le N/2$ is maximum tree width.

