# Cherry Pickup II (LeetCode 1463)

## Problem Statement

You are given a `rows x cols` matrix `grid` representing a field of cherries where `grid[i][j]` represents the number of cherries that you can collect from cell `(i, j)`.

You have two robots that can collect cherries for you:
- **Robot #1** is located at the top-left corner `(0, 0)`.
- **Robot #2** is located at the top-right corner `(0, cols - 1)`.

Return the **maximum number of cherries** you can collect using both robots by following these rules:
1. From a cell `(i, c)`, a robot can move to cell `(i + 1, c - 1)`, `(i + 1, c)`, or `(i + 1, c + 1)`.
2. When any robot passes through a cell, it picks up all cherries, and the cell becomes an empty cell `0`.
3. If both robots stay on the same cell at the same time, only **one** of them takes the cherries.
4. Both robots must reach the bottom row in `grid` (i.e. row `rows - 1`).
5. Both robots cannot move outside of the grid at any moment.

---

## Examples

### Example 1:
```text
Input: grid = [
  [3, 1, 1],
  [2, 5, 1],
  [1, 5, 5],
  [2, 1, 1]
]
Output: 24
Explanation:
Path of robot #1: (0, 0) -> (1, 1) -> (2, 1) -> (3, 0)
Cherries collected by #1: 3 + 5 + 5 + 2 = 15.
Path of robot #2: (0, 2) -> (1, 1) -> (2, 2) -> (3, 2)
Notice at row 1 both land on (1, 1) collecting 5 only once!
Cherries collected by #2: 1 + 0 (shared with #1) + 5 + 1 = 7? Wait, optimal:
Robot #1 takes (0,0)->(1,0)->(2,1)->(3,1): 3 + 2 + 5 + 1 = 11.
Robot #2 takes (0,2)->(1,1)->(2,2)->(3,2): 1 + 5 + 5 + 1 = 12?
Optimal paths collect: 3 + 1 + 5 + 2 + 5 + 5 + 2 + 1 = 24.
```

### Example 2:
```text
Input: grid = [
  [1, 0, 0, 0, 0, 0, 1],
  [2, 0, 0, 0, 0, 3, 0],
  [2, 0, 9, 0, 0, 0, 0],
  [0, 3, 0, 5, 4, 0, 0],
  [1, 0, 2, 3, 0, 0, 6]
]
Output: 28
Explanation:
Robot #1 path: (0,0) -> (1,0) -> (2,0) -> (3,1) -> (4,2): 1 + 2 + 2 + 3 + 2 = 10.
Robot #2 path: (0,6) -> (1,5) -> (2,2) -> (3,3) -> (4,7)? -> 28 total cherries.
```

---

## Constraints

- `rows == grid.length`
- `cols == grid[i].length`
- `2 <= rows, cols <= 70`
- `0 <= grid[i][j] <= 100`

---

## Recurrence Formulation & Algorithmic Approaches

Because both robots advance by exactly $+1$ row per move, their row coordinates are always identical: $row_1 = row_2 = i$. Thus, we only need to track 3 state parameters: $(i, j_1, j_2)$ where $j_1$ is Robot 1's column and $j_2$ is Robot 2's column.

### 1. State Definition
Let $dp[i][j_1][j_2]$ be the maximum cherries collected starting from row $i$ down to row `rows - 1` with Robot 1 at column $j_1$ and Robot 2 at column $j_2$.

### 2. Transition
Each robot has 3 possible moves: $\Delta \in \{-1, 0, 1\}$. There are $3 \times 3 = 9$ joint transitions from row $i$ to $i + 1$:
$$dp[i][j_1][j_2] = \text{cherries}(i, j_1, j_2) + \max_{\Delta_1, \Delta_2 \in \{-1, 0, 1\}} dp[i + 1][j_1 + \Delta_1][j_2 + \Delta_2]$$

where:
$$\text{cherries}(i, j_1, j_2) = \begin{cases} grid[i][j_1] & \text{if } j_1 = j_2 \\ grid[i][j_1] + grid[i][j_2] & \text{if } j_1 \ne j_2 \end{cases}$$

### 3. Base Case
At the bottom row $i = \text{rows} - 1$:
$$dp[\text{rows} - 1][j_1][j_2] = \text{cherries}(\text{rows} - 1, j_1, j_2)$$

### 4. Space Optimization ($O(C^2)$)
Row $i$ depends strictly on row $i + 1$. A 2D buffer of size $C \times C$ (`prev[cols][cols]` and `curr[cols][cols]`) suffices.

---

## Complexity Analysis

| Metric | Tabulation (3D) | Space-Optimized (2D) |
| :--- | :--- | :--- |
| **Time Complexity** | $O(R \cdot C^2 \cdot 9) = O(R \cdot C^2)$ | $O(R \cdot C^2)$ |
| **Auxiliary Space** | $O(R \cdot C^2)$ | $O(C^2)$ |
