# Reverse a Doubly Linked List

## Problem Statement

Given the `head` of a doubly linked list, reverse the linked list in-place by swapping the `next` and `prev` pointers of each node.

Return the pointer to the new head of the reversed doubly linked list.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 3, 4]`
- **Output:** `[4, 3, 2, 1]`
- **Explanation:**
  - Original: `nullptr <- 1 <-> 2 <-> 3 <-> 4 -> nullptr`
  - Reversed: `nullptr <- 4 <-> 3 <-> 2 <-> 1 -> nullptr`

### Example 2
- **Input:** `head = [1]`
- **Output:** `[1]`

### Example 3
- **Input:** `head = []`
- **Output:** `[]`

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^5]$.
- $-10^9 \le \text{Node.val} \le 10^9$

---

## The Pointer Swap Invariant

For each node:
$$\text{std::swap}(curr\text{->prev}, curr\text{->next})$$
Because `curr->prev` now holds the forward pointer to the next node in the original sequence, advance using:
$$curr = curr\text{->prev}$$
When `curr` becomes `nullptr`, the last non-null node encountered is the new head.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **In-Place Pointer Swap** | $O(N)$ | $O(1)$ |
| **Stack-Based Value Reversal** | $O(N)$ | $O(N)$ |

