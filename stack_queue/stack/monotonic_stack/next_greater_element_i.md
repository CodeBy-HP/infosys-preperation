# Problem 1: Next Greater Element I (LeetCode 496)

## Problem Statement

The **next greater element** of some element `x` in an array is the first greater element that is to the right of `x` in the same array.

You are given two distinct 0-indexed integer arrays `nums1` and `nums2`, where `nums1` is a subset of `nums2`.

For each $0 \le i < \text{nums1.length}$, find the index $j$ such that $\text{nums1}[i] == \text{nums2}[j]$ and determine the next greater element of $\text{nums2}[j]$ in `nums2`. If there is no next greater element, then the answer for this query is `-1`.

Return an array `ans` of length `nums1.length` such that `ans[i]` is the next greater element as described above.

---

## Examples

### Example 1
- **Input:** `nums1 = [4, 1, 2], nums2 = [1, 3, 4, 2]`
- **Output:** `[-1, 3, -1]`
- **Explanation:**
  - For 4: no greater element to its right in nums2 -> -1
  - For 1: next greater element is 3
  - For 2: no greater element to its right in nums2 -> -1

---

## Constraints

- $1 \le \text{nums1.length} \le \text{nums2.length} \le 1000$
- $0 \le \text{nums1}[i], \text{nums2}[i] \le 10^4$
- All integers in `nums1` and `nums2` are **unique**.
- All elements in `nums1` appear in `nums2`.

---

## Pattern: Monotonic Decreasing Stack with Hash Map

Traverse `nums2` maintaining a stack of numbers in decreasing order:
1. For each `num` in `nums2`:
   - While `!st.empty() && st.top() < num`:
     - `num` is the **first greater element** for `st.top()`!
     - Record `nextGreater[st.top()] = num; st.pop();`
   - Push `num` to stack.
2. For remaining elements in stack, no greater element exists (default to `-1`).
3. Answer queries for `nums1` in $O(1)$ via the hash map.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Monotonic Stack + Map** | $O(N + M)$ | $O(M)$ where $M = \text{nums2.size()}$ |
