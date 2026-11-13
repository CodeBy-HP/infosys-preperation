# Frog Jump (Geek Jump / AtCoder Frog 1)

## Problem Statement

There is a frog at the first step of an $N$-step staircase (stair index `0`). The frog wants to reach the $(N-1)$-th stair.

The frog can jump either **1 stair** or **2 stairs** forward at any step. If the frog jumps from stair $i$ to stair $j$, the energy lost in the jump is given by the absolute difference between their heights:
$$\text{Cost} = |height[i] - height[j]|$$

Given an integer array $height$ where $height[i]$ represents the height of the $i$-th stair, determine the **minimum total energy consumed** by the frog to reach the $(N-1)$-th stair from stair $0$.

---

## Examples

### Example 1:
```text
Input: height = [10, 20, 30, 10]
Output: 20
Explanation:
- Jump 1: From stair 0 (height 10) to stair 1 (height 20) -> Energy = |20 - 10| = 10.
- Jump 2: From stair 1 (height 20) to stair 3 (height 10) -> Energy = |10 - 20| = 10.
Total energy consumed = 10 + 10 = 20.
Alternative path 0 -> 2 -> 3 costs |30 - 10| + |10 - 30| = 20 + 20 = 40.
Minimum energy is 20.
```

### Example 2:
```text
Input: height = [10, 50, 10]
Output: 0
Explanation:
- Jump from stair 0 directly to stair 2 (cost = |10 - 10| = 0).
Total energy consumed = 0.
```

### Example 3:
```text
Input: height = [30, 10, 60, 10, 60, 50]
Output: 40
Explanation:
Optimal sequence of stairs: 0 -> 2 -> 4 -> 5:
- 0 to 2: |60 - 30| = 30
- 2 to 4: |60 - 60| = 0
- 4 to 5: |50 - 60| = 10
Total energy = 30 + 0 + 10 = 40.
```

---

## Constraints

- $1 \le N \le 10^5$
- $1 \le height[i] \le 10^4$

---

## Recurrence Formulation & Algorithmic Approaches

Let $dp[i]$ be the minimum energy required to reach stair $i$ starting from stair $0$.

### 1. Transitions
At any step $i$ ($i \ge 2$), the frog can arrive from either:
1. Step $i - 1$: Taking a 1-step jump:
   $$\text{jump1} = dp[i - 1] + |height[i] - height[i - 1]|$$
2. Step $i - 2$: Taking a 2-step jump:
   $$\text{jump2} = dp[i - 2] + |height[i] - height[i - 2]|$$

Therefore:
$$dp[i] = \min(\text{jump1}, \; \text{jump2})$$

### 2. Base Cases
- $dp[0] = 0$ (Start node, zero energy required)
- $dp[1] = |height[1] - height[0]|$ (Only 1 jump possible)

### 3. Space Optimization ($O(1)$ State Rolling)
Notice $dp[i]$ depends solely on the immediately preceding two states: $dp[i - 1]$ (`prev1`) and $dp[i - 2]$ (`prev2`). We can update these two scalars iteratively without holding the entire $O(N)$ table.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Recursive (Brute Force)** | $O(2^N)$ | $O(N)$ recursion call stack |
| **Memoization (Top-Down)** | $O(N)$ | $O(N)$ DP array + $O(N)$ stack |
| **Tabulation (Bottom-Up)** | $O(N)$ | $O(N)$ DP array |
| **Space-Optimized DP** | $O(N)$ | $O(1)$ scalar variables |
