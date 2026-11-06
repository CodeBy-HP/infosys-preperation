# Maximum XOR of Two Numbers in an Array

## Problem Statement
Given an integer array `nums`, return the **maximum result** of `nums[i] ^ nums[j]`, where $0 \le i \le j < \text{nums.length}$.

**Target Time Complexity:** $O(N)$ (where $N = \text{nums.length}$).

```
Input: nums = [3, 10, 5, 25, 2, 8]
Output: 28

Explanation:
The maximum result is 5 ^ 25 = 28:
  5  = 00101
 25  = 11001
 28  = 11100
```

---

## 1. Algorithmic Approach (32-Bit Binary Trie)

### The Bitwise Greedy Principle
To maximize the value of $X \oplus Y$, we want as many high-order bits as possible to be $1$:
- Because $2^k > \sum_{j=0}^{k-1} 2^j$, a single $1$ at bit position $k$ contributes more to the value than all lower bits combined.
- Therefore, at each bit position $i$ (from MSB $31$ down to LSB $0$):
  - If `num` has bit $b \in \{0, 1\}$, we **greedily desire** the opposite bit $1 - b$.
  - If a number with $1 - b$ exists in the Trie branch, we take that branch and add $2^i$ to our XOR sum.
  - If no such number exists, we are forced to take the branch with bit $b$ (contributing $0$ at bit $i$).

### Step-by-Step Algorithm
1. **Node Structure:** Each node has `links[2]` (`0` and `1`).
2. **Insertion:**
   - For each number in `nums`, traverse from bit 31 down to 0.
   - Extract `bit = (num >> i) & 1`.
   - Allocate `links[bit]` if null, then advance.
3. **Querying Max XOR for `num`:**
   - Initialize `maxXor = 0`, `curr = root`.
   - For bit $i = 31$ down to $0$:
     - `bit = (num >> i) & 1`.
     - `oppositeBit = 1 - bit`.
     - If `curr->containsKey(oppositeBit)`:
       - `maxXor |= (1 << i)`.
       - `curr = curr->get(oppositeBit)`.
     - Else:
       - `curr = curr->get(bit)`.
4. Maximize across all numbers in `nums`.

---

## 2. Complexity Analysis
- **Time Complexity:** $O(32 \cdot N) = O(N)$ — Inserting $N$ numbers takes $32 \times N$ operations. Querying $N$ numbers takes $32 \times N$ operations.
- **Space Complexity:** $O(32 \cdot N)$ — The binary tree has depth 32, with at most $32 \cdot N$ total node allocations.

