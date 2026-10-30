# Problem 21: Plus One Linked List (LeetCode 369)

## Problem Statement

Given a non-negative integer represented as a linked list of digits, `plus one` to the integer.

The digits are stored such that the most significant digit is at the head of the list.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 3]`
- **Output:** `[1, 2, 4]`

### Example 2
- **Input:** `head = [9, 9, 9]`
- **Output:** `[1, 0, 0, 0]`

---

## Constraints

- The number of nodes in the linked list is in the range $[1, 100]$.
- $0 \le \text{Node.val} \le 9$
- The number does not contain leading zeros except $0$ itself.

---

## Optimal Single-Pass Two-Pointer Technique ($O(1)$ Space)

Notice: Adding 1 only affects a suffix of `9`s.
1. Place a sentinel `dummy` node with value 0 before `head`.
2. Find the **rightmost non-9 node**:
   - Maintain pointer `notNine = dummy`.
   - Traverse the list: whenever `curr->val != 9`, update `notNine = curr`.
3. Increment `notNine->val += 1`.
4. Set every node after `notNine` to `0`.
5. If `dummy->val != 0` (e.g. `999 -> 1000`), return `dummy`; otherwise return `dummy->next`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Rightmost Non-9 Pointer** | $O(N)$ | $O(1)$ | Single pass, $O(1)$ space |
| **Reverse, Add 1, Reverse** | $O(N)$ | $O(1)$ | Modifies list 3 times |
