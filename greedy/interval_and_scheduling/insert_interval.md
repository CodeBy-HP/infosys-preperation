# Insert Interval (LeetCode 57)

## Problem Overview
You are given an array of non-overlapping intervals `intervals` where `intervals[i] = [start_i, end_i]` sorted in ascending order by `start_i`.
You are also given an interval `newInterval = [start, end]`.
Insert `newInterval` into `intervals` such that `intervals` is still sorted in ascending order by `start_i` and `intervals` still does not have any overlapping intervals (merge overlapping intervals if necessary).
Return `intervals` after the insertion.

---

## 3-Phase Linear Partition Invariant
Because the input `intervals` is already sorted and disjoint, we can process the insertion in a single **linear $O(N)$ pass** divided into 3 distinct phases:

### Phase 1: Left Disjoint Intervals
Add all intervals that completely finish **before** `newInterval` begins:
$$\text{intervals}[i][1] < \text{newInterval}[0]$$
Push directly to output without modification.

### Phase 2: Overlapping Span Merging
While intervals overlap with `newInterval` ($\text{intervals}[i][0] \le \text{newInterval}[1]$):
$$\text{newInterval}[0] = \min(\text{newInterval}[0], \; \text{intervals}[i][0])$$
$$\text{newInterval}[1] = \max(\text{newInterval}[1], \; \text{intervals}[i][1])$$
After absorbing all overlapping spans, push the expanded `newInterval` to output.

### Phase 3: Right Disjoint Intervals
Append all remaining intervals that begin **after** `newInterval` finishes:
$$\text{intervals}[i][0] > \text{newInterval}[1]$$

---

## Complexity Analysis
- **Time Complexity:** $O(N)$ single linear pass.
- **Space Complexity:** $O(N)$ to construct the merged interval list.

