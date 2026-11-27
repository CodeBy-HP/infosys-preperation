# 15. Maximum Subarray Sum with One Bitwise NOT (`~`) (Infosys SP OA Variant)

## Problem Statement

Given an integer array `arr` of length `n`, you are allowed to apply the **bitwise NOT operation** (`~x`, which flips all bits in 32-bit signed two's complement representation, i.e., `~x = -x - 1`) to **at most one element** in the array.

Find the **maximum possible sum** of any **non-empty contiguous subarray** after applying at most one bitwise NOT operation.

---

## Examples

### Example 1
- **Input:** `arr = [2, -10, 3]`
- **Output:** `14`
- **Explanation:** Apply `~(-10) = -(-10) - 1 = 9`. The subarray `[2, 9, 3]` has sum $2 + 9 + 3 = 14$.

### Example 2
- **Input:** `arr = [-5, -1, -3]`
- **Output:** `4`
- **Explanation:** Apply `~(-5) = 4`, take single-element subarray `[4]`.

### Example 3
- **Input:** `arr = [4, 5, 6]`
- **Output:** `15`
- **Explanation:** All numbers are positive; applying `~` would make them negative (`~4 = -5`), so use 0 operations: $4 + 5 + 6 = 15$.

---

## Constraints

- $1 \le n \le 10^5$
- $-10^9 \le \text{arr}[i] \le 10^9$

---

## Pattern Insight: State-Machine Kadane with `~x` Transform

Note that in C++/Java signed integers, `~x == -(x) - 1` mathematically! (Use `long long` for accumulation to avoid 32-bit sum overflow).
Track two Kadane states ending at index `i`:
1. `noFlip`: Max sum ending at `i` using **0** NOT operations:
   $$\text{noFlip} = \max(\text{arr}[i], \ \text{noFlip} + \text{arr}[i])$$
2. `oneFlip`: Max sum ending at `i` using **1** NOT operation:
   - Either apply `~` to `arr[i]` (starting fresh or extending `noFlip`):
     $$\max(\sim \text{arr}[i], \ \text{prevNoFlip} + \sim \text{arr}[i])$$
   - Or keep `arr[i]` unchanged while extending a previous `oneFlip` subarray:
     $$\text{oneFlip} + \text{arr}[i]$$

*(Note: If the problem uses unsigned $k$-bit NOT on $B$ bits instead of signed 32-bit `~`, replace `(~x)` with `((1LL << B) - 1) ^ x`.)*

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **State-Machine Kadane DP** | $O(N)$ | $O(1)$ |
| **Prefix + Suffix Kadane Arrays** | $O(N)$ | $O(N)$ |
