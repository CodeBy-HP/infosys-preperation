# Longest String Chain

## Problem Overview
You are given an array of words where each word consists of lowercase English letters.
`wordA` is a predecessor of `wordB` if and only if we can insert exactly one letter anywhere in `wordA` without changing the order of the other characters to make it equal to `wordB`.
For example, `"abc"` is a predecessor of `"abac"`, while `"cba"` is not a predecessor of `"bcad"`.
A **word chain** is a sequence of words `[word_1, word_2, ..., word_k]` with $k \ge 1$, where `word_1` is a predecessor of `word_2`, `word_2` is a predecessor of `word_3`, and so on.
Return the length of the **longest possible word chain**.

---

## Hash Map + Length Sorting Formulation
1. Sort words by length in ascending order.
2. Maintain a hash map `dp[word]` storing the longest chain ending at `word`.
3. For each word of length $L$, systematically generate all $L$ possible predecessor strings by omitting the character at index $k$ ($0 \le k < L$).
4. If a predecessor string exists in `dp`:
   $$dp[word] = \max(dp[word], \; dp[predecessor] + 1)$$
5. The answer is $\max_{w \in words} dp[w]$.

---

## Complexity Analysis
- **Sorting Time:** $O(N \log N)$
- **Transition Time:** For each of $N$ words of length at most $L$, we perform $L$ substring operations of length $L$: $O(N \times L^2)$.
- **Total Time Complexity:** $O(N \log N + N \cdot L^2)$
- **Auxiliary Space:** $O(N \cdot L)$ for the hash map.

