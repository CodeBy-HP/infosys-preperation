# Length of Loop in a Linked List

## Problem Statement

Given the `head` of a singly linked list, determine whether a loop exists, and if so, return the **number of nodes in the loop** (the length of the cycle).

If there is no loop present, return `0`.

---

## Examples

### Example 1
- **Input:** `head = [25, 14, 19, 33, 10, 21, 39, 90, 58, 45]`, loop from 45 back to 19 (which is at index 2).
- **Output:** `8`
- **Explanation:** The nodes inside the cycle are `[19, 33, 10, 21, 39, 90, 58, 45]`, giving a loop length of 8.

### Example 2
- **Input:** `head = [1, 2, 3, 4, 5]`, no loop.
- **Output:** `0`

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^5]$.
- $-10^9 \le \text{Node.val} \le 10^9$

---

## Two-Phase Fast & Slow Algorithm

1. **Phase 1: Collision Detection**
   - Advance `slow = slow->next` and `fast = fast->next->next`.
   - If `fast == nullptr || fast->next == nullptr`, no loop exists $\implies$ return `0`.
   - If `slow == fast`, collision occurred inside the loop.
2. **Phase 2: Cycle Counting**
   - Freeze one pointer at the meeting point: `curr = slow->next; int count = 1;`.
   - Advance `curr` until it circles back to `slow`:
     ```cpp
     while (curr != slow) {
         count++;
         curr = curr->next;
     }
     ```
   - Return `count`.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Floyd's Fast & Slow Counting** | $O(N)$ | $O(1)$ |
| **Hash Map Distance Recording** | $O(N)$ | $O(N)$ |

