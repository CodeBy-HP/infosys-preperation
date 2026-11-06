# Minimum and Maximum in a Binary Search Tree (BST)

## Problem Statement
Given the `root` of a binary search tree (BST), find:
1. The **minimum element** in the BST.
2. The **maximum element** in the BST.

```
          10
        /    \
       5      20
      / \    /  \
     2   8  15  25
    /
   1

Minimum = 1 (Leftmost node)
Maximum = 25 (Rightmost node)
```

---

## 1. Algorithmic Approach

### Core Invariant
From the BST definition:
- For any node, all smaller elements reside strictly in its **left subtree**.
- For any node, all larger elements reside strictly in its **right subtree**.

Therefore:
- **Finding Minimum:** Start at the root and continuously traverse down the **left pointers** until reaching a node whose `left == nullptr`. That node's value is the global minimum.
- **Finding Maximum:** Start at the root and continuously traverse down the **right pointers** until reaching a node whose `right == nullptr`. That node's value is the global maximum.

---

## 2. Complexity Analysis
- **Time Complexity:** $O(H)$ — Traverses along the leftmost / rightmost branch of height $H \le N$.
- **Space Complexity:** $O(1)$ — Iterative traversal without recursion stack.

