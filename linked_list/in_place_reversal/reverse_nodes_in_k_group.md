# Problem 6: Reverse Nodes in k-Group (LeetCode 25)

## Problem Statement

Given the `head` of a linked list, reverse the nodes of the list **$k$ at a time**, and return the modified list.

$k$ is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of $k$ then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 3, 4, 5], k = 2`
- **Output:** `[2, 1, 4, 3, 5]`

### Example 2
- **Input:** `head = [1, 2, 3, 4, 5], k = 3`
- **Output:** `[3, 2, 1, 4, 5]`

---

## Constraints

- The number of nodes in the list is $n$.
- $1 \le k \le n \le 5000$
- $0 \le \text{Node.val} \le 1000$

---

## Algorithmic Anatomy: Block Lookahead & In-Place Splicing

For each group of $k$ nodes:
1. **Lookahead Check:** Walk a pointer $k$ steps forward from `groupPrev`. If fewer than $k$ nodes remain before `nullptr`, stop immediately (leave remaining nodes untouched).
2. **Reverse the $k$ Nodes:** Using standard 3-pointer reversal between `groupPrev->next` and `groupNext`.
3. **Reconnect Boundaries:**
   - The former start of the group becomes the new tail.
   - Point `groupPrev->next` to the new group head.
   - Update `groupPrev` to the tail of the reversed group.

```
Initial state:
dummy -> [1 -> 2 -> 3] -> [4 -> 5]
groupPrev                   groupNext

After reversing 1 -> 2 -> 3:
dummy -> [3 -> 2 -> 1] -> [4 -> 5]
                    ^
                 new groupPrev
```

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Iterative Lookahead** | $O(N)$ | $O(1)$ | Strictly constant auxiliary space |
| **Recursive**          | $O(N)$ | $O(N / k)$ | Recursion call stack |
