# Find Nth Root of a Number

## Problem Statement

Given two positive integers $N$ and $M$, find the integer **$N$-th root** of $M$ (i.e., an integer $x$ such that $x^N = M$).

If no such integer exists, return `-1`.

---

## Examples

### Example 1
- **Input:** `N = 3`, `M = 27`
- **Output:** `3`
- **Explanation:** $3^3 = 27$, so the 3rd root of 27 is 3.

### Example 2
- **Input:** `N = 4`, `M = 69`
- **Output:** `-1`
- **Explanation:** $2^4 = 16$ and $3^4 = 81$. No integer exists such that $x^4 = 69$.

### Example 3
- **Input:** `N = 1`, `M = 14`
- **Output:** `14`
- **Explanation:** $14^1 = 14$.

---

## Constraints

- $1 \le N \le 30$
- $1 \le M \le 10^9$

---

## Monotonic Search Invariant

The function $f(x) = x^N$ is strictly monotonically increasing for $x \ge 1$.
Thus, we can binary search for $x$ in the search space $[1, M]$:
1. Midpoint: $\text{mid} = left + \frac{right - left}{2}$.
2. Evaluate $\text{mid}^N$ against $M$:
   - To prevent 64-bit integer overflow during exponentiation, compute the product term-by-term. If at any step $\text{prod} > M$, we immediately know $\text{mid}^N > M$.
3. Decision:
   - If $\text{mid}^N == M$: Exact integer root found, return `mid`.
   - If $\text{mid}^N < M$: $x$ must be larger $\to left = \text{mid} + 1$.
   - If $\text{mid}^N > M$: $x$ must be smaller $\to right = \text{mid} - 1$.
4. If the loop terminates with $left > right$, no integer root exists; return `-1`.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space | Overflow Safe? |
| :--- | :--- | :--- | :--- |
| **Binary Search with Early Termination** | $O(N \log M)$ | $O(1)$ | Yes |
| **Linear Search with Power Checks** | $O(N \times M^{1/N})$ | $O(1)$ | Yes |
| **Direct Float `pow()` (Floating-point error prone)** | $O(1)$ | $O(1)$ | Precision issues on large $M$ |

