# Best Time to Buy and Sell Stock (LeetCode 121)

## Problem Statement

You are given an array `prices` where `prices[i]` is the price of a given stock on the $i$-th day.

You want to maximize your profit by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock.

Return the **maximum profit** you can achieve from this transaction. If you cannot achieve any profit, return `0`.

---

## Examples

### Example 1:
```text
Input: prices = [7, 1, 5, 3, 6, 4]
Output: 5
Explanation:
Buy on day 1 (price = 1) and sell on day 4 (price = 6), profit = 6 - 1 = 5.
Note that buying on day 1 and selling on day 0 is not allowed because you must buy before you sell.
```

### Example 2:
```text
Input: prices = [7, 6, 4, 3, 1]
Output: 0
Explanation:
In this case, no transactions are done and the max profit = 0.
```

### Example 3:
```text
Input: prices = [2, 4, 1]
Output: 2
Explanation:
Buy on day 0 (price = 2) and sell on day 1 (price = 4), profit = 4 - 2 = 2.
```

---

## Constraints

- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^4`

---

## Recurrence Formulation & Algorithmic Approaches

### 1. Invariant & Prefix State
If you sell on day $i$, the optimal day to have bought is the day with the minimum price in the range $[0 \dots i - 1]$.
$$\text{profit}[i] = prices[i] - \min_{0 \le j < i} prices[j]$$

### 2. Single-Pass State Tracking
Maintain a running minimum `minPrice` of the stock seen so far:
1. Initialize `minPrice = prices[0]`, `maxProfit = 0`.
2. For each day $i$ from $1$ to $N - 1$:
   - $\text{maxProfit} = \max(\text{maxProfit}, \; prices[i] - \text{minPrice})$
   - $\text{minPrice} = \min(\text{minPrice}, \; prices[i])$

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Brute Force (All Pairs)** | $O(N^2)$ | $O(1)$ |
| **Prefix Min Single Pass** | $O(N)$ | $O(1)$ |
