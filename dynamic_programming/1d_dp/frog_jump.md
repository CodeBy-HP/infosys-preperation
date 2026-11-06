# Frog Jump

## Problem Overview
Geek is standing at the 1st stair (0-indexed, index `0`) and wants to reach the $N$-th stair (index $N-1$).
The frog can jump either **1 stair** or **2 stairs** at a time.
The cost of jumping from stair $i$ to stair $j$ is $|height[i] - height[j]|$.
Find the **minimum total energy consumed** to reach the $(N-1)$-th stair.

---

## Recurrence Formulation
Let $dp[i]$ be the minimum energy required to reach stair $i$ from stair $0$.
- **Base Case:**
  - $dp[0] = 0$ (Already at start)
  - $dp[1] = |height[1] - height[0]|$
- **Transition ($i \ge 2$):**
  $$dp[i] = \min(dp[i - 1] + |height[i] - height[i - 1]|, \; dp[i - 2] + |height[i] - height[i - 2]|)$$

---

## Complexity Analysis
- **Brute Force (Recursion):** $O(2^N)$ Time, $O(N)$ Call Stack Space.
- **Tabulation (1D DP):** $O(N)$ Time, $O(N)$ Auxiliary Space.
- **Space-Optimized DP:** Since $dp[i]$ only depends on $dp[i-1]$ and $dp[i-2]$, we can maintain two variables `prev1` and `prev2`.
  - **Time Complexity:** $O(N)$
  - **Auxiliary Space:** $O(1)$

