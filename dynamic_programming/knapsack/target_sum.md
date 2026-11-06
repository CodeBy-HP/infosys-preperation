# Target Sum (LeetCode 494)

## Problem Statement

You are given an integer array `nums` and an integer `target`.

You want to build an expression out of `nums` by adding one of the symbols `'+'` and `'-'` before each integer in `nums` and then concatenate all the integers.

For example, if `nums = [2, 1]`, you can add a `'+'` before `2` and a `'-'` before `1` to concatenate them to build the expression `"+2-1 = 1"`.

Return the **number of different expressions** that you can build, which evaluate to `target`.

---

## Examples

### Example 1:
```text
Input: nums = [1, 1, 1, 1, 1], target = 3
Output: 5
Explanation:
There are 5 ways to assign symbols to reach sum 3:
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
```

### Example 2:
```text
Input: nums = [1], target = 1
Output: 1
```

### Example 3:
```text
Input: nums = [1], target = 2
Output: 0
```

---

## Constraints

- `1 <= nums.length <= 20` (in standard LC, up to 100 in generalized DP)
- `0 <= nums[i] <= 1000`
- `0 <= sum(nums[i]) <= 1000`
- `-1000 <= target <= 1000`

---

## Recurrence Formulation & Algorithmic Approaches

### 1. Mathematical Reduction to Subset Sum
Let $P$ be the set of elements with positive signs `+`, and $N$ be the set of elements with negative signs `-`:
$$sum(P) - sum(N) = \text{target}$$
$$sum(P) + sum(N) = \text{totalSum}$$

Adding these two equations:
$$2 \times sum(P) = \text{totalSum} + \text{target} \implies sum(P) = \frac{\text{totalSum} + \text{target}}{2}$$

Therefore, the problem is **strictly isomorphic to finding the number of subsets in `nums` that sum to $S = \frac{\text{totalSum} + \text{target}}{2}$**.

### 2. Edge Case Invariants
If any of these conditions are violated, return `0`:
1. $|\text{target}| > \text{totalSum}$ (impossible to reach a target larger than the sum of all elements).
2. $(\text{totalSum} + \text{target}) \pmod 2 \ne 0$ (must be a whole integer).

### 3. State Transition & 1D DP
Let $S = (\text{totalSum} + \text{target}) / 2$.
```cpp
vector<int> dp(S + 1, 0);
dp[0] = 1; // 1 way to make sum 0 with an empty subset
for (int num : nums) {
    for (int s = S; s >= num; --s) {
        dp[s] += dp[s - num];
    }
}
return dp[S];
```
Iterating backwards naturally handles zeros and avoids duplicate item reuse.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Top-Down Memoization** | $O(N \times S)$ | $O(N \times S)$ table + $O(N)$ call stack |
| **Bottom-Up 1D DP** | $O(N \times S)$ | $O(S)$ where $S = \frac{\text{totalSum} + \text{target}}{2}$ |
