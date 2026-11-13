# Partition Set Into 2 Subsets With Min Absolute Sum Difference (GFG / LeetCode 2035)

## Problem Statement

Given an array `arr` of $N$ non-negative integers, partition the array into two subsets $S_1$ and $S_2$ such that the **absolute difference between their sums** $|sum(S_1) - sum(S_2)|$ is minimized.

Return the **minimum possible absolute difference**.

---

## Examples

### Example 1:
```text
Input: arr = [1, 6, 11, 5]
Output: 1
Explanation:
Subset 1 = {1, 5, 6}, sum = 12
Subset 2 = {11}, sum = 11
Absolute difference = |12 - 11| = 1.
```

### Example 2:
```text
Input: arr = [1, 4]
Output: 3
Explanation:
Subset 1 = {1}, sum = 1
Subset 2 = {4}, sum = 4
Difference = |1 - 4| = 3.
```

### Example 3:
```text
Input: arr = [3, 9, 7, 3]
Output: 2
Explanation:
Total sum = 3 + 9 + 7 + 3 = 22.
Subset 1 = {3, 7}, sum = 10.
Subset 2 = {3, 9}, sum = 12.
Difference = |10 - 12| = 2.
```

---

## Constraints

- $1 \le N \le 200$
- $0 \le arr[i] \le 500$
- Total sum $S_{tot} \le 10^5$

---

## Recurrence Formulation & Algorithmic Approaches

### 1. Invariant Formulation
Let total sum of all elements be $S_{tot} = \sum_{i=0}^{N-1} arr[i]$.
If subset $S_1$ has sum $s_1$, then subset $S_2$ must have sum $S_{tot} - s_1$.
The absolute difference is:
$$\Delta = |(S_{tot} - s_1) - s_1| = |S_{tot} - 2 s_1|$$

To minimize $\Delta$, we want $s_1$ to be as close as possible to $S_{tot} / 2$.
Without loss of generality, let $s_1 \le \lfloor S_{tot} / 2 \rfloor$.
Then:
$$\Delta = S_{tot} - 2 s_1$$

### 2. Connection to Subset Sum DP
Find all reachable subset sums in the range $[0, \lfloor S_{tot} / 2 \rfloor]$ using classic 0/1 Knapsack boolean DP:
- $dp[s] = \text{true}$ if a subset with sum $s$ exists.

### 3. Transition & Base Case
- Base Case: $dp[0] = \text{true}$
- For each number $num \in arr$:
  - Iterate backwards from $\lfloor S_{tot} / 2 \rfloor$ down to $num$:
    $$dp[s] = dp[s] \lor dp[s - num]$$

### 4. Answer Extraction
Scan $s$ downwards from $\lfloor S_{tot} / 2 \rfloor$ to $0$. The first $s$ where $dp[s] == \text{true}$ maximizes $s_1$ and thus minimizes $S_{tot} - 2 s_1$:
$$\text{Min Diff} = S_{tot} - 2 \cdot s_1$$

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Tabulation (2D DP)** | $O(N \times S_{tot})$ | $O(N \times S_{tot})$ |
| **Space-Optimized (1D DP)** | $O(N \times S_{tot})$ | $O(S_{tot})$ |
