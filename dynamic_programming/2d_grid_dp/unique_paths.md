# Problem 3: Unique Paths

## Problem Statement

There is a robot on an $m \times n$ grid. The robot is initially located at the top-left corner $(0, 0)$ and tries to reach the bottom-right corner $(m - 1, n - 1)$. The robot can only move either **down** or **right** at any point in time.

Given the two integers $m$ and $n$, return the **number of possible unique paths** that the robot can take to reach the bottom-right corner.

---

## Examples

### Example 1
- **Input:** `m = 3, n = 7`
- **Output:** `28`

### Example 2
- **Input:** `m = 3, n = 2`
- **Output:** `3`
- **Explanation:** From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
  1. Right $\rightarrow$ Down $\rightarrow$ Down
  2. Down $\rightarrow$ Down $\rightarrow$ Right
  3. Down $\rightarrow$ Right $\rightarrow$ Down

---

## Constraints

- $1 \le m, n \le 100$
- The answer will be less than or equal to $2 \times 10^9$.

---

## The 2D DP Logic

1. **The State:**
   - $\text{dp}[r][c]$ represents the total number of unique ways to reach cell $(r, c)$.
2. **The Choice (Recurrence Relation):**
   - Because the robot can only move Right or Down, any arrival at cell $(r, c)$ must come from either:
     - Directly above: $(r - 1, c)$
     - Directly left: $(r, c - 1)$
   $$\text{dp}[r][c] = \text{dp}[r - 1][c] + \text{dp}[r][c - 1]$$
3. **Base Cases:**
   - Any cell on the topmost row $(r = 0)$ can only be reached by moving strictly right: $\text{dp}[0][c] = 1$.
   - Any cell on the leftmost column $(c = 0)$ can only be reached by moving strictly down: $\text{dp}[r][0] = 1$.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Top-Down (Recursion + Memoization)** | $O(M \times N)$ | $O(M \times N)$ | $O(M \times N)$ memo table + call stack |
| **Bottom-Up (2D Tabulation)** | $O(M \times N)$ | $O(M \times N)$ | Standard 2D grid DP |
| **Space-Optimized Iterative** | $O(M \times N)$ | $O(N)$ | Rolling 1D array of width $N$ |
| **Combinatorics / Math** | $O(\min(M, N))$ | $O(1)$ | $\binom{(m-1) + (n-1)}{m-1}$ |

