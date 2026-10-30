# Koko Eating Bananas (LeetCode 875)

## Problem Statement
Koko loves to eat bananas. There are `n` piles of bananas, the $i$-th pile has `piles[i]` bananas. The guards have gone and will come back in `h` hours.

Koko can decide her bananas-per-hour eating speed of `k`. Each hour, she chooses some pile of bananas and eats `k` bananas from that pile. If the pile has less than `k` bananas, she eats all of them instead and will not eat any more bananas during this hour.

Return the minimum integer `k` such that she can eat all the bananas within `h` hours.

### Example 1:
```
Input: piles = [3,6,7,11], h = 8
Output: 4
```

### Constraints:
- `1 <= piles.length <= 10^4`
- `piles.length <= h <= 10^9`
- `1 <= piles[i] <= 10^9`

---

## Pattern Insight: Monotonic Feasibility Function
- Range for eating speed: $k \in [1, \max(piles)]$.
- **Monotonicity:** As speed $k$ increases, total hours needed monotonically decreases.
- Total hours for speed $k$:
  $$\text{hours}(k) = \sum_{p \in piles} \left\lceil \frac{p}{k} \right\rceil = \sum_{p \in piles} \frac{p + k - 1}{k}$$
- Feasibility check: $\text{hours}(k) \le h$.
- Binary search for the **minimum** feasible speed $k$.

---

## Complexity
- **Time Complexity:** $O(N \log(\max(piles)))$.
- **Space Complexity:** $O(1)$.
