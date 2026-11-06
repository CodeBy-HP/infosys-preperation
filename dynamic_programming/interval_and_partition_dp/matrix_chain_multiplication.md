# Matrix Chain Multiplication (MCM)

## Problem Overview
Given a sequence of matrices, find the most efficient way to multiply these matrices together.
The problem is not actually to perform the multiplications, but merely to decide in what order to perform the multiplications (parenthesization) so that the **total number of scalar multiplications is minimized**.
The dimensions of the matrices are given in an array `arr` of size $N$, where the $i$-th matrix $A_i$ has dimensions $arr[i-1] \times arr[i]$ for $1 \le i < N$.

---

## Canonical Interval DP Formulation
Let $dp[i][j]$ be the minimum number of scalar multiplications required to compute matrix product $A_i \dots A_j$ ($1 \le i \le j < N$).
- **Base Case:** $dp[i][i] = 0$ (a single matrix requires 0 multiplications).
- **Interval Partitioning Transition:**
  For each possible split point $k \in [i, j-1]$:
  $$dp[i][j] = \min_{i \le k < j} \big(dp[i][k] + dp[k + 1][j] + arr[i - 1] \times arr[k] \times arr[j]\big)$$

---

## Complexity Analysis
- **Tabulation (Interval DP by length $L = 2 \dots N-1$):**
  - **Time Complexity:** $O(N^3)$
  - **Auxiliary Space:** $O(N^2)$

