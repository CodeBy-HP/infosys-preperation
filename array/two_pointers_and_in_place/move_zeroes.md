# Problem 4: Move Zeroes (LeetCode 283)

## Problem Statement

Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this **in-place** without making a copy of the array.

---

## Examples

### Example 1
- **Input:** `nums = [0, 1, 0, 3, 12]`
- **Output:** `[1, 3, 12, 0, 0]`

### Example 2
- **Input:** `nums = [0]`
- **Output:** `[0]`

---

## Constraints

- $1 \le \text{nums.length} \le 10^4$
- $-2^{31} \le \text{nums}[i] \le 2^{31} - 1$

---

## In-Place Compaction Pattern (Writer & Reader Pointers)

1. `writer = 0` tracks the index where the next non-zero element must land.
2. `reader` scans linearly through `nums`:
   - If `nums[reader] != 0`:
     - Swap `nums[writer]` with `nums[reader]`.
     - Advance `writer++`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **In-Place Swap Compaction** | $O(N)$ | $O(1)$ |
