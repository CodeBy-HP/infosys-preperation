# Problem 10: Coin Change (Unbounded Knapsack)

## Problem Statement

You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

Return the **fewest number of coins** that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return `-1`.

You may assume that you have an **infinite number of each kind of coin**.

---

## Examples

### Example 1
- **Input:** `coins = [1, 2, 5], amount = 11`
- **Output:** `3`
- **Explanation:** $11 = 5 + 5 + 1$. Coin `5` was reused twice.

### Example 2
- **Input:** `coins = [2], amount = 3`
- **Output:** `-1`

### Example 3
- **Input:** `coins = [1], amount = 0`
- **Output:** `0`

---

## Constraints

- $1 \le \text{coins.length} \le 12$
- $1 \le \text{coins}[i] \le 2^{31} - 1$
- $0 \le \text{amount} \le 10^4$

---

## The Unbounded Knapsack Logic

1. **State:**
   - $\text{dp}[i][a]$: minimum coins needed to make amount $a$ using coin denominations up to index $i$.
2. **The "Stay-in-Place" Choice:**
   - **Not Pick:** Move to previous coin: $\text{dp}[i - 1][a]$.
   - **Pick:** Stay on the **same coin index $i$** because an infinite supply is available:
     $$1 + \text{dp}[i][a - \text{coins}[i]]$$
   $$\text{dp}[i][a] = \min(\text{dp}[i - 1][a],\, 1 + \text{dp}[i][a - \text{coins}[i]])$$
3. **1D Forward Loop Contrast:**
   - In 0/1 Knapsack, the 1D loop runs backwards to prevent reuse.
   - In Unbounded Knapsack, the 1D loop runs **forwards** precisely to allow infinite reuse!
     ```cpp
     for (int coin : coins) {
         for (int j = coin; j <= amount; j++) {
             dp[j] = min(dp[j], 1 + dp[j - coin]);
         }
     }
     ```

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Top-Down (Recursion + Memoization)** | $O(N \times \text{Amount})$ | $O(N \times \text{Amount})$ |
| **Bottom-Up (2D Tabulation)** | $O(N \times \text{Amount})$ | $O(N \times \text{Amount})$ |
| **Space-Optimized Iterative (1D Array)** | $O(N \times \text{Amount})$ | $O(\text{Amount})$ |

