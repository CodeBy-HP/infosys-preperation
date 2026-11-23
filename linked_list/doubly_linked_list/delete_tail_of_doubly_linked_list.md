# Delete Tail of Doubly Linked List

## Problem Statement

Given the `head` of a doubly linked list, delete the **last (tail) node** of the list and return the pointer to the head of the modified list.

If the list is empty or contains only one node, the resulting list is empty (`nullptr`).

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 3, 4]`
- **Output:** `[1, 2, 3]`
- **Explanation:** Node 4 is deleted; Node 3's `next` becomes `nullptr`.

### Example 2
- **Input:** `head = [10]`
- **Output:** `[]`

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^5]$.
- $-10^9 \le \text{Node.val} \le 10^9$

---

## The DLL Tail Deletion Invariant

Unlike singly linked lists where we must stop at the second-to-last node, doubly linked lists allow directly traversing to the tail node `tail`:
1. If `!head || !head->next`: delete `head` if present and return `nullptr`.
2. Traverse until `tail->next == nullptr`.
3. Get predecessor: `newTail = tail->prev;`.
4. Decouple links: `newTail->next = nullptr;`.
5. Free `delete tail;`.
6. Return `head`.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $O(N)$ without tail pointer, $O(1)$ with tail pointer |
| **Space Complexity** | $O(1)$ |

