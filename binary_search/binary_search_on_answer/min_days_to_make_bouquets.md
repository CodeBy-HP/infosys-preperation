# Minimum Number of Days to Make m Bouquets (LeetCode 1482)

## Problem Statement
You are given an integer array `bloomDay`, an integer `m` and an integer `k`.

You want to make `m` bouquets. To make a bouquet, you need to use `k` **adjacent** flowers from the garden.

The garden consists of `n` flowers, the $i$-th flower will bloom in the `bloomDay[i]` and then can be used in **exactly one** bouquet.

Return the minimum number of days you need to wait to be able to make `m` bouquets from the garden. If it is impossible to make `m` bouquets return `-1`.

### Example 1:
```
Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: After day 3, flowers bloom like [x, _, x, _, x]. We can make 3 bouquets with 1 flower each.
```

### Constraints:
- `bloomDay.length == n`
- `1 <= n <= 10^5`
- `1 <= bloomDay[i] <= 10^9`
- `1 <= m <= 10^6`
- `1 <= k <= n`

---

## Pattern Insight: Adjacent Clustering on Day Feasibility
- If $(long long)m \times k > n$, it is mathematically impossible $\to$ return `-1`.
- Search range: $D \in [\min(bloomDay), \max(bloomDay)]$.
- Feasibility check for day $D$:
  - Linear scan counting consecutive flowers with $bloomDay[i] \le D$.
  - When consecutive count reaches $k$: bouquet formed! Increment `bouquets` and reset `consecutive = 0`.
  - If a flower hasn't bloomed yet ($bloomDay[i] > D$), reset `consecutive = 0`.
  - Return `bouquets >= m`.

---

## Complexity
- **Time Complexity:** $O(N \log(\max(bloomDay)))$.
- **Space Complexity:** $O(1)$.
