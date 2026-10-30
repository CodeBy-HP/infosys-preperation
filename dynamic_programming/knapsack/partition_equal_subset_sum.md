# Problem 9: Partition Equal Subset Sum (0/1 Knapsack)

## Problem Statement

Given an integer array `nums`, return `true` if you can partition the array into two subsets such that the sum of the elements in both subsets is equal, or `false` otherwise.

---

## Examples

### Example 1
- **Input:** `nums = [1, 5, 11, 5]`
- **Output:** `true`
- **Explanation:** The array can be partitioned into $[1, 5, 5]$ and $[11]$, each having sum $11$.

### Example 2
- **Input:** `nums = [1, 2, 3, 5]`
- **Output:** `false`
- **Explanation:** The total sum is $11$, which is odd. An odd sum cannot be divided into two equal integer halves.

---

## Constraints

- $1 \le \text{nums.length} \le 200$
- $1 \le \text{nums}[i] \le 100$

---

## The 0/1 Knapsack Formulation

1. **Parity Check:**
   - If $\sum \text{nums}$ is odd, return `false` immediately.
   - Target sum for each subset is:
     $$\text{Target} = \frac{\sum \text{nums}}{2}$$

2. **The State:**
   - $\text{dp}[i][\text{sum}]$ is boolean: can we form sum $\text{sum}$ using a subset from `nums[0...i]`?

3. **Choice (Pick vs Not Pick):**
   - **Not Pick:** $\text{dp}[i - 1][\text{sum}]$
   - **Pick:** $\text{dp}[i - 1][\text{sum} - \text{nums}[i]]$ (if $\text{sum} \ge \text{nums}[i]$)
   $$\text{dp}[i][\text{sum}] = \text{dp}[i - 1][\text{sum}] \lor \text{dp}[i - 1][\text{sum} - \text{nums}[i]]$$

4. **1D Array Backward Loop Trick:**
   - In 0/1 Knapsack, each item can only be picked at most once.
   - When using a single 1D array `dp[target]`, the inner loop must run **backwards** from `target` down to `num`:
     ```cpp
     for (int j = target; j >= num; j--) {
         dp[j] = dp[j] || dp[j - num];
     }
     ```
   - Running forwards would reuse the same element multiple times, converting the solution to Unbounded Knapsack.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Top-Down (Recursion + Memoization)** | $O(N \times \text{Target})$ | $O(N \times \text{Target})$ |
| **Bottom-Up (2D Tabulation)** | $O(N \times \text{Target})$ | $O(N \times \text{Target})$ |
| **Space-Optimized Iterative** | $O(N \times \text{Target})$ | $O(\text{Target})$ |

