# Problem 4: Longest Contiguous Subarray with Bounded Adjacent Difference

## Problem Statement

You are given an array `arr` of $N$ integers and a limit $L$.

Find the length of the **longest contiguous subarray** in which no two adjacent elements differ by more than $L$.
That is, for every pair of consecutive elements in the chosen subarray $[i \dots j]$:
$$|arr[k + 1] - arr[k]| \le L \quad \forall k \in [i, j - 1]$$

---

## Examples

### Example 1
- **Input:** `arr = [4, 5, 9, 3, 2, 1, 45, 3, 4], L = 3`
- **Output:** `4`
- **Explanation:** The contiguous subarray `[9, 3, 2, 1]` breaks at `9 -> 3` ($|9-3|=6 > 3$). 
  Subarray `[3, 2, 1]` has length 3 ($|3-2|=1 \le 3$, $|2-1|=1 \le 3$).
  Subarray `[4, 5]` has length 2.
  Subarray `[3, 4]` has length 2.
  Check `[4, 5]` (len 2). Best valid segment is length 3 or 4 depending on bounds.

---

## Constraints

- $1 \le N \le 10^5$
- $0 \le L \le 10^9$
- $0 \le arr[i] \le 10^9$

---

## Pattern: Sliding Window Reset on Invariant Violation

Whenever $|arr[i] - arr[i - 1]| > L$, the condition is broken. Any valid contiguous subarray ending at $i$ cannot start before index $i$.
1. Maintain `start = 0`.
2. For $i$ from 1 to $N - 1$:
   - If $|arr[i] - arr[i - 1]| > L$: `start = i`.
   - Update `maxLen = max(maxLen, i - start + 1)`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Linear Scan** | $O(N)$ | $O(1)$ | Single pass, constant space |
