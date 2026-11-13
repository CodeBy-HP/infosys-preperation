# Valid Parenthesis Checker (LeetCode 678)

## Problem Overview
Given a string `s` containing only three types of characters: `'('`, `')'`, and `'*'`. Return `true` if `s` is valid.
The following rules define a valid string:
1. Any left parenthesis `'('` must have a corresponding right parenthesis `')'`.
2. Any right parenthesis `')'` must have a corresponding left parenthesis `'('`.
3. Left parenthesis `'('` must go before the corresponding right parenthesis `')'`.
4. `'*'` could be treated as a single right parenthesis `')'`, a single left parenthesis `'('`, or an empty string `""`.

---

## The Greedy Open-Bracket Interval Invariant
Because each `'*'` can branch into 3 possibilities, standard stack parsing branches into exponential combinations.
However, notice that all valid counts of open parentheses at any step form a **continuous integer interval**:
$$[\text{cmin}, \; \text{cmax}]$$
where:
- `cmin`: The minimum possible count of open `'('` parentheses.
- `cmax`: The maximum possible count of open `'('` parentheses.

### State Transitions:
For each character in `s`:
1. **If `'('`:** Both minimum and maximum open counts increase by 1:
   $$\text{cmin} \leftarrow \text{cmin} + 1, \quad \text{cmax} \leftarrow \text{cmax} + 1$$
2. **If `')'`:** Both counts decrease by 1:
   $$\text{cmin} \leftarrow \text{cmin} - 1, \quad \text{cmax} \leftarrow \text{cmax} - 1$$
3. **If `'*' `:**
   - As `')'`: $\text{cmin} \leftarrow \text{cmin} - 1$
   - As `'('`: $\text{cmax} \leftarrow \text{cmax} + 1$
   - As `""`: counts remain unchanged.
   $$\text{cmin} \leftarrow \text{cmin} - 1, \quad \text{cmax} \leftarrow \text{cmax} + 1$$

### Invariant Guard Rails:
- **Immediate Failure:** If $\text{cmax} < 0$, even with every `'*'` treated as `'('`, we have an excess of closing parentheses $\implies$ return `false`.
- **Lower Bound Clamp:** We can never have fewer than 0 open parentheses (we would simply treat the surplus `'*'` as empty `""` instead of `')'`):
  $$\text{cmin} = \max(\text{cmin}, \; 0)$$

### Final Validity Check:
At the end of the string, it is valid if and only if a 0-balance is achievable:
$$\text{cmin} == 0$$

---

## Complexity Analysis
- **Time Complexity:** $O(N)$ single pass.
- **Space Complexity:** $O(1)$ auxiliary space using two integer variables.

