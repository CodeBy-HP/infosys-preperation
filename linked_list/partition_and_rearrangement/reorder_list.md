# Problem 16: Reorder List (LeetCode 143)

## Problem Statement

You are given the head of a singly linked-list:
$L_0 \to L_1 \to \dots \to L_{n - 1} \to L_n$

Reorder the list to be on the following form:
$L_0 \to L_n \to L_1 \to L_{n - 1} \to L_2 \to L_{n - 2} \to \dots$

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 3, 4]`
- **Output:** `[1, 4, 2, 3]`

### Example 2
- **Input:** `head = [1, 2, 3, 4, 5]`
- **Output:** `[1, 5, 2, 4, 3]`

---

## Constraints

- The number of nodes in the list is in the range $[1, 5 \times 10^4]$.
- $1 \le \text{Node.val} \le 1000$

---

## Master Assessment Pipeline: 3 Combined Patterns

This classic OA interview problem combines three fundamental linked list patterns:
1. **Find Middle:** Use fast and slow pointers. Sever the list into two halves:
   - First half: $L_0 \dots L_{\lfloor n/2 \rfloor}$
   - Second half: $L_{\lfloor n/2 \rfloor + 1} \dots L_n$
2. **Reverse Second Half:** Invert second half in-place: $L_n \to L_{n-1} \dots$
3. **Interleave (Zigzag Merge):**
   - Save next pointers `tmp1 = first->next; tmp2 = second->next;`
   - Point `first->next = second; second->next = tmp1;`
   - Advance `first = tmp1; second = tmp2;`

```
Initial: 1 -> 2 -> 3 -> 4 -> 5

Phase 1 (Split):
L1: 1 -> 2 -> 3 -> NULL
L2: 4 -> 5 -> NULL

Phase 2 (Reverse L2):
L2: 5 -> 4 -> NULL

Phase 3 (Interleave):
1 -> 5 -> 2 -> 4 -> 3 -> NULL
```

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Middle + Reverse + Interleave** | $O(N)$ | $O(1)$ | Strictly constant auxiliary space |
| **Array of Node Pointers**       | $O(N)$ | $O(N)$ | Simple two-pointer array indexing |
