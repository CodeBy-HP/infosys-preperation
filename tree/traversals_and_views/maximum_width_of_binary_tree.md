# Maximum Width of Binary Tree

## Problem Statement
Given the `root` of a binary tree, return the **maximum width** of the given tree.

The **maximum width** of a tree is the maximum width among all levels.
The width of one level is defined as the length between the leftmost and rightmost non-null nodes at that level, where intermediate `null` nodes that would exist in a **full complete binary tree** are also counted into the length calculation.

```
          1
        /   \
       3     2
      /       \
     5         9
    /           \
   6             7

Level 0: width = 1
Level 1: width = 2
Level 2: width = 4 (nodes 5, null, null, 9)
Level 3: width = 8 (nodes 6, ..., 7)
Max Width = 8
```

---

## 1. Algorithmic Approach (0-Indexed Heap Coordinates with Normalized Offsets)

### Coordinate System
In a complete binary tree:
- If a parent is at index $i$:
  - Left child is at $2i + 1$.
  - Right child is at $2i + 2$.

### The 64-bit Integer Overflow Dilemma & Normalization Trick
In a skewed tree of depth $H = 3000$, indices grow as $2^{3000}$, overflowing even `unsigned long long`!
**Crucial Optimization:**
At the start of each level:
1. Capture `min_idx = q.front().second`.
2. Subtract `min_idx` from every node's index at that level:
   $$\text{normalized\_idx} = \text{idx} - \text{min\_idx}$$
3. This resets the leftmost node's coordinate of the current tier to $0$.
4. Then spawn children using $2 \times \text{normalized\_idx} + 1$ and $2 \times \text{normalized\_idx} + 2$.
5. The width of that level is strictly:
   $$\text{width} = \text{last\_idx} - \text{first\_idx} + 1$$

---

## 2. Complexity Analysis
- **Time Complexity:** $O(N)$ — Every node is queued and processed once.
- **Space Complexity:** $O(W) \le O(N)$ — The queue holds at most the maximum number of nodes at any level.

