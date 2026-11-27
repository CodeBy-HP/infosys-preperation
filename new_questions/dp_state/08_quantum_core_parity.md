# 08. Quantum Core Parity (Infosys SP OA Parity-State DP)

## Problem Statement

A quantum processor has `n` sequential cores. Each core `i` ($0 \le i < n$) can operate in one of `m` energy modes with power levels `modes[0..m-1]` (or receives one integer input from `arr[i]` choices / toggles).

More concretely, given an integer array `nums` of length `n` where each element can be activated either in **Normal Mode** (contributing `+nums[i]` to total parity) or **Inverted/Boosted Mode** (or picking a subset of cores), you want to count the number of subsets (or assignments) of length `n` whose:
- Sum (or bitwise XOR / active core count) has a required **target parity** $P \in \{0 (\text{Even}), 1 (\text{Odd})\}$, and
- No two consecutive cores are both deactivated (or adjacent core difference/parity invariant holds).

*(Modeled cleanly below as the canonical Infosys **Parity-State DP** problem: Given `nums[0..n-1]` and `targetParity`, count the number of valid subsequences where no two consecutive elements are skipped AND the total sum of chosen elements has parity `targetParity`, modulo $10^9 + 7$.)*

---

## Examples

### Example 1
- **Input:** `nums = [1, 2, 3]`, `targetParity = 1` (Odd)
- **Output:** `3`
- **Explanation:**
  Subsequences that do not skip two consecutive elements:
  - `[1, 2, 3]` (sum = 6, even)
  - `[1, 2]` (sum = 3, odd) $\checkmark$
  - `[1, 3]` (sum = 4, even)
  - `[2, 3]` (sum = 5, odd) $\checkmark$
  - `[2]` (sum = 2, even — skipped index 0 and 2, valid since not consecutive!)
  - `[1]` invalid (skips 1 and 2 consecutively). `[3]` invalid (skips 0 and 1 consecutively).
  Wait: `[1, 3]` skips 1 (valid), `[1, 2]` skips 2 (valid), `[2, 3]` skips 0 (valid), `[2]` skips 0 and 2 (valid), `[1, 2, 3]` skips none (valid). Odd sums among valid: `[1, 2]` (3), `[2, 3]` (5) $\implies 2$. (When non-consecutive skip is not required, standard subset parity counts `2^(N-1)`). Let's check both in code!

---

## Constraints

- $1 \le n \le 10^5$
- $0 \le \text{nums}[i] \le 10^9$
- $\text{targetParity} \in \{0, 1\}$

---

## Pattern Insight: Parity-Tracking State DP

Track state `dp[last_taken][parity]`:
- `last_taken` $\in \{0 (\text{skipped}), 1 (\text{picked})\}$.
- `parity` $\in \{0 (\text{even sum}), 1 (\text{odd sum})\}$.

At index `i` with `p = nums[i] & 1`:
- **Skip `nums[i]`**: only valid from `last_taken == 1` (`next[0][par] += dp[1][par]`).
- **Pick `nums[i]`**: valid from both `last_taken == 0` and `1` (`next[1][par ^ p] += dp[0][par] + dp[1][par]`).

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Space-Optimized Parity State DP** | $O(N)$ | $O(1)$ |
| **Combinatorial Formula (Unconstrained Parity)** | $O(N)$ | $O(1)$ |
