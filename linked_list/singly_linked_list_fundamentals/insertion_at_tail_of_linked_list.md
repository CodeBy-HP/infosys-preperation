# Insertion at the Tail of a Linked List

## Problem Statement

Given the `head` of a singly linked list and an integer `val`, append a new node containing value `val` to the **end (tail)** of the linked list.

Return the pointer to the head of the modified linked list.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 3]`, `val = 4`
- **Output:** `[1, 2, 3, 4]`

### Example 2
- **Input:** `head = []`, `val = 5`
- **Output:** `[5]`

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^5]$.
- $-10^9 \le \text{Node.val}, val \le 10^9$

---

## The Tail Insertion Invariant

1. If `head == nullptr`: Allocate `newNode` and return it directly.
2. If list is non-empty: Traverse to the terminal node where `curr->next == nullptr`.
3. Link `curr->next = new ListNode(val);`.
4. Return original `head`.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $O(N)$ without tail pointer, $O(1)$ with tail pointer |
| **Space Complexity** | $O(1)$ |

