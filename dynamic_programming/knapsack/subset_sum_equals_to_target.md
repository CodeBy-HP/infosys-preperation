# Subset Sum Equals Target

## Problem Overview
Given an array of non-negative integers `arr` and a target value `K`, determine whether there exists a subset of the array whose sum equals `K`. Return `true` if such a subset exists, otherwise return `false`.

---

## Recurrence Formulation
Let $dp[i][target]$ indicate whether a subset of prefix $0 \dots i$ sums to $target$:
- **Not Pick:** $dp[i - 1][target]$
- **Pick:** (if $target \ge arr[i]$) $dp[i - 1][target - arr[i]]$

$$dp[i][target] = dp[i - 1][target] \; \lor \; dp[i - 1][target - arr[i]]$$

- **Base Cases:**
  - $dp[i][0] = \text{true}$ (empty subset always achieves sum 0)
  - For $i = 0$: $dp[0][arr[0]] = \text{true}$ if $arr[0] \le K$.

### Space Optimization Trick
By iterating backwards from $target = K$ down to $arr[i]$, we can compress the 2D table into a single 1D boolean vector of size $K + 1$!

---

## Complexity Analysis
- **Tabulation (2D DP):** $O(N \times K)$ Time, $O(N \times K)$ Space.
- **Space-Optimized (1D DP):**
  - **Time Complexity:** $O(N \times K)$
  - **Auxiliary Space:** $O(K)$

