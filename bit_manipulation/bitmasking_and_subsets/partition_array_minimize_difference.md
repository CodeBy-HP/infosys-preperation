# Partition Array Into Two Arrays to Minimize Sum Difference (LeetCode 2035)

## Problem Statement
You are given an integer array `nums` of $2n$ integers. You need to partition `nums` into two arrays of length $n$ to **minimize the absolute difference** of the sums of the arrays. To partition `nums`, put each element of `nums` into one of the two arrays.

Return the minimum possible absolute difference.

### Example 1:
```
Input: nums = [3,9,7,3]
Output: 2
Explanation: One optimal partition is: [3,9] and [7,3].
The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.
```

### Constraints:
- `1 <= n <= 15`
- `nums.length == 2 * n`
- `-10^7 <= nums[i] <= 10^7`

---

## Pattern Insight: Meet-in-the-Middle with Bitmasks ($N \approx 30$)
- Brute force requires choosing $n$ elements out of $2n$:
  $$\binom{30}{15} = 155,117,520 \text{ states (or } 2^{30} \approx 10^9 \text{)},$$
  which TLEs!
- **Meet-in-the-Middle Strategy:**
  1. Divide `nums` into two halves: `left` of size $n$, and `right` of size $n$.
  2. For `left`, generate all $2^n$ subsets ($2^{15} = 32768$). Group subset sums by the count of elements chosen:
     `left_sums[k]` stores all sums formed by picking exactly $k$ elements from `left`.
  3. Do the same for `right`: `right_sums[k]` stores sums formed by picking $k$ elements from `right`.
  4. If we pick $k$ elements from `left`, we must pick exactly $n - k$ elements from `right` to total $n$ elements.
  5. Sort each vector in `right_sums[n - k]`.
  6. For each sum $s_L \in left\_sums[k]$:
     - Target sum for the chosen subset is $\frac{\text{totalSum}}{2}$.
     - We need $s_R \approx \frac{\text{totalSum}}{2} - s_L$.
     - Use `std::lower_bound` on `right_sums[n - k]` to find the closest sum in $O(\log(2^{n-k}))$.
     - Update minimum $| \text{totalSum} - 2(s_L + s_R) |$.

---

## Complexity
- **Time Complexity:** $O(2^n \cdot n)$ — For $n=15$, $\approx 32768 \times 15 \approx 5 \cdot 10^5$ operations (runs in ~100ms).
- **Space Complexity:** $O(2^n)$ to store subset sums.
