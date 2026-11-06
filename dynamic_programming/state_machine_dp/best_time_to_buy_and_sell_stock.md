# Best Time to Buy and Sell Stock (Single Transaction)

## Problem Overview
You are given an array `prices` where `prices[i]` is the price of a given stock on the $i$-th day.
You want to maximize your profit by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return `0`.

---

## Invariant Formulation
To maximize profit on day $i$, you should have bought at the **minimum price seen so far** in the prefix $0 \dots i-1$:
$$\text{profit}_i = \text{prices}[i] - \min_{0 \le j < i} \text{prices}[j]$$
We maintain a running minimum `minPrice` as we traverse the array.

---

## Complexity Analysis
- **Brute Force:** Compare all $(i, j)$ pairs with $j > i$: $O(N^2)$ Time, $O(1)$ Space.
- **Optimized Single Pass:**
  - **Time Complexity:** $O(N)$
  - **Auxiliary Space:** $O(1)$

