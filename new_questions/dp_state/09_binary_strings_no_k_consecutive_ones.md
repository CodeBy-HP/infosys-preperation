# 09. Binary Strings Without K Consecutive Ones (Infosys Bitstring DP)

## Problem Statement

Given two positive integers `n` and `k`, count the total number of binary strings of length `n` (consisting only of `'0'` and `'1'`) such that **no `k` consecutive characters are `'1'`** (i.e., `"11...1"` of length `k` does not appear as a substring).

*(Classic $K=2$ case corresponds to standard "Binary Strings without Consecutive 1s".)*

Return the answer modulo $10^9 + 7$.

---

## Examples

### Example 1
- **Input:** `n = 3`, `k = 2`
- **Output:** `5`
- **Explanation:** Valid strings of length 3 without `"11"`: `"000"`, `"001"`, `"010"`, `"100"`, `"101"`.

### Example 2
- **Input:** `n = 3`, `k = 3`
- **Output:** `7`
- **Explanation:** Out of $2^3 = 8$ strings, only `"111"` is invalid.

---

## Constraints

- $1 \le n \le 10^5$
- $2 \le k \le 100$
- Output modulo $10^9 + 7$.

---

## Pattern Insight: Sliding-Sum Linear Recurrence

Let `dp[i]` be the number of valid strings of length `i`:
- A valid string of length `i` must end with `'0'` followed by $0, 1, \dots, k - 1$ trailing `'1'`s.
- Alternatively:
  $$\text{dp}[i] = \sum_{j=1}^{k} \text{dp}[i - j] \quad \text{(for } i \ge k \text{)}$$
  Because you can append `"0"`, `"01"`, `"011"`, ..., `"0" + (k-1)*"1"` to an earlier valid prefix!
Using a rolling prefix sum window of length `k`, each transition takes **$O(1)$ time**, giving **$O(N)$ total time** independent of $K$!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Sliding Window Sum DP** | $O(N)$ | $O(N)$ (or $O(K)$ circular) |
| **2D DP `[len][consecutive_ones]`** | $O(N \cdot K)$ | $O(K)$ |
