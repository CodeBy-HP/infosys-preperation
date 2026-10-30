# Problem 21: Construct Binary Tree from Preorder and Inorder Traversal (LeetCode 105)

## Problem Statement

Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree and `inorder` is the inorder traversal of the same tree, construct and return the **binary tree**.

---

## Examples

### Example 1
```text
    3
   / \
  9  20
    /  \
   15   7
```
- **Input:** `preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]`
- **Output:** `[3,9,20,null,null,15,7]`

---

## Constraints

- $1 \le \text{preorder.length} \le 3000$
- $\text{inorder.length} == \text{preorder.length}$
- $-3000 \le \text{preorder}[i], \text{inorder}[i] \le 3000$
- `preorder` and `inorder` consist of **unique** values.
- Each value of `inorder` also appears in `preorder`.

---

## Algorithmic Anatomy: Hash Map Partitioning

1. `preorder` always supplies the **Root** as its first element: `rootVal = preorder[preIndex++]`.
2. Locate `rootVal` in `inorder` at index `inIndex` using an $O(1)$ precomputed hash map.
3. Every element to the left of `inIndex` belongs to the **Left Subtree**:
   `root->left = build(left, inIndex - 1)`.
4. Every element to the right of `inIndex` belongs to the **Right Subtree**:
   `root->right = build(inIndex + 1, right)`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Hash Map Inorder Indexing** | $O(N)$ | $O(N)$ | $O(1)$ lookup for root partition |
| **Linear Search Inorder**     | $O(N^2)$ | $O(H)$ | Searches inorder linearly |
