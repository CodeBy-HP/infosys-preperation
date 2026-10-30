# Knuth-Morris-Pratt (KMP) String Matching Algorithm

## Problem Statement

Given two strings: a `haystack` (text of length $n$) and a `needle` (pattern of length $m$).

Find and return the **index of the first occurrence** of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack` (LeetCode 28: `strStr`).
Also support returning **all occurrence indices** in linear $O(n + m)$ time.

---

## Why Naive Search Fails

The naive approach compares `needle` against `haystack` at every starting position:
- If `haystack = "AAAAAAAAAAAAAAAAAB"` and `needle = "AAAAAB"`, the naive approach resets the needle pointer to $0$ and rewinds the haystack pointer upon every mismatch at `'B'`.
- Worst-case time complexity: $O(n \times m)$.

The **Knuth-Morris-Pratt (KMP)** algorithm guarantees strictly **$O(n + m)$ time** by ensuring the **haystack pointer never moves backwards**.

---

## The Secret Weapon: The LPS Array

KMP precomputes an array called **LPS (Longest Proper Prefix which is also a Suffix)** for the pattern:
- `lps[i]` is the length of the longest proper prefix of `needle[0...i]` that is also a suffix of `needle[0...i]`.

### Trace Example: `needle = "A B A B C"`
- `i = 0`: `"A"` $\implies$ LPS = $0$
- `i = 1`: `"AB"` $\implies$ prefixes: `{"A"}`, suffixes: `{"B"}` $\implies$ LPS = $0$
- `i = 2`: `"ABA"` $\implies$ prefixes: `{"A", "AB"}`, suffixes: `{"A", "BA"}` $\implies$ match `"A"` $\implies$ LPS = $1$
- `i = 3`: `"ABAB"` $\implies$ prefixes: `{"A", "AB", "ABA"}`, suffixes: `{"B", "AB", "BAB"}` $\implies$ match `"AB"` $\implies$ LPS = $2$
- `i = 4`: `"ABABC"` $\implies$ LPS = $0$
- **Result:** `lps = [0, 0, 1, 2, 0]`

### How LPS Eliminates Backtracking:
If we successfully match `"ABAB"` and mismatch on `'C'`:
- `lps[3] = 2` tells us the suffix `"AB"` we just processed matches the prefix `"AB"`.
- We shift the needle pointer back to index `2` without rewinding the text pointer!

---

## Complexity Analysis

| Phase | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Compute LPS Array** | $O(m)$ | $O(m)$ |
| **Text Traversal & Search** | $O(n)$ | $O(1)$ |
| **Total Algorithm** | $O(n + m)$ | $O(m)$ |

