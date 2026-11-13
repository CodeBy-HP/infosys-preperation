# Best Time to Buy and Sell Stock II (LeetCode 122)

## Problem Statement

You are given an integer array `prices` where `prices[i]` is the price of a given stock on the $i$-th day.

On each day, you may decide to buy and/or sell the stock. You can only hold **at most one** share of the stock at any time. However, you can buy it and then immediately sell it on the same day.

Find and return the **maximum profit** you can achieve.

---

## Examples

### Example 1:
```text
Input: prices = [7, 1, 5, 3, 6, 4]
Output: 7
Explanation:
- Buy on day 1 (price = 1) and sell on day 2 (price = 5), profit = 5 - 1 = 4.
- Buy on day 3 (price = 3) and sell on day 4 (price = 6), profit = 6 - 3 = 3.
Total profit is 4 + 3 = 7.
```

### Example 2:
```text
Input: prices = [1, 2, 3, 4, 5]
Output: 4
Explanation:
- Buy on day 0 (price = 1) and sell on day 4 (price = 5), profit = 5 - 1 = 4.
Total profit is 4.
```

### Example 3:
```text
Input: prices = [7, 6, 4, 3, 1]
Output: 0
Explanation:
There is no way to make a positive profit, so we never buy the stock to achieve max profit 0.
```

---

## Constraints

- `1 <= prices.length <= 3 * 10^4`
- `0 <= prices[i] <= 10^4`

---

## Recurrence Formulation & Algorithmic Approaches

### 1. State Machine Dynamic Programming
On each day $i$, we can be in one of two states:
- State 0 (`hold`): We currently hold a stock.
- State 1 (`free`): We currently do not hold a stock.

#### Transitions:
- If holding on day $i$, we either:
  1. Kept the stock bought previously: `hold`
  2. Bought today: `free - prices[i]`
  $$\text{hold} = \max(\text{hold}, \; \text{free} - prices[i])$$

- If free on day $i$, we either:
  1. Remained empty: `free`
  2. Sold today: `hold + prices[i]`
  $$\text{free} = \max(\text{free}, \; \text{hold} + prices[i])$$

- **Base Cases:**
  $$\text{hold} = -prices[0], \quad \text{free} = 0$$

### 2. Greedy Equivalence (Valley-to-Peak)
Because there are no transaction fees, a holding period across multiple ascending days $[p_0 \dots p_k]$ equals the sum of contiguous daily profits:
$$p_k - p_0 = (p_1 - p_0) + (p_2 - p_1) + \dots + (p_k - p_{k-1})$$
Thus, simply summing every positive delta:
$$\text{Total Profit} = \sum_{i=1}^{N-1} \max(0, \; prices[i] - prices[i-1])$$

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **State Machine DP** | $O(N)$ | $O(1)$ |
| **Greedy Slope Accumulation** | $O(N)$ | $O(1)$ |
