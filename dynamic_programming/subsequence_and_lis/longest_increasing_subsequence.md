# Problem 11: Longest Increasing Subsequence (LIS)

## Problem Statement

Given an integer array `nums`, return the **length of the longest strictly increasing subsequence**.

A **subsequence** is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

---

## Examples

### Example 1
- **Input:** `nums = [10, 9, 2, 5, 3, 7, 101, 18]`
- **Output:** `4`
- **Explanation:** The longest strictly increasing subsequence is $[2, 3, 7, 101]$, so length is 4. (Another valid LIS is $[2, 5, 7, 101]$ or $[2, 3, 7, 18]$).

### Example 2
- **Input:** `nums = [0, 1, 0, 3, 2, 3]`
- **Output:** `4`
- **Explanation:** The longest strictly increasing subsequence is $[0, 1, 2, 3]$.

### Example 3
- **Input:** `nums = [7, 7, 7, 7, 7, 7, 7]`
- **Output:** `1`

---

## Constraints

- $1 \le \text{nums.length} \le 2500$
- $-10^4 \le \text{nums}[i] \le 10^4$

---

## Approaches & Paradigms

### 1. Top-Down (Pick vs Not Pick with Index Shift)
- State: `solve(curr, prev_idx)`
- We shift `prev_idx` by $+1$ for memoization since initial `prev_idx = -1`.
- Transition:
  - Not Pick: `solve(curr + 1, prev_idx)`
  - Pick: $1 + \text{solve}(curr + 1, curr)$ if $prev\_idx == -1$ or $\text{nums}[curr] > \text{nums}[prev\_idx]$.

### 2. Bottom-Up 1D DP ($O(N^2)$ Time, $O(N)$ Space)
- State: $\text{dp}[i]$ is the length of LIS ending **strictly at index $i$**.
- Base Case: $\text{dp}[i] = 1$ for all $i$.
- Recurrence:
  $$\text{dp}[i] = \max_{0 \le j < i,\, \text{nums}[i] > \text{nums}[j]} (1 + \text{dp}[j])$$

### 3. Patience Sorting / Binary Search ($O(N \log N)$ Time, $O(N)$ Space)
- Maintain an array `tails` where `tails[len - 1]` stores the smallest tail element of all increasing subsequences of length `len` found so far.
- For each `x` in `nums`:
  - Use `std::lower_bound` to find the first element in `tails` $\ge x$.
  - If found, replace it with `x` (giving smaller tail for the same length).
  - If not found, append `x` to `tails` (extends max LIS length).
- The final size of `tails` is the length of the LIS!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Top-Down (Recursion + Memoization)** | $O(N^2)$ | $O(N^2)$ |
| **Bottom-Up (1D Tabulation)** | $O(N^2)$ | $O(N)$ |
| **Patience Sorting / Binary Search** | $O(N \log N)$ | $O(N)$ |

