# Problem 16: The Traveling Salesperson Problem (TSP with Bitmasking)

## Problem Statement

Given $N$ cities numbered $0$ to $N - 1$ and an $N \times N$ matrix `dist`, where `dist[i][j]` represents the distance to travel from city `i` to city `j`.

Find the **absolute shortest possible route** that starts at city $0$, visits every other city **exactly once**, and returns to the starting city $0$.

---

## Examples

### Example 1
```text
dist = [
  [0, 10, 15, 20],
  [10, 0, 35, 25],
  [15, 35, 0, 30],
  [20, 25, 30, 0]
]
```
- **Output:** `80`
- **Explanation:**
  - Route: $0 \rightarrow 1 \rightarrow 3 \rightarrow 2 \rightarrow 0$
  - Distances: $10 + 25 + 30 + 15 = 80$.

---

## Constraints

- $2 \le N \le 20$
- $0 \le \text{dist}[i][j] \le 10^4$
- $\text{dist}[i][i] = 0$

---

## The Bitmasking Paradigm

Tracking an array of visited cities `[true, false, true]` cannot be directly hashed as a table dimension.
Instead, we compress the visited set into a **binary integer bitmask**:
- Bit $k$ is $1$ if city $k$ has been visited.
- Bit $k$ is $0$ if city $k$ is not yet visited.
- Full completion mask when all $N$ cities are visited: $(1 \ll N) - 1$.

### Recurrence Relations:

1. **State:**
   - $\text{solve}(\text{mask}, \text{pos})$ is the minimum distance to visit all remaining unvisited cities and return to city $0$, having visited the set of cities represented by $\text{mask}$ and currently standing at city $\text{pos}$.
2. **Transition:**
   - For every city $v \in [0, N - 1]$:
     - Check if $v$ is unvisited: `(mask & (1 << v)) == 0`.
     - Travel to $v$, updating the mask to `mask | (1 << v)`:
     $$\text{solve}(\text{mask}, \text{pos}) = \min_{v \text{ unvisited}} \Big( \text{dist}[\text{pos}][v] + \text{solve}(\text{mask} \mid (1 \ll v),\, v) \Big)$$
3. **Base Case:**
   - If $\text{mask} == (1 \ll N) - 1$, all cities have been visited. Return $\text{dist}[\text{pos}][0]$ (the cost to return home to city $0$).

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Top-Down (Recursion + Bitmask Memoization)** | $O(N^2 \cdot 2^N)$ | $O(N \cdot 2^N)$ |
| **Bottom-Up (Iterative Mask Tabulation)** | $O(N^2 \cdot 2^N)$ | $O(N \cdot 2^N)$ |
| **Brute Force Permutations** | $O(N!)$ | $O(N)$ |

