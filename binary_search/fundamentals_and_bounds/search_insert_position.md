# Search Insert Position (LeetCode 35)

## Problem Statement
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with $O(\log n)$ runtime complexity.

### Example 1:
```
Input: nums = [1,3,5,6], target = 5
Output: 2
```

### Example 2:
```
Input: nums = [1,3,5,6], target = 2
Output: 1
```

### Constraints:
- `1 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` contains distinct values sorted in ascending order.
- `-10^4 <= target <= 10^4`

---

## Pattern Insight: Lower Bound Index Invariant
- The insert position is equivalent to `std::lower_bound`: the first index where `nums[i] >= target`.
- In a standard binary search loop `while (left <= right)`:
  - If `nums[mid] >= target`: `right = mid - 1`.
  - If `nums[mid] < target`: `left = mid + 1`.
- When the loop terminates, `left` will point to the exact insertion position!

---

## Complexity
- **Time Complexity:** $O(\log N)$.
- **Space Complexity:** $O(1)$.
