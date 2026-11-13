# Count Triplets That Can Form Two Arrays of Equal XOR (LeetCode 1442)

## Problem Statement
Given an array of integers `arr`.

We want to select three indices `i`, `j` and `k` where `(0 <= i < j <= k < arr.length)`.

Let's define `a` and `b` as follows:
- `a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]`
- `b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]`

Note that `^` denotes the bitwise-xor operation.

Return the number of triplets `(i, j, k)` where `a == b`.

### Example 1:
```
Input: arr = [2,3,1,6,7]
Output: 4
Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
- (0,1,2): a = arr[0] = 2, b = arr[1] ^ arr[2] = 3 ^ 1 = 2
- (0,2,2): a = arr[0] ^ arr[1] = 2 ^ 3 = 1, b = arr[2] = 1
- (2,3,4): a = arr[2] = 1, b = arr[3] ^ arr[4] = 6 ^ 7 = 1
- (2,4,4): a = arr[2] ^ arr[3] = 1 ^ 6 = 7, b = arr[4] = 7
```

### Constraints:
- `1 <= arr.length <= 300`
- `1 <= arr[i] <= 10^8`

---

## Pattern Insight: XOR Zero-Sum Subarray Invariant
- Notice the fundamental equivalence:
  $$a == b \iff a \oplus b = 0$$
- Combining $a$ and $b$:
  $$a \oplus b = (arr[i] \oplus \dots \oplus arr[j-1]) \oplus (arr[j] \oplus \dots \oplus arr[k]) = arr[i] \oplus \dots \oplus arr[k] = 0$$
- In terms of prefix XOR array $P$ where $P[x] = arr[0] \oplus \dots \oplus arr[x-1]$:
  $$P[k + 1] \oplus P[i] = 0 \iff P[k + 1] == P[i]$$
- **Key Deduction:** Whenever $P[k + 1] == P[i]$ for some $i \le k$, **any index $j$** such that $i < j \le k$ will satisfy $a == b$!
- For a fixed pair $(i, k)$, there are exactly $k - i$ valid choices for $j$.
- **Approaches:**
  1. $O(N^2)$ pass: Check all pairs $(i, k)$. If $P[k+1] == P[i]$, add $k - i$ to total.
  2. $O(N)$ single-pass hash map: For each prefix XOR value, maintain the count of its occurrences and the sum of their indices.

---

## Complexity
- **Time Complexity:** $O(N)$ optimal with hash map ($O(N^2)$ nested loop).
- **Space Complexity:** $O(N)$ for prefix XOR state.
