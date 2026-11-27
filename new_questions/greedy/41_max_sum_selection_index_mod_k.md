# 41. Maximum Sum Selection by Index % K (Infosys SP OA Exact PYQ)

## Problem Statement

### Variant A (Residue-Class Exclusive Selection — Infosys Greedy PYQ)
You are given an integer array `nums` of size `n` and a positive integer `k`.
For each remainder class $r \in \{0, 1, \dots, k - 1\}$, you are allowed to pick **at most one** element `nums[i]` such that `i % k == r`.
Return the **maximum possible sum** of selected elements. (Skip negative residue maximums if picking nothing from a class is allowed.)

### Variant B (Trigger Multiplier Subsequence — Infosys State-DP PYQ)
Select a subsequence of elements in order where every $k$-th collected item acts as a trigger, doubling the value of the item immediately collected after it (`k+1`, `2k+1`, ...). Return maximum total earnings.

---

## Examples

### Example 1 (Variant A — Residue Exclusive)
- **Input:** `nums = [4, -1, 7, 2, 9, 3]`, `k = 3`
- **Output:** `18`
- **Explanation:**
  - `i % 3 == 0` (`4, 2`): max is `4`.
  - `i % 3 == 1` (`-1, 9`): max is `9`.
  - `i % 3 == 2` (`7, 3`): max is `7`.
  Wait: $4 + 9 + 7 = 20$!

### Example 2 (Variant B — Trigger Multiplier)
- **Input:** `nums = [10, 20, 30, 40]`, `k = 2`
- **Output:** `130`
- **Explanation:** $10 + 20 + (2 \times 30) + 40 = 130$.

---

## Constraints

- $1 \le n \le 10^5$
- $1 \le k \le 10^5$ (Variant A) / $1 \le k \le 100$ (Variant B)
- $-10^9 \le \text{nums}[i] \le 10^9$

---

## Pattern Insight

1. **Variant A:** Independent optimization across $k$ residue buckets! Track `best[i % k] = max(best[i % k], nums[i])`, then sum all positive `best[r]`. Runs in **$O(N)$ time**.
2. **Variant B:** State machine DP tracking `(picked_count % k, just_triggered)` in **$O(N \cdot k)$ time**.

---

## Complexity Analysis

| Variant | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Variant A (Residue Class Greedy)** | $O(N)$ | $O(\min(N, K))$ |
| **Variant B (Modulo Trigger DP)** | $O(N \cdot K)$ | $O(K)$ |
