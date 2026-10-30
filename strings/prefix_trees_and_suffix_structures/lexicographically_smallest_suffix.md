# Problem 20: Lexicographically Smallest Suffix with Matching Prefix

## Problem Statement

You are provided with a main string $S$ of length $N$. You must process a series of queries against this string.

### Query Definition
For each query, you are given a search string $T$. You need to perform the following steps:
1. Identify all suffixes of the main string $S$ that begin with the exact prefix $T$.
2. Out of all these valid suffixes, find the single suffix that is **lexicographically smallest**.
3. Determine the **length** of this lexicographically smallest suffix.
4. If there is no suffix in $S$ that starts with $T$, the query result is `0`.

Return the total sum of the lengths returned by all queries, modulo $10^9 + 7$.

---

## Examples

### Example 1
- **Input String $S$:** `"mzadpoghyykht"` ($N = 13$)
- **Query $T$:** `"yk"`
- **Execution:**
  - Suffixes of $S$ starting with `"yk"`: `"ykht"` (length 4).
  - Lexicographically smallest: `"ykht"` (length 4).
- **Output:** `4`

---

## Constraints

- $1 \le N \le 10^5$
- $1 \le Q \le 10^5$
- $\sum |T| \le 10^5$

---

## Pattern: Suffix Array + Binary Search or Suffix Trie

1. **Suffix Array Formulation:**
   - Precompute sorted suffix array $SA$ of $S$.
   - For query $T$, find the first occurrence in $SA$ via binary search: `lower_bound`.
   - If the suffix at that position starts with $T$, it is **guaranteed to be the lexicographically smallest** matching suffix because the suffix array is already sorted lexicographically!
   - Its length is $N - SA[pos]$.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Suffix Array + Binary Search** | $O(N \log N + Q \times |T| \log N)$ | $O(N)$ | Optimal for large query sets |
| **Brute Force Linear Scan**      | $O(Q \times N^2)$ | $O(1)$ | Times out for large inputs |
