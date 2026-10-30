# Single Number III (LeetCode 260)

## Problem Statement
Given an integer array `nums`, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

### Example 1:
```
Input: nums = [1,2,1,3,2,5]
Output: [3,5] (or [5,3])
```

### Example 2:
```
Input: nums = [-1,0]
Output: [-1,0]
```

### Constraints:
- `2 <= nums.length <= 3 * 10^4`
- `-2^31 <= nums[i] <= 2^31 - 1`
- Each element appears twice except two numbers which appear once.

---

## Pattern Insight: Lowest Set Bit Array Partitioning
- XOR of all elements yields:
  $$X = a \oplus b$$
  where $a$ and $b$ are the two unique elements.
- Since $a \ne b$, $X \ne 0$, meaning $X$ has at least one bit set to 1.
- Any set bit in $X$ represents a position where $a$ and $b$ have **different bits** (one has a 1, the other has a 0).
- Extract the lowest set bit using two's complement:
  $$\text{diff} = X \ \& \ (-X)$$
  *(cast to unsigned to avoid signed overflow on INT_MIN).*
- Now partition all numbers into two distinct groups based on whether `(num & diff) != 0`:
  - Numbers in Group 1 have that bit set (contains $a$ and all paired duplicates with that bit set).
  - Numbers in Group 2 have that bit unset (contains $b$ and all paired duplicates without that bit set).
- XORing each group separately isolates $a$ and $b$!

---

## Complexity
- **Time Complexity:** $O(N)$ two passes.
- **Space Complexity:** $O(1)$ constant memory.
