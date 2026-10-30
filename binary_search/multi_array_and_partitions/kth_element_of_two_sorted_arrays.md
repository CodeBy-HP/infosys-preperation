# K-th Element of Two Sorted Arrays

## Problem Statement
Given two sorted arrays `arr1` and `arr2` of size `m` and `n` respectively, and an element `k`. The task is to find the element that would be at the $k$-th position of the final sorted array.

### Example 1:
```
Input: arr1 = [2, 3, 6, 7, 9], arr2 = [1, 4, 8, 10], k = 5
Output: 6
Explanation: The final sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.
```

### Constraints:
- `1 <= m, n <= 10^5`
- `1 <= arr1[i], arr2[i] <= 10^6`
- `1 <= k <= m + n`

---

## Pattern Insight: Generalized Partition with Clamped Boundaries
- We want to partition `arr1` and `arr2` such that the combined left side has exactly $k$ elements.
- Ensure `arr1` is shorter: $m \le n$.
- Clamped range for cut $i$ in `arr1`:
  $$i \in [\max(0, k - n), \min(k, m)]$$
  - $i$ cannot exceed $k$ or $m$.
  - If $k > n$, $i$ must be at least $k - n$ (since `arr2` can supply at most $n$ elements).
- Cut in `arr2`: $j = k - i$.
- Invariant:
  - If $L_1 \le R_2$ and $L_2 \le R_1$: the $k$-th element is simply $\max(L_1, L_2)$!
  - If $L_1 > R_2$: `right = i - 1`.
  - Else: `left = i + 1`.

---

## Complexity
- **Time Complexity:** $O(\log(\min(m, n, k)))$.
- **Space Complexity:** $O(1)$.
