# Problem 2: House Robber II (The Circular Street)

## Problem Statement

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a **circle**. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have connected security systems; **if two adjacent houses are broken into on the same night, the police will automatically be alerted**.

Given an integer array `nums` representing the amount of money at each house, return the **maximum amount of money** you can rob tonight without alerting the police.

---

## Examples

### Example 1
- **Input:** `nums = [2, 3, 2]`
- **Output:** `3`
- **Explanation:** You cannot rob house 0 (money = 2) and house 2 (money = 2) because they are adjacent in a circular layout. The best choice is robbing house 1 (money = 3).

### Example 2
- **Input:** `nums = [1, 2, 3, 1]`
- **Output:** `4`
- **Explanation:** Rob house 1 (money = 1) and then rob house 3 (money = 3). Total = $1 + 3 = 4$.

### Example 3
- **Input:** `nums = [1, 2, 3]`
- **Output:** `3`

---

## Constraints

- $1 \le \text{nums.length} \le 100$
- $0 \le \text{nums}[i] \le 1000$

---

## The Paradigm Shift: Breaking the Circle

A circular layout invalidates a naive single-pass DP because house $0$ and house $N-1$ cannot both be robbed.

### The Two Parallel Universes

Since house $0$ and house $N-1$ are mutually exclusive, the optimal robbery belongs to one of two scenarios:
1. **Universe A (Include House $0$, Exclude House $N-1$):**
   - Solve linear House Robber on the subarray `nums[0 ... N - 2]`.
2. **Universe B (Exclude House $0$, Include House $N-1$):**
   - Solve linear House Robber on the subarray `nums[1 ... N - 1]`.

The global optimal answer is:
$$\text{Max Loot} = \max(\text{robLinear}(0, N - 2),\, \text{robLinear}(1, N - 1))$$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Top-Down (Two Memo Passes)** | $O(N)$ | $O(N)$ | Evaluates memoized linear robbery on both slices |
| **Bottom-Up Tabulation** | $O(N)$ | $O(N)$ | Tabulates both slices independently |
| **Space-Optimized Iterative** | $O(N)$ | $O(1)$ | Runs $O(1)$ space linear robbery twice |

