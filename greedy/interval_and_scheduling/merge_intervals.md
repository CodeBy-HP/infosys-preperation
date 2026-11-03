# Problem 8: Merge Intervals (LeetCode 56 / Scheduling)

## Problem Statement

A scheduler receives a list of proposed meeting time slots `intervals`, where $\text{intervals}[i] = [\text{start}_i, \text{end}_i]$.

Return a new list of non-overlapping intervals that cover all the intervals in the input, where all **overlapping time slots have been merged together**, sorted in ascending order of their start times.

Two intervals $[s_1, e_1]$ and $[s_2, e_2]$ overlap if $s_2 \le e_1$ (assuming $s_1 \le s_2$).

---

## Examples

### Example 1
- **Input:** `intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]`
- **Output:** `[[1, 6], [8, 10], [15, 18]]`
- **Explanation:** Intervals `[1, 3]` and `[2, 6]` overlap because $2 \le 3$, so they merge into `[1, max(3, 6)] = [1, 6]`.

### Example 2
- **Input:** `intervals = [[1, 4], [4, 5]]`
- **Output:** `[[1, 5]]`
- **Explanation:** Intervals touching at the boundary ($4 \le 4$) are considered overlapping and merged.

---

## Constraints

- $1 \le \text{intervals.length} \le 10^5$
- $\text{intervals}[i].\text{length} == 2$
- $0 \le \text{start}_i \le \text{end}_i \le 10^4$

---

## Algorithmic Paradigm: Sort by Start Time & Greedy Sweep

### Why Sorting by Start Time is Crucial
When intervals are sorted by their start times:
$$s_1 \le s_2 \le s_3 \le \dots \le s_N$$
any interval that can overlap with the current merged block must begin **before or at** the end of that block:
$$\text{current\_start} \le \text{merged.back().end}$$

If this condition holds:
- The current interval overlaps with the merged block.
- We extend the merged block's end to accommodate it:
  $$\text{merged.back().end} = \max(\text{merged.back().end}, \text{current\_end})$$

If $\text{current\_start} > \text{merged.back().end}$:
- No future interval can overlap with `merged.back()` either (since future start times will be $\ge \text{current\_start} > \text{merged.back().end}$).
- The previous interval is permanently finalized, and the current interval starts a brand-new distinct time slot.

---

## Complexity Analysis

| Step | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Sorting Intervals** | $O(N \log N)$ | $O(\log N)$ auxiliary |
| **Linear Merge Sweep** | $O(N)$ | $O(N)$ for output |
| **Total** | $\mathcal{O}(N \log N)$ | $\mathcal{O}(N)$ |

