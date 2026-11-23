# Insert Node Before Head in Doubly Linked List

## Problem Statement

Given the `head` of a doubly linked list and an integer `val`, insert a new node containing `val` **immediately before the head node**.

Return the pointer to the new head of the doubly linked list.

---

## Examples

### Example 1
- **Input:** `head = [2, 3, 4]`, `val = 1`
- **Output:** `[1, 2, 3, 4]`
- **Explanation:** Node 1 becomes the new head; Node 2's `prev` points to 1.

### Example 2
- **Input:** `head = []`, `val = 10`
- **Output:** `[10]`

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^5]$.
- $-10^9 \le \text{Node.val}, val \le 10^9$

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $O(1)$ |
| **Space Complexity** | $O(1)$ |

