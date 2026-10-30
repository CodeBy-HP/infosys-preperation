# Problem 8: Remove Nth Node From End of List (LeetCode 19)

## Problem Statement

Given the `head` of a linked list, remove the $n^{\text{th}}$ node from the end of the list and return its head.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 3, 4, 5], n = 2`
- **Output:** `[1, 2, 3, 5]`
- **Explanation:** The 2nd node from the end is node 4. After removing it, the list becomes `1 -> 2 -> 3 -> 5`.

### Example 2
- **Input:** `head = [1], n = 1`
- **Output:** `[]`

### Example 3
- **Input:** `head = [1, 2], n = 1`
- **Output:** `[1]`

---

## Constraints

- The number of nodes in the list is $sz$.
- $1 \le sz \le 30$
- $0 \le \text{Node.val} \le 100$
- $1 \le n \le sz$

---

## Pattern & Invariant: Fixed Sliding Gap of $(N + 1)$

To delete a node in a singly linked list, we must stop at the node **immediately preceding** the target node.
Using a sentinel `dummy` node before `head`:
1. Initialize `fast = dummy` and `slow = dummy`.
2. Advance `fast` forward by $n + 1$ steps. Now the gap between `fast` and `slow` is exactly $n + 1$ nodes.
3. Advance both `fast` and `slow` one step at a time until `fast == nullptr`.
4. When `fast` reaches the end, `slow` is guaranteed to point to the node **preceding** the $n^{\text{th}}$ node from the end!
5. Delete target node: `slow->next = slow->next->next`.

```
dummy -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL (n = 2)
  ^                ^
 slow             fast  (gap = 3)

Slide until fast reaches NULL:
dummy -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL
                   ^                ^
                 slow              fast

Delete slow->next (node 4):
slow->next = slow->next->next (links 3 directly to 5)
```

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Fixed Gap Sliding Pointer** | $O(L)$ | $O(1)$ | Single pass, elegant edge case handling |
| **Two-Pass (Length Count)**   | $O(L)$ | $O(1)$ | Counts length $L$, traverses $L - n$ |
