# Removing Given Node in a Doubly Linked List

## Problem Statement

Given a reference/pointer to a specific `node` in a **Doubly Linked List**, remove that node in **$O(1)$ time without requiring access to the head pointer**.

It is guaranteed that the node to be removed is **never the head node** of the list (i.e., `node->prev != nullptr`).

---

## Examples

### Example 1
- **Input:** `1 <-> 2 <-> 3 <-> 4`, remove `node` pointing to `3`
- **Output:** `1 <-> 2 <-> 4`
- **Explanation:** Node 3's predecessor 2 is wired directly to successor 4.

### Example 2
- **Input:** `1 <-> 2`, remove `node` pointing to `2`
- **Output:** `1`
- **Explanation:** Node 2 is the tail; Node 1's `next` becomes `nullptr`.

---

## Constraints

- The number of nodes in the list is in the range $[2, 10^5]$.
- `node` is guaranteed to exist and `node->prev != nullptr`.
- $-10^9 \le \text{Node.val} \le 10^9$

---

## O(1) Disconnection Invariant

Because `node->prev` is guaranteed non-null:
1. `back = node->prev;`.
2. `front = node->next;`.
3. Rewire forward: `back->next = front;`.
4. Rewire backward (if front exists):
   ```cpp
   if (front != nullptr) {
       front->prev = back;
   }
   ```
5. Decouple target pointers: `node->next = nullptr; node->prev = nullptr; delete node;`.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $O(1)$ |
| **Space Complexity** | $O(1)$ |

