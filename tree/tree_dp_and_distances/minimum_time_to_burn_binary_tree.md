# Minimum Time Taken to Burn a Binary Tree from a Given Node

## Problem Statement
Given the `root` of a binary tree and a target `start` node value:
At minute $t = 0$, fire starts at the `start` node. Every minute, the fire spreads simultaneously from currently burning nodes to all **adjacent unburned nodes**:
- Left child
- Right child
- Parent node

Return the **minimum time (in minutes)** required for the entire binary tree to burn.

```
          1
        /   \
       2     3
      / \     \
     4   5     6
        / \
       7   8

Target = 8
Minute 0: [8]
Minute 1: [5] (Parent)
Minute 2: [2, 7] (Parent of 5, Left child of 5)
Minute 3: [1, 4] (Parent of 2, Left child of 2)
Minute 4: [3] (Right child of 1)
Minute 5: [6] (Right child of 3)
Total time to burn: 5 minutes
```

---

## 1. Algorithmic Approach (Parent Pointer Mapping + Radial BFS)

### Step 1: Bidirectional Graph Construction
Binary tree nodes only store downward pointers (`left`, `right`). Because fire propagates upward as well:
- Perform an initial level-order BFS (or DFS) to build a parent mapping:
  $$\text{parentMap}[\text{child}] = \text{parent}$$
- Simultaneously locate and save the pointer to `startNode`.

### Step 2: Radial Breadth-First Fire Simulation
- Initialize a queue with `startNode`, and mark `startNode` as visited in `std::unordered_set<TreeNode*> visited`.
- At each minute:
  - Freeze `size = q.size()`.
  - Maintain a boolean `burnedAny = false`.
  - For each burning node, examine its 3 radial neighbors:
    1. `curr->left`
    2. `curr->right`
    3. `parentMap[curr]`
  - If a neighbor exists and is unvisited: mark visited, push to queue, and set `burnedAny = true`.
  - If `burnedAny == true`, increment `time++`.

---

## 2. Complexity Analysis
- **Time Complexity:** $O(N)$ — Initial parent mapping visits all $N$ nodes in $O(N)$ time. The radial BFS visits each node and edge at most once in $O(N)$ time.
- **Space Complexity:** $O(N)$ — `parentMap`, `visited` set, and BFS queue store references to $N$ nodes.

