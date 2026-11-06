# Distinct Subsequences

## Problem Overview
Given two strings `s` and `t`, return the **number of distinct subsequences** of `s` which equals `t`.
The test cases are generated so that the answer fits on a 64-bit signed integer.

---

## Recurrence Formulation
Let $dp[i][j]$ be the number of distinct subsequences of $s[0 \dots i-1]$ matching $t[0 \dots j-1]$:
- If $s[i - 1] == t[j - 1]$:
  We have two options:
  1. Use $s[i - 1]$ to match $t[j - 1]$: $dp[i - 1][j - 1]$
  2. Do not use $s[i - 1]$ (look for matches in earlier prefix): $dp[i - 1][j]$
  $$dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]$$
- If $s[i - 1] \ne t[j - 1]$:
  We cannot use $s[i - 1]$:
  $$dp[i][j] = dp[i - 1][j]$$

- **Base Cases:**
  - $dp[i][0] = 1$ for all $0 \le i \le N$ (an empty target $t$ matches exactly 1 empty subsequence).
  - $dp[0][j] = 0$ for all $j \ge 1$.

### 1D In-Place Optimization
By traversing $j$ **backwards** from $M$ down to $1$:
$$dp[j] = dp[j] + (s[i - 1] == t[j - 1] \; ? \; dp[j - 1] : 0)$$

---

## Complexity Analysis
- **Time Complexity:** $O(N \times M)$
- **Auxiliary Space:** $O(M)$

