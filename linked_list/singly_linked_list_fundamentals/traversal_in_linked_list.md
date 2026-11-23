# Traversal in a Singly Linked List

## Problem Statement

Given the `head` of a singly linked list, traverse the linked list from head to tail, visiting each node exactly once, and return a list/vector containing all node values in their traversal order.

If the linked list is empty (`head == nullptr`), return an empty list.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 3, 4, 5]`
- **Output:** `[1, 2, 3, 4, 5]`

### Example 2
- **Input:** `head = [10]`
- **Output:** `[10]`

### Example 3
- **Input:** `head = []`
- **Output:** `[]`

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^5]$.
- $-10^9 \le \text{Node.val} \le 10^9$

---

## Traversal Invariant

1. **Pointer Preservation:** Never advance the original `head` pointer if it needs to be reused; allocate a local iterator `ListNode* curr = head;`.
2. **Termination Condition:** Advance while `curr != nullptr`. At the terminal node, `curr->next` is `nullptr`, after which `curr = curr->next` becomes `nullptr`, ending the loop safely.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Iterative Traversal** | $O(N)$ | $O(1)$ |
| **Recursive Traversal** | $O(N)$ | $O(N)$ call stack |

