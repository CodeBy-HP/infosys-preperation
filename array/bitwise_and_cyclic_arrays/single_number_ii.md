# Problem 24: Single Number II (LeetCode 137)

## Problem Statement

Given an integer array `nums` where every element appears **three times** except for one, which appears **exactly once**. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only **constant extra space**.

---

## Examples

### Example 1
- **Input:** `nums = [2, 2, 3, 2]`
- **Output:** `3`

### Example 2
- **Input:** `nums = [0, 1, 0, 1, 0, 1, 99]`
- **Output:** `99`

---

## Constraints

- $1 \le \text{nums.length} \le 3 \times 10^4$
- $-2^{31} \le \text{nums}[i] \le 2^{31} - 1$

---

## Bit Counting Modulo 3 Principle

For each bit position $i \in [0, 31]$:
- Sum the $i^{\text{th}}$ bit across all numbers in `nums`.
- If a number appears 3 times, its contribution to the bit sum will be a multiple of 3.
- Therefore:
  $$\text{bitSum}[i] \pmod 3$$
  isolates the exact $i^{\text{th}}$ bit of the single unique number!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **32-Bit Sum Modulo 3** | $O(32 \times N) = O(N)$ | $O(1)$ |
