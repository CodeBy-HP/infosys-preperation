# 52. Best Time to Buy and Sell Stock — Dynamic Settlement Delay (Infosys SP OA Exact PYQ)

## Problem Statement

You are given an array `prices` where `prices[i]` is the price of a stock on day `i` ($0 \le i < n$).

Unlike standard stock trading, purchasing a stock on day `i` incurs a **price-dependent settlement delay** before you are permitted to sell that stock:
$$\text{delay}(i) = (\text{prices}[i] \pmod{10}) + 1$$
Specifically, if you buy on day `i`, you can only sell on a day `j` such that $j \ge i + \text{delay}(i)$.

Find the **maximum profit** achievable:
- **Variant A (Single Transaction — Infosys OA):** At most 1 buy and 1 sell.
- **Variant B (Unlimited Transactions with Settlement Delay):** Multiple non-overlapping buy/sell cycles allowed (`next buy >= sellDay + 1`).

---

## Examples

### Example 1 (Variant A — Single Transaction)
- **Input:** `prices = [11, 20, 15, 18]`
- **Output:** `7`
- **Explanation:**
  - Buy day `0` (`price = 11`): `delay = (11 % 10) + 1 = 2` days $\implies$ earliest sell is day `0 + 2 = 2`. Best future price $\ge$ day `2` is `18` (day `3`) $\implies$ profit = $18 - 11 = 7$.
  - Buy day `1` (`price = 20`): `delay = 1` $\implies$ earliest sell day `2`, profit $\le 0$.
  - Maximum profit = `7`.

### Example 2 (Variant B — Unlimited Transactions)
- **Input:** `prices = [1, 5, 2, 8]`
- **Output:** `6`
- **Explanation:** Buy day `2` (`2`), `delay = 3`, earliest sell day `5 >= 4` (cannot sell `8`!). Instead buy day `0` (`1`), `delay = 2`, sell day `3` (`8`) $\implies$ profit = `7`! Wait: buy at `1` (day 0), `delay = 2`, sell at `8` (day 3): `3 >= 0 + 2` $\implies$ profit = `7`!

---

## Constraints

- $1 \le \text{prices.length} \le 10^5$
- $0 \le \text{prices}[i] \le 10^9$

---

## Pattern Insight

1. **Variant A (Single Transaction in $O(N)$ Time):**
   Precompute `suffixMax[k]` = maximum price from day `k` to `n - 1`.
   For each potential buy day `i`, compute `sellIdx = i + (prices[i] % 10) + 1`.
   If `sellIdx < n`: candidate profit = `suffixMax[sellIdx] - prices[i]`.
2. **Variant B (Unlimited Transactions in $O(N)$ Time via Push-DP):**
   Notice `delay(i) <= 10` is bounded by constant `10`, or for general `delay[i]`:
   Compute `dp[i]` backwards (`n - 1 -> 0`):
   - `dp[i]`: max profit starting from day `i` with no stock held (`dp[i] = max(dp[i+1], bestSellAfter[i] - prices[i])`).
   -Wait: when holding a stock bought at `i` (earliest sell `e = i + delay(i)`), selling on day `j >= e` yields `prices[j] + dp[j + 1]`.
   - Maintain a single `suffixBestSell[k] = max_{j >= k} (prices[j] + dp[j + 1])` from right to left!
   Then:
   $$dp[i] = \max\Big(dp[i + 1], \ -prices[i] + \text{suffixBestSell}[i + \text{delay}(i)]\Big)$$
   Runs in strictly **$O(N)$ time and $O(N)$ space**!!

---

## Complexity Analysis

| Variant | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Variant A (Single Transaction + Suffix Max)** | $O(N)$ | $O(N)$ |
| **Variant B (Unlimited Transactions + Suffix Sell Best)** | $O(N)$ | $O(N)$ |
