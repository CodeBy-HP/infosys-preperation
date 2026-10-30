# Segment Tree (Range Sum Query - Mutable)

## Problem Statement

Design a data structure that efficiently maintains an array of $n$ numbers and supports two operations:
1. **Point Update:** `update(index, val)` updates the element at `nums[index]` to `val`.
2. **Range Query:** `sumRange(left, right)` returns the sum of elements from index `left` to index `right` inclusive ($\sum_{i=left}^{right} \text{nums}[i]$).

Both operations must execute in **$O(\log N)$ time**.

---

## Why Segment Trees?

| Data Structure | Point Update | Range Sum Query | Range Update | Memory |
| :--- | :--- | :--- | :--- | :--- |
| **Normal Array** | $O(1)$ | $O(N)$ | $O(N)$ | $O(N)$ |
| **Prefix Sum Array** | $O(N)$ | $O(1)$ | $O(N)$ | $O(N)$ |
| **Fenwick Tree (BIT)** | $O(\log N)$ | $O(\log N)$ | Harder | $N + 1$ |
| **Segment Tree** | $O(\log N)$ | $O(\log N)$ | $O(\log N)$ (with Lazy) | $4N$ |

A Segment Tree resolves the **Update vs. Query tradeoff** by arranging intervals into a balanced binary tree.

---

## Architecture & Mechanics

A Segment Tree represents an interval $[0, n - 1]$ hierarchically:
- The **Root** represents $[0, n - 1]$.
- Any internal node representing $[start, end]$ splits at $mid = \lfloor (start + end) / 2 \rfloor$:
  - Left child: $[start, mid]$ at index $2 \times \text{node} + 1$.
  - Right child: $[mid + 1, end]$ at index $2 \times \text{node} + 2$.
- The **Leaves** represent single-element intervals $[i, i]$.

### Three Query Overlap Scenarios:
1. **Total Overlap ($L \le start$ and $end \le R$):** The node's entire interval lies inside the query. Return `tree[node]` immediately.
2. **No Overlap ($R < start$ or $L > end$):** The node's interval is disjoint from $[L, R]$. Return $0$ (neutral element for sum).
3. **Partial Overlap:** The query range straddles the midpoint. Recurse on both children and return $\text{left\_sum} + \text{right\_sum}$.

### Lazy Propagation (Range Updates):
When updating a range $[L, R]$ with a delta:
- Instead of updating all leaf nodes individually ($O(N \log N)$), store the pending delta in a `lazy` array at the highest fully covered node.
- Push the lazy tag down to children only when those children are accessed during subsequent queries or updates.

---

## Complexity Analysis

| Operation | Standard Segment Tree | With Lazy Propagation |
| :--- | :--- | :--- |
| **Build Tree** | $O(N)$ | $O(N)$ |
| **Point Update** | $O(\log N)$ | $O(\log N)$ |
| **Range Sum Query** | $O(\log N)$ | $O(\log N)$ |
| **Range Update** | $O(N)$ without lazy | $O(\log N)$ with lazy |
| **Space Complexity** | $4N$ array | $4N$ tree $+ 4N$ lazy |

