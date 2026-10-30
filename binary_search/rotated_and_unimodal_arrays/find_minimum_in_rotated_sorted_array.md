# Find Minimum in Rotated Sorted Array (LeetCode 153)

## Problem Statement
Suppose an array of length `n` sorted in ascending order is rotated between `1` and `n` times.

Given the sorted rotated array `nums` of **unique** elements, return the minimum element of this array.

You must write an algorithm that runs in $O(\log n)$ time.

### Example 1:
```
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
```

### Constraints:
- `n == nums.length`
- `1 <= n <= 5000`
- `-5000 <= nums[i] <= 5000`
- All the integers of `nums` are unique.

---

## Pattern Insight: Pivot Comparison against `right`
- Compare `nums[mid]` against `nums[right]`:
  - If `nums[mid] > nums[right]`:
    - The inflection point (smallest element) must lie strictly to the right of `mid`.
    - Update `left = mid + 1`.
  - Else (`nums[mid] < nums[right]`):
    - The minimum is either `mid` itself or lies to the left of `mid`.
    - Update `right = mid` (cannot discard `mid`!).
- Loop condition: `while (left < right)`. When $left == right$, `nums[left]` is the minimum!

---

## Complexity
- **Time Complexity:** $O(\log N)$.
- **Space Complexity:** $O(1)$.
