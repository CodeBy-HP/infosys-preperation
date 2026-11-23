# Search in a Singly Linked List

## Problem Statement

Given the `head` of a singly linked list and an integer `key`, determine whether `key` is present in the linked list.

Return `true` if `key` exists in the linked list; otherwise, return `false`.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 3, 4]`, `key = 3`
- **Output:** `true`

### Example 2
- **Input:** `head = [1, 2, 3, 4]`, `key = 5`
- **Output:** `false`

### Example 3
- **Input:** `head = []`, `key = 1`
- **Output:** `false`

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^5]$.
- $-10^9 \le \text{Node.val}, key \le 10^9$

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Iterative Search** | $O(N)$ | $O(1)$ |
| **Recursive Search** | $O(N)$ | $O(N)$ stack frames |

