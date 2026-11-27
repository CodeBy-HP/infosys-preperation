# 37. Minimum Sum of AP Selection After One Swap (Infosys SP OA Exact PYQ)

## Problem Statement

You are given an integer array `A` of size `N`, and two positive integers `K` and `D` ($1 \le K \le N$, $D \ge 1$).

You must select `K` elements from `A` whose indices form an **arithmetic progression** with common difference `D`:
$$s,\ s + D,\ s + 2D,\ \dots,\ s + (K - 1)D \quad (\text{where } 0 \le s \text{ and } s + (K - 1)D < N)$$

After picking these `K` elements, you are allowed to perform **at most one swap** between any element **inside** your selection and any element **outside** your selection.

Return the **minimum possible sum** of the selected `K` elements.

---

## Examples

### Example 1
- **Input:** `A = [10, 2, 8, 1, 9, 4]`, `K = 3`, `D = 2`
- **Output:** `9`
- **Explanation:**
  - Start `s = 0`: indices `[0, 2, 4]` $\implies$ values `[10, 8, 9]`, sum = `27`, max inside = `10`, min outside (among indices `1, 3, 5`) = `1`. After swap: $27 - 10 + 1 = 18$.
  - Start `s = 1`: indices `[1, 3, 5]` $\implies$ values `[2, 1, 4]`, sum = `7`. Wait: outside values are `[10, 8, 9]`, min outside is `8 > 4` (max inside = `4`), so 0 swaps is better $\implies$ sum = `7`!

### Example 2
- **Input:** `A = [5, 1, 6, 7]`, `K = 2`, `D = 2`
- **Output:** `6`
- **Explanation:**
  - Start `s = 0`: `[5, 6]`, sum 11, max inside 6, min outside 1 $\implies 11 - 6 + 1 = 6$.
  - Start `s = 1`: `[1, 7]`, sum 8, max inside 7, min outside 5 $\implies 8 - 7 + 5 = 6$.

---

## Constraints

- $1 \le K \le N \le 10^5$
- $1 \le D \le N$
- $-10^9 \le A[i] \le 10^9$

---

## Pattern Insight: Residue-Class Sliding Window + Global Multiset

Group indices by their modulo remainder `rem = i % D` ($0 \le rem < D$).
Along each residue chain, every valid AP of length `K` is simply a **contiguous sliding window of size `K`**!
1. Maintain two `std::multiset<int>` structures or a global `outside` multiset alongside the `inside` sliding window of size `K`:
   - `windowSum`: current sum of elements in the AP window.
   - `maxInside`: `*inside.rbegin()`.
   - `minOutside`: `*outside.begin()` (if `outside` is non-empty).
2. At each valid window:
   $$\text{bestForWindow} = \min\big(\text{windowSum}, \ \text{windowSum} - \text{maxInside} + \text{minOutside}\big)$$
Since each element enters and leaves `inside` and `outside` at most once across all residue classes, total runtime is strictly **$O(N \log N)$**!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Residue-Class Sliding Window with Multisets** | $O(N \log N)$ | $O(N)$ |
| **Brute Force Over All Starts** | $O(N^2)$ | $O(1)$ |
