# 23. Combination Sum IV (LeetCode 377)

## Problem Statement

Given an array of **distinct** integers `nums` and a target integer `target`, return the number of possible combinations that add up to `target` (where different sequences count as different combinations — i.e., **permutations**).

The test cases are generated so that the answer fits in a **32-bit** integer (or modulo $10^9 + 7$ in Infosys variants).

---

## Examples

### Example 1
- **Input:** `nums = [1, 2, 3]`, `target = 4`
- **Output:** `7`
- **Explanation:** `(1,1,1,1)`, `(1,1,2)`, `(1,2,1)`, `(1,3)`, `(2,1,1)`, `(2,2)`, `(3,1)`.

### Example 2
- **Input:** `nums = [9]`, `target = 3`
- **Output:** `0`

---

## Constraints

- $1 \le \text{nums.length} \le 200$
- $1 \le \text{nums}[i] \le 1000$
- All elements of `nums` are unique.
- $1 \le \text{target} \le 1000$

---

## Pattern Insight: Outer Loop Sum vs. Inner Loop Coins

To count **ordered sequences** (permutations) rather than unordered combinations:
Iterate `sum` in the **outer loop** (`1 -> target`) and `num` in the **inner loop**:
$$\text{dp}[s] = \sum_{num \in nums,\, num \le s} \text{dp}[s - num]$$
*(Use `unsigned int` or `long long` with overflow clamp because intermediate impossible states in LeetCode 377 might exceed 32-bit signed max before being ignored.)*

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Bottom-Up 1D DP** | $O(\text{target} \cdot N)$ | $O(\text{target})$ |
| **Top-Down Memoization** | $O(\text{target} \cdot N)$ | $O(\text{target})$ |
