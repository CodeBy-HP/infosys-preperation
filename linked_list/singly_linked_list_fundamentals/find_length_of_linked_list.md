# Find the Length of a Linked List

## Problem Statement

Given the `head` of a singly linked list, compute and return the **total number of nodes** (length) in the list.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 3, 4, 5]`
- **Output:** `5`

### Example 2
- **Input:** `head = [2]`
- **Output:** `1`

### Example 3
- **Input:** `head = []`
- **Output:** `0`

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^5]$.
- $-10^9 \le \text{Node.val} \le 10^9$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Iterative Counter** | $O(N)$ | $O(1)$ |
| **Recursive Counting** | $O(N)$ | $O(N)$ stack |

