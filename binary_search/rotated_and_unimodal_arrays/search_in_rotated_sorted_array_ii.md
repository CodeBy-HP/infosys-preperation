# Search in Rotated Sorted Array II (LeetCode 81)

## Problem Statement
There is an integer array `nums` sorted in non-decreasing order (not necessarily with distinct values).

Given the array `nums` after the possible rotation and an integer `target`, return `true` if `target` is in `nums`, or `false` if it is not in `nums`.

You must decrease the overall operation steps as much as possible.

### Example 1:
```
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
```

### Constraints:
- `1 <= nums.length <= 5000`
- `-10^4 <= nums[i], target <= 10^4`
- `nums` is guaranteed to be rotated at some pivot.

---

## Pattern Insight: Resolving Duplicate Ambiguity
- When duplicate values exist, we may encounter:
  $$nums[left] == nums[mid] == nums[right]$$
  For example: `[1, 0, 1, 1, 1]`.
- In this scenario, we cannot deduce whether the left or right half is sorted!
- **Resolution:** Shrink both ends:
  ```cpp
  ++left;
  --right;
  ```
- This skips redundant duplicate boundaries. In the worst case (all elements identical except target), time degrades to $O(N)$, but on average maintains $O(\log N)$.

---

## Complexity
- **Time Complexity:** $O(\log N)$ average, $O(N)$ worst case.
- **Space Complexity:** $O(1)$.
