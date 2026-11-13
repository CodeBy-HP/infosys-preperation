# Linear Search

## Problem Statement

Given an array of integers `nums` and an integer `target`, return the **first index** of `target` in the array. If `target` is not present, return `-1`.

---

## Examples

### Example 1
- **Input:** `nums = [2, 3, 4, 10, 40]`, `target = 10`
- **Output:** `3`
- **Explanation:** Element `10` is present at index `3`.

### Example 2
- **Input:** `nums = [1, 2, 3, 4, 5]`, `target = 6`
- **Output:** `-1`
- **Explanation:** Element `6` is not present in the array.

---

## Constraints

- $1 \le \text{nums.length} \le 10^5$
- $-10^9 \le \text{nums}[i], \text{target} \le 10^9$

---

## Approaches

### Approach 1: Standard Linear Traversal
Iterate through the array sequentially from index $0$ to $N - 1$. The moment `nums[i] == target`, immediately return index $i$.

### Approach 2: Sentinel Linear Search
Place the target at the very end of the array (as a sentinel), avoiding the boundary check `i < n` on each iteration of the loop, reducing branch instructions at machine level.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Linear Search** | $\mathcal{O}(N)$ | $\mathcal{O}(1)$ |

