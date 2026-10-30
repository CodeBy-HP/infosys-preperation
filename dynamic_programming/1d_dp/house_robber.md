# Problem 1: House Robber

## Problem Statement

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. The only constraint stopping you from robbing every house is that adjacent houses have connected security systems; **if two adjacent houses are broken into on the same night, the police will automatically be alerted**.

Given an integer array `nums` representing the amount of money at each house, return the **maximum amount of money** you can rob tonight without alerting the police.

---

## Examples

### Example 1
- **Input:** `nums = [1, 2, 3, 1]`
- **Output:** `4`
- **Explanation:** Rob house 1 (money = 1) and then rob house 3 (money = 3). Total money robbed = $1 + 3 = 4$.

### Example 2
- **Input:** `nums = [2, 7, 9, 3, 1]`
- **Output:** `12`
- **Explanation:** Rob house 1 (money = 2), house 3 (money = 9), and house 5 (money = 1). Total money robbed = $2 + 9 + 1 = 12$.

### Example 3 (Why Greedy Fails)
- **Input:** `nums = [2, 1, 1, 2]`
- **Greedy / Alternating Odd-Even:** Evens give $2 + 1 = 3$, Odds give $1 + 2 = 3$.
- **Optimal Choice:** Pick house 0 and house 3, giving $2 + 2 = 4$. Greedy fails because taking a greedily large amount can block an even larger future sum.

---

## Constraints

- $1 \le \text{nums.length} \le 100$
- $0 \le \text{nums}[i] \le 400$

---

## The 3 Core Pillars of DP

1. **The State:**
   - Top-Down: `solve(i)` represents the maximum loot possible considering houses from index `i` to the end of the street.
   - Bottom-Up: `dp[i]` represents the maximum loot possible from the first `i` houses (prefix `0...i`).

2. **The Choice (Recurrence Relation):**
   At house `i`, you have two mutually exclusive choices:
   - **Choice 1 (Skip House $i$):** Do not rob house $i$. Move to the next house. Total loot is `dp[i - 1]` (or `solve(i + 1)` in top-down).
   - **Choice 2 (Rob House $i$):** Rob house $i$. Because adjacent houses trigger alarms, you cannot rob house $i - 1$. Total loot is `nums[i] + dp[i - 2]` (or `nums[i] + solve(i + 2)`).
   $$\text{dp}[i] = \max(\text{dp}[i - 1],\, \text{dp}[i - 2] + \text{nums}[i])$$

3. **Base Cases:**
   - For an empty street: $0$ loot.
   - For 1 house: $\text{dp}[0] = \text{nums}[0]$.
   - For 2 houses: $\text{dp}[1] = \max(\text{nums}[0], \text{nums}[1])$.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Top-Down (Recursion + Memo)** | $O(N)$ | $O(N)$ | $O(N)$ memo table + $O(N)$ recursion stack depth |
| **Bottom-Up (1D Tabulation)** | $O(N)$ | $O(N)$ | Iterative DP array of size $N$ |
| **Space-Optimized Iterative** | $O(N)$ | $O(1)$ | Uses only two variables (`prev1`, `prev2`) |

