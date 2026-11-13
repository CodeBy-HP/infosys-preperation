# Two Sum (LeetCode 1)

## Problem Statement

Given an array of integers `nums` and an integer `target`, return **indices of the two numbers** such that they add up to `target`.

You may assume that each input would have **exactly one solution**, and you may not use the same element twice. You can return the answer in any order.

---

## Examples

### Example 1
- **Input:** `nums = [2, 7, 11, 15]`, `target = 9`
- **Output:** `[0, 1]`
- **Explanation:** Because `nums[0] + nums[1] == 9`, we return `[0, 1]`.

### Example 2
- **Input:** `nums = [3, 2, 4]`, `target = 6`
- **Output:** `[1, 2]`

### Example 3
- **Input:** `nums = [3, 3]`, `target = 6`
- **Output:** `[0, 1]`

---

## Constraints

- $2 \le \text{nums.length} \le 10^4$
- $-10^9 \le \text{nums}[i] \le 10^9$
- $-10^9 \le \text{target} \le 10^9$
- Only one valid answer exists.

---

## Approaches

### Approach 1: Nested Loops (Brute Force)
Check all possible pairs $(i, j)$ with $0 \le i < j < n$ to see if `nums[i] + nums[j] == target`.
- **Time Complexity:** $\mathcal{O}(N^2)$
- **Space Complexity:** $\mathcal{O}(1)$

### Approach 2: Sorting + Two Pointers (Better)
Store pairs `(nums[i], i)`. Sort them by value, and use convergent two pointers ($L$ at start, $R$ at end).
- **Time Complexity:** $\mathcal{O}(N \log N)$
- **Space Complexity:** $\mathcal{O}(N)$

### Approach 3: One-Pass Hash Map (Optimal)
As we iterate through `nums`:
1. Calculate the required complement: $\text{complement} = \text{target} - \text{nums}[i]$.
2. Check if $\text{complement}$ already exists in the hash map:
   - If yes: return `[map[complement], i]`.
3. Otherwise, insert `map[nums[i]] = i`.
- **Time Complexity:** $\mathcal{O}(N)$ average
- **Space Complexity:** $\mathcal{O}(N)$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Brute Force** | $\mathcal{O}(N^2)$ | $\mathcal{O}(1)$ |
| **Sort + Two Pointers** | $\mathcal{O}(N \log N)$ | $\mathcal{O}(N)$ |
| **One-Pass Hash Map** | $\mathcal{O}(N)$ | $\mathcal{O}(N)$ |

