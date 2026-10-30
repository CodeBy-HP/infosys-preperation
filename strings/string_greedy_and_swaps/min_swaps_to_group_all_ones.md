# Problem 15: Minimum Swaps to Group All 1's or 0's (LeetCode 1151 / 2134)

## Problem Statement

You are given a binary string `s` consisting only of `'0'` and `'1'`.

Your task is to find the **minimum number of adjacent swaps** required to make all identical characters appear together in one contiguous block.

You have two choices:
1. Group all `'1'` characters together.
2. Group all `'0'` characters together.

Return the minimum swaps required among the two options.

---

## Examples

### Example 1
- **Input:** `s = "1001"`
- **Output:** `0` (Zeros are already contiguous)

### Example 2
- **Input:** `s = "10101"`
- **Output:** `1` (Swap middle '1' and '0' -> "11100" takes 1 swap)

---

## Mathematical Model: Inversion Counting vs Distance to Median

For adjacent swaps gathering all instances of a character together:
1. **Pass 1:** Record indices of all target characters.
2. **Optimal Pivot:** The median index minimizes absolute distance sum $\sum |pos[i] - \text{median}|$.
3. **Obstacle Jump Formula:** Each opposing character is an obstacle jumped over by either the elements to its left or its right:
   $$\text{swaps} = \sum_{c \text{ is obstacle}} \min(\text{leftCount}, \text{totalCount} - \text{leftCount})$$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Obstacle Barrier Sum** | $O(N)$ | $O(1)$ |
