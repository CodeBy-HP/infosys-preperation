# Count Subsets with Sum K (Perfect Sum Problem / GFG)

## Problem Statement

Given an array `arr` of $N$ non-negative integers and an integer $K$, find the **number of subsets** whose sum of elements equals $K$.

Since the answer may be very large, return it modulo $10^9 + 7$.

---

## Examples

### Example 1:
```text
Input: arr = [5, 2, 3, 10, 6, 8], K = 10
Output: 3
Explanation:
Subsets with sum 10:
1. {5, 2, 3} -> 5 + 2 + 3 = 10
2. {2, 8} -> 2 + 8 = 10
3. {10} -> 10
Total subsets = 3.
```

### Example 2:
```text
Input: arr = [0, 0, 1], K = 1
Output: 4
Explanation:
Subsets with sum 1:
1. {1}
2. {0 (first 0), 1}
3. {0 (second 0), 1}
4. {0, 0, 1}
All 4 combinations evaluate to sum 1.
```

### Example 3:
```text
Input: arr = [1, 2, 3, 4, 5], K = 5
Output: 3
Explanation:
Subsets: {5}, {2, 3}, {1, 4}.
```

---

## Constraints

- $1 \le N \le 1000$
- $0 \le arr[i] \le 1000$
- $0 \le K \le 1000$

---

## Recurrence Formulation & Algorithmic Approaches

### 1. State Definition
Let $dp[i][s]$ represent the number of subsets of the prefix subarray `arr[0 ... i]` that sum to $s$.

### 2. Decision Tree at Index $i$
- **Exclude `arr[i]`:** We seek sum $s$ using only the first $i - 1$ elements: $dp[i - 1][s]$.
- **Include `arr[i]` (if $s \ge arr[i]$):** We seek the remaining sum $s - arr[i]$ using elements $0 \dots i - 1$: $dp[i - 1][s - arr[i]]$.

$$dp[i][s] = (dp[i - 1][s] + (s \ge arr[i] \; ? \; dp[i - 1][s - arr[i]] : 0)) \pmod{10^9 + 7}$$

### 3. Critical Edge Case: Array Elements Equal to 0
If an array contains $Z$ zeros, every zero can either be chosen or omitted without altering the subset sum:
- If `arr[0] == 0`: $dp[0][0] = 2$ (take or don't take).
- If `arr[0] != 0`: $dp[0][0] = 1$, and if $arr[0] \le K$, $dp[0][arr[0]] = 1$.

### 4. Space-Optimized 1D Vector ($O(K)$)
To avoid using values from the same item pass, iterate sum $s$ **backwards** from $K$ down to $arr[i]$:
```cpp
vector<int> dp(K + 1, 0);
dp[0] = 1; // Empty subset
for (int num : arr) {
    for (int s = K; s >= num; --s) {
        dp[s] = (dp[s] + dp[s - num]) % MOD;
    }
}
```

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Top-Down Memoization** | $O(N \times K)$ | $O(N \times K)$ table + $O(N)$ recursion depth |
| **Tabulation (2D DP)** | $O(N \times K)$ | $O(N \times K)$ |
| **Space-Optimized (1D DP)** | $O(N \times K)$ | $O(K)$ |
