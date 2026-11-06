# Count Palindromic Subsequences

## Problem Overview
Given a string `s`, return the **total number of palindromic subsequences** (need not be distinct in value if characters are at different positions) modulo $10^9 + 7$.

---

## Inclusion-Exclusion Recurrence
Let $dp[i][j]$ be the count of palindromic subsequences in substring $s[i \dots j]$.
By the **Principle of Inclusion-Exclusion**:
- Subsequences in $s[i+1 \dots j]$: $dp[i+1][j]$
- Subsequences in $s[i \dots j-1]$: $dp[i][j-1]$
- Common intersection: $dp[i+1][j-1]$

### Case 1: $s[i] == s[j]$
The outer characters $s[i]$ and $s[j]$ can wrap around **every** palindromic subsequence in $s[i+1 \dots j-1]$, plus the two characters themselves form a new palindrome:
$$dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1$$
(Notice that $+ dp[i+1][j-1]$ from wrapping and $- dp[i+1][j-1]$ from intersection cancel out, leaving $+ 1$).

### Case 2: $s[i] \ne s[j]$
The outer characters cannot form a joint palindrome:
$$dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]$$

---

## Complexity Analysis
- **Tabulation (Interval DP):**
  - **Time Complexity:** $O(N^2)$
  - **Auxiliary Space:** $O(N^2)$ (or $O(N)$ rolling buffers).

