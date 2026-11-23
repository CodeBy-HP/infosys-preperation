# Find Pairs with Given Sum in a Sorted Doubly Linked List

## Problem Statement

Given the `head` of a **sorted** doubly linked list of distinct positive integers and a target integer `sum`, find all pairs of nodes in the list whose values add up to `sum`.

Return a list of pairs `(x, y)` such that $x + y == \text{sum}$ and $x < y$, sorted in ascending order of $x$.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 4, 5, 6, 8, 9]`, `sum = 7`
- **Output:** `[(1, 6), (2, 5)]`
- **Explanation:** $1 + 6 = 7$ and $2 + 5 = 7$.

### Example 2
- **Input:** `head = [1, 5, 6]`, `sum = 6`
- **Output:** `[(1, 5)]`

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^5]$.
- $1 \le \text{Node.val}, sum \le 10^9$
- All node values are distinct and sorted in ascending order.

---

## Two-Pointer Bidirectional Shrinkage Invariant

Because the DLL has bidirectional pointers and the values are strictly sorted:
1. Initialize `left = head`.
2. Find the tail node: `right = head; while (right->next) right = right->next;`.
3. While `left != right && right->next != left` (pointers have not crossed or met):
   - Current sum: $S = left\text{->val} + right\text{->val}$.
   - If $S == sum$: record pair `(left->val, right->val)`, advance `left = left->next`, `right = right->prev`.
   - If $S < sum$: we need a larger sum $\implies left = left\text{->next}$.
   - If $S > sum$: we need a smaller sum $\implies right = right\text{->prev}$.
This achieves optimal **$O(N)$ time and $O(1)$ auxiliary space**.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Two-Pointer Bidirectional Scan** | $O(N)$ | $O(1)$ |
| **Hash Set Lookup** | $O(N)$ | $O(N)$ |
| **Nested Loops Brute Force** | $O(N^2)$ | $O(1)$ |

