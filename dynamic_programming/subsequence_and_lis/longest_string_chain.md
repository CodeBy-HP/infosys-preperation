# Longest String Chain (LeetCode 1048)

## Problem Statement

You are given an array of `words` where each word consists of lowercase English letters.

`wordA` is a **predecessor** of `wordB` if and only if we can insert exactly one letter anywhere in `wordA` without changing the order of the other characters to make it equal to `wordB`.
- For example, `"abc"` is a predecessor of `"abac"`, while `"cba"` is not a predecessor of `"bcad"`.

A **word chain** is a sequence of words `[word_1, word_2, ..., word_k]` with $k \ge 1$, where `word_1` is a predecessor of `word_2`, `word_2` is a predecessor of `word_3`, and so on. A single word is trivially a word chain with $k = 1$.

Return the length of the **longest possible word chain** with words chosen from the given list of `words`.

---

## Examples

### Example 1:
```text
Input: words = ["a", "b", "ba", "bca", "bda", "bdca"]
Output: 4
Explanation:
One of the longest word chains is ["a", "ba", "bda", "bdca"].
- "a" -> "ba" (insert 'b')
- "ba" -> "bda" (insert 'd')
- "bda" -> "bdca" (insert 'c')
Length is 4.
```

### Example 2:
```text
Input: words = ["xbc", "pcxbcf", "xb", "cxbc", "pcxbc"]
Output: 5
Explanation:
All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
```

### Example 3:
```text
Input: words = ["abcd", "dbqca"]
Output: 1
Explanation:
"abcd" is not a predecessor of "dbqca" (letters are out of order), so the longest chain is 1.
```

---

## Constraints

- `1 <= words.length <= 1000`
- `1 <= words[i].length <= 16`
- `words[i]` only consists of lowercase English letters.

---

## Recurrence Formulation & Algorithmic Approaches

### 1. Length Sorting & Hash Table Formulation
Because a word can only have a predecessor with length strictly equal to $|w| - 1$, cycles are impossible—the dependencies form a DAG.
If we sort the words by length in ascending order, any valid predecessor of word $w$ is guaranteed to have been processed earlier.

### 2. Deletion Search Transition
Rather than searching for successors among all words in the dictionary, for a word of length $L \le 16$, we can simply generate all $L$ possible predecessor candidates by removing each character one by one:
```cpp
for (int i = 0; i < word.length(); ++i) {
    string pred = word.substr(0, i) + word.substr(i + 1);
    if (dp.count(pred)) {
        dp[word] = max(dp[word], dp[pred] + 1);
    }
}
```

### 3. Algorithm
1. Sort `words` by length in ascending order: `sort(words.begin(), words.end(), [](const string& a, const string& b){ return a.size() < b.size(); });`
2. Initialize `unordered_map<string, int> dp`.
3. For each word $w \in words$:
   - Initialize $dp[w] = 1$.
   - For $k = 0 \dots |w| - 1$:
     - Construct predecessor $p = w[0 \dots k - 1] + w[k + 1 \dots |w| - 1]$.
     - If $p$ is in $dp$: $dp[w] = \max(dp[w], dp[p] + 1)$.
   - Update global maximum chain length.

---

## Complexity Analysis

| Metric | Length Sorting + Hash Map |
| :--- | :--- |
| **Time Complexity** | $O(N \log N + N \cdot L^2)$ where $N \le 1000$ and $L \le 16$ |
| **Auxiliary Space** | $O(N \cdot L)$ storing words in hash map |
