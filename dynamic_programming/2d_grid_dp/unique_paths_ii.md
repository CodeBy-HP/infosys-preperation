# Unique Paths II (LeetCode 63)

## Problem Statement

You are given an $m \times n$ integer array `obstacleGrid`. There is a robot initially located at the top-left corner `(0, 0)` that wants to move to the bottom-right corner `(m - 1, n - 1)`.

The robot can only move either **down** or **right** at any point in time.

An obstacle and space are marked as `1` or `0` respectively in `obstacleGrid`. A path that encounters an obstacle is blocked and cannot be traversed.

Return the **number of possible unique paths** the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to $2 \times 10^9$.

---

## Examples

### Example 1:
```text
Input: obstacleGrid = [
  [0, 0, 0],
  [0, 1, 0],
  [0, 0, 0]
]
Output: 2
Explanation: 
There is one obstacle in the middle of the 3x3 grid.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
```

### Example 2:
```text
Input: obstacleGrid = [
  [0, 1],
  [0, 0]
]
Output: 1
Explanation:
The path starting Right is immediately blocked by an obstacle.
Only 1 valid path: Down -> Right.
```

### Example 3:
```text
Input: obstacleGrid = [[1]]
Output: 0
Explanation:
The starting cell itself contains an obstacle, so 0 paths exist.
```

---

## Constraints

- `m == obstacleGrid.length`
- `n == obstacleGrid[i].length`
- `1 <= m, n <= 100`
- `obstacleGrid[i][j]` is `0` or `1`.

---

## Recurrence Formulation & Algorithmic Approaches

### 1. State Definition
Let $dp[i][j]$ denote the total number of unique valid paths from `(0, 0)` to `(i, j)`.

### 2. State Transition
- If `obstacleGrid[i][j] == 1`:
  $$dp[i][j] = 0$$
- If `obstacleGrid[i][j] == 0`:
  $$dp[i][j] = (i > 0 \; ? \; dp[i-1][j] : 0) + (j > 0 \; ? \; dp[i][j-1] : 0)$$

### 3. Base Case
At starting cell `(0, 0)`:
$$dp[0][0] = (\text{obstacleGrid}[0][0] == 0 \; ? \; 1 : 0)$$

### 4. Space Optimization ($O(N)$)
Notice that each row $i$ depends only on the current row's previous cell $dp[j-1]$ (left) and the previous row's cell $dp[j]$ (top).
Using a single 1D vector `dp[n]`:
```cpp
dp[0] = (obstacleGrid[0][0] == 0);
for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
        if (obstacleGrid[i][j] == 1) {
            dp[j] = 0;
        } else if (j > 0) {
            dp[j] += dp[j - 1];
        }
    }
}
```

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Top-Down Memoization** | $O(M \times N)$ | $O(M \times N)$ table + $O(M + N)$ call stack |
| **Tabulation (2D DP)** | $O(M \times N)$ | $O(M \times N)$ |
| **Space-Optimized (1D DP)** | $O(M \times N)$ | $O(N)$ |
