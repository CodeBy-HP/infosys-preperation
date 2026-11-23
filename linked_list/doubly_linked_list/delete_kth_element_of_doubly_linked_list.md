# Delete K-th Element of Doubly Linked List

## Problem Statement

Given the `head` of a doubly linked list and an integer `k` ($1$-based index), delete the **$k$-th node** of the doubly linked list and return the head of the modified list.

If $k$ is greater than the length of the list, the list remains unchanged.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 3, 4, 5]`, `k = 3`
- **Output:** `[1, 2, 4, 5]`
- **Explanation:** Node 3 is removed. Node 2's `next` points to 4, and Node 4's `prev` points to 2.

### Example 2
- **Input:** `head = [10, 20]`, `k = 1`
- **Output:** `[20]`

### Example 3
- **Input:** `head = [10, 20]`, `k = 2`
- **Output:** `[10]`

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^5]$.
- $1 \le k \le 10^5$
- $-10^9 \le \text{Node.val} \le 10^9$

---

## Bi-Directional Splicing Invariant

When deleting node `kNode`:
1. If $k = 1$: Fallback to `deleteHead`.
2. Traverse $k-1$ steps to reach `kNode`.
3. Predecessor: `back = kNode->prev;`.
4. Successor: `front = kNode->next;`.
5. If `front == nullptr`: `kNode` is the tail $\implies$ `back->next = nullptr; delete kNode;`.
6. Else (internal node):
   ```cpp
   back->next = front;
   front->prev = back;
   delete kNode;
   ```
7. Return `head`.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $O(\min(k, N))$ |
| **Space Complexity** | $O(1)$ |

