# Sum of Subarray Ranges (LeetCode 2104)

## Problem Statement

You are given an integer array `nums`. The **range** of a subarray of `nums` is the difference between the largest and smallest element in the subarray:
$$\text{range}(b) = \max(b) - \min(b)$$

Return the **sum of all subarray ranges** of `nums`:
$$\sum_{\text{subarrays } b} (\max(b) - \min(b))$$

---

## Examples

### Example 1
- **Input:** `nums = [1, 2, 3]`
- **Output:** `4`
- **Explanation:**
  - Subarrays of length 1: range is 0.
  - Subarrays of length 2:
    - `[1, 2] -> 2 - 1 = 1`
    - `[2, 3] -> 3 - 2 = 1`
  - Subarrays of length 3:
    - `[1, 2, 3] -> 3 - 1 = 2`
  - Total sum = $0 + 1 + 1 + 2 = 4$.

### Example 2
- **Input:** `nums = [1, 3, 3]`
- **Output:** `4`

### Example 3
- **Input:** `nums = [4, -2, -3, 4, 1]`
- **Output:** `59`

---

## Constraints

- $1 \le \text{nums.length} \le 1000$ (can easily scale to $10^5$ with $O(N)$ solution)
- $-10^9 \le \text{nums}[i] \le 10^9$

---

## Algorithmic Paradigm: Linearity of Summation

By linearity of summation:
$$\sum (\max(b) - \min(b)) = \sum \max(b) - \sum \min(b)$$

Instead of tracking pairs of indices for every subarray, we can:
1. Compute $\sum \max(b)$ using a **Monotonic Decreasing Stack** (finding previous greater and next greater boundaries for each element).
2. Compute $\sum \min(b)$ using a **Monotonic Increasing Stack** (finding previous smaller and next smaller boundaries for each element).
3. The answer is simply:
   $$\text{Total Ranges} = \text{Sum of Maximums} - \text{Sum of Minimums}$$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Monotonic Stack (Linearity of Summation)** | $O(N)$ | $O(N)$ |
| **Brute Force Subarray Iteration** | $O(N^2)$ | $O(1)$ |

