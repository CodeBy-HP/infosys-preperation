# 22. Last Stone Weight II + Resonance (Infosys SP OA Exact PYQ)

## Problem Statement

You are given an integer array `stones` of length `n` and a positive integer `R` representing the **resonance factor**.

You need to divide all `n` stones in order into two sets, **Set A** and **Set B**, such that each stone belongs to exactly one set.
The effective total power of each set is computed as:
$$\text{Power}(S) = \sum_{i \in S} \text{stones}[i] + \sum_{\substack{0 \le i < n - 1 \\ i \in S \text{ and } (i+1) \in S}} R$$
In other words, whenever two **adjacent** stones (`i` and `i + 1`) are placed into the **same set**, that set gains an additional resonance bonus of `R`.

Find the **minimum possible absolute difference** between the effective total powers of the two sets:
$$\min |\text{Power}(A) - \text{Power}(B)|$$

---

## Examples

### Example 1
- **Input:** `stones = [4, 5, 2]`, `R = 2`
- **Output:** `1`
- **Explanation:**
  - If `A = {4, 5}` (indices 0, 1 adjacent $\implies$ Power = $4 + 5 + 2 = 11$) and `B = {2}` (Power = $2$), diff = $|11 - 2| = 9$.
  - If `A = {4, 2}` (indices 0, 2 not adjacent $\implies$ Power = $4 + 2 = 6$) and `B = {5}` (Power = $5$), diff = $|6 - 5| = 1$.
  - Minimum difference = `1`.

### Example 2
- **Input:** `stones = [3, 3]`, `R = 5`
- **Output:** `0`
- **Explanation:** Put index 0 in `A` and index 1 in `B`. Neither gets resonance, Power(A) = 3, Power(B) = 3, diff = `0`.

---

## Constraints

- $1 \le n \le 100$
- $1 \le \text{stones}[i], R \le 100$

---

## Pattern Insight: Offset Signed-Difference DP with `prevSet` State

Track reachable signed differences $\Delta = \text{Power}(A) - \text{Power}(B)$ with an offset `OFF`:
Let `dp[prevSet][diff + OFF]` be whether balance `diff` is reachable after processing up to `i`, with `stones[i]` placed in `prevSet \in {0 (A), 1 (B)}`.
- Placing `stones[i]` in Set A (`0`):
  - From `prevSet == 0`: `newDiff = diff + stones[i] + R`
  - From `prevSet == 1`: `newDiff = diff + stones[i]`
- Placing `stones[i]` in Set B (`1`):
  - From `prevSet == 0`: `newDiff = diff - stones[i]`
  - From `prevSet == 1`: `newDiff = diff - stones[i] - R`

Answer is $\min |\text{diff}|$ across all reachable states after index `n - 1`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Reachability Balance DP** | $O(N \cdot (\sum stones + N \cdot R))$ | $O(\sum stones + N \cdot R)$ |
| **Meet-in-the-Middle / Backtracking** | $O(2^N)$ | $O(N)$ |
