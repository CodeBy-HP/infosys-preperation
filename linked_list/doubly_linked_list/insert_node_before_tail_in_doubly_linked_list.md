# Insert Node Before Tail in Doubly Linked List

## Problem Statement

Given the `head` of a doubly linked list and an integer `val`, insert a new node containing value `val` **immediately before the tail node**.

If the list is empty, return a new single node containing `val`.
If the list has only 1 node, the new node becomes the new head (since it is placed before the only node, which is also the tail).

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 4]`, `val = 3`
- **Output:** `[1, 2, 3, 4]`

### Example 2
- **Input:** `head = [10]`, `val = 5`
- **Output:** `[5, 10]`

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^5]$.
- $-10^9 \le \text{Node.val}, val \le 10^9$

---

## The 4-Pointer Splice Invariant

1. If `!head`: return `new Node(val);`.
2. If `!head->next`:
   - `newHead = new Node(val);`
   - `newHead->next = head; head->prev = newHead;`
   - return `newHead`.
3. Traverse to tail: `tail = head; while (tail->next) tail = tail->next;`.
4. Predecessor: `back = tail->prev;`.
5. Allocate: `newNode = new Node(val, back, tail);`.
6. Rewire: `back->next = newNode; tail->prev = newNode;`.
7. Return `head`.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $O(N)$ without tail pointer, $O(1)$ with tail pointer |
| **Space Complexity** | $O(1)$ |

