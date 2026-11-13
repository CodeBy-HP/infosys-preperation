# 0/1 Knapsack Problem (GFG)

## Problem Statement

Given $N$ items, each with a given weight `wt[i]` and value `val[i]`, and a knapsack of maximum capacity $W$.

You cannot divide items; you must either pick an item completely or leave it (the 0/1 property).

Find the **maximum total value** that can be put in the knapsack such that the sum of the weights of the chosen items does not exceed $W$.

---

## Examples

### Example 1:
```text
Input: N = 3, W = 4, val = [1, 2, 3], wt = [4, 5, 1]
Output: 3
Explanation:
Only item 0 (wt 4, val 1) or item 2 (wt 1, val 3) can fit within capacity 4.
Selecting item 2 gives maximum value 3.
```

### Example 2:
```text
Input: N = 3, W = 3, val = [1, 2, 3], wt = [4, 5, 6]
Output: 0
Explanation:
Every item weighs more than the knapsack capacity W = 3.
Maximum obtainable value is 0.
```

### Example 3:
```text
Input: N = 4, W = 5, val = [10, 40, 30, 50], wt = [5, 4, 6, 3]
Output: 50
Explanation:
Pick item 3 (wt 3, val 50) within capacity 5 -> value = 50.
```

---

## Constraints

- $1 \le N \le 1000$
- $1 \le W \le 1000$
- $1 \le wt[i] \le 1000$
- $1 \le val[i] \le 10^5$

---

## Recurrence Formulation & Algorithmic Approaches

### 1. State Definition
Let $dp[i][w]$ denote the maximum value obtainable using a subset of the first $i$ items `items[0 ... i - 1]` with a weight capacity of $w$.

### 2. State Transition
For each item $i - 1$:
- **Leave item $i - 1$:** Value is whatever was optimal with $i - 1$ items: $dp[i - 1][w]$.
- **Take item $i - 1$ (if $w \ge wt[i - 1]$):** Add $val[i - 1]$ and look up remaining capacity in the previous row:
  $$val[i - 1] + dp[i - 1][w - wt[i - 1]]$$

$$dp[i][w] = \max(dp[i - 1][w], \; (w \ge wt[i - 1] \; ? \; val[i - 1] + dp[i - 1][w - wt[i - 1]] : 0))$$

### 3. Base Cases
- $dp[0][w] = 0$ for all $0 \le w \le W$ (0 items give 0 value).
- $dp[i][0] = 0$ for all $0 \le i \le N$ (capacity 0 cannot hold any weight).

### 4. 1D In-Place Optimization ($O(W)$)
Because calculating the state for capacity $w$ requires only the previous row's value at a strictly smaller capacity $w - wt[i - 1]$, iterating $w$ **backwards** from $W$ down to $wt[i - 1]$ prevents overwriting values needed for subsequent computations:
```cpp
vector<int> dp(W + 1, 0);
for (int i = 0; i < N; ++i) {
    for (int w = W; w >= wt[i]; --w) {
        dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
    }
}
return dp[W];
```

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Top-Down Memoization** | $O(N \times W)$ | $O(N \times W)$ table + $O(N)$ recursion depth |
| **Tabulation (2D DP)** | $O(N \times W)$ | $O(N \times W)$ |
| **Space-Optimized (1D DP)** | $O(N \times W)$ | $O(W)$ |
