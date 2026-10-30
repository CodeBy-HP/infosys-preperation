# Find First and Last Position of Element in Sorted Array (LeetCode 34)

## Problem Statement
Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with $O(\log n)$ runtime complexity.

### Example 1:
```
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
```

### Constraints:
- `0 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`
- `nums` is a non-decreasing array.
- `-10^9 <= target <= 10^9`

---

## Pattern Insight: Lower Bound and Upper Bound Templates
1. **Lower Bound (`first_index`):**
   - Find the first index $i$ such that $nums[i] \ge target$.
   - If `nums[mid] >= target`: `ans = mid; right = mid - 1;` (search left for earlier occurrences).
   - Else: `left = mid + 1;`.
2. **Upper Bound (`last_index`):**
   - Find the last index $i$ such that $nums[i] \le target$.
   - If `nums[mid] <= target`: `ans = mid; left = mid + 1;` (search right for later occurrences).
   - Else: `right = mid - 1;`.
- Combining both gives the exact contiguous range $[first, last]$ in $2 \log N$ operations.

---

## Complexity
- **Time Complexity:** $O(\log N)$ logarithmic time.
- **Space Complexity:** $O(1)$.
