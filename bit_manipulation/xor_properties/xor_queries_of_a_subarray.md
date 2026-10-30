# XOR Queries of a Subarray (LeetCode 1310)

## Problem Statement
You are given an array `arr` of positive integers and an array `queries` where `queries[i] = [left_i, right_i]`.

For each query `i`, compute the **XOR** of elements from `left_i` to `right_i` (that is, `arr[left_i] ^ arr[left_i + 1] ^ ... ^ arr[right_i]`).

Return an array containing the results for all queries.

### Example 1:
```
Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
Output: [2,7,14,8] 
Explanation: 
- [0,1] = 1 ^ 3 = 2 
- [1,2] = 3 ^ 4 = 7 
- [0,3] = 1 ^ 3 ^ 4 ^ 8 = 14 
- [3,3] = 8
```

### Constraints:
- `1 <= arr.length, queries.length <= 3 * 10^4`
- `1 <= arr[i] <= 10^9`
- `queries[i].length == 2`
- `0 <= left_i <= right_i < arr.length`

---

## Pattern Insight: Prefix XOR Array ($O(1)$ Query Time)
- Similar to Prefix Sums, we can precompute prefix XORs:
  $$P[0] = 0$$
  $$P[i + 1] = P[i] \oplus arr[i]$$
- Notice:
  $$P[R + 1] = arr[0] \oplus \dots \oplus arr[L-1] \oplus arr[L] \oplus \dots \oplus arr[R]$$
  $$P[L] = arr[0] \oplus \dots \oplus arr[L-1]$$
- Because $x \oplus x = 0$:
  $$P[R + 1] \oplus P[L] = arr[L] \oplus \dots \oplus arr[R]$$
- Every query executes in strict $O(1)$ time!

---

## Complexity
- **Time Complexity:** $O(N + Q)$ — $O(N)$ preprocessing and $O(1)$ per query.
- **Space Complexity:** $O(N)$ for prefix XOR table.
