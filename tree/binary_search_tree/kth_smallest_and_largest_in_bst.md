# K-th Smallest and K-th Largest Element in a BST

## Problem Statement
Given the `root` of a binary search tree (BST) and an integer `k`:
1. Find the **$k$-th smallest** value (1-indexed) in the BST.
2. Find the **$k$-th largest** value (1-indexed) in the BST.

```
          5
        /   \
       3     6
      / \
     2   4
    /
   1

k = 3:
Sorted Elements: [1, 2, 3, 4, 5, 6]
3rd Smallest: 3
3rd Largest:  4
```

---

## 1. Algorithmic Approach

### A. $K$-th Smallest (Inorder Traversal)
- Inorder traversal ($\text{Left} \to \text{Root} \to \text{Right}$) visits elements in **ascending order**.
- Maintain a countdown counter `k`:
  - Recurse down the left subtree.
  - At current root: decrement `k--`. If `k == 0`, record `ans = root->val` and return immediately (early pruning).
  - Recurse down the right subtree.

### B. $K$-th Largest (Reverse Inorder Traversal)
- Reverse Inorder traversal ($\text{Right} \to \text{Root} \to \text{Left}$) visits elements in **descending order**.
- Maintain a countdown counter `k`:
  - Recurse down the right subtree first.
  - At current root: decrement `k--`. If `k == 0`, record `ans = root->val` and stop.
  - Recurse down the left subtree.

---

## 2. Complexity Analysis
- **Time Complexity:** $O(H + k)$ — Stops immediately upon encountering the $k$-th element, avoiding full $O(N)$ tree traversal.
- **Space Complexity:** $O(H)$ auxiliary call stack frames ($O(\log N)$ balanced, $O(N)$ worst-case). Can also be achieved in strictly $O(1)$ space using Morris Inorder/Reverse-Inorder Traversal.

