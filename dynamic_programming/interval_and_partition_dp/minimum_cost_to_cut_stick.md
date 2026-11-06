# Minimum Cost to Cut a Stick (LeetCode 1547)

## Problem Statement

Given a wooden stick of length $n$ units. The stick is labelled from $0$ to $n$. For example, a stick of length 6 is labelled as:
```text
0---|---|---|---|---|---6
```

Given an integer array `cuts` where `cuts[i]` denotes a position you should perform a cut at. You should perform the cuts in order of your choice.

The cost of one cut is the **length of the stick to be cut**, which is the distance between the two closest cuts previously made (or the ends of the stick).

Return the **minimum total cost** of all the cuts.

---

## Examples

### Example 1:
```text
Input: n = 7, cuts = [1, 3, 4, 5]
Output: 16
Explanation:
Using cuts order [3, 5, 1, 4]:
1. Cut at 3: Initial stick is length 7 (from 0 to 7) -> Cost = 7. Cuts made at 3 divide stick into [0..3] and [3..7].
2. Cut at 5: Stick from [3..7] has length 4 -> Cost = 4. Divides into [3..5] and [5..7].
3. Cut at 1: Stick from [0..3] has length 3 -> Cost = 3. Divides into [0..1] and [1..3].
4. Cut at 4: Stick from [3..5] has length 2 -> Cost = 2. Divides into [3..4] and [4..5].
Total cost = 7 + 4 + 3 + 2 = 16.
```

### Example 2:
```text
Input: n = 9, cuts = [5, 6, 1, 4, 2]
Output: 22
Explanation:
If we sort cuts and execute optimal partitions, the minimum total cost achieved is 22.
```

---

## Constraints

- `2 <= n <= 10^6`
- `1 <= cuts.length <= 100`
- `1 <= cuts[i] <= n - 1`
- All the integers in `cuts` are distinct.

---

## Recurrence Formulation & Algorithmic Approaches

### 1. Augmentation & Sorting
The difficulty stems from the dynamic lengths of stick fragments. Notice that each stick segment is always bounded by two cut points (or the initial endpoints $0$ and $n$).
If we:
1. Append $0$ and $n$ to `cuts`.
2. Sort the augmented array:
   $$A = [0, \; c_1, \; c_2, \dots, c_m, \; n]$$
Then any sub-stick between index $i$ and index $j$ ($i < j$) has physical length $A[j] - A[i]$.

### 2. State Definition
Let $dp[i][j]$ be the minimum cost to perform all cuts between index $i$ and index $j$ in the sorted array $A$.

### 3. Transition
If we choose index $k$ ($i < k < j$) as the **first cut** inside interval $(i, j)$:
- Cost of cutting at $k$ is $A[j] - A[i]$.
- The remaining sub-sticks are $(i, k)$ and $(k, j)$, which are completely independent!
$$dp[i][j] = (A[j] - A[i]) + \min_{i < k < j} \big( dp[i][k] + dp[k][j] \big)$$

### 4. Base Case
When $j = i + 1$, there are no intermediate cut points between $i$ and $j$:
$$dp[i][i + 1] = 0$$

---

## Complexity Analysis

| Metric | Augmented Interval DP |
| :--- | :--- |
| **Time Complexity** | $O(M^3)$ where $M$ is the number of cuts ($M \le 100$, so $M^3 \approx 10^6$ operations) |
| **Auxiliary Space** | $O(M^2)$ for the 2D DP matrix |
