# Second Largest Element in an Array

## Problem Statement

Given an array of integers `nums`, find and return the **second largest unique element** in the array. If no distinct second largest element exists (e.g., all elements are identical, or array size $< 2$), return `-1`.

---

## Examples

### Example 1
- **Input:** `nums = [1, 2, 4, 7, 7, 5]`
- **Output:** `5`
- **Explanation:** Largest is `7`. Second largest distinct element is `5`.

### Example 2
- **Input:** `nums = [10, 10, 10]`
- **Output:** `-1`
- **Explanation:** All elements are identical; no second largest exists.

---

## Constraints

- $1 \le \text{nums.length} \le 10^5$
- $-10^9 \le \text{nums}[i] \le 10^9$

---

## Approaches

### Approach 1: Brute Force (Sorting)
Sort the array in ascending order. Traverse backwards from $N - 2$ down to $0$ until an element strictly smaller than `nums[N - 1]` is encountered.
- **Time Complexity:** $\mathcal{O}(N \log N)$
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary

### Approach 2: Better (Two Passes)
1. Pass 1: Find the maximum element `largest`.
2. Pass 2: Find the maximum element that is strictly less than `largest`.
- **Time Complexity:** $\mathcal{O}(2N)$
- **Space Complexity:** $\mathcal{O}(1)$

### Approach 3: Optimal (Single Pass State Machine)
Maintain two variables: `largest` and `second_largest`.
For each element `x`:
- If `x > largest`:
  - `second_largest = largest`
  - `largest = x`
- Else if `x < largest && x > second_largest`:
  - `second_largest = x`
- **Time Complexity:** $\mathcal{O}(N)$
- **Space Complexity:** $\mathcal{O}(1)$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Brute Force (Sort)** | $\mathcal{O}(N \log N)$ | $\mathcal{O}(1)$ |
| **Better (Two Passes)** | $\mathcal{O}(2N)$ | $\mathcal{O}(1)$ |
| **Optimal (Single Pass)** | $\mathcal{O}(N)$ | $\mathcal{O}(1)$ |

