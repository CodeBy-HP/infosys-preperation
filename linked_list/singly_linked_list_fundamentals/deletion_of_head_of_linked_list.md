# Deletion of the Head of a Linked List

## Problem Statement

Given the `head` of a singly linked list, delete the **first (head) node** of the linked list and return the pointer to the new head.

If the linked list is empty (`head == nullptr`), return `nullptr`.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 3, 4]`
- **Output:** `[2, 3, 4]`
- **Explanation:** Deleting node 1 makes node 2 the new head.

### Example 2
- **Input:** `head = [1]`
- **Output:** `[]`
- **Explanation:** The only node is deleted, leaving an empty list.

### Example 3
- **Input:** `head = []`
- **Output:** `[]`

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^5]$.
- $-10^9 \le \text{Node.val} \le 10^9$

---

## Invariant & Memory Hygiene

In C++, deleting dynamically allocated nodes requires deallocating memory to prevent memory leaks:
1. Check if `head == nullptr`. If so, return `nullptr`.
2. Cache the current head in a temporary pointer `temp = head`.
3. Advance `head = head->next`.
4. Free `delete temp`.
5. Return the new `head`.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $O(1)$ |
| **Space Complexity** | $O(1)$ |

