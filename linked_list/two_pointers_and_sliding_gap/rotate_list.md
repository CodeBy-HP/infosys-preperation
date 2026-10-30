# Problem 10: Rotate List (LeetCode 61)

## Problem Statement

Given the `head` of a linked list, rotate the list to the right by $k$ places.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 3, 4, 5], k = 2`
- **Output:** `[4, 5, 1, 2, 3]`

### Example 2
- **Input:** `head = [0, 1, 2], k = 4`
- **Output:** `[2, 0, 1]`

---

## Constraints

- The number of nodes in the list is in the range $[0, 500]$.
- $-100 \le \text{Node.val} \le 100$
- $0 \le k \le 2 \times 10^9$

---

## Pattern: Circular Ring Connection & Strategic Cut

When $k$ is huge ($k \le 2 \times 10^9$), rotating $k$ times is equivalent to rotating $k \pmod L$ times, where $L$ is list length.
1. Traverse list to find length $L$ and locate the tail node.
2. If $k \pmod L == 0$, no rotation needed, return `head`.
3. Connect `tail->next = head` to form a circular list.
4. The new tail will be at position $(L - (k \pmod L))$ from the start (1-indexed).
5. Walk to the new tail, save `newHead = newTail->next`, and break the circle by setting `newTail->next = nullptr`.

```
Original (L = 5, k = 2):
1 -> 2 -> 3 -> 4 -> 5 -> NULL
Connect tail to head:
+-------------------+
|                   |
v                   |
1 -> 2 -> 3 -> 4 -> 5
          ^    ^
       newTail newHead (position L - k = 3)

Break link at 3:
4 -> 5 -> 1 -> 2 -> 3 -> NULL
```

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Ring Cut** | $O(L)$ | $O(1)$ | At most $2L$ node traversals |
| **Naive Step Rotation** | $O(k \times L)$ | $O(1)$ | TLE for $k = 10^9$ |
