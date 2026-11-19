# Remove K Digits (LeetCode 402)

## Problem Statement

Given string `num` representing a non-negative integer, and an integer `k`, return the smallest possible integer after removing `k` digits from `num`.

If the resulting string is empty, return `"0"`.

---

## Examples

### Example 1
- **Input:** `num = "1432219"`, `k = 3`
- **Output:** `"1219"`
- **Explanation:** Remove the three digits 4, 3, and 2 to form the new number `"1219"` which is the smallest.

### Example 2
- **Input:** `num = "10200"`, `k = 1`
- **Output:** `"200"`
- **Explanation:** Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

### Example 3
- **Input:** `num = "10"`, `k = 2`
- **Output:** `"0"`
- **Explanation:** Remove all digits from the number and nothing is left, which is 0.

---

## Constraints

- $1 \le k \le \text{num.length} \le 10^5$
- `num` consists of only digits.
- `num` does not have any leading zeros except for the zero itself.

---

## Monotonic Stack Invariant

The relative significance of a digit is determined by its position (leftmost digits are most significant).
To minimize the resulting number:
1. Whenever we encounter a digit $\text{num}[i]$ that is strictly smaller than the preceding digit in our chosen sequence, the preceding digit is suboptimal and should be removed (as long as we still have removals $k > 0$ remaining).
2. Maintain a **monotonic non-decreasing stack** of characters.
3. If $k > 0$ after processing all digits (e.g., when the digits are already in non-decreasing order like `"12345"`), remove the remaining $k$ characters from the top/tail of the stack.
4. Strip any leading zeros. If the resulting string is empty, return `"0"`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Monotonic Stack (string as stack)** | $O(N)$ | $O(N)$ | Optimal; avoids extra string copies |
| **Standard Stack (`std::stack<char>`)** | $O(N)$ | $O(N)$ | Classic LIFO representation |
| **Greedy Search Scan** | $O(k \cdot N)$ | $O(N)$ | Iteratively finds first valley |

