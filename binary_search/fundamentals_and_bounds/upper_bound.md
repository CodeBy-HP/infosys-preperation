# Upper Bound in a Sorted Array

## Problem Statement

Given a sorted array `arr` of $N$ integers and an integer `target`, find the **upper bound** of `target`.

The **upper bound** of a target is defined as the smallest index `idx` such that:
$$\text{arr}[idx] > target$$

If all elements in the array are less than or equal to `target`, the upper bound is defined as the size of the array, $N$.

---

## Examples

### Example 1
- **Input:** `arr = [2, 3, 6, 7, 8, 8, 11, 11, 11, 12]`, `target = 6`
- **Output:** `3`
- **Explanation:** The first element strictly greater than `6` is `7`, located at index `3`.

### Example 2
- **Input:** `arr = [2, 3, 6, 7, 8, 8, 11, 11, 11, 12]`, `target = 11`
- **Output:** `9`
- **Explanation:** The first element strictly greater than `11` is `12`, located at index `9`.

### Example 3
- **Input:** `arr = [1, 2, 5, 6]`, `target = 10`
- **Output:** `4`
- **Explanation:** No element is strictly greater than `10`. The upper bound returns $N = 4$.

---

## Constraints

- $1 \le N \le 10^5$
- $1 \le \text{arr}[i], target \le 10^9$
- `arr` is sorted in non-decreasing order.

---

## The Upper Bound Invariant

In binary search on a closed interval $[left, right]$:
1. Initialize `ans = N`.
2. Compute $\text{mid} = left + \frac{right - left}{2}$.
3. Check condition $\text{arr}[mid] > target$:
   - If **True**: `arr[mid]` is strictly greater. Save `ans = mid`. Search leftward for an earlier index: `right = mid - 1`.
   - If **False**: $\text{arr}[mid] \le target$. We need strictly greater values, so search rightward: `left = mid + 1`.
4. At termination, `ans` holds the first index where $\text{arr}[idx] > target$.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space | Notes |
| :--- | :--- | :--- | :--- |
| **Binary Search (Custom Implementation)** | $O(\log N)$ | $O(1)$ | Optimal halving |
| **C++ Standard Library (`std::upper_bound`)** | $O(\log N)$ | $O(1)$ | Production iterator arithmetic |
| **Linear Search** | $O(N)$ | $O(1)$ | Brute-force scanning |

