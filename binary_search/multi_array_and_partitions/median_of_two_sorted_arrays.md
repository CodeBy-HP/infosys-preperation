# Median of Two Sorted Arrays (LeetCode 4)

## Problem Statement
Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return the median of the two sorted arrays.

The overall run time complexity should be $O(\log (m+n))$.

### Example 1:
```
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
```

### Example 2:
```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
```

### Constraints:
- `nums1.length == m`
- `nums2.length == n`
- `0 <= m, n <= 1000`
- `1 <= m + n <= 2000`
- `-10^6 <= nums1[i], nums2[i] <= 10^6`

---

## Pattern Insight: Partition Cut Binary Search on the Shorter Array
- Always ensure `nums1` is the shorter array ($m \le n$). If not, swap arguments.
- We want to partition both arrays into left and right halves such that:
  1. $\text{Left size} = \text{Right size} = \frac{m + n + 1}{2}$.
  2. Every element on the left $\le$ every element on the right.
- Binary search for cut index $i \in [0, m]$ in `nums1`:
  $$j = \frac{m + n + 1}{2} - i$$
- Boundary elements:
  - $L_1 = nums1[i-1]$ (or $-\infty$ if $i=0$), $R_1 = nums1[i]$ (or $+\infty$ if $i=m$)
  - $L_2 = nums2[j-1]$ (or $-\infty$ if $j=0$), $R_2 = nums2[j]$ (or $+\infty$ if $j=n$)
- Validation:
  - If $L_1 \le R_2$ and $L_2 \le R_1$: Correct partition!
    - If total length is odd: $\text{median} = \max(L_1, L_2)$.
    - If total length is even: $\text{median} = \frac{\max(L_1, L_2) + \min(R_1, R_2)}{2.0}$.
  - If $L_1 > R_2$: Cut $i$ in `nums1` is too far right $\to$ `right = i - 1`.
  - Else: Cut $i$ in `nums1` is too far left $\to$ `left = i + 1`.

---

## Complexity
- **Time Complexity:** $O(\log(\min(m, n)))$ optimal.
- **Space Complexity:** $O(1)$.
