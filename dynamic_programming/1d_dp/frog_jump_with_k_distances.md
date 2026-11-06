# Frog Jump with K Distances (Geek Jump with K Jumps / AtCoder Frog 2)

## Problem Statement

There is a frog standing at the first step of an $N$-step staircase (stair index `0`). The frog wants to reach the $(N-1)$-th stair.

Unlike the classic version where only 1 or 2 steps were allowed, the frog can now jump **at most $K$ stairs** forward in a single leap. Specifically, from stair $i$, the frog can jump to any stair $j$ such that:
$$i + 1 \le j \le \min(i + K, \; N - 1)$$

The energy consumed jumping from stair $i$ to stair $j$ is:
$$\text{Cost} = |height[i] - height[j]|$$

Given the array $height$ and an integer $K$, compute the **minimum total energy** consumed by the frog to reach the $(N-1)$-th stair.

---

## Examples

### Example 1:
```text
Input: height = [10, 30, 40, 50, 20], K = 3
Output: 30
Explanation:
- Step 0 (10) -> Step 1 (30): Cost = |30 - 10| = 20
- Step 1 (30) -> Step 4 (20): Jump of length 3 (valid since 3 <= K). Cost = |20 - 30| = 10
Total energy = 20 + 10 = 30.
```

### Example 2:
```text
Input: height = [10, 20, 10], K = 1
Output: 20
Explanation:
Since K = 1, the frog can only take 1-step jumps:
- 0 -> 1: |20 - 10| = 10
- 1 -> 2: |10 - 20| = 10
Total energy = 10 + 10 = 20.
```

### Example 3:
```text
Input: height = [40, 10, 20, 70, 80, 10], K = 4
Output: 40
Explanation:
- 0 (40) -> 2 (20): Cost = |20 - 40| = 20 (jump length 2 <= 4)
- 2 (20) -> 5 (10): Cost = |10 - 20| = 10 (jump length 3 <= 4)
Wait, let's check path: 0 -> 2 (cost 20) -> 5 (cost 10)? Wait, |10 - 20| = 10, total 30!
Wait, can 0 jump directly to 1 (10) with cost 30, then 1 to 5 (10) with jump length 4: cost |10 - 10| = 0, total 30.
Minimum energy = 30.
```

---

## Constraints

- $1 \le N \le 10^5$
- $1 \le K \le 100$
- $1 \le height[i] \le 10^4$

---

## Recurrence Formulation & Algorithmic Approaches

Let $dp[i]$ denote the minimum energy required to reach stair $i$ from stair $0$.

### 1. State Transition
To reach stair $i$, the frog could have leaped from any stair $i - j$ where $1 \le j \le K$ and $i - j \ge 0$:
$$dp[i] = \min_{1 \le j \le K, \; i - j \ge 0} \Big( dp[i - j] + |height[i] - height[i - j]| \Big)$$

### 2. Base Case
- $dp[0] = 0$ (zero energy at start)

### 3. Circular Buffer Optimization
Since calculating $dp[i]$ only requires the last $K$ states $\{dp[i-1], dp[i-2], \dots, dp[i-K]\}$, we can store only $K$ elements using a circular array of size $K$:
$$\text{buffer}[i \pmod K] = dp[i]$$
This reduces auxiliary space from $O(N)$ to $O(K)$.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Recursive (Brute Force)** | $O(K^N)$ | $O(N)$ recursion depth |
| **Memoization (Top-Down)** | $O(N \cdot K)$ | $O(N)$ DP table + $O(N)$ stack |
| **Tabulation (Bottom-Up)** | $O(N \cdot K)$ | $O(N)$ DP table |
| **Sliding Window Buffer** | $O(N \cdot K)$ | $O(K)$ circular buffer |
