# Single Number I (LeetCode 136)

## Problem Statement
Given a non-empty array of integers `nums`, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

### Example 1:
```
Input: nums = [2,2,1]
Output: 1
```

### Example 2:
```
Input: nums = [4,1,2,1,2]
Output: 4
```

### Constraints:
- `1 <= nums.length <= 3 * 10^4`
- `-3 * 10^4 <= nums[i] <= 3 * 10^4`
- Each element in the array appears twice except for one element which appears only once.

---

## Pattern Insight: XOR Self-Inverse Cancellation
- The XOR operation $\oplus$ satisfies:
  1. **Commutativity:** $a \oplus b = b \oplus a$
  2. **Associativity:** $(a \oplus b) \oplus c = a \oplus (b \oplus c)$
  3. **Identity Element:** $a \oplus 0 = a$
  4. **Self-Inverse:** $a \oplus a = 0$
- If we XOR all numbers in the array together:
  $$(x_1 \oplus x_1) \oplus (x_2 \oplus x_2) \oplus \dots \oplus (x_k \oplus x_k) \oplus \text{unique} = 0 \oplus 0 \oplus \dots \oplus 0 \oplus \text{unique} = \text{unique}$$
- All paired duplicate numbers eliminate each other to 0, leaving strictly the unique element!

---

## Complexity
- **Time Complexity:** $O(N)$ single pass.
- **Space Complexity:** $O(1)$ constant space.
