# Find Out How Many Times the Array is Rotated

## Problem Statement

Given an array `arr` of $N$ distinct integers, sorted in ascending order and then rotated right by an unknown number of times $k$ ($0 \le k < N$), find the value of $k$ (the rotation count).

---

## Examples

### Example 1
- **Input:** `arr = [4, 5, 6, 7, 0, 1, 2]`
- **Output:** `4`
- **Explanation:** The original sorted array was `[0, 1, 2, 4, 5, 6, 7]`. It was rotated right by 4 positions. Notice that the minimum element `0` is at index `4`.

### Example 2
- **Input:** `arr = [3, 4, 5, 1, 2]`
- **Output:** `3`
- **Explanation:** The minimum element `1` is at index `3`, so the array has been rotated 3 times.

### Example 3
- **Input:** `arr = [1, 2, 3, 4, 5]`
- **Output:** `0`
- **Explanation:** The array is not rotated (or rotated 0 times), minimum element `1` is at index `0`.

---

## Constraints

- $1 \le N \le 10^5$
- $-10^9 \le \text{arr}[i] \le 10^9$
- All elements in `arr` are distinct.

---

## Pattern Insight: Index of Minimum Element

In a right-rotated sorted array, the number of rotations is **strictly equal to the index of the minimum element**:
$$\text{rotation count } k = \text{index of } \min(arr)$$

### Binary Search Invariant
1. Maintain interval $[left, right]$.
2. If `arr[left] <= arr[right]`: The subarray is already completely sorted; `arr[left]` is the minimum, so its index `left` is the candidate.
3. Midpoint: $\text{mid} = left + \frac{right - left}{2}$.
4. If `arr[mid] >= arr[left]`:
   - The left half is sorted. The rotation pivot must lie in the right half.
   - Record `arr[left]` as candidate, and move `left = mid + 1`.
5. Else (`arr[mid] < arr[left]`):
   - The right half is sorted, and the pivot is in the left half including `mid`.
   - Record `arr[mid]` as candidate, and move `right = mid - 1`.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Binary Search (Inflection Detection)** | $O(\log N)$ | $O(1)$ |
| **Linear Search for Minimum Index** | $O(N)$ | $O(1)$ |

