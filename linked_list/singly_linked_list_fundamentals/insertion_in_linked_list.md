# Insertion in a Singly Linked List (Master Operations)

## Problem Statement

Implement the core **insertion operations** on a Singly Linked List:
1. **`insertHead(head, val)`:** Inserts at the beginning of the list.
2. **`insertTail(head, val)`:** Appends to the end of the list.
3. **`insertKth(head, val, k)`:** Inserts at the $k$-th position ($1$-based index).
4. **`insertBeforeValue(head, val, x)`:** Inserts before the first node containing value `x`.

---

## Examples

### Example 1 (Insert Head)
- `head = [20, 30]`, `insertHead(10) -> [10, 20, 30]`

### Example 2 (Insert Tail)
- `head = [10, 20]`, `insertTail(30) -> [10, 20, 30]`

### Example 3 (Insert K-th)
- `head = [10, 30]`, `insertKth(20, k = 2) -> [10, 20, 30]`

### Example 4 (Insert Before Value)
- `head = [10, 30]`, `insertBeforeValue(20, x = 30) -> [10, 20, 30]`

---

## Complexity Summary

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Insert Head** | $O(1)$ | $O(1)$ |
| **Insert Tail** | $O(N)$ | $O(1)$ |
| **Insert K-th** | $O(\min(k, N))$ | $O(1)$ |
| **Insert Before Value** | $O(N)$ | $O(1)$ |

