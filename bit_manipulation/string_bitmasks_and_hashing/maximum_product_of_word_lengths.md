# Maximum Product of Word Lengths (LeetCode 318)

## Problem Statement
Given a string array `words`, return the maximum value of `length(word[i]) * length(word[j])` where the two words do not share common letters. If no such two words exist, return `0`.

### Example 1:
```
Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".
```

### Example 2:
```
Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: The two words can be "ab", "cd".
```

### Constraints:
- `2 <= words.length <= 1000`
- `1 <= words[i].length <= 1000`
- `words[i]` consists only of lowercase English letters.

---

## Pattern Insight: 26-Bit Character Presence Mask
- A naive comparison checking if two strings share characters takes $O(L_1 \times L_2)$ or $O(26)$ per pair $\to O(N^2 \times 26)$.
- **Bitmask Hashing:**
  - Since there are only 26 lowercase English letters, encode each word into a 26-bit integer:
    $$\text{mask} = \sum_{c \in word} (1 \ll (c - 'a'))$$
  - Two words share **no common characters** if and only if:
    $$(\text{mask}_i \ \& \ \text{mask}_j) == 0$$
  - Evaluated in a single CPU cycle ($O(1)$)!
- **Deduplication Optimization:**
  - If multiple words share the identical bitmask (e.g., `"eat"`, `"tea"`, `"ate"` all have the same mask), keep only the one with the maximum length.

---

## Complexity
- **Time Complexity:** $O(\sum |words[i]| + N^2)$ with $O(1)$ bitwise comparisons.
- **Space Complexity:** $O(N)$ for bitmasks.
