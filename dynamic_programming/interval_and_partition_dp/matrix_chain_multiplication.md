# Matrix Chain Multiplication (MCM)

## Problem Statement

Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in what order to perform the multiplications (parenthesization) so that the **total number of scalar multiplications is minimized**.

The dimensions of the matrices are given in an array `arr` of size $N$, where the $i$-th matrix $A_i$ has dimensions:
$$\text{Dimension of } A_i = arr[i - 1] \times arr[i] \quad \text{for } 1 \le i < N$$

Two matrices of size $p \times q$ and $q \times r$ can be multiplied together using $p \times q \times r$ scalar multiplications.

Return the **minimum number of scalar multiplications** needed to multiply the chain of $N - 1$ matrices.

---

## Examples

### Example 1:
```text
Input: arr = [40, 20, 30, 10, 30]
Output: 26000
Explanation:
There are 4 matrices:
A1: 40 x 20
A2: 20 x 30
A3: 30 x 10
A4: 10 x 30

Optimal parenthesization: ((A1 x (A2 x A3)) x A4)
1. Multiply A2 and A3: (20 x 30) x (30 x 10) -> 20 x 30 x 10 = 6,000 multiplications (Result is 20 x 10).
2. Multiply A1 and (A2 x A3): (40 x 20) x (20 x 10) -> 40 x 20 x 10 = 8,000 multiplications (Result is 40 x 10).
3. Multiply ((A1 x (A2 x A3))) and A4: (40 x 10) x (10 x 30) -> 40 x 10 x 30 = 12,000 multiplications.
Total scalar multiplications = 6,000 + 8,000 + 12,000 = 26,000.
```

### Example 2:
```text
Input: arr = [10, 20, 30]
Output: 6000
Explanation:
There are 2 matrices: A1 (10 x 20) and A2 (20 x 30).
Only one multiplication needed: 10 x 20 x 30 = 6000.
```

### Example 3:
```text
Input: arr = [10, 30, 5, 60]
Output: 4500
Explanation:
Multiplication order: ((A1 x A2) x A3):
1. A1 x A2: 10 x 30 x 5 = 1,500 operations (result 10 x 5).
2. (A1 x A2) x A3: 10 x 5 x 60 = 3,000 operations.
Total = 1,500 + 3,000 = 4,500.
```

---

## Constraints

- $2 \le N \le 100$ (where $N = \text{arr.length}$)
- $1 \le arr[i] \le 500$

---

## Recurrence Formulation & Algorithmic Approaches

### 1. State Definition
Let $dp[i][j]$ denote the minimum scalar multiplications required to compute the matrix product $A_i \dots A_j$ (where $1 \le i \le j < N$).

### 2. Base Case
When $i == j$, a single matrix requires no multiplication:
$$dp[i][i] = 0$$

### 3. Transition via Split Point $k$
To multiply the chain from $A_i$ to $A_j$, we can split the product at any boundary $k$ ($i \le k < j$):
$$(A_i \dots A_k) \times (A_{k+1} \dots A_j)$$
The cost to combine these two resulting matrices of dimension $(arr[i-1] \times arr[k])$ and $(arr[k] \times arr[j])$ is $arr[i-1] \times arr[k] \times arr[j]$:
$$dp[i][j] = \min_{i \le k < j} \Big( dp[i][k] + dp[k + 1][j] + arr[i - 1] \times arr[k] \times arr[j] \Big)$$

### 4. Tabulation Order
States must be solved in increasing order of chain length $L = j - i + 1$, from $L = 2$ up to $N - 1$.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Top-Down Memoization** | $O(N^3)$ | $O(N^2)$ table + $O(N)$ recursion depth |
| **Bottom-Up Interval DP** | $O(N^3)$ | $O(N^2)$ 2D DP table |
