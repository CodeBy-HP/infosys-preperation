# 54. Pizza With 3n Slices + Tolerance Tokens (LeetCode 1388 + Infosys Twist)

## Problem Statement

There is a pizza with `3n` slices of varying sizes given in a **circular** array `slices`. You need to pick `n` slices (in standard LeetCode 1388, no two chosen slices may be adjacent).

In the **Infosys Tolerance Token Variant**, you are additionally given `K` **tolerance tokens** ($K \ge 0$). Whenever you choose two **circularly adjacent** slices, it consumes **1 tolerance token**.
You may pick `n` slices such that the number of chosen adjacent pairs is at most `K`.

Return the **maximum possible sum** of the sizes of the `n` slices you pick!
*(Setting `K = 0` solves the exact LeetCode 1388 problem.)*

---

## Examples

### Example 1 (`K = 0` — LeetCode 1388)
- **Input:** `slices = [1, 2, 3, 4, 5, 6]`, `K = 0`
- **Output:** `10`
- **Explanation:** Pick `[4, 6]` (non-adjacent) $\implies 10$.

### Example 2 (`K = 1` — With 1 Tolerance Token)
- **Input:** `slices = [1, 2, 3, 4, 5, 6]`, `K = 1`
- **Output:** `11`
- **Explanation:** Use 1 tolerance token to pick adjacent `[5, 6]` $\implies 11$.

---

## Constraints

- $1 \le \text{slices.length} \le 500$, `slices.length = 3n`
- $0 \le K \le n$
- $1 \le \text{slices}[i] \le 1000$

---

## Pattern Insight: Boundary-Fixed Linearization + Tolerance DP

Since `slices` is circular, index `0` and index `m - 1` are adjacent:
Fix whether `slices[0]` is picked (`pickFirst \in {0, 1}`) and compute the linear DP over `1..m-1`:
- Track `dp[cnt][tol][lastPicked]`:
  - Skip `i`: `next[cnt][tol][0] = max(dp[cnt][tol][0], dp[cnt][tol][1])`.
  - Pick `i`:
    - From `lastPicked == 0`: `next[cnt+1][tol][1] = max(..., dp[cnt][tol][0] + slices[i])`.
    - From `lastPicked == 1`: if `tol + 1 <= K`, `next[cnt+1][tol+1][1] = max(..., dp[cnt][tol][1] + slices[i])`.
- At `i = m - 1`, if `pickFirst == 1 && lastPicked == 1`, that wrap-around boundary pair consumes **1 extra tolerance token** (only valid if `tol + 1 <= K`).

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Boundary-Fixed Linear Tolerance DP** | $O(N^2 \cdot K)$ | $O(N \cdot K)$ |
| **Standard LeetCode 1388 (`K = 0`)** | $O(N^2)$ | $O(N)$ |
