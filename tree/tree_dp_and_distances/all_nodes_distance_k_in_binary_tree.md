# Problem 24: All Nodes Distance K in Binary Tree (LeetCode 863)

## Problem Statement

Given the `root` of a binary tree, the value of a target node `target`, and an integer `k`, return an array of the values of all nodes that have a distance `k` from the target node.

You can return the answer in **any order**.

---

## Examples

### Example 1
```text
        3
       / \
     (5)  1
     / \ / \
    6  2 0  8
      / \
     7   4
```
- **Input:** `root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2`
- **Output:** `[7, 4, 1]`
- **Explanation:** The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

---

## Constraints

- The number of nodes in the tree is in the range $[1, 500]$.
- $0 \le \text{Node.val} \le 500$
- All the values `Node.val` are **unique**.
- `target` is the value of one of the nodes in the tree.
- $0 \le k \le 1000$

---

## Pattern: Tree to Undirected Graph Radial BFS

Trees only have downward pointers (`left` and `right`). Distance $k$ nodes can reside **upwards** through parents!
1. **Build Parent Pointers:** Perform a DFS/BFS to populate `unordered_map<TreeNode*, TreeNode*> parentMap`.
2. **Radial BFS from Target:**
   - Initialize queue with `targetNode` and `unordered_set<TreeNode*> visited = {targetNode}`.
   - At each BFS level increment `distance++`.
   - For each node, explore 3 directions: `left`, `right`, and `parentMap[curr]`.
   - When `distance == k`, the queue contains all nodes at distance $k$!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Parent Map + Radial BFS** | $O(N)$ | $O(N)$ map + queue |
