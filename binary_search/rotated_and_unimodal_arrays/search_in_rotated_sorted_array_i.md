# Search in Rotated Sorted Array I (LeetCode 33)

## Problem Statement
There is an integer array `nums` sorted in ascending order (with distinct values).

Prior to being passed to your function, `nums` is possibly rotated at an unknown pivot index `k` (`1 <= k < nums.length`).

Given the array `nums` after the possible rotation and an integer `target`, return the index of `target` if it is in `nums`, or `-1` if it is not in `nums`.

You must write an algorithm with $O(\log n)$ runtime complexity.

### Example 1:
```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```

### Constraints:
- `1 <= nums.length <= 5000`
- `-10^4 <= nums[i], target <= 10^4`
- All values of `nums` are unique.
- `nums` is an ascending array that is possibly rotated.

---

## Pattern Insight: One Half Is Always Monotonically Sorted
- In any rotated sorted array, splitting at `mid` always produces **at least one sorted half**:
  - If `nums[left] <= nums[mid]`: The **left half** $[left, mid]$ is sorted.
    - If `nums[left] <= target && target < nums[mid]`: target is in left half $\to$ `right = mid - 1`.
    - Else: target must be in right half $\to$ `left = mid + 1`.
  - Else: The **right half** $[mid, right]$ is sorted.
    - If `nums[mid] < target && target <= nums[right]`: target is in right half $\to$ `left = mid + 1`.
    - Else: target must be in left half $\to$ `right = mid - 1`.

---

## Complexity
- **Time Complexity:** $O(\log N)$ strictly.
- **Space Complexity:** $O(1)$.
