# Rod Cutting Problem (GFG)

## Problem Statement

Given a rod of length $N$ inches and an array of prices `price` of size $N$, where `price[i]` denotes the price of a piece of length $i + 1$.

Determine the **maximum value obtainable** by cutting up the rod and selling the pieces. You may make any number of cuts (or no cuts at all), and pieces of the same length can be cut and sold repeatedly.

---

## Examples

### Example 1:
```text
Input: price = [1, 5, 8, 9, 10, 17, 17, 20], N = 8
Output: 22
Explanation:
The rod of length 8 can be cut into two pieces of lengths 2 and 6:
Price = price[2 - 1] + price[6 - 1] = price[1] + price[5] = 5 + 17 = 22.
No other combination yields a higher total price.
```

### Example 2:
```text
Input: price = [3, 5, 8, 9, 10, 17, 17, 20], N = 8
Output: 24
Explanation:
Cutting into 8 pieces of length 1:
8 * price[0] = 8 * 3 = 24.
```

### Example 3:
```text
Input: price = [3], N = 1
Output: 3
```

---

## Constraints

- $1 \le N \le 1000$
- $1 \le price[i] \le 10^5$

---

## Recurrence Formulation & Algorithmic Approaches

This problem maps directly to the **Unbounded Knapsack** paradigm:
- Knapsack capacity: $N$ (the total length of the rod).
- Available items: Pieces of lengths $1, 2, 3, \dots, N$.
- Item values: `price[0], price[1], ..., price[N - 1]`.
- Reusability: Any piece length can be cut arbitrarily many times.

### 1. State Definition
Let $dp[l]$ be the maximum revenue obtained from a rod of length $l$ ($0 \le l \le N$).

### 2. Transition
To solve for rod length $l$, consider all possible first cuts of length $cut \in [1, l]$:
$$dp[l] = \max_{1 \le cut \le l} \Big( price[cut - 1] + dp[l - cut] \Big)$$

### 3. Base Case
- $dp[0] = 0$ (a rod of length 0 generates 0 value).

### 4. Space-Optimized Forward Tabulation
We maintain a 1D DP table of size $N + 1$:
```cpp
vector<int> dp(N + 1, 0);
for (int l = 1; l <= N; ++l) {
    for (int cut = 1; cut <= l; ++cut) {
        dp[l] = max(dp[l], price[cut - 1] + dp[l - cut]);
    }
}
```

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Top-Down Memoization** | $O(N^2)$ | $O(N)$ table + $O(N)$ call stack |
| **Bottom-Up Tabulation (1D DP)** | $O(N^2)$ | $O(N)$ |
