# Data Center Cooling Optimization

## Problem Statement

You are managing a data center cooling system operating over $n$ discrete time intervals, indexed from $0$ to $n - 1$. You are given an initial array $H$ of size $n$, where $H[i]$ represents the initial heat load at interval $i$.

You are also given an integer $d$, which represents the **minimum required index separation** between any two selected cooling units. Specifically, if you select intervals at indices $i$ and $j$, they must satisfy:
$$|i - j| \ge d$$

You must process $q$ operations, which can be of two types:

### 1. Update Operation
**Format:** `1 position value`
- **Action:** Update the heat load at `position` to `value` (i.e., $H[\text{position}] = \text{value}$).

### 2. Query Operation
**Format:** `2 l r k critical`
- **Action:** Consider the subarray $H[l \dots r]$. Select at most $k$ intervals from this range using the greedy rule:
  1. **Greedy Choice:** At each step, choose an available interval with the **highest heat load**. In case of ties, choose the one with the **smallest index**.
  2. **Separation Rule:** Once index $i$ is selected, all intervals in the range $[i - d + 1, i + d - 1]$ become unavailable for further selection in this query.
  3. **Termination:** Repeat until $k$ intervals are selected or no valid intervals remain.
- **Scoring:** For each selected interval with heat load $x$:
  - If $x \ge \text{critical}$, turbo mode activates: contributes $4x$ heat reduction.
  - If $x < \text{critical}$, normal operation: contributes $x$ heat reduction.
- **Output:** Calculate the total heat reduction for this query.

**Final Result:** Return the **sum of total heat reductions** across all type-2 queries.

---

## Example Walkthrough

### Parameters
- $n = 3$, $d = 2$, $H = [5, 5, 5]$, $q = 1$
- **Query:** `2 0 2 3 0` ($l = 0, r = 2, k = 3, \text{critical} = 0$)

### Step-by-Step Selection:
1. **First Pick:** All indices $0, 1, 2$ have heat load $5$. Tie-breaker chooses smallest index: **Index 0**.
   - Contribution: $5 \ge 0 \implies 5 \times 4 = 20$.
   - Separation $d = 2$: Invalidates index range $[0 - 1, 0 + 1] \implies$ Index $1$ is invalidated.
2. **Second Pick:** Available indices in $[0, 2]$: only **Index 2**.
   - Contribution: $5 \ge 0 \implies 5 \times 4 = 20$.
   - Invalidates index $1$ (already invalid) and index $2$.
3. **Third Pick:** No valid intervals remain. Stops even though $k = 3$.

- **Query Total:** $20 + 20 = 40$.

---

## Constraints

- $1 \le n \le 10^5$
- $1 \le d \le n$
- $1 \le q \le 10^5$
- $0 \le H[i], \text{value}, \text{critical} \le 10^9$
- $0 \le l \le r < n$
- $1 \le k \le n$

---

## Greedy Approach & Data Structures

At each query:
1. Build a **Max-Heap (Priority Queue)** containing pairs `(-heat[i], index)` for $i \in [l, r]$.
   - Priority 1: Largest heat load.
   - Priority 2: Smallest index.
2. Maintain a boolean array or bitset `invalid` to track cooldown intervals.
3. While the heap is not empty and fewer than $k$ intervals have been selected:
   - Pop `(val, idx)`.
   - If `invalid[idx]` is true, continue.
   - Add $4 \times val$ (if $val \ge \text{critical}$) or $val$ to query total.
   - Invalidate $[idx - d + 1, idx + d - 1]$.

---

## Complexity Analysis

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Type 1 (Update)** | $O(1)$ | $O(1)$ |
| **Type 2 (Query via Heap)** | $O((r - l + 1) + k \cdot d \log(r - l + 1))$ | $O(r - l + 1)$ |
| **Overall** | $O(q \cdot (r - l + 1))$ worst-case | $O(n)$ |

