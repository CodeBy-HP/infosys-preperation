# Deletion of the Tail of a Linked List

## Problem Statement

Given the `head` of a singly linked list, delete the **last (tail) node** of the linked list and return the pointer to the head of the modified list.

If the linked list is empty or contains only one node, the result is an empty list (`nullptr`).

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 3, 4, 5]`
- **Output:** `[1, 2, 3, 4]`

### Example 2
- **Input:** `head = [7]`
- **Output:** `[]`

### Example 3
- **Input:** `head = []`
- **Output:** `[]`

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^5]$.
- $-10^9 \le \text{Node.val} \le 10^9$

---

## The Lookahead Rule for Tail Deletion

To delete the last node, you must stop at the **second-to-last node**:
1. If `head == nullptr` or `head->next == nullptr`: delete `head` if present and return `nullptr`.
2. Traverse with lookahead condition: `while (curr->next->next != nullptr) curr = curr->next;`.
3. When the loop terminates, `curr` points to the second-to-last node.
4. Delete `curr->next`, then sever the link by setting `curr->next = nullptr`.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $O(N)$ |
| **Space Complexity** | $O(1)$ |

