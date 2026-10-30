# Problem 15: Odd Even Linked List (LeetCode 328)

## Problem Statement

Given the `head` of a singly linked list, group all the nodes with **odd indices** together followed by the nodes with **even indices**, and return the reordered list.

The **first** node is considered odd, and the **second** node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in $O(1)$ extra space complexity and $O(n)$ time complexity.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 3, 4, 5]`
- **Output:** `[1, 3, 5, 2, 4]`

### Example 2
- **Input:** `head = [2, 1, 3, 5, 6, 4, 7]`
- **Output:** `[2, 3, 6, 7, 1, 5, 4]`

---

## Constraints

- The number of nodes in the linked list is in the range $[0, 10^4]$.
- $-10^6 \le \text{Node.val} \le 10^6$

---

## Pattern: Parallel Pointer Leapfrog

1. Let `odd = head` and `even = head->next`.
2. Save `evenHead = even` so we can stitch it behind odd nodes later.
3. While `even != nullptr && even->next != nullptr`:
   - `odd->next = even->next; odd = odd->next;`
   - `even->next = odd->next; even = even->next;`
4. Connect: `odd->next = evenHead`.

```
Initial:
1  ->  2  ->  3  ->  4  ->  5
odd   even

Step 1:
odd->next = 3; odd = 3;
even->next = 4; even = 4;
1 -> 3,  2 -> 4

Stitch odd->next = evenHead:
1 -> 3 -> 5 -> 2 -> 4
```

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Parallel Leapfrog** | $O(N)$ | $O(1)$ | Strictly $O(1)$ auxiliary space |
