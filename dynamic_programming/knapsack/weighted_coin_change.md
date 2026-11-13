# Weighted Coin Change Problem

## Problem Statement
You are given an integer array `coins` representing coin denominations and an integer array `weights` where `weights[i]` represents the weight (or cost) of choosing coin `coins[i]`. You are also given an integer `target` representing the total monetary amount to achieve.

You have an **infinite supply** of each coin denomination.

Find the **minimum total accumulated weight** required to form the exact target amount. If that amount of money cannot be made up by any combination of the coins, return `-1`.

### Example 1:
```
Input: coins = [1, 2, 5], weights = [10, 5, 2], target = 11
Output: 7
Explanation:
Combinations to make 11:
- Two 5-cent coins and one 1-cent coin: 2 * 2 + 10 = 14 weight.
- Five 2-cent coins and one 1-cent coin: 5 * 5 + 10 = 35 weight.
- One 5-cent coin and three 2-cent coins: 2 + 3 * 5 = 17 weight.
- But if we pick five 2-cent coins and one 1-cent coin, it's 35.
- What about two 5-cent and one 1-cent? 2 + 2 + 10 = 14.
- If weights were [10, 1, 5], picking five 2-cent coins and one 1-cent is 5*1 + 10 = 15.
Let's see target = 11 with weights [3, 2, 8]:
- Five 2-cent (weight 5 * 2 = 10) + one 1-cent (weight 3) = 13.
- Two 5-cent (weight 2 * 8 = 16) + one 1-cent (weight 3) = 19.
Minimum weight is 13!
```

### Constraints:
- `1 <= coins.length == weights.length <= 100`
- `1 <= coins[i] <= 10^4`
- `1 <= weights[i] <= 10^4`
- `0 <= target <= 10^4`

---

## Pattern Insight: Unbounded Knapsack / Minimum Cost Formulation
- Standard Coin Change minimizes the **count** of coins ($\text{weight} = 1$ for all coins).
- In the **Weighted Coin Change**, each coin has an explicit cost/weight $W_i$.
- Greedy selection (e.g. highest denomination first, or best value-to-weight ratio) fails because discrete coin denominations cannot be partitioned fractionally.
- **Dynamic Programming Recurrence:**
  - Let $dp[v]$ be the minimum weight needed to form value $v$.
  - Base Case: $dp[0] = 0$, all other $dp[v] = \infty$.
  - Transition:
    $$dp[v] = \min_{i} \Big( dp[v - coins[i]] + weights[i] \Big) \quad \text{for all } v \ge coins[i]$$
  - Since each coin can be reused infinitely, iterating $v$ from $1$ up to $target$ naturally supports unbounded coin reuse in 1D space!

---

## Complexity
- **Time Complexity:** $O(N \times \text{target})$ where $N$ is the number of coin types.
- **Space Complexity:** $O(\text{target})$ 1D DP table.

