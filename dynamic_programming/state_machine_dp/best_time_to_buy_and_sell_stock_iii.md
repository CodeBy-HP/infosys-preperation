# Best Time to Buy and Sell Stock III (LeetCode 123)

## Problem Statement

You are given an array `prices` where `prices[i]` is the price of a given stock on the $i$-th day.

Find the **maximum profit** you can achieve. You may complete **at most two transactions**.

**Note:** You may not engage in multiple transactions simultaneously (i.e. you must sell the stock before you buy again).

---

## Examples

### Example 1:
```text
Input: prices = [3, 3, 5, 0, 0, 3, 1, 4]
Output: 6
Explanation:
- Buy on day 3 (price = 0) and sell on day 5 (price = 3), profit = 3 - 0 = 3.
- Buy on day 6 (price = 1) and sell on day 7 (price = 4), profit = 4 - 1 = 3.
Total profit = 3 + 3 = 6.
```

### Example 2:
```text
Input: prices = [1, 2, 3, 4, 5]
Output: 4
Explanation:
- Buy on day 0 (price = 1) and sell on day 4 (price = 5), profit = 5 - 1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell later, as you are engaging in multiple transactions simultaneously.
```

### Example 3:
```text
Input: prices = [7, 6, 4, 3, 1]
Output: 0
Explanation:
No profit is possible, return 0.
```

---

## Constraints

- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^5`

---

## Recurrence Formulation & Algorithmic Approaches

### 1. 3D State Formulation
Let $dp[i][buy][cap]$ represent the maximum profit from day $i$ onwards:
- $buy \in \{0, 1\}$: $1$ if permitted to buy, $0$ if holding and must sell.
- $cap \in \{1, 2\}$: Remaining allowed transaction capacity (a transaction finishes upon selling).

#### Transitions:
- If $buy == 1$:
  $$dp[i][1][cap] = \max\Big(-prices[i] + dp[i + 1][0][cap], \; dp[i + 1][1][cap]\Big)$$
- If $buy == 0$:
  $$dp[i][0][cap] = \max\Big(prices[i] + dp[i + 1][1][cap - 1], \; dp[i + 1][0][cap]\Big)$$

- **Base Cases:**
  $$dp[N][buy][cap] = 0, \quad dp[i][buy][0] = 0$$

### 2. Four Finite States ($O(1)$ Space)
At any point, we can track the maximum capital balance across four sequential states:
- `firstBuy`: Max balance after 1st buy $\to \max(\text{firstBuy}, -\text{prices}[i])$
- `firstSell`: Max profit after 1st sell $\to \max(\text{firstSell}, \text{firstBuy} + \text{prices}[i])$
- `secondBuy`: Max balance after 2nd buy $\to \max(\text{secondBuy}, \text{firstSell} - \text{prices}[i])$
- `secondSell`: Max profit after 2nd sell $\to \max(\text{secondSell}, \text{secondBuy} + \text{prices}[i])$

Initial states:
`firstBuy = -INF`, `firstSell = 0`, `secondBuy = -INF`, `secondSell = 0`.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **3D DP Tabulation** | $O(N \times 2 \times 3) = O(N)$ | $O(N \times 6)$ |
| **4-Variable State Machine** | $O(N)$ | $O(1)$ |
