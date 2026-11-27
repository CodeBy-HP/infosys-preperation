# 31. Frog Jump with Fatigue (LeetCode 403 & K-Step Energy Fatigue)

## Problem Statement

### Variant A (LeetCode 403 — River Crossing Jump)
A frog is crossing a river divided into units where stones sit at sorted positions `stones[0..n-1]`. Initially on `stones[0]` with `stones[1] == 1`, if the frog's last jump was `k` units, its next jump must be `k - 1`, `k`, or `k + 1` units forward. Determine if the frog can reach the last stone.

### Variant B (Infosys OA — Frog Jump with K Steps & Fatigue)
Given `n` stones with heights `h[0..n-1]`, a frog can jump from stone `i` to `i + 1, i + 2, ..., i + K`.
Each jump from `i` to `j` incurs a **fatigue cost** of `|h[i] - h[j]| + penalty(j - i)` (where basic fatigue has `penalty = 0`, or extra fatigue per jump length). Return the **minimum total fatigue** to reach stone `n - 1`.

---

## Examples

### Example 1 (Variant A — River Crossing)
- **Input:** `stones = [0, 1, 3, 5, 6, 8, 12, 17]`
- **Output:** `true`
- **Explanation:** Jump sizes `1 -> 2 -> 2 -> 3 -> 4 -> 5` reach stone `17`.

### Example 2 (Variant B — K-Step Fatigue)
- **Input:** `h = [10, 30, 40, 50, 20]`, `K = 3`
- **Output:** `30`
- **Explanation:** Jump `0 (10) -> 4 (20)` directly? Wait: `4 - 0 = 4 > K = 3`. Jump `0 (10) -> 1 (30)` (cost 20) $\to$ `4 (20)` (cost 10) $\implies$ total `30`!

---

## Constraints

- Variant A: $2 \le \text{stones.length} \le 2000$, $0 \le \text{stones}[i] \le 2^{31} - 1$.
- Variant B: $1 \le n \le 10^5$, $1 \le K \le 100$.

---

## Pattern Insight

1. **Variant A (LeetCode 403):** Store `unordered_map<int, unordered_set<int>> reach` mapping each stone position to all valid previous jump sizes `k` that can land on it. Check transitions `k-1, k, k+1`.
2. **Variant B (K-Jump Fatigue):** Linear 1D DP:
   $$dp[i] = \min_{1 \le j \le \min(i, K)} \big(dp[i - j] + |h[i] - h[i - j]| + stepFatigue(j)\big)$$

---

## Complexity Analysis

| Variant | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Variant A (LeetCode 403 Map DP)** | $O(N^2)$ | $O(N^2)$ |
| **Variant B (K-Step Fatigue DP)** | $O(N \cdot K)$ | $O(N)$ |
