# Bitwise AND of Numbers Range (LeetCode 201)

## Problem Statement
Given two integers `left` and `right` that represent the range `[left, right]`, return the bitwise AND of all numbers in this range, inclusive.

### Example 1:
```
Input: left = 5, right = 7
Output: 4
Explanation: 5 & 6 & 7 = 101 & 110 & 111 = 100 (4)
```

### Example 2:
```
Input: left = 0, right = 0
Output: 0
```

### Constraints:
- `0 <= left <= right <= 2^31 - 1`

---

## Pattern Insight: Common Binary Prefix
- Consider the consecutive binary numbers from `left` to `right`.
- For any bit position that changes between `left` and `right`:
  - Because numbers are contiguous, that bit must transition between `0` and `1` at least once.
  - Since $1 \ \& \ 0 = 0$, that entire bit column zeroes out in the cumulative AND!
- **Conclusion:** The cumulative bitwise AND of `[left, right]` is simply the **common binary prefix** of `left` and `right`, with all differing trailing bits replaced by zeroes!
- **Approach 1 (Right Shift):**
  - Shift both `left` and `right` rightward until they become equal, tracking shift count $k$.
  - Return `left << k`.
- **Approach 2 (Brian Kernighan Clearing):**
  - While `right > left`, clear the lowest set bit of `right`: `right &= (right - 1)`.
  - When `right <= left`, return `right`.

---

## Complexity
- **Time Complexity:** $O(32) = O(1)$ bit shifts or bit eliminations.
- **Space Complexity:** $O(1)$.
