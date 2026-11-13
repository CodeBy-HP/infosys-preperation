# Count Square Submatrices with All Ones (LeetCode 1277)

## Problem Statement

Given a `m x n` binary matrix of ones and zeros, return how many **square submatrices** have all ones.

A square submatrix is defined by its top-left and bottom-right corners and must have equal height and width.

---

## Examples

### Example 1:
```text
Input: matrix = [
  [0, 1, 1, 1],
  [1, 1, 1, 1],
  [0, 1, 1, 1]
]
Output: 15
Explanation: 
There are 10 squares of side length 1.
There are 4 squares of side length 2.
There is 1 square of side length 3.
Total number of squares = 10 + 4 + 1 = 15.
```

### Example 2:
```text
Input: matrix = [
  [1, 0, 1],
  [1, 1, 0],
  [1, 1, 0]
]
Output: 7
Explanation: 
There are 6 squares of side length 1.  
There is 1 square of side length 2. 
Total number of squares = 6 + 1 = 7.
```

---

## Constraints

- `1 <= arr.length <= 300`
- `1 <= arr[0].length <= 300`
- `0 <= arr[i][j] <= 1`

---

## Recurrence Formulation & Algorithmic Approaches

### 1. Key Invariant
Let $dp[i][j]$ denote the **side length of the largest square submatrix whose bottom-right corner is at cell $(i, j)$**.

Crucial property: If the largest all-1 square ending at $(i, j)$ has size $K$, then $(i, j)$ is also the bottom-right corner of squares of size $1, 2, \dots, K$. Therefore, cell $(i, j)$ contributes **exactly $dp[i][j]$ squares** to the total answer!

$$\text{Total Square Submatrices} = \sum_{i=0}^{m-1} \sum_{j=0}^{n-1} dp[i][j]$$

### 2. State Transition
- If `matrix[i][j] == 0`:
  $$dp[i][j] = 0$$
- If `matrix[i][j] == 1`:
  $$dp[i][j] = 1 + \min(dp[i - 1][j], \; dp[i][j - 1], \; dp[i - 1][j - 1])$$
  where boundaries (when $i = 0$ or $j = 0$) default to `matrix[i][j]`.

### 3. Space Optimization ($O(N)$)
Calculating $dp[i][j]$ only requires the current row's previous element $dp[i][j-1]$, the previous row's element $dp[i-1][j]$, and the diagonal top-left element $dp[i-1][j-1]$. We can reduce memory to a 1D array of size $N$ with a single temporary variable `prevDiag`.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Tabulation (2D DP)** | $O(M \times N)$ | $O(M \times N)$ |
| **Space-Optimized (1D DP)** | $O(M \times N)$ | $O(N)$ |
| **In-Place Modification** | $O(M \times N)$ | $O(1)$ (modifies input matrix) |
