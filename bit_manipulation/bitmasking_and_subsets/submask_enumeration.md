# Submask Enumeration (SOS DP Foundation)

## Problem Statement
Given a bitmask `mask` representing a set, enumerate all submasks (subsets of set bits) of `mask` in descending order.

A mask `sub` is a submask of `mask` if `(sub & mask) == sub` (i.e., every bit set in `sub` is also set in `mask`).

### Example 1:
```
Input: mask = 13 (binary 1101, elements at bit positions {0, 2, 3})
Output submasks:
1101 (13), 1100 (12), 1001 (9), 1000 (8), 0101 (5), 0100 (4), 0001 (1), 0000 (0)
Total = 2^3 = 8 submasks.
```

---

## Pattern Insight: The `(sub - 1) & mask` Trick
- Naive check tests all numbers from `mask` down to 0: takes $O(2^N)$ even if mask has only a few bits!
- **Optimal Submask Trick:**
  ```cpp
  for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
      // process sub
  }
  // 0 is also a valid submask
  ```
- **How it works:**
  - Subtracting 1 from `sub` flips its lowest set bit to 0 and all trailing zeroes to 1.
  - ANDing with `mask` immediately removes all extraneous 1s that were not in `mask`!
  - It jumps directly from one valid submask to the next valid submask without visiting any non-submasks.
- **Asymptotic Power:**
  Iterating over all submasks for all masks of size $N$ takes:
  $$\sum_{k=0}^N \binom{N}{k} 2^k = (1 + 2)^N = 3^N$$
  This $O(3^N)$ submask DP complexity is vastly superior to $O(4^N)$!

---

## Complexity
- **Time Complexity:** $O(2^k)$ for a mask with $k$ set bits. Across all $N$-bit masks: $O(3^N)$.
- **Space Complexity:** $O(1)$ extra space.
