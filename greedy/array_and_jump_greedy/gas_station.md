# Problem 5: Gas Station (LeetCode 134)

## Problem Statement

There are $n$ gas stations along a circular route, where the amount of gas at the $i$-th station is `gas[i]`.

You have a car with an unlimited gas tank, and it costs `cost[i]` of gas to travel from the $i$-th station to its next $(i + 1)$-th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays `gas` and `cost`, return the **starting gas station's index** if you can travel around the circuit once in the clockwise direction, otherwise return `-1`. If there exists a solution, it is **guaranteed to be unique**.

---

## Examples

### Example 1
- **Input:** `gas = [1, 2, 3, 4, 5], cost = [3, 4, 5, 1, 2]`
- **Output:** `3`
- **Explanation:**
  - Start at station 3 and fill up with 4 unit of gas. Tank = $0 + 4 = 4$.
  - Travel to station 4. Cost = 1. Tank = $4 - 1 + 5 = 8$.
  - Travel to station 0. Cost = 2. Tank = $8 - 2 + 1 = 7$.
  - Travel to station 1. Cost = 3. Tank = $7 - 3 + 2 = 6$.
  - Travel to station 2. Cost = 4. Tank = $6 - 4 + 3 = 5$.
  - Travel back to station 3. Cost = 5. Tank = $5 - 5 = 0$.
  - Successfully returned to station 3!

### Example 2
- **Input:** `gas = [2, 3, 4], cost = [3, 4, 3]`
- **Output:** `-1`
- **Explanation:** Total gas = 9, total cost = 10. You cannot travel around the circuit once because total gas < total cost.

---

## Constraints

- $n == \text{gas.length} == \text{cost.length}$
- $1 \le n \le 10^5$
- $0 \le \text{gas}[i], \text{cost}[i] \le 10^4$

---

## The Greedy Leap & Mathematical Proof

Simulating every start index takes $O(N^2)$ time. Greedy achieves $O(N)$ time with $O(1)$ space using two core deductions:

### Deduction 1: The Global Solvability Condition
$$\sum_{i=0}^{n-1} \text{gas}[i] \ge \sum_{i=0}^{n-1} \text{cost}[i]$$
- If the total amount of gas is strictly less than the total cost, completing the circuit from *any* station is physically impossible. Return `-1`.
- If total gas $\ge$ total cost, **a valid starting station is mathematically guaranteed to exist**.

### Deduction 2: The "Failed Reach" Greedy Leap
Suppose you start at station $A$ with an empty tank, pass some intermediate stations with non-negative tank surplus, but your tank drops below $0$ attempting to travel from station $B$ to $B + 1$.
- **Can any station $K$ between $A$ and $B$ be a valid start?**
- **No!** Because starting at $A$ allowed you to arrive at $K$ with a surplus $\ge 0$. If you failed to pass $B$ even *with* that surplus, you will certainly fail starting at $K$ with an empty tank!
- **The Leap:** Discard all stations from $A$ to $B$. Greedily restart at station $B + 1$ with an empty tank!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Greedy Single-Pass** | $O(N)$ | $O(1)$ | Single pass with greedy leap |
| **Brute-Force Simulation** | $O(N^2)$ | $O(1)$ | Tests each candidate starting point |

