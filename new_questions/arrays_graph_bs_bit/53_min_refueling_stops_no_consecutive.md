# 53. Minimum Number of Refueling Stops with No Consecutive Refuels (LeetCode 871 + Infosys Twist)

## Problem Statement

A car travels from a starting position to a destination which is `target` miles east of the starting position.
Along the way, there are gas stations. Each `stations[i] = [position_i, fuel_i]` indicates a gas station at `position_i` miles east of start with `fuel_i` liters of gas.
The car starts with an infinite tank of gas containing `startFuel` liters initially, burning 1 liter per mile.

- **Variant A (LeetCode 871 — Standard):** Return the minimum number of refueling stops to reach `target`, or `-1`.
- **Variant B (Infosys Twist — No Consecutive Refuels):** You **cannot refuel at two consecutive gas stations** (i.e., if you refuel at station `i`, you must skip station `i + 1`). Return the **minimum number of stops** to reach `target`, or `-1`.

---

## Examples

### Example 1 (Variant A — Standard)
- **Input:** `target = 100`, `startFuel = 10`, `stations = [[10, 60], [20, 30], [30, 30], [60, 40]]`
- **Output:** `2`
- **Explanation:** Stop at `[10, 60]` and `[60, 40]`.

### Example 2 (Variant B — No Consecutive Refuels)
- **Input:** `target = 100`, `startFuel = 10`, `stations = [[10, 60], [20, 30], [30, 30], [60, 40]]`
- **Output:** `2`
- **Explanation:** Indices 0 (`10`) and 3 (`60`) are non-consecutive!

### Example 3 (Variant B — Consecutive Trap)
- **Input:** `target = 25`, `startFuel = 10`, `stations = [[10, 10], [20, 10]]`
- **Output:** `-1`
- **Explanation:** You must refuel at station 0 (`10`) to reach `20`, which forbids refueling at station 1 (`20`), leaving max reach `20 < 25`.

---

## Constraints

- $1 \le \text{target}, \text{startFuel} \le 10^9$
- $0 \le \text{stations.length} \le 500$

---

## Pattern Insight

1. **Standard LeetCode 871 (Max-Heap Greedy):** Push passed station fuels into a max-heap and retroactively refuel from the largest passed station whenever tank runs out: **$O(N \log N)$ time**.
2. **No Consecutive Refuels (2D DP):**
   Because stopping at `i` forbids stopping at `i - 1`, define `dp[k][state]` or `reach[i][k]` = max distance reachable ending with stop `i` using `k` stops:
   - Station `i` can transition from `startFuel` (`k = 1` if `startFuel >= pos[i]`) or from any earlier station `j <= i - 2` where `reach[j][k - 1] >= pos[i]`.
   - Maintain a rolling prefix maximum `bestPref[k]` delayed by 1 station (`bestPrevUpTo[i - 2][k]`) so the entire DP executes in **$O(N^2)$ time**!

---

## Complexity Analysis

| Variant | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Standard (Max-Heap Greedy)** | $O(N \log N)$ | $O(N)$ |
| **No Consecutive Refuels (Delayed Prefix DP)** | $O(N^2)$ | $O(N)$ |
