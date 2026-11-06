# Union of Two Sorted Arrays

## Problem Statement

Given two sorted arrays `a` and `b` of sizes $n$ and $m$ respectively, return an array containing the **union** of both arrays.
The elements in the union should be **distinct** and sorted in **ascending order**.

---

## Examples

### Example 1
- **Input:** `a = [1, 2, 3, 4, 5]`, `b = [1, 2, 3, 6, 7]`
- **Output:** `[1, 2, 3, 4, 5, 6, 7]`

### Example 2
- **Input:** `a = [2, 2, 3, 4, 5]`, `b = [1, 1, 2, 3, 4]`
- **Output:** `[1, 2, 3, 4, 5]`

---

## Constraints

- $1 \le n, m \le 10^5$
- $-10^9 \le a[i], b[j] \le 10^9$

---

## Approaches

### Approach 1: Set Collection (Brute Force)
Insert all elements from both arrays into a `std::set`. A balanced binary search tree automatically deduplicates and sorts the union.
- **Time Complexity:** $\mathcal{O}((N + M) \log(N + M))$
- **Space Complexity:** $\mathcal{O}(N + M)$

### Approach 2: Optimal Two-Pointer Merge
Take advantage of the fact that both input arrays are **already sorted**:
1. Initialize pointers $i = 0$ and $j = 0$.
2. Maintain a helper function `add(val)` that only appends `val` if the result vector is empty or `result.back() != val`.
3. Compare `a[i]` and `b[j]`:
   - If `a[i] <= b[j]`: append `a[i]` and advance $i++$.
   - Else: append `b[j]` and advance $j++$.
4. Append any remaining elements from array $a$ or array $b$.
- **Time Complexity:** $\mathcal{O}(N + M)$
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space (excluding result)

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **std::set (Brute)** | $\mathcal{O}((N + M) \log(N + M))$ | $\mathcal{O}(N + M)$ |
| **Two-Pointer Merge** | $\mathcal{O}(N + M)$ | $\mathcal{O}(1)$ auxiliary |

