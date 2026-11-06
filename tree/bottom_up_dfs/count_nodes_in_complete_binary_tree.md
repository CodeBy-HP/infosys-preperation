# Count Complete Tree Nodes

## Problem Statement
Given the `root` of a **complete** binary tree, return the number of the nodes in the tree.

**Design an algorithm that runs in less than $O(N)$ time complexity.**

---

## 1. Algorithmic Approach (Divide & Conquer via Complete Tree Property)

### Core Invariant
In a **complete binary tree**, every level except possibly the last is completely filled, and all nodes in the last level are as far left as possible.

At any node `root`:
1. Measure the **leftmost depth** $lh$: traverse continuously along `curr->left`.
2. Measure the **rightmost depth** $rh$: traverse continuously along `curr->right`.

Two cases arise:
- **Case 1: $lh == rh$**
  The subtree is a **perfect binary tree** of height $lh$.
  The number of nodes in a perfect binary tree is strictly:
  $$\text{Nodes} = 2^{lh} - 1 = (1 \ll lh) - 1$$
  This is computed in $O(lh) = O(\log N)$ time without inspecting the interior nodes!
- **Case 2: $lh \ne rh$**
  The last level is not completely full on the right side.
  Recurse on both subtrees:
  $$\text{Nodes} = 1 + \text{countNodes}(\text{root}\to\text{left}) + \text{countNodes}(\text{root}\to\text{right})$$

### Why is this $O(\log^2 N)$?
At each recursive step, at least one of the two subtrees (`left` or `right`) is guaranteed to be a perfect binary tree, which terminates in $O(\log N)$ immediately!
Only one branch continues recursion down the height of the tree ($O(\log N)$ levels).
Total time:
$$T(N) = O(\log N) \times O(\log N) = O(\log^2 N)$$

---

## 2. Complexity Analysis
- **Time Complexity:** $O(\log^2 N)$ — Significantly faster than linear $O(N)$ scan for $N = 10^5$.
- **Space Complexity:** $O(\log N)$ — Auxiliary recursion stack bounded by the tree height.

