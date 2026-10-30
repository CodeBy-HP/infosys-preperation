# Find K Closest Elements (LeetCode 658)

## Problem Statement
Given a sorted integer array `arr`, two integers `k` and `x`, return the `k` closest integers to `x` in the array. The result should also be sorted in ascending order.

An integer `a` is closer to `x` than an integer `b` if:
- `|a - x| < |b - x|`, or
- `|a - x| == |b - x|` and `a < b`

### Example 1:
```
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
```

### Constraints:
- `1 <= k <= arr.length <= 10^4`
- `arr` is sorted in ascending order.
- `-10^4 <= arr[i], x <= 10^4`

---

## Pattern Insight: Binary Search on the Window Left Bound
- The answer is always a contiguous subarray of length $k$.
- Instead of expanding from $x$, binary search directly for the **starting index** $mid \in [0, n - k]$ of the window!
- Compare the two bounding elements: $arr[mid]$ (first element of window) and $arr[mid + k]$ (first element immediately outside window):
  - Is $arr[mid]$ closer to $x$ than $arr[mid + k]$?
  - Condition: if `x - arr[mid] > arr[mid + k] - x`:
    - $arr[mid + k]$ is strictly closer to $x$ than $arr[mid]$. The entire window must shift right!
    - `left = mid + 1`.
  - Else:
    - $arr[mid]$ is as close or closer to $x$. Keep window starting at or to the left of `mid`.
    - `right = mid`.
- Takes strictly $O(\log(N - k) + k)$ optimal time!

---

## Complexity
- **Time Complexity:** $O(\log(N - k) + k)$.
- **Space Complexity:** $O(1)$ auxiliary space.
