# Aggressive Cows (SPOJ / GFG)

## Problem Statement

You are given an array `stalls` of $N$ integers representing the coordinates of $N$ stalls on a straight line, and an integer $K$ representing the number of aggressive cows.

You want to assign the $K$ cows to the stalls such that the **minimum distance between any two cows is as large as possible**.

Return the **largest minimum distance**.

---

## Examples

### Example 1
- **Input:** `stalls = [1, 2, 8, 4, 9]`, `K = 3`
- **Output:** `3`
- **Explanation:**
  - Sorted stall coordinates: `[1, 2, 4, 8, 9]`.
  - Place 3 cows at stalls 1, 4, and 8 (or 9).
  - Pairwise distances: $|1-4| = 3$, $|4-8| = 4$, $|1-8| = 7$.
  - Minimum distance is $\min(3, 4, 7) = 3$. This is the maximum achievable minimum distance.

### Example 2
- **Input:** `stalls = [0, 3, 4, 7, 10, 9]`, `K = 4`
- **Output:** `3`
- **Explanation:** Sorted stalls: `[0, 3, 4, 7, 9, 10]`. Place cows at 0, 3, 7, 10 with pairwise minimum distance of 3.

---

## Constraints

- $2 \le N \le 10^5$
- $2 \le K \le N$
- $0 \le \text{stalls}[i] \le 10^9$

---

## Pattern Insight: Maximizing the Minimum Distance

1. **Sort the Stalls:** Sorting allows placing cows greedily in increasing order of positions.
2. **Search Range for Minimum Distance $d$:**
   - **Minimum feasible distance:** $1$.
   - **Maximum possible distance:** $\text{stalls}[N-1] - \text{stalls}[0]$.
3. **Greedy Feasibility Check (`canPlace(stalls, dist, K)`):**
   - Place the first cow at `stalls[0]`.
   - Place each subsequent cow at the earliest stall whose coordinate satisfies:
     $$\text{stalls}[i] - \text{last\_stall} \ge dist$$
   - If total cows placed $\ge K$, then distance $dist$ is valid.
4. **Binary Search Transition:**
   - If feasible: Try larger distance: `left = mid + 1`, `ans = mid`.
   - Else: Distance too large: `right = mid - 1`.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Binary Search on Answer** | $O(N \log N + N \log(\max - \min))$ | $O(1)$ |
| **Linear Distance Probing** | $O(N \log N + N \times (\max - \min))$ | $O(1)$ |

