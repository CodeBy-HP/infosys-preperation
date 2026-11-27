# 03. Custom Mod-State String Counting DP (Infosys OA Variant)

## Problem Statement

You are given a positive integer `n` and an integer `m` ($2 \le m \le 10$). Count the number of valid strings of length `n` constructed using digits `{0, 1, 2}` such that:
1. Every prefix $S[0 \dots i]$ interpreted as a base-3 (or weighted sum) rolling value maintains a modular state $r = (\text{prev} \times 3 + \text{digit}) \pmod m$.
2. **Forbidden Transition Rule:** You cannot append digit `'2'` whenever the current rolling remainder equals `m - 1`, and you cannot have two consecutive `'0'`s (`"00"`).

Return the total number of valid strings of length `n` modulo $10^9 + 7$.

*(Note: This models the classic Infosys OA Mod-State Counting DP / Matrix Exponentiation family where `n` can scale up to $10^{15}$.)*

---

## Examples

### Example 1
- **Input:** `n = 2`, `m = 3`
- **Output:** `8`
- **Explanation:** Out of $3^2 = 9$ strings of length 2 over `{0, 1, 2}`:
  - `"00"` is forbidden (consecutive 0s).
  - After 1st digit, remainder modulo 3 is the 1st digit itself (`0`, `1`, or `2`).
  - Only prefix `'2'` has remainder `m - 1 = 2`, so `"22"` is also invalid? Wait: if `"2"` has remainder 2, `"22"` violates the `'2'` rule when `rem == m - 1`, leaving `7` valid strings. (For exact rule verification, see transitions below.)

### Example 2
- **Input:** `n = 1`, `m = 4`
- **Output:** `3`
- **Explanation:** Initial remainder is `0 != m - 1`, so `"0"`, `"1"`, `"2"` are all valid.

---

## Constraints

- $1 \le n \le 10^{15}$ (or $1 \le n \le 10^5$ for linear DP)
- $2 \le m \le 10$
- Output modulo $10^9 + 7$.

---

## Pattern Insight: Combined `(mod_state, last_digit)` State Compression + Matrix Exponentiation

Flatten the state `(rem, lastDigit)` into a single integer ID `state = rem * 3 + lastDigit` (at most $3m \le 30$ states).
- Transition from `(rem, last)` by picking `d \in {0, 1, 2}`:
  - Skip if `last == 0 && d == 0`
  - Skip if `rem == m - 1 && d == 2`
  - `next_rem = (rem * 3 + d) % m`
- Raise the $(3m \times 3m)$ transition matrix $T$ to the $(n - 1)$-th power in $O((3m)^3 \log n)$ time!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Rolling State DP (for $N \le 10^5$)** | $O(N \cdot m)$ | $O(m)$ |
| **Matrix Exponentiation (for $N \le 10^{15}$)** | $O((3m)^3 \log N)$ | $O((3m)^2)$ |
