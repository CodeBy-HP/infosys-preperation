# Wildcard Matching (LeetCode 44)

## Problem Statement

Given an input string `s` and a pattern `p`, implement wildcard pattern matching with support for `'?'` and `'*'`:
- `'?'` Matches any single character.
- `'*'` Matches any sequence of characters (including the empty sequence).

The matching should cover the **entire** input string (not partial).

---

## Examples

### Example 1:
```text
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

### Example 2:
```text
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence, including "aa".
```

### Example 3:
```text
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter 'a' does not match 'b'.
```

### Example 4:
```text
Input: s = "adceb", p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, and the second '*' matches "dce".
```

---

## Constraints

- `0 <= s.length, p.length <= 2000`
- `s` contains only lowercase English letters.
- `p` contains only lowercase English letters, `'?'` or `'*'`.

---

## Recurrence Formulation & Algorithmic Approaches

### 1. State Definition
Let $dp[i][j]$ be a boolean denoting whether the prefix $s[0 \dots i - 1]$ matches the pattern prefix $p[0 \dots j - 1]$.

### 2. State Transitions
- **Matching character or `'?'`:**
  If $p[j - 1] == s[i - 1]$ or $p[j - 1] == '?'$:
  $$dp[i][j] = dp[i - 1][j - 1]$$

- **Wildcard `'*'`:**
  The `'*'` character can either:
  1. Match an empty character sequence: $dp[i][j - 1]$
  2. Consume one character of $s$ ($s[i - 1]$) and remain available to match more: $dp[i - 1][j]$
  $$dp[i][j] = dp[i][j - 1] \lor dp[i - 1][j]$$

- **Mismatch:**
  $$dp[i][j] = \text{false}$$

### 3. Base Cases
- $dp[0][0] = \text{true}$ (empty string matches empty pattern).
- $dp[i][0] = \text{false}$ for $i > 0$ (non-empty string cannot match empty pattern).
- $dp[0][j] = \text{true}$ if and only if $p[j - 1] == '*'$ and $dp[0][j - 1] == \text{true}$ (prefix consists exclusively of `*`).

### 4. 1D Space Optimization ($O(M)$)
Since row $i$ relies only on row $i - 1$, maintain two 1D boolean vectors `prev` and `curr` of size $|p| + 1$.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Tabulation (2D DP)** | $O(N \times M)$ | $O(N \times M)$ |
| **Space-Optimized (Rolling Rows)** | $O(N \times M)$ | $O(M)$ where $M = |p|$ |
| **Greedy Two-Pointers** | $O(N + M)$ average, $O(N \times M)$ worst | $O(1)$ |
