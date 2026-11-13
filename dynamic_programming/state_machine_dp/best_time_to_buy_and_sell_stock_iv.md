# Best Time to Buy and Sell Stock IV (LeetCode 188)

## Problem Statement

You are given an integer array `prices` where `prices[i]` is the price of a given stock on the $i$-th day, and an integer $k$.

Find the **maximum profit** you can achieve. You may complete at most $k$ transactions: i.e., you may buy at most $k$ times and sell at most $k$ times.

**Note:** You may not engage in multiple transactions simultaneously (i.e. you must sell the stock before you buy again).

---

## Examples

### Example 1:
```text
Input: k = 2, prices = [2, 4, 1]
Output: 2
Explanation:
Buy on day 0 (price = 2) and sell on day 1 (price = 4), profit = 4 - 2 = 2.
```

### Example 2:
```text
Input: k = 2, prices = [3, 2, 6, 5, 0, 3]
Output: 7
Explanation:
- Buy on day 1 (price = 2) and sell on day 2 (price = 6), profit = 6 - 2 = 4.
- Buy on day 4 (price = 0) and sell on day 5 (price = 3), profit = 3 - 0 = 3.
Total profit = 4 + 3 = 7.
```

---

## Constraints

- `1 <= k <= 100`
- `1 <= prices.length <= 1000`
- `0 <= prices[i] <= 1000`

---

## Recurrence Formulation & Algorithmic Approaches

### 1. Large $k$ Optimization
If $k \ge \lfloor N / 2 \rfloor$, you can conduct a transaction on every profitable upward slope. The problem degenerates to **Stock II (Unlimited Transactions)**:
$$\text{Profit} = \sum_{i=1}^{N-1} \max(0, \; prices[i] - prices[i - 1])$$

### 2. State Definition & Transitions
For $k < N / 2$, let $dp[i][buy][cap]$ denote the maximum profit achievable from day $i$ with buying permission $buy \in \{0, 1\}$ and remaining transaction quota $cap \in [0, k]$:
- If $buy == 1$:
  $$dp[i][1][cap] = \max\Big(-prices[i] + dp[i + 1][0][cap], \; dp[i + 1][1][cap]\Big)$$
- If $buy == 0$:
  $$dp[i][0][cap] = \max\Big(prices[i] + dp[i + 1][1][cap - 1], \; dp[i + 1][0][cap]\Big)$$

### 3. Space Optimization to $O(K)$
Since day $i$ depends strictly on day $i + 1$, maintain two rolling tables of size $2 \times (k + 1)$: `ahead[2][k + 1]` and `curr[2][k + 1]`.

Alternatively, maintain $k$ buy-sell pairs in 1D arrays:
```cpp
vector<int> buy(k + 1, -1e9), sell(k + 1, 0);
for (int price : prices) {
    for (int t = 1; t <= k; ++t) {
        buy[t] = max(buy[t], sell[t - 1] - price);
        sell[t] = max(sell[t], buy[t] + price);
    }
}
return sell[k];
```

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Tabulation (3D DP)** | $O(N \times K)$ | $O(N \times K)$ |
| **Space-Optimized (1D Arrays)** | $O(N \times K)$ | $O(K)$ |
