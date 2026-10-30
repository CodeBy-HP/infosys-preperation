# Problem 18: Find Mode in Binary Search Tree (LeetCode 501)

## Problem Statement

Given the `root` of a binary search tree (BST) with duplicates, return all the **mode(s)** (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:
- The left subtree of a node contains only nodes with keys **less than or equal to** the node's key.
- The right subtree of a node contains only nodes with keys **greater than or equal to** the node's key.
- Both the left and right subtrees must also be binary search trees.

**Follow up:** Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

---

## Examples

### Example 1
```text
   1
    \
     2
    /
   2
```
- **Input:** `root = [1,null,2,2]`
- **Output:** `[2]`

### Example 2
- **Input:** `root = [0]`
- **Output:** `[0]`

---

## Constraints

- The number of nodes in the tree is in the range $[1, 10^4]$.
- $-10^5 \le \text{Node.val} \le 10^5$

---

## Two-Pass In-Order Tracking ($O(1)$ Auxiliary Space)

Because in-order traversal of a BST processes equal keys in contiguous clusters:
1. Maintain `currVal`, `currCount`, and `maxCount`.
2. As you visit each node in ascending order:
   - If `node->val == currVal`: `currCount++`.
   - Else: reset `currVal = node->val; currCount = 1;`
3. Compare against `maxCount`:
   - If `currCount > maxCount`: update `maxCount = currCount; modes = {currVal};`
   - Else if `currCount == maxCount`: `modes.push_back(currVal);`

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **In-Order Streaming** | $O(N)$ | $O(H)$ | Respects follow-up: zero hash maps |
| **Hash Frequency Map** | $O(N)$ | $O(N)$ | Unordered map of frequencies |
