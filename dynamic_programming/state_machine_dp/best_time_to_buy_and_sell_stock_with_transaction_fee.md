# Best Time to Buy and Sell Stock with Transaction Fee

## Problem Overview
You are given an array `prices` where `prices[i]` is the price of a given stock on the $i$-th day, and an integer `fee` representing a transaction fee.
Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
Note: You may not engage in multiple transactions simultaneously (i.e. you must sell the stock before you buy again). The fee is paid once per complete buy-sell round-trip (conventionally subtracted upon selling or buying).

---

## Recurrence Formulation
Two states:
- `hold`: Max profit on day $i$ while holding a stock.
  $$\text{hold} = \max(\text{hold}, \; \text{cash} - \text{prices}[i])$$
- `cash`: Max profit on day $i$ while not holding a stock (subtracting `fee` upon selling):
  $$\text{cash} = \max(\text{cash}, \; \text{hold} + \text{prices}[i] - \text{fee})$$

---

## Complexity Analysis
- **Time Complexity:** $O(N)$
- **Auxiliary Space:** $O(1)$

