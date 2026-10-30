# Maximum XOR of Two Numbers in an Array (LeetCode 421)

## Problem Statement
Given an integer array `nums`, return the maximum result of `nums[i] ^ nums[j]`, where `0 <= i <= j < nums.length`.

### Example 1:
```
Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 ^ 25 = 28.
```

### Constraints:
- `1 <= nums.length <= 2 * 10^5`
- `0 <= nums[i] <= 2^31 - 1`

---

## Pattern Insight: 31-Bit Binary Trie with Greedy Branching
- Naive pair comparison takes $O(N^2)$ time, which TLEs for $N = 2 \cdot 10^5$.
- A **Binary Trie** represents numbers as 31-bit binary paths from root (MSB bit 30 down to LSB bit 0).
- To maximize $XOR$ with a given number $x$:
  - At each bit position $b$, we desire the opposite bit $1 - \text{bit}_b$ because $1 \oplus 0 = 1$.
  - If a child node with the opposite bit exists, traverse it and set bit $b$ of the result to 1.
  - Otherwise, take the existing branch with the same bit (contributing 0 to the XOR).
- Inserting all $N$ numbers and querying for each number takes $O(31 \cdot N) = O(N)$ time!

---

## Complexity
- **Time Complexity:** $O(31 \cdot N) = O(N)$ linear time.
- **Space Complexity:** $O(31 \cdot N)$ nodes in Trie.
