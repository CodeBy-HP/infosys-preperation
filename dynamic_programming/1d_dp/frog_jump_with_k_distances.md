# Frog Jump with K Distances

## Problem Overview
Geek is at stair $0$ and wants to reach the $(N-1)$-th stair.
In each move, the frog can jump **at most $K$ stairs** forward (i.e. from $i$ to $i+1, i+2, \dots, i+K$).
The energy consumed to jump from stair $i$ to stair $j$ is $|height[i] - height[j]|$.
Find the **minimum total energy** required to reach the last stair.

---

## Recurrence Formulation
Let $dp[i]$ be the minimum energy to reach stair $i$.
- **Base Case:**
  - $dp[0] = 0$
- **Transition ($i \ge 1$):**
  $$dp[i] = \min_{1 \le j \le K, \; i - j \ge 0} \big(dp[i - j] + |height[i] - height[i - j]|\big)$$

---

## Complexity Analysis
- **Brute Force (Recursion):** $O(K^N)$ Time, $O(N)$ Space.
- **Tabulation (1D DP):**
  - **Time Complexity:** $O(N \cdot K)$ since each state looks back at up to $K$ previous stairs.
  - **Auxiliary Space:** $O(N)$ (or $O(K)$ circular sliding buffer).

