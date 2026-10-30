# Capacity To Ship Packages Within D Days (LeetCode 1011)

## Problem Statement
A conveyor belt has packages that must be shipped from one port to another within `days` days.

The $i$-th package on the conveyor belt has a weight of `weights[i]`. Each day, we load the ship with packages on the conveyor belt (in the order given by `weights`). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within `days` days.

### Example 1:
```
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
```

### Constraints:
- `1 <= days <= weights.length <= 5 * 10^4`
- `1 <= weights[i] <= 500`

---

## Pattern Insight: Search Space Boundaries $[\max, \sum]$
- Lower bound: $left = \max(weights)$ (must be able to carry the heaviest individual package).
- Upper bound: $right = \sum weights$ (carrying all packages in 1 day).
- Feasibility function: Greedy simulation counting days needed for capacity $C$:
  - If cumulative weight exceeds $C$, ship current load and start a new day.
  - Return `daysNeeded <= days`.
- Binary search finds the smallest capacity $C$ that meets the constraint.

---

## Complexity
- **Time Complexity:** $O(N \log(\sum weights))$.
- **Space Complexity:** $O(1)$.
