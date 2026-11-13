# Coin Change II (LeetCode 518)

## Problem Statement

You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

Return the **number of combinations** that make up that amount. If that amount of money cannot be made up by any combination of the coins, return `0`.

You may assume that you have an **infinite number of each kind of coin**.

The answer is guaranteed to fit into a signed 32-bit integer.

---

## Examples

### Example 1:
```text
Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation:
There are four distinct combinations to make up 5:
1. 5 = 5
2. 5 = 2 + 2 + 1
3. 5 = 2 + 1 + 1 + 1
4. 5 = 1 + 1 + 1 + 1 + 1
Note that orders do not matter: [2, 2, 1] is the same combination as [1, 2, 2].
```

### Example 2:
```text
Input: amount = 3, coins = [2]
Output: 0
Explanation:
The amount of 3 cannot be made up just with coins of 2.
```

### Example 3:
```text
Input: amount = 10, coins = [10]
Output: 1
Explanation:
Only 1 way: taking one 10-coin.
```

---

## Constraints

- `1 <= coins.length <= 300`
- `1 <= coins[i] <= 5000`
- All the values of `coins` are **unique**.
- `0 <= amount <= 5000`

---

## Recurrence Formulation & Algorithmic Approaches

### 1. Combinations vs. Permutations
To count **combinations** (where order does not matter: `[1, 2]` is identical to `[2, 1]`), we must iterate through the coin denominations in the **outer loop**. By considering each coin once in fixed order, we guarantee no duplicate permutations are counted.

### 2. State Definition
Let $dp[i][a]$ denote the number of ways to form amount $a$ using a subset of the first $i$ coin denominations `coins[0 ... i - 1]`.

### 3. Transition (Unbounded Knapsack)
At coin index $i - 1$, we can either:
1. **Exclude coin $i - 1$:** Use only the previous $i - 1$ coins: $dp[i - 1][a]$
2. **Include coin $i - 1$:** Take at least one coin and stay at the same coin state $i$ to allow reuse: $dp[i][a - \text{coins}[i - 1]]$ (if $a \ge \text{coins}[i - 1]$)

$$dp[i][a] = dp[i - 1][a] + (a \ge \text{coins}[i - 1] \; ? \; dp[i][a - \text{coins}[i - 1]] : 0)$$

### 4. Base Cases
- $dp[i][0] = 1$ for all $0 \le i \le N$ (amount 0 can always be made in exactly 1 way: choosing no coins).
- $dp[0][a] = 0$ for all $a > 0$ (no amount $>0$ can be formed with 0 coins).

### 5. Space Optimization ($O(\text{amount})$)
Since the transition depends on the current row's previous values, we iterate the inner loop **forward** from $\text{coin}$ to $\text{amount}$:
```cpp
vector<uint64_t> dp(amount + 1, 0);
dp[0] = 1;
for (int coin : coins) {
    for (int a = coin; a <= amount; ++a) {
        dp[a] += dp[a - coin];
    }
}
```

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Tabulation (2D DP)** | $O(N \times \text{amount})$ | $O(N \times \text{amount})$ |
| **Space-Optimized (1D DP)** | $O(N \times \text{amount})$ | $O(\text{amount})$ |
