# Insert Before Given Node in Doubly Linked List

## Problem Statement

Given a pointer to a specific `node` in a **Doubly Linked List** and an integer `val`, insert a new node containing value `val` **immediately before the given node**.

It is guaranteed that `node` is **never the head node** (i.e., `node->prev != nullptr`).
The function should execute in **$O(1)$ time** without requiring the head pointer.

---

## Examples

### Example 1
- **Input:** `1 <-> 2 <-> 4`, `node` points to 4, `val = 3`
- **Output:** `1 <-> 2 <-> 3 <-> 4`
- **Explanation:** Node 3 is spliced between 2 and 4.

---

## Constraints

- The number of nodes in the list is in the range $[2, 10^5]$.
- `node` is guaranteed to exist and `node->prev != nullptr`.
- $-10^9 \le \text{Node.val}, val \le 10^9$

---

## The O(1) Splicing Invariant

```cpp
Node* back = node->prev;
Node* newNode = new Node(val, back, node);
back->next = newNode;
node->prev = newNode;
```

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $O(1)$ |
| **Space Complexity** | $O(1)$ |

