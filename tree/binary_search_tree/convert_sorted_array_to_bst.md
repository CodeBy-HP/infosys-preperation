# Problem 19: Convert Sorted Array to Binary Search Tree (LeetCode 108)

## Problem Statement

Given an integer array `nums` where the elements are sorted in **ascending order**, convert it to a **height-balanced** binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

---

## Examples

### Example 1
```text
      0
     / \
   -3   9
   /   /
 -10  5
```
- **Input:** `nums = [-10, -3, 0, 5, 9]`
- **Output:** `[0, -3, 9, -10, null, 5]`

---

## Constraints

- $1 \le \text{nums.length} \le 10^4$
- $-10^4 \le \text{nums}[i] \le 10^4$
- `nums` is sorted in a **strictly increasing** order.

---

## Divide & Conquer Paradigm

To guarantee minimum height and balanced subtrees:
1. The exact middle element $mid = (left + right) / 2$ must become the local `root`.
2. The subarray `nums[left ... mid - 1]` becomes the left balanced BST subtree.
3. The subarray `nums[mid + 1 ... right]` becomes the right balanced BST subtree.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Divide & Conquer** | $O(N)$ | $O(\log N)$ call stack |
