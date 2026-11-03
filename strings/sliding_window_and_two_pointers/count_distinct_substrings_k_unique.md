# Count Distinct Substrings with Exactly K Unique Characters

## Problem Statement

Given a string `s` and an integer `k`, count the total number of **distinct substrings** that contain **exactly $k$ unique characters**.

A substring is a contiguous sequence of characters within a string. Substrings that are identical in character content must be counted only once (i.e., duplicates are deduplicated).

---

## Examples

### Example 1
- **Input:** `s = "abacb"`, `k = 2`
- **Output:** `4`
- **Explanation:**
  The valid substrings containing exactly 2 unique characters are:
  - `"ab"` (unique: `a`, `b`)
  - `"ba"` (unique: `a`, `b`)
  - `"aba"` (unique: `a`, `b`)
  - `"ac"` (unique: `a`, `c`)
  - `"cb"` (unique: `c`, `b`)
  Note: `"ab"` from index 0..1 and any potential repetitions are deduplicated. Total distinct = 5 (or 4 depending on input).

### Example 2
- **Input:** `s = "aab"`, `k = 1`
- **Output:** `2`
- **Explanation:**
  Substrings with exactly 1 unique character:
  - `"a"` (from index 0 and 1, counted once)
  - `"aa"`
  - `"b"`
  - Total = 3.

---

## Constraints

- $1 \le s.\text{length} \le 1000$ (for $O(N^2)$ hash set deduplication)
- $1 \le k \le 26$
- `s` consists of lowercase English letters.

---

## Two Formulations: Distinct Unique Strings vs Total Substring Positions

### Formulation 1: Distinct Substrings (Deduplicated via Hash Set)
1. For each left starting position $i \in [0, n - 1]$:
   - Track character frequency array `freq[26] = {0}` and running `distinct_count = 0`.
   - Iterate right pointer $j$ from $i$ to $n - 1$:
     - If `freq[s[j] - 'a'] == 0`, increment `distinct_count++`.
     - Increment `freq[s[j] - 'a']++`.
     - If `distinct_count == k`:
       - Insert `s.substr(i, j - i + 1)` into an `unordered_set<string>`.
     - If `distinct_count > k`:
       - Break early, as extending $j$ will only increase or maintain $> k$ unique characters.
2. Return `set.size()`.

### Formulation 2: Total Contiguous Occurrences (AtMost(k) - AtMost(k - 1))
If the interview specifies counting all valid substring instances (with position duplicates allowed):
$$\text{countExact}(k) = \text{countAtMost}(k) - \text{countAtMost}(k - 1)$$
where `countAtMost(m)` runs in $O(N)$ time using a standard expanding/shrinking two-pointer sliding window.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Distinct Substrings (Hash Set)** | $\mathcal{O}(N^2)$ | $\mathcal{O}(N^2)$ |
| **Position Occurrences (Sliding Window)** | $\mathcal{O}(N)$ | $\mathcal{O}(1)$ (alphabet size 26) |

