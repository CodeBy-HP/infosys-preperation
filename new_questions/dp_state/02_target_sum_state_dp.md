# 02. Target Sum (Infosys Sign-Assignment State DP)

## Problem Statement

You are given an integer array `nums` and an integer `target`.

You want to build an **expression** out of `nums` by adding one of the symbols `'+'` and `'-'` before each integer in `nums` and then concatenate all the integers.
- For example, if `nums = [2, 1]`, you can add a `'+'` before `2` and a `'-'` before `1` and concatenate them to build the expression `"+2-1"`.

Return the number of different **expressions** that you can build, which evaluates to `target`.

---

## Examples

### Example 1
- **Input:** `nums = [1, 1, 1, 1, 1]`, `target = 3`
- **Output:** `5`
- **Explanation:** There are 5 ways to assign symbols to make the sum of `nums` be `3`:
  `-1 + 1 + 1 + 1 + 1 = 3`, `+1 - 1 + 1 + 1 + 1 = 3`, ..., `+1 + 1 + 1 + 1 - 1 = 3`.

### Example 2
- **Input:** `nums = [1]`, `target = 1`
- **Output:** `1`

---

## Constraints

- $1 \le \text{nums.length} \le 20$ (up to $1000$ in Infosys OA variant)
- $0 \le \text{nums}[i] \le 1000$
- $0 \le \text{sum(nums)} \le 1000$
- $-1000 \le \text{target} \le 1000$

---

## Pattern Insight: Subset-Difference Reduction to 0/1 Knapsack

Let $P$ be the sum of elements assigned `'+'` and $N$ be the sum of elements assigned `'-'`:
$$P + N = \text{totalSum}, \quad P - N = \text{target} \implies P = \frac{\text{totalSum} + \text{target}}{2}$$
If $|\text{target}| > \text{totalSum}$ or $(\text{totalSum} + \text{target})$ is odd, return `0`.
Otherwise, the problem reduces strictly to counting subsets of `nums` summing to $P$!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **1D Subset-Sum DP** | $O(N \cdot P)$ | $O(P)$ |
| **2D Offset State DP** | $O(N \cdot \text{totalSum})$ | $O(\text{totalSum})$ |
