# Insertion at the Head of a Linked List

## Problem Statement

Given the `head` of a singly linked list and an integer `val`, insert a new node containing value `val` at the **very beginning (head)** of the linked list.

Return the pointer to the new head of the linked list.

---

## Examples

### Example 1
- **Input:** `head = [2, 3, 4]`, `val = 1`
- **Output:** `[1, 2, 3, 4]`

### Example 2
- **Input:** `head = []`, `val = 10`
- **Output:** `[10]`

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^5]$.
- $-10^9 \le \text{Node.val}, val \le 10^9$

---

## The O(1) Head Insertion Invariant

1. Allocate `newNode = new ListNode(val);`.
2. Point `newNode->next = head;`.
3. Return `newNode` as the new head.
This executes in strictly **$O(1)$** time and auxiliary space.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $O(1)$ |
| **Space Complexity** | $O(1)$ |

