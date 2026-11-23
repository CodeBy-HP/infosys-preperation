# Insertion in a Doubly Linked List (Master Operations)

## Problem Statement

Implement all fundamental **insertion operations** on a Doubly Linked List:
1. **`insertBeforeHead(head, val)`:** Inserts before current head, returning new head.
2. **`insertBeforeTail(head, val)`:** Inserts immediately before the tail node.
3. **`insertBeforeKth(head, val, k)`:** Inserts before the $k$-th node ($1$-based index).
4. **`insertBeforeNode(node, val)`:** Inserts before a given non-head node in $O(1)$ time.

---

## Complexity Summary

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Insert Before Head** | $O(1)$ | $O(1)$ |
| **Insert Before Tail** | $O(N)$ / $O(1)$ with tail | $O(1)$ |
| **Insert Before K-th** | $O(\min(k, N))$ | $O(1)$ |
| **Insert Before Given Node** | $O(1)$ | $O(1)$ |

