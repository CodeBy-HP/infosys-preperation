# Problem 15: Best Time to Buy and Sell Stock with Cooldown

## Problem Statement

You are given an array `prices` where `prices[i]` is the price of a given stock on the $i$-th day.

Find the **maximum profit** you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
1. After you sell your stock, you cannot buy stock on the next day (i.e., **cooldown of 1 day**).
2. You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

---

## Examples

### Example 1
- **Input:** `prices = [1, 2, 3, 0, 2]`
- **Output:** `3`
- **Explanation:**
  - Day 0: Buy at price = 1
  - Day 1: Sell at price = 2 (profit = $2 - 1 = 1$)
  - Day 2: Cooldown (mandatory)
  - Day 3: Buy at price = 0
  - Day 4: Sell at price = 2 (profit = $2 - 0 = 2$)
  - Total profit = $1 + 2 = 3$.

### Example 2
- **Input:** `prices = [1]`
- **Output:** `0`

---

## Constraints

- $1 \le \text{prices.length} \le 5000$
- $0 \le \text{prices}[i] \le 1000$

---

## State Machine Formulation

On any day, you are in one of two fundamental ownership states:
- `holding == 0` (You do NOT currently own a stock)
- `holding == 1` (You DO currently own a stock)

### Recurrence Relations:

1. **If `holding == 0`:**
   - **Choice 1 (Buy):** Pay $\text{prices}[i]$, switch state to `holding = 1`, proceed to day $i + 1$:
     $$-\text{prices}[i] + \text{solve}(i + 1, 1)$$
   - **Choice 2 (Rest):** Do nothing, stay in state `holding = 0`, proceed to day $i + 1$:
     $$\text{solve}(i + 1, 0)$$
   $$\text{dp}[i][0] = \max(-\text{prices}[i] + \text{dp}[i + 1][1],\, \text{dp}[i + 1][0])$$

2. **If `holding == 1`:**
   - **Choice 1 (Sell with Cooldown):** Gain $+\text{prices}[i]$, switch state to `holding = 0`, but skip the cooldown day by jumping straight to day **$i + 2$**:
     $$+\text{prices}[i] + \text{solve}(i + 2, 0)$$
   - **Choice 2 (Rest / Hold):** Keep holding, proceed to day $i + 1$:
     $$\text{solve}(i + 1, 1)$$
   $$\text{dp}[i][1] = \max(\text{prices}[i] + \text{dp}[i + 2][0],\, \text{dp}[i + 1][1])$$

3. **Base Case:**
   - If $i \ge N$, no more transactions are possible; return $0$.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Top-Down (Recursion + Memoization)** | $O(N)$ | $O(N)$ |
| **Bottom-Up (2D Tabulation)** | $O(N)$ | $O(N)$ |
| **Space-Optimized Iterative (Three Variables)** | $O(N)$ | $O(1)$ |

