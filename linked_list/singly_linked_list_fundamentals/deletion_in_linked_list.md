# Deletion in a Singly Linked List (Master Operations)

## Problem Statement

Implement the core **deletion operations** on a Singly Linked List:
1. **`deleteHead(head)`:** Removes the first node.
2. **`deleteTail(head)`:** Removes the final node.
3. **`deleteKth(head, k)`:** Removes the $k$-th node ($1$-based index).
4. **`deleteValue(head, x)`:** Removes the first node containing value `x`.

---

## Examples

### Example 1 (Delete Head)
- **Input:** `[10, 20, 30]`, `deleteHead()`
- **Output:** `[20, 30]`

### Example 2 (Delete Tail)
- **Input:** `[10, 20, 30]`, `deleteTail()`
- **Output:** `[10, 20]`

### Example 3 (Delete K-th)
- **Input:** `[10, 20, 30]`, `deleteKth(k = 2)`
- **Output:** `[10, 30]`

### Example 4 (Delete Value)
- **Input:** `[10, 20, 30]`, `deleteValue(x = 20)`
- **Output:** `[10, 30]`

---

## The Four Deletion Invariants

1. **Delete Head:** $O(1)$ operation. `temp = head; head = head->next; delete temp;`.
2. **Delete Tail:** $O(N)$ operation. Traverse to $(N-1)$-th node (`curr->next->next == nullptr`), free `curr->next`, set `curr->next = nullptr`.
3. **Delete K-th:** $O(\min(k, N))$ operation. Advance $k-1$ steps from dummy sentinel.
4. **Delete Value:** $O(N)$ operation. Traverse until `curr->next->val == x`, splice out target, free memory.

---

## Complexity Summary

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Delete Head** | $O(1)$ | $O(1)$ |
| **Delete Tail** | $O(N)$ | $O(1)$ |
| **Delete K-th** | $O(N)$ | $O(1)$ |
| **Delete Value** | $O(N)$ | $O(1)$ |

