# Sum of All Subset XOR Totals (LeetCode 1863)

## Problem Statement
The **XOR total** of an array is defined as the bitwise `XOR` of all its elements, or `0` if the array is empty.

For example, the XOR total of the array `[2,5,6]` is `2 ^ 5 ^ 6 = 1`.

Given an array `nums`, return the sum of all **XOR totals** for every subset of `nums`. 

### Example 1:
```
Input: nums = [1,3]
Output: 6
Explanation: The 4 subsets of [1, 3] are:
- The empty subset has an XOR total of 0.
- [1] has an XOR total of 1.
- [3] has an XOR total of 3.
- [1, 3] has an XOR total of 1 ^ 3 = 2.
0 + 1 + 3 + 2 = 6.
```

### Constraints:
- `1 <= nums.length <= 12`
- `1 <= nums[i] <= 20`

---

## Pattern Insight: Combinatorial Bit Independence ($O(N)$ Optimal)
1. **Approach 1: Subset Backtracking / Power Set ($O(2^N)$):**
   - Enumerate all $2^N$ subsets and accumulate their XOR sum.
2. **Approach 2: Bitwise OR Mathematical Deduction ($O(N)$ time, $O(1)$ space):**
   - Consider a single bit position $b$. If no number in `nums` has bit $b$ set, it never appears in any subset XOR.
   - If **at least one** element has bit $b$ set:
     - By algebraic symmetry of XOR sums across subsets of a vector space, exactly **half** of all $2^N$ subsets (i.e. $2^{N-1}$ subsets) will have an odd number of elements with bit $b$ set (resulting in bit $b = 1$).
     - The other half will have an even number of elements with bit $b$ set (resulting in bit $b = 0$).
   - Therefore, every bit that appears in the bitwise OR of the entire array contributes $2^{N-1} \cdot 2^b$ to the grand sum!
   - Result:
     $$\text{Total Sum} = (\text{nums}[0] \mid \text{nums}[1] \mid \dots \mid \text{nums}[N-1]) \times 2^{N-1}$$

---

## Complexity
- **Time Complexity:** $O(N)$ single pass OR accumulator.
- **Space Complexity:** $O(1)$.
