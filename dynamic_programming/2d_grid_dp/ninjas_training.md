# Ninja's Training (Geek's Training / 2D Activity DP)

## Problem Statement

Geek (Ninja) plans his training schedule for the next $N$ days. Each day, he can perform one of three activities:
- **Activity 0:** Running
- **Activity 1:** Fighting
- **Activity 2:** Learning

Each activity on day $i$ rewards a certain amount of merit points given by `points[i][0]`, `points[i][1]`, and `points[i][2]`.

However, the ninja has a strict rule: **he cannot perform the same activity on two consecutive days**.

Given the $N \times 3$ matrix `points`, find the **maximum total merit points** the ninja can earn across all $N$ days.

---

## Examples

### Example 1:
```text
Input: points = [
  [1, 2, 5],
  [3, 1, 1],
  [3, 3, 3]
]
Output: 11
Explanation:
- Day 0: Choose Activity 2 (learning) -> points = 5
- Day 1: Choose Activity 0 (running, different from day 0) -> points = 3
- Day 2: Choose Activity 1 (fighting, different from day 1) -> points = 3
Total maximum merit points = 5 + 3 + 3 = 11.
```

### Example 2:
```text
Input: points = [
  [10, 40, 70],
  [20, 50, 80],
  [30, 60, 90]
]
Output: 210
Explanation:
- Day 0: Activity 2 -> 70
- Day 1: Activity 1 -> 50
- Day 2: Activity 2 -> 90
Total = 70 + 50 + 90 = 210.
```

---

## Constraints

- $1 \le N \le 10^5$
- `points.length == N`
- `points[i].length == 3`
- $1 \le points[i][j] \le 100$

---

## Recurrence Formulation & Algorithmic Approaches

### 1. State Definition
Let $dp[day][last]$ represent the maximum points achievable up to day $day$, where $last \in \{0, 1, 2, 3\}$ indicates the activity performed on day $day + 1$.
- Values $0, 1, 2$ represent activities.
- Value $3$ represents the special flag "no previous activity restriction" (used for the final query on day $N - 1$).

### 2. State Transition
For each day from $0$ to $N - 1$:
$$dp[day][last] = \max_{\substack{task \in \{0, 1, 2\} \\ task \ne last}} \Big( points[day][task] + (day > 0 \; ? \; dp[day - 1][task] : 0) \Big)$$

### 3. Base Case
On Day 0 ($day = 0$):
$$dp[0][last] = \max_{\substack{task \in \{0, 1, 2\} \\ task \ne last}} points[0][task]$$

### 4. Space Optimization ($O(1)$)
Notice that computing $dp[day]$ requires only the four values of $dp[day - 1]$. An array of size 4 suffices to store the previous day's best outcomes:
$$\text{prev}[4] \to \text{curr}[4]$$
This eliminates the $O(N \times 4)$ table completely.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Recursive (Brute Force)** | $O(3^N)$ | $O(N)$ stack |
| **Memoization (Top-Down)** | $O(N \times 4 \times 3) = O(N)$ | $O(N \times 4)$ table + $O(N)$ stack |
| **Tabulation (Bottom-Up)** | $O(N \times 4 \times 3) = O(N)$ | $O(N \times 4)$ |
| **Space-Optimized DP** | $O(N)$ | $O(1)$ (constant 4-element buffer) |
