# Problem 11: Sliding Subarray Beauty (LeetCode 2653)

## Problem Statement

Given an integer array `nums` containing $n$ integers, find the **beauty** of every subarray of size $k$.

The **beauty** of a subarray is defined as:
- The **$x^{\text{th}}$ smallest integer** in the subarray if it is **negative**.
- Otherwise, the beauty is **0** if there are fewer than $x$ negative integers in the subarray.

Return an integer array of size $n - k + 1$ containing the beauty of each subarray.

---

## Examples

### Example 1
- **Input:** `nums = [1, -1, -3, -2, 3], k = 3, x = 2`
- **Output:** `[-1, -2, -2]`
- **Explanation:**
  - Window 1: `[1, -1, -3]`, negative numbers are `[-3, -1]`. 2nd smallest is `-1`.
  - Window 2: `[-1, -3, -2]`, negative numbers are `[-3, -2, -1]`. 2nd smallest is `-2`.
  - Window 3: `[-3, -2, 3]`, negative numbers are `[-3, -2]`. 2nd smallest is `-2`.

---

## Constraints

- $n == \text{nums.length}$
- $1 \le n \le 10^5$
- $1 \le k \le n$
- $1 \le x \le k$
- $-50 \le \text{nums}[i] \le 50$

---

## Pattern: Value-Bounded Frequency Bucket

Notice the critical constraint: $-50 \le \text{nums}[i] \le 50$.
Negative numbers range strictly from $-50$ to $-1$ (only 50 unique negative values!).
1. Maintain frequency array `count[51]` for negative values $[-50, -1]$.
2. Slide window of size $k$:
   - Add incoming negative number `count[abs(num)]++`.
   - Remove outgoing negative number `count[abs(outgoing)]--`.
3. To find $x^{\text{th}}$ smallest negative:
   - Iterate through buckets from $-50$ to $-1$. Sum frequencies until cumulative count reaches $x$.
   - Takes at most 50 steps per window!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Frequency Bucket Array** | $O(N \times 50) = O(N)$ | $O(51) = O(1)$ |
