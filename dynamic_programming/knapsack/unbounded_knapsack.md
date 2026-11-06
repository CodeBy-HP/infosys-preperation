# Unbounded Knapsack (Knapsack with Duplicate Items / GFG)

## Problem Statement

Given $N$ items, each with a given weight `wt[i]` and value `val[i]`, and a knapsack of maximum capacity $W$.

Unlike the 0/1 Knapsack problem, in the **Unbounded Knapsack problem**, you are allowed to take **an unlimited number of copies** of each item.

Find the **maximum total value** that can be put in the knapsack without exceeding capacity $W$.

---

## Examples

### Example 1:
```text
Input: N = 2, W = 3, val = [1, 1], wt = [2, 1]
Output: 3
Explanation:
Pick 3 copies of item 2 (weight = 1, val = 1):
Total weight = 1 + 1 + 1 = 3 <= W.
Total value = 1 + 1 + 1 = 3.
```

### Example 2:
```text
Input: N = 4, W = 8, val = [10, 40, 50, 70], wt = [1, 3, 4, 5]
Output: 110
Explanation:
Pick 2 copies of item 4 (wt = 4, val = 50) and 1 copy of item 2 (wt = 3, val = 40):
Wait:
- 2 copies of item 4: wt = 4 + 4 = 8, val = 50 + 50 = 100.
- Or 1 copy of item 4 (wt 5, val 70) + 1 copy of item 2 (wt 3, val 40): wt = 5 + 3 = 8, val = 70 + 40 = 110.
Maximum value is 110.
```

### Example 3:
```text
Input: N = 3, W = 4, val = [1, 2, 3], wt = [4, 5, 1]
Output: 12
Explanation:
Pick 4 copies of item 3 (wt = 1, val = 3):
Total weight = 4 * 1 = 4.
Total value = 4 * 3 = 12.
```

---

## Constraints

- $1 \le N \le 1000$
- $1 \le W \le 1000$
- $1 \le wt[i] \le 1000$
- $1 \le val[i] \le 10^5$

---

## Recurrence Formulation & Algorithmic Approaches

### 1. State Definition
Let $dp[i][w]$ denote the maximum value obtainable using a subset of the first $i$ items with capacity $w$.

### 2. State Transition
At item $i - 1$:
- **Exclude item $i - 1$:** Move to $i - 1$: $dp[i - 1][w]$.
- **Include item $i - 1$ (if $w \ge wt[i - 1]$):** Add $val[i - 1]$ and **stay at state $i$** (allowing this item to be chosen again):
  $$val[i - 1] + dp[i][w - wt[i - 1]]$$

$$dp[i][w] = \max(dp[i - 1][w], \; (w \ge wt[i - 1] \; ? \; val[i - 1] + dp[i][w - wt[i - 1]] : 0))$$

### 3. Space-Optimized 1D Vector ($O(W)$)
Because an item can be picked repeatedly, the inner loop for capacity $w$ iterates **forward** from $wt[i - 1]$ up to $W$:
```cpp
vector<int> dp(W + 1, 0);
for (int i = 0; i < N; ++i) {
    for (int w = wt[i]; w <= W; ++w) {
        dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
    }
}
```
As $w$ increases, the updated entry $dp[w - wt[i]]$ is immediately available for subsequent choices within the same item iteration.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Tabulation (2D DP)** | $O(N \times W)$ | $O(N \times W)$ |
| **Space-Optimized (1D DP)** | $O(N \times W)$ | $O(W)$ |
