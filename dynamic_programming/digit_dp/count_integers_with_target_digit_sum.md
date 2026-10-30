# Problem 17: Count Integers with Target Digit Sum (Digit DP)

## Problem Statement

Given a string `N` representing a non-negative integer and an integer `target`, return the **total number of integers from $0$ up to $N$ whose digits sum up to exactly `target`**.

Since counting one-by-one up to $10^{18}$ takes $O(N)$ time and will cause a Time Limit Exceeded (TLE), **Digit DP** builds numbers digit-by-digit from left to right in $O(\text{digits} \times \text{target} \times 10)$ time.

---

## Examples

### Example 1
- **Input:** `N = "324", target = 5`
- **Output:** `18`
- **Explanation:** Numbers $\le 324$ with digit sum $5$ include:
  - 1-digit: `5`
  - 2-digit: `14, 23, 32, 41, 50`
  - 3-digit: `104, 113, 122, 131, 140, 203, 212, 221, 230, 302, 311, 320`
  - Total valid integers = $1 + 5 + 12 = 18$.

### Example 2
- **Input:** `N = "20", target = 2`
- **Output:** `3`
- **Explanation:** The integers $\le 20$ with digit sum 2 are `2, 11, 20`. Total = 3.

---

## Constraints

- $1 \le \text{N.length} \le 100$ (can easily scale to $10^{18}$)
- `N` consists of digits only and does not contain leading zeros (except `"0"`).
- $1 \le \text{target} \le 9 \times \text{N.length}$

---

## The "Tight" Bound Logic

When placing digits from left to right to build an integer $\le N$:
- If the prefix placed so far is strictly less than the prefix of $N$, you are **unrestricted** (`tight = false`), so the next digit can be any digit in $[0, 9]$.
- If the prefix matches $N$'s prefix, you are **hugging the ceiling** (`tight = true`), so the next digit can only go up to $N[\text{idx}] - '0'$.

### Recurrence Relations:

1. **State:**
   - $\text{solve}(\text{idx}, \text{current\_sum}, \text{tight})$: number of valid ways to complete building the number starting from digit index $\text{idx}$ with current digit sum $\text{current\_sum}$.
2. **Transition:**
   - Let $\text{limit} = \text{tight} ? (N[\text{idx}] - '0') : 9$.
   - For every digit $d \in [0, \text{limit}]$:
     - $\text{next\_tight} = \text{tight} \land (d == \text{limit})$
     $$\text{ans} = \sum_{d = 0}^{\text{limit}} \text{solve}(\text{idx} + 1,\, \text{current\_sum} + d,\, \text{next\_tight})$$
3. **Base Cases:**
   - If $\text{current\_sum} > \text{target}$, return $0$ (prune immediately).
   - If $\text{idx} == N\text{.length()}$, return $1$ if $\text{current\_sum} == \text{target}$, else $0$.

---

## The Range Query Trick

If a problem asks for integers in a range $[L, R]$ with target sum $S$:
$$\text{countInRange}(L, R) = \text{countUpTo}(R, S) - \text{countUpTo}(L - 1, S)$$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Top-Down (Recursion + 3D Memoization)** | $O(|N| \times \text{Target} \times 10)$ | $O(|N| \times \text{Target} \times 2)$ |
| **Bottom-Up (3D Tabulation)** | $O(|N| \times \text{Target} \times 10)$ | $O(|N| \times \text{Target} \times 2)$ |

