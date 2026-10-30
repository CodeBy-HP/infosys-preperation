# Problem 25: Remove Duplicates from Sorted List II (LeetCode 82)

## Problem Statement

Given the `head` of a sorted linked list, **delete all nodes that have duplicate numbers**, leaving only distinct numbers from the original list. Return the linked list **sorted** as well.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 3, 3, 4, 4, 5]`
- **Output:** `[1, 2, 5]`

### Example 2
- **Input:** `head = [1, 1, 1, 2, 3]`
- **Output:** `[2, 3]`

---

## Constraints

- The number of nodes in the list is in the range $[0, 300]$.
- $-100 \le \text{Node.val} \le 100$
- The list is guaranteed to be sorted in ascending order.

---

## Pattern: Sentinel Dummy with Inner Duplicate Drain

1. Create a sentinel `dummy` node pointing to `head`.
2. Maintain `prev = &dummy`.
3. While `curr != nullptr`:
   - If `curr->next != nullptr && curr->val == curr->next->val`:
     - Run inner loop to consume all nodes with this duplicate value:
       ```cpp
       while (curr->next && curr->val == curr->next->val) {
           curr = curr->next;
       }
       // Discard the entire duplicate cluster
       prev->next = curr->next;
       ```
   - Else (value is strictly distinct):
     - `prev = prev->next;`
   - `curr = curr->next;`

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Sentinel Duplicate Drain** | $O(N)$ | $O(1)$ | Single pass, frees duplicates |
| **Hash Frequency Map**       | $O(N)$ | $O(N)$ | Extra map space |
