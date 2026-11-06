# Ninja's Training (2D DP)

## Problem Overview
A Ninja plans his $N$-day training schedule. Each day, he can choose one of three activities:
- Activity 0: Running
- Activity 1: Fighting
- Activity 2: Learning

Each activity gives points $points[day][task]$.
The Ninja **cannot perform the same activity on two consecutive days**.
Find the maximum total merit points he can achieve after $N$ days.

---

## Recurrence Formulation
Let $dp[day][last]$ represent the maximum points earned up to $day$ given that on $day+1$ the activity chosen was $last$ (where $last \in \{0, 1, 2, 3\}$, with $3$ meaning "no restriction" on the final day).

For $day = 0$:
$$dp[0][last] = \max_{task \ne last} points[0][task]$$

For $day = 1 \dots N-1$:
$$dp[day][last] = \max_{task \ne last} \big(points[day][task] + dp[day - 1][task]\big)$$

---

## Complexity Analysis
- **Brute Force (Recursion):** $O(3^N)$ Time, $O(N)$ Space.
- **Tabulation (2D DP):** $O(N \times 4 \times 3) = O(N)$ Time, $O(N \times 4)$ Space.
- **Space-Optimized DP:** Since $dp[day]$ only relies on $dp[day-1]$, we only keep a size 4 array.
  - **Time Complexity:** $O(N)$
  - **Auxiliary Space:** $O(1)$

