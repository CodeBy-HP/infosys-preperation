# Triangle (LeetCode 120)

## Problem Statement

Given a `triangle` array, return the **minimum path sum from top to bottom**.

For each step, you may move to an adjacent number of the row below. More formally, if you are at index `j` on the current row `i`, you may move to either:
- index `j` on row `i + 1`, or
- index `j + 1` on row `i + 1`.

---

## Examples

### Example 1:
```text
Input: triangle = [
     [2],
    [3, 4],
   [6, 5, 7],
  [4, 1, 8, 3]
]
Output: 11
Explanation:
The path 2 -> 3 -> 5 -> 1 yields the minimum total:
2 + 3 + 5 + 1 = 11.
```

### Example 2:
```text
Input: triangle = [[-10]]
Output: -10
Explanation:
Only one element exists, so the minimum path sum is -10.
```

---

## Constraints

- `1 <= triangle.length <= 200`
- `triangle[0].length == 1`
- `triangle[i].length == triangle[i - 1].length + 1`
- `-10^4 <= triangle[i][j] <= 10^4`

---

## Recurrence Formulation & Algorithmic Approaches

While a top-down formulation requires boundary checks along the left and right slopes, **bottom-up dynamic programming** starting at the base is uniquely elegant because every state converges without special boundary guards.

### 1. State Definition
Let $dp[i][j]$ represent the minimum path sum from position $(i, j)$ down to any element in the bottom row.

### 2. Transition (Bottom-Up)
Starting from row $N - 2$ down to row $0$:
$$dp[i][j] = triangle[i][j] + \min(dp[i + 1][j], \; dp[i + 1][j + 1])$$

### 3. Base Case
At the bottom row $i = N - 1$:
$$dp[N - 1][j] = triangle[N - 1][j] \quad \text{for } 0 \le j < N$$

### 4. Final Answer
$$dp[0][0]$$

### 5. In-Place / 1D Space Optimization
Notice row $i$ only needs row $i + 1$. We can maintain a single 1D array of size $N$ initialized with the bottom row of `triangle`:
$$\text{dp}[j] = triangle[i][j] + \min(\text{dp}[j], \; \text{dp}[j + 1])$$
Or modify `triangle` directly in-place for $O(1)$ additional space.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Top-Down Memoization** | $O(N^2)$ | $O(N^2)$ table + $O(N)$ recursion stack |
| **Bottom-Up Tabulation (2D)** | $O(N^2)$ | $O(N^2)$ |
| **Space-Optimized (1D Buffer)** | $O(N^2)$ | $O(N)$ |
| **In-Place Tabulation** | $O(N^2)$ | $O(1)$ auxiliary |
