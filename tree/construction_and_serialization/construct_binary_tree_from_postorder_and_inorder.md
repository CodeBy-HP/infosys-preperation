# Construct Binary Tree from Inorder and Postorder Traversal

## Problem Statement
Given two integer arrays `inorder` and `postorder` where `inorder` is the inorder traversal of a binary tree and `postorder` is the postorder traversal of the same tree, construct and return the binary tree.

```
Inorder:   [9, 3, 15, 20, 7]
Postorder: [9, 15, 7, 20, 3]

Output Tree:
    3
   / \
  9  20
    /  \
   15   7
```

---

## 1. Algorithmic Approach (Hash Map + Index Slicing)

### Core Invariant
- **Root Identification:** The last element of the postorder range, `postorder[postEnd]`, is always the root of the current subtree.
- **Subtree Partitioning:** Locate `rootVal` in `inorder` at index `inRoot` using a precomputed hash map `inMap[val] -> index`:
  - Elements in `inorder` from `inStart` to `inRoot - 1` form the **Left Subtree**.
  - Elements in `inorder` from `inRoot + 1` to `inEnd` form the **Right Subtree**.
- **Index Offsets:**
  - Size of left subtree: $\text{numsLeft} = \text{inRoot} - \text{inStart}$.
  - **Left Subtree Postorder Range:** `postStart` to `postStart + numsLeft - 1`.
  - **Right Subtree Postorder Range:** `postStart + numsLeft` to `postEnd - 1`.

```
inorder:   [  LEFT SUBTREE  ] [ inRoot ] [  RIGHT SUBTREE  ]
           inStart      inRoot-1         inRoot+1        inEnd

postorder: [  LEFT SUBTREE  ] [  RIGHT SUBTREE  ] [ ROOT ]
           postStart     postStart+numsLeft-1     postEnd-1   postEnd
```

---

## 2. Complexity Analysis
- **Time Complexity:** $O(N)$ — Precomputing the hash map takes $O(N)$. Each of the $N$ nodes is created exactly once in $O(1)$ time.
- **Space Complexity:** $O(N)$ — Hash map stores $N$ entries; recursion stack depth bounded by tree height $H \le N$.

