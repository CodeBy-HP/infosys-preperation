# Problem 3: Palindrome Linked List (LeetCode 234)

## Problem Statement

Given the `head` of a singly linked list, return `true` if it is a **palindrome** or `false` otherwise.

**Follow up:** Could you do it in $O(n)$ time and $O(1)$ space?

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 2, 1]`
- **Output:** `true`

### Example 2
- **Input:** `head = [1, 2]`
- **Output:** `false`

---

## Constraints

- The number of nodes in the list is in the range $[1, 10^5]$.
- $0 \le \text{Node.val} \le 9$

---

## Architectural Strategy: 3-Phase In-Place Check

To achieve $O(1)$ auxiliary space without mutating the user's input permanently:
1. **Find Middle:** Use fast and slow pointers. `slow` stops at the end of the first half (for odd length, exact middle; for even length, lower middle).
2. **Reverse Second Half:** Reverse the sublist starting from `slow->next`.
3. **Compare & Restore:**
   - Compare values node by node from `head` and reversed second half.
   - Re-reverse the second half back to its original state (production engineering best practice).

```
Step 1: Find Middle
1 -> 2 -> 2 -> 1 -> NULL
     ^
    slow

Step 2: Reverse Second Half
First half:   1 -> 2
Second half:  1 -> 2 (reversed)

Step 3: Compare & Restore
```

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Middle + Reverse in Place** | $O(N)$ | $O(1)$ | Modifies in-place, then restores |
| **Vector Copy + Two Pointers**| $O(N)$ | $O(N)$ | Simple array comparison |
| **Recursive Call Stack**      | $O(N)$ | $O(N)$ | Recursive tail-to-head comparison |
