# Merge Two Sorted Arrays Without Extra Space

## Problem Statement

You are given two sorted integer arrays `nums1` and `nums2` of sizes $m$ and $n$ respectively.

There are two classic interview formulations of this problem:

### Formulation 1 (LeetCode 88 - Buffered Merge)
`nums1` has a size of $m + n$, where the first $m$ elements denote the elements that should be merged, and the last $n$ elements are initialized to $0$ as an extra buffer. Merge `nums2` into `nums1` as one sorted array in-place.

### Formulation 2 (Disjoint In-Place Merge / The Gap Method)
`nums1` has size $m$ and `nums2` has size $n$ without any buffer. Modify both arrays in-place such that `nums1` contains the first $m$ smallest elements and `nums2` contains the remaining $n$ largest elements, both sorted.

---

## Examples

### Example 1 (Formulation 1: LeetCode 88)
- **Input:** `nums1 = [1, 2, 3, 0, 0, 0], m = 3`, `nums2 = [2, 5, 6], n = 3`
- **Output:** `nums1 = [1, 2, 2, 3, 5, 6]`

### Example 2 (Formulation 2: Disjoint In-Place Merge)
- **Input:** `a = [1, 4, 8, 10]`, `b = [2, 3, 9]`
- **Output:** `a = [1, 2, 3, 4]`, `b = [8, 9, 10]`

---

## Constraints

- $1 \le m, n \le 10^5$
- $-10^9 \le \text{nums1}[i], \text{nums2}[j] \le 10^9$

---

## Approaches

### Approach 1: Extra Buffer / Sorting (Brute Force)
Copy all elements into an auxiliary array of size $m + n$, sort the combined array, and copy back into the target array(s).
- **Time Complexity:** $\mathcal{O}((M + N) \log(M + N))$
- **Space Complexity:** $\mathcal{O}(M + N)$

### Approach 2: Three Pointers from the Back (Optimal for LeetCode 88)
Because the extra space is located at the **end** of `nums1`, writing from beginning to end would overwrite elements before they are compared.
Instead, write from **back to front**:
1. `p1 = m - 1` (last valid element in `nums1`)
2. `p2 = n - 1` (last element in `nums2`)
3. `p = m + n - 1` (last position in `nums1`)
Compare `nums1[p1]` and `nums2[p2]`. Place the larger element at `nums1[p--]`.
- **Time Complexity:** $\mathcal{O}(M + N)$
- **Space Complexity:** $\mathcal{O}(1)$

### Approach 3: The Gap Method / Shell Sort (Optimal for Disjoint Arrays)
Derived from Knuth's Shell Sort:
1. Initialize $\text{gap} = \lceil (m + n) / 2 \rceil$.
2. Compare and swap elements at distance $\text{gap}$ across both arrays using two pointers:
   - Left pointer in `nums1`, right in `nums1`
   - Left pointer in `nums1`, right in `nums2`
   - Left pointer in `nums2`, right in `nums2`
3. After completing the pass, reduce the gap: $\text{gap} = \lceil \text{gap} / 2 \rceil$. Repeat until $\text{gap} = 0$.
- **Time Complexity:** $\mathcal{O}((M + N) \log(M + N))$
- **Space Complexity:** $\mathcal{O}(1)$ strictly in-place

---

## Complexity Analysis

| Approach | Formulation | Time Complexity | Space Complexity |
| :--- | :--- | :--- | :--- |
| **Three Pointers (Back-to-Front)** | LeetCode 88 | $\mathcal{O}(M + N)$ | $\mathcal{O}(1)$ |
| **The Gap Method** | Disjoint Arrays | $\mathcal{O}((M + N) \log(M + N))$ | $\mathcal{O}(1)$ strictly |

