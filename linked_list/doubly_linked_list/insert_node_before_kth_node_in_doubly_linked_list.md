# Insert Node Before K-th Node in Doubly Linked List

## Problem Statement

Given the `head` of a doubly linked list, an integer `val`, and an integer `k` ($1$-based index), insert a new node containing value `val` **immediately before the $k$-th node**.

- If $k = 1$, the new node becomes the new head.
- If $k > N$, the list remains unchanged.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 4, 5]`, `val = 3`, `k = 3`
- **Output:** `[1, 2, 3, 4, 5]`
- **Explanation:** Node 3 is inserted before the 3rd node (which was 4).

### Example 2
- **Input:** `head = [2, 3]`, `val = 1`, `k = 1`
- **Output:** `[1, 2, 3]`

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^5]$.
- $1 \le k \le 10^5$
- $-10^9 \le \text{Node.val}, val \le 10^9$

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $O(\min(k, N))$ |
| **Space Complexity** | $O(1)$ |

