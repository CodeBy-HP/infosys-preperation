# Deletion in a Doubly Linked List (Master Operations)

## Problem Statement

Implement all fundamental **deletion operations** on a Doubly Linked List:
1. **`deleteHead(head)`:** Deletes the first node and rewires `prev = nullptr`.
2. **`deleteTail(head)`:** Deletes the last node and rewires `next = nullptr`.
3. **`deleteKth(head, k)`:** Deletes the $k$-th node ($1$-based index).
4. **`deleteGivenNode(node)`:** Deletes a specific non-head node in $O(1)$ time.

---

## Complexity Summary

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Delete Head** | $O(1)$ | $O(1)$ |
| **Delete Tail** | $O(N)$ / $O(1)$ with tail | $O(1)$ |
| **Delete K-th** | $O(\min(k, N))$ | $O(1)$ |
| **Delete Given Node** | $O(1)$ | $O(1)$ |

