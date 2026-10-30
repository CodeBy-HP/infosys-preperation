# Single Element in a Sorted Array (LeetCode 540)

## Problem Statement
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in $O(\log n)$ time and $O(1)$ space.

### Example 1:
```
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
```

### Example 2:
```
Input: nums = [3,3,7,7,10,11,11]
Output: 10
```

### Constraints:
- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^5`

---

## Pattern Insight: Even-Odd Index Parity Invariant
- Before the unique single element appears:
  - Every pair starts at an **even index** ($0, 2, 4, \dots$) and ends at an **odd index** ($1, 3, 5, \dots$).
  - For any even index $i$, $nums[i] == nums[i + 1]$.
- After the unique element appears:
  - The pattern is disrupted! Pairs start at odd indices and end at even indices ($nums[i] == nums[i - 1]$ for even $i$).
- Binary search:
  - Let $mid = left + (right - left) / 2$.
  - Ensure $mid$ is even: `if (mid % 2 == 1) mid--;`
  - If `nums[mid] == nums[mid + 1]`:
    - The disruption has not occurred yet. Unique element must be to the right $\to$ `left = mid + 2`.
  - Else:
    - The disruption has occurred at or before $mid \to$ `right = mid`.
- Terminates at `nums[left]`!

---

## Complexity
- **Time Complexity:** $O(\log N)$.
- **Space Complexity:** $O(1)$.
