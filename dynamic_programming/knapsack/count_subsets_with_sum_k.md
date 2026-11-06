# Count Subsets with Sum K

## Problem Overview
Given an array `arr` of $N$ non-negative integers and an integer $K$, find the number of subsets whose sum is equal to $K$.
Since the answer may be very large, return it modulo $10^9 + 7$.

---

## Critical Edge Case: Elements Equal to 0
When an element in the array is `0`, picking or skipping it doesn't change the sum!
For example, if array has $Z$ zeros, every valid non-zero subset can be paired with any of the $2^Z$ subsets of zeros.
- **Base Case at Index 0:**
  - If $arr[0] == 0$: $dp[0][0] = 2$ (either pick the zero or don't).
  - Else: $dp[0][0] = 1$ (don't pick), and if $arr[0] \le K$, $dp[0][arr[0]] = 1$ (pick).

---

## Recurrence Formulation
Let $dp[i][sum]$ be the number of subsets of prefix $0 \dots i$ with sum equal to $sum$:
$$dp[i][sum] = (dp[i - 1][sum] + (sum \ge arr[i] \; ? \; dp[i - 1][sum - arr[i]] : 0)) \pmod{10^9 + 7}$$

---

## Complexity Analysis
- **Space-Optimized Tabulation:**
  - **Time Complexity:** $O(N \times K)$
  - **Auxiliary Space:** $O(K)$

