# Binary Search (LeetCode 704)

## Problem Statement
Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index. Otherwise, return `-1`.

You must write an algorithm with $O(\log n)$ runtime complexity.

### Example 1:
```
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4.
```

### Constraints:
- `1 <= nums.length <= 10^4`
- `-10^4 < nums[i], target < 10^4`
- All integers in `nums` are unique.
- `nums` is sorted in ascending order.

---

## Pattern Insight: The Halving Invariant & Overflow Prevention
- **Core Invariant:** Search range is $[left, right]$ (closed interval).
- **Midpoint Calculation:**
  $$\text{mid} = left + \frac{right - left}{2}$$
  *(Using `(left + right) / 2` can cause 32-bit signed integer overflow when $left + right > 2^{31} - 1$)*.
- **Three-way Comparison:**
  - If `nums[mid] == target`: Found immediately!
  - If `nums[mid] < target`: Target must lie in the right half $\to$ `left = mid + 1`.
  - If `nums[mid] > target`: Target must lie in the left half $\to$ `right = mid - 1`.

---

## Complexity
- **Time Complexity:** $O(\log N)$ logarithmic time.
- **Space Complexity:** $O(1)$ auxiliary space.
