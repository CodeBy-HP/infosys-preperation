# Maximum Sum Circular Subarray (LeetCode 918 / Dual Kadane's Algorithm)

## Problem Statement

Given a circular integer array `nums` of length $n$, return the **maximum possible sum of a non-empty subarray** of `nums`.

A **circular array** means the end of the array connects to the beginning of the array:
- Formally, the next element of `nums[i]` is `nums[(i + 1) % n]`.
- The previous element of `nums[i]` is `nums[(i - 1 + n) % n]`.

A subarray may only include each element of the fixed buffer `nums` **at most once**. Formally, for a subarray $\text{nums}[i], \text{nums}[i + 1], \dots, \text{nums}[j]$, there does not exist $i \le k_1, k_2 \le j$ with $k_1 \pmod n == k_2 \pmod n$.

---

## Examples

### Example 1
- **Input:** `nums = [1, -2, 3, -2]`
- **Output:** `3`
- **Explanation:** Subarray `[3]` has maximum sum 3. (Linear subarray, no wrapping needed).

### Example 2
- **Input:** `nums = [5, -3, 5]`
- **Output:** `10`
- **Explanation:** Subarray `[5, 5]` (wrapping around index 2 to index 0) has maximum sum $5 + 5 = 10$.

### Example 3
- **Input:** `nums = [-3, -2, -3]`
- **Output:** `-2`
- **Explanation:** Subarray `[-2]` has maximum sum -2.

---

## Constraints

- $n == \text{nums.length}$
- $1 \le n \le 3 \times 10^4$
- $-3 \times 10^4 \le \text{nums}[i] \le 3 \times 10^4$

---

## The Dual Kadane Invariant: Linear vs. Wrapping Subarrays

Any valid non-empty circular subarray falls into one of two mutually exclusive structural cases:

```
Case 1 (No Wrap):     [ ... |   MAX SUBARRAY   | ... ]
                             ▲                ▲
                             L                R

Case 2 (Wraps Around): [ MAX_PART_1 |  MIN SUBARRAY  | MAX_PART_2 ]
                        ▲          ▲                 ▲           ▲
                        0          i                 j          n-1
```

### Case 1: The Maximum Subarray Does Not Wrap
The optimal subarray is completely contiguous within the linear array $[0, n - 1]$.
- Computed using standard **Kadane's Algorithm**:
  $$\text{current\_max} = \max(\text{num}, \text{current\_max} + \text{num})$$
  $$\text{max\_sum} = \max(\text{max\_sum}, \text{current\_max})$$

### Case 2: The Maximum Subarray Wraps Around the Boundary
A wrapping subarray consists of a prefix $\text{nums}[0 \dots i]$ and a suffix $\text{nums}[j \dots n - 1]$ ($i < j$).
- Notice that the elements **omitted** from this circular subarray form a contiguous internal subarray $\text{nums}[i + 1 \dots j - 1]$.
- To maximize the circular sum of the outside elements, we must **minimize the sum of the omitted inside subarray**:
  $$\text{wrapping\_max\_sum} = \text{total\_sum} - \min \text{subarray sum}$$
- The minimum subarray sum is computed concurrently using an inverted Kadane's algorithm:
  $$\text{current\_min} = \min(\text{num}, \text{current\_min} + \text{num})$$
  $$\text{min\_sum} = \min(\text{min\_sum}, \text{current\_min})$$

---

## ⚠️ Crucial Edge Case: All Negative Elements

Consider `nums = [-3, -2, -3]`:
- $\text{total\_sum} = -8$
- $\text{min\_sum} = -8$ (the entire array is the minimum subarray)
- $\text{total\_sum} - \text{min\_sum} = -8 - (-8) = 0$
- Here, $0$ corresponds to selecting the **empty subarray**, which is strictly prohibited!
- **Invariant Check:**
  If every element is negative, $\text{max\_sum} < 0$. In this case, we must take the least negative single element (i.e., $\text{max\_sum}$):
  ```cpp
  if (max_sum < 0) return max_sum;
  return max(max_sum, total_sum - min_sum);
  ```

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $\mathcal{O}(N)$ (single linear pass computing total, min, and max simultaneously) |
| **Space Complexity** | $\mathcal{O}(1)$ auxiliary memory |

