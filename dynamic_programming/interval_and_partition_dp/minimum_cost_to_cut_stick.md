# Minimum Cost to Cut a Stick

## Problem Overview
Given a wooden stick of length $n$ units. The stick is labelled from $0$ to $n$.
Given an integer array `cuts` where `cuts[i]` denotes a position you should perform a cut at.
You can perform the cuts in any order. The cost of one cut is the length of the stick to be cut.
Return the **minimum total cost** of the cuts.

---

## Boundary Augmentation & Interval DP
Cuts depend on the current boundaries of the stick fragment.
If we sort the cuts and augment the array with the physical endpoints `0` and `n`:
$$\text{augmented\_cuts} = [0, \; c_1, \; c_2, \dots, c_m, \; n]$$
Now, any sub-segment between augmented indices $i$ and $j$ has physical length:
$$\text{cost} = cuts[j] - cuts[i]$$
If we pick index $k \in (i, j)$ as the cut to perform:
$$dp[i][j] = (cuts[j] - cuts[i]) + \min_{i < k < j} \big(dp[i][k] + dp[k][j]\big)$$
- **Base Case:** When $j == i + 1$, there are no internal cuts to make: $dp[i][i + 1] = 0$.

---

## Complexity Analysis
- **Time Complexity:** $O(M^3)$ where $M$ is the number of cuts ($M \le 100$).
- **Auxiliary Space:** $O(M^2)$

