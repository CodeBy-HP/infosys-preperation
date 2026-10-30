# Magnetic Force Between Two Balls / Aggressive Cows (LeetCode 1552)

## Problem Statement
In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls. Rick has `n` empty baskets, the $i$-th basket is at `position[i]`, Rick wants to distribute `m` balls into the baskets such that the **minimum magnetic force** between any two balls is **maximized**.

The magnetic force between two different balls at positions `x` and `y` is `|x - y|`.

Given the integer array `position` and the integer `m`, return the required maximum minimum magnetic force.

### Example 1:
```
Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls at positions 1, 4 and 7 yields forces |1-4|=3, |4-7|=3, |1-7|=6. Minimum force is 3.
```

### Constraints:
- `n == position.length`
- `2 <= n <= 10^5`
- `1 <= position[i] <= 10^9`
- All integers in `position` are distinct.
- `2 <= m <= position.length`

---

## Pattern Insight: Maximizing the Minimum (Aggressive Cows Paradigm)
- Sort the positions ascending: $pos[0] \le pos[1] \dots \le pos[n-1]$.
- Search range for minimum distance: $d \in [1, pos[n-1] - pos[0]]$.
- Greedy verification: Place the first ball at $pos[0]$. Each subsequent ball is placed at the earliest basket whose position $\ge \text{last\_pos} + d$.
- If we can place $\ge m$ balls: distance $d$ is feasible! Try larger distance (`left = mid + 1`, `ans = mid`).
- Else: distance $d$ is too large, reduce (`right = mid - 1`).

---

## Complexity
- **Time Complexity:** $O(N \log N + N \log(\max - \min))$.
- **Space Complexity:** $O(1)$.
