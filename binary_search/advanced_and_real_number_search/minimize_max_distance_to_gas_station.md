# Minimize Max Distance to Gas Station (LeetCode 774)

## Problem Statement
You are given an integer array `stations` that represents the positions of the gas stations on the x-axis. You are also given an integer `k`.

You should add `k` new gas stations. You can add the stations anywhere on the x-axis, and not necessarily on an integer position.

Let `penalty()` be the maximum distance between adjacent gas stations after adding the `k` new stations.

Find the smallest possible value of `penalty()`. Answers within `10^-6` of the actual answer will be accepted.

### Example 1:
```
Input: stations = [1,2,3,4,5,6,7,8,9,10], k = 9
Output: 0.50000
```

### Constraints:
- `10 <= stations.length <= 2000`
- `0 <= stations[i] <= 10^8`
- `stations` is sorted in strictly increasing order.
- `1 <= k <= 10^6`

---

## Pattern Insight: Real-Number Floating Point Binary Search
- Search range: continuous real numbers $D \in [0, stations.back() - stations.front()]$.
- Precision loop: `while (right - left > 1e-6)` (or fixed 80 iterations).
- For a candidate max distance $D$:
  - Between adjacent stations $i$ and $i+1$, the gap is $g = stations[i+1] - stations[i]$.
  - The number of new stations needed in this gap is $\lfloor g / D \rfloor$.
  - Feasible if $\sum \lfloor g / D \rfloor \le k$.
- If feasible: `right = mid` (try smaller max distance).
- Else: `left = mid`.

---

## Complexity
- **Time Complexity:** $O(N \log((\max - \min) / \epsilon))$ where $\epsilon = 10^{-6}$.
- **Space Complexity:** $O(1)$.
