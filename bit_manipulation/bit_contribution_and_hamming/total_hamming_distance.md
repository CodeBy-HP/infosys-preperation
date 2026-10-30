# Total Hamming Distance (LeetCode 477)

## Problem Statement
The **Hamming distance** between two integers is the number of positions at which the corresponding bits are different.

Given an integer array `nums`, return the sum of Hamming distances between all the pairs of the integers in `nums`.

### Example 1:
```
Input: nums = [4,14,2]
Output: 6
Explanation: In binary representation:
4  is 0100
14 is 1110
2  is 0010
HammingDistance(4, 14) = 2
HammingDistance(4, 2)  = 2
HammingDistance(14, 2) = 2
Total = 2 + 2 + 2 = 6.
```

### Constraints:
- `1 <= nums.length <= 10^4`
- `0 <= nums[i] <= 10^9`

---

## Pattern Insight: Independent Bit Contribution Technique
- A brute force comparison of all pairs takes $O(N^2 \cdot 32)$, which TLEs for $N = 10^4$ ($10^8$ operations).
- Notice that **each bit position contributes independently** to the total Hamming distance!
- For any bit position $b \in [0, 31]$:
  - Suppose $c$ numbers have bit $b = 1$.
  - Then $(N - c)$ numbers have bit $b = 0$.
  - Any pair consisting of one number with bit 1 and one number with bit 0 will differ at bit $b$, contributing exactly 1 to the Hamming distance between them.
  - Thus, bit position $b$ contributes:
    $$\text{contribution}_b = c \times (N - c)$$
- Summing across all 32 bit positions yields the answer in strictly $O(32 N) = O(N)$ time!

---

## Complexity
- **Time Complexity:** $O(32 N) = O(N)$ linear time.
- **Space Complexity:** $O(1)$ constant space.
