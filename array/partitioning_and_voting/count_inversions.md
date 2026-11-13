# Count Inversions in an Array

## Problem Statement

Given an integer array `nums` of size $n$, count the total number of **inversions** in the array.

Two elements `nums[i]` and `nums[j]` form an inversion if:
$$\text{nums}[i] > \text{nums}[j] \quad \text{and} \quad i < j$$

The inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted, the inversion count is $0$.

---

## Examples

### Example 1
- **Input:** `nums = [2, 4, 1, 3, 5]`
- **Output:** `3`
- **Explanation:** The inversions are $(2, 1)$, $(4, 1)$, and $(4, 3)$.

### Example 2
- **Input:** `nums = [5, 4, 3, 2, 1]`
- **Output:** `10`
- **Explanation:** In an array sorted in reverse order, every pair forms an inversion: $\frac{5 \times 4}{2} = 10$.

---

## Constraints

- $1 \le n \le 10^5$
- $-10^9 \le \text{nums}[i] \le 10^9$

---

## Approaches

### Approach 1: Nested Loops (Brute Force)
Check all pairs $(i, j)$ with $i < j$ and increment count if `nums[i] > nums[j]`.
- **Time Complexity:** $\mathcal{O}(N^2)$
- **Space Complexity:** $\mathcal{O}(1)$

### Approach 2: Divide and Conquer (Modified Merge Sort)
In Merge Sort, when merging two sorted halves `left` ($[l, \text{mid}]$) and `right` ($[\text{mid} + 1, r]$):
- If `nums[i] <= nums[j]`: `nums[i]` does not form an inversion with `nums[j]`. Advance $i++$.
- If `nums[i] > nums[j]`:
  Because the left subarray is sorted in ascending order, **every remaining element from index $i$ to $\text{mid}$ is strictly greater than `nums[j]`**!
  $$\text{inversions} += (\text{mid} - i + 1)$$
  Advance $j++$.

This seamlessly counts inversions during the standard sort pass in $\mathcal{O}(N \log N)$ total time.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Brute Force** | $\mathcal{O}(N^2)$ | $\mathcal{O}(1)$ |
| **Modified Merge Sort** | $\mathcal{O}(N \log N)$ | $\mathcal{O}(N)$ |

