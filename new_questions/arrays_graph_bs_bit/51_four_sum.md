# 51. 4Sum (LeetCode 18)

## Problem Statement

Given an array `nums` of `n` integers, return an array of all the **unique** quadruplets `[nums[a], nums[b], nums[c], nums[d]]` such that:
- $0 \le a, b, c, d < n$
- `a`, `b`, `c`, and `d` are **distinct**.
- `nums[a] + nums[b] + nums[c] + nums[d] == target`

You may return the answer in **any order**.

---

## Examples

### Example 1
- **Input:** `nums = [1, 0, -1, 0, -2, 2]`, `target = 0`
- **Output:** `[[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]`

### Example 2
- **Input:** `nums = [2, 2, 2, 2, 2]`, `target = 8`
- **Output:** `[[2, 2, 2, 2]]`

---

## Constraints

- $1 \le \text{nums.length} \le 200$
- $-10^9 \le \text{nums}[i] \le 10^9$
- $-10^9 \le \text{target} \le 10^9$

---

## Pattern Insight: Sorting + Two-Pointer Squeeze + Duplicate Pruning

1. Sort `nums` ascending in $O(N \log N)$.
2. Fix `i` (`0..n-4`) and `j` (`i+1..n-3`), skipping duplicate values at `i` and `j`.
3. Use two pointers `left = j + 1`, `right = n - 1` looking for `nums[left] + nums[right] == rem` using 64-bit `long long` arithmetic to prevent overflow.
4. Skip duplicate values after matching.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Sorting + Fixed Pair + Two Pointers** | $O(N^3)$ | $O(1)$ auxiliary |
