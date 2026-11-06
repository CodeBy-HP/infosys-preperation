# Left Rotate Array by One

## Problem Statement

Given an integer array `nums` of size $n$, rotate the array to the left by one position in-place.
Each element shifts to the left by one index, and the first element moves to the end of the array.

---

## Examples

### Example 1
- **Input:** `nums = [1, 2, 3, 4, 5]`
- **Output:** `[2, 3, 4, 5, 1]`

### Example 2
- **Input:** `nums = [3]`
- **Output:** `3`

---

## Constraints

- $1 \le \text{nums.length} \le 10^5$
- $-10^9 \le \text{nums}[i] \le 10^9$

---

## Approaches

### Approach 1: Auxiliary Array (Brute Force)
Copy `nums[1 ... n-1]` into indices `0 ... n-2` of a new array, and place `nums[0]` at index `n - 1`.
- **Time Complexity:** $\mathcal{O}(N)$
- **Space Complexity:** $\mathcal{O}(N)$

### Approach 2: Optimal In-Place Shift
1. Store the first element: `temp = nums[0]`.
2. Shift every element from index $1$ to $n - 1$ one step left: `nums[i - 1] = nums[i]`.
3. Set the last element: `nums[n - 1] = temp`.
- **Time Complexity:** $\mathcal{O}(N)$
- **Space Complexity:** $\mathcal{O}(1)$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Auxiliary Array** | $\mathcal{O}(N)$ | $\mathcal{O}(N)$ |
| **In-Place Shift** | $\mathcal{O}(N)$ | $\mathcal{O}(1)$ |

