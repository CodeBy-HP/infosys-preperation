# Problem 20: Add Two Numbers II (LeetCode 445)

## Problem Statement

You are given two **non-empty** linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Follow up:** Could you solve it without reversing the input lists?

---

## Examples

### Example 1
- **Input:** `l1 = [7, 2, 4, 3], l2 = [5, 6, 4]` (7243 + 564)
- **Output:** `[7, 8, 0, 7]`

---

## Constraints

- The number of nodes in each linked list is in the range $[1, 100]$.
- $0 \le \text{Node.val} \le 9$

---

## Strategy: Stacks for LIFO Access Without Reversal

Since the most significant digit comes first, addition requires starting from the least significant digit (tails).
1. Push all values of `l1` into `stack1`.
2. Push all values of `l2` into `stack2`.
3. Pop from both stacks, add digits with `carry`.
4. Insert newly created digit nodes at the **front** of the result list (`newNode->next = head; head = newNode`).

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Two Stacks** | $O(N + M)$ | $O(N + M)$ | Respects follow-up: zero mutation to inputs |
