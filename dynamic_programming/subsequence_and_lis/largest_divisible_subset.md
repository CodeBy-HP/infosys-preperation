# Largest Divisible Subset

## Problem Overview
Given a set of distinct positive integers `nums`, return the largest subset `answer` such that every pair of elements `(answer[i], answer[j])` satisfies:
$$answer[i] \pmod{answer[j]} = 0 \quad \lor \quad answer[j] \pmod{answer[i]} = 0$$
If there are multiple solutions, return any of them.

---

## Sorting & Transitivity Reduction
Divisibility is transitive over ordered positive integers:
$$\text{If } a \mid b \text{ and } b \mid c \implies a \mid c$$
Therefore, if we **sort** the array `nums` in ascending order:
Any new element $nums[i]$ that is divisible by the largest element in an existing valid subset $nums[j]$ is automatically divisible by all smaller elements in that subset!

This transforms the problem directly into an **LIS variant**:
$$dp[i] = 1 + \max_{0 \le j < i, \; nums[i] \pmod{nums[j]} == 0} dp[j]$$
We track `parent[i]` to reconstruct the subset.

---

## Complexity Analysis
- **Time Complexity:** $O(N \log N + N^2) = O(N^2)$
- **Auxiliary Space:** $O(N)$

