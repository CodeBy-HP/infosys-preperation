# Problem 12: Burst Balloons (Interval DP / MCM)

## Problem Statement

You are given `n` balloons, indexed from `0` to `n - 1`. Each balloon is painted with a number represented by an array `nums`. You are asked to burst all the balloons.

If you burst the `i`-th balloon, you will get:
$$\text{nums}[i - 1] \times \text{nums}[i] \times \text{nums}[i + 1] \text{ coins}$$

If `i - 1` or `i + 1` goes out of the bounds of the array, then treat it as if there is a balloon with a `1` painted on it.

Return the **maximum coins** you can collect by bursting the balloons wisely.

---

## Examples

### Example 1
- **Input:** `nums = [3, 1, 5, 8]`
- **Output:** `167`
- **Explanation:**
  - Burst 1: coins = $3 \times 1 \times 5 = 15$ (remaining: $[3, 5, 8]$)
  - Burst 5: coins = $3 \times 5 \times 8 = 120$ (remaining: $[3, 8]$)
  - Burst 3: coins = $1 \times 3 \times 8 = 24$ (remaining: $[8]$)
  - Burst 8: coins = $1 \times 8 \times 1 = 8$ (remaining: $[]$)
  - Total = $15 + 120 + 24 + 8 = 167$.

### Example 2
- **Input:** `nums = [1, 5]`
- **Output:** `10`

---

## Constraints

- $n == \text{nums.length}$
- $1 \le n \le 300$
- $0 \le \text{nums}[i] \le 100$

---

## The Paradigm Shift: The "Last Survivor" Trick

Why does thinking forward ("which balloon bursts first?") fail?
- Bursting balloon $i$ causes its left neighbor and right neighbor to become adjacent, coupling the remaining subproblems.

### Thinking Backwards:
Instead of choosing which balloon bursts *first*, choose which balloon $k$ bursts **LAST** in the range $[i, j]$.
- Because $k$ is the last to burst in $[i, j]$, all balloons between $i$ and $k - 1$ and between $k + 1$ and $j$ have already popped.
- Therefore, when $k$ finally pops, its remaining neighbors are strictly $\text{nums}[i - 1]$ and $\text{nums}[j + 1]$!
- The left subproblem $[i, k - 1]$ and right subproblem $[k + 1, j]$ are completely independent!

### The Recurrence:
$$\text{dp}[i][j] = \max_{i \le k \le j} \Big( \text{nums}[i - 1] \times \text{nums}[k] \times \text{nums}[j + 1] + \text{dp}[i][k - 1] + \text{dp}[k + 1][j] \Big)$$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Top-Down (Recursion + Memoization)** | $O(N^3)$ | $O(N^2)$ |
| **Bottom-Up (Interval Tabulation)** | $O(N^3)$ | $O(N^2)$ |

