# Counting Bits (LeetCode 338)

## Problem Statement
Given an integer `n`, return an array `ans` of length `n + 1` such that for each `i` (`0 <= i <= n`), `ans[i]` is the **number of 1's** in the binary representation of `i`.

### Example 1:
```
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
```

### Example 2:
```
Input: n = 5
Output: [0,1,1,2,1,2]
```

### Constraints:
- `0 <= n <= 10^5`

**Follow-up:** Can you solve it in linear time $O(n)$ in a single pass without using built-in popcount functions?

---

## Pattern Insight: Dynamic Programming + Bit Shift Transition
- Notice the relationship between $i$ and $i >> 1$ (which is $\lfloor i / 2 \rfloor$):
  - Shifting $i$ right by 1 bit removes its lowest bit.
  - The number of 1s in $i$ is equal to the number of 1s in $(i >> 1)$ plus the lowest bit $(i \& 1)$.
- Recurrence:
  $$dp[i] = dp[i >> 1] + (i \& 1)$$
- Alternative recurrence using lowest set bit clearance:
  $$dp[i] = dp[i \& (i - 1)] + 1$$
- Both relations compute each state in strictly $O(1)$ time, yielding an optimal single-pass $O(N)$ solution.

---

## Complexity
- **Time Complexity:** $O(N)$ linear time.
- **Space Complexity:** $O(1)$ auxiliary space (excluding the output array).
