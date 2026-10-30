# Problem 1: Non-overlapping Intervals (LeetCode 435)

## Problem Statement

Given an array of intervals `intervals` where `intervals[i] = [start_i, end_i]`, return the **minimum number of intervals you need to remove to make the rest of the intervals non-overlapping**.

Note that intervals which touch at a single point (e.g., `[1, 2]` and `[2, 3]`) are non-overlapping.

---

## Examples

### Example 1
- **Input:** `intervals = [[1, 2], [2, 3], [3, 4], [1, 3]]`
- **Output:** `1`
- **Explanation:** `[1, 3]` can be removed and the remaining intervals are non-overlapping.

### Example 2
- **Input:** `intervals = [[1, 2], [1, 2], [1, 2]]`
- **Output:** `2`
- **Explanation:** You need to remove two `[1, 2]` to leave a single non-overlapping interval.

### Example 3
- **Input:** `intervals = [[1, 2], [2, 3]]`
- **Output:** `0`
- **Explanation:** You don't need to remove any of the intervals since they're already non-overlapping.

---

## Constraints

- $1 \le \text{intervals.length} \le 10^5$
- $\text{intervals}[i]\text{.length} == 2$
- $-5 \times 10^4 \le start_i < end_i \le 5 \times 10^4$

---

## The Greedy Choice & Paradigm

Minimizing the intervals to remove is strictly equivalent to **maximizing the number of compatible non-overlapping intervals you can keep** (The Activity Selection Problem).

### Why Sort by End Time?
- If you sort by start time, an interval starting early might be extremely long (e.g., `[1, 100]`), blocking many smaller, better intervals.
- By sorting strictly by **end time**, the interval that finishes earliest frees up the timeline as soon as possible, leaving maximum remaining room for future intervals.

### Greedy Algorithm:
1. Sort intervals by their ending times in ascending order.
2. Maintain `last_end` of the most recently scheduled interval.
3. For each subsequent interval $[start, end]$:
   - If $start \ge last\_end$: It does not overlap. Keep it and update $last\_end = end$.
   - If $start < last\_end$: It overlaps with an interval that ends earlier (or at the same time). Greedily remove this interval (`removals++`).

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Greedy (Sort by End Time)** | $O(N \log N)$ | $O(1)$ (or $O(\log N)$ for sort stack) | Optimal standard approach |
| **Greedy (Sort by Start Time)** | $O(N \log N)$ | $O(1)$ | Tracks earliest end when collision occurs |
| **Dynamic Programming (LIS style)** | $O(N^2)$ | $O(N)$ | Suboptimal baseline |

