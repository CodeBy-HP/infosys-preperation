# Single Number II (LeetCode 137)

## Problem Statement
Given an integer array `nums` where every element appears **three times** except for one, which appears **exactly once**. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

### Example 1:
```
Input: nums = [2,2,3,2]
Output: 3
```

### Example 2:
```
Input: nums = [0,1,0,1,0,1,99]
Output: 99
```

### Constraints:
- `1 <= nums.length <= 3 * 10^4`
- `-2^31 <= nums[i] <= 2^31 - 1`
- Each element in `nums` appears exactly three times except for one element which appears once.

---

## Pattern Insight: Modulo-3 Bit Counter & Finite State Machine
1. **Approach 1: Bit Counting Modulo 3 ($O(32N)$):**
   - For each bit position $0 \le b < 32$, sum the count of $b$-th bits across all numbers.
   - If a number appears 3 times, its contribution to bit $b$ is a multiple of 3.
   - Thus, $\text{count}[b] \pmod 3$ isolates the bit of the unique number.
2. **Approach 2: Digital Logic State Machine ($O(N)$ time, $O(1)$ space):**
   - We need a counter modulo 3 for each bit position: states `00 -> 01 -> 10 -> 00`.
   - Maintain two bitmasks `ones` and `twos`:
     - `ones`: bits that have appeared $1 \pmod 3$ times.
     - `twos`: bits that have appeared $2 \pmod 3$ times.
   - Transitions:
     ```cpp
     ones = (ones ^ num) & ~twos;
     twos = (twos ^ num) & ~ones;
     ```
   - At the end, `ones` holds the unique number!

---

## Complexity
- **Time Complexity:** $O(N)$ single pass.
- **Space Complexity:** $O(1)$ constant space.
