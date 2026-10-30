# Problem 19: Add Two Numbers (LeetCode 2)

## Problem Statement

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

---

## Examples

### Example 1
- **Input:** `l1 = [2, 4, 3], l2 = [5, 6, 4]` (342 + 465)
- **Output:** `[7, 0, 8]` (807)

### Example 2
- **Input:** `l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9]`
- **Output:** `[8, 9, 9, 9, 0, 0, 0, 1]`

---

## Constraints

- The number of nodes in each linked list is in the range $[1, 100]$.
- $0 \le \text{Node.val} \le 9$
- It is guaranteed that the list represents a number that does not have leading zeros.

---

## Invariant: Carry Propagation Loop

Using a dummy head:
While `l1 != nullptr || l2 != nullptr || carry != 0`:
1. Sum components: `sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0)`
2. `carry = sum / 10`
3. Append `new ListNode(sum % 10)` to tail.
4. Advance pointers.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Carry Propagation** | $O(\max(N, M))$ | $O(\max(N, M))$ | Creates exact digit count for result |
