# K-th Symbol in Grammar (LeetCode 779)

## Problem Statement
We build a table of `n` rows (1-indexed). We start by writing `0` in the 1st row. Now in every subsequent row, we look at the previous row and replace each occurrence of `0` with `01`, and each occurrence of `1` with `10`.

- For example, for $n = 3$, the 1st row is `0`, the 2nd row is `01`, and the 3rd row is `0110`.

Given two integers `n` and `k`, return the $k$-th (1-indexed) symbol in the $n$-th row of a table of `n` rows.

### Example 1:
```
Input: n = 1, k = 1
Output: 0
```

### Example 2:
```
Input: n = 2, k = 1
Output: 0
```

### Example 3:
```
Input: n = 2, k = 2
Output: 1
```

### Constraints:
- `1 <= n <= 30`
- `1 <= k <= 2^(n - 1)`

---

## Pattern Insight: Thue-Morse Sequence & Set Bit Parity
- Observe the sequence generated row by row:
  - Row 1: `0`
  - Row 2: `0 1`
  - Row 3: `0 1 1 0`
  - Row 4: `0 1 1 0 1 0 0 1`
- This is the famous **Thue-Morse Sequence**!
- In binary, each step doubles the sequence by appending the bitwise inversion of the previous sequence.
- **Bitwise Parity Invariant:**
  - Convert $k$ to 0-based index: $\text{idx} = k - 1$.
  - The value at index $\text{idx}$ is $1$ if and only if $\text{idx}$ has an **odd number of set bits (1s)** in its binary representation!
  - If $\text{idx}$ has an even number of set bits, the value is $0$.
  - Formula:
    $$\text{answer} = \text{\_\_builtin\_popcount}(k - 1) \pmod 2$$
- Runs in strictly $O(1)$ time and $O(1)$ memory!

---

## Complexity
- **Time Complexity:** $O(1)$ using bitwise popcount.
- **Space Complexity:** $O(1)$.
