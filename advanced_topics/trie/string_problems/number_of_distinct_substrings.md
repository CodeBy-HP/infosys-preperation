# Number of Distinct Substrings in a String

## Problem Statement
Given a string `s` consisting of lowercase English letters, return the **number of distinct (non-empty) substrings** of `s`.

```
Input: s = "abab"
Output: 7

Explanation:
All substrings of "abab":
Length 1: "a", "b", "a", "b" -> Distinct: {"a", "b"}
Length 2: "ab", "ba", "ab"    -> Distinct: {"ab", "ba"}
Length 3: "aba", "bab"        -> Distinct: {"aba", "bab"}
Length 4: "abab"              -> Distinct: {"abab"}
Total distinct substrings = 2 + 2 + 2 + 1 = 7.
```

---

## 1. Algorithmic Approaches

### The Naive Set Approach ($O(N^3)$ time, $O(N^3)$ space)
Generating all substrings and inserting them into `std::unordered_set<string>` takes $O(N^2)$ iterations, where each string allocation and hashing step takes $O(N)$, resulting in $O(N^3)$ time and severe memory pressure for $N = 1000$.

---

### The Trie Suffix-Prefix Invariant ($O(N^2)$ time, $O(N^2)$ space)

#### Core Mathematical Observation
Every substring of string $s$ is a **prefix of some suffix** of $s$:
$$\text{Substring } s[i \dots j] = \text{Prefix of Suffix starting at index } i$$

If we insert all $N$ suffixes into a Trie:
- Every node in the Trie (excluding the root) represents **exactly one unique substring**!
- Whenever we need to allocate a **new Trie node** while inserting a character $s[j]$, we have encountered a **brand new distinct substring** never seen before!

```
Initialize count = 0, root = new TrieNode()

For i = 0 to N - 1:
    curr = root
    For j = i to N - 1:
        char ch = s[j]
        If !curr->containsKey(ch):
            curr->put(ch, new TrieNode())
            count++   <--- NEW DISTINCT SUBSTRING DISCOVERED!
        curr = curr->get(ch)

Return count
```

---

## 2. Complexity Analysis
- **Time Complexity:** $O(N^2)$ — Two nested loops. Each character transition checks and creates a node in $O(1)$ time. Zero string allocations, zero hashing overhead.
- **Space Complexity:** $O(N^2 \cdot 26)$ worst-case — Total Trie nodes bounded by $\frac{N(N+1)}{2}$.

