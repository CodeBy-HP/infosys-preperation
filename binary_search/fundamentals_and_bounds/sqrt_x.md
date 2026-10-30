# Sqrt(x) (LeetCode 69)

## Problem Statement
Given a non-negative integer `x`, return the square root of `x` rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator, such as `pow(x, 0.5)` or `x ** 0.5`.

### Example 1:
```
Input: x = 4
Output: 2
```

### Example 2:
```
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round down to the nearest integer, 2 is returned.
```

### Constraints:
- `0 <= x <= 2^31 - 1`

---

## Pattern Insight: Monotonic Range Search on $[0, x]$
- The function $f(m) = m^2$ is monotonically strictly increasing for $m \ge 0$.
- Search range is $[0, x]$ (or $[1, x / 2]$ for $x \ge 4$).
- Use `long long` for $mid \times mid$ to prevent 32-bit overflow when $mid \approx 2^{16} = 65536$.
- If `mid * mid <= x`: `ans = mid; left = mid + 1;` (search for larger integer).
- Else: `right = mid - 1;`.

---

## Complexity
- **Time Complexity:** $O(\log x)$.
- **Space Complexity:** $O(1)$.
