# Problem 7: Swap Nodes in Pairs (LeetCode 24)

## Problem Statement

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 3, 4]`
- **Output:** `[2, 1, 4, 3]`

### Example 2
- **Input:** `head = []`
- **Output:** `[]`

### Example 3
- **Input:** `head = [1]`
- **Output:** `[1]`

---

## Constraints

- The number of nodes in the list is in the range $[0, 100]$.
- $0 \le \text{Node.val} \le 100$

---

## Pointer Rewiring Pattern

Using a dummy node pointing to `head`:
For each pair `(first, second)`:
1. `prev->next = second`
2. `first->next = second->next`
3. `second->next = first`
4. Advance `prev = first`

```
dummy -> 1 -> 2 -> 3 -> 4
prev    first second

After rewiring:
dummy -> 2 -> 1 -> 3 -> 4
             prev (ready for next pair)
```

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Iterative Pointer Rewiring** | $O(N)$ | $O(1)$ | Strictly $O(1)$ space |
| **Recursive**                 | $O(N)$ | $O(N)$ | $O(N/2)$ stack frames |
