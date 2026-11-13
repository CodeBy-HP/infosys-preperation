# Distinct Subsequences (LeetCode 115)

## Problem Statement

Given two strings `s` and `t`, return the **number of distinct subsequences** of `s` which equals `t`.

The test cases are generated so that the answer fits on a 64-bit signed integer.

---

## Examples

### Example 1:
```text
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s:
1. ra[b]bbit
2. rab[b]bit
3. rabb[b]it
(Each bracket represents deleting that specific 'b').
```

### Example 2:
```text
Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
There are 5 ways to form "bag" from s:
1. [ba]b[g]bag
2. [ba]bgba[g]
3. [b]abgb[ag]
4. bab[g]ba[g]
5. babg[bag]
```

---

## Constraints

- `1 <= s.length, t.length <= 1000`
- `s` and `t` consist of English letters.

---

## Recurrence Formulation & Algorithmic Approaches

### 1. State Definition
Let $dp[i][j]$ be the number of distinct subsequences of prefix $s[0 \dots i - 1]$ that equal prefix $t[0 \dots j - 1]$.

### 2. State Transition
At character $s[i - 1]$ and target character $t[j - 1]$:
- **Case 1: $s[i - 1] == t[j - 1]$**
  We have two distinct options:
  1. **Match them:** Pair $s[i - 1]$ with $t[j - 1]$ and count solutions for remaining prefixes: $dp[i - 1][j - 1]$.
  2. **Skip $s[i - 1]$:** Leave $s[i - 1]$ unused and look for other matches of $t[j - 1]$ earlier in $s$: $dp[i - 1][j]$.
  $$dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]$$

- **Case 2: $s[i - 1] \ne t[j - 1]$**
  We cannot use $s[i - 1]$ to match $t[j - 1]$:
  $$dp[i][j] = dp[i - 1][j]$$

### 3. Base Cases
- $dp[i][0] = 1$ for all $0 \le i \le N$ (an empty target string $t$ is formed in exactly 1 way: deleting all characters in $s$).
- $dp[0][j] = 0$ for all $j \ge 1$ (an empty source string $s$ cannot match a non-empty target).

### 4. 1D In-Place Optimization ($O(M)$)
By iterating $j$ **backwards** from $M$ down to $1$:
```cpp
vector<uint64_t> dp(M + 1, 0);
dp[0] = 1;
for (int i = 1; i <= N; ++i) {
    for (int j = M; j >= 1; --j) {
        if (s[i - 1] == t[j - 1]) {
            dp[j] += dp[j - 1];
        }
    }
}
return dp[M];
```

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Top-Down Memoization** | $O(N \times M)$ | $O(N \times M)$ table + $O(N + M)$ stack |
| **Tabulation (2D DP)** | $O(N \times M)$ | $O(N \times M)$ |
| **Space-Optimized (1D DP)** | $O(N \times M)$ | $O(M)$ where $M = |t|$ |
