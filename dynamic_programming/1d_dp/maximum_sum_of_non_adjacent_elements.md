# Maximum Sum of Non-Adjacent Elements (Stickler Thief / House Robber I)

## Problem Statement

Given an array of $N$ integers `nums`, find the **maximum sum of a subsequence** such that **no two elements in the chosen subsequence are adjacent** in the original array.

In other words, you cannot select both `nums[i]` and `nums[i+1]` for any valid index $i$.

---

## Examples

### Example 1:
```text
Input: nums = [2, 1, 4, 9]
Output: 11
Explanation:
Subsequence choices:
- [2, 4] -> sum = 6
- [2, 9] -> sum = 11 (indices 0 and 3 are non-adjacent)
- [1, 9] -> sum = 10
The maximum possible sum is 11.
```

### Example 2:
```text
Input: nums = [1, 2, 3, 1]
Output: 4
Explanation:
Pick nums[0] = 1 and nums[2] = 3.
Total sum = 1 + 3 = 4.
```

### Example 3:
```text
Input: nums = [5, 5, 10, 100, 10, 5]
Output: 110
Explanation:
Pick nums[0] = 5, nums[3] = 100, nums[5] = 5.
Total sum = 5 + 100 + 5 = 110.
```

---

## Constraints

- $1 \le N \le 10^5$
- $0 \le \text{nums}[i] \le 10^4$

---

## Recurrence Formulation & Algorithmic Approaches

Let $dp[i]$ be the maximum sum of non-adjacent elements chosen from the prefix subsegment $\text{nums}[0 \dots i]$.

### 1. Decision Tree at Element $i$
At index $i$, we make a binary choice:
1. **Pick Element $i$:** Because adjacent elements are prohibited, we cannot choose element $i - 1$. We add $\text{nums}[i]$ to the best solution for the prefix ending at $i - 2$:
   $$\text{pick} = \text{nums}[i] + (i \ge 2 \; ? \; dp[i-2] : 0)$$
2. **Do Not Pick Element $i$:** The element $i$ is omitted, so the best sum remains whatever was optimal up to index $i - 1$:
   $$\text{not\_pick} = dp[i-1]$$

### 2. Transition
$$dp[i] = \max(\text{pick}, \; \text{not\_pick}) = \max(\text{nums}[i] + dp[i-2], \; dp[i-1])$$

### 3. Base Cases
- $dp[0] = \text{nums}[0]$
- $dp[1] = \max(\text{nums}[0], \; \text{nums}[1])$

### 4. Space Optimization ($O(1)$)
Notice $dp[i]$ relies only on $dp[i-1]$ (`prev1`) and $dp[i-2]$ (`prev2`). At each step:
$$\text{curr} = \max(\text{prev1}, \; \text{nums}[i] + \text{prev2})$$
$$\text{prev2} = \text{prev1}, \quad \text{prev1} = \text{curr}$$

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Recursive (Pick / Not-Pick)** | $O(2^N)$ | $O(N)$ call stack |
| **Memoization (Top-Down)** | $O(N)$ | $O(N)$ table + $O(N)$ stack |
| **Tabulation (Bottom-Up)** | $O(N)$ | $O(N)$ DP table |
| **Space-Optimized Tabulation** | $O(N)$ | $O(1)$ scalar variables |
