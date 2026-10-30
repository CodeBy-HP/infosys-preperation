# Problem 2: 3Sum (LeetCode 15)

## Problem Statement

Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set must not contain **duplicate triplets**.

---

## Examples

### Example 1
- **Input:** `nums = [-1, 0, 1, 2, -1, -4]`
- **Output:** `[[-1, -1, 2], [-1, 0, 1]]`

### Example 2
- **Input:** `nums = [0, 1, 1]`
- **Output:** `[]`

---

## Constraints

- $3 \le \text{nums.length} \le 3000$
- $-10^5 \le \text{nums}[i] \le 10^5$

---

## Pattern: Sort + Fixed Element Two-Pointer Scan with Duplicate Skipping

1. **Sort `nums`** in ascending order.
2. For $i = 0$ to $N - 3$:
   - If `nums[i] > 0`: because array is sorted, sum of three positive numbers cannot be 0. Break!
   - If $i > 0$ and `nums[i] == nums[i - 1]`: skip duplicate pivot!
   - Set `left = i + 1`, `right = N - 1`.
   - While `left < right`:
     - If `nums[i] + nums[left] + nums[right] == 0`:
       - Record triplet `{nums[i], nums[left], nums[right]}`.
       - Skip identical `nums[left]` and `nums[right]`.
       - Advance `left++`, `right--`.
     - Else if `sum < 0`: `left++`.
     - Else: `right--`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Sort + Two Pointers** | $O(N^2)$ | $O(1)$ auxiliary (ignoring output) |
