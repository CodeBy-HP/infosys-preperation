# Wildcard Matching

## Problem Overview
Given an input string `s` and a pattern `p`, implement wildcard pattern matching with support for `'?'` and `'*'`:
- `'?'` Matches any single character.
- `'*'` Matches any sequence of characters (including the empty sequence).

The matching should cover the **entire** input string (not partial).

---

## Recurrence Formulation
Let $dp[i][j]$ be whether string prefix $s[0 \dots i-1]$ matches pattern prefix $p[0 \dots j-1]$:
1. **Direct match or `?`:**
   If $p[j - 1] == s[i - 1]$ or $p[j - 1] == '?'$:
   $$dp[i][j] = dp[i - 1][j - 1]$$
2. **Wildcard `*`:**
   `*` can either match an empty sequence ($dp[i][j - 1]$) or consume the current character $s[i - 1]$ ($dp[i - 1][j]$):
   $$dp[i][j] = dp[i][j - 1] \lor dp[i - 1][j]$$
3. **Mismatch:**
   $$dp[i][j] = \text{false}$$

### Base Cases
- $dp[0][0] = \text{true}$ (empty string matches empty pattern).
- $dp[i][0] = \text{false}$ for $i > 0$ (non-empty string cannot match empty pattern).
- $dp[0][j] = \text{true}$ if and only if pattern prefix $p[0 \dots j-1]$ consists **exclusively of `*`**.

---

## Complexity Analysis
- **Space-Optimized Tabulation:**
  - **Time Complexity:** $O(N \times M)$
  - **Auxiliary Space:** $O(M)$

