# Problem 15: Lowest Common Ancestor with Parent Pointers (LeetCode 1650)

## Problem Statement

Given two nodes of a binary tree `p` and `q`, return their **lowest common ancestor (LCA)**.

Each node will have a reference to its parent node. The definition for `Node` is below:

```cpp
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
```

---

## Mathematical Reduction: Linked List Intersection

When nodes possess `parent` pointers, tracing parent links from `p` and `q` to the root is structurally **identical to two intersecting singly linked lists**!
1. Pointer `a = p` walks up parent chain to root, then resets to `q`.
2. Pointer `b = q` walks up parent chain to root, then resets to `p`.
3. Path equalization ($d_p + d_{lca} + d_q = d_q + d_{lca} + d_p$) ensures both pointers collide exactly at the LCA!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Two-Pointer Equalization** | $O(H)$ | $O(1)$ | Strictly $O(1)$ space |
| **Hash Set**                 | $O(H)$ | $O(H)$ | Stores visited parents |
