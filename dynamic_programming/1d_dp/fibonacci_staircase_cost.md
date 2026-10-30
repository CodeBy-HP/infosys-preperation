# Fibonacci Staircase Cost

## Problem Statement

A staircase contains $N$ steps numbered from $1$ to $N$. You start from step $1$ and want to reach step $N$.

From any step, you may jump **only by a Fibonacci jump length ahead**. That is, if you are currently at step $i$, you may jump to $i + k$, where $k$ is a Fibonacci number ($1, 2, 3, 5, 8, 13, \dots$) such that $i + k \le N$.

The cost of making a jump of length $k$ is:
$$\text{Cost} = A + B \times k$$

where:
- $A$: fixed activation cost per jump
- $B$: cost per unit step jumped
- $k$: jump length (a Fibonacci number)

Find the **minimum total cost** required to reach step $N$ from step $1$.

---

## Input & Output Format

### Input Format
A single line containing three space-separated integers:
```text
N A B
```

### Output Format
Print a single integer representing the minimum total cost.

---

## Constraints

- $2 \le N \le 2 \times 10^5$ (for DP evaluation) / $N \le 10^9$ (for Zeckendorf Greedy)
- $1 \le A, B \le 10^9$

---

## Algorithmic Insight & Paradigm

Total distance to cover is $D = N - 1$.
Suppose we make $m$ jumps of lengths $k_1, k_2, \dots, k_m$ such that $\sum_{j=1}^m k_j = D$.

The total cost is:
$$\sum_{j=1}^m (A + B \times k_j) = m \times A + B \times \sum_{j=1}^m k_j = m \times A + B \times D$$

Notice that **$B \times D$ is constant** for any valid sequence of jumps that reaches the goal!
Therefore:
$$\text{Minimizing Total Cost} \iff \text{Minimizing the Number of Jumps } m$$

### The Two Approaches:

1. **Dynamic Programming (Unbounded Knapsack style):**
   - State: `dp[dist]` = minimum jumps to cover distance `dist`.
   - Transition: `dp[dist] = 1 + min(dp[dist - fib])` for all Fibonacci numbers `fib <= dist`.
   - Great for smaller $N$ or when jump costs are non-linear.

2. **Zeckendorf's Theorem (Optimal Greedy):**
   - By Zeckendorf's theorem, every positive integer can be uniquely represented as the sum of one or more non-consecutive Fibonacci numbers.
   - Greedily picking the largest Fibonacci number $\le \text{remaining distance}$ guarantees the minimum number of jumps in $O(\log N)$ time and $O(1)$ space!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Recursive + Memoization DP** | $O(N \log N)$ | $O(N)$ |
| **Iterative Tabulation DP** | $O(N \log N)$ | $O(N)$ |
| **Zeckendorf Greedy (Optimal)** | $O(\log N)$ | $O(\log N)$ or $O(1)$ |

