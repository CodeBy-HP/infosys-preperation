# Subset Sum Equals Target (GFG)

## Problem Statement

Given an array of non-negative integers `arr` of size $N$ and an integer $K$ (target), determine whether there exists a subset of the array whose sum equals $K$.

Return `true` if such a subset exists, otherwise return `false`.

---

## Examples

### Example 1:
```text
Input: arr = [3, 34, 4, 12, 5, 2], K = 9
Output: true
Explanation:
There is a subset {4, 5} with sum 9.
```

### Example 2:
```text
Input: arr = [3, 34, 4, 12, 5, 2], K = 30
Output: false
Explanation:
There is no subset whose elements sum to 30.
```

### Example 3:
```text
Input: arr = [1, 2, 7], K = 10
Output: true
Explanation:
1 + 2 + 7 = 10.
```

---

## Constraints

- $1 \le N \le 100$
- $0 \le arr[i] \le 1000$
- $1 \le K \le 10^4$

---

## Recurrence Formulation & Algorithmic Approaches

This is the canonical decision-making model of the **0/1 Knapsack** family.

### 1. State Definition
Let $dp[i][target]$ be a boolean value indicating whether a subset formed from the first $i$ elements `arr[0 ... i - 1]` can achieve a sum of $target$.

### 2. State Transition
For each element `arr[i - 1]` and target sum $s \in [0, K]$:
- **Exclude `arr[i - 1]`:** $dp[i - 1][s]$
- **Include `arr[i - 1]` (if $s \ge arr[i - 1]$):** $dp[i - 1][s - arr[i - 1]]$

$$dp[i][s] = dp[i - 1][s] \; \lor \; (s \ge arr[i - 1] \; ? \; dp[i - 1][s - arr[i - 1]] : \text{false})$$

### 3. Base Cases
- $dp[i][0] = \text{true}$ for all $0 \le i \le N$ (an empty subset always sums to 0).
- $dp[0][s] = \text{false}$ for all $s > 0$ (no positive sum can be achieved with 0 elements).

### 4. 1D In-Place Space Optimization ($O(K)$)
Because row $i$ references only row $i - 1$ at indices $s$ and $s - arr[i - 1]$, iterating $s$ **backwards** from $K$ down to $arr[i - 1]$ allows in-place updates:
```cpp
vector<bool> dp(K + 1, false);
dp[0] = true;
for (int num : arr) {
    for (int s = K; s >= num; --s) {
        if (dp[s - num]) dp[s] = true;
    }
}
return dp[K];
```

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Recursive (Pick / Not Pick)** | $O(2^N)$ | $O(N)$ recursion stack |
| **Tabulation (2D DP)** | $O(N \times K)$ | $O(N \times K)$ |
| **Space-Optimized (1D DP)** | $O(N \times K)$ | $O(K)$ |
