# Problem 23: Flatten Binary Tree to Linked List (LeetCode 114)

## Problem Statement

Given the `root` of a binary tree, flatten the tree into a "linked list":
- The "linked list" should use the same `TreeNode` class where the `right` child pointer points to the next node in the list and the `left` child pointer is always `null`.
- The "linked list" should be in the same order as a **pre-order traversal** of the binary tree.

---

## Examples

### Example 1
```text
    1               1
   / \               \
  2   5     ===>      2
 / \   \               \
3   4   6               3
                         \
                          4
                           \
                            5
                             \
                              6
```
- **Input:** `root = [1,2,5,3,4,null,6]`
- **Output:** `[1,null,2,null,3,null,4,null,5,null,6]`

---

## Constraints

- The number of nodes in the tree is in the range $[0, 2000]$.
- $-100 \le \text{Node.val} \le 100$

---

## Two Methods

### 1. Reverse Post-Order Traversal (`Right -> Left -> Root`)
If we traverse in reverse preorder (`right`, `left`, `root`), we process nodes from tail to head!
- Maintain pointer `prev = nullptr`.
- Set `curr->right = prev; curr->left = nullptr;`
- Advance `prev = curr`.

### 2. Morris Threading ($O(1)$ Space)
For each node with a left child:
- Find the rightmost node in `curr->left`.
- Connect `rightmost->right = curr->right`.
- Move left subtree to right: `curr->right = curr->left; curr->left = nullptr;`

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Morris Splicing** | $O(N)$ | $O(1)$ | Strictly constant auxiliary space |
| **Reverse Post-Order** | $O(N)$ | $O(H)$ | Elegant recursion |
