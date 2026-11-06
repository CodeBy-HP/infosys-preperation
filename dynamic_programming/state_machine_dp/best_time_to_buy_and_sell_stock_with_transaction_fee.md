# Best Time to Buy and Sell Stock with Transaction Fee (LeetCode 714)

## Problem Statement

You are given an array `prices` where `prices[i]` is the price of a given stock on the $i$-th day, and an integer `fee` representing a transaction fee.

Find the **maximum profit** you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

**Note:**
- You may not engage in multiple transactions simultaneously (i.e. you must sell the stock before you buy again).
- The transaction fee is only charged once per transaction (typically deducted upon either buying or selling).

---

## Examples

### Example 1:
```text
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation:
The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8 (profit = 8 - 1 - 2 = 5)
- Buying at prices[4] = 4
- Selling at prices[5] = 9 (profit = 9 - 4 - 2 = 3)
Total profit: 5 + 3 = 8.
```

### Example 2:
```text
Input: prices = [1, 3, 7, 5, 10, 3], fee = 3
Output: 6
Explanation:
- Buy at 1, sell at 7: 7 - 1 - 3 = 3
- Buy at 5, sell at 10: 10 - 5 - 3 = 2
Total = 5? Wait:
Buy at 1, sell at 10: 10 - 1 - 3 = 6!
Total profit is 6.
```

---

## Constraints

- `1 <= prices.length <= 5 * 10^4`
- `1 <= prices[i] <= 5 * 10^4`
- `0 <= fee <= 5 * 10^4`

---

## Recurrence Formulation & Algorithmic Approaches

### 1. State Machine Definition
On any given day, our portfolio is in one of two states:
- `hold`: We are holding a share of stock.
- `free`: We are not holding any stock (cash state).

### 2. State Transitions
On day $i$ with stock price $P = prices[i]$:
- To be in the `hold` state today:
  - We already held the stock yesterday: `hold`
  - Or we bought today using our cash balance: `free - P`
  $$\text{hold} = \max(\text{hold}, \; \text{free} - P)$$

- To be in the `free` state today:
  - We already were in cash yesterday: `free`
  - Or we sold our holding today and paid the transaction fee: `hold + P - fee`
  $$\text{free} = \max(\text{free}, \; \text{hold} + P - fee)$$

### 3. Base Cases
At day 0:
- `hold = -prices[0]`
- `free = 0`

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **State Machine DP** | $O(N)$ | $O(1)$ |
| **Tabulation (2D Array)** | $O(N)$ | $O(N)$ |
