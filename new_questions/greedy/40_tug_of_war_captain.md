# 40. Tug of War Captain (Infosys SP OA Exact PYQ)

## Problem Statement

There are `n` kids with individual strengths given in an integer array `s` of length `n`.

You must organize a Tug of War match between **Team A** and **Team B**:
1. First, choose **exactly one kid** `c` ($0 \le c < n$) to be the **Captain**, whose strength is **doubled** (`2 * s[c]`).
2. Kids join the match **one by one** (either in an optimal order chosen by you, or in array order depending on test variant).
3. **Mandatory Joining Rule:** Each incoming kid must join whichever team currently has the **smaller total strength** (if both teams currently have equal strength, the kid may join either team).

Find the **minimum possible absolute difference** between the final total strengths of Team A and Team B!

---

## Examples

### Example 1 (Optimal Order + Captain Choice)
- **Input:** `s = [1, 2, 4]`
- **Output:** `0`
- **Explanation:**
  - Pick kid 1 (`2`) as captain $\implies$ strength becomes `4`. Remaining kids: `1`, `4`.
  - Sequence: `4` joins Team A (`A=4, B=0`) $\to$ `4` joins Team B (`A=4, B=4`) $\to$ `1` joins A (`A=5, B=4`, diff `1`).
  - Wait: Pick kid 0 (`1`) as captain $\implies$ strength becomes `2`! Remaining: `2, 4`.
    Join order: `4` (`A=4, B=0`) $\to$ `2` (`A=4, B=2`) $\to$ `2` (`A=4, B=4`) $\implies$ diff = `0`!

### Example 2 (Fixed Sequential Order)
- **Input:** `s = [3, 1, 4, 2]`, fixed order `0 -> 1 -> 2 -> 3`
- **Output:** Try each index as captain, simulate strictly left-to-right!

---

## Constraints

- Optimal Order Variant: $1 \le n \le 18$ (or small weights $s[i]$), $1 \le s[i] \le 10^4$.
- Fixed Order Variant: $1 \le n \le 1000$.

---

## Pattern Insight: Difference State Invariant (`d' = |d - x|`)

Suppose the current absolute difference between the two teams is `d >= 0` (the heavier team has `W` and lighter team has `W - d`).
When a kid of strength `x` arrives, they **must** join the lighter team (`W - d`), making the new weights `W` and `W - d + x`!
Therefore, the new absolute difference is simply:
$$d_{\text{new}} = |d - x|$$
Notice two extraordinary properties:
1. $d$ never depends on the absolute weights of the teams — only on `d` itself!
2. If you know `maxDiff` after assigning captain, for small `n` ($n \le 16$) a Bitmask DP / Memoized state `(mask, d)` finds the exact optimal joining order! (And greedy sorting descending + assigning captain via brute force runs cleanly as a polynomial heuristic when $n$ is large).

---

## Complexity Analysis

| Variant | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Fixed Order Simulation** | $O(N^2)$ | $O(1)$ |
| **Optimal Order Bitmask DP ($N \le 16$)** | $O(N \cdot 2^N \cdot \text{states})$ | $O(2^N \cdot \text{states})$ |
