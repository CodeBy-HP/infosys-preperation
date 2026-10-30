# Problem 7: Continuous Subarray Sum (LeetCode 523)

## Problem Statement

Given an integer array `nums` and an integer `k`, return `true` if `nums` has a **good subarray** or `false` otherwise.

A **good subarray** is defined as:
- its length is **at least two**, and
- the sum of the elements of the subarray is a multiple of `k` (i.e. $\text{sum} = n \times k$ where $n \in \mathbb{Z}$).

---

## Examples

### Example 1
- **Input:** `nums = [23, 2, 4, 6, 7], k = 6`
- **Output:** `true` (`[2, 4]` sums to 6)

### Example 2
- **Input:** `nums = [23, 2, 6, 4, 7], k = 6`
- **Output:** `true` (`[23, 2, 6, 4, 7]` sums to 42 = $7 \times 6$)

### Example 3
- **Input:** `nums = [23, 2, 6, 4, 7], k = 13`
- **Output:** `false`

---

## Constraints

- $1 \le \text{nums.length} \le 10^5$
- $0 \le \text{nums}[i] \le 10^9$
- $1 \le k \le 2^{31} - 1$

---

## Pattern: Remainder Hashing with Earliest Index Tracking

If two prefix sums have the exact same remainder modulo $k$:
$$\text{prefix}[j] \equiv \text{prefix}[i] \pmod k \implies (\text{prefix}[j] - \text{prefix}[i]) \equiv 0 \pmod k$$
To satisfy the length condition ($j - i \ge 2$):
- Store the **earliest seen index** for each remainder in `earliestIndex` hash map.
- Initialize `earliestIndex[0] = -1`.
- If a remainder has been seen before at `earliestIndex[rem]`, check if $i - \text{earliestIndex}[rem] \ge 2$.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Remainder Hashing** | $O(N)$ | $O(\min(N, k))$ |
