# Subsets / Power Set Generation (LeetCode 78)

## Problem Statement
Given an integer array `nums` of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

### Example 1:
```
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

### Constraints:
- `1 <= nums.length <= 10`
- `-10 <= nums[i] <= 10`
- All numbers of `nums` are unique.

---

## Pattern Insight: Integer as a Boolean Characteristic Vector
- A set with $N$ elements has $2^N$ subsets.
- An integer `mask` in the range $[0, 2^N - 1]$ uniquely identifies which elements to pick:
  - If the $j$-th bit of `mask` is 1 (`(mask >> j) & 1`), include `nums[j]`.
  - If 0, exclude `nums[j]`.
- Loop `mask` from $0$ to $(1 \ll N) - 1$:
  - Non-recursive, completely iterative, and cache-friendly.

---

## Complexity
- **Time Complexity:** $O(N \cdot 2^N)$ — Generating $2^N$ subsets, each taking $O(N)$ bit inspections.
- **Space Complexity:** $O(1)$ auxiliary space (excluding result).
