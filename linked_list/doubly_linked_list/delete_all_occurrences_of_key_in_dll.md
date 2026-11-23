# Delete All Occurrences of a Key in a Doubly Linked List

## Problem Statement

Given the `head` of a doubly linked list and an integer `key`, delete **all nodes** in the doubly linked list that have value equal to `key`.

Return the pointer to the head of the modified doubly linked list.

---

## Examples

### Example 1
- **Input:** `head = [2, 2, 10, 8, 4, 2, 5, 2]`, `key = 2`
- **Output:** `[10, 8, 4, 5]`
- **Explanation:** All nodes with value 2 (including head and tail occurrences) are deleted.

### Example 2
- **Input:** `head = [9, 9, 9]`, `key = 9`
- **Output:** `[]`
- **Explanation:** All elements match key, returning empty list.

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^5]$.
- $-10^9 \le \text{Node.val}, key \le 10^9$

---

## Bi-Directional Splicing Invariant

When traversing with pointer `curr`:
1. If `curr->val == key`:
   - If `curr == head`: advance `head = head->next; if (head) head->prev = nullptr;`.
   - If `curr` is an internal or tail node:
     - `prevNode = curr->prev; nextNode = curr->next;`
     - `if (prevNode) prevNode->next = nextNode;`
     - `if (nextNode) nextNode->prev = prevNode;`
   - Cache node, advance `curr = curr->next;`, and `delete` target node.
2. Else: advance `curr = curr->next;`.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $O(N)$ |
| **Space Complexity** | $O(1)$ |

