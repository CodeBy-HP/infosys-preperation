# Intersection of Two Sorted Arrays

## Problem Statement

Given two sorted arrays `a` and `b`, return an array containing their **intersection** (the elements present in both arrays).
Each element in the result must be **unique**, and the result should be sorted in **ascending order**.

---

## Examples

### Example 1
- **Input:** `a = [1, 2, 2, 3, 4]`, `b = [2, 2, 4, 6, 7, 8]`
- **Output:** `[2, 4]`

### Example 2
- **Input:** `a = [1, 2, 3]`, `b = [4, 5, 6]`
- **Output:** `[]`

---

## Constraints

- $1 \le n, m \le 10^5$
- $-10^9 \le a[i], b[j] \le 10^9$

---

## Approaches

### Approach 1: Hash Set (Brute Force)
Store elements of `a` in a hash set. Traverse `b`, and if an element exists in the set, add it to a result set.
- **Time Complexity:** $\mathcal{O}(N + M)$
- **Space Complexity:** $\mathcal{O}(N)$ extra hash table memory

### Approach 2: Optimal Two-Pointer Merge
Utilizing the sorted property of both arrays:
1. Initialize $i = 0, j = 0$.
2. While $i < n$ and $j < m$:
   - If `a[i] == b[j]`:
     - If `result.empty() || result.back() != a[i]`, append `a[i]`.
     - Advance both $i++$ and $j++$.
   - Else if `a[i] < b[j]`:
     - Advance $i++$.
   - Else:
     - Advance $j++$.
- **Time Complexity:** $\mathcal{O}(N + M)$
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Hash Set** | $\mathcal{O}(N + M)$ | $\mathcal{O}(N)$ |
| **Two-Pointer Merge** | $\mathcal{O}(N + M)$ | $\mathcal{O}(1)$ auxiliary |

