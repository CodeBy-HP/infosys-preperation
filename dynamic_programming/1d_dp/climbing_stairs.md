# Climbing Stairs (LeetCode 70)

## Problem Statement
You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?

### Example 1:
```
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
```

### Example 2:
```
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```

### Constraints:
- `1 <= n <= 45`

---

## Pattern Insight: Fibonacci Recurrence & $O(1)$ Space State Roll
- To reach step $i$, you must either:
  1. Arrive from step $i - 1$ by taking a 1-step leap.
  2. Arrive from step $i - 2$ by taking a 2-step leap.
- Recurrence relation:
  $$f(n) = f(n - 1) + f(n - 2)$$
- Base Cases:
  - $f(1) = 1$ (one way: `[1]`)
  - $f(2) = 2$ (two ways: `[1, 1]`, `[2]`)
- **Space Optimization:**
  - Notice that calculating $f(n)$ only requires the previous two terms: $f(n - 1)$ and $f(n - 2)$.
  - We can maintain two variables `prev1` and `prev2` without allocating an array, reducing auxiliary space to $O(1)$.
- **Matrix Exponentiation ($O(\log N)$):**
  $$\begin{pmatrix} f(n) \\ f(n-1) \end{pmatrix} = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix}^{n-1} \begin{pmatrix} f(1) \\ f(0) \end{pmatrix}$$

---

## Complexity
- **Time Complexity:** $O(N)$ linear pass (or $O(\log N)$ with matrix exponentiation).
- **Space Complexity:** $O(1)$ constant space.

