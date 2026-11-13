# Bracket Balance Cost

## Problem Statement
Given a string of brackets `s` consisting of opening brackets `'('` and closing brackets `')'`, and two integers `a` and `b`:
- `a`: Cost to insert an opening bracket `'('` at any position.
- `b`: Cost to insert a closing bracket `')'` at any position.

Determine the **minimum total insertion cost** required to make `s` a valid balanced bracket sequence. Return the answer modulo $10^9 + 7$.

### Validity Rules:
1. Every opening bracket `'('` must have a corresponding closing bracket `')'` appearing strictly after it.
2. Every closing bracket `')'` must have a corresponding opening bracket `'('` appearing strictly before it.
3. The empty string is valid.

### Example 1:
```
Input: s = ")()(", a = 3, b = 5
Output: 8
Explanation:
- The first ')' has no preceding '('. We must insert an opening bracket '(' before it (cost a = 3) -> "()()(".
- The last '(' has no succeeding ')'. We must insert a closing bracket ')' after it (cost b = 5) -> "()()()".
Total cost = 3 + 5 = 8.
```

### Example 2:
```
Input: s = "(((", a = 2, b = 4
Output: 12
Explanation:
We have 3 unmatched opening brackets. We must insert 3 closing brackets at cost b = 4 each.
Total cost = 3 * 4 = 12.
```

### Constraints:
- `1 <= s.length <= 10^5`
- `1 <= a, b <= 10^9`
- `s` consists only of `'('` and `')'`.

---

## Pattern Insight: Greedy Balance Tracking ($O(N)$ Optimal)
- We do not need to physically modify the string. We only need to count how many opening and closing brackets are missing.
- Maintain a running `balance` (number of unmatched opening brackets):
  1. Iterate character by character:
     - If `c == '('`: increment `balance++`.
     - If `c == ')'`:
       - If `balance > 0`: it successfully matches the most recent opening bracket $\to$ `balance--`.
       - If `balance == 0`: we have a closing bracket with **no available opening bracket** before it. To satisfy the validity invariant, an opening bracket `'('` must be inserted to its left!
         - Increment `needed_opening++`.
         - (The inserted `'('` matches this `')'`, so `balance` remains 0).
  2. At the end of the string:
     - Any remaining `balance > 0` represents opening brackets that were never closed.
     - Each requires a closing bracket `')'` to be inserted at the end.
     - `needed_closing = balance`.
- **Total Cost:**
  $$\text{Total Cost} = (\text{needed\_opening} \times a + \text{needed\_closing} \times b) \pmod{10^9 + 7}$$

---

## Complexity
- **Time Complexity:** $O(N)$ single linear pass.
- **Space Complexity:** $O(1)$ constant memory.

