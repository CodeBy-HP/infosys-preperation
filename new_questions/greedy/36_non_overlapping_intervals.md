# 36. Non-Overlapping Intervals (LeetCode 435)

## Problem Statement

Given an array of intervals `intervals` where `intervals[i] = [start_i, end_i]`, return the **minimum number of intervals** you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are **non-overlapping**. For example, `[1, 2]` and `[2, 3]` are non-overlapping.

---

## Examples

### Example 1
- **Input:** `intervals = [[1, 2], [2, 3], [3, 4], [1, 3]]`
- **Output:** `1`
- **Explanation:** `[1, 3]` can be removed and the rest of the intervals are non-overlapping.

### Example 2
- **Input:** `intervals = [[1, 2], [1, 2], [1, 2]]`
- **Output:** `2`

### Example 3
- **Input:** `intervals = [[1, 2], [2, 3]]`
- **Output:** `0`

---

## Constraints

- $1 \le \text{intervals.length} \le 10^5$
- $\text{intervals}[i].\text{length} == 2$
- $-5 \times 10^4 \le \text{start}_i < \text{end}_i \le 5 \times 10^4$

---

## Pattern Insight: Activity Selection (Sort by Earliest End Time)

To remove the minimum number of intervals, keep the **maximum number** of compatible intervals:
1. Sort intervals ascending by `end_i`.
2. Track `prevEnd = intervals[0][1]` and `kept = 1`.
3. For each subsequent interval: if `start >= prevEnd`, keep it (`kept++`, `prevEnd = end`).
4. Answer is `intervals.size() - kept`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Greedy Earliest Finish Time** | $O(N \log N)$ | $O(1)$ auxiliary |
