# Delete Head of Doubly Linked List

## Problem Statement

Given the `head` of a doubly linked list, delete the **first (head) node** of the list and return the pointer to the new head.

If the list is empty or contains only one node, the resulting list is empty (`nullptr`).

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 3, 4]`
- **Output:** `[2, 3, 4]`
- **Explanation:** Node 1 is deleted; Node 2's `prev` is set to `nullptr`.

### Example 2
- **Input:** `head = [10]`
- **Output:** `[]`

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^5]$.
- $-10^9 \le \text{Node.val} \le 10^9$

---

## The DLL Head Deletion Invariant

1. If `head == nullptr` or `head->next == nullptr`: delete `head` if present and return `nullptr`.
2. Cache `prevHead = head`.
3. Advance `head = head->next`.
4. Decouple backwards link: `head->prev = nullptr;`.
5. Free `delete prevHead;`.
6. Return new `head`.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $O(1)$ |
| **Space Complexity** | $O(1)$ |

