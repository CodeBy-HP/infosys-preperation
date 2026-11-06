# Recover Binary Search Tree (Two Nodes Swapped)

## Problem Statement
You are given the `root` of a binary search tree (BST), where the values of **exactly two nodes** were swapped by mistake. Recover the tree without changing its structure.

**Follow up:** Solve in $O(1)$ auxiliary space.

```
Input Tree (Mistake):
        1
       /
      3
       \
        2

Swapped nodes: 1 and 3
Recovered Tree:
        3
       /
      1
       \
        2
```

---

## 1. Algorithmic Approach (Inorder Anomaly Detection)

### The Inversion Signature
In a valid BST, the inorder traversal is strictly ascending:
$$A = [1, 2, 3, 4, 5, 6]$$

Suppose two nodes are swapped:
- **Case 1: Non-adjacent nodes swapped (e.g., 2 and 5 swapped):**
  $$\text{Inorder: } [1, \mathbf{5}, \mathbf{3}, 4, \mathbf{2}, 6]$$
  Notice **two distinct violations** where `prev->val > curr->val`:
  1. First violation ($5 > 3$): `first = prev (5)`, `middle = curr (3)`.
  2. Second violation ($4 > 2$): `last = curr (2)`.
  Swapping `first` and `last` restores the BST!

- **Case 2: Adjacent nodes swapped (e.g., 2 and 3 swapped):**
  $$\text{Inorder: } [1, \mathbf{3}, \mathbf{2}, 4, 5, 6]$$
  Notice **only one violation** ($3 > 2$):
  1. Violation: `first = prev (3)`, `middle = curr (2)`.
  No second violation occurs.
  Swapping `first` and `middle` restores the BST!

### Unified Swap Formula
```cpp
if (first && last) {
    swap(first->val, last->val);
} else if (first && middle) {
    swap(first->val, middle->val);
}
```

---

## 2. Complexity Analysis
- **Time Complexity:** $O(N)$ — Single in-order traversal visiting all nodes.
- **Space Complexity:**
  - Standard Inorder: $O(H)$ call stack space.
  - Morris Inorder: $O(1)$ strictly constant auxiliary space.

