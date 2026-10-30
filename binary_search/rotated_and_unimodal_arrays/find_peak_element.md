# Find Peak Element (LeetCode 162)

## Problem Statement
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array `nums`, find a peak element, and return its index. If the array contains multiple peaks, return the index to **any of the peaks**.

You may imagine that `nums[-1] = nums[n] = -inf`. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in $O(\log n)$ time.

### Example 1:
```
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
```

### Constraints:
- `1 <= nums.length <= 1000`
- `-2^31 <= nums[i] <= 2^31 - 1`
- `nums[i] != nums[i + 1]` for all valid $i$.

---

## Pattern Insight: Local Gradient / Slope Test
- Compare `nums[mid]` with its immediate right neighbor `nums[mid + 1]`:
  - If `nums[mid] < nums[mid + 1]`:
    - We are on an **uphill slope** going right. Since $nums[n] = -\infty$, the curve must eventually turn downwards, guaranteeing at least one peak in $[mid + 1, right]$.
    - `left = mid + 1`.
  - Else (`nums[mid] > nums[mid + 1]`):
    - We are on a **downhill slope**. A peak must exist at `mid` or to its left.
    - `right = mid`.
- Terminates at `left == right`, identifying a guaranteed peak!

---

## Complexity
- **Time Complexity:** $O(\log N)$.
- **Space Complexity:** $O(1)$.
