# Problem 20: Sort Colors / Dutch National Flag (LeetCode 75)

## Problem Statement

Given an array `nums` with $n$ objects colored red, white, or blue, sort them **in-place** so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers `0`, `1`, and `2` to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function and in **a single pass with $O(1)$ extra space**.

---

## Examples

### Example 1
- **Input:** `nums = [2, 0, 2, 1, 1, 0]`
- **Output:** `[0, 0, 1, 1, 2, 2]`

### Example 2
- **Input:** `nums = [2, 0, 1]`
- **Output:** `[0, 1, 2]`

---

## Constraints

- $n == \text{nums.length}$
- $1 \le n \le 300$
- `nums[i]` is either `0`, `1`, or `2`.

---

## The Dutch National Flag 3-Way Partition

Maintain three pointers:
- `low`: boundary where next `0` must be placed (all indices $< low$ are `0`).
- `mid`: current element being evaluated (all indices between $low$ and $mid - 1$ are `1`).
- `high`: boundary where next `2` must be placed (all indices $> high$ are `2`).

### Invariant Steps:
- If `nums[mid] == 0`: `swap(nums[low], nums[mid]); low++; mid++;`
- If `nums[mid] == 1`: `mid++;`
- If `nums[mid] == 2`: `swap(nums[mid], nums[high]); high--;` (Do **not** advance `mid`, since swapped-in element from `high` has not yet been evaluated!).

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Dutch National Flag (One Pass)** | $O(N)$ | $O(1)$ |
